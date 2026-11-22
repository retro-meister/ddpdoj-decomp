#include "common.h"

extern u16 D_0028E130;
extern u32 D_0028E468;
extern u8 D_002A3DB0[];

void func_0019DB20(void) {
    u32 old_offset;

    old_offset = D_0028E130;
    D_0028E468 = (u32)D_002A3DB0;
    D_0028E468 += old_offset;
    D_0028E130 = old_offset + 0xC;
}
