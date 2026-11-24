#include "common.h"

extern u16 D_0028E188;
extern u8 *reg_a0;
extern u8 D_002A68E0[];

void func_0019D260(void) {
    u8 *base;
    s32 step;

    base = D_002A68E0;
    reg_a0 = base;
    step = D_0028E188;
    reg_a0 += step;
    D_0028E188 = step + 0xC;
}
