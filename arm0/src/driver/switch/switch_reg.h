#ifndef SWITCH_REG_H_
#define SWITCH_REG_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SwReg {
  uint8_t reg;
  uint8_t val;
} SwReg;

// Sw0, enable and reset adau1979 and adau1962.
#define SW0_DEV       (0x22u)
#define SW0_RST_LEN   (4u)
#define SW0_EN_LEN    (4u)

extern SwReg sw0_en[SW0_EN_LEN];
extern SwReg sw0_rst[SW0_RST_LEN];

#ifdef __cplusplus
} // extern "C"
#endif

#endif // SWITCH_REG_H_
