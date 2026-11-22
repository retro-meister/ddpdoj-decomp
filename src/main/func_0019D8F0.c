#include "common.h"

extern u16 D_0028E128;
extern u8 *D_0028E468;
extern u8 D_002A3C80[];
void func_0019D8F0(void) {
    u8 *base;
    s32 step;

    base = D_002A3C80;
    D_0028E468 = base;
    step = D_0028E128;
    D_0028E468 += step;
    D_0028E128 = step + 0xC;
}
