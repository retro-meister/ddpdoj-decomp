#include "common.h"

extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0014E2C0(void)
{
    do {
        reg_a6[1] = *(u8 *)&reg_d0;
        reg_a6 += 0x20;
    } while ((s16)(--reg_d1.h[0]) >= 0);

    *(u16 *)reg_a5 = 0;
}
