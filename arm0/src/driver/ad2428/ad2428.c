#include <stdint.h>

#include "ad2428.h"
#include "ad2428_reg.h"
#include "log/log.h"
#include "twi/twi.h"

#define TIME_BND        (0x100000u)
#define DATA_ERR_BND    (7u)

typedef struct Ad2428Msg {
  uint32_t int_cnt;
  uint32_t be_cnt;
  uint32_t tot_becnt;
  uint32_t data_err_cnt;
  uint32_t poll_idx;
  uint8_t int_src;
  uint8_t int_type;
  uint8_t node_num;
} Ad2428Msg;

static Ad2428Msg ad24280_mon = {0};
static Ad2428Msg ad24281_mon = {0};

static void Ad2428CfgDelay(uint32_t delay_val) {
  volatile uint32_t delay_cnt = delay_val * TIME_BND;
  for (; delay_cnt > 0u; delay_cnt--) {
  }
}

static void Ad2428Mon(uint8_t master_dev, Ad2428Msg* mon) {
  uint8_t int_src = 0u;
  mon->poll_idx++;
  int_src = Twi2DevRegShtRd(master_dev, AD2428_REG_INTSRC);
  if (int_src) {
    mon->int_src = int_src;
    mon->int_type = Twi2DevRegShtRd(master_dev, AD2428_REG_INTTYPE);
    if (mon->int_type < DATA_ERR_BND) {
      mon->data_err_cnt++;
    }
    mon->int_cnt++;
  }
  mon->be_cnt = Twi2DevRegShtRd(master_dev, AD2428_REG_BECNT);
  mon->tot_becnt += mon->be_cnt;
  Twi2DevRegShtWr(master_dev, AD2428_REG_BECNT, 0u);

  ShtLog("ad2428 %d mon:\n", master_dev);
  ShtLog("int cnt: %u.\n", mon->int_cnt);
  ShtLog("be cnt: %u.\n", mon->be_cnt);
  ShtLog("tot be cnt: %u.\n", mon->tot_becnt);
  ShtLog("int src: %u.\n", mon->int_src);
  ShtLog("int type: %u.\n", mon->int_type);
  ShtLog("node num: %u.\n", mon->node_num);
}

static void Ad2428Cfg(uint8_t master_dev, Ad2428Reg* cfg, uint32_t cfg_len,
                      Ad2428Msg* mon) {
  uint32_t timer = 0;
  uint8_t is_node_found = 0u;
  uint8_t is_master_run = 0u;

  uint8_t* val_ptr;
  uint8_t i2c_addr, a2b_cmd, val_width, reg_width, rd_val;
  uint16_t val_len = 0;
  uint32_t reg, delay_val, i;
  uint32_t last_reg = 0;

  for (i = 0; i < cfg_len; ++i) {
    i2c_addr = cfg[i].dev;
    a2b_cmd = cfg[i].op_code;
    reg_width = cfg[i].reg_width;
    reg = cfg[i].reg;
    val_width = cfg[i].val_width;
    val_len = cfg[i].val_len;
    val_ptr = cfg[i].val_ptr;

    if (val_width > 1u) {
      return;
    }
    if (a2b_cmd == WRITE) {
      if (val_len == 1u && reg_width == 1) {
        Twi2DevRegShtWr(i2c_addr, (uint8_t)reg, *val_ptr);
      } else {
        Twi2DevRegLngWr(i2c_addr, reg, reg_width, val_ptr, val_len);
      }
    } else if (a2b_cmd == READ) {
      rd_val = Twi2DevRegShtRd(i2c_addr, (uint8_t)reg);
      (void)rd_val;
    } else if (a2b_cmd == DELAY) {
      if (val_len == 2u) {
        delay_val = val_ptr[1];
      } else {
        delay_val = val_ptr[0];
      }
      Ad2428CfgDelay(delay_val);
      if (i == 1) {
        timer = 0u;
        while (!is_master_run) {
          if (timer > TIME_BND) {
            ShtLog("master run timeout.\n");
            break;
          }
          if (Twi2DevRegShtRd(master_dev, AD2428_REG_INTSRC) &&
              Twi2DevRegShtRd(master_dev, AD2428_REG_INTTYPE) ==
                  AD2428_MSTR_RUNNING) {
            ShtLog("master run.\n");
            is_master_run = 1u;
          }
          timer++;
        }
      }
      if (last_reg == 0x13u) {
        timer = 0u;
        while (!is_node_found) {
          if (timer > TIME_BND) {
            ShtLog("slave %u discover timeout.\n",
                   (unsigned)(mon->node_num + 1u));
            break;
          }
          if (Twi2DevRegShtRd(master_dev, AD2428_REG_INTSRC) &&
              Twi2DevRegShtRd(master_dev, AD2428_REG_INTTYPE) ==
                  AD2428_DSCDONE) {
            mon->node_num++;
            ShtLog("slave %u discovered.\n", mon->node_num);
            is_node_found = 1u;
          }
          timer++;
        }
        is_node_found = 0u;
      }
    }
    last_reg = reg;
  }
}

void Ad24280Mon(void) {
  Twi2Open();
  Ad2428Mon(AD24280_MASTER_DEV, &ad24280_mon);
  Twi2Stop();
}

void Ad24281Mon(void) {
  /* Carrier has one A2B master. Keep the symbol, do not touch the bus. */
  (void)ad24281_mon;
}

void Ad24280Init(void) {
  Twi2Open();
  Ad2428Cfg(AD24280_MASTER_DEV, ad24280_cfg, AD24280_CFG_LEN, &ad24280_mon);
  Twi2Stop();
}

void Ad24281Init(void) {
  ShtLog("ad24281 skipped: no 2nd A2B on EV-SOMCRR-EZKIT.\n");
}
