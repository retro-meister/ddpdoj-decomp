#include "common.h"

extern s8 D_00251560[];
extern s8 *reg_a2_as_s8_p;

void func_0020B640(void)
{
    u32 cursor = *(u8 *)&rng_cursor;
    s8 *table;
    u32 mask;

    reg_d1.w = 0x3F;
    table = D_00251560;
    mask = reg_d1.h[0];
    reg_a2_as_s8_p = table;
    *(u8 *)&rng_cursor = (u8)(cursor + 1U);
    reg_d1.h[0] = (u16)(mask & (u32)rng_cursor);
    reg_a2_as_s8_p += reg_d1.h[0];
    reg_d1.b[0] = (u8)*reg_a2_as_s8_p;
}
