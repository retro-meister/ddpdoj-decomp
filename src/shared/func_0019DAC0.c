#include "common.h"

extern u16 D_0028E134;
extern u8 *reg_a0;
extern u8 D_002A3DD0[];

void func_0019DAC0(void) {
    u32 offset;

    reg_a0 = D_002A3DD0;
    offset = D_0028E134;
    reg_a0 += offset;
    D_0028E134 = offset + 0xC;
}
