#include "common.h"

s32 func_001A53E0();
extern u8 D_0026B730[];
extern u16 D_0028E3EC;
extern u8 *reg_a0;

void func_001A77A0(void) {
    reg_d1.h[0] += 0xFE00;
    reg_d1.h[1] = 0x4EC0;
    reg_d6.h[0] -= 0x17;
    if ((s16) reg_d6.h[0] >= 0) goto next_1;
    reg_d6.h[0] *= 0xFFFF;
    reg_a0 = (u8 *)D_0026B730;
    reg_d6.h[0] &= 0xFFFE;
    reg_d6.h[0] += reg_d6.h[0];
    reg_d2.w = *(u32 *) (reg_a0 + reg_d6.h[0]);
    goto next_2;
next_1:
    reg_d2.w = 0xD78;
    if (D_0028E3EC != 0) goto next_2;
    reg_d2.w = 0xD78;
next_2:
    reg_d3.h[0] = 0x420;
    func_001A53E0();
}
