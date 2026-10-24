#ifndef ADAU1962_REG_H_
#define ADAU1962_REG_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ADAU1962_PLL_CTL_CTRL0    0x00
#define ADAU1962_PLL_CTL_CTRL1	  0x01
#define ADAU1962_PDN_CTRL_1 			0x02
#define ADAU1962_PDN_CTRL_2			  0x03
#define ADAU1962_PDN_CTRL_3 			0x04
#define ADAU1962_TEMP_STAT  			0x05
#define ADAU1962_DAC_CTRL0  			0x06
#define ADAU1962_DAC_CTRL1   			0x07
#define ADAU1962_DAC_CTRL2  			0x08
#define ADAU1962_DAC_MUTE1			  0x09
#define ADAU1962_DAC_MUTE2  			0x0A
#define ADAU1962_MSTR_VOL   			0x0B
#define ADAU1962_DAC1_VOL   			0x0C
#define ADAU1962_DAC2_VOL			    0x0D
#define ADAU1962_DAC3_VOL				  0x0E
#define ADAU1962_DAC4_VOL			    0x0F
#define ADAU1962_DAC5_VOL			    0x10
#define ADAU1962_DAC6_VOL			    0x11
#define ADAU1962_DAC7_VOL			    0x12
#define ADAU1962_DAC8_VOL	     		0x13
#define ADAU1962_DAC9_VOL   			0x14
#define ADAU1962_DAC10_VOL			  0x15
#define ADAU1962_DAC11_VOL			  0x16
#define ADAU1962_DAC12_VOL			  0x17
#define ADAU1962_PAD_STRGTH			  0x1C
#define ADAU1962_DAC_PWR1			    0x1D
#define ADAU1962_DAC_PWR2			    0x1E
#define ADAU1962_DAC_PWR3			    0x1F

typedef struct Adau1962Reg {
  uint8_t reg;
  uint8_t val;
} Adau1962Reg;

// Dev0, master, fs 48khz, fs rising pol pulse, tdm16, 48 khz, early sync,
// msbf, sampling falling edge.
#define ADAU19620_CFG_LEN   (28u)
#define ADAU19620_PLL_LEN   (3u)
#define ADAU19620_DEV       (0x04u)

extern Adau1962Reg adau19620_cfg[ADAU19620_CFG_LEN];
extern Adau1962Reg adau19620_pll[ADAU19620_PLL_LEN];

#ifdef __cplusplus
} // extern "C"
#endif

#endif // ADAU1962_REG_H_
