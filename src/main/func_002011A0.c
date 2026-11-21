#include "common.h"

extern u8 rng_unsigned_values[256];

void func_002011A0(void)
{
    ++*(u8 *)&rng_cursor;
    work_reg_0.h[0] = rng_cursor;
    work_reg_0.b[0] = rng_unsigned_values[work_reg_0.h[0]];
}
