#include "common.h"

extern u16 D_0028E134;
extern u8 *D_0028E468;
extern u8 D_002A3DD0[];

void func_0019DAC0(void) {
    u32 offset;

    D_0028E468 = D_002A3DD0;
    offset = D_0028E134;
    D_0028E468 += offset;
    D_0028E134 = offset + 0xC;
}
