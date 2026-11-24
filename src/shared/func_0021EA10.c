#include "common.h"

extern s8 D_0028E2EC_as_s8;
extern s8 D_0028E304_as_s8;
extern s8 D_0028E308_as_s8;
extern s8 D_0028E30C_as_s8;
extern s8 D_0068DC41[];
extern s8 D_0068DC42_as_s8_a[];
extern s8 D_0068DC43_as_s8_a[];
extern s8 D_0068DC44[];

#ifdef DEATH_LABEL
extern s8 D_0068DC45_as_s8_a[];
extern s8 death_D_00290854_as_s8;
extern s8 death_D_00290858_as_s8;
extern s8 death_D_00628DC6_as_s8_a[];
#endif

void func_0021EA10(void) {
    D_0028E304_as_s8 = D_0068DC41[0];
    D_0028E30C_as_s8 = D_0068DC42_as_s8_a[0];
    D_0028E308_as_s8 = D_0068DC43_as_s8_a[0];
    D_0028E2EC_as_s8 = D_0068DC44[0];
#ifdef DEATH_LABEL
    death_D_00290858_as_s8 = D_0068DC45_as_s8_a[0];
    death_D_00290854_as_s8 = death_D_00628DC6_as_s8_a[0];
#endif
}
