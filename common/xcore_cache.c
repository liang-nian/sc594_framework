#include "xcore_proto.h"

#include <stdint.h>

#if defined(__ADSPSHARC__)
#include <sys/cache.h>

void XcoreWriteback(void *addr, uint32_t bytes) {
  if (addr != NULL && bytes > 0u) {
    flush_data_buffer(addr, (uint8_t *)addr + bytes - 1u, ADI_FLUSH_DATA_NOINV);
  }
}

void XcoreInvalidate(void *addr, uint32_t bytes) {
  if (addr != NULL && bytes > 0u) {
    /* CCES 3.0.3 pairs this with ADI_FLUSH_DATA_NOINV, which sport.c
     * already uses. INV writeback-invalidates. Readers do not dirty
     * the line they are about to read, so a clean writeback is a no-op
     * and the invalidate drops a stale SHARC line. */
    flush_data_buffer(addr, (uint8_t *)addr + bytes - 1u, ADI_FLUSH_DATA_INV);
  }
}

#elif defined(__arm__) || defined(__ADSPARM__)

void XcoreWriteback(void *addr, uint32_t bytes) {
  (void)addr;
  (void)bytes;
  /* 0x20038000..0x2003FFFF is ADI_MMU_RW_UNCACHED in apt.c, so the A5
   * data cache does not hold the block. DSB orders the stores against
   * the flag word that follows. */
  __asm__ volatile("dsb" ::: "memory");
}

void XcoreInvalidate(void *addr, uint32_t bytes) {
  (void)addr;
  (void)bytes;
  __asm__ volatile("dsb" ::: "memory");
}

#else
#error "xcore_cache.c is compiled only for SHARC or ARM"
#endif
