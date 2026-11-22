#include "common.h"

extern s16 D_002666D0[];
extern s16 D_002666D2[];
extern s16 D_0028E4A6;

void func_002013F0(void)
{
    u16 table_index;

    (*(u8 *)&rng_cursor)++;
    reg_d1.w = rng_cursor & 0x3F;
    reg_d1.h[0] *= 2;
    table_index = reg_d1.h[0];
    D_0028E4A6 = D_002666D0[table_index];
    reg_d1.h[0] = (u16)D_002666D2[table_index];
}
