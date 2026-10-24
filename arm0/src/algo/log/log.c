#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

#include "log.h"
#include "uart/uart.h"

static char msg[128];

uint8_t ShtLog(const char* format, ...) {
  va_list args;
  int len;

  va_start(args, format);
  len = vsnprintf(msg, sizeof(msg), format, args);
  va_end(args);

  if (len <= 0 || (size_t)len >= sizeof(msg)) {
    return 0u;
  }

  return Uart0Wr((uint8_t*)msg, (uint32_t)len);
}

uint8_t LngLog(const char* level, const char* format, ...) {
  (void)level;
  (void)format;
  return 0u;
}
