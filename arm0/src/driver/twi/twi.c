#include <drivers/twi/adi_twi.h>
#include <stddef.h>
#include <stdint.h>

#include "twi.h"

/*
 * TWI2 is the SOMCRR codec / A2B / U6 bus. ARM owns the controller.
 * Prescale 12 assumes SCLK0 / 10 MHz, the same 125 MHz SCLK0 the 21593
 * timer uses. Retune if the SC594 CGU brings SCLK0 up differently.
 *
 * Each client Open/Stop pair is intentional: a NAK must not leak into the
 * next device. See doc/migration_sc594.md.
 */
#define TWI2_DEV          (2u)
#define TWI2_BIT_RATE     (100u) /* kHz */
#define TWI2_DUTY_CYCLE   (50u)
#define TWI2_PRESCALE     (12u)

static ADI_TWI_HANDLE twi2_dev;
static uint8_t twi2_mem[ADI_TWI_MEMORY_SIZE];
static uint8_t twi2_busy = 0u;

uint8_t Twi2IsIdle(void) {
  return twi2_busy == 0u;
}

void Twi2Open(void) {
  /* A second Open while this core still owns the controller corrupts the
   * session. Callers Stop before the next owner, including USBi. */
  if (twi2_busy) {
    return;
  }
  adi_twi_Open(TWI2_DEV, ADI_TWI_MASTER, twi2_mem, ADI_TWI_MEMORY_SIZE,
               &twi2_dev);
  adi_twi_SetPrescale(twi2_dev, TWI2_PRESCALE);
  adi_twi_SetBitRate(twi2_dev, TWI2_BIT_RATE);
  adi_twi_SetDutyCycle(twi2_dev, TWI2_DUTY_CYCLE);
  twi2_busy = 1u;
}

void Twi2DevAddrSet(uint8_t dev) {
  adi_twi_SetHardwareAddress(twi2_dev, dev);
}

void Twi2DevRegShtWr(uint8_t dev, uint8_t reg, uint8_t val) {
  uint8_t wr_val[2u];

  adi_twi_SetHardwareAddress(twi2_dev, dev);
  wr_val[0] = reg;
  wr_val[1] = val;
  adi_twi_Write(twi2_dev, wr_val, 2u, false);
}

uint8_t Twi2DevRegShtRd(uint8_t dev, uint8_t reg) {
  uint8_t read_val;

  adi_twi_SetHardwareAddress(twi2_dev, dev);
  adi_twi_Write(twi2_dev, &reg, 1u, true);
  adi_twi_Read(twi2_dev, &read_val, 1u, false);
  return read_val;
}

void Twi2RegShtWr(uint8_t reg, uint8_t val) {
  uint8_t wr_val[2];

  wr_val[0] = reg;
  wr_val[1] = val;
  adi_twi_Write(twi2_dev, wr_val, 2u, false);
}

uint8_t Twi2RegShtRd(uint8_t reg) {
  uint8_t read_val;

  adi_twi_Write(twi2_dev, &reg, 1u, true);
  adi_twi_Read(twi2_dev, &read_val, 1u, false);
  return read_val;
}

/* Register address is MSB-first. Address and payload are one I2C write.
 * A repeated start between them starts a second addressed write, and the
 * slave treats payload[0] as a register address. */
#define TWI2_LNG_PAYLOAD_MAX  (128u)

void Twi2DevRegLngWr(uint8_t dev, uint32_t reg, uint8_t reg_len, uint8_t* val,
                     uint16_t val_len) {
  uint8_t seq[4u + TWI2_LNG_PAYLOAD_MAX];
  uint16_t i;
  uint16_t n;

  if (reg_len != 1u && reg_len != 2u && reg_len != 4u) {
    return;
  }
  if (val == NULL ||
      ((uint32_t)reg_len + (uint32_t)val_len) > (uint32_t)sizeof(seq)) {
    return;
  }
  if (reg_len == 1u) {
    seq[0] = (uint8_t)(reg & 0xFFu);
  } else if (reg_len == 2u) {
    seq[0] = (uint8_t)((reg >> 8) & 0xFFu);
    seq[1] = (uint8_t)(reg & 0xFFu);
  } else {
    seq[0] = (uint8_t)((reg >> 24) & 0xFFu);
    seq[1] = (uint8_t)((reg >> 16) & 0xFFu);
    seq[2] = (uint8_t)((reg >> 8) & 0xFFu);
    seq[3] = (uint8_t)(reg & 0xFFu);
  }
  for (i = 0u; i < val_len; ++i) {
    seq[reg_len + i] = val[i];
  }
  n = (uint16_t)((uint16_t)reg_len + val_len);
  adi_twi_SetHardwareAddress(twi2_dev, dev);
  adi_twi_Write(twi2_dev, seq, n, false);
}

void Twi2Stop(void) {
  if (!twi2_busy) {
    return;
  }
  adi_twi_Close(twi2_dev);
  twi2_busy = 0u;
}
