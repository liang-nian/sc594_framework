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
- A2B0 的 4 个通道按 21593 的方式放到 DAC 通道 8 起，不改 DAC 通道 0。A2B1 只写 TX 前 4 个通道。
- `ad24281_cfg` 仍是一条 `dev == 0` 的记录。

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
4. 命令 `0xAA`。AD24280 仍走 TWI 监视。AD24281 在脚本为空时只打印阻塞原因，不打开 TWI。

## 第二路 A2B 没有在板上接通

已经接上的部分，依据都在仓库里：

- SPORT5A/B、DAI1 PB19/PB10/PB11/PB07、时钟 PB08/PB09，见 `arm0/src/driver/sru/signal_route.c`。
- SPU id 73/74，见 `arm0/src/driver/spu/spu.c`。
- DMA 与全局 SPORT 组，见 `sharc1/src/driver/sport/sport.c`。通道 0–3 进入共享音频 lane 1。

没有做、也不能声称已经工作的部分：

- `doc/sc594_framework.md` 和上游 `ad2428.h` 都写明 EV-SOMCRR-EZKIT 只有一颗 AD2428（AD24280）。
- `arm0/src/driver/ad2428/ad24281_reg.c` 的表长是 1，唯一记录是 0。`Ad24281Init` 在 `dev == 0` 或表长小于 2 时直接返回。
- 头文件里的 `0x6C` / `0x6D` 没有对应的发现脚本，启动代码不会向这个地址发起传输。

要让第二颗收发器真正进发现流程，需要一块实际焊上或插上的第二颗 AD2428，以及它的 SigmaStudio 导出（主节点地址、`ad24281_cfg` 长度至少 2，且第一条 `dev` 不是 0）。在那之前，控制块里的 `a2b1_link` 是 `BLOCKED`，`a2b1_block` 是 `NO_SCRIPT`，lane 1 的增益是 0。
