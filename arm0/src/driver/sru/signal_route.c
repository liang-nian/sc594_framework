#include <sru.h>
#include <sys/platform.h>

#include "signal_route.h"

/*
 * EV-SOMCRR-EZKIT audio nets, retargeted onto the SC594 SRU.
 *
 * 21593 could SRU() a DAI1 pin straight into SPORT0. On SC594 (and 21593's
 * shared 2159x DAI), SPORT0-3 are DAI0 and SPORT4-7 are DAI1. Destinations
 * on DAI1 use SRU2(); destinations on DAI0 use SRU(). The DRU publishes
 * every DAI1 source into the DAI0 SRU, so the codec BCLK/FS on DAI1_PB05 /
 * DAI1_PB04 still fans out to the A2B0 pins on DAI0.
 *
 * Pin directions match the 21593 carrier route:
 *   DAI1 PB05/PB04  in   ADAU1962 BCLK/FS (clock master)
 *   DAI1 PB01       out  DAC data     SPORT4A
 *   DAI1 PB06       in   ADC data     SPORT4B
 *   DAI1 PB12/PB20  out  ADC BCLK/FS
 *   DAI0 PB03/PB04  out  A2B0 BCLK/FS (copy of the DAC clocks)
 *   DAI0 PB05/PB06  out  A2B0 DTX     SPORT1A
 *   DAI0 PB01/PB02  in   A2B0 DRX     SPORT1B
 *   DAI1 PB08/PB09  out  legacy A2B1 clocks (no second transceiver)
 *   DAI1 PB19/PB10  out  legacy A2B1 TX  SPORT5A
 *   DAI1 PB11/PB07  in   legacy A2B1 RX  SPORT5B
 *
 * adi_SRU_Init() in the generated file only enables the DAI input pads
 * unless SRU_FULL_INIT is set. That full-init map is a straight-through
 * SPORT-to-adjacent-pin template and must stay off; it fights this route.
 * SruInit() runs after adi_initComponents() and programs the real nets.
 */
void SruInit(void) {
  *pREG_PADS0_DAI0_IE = BITM_PADS_DAI0_IE_VALUE;
  *pREG_PADS0_DAI1_IE = BITM_PADS_DAI1_IE_VALUE;

  /* DAC BCLK source: DAI1 pin 5, pin buffer is an input. */
  SRU2(LOW, DAI1_PBEN05_I);
  SRU2(DAI1_PB05_O, SPT4_ACLK_I);
  SRU2(DAI1_PB05_O, SPT4_BCLK_I);
  SRU2(DAI1_PB05_O, SPT5_ACLK_I);
  SRU2(DAI1_PB05_O, SPT5_BCLK_I);
  /* BCLK to the ADC on DAI1 pin 12. */
  SRU2(HIGH, DAI1_PBEN12_I);
  SRU2(DAI1_PB05_O, DAI1_PB12_I);
  /* BCLK to A2B0 on DAI0 pin 3 (cross-DAI via the DRU). */
  SRU(HIGH, DAI0_PBEN03_I);
  SRU(DAI1_PB05_O, DAI0_PB03_I);
  SRU(DAI1_PB05_O, SPT1_ACLK_I);
  SRU(DAI1_PB05_O, SPT1_BCLK_I);
  /* BCLK to the unused A2B1 pins on DAI1 pin 8. */
  SRU2(HIGH, DAI1_PBEN08_I);
  SRU2(DAI1_PB05_O, DAI1_PB08_I);

  /* DAC FS source: DAI1 pin 4. */
  SRU2(LOW, DAI1_PBEN04_I);
  SRU2(DAI1_PB04_O, SPT4_AFS_I);
  SRU2(DAI1_PB04_O, SPT4_BFS_I);
  SRU2(DAI1_PB04_O, SPT5_AFS_I);
  SRU2(DAI1_PB04_O, SPT5_BFS_I);
  SRU2(HIGH, DAI1_PBEN20_I);
  SRU2(DAI1_PB04_O, DAI1_PB20_I);
  SRU(HIGH, DAI0_PBEN04_I);
  SRU(DAI1_PB04_O, DAI0_PB04_I);
  SRU(DAI1_PB04_O, SPT1_AFS_I);
  SRU(DAI1_PB04_O, SPT1_BFS_I);
  SRU2(HIGH, DAI1_PBEN09_I);
  SRU2(DAI1_PB04_O, DAI1_PB09_I);

  /* SPORT4A data to the DAC, DAI1 pin 1. */
  SRU2(HIGH, DAI1_PBEN01_I);
  SRU2(SPT4_AD0_O, DAI1_PB01_I);
  /* SPORT4B data from the ADC, DAI1 pin 6. */
  SRU2(LOW, DAI1_PBEN06_I);
  SRU2(DAI1_PB06_O, SPT4_BD0_I);

  /* SPORT1A data to A2B0, DAI0 pins 5 and 6. */
  SRU(HIGH, DAI0_PBEN05_I);
  SRU(SPT1_AD0_O, DAI0_PB05_I);
  SRU(HIGH, DAI0_PBEN06_I);
  SRU(SPT1_AD1_O, DAI0_PB06_I);
  /* SPORT1B data from A2B0, DAI0 pins 1 and 2. */
  SRU(LOW, DAI0_PBEN01_I);
  SRU(DAI0_PB01_O, SPT1_BD0_I);
  SRU(LOW, DAI0_PBEN02_I);
  SRU(DAI0_PB02_O, SPT1_BD1_I);

  /* Legacy A2B1 pins on DAI1, SPORT5. No second transceiver on the carrier. */
  SRU2(HIGH, DAI1_PBEN19_I);
  SRU2(SPT5_AD0_O, DAI1_PB19_I);
  SRU2(HIGH, DAI1_PBEN10_I);
  SRU2(SPT5_AD1_O, DAI1_PB10_I);
  SRU2(LOW, DAI1_PBEN11_I);
  SRU2(DAI1_PB11_O, SPT5_BD0_I);
  SRU2(LOW, DAI1_PBEN07_I);
  SRU2(DAI1_PB07_O, SPT5_BD1_I);
}
