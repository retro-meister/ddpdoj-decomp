#include "common.h"

extern Reg32 reg_d5;

void func_00201100(void)
{
    ++*(u8 *)&rng_cursor;
    reg_d5.h[0] = rng_cursor;
    reg_d5.b[0] = rng_values[reg_d5.h[0]];
}
