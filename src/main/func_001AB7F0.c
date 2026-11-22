#include "common.h"

extern s16 D_002BAF30[];
extern s16 D_002BAF50[];
extern s16 *reg_a0;

void func_001AB7F0(void)
{
    u32 saved_d0 = reg_d0.w;
    s16 *saved_a0 = reg_a0;

    reg_a0 = D_002BAF50;
    reg_d0.w = 8;

    do {
        *reg_a0 = 1;
        reg_a0 += 5;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_d0.w = saved_d0;
    D_002BAF30[0] = 1;
    reg_a0 = saved_a0;
}
