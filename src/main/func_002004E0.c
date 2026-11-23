#include "common.h"

s32 func_0019C570();
extern u8 D_002664A0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_002004E0(void) {
    u16 temp_a0;

    if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) != 0) {
        reg_d1.w = 0;
        reg_a0 = (u8 *)D_002664A0;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] *= 8;
        reg_a0 += reg_d1.h[0];
        reg_a1 = reg_a0;
        reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.h[0] = temp_a0;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0xC)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (0xE)));
        reg_d4.w += reg_tmp.w;
        func_0019C570();
    }
}
