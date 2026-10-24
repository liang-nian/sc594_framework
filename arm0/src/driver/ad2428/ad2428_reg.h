#ifndef AD2428_REG_H_
#define AD2428_REG_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define AD2428_REG_INTSTAT    (0x15)
#define AD2428_REG_INTPND2    (0x1A)
#define AD2428_REG_NODEADR    (0x01)
#define AD2428_REG_INTSRC     (0x16)
#define AD2428_REG_INTTYPE    (0x17)
#define AD2428_REG_BECNT      (0x1F)
#define AD2428_HDCNTERR       (0u)
#define AD2428_DDERR          (1u)
#define AD2428_CRCERR         (2u)
#define AD2428_DPERR          (3u)
#define AD2428_BECOVF         (4u)
#define AD2428_SRFERR         (5u)
#define AD2428_SRFCRCERR      (6u)
#define AD2428_DSCDONE        (24u)
#define AD2428_MSTR_RUNNING   (255u)

#define WRITE     ((uint8_t) 0x00u)
#define READ      ((uint8_t) 0x01u)
#define DELAY     ((uint8_t) 0x02u)
#define INVALID   ((uint8_t) 0xFFu)

typedef struct Ad2428Reg {
	uint8_t dev;
	uint8_t op_code;
	uint8_t reg_width;
	uint32_t reg;
	uint8_t val_width;
	uint16_t val_len;
	uint8_t* val_ptr;
} Ad2428Reg;

// Dev0 (AD24280): primary A2B on EV-SOMCRR-EZKIT (21593 and SC594 carriers).
// Topology exported for this learning project: 12 slave nodes with 2-mic each,
// 48 kHz, sampling falling edge, FS pol rising pulse, early FS, TDM16, 32-bit,
// A2B transceiver in slave I2S mode toward the SHARC SPORT.
#define AD24280_MASTER_DEV    (0x68u)
#define AD24280_SLAVE_DEV     (0x69u)
#define AD24280_CFG_LEN       (829u)

extern Ad2428Reg ad24280_cfg[AD24280_CFG_LEN];

/*
 * Dev1 (AD24281): second A2B path — NOT present on EV-SOMCRR-EZKIT
 * (the carrier used by both the 21593 EZ-KIT and the SC594 EZ-KIT).
 *
 * The carrier has a single A2B master. AD24281_* and ad24281_cfg stay empty
 * stubs so call sites compile. Do not treat them as a second bus.
 */
#define AD24281_MASTER_DEV    (0x6Cu)
#define AD24281_SLAVE_DEV     (0x6Du)
#define AD24281_CFG_LEN       (1u)

extern Ad2428Reg ad24281_cfg[AD24281_CFG_LEN];

#ifdef __cplusplus
} // extern "C"
#endif

#endif // AD2428_REG_H_
