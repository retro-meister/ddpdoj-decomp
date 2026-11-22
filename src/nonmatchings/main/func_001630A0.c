#include "common.h"

/* NONMATCHING: ~94.2%; retail leaves nearly all fallthrough-fillable delay slots as nop (see mwcc_quirks.md) and keeps `beqz; nop; b exit` for the early return */

s32 func_00125EF0();
s32 func_00128930();
s32 func_00128A20();
s32 func_001368E0();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_00170A60();
s32 func_00170BE0();
s32 func_00170D00();
s32 func_0018D580();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_002021F0();
s32 func_00202500();
s32 func_00211550();
extern u16 D_002590F0[];
extern u16 D_002594F0[];
extern u16 D_0025A610[];
extern u16 D_0025A620[];
extern s16 *D_0028E44C;
extern Reg32 D_0028E484;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u16 D_0028E8B8;
extern u16 D_0028E8C8;
extern u16 D_0028E8D8;
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

void func_001630A0(void) {
    s16 *temp_a0;
    s16 *temp_v1_2;
    s64 temp_v0;
    s64 temp_v0_2;
    s64 temp_v0_3;
    s64 temp_v1_4;
    s64 temp_v1_5;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_5;
    u16 temp_v1;
    u16 var_v0_2;
    u16 var_v0_3;
    u32 var_a0;
    u8 temp_v0_4;
    u8 temp_v0_5;
    u8 temp_v1_3;

    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        if (((*(u16 *)((u8 *)(reg_a6) + (0x2E))) != 0) && ((*(u8 *)((u8 *)(reg_a6) + (1))) & 0x20)) {
            reg_a0 = (u8 *)(reg_a6 + 0x16);
            if ((*(u16 *)((u8 *)(reg_a6) + (0x30))) != 0) {
                reg_a0 = (u8 *)(reg_a6 + 0x14);
                reg_d3.h[0] *= 0xFFFF;
            }
            temp_v1 = (*(u16 *)((u8 *)(reg_a0) + (0)));
            if ((s16)temp_v1 < 0xC00) {
                *(u16 *)reg_a0 += reg_d3.h[0];
            }
        }
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] += 0x1400;
        reg_tmp.w = 0;
        D_0028E484.w = 0;
        D_0028E484.h[0] = 0xA000;
        reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d0.h[0] += D_0029C068[0];
        reg_tmp.h[0] = reg_d0.h[0];
        var_a0 = reg_tmp.w;
        reg_d0.h[0] += 0x7FFF + 0x2001;
        reg_tmp.w = var_a0 + D_0028E484.w;
        if (reg_tmp.h[1] != 0) goto block_out;
        D_0028E484.w = 0;
        D_0028E484.h[0] = 0x7800;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] = reg_d0.h[1];
        temp_a0_2 = reg_tmp.h[0];
        reg_d0.h[0] += 0xC00;
        reg_tmp.w = 0;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] += 0x7800;
        reg_tmp.w += D_0028E484.w;
        reg_d0.h[1] = temp_a0_2;
        if (reg_tmp.h[1] != 0) {
block_out:
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
            if (((s32) (*(u16 *)((u8 *)(temp_a0) + (0x18))) < 0x4A0) && (D_0028E8B8 == 0)) {
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
            if (D_0028E8A0 == 0) {
                (*(u16 *)((u8 *)(reg_a6) + (6))) = 0xF400;
                if ((s32) (*(u8 *)((u8 *)(reg_a6) + (0x1A))) < 0x40) {
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x27)));
                    (*(u8 *)((u8 *)(reg_a6) + (0x27))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a6) + (0x27))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x26)));
                        (*(u16 *)((u8 *)(reg_a6) + (6))) = 0xF3C0;
                        if ((*(u8 *)((u8 *)(reg_a6) + (0x1A))) == 0x10) {
                            (*(u16 *)((u8 *)(reg_a6) + (0x28))) += 4;
                            if ((*(u16 *)((u8 *)(reg_a6) + (0x28))) == 0x10) {
                                (*(u16 *)((u8 *)(reg_a6) + (0x28))) = 0U;
                            }
                        } else {
                            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
                            (*(u16 *)((u8 *)(reg_a6) + (0x28))) -= 4;
                            if ((s32) reg_tmp.h[0] < 4) {
                                (*(u16 *)((u8 *)(reg_a6) + (0x28))) = 0xCU;
                            }
                        }
                        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
                        reg_a0 = (u8 *)(D_0025A610);
                        (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                        (*(u16 *)((u8 *)(reg_a6) + (0x2C))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    }
                }
            }
            if ((D_0028E8A0 == 0) && (D_0028E89C == 0)) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
                (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x22)));
                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x21)));
                    if ((*(u8 *)((u8 *)(reg_a5) + (0x20))) == reg_d0.b[0]) {
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
                                goto block_43;
                            }
                        } else {
block_43:
                            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
                            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_a3 = (u8 *)(D_002590F0);
                            temp_v1_3 = (*(u8 *)((u8 *)(reg_a6) + (0)));
                            if (temp_v1_3 & 0x40) {
                                (*(u8 *)((u8 *)(reg_a6) + (0))) = (u8) (temp_v1_3 & 0xBF);
                                goto block_t;
                            }
                            (*(u8 *)((u8 *)(reg_a6) + (0))) = (u8) (temp_v1_3 | 0x40);
                            reg_d0.h[0] += 0x300;
                            reg_d1.h[0] += 0x5C0;
                            func_002021F0();
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
                            func_00202500();
                            (*(u16 *)((u8 *)(reg_a5) + (0x28))) = (u16) reg_d1.h[0];
                            reg_d1.h[0] &= 0x3E;
                            reg_d1.h[0] += reg_d1.h[0];
                            (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                            (*(u16 *)((u8 *)(reg_a5) + (0x26))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                            goto block_join;
block_t:
                            reg_d0.h[0] += 0x300;
                            reg_d1.h[0] += 0x7FFF + 0x79C1;
                            func_002021F0();
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x2E)));
                            func_00202500();
                            (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = (u16) reg_d1.h[0];
                            reg_d1.h[0] &= 0x3E;
                            reg_d1.h[0] += reg_d1.h[0];
                            (*(u16 *)((u8 *)(reg_a5) + (0x2A))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                            (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                        }
                    }
                }
            }
block_join:
            func_00170A60();
            reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            temp_a0_2 = reg_d1.h[0];
            reg_d1.h[1] += 0x7FFF + 0x7201;
            reg_d1.h[0] = (u32)temp_a0_2 + 0x7FFF + 0x7501;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2C)));
            reg_d3.h[0] = 0x458;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
            func_00170BE0();
            reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            temp_a0_3 = reg_d1.h[0];
            reg_d1.h[1] += 0x7FFF + 0x7F01;
            reg_d1.h[0] = (u32)temp_a0_3 + 0x2C0;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x24)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
            reg_d3.h[0] = 0x418;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
            func_00170BE0();
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d1.h[0] += 0x7FFF + 0x76C1;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x2A)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x2C)));
            func_00170BE0();
            reg_a0 = (u8 *)(reg_a6);
            func_0014D220();
            if ((D_0028E8A0 == 0) && (D_0028E89C == 0) && ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) >= 0x1000)) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
                (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
                if (reg_tmp.b[0] != 0) {
                    reg_tmp.b[0] = 0;
                    return;
                }
                (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x30)));
                reg_a4 = (u8 *)(D_002594F0);
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
                reg_d0.h[0] = reg_d1.h[0];
                reg_d0.h[0] &= 0x3E;
                reg_d0.h[0] += reg_d0.h[0];
                reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
                reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a4;
                reg_d4.w = 0;
                temp_a0_4 = (u32)reg_d3.h[0] + 0x5C0;
                reg_d3.h[0] = temp_a0_4;
                reg_d3.h[1] += 0x300;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d0.w = 0x30004;
                temp_v0_4 = (*(u8 *)((u8 *)(reg_a5) + (0x33)));
                if (temp_v0_4 == 0) {
                    var_v0_2 = reg_d1.h[0] + 3;
                    goto block_75;
                }
                if ((temp_v0_4 & 0xFF) == 1) {
                    var_v0_2 = reg_d1.h[0] + 5;
block_75:
                    reg_d1.h[0] = var_v0_2;
                }
                func_00128A20();
                reg_d1.h[0] -= 5;
                func_00128930();
                reg_d1.h[0] -= 5;
                func_00128A20();
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x2E)));
                reg_d4.h[0] = reg_d1.h[0];
                reg_d4.h[0] &= 0x3E;
                reg_d4.h[0] += reg_d4.h[0];
                reg_d3.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a4;
                reg_d3.h[0] = (((reg_d4.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((reg_d4.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a4;
                reg_d4.w = 0;
                reg_d0.w = 0x30004;
                temp_a0_5 = reg_d3.h[0] + 0x7FFF + 0x79C1;
                reg_d3.h[0] = temp_a0_5;
                reg_d3.h[1] += 0x300;
                temp_v0_5 = (*(u8 *)((u8 *)(reg_a5) + (0x33)));
                if (temp_v0_5 == 0) {
                    var_v0_3 = reg_d1.h[0] - 3;
                    goto block_86;
                }
                if ((temp_v0_5 & 0xFF) == 1) {
                    var_v0_3 = reg_d1.h[0] - 5;
block_86:
                    reg_d1.h[0] = var_v0_3;
                }
                func_00128A20();
                reg_d1.h[0] += 5;
                func_00128930();
                reg_d1.h[0] += 5;
                func_00128A20();
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x21)));
                (*(u8 *)((u8 *)(reg_a5) + (0x21))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x21))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x20)));
                    reg_d0.h[0] = 0xA;
                    reg_d1.h[0] = D_0028E8C8;
                    reg_d1.h[0] >>= 2;
                    reg_d0.h[0] -= reg_d1.h[0];
                    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) reg_d0.b[0];
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x33)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x33))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a5) + (0x33))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x32)));
                        reg_d0.h[0] = 0x60;
                        reg_d0.h[0] -= D_0028E8D8;
                        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) reg_d0.b[0];
                    }
                }
            }
        } else {
            reg_d0.w = 0x115;
            func_001A91A0();
            func_0018D580();
            reg_d1.h[0] = 0;
            reg_d2.w = -0x600U;
            reg_d0.w = 0xC;
            func_00211550();
            reg_d2.w = 0x600;
            func_00211550();
            reg_d0.w = 8;
            reg_a4 = (u8 *)(D_0025A620);
            reg_d6.w = 6;
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
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
            (*(s16 *)((u8 *)(reg_a0) + (0x26))) = 0x200;
            (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
            reg_d0.w = 0xC;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
            func_00170D00();
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFE00;
            (*(u16 *)((u8 *)(reg_a0) + (0x28))) = 0xFA00;
            (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x5C0;
            (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
            reg_d0.w = 0xC;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
            func_00170D00();
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFC00;
            (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0x200;
            (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x440;
            (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
            reg_d0.h[0] = 0x85;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
            func_00170D00();
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFE00;
            (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x380;
            (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
            func_0014E290();
        }
    }
}
