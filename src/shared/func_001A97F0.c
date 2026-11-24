#include "common.h"

extern s32 *reg_a1_as_s32_p;
extern s32 reg_a0_as_s32;
extern s32 D_0028E6E8;

extern void func_001AE9A0(s32 *, s32);

void func_001A97F0(void) {
    reg_a0_as_s32 -= 4;
    reg_a1_as_s32_p = &D_0028E6E8;
    *reg_a1_as_s32_p = reg_d0.w;
    reg_d2.sh[0] = 0;
    func_001AE9A0(reg_a1_as_s32_p, reg_a0_as_s32);
}
