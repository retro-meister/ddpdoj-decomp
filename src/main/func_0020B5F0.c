#include "common.h"

extern s8 D_00251520[];
extern s8 *reg_a2;

void func_0020B5F0(void)
{
    u32 cursor = *(u8 *)&rng_cursor;

    reg_d1.w = 0x3F;
    reg_a2 = D_00251520;
    *(u8 *)&rng_cursor = cursor + 1U;
    reg_d1.h[0] &= rng_cursor;
    reg_a2 += reg_d1.h[0];
    reg_d1.b[0] = (u8)*reg_a2;
}
