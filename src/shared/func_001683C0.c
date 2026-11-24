#include "common.h"

extern s8 D_0028E408;

s32 func_00128970();
s32 func_00129320();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_0018D540();
s32 func_0019BFC0();
s32 func_0019C530();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_002021F0();
s32 func_00202500();
s32 func_00202730();
extern u16 D_0025AF40[];
extern u16 D_0025AFC0[];
extern u16 D_0025B040[];
extern u16 D_0028E3EC;
extern s16 *D_0028E448;
extern Reg32 D_0028E484;
extern u16 D_0028E890;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u16 D_0028E8A8;
extern u16 D_0028E8B8;
extern u16 D_0028E8D4;
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern u16 D_0029C068[];
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001683C0(void) {
    u16 swap;
    s16 *t1;
    s16 *t2;
    u16 *t3;
    u16 t4;
    u16 t5;

    func_0014EA50();
    if (enemy_move_end_requested != 0) return;
    {
        reg_d0.h[1] = *(u16 *)(reg_a6 + 2);
        reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
        D_0028E484.w = 0;
        reg_tmp.w = 0;
        reg_d0.h[0] += D_0029C068[0];
        D_0028E484.h[0] = 0xAC00;
        reg_d0.h[0] += 0xE00;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += D_0028E484.w;
        reg_d0.h[0] += 0x7FFF + 0x2C01;
        if (reg_tmp.h[1] != 0) goto next_20;
        D_0028E484.w = 0;
        D_0028E484.h[0] = 0x8400;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] = reg_d0.h[1];
        swap = reg_tmp.h[0];
        reg_d0.h[0] += 0x600;
        reg_tmp.w = 0;
        reg_d0.h[1] = swap;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += D_0028E484.w;
        reg_d0.h[0] += 0x7FFF + 0x401;
        if (reg_tmp.h[1] == 0) goto next_30;
next_20:
        if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_1;
        func_0014E290();
        return;
next_30:
        *(u8 *)(reg_a5 + 0x17) = 1U;
next_1:
        t2 = (s16 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(t2) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
            if (((s32) (*(u16 *)((u8 *)(t2) + (0x18))) < 0x1C) && (D_0028E8B8 == 0)) {
                reg_d0.w = 0x19;
            }
            goto next_2;
        }
        (*(u8 *)((u8 *)(t2) + (1))) &= 0xA3;
        func_001A9000();
        t2 = (s16 *)(reg_a6);
        reg_d0.b[0] = (*(u8 *)((u8 *)(t2) + (0x1C)));
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
        }
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) (*(u16 *)((u8 *)(t2) + (0x18))) >= 0) {
next_2:
            *(u8 *)(reg_a6 + 0x1C) = (u8) reg_d0.b[0];
            if ((D_0028E8A0 == 0) && (D_0028E89C == 0)) {
                reg_a0 = (u8 *)(D_0029F260_as_u16_a);
                reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
                if (*(u8 *)(reg_a5 + 2) != 0) {
                    D_0028E448 = (s16 *)(reg_a1);
                    reg_a1 = (u8 *)(reg_a0);
                    reg_a0 = (u8 *)(D_0028E448);
                }
                if (*(s16 *)reg_a0 >= 0) {
                    t1 = (s16 *)(reg_a1);
                    if (*t1 < 0) {
                        reg_a1 = (u8 *)(reg_a0);
                        D_0028E448 = (s16 *)(t1);
                        reg_a0 = (u8 *)(t1);
                        goto next_3;
                    }
                } else {
next_3:
                    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
                    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
                    func_002021F0();
                    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x26);
                    func_00202500();
                    *(u16 *)(reg_a5 + 0x26) = (u16) reg_d1.h[0];
                    reg_a3 = (u8 *)(D_0025AF40);
                    reg_d1.h[0] &= 0x3E;
                    reg_d1.h[0] += reg_d1.h[0];
                    *(u16 *)(reg_a6 + 0xA) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                    *(u16 *)(reg_a6 + 0xC) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                    reg_a3 = (u8 *)(D_0025AFC0);
                    *(u16 *)(reg_a5 + 0x22) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                    *(u16 *)(reg_a5 + 0x24) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                }
                t2 = (s16 *) ((s16) *(u16 *)(reg_a6 + 2) < 0x1000);
                if (t2 == 0) {
                    t2 = (s16 *) D_0028E890;
                    if (t2 != 0) {
                        t5 = D_0028E91C;
                        reg_a4 = (u8 *)(D_0025B040);
                        reg_d1.h[0] = *(u16 *)(reg_a5 + 0x26);
                        reg_d5.h[0] = reg_d1.h[0];
                        reg_d5.h[0] &= 0x3E;
                        reg_d5.h[0] += reg_d5.h[0];
                        reg_a4 += reg_d5.h[0];
                        reg_d3.h[1] = *(u16 *)reg_a4;
                        reg_a4 += 2;
                        t3 = (u16 *)(reg_a4 + 2);
                        reg_d3.h[0] = *(u16 *)reg_a4;
                        reg_a4 = (u8 *)(t3);
                        reg_d0.w = 0x30007;
                        reg_d4.w = 0;
                        if ((t5 == 3) && ((s32) D_0028E8A8 >= 0x240)) {
                            reg_d0.w = 0xFFFE0007;
                        }
                        if (D_0028E910 != 0) {
                            reg_d0.w += 0x20000;
                        }
                        reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
                        reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
                        func_00128970();
                        *(u8 *)(reg_a5 + 0x1D) -= 1;
                        t2 = (s16 *)(reg_a5 + 0x1D);
                        if ((s8) *(u8 *)(reg_a5 + 0x1D) < 0) {
                            *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x1C);
                            reg_d0.h[0] = 0x20;
                            reg_d0.h[0] -= D_0028E8D4;
                            reg_d0.h[0] += 8;
                            *(u8 *)(reg_a5 + 0x1B) = (u8) reg_d0.b[0];
                        }
                    }
                }
            }
            func_0019BFC0();
            reg_a0 = (u8 *)(reg_a6);
            func_0014D220();
            switch (D_0028E3EC) {
            case 0:
                return;
            default:
                break;
            }
            {
                reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
                reg_d1.h[0] += 0x7FFF + 0x6E01;
                D_0028E484.h[0] = reg_d1.h[0];
                reg_d1.h[0] = reg_d1.h[1];
                reg_d1.h[1] = D_0028E484.h[0];
                reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
                reg_d1.h[0] += 0x200;
                reg_d2.h[1] = *(u16 *)(reg_a5 + 0x22);
                t4 = *(u16 *)(reg_a5 + 0x24);
                reg_d2.h[0] = t4;
                reg_d3.h[0] = 0x410;
                reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
                reg_d4.b[0] = 0x18;
                func_0019C530();
            }
        } else {
            reg_d0.w = 0x11;
            func_001A91A0();
            if (D_0028E910 != 0) {
                func_00202730();
                if (D_0028E408 == 0) {
                    reg_d0.w = 0x1000C;
                    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
                    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
                    reg_d4.w = 0;
                    reg_d3.w = 0;
                    func_00129320();
                }
            }
            reg_d0.w = 2;
            func_0013A780();
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
            reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1B);
            reg_d0.b[0] += 8;
            *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
            reg_d1.b[0] = *(u8 *)(reg_a6 + 0x1A);
            reg_d1.b[0] *= 4;
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d1.b[0];
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0;
            func_0018D540();
            func_0014E290();
        }
    }
}
