#include "common.h"

extern u16 D_0028E188;
extern u8 *D_0028E468;
extern u8 D_002A68E0[];

void func_0019D260(void) {
    u8 *base;
    s32 step;

    base = D_002A68E0;
    D_0028E468 = base;
    step = D_0028E188;
    D_0028E468 += step;
    D_0028E188 = step + 0xC;
}
