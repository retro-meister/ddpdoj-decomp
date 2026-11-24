#include "common.h"

extern s16 D_002668D0[];
extern s16 D_002668D2[];
extern s16 D_0028E4A6_as_s16;

void func_00201330(void)
{
    s32 table_index;

    *(u8 *)&rng_cursor += 1;
    reg_d1.w = rng_cursor & 0x3F;
    reg_d1.h[0] *= 2;
    table_index = reg_d1.h[0];
    D_0028E4A6_as_s16 = D_002668D0[table_index];
    reg_d1.h[0] = (u16)D_002668D2[table_index];
}
