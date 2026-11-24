#include "common.h"

s32 func_001FDBD0();
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001FDAB0(void) {
    reg_d2.w = 0x1E92;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.w += 0xF7000000;
    reg_d1.w += 0xF600F900;
    reg_d3.h[0] = 0xA38;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x1C);
    func_001FDBD0();
    reg_d2.w = 0x1E91;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[1] += *(u16 *)(reg_a5 + 0x1E);
    reg_d1.w += 0x0C800000;
    reg_d1.w += 0xF200EF00;
    reg_d3.h[0] = 0xE88;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x1C);
    func_001FDBD0();
    reg_d2.w = 0x1E90;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.w += 0xF200E600;
    reg_d3.h[0] = 0xED0;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x1C);
    func_001FDBD0();
}
