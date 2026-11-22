#include "common.h"

extern u16 D_0028E614;
extern s16 D_0028E698, D_0028E69C, D_0028E6A0;
extern s32 D_0028E6A4, D_0028E6A8, D_0028E6AC;
extern s16 D_0028E6B0, D_0028E6B4, D_0028E6B8, D_0028E6BC, D_0028E6C0, D_0028E6C4, D_0028E6C8;
extern u32 D_0028E6CC;
extern s32 D_0028E6D0;

void func_001AB440(void) {
    u32 savedD0 = reg_d0.w;
    s32 zero = (u16)(reg_d0.w = 0);

    D_0028E698 = 0;
    D_0028E69C = 0;
    D_0028E6A0 = 0;
    D_0028E6A4 = zero;
    D_0028E6A8 = zero;
    D_0028E6AC = zero;
    D_0028E6B0 = 0;
    D_0028E6B4 = 0;
    D_0028E6B8 = 0;
    D_0028E6BC = 0;
    D_0028E6C0 = 0;
    D_0028E6C4 = 0;
    D_0028E6C8 = 0;
    D_0028E614 = reg_d0.h[0];
    D_0028E6CC = reg_d0.w;
    D_0028E6D0 = zero;
    reg_d0.w = savedD0;
}
