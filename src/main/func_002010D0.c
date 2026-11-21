#include "common.h"


void func_002010D0(void)
{
    ++*(u8 *)&rng_cursor;
    work_reg_1.h[0] = rng_cursor;
    work_reg_1.b[0] = rng_values[work_reg_1.h[0]];
}
