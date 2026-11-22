#include "common.h"

extern s8 rng_masked_values[128];

void func_00201160(void)
{
    ++*(u8 *)&rng_cursor;
    reg_d0.w = rng_cursor & 0x7F;
    reg_d0.b[0] = rng_masked_values[reg_d0.h[0]];
}
