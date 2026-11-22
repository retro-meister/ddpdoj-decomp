#include "common.h"

extern u16 D_0028E16C;
extern u32 D_0028E468;
extern u8 D_002A5DF0[];

void func_0019D590(void) {
    u32 pos = D_0028E16C;

    D_0028E468 = (u32)D_002A5DF0;
    D_0028E468 += pos;
    D_0028E16C = pos + 0xC;
}
