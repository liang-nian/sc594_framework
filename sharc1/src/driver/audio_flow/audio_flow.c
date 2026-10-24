#include <stdint.h>
#include <math.h>

#include "audio_flow.h"
#include "sport/sport.h"

/*
 * Same demo mix as the 21593 AudioProcess: ADC loopback on DAC 0-3,
 * 1 kHz on DAC 4-7, selected A2B0 slots on DAC 8-11.
 * Channel-major indexing, FRAME_LEN samples per channel.
 */

static float Harm1000(void) {
  static float ft = 0.f;
  ft += 1000.f / 48000.f;
  ft = ft - floorf(ft);
  return sinf(2.f * 3.14159265358979323846f * ft);
}

void AudioProcess(void) {
  uint32_t i;
  float sin_1000;
  float* dac_out_ptr = dac_out();
  float* adc_in_ptr = adc_in();
  float* a2b0_in_ptr = a2b0_in();
  for (i = 0; i < FRAME_LEN; ++i) {
    sin_1000 = Harm1000();
    dac_out_ptr[i] = adc_in_ptr[i];
    dac_out_ptr[FRAME_LEN + i] = adc_in_ptr[FRAME_LEN + i];
    dac_out_ptr[2 * FRAME_LEN + i] = adc_in_ptr[2 * FRAME_LEN + i];
    dac_out_ptr[3 * FRAME_LEN + i] = adc_in_ptr[3 * FRAME_LEN + i];
    dac_out_ptr[4 * FRAME_LEN + i] = sin_1000;
    dac_out_ptr[5 * FRAME_LEN + i] = sin_1000;
    dac_out_ptr[6 * FRAME_LEN + i] = sin_1000;
    dac_out_ptr[7 * FRAME_LEN + i] = sin_1000;
    dac_out_ptr[8 * FRAME_LEN + i] = a2b0_in_ptr[i];
    dac_out_ptr[9 * FRAME_LEN + i] = a2b0_in_ptr[2 * FRAME_LEN + i];
    dac_out_ptr[10 * FRAME_LEN + i] = a2b0_in_ptr[FRAME_LEN + i];
    dac_out_ptr[11 * FRAME_LEN + i] = a2b0_in_ptr[3 * FRAME_LEN + i];
  }
}
