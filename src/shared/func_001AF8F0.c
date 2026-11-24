#include "common.h"

typedef void (*Fn)();

extern s8 D_0028E408;

s32 func_0018DA30();
s32 func_0018DA50();
s32 func_0019DA80();
extern u16 D_00251B20[];
extern u16 D_00251B30[];
extern u16 D_0028C128[];
extern u16 D_0028E3F0;
extern s32 D_0028E998;
extern s32 D_0028E99C;
extern u8 D_0029BF40[];
extern u8 *jtbl_0028E3F4_as_u8_p;
extern u8 *reg_a0;
extern u8 *reg_a2;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_001AF8F0(void) {
    u32 temp_a1_3;
    u32 temp_v1;
    u32 temp_a1;
    u32 temp_a1_2;

    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    reg_a0 = (u8 *)reg_tmp.w;
    jtbl_0028E3F4_as_u8_p = reg_a0;
    ((Fn)jtbl_0028E3F4_as_u8_p)();
    if (reg_d0.w & 4) {
        (*(u8 *)((u8 *)(reg_a5) + (0xF))) -= 1;
        (*(s8 *)((u8 *)(reg_a5) + (0xC))) = 1;
        func_0018DA50();
    }
    if (reg_d0.w & 8) {
        (*(u8 *)((u8 *)(reg_a5) + (0xF))) += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0xC))) = 1;
        func_0018DA50();
    }
    (*(u8 *)((u8 *)(reg_a5) + (0xF))) &= 1;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0x10)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x12)));
    reg_a0 = (u8 *)reg_tmp.w;
    (*(u8 *)((u8 *)(reg_a0) + (1))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0xF)));
    (*(u16 *)((u8 *)(reg_a5) + (0x12))) -= 1;
    if (((*(u8 *)((u8 *)(reg_a5) + (0x13))) == 0) || (reg_d0.h[0] &= 0x70, (reg_d0.h[0] != 0))) {
        func_0018DA30();
        (*(u16 *)((u8 *)(reg_a5) + (0x12))) = 0x4B0U;
        if (reg_a0 == D_0029BF40) {
            D_0028E99C = (s32) (*(u8 *)((u8 *)(reg_a0) + (1)));
        } else {
            D_0028E998 = (*(u8 *)((u8 *)(reg_a0) + (1))) + 2;
        }
        D_0028E408 = 1;
        return;
    }
    reg_d1.w = 0x5BC00000;
    if ((*(u8 *)((u8 *)(reg_a5) + (6))) != 0) {
        reg_d1.w = 0x5BC02C00;
    }
    reg_d2.w = 0x1552;
    reg_d4.w = 0;
    reg_d3.h[0] = 0x630;
    reg_d7.w = reg_d1.w;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
    func_0019DA80();
    if ((*(u8 *)((u8 *)(reg_a5) + (6))) == 0) {
        temp_a1 = reg_d1.w;
        reg_d1.w = temp_a1 + 0x04000100;
        reg_d2.w = 0x1553;
        reg_d3.h[0] = 0x410;
        reg_d4.w = 0;
        reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x16)));
        func_0019DA80();
        reg_d2.w = 0x1554;
        reg_d4.w = 0;
        reg_d3.h[0] = 0x410;
        reg_d1.w += 0x600;
        reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x18)));
        func_0019DA80();
    } else {
        temp_a1_2 = reg_d1.w;
        reg_d1.w = temp_a1_2 + 0x04000100;
        reg_d2.w = 0x1555;
        reg_d3.h[0] = 0x410;
        reg_d4.w = 0;
        reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x16)));
        func_0019DA80();
        reg_d2.w = 0x1556;
        reg_d4.w = 0;
        reg_d3.h[0] = 0x410;
        reg_d1.w += 0x600;
        reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x18)));
        func_0019DA80();
    }
    reg_d0.w = 0;
    reg_d1.w = reg_d7.w;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0xF)));
    reg_a2 = (u8 *)(D_0028C128);
    reg_d0.h[0] += reg_d0.h[0];
    temp_a1_3 = reg_d0.h[0];
    reg_a2 += temp_a1_3;
    temp_v1 = reg_d1.h[0] + *(u16 *)reg_a2;
    reg_a2 = (u8 *)(D_00251B20);
    reg_d1.h[0] = temp_v1;
    if ((*(u8 *)((u8 *)(reg_a5) + (6))) != 0) {
        reg_a2 = (u8 *)(D_00251B30);
    }
    reg_d0.h[0] = D_0028E3F0;
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    reg_d0.h[0] &= 3;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a2;
    reg_d4.w = 0;
    reg_d3.h[0] = 0x618;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
    func_0019DA80();
    reg_d0.w = 0;
    D_0028E408 = 0;
}
