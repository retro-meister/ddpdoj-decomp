#include "common.h"

extern s8 rng_signed_word_values[256];

void func_00201130(void)
{
    ++*(u8 *)&rng_cursor;
    work_reg_0.h[0] = rng_cursor;
    work_reg_0.h[0] = rng_signed_word_values[work_reg_0.h[0]];
}
