#include "common.h"

extern u16 D_0028E17C;
extern u8 *reg_a0;
extern u8 D_002A6630[];

void func_0019D330(void) {
    u8 *base;
    s32 step;

    base = D_002A6630;
    reg_a0 = base;
    step = D_0028E17C;
    reg_a0 += step;
    D_0028E17C = step + 0xC;
}
