#include "common.h"

extern u16 rng_cursor;
extern Reg32 work_reg_0;
extern s8 D_00266B90[];

void func_002011D0(void) {
    *(u8 *)&rng_cursor += 1;
    work_reg_0.h[0] = rng_cursor;
    work_reg_0.h[0] = D_00266B90[work_reg_0.h[0]];
}
