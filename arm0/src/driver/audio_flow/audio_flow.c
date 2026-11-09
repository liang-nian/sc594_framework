#include "audio_flow.h"
#include "xcore/xcore_arm.h"
#include "ad2428/ad2428.h"
#include "adau1962/adau1962.h"
#include "adau1979/adau1979.h"
#include "pinmux/board_pinmux.h"
#include "spu/spu.h"
#include "sru/signal_route.h"
#include "switch/switch.h"
#include "timer/timer.h"
#include "uart/uart.h"

/*
 * ARM half of the 21593 AudioFlowInit chain.
 *
 * Order is the 21593 order with SPORT DMA removed (that starts on SHARC1
 * only after adi_core_enable, so clocks already exist):
 *   pinmux, SPU, UART, timer, U6 switch, SRU, ADAU1962, ADAU1979,
 *   AD24280, AD24281 (no TWI while its script is empty), then the
 *   shared control block. SHARC cores are enabled after this returns.
 * UART RX DMA is armed before TMR0. The 1 ms callback is Uart0Poll.
 *
 * USBi / A2B rule: BCLK and FS must be running before any A2B I2C, and the
 * firmware must not hold TWI2 while USBi is plugged in. ADAU1962 is the
 * clock master and is programmed before Ad24280Init(). Every TWI client
 * Stop()s before the next client Open()s, so TWI2 is idle between them.
 * Do not attach USBi during this boot path. To capture a new SigmaStudio
 * script, stop before Ad24280Init(), confirm clocks, then plug USBi in.
 */
void AudioCtrlInit(void) {
  BoardPinmux();
  Spu0Init();
  Uart0Init();
  Tmr0Init();
  Sw0Init();
  SruInit();
  Adau19620Init();
  Adau19790Init();
  Ad24280Init();
  /* Returns before any TWI access while ad24281_cfg is the empty stub.
   * SPORT5 is already routed and is started later on SHARC1. */
  Ad24281Init();
  XcoreArmBoot(Ad24280NodeCount(), Ad24280ScriptRan(), Ad24281CfgImported(),
               Ad24281ScriptRan());
}
