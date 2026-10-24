#ifndef AUDIO_FLOW_H_
#define AUDIO_FLOW_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Control-plane bring-up. Real-time AudioProcess() runs on SHARC1. */
void AudioCtrlInit(void);

#ifdef __cplusplus
}
#endif

#endif /* AUDIO_FLOW_H_ */
