/*
 * tune.h — UART tuning parser (stub). Lives on ARM with the UART driver.
 */

#ifndef ALGO_TUNE_TUNE_H_
#define ALGO_TUNE_TUNE_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void TuneRx(uint8_t byte);
void TuneTx(uint8_t cmd, uint8_t* data, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif /* ALGO_TUNE_TUNE_H_ */
