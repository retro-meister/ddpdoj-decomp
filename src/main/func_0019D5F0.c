#include "common.h"

extern u16 D_0028E15C;
extern u8 *reg_a0;
extern u8 D_002A5050[];

void func_0019D5F0(void) {
    u32 offset;

    reg_a0 = D_002A5050;
    offset = D_0028E15C;
    reg_a0 += offset;
    D_0028E15C = offset + 0xC;
}
