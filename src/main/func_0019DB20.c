#include "common.h"

extern u16 D_0028E130;
extern u8 *D_0028E468;
extern u8 D_002A3DB0[];

void func_0019DB20(void) {
    u8 *base;
    s32 step;

    base = D_002A3DB0;
    D_0028E468 = base;
    step = D_0028E130;
    D_0028E468 += step;
    D_0028E130 = step + 0xC;
}
