#include "common.h"

extern u16 D_0028E140;
extern u8 *reg_a0;
extern u8 D_002A3EF0[];

void func_0019DA50(void) {
    u32 offset;
    u8 *cursor;

    reg_a0 = D_002A3EF0;
    offset = D_0028E140;
    cursor = reg_a0;
    reg_a0 = cursor + offset;
    D_0028E140 = offset + 0xC;
}
