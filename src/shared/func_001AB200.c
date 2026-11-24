#include "common.h"


extern u8 D_0028E70C;
extern u16 D_0028E73C;
extern u32 D_0028E744;
extern u16 D_0028E75C;
extern u32 D_0028E768;
extern u8 D_002B4E28[];
extern u16 D_002BAF30[];
extern u16 D_002BAF50[];
extern u8 *reg_a0;

void func_001AB200(void) {
    reg_d0.w = 0;
    reg_d2.w = 0;
    reg_d1.w = (u32) D_002B4E28;
    reg_d3.w = 0;
    reg_a0 = (u8 *)(D_002BAF50);
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
    reg_a0 = (u8 *)(D_002BAF30);
    *(u16 *)reg_a0 = 1;
    reg_d0.w = 0;
    D_0028E768 = reg_d0.w;
    D_0028E744 = reg_d0.w;
    reg_a0 += 2;
    D_0028E75C = reg_d0.h[0];
    D_0028E70C = reg_d0.b[0];
    D_0028E73C = reg_d0.h[0];
}
