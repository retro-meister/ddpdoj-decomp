#include "common.h"
s32 func_0019C670();
extern u8 D_0026D3C0[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001D16D0(void) {
    reg_a0 = (u8 *)D_0026D3C0;
    reg_a0 += *(u16 *) (reg_a6 + 0xA8);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0xA8);
    reg_d2.w = *(u32 *) (D_0026D3C0 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = *(u16 *) (reg_a6 + 2);
    reg_d1.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.w += 0xF6400000;
    reg_d1.w += 0xF600F400;
    reg_d3.h[0] = 0xA60;
    reg_d4.w = 0;
    reg_d4.b[0] = reg_a6[0x66];
    func_0019C670();
}
