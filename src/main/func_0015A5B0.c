#include "common.h"

extern s8 D_0028E408;

s32 func_00128930();
s32 func_00128A20();
s32 func_00129320();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_0018D540();
s32 func_0019C730();
s32 func_0019C790();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_00201E20();
s32 func_00202140();
s32 func_00202500();
s32 func_002026F0();
s32 func_00203060();
extern u8 D_00258800[];
extern u8 D_0028C9D8;
extern u16 D_0028E8C8;
extern u16 D_0028E91C;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0015A5B0(void) {
    u16 temp_a1;
    u16 temp_a2;
    u8 temp_a0_3;
    u8 *temp_a0_2;

    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] -= (*(u16 *)((u8 *)(reg_a5) + (0x1E)));
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d1.h[0];
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
        if (D_0028E91C != 4) {
            reg_d1.w = 0;
            reg_d0.w = 0;
            reg_d0.b[0] = 0x28;
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x20)));
            (*(u8 *)((u8 *)(reg_a5) + (0x20))) += 2;
            func_00201E20();
            (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = (u16) reg_d2.h[0];
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a5) + (0x1E)));
            (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d1.h[0];
        }
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
            func_001A9000();
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
            reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x18)));
            reg_d0.b[0] ^= reg_d2.b[0];
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
            if ((*(s16 *)((u8 *)(reg_a6) + (0x18))) < 0) {
                reg_d0.w = 0x31;
                func_001A91A0();
                reg_d0.h[0] = 2;
                func_0013A780();
                (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (6)));
                (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (8)));
                (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
                temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a1;
                (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0xC;
                (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
                (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
                (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 2;
                (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                reg_d0.b[0] *= 4;
                (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
                func_0018D540();
                func_0014E290();
                return;
            }
            goto block_11;
        }
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x19)));
block_11:
        temp_a0_2 = (u8 *)(reg_a6 + 2);
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) > 0x1400) {
            if (D_0028E91C == 4) {
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x26)));
                if ((*(u8 *)((u8 *)(reg_a5) + (0x27))) == reg_d0.b[0]) {
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    reg_d0.h[0] += 0x3C0;
                    func_00202140();
                    if (D_0028E408 == 0) {
                        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
                        func_00202500();
                        (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) reg_d1.b[0];
                    }
                }
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x25)));
                (*(u8 *)((u8 *)(reg_a5) + (0x25))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x24)));
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    reg_d0.h[0] += 0x3C0;
                    func_002026F0();
                    if (D_0028E408 == 0) {
                        reg_d0.h[0] = reg_d1.h[0];
                        reg_a0 = (u8 *)D_00258800;
                        reg_d0.h[0] &= 0xF8;
                        reg_d0.h[0] >>= 1;
                        reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                        reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                        reg_d4.w = 0;
                        reg_d0.w = 0x10007;
                        reg_d1.h[0] += 4;
                        reg_d1.h[0] &= 0xF8;
                        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                        reg_d0.w = 0xFFFC0007;
                        func_00129320();
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x27)));
                        (*(u8 *)((u8 *)(reg_a5) + (0x27))) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            (*(u8 *)((u8 *)(reg_a5) + (0x27))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x26)));
                            reg_d0.h[0] = 0xA;
                            reg_d1.h[0] = D_0028E8C8;
                            reg_d1.h[0] >>= 1;
                            reg_d0.h[0] -= reg_d1.h[0];
                            (*(u8 *)((u8 *)(reg_a5) + (0x25))) = reg_d0.b[0];
                        }
                    }
                }
            } else {
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x26)));
                if ((*(u8 *)((u8 *)(reg_a5) + (0x27))) == reg_d0.b[0]) {
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    reg_d0.h[0] += 0x3C0;
                    func_00202140();
                    if (D_0028E408 == 0) {
                        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
                        func_00202500();
                        (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) reg_d1.b[0];
                    }
                }
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x25)));
                (*(u8 *)((u8 *)(reg_a5) + (0x25))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x24)));
                    reg_d1.w = 0;
                    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
                    reg_a0 = (u8 *)D_00258800;
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d1.b[0] += 1;
                    reg_d1.h[0] &= 0x3E;
                    reg_d3.b[0] += 2;
                    reg_d7.b[0] = reg_d1.b[0];
                    reg_d0.h[0] = reg_d1.h[0];
                    reg_d3.h[0] &= 0x3C;
                    reg_d0.h[0] *= 2;
                    reg_d1.h[0] = reg_d3.h[0];
                    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                    reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d4.w = 0;
                    reg_d0.w = 0x4000C;
                    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    func_00128930();
                    reg_d0.w = 0xFFFE000D;
                    reg_d1.h[0] = reg_d7.h[0];
                    func_00128A20();
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x27)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x27))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a5) + (0x27))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x26)));
                        reg_d0.h[0] = 0xA;
                        reg_d1.h[0] = D_0028E8C8;
                        reg_d1.h[0] >>= 2;
                        reg_d0.h[0] -= reg_d1.h[0];
                        (*(u8 *)((u8 *)(reg_a5) + (0x25))) = reg_d0.b[0];
                    }
                }
            }
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
        (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1C)));
            (*(u16 *)((u8 *)(reg_a5) + (0x1A))) += 4;
            (*(u16 *)((u8 *)(reg_a5) + (0x1A))) &= 7;
        }
        reg_a0 = &D_0028C9D8;
        reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d0.w = 0;
        reg_a0 = (u8 *) reg_tmp.w;
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
        reg_d0.b[0] += 1;
        reg_d0.h[0] &= 0x3E;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        temp_a2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.h[0] = temp_a2;
        reg_d1.w += 0xF600FA00;
        reg_d3.h[0] = 0xA30;
        reg_d4.w = 0;
        temp_a0_3 = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
        reg_d4.b[0] = temp_a0_3;
        if (D_0028E91C != 4) {
            func_0019C790();
        } else {
            func_0019C730();
        }
        reg_a0 = reg_a6;
        func_0014D220();
    }
}
