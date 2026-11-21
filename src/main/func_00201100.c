#include "common.h"

extern Reg32 work_reg_5;

void func_00201100(void)
{
    ++*(u8 *)&rng_cursor;
    work_reg_5.h[0] = rng_cursor;
    work_reg_5.b[0] = rng_values[work_reg_5.h[0]];
}
