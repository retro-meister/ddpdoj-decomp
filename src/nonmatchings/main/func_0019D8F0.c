#include "common.h"

extern u16 D_0028E128;
extern u32 D_0028E468;
extern u8 D_002A3C80[];

void func_0019D8F0(void) {
    u32 count;

    count = D_0028E128;
    D_0028E468 = (u32)D_002A3C80;
    D_0028E128 = (u16)(count + 0xC);
    D_0028E468 += count;
}
