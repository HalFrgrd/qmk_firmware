#include "ILI9341_hf.h"


void ILI9341_init(void){
    spi_start(TFT_CS, false, 0, 2);
}