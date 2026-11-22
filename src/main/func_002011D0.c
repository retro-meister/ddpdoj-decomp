#include "common.h"

extern u16 rng_cursor;
extern Reg32 reg_d0;
extern s8 D_00266B90[];

void func_002011D0(void) {
    *(u8 *)&rng_cursor += 1;
    reg_d0.h[0] = rng_cursor;
    reg_d0.h[0] = D_00266B90[reg_d0.h[0]];
}
