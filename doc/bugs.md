# Verified defects / 已核实缺陷

**[English](#english)** | **[中文](#中文)**

Review scope: `arm0/src` and `sharc1/src` application sources, against the defects already fixed on ADSP-21593 (`adsp21593_framework/doc/bugs.md`) and against the CCES 3.0.3 Debug build of this tree. A defect is listed only when a file and function (or a datasheet field that the programmed byte violates) show it. Items that were inspected and left unchanged are in the last section.

---

<a id="english"></a>

## English

Twelve firmware defects were fixed. Two of them also stopped the Debug build (`NULL` in `timer.c` / `spu.c`, and `FLUSH_DATA_BUFFER_NO_INV` in `sport.c`). Debug images for all three cores now link. `sharc2` was already clean and was not edited.

### Fixed

| # | Evidence | What was wrong | Fix |
|---|----------|----------------|-----|
| 1 | `timer.c` `Tmr0Init` | `Tmr0Cfg` filled `tmr0_cfg` and `adi_tmr_Enable` ran, but `adi_tmr_Config` was never called. The 1 ms period never reached the timer. `NULL` was also undeclared, so ARM gcc stopped here. | `#include <stddef.h>`. Call `adi_tmr_Config(tmr0_dev, &tmr0_cfg)` before enable. |
| 2 | `audio_flow.c` `AudioCtrlInit` | TMR0 was started before UART0 RX DMA. Once the timer is actually configured, the callback polls DMA that is not armed yet. | Order is now pinmux, SPU, UART, TMR, switch, SRU, DAC, ADC, A2B, then the shared-stat clear. SPORT DMA stays on SHARC1 and starts only after `adi_core_enable`. |
| 3 | `uart.c` `Uart0Poll` | `XCNT_CUR` is transfers still remaining. A read of 0 produced write index `DMA_LEN` (512), one past the buffer. The wrap test required `cur >= old && cur < old`, which is impossible, so a write pointer that wrapped past the reader never incremented `overrun_cnt`. Landing on the reader was ignored. | Clamp, then map `DMA_LEN` to index 0. Count overrun when the writer passes or lands on the reader, including the wrap. |
| 4 | `uart.c` `Uart0Wr` | `len == 0`, a NULL pointer, or a length that is an exact multiple of 512 queued a DMA with `XCount == 0`. That completion interrupt never arrives, so `is_tx_over` stayed 0. The wait timeout was also not reloaded per chunk. | Reject NULL / zero. After the chunk loop, return when nothing remains. Each wait reloads its own timeout. |
| 5 | `spu.c` `Spu0Init` | `adi_spu_Init` passes `NULL`. ARM gcc does not get `NULL` from `<stdint.h>`. The first build stopped at `timer.c` and never reached this file. | `#include <stddef.h>`. |
| 6 | `adau19790_reg.c` `SAI_CTRL0` | `0x23` is SAI=`100` (TDM16) and FS=`011` (64–96 kHz). This path is 48 kHz. ADAU1979 FS=`010` is 32–48 kHz, so the byte is `0x22`. | Program `0x22`. `CMAP34` stays `0x23`. |
| 7 | `twi.c` `Twi2DevRegLngWr`, `Twi2Open`, `Twi2Stop` | Two `adi_twi_Write` calls (address with a repeated start, then the payload) start a second addressed write. The slave treats `payload[0]` as a register address. A second `Twi2Open` while the controller is still open was also accepted. | One write: MSB-first address (1, 2, or 4 bytes) plus payload, max 128 payload bytes. Longer, NULL, or illegal widths return without touching the bus. `Twi2Open` refuses a second open. `Twi2Stop` is a no-op when already idle. `Twi2IsIdle` reports that flag. |
| 8 | `ad2428.c` `Ad2428Cfg` DELAY | A 2-byte delay used only `val_ptr[1]`. SigmaStudio’s 16-bit delay is big-endian. This table’s delays are 1 byte, so the current script’s delays do not change. | `val_len == 2` uses `(b0 << 8) \| b1`. NULL or empty delay is 0. |
| 9 | `ad2428.c` `Ad24280Init`, `adau1962.c` | Discovery ran with no check that the DAC PLL had locked or that TWI2 was free. USBi is an I2C master and does not generate BCLK/FS. | `Adau1962ClkReady()` is 1 only after `PLL_CLK_CTRL1` bit 2 is seen. `Ad24280Init` returns unless that flag is set and `Twi2IsIdle()` is true. |
| 10 | `switch.c` `Sw0Init` | After releasing `~ADAU_RESET` the only wait was 65535 `nop`s, well under 1 ms. ADAU1962A Rev. A requires 300 ms after PU/RST. ARM has no `__builtin_emuclk`. | After `Twi2Stop`, count down a `volatile uint32_t` from 300e6 with `BUSY_NOP()`. At CCLK ≤ 1 GHz that cannot finish in less than 300 ms. |
| 11 | `tune.c` `TuneTx` | `TuneTx` sent a 4-byte length and passed the address of the CRC `uint16_t`. `TuneRx` accepts a 1-byte length only for command `0x01`, and no length for `0x02` / `0x03` / `0x04`. | `0x01` sends one length byte (reject `len > 255`). Other commands send header + cmd + CRC only. CRC bytes are explicit little-endian. `TuneRx` is still not called from `MonTmp`. |
| 12 | `sport.c` `PublishAudioStat` | `FLUSH_DATA_BUFFER_NO_INV` is not a symbol in CCES 3.0.3 `sys/cache.h`. cc21k stopped on `sharc1`. | `flush_data_buffer(..., ADI_FLUSH_DATA_NOINV)`. That writes the `AudioStat` block back and does not invalidate it. |

### Inspected and left as-is

- `log.c` `ShtLog` already includes `<stdarg.h>` / `<stdio.h>` and refuses a `vsnprintf` result that does not fit in the 128-byte buffer. Callers of `ShtLog` already include `log/log.h`.
- `UART0_RXDMA_XCNT_CUR` is a DFP address macro in this SC594 pack. `uart.c` compiled with it. UART0 RX remains DMA channel 21. It was not rewritten to `pREG_DMA21_XCNT_CUR`.
- `AD24281` is an empty stub. `Ad24281Init` stays uncalled.
- `CMAP12 = 0x01` and `CMAP34 = 0x23` swap adjacent channels versus reset. Not proven wrong.
- A full lap of the UART ring that lands back on the old index is still invisible to `overrun_cnt`.
- `Uart0Rd` increments `underrun_cnt` on an empty buffer. `MonTmp` loops until empty, so the counter includes idle polls.
- `sharc1/src/sc594_framework_Core1.c` and `sharc2/src/sc594_framework_Core2.c` warn `cc0111` on `return 0` after `while (1)`. That is the CCES template. The statement is unreachable and was not edited.
- No `adi_pwr_Init` in this tree. UART divisor 136 and `TMR0_1MS` 125000 still assume SCLK0 = 125 MHz.

### Build

CCES 3.0.3 Debug, processor ADSP-SC594, silicon revision 0.0. `make.exe` is `E:\bin\cces\3.0.3\make.exe`. ARM `gcc` is on `E:\bin\cces\3.0.3\ARM\arm-none-eabi\bin`. `cc21k` is on the CCES root.

```text
make -C arm0/Debug -j8 all
Finished building target: arm0
  arm0/Debug/arm0          4737056 bytes

make -C sharc1/Debug -j8 all
Finished building target: sharc1.dxe
  sharc1/Debug/sharc1.dxe   523092 bytes
  cc0111 warning: unreachable return 0 (left as-is)

make -C sharc2/Debug -j8 all
make: Nothing to be done for 'all'.
  sharc2/Debug/sharc2.dxe   308176 bytes
  previous link: 0 errors, 1 warning (same unreachable return)
```

The ARM makefile emits the image as `arm0` with no `.dxe` suffix. That is the generated link rule, not a missing file.

---

<a id="中文"></a>

## 中文

固件里核实并改掉 12 处。其中两处直接让 Debug 编不过：`timer.c` / `spu.c` 的 `NULL`，以及 `sport.c` 的 `FLUSH_DATA_BUFFER_NO_INV`。三个核的 Debug 映像现在都能链出来。`sharc2` 本来就是干净的，没有改源码。

### 已修复

| # | 证据 | 问题 | 修复 |
|---|------|------|------|
| 1 | `timer.c` `Tmr0Init` | `Tmr0Cfg` 只填了 `tmr0_cfg`，接着 `adi_tmr_Enable`，没有 `adi_tmr_Config`。1 ms 周期进不了定时器。`NULL` 也未声明，ARM gcc 在这里停下。 | `#include <stddef.h>`。Enable 之前调用 `adi_tmr_Config(tmr0_dev, &tmr0_cfg)`。 |
| 2 | `audio_flow.c` `AudioCtrlInit` | TMR0 早于 UART0 RX DMA。定时器一旦真的按 1 ms 跑，回调会去读还没武装的 DMA。 | 顺序改为 pinmux → SPU → UART → TMR → switch → SRU → DAC → ADC → A2B → 清共享状态。SPORT DMA 仍在 SHARC1，并且只在 `adi_core_enable` 之后启动。 |
| 3 | `uart.c` `Uart0Poll` | `XCNT_CUR` 是剩余传输个数。读到 0 时写指针变成 `DMA_LEN`（512），越界。回绕判断写成 `cur >= old && cur < old`，恒假，写指针绕过读指针时 `overrun_cnt` 不增加。写指针落在读指针上也没计数。 | 钳位后把 `DMA_LEN` 映射为下标 0。越过或落在读指针上，包括回绕，都计 overrun。 |
| 4 | `uart.c` `Uart0Wr` | `len == 0`、空指针，或长度刚好是 512 的整数倍时，会提交 `XCount == 0` 的 DMA。完成中断不来，`is_tx_over` 停在 0。等待超时也没有按块重装。 | 拒绝空指针和 0 长度。分块发完就返回。每次等待各自重装超时。 |
| 5 | `spu.c` `Spu0Init` | `adi_spu_Init` 传入 `NULL`。ARM gcc 不会从 `<stdint.h>` 得到 `NULL`。第一次构建停在 `timer.c`，没编到这个文件。 | `#include <stddef.h>`。 |
| 6 | `adau19790_reg.c` `SAI_CTRL0` | `0x23` 的 SAI=`100`（TDM16），FS=`011`（64–96 kHz）。本链路是 48 kHz。ADAU1979 的 FS=`010` 才是 32–48 kHz，对应 `0x22`。 | 改为 `0x22`。`CMAP34` 仍是 `0x23`。 |
| 7 | `twi.c` `Twi2DevRegLngWr`、`Twi2Open`、`Twi2Stop` | 两次 `adi_twi_Write`（地址带重复起始，再发数据）会开始第二次寻址写，从机把 `payload[0]` 当成寄存器地址。控制器还开着时再次 `Twi2Open` 也会被接受。 | 一次写入：地址按大端放 1/2/4 字节，再拼数据，数据最长 128 字节。空指针、更长或非法宽度直接返回。`Twi2Open` 拒绝第二次打开。`Twi2Stop` 在已空闲时什么都不做。`Twi2IsIdle` 报告这个标志。 |
| 8 | `ad2428.c` `Ad2428Cfg` 的 DELAY | 两字节延时只用了 `val_ptr[1]`。SigmaStudio 的 16 位延时是大端。本表的延时是 1 字节，当前脚本的延时不变。 | `val_len == 2` 时用 `(b0 << 8) \| b1`。空指针或空长度当作 0。 |
| 9 | `ad2428.c` `Ad24280Init`、`adau1962.c` | 发现流程不检查 DAC PLL 是否锁定，也不检查 TWI2 是否空闲。USBi 是 I2C 主机，不产生 BCLK/FS。 | 看到 `PLL_CLK_CTRL1` bit 2 之后 `Adau1962ClkReady()` 才为 1。该标志或 `Twi2IsIdle()` 任一失败，`Ad24280Init` 直接返回。 |
| 10 | `switch.c` `Sw0Init` | 释放 `~ADAU_RESET` 之后只空转 65535 次 `nop`，不到 1 ms。ADAU1962A Rev. A 要求 PU/RST 拉高后 300 ms。ARM 没有 `__builtin_emuclk`。 | `Twi2Stop` 之后用 `volatile uint32_t` 从 3×10^8 倒数，每次 `BUSY_NOP()`。CCLK ≤ 1 GHz 时不可能短于 300 ms。 |
| 11 | `tune.c` `TuneTx` | `TuneTx` 发送 4 字节长度，并把 CRC `uint16_t` 的地址交给 `Uart0Wr`。`TuneRx` 只给命令 `0x01` 收 1 字节长度，`0x02` / `0x03` / `0x04` 没有长度。 | `0x01` 发 1 字节长度（`len > 255` 拒绝）。其它命令只发帧头 + cmd + CRC。CRC 按小端拆成两个字节。`TuneRx` 仍未接到 `MonTmp`。 |
| 12 | `sport.c` `PublishAudioStat` | CCES 3.0.3 的 `sys/cache.h` 里没有 `FLUSH_DATA_BUFFER_NO_INV`。cc21k 在 `sharc1` 上停下。 | 改为 `flush_data_buffer(..., ADI_FLUSH_DATA_NOINV)`。这是把 `AudioStat` 写回，不作废缓存。 |

### 看过但没有改

- `log.c` 的 `ShtLog` 已经包含 `<stdarg.h>` / `<stdio.h>`，`vsnprintf` 的结果放不进 128 字节缓冲时不发送。调用 `ShtLog` 的文件已经包含 `log/log.h`。
- 本机 SC594 DFP 里 `UART0_RXDMA_XCNT_CUR` 是地址宏，`uart.c` 能编过。UART0 RX 仍是 DMA21。没有改成 `pREG_DMA21_XCNT_CUR`。
- `AD24281` 是空桩。`Ad24281Init` 保持不调用。
- `CMAP12 = 0x01`、`CMAP34 = 0x23` 相对复位值交换了相邻通道，没有证据说明这是错的。
- UART 环整圈后停在旧下标时，`overrun_cnt` 仍然看不出来。
- `Uart0Rd` 在缓冲空时增加 `underrun_cnt`。`MonTmp` 一直读到空，所以计数包含空闲轮询。
- `sharc1/src/sc594_framework_Core1.c` 和 `sharc2/src/sc594_framework_Core2.c` 对 `while (1)` 后面的 `return 0` 报 `cc0111`。这是 CCES 模板，语句不可达，没有改。
- 工程里没有 `adi_pwr_Init`。UART 除数 136 和 `TMR0_1MS` 125000 仍按 SCLK0 = 125 MHz。

### 构建

CCES 3.0.3，Debug，处理器 ADSP-SC594，硅版本 0.0。`make.exe` 在 `E:\bin\cces\3.0.3\make.exe`。ARM `gcc` 在 `E:\bin\cces\3.0.3\ARM\arm-none-eabi\bin`。`cc21k` 在 CCES 根目录。

```text
make -C arm0/Debug -j8 all
Finished building target: arm0
  arm0/Debug/arm0          4737056 字节

make -C sharc1/Debug -j8 all
Finished building target: sharc1.dxe
  sharc1/Debug/sharc1.dxe   523092 字节
  cc0111：return 0 不可达（保留）

make -C sharc2/Debug -j8 all
make: Nothing to be done for 'all'.
  sharc2/Debug/sharc2.dxe   308176 字节
  上一次链接：0 error，1 warning（同一处不可达 return）
```

ARM 的 makefile 链出来的文件名是 `arm0`，没有 `.dxe` 后缀。这是生成出来的链接规则，不是文件没生成。
