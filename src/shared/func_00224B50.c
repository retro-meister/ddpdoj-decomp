#include "common.h"

s32 printf();
extern u8 D_00289C40[];
extern s8 D_0028E2EC;
extern s8 D_0028E304;
extern s8 D_0028E384;
extern s8 D_0028E388;
extern s8 D_0028E38C;
extern s8 D_0068DC21[];
extern s8 D_0068DC22[];
extern s8 D_0068DC23[];
extern s8 D_0068DC41[];
extern s8 D_0068DC44[];
void func_00224B50(void) {
    D_0028E38C = D_0068DC21[0];
    D_0028E384 = D_0068DC22[0];
    D_0028E388 = D_0068DC23[0];
    D_0028E2EC = D_0068DC44[0];
    D_0028E304 = D_0068DC41[0];
#ifndef DEATH_LABEL
    printf(D_00289C40, D_0068DC23[0], D_0068DC22[0], D_0068DC21[0]);
#endif
}
