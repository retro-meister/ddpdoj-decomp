#include "common.h"

s32 func_0019C530();
extern u8 *reg_a6;

void func_001FABA0(void) {
    u16 temp_a0;
    u16 temp_a1;

    reg_d2.w = 0x1E7F;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xF2000000;
    reg_d4.w = 0;
    reg_d1.w += 0xF000E600;
    reg_d3.h[0] = 0x10D0;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
    func_0019C530();
    reg_d2.w = 0x1E7C;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xEA00E600;
    reg_d3.h[0] = 0x16D0;
    reg_d4.w = 0;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
    func_0019C530();
}
