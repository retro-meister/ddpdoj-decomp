#include "common.h"

/* NONMATCHING: 98.1% with the stock compiler, 99.35% with a compiler patched to never fill delay slots from the fall-through block (see the unfilled-delay-slot entry in knowledge/mwcc_quirks.md). Remaining diff: the `if (reg_tmp.b[0] != 0) return;` layout. */

#pragma mpwc_relax on

s32 func_00125EF0();
s32 func_001289D0();
s32 func_001368E0();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_00170A60();
s32 func_00170BE0();
s32 func_00170CA0();
s32 func_00170D00();
s32 func_0018D520();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_002021F0();
s32 func_00202500();
s32 func_00211550();
extern u16 D_00258FF0[];
extern u16 D_00259370[];
extern u16 D_0025ADE0[];
extern u16 D_0025ADF0[];
extern s16 *D_0028E44C;
extern Reg32 D_0028E484;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u16 D_0028E8B8;
extern u16 D_0028E8C8;
extern u16 D_0028E8D4;
extern u16 D_0028E91C;
extern u16 D_0029C068[];
extern u16 D_0029F1F0[];
extern u16 D_0029F260[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001676F0(void) {
    s16 *temp_a0;
    s16 *temp_v1_2;
    s64 temp_v0;
    s64 temp_v0_2;
    s64 temp_v1_3;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a1;
    u16 temp_a1_2;
    u16 temp_a1_3;
    u16 temp_a2;
    u32 temp_v1;
    u16 var_a0;
    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        if (((*(u16 *)((u8 *)(reg_a5) + (0x30))) != 0) && ((*(u8 *)((u8 *)(reg_a6) + (1))) & 0x20)) {
            reg_a0 = (u8 *)(reg_a6 + 0x16);
            if ((*(u16 *)((u8 *)(reg_a5) + (0x32))) != 0) {
                reg_a0 = (u8 *)(reg_a6 + 0x14);
                reg_d3.h[0] *= 0xFFFF;
            }
            temp_v1 = (*(u16 *)((u8 *)(reg_a0) + (0)));
            if ((s16)(temp_v1) < 0x800) {
                (*(s16 *)((u8 *)(reg_a0) + (0))) = temp_v1 + reg_d3.h[0];
            }
        }
        reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        temp_a1 = (u32)reg_d0.h[0] + 0x1000;
        reg_d0.h[0] = temp_a1;
        reg_tmp.w = 0;
        reg_tmp.h[0] = 0xA800;
        D_0028E484.w = 0;
        var_a0 = D_0029C068[0];
        reg_d0.h[0] += var_a0;
        reg_tmp.w += D_0028E484.w;
        reg_d0.h[0] += 0x7FFF + 0x2801;
        if ((reg_tmp.h[1] != 0) || (D_0028E484.w = 0, D_0028E484.h[0] = 0x7800, reg_tmp.h[0] = reg_d0.h[0], reg_d0.h[0] = reg_d0.h[1], var_a0 = reg_tmp.h[0], reg_d0.h[0] += 0xC00, reg_tmp.w = 0, reg_tmp.h[0] = reg_d0.h[0], reg_d0.h[0] += 0x7800, reg_tmp.w += D_0028E484.sw, reg_d0.h[1] = var_a0, (reg_tmp.h[1] != 0))) {
            if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
                func_0014E290();
                return;
            }
            goto block_12;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_12:
        temp_a0 = (s16 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(temp_a0) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
            if (((s32) (*(u16 *)((u8 *)(temp_a0) + (0x18))) < 0x2C0) && (D_0028E8B8 == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_19;
        }
        (*(u8 *)((u8 *)(temp_a0) + (1))) &= 0xA3;
        func_001A9000();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
        }
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1C)));
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x18))) >= 0) {
block_19:
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
            func_001368E0();
            if ((D_0028E8A0 == 0) && ((s32) (*(u8 *)((u8 *)(reg_a6) + (0x1A))) < 0x40)) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x35)));
                (*(u8 *)((u8 *)(reg_a5) + (0x35))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x35))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x34)));
                    if ((*(u8 *)((u8 *)(reg_a6) + (0x1A))) == 0x10) {
                        (*(u16 *)((u8 *)(reg_a5) + (0x36))) += 4;
                        if ((*(u16 *)((u8 *)(reg_a5) + (0x36))) == 0x10) {
                            (*(u16 *)((u8 *)(reg_a5) + (0x36))) = 0U;
                        }
                    } else {
                        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x36)));
                        (*(u16 *)((u8 *)(reg_a5) + (0x36))) -= 4;
                        if ((s32) reg_tmp.b[0] < 4) {
                            (*(u16 *)((u8 *)(reg_a5) + (0x36))) = 0xCU;
                        }
                    }
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x36)));
                    reg_a0 = (u8 *)(D_0025ADE0);
                    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                }
            }
            if ((D_0028E8A0 == 0) && (D_0028E89C == 0)) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
                (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x22)));
                    reg_a0 = (u8 *)(D_0029F260);
                    reg_a1 = (u8 *)(D_0029F1F0);
                    if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
                        D_0028E44C = (s16 *)(reg_a0);
                        reg_a0 = (u8 *)(reg_a1);
                        reg_a1 = (u8 *)(D_0028E44C);
                    }
                    temp_v1_2 = (s16 *)(reg_a0);
                    if ((*(s16 *)((u8 *)(temp_v1_2) + (0))) >= 0) {
                        if (*(s16 *)reg_a1 < 0) {
                            reg_a0 = (u8 *)(reg_a1);
                            D_0028E44C = (s16 *)(temp_v1_2);
                            reg_a1 = (u8 *)(temp_v1_2);
                            goto block_42;
                        }
                    } else {
block_42:
                        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
                        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
                        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                        temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                        reg_d1.h[0] = temp_a0_2;
                        reg_a3 = (u8 *)(D_00258FF0);
                        reg_d0.h[0] += 0x440;
                        reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a5) + (0x2E)));
                        func_002021F0();
                        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
                        func_00202500();
                        (*(u16 *)((u8 *)(reg_a5) + (0x28))) = (u16) reg_d1.h[0];
                        reg_d1.h[0] &= 0x3E;
                        reg_d1.h[0] += reg_d1.h[0];
                        (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                        (*(u16 *)((u8 *)(reg_a5) + (0x26))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                    }
                }
            }
            func_00170A60();
            reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a5) + (0x2E)));
            reg_d1.h[1] += 0x7FFF + 0x7E41;
            reg_d1.h[0] += 0x7FFF + 0x7C01;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x24)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
            reg_d3.h[0] = 0x620;
            reg_d4.w = 0;
            reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
            func_00170BE0();
            reg_a0 = (u8 *)(reg_a6);
            func_0014D220();
            if ((D_0028E8A0 == 0) && (D_0028E89C == 0) && ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) >= 0x1000)) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
                (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
                if (reg_tmp.b[0] != 0) {
                    return;
                }
                reg_d0.h[0] = 3;
                reg_d1.h[0] = D_0028E8C8;
                reg_d1.h[0] >>= 3;
                reg_d0.h[0] -= reg_d1.h[0];
                (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) reg_d0.b[0];
                reg_a4 = (u8 *)(D_00259370);
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
                reg_d0.h[0] = reg_d1.h[0];
                reg_d0.h[0] &= 0x3E;
                reg_d0.h[0] += reg_d0.h[0];
                reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
                reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a4;
                reg_d3.h[0] += (*(u16 *)((u8 *)(reg_a5) + (0x2E)));
                reg_d3.h[1] += 0x440;
                reg_d4.w = (u32) reg_a6;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                temp_a0_4 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d2.h[0] = temp_a0_4;
                reg_d0.w = 0x2000C;
                if ((*(u8 *)((u8 *)(reg_a5) + (0x21))) & 1) {
                    reg_d1.h[0] -= 2;
                    func_001289D0();
                    reg_d1.h[0] += 4;
                    func_001289D0();
                } else {
                    func_001289D0();
                }
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x21)));
                (*(u8 *)((u8 *)(reg_a5) + (0x21))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x21))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x20)));
                    reg_d0.h[0] = 0xA;
                    reg_d0.h[0] -= D_0028E8C8;
                    reg_d0.h[0] += 8;
                    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) reg_d0.b[0];
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x2D)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x2D))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a5) + (0x2D))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2C)));
                        reg_d0.h[0] = 0x70;
                        reg_d0.h[0] -= D_0028E8D4;
                        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) reg_d0.b[0];
                        return;
                    }
                }
            }
        } else {
            func_0018D520();
            reg_d0.w = 0x88;
            func_001A91A0();
            func_00170CA0();
            reg_d2.w = 0xFE000000;
            reg_d0.w = 0xC;
            func_00211550();
            reg_d0.w = 8;
            reg_a4 = (u8 *)(D_0025ADF0);
            reg_d6.w = 4;
            do {
                reg_d1.h[1] = *(u16 *)reg_a4;
                reg_a4 += 2;
                reg_d1.h[0] = *(u16 *)reg_a4;
                reg_a4 += 2;
                func_00125EF0();
            } while ((s16)(--reg_d6.h[0]) >= 0);
            reg_d0.w = 0xD;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
            func_00170D00();
            if (D_0028E91C == 1) {
                (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 8;
            }
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFC00;
            (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
            reg_d0.w = 8;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
            func_00170D00();
            if (D_0028E91C == 1) {
                (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 8;
            }
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xF600;
            (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
            func_0014E290();
        }
    }
}
