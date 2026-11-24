#include "common.h"

extern s32 reg_a4_as_s32;
extern s32 D_0028E570_as_s32;
extern u16 D_0028E160;

void func_00209EE0(void) {
    reg_a4_as_s32 -= D_0028E570_as_s32;
    reg_tmp.sw = reg_a4_as_s32;
    D_0028E160 = reg_tmp.h[0];
}
