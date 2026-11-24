#include "common.h"

extern u8 rng_unsigned_values[256];

void func_002011A0(void)
{
    ++*(u8 *)&rng_cursor;
    reg_d0.h[0] = rng_cursor;
    reg_d0.b[0] = rng_unsigned_values[reg_d0.h[0]];
}
