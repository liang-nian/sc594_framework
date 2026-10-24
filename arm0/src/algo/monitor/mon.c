#include <stdint.h>

#include "ad2428/ad2428.h"
#include "audio_stat.h"
#include "log/log.h"
#include "mon.h"
#include "uart/uart.h"

static void LogFixed3(const char *label, float value) {
  int whole;
  int frac;

  if (value < 0.f) {
    value = 0.f;
  }
  whole = (int)value;
  frac = (int)((value - (float)whole) * 1000.f);
  if (frac < 0) {
    frac = 0;
  }
  if (frac > 999) {
    frac = 999;
  }
  ShtLog("%s: %d.%03d\n", label, whole, frac);
}

static void CpuMsgMon(void) {
  AudioStat *st = (AudioStat *)AUDIO_STAT_ADDR;

  if (st->magic != AUDIO_STAT_MAGIC) {
    ShtLog("cpu load: sharc1 has not published yet.\n");
    return;
  }
  LogFixed3("cpu load", st->cpu_load);
  LogFixed3("max cpu load", st->max_cpu_load);
  LogFixed3("ave cpu load", st->ave_cpu_load);
}

static void MonProcess(uint8_t type) {
  switch (type) {
    case 0xAAu:
      Ad24280Mon();
      Ad24281Mon();
      break;
    case 0xBBu:
      Uart0Mon();
      break;
    case 0xCCu:
      CpuMsgMon();
      break;
    default:
      break;
  }
}

void MonTmp(void) {
  uint8_t type = 0u;

  while (!Uart0Rd(&type)) {
    MonProcess(type);
  }
}
