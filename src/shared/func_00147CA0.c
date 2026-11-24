#include "common.h"

s32 func_001478A0();
extern u8 D_00256130[];
extern u8 D_0028DFD4_as_u8;
extern u8 D_0028DFD8_as_u8;
extern u8 D_0029D750[];
extern u8 D_0029D770[];
extern u8 D_0029DD30[];
extern u8 D_0029E330[];
extern u8 D_0029F1F0_as_u8_a[];
extern u8 D_0029F260_as_u8_a[];
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00147CA0(void) {
    u8 *temp_a3;
    u16 temp_a2;
    u16 temp_a2_2;
    u16 var_a0;
    temp_a3 = (u8 *)(reg_a4);
    (*(u8 *)((u8 *)(temp_a3) + (1))) |= 0x20;
    reg_a2 = (u8 *)D_0029D770;
    reg_a3 = (u8 *)D_0029E330;
    reg_a4 = &D_0028DFD8_as_u8;
    reg_a5 = (u8 *)D_0029F260_as_u8_a;
    if ((*(u16 *)((u8 *)(reg_a6) + (0x1A))) == 0) {
        reg_a2 = (u8 *)D_0029D750;
        reg_a3 = (u8 *)D_0029DD30;
        reg_a4 = &D_0028DFD4_as_u8;
        reg_a5 = (u8 *)D_0029F1F0_as_u8_a;
    }
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x2C)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2E)));
    reg_a1 = (u8 *)(reg_tmp.w);
    (*(u16 *)((u8 *)(reg_a2) + (0))) = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a5) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (4)));
    temp_a2 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[1] = temp_a2;
    temp_a2_2 = *(u16 *)reg_a1;
    reg_tmp.h[0] = temp_a2_2;
    reg_a1 += 2;
    reg_d1.w += reg_tmp.w;
    (*(u16 *)((u8 *)(reg_a2) + (2))) = (u16) reg_d1.h[1];
    (*(u16 *)((u8 *)(reg_a2) + (4))) = (u16) reg_d1.h[0];
    (*(u16 *)((u8 *)(reg_a2) + (6))) = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    (*(u16 *)((u8 *)(reg_a2) + (8))) = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    (*(u16 *)((u8 *)(reg_a2) + (0xA))) = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    var_a0 = *(u16 *)reg_a1;
    (*(u16 *)((u8 *)(reg_a2) + (0xC))) = var_a0;
    reg_a1 = (u8 *)((u32) D_00256130);
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x22)));
    if ((*(u8 *)((u8 *)(reg_a5) + (0))) & 1) {
        reg_d0.h[0] += 0x3C;
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x58)));
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x5A)));
        reg_d3.h[0] -= 2;
    } else {
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x5A)));
        reg_d3.h[0] -= 2;
        reg_d1.h[0] = reg_d3.h[0];
        reg_d1.h[0] *= 5;
        reg_d0.h[0] += reg_d1.h[0];
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x58)));
        if (reg_d2.h[0] != 0) {
            reg_d0.h[0] += 0x1E;
        }
    }
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    (*(u16 *)((u8 *)(reg_a2) + (0xE))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a2) + (0x18))) = (u16) reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a2) + (0x1A))) = (u16) reg_d3.h[0];
    (*(u16 *)((u8 *)(reg_a2) + (0x1C))) = (u16) reg_d0.h[0];
    func_001478A0();
}
