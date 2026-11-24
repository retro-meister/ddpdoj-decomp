#include "common.h"

s32 func_00125EC0();
s32 func_001292C0();
s32 func_001368E0();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_0018D520();
s32 func_0019BF80();
s32 func_0019C530();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_002010A0();
s32 func_002026F0();
s32 func_00211550();
extern u16 D_0025B7E0[];
extern u8 D_0025B7F0[];
extern u8 D_0025B800[];
extern Reg32 D_0028E484;
extern u16 D_0028E894;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u16 D_0028E8B8;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0016FAE0(void) {
    u8 *t1;
    u32 t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;

    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
        D_0028E484.w = 0;
        D_0028E484.h[0] = 0x7800;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0xC00;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += D_0028E484.w;
        reg_d0.h[0] += 0x7800;
        if (reg_tmp.h[1] != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                D_0028E894 -= 1;
                func_0014E290();
                return;
            }
            goto next_1;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
next_1:
        t1 = (u8 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(t1) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
            if (((s32) (*(u16 *)((u8 *)(t1) + (0x18))) < 0x380) && (D_0028E8B8 == 0)) {
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
                *(u16 *)(reg_a6 + 6) = 0xF400U;
                if ((s32) *(u8 *)(reg_a6 + 0x1A) < 0x40) {
                    *(u16 *)(reg_a6 + 0x2E) += 0x20;
                    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2E);
                    reg_d0.h[0] &= 0x40;
                    *(u16 *)(reg_a6 + 6) -= reg_d0.h[0];
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
                        reg_a0 = (u8 *)D_0025B7F0;
                        *(u16 *)(reg_a6 + 0x2A) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                        *(u16 *)(reg_a6 + 0x2C) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    }
                }
            }
            if ((D_0028E8A0 == 0) && (D_0028E89C == 0) && (D_0028E8A0 == 0) && (D_0028E89C == 0) && ((s16) *(u16 *)(reg_a6 + 2) >= 0x1000)) {
                reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
                if (reg_d0.h[0] == 0) {
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                    *(u8 *)(reg_a5 + 0x1F) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x1F) = 0x10U;
                        *(u16 *)(reg_a5 + 0x18) = 1U;
                    }
                } else if ((reg_d0.h[0] & 0xFFFF) == 1) {
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                    *(u8 *)(reg_a5 + 0x23) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
                        if ((s16) *(u16 *)(reg_a6 + 2) < 0x6C00) {
                            *(u16 *)(reg_a5 + 0x24) += 4;
                            reg_d0.h[0] = *(u16 *)(reg_a5 + 0x24);
                            reg_a0 = (u8 *)D_0025B800;
                            *(u16 *)(reg_a5 + 0x26) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                            *(u16 *)(reg_a5 + 0x28) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            if (reg_d0.h[0] == 0x1C) {
                                *(u16 *)(reg_a5 + 0x34) = 0xFFFEU;
                                *(u16 *)(reg_a5 + 0x18) = 2U;
                            }
                        }
                    }
                } else if ((reg_d0.h[0] & 0xFFFF) == 2) {
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                    *(u8 *)(reg_a5 + 0x1F) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x2F);
                        reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
                        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
                        reg_d0.h[0] += 0xA80;
                        func_002026F0();
                        reg_d7.h[0] = reg_d1.h[0];
                        func_002010A0();
                        reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
                        reg_d1.b[0] += reg_d0.b[0];
                        reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
                        t4 = *(u16 *)(reg_a6 + 4);
                        reg_d2.h[0] = t4;
                        reg_d3.w = 0x0A800400;
                        reg_d4.w = 0;
                        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x34);
                        reg_tmp.h[0] = reg_d0.h[0];
                        reg_d0.h[0] = 0x13;
                        reg_d0.h[1] = reg_tmp.h[0];
                        func_001292C0();
                        reg_d1.h[0] = reg_d7.h[0];
                        func_002010A0();
                        reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
                        reg_d1.b[0] += reg_d0.b[0];
                        reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
                        t5 = *(u16 *)(reg_a6 + 4);
                        reg_d2.h[0] = t5;
                        reg_d3.w = 0x0A7FFC00;
                        reg_d4.w = 0;
                        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x34);
                        reg_tmp.h[0] = reg_d0.h[0];
                        reg_d0.h[0] = 0x13;
                        reg_d0.h[1] = reg_tmp.h[0];
                        func_001292C0();
                        *(u16 *)(reg_a5 + 0x34) += 1;
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
                        *(u8 *)(reg_a5 + 0x21) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x21) = (u8) *(u8 *)(reg_a5 + 0x20);
                            if (*(u8 *)(reg_a5 + 0x21) != 0) {
                                *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
                                *(u16 *)(reg_a5 + 0x18) = 3U;
                                *(u8 *)(reg_a5 + 0x23) = 0x10U;
                            }
                        }
                    }
                } else {
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                    *(u8 *)(reg_a5 + 0x23) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
                        *(u16 *)(reg_a5 + 0x24) -= 4;
                        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x24);
                        reg_a0 = (u8 *)D_0025B800;
                        *(u16 *)(reg_a5 + 0x26) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                        *(u16 *)(reg_a5 + 0x28) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                        if (reg_d0.h[0] == 0) {
                            *(u16 *)(reg_a5 + 0x18) = 0U;
                        }
                    }
                }
            }
            t2 = 0xFA00 & 0xFFFF;
            reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
            reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d1.h[0] += t2;
            D_0028E484.h[0] = reg_d1.h[0];
            reg_d1.h[0] = reg_d1.h[1];
            reg_d1.h[1] = D_0028E484.h[0];
            reg_d1.h[0] += 0x7FFF + 0x7201;
            D_0028E484.h[0] = reg_d1.h[0];
            reg_d1.h[0] = reg_d1.h[1];
            reg_d1.h[1] = D_0028E484.h[0];
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0x2A);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x2C);
            reg_d3.h[0] = 0x230;
            reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
            func_0019C530();
            func_0019BF80();
            reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
            reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d1.h[0] += 0x7FFF + 0x7A01;
            D_0028E484.h[0] = reg_d1.h[0];
            reg_d1.h[0] = reg_d1.h[1];
            reg_d1.h[1] = D_0028E484.h[0];
            reg_d1.h[0] += 0x800;
            reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2E);
            reg_d0.h[0] &= 0x40;
            reg_d1.h[0] -= reg_d0.h[0];
            D_0028E484.h[0] = reg_d1.h[0];
            reg_d1.h[0] = reg_d1.h[1];
            reg_d1.h[1] = D_0028E484.h[0];
            reg_d2.h[1] = *(u16 *)(reg_a5 + 0x26);
            reg_d2.h[0] = *(u16 *)(reg_a5 + 0x28);
            reg_d3.h[0] = 0x430;
            reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
            func_0019C530();
            reg_a0 = reg_a6;
            func_0014D220();
            if (D_0028E8A0 != 0) {
                goto block_rts;
            }
            switch (D_0028E89C) {
            case 0:
                break;
            default:
                return;
            }
            if ((s16) *(u16 *)(reg_a6 + 2) < 0x1000) {
                goto block_rts;
            }
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x31);
            *(u8 *)(reg_a5 + 0x31) -= 1;
            if ((s32) reg_tmp.b[0] > 0) {
                goto block_rts;
            }
            *(u8 *)(reg_a5 + 0x31) = (u8) *(u8 *)(reg_a5 + 0x2E);
            reg_d0.w = 0xFFFE0004;
            reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d3.w = 0xFE000000;
            reg_d7.h[0] = 7;
            reg_d1.h[0] = 0x6B;
            reg_d4.w = 0;
            do {
                func_001292C0();
                reg_d1.h[0] += 7;
            } while ((s16)(--reg_d7.h[0]) >= 0);
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x33);
            *(u8 *)(reg_a5 + 0x33) -= 1;
            if ((s32) reg_tmp.b[0] > 0) {
                goto block_rts;
            }
            *(u8 *)(reg_a5 + 0x33) = (u8) *(u8 *)(reg_a5 + 0x32);
            *(u8 *)(reg_a5 + 0x31) = (u8) *(u8 *)(reg_a5 + 0x30);
block_rts:
            return;
        } else {
            reg_d0.w = 0x130;
            func_001A91A0();
            func_0018D520();
            reg_d0.w = 0xC;
            reg_d1.h[0] = 8;
            func_00211550();
            reg_d0.w = 0xD;
            func_0013A780();
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
            t6 = *(u16 *)(reg_a6 + 4);
            *(u16 *)(reg_a0 + 4) = t6;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            *(s16 *)(reg_a0 + 0x26) = 0x400;
            *(s16 *)(reg_a0 + 0x28) = 0;
            *(s16 *)(reg_a0 + 0x10) = 1;
            reg_d0.w = 0xC;
            func_0013A780();
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(u16 *)(reg_a0 + 0x26) = 0xFA00;
            *(s16 *)(reg_a0 + 0x28) = 0x600;
            *(s16 *)(reg_a0 + 0x10) = 1;
            reg_d0.w = 0x84;
            func_0013A780();
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(u16 *)(reg_a0 + 0x26) = 0xFA00;
            *(u16 *)(reg_a0 + 0x28) = 0xFA00;
            *(s16 *)(reg_a0 + 0x10) = 1;
            D_0028E894 -= 1;
            reg_d0.w = 8;
            reg_a4 = (u8 *)(D_0025B7E0);
            reg_d6.w = 3;
            do {
                reg_d1.h[1] = *(u16 *)reg_a4;
                reg_a4 += 2;
                t3 = *(u16 *)reg_a4;
                reg_d1.h[0] = t3;
                reg_a4 += 2;
                reg_d2.w = 3;
                func_00125EC0();
            } while ((s16)(--reg_d6.h[0]) >= 0);
            func_0014E290();
        }
    }
}
