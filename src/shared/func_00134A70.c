#include "common.h"

extern u32 reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_00134A70(void)
{
    *(u16 *)(reg_a5 + 4) = 0x93C;
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0x10);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x12);
    reg_a0 = reg_tmp.w;
    reg_d0.b[0] = reg_a5[5];
    *(u8 *)reg_a0 = reg_d0.b[0];
}
