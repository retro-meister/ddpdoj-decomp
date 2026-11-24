#include "common.h"

s32 func_001292C0();
s32 func_00129410();
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00166740(void) {
    u16 temp_a1;

    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d2.h[0] = temp_a1;
    reg_d3.w = reg_d7.w;
    reg_d0.w = 0x3000C;
    reg_d0.h[0] = 0xB;
    reg_d4.w = 0;
    func_00129410();
    reg_d0.h[1] += 3;
    reg_d5.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
    reg_d5.b[0] *= 2;
    reg_d1.b[0] += reg_d5.b[0];
    func_001292C0();
}
