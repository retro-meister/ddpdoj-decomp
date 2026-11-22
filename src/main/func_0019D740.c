#include "common.h"

extern u16 D_0028E154;
extern u8 *D_0028E468;
extern u8 D_002A45B0[];

void func_0019D740(void) {
    u8 *base;
    s32 step;

    base = D_002A45B0;
    D_0028E468 = base;
    step = D_0028E154;
    D_0028E468 += step;
    D_0028E154 = step + 0xC;
}
