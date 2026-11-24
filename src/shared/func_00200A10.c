#include "common.h"

extern s16 D_0028DE80[4];
extern s16 D_002BDA80[];
extern s16 *reg_a6;

void func_00200A10(void)
{
    reg_a6 = D_002BDA80;
    reg_d7.w = 0x31;

    do {
        *reg_a6 = 0;
        reg_a6 += 0x10;
    } while ((s16)(--reg_d7.h[0]) >= 0);

    D_0028DE80[0] = 0;
    D_0028DE80[2] = 0x20;
    D_0028DE80[1] = 0;
}
