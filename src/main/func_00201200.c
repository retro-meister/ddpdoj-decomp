#include "common.h"

extern u16 work_reg_5;
extern s8 D_00266B90[];

void func_00201200(void) {
    *(u8 *)&rng_cursor += 1;
    work_reg_5 = rng_cursor;
    work_reg_5 = (u16)D_00266B90[work_reg_5];
}
