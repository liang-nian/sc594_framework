#include <services/tmr/adi_tmr.h>
#include <stdint.h>

#include "timer.h"
#include "uart/uart.h"

/*
 * TMR0 exists to poll the UART RX ring. It follows UART onto ARM.
 * Period assumes SCLK0 = 125 MHz (same comment as the 21593 driver).
 */
#define TMR0_DEV    (0u)
#define TMR0_1MS    (125000u)

static ADI_TMR_HANDLE tmr0_dev;
static ADI_TMR_CFG_PARAMS tmr0_cfg;
static uint8_t tmr0_mem[ADI_TMR_MEMORY];

static void Tmr0Cfg(void) {
  tmr0_cfg.Mode = ADI_TMR_MODE_CONTINUOUS_PWMOUT;
  tmr0_cfg.IRQMode = ADI_TMR_IRQMODE_PERIOD;
  tmr0_cfg.PulsePolarity = false;
  tmr0_cfg.ClkInSource = ADI_TMR_CLKIN_SYSCLK;
  tmr0_cfg.InputAuxIn = false;
  tmr0_cfg.Period = TMR0_1MS;
  tmr0_cfg.Width = (TMR0_1MS >> 2u);
  tmr0_cfg.Delay = 0u;
  tmr0_cfg.EnableGracefulStop = true;
}

static void Tmr0Callback(void* param, uint32_t event, void* arg) {
  (void)param;
  (void)arg;
  switch ((ADI_TMR_EVENT)event) {
  case ADI_TMR_EVENT_DATA_INT:
    Uart0Poll();
    break;
  default:
    break;
  }
}

void Tmr0Init(void) {
  adi_tmr_Open(TMR0_DEV, tmr0_mem, ADI_TMR_MEMORY, Tmr0Callback, NULL,
               &tmr0_dev);
  Tmr0Cfg();
  adi_tmr_Enable(tmr0_dev, true);
}

void Tmr0En(uint8_t is_en) {
  adi_tmr_Enable(tmr0_dev, is_en);
}

void Tmr0Close(void) {
  adi_tmr_Enable(tmr0_dev, false);
  adi_tmr_Close(tmr0_dev);
}
