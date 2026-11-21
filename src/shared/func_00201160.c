#include "common.h"

extern s8 rng_masked_values[128];

void func_00201160(void)
{
    ++*(u8 *)&rng_cursor;
    work_reg_0.w = rng_cursor & 0x7F;
    work_reg_0.b[0] = rng_masked_values[work_reg_0.h[0]];
}
