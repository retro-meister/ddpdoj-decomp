#include "common.h"

extern s8 D_0028E408;

void func_0016D290(void);
extern u8 D_00267030[];
extern u8 D_00267050[];
extern u8 D_00267070[];
extern u8 D_00267090[];
extern Reg32 D_0028E47C_as_Reg32;
extern Reg32 D_0028E480;
extern Reg32 D_0028E484;
extern u16 D_0028E910;
extern u16 D_0028E914;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_0016D040(void) {
    D_0028E408 = 0;
    reg_d0.h[0] = D_0028E914;
    reg_a0 = (u8 *)D_00267050;
    if (D_0028E910 != 0) {
        reg_a0 = (u8 *)D_00267090;
    }
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)D_00267030;
    if (D_0028E910 != 0) {
        reg_a0 = (u8 *)D_00267070;
    }
    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = reg_a6 + 2;
    reg_d1.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d1.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[0] -= reg_d2.h[0];
    D_0028E480.h[0] = reg_d2.h[0];
    reg_d2.h[0] = reg_d2.h[1];
    reg_d2.h[1] = D_0028E480.h[0];
    reg_tmp.w = 0;
    D_0028E484.w = 0;
    reg_tmp.h[0] = reg_d2.h[0];
    D_0028E484.h[0] = reg_d1.h[0];
    D_0028E484.w += reg_tmp.w;
    reg_d1.h[0] += reg_d2.h[0];
    if (D_0028E484.h[1] == 0) {
        D_0028E484.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = D_0028E484.h[0];
        reg_d1.h[0] -= reg_d3.h[0];
        D_0028E47C_as_Reg32.h[0] = reg_d3.h[0];
        reg_d3.h[0] = reg_d3.h[1];
        reg_d3.h[1] = D_0028E47C_as_Reg32.h[0];
        reg_tmp.w = 0;
        D_0028E484.w = 0;
        reg_tmp.h[0] = reg_d3.h[0];
        D_0028E484.h[0] = reg_d1.h[0];
        D_0028E484.w += reg_tmp.w;
        reg_d1.h[0] += reg_d3.h[0];
        if (D_0028E484.h[1] == 0) {
            func_0016D290();
            return;
        }
    }
    D_0028E408 = 1;
}
