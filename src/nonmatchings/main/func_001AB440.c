#include "common.h"

extern u16 D_0028E614;
extern s16 D_0028E698;
extern s16 D_0028E69C;
extern s16 D_0028E6A0;
extern s32 D_0028E6A4;
extern s32 D_0028E6A8;
extern s32 D_0028E6AC;
extern s16 D_0028E6B0;
extern s16 D_0028E6B4;
extern s16 D_0028E6B8;
extern s16 D_0028E6BC;
extern s16 D_0028E6C0;
extern s16 D_0028E6C4;
extern s16 D_0028E6C8;
extern u32 D_0028E6CC;
extern s32 D_0028E6D0;

void func_001AB440(void)
{
    u32 savedD0 = reg_d0.w;
    u16 zero = 0;

    D_0028E6A4 = zero;
    D_0028E6A8 = zero;
    D_0028E6AC = zero;
    D_0028E6D0 = zero;
    D_0028E698 = 0;
    reg_d0.w = 0;
    D_0028E69C = 0;
    D_0028E6A0 = 0;
    D_0028E6B0 = 0;
    D_0028E6B4 = 0;
    D_0028E6B8 = 0;
    D_0028E6BC = 0;
    D_0028E6C0 = 0;
    D_0028E6C4 = 0;
    D_0028E6C8 = 0;
    D_0028E614 = reg_d0.h[0];
    D_0028E6CC = reg_d0.w;
    reg_d0.w = savedD0;
}
