#ifndef TIMER_H_
#define TIMER_H_

#ifdef __cplusplus
extern "C" {
#endif

void Tmr0Init(void);

void Tmr0En(uint8_t is_en);

void Tmr0Close(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // TIMER_H_
