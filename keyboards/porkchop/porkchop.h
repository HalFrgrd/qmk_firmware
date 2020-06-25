#ifndef PORKCHOP
#define PORKCHOP

#include "quantum.h"
#include "matrix.h"
#include <stddef.h>
#include "ILI9341_hf.h"
#include "spi_master.h"


// This a shortcut to help you visually see your layout.
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array
 #define KEYMAP( \
  k00, k01, k02, k03, k04,      k05, k06, k07, k08, k09, \
  k10, k11, k12, k13, k14,      k15, k16, k17, k18, k19, \
  k20, k21, k22, k23, k24,      k25, k26, k27, k28, k29, \
  k30, k31, k32, k33, k34,      k35, k36, k37, k38, k39   \
) \
{ \
	{ k00,   k01, k02, k03, k04,      k05, k06, k07, k08, k09   }, \
	{ k10,   k11, k12, k13, k14,      k15, k16, k17, k18, k19   }, \
	{ k20,   k21, k22, k23, k24,      k25, k26, k27, k28, k29   }, \
	{ k30,   k31, k32, k33, k34,      k35, k36, k37, k38, k39   },  \
}


#endif 
