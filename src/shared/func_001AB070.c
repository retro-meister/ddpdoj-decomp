#include "common.h"

extern u8 D_0028E708;
extern u16 D_0028E738;
extern u32 D_0028E740;
extern u16 D_0028E748;
extern u16 D_0028E758;
extern u32 D_0028E764;
extern u8 D_002B5F28[];
extern u8 D_002B6828[];
extern u16 D_002BAF3A[];
extern u16 D_002BAFAA[];
extern u8 *reg_a0;

void func_001AB070(void) {
    reg_d0.w = 0;
    reg_d2.w = 0;
    reg_d1.w = (u32) D_002B5F28;
    reg_d3.w = 0;
    reg_a0 = (u8 *)(D_002BAFAA);
    reg_d7.w = 8;
    do {
        *(u16 *)reg_a0 = reg_d0.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[1];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d2.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d3.h[0];
        reg_a0 += 2;
        reg_d1.w += 0x100;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_a0 = (u8 *)(D_002BAF3A);
    *(u16 *)reg_a0 = 1;
    reg_tmp.w = (u32) D_002B6828;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = 0xC030;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_d0.w = 0;
    D_0028E764 = reg_d0.w;
    D_0028E740 = reg_d0.w;
    reg_a0 += 2;
    D_0028E758 = reg_d0.h[0];
    D_0028E708 = reg_d0.b[0];
    D_0028E738 = reg_d0.h[0];
    D_0028E748 = reg_d0.h[0];
}
