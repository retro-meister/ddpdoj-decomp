#include "common.h"

extern s8 D_0028E408;

s32 func_00211470();
s32 func_00211F40();
extern u16 D_00299780[];
extern u8 *reg_a0;

void func_002115E0(void) {
    u32 tmp;

    func_00211470();
    reg_a0 = (u8 *) D_00299780;
loop_1:
    if (*(u16 *) reg_a0 != 0) goto next_1;
    func_00211F40();
    D_0028E408 = 0;
    return;
next_1:
    reg_a0 += 0x30;
    tmp = reg_d3.h[0] - 1;
    reg_d3.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d3.w = 0;
    D_0028E408 = 1;
    reg_d3.h[0] -= 1;
}
