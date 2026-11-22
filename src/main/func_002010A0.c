#include "common.h"

void func_002010A0(void)
{
    ++*(unsigned char *)&rng_cursor;
    reg_d0.h[0] = rng_cursor;
    reg_d0.b[0] = rng_values[reg_d0.h[0]];
}
