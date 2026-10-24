#ifndef ADAU1979_REG_H_
#define ADAU1979_REG_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ADAU1979_REG_POWER              0x00
#define ADAU1979_REG_PLL					      0x01
#define ADAU1979_REG_BOOST					    0x02
#define ADAU1979_REG_MICBIAS				    0x03
#define ADAU1979_REG_BLOCK_POWER_SAI    0x04
#define ADAU1979_REG_SAI_CTRL0				  0x05
#define ADAU1979_REG_SAI_CTRL1				  0x06
#define ADAU1979_REG_CMAP12					    0x07
#define ADAU1979_REG_CMAP34					    0x08
#define ADAU1979_REG_SAI_OVERTEMP			  0x09
#define ADAU1979_REG_POST_ADC_GAIN1 		0x0A
#define ADAU1979_REG_POST_ADC_GAIN2 		0x0B
#define ADAU1979_REG_POST_ADC_GAIN3 		0x0C
#define ADAU1979_REG_POST_ADC_GAIN4 		0x0D
#define ADAU1979_REG_MISC_CONTROL			  0x0E
#define ADAU1979_REG_ADC_CLIP				    0x19
#define ADAU1979_REG_DC_HPF_CAL				  0x1A

typedef struct Adau1979Reg{
  uint8_t reg;
  uint8_t val;
} Adau1979Reg;

// Dev0, fs rising pol pulse, tdm16, 48 khz, tx rising bclk, salve, msbf,
// early sync.
#define ADAU19790_CFG_LEN   (16u)
#define ADAU19790_PLL_LEN   (2u)
#define ADAU19790_DEV       (0x11u)

extern Adau1979Reg adau19790_cfg[ADAU19790_CFG_LEN];
extern Adau1979Reg adau19790_pll[ADAU19790_PLL_LEN];

#ifdef __cplusplus
} // extern "C"
#endif

#endif // ADAU1979_REG_H_
