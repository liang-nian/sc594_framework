#ifndef XCORE_ARM_H_
#define XCORE_ARM_H_

#include <stdint.h>

#include "../../../../common/xcore_abi.h"

#ifdef __cplusplus
extern "C" {
#endif

void XcoreArmBoot(uint32_t a2b0_nodes, int a2b0_script_ran, int a2b1_imported,
                  int a2b1_script_ran);
int XcoreArmReadStat(uint32_t core, XcoreDspStat *stat);
uint32_t XcoreArmAck(uint32_t core);
uint32_t XcoreArmPublished(void);
uint32_t XcoreArmA2b1Cfg(void);
uint32_t XcoreArmA2b1Mute(void);

#ifdef __cplusplus
}
#endif

#endif /* XCORE_ARM_H_ */
