#ifndef TWI_H_
#define TWI_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void Twi2Open(void);

uint8_t Twi2IsIdle(void);

void Twi2DevAddrSet(uint8_t dev);

void Twi2DevRegShtWr(uint8_t dev, uint8_t reg, uint8_t val);

uint8_t Twi2DevRegShtRd(uint8_t dev, uint8_t reg);

void Twi2RegShtWr(uint8_t reg, uint8_t val);

uint8_t Twi2RegShtRd(uint8_t reg);

void Twi2DevRegLngWr(uint8_t dev, uint32_t reg, uint8_t reg_len, uint8_t* val,
                     uint16_t val_len);

void Twi2Stop(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // TWI_H_
