#include "common.h"

s32 func_0019C5B0();
extern u8 D_0026B520[];
extern u8 D_0026B550[];
extern u8 D_0028E294;
extern u32 D_0028E480;
extern u16 D_002BB348[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001A4EA0(void) {
    u16 temp_a0;

    reg_a6 = (u8 *)(D_002BB348);
    if (D_0028E294 != 0) {
        reg_d1.w = 0x62C02780;
    } else {
        reg_d1.w = 0x53C02780;
    }
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 5;
    reg_d7.w = 4;
    reg_a0 = (u8 *)D_0026B520;
    do {
        temp_a0 = *(u16 *)reg_a6;
        reg_d2.h[0] = temp_a0;
        reg_a6 += 2;
        reg_d2.h[0] &= 0xF;
        reg_d2.h[0] += reg_d2.h[0];
        reg_d2.h[0] += reg_d2.h[0];
        D_0028E480 = reg_d2.w;
        reg_d2.w = *(u32 *)(reg_a0 + (u16) D_0028E480);
        func_0019C5B0();
        reg_a0 = (u8 *)D_0026B550;
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
