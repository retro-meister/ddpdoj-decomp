#include "common.h"

extern u16 *reg_a2_as_u16_p;
extern u16 *reg_a3_as_u16_p;

void func_00206FD0(void) {
    u16 *temp_v1;
    u16 *temp_a0;
    u32 temp_a1;

    temp_a1 = reg_d3.w;
    temp_v1 = reg_a2_as_u16_p;
    temp_a0 = reg_a3_as_u16_p;
    reg_d3.w = temp_a1 >> 2;
    reg_d3.w -= 1;
    do {
        *reg_a2_as_u16_p = *reg_a3_as_u16_p;
        reg_a3_as_u16_p += 1;
        reg_a2_as_u16_p += 1;
        *reg_a2_as_u16_p = *reg_a3_as_u16_p;
        reg_a3_as_u16_p += 1;
        reg_a2_as_u16_p += 1;
    } while ((s16)(--reg_d3.h[0]) >= 0);
    reg_d3.w = temp_a1;
    reg_a2_as_u16_p = temp_v1;
    reg_a3_as_u16_p = temp_a0;
}
