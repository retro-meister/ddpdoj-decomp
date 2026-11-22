#include "common.h"

extern u16 D_0028E168;
extern u8 *D_0028E468;
extern u8 D_002A5DC0[];

void func_0019D4A0(void) {
    u32 step = D_0028E168;

    D_0028E468 = D_002A5DC0;
    D_0028E468 += step;
    D_0028E168 = step + 0xC;
}
