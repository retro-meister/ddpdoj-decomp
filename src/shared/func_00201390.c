#include "common.h"

extern s16 D_002667D0[];
extern s16 D_002667D2[];
extern s16 D_0028E49A_as_s16;

void func_00201390(void)
{
    u16 table_index;

    *(u8 *)&rng_cursor += 1;
    reg_d4.w = rng_cursor & 0x3F;
    reg_d4.h[0] <<= 1;
    table_index = reg_d4.h[0];
    D_0028E49A_as_s16 = D_002667D0[table_index];
    reg_d4.h[0] = (u16)D_002667D2[table_index];
}
