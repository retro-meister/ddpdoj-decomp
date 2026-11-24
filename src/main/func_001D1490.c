#include "common.h"

s32 func_0019C670();
extern u8 D_0026D360[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001D1490(void) {
    reg_a0 = (u8 *)D_0026D360;
    reg_a0 += *(u16 *) (reg_a6 + 0xAA);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0xAA);
    reg_d2.w = *(u32 *) (D_0026D360 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = *(u16 *) (reg_a6 + 2);
    reg_d1.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.h[1] += 0x4C0;
    reg_d1.h[0] += 0xF600;
    reg_d1.w += 0xF000FC00;
    reg_d3.h[0] = 0x1020;
    reg_d4.w = 0;
    reg_d4.b[0] = reg_a6[0x68];
    func_0019C670();
}
