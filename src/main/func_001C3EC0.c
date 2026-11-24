#include "common.h"

s32 func_0019C670();
extern u8 D_0026C2A0[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001C3EC0(void) {
    reg_a0 = (u8 *)D_0026C2A0;
    reg_a0 += *(u16 *) (reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0x28);
    reg_d2.w = *(u32 *) (D_0026C2A0 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = *(u16 *) (reg_a6 + 0x22);
    reg_d1.h[0] = *(u16 *) (reg_a6 + 0x24);
    reg_d1.h[0] += 0xFD00;
    reg_d1.w += 0xEC00F000;
    reg_d3.h[0] = 0x1480;
    reg_d4.h[0] = *(u16 *) (reg_a6 + 0x1C);
    reg_d4.b[0] = reg_a6[0x127];
    func_0019C670();
}
