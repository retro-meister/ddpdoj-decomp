#include "common.h"

extern s16 D_0028DE80_as_s16_a4[4];
extern s16 D_002BDA80_as_s16_a[];
extern s16 *reg_a6_as_s16_p;

void func_00200A10(void)
{
    reg_a6_as_s16_p = D_002BDA80_as_s16_a;
    reg_d7.w = 0x31;

    do {
        *reg_a6_as_s16_p = 0;
        reg_a6_as_s16_p += 0x10;
    } while ((s16)(--reg_d7.h[0]) >= 0);

    D_0028DE80_as_s16_a4[0] = 0;
    D_0028DE80_as_s16_a4[2] = 0x20;
    D_0028DE80_as_s16_a4[1] = 0;
}
