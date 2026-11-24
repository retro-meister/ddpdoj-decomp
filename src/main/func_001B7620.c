#include "common.h"

s32 func_00129280();
extern u16 D_0028E910;

void func_001B7620(void) {
    u32 tmp;

    reg_d3.w = 0;
    reg_d4.w = 0;
    if (D_0028E910 != 0) goto next_1;
    reg_d0.w = 0xFFFE0004;
    reg_d1.b[0] -= 2;
    reg_d5.h[0] = 2;
    reg_d7.h[0] = 2;
    goto loop_1;
next_1:
    reg_d0.w = 3;
    reg_d1.b[0] -= 0xC;
    reg_d5.h[0] = 4;
    reg_d7.h[0] = 6;
loop_1:
    func_00129280();
    reg_d1.b[0] += reg_d5.b[0];
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
}
