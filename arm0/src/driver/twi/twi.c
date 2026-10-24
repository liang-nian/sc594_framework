#include <drivers/twi/adi_twi.h>
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

void Twi2Open(void) {
  adi_twi_Open(TWI2_DEV, ADI_TWI_MASTER, twi2_mem, ADI_TWI_MEMORY_SIZE,
               &twi2_dev);
  adi_twi_SetPrescale(twi2_dev, TWI2_PRESCALE);
  adi_twi_SetBitRate(twi2_dev, TWI2_BIT_RATE);
  adi_twi_SetDutyCycle(twi2_dev, TWI2_DUTY_CYCLE);
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

/* Memory is little-endian. A2B register addresses go on the wire MSB first. */
void Twi2DevRegLngWr(uint8_t dev, uint32_t reg, uint8_t reg_len, uint8_t* val,
                     uint16_t val_len) {
  uint8_t seq[4];

  if (reg_len == 1) {
    seq[0] = (uint8_t)(reg & 0xFFu);
  } else if (reg_len == 2) {
    seq[0] = (uint8_t)((reg >> 8) & 0xFFu);
    seq[1] = (uint8_t)(reg & 0xFFu);
  } else if (reg_len == 4) {
    seq[0] = (uint8_t)((reg >> 24) & 0xFFu);
    seq[1] = (uint8_t)((reg >> 16) & 0xFFu);
    seq[2] = (uint8_t)((reg >> 8) & 0xFFu);
    seq[3] = (uint8_t)(reg & 0xFFu);
  } else {
    return;
  }
  adi_twi_SetHardwareAddress(twi2_dev, dev);
  adi_twi_Write(twi2_dev, seq, reg_len, true);
  adi_twi_Write(twi2_dev, val, val_len, false);
}

void Twi2Stop(void) {
  adi_twi_Close(twi2_dev);
}
