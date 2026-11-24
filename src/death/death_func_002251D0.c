#include "common.h"

void death_func_002251F0(u8 index);
extern u8 *reg_a4;
extern u8 *reg_a6;

void death_func_002251D0(u8 index) {
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 1) = reg_d0.b[0];
    *(u8 *)(reg_a4 + 0) = reg_d0.b[0];
    death_func_002251F0(index);
}
