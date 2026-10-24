#include <stdint.h>

#include "adau1962_reg.h"
#include "adau1962.h"
#include "log/log.h"
#include "sys_compat.h"
#include "twi/twi.h"

#define TIME_BND    (0xFFFFu)

static uint8_t adau1962_clk_ready = 0u;

uint8_t Adau1962ClkReady(void) {
  return adau1962_clk_ready;
}

static void Adau1962Cfg(uint8_t dev, Adau1962Reg* cfg, uint32_t len) {
  uint32_t i;
  uint8_t val;

  Twi2DevAddrSet(dev);
  for (i = 0; i < len; ++i) {
    Twi2RegShtWr(cfg[i].reg, cfg[i].val);
    val = Twi2RegShtRd(cfg[i].reg);
    if (val != cfg[i].val) {
      ShtLog("adau1962 cfg fail.\n");
    }
  }
}

static void Adau1962Pll(uint8_t dev, Adau1962Reg* pll, uint32_t len) {
  uint32_t delay, i;
  uint8_t val;

  Twi2DevAddrSet(dev);
  for (i = 0; i < len; ++i) {
    delay = TIME_BND;
    Twi2RegShtWr(pll[i].reg, pll[i].val);
    while (delay--) {
      BUSY_NOP();
    }
  }
  delay = 0u;
  val = Twi2RegShtRd(ADAU1962_PLL_CTL_CTRL1);
  /* PLL_CLK_CTRL1 bit 2 is PLL_LOCK (read-only). */
  while ((val & 0x4u) == 0u) {
    if (delay > TIME_BND) {
      ShtLog("adau1962 pll fail.\n");
      break;
    }
    val = Twi2RegShtRd(ADAU1962_PLL_CTL_CTRL1);
    delay++;
    BUSY_NOP();
  }
  if ((val & 0x4u) != 0u) {
    adau1962_clk_ready = 1u;
  }
}

void Adau19620Init(void) {
  adau1962_clk_ready = 0u;
  Twi2Open();
  Adau1962Pll(ADAU19620_DEV, adau19620_pll, ADAU19620_PLL_LEN);
  Adau1962Cfg(ADAU19620_DEV, adau19620_cfg, ADAU19620_CFG_LEN);
  Twi2Stop();
}
