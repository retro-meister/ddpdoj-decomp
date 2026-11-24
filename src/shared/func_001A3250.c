#include "common.h"

s32 func_001A2F20();
extern s16 D_0028E0BC;
extern u8 D_0029F4B0[];
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_001A3250(void) {
    u32 save_d0;
    u32 save_d1;
    u8 *save_a0;
    u8 *save_a1;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    reg_a1 = (u8 *)D_0029F4B0;
    reg_d0.h[0] <<= 6;
    reg_a1 += reg_d0.h[0];
    do {
        reg_d0.w = 0xF;
        func_001A2F20();
    } while ((s16)(--reg_d1.h[0]) >= 0);
    reg_d0.w = save_d0;
    D_0028E0BC = 1;
    reg_d1.w = save_d1;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
}
