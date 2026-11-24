#include "common.h"

extern s8 D_0028E9E8;

#ifdef DEATH_LABEL
extern s8 death_D_00290B60;
#endif

void func_00217A30(void) {
#ifdef DEATH_LABEL
    death_D_00290B60 = 0;
#endif
    D_0028E9E8 = 1;
}
