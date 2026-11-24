#include "common.h"

s32 func_0019C670();
extern u8 D_0026BFA0[];
extern u32 D_0028E63C_as_u32;
extern u8 *reg_a0;

void func_001A7B30(void) {
    reg_d0.w = D_0028E63C_as_u32;
    reg_d1.w = 0x0E000C00;
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = 0x10;
    reg_a0 = (u8 *)D_0026BFA0;
    reg_d6.w = 0;
    reg_d7.w = 7;
loop_0:
    reg_tmp.w = reg_d0.w;
    reg_d0.w <<= 4;
    reg_d0.w |= reg_tmp.w >> 28;
    reg_d2.w = 0xF;
    reg_d2.h[0] &= reg_d0.h[0];
    if (reg_d2.h[0] != 0) goto next_0;
    if (reg_d7.h[0] == 0) goto next_0;
    if (reg_d6.h[0] == 0) goto next_1;
next_0:
    reg_d6.w = 1;
    reg_a0 = (u8 *)D_0026BFA0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 += reg_d2.h[0];
    reg_d2.w = *(u32 *)reg_a0;
    func_0019C670();
next_1:
    reg_d1.h[0] += 0x400;
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
}
