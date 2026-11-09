#include "xcore_proto.h"

#include <string.h>

void XcoreBarrier(void) {
  static volatile uint32_t sink;
  sink += 1u;
}

static uint32_t load32(const uint32_t *p) {
  return *(volatile const uint32_t *)p;
}

static void store32(uint32_t *p, uint32_t value) {
  *(volatile uint32_t *)p = value;
}

static uint32_t next_even(uint32_t even_seq) {
  uint32_t n;

  if ((even_seq & 1u) != 0u) {
    even_seq += 1u;
    if (even_seq == 0u) {
      even_seq = 0xFFFFFFFEu;
    }
  }
  n = even_seq + 2u;
  if (n < 2u) {
    n = 2u;
  }
  return n;
}

uint32_t XcoreChecksum(const XcoreParamImage *image) {
  uint32_t words[sizeof(XcoreParamImage) / 4u];
  uint32_t sum;
  uint32_t i;

  if (image == NULL) {
    return 0u;
  }
  memcpy(words, image, sizeof(words));
  sum = 0u;
  for (i = 0; i < (uint32_t)(sizeof(words) / sizeof(words[0])); ++i) {
    sum += words[i];
  }
  return sum;
}

static void fill_ident(XcoreIdent *ident, uint32_t epoch, uint32_t ready) {
  memset(ident, 0, sizeof(*ident));
  ident->magic = XCORE_MAGIC;
  ident->abi_version = XCORE_ABI_VERSION;
  ident->ident_bytes = (uint32_t)sizeof(XcoreIdent);
  ident->ctrl_bytes = XCORE_CTRL_BYTES;
  ident->audio_bytes = XCORE_AUDIO_BYTES;
  ident->ctrl_struct_bytes = (uint32_t)sizeof(XcoreCtrl);
  ident->audio_struct_bytes = (uint32_t)sizeof(XcoreAudio);
  ident->epoch = epoch;
  ident->arm_ready = ready;
  ident->published_index = 0u;
  ident->frame_len = XCORE_FRAME_LEN;
  ident->lane_channels = XCORE_LANE_CH;
  ident->lane_count = XCORE_LANE_COUNT;
  ident->audio_slot_bytes = (uint32_t)sizeof(XcoreAudioSlot);
  ident->in_samples_off = (uint32_t)offsetof(XcoreAudioSlot, in_samples);
  ident->out_samples_off = (uint32_t)offsetof(XcoreAudioSlot, out_samples);
}

static int ident_matches(const XcoreIdent *ident) {
  if (load32(&ident->magic) != XCORE_MAGIC) {
    return XCORE_ERR_MAGIC;
  }
  if (load32(&ident->abi_version) != XCORE_ABI_VERSION) {
    return XCORE_ERR_VERSION;
  }
  if (load32(&ident->ident_bytes) != (uint32_t)sizeof(XcoreIdent) ||
      load32(&ident->ctrl_bytes) != XCORE_CTRL_BYTES ||
      load32(&ident->audio_bytes) != XCORE_AUDIO_BYTES ||
      load32(&ident->ctrl_struct_bytes) != (uint32_t)sizeof(XcoreCtrl) ||
      load32(&ident->audio_struct_bytes) != (uint32_t)sizeof(XcoreAudio) ||
      load32(&ident->audio_slot_bytes) != (uint32_t)sizeof(XcoreAudioSlot) ||
      load32(&ident->frame_len) != XCORE_FRAME_LEN ||
      load32(&ident->lane_channels) != XCORE_LANE_CH ||
      load32(&ident->lane_count) != XCORE_LANE_COUNT ||
      load32(&ident->in_samples_off) !=
          (uint32_t)offsetof(XcoreAudioSlot, in_samples) ||
      load32(&ident->out_samples_off) !=
          (uint32_t)offsetof(XcoreAudioSlot, out_samples)) {
    return XCORE_ERR_SIZE;
  }
  return XCORE_OK;
}

int XcoreArmReset(XcoreCtrl *ctrl, XcoreAudio *audio, uint32_t epoch) {
  if (ctrl == NULL || audio == NULL || epoch == 0u) {
    return XCORE_ERR_ARG;
  }
  /* Drop ready before the bytes move so a live SHARC does not sample a
   * half-cleared header. Cold boot does this before adi_core_enable. */
  store32(&ctrl->ident.arm_ready, 0u);
  XcoreWriteback(&ctrl->ident.arm_ready, sizeof(uint32_t));
  memset(ctrl, 0, sizeof(*ctrl));
  memset(audio, 0, sizeof(*audio));
  fill_ident(&ctrl->ident, epoch, 0u);
  XcoreWriteback(ctrl, sizeof(*ctrl));
  XcoreWriteback(audio, sizeof(*audio));
  store32(&ctrl->ident.arm_ready, XCORE_READY_MAGIC);
  XcoreWriteback(&ctrl->ident.arm_ready, sizeof(uint32_t));
  return XCORE_OK;
}

int XcoreArmPublish(XcoreCtrl *ctrl, const XcoreParamImage *image) {
  uint32_t idx;
  uint32_t cur;
  uint32_t odd;
  uint32_t even;
  uint32_t generation;
  XcoreParamSlot *slot;

  if (ctrl == NULL || image == NULL) {
    return XCORE_ERR_ARG;
  }
  if (load32(&ctrl->ident.arm_ready) != XCORE_READY_MAGIC) {
    return XCORE_ERR_NOT_READY;
  }
  idx = load32(&ctrl->ident.published_index) & 1u;
  if (load32(&ctrl->slot[idx].generation) != 0u) {
    idx ^= 1u;
  }
  slot = &ctrl->slot[idx];
  cur = load32(&slot->seq);
  even = next_even((cur & 1u) ? (cur + 1u) : cur);
  odd = even - 1u;
  generation = load32(&ctrl->slot[load32(&ctrl->ident.published_index) & 1u]
                          .generation);
  if (generation == 0xFFFFFFFFu) {
    generation = 1u;
  } else {
    generation += 1u;
  }
  if (generation == 0u) {
    generation = 1u;
  }

  store32(&slot->seq, odd);
  XcoreWriteback(&slot->seq, sizeof(uint32_t));
  slot->image = *image;
  store32(&slot->generation, generation);
  store32(&slot->checksum, XcoreChecksum(&slot->image));
  XcoreWriteback(&slot->generation,
                 sizeof(*slot) - offsetof(XcoreParamSlot, generation));
  store32(&slot->seq, even);
  XcoreWriteback(&slot->seq, sizeof(uint32_t));
  store32(&ctrl->ident.published_index, idx);
  store32(&ctrl->core[XCORE_CORE_ARM].ack_generation, generation);
  store32(&ctrl->core[XCORE_CORE_ARM].ack_epoch, load32(&ctrl->ident.epoch));
  store32(&ctrl->core[XCORE_CORE_ARM].applied_checksum, load32(&slot->checksum));
  XcoreWriteback(&ctrl->ident.published_index, sizeof(uint32_t));
  XcoreWriteback(&ctrl->core[XCORE_CORE_ARM], sizeof(XcoreCoreLine));
  return XCORE_OK;
}

int XcoreAttach(XcoreCtrl *ctrl, uint32_t core) {
  int rc;
  XcoreCoreLine *line;

  if (ctrl == NULL || core >= XCORE_CORE_NUM || core == XCORE_CORE_ARM) {
    return XCORE_ERR_ARG;
  }
  line = &ctrl->core[core];
  XcoreInvalidate(&ctrl->ident, sizeof(XcoreIdent));
  if (load32(&ctrl->ident.arm_ready) != XCORE_READY_MAGIC) {
    store32(&line->ready, 0u);
    store32(&line->error, (uint32_t)XCORE_ERR_NOT_READY);
    XcoreWriteback(line, sizeof(*line));
    return XCORE_ERR_NOT_READY;
  }
  rc = ident_matches(&ctrl->ident);
  if (rc != XCORE_OK) {
    store32(&line->ready, 0u);
    store32(&line->error, (uint32_t)rc);
    store32(&line->abi_seen, load32(&ctrl->ident.abi_version));
    XcoreWriteback(line, sizeof(*line));
    return rc;
  }
  store32(&line->ready, XCORE_READY_MAGIC);
  store32(&line->abi_seen, XCORE_ABI_VERSION);
  store32(&line->error, 0u);
  store32(&line->reset_seen, load32(&ctrl->ident.epoch));
  store32(&line->ack_generation, 0u);
  store32(&line->ack_epoch, 0u);
  store32(&line->applied_checksum, 0u);
  XcoreWriteback(line, sizeof(*line));
  return XCORE_OK;
}

int XcorePoll(XcoreCtrl *ctrl, uint32_t core, XcoreParamImage *out) {
  uint32_t idx;
  uint32_t seq1;
  uint32_t seq2;
  uint32_t epoch;
  uint32_t generation;
  uint32_t checksum;
  XcoreParamSlot *slot;
  XcoreCoreLine *line;
  XcoreParamImage image;

  if (ctrl == NULL || out == NULL || core == XCORE_CORE_ARM ||
      core >= XCORE_CORE_NUM) {
    return XCORE_ERR_ARG;
  }
  line = &ctrl->core[core];
  if (load32(&line->ready) != XCORE_READY_MAGIC) {
    return XCORE_ERR_NOT_READY;
  }
  XcoreInvalidate(&ctrl->ident, sizeof(XcoreIdent));
  if (load32(&ctrl->ident.arm_ready) != XCORE_READY_MAGIC) {
    store32(&line->ready, 0u);
    store32(&line->error, (uint32_t)XCORE_ERR_NOT_READY);
    XcoreWriteback(line, sizeof(*line));
    return XCORE_ERR_NOT_READY;
  }
  epoch = load32(&ctrl->ident.epoch);
  if (epoch != load32(&line->reset_seen)) {
    store32(&line->ack_generation, 0u);
    store32(&line->reset_seen, epoch);
    store32(&line->applied_checksum, 0u);
    XcoreWriteback(line, sizeof(*line));
  }
  idx = load32(&ctrl->ident.published_index) & 1u;
  slot = &ctrl->slot[idx];
  XcoreInvalidate(&slot->seq, sizeof(uint32_t) * 2u);
  seq1 = load32(&slot->seq);
  generation = load32(&slot->generation);
  if (seq1 != 0u && (seq1 & 1u) == 0u && generation != 0u &&
      generation == load32(&line->ack_generation) &&
      epoch == load32(&line->ack_epoch)) {
    /* Already applied. Leave *out alone so the main loop does not
     * republish a same-core gain snapshot on every spin. */
    return XCORE_UNCHANGED;
  }
  if (seq1 == 0u || (seq1 & 1u) != 0u) {
    return XCORE_ERR_PARTIAL;
  }
  XcoreInvalidate(&slot->generation,
                  sizeof(*slot) - offsetof(XcoreParamSlot, generation));
  generation = load32(&slot->generation);
  checksum = load32(&slot->checksum);
  image = slot->image;
  seq2 = load32(&slot->seq);
  if (seq1 != seq2 || (seq2 & 1u) != 0u) {
    return XCORE_ERR_PARTIAL;
  }
  if (checksum != XcoreChecksum(&image)) {
    return XCORE_ERR_CHECKSUM;
  }
  if (generation == 0u) {
    return XCORE_ERR_PARTIAL;
  }
  if (generation == load32(&line->ack_generation) &&
      epoch == load32(&line->ack_epoch)) {
    *out = image;
    return XCORE_OK;
  }
  *out = image;
  store32(&line->ack_generation, generation);
  store32(&line->ack_epoch, epoch);
  store32(&line->applied_checksum, checksum);
  store32(&line->error, 0u);
  XcoreWriteback(line, sizeof(*line));
  return XCORE_OK;
}

uint32_t XcorePublishedGeneration(const XcoreCtrl *ctrl) {
  uint32_t idx;
  if (ctrl == NULL) {
    return 0u;
  }
  idx = load32(&ctrl->ident.published_index) & 1u;
  return load32(&ctrl->slot[idx].generation);
}

uint32_t XcoreAckGeneration(const XcoreCtrl *ctrl, uint32_t core) {
  if (ctrl == NULL || core >= XCORE_CORE_NUM) {
    return 0u;
  }
  return load32(&ctrl->core[core].ack_generation);
}

uint32_t XcoreAudioSlotOf(uint32_t frame_index) {
  return frame_index % XCORE_AUDIO_SLOTS;
}

int XcoreAudioBegin(XcoreAudio *audio, uint32_t slot, uint32_t epoch,
                    uint32_t *odd_seq) {
  XcoreAudioSlot *s;
  uint32_t cur;
  uint32_t even;
  uint32_t odd;

  if (audio == NULL || odd_seq == NULL || slot >= XCORE_AUDIO_SLOTS ||
      epoch == 0u) {
    return XCORE_ERR_ARG;
  }
  s = &audio->slot[slot];
  cur = load32(&s->in_seq);
  even = next_even(cur);
  odd = even - 1u;
  store32(&s->in_seq, odd);
  store32(&s->in_epoch, epoch);
  XcoreWriteback(&s->in_seq, sizeof(uint32_t) * 2u);
  *odd_seq = odd;
  return XCORE_OK;
}

int XcoreAudioCommitIn(XcoreAudio *audio, uint32_t slot, uint32_t odd_seq,
                       const float *lane0, const float *lane1,
                       uint32_t *even_seq) {
  XcoreAudioSlot *s;
  uint32_t even;
  uint32_t samples;

  if (audio == NULL || lane0 == NULL || lane1 == NULL || even_seq == NULL ||
      slot >= XCORE_AUDIO_SLOTS || odd_seq == 0u || (odd_seq & 1u) == 0u) {
    return XCORE_ERR_ARG;
  }
  s = &audio->slot[slot];
  if (load32(&s->in_seq) != odd_seq) {
    return XCORE_ERR_STALE;
  }
  even = odd_seq + 1u;
  if (even == 0u) {
    even = 2u;
  }
  samples = XCORE_LANE_CH * XCORE_FRAME_LEN;
  memcpy(s->in_samples[0], lane0, sizeof(float) * samples);
  memcpy(s->in_samples[1], lane1, sizeof(float) * samples);
  store32(&s->channels, XCORE_LANE_CH);
  store32(&s->frame_len, XCORE_FRAME_LEN);
  store32(&s->lanes, XCORE_LANE_COUNT);
  store32(&s->in_samples_off, (uint32_t)offsetof(XcoreAudioSlot, in_samples));
  store32(&s->out_samples_off, (uint32_t)offsetof(XcoreAudioSlot, out_samples));
  XcoreWriteback(s->in_samples, sizeof(s->in_samples));
  XcoreWriteback(&s->channels, sizeof(uint32_t) * 6u);
  store32(&s->in_seq, even);
  XcoreWriteback(&s->in_seq, sizeof(uint32_t));
  *even_seq = even;
  return XCORE_OK;
}

int XcoreAudioPending(const XcoreAudio *audio, uint32_t slot, uint32_t epoch,
                      uint32_t *even_seq) {
  const XcoreAudioSlot *s;
  uint32_t seq;

  if (audio == NULL || even_seq == NULL || slot >= XCORE_AUDIO_SLOTS) {
    return XCORE_ERR_ARG;
  }
  s = &audio->slot[slot];
  seq = load32(&s->in_seq);
  if (seq == 0u || (seq & 1u) != 0u) {
    return XCORE_ERR_PARTIAL;
  }
  if (load32(&s->in_epoch) != epoch) {
    return XCORE_ERR_EPOCH;
  }
  if (load32(&s->out_seq) == seq) {
    return XCORE_ERR_STALE;
  }
  *even_seq = seq;
  return XCORE_OK;
}

int XcoreAudioReadIn(XcoreAudio *audio, uint32_t slot, uint32_t epoch,
                     float *lane0, float *lane1, uint32_t *even_seq) {
  XcoreAudioSlot *s;
  uint32_t seq1;
  uint32_t seq2;
  uint32_t samples;

  if (audio == NULL || lane0 == NULL || lane1 == NULL || even_seq == NULL ||
      slot >= XCORE_AUDIO_SLOTS) {
    return XCORE_ERR_ARG;
  }
  s = &audio->slot[slot];
  seq1 = load32(&s->in_seq);
  if (seq1 == 0u || (seq1 & 1u) != 0u || load32(&s->in_epoch) != epoch) {
    return XCORE_ERR_PARTIAL;
  }
  XcoreInvalidate(s->in_samples, sizeof(s->in_samples));
  samples = XCORE_LANE_CH * XCORE_FRAME_LEN;
  memcpy(lane0, s->in_samples[0], sizeof(float) * samples);
  memcpy(lane1, s->in_samples[1], sizeof(float) * samples);
  seq2 = load32(&s->in_seq);
  if (seq1 != seq2) {
    return XCORE_ERR_PARTIAL;
  }
  *even_seq = seq1;
  return XCORE_OK;
}

int XcoreAudioCommitOut(XcoreAudio *audio, uint32_t slot, uint32_t even_seq,
                        uint32_t epoch, const float *lane0, const float *lane1) {
  XcoreAudioSlot *s;
  uint32_t samples;

  if (audio == NULL || lane0 == NULL || lane1 == NULL ||
      slot >= XCORE_AUDIO_SLOTS || even_seq == 0u || (even_seq & 1u) != 0u) {
    return XCORE_ERR_ARG;
  }
  s = &audio->slot[slot];
  if (load32(&s->in_seq) != even_seq || load32(&s->in_epoch) != epoch) {
    return XCORE_ERR_STALE;
  }
  samples = XCORE_LANE_CH * XCORE_FRAME_LEN;
  store32(&s->out_seq, even_seq - 1u);
  XcoreWriteback(&s->out_seq, sizeof(uint32_t));
  memcpy(s->out_samples[0], lane0, sizeof(float) * samples);
  memcpy(s->out_samples[1], lane1, sizeof(float) * samples);
  store32(&s->out_epoch, epoch);
  XcoreWriteback(s->out_samples, sizeof(s->out_samples));
  if (load32(&s->in_seq) != even_seq) {
    return XCORE_ERR_STALE;
  }
  store32(&s->out_seq, even_seq);
  XcoreWriteback(&s->out_seq, sizeof(uint32_t));
  return XCORE_OK;
}

int XcoreAudioReadOut(XcoreAudio *audio, uint32_t slot, uint32_t even_seq,
                      float *lane0, float *lane1) {
  XcoreAudioSlot *s;
  uint32_t seq1;
  uint32_t samples;

  if (audio == NULL || lane0 == NULL || lane1 == NULL ||
      slot >= XCORE_AUDIO_SLOTS || even_seq == 0u || (even_seq & 1u) != 0u) {
    return XCORE_ERR_ARG;
  }
  s = &audio->slot[slot];
  XcoreInvalidate(&s->out_seq, sizeof(uint32_t));
  seq1 = load32(&s->out_seq);
  if (seq1 != even_seq) {
    return XCORE_ERR_STALE;
  }
  XcoreInvalidate(s->out_samples, sizeof(s->out_samples));
  samples = XCORE_LANE_CH * XCORE_FRAME_LEN;
  memcpy(lane0, s->out_samples[0], sizeof(float) * samples);
  memcpy(lane1, s->out_samples[1], sizeof(float) * samples);
  if (load32(&s->out_seq) != even_seq) {
    return XCORE_ERR_PARTIAL;
  }
  return XCORE_OK;
}

void XcoreMapLaneToDac(float *dac, uint32_t dac_ch, const float *lane) {
  if (dac == NULL || lane == NULL) {
    return;
  }
  memcpy(dac + (dac_ch * XCORE_FRAME_LEN), lane,
         sizeof(float) * XCORE_LANE_CH * XCORE_FRAME_LEN);
}

void XcoreMapLaneToTx(float *tx, const float *lane) {
  if (tx == NULL || lane == NULL) {
    return;
  }
  memcpy(tx, lane, sizeof(float) * XCORE_LANE_CH * XCORE_FRAME_LEN);
}

void XcoreWriteStat(XcoreCtrl *ctrl, uint32_t core, const XcoreDspStat *stat) {
  XcoreDspStat *dst;

  if (ctrl == NULL || stat == NULL || core < XCORE_CORE_SHARC1 ||
      core > XCORE_CORE_SHARC2) {
    return;
  }
  dst = &ctrl->stat[core - XCORE_CORE_SHARC1];
  *dst = *stat;
  XcoreWriteback(dst, sizeof(*dst));
}

int XcoreReadStat(XcoreCtrl *ctrl, uint32_t core, XcoreDspStat *stat) {
  XcoreDspStat *src;
  uint32_t magic;

  if (ctrl == NULL || stat == NULL || core < XCORE_CORE_SHARC1 ||
      core > XCORE_CORE_SHARC2) {
    return XCORE_ERR_ARG;
  }
  src = &ctrl->stat[core - XCORE_CORE_SHARC1];
  XcoreInvalidate(src, sizeof(*src));
  *stat = *src;
  magic = (core == XCORE_CORE_SHARC1) ? XCORE_STAT_MAGIC_SH1 : XCORE_STAT_MAGIC_SH2;
  if (stat->magic != magic) {
    return XCORE_ERR_NOT_READY;
  }
  return XCORE_OK;
}
