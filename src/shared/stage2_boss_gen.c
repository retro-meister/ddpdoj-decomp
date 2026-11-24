#include "common.h"

void func_001C5160(void) {
    void func_001713F0(s32);
    func_001713F0(0);
}

extern s8 D_00262C40[];
extern s8 D_00262C50[];
extern s8 D_00262C60[];
extern u16 D_0028E910;
extern u16 D_0028E918;
extern s8 enemy_move_end_requested;
extern s8 *reg_a0_as_s8_p;

void func_001C5170(void) {
    s32 func_0014E300();
    s32 func_0014E370();
    s32 func_0014E7E0();
    reg_a0_as_s8_p = D_00262C60;
    func_0014E370();
    reg_a0_as_s8_p = D_00262C50;
    reg_d0.w = 5;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_a0_as_s8_p = D_00262C40;
        reg_d0.h[0] = D_0028E918;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        *(s8 *)(reg_a6 + 0x1C) = (s8) *reg_a0_as_s8_p;
        *(s8 *)(reg_a5 + 0x1B) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        *(s8 *)(reg_a5 + 0x1A) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        if (D_0028E910 != 0) {
            *(s16 *)(reg_a5 + 0x1E) = 0;
        }
    }
}

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
extern u16 D_0028E8B8;

void func_001C5240(void) {
    u32 t;

    if (*(s8 *)reg_a6 < 0) goto block_explos;
    func_0014EA50();
    if (enemy_move_end_requested != 0) return;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x7000;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x1000;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
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
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
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

void func_001C5730(void) {
    void func_001713F0(s32);
    func_001713F0(0);
}

s32 func_0014E300();                            /* extern */
s32 func_0014E370();                            /* extern */
s32 func_0014E7E0();                            /* extern */
extern s8 D_00262C80[];
extern s8 D_00262C90[];
extern s8 D_0028D9A0;

void func_001C5740(void) {
    reg_a0_as_s8_p = D_00262C90;
    func_0014E370();
    reg_a0_as_s8_p = &D_0028D9A0;
    reg_d0.w = 1;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_a0_as_s8_p = D_00262C80;
        reg_d0.h[0] = D_0028E918;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        *(s8 *)(reg_a6 + 0x1C) = (s8) *reg_a0_as_s8_p;
        *(s8 *)(reg_a5 + 0x19) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        *(s8 *)(reg_a5 + 0x18) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
    }
}

s32 func_00170A60();
extern u16 D_00262CB0[];

void func_001C5800(void) {
    u8 t1;

    func_0014EA50();
    if (enemy_move_end_requested != 0) return;
    {
        reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x6C00;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1200;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x6C00;
        if (reg_tmp.h[1] != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                func_0014E290();
                return;
            }
            goto next_1;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
    }
next_1:
    if (*(s8 *)reg_a6 < 0) goto block_explos;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] != 0) goto next_50;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
    if ((s32) *(u16 *)(reg_a6 + 0x18) >= 0x380) goto next_90;
    if (D_0028E8B8 != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    *(u8 *)(reg_a6 + 1) &= 0xA3;
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    if (reg_d0.b[0] == 0x19) {
        reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
    }
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
    reg_d0.b[0] ^= reg_d2.b[0];
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x18);
    if ((s16) reg_d2.h[0] < 0) goto block_dead;
next_90:
    *(u8 *)(reg_a6 + 0x1C) = (u8) reg_d0.b[0];
block_objset:
    func_00170A60();
    reg_a0 = reg_a6;
    func_0014D220();
    return;
block_dead:
    func_0018D580();
    reg_d0.w = 0x13;
    func_001A91A0();
    *(u16 *)reg_a6 = 0x8080;
    t1 = *(u8 *)(reg_a5 + 0x19);
    *(u8 *)(reg_a6 + 0x1C) = t1;
    reg_d0.w = 5;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(s16 *)(reg_a0 + 0x26) = 0xA00;
    *(s16 *)(reg_a0 + 0x28) = 0x80;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x18) = 6;
    reg_d0.w = 5;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 2;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x26) = 0xFC00;
    *(u16 *)(reg_a0 + 0x28) = 0xFF80;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s8 *)(reg_a0 + 0x1D) = 0x40;
    *(s16 *)(reg_a0 + 0x18) = 3;
    reg_d0.w = 5;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x26) = 0xEE00;
    *(s16 *)(reg_a0 + 0x28) = 0x80;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x18) = 0;
    goto block_objset;
block_explos:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x16);
    *(u8 *)(reg_a5 + 0x16) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_objset;
    reg_a4 = (u8 *)(D_00262CB0);
    reg_d0.h[0] = *(u16 *)reg_a4;
    reg_a4 += 2;
    reg_d6.h[0] = *(u16 *)reg_a4;
    reg_a4 += 2;
    do {
        reg_d1.h[1] = *(u16 *)reg_a4;
        reg_a4 += 2;
        reg_d1.h[0] = *(u16 *)reg_a4;
        reg_a4 += 2;
        func_00125EF0();
    } while ((s16)(--reg_d6.h[0]) >= 0);
    func_0014E290();
}

void func_001C5BE0(void) {
    void func_001713F0(s32);
    func_001713F0(0);
}

extern s8 D_00262CD0[];
extern s8 D_00262CE0[];
extern s8 D_0028D9A4;

void func_001C5BF0(void) {
    s32 func_0014E300();
    s32 func_0014E370();
    s32 func_0014E7E0();
    reg_a0_as_s8_p = D_00262CE0;
    func_0014E370();
    reg_a0_as_s8_p = &D_0028D9A4;
    reg_d0.w = 1;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_a0_as_s8_p = D_00262CD0;
        reg_d0.h[0] = D_0028E918;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        *(s8 *)(reg_a6 + 0x1C) = (s8) *reg_a0_as_s8_p;
        *(s8 *)(reg_a5 + 0x19) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        *(s8 *)(reg_a5 + 0x18) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        if (*(u8 *)(reg_a6 + 0x1F) != 0) {
            *(u8 *)(reg_a6 + 0x1F) = 0U;
            *(u8 *)(reg_a6 + 0x1D) |= 0x40;
        }
    }
}

s32 func_00125EC0();

void func_001C5CD0(void) {
    func_0014EA50();
    if (enemy_move_end_requested != 0) return;
    {
        reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x6800;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1400;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x6800;
        if (reg_tmp.h[1] != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                func_0014E290();
                return;
            }
            goto next_1;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
    }
next_1:
    if (*(s8 *)reg_a6 < 0) goto next_2;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] != 0) goto next_50;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
    if ((s32) *(u16 *)(reg_a6 + 0x18) >= 0x380) goto next_90;
    if (D_0028E8B8 != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    *(u8 *)(reg_a6 + 1) &= 0xA3;
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    if (reg_d0.b[0] == 0x19) {
        reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
    }
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
    reg_d0.b[0] ^= reg_d2.b[0];
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x18);
    if ((s16) reg_d2.h[0] < 0) goto next_3;
next_90:
    *(u8 *)(reg_a6 + 0x1C) = (u8) reg_d0.b[0];
next_4:
    func_00170A60();
    reg_a0 = reg_a6;
    func_0014D220();
    return;
next_3:
    func_0018D580();
    reg_d0.w = 0x14;
    func_001A91A0();
    *(u16 *)reg_a6 = 0x8080;
    *(u8 *)(reg_a6 + 0x1C) = *(u8 *)(reg_a5 + 0x19);
    reg_d0.w = 0xD;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(s16 *)(reg_a0 + 0x26) = 0;
    *(s16 *)(reg_a0 + 0x28) = 0;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x18) = 3;
    reg_d0.w = 5;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x26) = 0xF200;
    *(s16 *)(reg_a0 + 0x28) = 0x80;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x18) = 0;
    goto next_4;
next_2:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x16);
    *(u8 *)(reg_a5 + 0x16) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_4;
    reg_d0.w = 0xC;
    reg_d1.w = 0xFF00FE00;
    if (*(u8 *)(reg_a6 + 0x1D) & 0x40) {
        reg_d1.h[0] *= -1;
    }
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x1E);
    func_00125EC0();
    func_0014E290();
}

void func_001C5FF0(void) {
    void func_001713F0(s32 mode);
    func_001713F0(0);
}

s32 func_0014E300();                            /* extern */
s32 func_0014E370();                            /* extern */
s32 func_0014E7E0();                            /* extern */
extern s8 D_00262D00[];
extern s8 D_00262D10[];
extern s8 D_0028D9A8;

void func_001C6000(void) {
    reg_a0_as_s8_p = D_00262D10;
    func_0014E370();
    reg_a0_as_s8_p = &D_0028D9A8;
    reg_d0.w = 1;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_a0_as_s8_p = D_00262D00;
        reg_d0.h[0] = D_0028E918;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        *(s8 *)(reg_a6 + 0x1C) = (s8) *reg_a0_as_s8_p;
        *(s8 *)(reg_a5 + 0x19) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        *(s8 *)(reg_a5 + 0x18) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
    }
}

void func_001C60C0(void) {
    u8 *t1;

    func_0014EA50();
    if (enemy_move_end_requested != 0) return;
    {
        reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x6800;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1400;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x6800;
        if (reg_tmp.h[1] != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                func_0014E290();
                return;
            }
            goto next_1;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
    }
next_1:
    if (*(s8 *)reg_a6 < 0) goto next_2;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] != 0) goto next_50;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
    if ((s32) *(u16 *)(reg_a6 + 0x18) >= 0x380) goto next_90;
    if (D_0028E8B8 != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    *(u8 *)(reg_a6 + 1) &= 0xA3;
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    if (reg_d0.b[0] == 0x19) {
        reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
    }
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
    reg_d0.b[0] ^= reg_d2.b[0];
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x18);
    if ((s16) reg_d2.h[0] < 0) goto next_3;
next_90:
    *(u8 *)(reg_a6 + 0x1C) = (u8) reg_d0.b[0];
next_4:
    func_00170A60();
    reg_a0 = reg_a6;
    func_0014D220();
    return;
next_3:
    func_0018D580();
    reg_d0.w = 0x15;
    func_001A91A0();
    *(u16 *)reg_a6 = 0x8080;
    *(u8 *)(reg_a6 + 0x1C) = *(u8 *)(reg_a5 + 0x19);
    reg_d0.h[0] = 0x85;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(s16 *)(reg_a0 + 0x26) = 0xC00;
    *(u16 *)(reg_a0 + 0x28) = 0xFE80;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s8 *)(reg_a0 + 0x1D) = 0x40;
    *(s16 *)(reg_a0 + 0x18) = 2;
    reg_d0.w = 0xD;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 2;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x26) = 0xFA00;
    *(u16 *)(reg_a0 + 0x28) = 0xFF00;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x18) = 1;
    reg_d0.h[0] = 0x85;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
    func_00170D00();
    t1 = (u8 *)((void *)1);
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x26) = 0xEE00;
    *(s16 *)(reg_a0 + 0x28) = 0;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x18) = 0;
    goto next_4;
next_2:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x16);
    *(u8 *)(reg_a5 + 0x16) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_4;
    reg_d0.w = 0xC;
    reg_d1.w = 0xFAC0FA40;
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x1E);
    func_00125EC0();
    func_0014E290();
}

void func_001C6430(void) {
    void func_001713F0(s32 mode);
    func_001713F0(0);
}

extern u16 D_00262D30[];
extern u16 D_00262D40[];
extern u16 D_00262D60[];
extern u16 D_00262D80[];
extern u16 D_0028E8DC;
extern u16 g_stage;

void func_001C6440(void) {
    s32 func_0014E300();
    s32 func_0014E370();
    s32 func_0014E7E0();
    reg_a0 = (u8 *)(D_00262D60);
    func_0014E370();
    reg_a0 = (u8 *)(D_00262D40);
    reg_d0.w = 9;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_d0.b[0] = 6;
        if ((s32) g_stage > 1) {
            reg_d0.b[0] = 2;
        }
        *(u8 *)(reg_a5 + 0x16) = (u8) reg_d0.b[0];
        reg_d0.h[0] = D_0028E8DC;
        *(u8 *)(reg_a5 + 0x1D) -= reg_d0.b[0];
        if (*(u8 *)(reg_a6 + 0x1F) != 0) {
            *(u8 *)(reg_a6 + 0x1F) = 0U;
            *(u8 *)(reg_a6 + 0x1D) |= 0x40;
            reg_tmp.w = 0x14;
            *(u16 *)(reg_a5 + 0x24) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a5 + 0x26) = (u16) reg_tmp.h[0];
            *(s16 *)(reg_a5 + 0x28) = 0;
        }
        reg_d0.w = (u32) reg_a6;
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x24);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x26);
        reg_tmp.w += reg_d0.w;
        *(u16 *)(reg_a5 + 0x24) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a5 + 0x26) = (u16) reg_tmp.h[0];
        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
        reg_a0 = (u8 *)(D_00262D80);
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x24);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x26);
        reg_a1 = (u8 *)(reg_tmp.w);
        *(u16 *)reg_a1 = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_00262D30);
        reg_d0.h[0] = D_0028E918;
        reg_a0 += reg_d0.h[0];
        *(s8 *)(reg_a6 + 0x1C) = *(s8 *)reg_a0;
        *(s8 *)(reg_a5 + 0x1B) = *(s8 *)reg_a0;
        reg_a0 += 1;
        *(s8 *)(reg_a5 + 0x1A) = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}


s32 func_00125EB0();
s32 func_00129370();
s32 func_0016D290();
s32 func_00170DE0();
s32 func_0018D560();
s32 func_002027A0();
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u16 D_0028E8D4;
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];

void func_001C6640(void) {
    s16 *temp_v1;
    u16 temp_a0_3;
    u8 temp_v0;

    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7C00;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0xA00;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x7C00;
        if (reg_tmp.h[1] != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                func_0014E290();
                return;
            }
            goto block_5;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
block_5:
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= *(u8 *)(reg_a6 + 1);
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
            if (((s32) *(u16 *)(reg_a6 + 0x18) < 0x180) && (D_0028E8B8 == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_12;
        }
        *(u8 *)(reg_a6 + 1) &= 0xA3;
        func_001A9000();
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
        }
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1A);
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) *(u16 *)(reg_a6 + 0x18) >= 0) {
block_12:
            *(u8 *)(reg_a6 + 0x1C) = (u8) reg_d0.b[0];
            if ((D_0028E8A0 == 0) && (D_0028E89C == 0) && ((s16) *(u16 *)(reg_a6 + 2) >= 0x2C00)) {
                reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
                if (reg_d0.h[0] == 0) {
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
                    *(u8 *)(reg_a5 + 0x1D) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x1D) = 0x10U;
                        *(u16 *)(reg_a5 + 0x18) = 1U;
                    }
                } else if ((reg_d0.h[0] & 0xFFFF) == 1) {
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                    *(u8 *)(reg_a5 + 0x23) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
                        *(u16 *)(reg_a5 + 0x20) += 8;
                        if (*(u16 *)(reg_a5 + 0x20) == 0x78) {
                            *(u16 *)(reg_a5 + 0x18) = 2U;
                        }
                        goto block_38;
                    }
                } else if ((reg_d0.h[0] & 0xFFFF) == 2) {
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
                    *(u8 *)(reg_a5 + 0x1D) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x16);
                        func_0016D290();
                        if (cond_flag == 0) {
                            reg_a0 = (u8 *)(D_0029F260_as_u16_a);
                            reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
                            if (*(u8 *)(reg_a5 + 2) != 0) {
                                reg_atmp = (u8 *)(reg_a0);
                                reg_a0 = (u8 *)(reg_a1);
                                reg_a1 = (u8 *)(reg_atmp);
                            }
                            temp_v1 = (s16 *)(reg_a0);
                            if ((*(s16 *)((u8 *)(temp_v1) + (0))) >= 0) {
                                if (*(s16 *)reg_a1 < 0) {
                                    reg_a0 = (u8 *)(reg_a1);
                                    reg_atmp = (u8 *)(temp_v1);
                                    reg_a1 = (u8 *)(temp_v1);
                                    goto block_30;
                                }
                            } else {
block_30:
                                reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                                reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                                reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
                                reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
                                reg_d7.h[0] = 0x300;
                                reg_tmp7.h[0] = reg_d7.h[0];
                                reg_d0.h[0] += reg_d7.h[0];
                                reg_d7.h[0] = reg_d7.h[1];
                                reg_d7.h[1] = reg_tmp7.h[0];
                                reg_d7.h[0] = *(u16 *)(reg_a5 + 0x28);
                                reg_d1.h[0] += reg_d7.h[0];
                                func_002027A0();
                                reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
                                temp_a0_3 = *(u16 *)(reg_a6 + 4);
                                reg_d2.h[0] = temp_a0_3;
                                reg_d3.w = reg_d7.w;
                                reg_d4.w = (u32) reg_a6;
                                reg_d0.w = 0x1000C;
                                func_00129370();
                            }
                            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                            *(u8 *)(reg_a5 + 0x1F) -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
                                *(u8 *)(reg_a5 + 0x1D) = 0x10U;
                                *(u16 *)(reg_a5 + 0x18) = 3U;
                            }
                        }
                    }
                } else {
                    temp_v0 = *(u8 *)(reg_a5 + 0x1D);
                    if (temp_v0 != 0) {
                        *(u8 *)(reg_a5 + 0x1D) = (u8) (temp_v0 - 1);
                    } else {
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                        *(u8 *)(reg_a5 + 0x23) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
                            *(u16 *)(reg_a5 + 0x20) -= 8;
                            if (*(u16 *)(reg_a5 + 0x20) == 0) {
                                reg_d0.h[0] = 0x40;
                                reg_d0.h[0] -= D_0028E8D4;
                                *(u8 *)(reg_a5 + 0x1D) = (u8) reg_d0.b[0];
                                *(u16 *)(reg_a5 + 0x18) = 0U;
                            }
block_38:
                            reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
                            reg_a0 = (u8 *)(D_00262D80);
                            reg_a0 += reg_d0.h[0];
                            *(u16 *)(reg_a6 + 0xA) = *(u16 *)reg_a0;
                            reg_a0 += 2;
                            *(u16 *)(reg_a6 + 0xC) = *(u16 *)reg_a0;
                            reg_a0 += 2;
                            reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x24);
                            reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x26);
                            reg_a1 = (u8 *) reg_tmp.w;
                            *(s16 *)reg_a1 = (s16) *(u16 *)reg_a0;
                            reg_a0 += 2;
                        }
                    }
                }
            }
            func_00170A60();
            reg_a0 = (u8 *)(reg_a6);
            func_0014D220();
            return;
        }
        func_0018D560();
        reg_d0.w = 0x34;
        func_001A91A0();
        reg_d0.w = 8;
        func_00170DE0();
        func_00125EB0();
        reg_d0.w = 0xC;
        func_0013A780();
        *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
        *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
        func_00170D00();
        *(s16 *)(reg_a0 + 0x12) = 1;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(u16 *)(reg_a0 + 0x26) = 0xFD00;
        *(s16 *)(reg_a0 + 0x28) = 0;
        *(s16 *)(reg_a0 + 0x10) = 1;
        func_0014E290();
    }
}

void func_001C6C00(void) {
    void func_001713F0(s32 mode);
    func_001713F0(0);
}

extern s8 D_00262E00[];
extern s8 D_00262E10[];
extern s8 D_00262E30[];
extern u16 D_0028E8C8;

void func_001C6C10(void) {
    s32 func_0014E300();
    s32 func_0014E370();
    s32 func_0014E7E0();
    reg_a0_as_s8_p = D_00262E30;
    func_0014E370();
    reg_a0_as_s8_p = D_00262E10;
    reg_d0.w = 0xB;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_d0.b[0] = 6;
        if ((s32) g_stage > 0x1) {
            reg_d0.b[0] = 2;
        }
        *(u8 *)(reg_a5 + 0x16) = (u8) reg_d0.b[0];
        reg_d0.h[0] = D_0028E8C8;
        *(u8 *)(reg_a5 + 0x1C) -= reg_d0.b[0];
        reg_a0_as_s8_p = D_00262E00;
        reg_d0.h[0] = D_0028E918;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        *(s8 *)(reg_a6 + 0x1C) = (s8) *reg_a0_as_s8_p;
        *(s8 *)(reg_a5 + 0x1B) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        *(s8 *)(reg_a5 + 0x1A) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
    }
}

s32 func_00129410();
s32 func_00171400();
s32 func_00201710();
extern u16 D_00259970[];
extern u16 D_00262E50[];
extern u16 D_0028E8CC;
extern s16 D_0029CEA0_as_s16_a[];

void func_001C6D10(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 *temp_v1;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    u16 temp_v0_6;
    u8 temp_a0;
    u8 temp_v0_5;

    var_a0 = arg0;
    var_a1 = arg1;
    var_a2 = arg2;
    var_a3 = arg3;
    if (*(s8 *)reg_a6 >= 0) {
        func_0014EA50();
        if (enemy_move_end_requested == 0) {
            reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
            reg_tmp1.w = 0;
            reg_tmp1.h[0] = 0x6000;
            reg_tmp.w = 0;
            reg_d0.h[0] += 0x1800;
            reg_tmp.h[0] = reg_d0.h[0];
            reg_tmp.w += reg_tmp1.w;
            reg_d0.h[0] += 0x6000;
            if (reg_tmp.h[1] != 0) {
                if (*(u8 *)(reg_a5 + 0x17) != 0) {
                    func_0014E290();
                    return;
                }
                goto block_6;
            }
            *(u8 *)(reg_a5 + 0x17) = 1U;
block_6:
            if (*(s16 *)(reg_a5 + 0x24) >= 0) {
                *(u16 *)(reg_a6 + 0x18) = 0x7FFFU;
                reg_d0.w = 1;
                if (D_0029CEA0_as_s16_a[0] < 0) {
                    reg_d0.w = 2;
                }
                *(u16 *)(reg_a5 + 0x24) -= reg_d0.h[0];
                if (*(s16 *)(reg_a5 + 0x24) < 0) {
                    *(u16 *)(reg_a6 + 0x18) = 0x600U;
                }
            }
            reg_d1.w = 0x5C;
            reg_d1.b[0] &= *(u8 *)(reg_a6 + 1);
            if (reg_d1.b[0] == 0) {
                reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
                if (((s32) *(u16 *)(reg_a6 + 0x18) < 0x180) && (D_0028E8B8 == 0)) {
                    reg_d0.w = 0x19;
                }
                goto block_18;
            }
            *(u8 *)(reg_a6 + 1) &= 0xA3;
            func_001A9000();
            reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
            if (reg_d0.b[0] == 0x19) {
                reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
            }
            reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1A);
            reg_d0.b[0] ^= reg_d2.b[0];
            if ((s16) *(u16 *)(reg_a6 + 0x18) >= 0) {
block_18:
                *(u8 *)(reg_a6 + 0x1C) = (u8) reg_d0.b[0];
                if (D_0028E8A0 == 0) {
                    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
                    if (reg_d0.h[0] == 0) {
                        if ((s16) *(u16 *)(reg_a6 + 2) >= 0x1000) {
                            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
                            *(u8 *)(reg_a5 + 0x1D) -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                reg_d0.h[0] = 0x10;
                                reg_d0.h[0] -= D_0028E8C8;
                                reg_d0.h[0] += 8;
                                *(u8 *)(reg_a5 + 0x1D) = (u8) reg_d0.b[0];
                                *(u16 *)(reg_a5 + 0x18) = 1U;
                            }
                        }
                    } else if ((reg_d0.h[0] & 0xFFFF) == 1) {
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                        *(u8 *)(reg_a5 + 0x23) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
                            *(u16 *)(reg_a5 + 0x20) += 8;
                            reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x20);
                            if (*(u16 *)(reg_a5 + 0x20) == 0x78) {
                                *(u16 *)(reg_a5 + 0x18) = 2U;
                            }
                            goto block_60;
                        }
                    } else if ((reg_d0.h[0] & 0xFFFF) == 2) {
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
                        *(u8 *)(reg_a5 + 0x1D) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x16);
                            if ((s16) *(u16 *)(reg_a6 + 2) >= 0x1000) {
                                reg_a0 = (u8 *)(D_0029F260_as_u16_a);
                                reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
                                if (*(u8 *)(reg_a5 + 2) != 0) {
                                    reg_atmp = (u8 *)(reg_a0);
                                    reg_a0 = (u8 *)(reg_a1);
                                    reg_a1 = (u8 *)(reg_atmp);
                                }
                                temp_v1 = (s16 *)(reg_a0);
                                if ((*(s16 *)((u8 *)(temp_v1) + (0))) >= 0) {
                                    if (*(s16 *)reg_a1 < 0) {
                                        reg_a0 = (u8 *)(reg_a1);
                                        reg_atmp = (u8 *)(temp_v1);
                                        reg_a1 = (u8 *)(temp_v1);
                                        goto block_35;
                                    }
                                } else {
block_35:
                                    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                                    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                                    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
                                    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
                                    reg_d0.h[0] += 0xA00;
                                    func_002027A0();
                                    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
                                    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
                                    reg_d5.w = 0x0A000000;
                                    reg_d0.w = 0xB;
                                    reg_a0 = (u8 *)(D_00259970);
                                    reg_d4.w = 0;
                                    if (*(u8 *)(reg_a5 + 0x1F) & 1) {
                                        reg_d1.h[0] -= 0x28;
                                        reg_d7.w = 5;
                                        do {
                                            reg_d3.h[0] = reg_d1.h[0];
                                            reg_d3.h[0] += 2;
                                            reg_d3.h[0] &= 0xFC;
                                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                            reg_d3.w += reg_d5.w;
                                            func_00129410();
                                            reg_d1.h[0] += 0x10;
                                        } while ((s16)(--reg_d7.h[0]) >= 0);
                                    } else {
                                        reg_d1.h[0] -= 0x30;
                                        reg_d7.w = 6;
                                        do {
                                            reg_d3.h[0] = reg_d1.h[0];
                                            reg_d3.h[0] += 2;
                                            reg_d3.h[0] &= 0xFC;
                                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                            reg_d3.w += reg_d5.w;
                                            func_00129410();
                                            reg_d1.h[0] += 0x10;
                                        } while ((s16)(--reg_d7.h[0]) >= 0);
                                    }
                                }
                            }
                            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                            *(u8 *)(reg_a5 + 0x1F) -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
                                reg_d0.h[0] = 0x10;
                                reg_d0.h[0] -= D_0028E8C8;
                                reg_d0.h[0] += 8;
                                *(u8 *)(reg_a5 + 0x1D) = (u8) reg_d0.b[0];
                                *(u16 *)(reg_a5 + 0x18) = 3U;
                            }
                        }
                    } else {
                        temp_v0_5 = *(u8 *)(reg_a5 + 0x1D);
                        if (temp_v0_5 != 0) {
                            *(u8 *)(reg_a5 + 0x1D) = (u8) (temp_v0_5 - 1);
                        } else {
                            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                            *(u8 *)(reg_a5 + 0x23) -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
                                *(u16 *)(reg_a5 + 0x20) -= 8;
                                if (*(u16 *)(reg_a5 + 0x20) == 0) {
                                    func_00171400();
                                    reg_d0.h[0] = 0x20;
                                    reg_d0.h[0] -= D_0028E8CC;
                                    *(u8 *)(reg_a5 + 0x1D) = (u8) reg_d0.b[0];
                                    *(u16 *)(reg_a5 + 0x18) = 0U;
                                }
block_60:
                                reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
                                reg_a0 = (u8 *)(D_00262E50);
                                reg_a0 += reg_d0.h[0];
                                *(u16 *)(reg_a6 + 0xA) = *(u16 *)reg_a0;
                                reg_a0 += 2;
                                *(u16 *)(reg_a6 + 0xC) = *(u16 *)reg_a0;
                                reg_a0 += 2;
                                *(u16 *)(reg_a6 + 0x14) = *(u16 *)reg_a0;
                                reg_a0 += 2;
                                *(u16 *)(reg_a6 + 0x16) = *(u16 *)reg_a0;
                                reg_a0 += 2;
                            }
                        }
                    }
                }
                func_00170A60();
                reg_a0 = (u8 *)(reg_a6);
                func_0014D220();
                return;
            }
            *(u16 *)(reg_a5 + 0x2C) = (u16) reg_d1.h[0];
            reg_d0.w = 0x256;
            func_001A91A0();
            func_0018D580();
            *(u16 *)reg_a6 = 0x8080;
            temp_a0 = *(u8 *)(reg_a5 + 0x1B);
            *(u8 *)(reg_a6 + 0x1C) = temp_a0;
            reg_d0.h[0] = 0x85;
            func_0013A780();
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            *(s16 *)(reg_a0 + 0x26) = 0;
            *(s16 *)(reg_a0 + 0x28) = 0;
            *(s16 *)(reg_a0 + 0x10) = 1;
            *(s16 *)(reg_a0 + 0x1A) = 0x700;
            *(s16 *)(reg_a0 + 0x18) = 0;
            reg_d0.h[0] = 0x85;
            func_0013A780();
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            *(u16 *)(reg_a0 + 0x26) = 0xFC00;
            *(s16 *)(reg_a0 + 0x28) = 0x800;
            *(s16 *)(reg_a0 + 0x10) = 1;
            *(s16 *)(reg_a0 + 0x1A) = 0x740;
            *(s16 *)(reg_a0 + 0x18) = 2;
            reg_d0.h[0] = 0x85;
            func_0013A780();
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            *(u16 *)(reg_a0 + 0x26) = 0xF200;
            *(s16 *)(reg_a0 + 0x28) = 0;
            *(s16 *)(reg_a0 + 0x10) = 1;
            *(s16 *)(reg_a0 + 0x1A) = 0x880;
            *(s16 *)(reg_a0 + 0x18) = 4;
            reg_d0.h[0] = 0x85;
            func_0013A780();
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            *(u16 *)(reg_a0 + 0x26) = 0xFC00;
            *(u16 *)(reg_a0 + 0x28) = 0xF800;
            *(s16 *)(reg_a0 + 0x10) = 1;
            *(s16 *)(reg_a0 + 0x1A) = 0x7C0;
            *(s16 *)(reg_a0 + 0x18) = 6;
            reg_d0.h[0] = 0x85;
            func_0013A780();
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(s16 *)(reg_a0 + 0x26) = 0x600;
            *(u16 *)(reg_a0 + 0x28) = 0xF600;
            *(s16 *)(reg_a0 + 0x10) = 1;
            *(s16 *)(reg_a0 + 0x1A) = 0x4D0;
            *(s8 *)(reg_a0 + 0x1D) = 0x40;
            *(s16 *)(reg_a0 + 0x18) = 8;
            reg_d0.h[0] = 0xD;
            func_0013A780();
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            *(s16 *)(reg_a0 + 0x26) = 0x200;
            *(s16 *)(reg_a0 + 0x28) = 0x600;
            *(s16 *)(reg_a0 + 0x10) = 1;
            *(s16 *)(reg_a0 + 0x1A) = 0x430;
            *(s16 *)(reg_a0 + 0x18) = 0xA;
            reg_d0.h[0] = 0x85;
            func_0013A780();
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(u16 *)(reg_a0 + 0x26) = 0xF000;
            *(s16 *)(reg_a0 + 0x28) = 0xA00;
            *(s16 *)(reg_a0 + 0x10) = 1;
            *(s16 *)(reg_a0 + 0x1A) = 0x450;
            *(s16 *)(reg_a0 + 0x18) = 0xC;
            reg_d0.h[0] = 0xD;
            func_0013A780();
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            *(u16 *)(reg_a0 + 0x26) = 0xF000;
            *(u16 *)(reg_a0 + 0x28) = 0xFA00;
            *(s16 *)(reg_a0 + 0x10) = 1;
            *(s16 *)(reg_a0 + 0x1A) = 0x4B0;
            *(s16 *)(reg_a0 + 0x18) = 0xE;
            reg_d0.h[0] = 0xD;
            func_0013A780();
            var_a3 = 0xC;
            var_a2 = 0x400;
            var_a1 = 0xF400;
            var_a0 = 1;
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            *(u16 *)(reg_a0 + 0x26) = 0xF400;
            *(s16 *)(reg_a0 + 0x28) = 0;
            *(s16 *)(reg_a0 + 0x10) = 1;
            *(s16 *)(reg_a0 + 0x18) = 0x10;
            goto block_63;
        }
    } else {
block_63:
        if (*(u16 *)(reg_a5 + 0x28) != 0) {
            reg_d1.h[0] = *(u16 *)(reg_a5 + 0x2C);
            func_00201710();
            *(u16 *)(reg_a5 + 0x28) -= 1;
        }
        temp_v0_6 = *(u16 *)(reg_a5 + 0x2A);
        if (temp_v0_6 != 0) {
            *(u16 *)(reg_a5 + 0x2A) = (u16) (temp_v0_6 - 1);
            if (*(u16 *)(reg_a5 + 0x2A) == 0) {
                reg_tmp.w = 0x1BF7;
                *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[1];
                *(u16 *)(reg_a6 + 0xC) = (u16) reg_tmp.h[0];
            }
        }
        func_0014EA50();
        if (enemy_move_end_requested == 0) {
            reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
            reg_tmp1.w = 0;
            reg_tmp1.h[0] = 0x6000;
            reg_tmp.w = 0;
            reg_d0.h[0] += 0x1800;
            reg_tmp.h[0] = reg_d0.h[0];
            reg_tmp.w += reg_tmp1.w;
            reg_d0.h[0] += 0x6000;
            if (reg_tmp.h[1] != 0) {
                func_0014E290();
                return;
            }
            func_00170A60();
        }
    }
}

void func_001C7A90(void) {
    void func_001713F0(s32);
    func_001713F0(0);
}

extern u32 reg_a0_as_u32;
extern u32 D_00262ED0[];
extern u32 D_00262EE0[];


void func_001C7AA0(void)
{
    extern void func_0014E300(void);
    extern void func_0014E370(void);
    extern void func_0014E7E0(void);
    reg_a0_as_u32 = (u32)D_00262EE0;
    func_0014E370();

    reg_a0_as_u32 = (u32)D_00262ED0;
    reg_d0.w = 5;
    func_0014E300();
    func_0014E7E0();

    if (enemy_move_end_requested) {
        return;
    }
}

s32 func_0019BF80();
s32 func_0019C530();
extern u16 D_00262F00[];
extern u16 D_0028E8A8;

void func_001C7AF0(void) {
    u32 temp_a1;

    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        if ((s32) D_0028E8A8 >= 0x22F) {
            func_0014E290();
            return;
        }
        if (((s32) D_0028E8A8 >= 0x1F8) && (*(s16 *)(reg_a5 + 0x1C) >= 0)) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
            *(u8 *)(reg_a5 + 0x1B) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
                reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1C);
                reg_a0 = (u8 *)(D_00262F00);
                reg_a0 += reg_d0.h[0];
                *(u16 *)(reg_a6 + 0xA) = (u16) *(u16 *)reg_a0;
                reg_a0 += 2;
                *(u16 *)(reg_a6 + 0xC) = (u16) *(u16 *)reg_a0;
                reg_a0 += 2;
                *(u16 *)(reg_a5 + 0x1E) = (u16) *(u16 *)reg_a0;
                reg_a0 += 2;
                *(u16 *)(reg_a5 + 0x20) = (u16) *(u16 *)reg_a0;
                reg_a0 += 2;
                *(u16 *)(reg_a5 + 0x1C) -= 8;
            }
        }
        if ((s32) D_0028E8A8 < 0x21A) {
            func_0019BF80();
        }
        reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
        reg_d1.h[0] += 0x4C00;
        temp_a1 = reg_d1.h[0];
        reg_tmp1.h[0] = temp_a1;
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        reg_d1.w += 0xFE00DC00;
        reg_d2.h[1] = *(u16 *)(reg_a5 + 0x1E);
        reg_d2.h[0] = *(u16 *)(reg_a5 + 0x20);
        reg_d3.h[0] = 0x2320;
        reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
        func_0019C530();
    }
}
