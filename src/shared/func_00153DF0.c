#include "common.h"

s32 func_00128970();
s32 func_00128A20();
s32 func_00128AC0();
s32 func_00136980();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_00153770();
s32 func_001554E0();
s32 func_001555F0();
s32 func_00155700();
s32 func_00155810();
s32 func_00155920();
s32 func_0018D4E0();
s32 func_0018D580();
s32 func_0019C730();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_00202140();
s32 func_00202500();
extern u16 D_00257D20[];
extern u8 D_002593F0[];
extern u8 D_00259570[];
extern u8 D_00259870[];
extern s8 D_0028E408;
extern u16 D_0028E858;
extern u16 D_0028E85C;
extern u16 D_0028E860;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u16 D_0028E8A8;
extern u16 D_0028E8C8;
extern u16 D_0028E8CC;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u16 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00153DF0(void) {
    u16 temp_a0;
    u16 temp_a1_2;
    u16 temp_a2;
    u16 temp_a2_2;
    u16 temp_a2_3;
    u16 var_a0;
    u8 *temp_a3;
    u8 *var_a1;

    if ((s16)*(u16 *)(reg_a6 + 2) <= -0x2400) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            D_0028E860 = 0;
            func_0014E290();
            return;
        }
        goto block_4;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_4:
    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        if ((s32) D_0028E8A8 >= 0x7F) {
            D_0028E860 = 0;
            D_0028E858 = 0;
        }
        reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x42))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x44))) = (u16) reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x42))) += 0xA00;
        (*(u16 *)((u8 *)(reg_a6) + (0x44))) -= 0x600;
        (*(u16 *)((u8 *)(reg_a6) + (0x62))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x64))) = (u16) reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x62))) += 0xA00;
        (*(u16 *)((u8 *)(reg_a6) + (0x64))) += 0x600;
        (*(u16 *)((u8 *)(reg_a6) + (0x82))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x84))) = (u16) reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x82))) -= 0x300;
        (*(u16 *)((u8 *)(reg_a6) + (0xA2))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0xA4))) = (u16) reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0xA2))) -= 0x1000;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        reg_d1.b[0] |= (*(u8 *)((u8 *)(reg_a6) + (0x21)));
        reg_d1.h[0] &= 0x5C;
        if (reg_d1.h[0] != 0) {
            reg_d0.b[0] = 0xA3;
            (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a6) + (0x21))) &= reg_d0.b[0];
            func_001A9000();
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
            reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x18)));
            reg_d0.b[0] ^= reg_d2.b[0];
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x5C)));
            reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x5F)));
            reg_d0.b[0] ^= reg_d2.b[0];
            (*(u8 *)((u8 *)(reg_a6) + (0x5C))) = (u8) reg_d0.b[0];
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x7C)));
            reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x7F)));
            reg_d0.b[0] ^= reg_d2.b[0];
            (*(u8 *)((u8 *)(reg_a6) + (0x7C))) = (u8) reg_d0.b[0];
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x9C)));
            reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x9F)));
            reg_d0.b[0] ^= reg_d2.b[0];
            (*(u8 *)((u8 *)(reg_a6) + (0x9C))) = (u8) reg_d0.b[0];
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xBC)));
            reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xBF)));
            reg_d0.b[0] ^= reg_d2.b[0];
            (*(u8 *)((u8 *)(reg_a6) + (0xBC))) = (u8) reg_d0.b[0];
            reg_d2.w = 0x7FFF;
            reg_d2.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x18)));
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
            reg_tmp.w -= reg_d2.w;
            (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = (u16) reg_tmp.h[0];
            reg_d2.w = 0x7FFF;
            var_a1 = reg_a5;
            reg_d2.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x38)));
            reg_tmp.h[1] = (*(u16 *)((u8 *)(var_a1) + (0x1A)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(var_a1) + (0x1C)));
            reg_tmp.w -= reg_d2.w;
            (*(u16 *)((u8 *)(var_a1) + (0x1A))) = (u16) reg_tmp.h[1];
            var_a0 = reg_tmp.h[0];
            (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = var_a0;
            reg_d0.h[0] = 0x7FFF;
            (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (0x38))) = (u16) reg_d0.h[0];
            if ((*(u8 *)((u8 *)(reg_a6) + (0x5E))) == 0) {
                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
                if ((s32) reg_tmp.w < 0x1001) {
                    reg_d0.w = 0x13;
                    func_001A91A0();
                    reg_d0.w = 0x13;
                    func_001A91A0();
                    func_0018D4E0();
                    (*(u8 *)((u8 *)(reg_a6) + (0x5E))) = 1U;
                    (*(u8 *)((u8 *)(reg_a6) + (0x7E))) = 1U;
                    reg_d0.h[0] = 0x83;
                    func_0013A780();
                    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x42)));
                    temp_a2 = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
                    (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a2;
                    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
                    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
                    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
                    (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 2;
                    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                    reg_d0.b[0] *= 4;
                    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
                    reg_d0.h[0] = 0x83;
                    func_0013A780();
                    var_a0 = 0x10;
                    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x62)));
                    var_a1 = (void *) (*(u16 *)((u8 *)(reg_a6) + (0x64)));
                    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) var_a1;
                    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
                    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
                    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
                    (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 2;
                    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                    reg_d0.b[0] *= 4;
                    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
                }
            }
            if ((*(u8 *)((u8 *)(reg_a6) + (0xBE))) == 0) {
                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
                if ((s32) reg_tmp.w < 0x2A01) {
                    reg_d0.w = 0x11;
                    func_001A91A0();
                    (*(u8 *)((u8 *)(reg_a6) + (0xBE))) = 1U;
                    reg_d0.h[0] = 0x84;
                    func_0013A780();
                    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
                    temp_a2_2 = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
                    (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a2_2;
                    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
                    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x800;
                    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
                    (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 2;
                    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                    reg_d0.b[0] *= 4;
                    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
                    func_0018D4E0();
                }
            }
            if ((*(u8 *)((u8 *)(reg_a6) + (0x9E))) == 0) {
                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
                if ((s32) reg_tmp.w < 0x2001) {
                    reg_d0.w = 0x32;
                    func_001A91A0();
                    (*(u8 *)((u8 *)(reg_a6) + (0x9E))) = 1U;
                    reg_d0.h[0] = 0x84;
                    func_0013A780();
                    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x82)));
                    temp_a2_3 = (*(u16 *)((u8 *)(reg_a6) + (0x84)));
                    (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a2_3;
                    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
                    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x800;
                    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
                    (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 2;
                    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                    reg_d0.b[0] *= 4;
                    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
                    func_0018D4E0();
                }
            }
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
            if ((s32) reg_tmp.w < 0) {
                reg_d0.w = 0x174;
                func_001A91A0();
                reg_a1 = (u16 *)D_00257D20;
loop_19:
                temp_a0 = *reg_a1;
                reg_d1.h[0] = temp_a0;
                reg_a1 += 1;
                if ((s16) reg_d1.h[0] != -1) {
                    reg_d0.h[0] = *reg_a1;
                    reg_a1 += 1;
                    func_0013A780();
                    reg_d0.h[0] = *reg_a1;
                    reg_a1 += 1;
                    (*(u8 *)((u8 *)(reg_a0) + (0x1D))) = (u8) reg_d0.b[0];
                    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d1.h[0];
                    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) *reg_a1;
                    reg_a1 += 1;
                    (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) *reg_a1;
                    reg_a1 += 1;
                    (*(u16 *)((u8 *)(reg_a0) + (2))) = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
                    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
                    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
                    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
                    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                    reg_d0.b[0] *= 4;
                    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
                    reg_a1 += 1;
                    goto loop_19;
                }
                func_0018D580();
                func_00155920();
                if ((*(u8 *)((u8 *)(reg_a6) + (0xD8))) != 0) {
                    D_0028E85C = 0;
                }
                D_0028E858 = 0;
                D_0028E860 = 0;
                (*(u16 *)((u8 *)(reg_a6) + (0))) = 0x8000;
                (*(u16 *)((u8 *)(reg_a6) + (0x20))) = 0x8000;
                (*(u8 *)((u8 *)(reg_a6) + (0xDB))) = 1U;
                goto block_24;
            }
        } else {
block_24:
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x19)));
            (*(u8 *)((u8 *)(reg_a6) + (0x5C))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x5D)));
            (*(u8 *)((u8 *)(reg_a6) + (0x7C))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x7D)));
            (*(u8 *)((u8 *)(reg_a6) + (0x9C))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x9D)));
            (*(u8 *)((u8 *)(reg_a6) + (0xBC))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0xBD)));
        }
        if ((*(u8 *)((u8 *)(reg_a6) + (0xDB))) != 0) {
            (*(u8 *)((u8 *)(reg_a6) + (0xDA))) -= 1;
            if ((*(u8 *)((u8 *)(reg_a6) + (0xDA))) == 0) {
                func_0014E290();
                return;
            }
        }
        reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
        func_00136980();
        if (D_0028E8A0 == 0) {
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
            func_00202140();
            if (D_0028E408 == 0) {
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x5A)));
                func_00202500();
                (*(u8 *)((u8 *)(reg_a6) + (0x5A))) = (u8) reg_d1.b[0];
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x62)));
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x64)));
                func_00202140();
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x7A)));
                func_00202500();
                (*(u8 *)((u8 *)(reg_a6) + (0x7A))) = (u8) reg_d1.b[0];
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xC7)));
                (*(u8 *)((u8 *)(reg_a6) + (0xC7))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    reg_d0.h[0] = 0x20;
                    reg_d0.h[0] -= D_0028E8C8;
                    (*(u8 *)((u8 *)(reg_a6) + (0xC7))) = (u8) reg_d0.b[0];
                    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x62))) > 0x1800) {
                        if (((*(u8 *)((u8 *)(reg_a6) + (0x5E))) == 0) && (D_0028E89C == 0)) {
                            reg_d3.w = 0;
                            reg_a4 = D_00259570;
                            reg_d3.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x5A)));
                            reg_d3.b[0] += 1;
                            reg_d3.h[0] &= 0x3E;
                            reg_d3.h[0] += reg_d3.h[0];
                            reg_a4 += reg_d3.h[0];
                            reg_d5.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0)));
                            reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a4) + (2)));
                            reg_d1.w = 0;
                            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x5A)));
                            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
                            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
                            reg_a0 = reg_a6 + 0x40;
                            func_00153770();
                        }
                        if (((*(u8 *)((u8 *)(reg_a6) + (0x7E))) == 0) && (D_0028E89C == 0)) {
                            reg_d3.w = 0;
                            reg_a4 = D_00259570;
                            reg_d3.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x7A)));
                            reg_d3.b[0] += 1;
                            reg_d3.h[0] &= 0x3E;
                            reg_d3.h[0] += reg_d3.h[0];
                            reg_a4 += reg_d3.h[0];
                            reg_d5.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0)));
                            reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a4) + (2)));
                            reg_d1.w = 0;
                            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x7A)));
                            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x62)));
                            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x64)));
                            reg_a0 = reg_a6 + 0x60;
                            func_00153770();
                        }
                    }
                }
                if ((*(u8 *)((u8 *)(reg_a6) + (0x9E))) == 0) {
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x82)));
                    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x84)));
                    func_00202140();
                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x9A)));
                    func_00202500();
                    (*(u8 *)((u8 *)(reg_a6) + (0x9A))) = (u8) reg_d1.b[0];
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xC9)));
                    (*(u8 *)((u8 *)(reg_a6) + (0xC9))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        reg_d0.h[0] = 0x30;
                        reg_d0.h[0] -= D_0028E8CC;
                        (*(u8 *)((u8 *)(reg_a6) + (0xC9))) = (u8) reg_d0.b[0];
                        if (((s16) (*(u16 *)((u8 *)(reg_a6) + (0x82))) > 0x1800) && (D_0028E89C == 0)) {
                            reg_d3.w = 0;
                            reg_a4 = D_002593F0;
                            reg_d3.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x9A)));
                            reg_d1.w = 0;
                            reg_d3.h[0] &= 0x3E;
                            reg_d3.h[0] *= 4;
                            reg_a4 += reg_d3.h[0];
                            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x9A)));
                            reg_d1.b[0] += 1;
                            reg_d1.b[0] &= 0x3E;
                            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x82)));
                            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x84)));
                            reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0)));
                            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a4) + (2)));
                            reg_a0 = reg_a6 + 0x80;
                            reg_d0.w = 0x60004;
                            reg_d4.w = 0;
                            func_00128A20();
                            reg_d0.w = 0x20004;
                            func_00128A20();
                            reg_d1.b[0] += 2;
                            reg_d0.w = 0x60004;
                            func_00128A20();
                            reg_d0.w = 0x20004;
                            func_00128A20();
                            reg_d1.b[0] -= 4;
                            reg_d0.w = 0x60004;
                            func_00128A20();
                            reg_d0.w = 0x20004;
                            func_00128A20();
                        }
                    }
                }
                if ((*(u8 *)((u8 *)(reg_a6) + (0xBE))) == 0) {
                    if ((*(u8 *)((u8 *)(reg_a6) + (0xCF))) == 0) {
                        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
                        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
                        func_00202140();
                        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xBA)));
                        func_00202500();
                        (*(u8 *)((u8 *)(reg_a6) + (0xBA))) = (u8) reg_d1.b[0];
                        (*(u8 *)((u8 *)(reg_a6) + (0xCB))) -= 1;
                        if ((*(u8 *)((u8 *)(reg_a6) + (0xCB))) == 0) {
                            (*(u8 *)((u8 *)(reg_a6) + (0xCB))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0xCA)));
                            (*(u8 *)((u8 *)(reg_a6) + (0xCF))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0xCE)));
                            goto block_47;
                        }
                    } else {
block_47:
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xCD)));
                        (*(u8 *)((u8 *)(reg_a6) + (0xCD))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            reg_d0.h[0] = 8;
                            reg_d1.h[0] = D_0028E8C8;
                            reg_d1.h[0] >>= 3;
                            reg_d0.h[0] -= reg_d1.h[0];
                            (*(u8 *)((u8 *)(reg_a6) + (0xCD))) = (u8) reg_d0.b[0];
                            if (((s16) (*(u16 *)((u8 *)(reg_a6) + (0xA2))) > 0x1800) && (D_0028E89C == 0)) {
                                reg_d3.w = 0;
                                reg_a4 = D_002593F0;
                                reg_d3.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xBA)));
                                reg_d1.w = 0;
                                reg_d3.b[0] += 1;
                                reg_d3.h[0] &= 0x3E;
                                reg_d3.h[0] *= 4;
                                reg_a4 += reg_d3.h[0];
                                reg_d0.w = 0x10005;
                                reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xBA)));
                                reg_d1.b[0] += 1;
                                reg_d1.b[0] &= 0x3E;
                                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
                                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
                                reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0)));
                                reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a4) + (2)));
                                reg_a0 = reg_a6 + 0xA0;
                                reg_d4.w = 0;
                                func_00128970();
                                reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a4) + (4)));
                                reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a4) + (6)));
                                func_00128970();
                                (*(u8 *)((u8 *)(reg_a6) + (0xCF))) -= 1;
                            }
                        }
                    }
                }
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xBE)));
                reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x9E)));
                reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x7E)));
                reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x5E)));
                if (reg_d0.b[0] == 4) {
                    (*(s8 *)((u8 *)(reg_a6) + (0xD6))) = 1;
                    if ((*(u8 *)((u8 *)(reg_a6) + (0xD5))) == 0) {
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xD1)));
                        (*(u8 *)((u8 *)(reg_a6) + (0xD1))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            (*(u8 *)((u8 *)(reg_a6) + (0xD1))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0xD0)));
                            (*(u8 *)((u8 *)(reg_a6) + (0xD5))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0xD4)));
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_d0.h[0] += 0x400;
                            func_00202140();
                            if (D_0028E408 == 0) {
                                (*(u8 *)((u8 *)(reg_a6) + (0xD7))) = (u8) reg_d1.b[0];
                            }
                            goto block_56;
                        }
                    } else {
block_56:
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xD3)));
                        (*(u8 *)((u8 *)(reg_a6) + (0xD3))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            reg_d0.h[0] = 0x10;
                            reg_d1.h[0] = D_0028E8C8;
                            reg_d1.h[0] >>= 2;
                            reg_d0.h[0] -= reg_d1.h[0];
                            (*(u8 *)((u8 *)(reg_a6) + (0xD3))) = (u8) reg_d0.b[0];
                            temp_a3 = reg_a6 + 2;
                            if (((*(s16 *)((u8 *)(reg_a6) + (2))) > 0x1800) && (D_0028E89C == 0)) {
                                reg_d1.w = 0;
                                reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xD7)));
                                reg_d0.w = 0x20004;
                                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                                temp_a1_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                                reg_d2.h[0] = temp_a1_2;
                                reg_d5.w = 0x04000000;
                                reg_a0 = D_00259870;
                                reg_d4.w = 0;
                                reg_d7.b[0] = reg_d1.b[0];
                                if (!((*(u8 *)((u8 *)(reg_a6) + (0xD5))) & 1)) {
                                    (*(s8 *)((u8 *)(reg_a6) + (0xD9))) = 1;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    func_00128AC0();
                                    reg_d1.b[0] += 4;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    func_00128AC0();
                                    reg_d1.b[0] += 4;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    func_00128AC0();
                                    reg_d1.b[0] = reg_d7.b[0];
                                    reg_d1.b[0] -= 4;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    func_00128AC0();
                                    reg_d1.b[0] -= 4;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    func_00128AC0();
                                } else {
                                    reg_d1.b[0] += 2;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    func_00128AC0();
                                    reg_d1.b[0] += 4;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    func_00128AC0();
                                    reg_d1.b[0] = reg_d7.b[0];
                                    reg_d1.b[0] -= 2;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    func_00128AC0();
                                    reg_d1.b[0] -= 4;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    func_00128AC0();
                                }
                                (*(u8 *)((u8 *)(reg_a6) + (0xD5))) -= 1;
                            }
                        }
                    }
                }
            }
        }
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.w += 0xDC00F600;
        reg_d3.h[0] = 0x2450;
        reg_d2.w = 0x18C9;
        reg_d4.w = 0;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
        func_0019C730();
        func_001554E0();
        func_001555F0();
        func_00155810();
        func_00155700();
        reg_a0 = reg_a6;
        func_0014D220();
        reg_a0 = reg_a6 + 0x20;
        func_0014D220();
    }
}
