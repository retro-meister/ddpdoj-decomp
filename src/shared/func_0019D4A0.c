#include "common.h"

extern u16 D_0028E168;
extern u8 *reg_a0;
extern u8 D_002A5DC0[];

void func_0019D4A0(void) {
    u8 *base;
    s32 step;

    base = D_002A5DC0;
    reg_a0 = base;
    step = D_0028E168;
    reg_a0 += step;
    D_0028E168 = step + 0xC;
}
