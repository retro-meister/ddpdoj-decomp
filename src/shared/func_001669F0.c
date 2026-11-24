#include "common.h"

s32 func_00128930();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_00166740();
s32 func_0018D580();
s32 func_0019BFC0();
s32 func_0019C530();
s32 func_0019C570();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_002027A0();
extern u16 D_0025AD30[];
extern u16 D_0028C9F8;
extern u16 D_0028E3EC;
extern s16 *D_0028E44C;
extern u16 D_0028E46C;
extern Reg32 D_0028E484;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u16 D_0028E8A8;
extern u16 D_0028E8B8;
extern u16 D_0028E8C8;
extern u16 D_0028E8CC;
extern u16 D_0028E8D0;
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern u16 D_0029F1F0[];
extern u16 D_0029F260[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001669F0(void) {
    s16 *temp_v1_2;
    s16 *var_a1;
    u16 temp_a0_2;
    s32 temp_a0_4;
    s64 temp_v0_2;
    u16 temp_a0;
    u16 temp_a0_3;
    u16 temp_a0_5;
    u16 temp_a1;
    u16 temp_a1_2;
    u16 temp_a2;
    u16 var_a2;
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    u32 temp_s3;
    u8 temp_v0;
    u8 temp_v1;
    u8 var_v0;

    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        D_0028E484.w = 0;
        D_0028E484.h[0] = 0x7000;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1000;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] += 0x7000;
        reg_tmp.w += D_0028E484.sw;
        if (reg_tmp.h[1] != 0) {
            if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
                func_0014E290();
                return;
            }
            goto block_5;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_5:
        (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
        (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        reg_d1.b[0] |= (*(u8 *)((u8 *)(reg_a6) + (0x21)));
        reg_d1.h[0] &= 0x5C;
        var_a1 = (s16 *)(reg_a6 + 1);
        if (reg_d1.h[0] == 0) {
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
            if (((s32) (*(u16 *)((u8 *)(reg_a6) + (0x18))) < 0x260) && (D_0028E8B8 == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_14;
        }
        reg_d0.h[0] = 0xA3;
        (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x21))) &= reg_d0.b[0];
        func_001A9000();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
        }
        var_a1 = (s16 *)(reg_a6 + 0x18);
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
        reg_d0.b[0] ^= reg_d2.b[0];
        reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x18)));
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x38)));
        if ((s16)(temp_a0) < (s16) reg_d4.h[0]) {
            reg_d4.h[0] = temp_a0;
        }
        (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) reg_d4.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x38))) = (u16) reg_d4.h[0];
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x18))) >= 0) {
block_14:
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
            if ((D_0028E8A0 == 0) && (D_0028E89C == 0)) {
                if (((D_0028E910 != 0) || ((s32) D_0028E91C >= 3)) && ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) >= 0x1000)) {
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x2B)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x2B))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a5) + (0x2B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2F)));
                        reg_d1.w = 0x20;
                        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                        reg_d4.w = 0;
                        if (!((*(u8 *)((u8 *)(reg_a6) + (0))) & 0x40)) {
                            reg_d0.w = 0x20007;
                            reg_d3.w = 0xF200F940;
                            func_00128930();
                            reg_d3.w = 0xF2000700;
                            func_00128930();
                        } else {
                            reg_d0.w = 0x20007;
                            reg_d3.w = 0xF400FE00;
                            func_00128930();
                            reg_d3.w = 0xF4000240;
                            func_00128930();
                        }
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x2D)));
                        (*(u8 *)((u8 *)(reg_a5) + (0x2D))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            (*(u8 *)((u8 *)(reg_a5) + (0x2D))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2C)));
                            temp_v1 = (*(u8 *)((u8 *)(reg_a6) + (0)));
                            if (temp_v1 & 0x40) {
                                (*(u8 *)((u8 *)(reg_a6) + (0))) = temp_v1 & 0xBF;
                            } else {
                                (*(u8 *)((u8 *)(reg_a6) + (0))) = temp_v1 | 0x40;
                            }
                            reg_d0.h[0] = 0x20;
                            reg_d0.h[0] -= D_0028E8CC;
                            (*(u8 *)((u8 *)(reg_a5) + (0x2B))) = (u8) reg_d0.b[0];
                            (*(u8 *)((u8 *)(reg_a5) + (0x2A))) = (u8) reg_d0.b[0];
                        }
                    }
                }
                if ((D_0028E8A0 == 0) && (D_0028E89C == 0) && ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) >= 0x1000) && ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0)) {
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
                    temp_a0_2 = reg_d0.h[0] & 0xFFFF;
                    if (reg_d0.h[0] == 0) {
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
                        (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            reg_d0.h[0] = 0x10;
                            reg_d0.h[0] -= D_0028E8C8;
                            (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) reg_d0.b[0];
                            (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 1U;
                        }
                    } else if (temp_a0_2 == 1) {
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
                        (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x22)));
                            (*(u16 *)((u8 *)(reg_a5) + (0x20))) += 4;
                            if ((*(u16 *)((u8 *)(reg_a5) + (0x20))) == 0x1C) {
                                (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 2U;
                            }
                            goto block_58;
                        }
                    } else if (temp_a0_2 == 2) {
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
                        (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2E)));
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
                                    goto block_45;
                                }
                            } else {
block_45:
                                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
                                reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
                                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                                reg_d4.w = 0;
                                reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
                                reg_a0 = (u8 *)(&D_0028C9F8);
                                reg_d4.h[0] += reg_d4.h[0];
                                reg_d7.h[0] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d4.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                                temp_a1 = reg_d7.h[0];
                                temp_s1 = reg_d1.w;
                                temp_s2 = reg_d2.w;
                                temp_s3 = reg_d3.w;
                                reg_d0.h[0] += temp_a1;
                                *(u16 *)&D_0028E46C = temp_a1;
                                reg_d7.h[1] = *(u16 *)&D_0028E46C;
                                reg_d7.h[0] = 0x700;
                                reg_d1.h[0] += reg_d7.h[0];
                                temp_s0 = reg_d0.w;
                                func_002027A0();
                                func_00166740();
                                reg_d1.w = temp_s1;
                                reg_d7.h[0] = 0xF900;
                                reg_d0.w = temp_s0;
                                reg_d2.w = temp_s2;
                                reg_d3.w = temp_s3;
                                reg_d1.h[0] += reg_d7.h[0];
                                func_002027A0();
                                func_00166740();
                            }
                            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
                            (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1E)));
                                reg_d0.h[0] = 0x10;
                                reg_d0.h[0] -= D_0028E8C8;
                                (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) reg_d0.b[0];
                                (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 3U;
                            }
                        }
                    } else {
                        temp_v0 = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
                        if (temp_v0 != 0) {
                            (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) (temp_v0 - 1);
                        } else {
                            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
                            (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x22)));
                                (*(u16 *)((u8 *)(reg_a5) + (0x20))) -= 4;
                                if ((*(u16 *)((u8 *)(reg_a5) + (0x20))) == 0) {
                                    reg_d0.h[0] = 0x30;
                                    if (D_0028E91C == 4) {
                                        reg_d0.h[0] += 0x10;
                                    }
                                    reg_d0.h[0] -= D_0028E8D0;
                                    (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) reg_d0.b[0];
                                    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 0U;
                                }
block_58:
                                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x20)));
                                reg_a0 = (u8 *)(D_0025AD30);
                                (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                                (*(u16 *)((u8 *)(reg_a5) + (0x26))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            }
                        }
                    }
                }
            }
            func_0019BFC0();
            reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            temp_a0_3 = reg_d1.h[0];
            reg_d1.h[1] += 0x7FFF + 0x7D01;
            reg_d1.h[0] = (u32)temp_a0_3 + 0x7FFF + 0x7701;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x24)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
            reg_d3.h[0] = 0x648;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
            func_0019C570();
            if ((D_0028E910 == 0) && (D_0028E3EC != 0) && ((D_0028E91C != 1) || ((s32) D_0028E8A8 < 0x16C))) {
                reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d1.h[1] += 0x7FFF + 0x5801;
                reg_d2.w = 0x1887;
                reg_d3.h[0] = 0x830;
                reg_d4.h[0] = 0x18;
                reg_d1.h[0] += 0x200;
                func_0019C530();
            }
            reg_a0 = (u8 *)(reg_a6);
            func_0014D220();
            reg_a0 = (u8 *)(reg_a6 + 0x20);
            func_0014D220();
            return;
        }
        reg_d0.w = 0x55;
        func_001A91A0();
        func_0018D580();
        reg_d0.w = 0xD;
        func_0013A780();
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
        var_a2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
        (*(u16 *)((u8 *)(reg_a0) + (4))) = var_a2;
        (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
        (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
        (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
        (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xF600;
        (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0;
        if ((D_0028E91C != 1) || ((s32) D_0028E8A8 < 0x150)) {
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1A)));
            reg_d0.b[0] *= 4;
            temp_a0_5 = reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a0) + (0x1A))) = temp_a0_5;
            reg_d0.h[0] = 0x84;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            var_a2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = var_a2;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
            (*(s16 *)((u8 *)(reg_a0) + (0x26))) = 0x400;
            (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0;
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1A)));
            reg_d0.h[0] += 0x800;
            reg_d0.b[0] *= 4;
            (*(u16 *)((u8 *)(reg_a0) + (0x1A))) = (u16) reg_d0.h[0];
        }
        func_0014E290();
    }
}
