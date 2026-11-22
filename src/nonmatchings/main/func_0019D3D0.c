#include "common.h"

extern u16 D_0028E164;
extern u8 *D_0028E468;
extern u8 D_002A5D00[];

void func_0019D3D0(void) {
    u32 offset = D_0028E164;

    D_0028E468 = D_002A5D00;
    D_0028E468 = D_0028E468 + offset;
    D_0028E164 = offset + 0xC;
}
