#include "common.h"

s32 func_00129280();
s32 func_00129370();
s32 func_001368E0();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_0018D580();
s32 func_0019BFC0();
s32 func_0019C530();
s32 func_0019C570();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_002021F0();
s32 func_00202500();
s32 func_002027A0();
extern u16 D_00259170[];
extern u16 D_00259570[];
extern u16 D_00259770[];
extern u16 D_0025A1E0[];
extern u16 D_0028E3EC;
extern s16 *D_0028E44C;
extern Reg32 D_0028E484;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u16 D_0028E8B8;
extern u16 D_0028E8D4;
extern u16 D_0028E8DC;
extern u16 D_0028E910;
extern s16 D_0029CEA0_as_s16_a[];
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0015DC20(void) {
    s16 *temp_a0;
    s16 *temp_v1;
    s16 *temp_v1_2;
    u32 temp_a0_3;
    u32 temp_a0_4;
    u32 temp_a1;
    u32 temp_a3;
    u32 temp_a3_2;
    u32 temp_a3_3;
    u16 var_a0_2;
    u8 temp_v1_3;

    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        D_0028E484.w = 0;
        D_0028E484.h[0] = 0x7A00;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0xE00;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += D_0028E484.w;
        reg_d0.h[0] += 0x7A00;
        if (reg_tmp.h[1] != 0) {
            if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
                func_0014E290();
                return;
            }
            goto block_5;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_5:
        if ((*(s16 *)((u8 *)(reg_a5) + (0x2A))) >= 0) {
            (*(u16 *)((u8 *)(reg_a6) + (0x18))) = 0x7FFFU;
            reg_d0.w = 1;
            if (D_0029CEA0_as_s16_a[0] < 0) {
                reg_d0.w = 2;
            }
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x2A)));
            (*(u16 *)((u8 *)(reg_a5) + (0x2A))) -= reg_d0.h[0];
            if ((s32) reg_tmp.h[0] < (s32) reg_d0.h[0]) {
                (*(u16 *)((u8 *)(reg_a6) + (0x18))) = 0x2600U;
            }
        }
        temp_a0 = (s16 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(temp_a0) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
            if (((s32) (*(u16 *)((u8 *)(temp_a0) + (0x18))) < 0x980) && (D_0028E8B8 == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_17;
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
block_17:
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
            func_001368E0();
            if ((D_0028E8A0 == 0) && (D_0028E89C == 0)) {
                if ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) >= 0x1000) {
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x38)));
                    if (reg_d0.h[0] == 0) {
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
                        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x29)));
                            (*(u16 *)((u8 *)(reg_a6) + (0x38))) = 1U;
                        }
                    } else if ((reg_d0.h[0] & 0xFFFF) == 1) {
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x3B)));
                        (*(u8 *)((u8 *)(reg_a6) + (0x3B))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            (*(u8 *)((u8 *)(reg_a6) + (0x3B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x3A)));
                            (*(u16 *)((u8 *)(reg_a6) + (0x36))) += 4;
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x36)));
                            reg_a0 = (u8 *)(D_0025A1E0);
                            (*(u16 *)((u8 *)(reg_a6) + (0x32))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                            (*(u16 *)((u8 *)(reg_a6) + (0x34))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            if (reg_d0.h[0] == 0x14) {
                                (*(u16 *)((u8 *)(reg_a6) + (0x38))) = 2U;
                            }
                        }
                    } else if ((reg_d0.h[0] & 0xFFFF) == 2) {
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x3B)));
                        (*(u8 *)((u8 *)(reg_a6) + (0x3B))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            (*(u8 *)((u8 *)(reg_a6) + (0x3B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x3A)));
                            (*(u16 *)((u8 *)(reg_a6) + (0x36))) += 4;
                            if ((*(u16 *)((u8 *)(reg_a6) + (0x36))) == 0x18) {
                                (*(u16 *)((u8 *)(reg_a6) + (0x36))) = 0x10U;
                            }
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x36)));
                            reg_a0 = (u8 *)(D_0025A1E0);
                            (*(u16 *)((u8 *)(reg_a6) + (0x32))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                            (*(u16 *)((u8 *)(reg_a6) + (0x34))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                        }
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
                        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x29)));
                            reg_a0 = (u8 *)(D_0029F260_as_u16_a);
                            reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
                            if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
                                D_0028E44C = (s16 *)(reg_a0);
                                reg_a0 = (u8 *)(reg_a1);
                                reg_a1 = (u8 *)(D_0028E44C);
                            }
                            temp_v1 = (s16 *)(reg_a0);
                            if ((*(s16 *)((u8 *)(temp_v1) + (0))) >= 0) {
                                if (*(s16 *)reg_a1 < 0) {
                                    reg_a0 = (u8 *)(reg_a1);
                                    D_0028E44C = (s16 *)(temp_v1);
                                    reg_a1 = (u8 *)(temp_v1);
                                    goto block_51;
                                }
                            } else {
block_51:
                                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
                                reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
                                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                                reg_d0.h[0] += 0xF780;
                                func_002027A0();
                                reg_d6.h[0] = reg_d1.h[0];
                                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                                reg_d2.h[0] = temp_a1;
                                reg_d3.w = 0xF7800380;
                                reg_d0.w = 0xFFFD0005;
                                reg_d1.h[0] += 0xA;
                                reg_d4.w = 0;
                                func_00129370();
                                reg_d1.h[0] -= 0x14;
                                func_00129370();
                                reg_d3.w = 0xF780FC80;
                                reg_d1.h[0] = reg_d6.h[0];
                                reg_d1.h[0] += 0xA;
                                func_00129370();
                                reg_d1.h[0] -= 0x14;
                                func_00129370();
                            }
                            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x21)));
                            (*(u8 *)((u8 *)(reg_a5) + (0x21))) -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                (*(u8 *)((u8 *)(reg_a5) + (0x21))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x20)));
                                reg_d0.h[0] = 0x40;
                                reg_d0.h[0] -= D_0028E8D4;
                                (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) reg_d0.b[0];
                                (*(u16 *)((u8 *)(reg_a6) + (0x38))) = 3U;
                            }
                        }
                    } else {
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x3B)));
                        (*(u8 *)((u8 *)(reg_a6) + (0x3B))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            (*(u8 *)((u8 *)(reg_a6) + (0x3B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x3A)));
                            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x36)));
                            (*(u16 *)((u8 *)(reg_a6) + (0x36))) -= 4;
                            if ((s32) reg_tmp.h[0] < 4) {
                                (*(u16 *)((u8 *)(reg_a6) + (0x38))) = 0U;
                            } else {
                                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x36)));
                                reg_a0 = (u8 *)(D_0025A1E0);
                                (*(u16 *)((u8 *)(reg_a6) + (0x32))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                                (*(u16 *)((u8 *)(reg_a6) + (0x34))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            }
                        }
                    }
                }
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x27)));
                (*(u8 *)((u8 *)(reg_a5) + (0x27))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x27))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x26)));
                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x25)));
                    if ((*(u8 *)((u8 *)(reg_a5) + (0x24))) == reg_d0.b[0]) {
                        reg_a0 = (u8 *)(D_0029F260_as_u16_a);
                        reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
                        switch ((*(u8 *)((u8 *)(reg_a5) + (2)))) { case 0: break; default:
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
                                goto block_71;
                            }
                        } else {
block_71:
                            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
                            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_a3 = (u8 *)(D_00259170);
                            temp_v1_3 = (*(u8 *)((u8 *)(reg_a6) + (0)));
                            if (temp_v1_3 & 0x40) {
                                (*(u8 *)((u8 *)(reg_a6) + (0))) = (u8) (temp_v1_3 & 0xBF);
                                goto block_set;
                            }
                            (*(u8 *)((u8 *)(reg_a6) + (0))) = (u8) (temp_v1_3 | 0x40);
                            reg_d0.h[0] += 0x5C0;
                            reg_d1.h[0] += 0xA40;
                            func_002021F0();
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
                            func_00202500();
                            (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = (u16) reg_d1.h[0];
                            reg_d1.h[0] &= 0x3E;
                            reg_d1.h[0] += reg_d1.h[0];
                            (*(u16 *)((u8 *)(reg_a6) + (0x26))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                            (*(u16 *)((u8 *)(reg_a6) + (0x28))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                            goto block_join;
block_set:
                            reg_d0.h[0] += 0x5C0;
                            reg_d1.h[0] += 0xF600;
                            func_002021F0();
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x30)));
                            func_00202500();
                            (*(u16 *)((u8 *)(reg_a6) + (0x30))) = (u16) reg_d1.h[0];
                            reg_d1.h[0] &= 0x3E;
                            reg_d1.h[0] += reg_d1.h[0];
                            (*(u16 *)((u8 *)(reg_a6) + (0x2C))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                            (*(u16 *)((u8 *)(reg_a6) + (0x2E))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                        }
                    }
                }
            }
block_join:
            func_0019BFC0();
            reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            temp_a0_3 = reg_d1.h[0];
            reg_d1.h[1] += 0xF400;
            reg_d1.h[0] = (u32)temp_a0_3 + 0xFB00;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x32)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x34)));
            reg_d3.h[0] = 0x428;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
            func_0019C570();
            reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            temp_a0_4 = reg_d1.h[0];
            reg_d1.h[1] += 0xFFC0;
            reg_d1.h[0] = (u32)temp_a0_4 + 0x640;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x26)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
            reg_d3.h[0] = 0x620;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
            func_0019C570();
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d1.h[0] += 0xF200;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x2C)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2E)));
            func_0019C570();
            if ((D_0028E910 == 0) && (D_0028E3EC != 0)) {
                reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d1.h[1] += 0xD400;
                reg_d1.h[0] += 0x100;
                reg_d2.w = 0x1874;
                reg_d3.h[0] = 0x848;
                reg_d4.h[0] = 0x18;
                func_0019C530();
            }
            reg_a0 = (u8 *)(reg_a6);
            func_0014D220();
            if ((D_0028E8A0 == 0) && (D_0028E89C == 0) && ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) >= 0x1000)) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
                (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= 1;
                switch (reg_tmp.b[0]) {
                case 0:
                    (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x28)));
                    reg_a4 = (u8 *)(D_00259570);
                    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] &= 0x3E;
                    reg_d5.h[0] += reg_d5.h[0];
                    reg_d5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a4;
                    reg_d5.h[0] = ((reg_d5.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)(reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
                    reg_d0.w = 0x40007;
                    reg_d4.w = 0;
                    reg_d5.h[0] += 0xA40;
                    reg_d5.h[1] += 0x5C0;
                    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    reg_d1.b[0] *= 4;
                    reg_d7.h[0] = 6;
                    reg_a0 = (u8 *)(D_00259770);
                    reg_d1.h[0] -= 0x2D;
                    do {
                        reg_d3.h[0] = reg_d1.h[0];
                        reg_d3.h[0] += 2;
                        reg_d3.h[0] &= 0xFC;
                        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                        reg_d3.w += reg_d5.w;
                        func_00129280();
                        reg_d1.h[0] += 0xF;
                    } while ((s16)(--reg_d7.h[0]) >= 0);
                    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x30)));
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] &= 0x3E;
                    reg_d5.h[0] += reg_d5.h[0];
                    reg_d5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a4;
                    reg_d5.h[0] = ((reg_d5.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)(reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
                    reg_d7.h[0] = 6;
                    reg_a0 = (u8 *)(D_00259770);
                    reg_d5.h[0] += 0xF600;
                    reg_d5.h[1] += 0x5C0;
                    reg_d1.b[0] *= 4;
                    reg_d1.h[0] -= 0x2D;
                    do {
                        reg_d3.h[0] = reg_d1.h[0];
                        reg_d3.h[0] += 2;
                        reg_d3.h[0] &= 0xFC;
                        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                        reg_d3.w += reg_d5.w;
                        func_00129280();
                        var_a0_2 = (u32)reg_d1.h[0] + 0xF;
                        reg_d1.h[0] = var_a0_2;
                    } while ((s16)(--reg_d7.h[0]) >= 0);
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x25)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x25))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x24)));
                        reg_d0.h[0] = 0x80;
                        reg_d0.h[0] -= D_0028E8DC;
                        (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) reg_d0.b[0];
                    }
                    return;
                }
            }
        } else {
            reg_d0.w = 0x271;
            func_001A91A0();
            func_0018D580();
            reg_d0.w = 0xD;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(s16 *)((u8 *)(reg_a0) + (0x26))) = 0x600;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
            reg_d0.w = 5;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a3 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a3;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFC00;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            reg_d0.w = 4;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(s16 *)((u8 *)(reg_a0) + (0x26))) = 0x200;
            (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0x800;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            reg_d0.w = 4;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(s16 *)((u8 *)(reg_a0) + (0x26))) = 0x200;
            (*(u16 *)((u8 *)(reg_a0) + (0x28))) = 0xF600;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
            reg_d0.w = 8;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xF800;
            (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0x600;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            reg_d0.w = 8;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a3_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a3_2;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xF800;
            (*(u16 *)((u8 *)(reg_a0) + (0x28))) = 0xF800;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            reg_d0.w = 4;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFC00;
            (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0xE00;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
            reg_d0.w = 4;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a3_3 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a3_3;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFC00;
            (*(u16 *)((u8 *)(reg_a0) + (0x28))) = 0xF000;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            func_0014E290();
        }
    }
}
