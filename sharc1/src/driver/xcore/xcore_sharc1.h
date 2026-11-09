#ifndef XCORE_SHARC1_H_
#define XCORE_SHARC1_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void XcoreSharc1Boot(void);
void XcoreSharc1Poll(void);
int XcoreSharc2Ready(void);
int XcoreSharc1Push(const float *a2b0_in, const float *a2b1_in,
                    uint32_t *slot, uint32_t *seq);
int XcoreSharc1Pull(uint32_t slot, uint32_t seq, float *dac, float *a2b1_out);
void XcoreSharc1ApplyGain(float *dac);
void XcoreSharc1NoteLoad(float cpu, float max_cpu, float ave, float tot,
                         uint32_t frames, uint32_t misses, uint32_t seq);

#ifdef __cplusplus
}
#endif

#endif /* XCORE_SHARC1_H_ */
