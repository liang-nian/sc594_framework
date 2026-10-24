/*****************************************************************************
 * sc594_framework_Core0.c
 *
 * ARM core. Owns UART, TWI, and A2B/codec register configuration.
 * SHARC1 is released only after BCLK/FS and the A2B script have finished,
 * so SPORT DMA starts against a running clock.
 *****************************************************************************/

#include "adi_initialize.h"
#include "sc594_framework_Core0.h"

#include <sys/platform.h>
#include <sys/adi_core.h>

#include "audio_flow/audio_flow.h"
#include "monitor/mon.h"

int main(void)
{
	/**
	 * Managed startup: GIC, generated pinmux (still empty), DAI pad enables,
	 * MCAPI. Board UART/TWI mux is applied inside AudioCtrlInit().
	 */
	adi_initComponents();

	AudioCtrlInit();

	/**
	 * Enable the SHARC cores after the control plane is up. SHARC1 then
	 * opens SPORT DMA. SHARC2 stays the idle secondary core.
	 */
	adi_core_enable(ADI_CORE_SHARC0);
	adi_core_enable(ADI_CORE_SHARC1);

	while (1) {
		MonTmp();
	}

	return 0;
}
