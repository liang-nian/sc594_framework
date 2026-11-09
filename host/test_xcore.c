#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xcore_proto.h"
#include "../arm0/src/driver/ad2428/ad2428_reg.h"

static int failures;

#define CHECK(cond)                                                            \
  do {                                                                         \
    if (!(cond)) {                                                             \
      fprintf(stderr, "fail %s:%d: %s\n", __FILE__, __LINE__, #cond);         \
      failures += 1;                                                           \
    }                                                                          \
  } while (0)

#define CACHE_LOG 64
static void *cache_addr[CACHE_LOG];
static uint32_t cache_len[CACHE_LOG];
static char cache_kind[CACHE_LOG];
static int cache_n;

void XcoreWriteback(void *addr, uint32_t bytes) {
  if (cache_n < CACHE_LOG) {
    cache_addr[cache_n] = addr;
    cache_len[cache_n] = bytes;
    cache_kind[cache_n] = 'W';
    cache_n += 1;
  }
}

void XcoreInvalidate(void *addr, uint32_t bytes) {
  if (cache_n < CACHE_LOG) {
    cache_addr[cache_n] = addr;
    cache_len[cache_n] = bytes;
    cache_kind[cache_n] = 'I';
    cache_n += 1;
  }
}

static void *aligned_bytes(uint32_t bytes) {
  void *p = aligned_alloc(64, bytes);
  if (p == NULL) {
    return NULL;
  }
  memset(p, 0xA5, bytes);
  return p;
}

static int saw_payload_before_final(const void *payload, const void *seq) {
  int last_seq = -1;
  int i;
  for (i = 0; i < cache_n; ++i) {
    if (cache_kind[i] == 'W' && cache_addr[i] == seq) {
      last_seq = i;
    }
  }
  if (last_seq < 0) {
    return 0;
  }
  for (i = 0; i < last_seq; ++i) {
    if (cache_kind[i] == 'W' && cache_addr[i] == payload) {
      return 1;
    }
  }
  return 0;
}

static void fill_lane(float *lane, float base) {
  uint32_t i;
  for (i = 0; i < XCORE_LANE_CH * XCORE_FRAME_LEN; ++i) {
    lane[i] = base + (float)i;
  }
}

static void test_layout(void) {
  CHECK(sizeof(float) == 4);
  CHECK(sizeof(XcoreCtrl) <= XCORE_CTRL_BYTES);
  CHECK(sizeof(XcoreAudio) <= XCORE_AUDIO_BYTES);
  CHECK(sizeof(XcoreAudioSlot) % 64u == 0u);
  CHECK((XCORE_CTRL_ADDR + XCORE_CTRL_BYTES) == XCORE_AUDIO_ADDR);
  CHECK((XCORE_AUDIO_ADDR + XCORE_AUDIO_BYTES) == 0x20040000u);
  CHECK(XCORE_CTRL_ADDR >= 0x20025000u);
  CHECK(XCORE_CTRL_ADDR >= 0x20025000u);
  CHECK(XCORE_AUDIO_ADDR + XCORE_AUDIO_BYTES <= 0x20040000u);
  CHECK(XCORE_CTRL_ADDR >= 0x20025000u && XCORE_AUDIO_ADDR < 0x20100000u);
  CHECK(0x2003FF00u >= XCORE_AUDIO_ADDR);
  CHECK(0x2003FF00u < (XCORE_AUDIO_ADDR + XCORE_AUDIO_BYTES));
  CHECK(offsetof(XcoreAudioSlot, in_samples) ==
        (XCORE_CTRL_ADDR ? offsetof(XcoreAudioSlot, in_samples) : 0));
  CHECK(XCORE_SPORT_A2B0 == 1u);
  CHECK(XCORE_SPORT_A2B1 == 5u);
  CHECK(XCORE_DAC_LANE0_CH == 8u);
  CHECK(XCORE_FRAME_LEN == 48u);
  CHECK(XCORE_LANE_COUNT == 2u);
  CHECK(AD24281_CFG_LEN < 2u || ad24281_cfg[0].dev == 0u);
  CHECK(ad24281_cfg[0].dev == 0u);
  CHECK(XcoreAudioSlotOf(0) == 0u);
  CHECK(XcoreAudioSlotOf(1) == 1u);
  CHECK(XcoreAudioSlotOf(2) == 0u);
}

static void test_params(void) {
  XcoreCtrl *ctrl = aligned_bytes(sizeof(XcoreCtrl));
  XcoreAudio *audio = aligned_bytes(sizeof(XcoreAudio));
  XcoreParamImage image;
  XcoreParamImage got1;
  XcoreParamImage got2;
  uint32_t i;

  CHECK(ctrl != NULL && audio != NULL);
  memset(&image, 0, sizeof(image));
  image.flags = XCORE_FLAG_STREAM_RUN | XCORE_FLAG_A2B0_SPORT |
                XCORE_FLAG_A2B1_SPORT;
  image.a2b0_link = XCORE_A2B_LINK_UP;
  image.a2b0_nodes = 12u;
  image.a2b1_link = XCORE_A2B_LINK_DEFAULT;
  image.a2b1_cfg = XCORE_A2B1_CFG_DEFAULT;
  image.a2b1_tx_mute = 1u;
  image.sport_a2b0_dev = XCORE_SPORT_A2B0;
  image.sport_a2b1_dev = XCORE_SPORT_A2B1;
  image.dac_lane0_ch = XCORE_DAC_LANE0_CH;
  image.lane_count = XCORE_LANE_COUNT;
  image.frame_len = XCORE_FRAME_LEN;
  for (i = 0; i < XCORE_GAIN_NUM; ++i) {
    image.gain[i] = 1.f;
  }

  CHECK(XcoreAttach(ctrl, XCORE_CORE_SHARC1) == XCORE_ERR_NOT_READY);
  CHECK(ctrl->core[XCORE_CORE_SHARC1].ready == 0u);

  CHECK(XcoreArmReset(ctrl, audio, 1u) == XCORE_OK);
  CHECK(ctrl->ident.magic == XCORE_MAGIC);
  CHECK(ctrl->ident.arm_ready == XCORE_READY_MAGIC);
  CHECK(audio->slot[0].in_seq == 0u);

  ctrl->ident.arm_ready = 0u;
  CHECK(XcoreAttach(ctrl, XCORE_CORE_SHARC2) == XCORE_ERR_NOT_READY);
  CHECK(ctrl->core[XCORE_CORE_SHARC2].ready == 0u);
  ctrl->ident.arm_ready = XCORE_READY_MAGIC;

  cache_n = 0;
  CHECK(XcoreArmPublish(ctrl, &image) == XCORE_OK);
  CHECK(saw_payload_before_final(&ctrl->slot[0].generation, &ctrl->slot[0].seq));
  CHECK(XcorePublishedGeneration(ctrl) == 1u);

  ctrl->ident.abi_version = 0u;
  CHECK(XcoreAttach(ctrl, XCORE_CORE_SHARC1) == XCORE_ERR_VERSION);
  CHECK(ctrl->core[XCORE_CORE_SHARC1].ready == 0u);
  ctrl->ident.abi_version = XCORE_ABI_VERSION;

  ctrl->ident.ctrl_struct_bytes = 1u;
  CHECK(XcoreAttach(ctrl, XCORE_CORE_SHARC1) == XCORE_ERR_SIZE);
  ctrl->ident.ctrl_struct_bytes = (uint32_t)sizeof(XcoreCtrl);

  CHECK(XcoreAttach(ctrl, XCORE_CORE_SHARC1) == XCORE_OK);
  CHECK(XcoreAttach(ctrl, XCORE_CORE_SHARC2) == XCORE_OK);
  CHECK(XcorePoll(ctrl, XCORE_CORE_SHARC1, &got1) == XCORE_OK);
  CHECK(got1.a2b0_nodes == 12u);
  CHECK(got1.a2b1_cfg == XCORE_A2B1_CFG_DEFAULT);
  CHECK(got1.a2b1_tx_mute == 1u);
  CHECK(got1.gain[0] == 1.f);
  CHECK(got1.gain[12] == 1.f);
  CHECK(XcoreAckGeneration(ctrl, XCORE_CORE_SHARC1) == 1u);
  CHECK(XcoreAckGeneration(ctrl, XCORE_CORE_SHARC2) == 0u);

  image.gain[3] = 0.5f;
  CHECK(XcoreArmPublish(ctrl, &image) == XCORE_OK);
  CHECK(XcorePoll(ctrl, XCORE_CORE_SHARC1, &got1) == XCORE_OK);
  CHECK(got1.gain[3] == 0.5f);
  CHECK(XcoreAckGeneration(ctrl, XCORE_CORE_SHARC1) == 2u);
  CHECK(XcoreAckGeneration(ctrl, XCORE_CORE_SHARC2) == 0u);

  CHECK(XcorePoll(ctrl, XCORE_CORE_SHARC2, &got2) == XCORE_OK);
  CHECK(got2.gain[3] == 0.5f);
  CHECK(XcoreAckGeneration(ctrl, XCORE_CORE_SHARC2) == 2u);
  CHECK(XcoreAckGeneration(ctrl, XCORE_CORE_SHARC1) == 2u);
  CHECK(XcorePoll(ctrl, XCORE_CORE_SHARC1, &got1) == XCORE_UNCHANGED);
  CHECK(XcoreAckGeneration(ctrl, XCORE_CORE_SHARC1) == 2u);

  {
    uint32_t idx;
    image.gain[4] = 0.25f;
    CHECK(XcoreArmPublish(ctrl, &image) == XCORE_OK);
    idx = ctrl->ident.published_index & 1u;
    ctrl->slot[idx].seq |= 1u;
    CHECK(XcorePoll(ctrl, XCORE_CORE_SHARC1, &got1) == XCORE_ERR_PARTIAL);
    CHECK(XcoreAckGeneration(ctrl, XCORE_CORE_SHARC1) == 2u);
    CHECK(XcoreAckGeneration(ctrl, XCORE_CORE_SHARC2) == 2u);
    ctrl->slot[idx].seq &= ~1u;
    ctrl->slot[idx].image.gain[4] = 9.f;
    CHECK(XcorePoll(ctrl, XCORE_CORE_SHARC1, &got1) == XCORE_ERR_CHECKSUM);
    CHECK(got1.gain[3] == 0.5f);
    CHECK(XcoreAckGeneration(ctrl, XCORE_CORE_SHARC1) == 2u);
    ctrl->slot[idx].image.gain[4] = 0.25f;
    CHECK(XcorePoll(ctrl, XCORE_CORE_SHARC1, &got1) == XCORE_OK);
    CHECK(got1.gain[4] == 0.25f);
    CHECK(XcoreAckGeneration(ctrl, XCORE_CORE_SHARC1) == 3u);
    CHECK(XcoreAckGeneration(ctrl, XCORE_CORE_SHARC2) == 2u);
  }

  CHECK(XcoreArmReset(ctrl, audio, 2u) == XCORE_OK);
  CHECK(XcoreAckGeneration(ctrl, XCORE_CORE_SHARC1) == 0u);
  CHECK(XcoreAckGeneration(ctrl, XCORE_CORE_SHARC2) == 0u);
  CHECK(audio->slot[0].in_seq == 0u);
  CHECK(XcoreAttach(ctrl, XCORE_CORE_SHARC1) == XCORE_OK);
  CHECK(XcorePoll(ctrl, XCORE_CORE_SHARC1, &got1) == XCORE_ERR_PARTIAL);
  CHECK(XcoreArmPublish(ctrl, &image) == XCORE_OK);
  CHECK(XcorePoll(ctrl, XCORE_CORE_SHARC1, &got1) == XCORE_OK);
  CHECK(XcoreAckGeneration(ctrl, XCORE_CORE_SHARC1) == 1u);
  CHECK(XcoreAckGeneration(ctrl, XCORE_CORE_SHARC2) == 0u);

  free(ctrl);
  free(audio);
}

static void test_audio(void) {
  XcoreAudio *audio = aligned_bytes(sizeof(XcoreAudio));
  float in0[XCORE_LANE_CH * XCORE_FRAME_LEN];
  float in1[XCORE_LANE_CH * XCORE_FRAME_LEN];
  float out0[XCORE_LANE_CH * XCORE_FRAME_LEN];
  float out1[XCORE_LANE_CH * XCORE_FRAME_LEN];
  float dac[16u * XCORE_FRAME_LEN];
  float tx[32u * XCORE_FRAME_LEN];
  uint32_t odd = 0u;
  uint32_t even = 0u;
  uint32_t seq = 0u;
  uint32_t i;

  CHECK(audio != NULL);
  fill_lane(in0, 10.f);
  fill_lane(in1, 100.f);
  memset(dac, 0, sizeof(dac));
  memset(tx, 0x5a, sizeof(tx));
  dac[0] = 42.f;

  cache_n = 0;
  CHECK(XcoreAudioBegin(audio, 0u, 1u, &odd) == XCORE_OK);
  CHECK((odd & 1u) == 1u);
  CHECK(XcoreAudioReadIn(audio, 0u, 1u, out0, out1, &seq) == XCORE_ERR_PARTIAL);
  CHECK(XcoreAudioCommitIn(audio, 0u, odd, in0, in1, &even) == XCORE_OK);
  CHECK((even & 1u) == 0u);
  CHECK(saw_payload_before_final(audio->slot[0].in_samples, &audio->slot[0].in_seq));
  CHECK(XcoreAudioPending(audio, 0u, 1u, &seq) == XCORE_OK);
  CHECK(seq == even);
  CHECK(XcoreAudioReadIn(audio, 0u, 1u, out0, out1, &seq) == XCORE_OK);
  CHECK(out0[0] == 10.f);
  CHECK(out1[0] == 100.f);
  CHECK(XcoreAudioReadOut(audio, 0u, even, out0, out1) == XCORE_ERR_STALE);

  for (i = 0; i < XCORE_LANE_CH * XCORE_FRAME_LEN; ++i) {
    out0[i] = in0[i] * 2.f;
    out1[i] = 0.f;
  }
  CHECK(XcoreAudioCommitOut(audio, 0u, even, 1u, out0, out1) == XCORE_OK);
  CHECK(XcoreAudioPending(audio, 0u, 1u, &seq) == XCORE_ERR_STALE);
  CHECK(XcoreAudioReadOut(audio, 0u, even, in0, in1) == XCORE_OK);
  CHECK(in0[1] == 22.f);
  CHECK(XcoreAudioReadOut(audio, 0u, 0xFFFFFFFEu, in0, in1) == XCORE_ERR_STALE);

  XcoreMapLaneToDac(dac, XCORE_DAC_LANE0_CH, in0);
  XcoreMapLaneToTx(tx, in1);
  CHECK(dac[0] == 42.f);
  CHECK(dac[XCORE_DAC_LANE0_CH * XCORE_FRAME_LEN] == in0[0]);
  CHECK(dac[(XCORE_DAC_LANE0_CH + 3u) * XCORE_FRAME_LEN + (XCORE_FRAME_LEN - 1u)] ==
        in0[3u * XCORE_FRAME_LEN + (XCORE_FRAME_LEN - 1u)]);
  CHECK(tx[0] == 0.f);
  CHECK(tx[XCORE_LANE_CH * XCORE_FRAME_LEN] != 0.f);

  audio->slot[1].in_seq = 0xFFFFFFFEu;
  CHECK(XcoreAudioBegin(audio, 1u, 1u, &odd) == XCORE_OK);
  CHECK(odd == 1u);
  fill_lane(in0, 1.f);
  fill_lane(in1, 2.f);
  CHECK(XcoreAudioCommitIn(audio, 1u, odd, in0, in1, &even) == XCORE_OK);
  CHECK(even == 2u);
  CHECK(XcoreAudioReadIn(audio, 1u, 1u, out0, out1, &seq) == XCORE_OK);
  CHECK(seq == 2u);
  CHECK(XcoreAudioCommitOut(audio, 1u, 2u, 1u, out0, out1) == XCORE_OK);
  CHECK(XcoreAudioReadOut(audio, 1u, 2u, out0, out1) == XCORE_OK);
  CHECK(XcoreAudioReadOut(audio, 1u, 0xFFFFFFFEu, out0, out1) == XCORE_ERR_STALE);

  free(audio);
}

static void test_a2b1_route(void) {
  float lane0[XCORE_LANE_CH * XCORE_FRAME_LEN];
  float lane1[XCORE_LANE_CH * XCORE_FRAME_LEN];
  float processed0[XCORE_LANE_CH * XCORE_FRAME_LEN];
  float processed1[XCORE_LANE_CH * XCORE_FRAME_LEN];
  float dac[16u * XCORE_FRAME_LEN];
  float tx[8u * XCORE_FRAME_LEN];
  float tail;
  uint32_t i;
  Ad2428Reg imported[2];

  fill_lane(lane0, 3.f);
  fill_lane(lane1, 7.f);
  for (i = 0; i < XCORE_LANE_CH * XCORE_FRAME_LEN; ++i) {
    processed0[i] = lane0[i] * 1.f;
    processed1[i] = lane1[i] * 1.f;
  }
  memset(dac, 0, sizeof(dac));
  dac[0] = 42.f;
  memset(tx, 0, sizeof(tx));
  tx[XCORE_LANE_CH * XCORE_FRAME_LEN] = 9.f;
  tail = tx[XCORE_LANE_CH * XCORE_FRAME_LEN];

  XcoreRouteOutputs(dac, tx, processed0, processed1, 1u);
  CHECK(dac[0] == 42.f);
  CHECK(dac[XCORE_DAC_LANE0_CH * XCORE_FRAME_LEN] == processed0[0]);
  CHECK(dac[7u * XCORE_FRAME_LEN] == 0.f);
  CHECK(tx[0] == 0.f);
  CHECK(tx[XCORE_LANE_CH * XCORE_FRAME_LEN - 1u] == 0.f);
  CHECK(tx[XCORE_LANE_CH * XCORE_FRAME_LEN] == tail);
  CHECK(processed1[0] == 7.f);

  XcoreRouteOutputs(dac, tx, processed0, processed1, 0u);
  CHECK(dac[0] == 42.f);
  CHECK(dac[XCORE_DAC_LANE0_CH * XCORE_FRAME_LEN] == processed0[0]);
  CHECK(tx[0] == processed1[0]);
  CHECK(tx[XCORE_LANE_CH * XCORE_FRAME_LEN - 1u] ==
        processed1[XCORE_LANE_CH * XCORE_FRAME_LEN - 1u]);
  CHECK(tx[XCORE_LANE_CH * XCORE_FRAME_LEN] == tail);

  memset(&imported, 0, sizeof(imported));
  CHECK(Ad24281TableIsImported(ad24281_cfg, AD24281_CFG_LEN) == 0);
  CHECK(Ad24281TableIsImported(imported, 2u) == 0);
  imported[0].dev = AD24281_MASTER_DEV;
  imported[1].dev = AD24281_SLAVE_DEV;
  CHECK(Ad24281TableIsImported(imported, 2u) == 1);
  CHECK(Ad24281TableIsImported(imported, 1u) == 0);
}

int main(void) {
  test_layout();
  test_params();
  test_audio();
  test_a2b1_route();
  if (failures != 0) {
    fprintf(stderr, "%d checks failed\n", failures);
    return 1;
  }
  printf("xcore host checks passed\n");
  return 0;
}
