#include "common.h"

s32 func_00125EF0();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_00170D00();
s32 func_0018D580();
s32 func_0019BEC0();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_00201270();
extern u8 D_0028D998;
extern Reg32 D_0028E484;
extern u16 D_0028E8B8;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001C5240(void) {
    u32 t;

    if (*(s8 *)reg_a6 < 0) goto block_explos;
    func_0014EA50();
    if (enemy_move_end_requested != 0) return;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0x7000;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x1000;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d0.h[0] += 0x7000;
    if (reg_tmp.h[1] == 0) goto next_30;
    if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_40;
    func_0014E290();
    return;
next_30:
    *(u8 *)(reg_a5 + 0x17) = 1;
next_40:
    if (*(u16 *)(reg_a5 + 0x1C) == 0) goto next_45;
    if ((s32) *(u16 *)(reg_a6 + 2) < 0x3C00) goto next_43;
    if (*(s16 *)(reg_a6 + 0x18) >= 0) goto next_45;
    *(s16 *)(reg_a6 + 0x18) = 0x7FFF;
    *(u16 *)(reg_a5 + 0x18) = 0x7EFF;
    *(u16 *)(reg_a5 + 0x1E) += 1;
    *(u16 *)(reg_a5 + 0x20) = 1;
    goto next_45;
next_43:
    *(u16 *)(reg_a5 + 0x1C) = 0;
    if (*(u16 *)(reg_a5 + 0x20) == 0) goto next_44;
    *(s16 *)(reg_a6 + 0x18) = 0x400;
    *(s16 *)(reg_a5 + 0x18) = 0x300;
    goto next_45;
next_44:
    if ((s32) *(u16 *)(reg_a6 + 0x18) < 0x1000) goto next_45;
    *(s16 *)(reg_a6 + 0x18) = 0x1000;
    *(s16 *)(reg_a5 + 0x18) = 0xF00;
next_45:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] != 0) goto next_50;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
    if ((s32) *(u16 *)(reg_a6 + 0x18) >= 0x400) goto next_90;
    if (D_0028E8B8 != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    *(u8 *)(reg_a6 + 1) &= 0xA3;
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    if (reg_d0.b[0] == 0x19) {
        reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
    }
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1A);
    reg_d0.b[0] ^= reg_d2.b[0];
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x18);
    if ((s16)(reg_d2.h[0]) < 0) goto block_dead;
    if ((s32) *(u16 *)(reg_a5 + 0x18) <= (s32)(reg_d2.h[0] & 0xFFFF)) goto next_90;
    reg_d6.h[0] = *(u16 *)(reg_a5 + 0x1E);
    t = reg_d0.w;
    do {
        reg_d1.h[0] = 0x8C0;
        D_0028E484.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = D_0028E484.h[0];
        func_00201270();
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 = &D_0028D998;
        reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d0.w = 0x10;
        func_00125EF0();
    } while ((s16)(--reg_d6.h[0]) >= 0);
    reg_d0.w = t;
    *(u16 *)(reg_a5 + 0x18) -= 0x100;
next_90:
    *(u8 *)(reg_a6 + 0x1C) = (u8) reg_d0.b[0];
block_objset:
    func_0019BEC0();
    reg_a0 = reg_a6;
    func_0014D220();
    return;
block_dead:
    func_0018D580();
    reg_d0.w = 0x32;
    func_001A91A0();
    *(u16 *)reg_a6 = 0x8080;
    *(u8 *)(reg_a6 + 0x1C) = *(u8 *)(reg_a5 + 0x1B);
    reg_d0.w = 0xD;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 2;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x26) = 0xFA00;
    *(s16 *)(reg_a0 + 0x28) = 0x600;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x18) = 4;
    reg_d0.w = 0xD;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 2;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x26) = 0xFA00;
    *(u16 *)(reg_a0 + 0x28) = 0xFA00;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x18) = 2;
    reg_d0.h[0] = 0x85;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 2;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    *(s16 *)(reg_a0 + 0x28) = 0;
    *(s16 *)(reg_a0 + 0x10) = 1;
    goto block_objset;
block_explos:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x16);
    *(u8 *)(reg_a5 + 0x16) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_objset;
    func_0014E290();
}
