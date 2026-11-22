#include "common.h"

extern u16 *reg_a6;
extern u16 *reg_a5;
extern u16 D_0028E8A8;

void func_0014CEE0(void) {
    reg_a5[4] = 1;
    reg_d0.h[0] = D_0028E8A8;
    reg_d0.h[0] += 4;
    reg_a6[12] = (u16) reg_d0.h[0];
}
