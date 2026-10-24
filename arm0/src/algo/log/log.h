/*
 * log.h ? short UART log helper (ShtLog declared for callers via include path / C linkage).
 */

#ifndef ALGO_LOG_LOG_H_
#define ALGO_LOG_LOG_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint8_t ShtLog(const char* format, ...);
uint8_t LngLog(const char* level, const char* format, ...);

#ifdef __cplusplus
}
#endif

#endif /* ALGO_LOG_LOG_H_ */
