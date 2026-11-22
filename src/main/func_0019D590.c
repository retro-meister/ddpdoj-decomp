#include "common.h"

extern u16 D_0028E16C;
extern u8 *reg_a0;
extern u8 D_002A5DF0[];

void func_0019D590(void) {
    u8 *base;
    s32 step;

    base = D_002A5DF0;
    reg_a0 = base;
    step = D_0028E16C;
    reg_a0 += step;
    D_0028E16C = step + 0xC;
}
