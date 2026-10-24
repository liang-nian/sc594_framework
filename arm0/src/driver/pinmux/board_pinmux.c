#include <stdint.h>
#include <sys/platform.h>

#include "board_pinmux.h"

/*
 * EV-SC594-SOM + EV-SOMCRR-EZKIT pinmux for the control bus.
 *
 * The Pin Multiplexing add-in is installed, but its generated
 * adi_initpinmux() is still a no-op. These bits are the SC594 EZ-KIT
 * selection (same PORTA functions the 21593 carrier uses):
 *   UART0 TX/RX/RTS/CTS = PA06..PA09, mux function 1
 *   TWI2  SCL/SDA       = PA14/PA15, mux function 0
 * Confirmed against the SC594 Linux pinctrl (ALT1 UART, ALT0 I2C2).
 *
 * Read-modify-write so a later plugin setting on other PORTA pins survives.
 * TWI function 0 is encoded by clearing the two mux bits.
 */

#define UART0_TX_SHIFT   (12u)
#define UART0_RX_SHIFT   (14u)
#define UART0_RTS_SHIFT  (16u)
#define UART0_CTS_SHIFT  (18u)
#define TWI2_SCL_SHIFT   (28u)
#define TWI2_SDA_SHIFT   (30u)

#define PORTA_MUX_PAIR(shift) (0x3u << (shift))

#define UART0_TX_FER   (1u << 6)
#define UART0_RX_FER   (1u << 7)
#define UART0_RTS_FER  (1u << 8)
#define UART0_CTS_FER  (1u << 9)
#define TWI2_SCL_FER   (1u << 14)
#define TWI2_SDA_FER   (1u << 15)

void BoardPinmux(void) {
  uint32_t mux = *pREG_PORTA_MUX;
  uint32_t fer = *pREG_PORTA_FER;

  mux &= ~(PORTA_MUX_PAIR(UART0_TX_SHIFT) | PORTA_MUX_PAIR(UART0_RX_SHIFT) |
           PORTA_MUX_PAIR(UART0_RTS_SHIFT) | PORTA_MUX_PAIR(UART0_CTS_SHIFT) |
           PORTA_MUX_PAIR(TWI2_SCL_SHIFT) | PORTA_MUX_PAIR(TWI2_SDA_SHIFT));
  mux |= (1u << UART0_TX_SHIFT) | (1u << UART0_RX_SHIFT) |
         (1u << UART0_RTS_SHIFT) | (1u << UART0_CTS_SHIFT);

  fer |= UART0_TX_FER | UART0_RX_FER | UART0_RTS_FER | UART0_CTS_FER |
         TWI2_SCL_FER | TWI2_SDA_FER;

  *pREG_PORTA_MUX = mux;
  *pREG_PORTA_FER = fer;
}
