#ifndef SYS_COMPAT_H_
#define SYS_COMPAT_H_

/*
 * Busy-wait nop. SHARC accepts `asm("nop;")`. The ARM GCC in CCES does not
 * use that spelling, and it has no seg_l1_block1 pragma.
 */
#if defined(__ADSPSHARC__)
#define BUSY_NOP() asm("nop;")
#else
#define BUSY_NOP() __asm__ volatile("nop")
#endif

#endif /* SYS_COMPAT_H_ */
