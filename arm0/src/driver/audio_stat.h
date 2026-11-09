#ifndef AUDIO_STAT_H_
#define AUDIO_STAT_H_

/*
 * The old SHARC1 block at 0x2003FF00 is inside the shared audio window
 * (0x2003C000..0x2003FFFF) and must not be written. CPU load, parameter
 * acks, and the audio lanes live in common/xcore_abi.h.
 */

#endif /* AUDIO_STAT_H_ */
