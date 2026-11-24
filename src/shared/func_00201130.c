#include "common.h"

extern s8 rng_signed_word_values[256];

void func_00201130(void)
{
    ++*(u8 *)&rng_cursor;
    reg_d0.h[0] = rng_cursor;
    reg_d0.h[0] = rng_signed_word_values[reg_d0.h[0]];
}
