#include "common.h"

extern u16 *reg_a0_as_u16_p;

void func_0013D030(void) {
    reg_d0.h[0] = 0xF;
    do {
        *reg_a0_as_u16_p = reg_d1.h[1];
        reg_a0_as_u16_p += 1;
        *reg_a0_as_u16_p = reg_d1.h[0];
        reg_a0_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}
