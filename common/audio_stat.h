#ifndef AUDIO_STAT_H_
#define AUDIO_STAT_H_

#include <stdint.h>

/*
 * SHARC1 publishes SPORT callback CPU-load counters here.
 * ARM prints them when the UART monitor gets command 0xCC.
 *
 * Address is the last 256 bytes of the ARM uncached L2 window
 * (apt.c: 0x20025000..0x2003FFFF). The linker does not place any
 * other object in that tail. Both cores use this absolute address;
 * MCAPI is left for larger messages.
 */
#define AUDIO_STAT_ADDR  (0x2003FF00u)
#define AUDIO_STAT_MAGIC (0xA5A500CCu)

typedef struct AudioStat {
  volatile uint32_t magic;
  volatile float cpu_load;
  volatile float max_cpu_load;
  volatile float ave_cpu_load;
} AudioStat;

#endif /* AUDIO_STAT_H_ */
