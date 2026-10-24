#include "ad2428_reg.h"

/*
 * Second A2B (AD24281) config table — intentionally empty.
 *
 * EV-SOMCRR-EZKIT (SC594 and 21593) provides only one A2B master
 * (AD24280 @ 0x68/0x69). There is no second on-board transceiver.
 *
 * Keep this stub so the build still links Ad24281Init / Ad24281Mon without
 * shipping any product-specific SigmaStudio export.
 */

Ad2428Reg ad24281_cfg[AD24281_CFG_LEN] = {
	{0}
};
