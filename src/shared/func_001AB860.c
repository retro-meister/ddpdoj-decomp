#include "common.h"

extern s16 D_002BAF3A_as_s16_a[];
extern s16 D_002BAFAA_as_s16_a[];
extern u32 reg_a0_as_u32;

void func_001AB860(void)
{
    u32 saved_d0 = reg_d0.w;
    u32 saved_a0 = reg_a0_as_u32;

    reg_a0_as_u32 = (u32)D_002BAFAA_as_s16_a;
    reg_d0.w = 8;

    do {
        *(s16 *)reg_a0_as_u32 = 1;
        reg_a0_as_u32 += 10;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_d0.w = saved_d0;
    D_002BAF3A_as_s16_a[0] = 1;
    reg_a0_as_u32 = saved_a0;
}
