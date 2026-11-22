#include "common.h"

extern s16 D_002BAF3A[];
extern s16 D_002BAFAA[];
extern u32 reg_a0;

void func_001AB860(void)
{
    u32 saved_d0 = reg_d0.w;
    u32 saved_a0 = reg_a0;

    reg_a0 = (u32)D_002BAFAA;
    reg_d0.w = 8;

    do {
        *(s16 *)reg_a0 = 1;
        reg_a0 += 10;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_d0.w = saved_d0;
    D_002BAF3A[0] = 1;
    reg_a0 = saved_a0;
}
