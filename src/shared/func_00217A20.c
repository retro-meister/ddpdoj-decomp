#include "common.h"

extern s16 D_0028E9E0;
extern s8 D_0028E9E8;

#ifdef DEATH_LABEL
extern s8 death_D_00290B60;
#endif

void func_00217A20(void) {
    D_0028E9E8 = 0;
    D_0028E9E0 = 0;
#ifdef DEATH_LABEL
    death_D_00290B60 = 0;
#endif
}
