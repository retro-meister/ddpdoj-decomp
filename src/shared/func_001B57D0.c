#include "common.h"

s32 func_001292C0();
extern u16 D_0028E910;
extern u8 *reg_a4;

void func_001B57D0(void) {
    u32 tmp;

    reg_d0.h[0] = *(u16 *) (reg_a4 + 0x10);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d1.b[0] = reg_a4[0xD];
    if (D_0028E910 != 0) goto next_1;
    reg_d1.b[0] -= 0x14;
    reg_d5.h[0] = 0x14;
    reg_d7.h[0] = 2;
    goto loop_1;
next_1:
    reg_d1.b[0] -= 0x1E;
    reg_d5.h[0] = 0xA;
    reg_d7.h[0] = 6;
loop_1:
    func_001292C0();
    reg_d1.b[0] += reg_d5.b[0];
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
}
