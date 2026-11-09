#ifndef AD2428_H_
#define AD2428_H_

#include <stdint.h>

#include "ad2428_reg.h"

#ifdef __cplusplus
extern "C" {
#endif

void Ad24280Mon(void);
void Ad24281Mon(void);
void Ad24280Init(void);
void Ad24281Init(void);
uint32_t Ad24280NodeCount(void);
int Ad24280ScriptRan(void);
int Ad24281CfgImported(void);
int Ad24281ScriptRan(void);
/* 1 if reg is an imported table and becomes the active I2C script.
 * A default or empty table is rejected and the placeholder stays active. */
int Ad24281Bind(const Ad2428Reg *reg, uint32_t len);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // AD2428_H_
