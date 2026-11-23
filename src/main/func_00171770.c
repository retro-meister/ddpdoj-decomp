#include "common.h"

s32 func_0019D650();
s32 func_0019D6D0();
extern u8 *reg_a6;

void func_00171770(void) {
    func_0019D650();
    reg_d0.h[0] = 0x3800;
    reg_d0.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (8)));
    reg_d1.h[1] += (*(u16 *)((u8 *)(reg_a6) + (6)));
    reg_d1.h[1] += reg_d0.h[0];
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xE)));
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    reg_d2.w = 0x11C6;
    func_0019D6D0();
}
