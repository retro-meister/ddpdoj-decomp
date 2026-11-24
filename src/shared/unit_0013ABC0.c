#include "common.h"

void func_001713F0(s32);

void func_0013ABC0(void) {
    func_001713F0(0);
}

s32 func_0014E300();                            /* extern */
s32 func_0014E370();                            /* extern */
extern s32 D_00253200[];
extern s32 D_0028C188;
extern s32 *reg_a0_as_s32_p;
extern u8 *reg_a6;

void func_0013ABD0(void) {
    reg_a0_as_s32_p = D_00253200;
    func_0014E370();
    reg_a0_as_s32_p = &D_0028C188;
    reg_d0.w = 1;
    func_0014E300();
    reg_tmp.w = 0x38001C00;
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[0];
}

s32 func_0013A780();
s32 func_0016A8C0();
s32 func_0016A8E0();
s32 func_0019C790();
extern u16 D_00253220[];
extern u16 D_0028C190_as_u16;
extern u16 D_0028E484_as_u16;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;

void func_0013AC30(void) {
    u32 temp_a0;
    u32 temp_a1;
    u32 temp_v1_2;

    func_0016A8E0();
    reg_d0.h[0] &= 3;
    if (reg_d0.h[0] != 0) {
        (*(u8 *)((u8 *)(reg_a5) + (0x16))) += 1;
        (*(u8 *)((u8 *)(reg_a5) + (0x16))) &= 1;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
    if ((s8) (*(u8 *)((u8 *)(reg_a5) + (0x19))) < 0) {
        (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x18)));
        reg_d6.w = 0;
        reg_d6.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x16)));
        reg_d4.h[0] = reg_d6.h[0];
        reg_d4.h[0] *= 8;
        reg_d6.h[0] += reg_d4.h[0];
        func_0016A8C0();
        reg_d0.h[0] &= 0x20;
        if (reg_d0.h[0] != 0) {
            reg_d6.h[0] |= 0x80;
        }
        reg_a1 = (u8 *)(D_00253220);
        reg_d7.w = 8;
        do {
            reg_d0.h[0] = reg_d6.h[0];
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            reg_d6.h[0] += 1;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    reg_d0.w = 0;
    reg_a0 = (u8 *)(&D_0028C190_as_u16);
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x16)));
    reg_d0.h[0] *= 4;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(D_00253220);
    reg_d7.w = 8;
    reg_a1 = (u8 *) reg_tmp.w;
    do {
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d1.h[0] += 0x7FFF + 0x7D01;
        temp_a1 = reg_d1.h[0];
        D_0028E484_as_u16 = temp_a1;
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = D_0028E484_as_u16;
        temp_a0 = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d1.h[0] = temp_a0;
        reg_d2.w = 0x2B;
        reg_d3.h[0] = 0x208;
        reg_d4.h[0] = 0;
        reg_d1.h[0] += 0x7FFF + 0x7F01;
        func_0019C790();
        reg_d1.w += 0xFC000400;
        temp_v1_2 = *(u16 *)reg_a1;
        reg_a1 += 2;
        reg_d2.h[1] = temp_v1_2;
        reg_d2.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        func_0019C790();
        reg_a0 += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
