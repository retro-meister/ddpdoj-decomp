#include "common.h"

extern s8 D_00266AD0[];

void func_002012B0(void)
{
    *(u8 *)&rng_cursor += 1;
    reg_d1.w = rng_cursor & 0x3F;
    reg_d1.b[0] = D_00266AD0[reg_d1.h[0]];
}
