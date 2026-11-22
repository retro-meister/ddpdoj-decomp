#include "common.h"

extern u16 reg_d5;
extern s8 D_00266B90[];

void func_00201200(void) {
    *(u8 *)&rng_cursor += 1;
    reg_d5 = rng_cursor;
    reg_d5 = (u16)D_00266B90[reg_d5];
}
