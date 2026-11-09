#include <stdint.h>
#include <math.h>

#include "audio_flow.h"
#include "sport/sport.h"

/*
 * Same mix as adsp21593 sharc1/src/algo/algo/algo.c.
 * ADC 0-3 pass through. DAC 4-7 are a 1 kHz tone.
 * DAC 8-11 are filled by the SPORT callback from SHARC2's A2B0 lane.
 * SHARC1 owns the stream; this function does not touch A2B or DAC 8-15.
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
  }
}
