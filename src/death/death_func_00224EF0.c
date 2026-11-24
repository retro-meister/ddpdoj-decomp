#include "common.h"

void death_func_00224F20(u8 index);
extern u8 *reg_a4;
extern u8 *reg_a6;

void death_func_00224EF0(u8 index) {
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 1) = reg_d0.b[0];
    *(u8 *)(reg_a4 + 0) = reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x1B) = 6;
    death_func_00224F20(index);
}
