# 核间共享与第二路 A2B：验证说明

上游只读基线是 `liang-nian/adsp21593_framework` 的 `main`，提交 `2bd625d4ba38aea9e8ef8e6e2158f18dc0d6f2f3`（2026-11-08，`Merge branch 'doc/git_ignore'`）。本仓库改动基于 `dev/base_frame` 的 `6201d294507b48e29d19c9dc142db9326b2e877f`。

这里的“通过”只包括主机上能编译运行的检查。没有 CCES，也没有 EV-SC594-SOM，下面两节不能当成已经在板子上跑过。

## 主机上已经跑的检查

在仓库根目录：

```bash
gcc -std=c11 -Wall -Wextra -Werror -Icommon \
  host/test_xcore.c common/xcore_proto.c \
  arm0/src/driver/ad2428/ad24281_reg.c -o /tmp/test_xcore
/tmp/test_xcore
python3 host/check_map.py
```

`test_xcore` 覆盖：

- 控制块和音频块的宽度、64 字节对齐、两段地址首尾相接，并且都落在 ARM 非缓存 L2（`0x20025000`–`0x2003FFFF`）里。旧的 `0x2003FF00` 现在在音频窗口内部，不能再当独立状态块写。
- 版本、结构长度和 ARM 未就绪时，SHARC 挂接失败，并且不会把自己标成 ready。
- 参数双槽发布。SHARC1 的应答不会清掉 SHARC2 的应答；后一次发布也不会把另一核还没跟上的应答抹成 0。
- `seq` 为奇数，或校验和与槽内容不一致时，读方不采用，已有应答保留。
- `XcoreArmReset` 之后旧应答和音频槽序号都回到 0，必须重新挂接再发布。
- 音频两槽回绕、`0xFFFFFFFE` 之后的下一偶数序号、过期序号读不回来。
- 发布方先写回样本，再写回偶数 `seq`。
- A2B0 的 4 个通道按 21593 的方式放到 DAC 通道 8 起，不改 DAC 通道 0。缺省时第二路共享结果仍非 0，SPORT5 前 4 通道写静音；同一路由在 mute 清掉后把该结果写到 SPORT5，且不改 DAC 8–11。通道 4 之后的 TX 尾部保持不动。
- 缺省 `ad24281_cfg` 不是导入表。两条 `dev` 非 0 的记录才会被 `Ad24281TableIsImported()` 接受。

`check_map.py` 核对 `arm0/system/linker/app.ld` 的 `MEM_L2_XCORE_CTRL` / `MEM_L2_XCORE_AUDIO` 与 `common/xcore_abi.h` 一致，并且旧的 `MEM_L2_AUDIO_STAT` 已经不在链接脚本里。

## CCES 上要做的，本次没有做

环境仍是文档里的 CCES 3.0.3，处理器 ADSP-SC594，硅版本 0.0。三个工程都编 Debug：

```text
make -C arm0/Debug -j8 all
make -C sharc1/Debug -j8 all
make -C sharc2/Debug -j8 all
```

预期：

- ARM 链接脚本把 `0x20038000`（16 KB）和 `0x2003C000`（16 KB）标成 NOLOAD，不和 `.l2_uncached_data`、MCAPI、`0x20040000` 起的缓存 L2 重叠。
- `sharc1/system/startup_ldf/app.ldf` 和 `sharc2` 的同名文件是 CCES 生成的，仓库用 `*.ldf` 忽略它们。重新生成之后，用 `sharc*/system/startup_ldf/xcore_reserve.mem` 里的两段地址对照 map：SHARC 的输出段不能覆盖 `0x20038000`–`0x2003FFFF`。默认划分里 SHARC L2 从 `0x20100000` 起。
- `common/xcore_cache.c` 使用 `ADI_FLUSH_DATA_NOINV` 和 `ADI_FLUSH_DATA_INV`。前者已经在本树的 CCES 3.0.3 上用过。若 `ADI_FLUSH_DATA_INV` 的枚举名不同，只改这个文件，不要改成只靠 `volatile`。
- 启动代码把 `REG_SHL1C0_CFG` 写成 0（`system.svc` 的 `dcache_config` 是 `disable_dcache_and_enable_cplb`）。刷新调用仍然留着，避免以后打开数据缓存时协议失效。ARM 侧这段 L2 在 `apt.c` 里是 `ADI_MMU_RW_UNCACHED`，屏障是 `dsb`。

## 板上要看的，本次没有做

板子是 EV-SC594-SOM + EV-SOMCRR-EZKIT。下载三个核之后：

1. UART 命令 `0xCC`。应看到参数 generation，以及 SHARC1、SHARC2 各自的 ack。两颗 DSP 都起来之后，两个 ack 应等于 generation。只看到其中一个时，不要当成两颗都收到了。
2. 同一条命令里的负载。SHARC1 magic `0xA5A500CC`，SHARC2 magic `0xA5A500CD`。SHARC2 一直“尚未发布”时，优先看 `INTR_SYS_SOFT0_INT` 是不是只进了 SHARC2。SHARC1 的音频回调有 200000 周期上限（1 GHz 下约 0.2 ms），超时会计 miss，不会一直卡在回调里。
3. DAC 0–3 仍是 ADC 回环，4–7 仍是 1 kHz。DAC 8–11 应是 A2B0 通道 0、1、2、3 经 SHARC2 后的结果，顺序与 21593 相同，不再是以前的 0、2、1、3 交错。
4. 命令 `0xAA`。AD24280 仍走 TWI 监视。缺省 AD24281 只打印 `default cfg`，不打开 TWI，也不表示发现成功。
5. 示波器或 DAC 上，第二路不应改变 DAC 8–11。缺省时 SPORT5 前 4 个槽是静音。导入表并重新编译后，同一槽应出现 A2B1 通道 0–3 经 SHARC2 后的样本。

## 第二路音频路由

两条车道都是 4 通道，和 21593 交给 SHARC2 的宽度一样。

| 共享车道 | 来源 | 谁处理 | 消费到哪里 |
|----------|------|--------|------------|
| lane 0 | A2B0 通道 0–3（SPORT1） | SHARC2，增益 8–11，缺省 1 | DAC 通道 8–11。这是 21593 的路由，第二路不改它 |
| lane 1 | A2B1 通道 0–3（SPORT5 RX） | SHARC2，增益 12–15，缺省 1 | SHARC1 先读回共享结果。`a2b1_tx_mute == 1` 时 SPORT5 TX 前 4 通道写 0；导入配置后同一函数把样本写出去 |

A2B0 / A2B1 的通道 4–31 只留在 SHARC1 的 SPORT 浮点缓冲里，没有放进共享块，所以不是“没人消费的共享音频”。共享块里的 8 个通道都会被读走。A2B0 的 TX（`a2b0_out`）和 21593 一样不由这条路由填充。

缺省表是 `arm0/src/driver/ad2428/ad24281_reg.c` 的一条全 0 记录。`Ad24281TableIsImported()` 拒绝它。`Ad24281Init` 不打开 TWI，`a2b1_link` 是 `DEFAULT`，`a2b1_tx_mute` 是 1，`a2b1_nodes` 保持 0。这不是发现成功。

导入时替换该文件和 `AD24281_CFG_LEN`，或调用 `Ad24281Bind()`。表长至少 2 且第一条 `dev` 不是 0 才算导入。播放仍是原来的 `Ad2428Cfg` I2C 读写。音频路由函数不用改。`a2b1_link == UP` 只表示脚本已经交给 TWI，不表示从节点已经应答。

上板还要做的事：准备第二颗 AD2428 和它的 SigmaStudio 导出，再确认 SPORT5 出口从静音变成该导出对应的音频。这是硬件 bring-up，不是这次软件路由的缺口。
