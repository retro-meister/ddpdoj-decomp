#include "common.h"

s32 func_0019C670();
s32 func_00201E20();
extern u8 *reg_a6;

void func_001F04A0(void) {
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1B);
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x1A);
    func_00201E20();
    *(u16 *)(reg_a6 + 0x1FA) = reg_d2.h[0];
    *(u8 *)(reg_a6 + 0x1A) += 2;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] += reg_d2.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.w += 0xFC000000;
    reg_d1.w += 0xE000DC00;
    reg_d2.w = 0x1E50;
    reg_d3.h[0] = 0x2120;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0xE6);
    func_0019C670();
}
