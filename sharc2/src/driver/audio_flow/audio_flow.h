#ifndef AUDIO_FLOW_H_
#define AUDIO_FLOW_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Installs the same system software interrupt the 21593 SHARC2 uses. */
void AudioFlowInit(void);

#ifdef __cplusplus
}
#endif

#endif /* AUDIO_FLOW_H_ */
