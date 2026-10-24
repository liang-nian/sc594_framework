/*****************************************************************************
 * sc594_framework_Core2.c
 *****************************************************************************/

#include "adi_initialize.h"
#include "sc594_framework_Core2.h"

#include <sys/platform.h>

/** 
 * If you want to use command program arguments, then place them in the following string. 
 */
char __argv_string[] = "";

int main(int argc, char *argv[])
{
	/**
	 * Initialize managed drivers and/or services that have been added to 
	 * the project.
	 * @return zero on success 
	 */
	adi_initComponents();

	/*
	 * Secondary DSP core. Matches the 21593 SHARC2 stub: no drivers.
	 * UART, TWI, and A2B configuration are on ARM. SPORT and AudioProcess
	 * are on SHARC1. This loop is the extension point for a second
	 * algorithm core.
	 */
	while (1) {
	}

	return 0;
}

