#include "common.h"

s32 func_0019C670();
extern u8 D_0026C330[];
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_001C4090(void) {
    u16 temp_a1;
    u16 temp_a3;

    reg_a2 = (u8 *)D_0026C330;
    temp_a3 = (*(u16 *)((u8 *)(reg_a6) + (0x16A)));
    reg_a2 += temp_a3;
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x16A)));
    reg_d2.w = *(u32 *)(D_0026C330 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xF6000000;
    reg_d1.w += 0xF400ED00;
    reg_d3.h[0] = 0xC98;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x131)));
    func_0019C670();
}
