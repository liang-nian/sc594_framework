#include "xcore_sharc2.h"

#include "../../../../common/xcore_proto.h"

static XcoreCtrl *const ctrl = (XcoreCtrl *)XCORE_CTRL_ADDR;
static XcoreAudio *const audio = (XcoreAudio *)XCORE_AUDIO_ADDR;

static uint32_t epoch;
static int attached;
static float gain_bank[2][XCORE_LANE_COUNT][XCORE_LANE_CH];
static volatile uint32_t gain_pub;
static float in0_[XCORE_LANE_CH * XCORE_FRAME_LEN];
static float in1_[XCORE_LANE_CH * XCORE_FRAME_LEN];
static float out0_[XCORE_LANE_CH * XCORE_FRAME_LEN];
static float out1_[XCORE_LANE_CH * XCORE_FRAME_LEN];
static float cpu_load;
static float max_cpu_load;
static float ave_cpu_load;
static uint32_t frames;

static void GainsDefault(void) {
  uint32_t b;
  uint32_t c;
  for (b = 0; b < 2u; ++b) {
    for (c = 0; c < XCORE_LANE_CH; ++c) {
      gain_bank[b][0][c] = 1.f;
      gain_bank[b][1][c] = 1.f;
    }
  }
  gain_pub = 0u;
}

static void ApplyImage(const XcoreParamImage *image) {
  uint32_t next = (gain_pub ^ 1u) & 1u;
  uint32_t c;
  for (c = 0; c < XCORE_LANE_CH; ++c) {
    gain_bank[next][0][c] = image->gain[XCORE_GAIN_LANE0 + c];
    gain_bank[next][1][c] = image->gain[XCORE_GAIN_LANE1 + c];
  }
  XcoreBarrier();
  gain_pub = next;
}

void XcoreSharc2Boot(void) {
  XcoreParamImage image;

  GainsDefault();
  epoch = 0u;
  attached = 0;
  cpu_load = 0.f;
  max_cpu_load = 0.f;
  ave_cpu_load = 0.f;
  frames = 0u;
  if (XcoreAttach(ctrl, XCORE_CORE_SHARC2) != XCORE_OK) {
    return;
  }
  attached = 1;
  epoch = ctrl->ident.epoch;
  if (XcorePoll(ctrl, XCORE_CORE_SHARC2, &image) == XCORE_OK) {
    ApplyImage(&image);
  }
}

void XcoreSharc2Poll(void) {
  XcoreParamImage image;
  int rc;

  if (!attached) {
    XcoreSharc2Boot();
    return;
  }
  rc = XcorePoll(ctrl, XCORE_CORE_SHARC2, &image);
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

void XcoreSharc2Service(void) {
  uint32_t slot;
  uint64_t t0;
  const float k = 0.001f;

  if (!attached || epoch == 0u) {
    return;
  }
  t0 = __builtin_emuclk();
  for (slot = 0; slot < XCORE_AUDIO_SLOTS; ++slot) {
    uint32_t seq = 0u;
    uint32_t ch;
    uint32_t i;

    if (XcoreAudioPending(audio, slot, epoch, &seq) != XCORE_OK) {
      continue;
    }
    if (XcoreAudioReadIn(audio, slot, epoch, in0_, in1_, &seq) != XCORE_OK) {
      continue;
    }
    {
      uint32_t pub = gain_pub & 1u;
      for (ch = 0; ch < XCORE_LANE_CH; ++ch) {
        for (i = 0; i < XCORE_FRAME_LEN; ++i) {
          out0_[ch * XCORE_FRAME_LEN + i] =
              in0_[ch * XCORE_FRAME_LEN + i] * gain_bank[pub][0][ch];
          out1_[ch * XCORE_FRAME_LEN + i] =
              in1_[ch * XCORE_FRAME_LEN + i] * gain_bank[pub][1][ch];
        }
      }
    }
    if (XcoreAudioCommitOut(audio, slot, seq, epoch, out0_, out1_) == XCORE_OK) {
      frames += 1u;
    }
  }
  t0 = __builtin_emuclk() - t0;
  cpu_load = (float)t0 / 1000.f;
  if (cpu_load > max_cpu_load) {
    max_cpu_load = cpu_load;
  }
  ave_cpu_load = k * cpu_load + (1.f - k) * ave_cpu_load;
  {
    XcoreDspStat stat;
    stat.magic = XCORE_STAT_MAGIC_SH2;
    stat.epoch = epoch;
    stat.frames = frames;
    stat.misses = 0u;
    stat.cpu_load = cpu_load;
    stat.max_cpu_load = max_cpu_load;
    stat.ave_cpu_load = ave_cpu_load;
    stat.tot_cpu_load = cpu_load;
    stat.last_seq = 0u;
    stat.reserved[0] = 0u;
    stat.reserved[1] = 0u;
    stat.reserved[2] = 0u;
    stat.reserved[3] = 0u;
    stat.reserved[4] = 0u;
    stat.reserved[5] = 0u;
    stat.reserved[6] = 0u;
    XcoreWriteStat(ctrl, XCORE_CORE_SHARC2, &stat);
  }
}
