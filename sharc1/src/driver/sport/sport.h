#ifndef SPORT_H_
#define SPORT_H_

#ifdef __cplusplus
extern "C" {
#endif

#define FRAME_LEN   (48u)
#define TDM_NORM    (16u)
#define TDM_A2B     (2u * TDM_NORM)

float* adc_in(void);
float* dac_out(void);
float* a2b0_in(void);
float* a2b0_out(void);
float* a2b1_in(void);
float* a2b1_out(void);
void SpInit(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // SPORT_H_
