#include "common.h"
s32 func_001A2F20();
extern s16 D_0028E0C0;
extern u8 D_0029FCB0[];
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_001A30A0(void) {
    s32 d0 = reg_d0.w;
    u8 *a0 = reg_a0;
    u8 *a1 = reg_a1;

    reg_a1 = (u8 *)D_0029FCB0;
    reg_d0.h[0] <<= 6;
    reg_d0.h[0] += 0x20;
    reg_a1 += reg_d0.h[0];
    reg_d0.w = 7;
    func_001A2F20();
    reg_d0.w = d0;
    D_0028E0C0 = 1;
    reg_a0 = a0;
    reg_a1 = a1;
}
