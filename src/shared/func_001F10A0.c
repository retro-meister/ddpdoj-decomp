#include "common.h"

s32 func_0019C670();
s32 func_00201E20();
extern u8 *reg_a6;

void func_001F10A0(void) {
    reg_d0.h[0] = 0x1A;
    reg_d1.w = 0;
    reg_d1.b[0] = reg_a6[0x13C];
    func_00201E20();
    reg_d1.h[0] = *(u16 *) (reg_a6 + 2);
    reg_d1.h[0] += reg_d2.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.w += 0xD8000000;
    reg_d1.w += 0xF400F900;
    reg_d2.w = 0x1DF4;
    reg_d3.h[0] = 0xC38;
    reg_d4.w = 0;
    reg_d4.b[0] = reg_a6[0xE9];
    func_0019C670();
}
