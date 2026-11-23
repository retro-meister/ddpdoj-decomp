#include "common.h"

s32 func_0019C570();
extern u8 D_00266090[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001FC7F0(void) {
    u32 temp_a0;

    if ((*(u8 *)((u8 *)(reg_a5) + (0x1D))) & 4) {
        reg_a0 = (u8 *)D_00266090;
        reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x26)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (4)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (6)));
        reg_d1.w += reg_tmp.w;
        if ((*(u16 *)((u8 *)(reg_a5) + (0x1A))) != 0) {
            reg_d1.h[0] += 0x7FFF + 0x7D81;
        } else {
            reg_d1.h[0] += 0x280;
        }
        temp_a0 = reg_d1.w;
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0xC)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0xE)));
        reg_d1.w = temp_a0 + reg_tmp.w;
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (8)));
        reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
        func_0019C570();
    }
}
