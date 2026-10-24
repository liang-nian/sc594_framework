#include "ad2428_reg.h"

static unsigned char gaConfig_A2BMasterNode_CONTROL_Data0[1] =
{
  0x84u
};

static unsigned char gaConfig_A2BMasterNode_A2BDelay_Data1[1] =
{
  0x19u
};

static unsigned char gaConfig_A2BMasterNode_INTTYPE_Data2[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_INTMSK0_Data3[1] =
{
  0x70u
};

static unsigned char gaConfig_A2BMasterNode_INTMSK1_Data4[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_INTMSK2_Data5[1] =
{
  0x0Du
};

static unsigned char gaConfig_A2BMasterNode_BECCTL_Data6[1] =
{
  0xFFu
};

static unsigned char gaConfig_A2BMasterNode_INTPND2_Data7[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_RESPCYCS_Data8[1] =
{
  0x46u
};

static unsigned char gaConfig_A2BMasterNode_CONTROL_Data9[1] =
{
  0x81u
};

static unsigned char gaConfig_A2BMasterNode_A2BDelay_Data10[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_I2SGCFG_Data11[1] =
{
  0x44u
};

static unsigned char gaConfig_A2BMasterNode_SWCTL_Data12[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_I2CCFG_Data13[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_I2STXOFFSET_Data14[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_I2SRXOFFSET_Data15[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_I2SCFG_Data16[1] =
{
  0x93u
};

static unsigned char gaConfig_A2BMasterNode_PDMCTL_Data17[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_PDMCTL2_Data18[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_ERRMGMT_Data19[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_GPIODAT_Data20[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_GPIOOEN_Data21[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_GPIOIEN_Data22[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_PINTEN_Data23[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_PINTINV_Data24[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_PINCFG_Data25[1] =
{
  0x11u
};

static unsigned char gaConfig_A2BMasterNode_TESTMODE_Data26[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_CLK1CFG_Data27[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_CLK2CFG_Data28[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_GPIOD0MSK_Data29[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_GPIOD1MSK_Data30[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_GPIOD2MSK_Data31[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_GPIOD3MSK_Data32[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_GPIOD4MSK_Data33[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_GPIOD5MSK_Data34[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_GPIOD6MSK_Data35[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_GPIOD7MSK_Data36[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_GPIODINV_Data37[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_GPIODEN_Data38[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_I2SRRCTL_Data39[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_TXACTL_Data40[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_TXBCTL_Data41[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_BECCTL_Data42[1] =
{
  0xFFu
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data43[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_DISCVRY_Data44[1] =
{
  0x46u
};

static unsigned char gaConfig_A2BMasterNode_A2BDelay_Data45[1] =
{
  0x32u
};

static unsigned char gaConfig_A2BMasterNode_INTTYPE_Data46[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_SWCTL_Data47[1] =
{
  0x21u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data48[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_VENDOR_Data0[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_PRODUCT_Data1[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_VERSION_Data2[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data49[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_CONTROL_Data3[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_SWCTL_Data4[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data50[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_BCDNSLOTS_Data5[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_LDNSLOTS_Data6[1] =
{
  0x80u
};

static unsigned char gaConfig_A2BDMIC0_LUPSLOTS_Data7[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC0_I2CCFG_Data8[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_PDMCTL_Data9[1] =
{
  0x15u
};

static unsigned char gaConfig_A2BDMIC0_PDMCTL2_Data10[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_ERRMGMT_Data11[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_GPIODAT_Data12[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_GPIOOEN_Data13[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_GPIOIEN_Data14[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_PINTEN_Data15[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_PINTINV_Data16[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_PINCFG_Data17[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BDMIC0_TESTMODE_Data18[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_CLK1CFG_Data19[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_CLK2CFG_Data20[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_UPMASK0_Data21[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_UPMASK1_Data22[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_UPMASK2_Data23[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_UPMASK3_Data24[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_UPOFFSET_Data25[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_DNMASK0_Data26[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_DNMASK1_Data27[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_DNMASK2_Data28[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_DNMASK3_Data29[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_DNOFFSET_Data30[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_GPIOD0MSK_Data31[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_GPIOD1MSK_Data32[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_GPIOD2MSK_Data33[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_GPIOD3MSK_Data34[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_GPIOD4MSK_Data35[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_GPIOD5MSK_Data36[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_GPIOD6MSK_Data37[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_GPIOD7MSK_Data38[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_GPIODINV_Data39[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_GPIODEN_Data40[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_MBOX0CTL_Data41[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_MBOX1CTL_Data42[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC0_SUSCFG_Data43[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_I2SRRSOFFS_Data44[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_I2SRRCTL_Data45[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_TXACTL_Data46[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_TXBCTL_Data47[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_INTMSK0_Data48[1] =
{
  0x70u
};

static unsigned char gaConfig_A2BDMIC0_INTMSK1_Data49[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_BECCTL_Data50[1] =
{
  0xFFu
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data51[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_DISCVRY_Data52[1] =
{
  0x42u
};

static unsigned char gaConfig_A2BMasterNode_A2BDelay_Data53[1] =
{
  0x32u
};

static unsigned char gaConfig_A2BMasterNode_INTTYPE_Data54[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data55[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_SWCTL_Data51[1] =
{
  0x21u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data56[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BDMIC1_VENDOR_Data0[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_PRODUCT_Data1[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_VERSION_Data2[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data57[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BDMIC1_CONTROL_Data3[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_SWCTL_Data4[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data58[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BDMIC1_BCDNSLOTS_Data5[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_LDNSLOTS_Data6[1] =
{
  0x80u
};

static unsigned char gaConfig_A2BDMIC1_LUPSLOTS_Data7[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC1_I2CCFG_Data8[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_PDMCTL_Data9[1] =
{
  0x15u
};

static unsigned char gaConfig_A2BDMIC1_PDMCTL2_Data10[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_ERRMGMT_Data11[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_GPIODAT_Data12[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_GPIOOEN_Data13[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_GPIOIEN_Data14[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_PINTEN_Data15[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_PINTINV_Data16[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_PINCFG_Data17[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BDMIC1_TESTMODE_Data18[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_CLK1CFG_Data19[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_CLK2CFG_Data20[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_UPMASK0_Data21[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_UPMASK1_Data22[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_UPMASK2_Data23[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_UPMASK3_Data24[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_UPOFFSET_Data25[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_DNMASK0_Data26[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_DNMASK1_Data27[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_DNMASK2_Data28[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_DNMASK3_Data29[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_DNOFFSET_Data30[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_GPIOD0MSK_Data31[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_GPIOD1MSK_Data32[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_GPIOD2MSK_Data33[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_GPIOD3MSK_Data34[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_GPIOD4MSK_Data35[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_GPIOD5MSK_Data36[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_GPIOD6MSK_Data37[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_GPIOD7MSK_Data38[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_GPIODINV_Data39[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_GPIODEN_Data40[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_MBOX0CTL_Data41[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_MBOX1CTL_Data42[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC1_SUSCFG_Data43[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_I2SRRSOFFS_Data44[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_I2SRRCTL_Data45[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_TXACTL_Data46[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_TXBCTL_Data47[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_INTMSK0_Data48[1] =
{
  0x70u
};

static unsigned char gaConfig_A2BDMIC1_INTMSK1_Data49[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_BECCTL_Data50[1] =
{
  0xFFu
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data59[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_DISCVRY_Data60[1] =
{
  0x3Eu
};

static unsigned char gaConfig_A2BMasterNode_A2BDelay_Data61[1] =
{
  0x32u
};

static unsigned char gaConfig_A2BMasterNode_INTTYPE_Data62[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data63[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BDMIC1_SWCTL_Data51[1] =
{
  0x21u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data64[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC2_VENDOR_Data0[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_PRODUCT_Data1[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_VERSION_Data2[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data65[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC2_CONTROL_Data3[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_SWCTL_Data4[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data66[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC2_BCDNSLOTS_Data5[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_LDNSLOTS_Data6[1] =
{
  0x80u
};

static unsigned char gaConfig_A2BDMIC2_LUPSLOTS_Data7[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC2_I2CCFG_Data8[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_PDMCTL_Data9[1] =
{
  0x15u
};

static unsigned char gaConfig_A2BDMIC2_PDMCTL2_Data10[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_ERRMGMT_Data11[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_GPIODAT_Data12[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_GPIOOEN_Data13[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_GPIOIEN_Data14[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_PINTEN_Data15[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_PINTINV_Data16[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_PINCFG_Data17[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BDMIC2_TESTMODE_Data18[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_CLK1CFG_Data19[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_CLK2CFG_Data20[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_UPMASK0_Data21[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_UPMASK1_Data22[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_UPMASK2_Data23[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_UPMASK3_Data24[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_UPOFFSET_Data25[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_DNMASK0_Data26[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_DNMASK1_Data27[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_DNMASK2_Data28[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_DNMASK3_Data29[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_DNOFFSET_Data30[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_GPIOD0MSK_Data31[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_GPIOD1MSK_Data32[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_GPIOD2MSK_Data33[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_GPIOD3MSK_Data34[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_GPIOD4MSK_Data35[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_GPIOD5MSK_Data36[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_GPIOD6MSK_Data37[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_GPIOD7MSK_Data38[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_GPIODINV_Data39[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_GPIODEN_Data40[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_MBOX0CTL_Data41[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_MBOX1CTL_Data42[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC2_SUSCFG_Data43[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_I2SRRSOFFS_Data44[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_I2SRRCTL_Data45[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_TXACTL_Data46[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_TXBCTL_Data47[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_INTMSK0_Data48[1] =
{
  0x70u
};

static unsigned char gaConfig_A2BDMIC2_INTMSK1_Data49[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_BECCTL_Data50[1] =
{
  0xFFu
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data67[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BMasterNode_DISCVRY_Data68[1] =
{
  0x3Au
};

static unsigned char gaConfig_A2BMasterNode_A2BDelay_Data69[1] =
{
  0x32u
};

static unsigned char gaConfig_A2BMasterNode_INTTYPE_Data70[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data71[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC2_SWCTL_Data51[1] =
{
  0x21u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data72[1] =
{
  0x03u
};

static unsigned char gaConfig_A2BDMIC3_VENDOR_Data0[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_PRODUCT_Data1[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_VERSION_Data2[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data73[1] =
{
  0x03u
};

static unsigned char gaConfig_A2BDMIC3_CONTROL_Data3[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_SWCTL_Data4[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data74[1] =
{
  0x03u
};

static unsigned char gaConfig_A2BDMIC3_BCDNSLOTS_Data5[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_LDNSLOTS_Data6[1] =
{
  0x80u
};

static unsigned char gaConfig_A2BDMIC3_LUPSLOTS_Data7[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC3_I2CCFG_Data8[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_PDMCTL_Data9[1] =
{
  0x15u
};

static unsigned char gaConfig_A2BDMIC3_PDMCTL2_Data10[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_ERRMGMT_Data11[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_GPIODAT_Data12[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_GPIOOEN_Data13[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_GPIOIEN_Data14[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_PINTEN_Data15[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_PINTINV_Data16[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_PINCFG_Data17[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BDMIC3_TESTMODE_Data18[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_CLK1CFG_Data19[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_CLK2CFG_Data20[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_UPMASK0_Data21[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_UPMASK1_Data22[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_UPMASK2_Data23[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_UPMASK3_Data24[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_UPOFFSET_Data25[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_DNMASK0_Data26[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_DNMASK1_Data27[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_DNMASK2_Data28[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_DNMASK3_Data29[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_DNOFFSET_Data30[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_GPIOD0MSK_Data31[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_GPIOD1MSK_Data32[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_GPIOD2MSK_Data33[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_GPIOD3MSK_Data34[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_GPIOD4MSK_Data35[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_GPIOD5MSK_Data36[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_GPIOD6MSK_Data37[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_GPIOD7MSK_Data38[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_GPIODINV_Data39[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_GPIODEN_Data40[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_MBOX0CTL_Data41[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_MBOX1CTL_Data42[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC3_SUSCFG_Data43[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_I2SRRSOFFS_Data44[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_I2SRRCTL_Data45[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_TXACTL_Data46[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_TXBCTL_Data47[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_INTMSK0_Data48[1] =
{
  0x70u
};

static unsigned char gaConfig_A2BDMIC3_INTMSK1_Data49[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_BECCTL_Data50[1] =
{
  0xFFu
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data75[1] =
{
  0x03u
};

static unsigned char gaConfig_A2BMasterNode_DISCVRY_Data76[1] =
{
  0x35u
};

static unsigned char gaConfig_A2BMasterNode_A2BDelay_Data77[1] =
{
  0x32u
};

static unsigned char gaConfig_A2BMasterNode_INTTYPE_Data78[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data79[1] =
{
  0x03u
};

static unsigned char gaConfig_A2BDMIC3_SWCTL_Data51[1] =
{
  0x21u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data80[1] =
{
  0x04u
};

static unsigned char gaConfig_A2BDMIC4_VENDOR_Data0[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_PRODUCT_Data1[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_VERSION_Data2[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data81[1] =
{
  0x04u
};

static unsigned char gaConfig_A2BDMIC4_CONTROL_Data3[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_SWCTL_Data4[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data82[1] =
{
  0x04u
};

static unsigned char gaConfig_A2BDMIC4_BCDNSLOTS_Data5[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_LDNSLOTS_Data6[1] =
{
  0x80u
};

static unsigned char gaConfig_A2BDMIC4_LUPSLOTS_Data7[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC4_I2CCFG_Data8[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_PDMCTL_Data9[1] =
{
  0x15u
};

static unsigned char gaConfig_A2BDMIC4_PDMCTL2_Data10[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_ERRMGMT_Data11[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_GPIODAT_Data12[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_GPIOOEN_Data13[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_GPIOIEN_Data14[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_PINTEN_Data15[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_PINTINV_Data16[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_PINCFG_Data17[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BDMIC4_TESTMODE_Data18[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_CLK1CFG_Data19[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_CLK2CFG_Data20[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_UPMASK0_Data21[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_UPMASK1_Data22[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_UPMASK2_Data23[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_UPMASK3_Data24[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_UPOFFSET_Data25[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_DNMASK0_Data26[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_DNMASK1_Data27[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_DNMASK2_Data28[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_DNMASK3_Data29[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_DNOFFSET_Data30[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_GPIOD0MSK_Data31[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_GPIOD1MSK_Data32[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_GPIOD2MSK_Data33[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_GPIOD3MSK_Data34[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_GPIOD4MSK_Data35[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_GPIOD5MSK_Data36[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_GPIOD6MSK_Data37[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_GPIOD7MSK_Data38[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_GPIODINV_Data39[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_GPIODEN_Data40[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_MBOX0CTL_Data41[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_MBOX1CTL_Data42[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC4_SUSCFG_Data43[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_I2SRRSOFFS_Data44[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_I2SRRCTL_Data45[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_TXACTL_Data46[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_TXBCTL_Data47[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_INTMSK0_Data48[1] =
{
  0x70u
};

static unsigned char gaConfig_A2BDMIC4_INTMSK1_Data49[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_BECCTL_Data50[1] =
{
  0xFFu
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data83[1] =
{
  0x04u
};

static unsigned char gaConfig_A2BMasterNode_DISCVRY_Data84[1] =
{
  0x31u
};

static unsigned char gaConfig_A2BMasterNode_A2BDelay_Data85[1] =
{
  0x32u
};

static unsigned char gaConfig_A2BMasterNode_INTTYPE_Data86[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data87[1] =
{
  0x04u
};

static unsigned char gaConfig_A2BDMIC4_SWCTL_Data51[1] =
{
  0x21u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data88[1] =
{
  0x05u
};

static unsigned char gaConfig_A2BDMIC5_VENDOR_Data0[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_PRODUCT_Data1[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_VERSION_Data2[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data89[1] =
{
  0x05u
};

static unsigned char gaConfig_A2BDMIC5_CONTROL_Data3[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_SWCTL_Data4[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data90[1] =
{
  0x05u
};

static unsigned char gaConfig_A2BDMIC5_BCDNSLOTS_Data5[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_LDNSLOTS_Data6[1] =
{
  0x80u
};

static unsigned char gaConfig_A2BDMIC5_LUPSLOTS_Data7[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC5_I2CCFG_Data8[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_PDMCTL_Data9[1] =
{
  0x15u
};

static unsigned char gaConfig_A2BDMIC5_PDMCTL2_Data10[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_ERRMGMT_Data11[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_GPIODAT_Data12[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_GPIOOEN_Data13[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_GPIOIEN_Data14[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_PINTEN_Data15[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_PINTINV_Data16[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_PINCFG_Data17[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BDMIC5_TESTMODE_Data18[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_CLK1CFG_Data19[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_CLK2CFG_Data20[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_UPMASK0_Data21[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_UPMASK1_Data22[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_UPMASK2_Data23[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_UPMASK3_Data24[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_UPOFFSET_Data25[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_DNMASK0_Data26[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_DNMASK1_Data27[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_DNMASK2_Data28[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_DNMASK3_Data29[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_DNOFFSET_Data30[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_GPIOD0MSK_Data31[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_GPIOD1MSK_Data32[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_GPIOD2MSK_Data33[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_GPIOD3MSK_Data34[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_GPIOD4MSK_Data35[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_GPIOD5MSK_Data36[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_GPIOD6MSK_Data37[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_GPIOD7MSK_Data38[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_GPIODINV_Data39[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_GPIODEN_Data40[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_MBOX0CTL_Data41[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_MBOX1CTL_Data42[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC5_SUSCFG_Data43[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_I2SRRSOFFS_Data44[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_I2SRRCTL_Data45[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_TXACTL_Data46[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_TXBCTL_Data47[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_INTMSK0_Data48[1] =
{
  0x70u
};

static unsigned char gaConfig_A2BDMIC5_INTMSK1_Data49[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_BECCTL_Data50[1] =
{
  0xFFu
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data91[1] =
{
  0x05u
};

static unsigned char gaConfig_A2BMasterNode_DISCVRY_Data92[1] =
{
  0x2Du
};

static unsigned char gaConfig_A2BMasterNode_A2BDelay_Data93[1] =
{
  0x32u
};

static unsigned char gaConfig_A2BMasterNode_INTTYPE_Data94[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data95[1] =
{
  0x05u
};

static unsigned char gaConfig_A2BDMIC5_SWCTL_Data51[1] =
{
  0x21u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data96[1] =
{
  0x06u
};

static unsigned char gaConfig_A2BDMIC6_VENDOR_Data0[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_PRODUCT_Data1[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_VERSION_Data2[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data97[1] =
{
  0x06u
};

static unsigned char gaConfig_A2BDMIC6_CONTROL_Data3[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_SWCTL_Data4[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data98[1] =
{
  0x06u
};

static unsigned char gaConfig_A2BDMIC6_BCDNSLOTS_Data5[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_LDNSLOTS_Data6[1] =
{
  0x80u
};

static unsigned char gaConfig_A2BDMIC6_LUPSLOTS_Data7[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC6_I2CCFG_Data8[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_PDMCTL_Data9[1] =
{
  0x15u
};

static unsigned char gaConfig_A2BDMIC6_PDMCTL2_Data10[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_ERRMGMT_Data11[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_GPIODAT_Data12[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_GPIOOEN_Data13[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_GPIOIEN_Data14[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_PINTEN_Data15[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_PINTINV_Data16[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_PINCFG_Data17[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BDMIC6_TESTMODE_Data18[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_CLK1CFG_Data19[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_CLK2CFG_Data20[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_UPMASK0_Data21[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_UPMASK1_Data22[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_UPMASK2_Data23[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_UPMASK3_Data24[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_UPOFFSET_Data25[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_DNMASK0_Data26[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_DNMASK1_Data27[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_DNMASK2_Data28[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_DNMASK3_Data29[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_DNOFFSET_Data30[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_GPIOD0MSK_Data31[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_GPIOD1MSK_Data32[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_GPIOD2MSK_Data33[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_GPIOD3MSK_Data34[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_GPIOD4MSK_Data35[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_GPIOD5MSK_Data36[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_GPIOD6MSK_Data37[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_GPIOD7MSK_Data38[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_GPIODINV_Data39[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_GPIODEN_Data40[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_MBOX0CTL_Data41[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_MBOX1CTL_Data42[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC6_SUSCFG_Data43[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_I2SRRSOFFS_Data44[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_I2SRRCTL_Data45[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_TXACTL_Data46[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_TXBCTL_Data47[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_INTMSK0_Data48[1] =
{
  0x70u
};

static unsigned char gaConfig_A2BDMIC6_INTMSK1_Data49[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_BECCTL_Data50[1] =
{
  0xFFu
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data99[1] =
{
  0x06u
};

static unsigned char gaConfig_A2BMasterNode_DISCVRY_Data100[1] =
{
  0x29u
};

static unsigned char gaConfig_A2BMasterNode_A2BDelay_Data101[1] =
{
  0x32u
};

static unsigned char gaConfig_A2BMasterNode_INTTYPE_Data102[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data103[1] =
{
  0x06u
};

static unsigned char gaConfig_A2BDMIC6_SWCTL_Data51[1] =
{
  0x21u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data104[1] =
{
  0x07u
};

static unsigned char gaConfig_A2BDMIC7_VENDOR_Data0[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_PRODUCT_Data1[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_VERSION_Data2[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data105[1] =
{
  0x07u
};

static unsigned char gaConfig_A2BDMIC7_CONTROL_Data3[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_SWCTL_Data4[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data106[1] =
{
  0x07u
};

static unsigned char gaConfig_A2BDMIC7_BCDNSLOTS_Data5[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_LDNSLOTS_Data6[1] =
{
  0x80u
};

static unsigned char gaConfig_A2BDMIC7_LUPSLOTS_Data7[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC7_I2CCFG_Data8[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_PDMCTL_Data9[1] =
{
  0x15u
};

static unsigned char gaConfig_A2BDMIC7_PDMCTL2_Data10[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_ERRMGMT_Data11[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_GPIODAT_Data12[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_GPIOOEN_Data13[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_GPIOIEN_Data14[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_PINTEN_Data15[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_PINTINV_Data16[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_PINCFG_Data17[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BDMIC7_TESTMODE_Data18[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_CLK1CFG_Data19[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_CLK2CFG_Data20[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_UPMASK0_Data21[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_UPMASK1_Data22[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_UPMASK2_Data23[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_UPMASK3_Data24[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_UPOFFSET_Data25[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_DNMASK0_Data26[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_DNMASK1_Data27[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_DNMASK2_Data28[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_DNMASK3_Data29[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_DNOFFSET_Data30[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_GPIOD0MSK_Data31[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_GPIOD1MSK_Data32[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_GPIOD2MSK_Data33[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_GPIOD3MSK_Data34[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_GPIOD4MSK_Data35[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_GPIOD5MSK_Data36[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_GPIOD6MSK_Data37[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_GPIOD7MSK_Data38[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_GPIODINV_Data39[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_GPIODEN_Data40[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_MBOX0CTL_Data41[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_MBOX1CTL_Data42[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC7_SUSCFG_Data43[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_I2SRRSOFFS_Data44[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_I2SRRCTL_Data45[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_TXACTL_Data46[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_TXBCTL_Data47[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_INTMSK0_Data48[1] =
{
  0x70u
};

static unsigned char gaConfig_A2BDMIC7_INTMSK1_Data49[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_BECCTL_Data50[1] =
{
  0xFFu
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data107[1] =
{
  0x07u
};

static unsigned char gaConfig_A2BMasterNode_DISCVRY_Data108[1] =
{
  0x25u
};

static unsigned char gaConfig_A2BMasterNode_A2BDelay_Data109[1] =
{
  0x32u
};

static unsigned char gaConfig_A2BMasterNode_INTTYPE_Data110[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data111[1] =
{
  0x07u
};

static unsigned char gaConfig_A2BDMIC7_SWCTL_Data51[1] =
{
  0x21u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data112[1] =
{
  0x08u
};

static unsigned char gaConfig_A2BDMIC8_VENDOR_Data0[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_PRODUCT_Data1[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_VERSION_Data2[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data113[1] =
{
  0x08u
};

static unsigned char gaConfig_A2BDMIC8_CONTROL_Data3[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_SWCTL_Data4[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data114[1] =
{
  0x08u
};

static unsigned char gaConfig_A2BDMIC8_BCDNSLOTS_Data5[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_LDNSLOTS_Data6[1] =
{
  0x80u
};

static unsigned char gaConfig_A2BDMIC8_LUPSLOTS_Data7[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC8_I2CCFG_Data8[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_PDMCTL_Data9[1] =
{
  0x15u
};

static unsigned char gaConfig_A2BDMIC8_PDMCTL2_Data10[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_ERRMGMT_Data11[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_GPIODAT_Data12[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_GPIOOEN_Data13[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_GPIOIEN_Data14[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_PINTEN_Data15[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_PINTINV_Data16[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_PINCFG_Data17[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BDMIC8_TESTMODE_Data18[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_CLK1CFG_Data19[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_CLK2CFG_Data20[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_UPMASK0_Data21[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_UPMASK1_Data22[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_UPMASK2_Data23[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_UPMASK3_Data24[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_UPOFFSET_Data25[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_DNMASK0_Data26[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_DNMASK1_Data27[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_DNMASK2_Data28[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_DNMASK3_Data29[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_DNOFFSET_Data30[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_GPIOD0MSK_Data31[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_GPIOD1MSK_Data32[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_GPIOD2MSK_Data33[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_GPIOD3MSK_Data34[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_GPIOD4MSK_Data35[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_GPIOD5MSK_Data36[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_GPIOD6MSK_Data37[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_GPIOD7MSK_Data38[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_GPIODINV_Data39[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_GPIODEN_Data40[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_MBOX0CTL_Data41[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_MBOX1CTL_Data42[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC8_SUSCFG_Data43[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_I2SRRSOFFS_Data44[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_I2SRRCTL_Data45[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_TXACTL_Data46[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_TXBCTL_Data47[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_INTMSK0_Data48[1] =
{
  0x70u
};

static unsigned char gaConfig_A2BDMIC8_INTMSK1_Data49[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_BECCTL_Data50[1] =
{
  0xFFu
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data115[1] =
{
  0x08u
};

static unsigned char gaConfig_A2BMasterNode_DISCVRY_Data116[1] =
{
  0x21u
};

static unsigned char gaConfig_A2BMasterNode_A2BDelay_Data117[1] =
{
  0x32u
};

static unsigned char gaConfig_A2BMasterNode_INTTYPE_Data118[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data119[1] =
{
  0x08u
};

static unsigned char gaConfig_A2BDMIC8_SWCTL_Data51[1] =
{
  0x21u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data120[1] =
{
  0x09u
};

static unsigned char gaConfig_A2BDMIC9_VENDOR_Data0[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_PRODUCT_Data1[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_VERSION_Data2[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data121[1] =
{
  0x09u
};

static unsigned char gaConfig_A2BDMIC9_CONTROL_Data3[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_SWCTL_Data4[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data122[1] =
{
  0x09u
};

static unsigned char gaConfig_A2BDMIC9_BCDNSLOTS_Data5[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_LDNSLOTS_Data6[1] =
{
  0x80u
};

static unsigned char gaConfig_A2BDMIC9_LUPSLOTS_Data7[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC9_I2CCFG_Data8[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_PDMCTL_Data9[1] =
{
  0x15u
};

static unsigned char gaConfig_A2BDMIC9_PDMCTL2_Data10[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_ERRMGMT_Data11[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_GPIODAT_Data12[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_GPIOOEN_Data13[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_GPIOIEN_Data14[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_PINTEN_Data15[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_PINTINV_Data16[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_PINCFG_Data17[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BDMIC9_TESTMODE_Data18[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_CLK1CFG_Data19[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_CLK2CFG_Data20[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_UPMASK0_Data21[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_UPMASK1_Data22[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_UPMASK2_Data23[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_UPMASK3_Data24[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_UPOFFSET_Data25[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_DNMASK0_Data26[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_DNMASK1_Data27[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_DNMASK2_Data28[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_DNMASK3_Data29[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_DNOFFSET_Data30[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_GPIOD0MSK_Data31[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_GPIOD1MSK_Data32[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_GPIOD2MSK_Data33[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_GPIOD3MSK_Data34[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_GPIOD4MSK_Data35[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_GPIOD5MSK_Data36[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_GPIOD6MSK_Data37[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_GPIOD7MSK_Data38[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_GPIODINV_Data39[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_GPIODEN_Data40[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_MBOX0CTL_Data41[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_MBOX1CTL_Data42[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC9_SUSCFG_Data43[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_I2SRRSOFFS_Data44[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_I2SRRCTL_Data45[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_TXACTL_Data46[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_TXBCTL_Data47[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_INTMSK0_Data48[1] =
{
  0x70u
};

static unsigned char gaConfig_A2BDMIC9_INTMSK1_Data49[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_BECCTL_Data50[1] =
{
  0xFFu
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data123[1] =
{
  0x09u
};

static unsigned char gaConfig_A2BMasterNode_DISCVRY_Data124[1] =
{
  0x1Du
};

static unsigned char gaConfig_A2BMasterNode_A2BDelay_Data125[1] =
{
  0x32u
};

static unsigned char gaConfig_A2BMasterNode_INTTYPE_Data126[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data127[1] =
{
  0x09u
};

static unsigned char gaConfig_A2BDMIC9_SWCTL_Data51[1] =
{
  0x21u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data128[1] =
{
  0x0Au
};

static unsigned char gaConfig_A2BDMIC10_VENDOR_Data0[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_PRODUCT_Data1[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_VERSION_Data2[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data129[1] =
{
  0x0Au
};

static unsigned char gaConfig_A2BDMIC10_CONTROL_Data3[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_SWCTL_Data4[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data130[1] =
{
  0x0Au
};

static unsigned char gaConfig_A2BDMIC10_BCDNSLOTS_Data5[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_LDNSLOTS_Data6[1] =
{
  0x80u
};

static unsigned char gaConfig_A2BDMIC10_LUPSLOTS_Data7[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC10_I2CCFG_Data8[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_PDMCTL_Data9[1] =
{
  0x15u
};

static unsigned char gaConfig_A2BDMIC10_PDMCTL2_Data10[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_ERRMGMT_Data11[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_GPIODAT_Data12[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_GPIOOEN_Data13[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_GPIOIEN_Data14[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_PINTEN_Data15[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_PINTINV_Data16[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_PINCFG_Data17[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BDMIC10_TESTMODE_Data18[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_CLK1CFG_Data19[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_CLK2CFG_Data20[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_UPMASK0_Data21[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_UPMASK1_Data22[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_UPMASK2_Data23[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_UPMASK3_Data24[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_UPOFFSET_Data25[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_DNMASK0_Data26[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_DNMASK1_Data27[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_DNMASK2_Data28[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_DNMASK3_Data29[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_DNOFFSET_Data30[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_GPIOD0MSK_Data31[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_GPIOD1MSK_Data32[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_GPIOD2MSK_Data33[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_GPIOD3MSK_Data34[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_GPIOD4MSK_Data35[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_GPIOD5MSK_Data36[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_GPIOD6MSK_Data37[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_GPIOD7MSK_Data38[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_GPIODINV_Data39[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_GPIODEN_Data40[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_MBOX0CTL_Data41[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_MBOX1CTL_Data42[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC10_SUSCFG_Data43[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_I2SRRSOFFS_Data44[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_I2SRRCTL_Data45[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_TXACTL_Data46[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_TXBCTL_Data47[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_INTMSK0_Data48[1] =
{
  0x70u
};

static unsigned char gaConfig_A2BDMIC10_INTMSK1_Data49[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_BECCTL_Data50[1] =
{
  0xFFu
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data131[1] =
{
  0x0Au
};

static unsigned char gaConfig_A2BMasterNode_DISCVRY_Data132[1] =
{
  0x19u
};

static unsigned char gaConfig_A2BMasterNode_A2BDelay_Data133[1] =
{
  0x32u
};

static unsigned char gaConfig_A2BMasterNode_INTTYPE_Data134[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data135[1] =
{
  0x0Au
};

static unsigned char gaConfig_A2BDMIC10_SWCTL_Data51[1] =
{
  0x21u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data136[1] =
{
  0x0Bu
};

static unsigned char gaConfig_A2BDMIC11_VENDOR_Data0[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_PRODUCT_Data1[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_VERSION_Data2[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data137[1] =
{
  0x0Bu
};

static unsigned char gaConfig_A2BDMIC11_BCDNSLOTS_Data3[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_LDNSLOTS_Data4[1] =
{
  0x80u
};

static unsigned char gaConfig_A2BDMIC11_LUPSLOTS_Data5[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC11_I2CCFG_Data6[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_PDMCTL_Data7[1] =
{
  0x15u
};

static unsigned char gaConfig_A2BDMIC11_PDMCTL2_Data8[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_ERRMGMT_Data9[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_GPIODAT_Data10[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_GPIOOEN_Data11[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_GPIOIEN_Data12[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_PINTEN_Data13[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_PINTINV_Data14[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_PINCFG_Data15[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BDMIC11_TESTMODE_Data16[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_CLK1CFG_Data17[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_CLK2CFG_Data18[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_UPMASK0_Data19[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_UPMASK1_Data20[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_UPMASK2_Data21[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_UPMASK3_Data22[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_UPOFFSET_Data23[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_DNMASK0_Data24[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_DNMASK1_Data25[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_DNMASK2_Data26[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_DNMASK3_Data27[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_DNOFFSET_Data28[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_GPIOD0MSK_Data29[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_GPIOD1MSK_Data30[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_GPIOD2MSK_Data31[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_GPIOD3MSK_Data32[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_GPIOD4MSK_Data33[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_GPIOD5MSK_Data34[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_GPIOD6MSK_Data35[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_GPIOD7MSK_Data36[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_GPIODINV_Data37[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_GPIODEN_Data38[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_MBOX0CTL_Data39[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_MBOX1CTL_Data40[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC11_SUSCFG_Data41[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_I2SRRSOFFS_Data42[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_I2SRRCTL_Data43[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_TXACTL_Data44[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_TXBCTL_Data45[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_INTMSK0_Data46[1] =
{
  0x70u
};

static unsigned char gaConfig_A2BDMIC11_INTMSK1_Data47[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC11_BECCTL_Data48[1] =
{
  0xFFu
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data138[1] =
{
  0x0Au
};

static unsigned char gaConfig_A2BDMIC10_DNSLOTS_Data52[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC10_UPSLOTS_Data53[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data139[1] =
{
  0x09u
};

static unsigned char gaConfig_A2BDMIC9_DNSLOTS_Data52[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC9_UPSLOTS_Data53[1] =
{
  0x04u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data140[1] =
{
  0x08u
};

static unsigned char gaConfig_A2BDMIC8_DNSLOTS_Data52[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC8_UPSLOTS_Data53[1] =
{
  0x06u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data141[1] =
{
  0x07u
};

static unsigned char gaConfig_A2BDMIC7_DNSLOTS_Data52[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC7_UPSLOTS_Data53[1] =
{
  0x08u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data142[1] =
{
  0x06u
};

static unsigned char gaConfig_A2BDMIC6_DNSLOTS_Data52[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC6_UPSLOTS_Data53[1] =
{
  0x0Au
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data143[1] =
{
  0x05u
};

static unsigned char gaConfig_A2BDMIC5_DNSLOTS_Data52[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC5_UPSLOTS_Data53[1] =
{
  0x0Cu
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data144[1] =
{
  0x04u
};

static unsigned char gaConfig_A2BDMIC4_DNSLOTS_Data52[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC4_UPSLOTS_Data53[1] =
{
  0x0Eu
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data145[1] =
{
  0x03u
};

static unsigned char gaConfig_A2BDMIC3_DNSLOTS_Data52[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC3_UPSLOTS_Data53[1] =
{
  0x10u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data146[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC2_DNSLOTS_Data52[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC2_UPSLOTS_Data53[1] =
{
  0x12u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data147[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BDMIC1_DNSLOTS_Data52[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC1_UPSLOTS_Data53[1] =
{
  0x14u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data148[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_DNSLOTS_Data52[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_UPSLOTS_Data53[1] =
{
  0x16u
};

static unsigned char gaConfig_A2BMasterNode_DNSLOTS_Data149[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_UPSLOTS_Data150[1] =
{
  0x18u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data151[1] =
{
  0x0Au
};

static unsigned char gaConfig_A2BDMIC10_SWCTL_Data54[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data152[1] =
{
  0x09u
};

static unsigned char gaConfig_A2BDMIC9_SWCTL_Data54[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data153[1] =
{
  0x08u
};

static unsigned char gaConfig_A2BDMIC8_SWCTL_Data54[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data154[1] =
{
  0x07u
};

static unsigned char gaConfig_A2BDMIC7_SWCTL_Data54[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data155[1] =
{
  0x06u
};

static unsigned char gaConfig_A2BDMIC6_SWCTL_Data54[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data156[1] =
{
  0x05u
};

static unsigned char gaConfig_A2BDMIC5_SWCTL_Data54[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data157[1] =
{
  0x04u
};

static unsigned char gaConfig_A2BDMIC4_SWCTL_Data54[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data158[1] =
{
  0x03u
};

static unsigned char gaConfig_A2BDMIC3_SWCTL_Data54[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data159[1] =
{
  0x02u
};

static unsigned char gaConfig_A2BDMIC2_SWCTL_Data54[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data160[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BDMIC1_SWCTL_Data54[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data161[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BDMIC0_SWCTL_Data54[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_SWCTL_Data162[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_PLLCTL_Data163[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data164[1] =
{
  0x80u
};

static unsigned char gaConfig_A2BMasterNode_PLLCTL_Data165[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data166[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_SLOTFMT_Data167[1] =
{
  0x42u
};

static unsigned char gaConfig_A2BMasterNode_DATCTL_Data168[1] =
{
  0x03u
};

static unsigned char gaConfig_A2BMasterNode_I2SRRATE_Data169[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_CONTROL_Data170[1] =
{
  0x81u
};

static unsigned char gaConfig_A2BMasterNode_A2BDelay_Data171[1] =
{
  0x01u
};

static unsigned char gaConfig_A2BMasterNode_NODEADR_Data172[1] =
{
  0x0Bu
};

static unsigned char gaConfig_A2BDMIC11_SWCTL_Data49[1] =
{
  0x00u
};

static unsigned char gaConfig_A2BMasterNode_CONTROL_Data173[1] =
{
  0x82u
};

Ad2428Reg ad24280_cfg[AD24280_CFG_LEN] =
{

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000012u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_CONTROL_Data0[0] }, /* CONTROL */
  {0x00u, DELAY,  0x01u,  0x00000000u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_A2BDelay_Data1[0] },  /* A2B_Delay */
  {0x68u, READ, 0x01u,  0x00000017u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_INTTYPE_Data2[0] }, /* INTTYPE */
  {0x68u, WRITE,  0x01u,  0x0000001Bu,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_INTMSK0_Data3[0] }, /* INTMSK0 */
  {0x68u, WRITE,  0x01u,  0x0000001Cu,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_INTMSK1_Data4[0] }, /* INTMSK1 */
  {0x68u, WRITE,  0x01u,  0x0000001Du,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_INTMSK2_Data5[0] }, /* INTMSK2 */
  {0x68u, WRITE,  0x01u,  0x0000001Eu,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_BECCTL_Data6[0] },  /* BECCTL */
  {0x68u, WRITE,  0x01u,  0x0000001Au,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_INTPND2_Data7[0] }, /* INTPND2 */
  {0x68u, WRITE,  0x01u,  0x0000000Fu,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_RESPCYCS_Data8[0] },  /* RESPCYCS */
  {0x68u, WRITE,  0x01u,  0x00000012u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_CONTROL_Data9[0] }, /* CONTROL */
  {0x00u, DELAY,  0x01u,  0x00000000u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_A2BDelay_Data10[0] }, /* A2B_Delay */
  {0x68u, WRITE,  0x01u,  0x00000041u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_I2SGCFG_Data11[0] },  /* I2SGCFG */
  {0x68u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_SWCTL_Data12[0] },  /* SWCTL */
  {0x68u, WRITE,  0x01u,  0x0000003Fu,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_I2CCFG_Data13[0] }, /* I2CCFG */
  {0x68u, WRITE,  0x01u,  0x00000044u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_I2STXOFFSET_Data14[0] },  /* I2STXOFFSET */
  {0x68u, WRITE,  0x01u,  0x00000045u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_I2SRXOFFSET_Data15[0] },  /* I2SRXOFFSET */
  {0x68u, WRITE,  0x01u,  0x00000042u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_I2SCFG_Data16[0] }, /* I2SCFG */
  {0x68u, WRITE,  0x01u,  0x00000047u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_PDMCTL_Data17[0] }, /* PDMCTL */
  {0x68u, WRITE,  0x01u,  0x0000005Du,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_PDMCTL2_Data18[0] },  /* PDMCTL2 */
  {0x68u, WRITE,  0x01u,  0x00000048u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_ERRMGMT_Data19[0] },  /* ERRMGMT */
  {0x68u, WRITE,  0x01u,  0x0000004Au,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_GPIODAT_Data20[0] },  /* GPIODAT */
  {0x68u, WRITE,  0x01u,  0x0000004Du,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_GPIOOEN_Data21[0] },  /* GPIOOEN */
  {0x68u, WRITE,  0x01u,  0x0000004Eu,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_GPIOIEN_Data22[0] },  /* GPIOIEN */
  {0x68u, WRITE,  0x01u,  0x00000050u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_PINTEN_Data23[0] }, /* PINTEN */
  {0x68u, WRITE,  0x01u,  0x00000051u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_PINTINV_Data24[0] },  /* PINTINV */
  {0x68u, WRITE,  0x01u,  0x00000052u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_PINCFG_Data25[0] }, /* PINCFG */
  {0x68u, WRITE,  0x01u,  0x00000020u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_TESTMODE_Data26[0] }, /* TESTMODE */
  {0x68u, WRITE,  0x01u,  0x00000059u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_CLK1CFG_Data27[0] },  /* CLK1CFG */
  {0x68u, WRITE,  0x01u,  0x0000005Au,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_CLK2CFG_Data28[0] },  /* CLK2CFG */
  {0x68u, WRITE,  0x01u,  0x00000081u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_GPIOD0MSK_Data29[0] },  /* GPIOD0MSK */
  {0x68u, WRITE,  0x01u,  0x00000082u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_GPIOD1MSK_Data30[0] },  /* GPIOD1MSK */
  {0x68u, WRITE,  0x01u,  0x00000083u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_GPIOD2MSK_Data31[0] },  /* GPIOD2MSK */
  {0x68u, WRITE,  0x01u,  0x00000084u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_GPIOD3MSK_Data32[0] },  /* GPIOD3MSK */
  {0x68u, WRITE,  0x01u,  0x00000085u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_GPIOD4MSK_Data33[0] },  /* GPIOD4MSK */
  {0x68u, WRITE,  0x01u,  0x00000086u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_GPIOD5MSK_Data34[0] },  /* GPIOD5MSK */
  {0x68u, WRITE,  0x01u,  0x00000087u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_GPIOD6MSK_Data35[0] },  /* GPIOD6MSK */
  {0x68u, WRITE,  0x01u,  0x00000088u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_GPIOD7MSK_Data36[0] },  /* GPIOD7MSK */
  {0x68u, WRITE,  0x01u,  0x0000008Au,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_GPIODINV_Data37[0] }, /* GPIODINV */
  {0x68u, WRITE,  0x01u,  0x00000080u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_GPIODEN_Data38[0] },  /* GPIODEN */
  {0x68u, WRITE,  0x01u,  0x00000057u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_I2SRRCTL_Data39[0] }, /* I2SRRCTL */
  {0x68u, WRITE,  0x01u,  0x0000002Eu,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_TXACTL_Data40[0] }, /* TXACTL */
  {0x68u, WRITE,  0x01u,  0x00000030u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_TXBCTL_Data41[0] }, /* TXBCTL */
  {0x68u, WRITE,  0x01u,  0x0000001Eu,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_BECCTL_Data42[0] }, /* BECCTL */
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data43[0] },  /* NODEADR */
  {0x68u, WRITE,  0x01u,  0x00000013u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_DISCVRY_Data44[0] },  /* DISCVRY */
  {0x00u, DELAY,  0x01u,  0x00000000u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_A2BDelay_Data45[0] }, /* A2B_Delay */
  {0x68u, READ, 0x01u,  0x00000017u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_INTTYPE_Data46[0] },  /* INTTYPE */
  {0x68u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_SWCTL_Data47[0] },  /* SWCTL */
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data48[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC0 --*/
  {0x69u, READ, 0x01u,  0x00000002u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_VENDOR_Data0[0] }, /* VENDOR */
  {0x69u, READ, 0x01u,  0x00000003u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_PRODUCT_Data1[0] },  /* PRODUCT */
  {0x69u, READ, 0x01u,  0x00000004u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_VERSION_Data2[0] },  /* VERSION */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data49[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC0 --*/
  {0x69u, WRITE,  0x01u,  0x00000012u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_CONTROL_Data3[0] },  /* CONTROL */
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_SWCTL_Data4[0] },  /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data50[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC0 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_BCDNSLOTS_Data5[0] },  /* BCDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_LDNSLOTS_Data6[0] }, /* LDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_LUPSLOTS_Data7[0] }, /* LUPSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000003Fu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_I2CCFG_Data8[0] }, /* I2CCFG */
  {0x69u, WRITE,  0x01u,  0x00000047u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_PDMCTL_Data9[0] }, /* PDMCTL */
  {0x69u, WRITE,  0x01u,  0x0000005Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_PDMCTL2_Data10[0] }, /* PDMCTL2 */
  {0x69u, WRITE,  0x01u,  0x00000048u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_ERRMGMT_Data11[0] }, /* ERRMGMT */
  {0x69u, WRITE,  0x01u,  0x0000004Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_GPIODAT_Data12[0] }, /* GPIODAT */
  {0x69u, WRITE,  0x01u,  0x0000004Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_GPIOOEN_Data13[0] }, /* GPIOOEN */
  {0x69u, WRITE,  0x01u,  0x0000004Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_GPIOIEN_Data14[0] }, /* GPIOIEN */
  {0x69u, WRITE,  0x01u,  0x00000050u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_PINTEN_Data15[0] },  /* PINTEN */
  {0x69u, WRITE,  0x01u,  0x00000051u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_PINTINV_Data16[0] }, /* PINTINV */
  {0x69u, WRITE,  0x01u,  0x00000052u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_PINCFG_Data17[0] },  /* PINCFG */
  {0x69u, WRITE,  0x01u,  0x00000020u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_TESTMODE_Data18[0] },  /* TESTMODE */
  {0x69u, WRITE,  0x01u,  0x00000059u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_CLK1CFG_Data19[0] }, /* CLK1CFG */
  {0x69u, WRITE,  0x01u,  0x0000005Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_CLK2CFG_Data20[0] }, /* CLK2CFG */
  {0x69u, WRITE,  0x01u,  0x00000060u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_UPMASK0_Data21[0] }, /* UPMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000061u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_UPMASK1_Data22[0] }, /* UPMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000062u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_UPMASK2_Data23[0] }, /* UPMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000063u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_UPMASK3_Data24[0] }, /* UPMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000064u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_UPOFFSET_Data25[0] },  /* UPOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000065u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_DNMASK0_Data26[0] }, /* DNMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000066u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_DNMASK1_Data27[0] }, /* DNMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000067u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_DNMASK2_Data28[0] }, /* DNMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000068u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_DNMASK3_Data29[0] }, /* DNMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000069u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_DNOFFSET_Data30[0] },  /* DNOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000081u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_GPIOD0MSK_Data31[0] }, /* GPIOD0MSK */
  {0x69u, WRITE,  0x01u,  0x00000082u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_GPIOD1MSK_Data32[0] }, /* GPIOD1MSK */
  {0x69u, WRITE,  0x01u,  0x00000083u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_GPIOD2MSK_Data33[0] }, /* GPIOD2MSK */
  {0x69u, WRITE,  0x01u,  0x00000084u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_GPIOD3MSK_Data34[0] }, /* GPIOD3MSK */
  {0x69u, WRITE,  0x01u,  0x00000085u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_GPIOD4MSK_Data35[0] }, /* GPIOD4MSK */
  {0x69u, WRITE,  0x01u,  0x00000086u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_GPIOD5MSK_Data36[0] }, /* GPIOD5MSK */
  {0x69u, WRITE,  0x01u,  0x00000087u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_GPIOD6MSK_Data37[0] }, /* GPIOD6MSK */
  {0x69u, WRITE,  0x01u,  0x00000088u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_GPIOD7MSK_Data38[0] }, /* GPIOD7MSK */
  {0x69u, WRITE,  0x01u,  0x0000008Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_GPIODINV_Data39[0] },  /* GPIODINV */
  {0x69u, WRITE,  0x01u,  0x00000080u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_GPIODEN_Data40[0] }, /* GPIODEN */
  {0x69u, WRITE,  0x01u,  0x00000090u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_MBOX0CTL_Data41[0] },  /* MBOX0CTL */
  {0x69u, WRITE,  0x01u,  0x00000096u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_MBOX1CTL_Data42[0] },  /* MBOX1CTL */
  {0x69u, WRITE,  0x01u,  0x0000005Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_SUSCFG_Data43[0] },  /* SUSCFG */
  {0x69u, WRITE,  0x01u,  0x00000058u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_I2SRRSOFFS_Data44[0] },  /* I2SRRSOFFS */
  {0x69u, WRITE,  0x01u,  0x00000057u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_I2SRRCTL_Data45[0] },  /* I2SRRCTL */
  {0x69u, WRITE,  0x01u,  0x0000002Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_TXACTL_Data46[0] },  /* TXACTL */
  {0x69u, WRITE,  0x01u,  0x00000030u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_TXBCTL_Data47[0] },  /* TXBCTL */
  {0x69u, WRITE,  0x01u,  0x0000001Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_INTMSK0_Data48[0] }, /* INTMSK0 */
  {0x69u, WRITE,  0x01u,  0x0000001Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_INTMSK1_Data49[0] }, /* INTMSK1 */
  {0x69u, WRITE,  0x01u,  0x0000001Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_BECCTL_Data50[0] },  /* BECCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data51[0] },  /* NODEADR */
  {0x68u, WRITE,  0x01u,  0x00000013u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_DISCVRY_Data52[0] },  /* DISCVRY */
  {0x00u, DELAY,  0x01u,  0x00000000u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_A2BDelay_Data53[0] }, /* A2B_Delay */
  {0x68u, READ, 0x01u,  0x00000017u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_INTTYPE_Data54[0] },  /* INTTYPE */
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data55[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC0 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_SWCTL_Data51[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data56[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC1 --*/
  {0x69u, READ, 0x01u,  0x00000002u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_VENDOR_Data0[0] }, /* VENDOR */
  {0x69u, READ, 0x01u,  0x00000003u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_PRODUCT_Data1[0] },  /* PRODUCT */
  {0x69u, READ, 0x01u,  0x00000004u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_VERSION_Data2[0] },  /* VERSION */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data57[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC1 --*/
  {0x69u, WRITE,  0x01u,  0x00000012u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_CONTROL_Data3[0] },  /* CONTROL */
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_SWCTL_Data4[0] },  /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data58[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC1 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_BCDNSLOTS_Data5[0] },  /* BCDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_LDNSLOTS_Data6[0] }, /* LDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_LUPSLOTS_Data7[0] }, /* LUPSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000003Fu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_I2CCFG_Data8[0] }, /* I2CCFG */
  {0x69u, WRITE,  0x01u,  0x00000047u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_PDMCTL_Data9[0] }, /* PDMCTL */
  {0x69u, WRITE,  0x01u,  0x0000005Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_PDMCTL2_Data10[0] }, /* PDMCTL2 */
  {0x69u, WRITE,  0x01u,  0x00000048u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_ERRMGMT_Data11[0] }, /* ERRMGMT */
  {0x69u, WRITE,  0x01u,  0x0000004Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_GPIODAT_Data12[0] }, /* GPIODAT */
  {0x69u, WRITE,  0x01u,  0x0000004Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_GPIOOEN_Data13[0] }, /* GPIOOEN */
  {0x69u, WRITE,  0x01u,  0x0000004Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_GPIOIEN_Data14[0] }, /* GPIOIEN */
  {0x69u, WRITE,  0x01u,  0x00000050u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_PINTEN_Data15[0] },  /* PINTEN */
  {0x69u, WRITE,  0x01u,  0x00000051u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_PINTINV_Data16[0] }, /* PINTINV */
  {0x69u, WRITE,  0x01u,  0x00000052u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_PINCFG_Data17[0] },  /* PINCFG */
  {0x69u, WRITE,  0x01u,  0x00000020u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_TESTMODE_Data18[0] },  /* TESTMODE */
  {0x69u, WRITE,  0x01u,  0x00000059u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_CLK1CFG_Data19[0] }, /* CLK1CFG */
  {0x69u, WRITE,  0x01u,  0x0000005Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_CLK2CFG_Data20[0] }, /* CLK2CFG */
  {0x69u, WRITE,  0x01u,  0x00000060u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_UPMASK0_Data21[0] }, /* UPMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000061u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_UPMASK1_Data22[0] }, /* UPMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000062u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_UPMASK2_Data23[0] }, /* UPMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000063u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_UPMASK3_Data24[0] }, /* UPMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000064u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_UPOFFSET_Data25[0] },  /* UPOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000065u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_DNMASK0_Data26[0] }, /* DNMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000066u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_DNMASK1_Data27[0] }, /* DNMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000067u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_DNMASK2_Data28[0] }, /* DNMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000068u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_DNMASK3_Data29[0] }, /* DNMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000069u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_DNOFFSET_Data30[0] },  /* DNOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000081u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_GPIOD0MSK_Data31[0] }, /* GPIOD0MSK */
  {0x69u, WRITE,  0x01u,  0x00000082u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_GPIOD1MSK_Data32[0] }, /* GPIOD1MSK */
  {0x69u, WRITE,  0x01u,  0x00000083u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_GPIOD2MSK_Data33[0] }, /* GPIOD2MSK */
  {0x69u, WRITE,  0x01u,  0x00000084u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_GPIOD3MSK_Data34[0] }, /* GPIOD3MSK */
  {0x69u, WRITE,  0x01u,  0x00000085u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_GPIOD4MSK_Data35[0] }, /* GPIOD4MSK */
  {0x69u, WRITE,  0x01u,  0x00000086u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_GPIOD5MSK_Data36[0] }, /* GPIOD5MSK */
  {0x69u, WRITE,  0x01u,  0x00000087u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_GPIOD6MSK_Data37[0] }, /* GPIOD6MSK */
  {0x69u, WRITE,  0x01u,  0x00000088u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_GPIOD7MSK_Data38[0] }, /* GPIOD7MSK */
  {0x69u, WRITE,  0x01u,  0x0000008Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_GPIODINV_Data39[0] },  /* GPIODINV */
  {0x69u, WRITE,  0x01u,  0x00000080u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_GPIODEN_Data40[0] }, /* GPIODEN */
  {0x69u, WRITE,  0x01u,  0x00000090u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_MBOX0CTL_Data41[0] },  /* MBOX0CTL */
  {0x69u, WRITE,  0x01u,  0x00000096u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_MBOX1CTL_Data42[0] },  /* MBOX1CTL */
  {0x69u, WRITE,  0x01u,  0x0000005Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_SUSCFG_Data43[0] },  /* SUSCFG */
  {0x69u, WRITE,  0x01u,  0x00000058u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_I2SRRSOFFS_Data44[0] },  /* I2SRRSOFFS */
  {0x69u, WRITE,  0x01u,  0x00000057u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_I2SRRCTL_Data45[0] },  /* I2SRRCTL */
  {0x69u, WRITE,  0x01u,  0x0000002Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_TXACTL_Data46[0] },  /* TXACTL */
  {0x69u, WRITE,  0x01u,  0x00000030u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_TXBCTL_Data47[0] },  /* TXBCTL */
  {0x69u, WRITE,  0x01u,  0x0000001Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_INTMSK0_Data48[0] }, /* INTMSK0 */
  {0x69u, WRITE,  0x01u,  0x0000001Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_INTMSK1_Data49[0] }, /* INTMSK1 */
  {0x69u, WRITE,  0x01u,  0x0000001Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_BECCTL_Data50[0] },  /* BECCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data59[0] },  /* NODEADR */
  {0x68u, WRITE,  0x01u,  0x00000013u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_DISCVRY_Data60[0] },  /* DISCVRY */
  {0x00u, DELAY,  0x01u,  0x00000000u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_A2BDelay_Data61[0] }, /* A2B_Delay */
  {0x68u, READ, 0x01u,  0x00000017u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_INTTYPE_Data62[0] },  /* INTTYPE */
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data63[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC1 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_SWCTL_Data51[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data64[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC2 --*/
  {0x69u, READ, 0x01u,  0x00000002u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_VENDOR_Data0[0] }, /* VENDOR */
  {0x69u, READ, 0x01u,  0x00000003u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_PRODUCT_Data1[0] },  /* PRODUCT */
  {0x69u, READ, 0x01u,  0x00000004u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_VERSION_Data2[0] },  /* VERSION */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data65[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC2 --*/
  {0x69u, WRITE,  0x01u,  0x00000012u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_CONTROL_Data3[0] },  /* CONTROL */
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_SWCTL_Data4[0] },  /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data66[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC2 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_BCDNSLOTS_Data5[0] },  /* BCDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_LDNSLOTS_Data6[0] }, /* LDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_LUPSLOTS_Data7[0] }, /* LUPSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000003Fu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_I2CCFG_Data8[0] }, /* I2CCFG */
  {0x69u, WRITE,  0x01u,  0x00000047u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_PDMCTL_Data9[0] }, /* PDMCTL */
  {0x69u, WRITE,  0x01u,  0x0000005Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_PDMCTL2_Data10[0] }, /* PDMCTL2 */
  {0x69u, WRITE,  0x01u,  0x00000048u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_ERRMGMT_Data11[0] }, /* ERRMGMT */
  {0x69u, WRITE,  0x01u,  0x0000004Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_GPIODAT_Data12[0] }, /* GPIODAT */
  {0x69u, WRITE,  0x01u,  0x0000004Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_GPIOOEN_Data13[0] }, /* GPIOOEN */
  {0x69u, WRITE,  0x01u,  0x0000004Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_GPIOIEN_Data14[0] }, /* GPIOIEN */
  {0x69u, WRITE,  0x01u,  0x00000050u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_PINTEN_Data15[0] },  /* PINTEN */
  {0x69u, WRITE,  0x01u,  0x00000051u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_PINTINV_Data16[0] }, /* PINTINV */
  {0x69u, WRITE,  0x01u,  0x00000052u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_PINCFG_Data17[0] },  /* PINCFG */
  {0x69u, WRITE,  0x01u,  0x00000020u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_TESTMODE_Data18[0] },  /* TESTMODE */
  {0x69u, WRITE,  0x01u,  0x00000059u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_CLK1CFG_Data19[0] }, /* CLK1CFG */
  {0x69u, WRITE,  0x01u,  0x0000005Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_CLK2CFG_Data20[0] }, /* CLK2CFG */
  {0x69u, WRITE,  0x01u,  0x00000060u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_UPMASK0_Data21[0] }, /* UPMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000061u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_UPMASK1_Data22[0] }, /* UPMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000062u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_UPMASK2_Data23[0] }, /* UPMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000063u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_UPMASK3_Data24[0] }, /* UPMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000064u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_UPOFFSET_Data25[0] },  /* UPOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000065u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_DNMASK0_Data26[0] }, /* DNMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000066u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_DNMASK1_Data27[0] }, /* DNMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000067u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_DNMASK2_Data28[0] }, /* DNMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000068u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_DNMASK3_Data29[0] }, /* DNMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000069u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_DNOFFSET_Data30[0] },  /* DNOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000081u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_GPIOD0MSK_Data31[0] }, /* GPIOD0MSK */
  {0x69u, WRITE,  0x01u,  0x00000082u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_GPIOD1MSK_Data32[0] }, /* GPIOD1MSK */
  {0x69u, WRITE,  0x01u,  0x00000083u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_GPIOD2MSK_Data33[0] }, /* GPIOD2MSK */
  {0x69u, WRITE,  0x01u,  0x00000084u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_GPIOD3MSK_Data34[0] }, /* GPIOD3MSK */
  {0x69u, WRITE,  0x01u,  0x00000085u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_GPIOD4MSK_Data35[0] }, /* GPIOD4MSK */
  {0x69u, WRITE,  0x01u,  0x00000086u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_GPIOD5MSK_Data36[0] }, /* GPIOD5MSK */
  {0x69u, WRITE,  0x01u,  0x00000087u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_GPIOD6MSK_Data37[0] }, /* GPIOD6MSK */
  {0x69u, WRITE,  0x01u,  0x00000088u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_GPIOD7MSK_Data38[0] }, /* GPIOD7MSK */
  {0x69u, WRITE,  0x01u,  0x0000008Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_GPIODINV_Data39[0] },  /* GPIODINV */
  {0x69u, WRITE,  0x01u,  0x00000080u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_GPIODEN_Data40[0] }, /* GPIODEN */
  {0x69u, WRITE,  0x01u,  0x00000090u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_MBOX0CTL_Data41[0] },  /* MBOX0CTL */
  {0x69u, WRITE,  0x01u,  0x00000096u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_MBOX1CTL_Data42[0] },  /* MBOX1CTL */
  {0x69u, WRITE,  0x01u,  0x0000005Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_SUSCFG_Data43[0] },  /* SUSCFG */
  {0x69u, WRITE,  0x01u,  0x00000058u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_I2SRRSOFFS_Data44[0] },  /* I2SRRSOFFS */
  {0x69u, WRITE,  0x01u,  0x00000057u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_I2SRRCTL_Data45[0] },  /* I2SRRCTL */
  {0x69u, WRITE,  0x01u,  0x0000002Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_TXACTL_Data46[0] },  /* TXACTL */
  {0x69u, WRITE,  0x01u,  0x00000030u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_TXBCTL_Data47[0] },  /* TXBCTL */
  {0x69u, WRITE,  0x01u,  0x0000001Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_INTMSK0_Data48[0] }, /* INTMSK0 */
  {0x69u, WRITE,  0x01u,  0x0000001Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_INTMSK1_Data49[0] }, /* INTMSK1 */
  {0x69u, WRITE,  0x01u,  0x0000001Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_BECCTL_Data50[0] },  /* BECCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data67[0] },  /* NODEADR */
  {0x68u, WRITE,  0x01u,  0x00000013u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_DISCVRY_Data68[0] },  /* DISCVRY */
  {0x00u, DELAY,  0x01u,  0x00000000u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_A2BDelay_Data69[0] }, /* A2B_Delay */
  {0x68u, READ, 0x01u,  0x00000017u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_INTTYPE_Data70[0] },  /* INTTYPE */
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data71[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC2 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_SWCTL_Data51[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data72[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC3 --*/
  {0x69u, READ, 0x01u,  0x00000002u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_VENDOR_Data0[0] }, /* VENDOR */
  {0x69u, READ, 0x01u,  0x00000003u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_PRODUCT_Data1[0] },  /* PRODUCT */
  {0x69u, READ, 0x01u,  0x00000004u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_VERSION_Data2[0] },  /* VERSION */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data73[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC3 --*/
  {0x69u, WRITE,  0x01u,  0x00000012u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_CONTROL_Data3[0] },  /* CONTROL */
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_SWCTL_Data4[0] },  /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data74[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC3 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_BCDNSLOTS_Data5[0] },  /* BCDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_LDNSLOTS_Data6[0] }, /* LDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_LUPSLOTS_Data7[0] }, /* LUPSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000003Fu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_I2CCFG_Data8[0] }, /* I2CCFG */
  {0x69u, WRITE,  0x01u,  0x00000047u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_PDMCTL_Data9[0] }, /* PDMCTL */
  {0x69u, WRITE,  0x01u,  0x0000005Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_PDMCTL2_Data10[0] }, /* PDMCTL2 */
  {0x69u, WRITE,  0x01u,  0x00000048u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_ERRMGMT_Data11[0] }, /* ERRMGMT */
  {0x69u, WRITE,  0x01u,  0x0000004Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_GPIODAT_Data12[0] }, /* GPIODAT */
  {0x69u, WRITE,  0x01u,  0x0000004Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_GPIOOEN_Data13[0] }, /* GPIOOEN */
  {0x69u, WRITE,  0x01u,  0x0000004Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_GPIOIEN_Data14[0] }, /* GPIOIEN */
  {0x69u, WRITE,  0x01u,  0x00000050u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_PINTEN_Data15[0] },  /* PINTEN */
  {0x69u, WRITE,  0x01u,  0x00000051u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_PINTINV_Data16[0] }, /* PINTINV */
  {0x69u, WRITE,  0x01u,  0x00000052u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_PINCFG_Data17[0] },  /* PINCFG */
  {0x69u, WRITE,  0x01u,  0x00000020u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_TESTMODE_Data18[0] },  /* TESTMODE */
  {0x69u, WRITE,  0x01u,  0x00000059u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_CLK1CFG_Data19[0] }, /* CLK1CFG */
  {0x69u, WRITE,  0x01u,  0x0000005Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_CLK2CFG_Data20[0] }, /* CLK2CFG */
  {0x69u, WRITE,  0x01u,  0x00000060u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_UPMASK0_Data21[0] }, /* UPMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000061u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_UPMASK1_Data22[0] }, /* UPMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000062u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_UPMASK2_Data23[0] }, /* UPMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000063u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_UPMASK3_Data24[0] }, /* UPMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000064u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_UPOFFSET_Data25[0] },  /* UPOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000065u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_DNMASK0_Data26[0] }, /* DNMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000066u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_DNMASK1_Data27[0] }, /* DNMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000067u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_DNMASK2_Data28[0] }, /* DNMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000068u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_DNMASK3_Data29[0] }, /* DNMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000069u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_DNOFFSET_Data30[0] },  /* DNOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000081u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_GPIOD0MSK_Data31[0] }, /* GPIOD0MSK */
  {0x69u, WRITE,  0x01u,  0x00000082u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_GPIOD1MSK_Data32[0] }, /* GPIOD1MSK */
  {0x69u, WRITE,  0x01u,  0x00000083u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_GPIOD2MSK_Data33[0] }, /* GPIOD2MSK */
  {0x69u, WRITE,  0x01u,  0x00000084u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_GPIOD3MSK_Data34[0] }, /* GPIOD3MSK */
  {0x69u, WRITE,  0x01u,  0x00000085u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_GPIOD4MSK_Data35[0] }, /* GPIOD4MSK */
  {0x69u, WRITE,  0x01u,  0x00000086u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_GPIOD5MSK_Data36[0] }, /* GPIOD5MSK */
  {0x69u, WRITE,  0x01u,  0x00000087u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_GPIOD6MSK_Data37[0] }, /* GPIOD6MSK */
  {0x69u, WRITE,  0x01u,  0x00000088u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_GPIOD7MSK_Data38[0] }, /* GPIOD7MSK */
  {0x69u, WRITE,  0x01u,  0x0000008Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_GPIODINV_Data39[0] },  /* GPIODINV */
  {0x69u, WRITE,  0x01u,  0x00000080u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_GPIODEN_Data40[0] }, /* GPIODEN */
  {0x69u, WRITE,  0x01u,  0x00000090u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_MBOX0CTL_Data41[0] },  /* MBOX0CTL */
  {0x69u, WRITE,  0x01u,  0x00000096u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_MBOX1CTL_Data42[0] },  /* MBOX1CTL */
  {0x69u, WRITE,  0x01u,  0x0000005Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_SUSCFG_Data43[0] },  /* SUSCFG */
  {0x69u, WRITE,  0x01u,  0x00000058u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_I2SRRSOFFS_Data44[0] },  /* I2SRRSOFFS */
  {0x69u, WRITE,  0x01u,  0x00000057u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_I2SRRCTL_Data45[0] },  /* I2SRRCTL */
  {0x69u, WRITE,  0x01u,  0x0000002Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_TXACTL_Data46[0] },  /* TXACTL */
  {0x69u, WRITE,  0x01u,  0x00000030u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_TXBCTL_Data47[0] },  /* TXBCTL */
  {0x69u, WRITE,  0x01u,  0x0000001Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_INTMSK0_Data48[0] }, /* INTMSK0 */
  {0x69u, WRITE,  0x01u,  0x0000001Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_INTMSK1_Data49[0] }, /* INTMSK1 */
  {0x69u, WRITE,  0x01u,  0x0000001Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_BECCTL_Data50[0] },  /* BECCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data75[0] },  /* NODEADR */
  {0x68u, WRITE,  0x01u,  0x00000013u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_DISCVRY_Data76[0] },  /* DISCVRY */
  {0x00u, DELAY,  0x01u,  0x00000000u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_A2BDelay_Data77[0] }, /* A2B_Delay */
  {0x68u, READ, 0x01u,  0x00000017u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_INTTYPE_Data78[0] },  /* INTTYPE */
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data79[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC3 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_SWCTL_Data51[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data80[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC4 --*/
  {0x69u, READ, 0x01u,  0x00000002u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_VENDOR_Data0[0] }, /* VENDOR */
  {0x69u, READ, 0x01u,  0x00000003u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_PRODUCT_Data1[0] },  /* PRODUCT */
  {0x69u, READ, 0x01u,  0x00000004u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_VERSION_Data2[0] },  /* VERSION */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data81[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC4 --*/
  {0x69u, WRITE,  0x01u,  0x00000012u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_CONTROL_Data3[0] },  /* CONTROL */
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_SWCTL_Data4[0] },  /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data82[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC4 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_BCDNSLOTS_Data5[0] },  /* BCDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_LDNSLOTS_Data6[0] }, /* LDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_LUPSLOTS_Data7[0] }, /* LUPSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000003Fu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_I2CCFG_Data8[0] }, /* I2CCFG */
  {0x69u, WRITE,  0x01u,  0x00000047u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_PDMCTL_Data9[0] }, /* PDMCTL */
  {0x69u, WRITE,  0x01u,  0x0000005Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_PDMCTL2_Data10[0] }, /* PDMCTL2 */
  {0x69u, WRITE,  0x01u,  0x00000048u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_ERRMGMT_Data11[0] }, /* ERRMGMT */
  {0x69u, WRITE,  0x01u,  0x0000004Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_GPIODAT_Data12[0] }, /* GPIODAT */
  {0x69u, WRITE,  0x01u,  0x0000004Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_GPIOOEN_Data13[0] }, /* GPIOOEN */
  {0x69u, WRITE,  0x01u,  0x0000004Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_GPIOIEN_Data14[0] }, /* GPIOIEN */
  {0x69u, WRITE,  0x01u,  0x00000050u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_PINTEN_Data15[0] },  /* PINTEN */
  {0x69u, WRITE,  0x01u,  0x00000051u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_PINTINV_Data16[0] }, /* PINTINV */
  {0x69u, WRITE,  0x01u,  0x00000052u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_PINCFG_Data17[0] },  /* PINCFG */
  {0x69u, WRITE,  0x01u,  0x00000020u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_TESTMODE_Data18[0] },  /* TESTMODE */
  {0x69u, WRITE,  0x01u,  0x00000059u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_CLK1CFG_Data19[0] }, /* CLK1CFG */
  {0x69u, WRITE,  0x01u,  0x0000005Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_CLK2CFG_Data20[0] }, /* CLK2CFG */
  {0x69u, WRITE,  0x01u,  0x00000060u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_UPMASK0_Data21[0] }, /* UPMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000061u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_UPMASK1_Data22[0] }, /* UPMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000062u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_UPMASK2_Data23[0] }, /* UPMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000063u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_UPMASK3_Data24[0] }, /* UPMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000064u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_UPOFFSET_Data25[0] },  /* UPOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000065u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_DNMASK0_Data26[0] }, /* DNMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000066u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_DNMASK1_Data27[0] }, /* DNMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000067u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_DNMASK2_Data28[0] }, /* DNMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000068u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_DNMASK3_Data29[0] }, /* DNMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000069u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_DNOFFSET_Data30[0] },  /* DNOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000081u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_GPIOD0MSK_Data31[0] }, /* GPIOD0MSK */
  {0x69u, WRITE,  0x01u,  0x00000082u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_GPIOD1MSK_Data32[0] }, /* GPIOD1MSK */
  {0x69u, WRITE,  0x01u,  0x00000083u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_GPIOD2MSK_Data33[0] }, /* GPIOD2MSK */
  {0x69u, WRITE,  0x01u,  0x00000084u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_GPIOD3MSK_Data34[0] }, /* GPIOD3MSK */
  {0x69u, WRITE,  0x01u,  0x00000085u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_GPIOD4MSK_Data35[0] }, /* GPIOD4MSK */
  {0x69u, WRITE,  0x01u,  0x00000086u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_GPIOD5MSK_Data36[0] }, /* GPIOD5MSK */
  {0x69u, WRITE,  0x01u,  0x00000087u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_GPIOD6MSK_Data37[0] }, /* GPIOD6MSK */
  {0x69u, WRITE,  0x01u,  0x00000088u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_GPIOD7MSK_Data38[0] }, /* GPIOD7MSK */
  {0x69u, WRITE,  0x01u,  0x0000008Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_GPIODINV_Data39[0] },  /* GPIODINV */
  {0x69u, WRITE,  0x01u,  0x00000080u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_GPIODEN_Data40[0] }, /* GPIODEN */
  {0x69u, WRITE,  0x01u,  0x00000090u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_MBOX0CTL_Data41[0] },  /* MBOX0CTL */
  {0x69u, WRITE,  0x01u,  0x00000096u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_MBOX1CTL_Data42[0] },  /* MBOX1CTL */
  {0x69u, WRITE,  0x01u,  0x0000005Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_SUSCFG_Data43[0] },  /* SUSCFG */
  {0x69u, WRITE,  0x01u,  0x00000058u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_I2SRRSOFFS_Data44[0] },  /* I2SRRSOFFS */
  {0x69u, WRITE,  0x01u,  0x00000057u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_I2SRRCTL_Data45[0] },  /* I2SRRCTL */
  {0x69u, WRITE,  0x01u,  0x0000002Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_TXACTL_Data46[0] },  /* TXACTL */
  {0x69u, WRITE,  0x01u,  0x00000030u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_TXBCTL_Data47[0] },  /* TXBCTL */
  {0x69u, WRITE,  0x01u,  0x0000001Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_INTMSK0_Data48[0] }, /* INTMSK0 */
  {0x69u, WRITE,  0x01u,  0x0000001Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_INTMSK1_Data49[0] }, /* INTMSK1 */
  {0x69u, WRITE,  0x01u,  0x0000001Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_BECCTL_Data50[0] },  /* BECCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data83[0] },  /* NODEADR */
  {0x68u, WRITE,  0x01u,  0x00000013u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_DISCVRY_Data84[0] },  /* DISCVRY */
  {0x00u, DELAY,  0x01u,  0x00000000u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_A2BDelay_Data85[0] }, /* A2B_Delay */
  {0x68u, READ, 0x01u,  0x00000017u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_INTTYPE_Data86[0] },  /* INTTYPE */
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data87[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC4 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_SWCTL_Data51[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data88[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC5 --*/
  {0x69u, READ, 0x01u,  0x00000002u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_VENDOR_Data0[0] }, /* VENDOR */
  {0x69u, READ, 0x01u,  0x00000003u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_PRODUCT_Data1[0] },  /* PRODUCT */
  {0x69u, READ, 0x01u,  0x00000004u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_VERSION_Data2[0] },  /* VERSION */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data89[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC5 --*/
  {0x69u, WRITE,  0x01u,  0x00000012u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_CONTROL_Data3[0] },  /* CONTROL */
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_SWCTL_Data4[0] },  /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data90[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC5 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_BCDNSLOTS_Data5[0] },  /* BCDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_LDNSLOTS_Data6[0] }, /* LDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_LUPSLOTS_Data7[0] }, /* LUPSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000003Fu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_I2CCFG_Data8[0] }, /* I2CCFG */
  {0x69u, WRITE,  0x01u,  0x00000047u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_PDMCTL_Data9[0] }, /* PDMCTL */
  {0x69u, WRITE,  0x01u,  0x0000005Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_PDMCTL2_Data10[0] }, /* PDMCTL2 */
  {0x69u, WRITE,  0x01u,  0x00000048u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_ERRMGMT_Data11[0] }, /* ERRMGMT */
  {0x69u, WRITE,  0x01u,  0x0000004Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_GPIODAT_Data12[0] }, /* GPIODAT */
  {0x69u, WRITE,  0x01u,  0x0000004Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_GPIOOEN_Data13[0] }, /* GPIOOEN */
  {0x69u, WRITE,  0x01u,  0x0000004Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_GPIOIEN_Data14[0] }, /* GPIOIEN */
  {0x69u, WRITE,  0x01u,  0x00000050u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_PINTEN_Data15[0] },  /* PINTEN */
  {0x69u, WRITE,  0x01u,  0x00000051u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_PINTINV_Data16[0] }, /* PINTINV */
  {0x69u, WRITE,  0x01u,  0x00000052u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_PINCFG_Data17[0] },  /* PINCFG */
  {0x69u, WRITE,  0x01u,  0x00000020u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_TESTMODE_Data18[0] },  /* TESTMODE */
  {0x69u, WRITE,  0x01u,  0x00000059u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_CLK1CFG_Data19[0] }, /* CLK1CFG */
  {0x69u, WRITE,  0x01u,  0x0000005Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_CLK2CFG_Data20[0] }, /* CLK2CFG */
  {0x69u, WRITE,  0x01u,  0x00000060u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_UPMASK0_Data21[0] }, /* UPMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000061u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_UPMASK1_Data22[0] }, /* UPMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000062u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_UPMASK2_Data23[0] }, /* UPMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000063u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_UPMASK3_Data24[0] }, /* UPMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000064u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_UPOFFSET_Data25[0] },  /* UPOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000065u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_DNMASK0_Data26[0] }, /* DNMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000066u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_DNMASK1_Data27[0] }, /* DNMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000067u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_DNMASK2_Data28[0] }, /* DNMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000068u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_DNMASK3_Data29[0] }, /* DNMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000069u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_DNOFFSET_Data30[0] },  /* DNOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000081u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_GPIOD0MSK_Data31[0] }, /* GPIOD0MSK */
  {0x69u, WRITE,  0x01u,  0x00000082u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_GPIOD1MSK_Data32[0] }, /* GPIOD1MSK */
  {0x69u, WRITE,  0x01u,  0x00000083u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_GPIOD2MSK_Data33[0] }, /* GPIOD2MSK */
  {0x69u, WRITE,  0x01u,  0x00000084u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_GPIOD3MSK_Data34[0] }, /* GPIOD3MSK */
  {0x69u, WRITE,  0x01u,  0x00000085u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_GPIOD4MSK_Data35[0] }, /* GPIOD4MSK */
  {0x69u, WRITE,  0x01u,  0x00000086u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_GPIOD5MSK_Data36[0] }, /* GPIOD5MSK */
  {0x69u, WRITE,  0x01u,  0x00000087u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_GPIOD6MSK_Data37[0] }, /* GPIOD6MSK */
  {0x69u, WRITE,  0x01u,  0x00000088u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_GPIOD7MSK_Data38[0] }, /* GPIOD7MSK */
  {0x69u, WRITE,  0x01u,  0x0000008Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_GPIODINV_Data39[0] },  /* GPIODINV */
  {0x69u, WRITE,  0x01u,  0x00000080u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_GPIODEN_Data40[0] }, /* GPIODEN */
  {0x69u, WRITE,  0x01u,  0x00000090u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_MBOX0CTL_Data41[0] },  /* MBOX0CTL */
  {0x69u, WRITE,  0x01u,  0x00000096u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_MBOX1CTL_Data42[0] },  /* MBOX1CTL */
  {0x69u, WRITE,  0x01u,  0x0000005Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_SUSCFG_Data43[0] },  /* SUSCFG */
  {0x69u, WRITE,  0x01u,  0x00000058u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_I2SRRSOFFS_Data44[0] },  /* I2SRRSOFFS */
  {0x69u, WRITE,  0x01u,  0x00000057u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_I2SRRCTL_Data45[0] },  /* I2SRRCTL */
  {0x69u, WRITE,  0x01u,  0x0000002Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_TXACTL_Data46[0] },  /* TXACTL */
  {0x69u, WRITE,  0x01u,  0x00000030u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_TXBCTL_Data47[0] },  /* TXBCTL */
  {0x69u, WRITE,  0x01u,  0x0000001Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_INTMSK0_Data48[0] }, /* INTMSK0 */
  {0x69u, WRITE,  0x01u,  0x0000001Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_INTMSK1_Data49[0] }, /* INTMSK1 */
  {0x69u, WRITE,  0x01u,  0x0000001Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_BECCTL_Data50[0] },  /* BECCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data91[0] },  /* NODEADR */
  {0x68u, WRITE,  0x01u,  0x00000013u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_DISCVRY_Data92[0] },  /* DISCVRY */
  {0x00u, DELAY,  0x01u,  0x00000000u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_A2BDelay_Data93[0] }, /* A2B_Delay */
  {0x68u, READ, 0x01u,  0x00000017u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_INTTYPE_Data94[0] },  /* INTTYPE */
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data95[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC5 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_SWCTL_Data51[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data96[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC6 --*/
  {0x69u, READ, 0x01u,  0x00000002u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_VENDOR_Data0[0] }, /* VENDOR */
  {0x69u, READ, 0x01u,  0x00000003u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_PRODUCT_Data1[0] },  /* PRODUCT */
  {0x69u, READ, 0x01u,  0x00000004u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_VERSION_Data2[0] },  /* VERSION */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data97[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC6 --*/
  {0x69u, WRITE,  0x01u,  0x00000012u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_CONTROL_Data3[0] },  /* CONTROL */
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_SWCTL_Data4[0] },  /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data98[0] },  /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC6 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_BCDNSLOTS_Data5[0] },  /* BCDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_LDNSLOTS_Data6[0] }, /* LDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_LUPSLOTS_Data7[0] }, /* LUPSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000003Fu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_I2CCFG_Data8[0] }, /* I2CCFG */
  {0x69u, WRITE,  0x01u,  0x00000047u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_PDMCTL_Data9[0] }, /* PDMCTL */
  {0x69u, WRITE,  0x01u,  0x0000005Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_PDMCTL2_Data10[0] }, /* PDMCTL2 */
  {0x69u, WRITE,  0x01u,  0x00000048u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_ERRMGMT_Data11[0] }, /* ERRMGMT */
  {0x69u, WRITE,  0x01u,  0x0000004Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_GPIODAT_Data12[0] }, /* GPIODAT */
  {0x69u, WRITE,  0x01u,  0x0000004Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_GPIOOEN_Data13[0] }, /* GPIOOEN */
  {0x69u, WRITE,  0x01u,  0x0000004Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_GPIOIEN_Data14[0] }, /* GPIOIEN */
  {0x69u, WRITE,  0x01u,  0x00000050u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_PINTEN_Data15[0] },  /* PINTEN */
  {0x69u, WRITE,  0x01u,  0x00000051u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_PINTINV_Data16[0] }, /* PINTINV */
  {0x69u, WRITE,  0x01u,  0x00000052u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_PINCFG_Data17[0] },  /* PINCFG */
  {0x69u, WRITE,  0x01u,  0x00000020u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_TESTMODE_Data18[0] },  /* TESTMODE */
  {0x69u, WRITE,  0x01u,  0x00000059u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_CLK1CFG_Data19[0] }, /* CLK1CFG */
  {0x69u, WRITE,  0x01u,  0x0000005Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_CLK2CFG_Data20[0] }, /* CLK2CFG */
  {0x69u, WRITE,  0x01u,  0x00000060u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_UPMASK0_Data21[0] }, /* UPMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000061u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_UPMASK1_Data22[0] }, /* UPMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000062u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_UPMASK2_Data23[0] }, /* UPMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000063u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_UPMASK3_Data24[0] }, /* UPMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000064u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_UPOFFSET_Data25[0] },  /* UPOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000065u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_DNMASK0_Data26[0] }, /* DNMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000066u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_DNMASK1_Data27[0] }, /* DNMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000067u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_DNMASK2_Data28[0] }, /* DNMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000068u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_DNMASK3_Data29[0] }, /* DNMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000069u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_DNOFFSET_Data30[0] },  /* DNOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000081u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_GPIOD0MSK_Data31[0] }, /* GPIOD0MSK */
  {0x69u, WRITE,  0x01u,  0x00000082u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_GPIOD1MSK_Data32[0] }, /* GPIOD1MSK */
  {0x69u, WRITE,  0x01u,  0x00000083u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_GPIOD2MSK_Data33[0] }, /* GPIOD2MSK */
  {0x69u, WRITE,  0x01u,  0x00000084u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_GPIOD3MSK_Data34[0] }, /* GPIOD3MSK */
  {0x69u, WRITE,  0x01u,  0x00000085u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_GPIOD4MSK_Data35[0] }, /* GPIOD4MSK */
  {0x69u, WRITE,  0x01u,  0x00000086u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_GPIOD5MSK_Data36[0] }, /* GPIOD5MSK */
  {0x69u, WRITE,  0x01u,  0x00000087u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_GPIOD6MSK_Data37[0] }, /* GPIOD6MSK */
  {0x69u, WRITE,  0x01u,  0x00000088u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_GPIOD7MSK_Data38[0] }, /* GPIOD7MSK */
  {0x69u, WRITE,  0x01u,  0x0000008Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_GPIODINV_Data39[0] },  /* GPIODINV */
  {0x69u, WRITE,  0x01u,  0x00000080u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_GPIODEN_Data40[0] }, /* GPIODEN */
  {0x69u, WRITE,  0x01u,  0x00000090u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_MBOX0CTL_Data41[0] },  /* MBOX0CTL */
  {0x69u, WRITE,  0x01u,  0x00000096u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_MBOX1CTL_Data42[0] },  /* MBOX1CTL */
  {0x69u, WRITE,  0x01u,  0x0000005Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_SUSCFG_Data43[0] },  /* SUSCFG */
  {0x69u, WRITE,  0x01u,  0x00000058u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_I2SRRSOFFS_Data44[0] },  /* I2SRRSOFFS */
  {0x69u, WRITE,  0x01u,  0x00000057u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_I2SRRCTL_Data45[0] },  /* I2SRRCTL */
  {0x69u, WRITE,  0x01u,  0x0000002Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_TXACTL_Data46[0] },  /* TXACTL */
  {0x69u, WRITE,  0x01u,  0x00000030u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_TXBCTL_Data47[0] },  /* TXBCTL */
  {0x69u, WRITE,  0x01u,  0x0000001Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_INTMSK0_Data48[0] }, /* INTMSK0 */
  {0x69u, WRITE,  0x01u,  0x0000001Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_INTMSK1_Data49[0] }, /* INTMSK1 */
  {0x69u, WRITE,  0x01u,  0x0000001Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_BECCTL_Data50[0] },  /* BECCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data99[0] },  /* NODEADR */
  {0x68u, WRITE,  0x01u,  0x00000013u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_DISCVRY_Data100[0] }, /* DISCVRY */
  {0x00u, DELAY,  0x01u,  0x00000000u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_A2BDelay_Data101[0] },  /* A2B_Delay */
  {0x68u, READ, 0x01u,  0x00000017u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_INTTYPE_Data102[0] }, /* INTTYPE */
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data103[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC6 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_SWCTL_Data51[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data104[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC7 --*/
  {0x69u, READ, 0x01u,  0x00000002u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_VENDOR_Data0[0] }, /* VENDOR */
  {0x69u, READ, 0x01u,  0x00000003u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_PRODUCT_Data1[0] },  /* PRODUCT */
  {0x69u, READ, 0x01u,  0x00000004u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_VERSION_Data2[0] },  /* VERSION */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data105[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC7 --*/
  {0x69u, WRITE,  0x01u,  0x00000012u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_CONTROL_Data3[0] },  /* CONTROL */
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_SWCTL_Data4[0] },  /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data106[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC7 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_BCDNSLOTS_Data5[0] },  /* BCDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_LDNSLOTS_Data6[0] }, /* LDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_LUPSLOTS_Data7[0] }, /* LUPSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000003Fu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_I2CCFG_Data8[0] }, /* I2CCFG */
  {0x69u, WRITE,  0x01u,  0x00000047u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_PDMCTL_Data9[0] }, /* PDMCTL */
  {0x69u, WRITE,  0x01u,  0x0000005Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_PDMCTL2_Data10[0] }, /* PDMCTL2 */
  {0x69u, WRITE,  0x01u,  0x00000048u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_ERRMGMT_Data11[0] }, /* ERRMGMT */
  {0x69u, WRITE,  0x01u,  0x0000004Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_GPIODAT_Data12[0] }, /* GPIODAT */
  {0x69u, WRITE,  0x01u,  0x0000004Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_GPIOOEN_Data13[0] }, /* GPIOOEN */
  {0x69u, WRITE,  0x01u,  0x0000004Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_GPIOIEN_Data14[0] }, /* GPIOIEN */
  {0x69u, WRITE,  0x01u,  0x00000050u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_PINTEN_Data15[0] },  /* PINTEN */
  {0x69u, WRITE,  0x01u,  0x00000051u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_PINTINV_Data16[0] }, /* PINTINV */
  {0x69u, WRITE,  0x01u,  0x00000052u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_PINCFG_Data17[0] },  /* PINCFG */
  {0x69u, WRITE,  0x01u,  0x00000020u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_TESTMODE_Data18[0] },  /* TESTMODE */
  {0x69u, WRITE,  0x01u,  0x00000059u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_CLK1CFG_Data19[0] }, /* CLK1CFG */
  {0x69u, WRITE,  0x01u,  0x0000005Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_CLK2CFG_Data20[0] }, /* CLK2CFG */
  {0x69u, WRITE,  0x01u,  0x00000060u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_UPMASK0_Data21[0] }, /* UPMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000061u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_UPMASK1_Data22[0] }, /* UPMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000062u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_UPMASK2_Data23[0] }, /* UPMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000063u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_UPMASK3_Data24[0] }, /* UPMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000064u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_UPOFFSET_Data25[0] },  /* UPOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000065u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_DNMASK0_Data26[0] }, /* DNMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000066u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_DNMASK1_Data27[0] }, /* DNMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000067u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_DNMASK2_Data28[0] }, /* DNMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000068u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_DNMASK3_Data29[0] }, /* DNMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000069u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_DNOFFSET_Data30[0] },  /* DNOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000081u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_GPIOD0MSK_Data31[0] }, /* GPIOD0MSK */
  {0x69u, WRITE,  0x01u,  0x00000082u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_GPIOD1MSK_Data32[0] }, /* GPIOD1MSK */
  {0x69u, WRITE,  0x01u,  0x00000083u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_GPIOD2MSK_Data33[0] }, /* GPIOD2MSK */
  {0x69u, WRITE,  0x01u,  0x00000084u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_GPIOD3MSK_Data34[0] }, /* GPIOD3MSK */
  {0x69u, WRITE,  0x01u,  0x00000085u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_GPIOD4MSK_Data35[0] }, /* GPIOD4MSK */
  {0x69u, WRITE,  0x01u,  0x00000086u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_GPIOD5MSK_Data36[0] }, /* GPIOD5MSK */
  {0x69u, WRITE,  0x01u,  0x00000087u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_GPIOD6MSK_Data37[0] }, /* GPIOD6MSK */
  {0x69u, WRITE,  0x01u,  0x00000088u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_GPIOD7MSK_Data38[0] }, /* GPIOD7MSK */
  {0x69u, WRITE,  0x01u,  0x0000008Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_GPIODINV_Data39[0] },  /* GPIODINV */
  {0x69u, WRITE,  0x01u,  0x00000080u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_GPIODEN_Data40[0] }, /* GPIODEN */
  {0x69u, WRITE,  0x01u,  0x00000090u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_MBOX0CTL_Data41[0] },  /* MBOX0CTL */
  {0x69u, WRITE,  0x01u,  0x00000096u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_MBOX1CTL_Data42[0] },  /* MBOX1CTL */
  {0x69u, WRITE,  0x01u,  0x0000005Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_SUSCFG_Data43[0] },  /* SUSCFG */
  {0x69u, WRITE,  0x01u,  0x00000058u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_I2SRRSOFFS_Data44[0] },  /* I2SRRSOFFS */
  {0x69u, WRITE,  0x01u,  0x00000057u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_I2SRRCTL_Data45[0] },  /* I2SRRCTL */
  {0x69u, WRITE,  0x01u,  0x0000002Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_TXACTL_Data46[0] },  /* TXACTL */
  {0x69u, WRITE,  0x01u,  0x00000030u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_TXBCTL_Data47[0] },  /* TXBCTL */
  {0x69u, WRITE,  0x01u,  0x0000001Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_INTMSK0_Data48[0] }, /* INTMSK0 */
  {0x69u, WRITE,  0x01u,  0x0000001Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_INTMSK1_Data49[0] }, /* INTMSK1 */
  {0x69u, WRITE,  0x01u,  0x0000001Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_BECCTL_Data50[0] },  /* BECCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data107[0] }, /* NODEADR */
  {0x68u, WRITE,  0x01u,  0x00000013u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_DISCVRY_Data108[0] }, /* DISCVRY */
  {0x00u, DELAY,  0x01u,  0x00000000u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_A2BDelay_Data109[0] },  /* A2B_Delay */
  {0x68u, READ, 0x01u,  0x00000017u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_INTTYPE_Data110[0] }, /* INTTYPE */
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data111[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC7 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_SWCTL_Data51[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data112[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC8 --*/
  {0x69u, READ, 0x01u,  0x00000002u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_VENDOR_Data0[0] }, /* VENDOR */
  {0x69u, READ, 0x01u,  0x00000003u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_PRODUCT_Data1[0] },  /* PRODUCT */
  {0x69u, READ, 0x01u,  0x00000004u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_VERSION_Data2[0] },  /* VERSION */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data113[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC8 --*/
  {0x69u, WRITE,  0x01u,  0x00000012u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_CONTROL_Data3[0] },  /* CONTROL */
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_SWCTL_Data4[0] },  /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data114[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC8 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_BCDNSLOTS_Data5[0] },  /* BCDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_LDNSLOTS_Data6[0] }, /* LDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_LUPSLOTS_Data7[0] }, /* LUPSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000003Fu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_I2CCFG_Data8[0] }, /* I2CCFG */
  {0x69u, WRITE,  0x01u,  0x00000047u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_PDMCTL_Data9[0] }, /* PDMCTL */
  {0x69u, WRITE,  0x01u,  0x0000005Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_PDMCTL2_Data10[0] }, /* PDMCTL2 */
  {0x69u, WRITE,  0x01u,  0x00000048u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_ERRMGMT_Data11[0] }, /* ERRMGMT */
  {0x69u, WRITE,  0x01u,  0x0000004Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_GPIODAT_Data12[0] }, /* GPIODAT */
  {0x69u, WRITE,  0x01u,  0x0000004Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_GPIOOEN_Data13[0] }, /* GPIOOEN */
  {0x69u, WRITE,  0x01u,  0x0000004Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_GPIOIEN_Data14[0] }, /* GPIOIEN */
  {0x69u, WRITE,  0x01u,  0x00000050u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_PINTEN_Data15[0] },  /* PINTEN */
  {0x69u, WRITE,  0x01u,  0x00000051u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_PINTINV_Data16[0] }, /* PINTINV */
  {0x69u, WRITE,  0x01u,  0x00000052u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_PINCFG_Data17[0] },  /* PINCFG */
  {0x69u, WRITE,  0x01u,  0x00000020u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_TESTMODE_Data18[0] },  /* TESTMODE */
  {0x69u, WRITE,  0x01u,  0x00000059u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_CLK1CFG_Data19[0] }, /* CLK1CFG */
  {0x69u, WRITE,  0x01u,  0x0000005Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_CLK2CFG_Data20[0] }, /* CLK2CFG */
  {0x69u, WRITE,  0x01u,  0x00000060u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_UPMASK0_Data21[0] }, /* UPMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000061u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_UPMASK1_Data22[0] }, /* UPMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000062u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_UPMASK2_Data23[0] }, /* UPMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000063u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_UPMASK3_Data24[0] }, /* UPMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000064u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_UPOFFSET_Data25[0] },  /* UPOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000065u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_DNMASK0_Data26[0] }, /* DNMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000066u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_DNMASK1_Data27[0] }, /* DNMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000067u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_DNMASK2_Data28[0] }, /* DNMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000068u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_DNMASK3_Data29[0] }, /* DNMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000069u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_DNOFFSET_Data30[0] },  /* DNOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000081u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_GPIOD0MSK_Data31[0] }, /* GPIOD0MSK */
  {0x69u, WRITE,  0x01u,  0x00000082u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_GPIOD1MSK_Data32[0] }, /* GPIOD1MSK */
  {0x69u, WRITE,  0x01u,  0x00000083u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_GPIOD2MSK_Data33[0] }, /* GPIOD2MSK */
  {0x69u, WRITE,  0x01u,  0x00000084u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_GPIOD3MSK_Data34[0] }, /* GPIOD3MSK */
  {0x69u, WRITE,  0x01u,  0x00000085u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_GPIOD4MSK_Data35[0] }, /* GPIOD4MSK */
  {0x69u, WRITE,  0x01u,  0x00000086u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_GPIOD5MSK_Data36[0] }, /* GPIOD5MSK */
  {0x69u, WRITE,  0x01u,  0x00000087u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_GPIOD6MSK_Data37[0] }, /* GPIOD6MSK */
  {0x69u, WRITE,  0x01u,  0x00000088u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_GPIOD7MSK_Data38[0] }, /* GPIOD7MSK */
  {0x69u, WRITE,  0x01u,  0x0000008Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_GPIODINV_Data39[0] },  /* GPIODINV */
  {0x69u, WRITE,  0x01u,  0x00000080u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_GPIODEN_Data40[0] }, /* GPIODEN */
  {0x69u, WRITE,  0x01u,  0x00000090u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_MBOX0CTL_Data41[0] },  /* MBOX0CTL */
  {0x69u, WRITE,  0x01u,  0x00000096u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_MBOX1CTL_Data42[0] },  /* MBOX1CTL */
  {0x69u, WRITE,  0x01u,  0x0000005Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_SUSCFG_Data43[0] },  /* SUSCFG */
  {0x69u, WRITE,  0x01u,  0x00000058u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_I2SRRSOFFS_Data44[0] },  /* I2SRRSOFFS */
  {0x69u, WRITE,  0x01u,  0x00000057u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_I2SRRCTL_Data45[0] },  /* I2SRRCTL */
  {0x69u, WRITE,  0x01u,  0x0000002Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_TXACTL_Data46[0] },  /* TXACTL */
  {0x69u, WRITE,  0x01u,  0x00000030u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_TXBCTL_Data47[0] },  /* TXBCTL */
  {0x69u, WRITE,  0x01u,  0x0000001Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_INTMSK0_Data48[0] }, /* INTMSK0 */
  {0x69u, WRITE,  0x01u,  0x0000001Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_INTMSK1_Data49[0] }, /* INTMSK1 */
  {0x69u, WRITE,  0x01u,  0x0000001Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_BECCTL_Data50[0] },  /* BECCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data115[0] }, /* NODEADR */
  {0x68u, WRITE,  0x01u,  0x00000013u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_DISCVRY_Data116[0] }, /* DISCVRY */
  {0x00u, DELAY,  0x01u,  0x00000000u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_A2BDelay_Data117[0] },  /* A2B_Delay */
  {0x68u, READ, 0x01u,  0x00000017u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_INTTYPE_Data118[0] }, /* INTTYPE */
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data119[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC8 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_SWCTL_Data51[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data120[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC9 --*/
  {0x69u, READ, 0x01u,  0x00000002u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_VENDOR_Data0[0] }, /* VENDOR */
  {0x69u, READ, 0x01u,  0x00000003u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_PRODUCT_Data1[0] },  /* PRODUCT */
  {0x69u, READ, 0x01u,  0x00000004u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_VERSION_Data2[0] },  /* VERSION */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data121[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC9 --*/
  {0x69u, WRITE,  0x01u,  0x00000012u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_CONTROL_Data3[0] },  /* CONTROL */
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_SWCTL_Data4[0] },  /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data122[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC9 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_BCDNSLOTS_Data5[0] },  /* BCDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_LDNSLOTS_Data6[0] }, /* LDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_LUPSLOTS_Data7[0] }, /* LUPSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000003Fu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_I2CCFG_Data8[0] }, /* I2CCFG */
  {0x69u, WRITE,  0x01u,  0x00000047u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_PDMCTL_Data9[0] }, /* PDMCTL */
  {0x69u, WRITE,  0x01u,  0x0000005Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_PDMCTL2_Data10[0] }, /* PDMCTL2 */
  {0x69u, WRITE,  0x01u,  0x00000048u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_ERRMGMT_Data11[0] }, /* ERRMGMT */
  {0x69u, WRITE,  0x01u,  0x0000004Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_GPIODAT_Data12[0] }, /* GPIODAT */
  {0x69u, WRITE,  0x01u,  0x0000004Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_GPIOOEN_Data13[0] }, /* GPIOOEN */
  {0x69u, WRITE,  0x01u,  0x0000004Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_GPIOIEN_Data14[0] }, /* GPIOIEN */
  {0x69u, WRITE,  0x01u,  0x00000050u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_PINTEN_Data15[0] },  /* PINTEN */
  {0x69u, WRITE,  0x01u,  0x00000051u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_PINTINV_Data16[0] }, /* PINTINV */
  {0x69u, WRITE,  0x01u,  0x00000052u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_PINCFG_Data17[0] },  /* PINCFG */
  {0x69u, WRITE,  0x01u,  0x00000020u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_TESTMODE_Data18[0] },  /* TESTMODE */
  {0x69u, WRITE,  0x01u,  0x00000059u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_CLK1CFG_Data19[0] }, /* CLK1CFG */
  {0x69u, WRITE,  0x01u,  0x0000005Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_CLK2CFG_Data20[0] }, /* CLK2CFG */
  {0x69u, WRITE,  0x01u,  0x00000060u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_UPMASK0_Data21[0] }, /* UPMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000061u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_UPMASK1_Data22[0] }, /* UPMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000062u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_UPMASK2_Data23[0] }, /* UPMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000063u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_UPMASK3_Data24[0] }, /* UPMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000064u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_UPOFFSET_Data25[0] },  /* UPOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000065u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_DNMASK0_Data26[0] }, /* DNMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000066u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_DNMASK1_Data27[0] }, /* DNMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000067u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_DNMASK2_Data28[0] }, /* DNMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000068u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_DNMASK3_Data29[0] }, /* DNMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000069u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_DNOFFSET_Data30[0] },  /* DNOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000081u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_GPIOD0MSK_Data31[0] }, /* GPIOD0MSK */
  {0x69u, WRITE,  0x01u,  0x00000082u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_GPIOD1MSK_Data32[0] }, /* GPIOD1MSK */
  {0x69u, WRITE,  0x01u,  0x00000083u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_GPIOD2MSK_Data33[0] }, /* GPIOD2MSK */
  {0x69u, WRITE,  0x01u,  0x00000084u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_GPIOD3MSK_Data34[0] }, /* GPIOD3MSK */
  {0x69u, WRITE,  0x01u,  0x00000085u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_GPIOD4MSK_Data35[0] }, /* GPIOD4MSK */
  {0x69u, WRITE,  0x01u,  0x00000086u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_GPIOD5MSK_Data36[0] }, /* GPIOD5MSK */
  {0x69u, WRITE,  0x01u,  0x00000087u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_GPIOD6MSK_Data37[0] }, /* GPIOD6MSK */
  {0x69u, WRITE,  0x01u,  0x00000088u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_GPIOD7MSK_Data38[0] }, /* GPIOD7MSK */
  {0x69u, WRITE,  0x01u,  0x0000008Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_GPIODINV_Data39[0] },  /* GPIODINV */
  {0x69u, WRITE,  0x01u,  0x00000080u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_GPIODEN_Data40[0] }, /* GPIODEN */
  {0x69u, WRITE,  0x01u,  0x00000090u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_MBOX0CTL_Data41[0] },  /* MBOX0CTL */
  {0x69u, WRITE,  0x01u,  0x00000096u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_MBOX1CTL_Data42[0] },  /* MBOX1CTL */
  {0x69u, WRITE,  0x01u,  0x0000005Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_SUSCFG_Data43[0] },  /* SUSCFG */
  {0x69u, WRITE,  0x01u,  0x00000058u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_I2SRRSOFFS_Data44[0] },  /* I2SRRSOFFS */
  {0x69u, WRITE,  0x01u,  0x00000057u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_I2SRRCTL_Data45[0] },  /* I2SRRCTL */
  {0x69u, WRITE,  0x01u,  0x0000002Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_TXACTL_Data46[0] },  /* TXACTL */
  {0x69u, WRITE,  0x01u,  0x00000030u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_TXBCTL_Data47[0] },  /* TXBCTL */
  {0x69u, WRITE,  0x01u,  0x0000001Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_INTMSK0_Data48[0] }, /* INTMSK0 */
  {0x69u, WRITE,  0x01u,  0x0000001Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_INTMSK1_Data49[0] }, /* INTMSK1 */
  {0x69u, WRITE,  0x01u,  0x0000001Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_BECCTL_Data50[0] },  /* BECCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data123[0] }, /* NODEADR */
  {0x68u, WRITE,  0x01u,  0x00000013u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_DISCVRY_Data124[0] }, /* DISCVRY */
  {0x00u, DELAY,  0x01u,  0x00000000u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_A2BDelay_Data125[0] },  /* A2B_Delay */
  {0x68u, READ, 0x01u,  0x00000017u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_INTTYPE_Data126[0] }, /* INTTYPE */
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data127[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC9 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_SWCTL_Data51[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data128[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC10 --*/
  {0x69u, READ, 0x01u,  0x00000002u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_VENDOR_Data0[0] },  /* VENDOR */
  {0x69u, READ, 0x01u,  0x00000003u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_PRODUCT_Data1[0] }, /* PRODUCT */
  {0x69u, READ, 0x01u,  0x00000004u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_VERSION_Data2[0] }, /* VERSION */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data129[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC10 --*/
  {0x69u, WRITE,  0x01u,  0x00000012u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_CONTROL_Data3[0] }, /* CONTROL */
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_SWCTL_Data4[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data130[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC10 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_BCDNSLOTS_Data5[0] }, /* BCDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_LDNSLOTS_Data6[0] },  /* LDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_LUPSLOTS_Data7[0] },  /* LUPSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000003Fu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_I2CCFG_Data8[0] },  /* I2CCFG */
  {0x69u, WRITE,  0x01u,  0x00000047u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_PDMCTL_Data9[0] },  /* PDMCTL */
  {0x69u, WRITE,  0x01u,  0x0000005Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_PDMCTL2_Data10[0] },  /* PDMCTL2 */
  {0x69u, WRITE,  0x01u,  0x00000048u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_ERRMGMT_Data11[0] },  /* ERRMGMT */
  {0x69u, WRITE,  0x01u,  0x0000004Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_GPIODAT_Data12[0] },  /* GPIODAT */
  {0x69u, WRITE,  0x01u,  0x0000004Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_GPIOOEN_Data13[0] },  /* GPIOOEN */
  {0x69u, WRITE,  0x01u,  0x0000004Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_GPIOIEN_Data14[0] },  /* GPIOIEN */
  {0x69u, WRITE,  0x01u,  0x00000050u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_PINTEN_Data15[0] }, /* PINTEN */
  {0x69u, WRITE,  0x01u,  0x00000051u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_PINTINV_Data16[0] },  /* PINTINV */
  {0x69u, WRITE,  0x01u,  0x00000052u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_PINCFG_Data17[0] }, /* PINCFG */
  {0x69u, WRITE,  0x01u,  0x00000020u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_TESTMODE_Data18[0] }, /* TESTMODE */
  {0x69u, WRITE,  0x01u,  0x00000059u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_CLK1CFG_Data19[0] },  /* CLK1CFG */
  {0x69u, WRITE,  0x01u,  0x0000005Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_CLK2CFG_Data20[0] },  /* CLK2CFG */
  {0x69u, WRITE,  0x01u,  0x00000060u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_UPMASK0_Data21[0] },  /* UPMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000061u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_UPMASK1_Data22[0] },  /* UPMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000062u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_UPMASK2_Data23[0] },  /* UPMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000063u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_UPMASK3_Data24[0] },  /* UPMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000064u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_UPOFFSET_Data25[0] }, /* UPOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000065u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_DNMASK0_Data26[0] },  /* DNMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000066u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_DNMASK1_Data27[0] },  /* DNMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000067u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_DNMASK2_Data28[0] },  /* DNMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000068u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_DNMASK3_Data29[0] },  /* DNMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000069u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_DNOFFSET_Data30[0] }, /* DNOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000081u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_GPIOD0MSK_Data31[0] },  /* GPIOD0MSK */
  {0x69u, WRITE,  0x01u,  0x00000082u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_GPIOD1MSK_Data32[0] },  /* GPIOD1MSK */
  {0x69u, WRITE,  0x01u,  0x00000083u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_GPIOD2MSK_Data33[0] },  /* GPIOD2MSK */
  {0x69u, WRITE,  0x01u,  0x00000084u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_GPIOD3MSK_Data34[0] },  /* GPIOD3MSK */
  {0x69u, WRITE,  0x01u,  0x00000085u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_GPIOD4MSK_Data35[0] },  /* GPIOD4MSK */
  {0x69u, WRITE,  0x01u,  0x00000086u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_GPIOD5MSK_Data36[0] },  /* GPIOD5MSK */
  {0x69u, WRITE,  0x01u,  0x00000087u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_GPIOD6MSK_Data37[0] },  /* GPIOD6MSK */
  {0x69u, WRITE,  0x01u,  0x00000088u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_GPIOD7MSK_Data38[0] },  /* GPIOD7MSK */
  {0x69u, WRITE,  0x01u,  0x0000008Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_GPIODINV_Data39[0] }, /* GPIODINV */
  {0x69u, WRITE,  0x01u,  0x00000080u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_GPIODEN_Data40[0] },  /* GPIODEN */
  {0x69u, WRITE,  0x01u,  0x00000090u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_MBOX0CTL_Data41[0] }, /* MBOX0CTL */
  {0x69u, WRITE,  0x01u,  0x00000096u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_MBOX1CTL_Data42[0] }, /* MBOX1CTL */
  {0x69u, WRITE,  0x01u,  0x0000005Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_SUSCFG_Data43[0] }, /* SUSCFG */
  {0x69u, WRITE,  0x01u,  0x00000058u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_I2SRRSOFFS_Data44[0] }, /* I2SRRSOFFS */
  {0x69u, WRITE,  0x01u,  0x00000057u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_I2SRRCTL_Data45[0] }, /* I2SRRCTL */
  {0x69u, WRITE,  0x01u,  0x0000002Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_TXACTL_Data46[0] }, /* TXACTL */
  {0x69u, WRITE,  0x01u,  0x00000030u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_TXBCTL_Data47[0] }, /* TXBCTL */
  {0x69u, WRITE,  0x01u,  0x0000001Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_INTMSK0_Data48[0] },  /* INTMSK0 */
  {0x69u, WRITE,  0x01u,  0x0000001Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_INTMSK1_Data49[0] },  /* INTMSK1 */
  {0x69u, WRITE,  0x01u,  0x0000001Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_BECCTL_Data50[0] }, /* BECCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data131[0] }, /* NODEADR */
  {0x68u, WRITE,  0x01u,  0x00000013u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_DISCVRY_Data132[0] }, /* DISCVRY */
  {0x00u, DELAY,  0x01u,  0x00000000u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_A2BDelay_Data133[0] },  /* A2B_Delay */
  {0x68u, READ, 0x01u,  0x00000017u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_INTTYPE_Data134[0] }, /* INTTYPE */
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data135[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC10 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_SWCTL_Data51[0] },  /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data136[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC11 --*/
  {0x69u, READ, 0x01u,  0x00000002u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_VENDOR_Data0[0] },  /* VENDOR */
  {0x69u, READ, 0x01u,  0x00000003u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_PRODUCT_Data1[0] }, /* PRODUCT */
  {0x69u, READ, 0x01u,  0x00000004u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_VERSION_Data2[0] }, /* VERSION */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data137[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC11 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_BCDNSLOTS_Data3[0] }, /* BCDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_LDNSLOTS_Data4[0] },  /* LDNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_LUPSLOTS_Data5[0] },  /* LUPSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000003Fu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_I2CCFG_Data6[0] },  /* I2CCFG */
  {0x69u, WRITE,  0x01u,  0x00000047u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_PDMCTL_Data7[0] },  /* PDMCTL */
  {0x69u, WRITE,  0x01u,  0x0000005Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_PDMCTL2_Data8[0] }, /* PDMCTL2 */
  {0x69u, WRITE,  0x01u,  0x00000048u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_ERRMGMT_Data9[0] }, /* ERRMGMT */
  {0x69u, WRITE,  0x01u,  0x0000004Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_GPIODAT_Data10[0] },  /* GPIODAT */
  {0x69u, WRITE,  0x01u,  0x0000004Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_GPIOOEN_Data11[0] },  /* GPIOOEN */
  {0x69u, WRITE,  0x01u,  0x0000004Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_GPIOIEN_Data12[0] },  /* GPIOIEN */
  {0x69u, WRITE,  0x01u,  0x00000050u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_PINTEN_Data13[0] }, /* PINTEN */
  {0x69u, WRITE,  0x01u,  0x00000051u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_PINTINV_Data14[0] },  /* PINTINV */
  {0x69u, WRITE,  0x01u,  0x00000052u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_PINCFG_Data15[0] }, /* PINCFG */
  {0x69u, WRITE,  0x01u,  0x00000020u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_TESTMODE_Data16[0] }, /* TESTMODE */
  {0x69u, WRITE,  0x01u,  0x00000059u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_CLK1CFG_Data17[0] },  /* CLK1CFG */
  {0x69u, WRITE,  0x01u,  0x0000005Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_CLK2CFG_Data18[0] },  /* CLK2CFG */
  {0x69u, WRITE,  0x01u,  0x00000060u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_UPMASK0_Data19[0] },  /* UPMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000061u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_UPMASK1_Data20[0] },  /* UPMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000062u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_UPMASK2_Data21[0] },  /* UPMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000063u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_UPMASK3_Data22[0] },  /* UPMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000064u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_UPOFFSET_Data23[0] }, /* UPOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000065u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_DNMASK0_Data24[0] },  /* DNMASK0 */
  {0x69u, WRITE,  0x01u,  0x00000066u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_DNMASK1_Data25[0] },  /* DNMASK1 */
  {0x69u, WRITE,  0x01u,  0x00000067u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_DNMASK2_Data26[0] },  /* DNMASK2 */
  {0x69u, WRITE,  0x01u,  0x00000068u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_DNMASK3_Data27[0] },  /* DNMASK3 */
  {0x69u, WRITE,  0x01u,  0x00000069u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_DNOFFSET_Data28[0] }, /* DNOFFSET */
  {0x69u, WRITE,  0x01u,  0x00000081u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_GPIOD0MSK_Data29[0] },  /* GPIOD0MSK */
  {0x69u, WRITE,  0x01u,  0x00000082u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_GPIOD1MSK_Data30[0] },  /* GPIOD1MSK */
  {0x69u, WRITE,  0x01u,  0x00000083u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_GPIOD2MSK_Data31[0] },  /* GPIOD2MSK */
  {0x69u, WRITE,  0x01u,  0x00000084u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_GPIOD3MSK_Data32[0] },  /* GPIOD3MSK */
  {0x69u, WRITE,  0x01u,  0x00000085u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_GPIOD4MSK_Data33[0] },  /* GPIOD4MSK */
  {0x69u, WRITE,  0x01u,  0x00000086u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_GPIOD5MSK_Data34[0] },  /* GPIOD5MSK */
  {0x69u, WRITE,  0x01u,  0x00000087u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_GPIOD6MSK_Data35[0] },  /* GPIOD6MSK */
  {0x69u, WRITE,  0x01u,  0x00000088u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_GPIOD7MSK_Data36[0] },  /* GPIOD7MSK */
  {0x69u, WRITE,  0x01u,  0x0000008Au,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_GPIODINV_Data37[0] }, /* GPIODINV */
  {0x69u, WRITE,  0x01u,  0x00000080u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_GPIODEN_Data38[0] },  /* GPIODEN */
  {0x69u, WRITE,  0x01u,  0x00000090u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_MBOX0CTL_Data39[0] }, /* MBOX0CTL */
  {0x69u, WRITE,  0x01u,  0x00000096u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_MBOX1CTL_Data40[0] }, /* MBOX1CTL */
  {0x69u, WRITE,  0x01u,  0x0000005Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_SUSCFG_Data41[0] }, /* SUSCFG */
  {0x69u, WRITE,  0x01u,  0x00000058u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_I2SRRSOFFS_Data42[0] }, /* I2SRRSOFFS */
  {0x69u, WRITE,  0x01u,  0x00000057u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_I2SRRCTL_Data43[0] }, /* I2SRRCTL */
  {0x69u, WRITE,  0x01u,  0x0000002Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_TXACTL_Data44[0] }, /* TXACTL */
  {0x69u, WRITE,  0x01u,  0x00000030u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_TXBCTL_Data45[0] }, /* TXBCTL */
  {0x69u, WRITE,  0x01u,  0x0000001Bu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_INTMSK0_Data46[0] },  /* INTMSK0 */
  {0x69u, WRITE,  0x01u,  0x0000001Cu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_INTMSK1_Data47[0] },  /* INTMSK1 */
  {0x69u, WRITE,  0x01u,  0x0000001Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_BECCTL_Data48[0] }, /* BECCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data138[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC10 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_DNSLOTS_Data52[0] },  /* DNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_UPSLOTS_Data53[0] },  /* UPSLOTS */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data139[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC9 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_DNSLOTS_Data52[0] }, /* DNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_UPSLOTS_Data53[0] }, /* UPSLOTS */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data140[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC8 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_DNSLOTS_Data52[0] }, /* DNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_UPSLOTS_Data53[0] }, /* UPSLOTS */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data141[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC7 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_DNSLOTS_Data52[0] }, /* DNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_UPSLOTS_Data53[0] }, /* UPSLOTS */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data142[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC6 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_DNSLOTS_Data52[0] }, /* DNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_UPSLOTS_Data53[0] }, /* UPSLOTS */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data143[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC5 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_DNSLOTS_Data52[0] }, /* DNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_UPSLOTS_Data53[0] }, /* UPSLOTS */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data144[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC4 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_DNSLOTS_Data52[0] }, /* DNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_UPSLOTS_Data53[0] }, /* UPSLOTS */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data145[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC3 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_DNSLOTS_Data52[0] }, /* DNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_UPSLOTS_Data53[0] }, /* UPSLOTS */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data146[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC2 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_DNSLOTS_Data52[0] }, /* DNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_UPSLOTS_Data53[0] }, /* UPSLOTS */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data147[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC1 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_DNSLOTS_Data52[0] }, /* DNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_UPSLOTS_Data53[0] }, /* UPSLOTS */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data148[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC0 --*/
  {0x69u, WRITE,  0x01u,  0x0000000Du,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_DNSLOTS_Data52[0] }, /* DNSLOTS */
  {0x69u, WRITE,  0x01u,  0x0000000Eu,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_UPSLOTS_Data53[0] }, /* UPSLOTS */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x0000000Du,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_DNSLOTS_Data149[0] }, /* DNSLOTS */
  {0x68u, WRITE,  0x01u,  0x0000000Eu,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_UPSLOTS_Data150[0] }, /* UPSLOTS */
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data151[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC10 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC10_SWCTL_Data54[0] },  /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data152[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC9 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC9_SWCTL_Data54[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data153[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC8 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC8_SWCTL_Data54[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data154[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC7 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC7_SWCTL_Data54[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data155[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC6 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC6_SWCTL_Data54[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data156[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC5 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC5_SWCTL_Data54[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data157[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC4 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC4_SWCTL_Data54[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data158[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC3 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC3_SWCTL_Data54[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data159[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC2 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC2_SWCTL_Data54[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data160[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC1 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC1_SWCTL_Data54[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data161[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC0 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC0_SWCTL_Data54[0] }, /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_SWCTL_Data162[0] }, /* SWCTL */
  {0x68u, WRITE,  0x01u,  0x00000040u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_PLLCTL_Data163[0] },  /* PLLCTL */
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data164[0] }, /* NODEADR */
  {0x69u, WRITE,  0x01u,  0x00000040u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_PLLCTL_Data165[0] },  /* PLLCTL */
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data166[0] }, /* NODEADR */
  {0x68u, WRITE,  0x01u,  0x00000010u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_SLOTFMT_Data167[0] }, /* SLOTFMT */
  {0x68u, WRITE,  0x01u,  0x00000011u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_DATCTL_Data168[0] },  /* DATCTL */
  {0x68u, WRITE,  0x01u,  0x00000056u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_I2SRRATE_Data169[0] },  /* I2SRRATE */
  {0x68u, WRITE,  0x01u,  0x00000012u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_CONTROL_Data170[0] }, /* CONTROL */
  {0x00u, DELAY,  0x01u,  0x00000000u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_A2BDelay_Data171[0] },  /* A2B_Delay */
  {0x68u, WRITE,  0x01u,  0x00000001u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_NODEADR_Data172[0] }, /* NODEADR */

  /*-- COMMANDS FOR DEVICE - A2B-DMIC11 --*/
  {0x69u, WRITE,  0x01u,  0x00000009u,  0x01u,  0x0001u,  &gaConfig_A2BDMIC11_SWCTL_Data49[0] },  /* SWCTL */

  /*-- COMMANDS FOR DEVICE - A2B Master Node  --*/
  {0x68u, WRITE,  0x01u,  0x00000012u,  0x01u,  0x0001u,  &gaConfig_A2BMasterNode_CONTROL_Data173[0] }, /* CONTROL */
};
