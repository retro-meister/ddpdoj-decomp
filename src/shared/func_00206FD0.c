#include "common.h"

extern u16 *reg_a2;
extern u16 *reg_a3;

void func_00206FD0(void) {
    u16 *temp_v1;
    u16 *temp_a0;
    u32 temp_a1;

    temp_a1 = reg_d3.w;
    temp_v1 = reg_a2;
    temp_a0 = reg_a3;
    reg_d3.w = temp_a1 >> 2;
    reg_d3.w -= 1;
    do {
        *reg_a2 = *reg_a3;
        reg_a3 += 1;
        reg_a2 += 1;
        *reg_a2 = *reg_a3;
        reg_a3 += 1;
        reg_a2 += 1;
    } while ((s16)(--reg_d3.h[0]) >= 0);
    reg_d3.w = temp_a1;
    reg_a2 = temp_v1;
    reg_a3 = temp_a0;
}
