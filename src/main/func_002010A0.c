#include "common.h"

void func_002010A0(void)
{
    ++*(unsigned char *)&rng_cursor;
    work_reg_0.h[0] = rng_cursor;
    work_reg_0.b[0] = rng_values[work_reg_0.h[0]];
}
