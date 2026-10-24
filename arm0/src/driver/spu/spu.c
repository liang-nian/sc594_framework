#include <services/spu/adi_spu.h>
#include <stddef.h>
#include <stdint.h>

#include "spu.h"

/*
 * SPU write-protect / secure-master ids for the ADSP-2159x / SC594 family.
 * The 21593 driver enabled SP0A..SP2B at 63..68 and UART0 at 29 / DMA 79..80.
 * Those numbers line up with one id per half-SPORT:
 *   SP0A = 63 ... SP7B = 78, then UART0 RX DMA = 79, TX DMA = 80.
 * SC594 audio uses SPORT1 (A2B0, DAI0), SPORT4 (codec, DAI1) and SPORT5
 * (legacy A2B1 pins, DAI1), so the set below replaces SP0/SP2.
 * Confirm against the DFP enum if a DMA channel faults.
 */
#define SPU0_DEV            (0u)
#define SPU0_SP1A           (65u)
#define SPU0_SP1B           (66u)
#define SPU0_SP4A           (71u)
#define SPU0_SP4B           (72u)
#define SPU0_SP5A           (73u)
#define SPU0_SP5B           (74u)
#define SPU0_UART0          (29u)
#define SPU0_UART0_RX_DMA   (79u)
#define SPU0_UART0_TX_DMA   (80u)
#define SPU0_SVC_NUM        (9u)

static ADI_SPU_HANDLE spu0_dev;
static uint8_t spu0_mem[ADI_SPU_MEMORY_SIZE];
static uint32_t spu0_target[SPU0_SVC_NUM] = {
    SPU0_SP1A, SPU0_SP1B,
    SPU0_SP4A, SPU0_SP4B,
    SPU0_SP5A, SPU0_SP5B,
    SPU0_UART0, SPU0_UART0_RX_DMA, SPU0_UART0_TX_DMA
};

void Spu0Init(void) {
  uint32_t i;

  adi_spu_Init(SPU0_DEV, spu0_mem, NULL, NULL, &spu0_dev);

  for (i = 0; i < SPU0_SVC_NUM; ++i) {
    adi_spu_EnableMasterSecure(spu0_dev, spu0_target[i], true);
  }
}
