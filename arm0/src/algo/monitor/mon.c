#include <stdint.h>

#include "ad2428/ad2428.h"
#include "log/log.h"
#include "mon.h"
#include "uart/uart.h"
#include "xcore/xcore_arm.h"

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
  XcoreDspStat sh1;
  XcoreDspStat sh2;

  ShtLog("param gen %u sharc1 ack %u sharc2 ack %u\n",
         (unsigned)XcoreArmPublished(),
         (unsigned)XcoreArmAck(1u),
         (unsigned)XcoreArmAck(2u));
  ShtLog("a2b1 block %u\n", (unsigned)XcoreArmA2b1Block());
  if (XcoreArmReadStat(1u, &sh1) != 0) {
    ShtLog("cpu load: sharc1 has not published yet.\n");
  } else {
    LogFixed3("cpu load", sh1.cpu_load);
    LogFixed3("max cpu load", sh1.max_cpu_load);
    LogFixed3("ave cpu load", sh1.ave_cpu_load);
  }
  if (XcoreArmReadStat(2u, &sh2) != 0) {
    ShtLog("core2 cpu load: sharc2 has not published yet.\n");
  } else {
    LogFixed3("core2 cpu load", sh2.cpu_load);
    LogFixed3("core2 max cpu load", sh2.max_cpu_load);
    LogFixed3("core2 ave cpu load", sh2.ave_cpu_load);
  }
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
