#include <stdint.h>

#include "adau1979.h"
#include "adau1979_reg.h"
#include "log/log.h"
#include "sys_compat.h"
#include "twi/twi.h"

#define TIME_BND    (0xFFFFu)

static void Adau1979Cfg(uint8_t dev, Adau1979Reg* cfg, uint32_t len) {
  uint32_t i;
  uint8_t val;

  Twi2DevAddrSet(dev);
  for (i = 0; i < len; ++i) {
    Twi2RegShtWr(cfg[i].reg, cfg[i].val);
    val = Twi2RegShtRd(cfg[i].reg);
    if (val != cfg[i].val) {
      ShtLog("adau1979 cfg fail.\n");
    }
  }
}

static void Adau1979Pll(uint8_t dev, Adau1979Reg* pll, uint32_t len) {
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
  val = Twi2RegShtRd(ADAU1979_REG_PLL);
  while (!((val & 0x80) >> 7)) {
    if (delay > TIME_BND) {
      ShtLog("adau1979 pll fail.\n");
      break;
    }
    val = Twi2RegShtRd(ADAU1979_REG_PLL);
    delay++;
    BUSY_NOP();
  }
}

void Adau19790Init(void) {
  Twi2Open();
  Adau1979Pll(ADAU19790_DEV, adau19790_pll, ADAU19790_PLL_LEN);
  Adau1979Cfg(ADAU19790_DEV, adau19790_cfg, ADAU19790_CFG_LEN);
  Twi2Stop();
}
