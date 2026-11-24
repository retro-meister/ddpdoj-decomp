#include "common.h"

extern s16 D_002BAF30_as_s16_a[];
extern s16 D_002BAF50_as_s16_a[];
extern s16 *reg_a0_as_s16_p;

void func_001AB7F0(void)
{
    u32 saved_d0 = reg_d0.w;
    s16 *saved_a0 = reg_a0_as_s16_p;

    reg_a0_as_s16_p = D_002BAF50_as_s16_a;
    reg_d0.w = 8;

    do {
        *reg_a0_as_s16_p = 1;
        reg_a0_as_s16_p += 5;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_d0.w = saved_d0;
    D_002BAF30_as_s16_a[0] = 1;
    reg_a0_as_s16_p = saved_a0;
}
