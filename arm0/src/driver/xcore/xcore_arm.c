#include "xcore_arm.h"

#include <string.h>

#include "../../../../common/xcore_proto.h"

static XcoreCtrl *const ctrl = (XcoreCtrl *)XCORE_CTRL_ADDR;
static XcoreAudio *const audio = (XcoreAudio *)XCORE_AUDIO_ADDR;

static void ImageDefaults(XcoreParamImage *image, uint32_t a2b0_nodes,
                          int a2b0_script_ran, int a2b1_imported,
                          int a2b1_script_ran) {
  uint32_t i;

  memset(image, 0, sizeof(*image));
  image->flags = XCORE_FLAG_STREAM_RUN | XCORE_FLAG_A2B0_SPORT |
                 XCORE_FLAG_A2B1_SPORT;
  image->a2b0_link = a2b0_script_ran ? XCORE_A2B_LINK_UP : XCORE_A2B_LINK_OFF;
  image->a2b0_nodes = a2b0_nodes;
  if (!a2b1_imported) {
    image->a2b1_link = XCORE_A2B_LINK_DEFAULT;
    image->a2b1_cfg = XCORE_A2B1_CFG_DEFAULT;
    image->a2b1_tx_mute = 1u;
  } else if (a2b1_script_ran) {
    image->a2b1_link = XCORE_A2B_LINK_UP;
    image->a2b1_cfg = XCORE_A2B1_CFG_IMPORTED;
    image->a2b1_tx_mute = 0u;
  } else {
    image->a2b1_link = XCORE_A2B_LINK_OFF;
    image->a2b1_cfg = XCORE_A2B1_CFG_IMPORTED;
    image->a2b1_tx_mute = 0u;
  }
  image->a2b1_nodes = 0u;
  image->sport_a2b0_dev = XCORE_SPORT_A2B0;
  image->sport_a2b1_dev = XCORE_SPORT_A2B1;
  image->dac_lane0_ch = XCORE_DAC_LANE0_CH;
  image->lane_count = XCORE_LANE_COUNT;
  image->frame_len = XCORE_FRAME_LEN;
  image->gain_sharc1_base = XCORE_GAIN_SHARC1;
  image->gain_lane0_base = XCORE_GAIN_LANE0;
  image->gain_lane1_base = XCORE_GAIN_LANE1;
  for (i = 0; i < XCORE_GAIN_NUM; ++i) {
    image->gain[i] = 1.f;
  }
}

void XcoreArmBoot(uint32_t a2b0_nodes, int a2b0_script_ran, int a2b1_imported,
                  int a2b1_script_ran) {
  XcoreParamImage image;

  XcoreArmReset(ctrl, audio, 1u);
  ImageDefaults(&image, a2b0_nodes, a2b0_script_ran, a2b1_imported,
                a2b1_script_ran);
  XcoreArmPublish(ctrl, &image);
}

int XcoreArmReadStat(uint32_t core, XcoreDspStat *stat) {
  return XcoreReadStat(ctrl, core, stat);
}

uint32_t XcoreArmAck(uint32_t core) {
  return XcoreAckGeneration(ctrl, core);
}

uint32_t XcoreArmPublished(void) {
  return XcorePublishedGeneration(ctrl);
}

uint32_t XcoreArmA2b1Cfg(void) {
  uint32_t idx = ctrl->ident.published_index & 1u;
  return ctrl->slot[idx].image.a2b1_cfg;
}

uint32_t XcoreArmA2b1Mute(void) {
  uint32_t idx = ctrl->ident.published_index & 1u;
  return ctrl->slot[idx].image.a2b1_tx_mute;
}
