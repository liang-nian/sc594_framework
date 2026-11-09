#include <services/int/adi_int.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "audio_flow.h"
#include "../xcore/xcore_sharc2.h"

static void AudioCallBack(uint32_t iid) {
  (void)iid;
  XcoreSharc2Service();
}

void AudioFlowInit(void) {
  adi_int_InstallHandler((uint32_t)INTR_SYS_SOFT0_INT,
                         (ADI_INT_HANDLER_PTR)AudioCallBack, NULL, true);
}
