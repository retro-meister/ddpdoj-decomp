#include "common.h"

extern u8 *reg_a2;
extern u8 *reg_a3;

void func_00206F30(void) {
    u8 *a2;
    u8 *a3;
    s32 d3;
    u32 tmp;

    d3 = reg_d3.w;
    a2 = reg_a2;
    a3 = reg_a3;
    reg_a2 += reg_d3.h[0];
    reg_a3 += reg_d3.h[0];
    reg_d3.w >>= 2;
    reg_d3.w -= 1;
loop_1:
    reg_a3 -= 4;
    reg_a2 -= 4;
    *(u16 *) (reg_a2 + 0) = *(u16 *) (reg_a3 + 0);
    *(u16 *) (reg_a2 + 2) = *(u16 *) (reg_a3 + 2);
    tmp = reg_d3.h[0] - 1;
    reg_d3.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d3.w = d3;
    reg_a2 = a2;
    reg_a3 = a3;
}
