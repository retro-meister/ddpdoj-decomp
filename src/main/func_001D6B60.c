#include "common.h"

s32 func_0019C530();
extern u8 D_002636B0[];
extern u8 D_002636D0[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D6B60(void) {
    u16 temp_a0;
    u16 temp_a1;

    if ((*(u8 *)((u8 *)(reg_a6) + (0x4F))) == 0) {
        reg_a0 = (u8 *)D_002636B0;
        reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x32)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
        reg_d1.h[0] = temp_a0;
        reg_d1.w += 0xF000F900;
        reg_d3.h[0] = 0x1038;
        reg_d4.w = 0;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x5B)));
        func_0019C530();
        reg_a0 = (u8 *)D_002636D0;
        reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x4A)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
        temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xF200F900;
        reg_d4.w = 0;
        reg_d1.w += 0xEBFFFE00;
        reg_d3.h[0] = 0xE38;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x5A)));
        func_0019C530();
    }
}
