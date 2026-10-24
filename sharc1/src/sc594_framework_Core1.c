/*****************************************************************************
 * sc594_framework_Core1.c
 *
 * SHARC1. Same role as 21593 SHARC1 for the audio path: SPORT DMA and
 * AudioProcess. UART, TWI, and A2B configuration run on ARM before this
 * core is released, so SpInit() sees clocks that are already running.
 *****************************************************************************/

#include "adi_initialize.h"
#include "sc594_framework_Core1.h"

#include <sys/platform.h>

#include "sport/sport.h"

/**
 * If you want to use command program arguments, then place them in the following string.
 */
char __argv_string[] = "";

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	adi_initComponents();

	SpInit();

	while (1) {
	}

	return 0;
}
