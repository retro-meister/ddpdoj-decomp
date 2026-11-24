#include "common.h"

s32 func_0019C5B0();
extern u8 D_0026B3B0[];
extern u8 D_0028E294;
extern u16 D_002BB368[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001A4660(void) {
    u16 temp_a0;

    reg_a6 = (u8 *)(D_002BB368);
    reg_a0 = (u8 *)D_0026B3B0;
    if (D_0028E294 != 0) {
        reg_d1.w = 0x5E0009C0;
    } else {
        reg_d1.w = 0x4F0009C0;
    }
    reg_d3.h[0] = 0x220;
    reg_d4.h[0] = 8;
    reg_d7.w = 4;
    do {
        temp_a0 = *(u16 *)reg_a6;
        reg_d0.h[0] = temp_a0;
        reg_a6 += 2;
        reg_d0.h[0] -= 2;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d2.w = *(u32 *)(reg_a0 + reg_d0.h[0]);
        func_0019C5B0();
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
