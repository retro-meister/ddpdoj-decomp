#include "common.h"

s32 func_0019C5B0();
extern u8 *reg_a6;

void func_002046F0(void) {
    reg_d1.w = 0x38001C00;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xC800;
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x3E);
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xE400;
    reg_d2.w = 0xACC;
    reg_d3.h[0] = 0x38E0;
    reg_d4.h[0] = 0x15;
    func_0019C5B0();
    reg_d2.w = 0xACC;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 0x3E);
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 0x3E);
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d4.h[0] |= 0x6000;
    func_0019C5B0();
}
