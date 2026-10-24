#include "switch_reg.h"

 /*
       U6 Port A                                  U6 Port B
  7--------------- ~ADAU1979_EN       |       7--------------- ~GIGe_RESET
  | 6------------- ~ADAU1962_EN       |       | 6------------- ~ETH1_RESET
  | | 5----------- ~ADAU_RESET        |       | | 5----------- ~ETH1_EN
  | | | 4---------  Not Used          |       | | | 4--------- ~MLB_EN
  | | | | 3-------  Not Used          |       | | | | 3-------  AUDIO_JACK_SEL
  | | | | | 2----- ~MicroSD_SPI       |       | | | | | 2----- ~SPDIF_OPTICAL_EN
  | | | | | | 1---  PUSHBUTTON_EN     |       | | | | | | 1--- ~SPDIF_DIGITAL_EN
  | | | | | | | 0-  EEPROM_EN         |       | | | | | | | 0-  OCTAL_SPI_CS_EN
  | | | | | | | |                     |       | | | | | | | |
  Y Y N X X N N Y                     |       N N N N Y N Y Y     ( Active Y or N )
  0 0 0 0 0 1 0 1                     |       1 1 1 1 1 1 0 1     ( value being set )
*/
SwReg sw0_en[SW0_EN_LEN] = {
  {0x12u, 0x05u},
  {0x13u, 0xFDu},
  // Set iodira direction.
  {0x0u, 0x18u},
  // Set iodirb direction.
  {0x1u, 0x00u},
};

/*
       U6 Port A                                  U6 Port B
  7--------------- ~ADAU1979_EN       |       7--------------- ~GIGe_RESET
  | 6------------- ~ADAU1962_EN       |       | 6------------- ~ETH1_RESET
  | | 5----------- ~ADAU_RESET        |       | | 5----------- ~ETH1_EN
  | | | 4---------  Not Used          |       | | | 4--------- ~MLB_EN
  | | | | 3-------  Not Used          |       | | | | 3-------  AUDIO_JACK_SEL
  | | | | | 2----- ~MicroSD_SPI       |       | | | | | 2----- ~SPDIF_OPTICAL_EN
  | | | | | | 1---  PUSHBUTTON_EN     |       | | | | | | 1--- ~SPDIF_DIGITAL_EN
  | | | | | | | 0-  EEPROM_EN         |       | | | | | | | 0-  OCTAL_SPI_CS_EN
  | | | | | | | |                     |       | | | | | | | |
  Y Y Y X X N N Y                     |       N N N N Y N Y Y     ( Active Y or N )
  0 0 1 0 0 1 0 1                     |       1 1 1 1 1 1 0 1     ( value being set )
*/
SwReg sw0_rst[SW0_RST_LEN] = {
  {0x12u, 0x25u},
  {0x13u, 0xFDu},
  // Set iodira direction.
  {0x0u, 0x18u},
  // Set iodirb direction.
  {0x1u, 0x00u},
};
