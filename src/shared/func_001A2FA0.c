#include "common.h"

s32 func_001A2F20();
extern s16 D_0028E0B8;
extern u8 D_0029F2D0[];
extern s32 reg_a0;
extern u8 *reg_a1;

void func_001A2FA0(void) {
    u32 temp_s0 = reg_d0.w;
    s32 temp_s1 = reg_a0;
    u8 *temp_s2 = reg_a1;

    reg_a1 = D_0029F2D0;
    reg_d0.h[0] <<= 5;
    reg_a1 += reg_d0.h[0];
    reg_d0.w = 7;
    func_001A2F20();
    reg_d0.w = temp_s0;
    D_0028E0B8 = 1;
    reg_a0 = temp_s1;
    reg_a1 = temp_s2;
}
