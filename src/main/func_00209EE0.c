#include "common.h"

extern s32 reg_a4;
extern s32 D_0028E570;
extern u16 D_0028E160;

void func_00209EE0(void) {
    reg_a4 -= D_0028E570;
    reg_tmp.sw = reg_a4;
    D_0028E160 = reg_tmp.h[0];
}
