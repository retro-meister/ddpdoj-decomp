#include "common.h"

s32 printf();
extern u8 D_00289C40[];
extern s8 D_0028E2EC_as_s8;
extern s8 D_0028E304_as_s8;
extern s8 D_0028E384_as_s8;
extern s8 D_0028E388_as_s8;
extern s8 D_0028E38C_as_s8;
extern s8 D_0068DC21[];
extern s8 D_0068DC22[];
extern s8 D_0068DC23[];
extern s8 D_0068DC41[];
extern s8 D_0068DC44[];
void func_00224B50(void) {
    D_0028E38C_as_s8 = D_0068DC21[0];
    D_0028E384_as_s8 = D_0068DC22[0];
    D_0028E388_as_s8 = D_0068DC23[0];
    D_0028E2EC_as_s8 = D_0068DC44[0];
    D_0028E304_as_s8 = D_0068DC41[0];
#ifndef DEATH_LABEL
    printf(D_00289C40, D_0068DC23[0], D_0068DC22[0], D_0068DC21[0]);
#endif
}
