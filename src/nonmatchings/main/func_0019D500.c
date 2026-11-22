#include "common.h"

extern u16 D_0028E170;
extern u8 *D_0028E468;
extern u8 D_002A60F0[];

void func_0019D500(void) {
    u8 *base;
    s32 step;

    base = D_002A60F0;
    step = D_0028E170;
    D_0028E468 = base;
    D_0028E468 += step;
    D_0028E170 = step + 0xC;
}
