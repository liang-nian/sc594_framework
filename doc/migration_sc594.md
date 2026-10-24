# SC594 driver migration

Port of the audio drivers from [adsp21593_framework](https://github.com/liang-nian/adsp21593_framework) branch `feat/base_audio_framework` into this ADSP-SC594 project (`dev/base_frame`). The 21593 tree was used as a reference only. Startup, linker, MCAPI, and the generated SRU register dump already in this repo were not replaced with the 21593 copies.

**[English](#english)** | **[中文](#中文)**

---

<a id="english"></a>

## English

### Core split

21593 has two SHARC cores and no ARM. Every driver sat on SHARC1. SHARC2 was an empty loop.

SC594 is ARM + SHARC1 + SHARC2. The projects stay `arm0/`, `sharc1/`, `sharc2/`.

| 21593 | SC594 | What runs there |
|-------|--------|-----------------|
| — | **arm0** (ARM, boots first) | UART0, TWI2, U6 switch, ADAU1962 / ADAU1979 register writes, AD2428 configuration, SPU, the 1 ms UART timer, SRU route, UART monitor |
| SHARC1 | **sharc1** | SPORT DMA and `AudioProcess` (ADC loopback, 1 kHz, A2B0 into the DAC) |
| SHARC2 | **sharc2** | Idle secondary core. No drivers. |

Codec and switch register programming moved with TWI. They are I2C clients. Leaving them on SHARC1 would require a cross-core TWI RPC, which this port does not add.

SHARC1 is released only after `AudioCtrlInit()` returns. `adi_core_enable()` used to run before any of that work. SPORT DMA now starts against clocks that are already up.

### What moved onto ARM

| Piece | Path |
|-------|------|
| UART0 DMA ring | `arm0/src/driver/uart/` |
| TWI2 | `arm0/src/driver/twi/` |
| AD2428 script (829 entries) and the empty AD24281 stub | `arm0/src/driver/ad2428/` |
| ADAU1962 / ADAU1979 init | `arm0/src/driver/adau1962/`, `adau1979/` |
| U6 switch @ 0x22 | `arm0/src/driver/switch/` |
| TMR0 → `Uart0Poll` | `arm0/src/driver/timer/` |
| SPU secure-master enables | `arm0/src/driver/spu/` |
| Carrier SRU route | `arm0/src/driver/sru/signal_route.c` |
| UART log, monitor (`0xAA` / `0xBB` / `0xCC`), tune parser stub | `arm0/src/algo/` |
| PORTA mux for UART0 and TWI2 | `arm0/src/driver/pinmux/board_pinmux.c` |

`AudioCtrlInit()` order:

1. `BoardPinmux`
2. `Spu0Init`
3. `Tmr0Init`
4. `Uart0Init`
5. `Sw0Init`
6. `SruInit`
7. `Adau19620Init` (clock master)
8. `Adau19790Init`
9. `Ad24280Init`
10. clear the shared CPU-load block
11. `adi_core_enable` both SHARCs (in `main`, after `AudioCtrlInit`)

`Ad24281Init()` is not called. EV-SOMCRR-EZKIT has one A2B master (AD24280 @ 0x68 / 0x69).

### UART / I2C / A2B on ARM — what changed

**Pinmux.** The Pin Multiplexing add-in is installed, but `arm0/system/pinmux/GeneratedSources/pinmux_config.c` is still `return 0`. `BoardPinmux()` runs from `AudioCtrlInit` and programs only the control pins, read-modify-write, so other PORTA settings survive:

- UART0 TX/RX/RTS/CTS = PA06..PA09, mux function 1
- TWI2 SCL/SDA = PA14/PA15, mux function 0

That matches the SC594 EZ-KIT pinctrl (UART ALT1, I2C2 ALT0) and the 21593 carrier mux. DAI pins are not PORT mux; they go through the SRU.

**UART buffers.** `#pragma default_section(ALLDATA, "seg_l1_block1")` is SHARC-only. UART DMA descriptors and the 512-byte rings are `__attribute__((section(".l2_uncached_data")))` so the ARM cache does not hide them from DMA. `UART0_RXDMA_XCNT_CUR` is still the DFP address macro. SC594 UART0 RX DMA is channel 21; the macro selects it.

**TWI.** Same API and the same per-driver `Twi2Open` / `Twi2Stop` isolation. Prescale 12 and the 100 kHz bit rate assume SCLK0 = 125 MHz, which is what the 21593 timer comment assumed. Retune both if the CGU setup on this board changes SCLK0. Busy-waits use `BUSY_NOP()` because the ARM compiler does not take `asm("nop;")`.

**A2B configuration.** `ad24280_reg.c` is the same SigmaStudio export. `Ad2428Cfg` still runs on TWI2 from ARM. The SPORT that carries A2B audio is not part of configuration; it stays on SHARC1.

**SPU.** Ids follow the 21593 map (SP0A = 63, then one id per half-SPORT, UART0 = 29, UART0 RX/TX DMA = 79/80). Audio on this SoC uses SPORT1, SPORT4, and SPORT5, so those half-SPORT ids are 65/66, 71/72, and 73/74. If a DMA channel faults, check the ids against the SC594 DFP SPU list before changing anything else.

**Monitor.** `0xAA` reads A2B status over TWI. `0xBB` prints UART underrun/overrun. `0xCC` prints the CPU load SHARC1 stores at `0x2003FF00` (`common/audio_stat.h`). That address is the last 256 bytes of the ARM uncached L2 window already described in `apt.c`. The linker no longer places ordinary data there. The load is printed as `d.ddd` text so the ARM libc does not need float `printf`.

### USBi: clocks before I2C

USBi is an I2C bridge onto TWI2. It does not generate BCLK or FS. The ADAU1962 does.

Bring-up rule, same as the 21593 notes, now split across cores:

1. SRU is programmed and the ADAU1962 PLL/clock-master setup has finished **before** `Ad24280Init()` opens TWI2.
2. Every TWI client `Twi2Stop()`s before the next client opens the bus. A NAK must not stick for the A2B script, and the bus must be idle before USBi is attached.
3. Do not leave USBi plugged in across a firmware boot. The boot path owns TWI2 from `Sw0Init` through `Ad24280Init`.
4. To re-export a SigmaStudio script: run until BCLK/FS are toggling (through `Adau19620Init`), do not enter `Ad24280Init`, then plug USBi in. Unplug it before the firmware opens TWI2 again.

`Ad24280Init` is still called on every boot. The rule is operational: clocks first, then I2C, and only one master on TWI2 at a time.

### Audio path vs the 21593 SHARC

SC594 has two SRU groups. SPORT0–3 are DAI0 (`SRU`). SPORT4–7 are DAI1 (`SRU2`). The datasheet DRU makes every DAI1 source available to the DAI0 SRU, so the codec clock on DAI1 can still be copied onto the A2B0 pins on DAI0.

Carrier nets are the EV-SOMCRR-EZKIT nets (same board the 21593 project targeted). Only the SPORT numbers change:

| Net | 21593 | SC594 |
|-----|--------|--------|
| DAC TX / ADC RX | SPORT0 | **SPORT4** (DAI1) |
| A2B0 TX / RX | SPORT1 | **SPORT1** (DAI0, unchanged) |
| Legacy A2B1 pins (no device) | SPORT2 | **SPORT5** (DAI1) |

`signal_route.c` uses `SRU2` for DAI1 destinations and `SRU` for DAI0 destinations, including `SRU(DAI1_PB05_O, DAI0_PB03_I)` for the A2B0 bit clock. The SPORT1B clock-edge stagger from the 21593 driver is unchanged.

`arm0/system/sru/sru_config.c` is the CCES SRU add-in output. With `SRU_FULL_INIT` **undefined** it only enables the DAI input pads. Leave that macro undefined. The full-init table is a straight-through SPORT-to-adjacent-pin template and overwrites the carrier route. `SruInit()` runs after `adi_SRU_Init()` and writes the real connections.

Generated pinmux, MCAPI, the ARM linker script (aside from the 256-byte status hole), startup, and both SHARC LDF add-ins were left as the SC594 project created them. 21593 `app.ldf` / pinmux was not copied. SHARC `app.ldf` is gitignored (`*.ldf`); CCES regenerates it from `system.svc`.

`tune.c` is still the unfinished parser from 21593. It sits next to the UART. `MonTmp` does not call `TuneRx` yet.

### Build

This VM has no CrossCore Embedded Studio and no `cc21k` / ARM bare-metal compiler, so the projects were not linked here. Build on a machine with CCES and the ADSP-SC594 Device Family Pack:

1. Install CCES. The ARM linker script in this tree was emitted by CCES 3.0.3. The SHARC startup files record Startup Code/LDF tool 6.3.2. Use a CCES release that still opens those ADSP-SC594 bare-metal projects.
2. File → Import → Existing Projects into Workspace. Import `arm0`, `sharc1`, and `sharc2`. The processor on all three is **ADSP-SC594**. Do not retarget them to 21593.
3. If `sharc1/system/startup_ldf/app.ldf` or `sharc2/system/startup_ldf/app.ldf` is missing, open each SHARC `system.svc` and regenerate the Startup Code/LDF add-in. Those files are ignored by git on purpose.
4. Do not define `SRU_FULL_INIT`.
5. Build `arm0`, then `sharc1`, then `sharc2` (Debug or Release). Include paths added for this port:
   - ARM: `src/driver`, `src/algo`, `../common`
   - SHARC1: `src/driver`, `../common`
6. Driver headers (`<drivers/uart/adi_uart.h>`, `<drivers/twi/adi_twi.h>`, `<drivers/sport/adi_sport.h>`, `<services/spu/adi_spu.h>`, `<services/tmr/adi_tmr.h>`, `<sru.h>`) come from the DFP on the CCES include path. They are not vendored.
7. Flash or debug with the SC594 EZ-KIT session. ARM `main` enables both SHARCs after the control plane init.

If `flush_data_buffer` or `FLUSH_DATA_BUFFER_NO_INV` disagrees with the installed `sys/cache.h`, keep the write-back (do not invalidate-only) of the `AudioStat` block in `sharc1/src/driver/sport/sport.c`. If a SPORT DMA channel faults, re-check the SPU ids in `arm0/src/driver/spu/spu.c` against the DFP.

---

<a id="中文"></a>

## 中文

### 核划分

21593 是双 SHARC、没有 ARM，驱动全在 SHARC1，SHARC2 空转。

SC594 是 ARM + SHARC1 + SHARC2。目录仍是 `arm0/`、`sharc1/`、`sharc2/`。

| 21593 | SC594 | 职责 |
|-------|--------|------|
| — | **arm0** | UART0、TWI2、U6 开关、ADAU1962/1979 寄存器、AD2428 配置、SPU、1 ms UART 定时器、SRU、串口监视 |
| SHARC1 | **sharc1** | SPORT DMA 与 `AudioProcess`（ADC 环回、1 kHz、A2B0 → DAC） |
| SHARC2 | **sharc2** | 空闲副核，无驱动 |

Codec 和 U6 的寄存器配置跟着 TWI 到 ARM。它们是 I2C 设备。放在 SHARC1 就必须再做一套跨核 TWI，这次没有做。

`adi_core_enable()` 改到 `AudioCtrlInit()` 之后。SHARC1 开 SPORT DMA 时 BCLK/FS 已经在跑。

### 放到 ARM 上的代码

UART、TWI、AD2428（含 829 条表和空的 AD24281）、ADAU1962、ADAU1979、switch、timer、SPU、SRU 路由、log / monitor / tune，以及 PORTA 上 UART0/TWI2 的 pinmux。路径见 English 节的表。

`AudioCtrlInit()` 顺序：pinmux → SPU → TMR0 → UART → switch → SRU → 1962 → 1979 → AD24280 → 清 CPU 负载共享块。然后 `main` 才放开两个 SHARC。`Ad24281Init()` 不调用。载板只有一路 A2B（0x68/0x69）。

### UART / I2C / A2B 归 ARM 后改了什么

**Pinmux。** 插件生成的 `adi_initpinmux()` 仍是空函数。`BoardPinmux()` 用读改写只动这些脚：UART0 在 PA06–PA09、功能 1；TWI2 在 PA14/PA15、功能 0。与 SC594 EZ-KIT pinctrl 一致。DAI 不走 PORT mux。

**UART。** SHARC 的 `seg_l1_block1` pragma 在 ARM 编译器上不存在。DMA 描述符和 512 字节环放在 `.l2_uncached_data`，避免 D-cache 和 DMA 各看各的。`UART0_RXDMA_XCNT_CUR` 仍用 DFP 宏。

**TWI。** 接口不变，每个设备自己 `Open`/`Stop`。Prescale 12、100 kHz 按 SCLK0 = 125 MHz（与 21593 定时器注释相同）。SCLK0 若被 CGU 改掉，这里和 `TMR0_1MS` 一起改。忙等用 `BUSY_NOP()`。

**A2B 配置。** 表还是原来的 SigmaStudio 导出，在 ARM 上经 TWI2 回放。A2B 的音频 SPORT 留在 SHARC1。

**SPU。** 沿用 21593 的编号方式：SP0A = 63，每个半 SPORT 加 1，UART0 = 29，RX/TX DMA = 79/80。本工程实际打开的是 SPORT1（65/66）、SPORT4（71/72）、SPORT5（73/74）。DMA 异常时先对一下 DFP 里的 SPU 编号。

**监视命令。** `0xAA` A2B，`0xBB` UART 计数，`0xCC` 读 SHARC1 写在 `0x2003FF00` 的 CPU 负载（`common/audio_stat.h`）。这块是 `apt.c` 里 ARM uncached L2 的最后 256 字节，链接脚本不再往这里放别的数据。打印用整数 `d.ddd`，不依赖 ARM 的浮点 printf。

### USBi：先有时钟，再占 I2C

USBi 只是接到 TWI2 的 I2C 桥，不产生 BCLK/FS。时钟来自 ADAU1962。

1. `SruInit` 和 `Adau19620Init` 完成之后才允许 `Ad24280Init()` 打开 TWI2。
2. 每个 TWI 用户在下一个用户 `Open` 之前 `Twi2Stop()`。NAK 不能留给 A2B 长脚本，USBi 插上之前总线必须是空的。
3. 不要在整段启动过程中插着 USBi。从 `Sw0Init` 到 `Ad24280Init` 固件占着 TWI2。
4. 要重新导出 SigmaStudio 表：跑到 1962 时钟已经出来，先不要进 `Ad24280Init`，再插 USBi。拔掉之后固件才能再次 `Open` TWI2。

当前启动路径每次都会调用 `Ad24280Init`。规则是操作顺序：先时钟，后 I2C，TWI2 上同时只能有一个主机。

### 相对 21593 的音频路径

SC594 的 SRU 分成两组。SPORT0–3 属于 DAI0，用 `SRU()`。SPORT4–7 属于 DAI1，用 `SRU2()`。DRU 把 DAI1 的源送到 DAI0，所以 DAI1 上的 codec 时钟仍能复制到 DAI0 的 A2B0 脚。

载板网络仍是 EV-SOMCRR-EZKIT（21593 工程用的同一块板）。变的是 SPORT 号：codec 从 SPORT0 改到 **SPORT4**，A2B0 仍是 **SPORT1**，遗留的 A2B1 脚从 SPORT2 改到 **SPORT5**。SP1B 的沿错开保持原样。

`sru_config.c` 是 CCES 插件生成的。不要定义 `SRU_FULL_INIT`。那个全表是 SPORT 直连相邻 DAI 脚的模板，会盖掉载板走线。`SruInit()` 在 `adi_SRU_Init()` 之后写真正的连接。

没有把 21593 的 `app.ldf`、pinmux、启动文件拷进来。MCAPI、ARM 链接脚本（只挖了 256 字节状态孔）、SHARC 启动桩保持本仓库原样。`*.ldf` 被 gitignore，需要时在 CCES 里从 `system.svc` 重新生成。

`tune.c` 仍是 21593 里未完成的解析器，放在 UART 旁边。`MonTmp` 还没有调用 `TuneRx`。

### 构建

这台环境没有 CCES，也没有 `cc21k` 和 ARM 裸机编译器，所以这里没有真正链出 dxe。在装了 CCES 和 ADSP-SC594 Device Family Pack 的机器上：

1. 安装 CCES。本仓库 ARM 链接脚本由 CCES 3.0.3 生成，SHARC 启动文件记录的 Startup Code/LDF 工具版本是 6.3.2。用还能打开这些 ADSP-SC594 裸机工程的 CCES 版本。
2. 导入 `arm0`、`sharc1`、`sharc2`。处理器都是 **ADSP-SC594**，不要改成 21593。
3. 若缺少 `sharc*/system/startup_ldf/app.ldf`，在 CCES 里打开对应 `system.svc`，重新生成 Startup Code/LDF。这些 ldf 故意不进 git。
4. 不要定义 `SRU_FULL_INIT`。
5. 依次编 `arm0`、`sharc1`、`sharc2`。新增头文件路径：ARM 为 `src/driver`、`src/algo`、`../common`；SHARC1 为 `src/driver`、`../common`。
6. `adi_uart` / `adi_twi` / `adi_sport` / `adi_spu` / `adi_tmr` / `sru.h` 来自 DFP 的系统头路径，没有放进仓库。
7. 用 SC594 EZ-KIT 会话下载。ARM 在控制面初始化完成之后才使能两个 SHARC。

若本机 `sys/cache.h` 里 `flush_data_buffer` 或 `FLUSH_DATA_BUFFER_NO_INV` 名字不同，改 `sharc1/src/driver/sport/sport.c` 时保持对 `AudioStat` 做写回，不要只作废缓存。SPORT DMA 异常时先核对 `spu.c` 里的编号。
