#include "common.h"

extern s8 D_0028E408;

s32 func_001292C0();
s32 func_00129320();
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
s32 func_00201100();
s32 func_002021F0();
s32 func_00202500();
s32 func_002026F0();
s32 func_00211550();
extern u16 D_00258FF0[];
extern u16 D_00259370[];
extern u16 D_00259870[];
extern u16 D_0025B740[];
extern s16 *D_0028E44C;
extern u16 D_0028E474_as_u16;
extern Reg32 D_0028E484;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u16 D_0028E8A8;
extern u16 D_0028E8B8;
extern u16 D_0028E91C;
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0016ED40(void) {
    s16 *t1;
    s16 *t2;
    u16 t3;
    u16 t4;
    u16 t5;

    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
        D_0028E484.w = 0;
        D_0028E484.h[0] = 0x6E00;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1000;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += D_0028E484.w;
        reg_d0.h[0] += 0x6E00;
        if (reg_tmp.h[1] != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                func_0014E290();
                return;
            }
            goto next_1;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
next_1:
        t1 = (s16 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(t1) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
            if (((s32) (*(u16 *)((u8 *)(t1) + (0x18))) < 0x7C0) && (D_0028E8B8 == 0)) {
                reg_d0.w = 0x19;
            }
            goto next_2;
        }
        (*(u8 *)((u8 *)(t1) + (1))) &= 0xA3;
        func_001A9000();
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
        }
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1C);
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) *(u16 *)(reg_a6 + 0x18) >= 0) {
next_2:
            *(u8 *)(reg_a6 + 0x1C) = (u8) reg_d0.b[0];
            func_001368E0();
            if (D_0028E8A0 == 0) {
                *(u16 *)(reg_a6 + 6) = 0xF000U;
                if ((s32) *(u8 *)(reg_a6 + 0x1A) < 0x40) {
                    *(u16 *)(reg_a6 + 0x36) += 0x20;
                    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x36);
                    reg_d0.h[0] &= 0x40;
                    *(u16 *)(reg_a6 + 6) += reg_d0.h[0];
                    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x27);
                    *(u8 *)(reg_a6 + 0x27) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a6 + 0x27) = (u8) *(u8 *)(reg_a6 + 0x26);
                        if (*(u8 *)(reg_a6 + 0x1A) == 0) {
                            *(u16 *)(reg_a6 + 0x28) += 4;
                            if (*(u16 *)(reg_a6 + 0x28) == 0x10) {
                                *(u16 *)(reg_a6 + 0x28) = 0U;
                            }
                        } else {
                            reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x28);
                            *(u16 *)(reg_a6 + 0x28) -= 4;
                            if ((s32) reg_tmp.h[0] < 4) {
                                *(u16 *)(reg_a6 + 0x28) = 0xCU;
                            }
                        }
                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x28);
                        reg_a0 = (u8 *)(D_0025B740);
                        *(u16 *)(reg_a6 + 0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                        *(u16 *)(reg_a6 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    }
                }
            }
            if ((D_0028E8A0 == 0) && (D_0028E89C == 0)) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                *(u8 *)(reg_a5 + 0x23) -= 1;
                if (((s32) reg_tmp.b[0] <= 0) && (*(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22), reg_d0.b[0] = *(u8 *)(reg_a5 + 0x21), (*(u8 *)(reg_a5 + 0x20) == reg_d0.b[0]))) {
                    reg_a0 = (u8 *)(D_0029F260_as_u16_a);
                    reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
                    if (*(u8 *)(reg_a5 + 2) != 0) {
                        D_0028E44C = (s16 *)(reg_a0);
                        reg_a0 = (u8 *)(reg_a1);
                        reg_a1 = (u8 *)(D_0028E44C);
                    }
                    t2 = (s16 *)(reg_a0);
                    if ((*(s16 *)((u8 *)(t2) + (0))) >= 0) {
                        if (*(s16 *)reg_a1 < 0) {
                            reg_a0 = (u8 *)(reg_a1);
                            D_0028E44C = (s16 *)(t2);
                            reg_a1 = (u8 *)(t2);
                            goto next_3;
                        }
                    } else {
next_3:
                        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                        reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                        reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
                        t3 = *(u16 *)(reg_a6 + 4);
                        reg_d1.h[0] = t3;
                        reg_a3 = (u8 *)(D_00258FF0);
                        reg_d0.h[0] += 0xB00;
                        func_002021F0();
                        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x28);
                        func_00202500();
                        *(u16 *)(reg_a5 + 0x28) = (u16) reg_d1.h[0];
                        reg_d1.h[0] &= 0x3E;
                        reg_d1.h[0] += reg_d1.h[0];
                        *(u16 *)(reg_a5 + 0x24) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                        *(u16 *)(reg_a5 + 0x26) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                        goto next_4;
                    }
                } else {
next_4:
                    if ((D_0028E8A0 == 0) && (D_0028E89C == 0) && ((s16) *(u16 *)(reg_a6 + 2) >= 0x1000)) {
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                        *(u8 *)(reg_a5 + 0x1F) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x2A);
                            reg_a4 = (u8 *)(D_00259370);
                            reg_d1.h[0] = *(u16 *)(reg_a5 + 0x28);
                            reg_d0.h[0] = reg_d1.h[0];
                            reg_d1.h[0] *= 4;
                            func_00201100();
                            reg_d1.b[0] += reg_d5.b[0];
                            reg_d0.h[0] &= 0x3E;
                            reg_d0.h[0] += reg_d0.h[0];
                            reg_d5.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
                            reg_d5.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a4;
                            reg_d0.w = 5;
                            reg_d4.w = 0;
                            D_0028E474_as_u16 = reg_d5.h[0];
                            reg_d5.h[0] = reg_d5.h[1];
                            reg_d5.h[1] = D_0028E474_as_u16;
                            reg_d5.h[0] += 0xB00;
                            D_0028E474_as_u16 = reg_d5.h[0];
                            reg_d5.h[0] = reg_d5.h[1];
                            reg_d5.h[1] = D_0028E474_as_u16;
                            reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
                            reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
                            reg_d1.h[0] -= 0x24;
                            reg_d7.h[0] = 6;
                            reg_a0 = (u8 *)(D_00259870);
                            do {
                                reg_d3.h[0] = reg_d1.h[0];
                                reg_d3.h[0] += 2;
                                reg_d3.h[0] &= 0xFC;
                                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                reg_d3.w += reg_d5.w;
                                func_00129320();
                                reg_d1.h[0] += 0xC;
                            } while ((s16)(--reg_d7.h[0]) >= 0);
                            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
                            *(u8 *)(reg_a5 + 0x21) -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                *(u8 *)(reg_a5 + 0x21) = (u8) *(u8 *)(reg_a5 + 0x20);
                                *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
                            }
                        }
                    }
                }
            }
            func_0019BEC0();
            reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
            reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
            t4 = reg_d1.h[0];
            reg_d1.h[1] += 0x500;
            reg_d1.h[0] = (u32)t4 + 0x7FFF + 0x7C01;
            reg_d2.h[1] = *(u16 *)(reg_a5 + 0x24);
            reg_d2.h[0] = *(u16 *)(reg_a5 + 0x26);
            reg_d3.h[0] = 0x620;
            reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
            func_0019C470();
            reg_a0 = (u8 *)(reg_a6);
            func_0014D220();
            if (D_0028E8A0 != 0) {
                return;
            }
            switch (D_0028E89C) {
            case 0:
                goto next_5;
            }
            return;
next_5:
            if ((s16) (*(u16 *)(reg_a6 + 2)) >= 0x1000) {
                if (reg_a5[0x31] != 0) {
                    goto next_6;
                }
                reg_tmp.b[0] = reg_a5[0x2F];
                reg_a5[0x2F] -= 1;
                if ((s32) reg_tmp.b[0] > 0) {
                    goto block_rts;
                }
                reg_a5[0x2F] = reg_a5[0x2B];
                reg_a5[0x31] = reg_a5[0x30];
                reg_a5[0x33] = 0x80;
                reg_a5[0x32] = 0x80;
                reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
                reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
                reg_d0.h[0] += 0xFA00;
                reg_d1.h[0] += 0x680;
                func_002026F0();
                if (D_0028E408 != 0) {
                    goto next_6;
                }
                reg_a5[0x33] = reg_d1.b[0];
                reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
                reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
                reg_d0.h[0] += 0x7FFF + 0x7A01;
                reg_d1.h[0] += 0x7FFF + 0x7981;
                func_002026F0();
                reg_a5[0x32] = reg_d1.b[0];
next_6:
                reg_tmp.b[0] = reg_a5[0x2F];
                reg_a5[0x2F] -= 1;
                if ((s32) reg_tmp.b[0] > 0) {
                    goto block_rts;
                }
                reg_a5[0x2F] = reg_a5[0x2B];
                reg_d1.w = 0;
                reg_d1.b[0] = reg_a5[0x33];
                func_002010A0();
                reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
                reg_d1.b[0] += reg_d0.b[0];
                reg_d0.w = 0x20016;
                reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
                reg_d3.w = 0xFA000680;
                reg_d4.w = 0;
                func_001292C0();
                reg_d1.w = 0;
                reg_d1.b[0] = reg_a5[0x32];
                func_002010A0();
                reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
                reg_d1.b[0] += reg_d0.b[0];
                reg_d0.w = 0x20016;
                reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
                reg_d3.w = 0xF9FFF980;
                reg_d4.w = 0;
                func_001292C0();
                reg_tmp.b[0] = reg_a5[0x31];
                reg_a5[0x31] -= 1;
                if ((s32) reg_tmp.b[0] > 0) {
                    goto block_rts;
                }
                reg_a5[0x2F] = reg_a5[0x2E];
block_rts:
                return;
            }
        } else {
            reg_d0.w = 0x550;
            func_001A91A0();
            func_0018D580();
            reg_d1.h[0] = 0;
            reg_d0.w = 0xC;
            reg_d2.w = 0xF8000000;
            func_00211550();
            if (D_0028E91C == 4) {
                if ((s32) D_0028E8A8 < 0x2B0) {
                    reg_d2.w = 0x08000000;
                    func_00211550();
                }
            }
            reg_d0.w = 0xD;
            func_0013A780();
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
            t5 = *(u16 *)(reg_a6 + 4);
            *(u16 *)(reg_a0 + 4) = t5;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(s16 *)(reg_a0 + 0x26) = 0x400;
            *(s16 *)(reg_a0 + 0x28) = 0;
            *(s16 *)(reg_a0 + 0x10) = 1;
            reg_d0.w = 5;
            func_0013A780();
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            *(u16 *)(reg_a0 + 0x26) = 0xF800;
            *(s16 *)(reg_a0 + 0x28) = 0x600;
            *(s16 *)(reg_a0 + 0x10) = 1;
            reg_d0.w = 5;
            func_0013A780();
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            *(u16 *)(reg_a0 + 0x26) = 0xF600;
            *(u16 *)(reg_a0 + 0x28) = 0xFA00;
            *(s16 *)(reg_a0 + 0x10) = 1;
            func_0014E290();
        }
    }
}
