#ifndef AUDIO_FLOW_H_
#define AUDIO_FLOW_H_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Real-time mix. Runs on SHARC1 from the SPORT TRU callback.
 * Device init (UART, TWI, A2B, codecs, SRU) is AudioCtrlInit() on ARM.
 */
void AudioProcess(void);

#ifdef __cplusplus
}
#endif

#endif /* AUDIO_FLOW_H_ */
