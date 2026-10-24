#include <stdint.h>

#include "switch.h"
#include "switch_reg.h"
#include "sys_compat.h"
#include "twi/twi.h"

#define TIME_BND    (0xFFFFu)

static void SwCfg(uint8_t dev, SwReg* cfg, uint32_t len) {
  uint32_t i;
  uint32_t delay = TIME_BND;

  Twi2DevAddrSet(dev);
  for (i = 0; i < len; ++i) {
    Twi2RegShtWr(cfg[i].reg, cfg[i].val);
  }
  while (delay--) {
    BUSY_NOP();
  }
}

void Sw0Init(void) {
  Twi2Open();
  SwCfg(SW0_DEV, sw0_en, SW0_EN_LEN);
  SwCfg(SW0_DEV, sw0_rst, SW0_RST_LEN);
  Twi2Stop();
}
