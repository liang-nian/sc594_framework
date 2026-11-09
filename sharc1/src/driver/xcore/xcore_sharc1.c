#include "xcore_sharc1.h"

#include "../../../../common/xcore_proto.h"

static XcoreCtrl *const ctrl = (XcoreCtrl *)XCORE_CTRL_ADDR;
static XcoreAudio *const audio = (XcoreAudio *)XCORE_AUDIO_ADDR;

static uint32_t epoch;
static uint32_t frame_index;
static float gain_bank[2][XCORE_GAIN_SHARC1_N];
static volatile uint32_t gain_pub;
static int attached;
static float pull_lane0[XCORE_LANE_CH * XCORE_FRAME_LEN];
static float pull_lane1[XCORE_LANE_CH * XCORE_FRAME_LEN];

static void GainsDefault(void) {
  uint32_t i;
  for (i = 0; i < XCORE_GAIN_SHARC1_N; ++i) {
    gain_bank[0][i] = 1.f;
    gain_bank[1][i] = 1.f;
  }
  gain_pub = 0u;
}

static void ApplyImage(const XcoreParamImage *image) {
  uint32_t next = (gain_pub ^ 1u) & 1u;
  uint32_t i;
  for (i = 0; i < XCORE_GAIN_SHARC1_N; ++i) {
    gain_bank[next][i] = image->gain[XCORE_GAIN_SHARC1 + i];
  }
  /* Keep the bank stores ahead of the index the audio callback reads.
   * The bank is core-local; do not flush it as shared L2. */
  XcoreBarrier();
  gain_pub = next;
}

void XcoreSharc1Boot(void) {
  XcoreParamImage image;

  GainsDefault();
  epoch = 0u;
  frame_index = 0u;
  attached = 0;
  if (XcoreAttach(ctrl, XCORE_CORE_SHARC1) != XCORE_OK) {
    return;
  }
  attached = 1;
  epoch = ctrl->ident.epoch;
  if (XcorePoll(ctrl, XCORE_CORE_SHARC1, &image) == XCORE_OK) {
    ApplyImage(&image);
  }
}

void XcoreSharc1Poll(void) {
  XcoreParamImage image;
  int rc;

  if (!attached) {
    XcoreSharc1Boot();
    return;
  }
  rc = XcorePoll(ctrl, XCORE_CORE_SHARC1, &image);
  if (rc == XCORE_OK) {
    epoch = ctrl->ident.epoch;
    ApplyImage(&image);
  } else if (rc == XCORE_UNCHANGED) {
    epoch = ctrl->ident.epoch;
  } else if (rc == XCORE_ERR_NOT_READY) {
    attached = 0;
    GainsDefault();
  }
}

int XcoreSharc2Ready(void) {
  XcoreInvalidate(&ctrl->core[XCORE_CORE_SHARC2], sizeof(XcoreCoreLine));
  return ctrl->core[XCORE_CORE_SHARC2].ready == XCORE_READY_MAGIC;
}

int XcoreSharc1Push(const float *a2b0_in, const float *a2b1_in,
                    uint32_t *slot, uint32_t *seq) {
  uint32_t use;
  uint32_t odd;
  uint32_t even;

  if (!attached || a2b0_in == NULL || a2b1_in == NULL || slot == NULL ||
      seq == NULL || epoch == 0u) {
    return XCORE_ERR_NOT_READY;
  }
  use = XcoreAudioSlotOf(frame_index);
  if (XcoreAudioBegin(audio, use, epoch, &odd) != XCORE_OK) {
    return XCORE_ERR_ARG;
  }
  if (XcoreAudioCommitIn(audio, use, odd, a2b0_in, a2b1_in, &even) != XCORE_OK) {
    return XCORE_ERR_STALE;
  }
  *slot = use;
  *seq = even;
  frame_index += 1u;
  return XCORE_OK;
}

int XcoreSharc1Pull(uint32_t slot, uint32_t seq, float *dac, float *a2b1_out) {
  int rc;

  rc = XcoreAudioReadOut(audio, slot, seq, pull_lane0, pull_lane1);
  if (rc != XCORE_OK) {
    return rc;
  }
  XcoreMapLaneToDac(dac, XCORE_DAC_LANE0_CH, pull_lane0);
  XcoreMapLaneToTx(a2b1_out, pull_lane1);
  return XCORE_OK;
}

void XcoreSharc1ApplyGain(float *dac) {
  const float *gains;
  uint32_t ch;
  uint32_t i;
  float g;

  if (dac == NULL) {
    return;
  }
  gains = gain_bank[gain_pub & 1u];
  for (ch = 0; ch < XCORE_GAIN_SHARC1_N; ++ch) {
    g = gains[ch];
    for (i = 0; i < XCORE_FRAME_LEN; ++i) {
      dac[ch * XCORE_FRAME_LEN + i] *= g;
    }
  }
}

void XcoreSharc1NoteLoad(float cpu, float max_cpu, float ave, float tot,
                         uint32_t frames, uint32_t misses, uint32_t seq) {
  XcoreDspStat stat;

  if (!attached) {
    return;
  }
  stat.magic = XCORE_STAT_MAGIC_SH1;
  stat.epoch = epoch;
  stat.frames = frames;
  stat.misses = misses;
  stat.cpu_load = cpu;
  stat.max_cpu_load = max_cpu;
  stat.ave_cpu_load = ave;
  stat.tot_cpu_load = tot;
  stat.last_seq = seq;
  stat.reserved[0] = 0u;
  stat.reserved[1] = 0u;
  stat.reserved[2] = 0u;
  stat.reserved[3] = 0u;
  stat.reserved[4] = 0u;
  stat.reserved[5] = 0u;
  stat.reserved[6] = 0u;
  XcoreWriteStat(ctrl, XCORE_CORE_SHARC1, &stat);
}
