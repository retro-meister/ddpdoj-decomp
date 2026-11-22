#include "common.h"

extern s8 D_00266B10[];

void func_00201230(void)
{
    *(u8 *)&rng_cursor += 1;
    reg_d0.w = rng_cursor & 0x7F;
    reg_d0.b[0] = D_00266B10[reg_d0.h[0]];
}
