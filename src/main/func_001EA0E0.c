#include "common.h"


extern u8 D_002641C0[];
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001EA0E0(void) {
    u16 temp_a2;

    reg_a2 = D_002641C0;
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.w = 0;
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_a2 += reg_d3.h[0];
    reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a2) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a2) + (2)));
    temp_a2 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.h[1] = temp_a2;
    reg_tmp.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d4.w = 0;
    reg_d3.w += reg_tmp.w;
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
}
