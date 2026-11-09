/*****************************************************************************
 * sc594_framework_Core2.c
 *****************************************************************************/

#include "adi_initialize.h"
#include "sc594_framework_Core2.h"

#include <sys/platform.h>

#include "driver/audio_flow/audio_flow.h"
#include "driver/xcore/xcore_sharc2.h"

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
	 * Same role as 21593 SHARC2: own the shared audio callback.
	 * SHARC1 builds the stream and kicks INTR_SYS_SOFT0_INT.
	 * Parameter acks run in this loop, not in the callback.
	 */
	XcoreSharc2Boot();
	AudioFlowInit();

	while (1) {
		XcoreSharc2Poll();
	}

	return 0;
}

