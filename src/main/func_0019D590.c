#include "common.h"

extern u16 D_0028E16C;
extern u8 *D_0028E468;
extern u8 D_002A5DF0[];

void func_0019D590(void) {
    u8 *base;
    s32 step;

    base = D_002A5DF0;
    D_0028E468 = base;
    step = D_0028E16C;
    D_0028E468 += step;
    D_0028E16C = step + 0xC;
}
