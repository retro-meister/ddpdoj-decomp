#include "common.h"

extern u16 D_0028E154;
extern u32 D_0028E468;
extern s32 D_002A45B0[];

void func_0019D740(void) {
    u32 offset = D_0028E154;

    D_0028E468 = (u32)D_002A45B0;
    D_0028E468 += offset;
    D_0028E154 = offset + 0xC;
}
