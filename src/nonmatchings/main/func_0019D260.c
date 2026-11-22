#include "common.h"

extern u16 D_0028E188;
extern u32 D_0028E468;
extern u8 D_002A68E0[];

void func_0019D260(void) {
    u32 bufferOffset;

    bufferOffset = D_0028E188;
    D_0028E468 = (u32)D_002A68E0;
    D_0028E468 += bufferOffset;
    D_0028E188 = bufferOffset + 0xC;
}
