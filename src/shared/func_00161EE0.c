#include "common.h"

extern s8 D_0028E408;

s32 func_00128930();
s32 func_001368E0();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_0016A9B0();
s32 func_0018D500();
s32 func_0019BFC0();
s32 func_0019C530();
s32 func_0019C570();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_002021F0();
s32 func_00202500();
s32 func_00203120();
extern u16 D_00259170[];
extern u16 D_00259570[];
extern u16 D_0028E3EC;
extern s16 *D_0028E44C;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u16 D_0028E8B8;
extern u16 D_0028E8CC;
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern u16 D_0028E928;
extern u16 D_0029F1F0[];
extern u16 D_0029F260[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00161EE0(void) {
    s16 *temp_v1;
    s16 *var_a0;
    s16 *var_a1;
    u32 temp_a0;
    u32 temp_a2_2;
    u32 temp_a2_3;
    u32 temp_a3;
    u32 temp_a0_3;

    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        func_00203120();
        if (D_0028E408 != 0) {
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
        var_a0 = (s16 *)(reg_a6);
        reg_d1.b[0] = (*(u8 *)((u8 *)(var_a0) + (1)));
        reg_d1.b[0] |= (*(u8 *)((u8 *)(var_a0) + (0x21)));
        reg_d1.h[0] &= 0x5C;
        var_a1 = (s16 *)(var_a0 + 1);
        if (reg_d1.h[0] == 0) {
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
            if (((s32) (*(u16 *)((u8 *)(var_a0) + (0x18))) < 0x1C0) && (D_0028E8B8 == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_14;
        }
        reg_d0.h[0] = 0xA3;
        (*(u8 *)((u8 *)(var_a0) + (1))) &= reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x21))) &= reg_d0.b[0];
        func_001A9000();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
        }
        var_a1 = (s16 *)(reg_a6 + 0x18);
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1C)));
        reg_d0.b[0] ^= reg_d2.b[0];
        reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x18)));
        var_a0 = (s16 *) (*(u16 *)((u8 *)(reg_a6) + (0x38)));
        if ((s16)(var_a0) < (s16) reg_d4.h[0]) {
            reg_d4.h[0] = (u16) var_a0;
        }
        (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) reg_d4.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x38))) = (u16) reg_d4.h[0];
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x18))) >= 0) {
block_14:
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
            func_001368E0();
            if ((D_0028E8A0 == 0) && (D_0028E89C == 0)) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
                (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x22)));
                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x21)));
                    if ((*(u8 *)((u8 *)(reg_a5) + (0x20))) == reg_d0.b[0]) {
                        reg_a0 = (u8 *)(D_0029F260);
                        reg_a1 = (u8 *)(D_0029F1F0);
                        switch ((*(u8 *)((u8 *)(reg_a5) + (2)))) { case 0: break; default:
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
                                goto block_23;
                            }
                        } else {
block_23:
                            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
                            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_d0.h[0] += 0x7FFF + 0x7901;
                            func_002021F0();
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
                            func_00202500();
                            (*(u16 *)((u8 *)(reg_a5) + (0x28))) = (u16) reg_d1.h[0];
                            reg_a3 = (u8 *)(D_00259170);
                            reg_d1.h[0] &= 0x3E;
                            reg_d1.h[0] += reg_d1.h[0];
                            (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                            (*(u16 *)((u8 *)(reg_a5) + (0x26))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                        }
                    }
                }
            }
            func_0019BFC0();
            reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            temp_a0 = reg_d1.h[0];
            reg_d1.h[1] += 0x7FFF + 0x7301;
            reg_d1.h[0] = (u32)temp_a0 + 0x7FFF + 0x7C01;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x24)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
            reg_d3.h[0] = 0x620;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
            func_0019C570();
            if ((D_0028E910 == 0) && (D_0028E3EC != 0) && (D_0028E91C != 2)) {
                reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d1.h[1] += 0xE400;
                reg_d1.h[0] += 0x400;
                reg_d2.w = 0x1936;
                reg_d3.h[0] = 0x820;
                reg_d4.h[0] = 0x18;
                func_0019C530();
            }
            reg_a0 = (u8 *)(reg_a6);
            func_0014D220();
            reg_a0 = (u8 *)(reg_a6 + 0x20);
            func_0014D220();
            if ((D_0028E8A0 == 0) && (D_0028E89C == 0) && ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) >= 0x1000)) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
                (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
                switch (reg_tmp.b[0]) {
                case 0:
                    reg_d0.h[0] = 6;
                    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) reg_d0.b[0];
                    reg_a4 = (u8 *)(D_00259570);
                    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
                    reg_d0.h[0] = reg_d1.h[0];
                    reg_d0.h[0] &= 0x3E;
                    reg_d0.h[0] += reg_d0.h[0];
                    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
                    reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a4;
                    temp_a0_3 = reg_d3.w;
                    reg_d3.w = temp_a0_3 + 0xF9000000;
                    reg_d0.w = 0xFFFF000D;
                    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    func_00128930();
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x21)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x21))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a5) + (0x21))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x20)));
                        reg_d0.h[0] = 0x50;
                        reg_d0.h[0] -= D_0028E8CC;
                        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) reg_d0.b[0];
                    }
                    return;
                }
            }
        } else {
            reg_d0.w = 0x25;
            func_001A91A0();
            reg_d0.w = 0;
            if ((*(u8 *)((u8 *)(reg_a5) + (0xD))) == 0x86) {
                reg_d0.w = 8;
            }
            func_0016A9B0();
            if (D_0028E928 == 0) {
                if (reg_d0.h[0] != 8) {
                    func_0016A9B0();
                }
            }
            reg_d0.w = 5;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a3 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a3;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
            (*(s16 *)((u8 *)(reg_a0) + (0x26))) = 0x200;
            (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0x200;
            reg_d0.w = 0xC;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a2_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a2_2;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xF600;
            reg_d0.h[0] = 0x84;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a2_3 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a2_3;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xEE00;
            (*(u16 *)((u8 *)(reg_a0) + (0x28))) = 0xFE00;
            func_0018D500();
            func_0014E290();
        }
    }
}
