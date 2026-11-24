#include "common.h"

#pragma opt_propagation off

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
    u8 *a0;
    u8 *a1;
    u8 *a2;
    u8 *a3;
    u8 *a4;
    u8 *a5;
    u8 *a6;
    u32 d0;
    u32 d1;
    u32 d2;
    u32 d3;
    u32 d4;
    u32 d5;
    u32 d6;
    u32 d7;

    D_0028E054 = 0x101;
    D_0028E050 = 0x101;
    d0 = reg_d0.w;
    d1 = reg_d1.w;
    d2 = reg_d2.w;
    d3 = reg_d3.w;
    d4 = reg_d4.w;
    d5 = reg_d5.w;
    d6 = reg_d6.w;
    d7 = reg_d7.w;
    a0 = reg_a0;
    a1 = reg_a1;
    a2 = reg_a2;
    a3 = reg_a3;
    a4 = reg_a4;
    a5 = reg_a5;
    a6 = reg_a6;
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
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_d3.w = d3;
    reg_d4.w = d4;
    reg_d5.w = d5;
    reg_d6.w = d6;
    reg_d7.w = d7;
    reg_a0 = a0;
    reg_a1 = a1;
    reg_a2 = a2;
    reg_a3 = a3;
    reg_a4 = a4;
    reg_a5 = a5;
    reg_a6 = a6;
}
