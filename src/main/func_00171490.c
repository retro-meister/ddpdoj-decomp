#include "common.h"

extern u16 *reg_a0;
extern u16 *reg_a1;
extern u16 *reg_a6;

void func_00171490(void) {
    reg_a1 = reg_a6;
    reg_d0.h[0] = 0xF;
    do {
        *reg_a1 = *reg_a0;
        reg_a0 += 1;
        reg_a1 += 1;
        *reg_a1 = *reg_a0;
        reg_a0 += 1;
        reg_a1 += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}
