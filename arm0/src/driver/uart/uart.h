#ifndef UART_H_
#define UART_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void Uart0Poll(void);
uint8_t Uart0Rd(uint8_t* val);
uint8_t Uart0Wr(uint8_t* val, uint32_t len);
void Uart0Init(void);
void Uart0Close(void);
void Uart0Mon(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // UART_H_
