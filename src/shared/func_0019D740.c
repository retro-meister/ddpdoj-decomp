#include "common.h"

extern u16 D_0028E154;
extern u8 *reg_a0;
extern u8 D_002A45B0[];

void func_0019D740(void) {
    u8 *base;
    s32 step;

    base = D_002A45B0;
    reg_a0 = base;
    step = D_0028E154;
    reg_a0 += step;
    D_0028E154 = step + 0xC;
}
