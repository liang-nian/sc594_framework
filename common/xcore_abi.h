/*
 * Cross-core ABI for ADSP-SC594 (ARM + SHARC0 + SHARC1).
 *
 * One copy of this header is compiled into every image. Layout rules:
 *   - little-endian uint32_t and IEEE-754 binary32 only
 *   - no pointers, no size_t, no enums in the shared image
 *   - byte offsets from the region base, never a foreign pointer
 *   - 64-byte lines so an ARM cache line and a SHARC line do not share
 *     a writer
 *
 * Address evidence in this repo:
 *   - L2 SRAM is 0x20000000..0x201FFFFF for ARM and both SHARC+ cores
 *     (byte addresses; SPORT XModify is 4; the old AudioStat block used
 *     the same numeric address from ARM and SHARC1)
 *   - apt.c maps 0x20025000..0x2003FFFF as ADI_MMU_RW_UNCACHED
 *   - MCAPI occupies 0x20000000..0x20024FFF
 *   - ARM cached L2 starts at 0x20040000
 *   - SHARC L2 in app.ld starts at 0x20100000
 *   - startup sets REG_SHL1C0_CFG = 0 (data cache off) but SHARC readers
 *     and writers still flush/invalidate. Volatile is not the barrier.
 *
 * The generated SHARC app.ldf is not in git. sharc1/system/startup_ldf/
 * xcore_reserve.mem is the MEMORY block to keep when that LDF is
 * regenerated. Until then the cores use these absolute addresses, which
 * is the same method the old AudioStat block used.
 */

#ifndef XCORE_ABI_H_
#define XCORE_ABI_H_

#include <stddef.h>
#include <stdint.h>

#define XCORE_MAGIC            (0x53433594u)
#define XCORE_ABI_VERSION      (0x00010000u)
#define XCORE_READY_MAGIC      (0x52445931u)
#define XCORE_STAT_MAGIC_SH1   (0xA5A500CCu)
#define XCORE_STAT_MAGIC_SH2   (0xA5A500CDu)

#define XCORE_CTRL_ADDR        (0x20038000u)
#define XCORE_CTRL_BYTES       (0x4000u)
#define XCORE_AUDIO_ADDR       (0x2003C000u)
#define XCORE_AUDIO_BYTES      (0x4000u)

#define XCORE_FRAME_LEN        (48u)
#define XCORE_LANE_CH          (4u)
#define XCORE_LANE_COUNT       (2u)
#define XCORE_AUDIO_SLOTS      (2u)
#define XCORE_GAIN_NUM         (16u)
#define XCORE_GAIN_SHARC1      (0u)
#define XCORE_GAIN_SHARC1_N    (8u)
#define XCORE_GAIN_LANE0       (8u)
#define XCORE_GAIN_LANE1       (12u)

#define XCORE_CORE_ARM         (0u)
#define XCORE_CORE_SHARC1      (1u)
#define XCORE_CORE_SHARC2      (2u)
#define XCORE_CORE_NUM         (3u)

#define XCORE_OK               (0)
#define XCORE_ERR_ARG          (1)
#define XCORE_ERR_MAGIC        (2)
#define XCORE_ERR_VERSION      (3)
#define XCORE_ERR_SIZE         (4)
#define XCORE_ERR_NOT_READY    (5)
#define XCORE_ERR_CHECKSUM     (6)
#define XCORE_ERR_PARTIAL      (7)
#define XCORE_ERR_STALE        (8)
#define XCORE_ERR_EPOCH        (9)
#define XCORE_UNCHANGED        (10)

#define XCORE_A2B_LINK_OFF     (0u)
#define XCORE_A2B_LINK_UP      (1u)
#define XCORE_A2B_LINK_BLOCKED (2u)

#define XCORE_A2B1_BLOCK_NONE  (0u)
/* EV-SOMCRR-EZKIT has one AD2428. ad24281_cfg is a one-entry zero stub. */
#define XCORE_A2B1_BLOCK_NO_SCRIPT (1u)

#define XCORE_FLAG_STREAM_RUN  (1u << 0)
#define XCORE_FLAG_A2B0_SPORT  (1u << 1)
#define XCORE_FLAG_A2B1_SPORT  (1u << 2)

/* SPORT device numbers already used by sharc1/src/driver/sport/sport.c. */
#define XCORE_SPORT_A2B0       (1u)
#define XCORE_SPORT_A2B1       (5u)
#define XCORE_DAC_LANE0_CH     (8u)

/* Bounded same-frame wait. 200000 cycles is 0.2 ms at 1 GHz, under the
 * 48-sample / 48 kHz frame. This is not a lock: SHARC2 runs on the
 * other core, and a timeout keeps the previous DAC/TX samples. */
#define XCORE_AUDIO_WAIT_CYCLES (200000u)

typedef struct XcoreIdent {
  uint32_t magic;
  uint32_t abi_version;
  uint32_t ident_bytes;
  uint32_t ctrl_bytes;
  uint32_t audio_bytes;
  uint32_t ctrl_struct_bytes;
  uint32_t audio_struct_bytes;
  uint32_t epoch;
  uint32_t arm_ready;
  uint32_t published_index;
  uint32_t frame_len;
  uint32_t lane_channels;
  uint32_t lane_count;
  uint32_t audio_slot_bytes;
  uint32_t in_samples_off;
  uint32_t out_samples_off;
} XcoreIdent;

typedef struct XcoreCoreLine {
  uint32_t ready;
  uint32_t abi_seen;
  uint32_t error;
  uint32_t ack_generation;
  uint32_t ack_epoch;
  uint32_t applied_checksum;
  uint32_t reset_seen;
  uint32_t reserved[9];
} XcoreCoreLine;

typedef struct XcoreParamImage {
  uint32_t flags;
  uint32_t a2b0_link;
  uint32_t a2b0_nodes;
  uint32_t a2b1_link;
  uint32_t a2b1_block;
  uint32_t a2b1_nodes;
  uint32_t sport_a2b0_dev;
  uint32_t sport_a2b1_dev;
  uint32_t dac_lane0_ch;
  uint32_t lane_count;
  uint32_t frame_len;
  uint32_t gain_sharc1_base;
  uint32_t gain_lane0_base;
  uint32_t gain_lane1_base;
  float gain[XCORE_GAIN_NUM];
  uint32_t reserved[14];
} XcoreParamImage;

typedef struct XcoreParamSlot {
  uint32_t seq;
  uint32_t generation;
  uint32_t checksum;
  uint32_t reserved_hdr;
  XcoreParamImage image;
} XcoreParamSlot;

typedef struct XcoreDspStat {
  uint32_t magic;
  uint32_t epoch;
  uint32_t frames;
  uint32_t misses;
  float cpu_load;
  float max_cpu_load;
  float ave_cpu_load;
  float tot_cpu_load;
  uint32_t last_seq;
  uint32_t reserved[7];
} XcoreDspStat;

typedef struct XcoreCtrl {
  XcoreIdent ident;
  XcoreCoreLine core[XCORE_CORE_NUM];
  XcoreParamSlot slot[2];
  XcoreDspStat stat[2];
} XcoreCtrl;

typedef struct XcoreAudioSlot {
  uint32_t in_seq;
  uint32_t in_epoch;
  uint32_t channels;
  uint32_t frame_len;
  uint32_t lanes;
  uint32_t flags;
  uint32_t in_samples_off;
  uint32_t out_samples_off;
  float in_samples[XCORE_LANE_COUNT][XCORE_LANE_CH * XCORE_FRAME_LEN];
  uint32_t out_seq;
  uint32_t out_epoch;
  uint32_t out_reserved0;
  uint32_t out_reserved1;
  float out_samples[XCORE_LANE_COUNT][XCORE_LANE_CH * XCORE_FRAME_LEN];
  uint8_t pad[16];
} XcoreAudioSlot;

typedef struct XcoreAudio {
  XcoreAudioSlot slot[XCORE_AUDIO_SLOTS];
} XcoreAudio;

typedef char xcore_float_is_4[(sizeof(float) == 4) ? 1 : -1];
typedef char xcore_u32_is_4[(sizeof(uint32_t) == 4) ? 1 : -1];
typedef char xcore_ident_line[(sizeof(XcoreIdent) == 64) ? 1 : -1];
typedef char xcore_core_line[(sizeof(XcoreCoreLine) == 64) ? 1 : -1];
typedef char xcore_image_176[(sizeof(XcoreParamImage) == 176) ? 1 : -1];
typedef char xcore_param_slot_192[(sizeof(XcoreParamSlot) == 192) ? 1 : -1];
typedef char xcore_stat_line[(sizeof(XcoreDspStat) == 64) ? 1 : -1];
typedef char xcore_ctrl_fits[(sizeof(XcoreCtrl) <= XCORE_CTRL_BYTES) ? 1 : -1];
typedef char xcore_audio_slot_align[(sizeof(XcoreAudioSlot) % 64u == 0) ? 1 : -1];
typedef char xcore_audio_fits[(sizeof(XcoreAudio) <= XCORE_AUDIO_BYTES) ? 1 : -1];
typedef char xcore_regions_pack[
    (XCORE_CTRL_ADDR >= 0x20025000u &&
     (XCORE_CTRL_ADDR + XCORE_CTRL_BYTES) == XCORE_AUDIO_ADDR &&
     (XCORE_AUDIO_ADDR + XCORE_AUDIO_BYTES) == 0x20040000u)
        ? 1
        : -1];
typedef char xcore_in_off_aligned[
    ((offsetof(XcoreAudioSlot, in_samples) % 4u) == 0u) ? 1 : -1];
typedef char xcore_out_off_aligned[
    ((offsetof(XcoreAudioSlot, out_samples) % 4u) == 0u) ? 1 : -1];
typedef char xcore_no_ptr_ident[(sizeof(XcoreIdent) == 16u * 4u) ? 1 : -1];

#endif /* XCORE_ABI_H_ */
