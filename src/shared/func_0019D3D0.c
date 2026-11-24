#include "common.h"

extern u16 D_0028E164;
extern u8 *reg_a0;
extern u8 D_002A5D00[];

void func_0019D3D0(void) {
    u8 *base;
    s32 step;

    base = D_002A5D00;
    reg_a0 = base;
    step = D_0028E164;
    reg_a0 += step;
    D_0028E164 = step + 0xC;
}
