#include "ad2428_reg.h"

/*
 * Default second-A2B register table.
 *
 * This is the file a later SigmaStudio export replaces. The single zero
 * record is not an I2C program: Ad24281TableIsImported() rejects it, so
 * Ad24281Init does not open TWI and does not report a discovered bus.
 *
 * Import without touching the SPORT route: replace ad24281_cfg and
 * AD24281_CFG_LEN with the export, or call Ad24281Bind() on that table.
 * The placeholder address bytes in the header stay unused until the
 * table is imported.
 */

Ad2428Reg ad24281_cfg[AD24281_CFG_LEN] = {
	{0}
};
