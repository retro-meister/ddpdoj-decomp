#include "common.h"


void func_002010D0(void)
{
    ++*(u8 *)&rng_cursor;
    reg_d1.h[0] = rng_cursor;
    reg_d1.b[0] = rng_values[reg_d1.h[0]];
}
