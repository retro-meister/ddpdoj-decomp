#include "common.h"

s32 func_001DC160();
s32 func_001DC170();
extern u8 D_0026EE70[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001DC290(void) {
    u16 temp_a1;
    u16 temp_a1_2;

    reg_a0 = (u8 *)D_0026EE70;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x106)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFE000000;
    reg_d1.w += 0xEC00E300;
    reg_d3.h[0] = 0x14E8;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x3C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x147)));
    func_001DC170();
    reg_d2.w = 0x1D05;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
    temp_a1_2 = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    reg_d1.h[0] = temp_a1_2;
    reg_d1.w += 0x0D000000;
    reg_d1.w += 0xF600F600;
    reg_d3.h[0] = 0xA50;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x3C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x147)));
    func_001DC160();
}
