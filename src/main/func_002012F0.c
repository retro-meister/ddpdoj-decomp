#include "common.h"

extern s16 D_002669D0[];

void func_002012F0(void)
{
    *(u8 *)&rng_cursor += 1;
    reg_d0.w = rng_cursor & 0x7F;
    reg_d0.h[0] = D_002669D0[reg_d0.h[0]];
}
