#include "common.h"

extern s8 D_0028E408;

s32 func_00125EB0();
s32 func_00128930();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_0016D290();
s32 func_00170B20();
s32 func_00170CA0();
s32 func_00170D00();
s32 func_00170DE0();
s32 func_0018D4E0();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_002021F0();
s32 func_00202500();
s32 func_00203060();
s32 func_002114C0();
extern u16 D_002590F0[];
extern u16 D_00259570[];
extern s16 *D_0028E44C;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u16 D_0028E8B8;
extern u16 D_0028E8CC;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00164040(void) {
    s16 *temp_v1;
    s16 *var_a0;

    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        func_00203060();
        if (D_0028E408 != 0) {
            if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
                func_0014E290();
                return;
            }
            goto block_5;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_5:
        var_a0 = (s16 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(var_a0) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
            if (((s32) (*(u16 *)((u8 *)(var_a0) + (0x18))) < 0x140) && (D_0028E8B8 == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_12;
        }
        (*(u8 *)((u8 *)(var_a0) + (1))) &= 0xA3;
        func_001A9000();
        var_a0 = (s16 *)(reg_a6);
        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x1C)));
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
        }
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x18)));
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) (*(u16 *)((u8 *)(var_a0) + (0x18))) >= 0) {
block_12:
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
            if (D_0028E8A0 == 0) {
                if (D_0028E89C == 0) {
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1E)));
                        var_a0 = (s16 *)(reg_a5);
                        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x1D)));
                        if ((*(u8 *)((u8 *)(var_a0) + (0x1C))) == reg_d0.b[0]) {
                            reg_a0 = (u8 *)(D_0029F260);
                            reg_a1 = (u8 *)(D_0029F1F0);
                            if ((*(u8 *)((u8 *)(var_a0) + (2))) != 0) {
                                D_0028E44C = (s16 *)(reg_a0);
                                reg_a0 = (u8 *)(reg_a1);
                                reg_a1 = (u8 *)(D_0028E44C);
                            }
                            temp_v1 = (s16 *)(reg_a0);
                            if ((*(s16 *)((u8 *)(temp_v1) + (0))) >= 0) {
                                var_a0 = (s16 *)(reg_a1);
                                if (*var_a0 < 0) {
                                    reg_a0 = (u8 *)(var_a0);
                                    D_0028E44C = (s16 *)(temp_v1);
                                    reg_a1 = (u8 *)(temp_v1);
                                    goto block_21;
                                }
                            } else {
block_21:
                                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
                                reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
                                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                                func_002021F0();
                                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x20)));
                                func_00202500();
                                var_a0 = (s16 *) reg_d1.h[0];
                                (*(u16 *)((u8 *)(reg_a5) + (0x20))) = (u16) var_a0;
                                reg_a3 = (u8 *)(D_002590F0);
                                reg_d1.h[0] &= 0x3E;
                                reg_d1.h[0] += reg_d1.h[0];
                                (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                                (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                            }
                        }
                    }
                    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) >= 0x1000) {
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
                        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x16)));
                            func_0016D290();
                            if (D_0028E408 == 0) {
                                reg_a4 = (u8 *)(D_00259570);
                                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x20)));
                                reg_d0.h[0] = reg_d1.h[0];
                                reg_d0.h[0] &= 0x3E;
                                reg_d0.h[0] += reg_d0.h[0];
                                reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
                                reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a4;
                                reg_d3.w = 0x80000 + reg_d3.w;
                                reg_d0.w = 0x20006;
                                reg_d4.w = 0;
                                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                                func_00128930();
                                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
                                (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1C)));
                                    reg_d0.h[0] = 0x40;
                                    reg_d0.h[0] -= D_0028E8CC;
                                    reg_d0.h[0] += 4;
                                    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) reg_d0.b[0];
                                }
                            }
                        }
                    }
                }
            }
            reg_d6.w = 0xF800F800;
            func_00170B20();
            reg_a0 = (u8 *)(reg_a6);
            func_0014D220();
            return;
        }
        reg_d0.w = 0x20;
        func_001A91A0();
        func_0018D4E0();
        func_00170CA0();
        reg_d0.w = 8;
        func_002114C0();
        reg_d0.w = 8;
        func_00170DE0();
        func_00125EB0();
        reg_d0.w = 0xC;
        func_0013A780();
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
        (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
        func_00170D00();
        (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
        (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x26))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
        func_0014E290();
    }
}
