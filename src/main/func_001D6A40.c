#include "common.h"

s32 func_0019C530();
extern u8 D_00263670[];
extern u8 D_00263690[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D6A40(void) {
    u16 temp_a0;
    u16 temp_a1;

    if ((*(u8 *)((u8 *)(reg_a6) + (0x2F))) == 0) {
        reg_a0 = (u8 *)D_00263670;
        reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x32)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        reg_d1.h[0] = temp_a0;
        reg_d1.w += 0xF000F900;
        reg_d3.h[0] = 0x1038;
        reg_d4.w = 0;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x3B)));
        func_0019C530();
        reg_a0 = (u8 *)D_00263690;
        reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xEC000200;
        reg_d4.w = 0;
        reg_d1.w += 0xF200F900;
        reg_d3.h[0] = 0xE38;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x3A)));
        func_0019C530();
    }
}
