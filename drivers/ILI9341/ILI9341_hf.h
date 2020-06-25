#include "spi_master.h"


// Pin outs
#define TFT_DC    B5      //9
#define TFT_CS    E6      //7
#define TFT_MOSI  B2      //16
#define TFT_CLK   B1      //15
#define TFT_MISO  F5      //19
#define TFT_RST   C6      //8
#define TFT_LED   F6      //18
//https://imgur.com/a/fRSx8
//https://deskthority.net/viewtopic.php?f=7&t=8448&start=

void ILI9341_init(void);