#include "common.h"

s32 func_00125EF0();
s32 func_00129370();
s32 func_00129410();
s32 func_001368E0();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_0018D580();
s32 func_0019BEC0();
s32 func_0019C470();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_002010A0();
s32 func_00201200();
s32 func_002027A0();
s32 func_00211550();
extern u16 D_0025A430[];
extern u16 D_0025A440[];
extern u16 D_0025A460[];
extern u16 D_0028C9E0;
extern s16 *D_0028E44C;
extern u16 D_0028E47C;
extern Reg32 D_0028E484;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u16 D_0028E8B8;
extern u16 D_0028E8C8;
extern u16 D_0028E8D4;
extern u16 D_0029F1F0[];
extern u16 D_0029F260[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00160FA0(void) {
    s16 *temp_a0;
    s16 *temp_v1_3;
    u16 temp_v1_2;
    s64 temp_v0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_5;
    u16 temp_a0_6;
    u16 temp_a0_7;
    u16 temp_a1_3;
    u16 temp_a1_4;
    u16 temp_a2;
    u16 temp_a2_2;
    u16 temp_a3;
    u16 temp_v1;
    u8 temp_a1;
    u8 temp_a1_2;
    u8 temp_v1_4;

    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        if (((*(u16 *)((u8 *)(reg_a6) + (0x30))) != 0) && ((*(u8 *)((u8 *)(reg_a6) + (1))) & 0x20)) {
            reg_a0 = (u8 *)(reg_a6 + 0x12);
            if ((*(u16 *)((u8 *)(reg_a6) + (0x32))) != 0) {
                reg_a0 = (u8 *)(reg_a6 + 0x10);
                reg_d2.h[0] *= 0xFFFF;
            }
            temp_v1 = (*(u16 *)((u8 *)(reg_a0) + (0)));
            if ((s16)temp_v1 < 0x1000) {
                *(u16 *)reg_a0 += reg_d2.h[0];
                if ((s32) (*(u16 *)((u8 *)(reg_a0) + (0))) < 0x800) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x18))) = 0x2D00U;
                }
            }
        }
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        D_0028E484.w = 0;
        D_0028E484.h[0] = 0x7200;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1600;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] += 0x7200;
        reg_tmp.w += D_0028E484.h[0];
        if (reg_tmp.h[1] != 0) {
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
            if (((s32) (*(u16 *)((u8 *)(temp_a0) + (0x18))) < 0xB40) && (D_0028E8B8 == 0)) {
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
                (*(u16 *)((u8 *)(reg_a6) + (6))) = 0xF000;
                if ((s32) (*(u8 *)((u8 *)(reg_a6) + (0x1A))) < 0x40) {
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x27)));
                    (*(u8 *)((u8 *)(reg_a6) + (0x27))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a6) + (0x27))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x26)));
                        (*(u16 *)((u8 *)(reg_a6) + (6))) = 0xF040;
                        if ((*(u8 *)((u8 *)(reg_a6) + (0x1A))) == 0) {
                            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
                            (*(u16 *)((u8 *)(reg_a6) + (0x28))) -= 4;
                            if ((s32) reg_tmp.h[0] < 4) {
                                (*(u16 *)((u8 *)(reg_a6) + (0x28))) = 0xCU;
                            }
                        } else {
                            (*(u16 *)((u8 *)(reg_a6) + (0x28))) += 4;
                            if ((*(u16 *)((u8 *)(reg_a6) + (0x28))) == 0x10) {
                                (*(u16 *)((u8 *)(reg_a6) + (0x28))) = 0U;
                            }
                        }
                        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
                        reg_a0 = (u8 *)(D_0025A430);
                        (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                        (*(u16 *)((u8 *)(reg_a6) + (0x2C))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    }
                }
            }
            if ((D_0028E8A0 == 0) && (D_0028E89C == 0) && (D_0028E8A0 == 0) && (D_0028E89C == 0) && ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) >= 0x1000)) {
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
                temp_v1_2 = reg_d0.h[0] & 0xFFFF;
                if (reg_d0.h[0] == 0) {
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = 8U;
                        (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 1U;
                    }
                } else if (temp_v1_2 == 1) {
                    (*(u16 *)((u8 *)(reg_a5) + (0x22))) += 2;
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x22)));
                    reg_a0 = (u8 *)(D_0025A440);
                    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                    if (reg_d0.h[0] == 0x14) {
                        (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 2U;
                        (*(u16 *)((u8 *)(reg_a5) + (0x22))) = 0x10U;
                    }
                } else if (temp_v1_2 == 2) {
                    (*(u16 *)((u8 *)(reg_a5) + (0x26))) = 0x2C0U;
                    (*(u16 *)((u8 *)(reg_a5) + (0x28))) = 0xF940U;
                    (*(u16 *)((u8 *)(reg_a6) + (0x2E))) = 0xF000U;
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        reg_d0.h[0] = 5;
                        reg_d1.h[0] = D_0028E8C8;
                        reg_d1.h[0] >>= 3;
                        reg_d0.h[0] -= reg_d1.h[0];
                        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) reg_d0.b[0];
                        reg_a0 = (u8 *)(D_0029F260);
                        reg_a1 = (u8 *)(D_0029F1F0);
                        if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
                            D_0028E44C = (s16 *)(reg_a0);
                            reg_a0 = (u8 *)(reg_a1);
                            reg_a1 = (u8 *)(D_0028E44C);
                        }
                        temp_v1_3 = (s16 *)(reg_a0);
                        if ((*(s16 *)((u8 *)(temp_v1_3) + (0))) >= 0) {
                            if (*(s16 *)reg_a1 < 0) {
                                reg_a0 = (u8 *)(reg_a1);
                                D_0028E44C = (s16 *)(temp_v1_3);
                                reg_a1 = (u8 *)(temp_v1_3);
                                goto block_55;
                            }
                        } else {
block_55:
                            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
                            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_d0.h[0] += 0xE00;
                            if (!((*(u8 *)((u8 *)(reg_a6) + (0))) & 0x40)) {
                                reg_d1.h[0] += 0x400;
                                func_002027A0();
                                reg_d7.h[0] = reg_d1.h[0];
                                func_002010A0();
                                reg_d1.b[0] += reg_d0.b[0];
                                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x2C)));
                                reg_a0 = (u8 *)(&D_0028C9E0);
                                reg_d3.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                                D_0028E47C = reg_d3.h[0];
                                reg_d3.h[0] = 0x400;
                                reg_d3.h[1] = D_0028E47C;
                                reg_d4.w = 0;
                                reg_d0.w = 0x30013;
                                func_00129370();
                                reg_d1.h[0] -= 0x10;
                                func_00201200();
                                if (reg_d5.h[0] != 0) {
                                    reg_d1.h[0] += 0x20;
                                }
                                func_00129410();
                            } else {
                                reg_d1.h[0] += 0xFC00 & 0xFFFF;
                                func_002027A0();
                                reg_d7.h[0] = reg_d1.h[0];
                                func_002010A0();
                                reg_d1.b[0] += reg_d0.b[0];
                                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x2C)));
                                reg_a0 = (u8 *)(&D_0028C9E0);
                                reg_d3.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                                D_0028E47C = reg_d3.h[0];
                                reg_d3.h[0] = 0xFC00;
                                reg_d3.h[1] = D_0028E47C;
                                reg_d4.w = 0;
                                reg_d0.w = 0x30013;
                                func_00129370();
                                reg_d1.h[0] -= 0x10;
                                func_00201200();
                                if (reg_d5.h[0] != 0) {
                                    reg_d1.h[0] += 0x20;
                                }
                                func_00129410();
                            }
                        }
                        (*(u16 *)((u8 *)(reg_a5) + (0x26))) = 0x280U;
                        (*(u16 *)((u8 *)(reg_a5) + (0x28))) = 0xF980U;
                        (*(u16 *)((u8 *)(reg_a6) + (0x2E))) = 0xEFC0U;
                        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x2C)));
                        (*(u16 *)((u8 *)(reg_a5) + (0x2C))) -= 2;
                        if ((s32) reg_tmp.h[0] < 2) {
                            (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = 4U;
                        }
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x21)));
                        (*(u8 *)((u8 *)(reg_a5) + (0x21))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            (*(u8 *)((u8 *)(reg_a5) + (0x21))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x20)));
                            temp_v1_4 = (*(u8 *)((u8 *)(reg_a6) + (0)));
                            if (!(temp_v1_4 & 0x40)) {
                                (*(u8 *)((u8 *)(reg_a6) + (0))) = (u8) (temp_v1_4 | 0x40);
                            } else {
                                (*(u8 *)((u8 *)(reg_a6) + (0))) = (u8) (temp_v1_4 & 0xBF);
                                reg_d0.h[0] = 0x40;
                                reg_d0.h[0] -= D_0028E8D4;
                                (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) reg_d0.b[0];
                                (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 3U;
                            }
                        }
                    }
                } else {
                    (*(u16 *)((u8 *)(reg_a5) + (0x22))) -= 2;
                    if ((*(u16 *)((u8 *)(reg_a5) + (0x22))) == 0) {
                        (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 0U;
                    }
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x22)));
                    reg_a0 = (u8 *)(D_0025A440);
                    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                }
            }
            reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            temp_a0_4 = reg_d1.h[0];
            reg_d1.h[1] += 0x7FFF + 0x6E01;
            reg_d1.h[0] = (u32)temp_a0_4 + 0x7FFF + 0x7801;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2C)));
            reg_d3.h[0] = 0x440;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
            func_0019C470();
            func_0019BEC0();
            reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d1.h[0] += 0x7FFF + 0x7901;
            reg_d1.h[1] += (*(u16 *)((u8 *)(reg_a6) + (0x2E)));
            reg_d2.w = 0x18E4;
            reg_d3.h[0] = 0x1438;
            func_0019C470();
            reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a5) + (0x26)));
            reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a5) + (0x24)));
            reg_d1.h[1] += 0x600;
            reg_d2.w = 0x18E6;
            reg_d3.h[0] = 0x810;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
            func_0019C470();
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a5) + (0x28)));
            reg_d1.h[0] -= (*(u16 *)((u8 *)(reg_a5) + (0x24)));
            reg_d2.w = 0x18E5;
            func_0019C470();
            reg_a0 = (u8 *)(reg_a6);
            func_0014D220();
            return;
        }
        reg_d0.w = 0x162;
        func_001A91A0();
        func_0018D580();
        reg_d1.h[0] = 0;
        reg_d2.w = 0xF8000000;
        reg_d0.w = 0xC;
        func_00211550();
        reg_d2.w = 0x08000000;
        func_00211550();
        reg_d0.w = 8;
        reg_a4 = (u8 *)(D_0025A460);
        reg_d6.w = 6;
        do {
            reg_d1.h[1] = *(u16 *)reg_a4;
            reg_a4 += 2;
            reg_d1.h[0] = *(u16 *)reg_a4;
            reg_a4 += 2;
            func_00125EF0();
        } while ((s16)(--reg_d6.h[0]) >= 0);
        reg_d0.h[0] = 0x85;
        func_0013A780();
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
        temp_a3 = (*(u16 *)((u8 *)(reg_a6) + (4)));
        (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a3;
        (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
        (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
        (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
        (*(s16 *)((u8 *)(reg_a0) + (0x26))) = 0x400;
        (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
        reg_d0.w = 0xD;
        func_0013A780();
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
        (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
        (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
        (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
        (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
        (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFA00;
        (*(u16 *)((u8 *)(reg_a0) + (0x28))) = 0xFE00;
        (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x3A0;
        (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
        reg_d0.w = 0xD;
        func_0013A780();
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
        (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
        (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
        (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
        (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
        (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFA00;
        (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0x200;
        (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x360;
        (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
        reg_d0.w = 0xC;
        func_0013A780();
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
        (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
        (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
        (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
        (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
        (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFA00;
        (*(u16 *)((u8 *)(reg_a0) + (0x28))) = 0xFE00;
        (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
        reg_d0.h[0] = 0x85;
        func_0013A780();
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
        (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
        (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
        (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
        (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
        (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xF600;
        (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x780;
        (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
        func_0014E290();
    }
}
