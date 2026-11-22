#include "common.h"

extern u16 D_0028E648;
extern u16 D_0028E64C;
extern u16 D_0028E650;

void func_001AC320(void) {
    u16 halfword;

    D_0028E648 = 0xFFFF;
    work_reg_0.w = 0x17;
    halfword = work_reg_0.h[0];
    D_0028E64C = halfword;
    D_0028E650 = halfword;
}
