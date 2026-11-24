#include "common.h"

extern u16 D_0028E148;
extern u8 *reg_a0;
extern u8 D_002A3CB0[];

void func_0019D880(void) {
    u32 temp;

    reg_a0 = D_002A3CB0;
    temp = D_0028E148;
    reg_a0 += temp;
    D_0028E148 = temp + 0xC;
}
