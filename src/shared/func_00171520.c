#include "common.h"

extern u16 *reg_a0_as_u16_p;
extern u16 *reg_a1_as_u16_p;
extern u16 *reg_a4_as_u16_p;

void func_00171520(void) {
    reg_a1_as_u16_p = reg_a4_as_u16_p;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}
