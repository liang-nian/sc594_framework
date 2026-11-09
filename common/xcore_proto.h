#ifndef XCORE_PROTO_H_
#define XCORE_PROTO_H_

#include "xcore_abi.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Target ports and the host test supply these. A writeback covers the
 * bytes just stored. An invalidate drops stale lines before a read.
 * ARM's port is a DSB (the window is MMU-uncached). SHARC's port calls
 * flush_data_buffer. The host port records the order. */
void XcoreWriteback(void *addr, uint32_t bytes);
void XcoreInvalidate(void *addr, uint32_t bytes);
/* Compiler barrier for a same-core snapshot. Does not touch the cache. */
void XcoreBarrier(void);

int XcoreArmReset(XcoreCtrl *ctrl, XcoreAudio *audio, uint32_t epoch);
int XcoreArmPublish(XcoreCtrl *ctrl, const XcoreParamImage *image);

int XcoreAttach(XcoreCtrl *ctrl, uint32_t core);
int XcorePoll(XcoreCtrl *ctrl, uint32_t core, XcoreParamImage *out);

uint32_t XcorePublishedGeneration(const XcoreCtrl *ctrl);
uint32_t XcoreAckGeneration(const XcoreCtrl *ctrl, uint32_t core);

/* Audio slots. seq 0 is empty. Odd seq means the owner is writing.
 * Even seq is a published frame. The slot index wraps at XCORE_AUDIO_SLOTS. */
uint32_t XcoreAudioSlotOf(uint32_t frame_index);
int XcoreAudioBegin(XcoreAudio *audio, uint32_t slot, uint32_t epoch,
                    uint32_t *odd_seq);
int XcoreAudioCommitIn(XcoreAudio *audio, uint32_t slot, uint32_t odd_seq,
                       const float *lane0, const float *lane1,
                       uint32_t *even_seq);
int XcoreAudioPending(const XcoreAudio *audio, uint32_t slot, uint32_t epoch,
                      uint32_t *even_seq);
int XcoreAudioReadIn(XcoreAudio *audio, uint32_t slot, uint32_t epoch,
                     float *lane0, float *lane1, uint32_t *even_seq);
int XcoreAudioCommitOut(XcoreAudio *audio, uint32_t slot, uint32_t even_seq,
                        uint32_t epoch, const float *lane0, const float *lane1);
int XcoreAudioReadOut(XcoreAudio *audio, uint32_t slot, uint32_t even_seq,
                      float *lane0, float *lane1);

void XcoreMapLaneToDac(float *dac, uint32_t dac_ch, const float *lane);
void XcoreMapLaneToTx(float *tx, const float *lane);
/* Lane 0 always feeds DAC channels 8-11. Lane 1 is always the SPORT5
 * consumer: tx_mute replaces that copy with silence and does not skip
 * the read. Channels past the 4-channel lane are left unchanged. */
void XcoreRouteOutputs(float *dac, float *a2b1_tx, const float *lane0,
                       const float *lane1, uint32_t tx_mute);

void XcoreWriteStat(XcoreCtrl *ctrl, uint32_t core, const XcoreDspStat *stat);
int XcoreReadStat(XcoreCtrl *ctrl, uint32_t core, XcoreDspStat *stat);

uint32_t XcoreChecksum(const XcoreParamImage *image);

#ifdef __cplusplus
}
#endif

#endif /* XCORE_PROTO_H_ */
