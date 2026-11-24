#include "common.h"

s32 func_0019C670();
extern u8 D_0026C2F0[];
extern Reg32 D_0028E484;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001C3FD0(void) {
    u16 temp_a2;
    u32 temp_a3;

    reg_a0 = (u8 *)D_0026C2F0;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x166)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x166)));
    reg_d2.w = *(u32 *)(D_0026C2F0 + (reg_tmp.h[0] & ~3));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x168)));
    temp_a3 = reg_d1.w;
    D_0028E484.w = temp_a3;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = D_0028E484.h[1];
    temp_a2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a2;
    reg_d1.w += 0x04000000;
    reg_d1.w += 0xEE00ED00;
    reg_d3.h[0] = 0x1298;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x129)));
    func_0019C670();
}
