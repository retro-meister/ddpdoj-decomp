#include "common.h"

extern s8 D_0028E2EC;
extern s8 D_0028E304;
extern s8 D_0028E308;
extern s8 D_0028E30C;
extern s8 D_0068DC41[];
extern s8 D_0068DC42[];
extern s8 D_0068DC43[];
extern s8 D_0068DC44[];

#ifdef DEATH_LABEL
extern s8 D_0068DC45[];
extern s8 death_D_00290854;
extern s8 death_D_00290858;
extern s8 death_D_00628DC6[];
#endif

void func_0021EA10(void) {
    D_0028E304 = D_0068DC41[0];
    D_0028E30C = D_0068DC42[0];
    D_0028E308 = D_0068DC43[0];
    D_0028E2EC = D_0068DC44[0];
#ifdef DEATH_LABEL
    death_D_00290858 = D_0068DC45[0];
    death_D_00290854 = death_D_00628DC6[0];
#endif
}
