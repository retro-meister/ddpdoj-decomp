#include "common.h"

s32 func_001A2F20();
extern s16 D_0028E0C0;
extern u8 D_0029FCB0[];
extern s32 reg_a0;
extern u8 *reg_a1;

void func_001A3020(void) {
    u32 temp_s0 = reg_d0.w;
    s32 temp_s1 = reg_a0;
    u8 *temp_s2 = reg_a1;

    reg_a1 = D_0029FCB0;
    reg_d0.h[0] <<= 6;
    reg_a1 += reg_d0.h[0];
    reg_d0.w = 0xF;
    func_001A2F20();
    reg_d0.w = temp_s0;
    D_0028E0C0 = 1;
    reg_a0 = temp_s1;
    reg_a1 = temp_s2;
}
