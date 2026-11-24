#include "common.h"

extern s16 D_0028E050;
extern s16 D_0028E054;
extern u16 D_0028E058;
extern u16 D_0028E05A;
extern u16 D_0028E05C;
extern u16 D_0028E05E;
extern s16 D_0028E5B4;
extern s16 D_0028E5B8;
extern s16 D_0028E5E0;
extern s16 D_0028E5E4;
extern s16 D_0028E5E8;
extern s16 D_0028E5EC;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00141640(void) {
    u32 sd0;

    D_0028E054 = 0x101;
    D_0028E050 = 0x101;
    sd0 = reg_d0.w;
    *(volatile u32 *)&reg_d2.w = *(volatile u32 *)&reg_d2.w;
    *(volatile u32 *)&reg_d1.w = *(volatile u32 *)&reg_d1.w;
    *(volatile u32 *)&reg_d3.w = *(volatile u32 *)&reg_d3.w;
    *(volatile u32 *)&reg_d4.w = *(volatile u32 *)&reg_d4.w;
    *(volatile u32 *)&reg_d5.w = *(volatile u32 *)&reg_d5.w;
    *(volatile u32 *)&reg_a0 = *(volatile u32 *)&reg_a0;
    *(volatile u32 *)&reg_a1 = *(volatile u32 *)&reg_a1;
    *(volatile u32 *)&reg_d6.w = *(volatile u32 *)&reg_d6.w;
    *(volatile u32 *)&reg_a2 = *(volatile u32 *)&reg_a2;
    *(volatile u32 *)&reg_a3 = *(volatile u32 *)&reg_a3;
    *(volatile u32 *)&reg_d7.w = *(volatile u32 *)&reg_d7.w;
    *(volatile u32 *)&reg_a4 = *(volatile u32 *)&reg_a4;
    *(volatile u32 *)&reg_a5 = *(volatile u32 *)&reg_a5;
    *(volatile u32 *)&reg_a6 = *(volatile u32 *)&reg_a6;
    reg_d0.w = 0xC30;
    D_0028E05C = reg_d0.h[1];
    D_0028E05E = reg_d0.h[0];
    D_0028E5B8 = 0;
    D_0028E5E4 = 0;
    D_0028E5B4 = 0;
    D_0028E5E0 = 0;
    D_0028E5EC = 0;
    D_0028E5E8 = 0;
    reg_d0.w = 0xC30;
    D_0028E058 = reg_d0.h[1];
    D_0028E05A = reg_d0.h[0];
    reg_d0.w = sd0;
}
