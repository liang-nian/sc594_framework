#ifndef AD2428_H_
#define AD2428_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void Ad24280Mon(void);
void Ad24281Mon(void);
void Ad24280Init(void);
void Ad24281Init(void);
uint32_t Ad24280NodeCount(void);
int Ad24280ScriptRan(void);
int Ad24281ScriptReady(void);
int Ad24281ScriptRan(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // AD2428_H_
