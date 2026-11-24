#include "common.h"

s32 func_0012FB00();
s32 func_00131590();
s32 func_001315D0();
s32 func_00132250();
s32 func_00133070();
s32 func_001330F0();
s32 func_00133840();
s32 func_00134FE0();
s32 func_0013B920();
s32 func_0016A8D0();
s32 func_0016A8E0();
s32 func_0018DED0();
s32 func_001A3020();
s32 func_001A9130();
s32 func_00200EE0();
s32 func_002071C0();
s32 func_00218B50();
s32 func_0022B660();
extern u16 D_00261F30[];
extern u16 D_00261FF0[];
extern u16 D_00262030[];
extern u16 D_00262070[];
extern u16 D_002620B0[];
extern u16 D_002622B0[];
extern u16 D_002698B0[];
extern u16 D_00269920[];
extern u16 D_00269A10[];
extern u16 D_00269A60[];
extern u8 D_00269AAE[];
extern u8 D_0028E2A0;
extern u8 D_0028E2A4;
extern s16 D_0028E3FC;
extern u16 D_0028E648;
extern u8 D_0028E854;
extern u16 D_0028E91C;
extern u8 D_0028E961;
extern u16 D_0028E970;
extern u16 D_0028E974;
extern u16 D_0028E978;
extern u16 D_0028E97C;
extern s8 D_0028EC24;
extern s8 D_0028ED60;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;
extern u16 D_0029C068[];
extern u16 D_0029C06C[];
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

#ifdef DEATH_LABEL
s32 func_00141640();
s32 func_001A7E90();
s32 func_001A8070();
s32 func_0013FCA0();
s32 func_0013FCE0();
s32 func_0013EAF0();
s32 func_0013EB60();
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 D_0028E290;
extern u8 death_D_00290568;
#endif

void func_00132420(void) {
    u32 t1;
    u32 t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;
    u32 t7;
    u32 t8;
    u32 t9;
    u32 t10;
    u32 t11;
    u32 t12;
    u32 t13;
    u32 t14;
    u32 t15;
    u8 v1;
    u8 v2;
    u8 *t16;
    u8 *v3;
    u8 *v4;

    v1 = (*(u8 *)((u8 *)(reg_a6) + (3)));
    v4 = (u8 *)(reg_a6 + 3);
    if (!(v1 & 1)) {
        (*(u8 *)((u8 *)(reg_a6) + (3))) = (u8) (v1 | 1);
        D_0028E961 |= 2;
        reg_d0.w = 0;
        t5 = reg_d0.h[0];
        D_0029C068[0] = t5;
        D_0029C06C[0] = t5;
        reg_a0 = (u8 *)(D_00261F30);
        reg_d0.h[0] = 0x11;
        func_001A3020();
        reg_a0 = (u8 *)(D_00261FF0);
        reg_d0.h[0] = 0x12;
        func_001A3020();
        reg_a0 = (u8 *)(D_00262030);
        reg_d0.h[0] = 0x13;
        func_001A3020();
        reg_a0 = (u8 *)(D_00262070);
        reg_d0.h[0] = 0x14;
        func_001A3020();
        reg_a0 = (u8 *)(D_002620B0);
        reg_d0.h[0] = 0x15;
        func_001A3020();
        reg_a0 = (u8 *)(D_002622B0);
        reg_d0.h[0] = 0x16;
        func_001A3020();
        reg_a0 = (u8 *)(D_00261FF0);
        reg_d0.h[0] = 0x10;
        func_001A3020();
        return;
    }
    if (!(v1 & 4)) {
        (*(u8 *)((u8 *)(reg_a6) + (3))) = (u8) (v1 | 4);
        (*(u16 *)((u8 *)(reg_a6) + (4))) = 1U;
        func_0012FB00();
        return;
    }
    t8 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    t16 = (u8 *)(reg_a6 + 4);
    if (t8 != 0) {
        (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (t8 - 1);
        if ((*(u16 *)((u8 *)(reg_a6) + (4))) != 0) goto next_290;
        {
            reg_a0 = (u8 *)(D_00269A10);
            reg_a1 = (u8 *)(reg_a6 + 6);
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_tmp.w = 0xA0000;
            reg_a0 += 2;
            reg_a1 += 2;
            (*(u16 *)((u8 *)(reg_a6) + (0x3A))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (0x3C))) = (u16) reg_tmp.h[0];
            reg_tmp.w = 0x4D001C00;
            (*(u16 *)((u8 *)(reg_a6) + (0x40))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (0x42))) = (u16) reg_tmp.h[0];
            reg_tmp.w = 0x2D001C00;
            (*(u16 *)((u8 *)(reg_a6) + (0x44))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (0x46))) = (u16) reg_tmp.h[0];
            reg_tmp.w = 0x0E001C00;
            (*(u16 *)((u8 *)(reg_a6) + (0x48))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (0x4A))) = (u16) reg_tmp.h[0];
            (*(s16 *)((u8 *)(reg_a6) + (0x4C))) = 0;
            (*(s16 *)((u8 *)(reg_a6) + (0x4E))) = 0;
            (*(s16 *)((u8 *)(reg_a6) + (0x50))) = 0;
            (*(s16 *)((u8 *)(reg_a6) + (0x52))) = 0;
            reg_tmp.w = 0xBCF;
            (*(u16 *)((u8 *)(reg_a6) + (0x54))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (0x56))) = (u16) reg_tmp.h[0];
            reg_tmp.w = 0xC0F;
            (*(u16 *)((u8 *)(reg_a6) + (0x58))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (0x5A))) = (u16) reg_tmp.h[0];
        }
next_290:
        return;
    } else {
        if ((*(s16 *)((u8 *)(reg_a6) + (6))) >= 0) {
            reg_a0 = (u8 *)(D_00269A60);
            reg_d1.w = 0;
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (6)));
            reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            (*(u16 *)((u8 *)(reg_a6) + (8))) -= reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (0xC))) += reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (6))) += 2;
            reg_a0 += reg_d1.w;
            t9 = (*(u16 *)((u8 *)(reg_a6) + (0x16)));
            if (t9 != 0) {
                (*(u16 *)((u8 *)(reg_a6) + (0x16))) = (u16) (t9 - reg_d0.h[0]);
                t10 = (*(u16 *)((u8 *)(reg_a6) + (0x16)));
                v3 = (u8 *)(reg_a6 + 0x16);
                if ((t10 != 0) && ((s16)(t10) < 0)) {
                    reg_d0.h[0] = t10;
                    reg_d0.h[0] *= 0xFFFF;
                    (*(u16 *)((u8 *)(reg_a6) + (0x16))) = 0U;
                    goto block_15;
                }
            } else {
block_15:
                (*(u16 *)((u8 *)(reg_a6) + (0xA))) -= reg_d0.h[0];
                v4 = (u8 *)(reg_a6);
                v3 = (u8 *)((void *) (*(u16 *)((u8 *)(v4) + (0xE))));
                (*(u16 *)((u8 *)(v4) + (0xE))) = (u16) (v3 + reg_d0.h[0]);
                if (D_00269AAE == reg_a0) {
                    (*(u16 *)((u8 *)(reg_a6) + (6))) = 0xFFFF;
                }
            }
            if (D_0029F260[0] >= 0) {
                (*(u16 *)((u8 *)(reg_a6) + (8))) = 0U;
                (*(u16 *)((u8 *)(reg_a6) + (0xA))) = 0U;
            }
            if (D_0029F1F0[0] >= 0) {
                (*(u16 *)((u8 *)(reg_a6) + (0xC))) = 0x40U;
                (*(u16 *)((u8 *)(reg_a6) + (0xE))) = 0x40U;
            }
            if ((*(s16 *)((u8 *)(reg_a6) + (6))) < 0) {
                D_0028E854 |= 8;
            }
            func_001330F0();
            return;
        }
        if (v1 & 2) {
            (*(u8 *)((u8 *)(reg_a6) + (3))) = (u8) (v1 | 2);
        } else {
            (*(u8 *)((u8 *)(reg_a6) + (3))) = (u8) (v1 | 2);
            (*(u16 *)((u8 *)(reg_a6) + (0x2C))) = 0x18U;
            reg_d7.w = 0;
            if (D_0029F260[0] < 0) {
                reg_d0.h[0] = D_0028E97C;
                reg_d0.h[0] += D_0028E978;
                if (reg_d0.h[0] != 0) {
                    reg_d0.h[0] = D_0028E978;
                    reg_d7.w = 1;
                    reg_d5.h[0] = reg_d0.h[0];
                    func_00200EE0();
                    (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) reg_d2.h[0];
                    t1 = reg_d5.h[0];
                    reg_d5.h[0] = t1 * 0xA;
                    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) reg_d5.h[0];
                    reg_d0.h[0] = D_0028E97C;
                    reg_d5.h[0] = reg_d0.h[0];
                    func_00200EE0();
                    (*(u16 *)((u8 *)(reg_a6) + (0x1C))) = (u16) reg_d2.h[0];
                    t3 = reg_d5.h[0];
                    reg_d5.h[0] = t3 * 0x14;
                    (*(u16 *)((u8 *)(reg_a6) + (0x1E))) = (u16) reg_d5.h[0];
                }
            }
            if (D_0029F1F0[0] < 0) {
                reg_d0.h[1] = D_0028E974;
                reg_d0.h[0] = D_0028E970;
                if (reg_d0.w != 0) {
                    reg_d0.h[0] = D_0028E970;
                    reg_d7.w = 1;
                    reg_d5.h[0] = reg_d0.h[0];
                    func_00200EE0();
                    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_d2.h[0];
                    t2 = reg_d5.h[0];
                    reg_d5.h[0] = t2 * 0xA;
                    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_d5.h[0];
                    reg_d0.h[0] = D_0028E974;
                    reg_d5.h[0] = reg_d0.h[0];
                    func_00200EE0();
                    (*(u16 *)((u8 *)(reg_a6) + (0x26))) = (u16) reg_d2.h[0];
                    t3 = reg_d5.h[0];
                    reg_d5.h[0] = t3 * 0x14;
                    (*(u16 *)((u8 *)(reg_a6) + (0x28))) = (u16) reg_d5.h[0];
                }
            }
            if (reg_d7.h[0] == 0) {
                (*(u16 *)((u8 *)(reg_a6) + (0x2C))) = 4U;
            }
        }
        func_001330F0();
        func_00133840();
        t11 = (*(u16 *)((u8 *)(reg_a6) + (0x2C)));
        if (t11 != 0) {
            (*(u16 *)((u8 *)(reg_a6) + (0x2C))) = (u16) (t11 - 1);
            return;
        }
        if (!((*(u8 *)((u8 *)(reg_a6) + (3))) & 8)) {
            reg_d7.w = 0;
            reg_d6.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1A)));
            reg_d6.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x1E)));
            if (reg_d6.h[0] != 0) {
                func_0016A8D0();
                if ((D_0028ED7C == 2) && (D_0028EC24 == 1)) {
                    func_0016A8E0();
                }
                t12 = reg_d0.h[0] & 0x70;
                reg_d0.h[0] = t12;
                if (t12 & 0xFFFF) {
                    reg_d0.h[0] = reg_d6.h[0];
                    func_00200EE0();
                    reg_d0.w = reg_d2.w;
                    reg_d0.w *= 0x10;
                    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = 0U;
                    (*(u16 *)((u8 *)(reg_a6) + (0x1E))) = 0U;
                    goto block_48;
                }
                reg_d6.w = 0;
                t13 = (*(u16 *)((u8 *)(reg_a6) + (0x1A)));
                if (t13 != 0) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) (t13 - 5);
                    reg_d0.w = 0x50;
                    reg_d7.h[0] = 1;
                    reg_d1.w = 0x10;
                    func_001A9130();
                    func_00131590();
                    reg_d6.w = 1;
                }
                t14 = (*(u16 *)((u8 *)(reg_a6) + (0x1E)));
                if (t14 != 0) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x1E))) = (u16) (t14 - 5);
                    reg_d0.w = 0x50;
block_48:
                    reg_d7.h[0] = 1;
                    reg_d1.w = 0x10;
                    func_001A9130();
                    if (reg_d6.h[0] == 0) {
                        func_00131590();
                    }
                }
            }
            reg_d6.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
            reg_d6.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x28)));
            if (reg_d6.h[0] != 0) {
                func_0016A8E0();
                if ((D_0028ED7C == 2) && (D_0028EC24 == 0)) {
                    func_0016A8D0();
                }
                t15 = reg_d0.h[0] & 0x70;
                reg_d0.h[0] = t15;
                if (t15 & 0xFFFF) {
                    reg_d0.h[0] = reg_d6.h[0];
                    func_00200EE0();
                    reg_d0.w = reg_d2.w;
                    reg_d0.w *= 0x10;
                    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = 0U;
                    (*(u16 *)((u8 *)(reg_a6) + (0x28))) = 0U;
                    goto block_60;
                }
                reg_d6.w = 0;
                t6 = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
                switch (t6) { case 0: break; default:
                    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) (t6 - 5);
                    reg_d0.w = 0x50;
                    reg_d7.h[0] = 1;
                    reg_d1.w = 8;
                    func_001A9130();
                    func_001315D0();
                    reg_d6.w = 1;
                }
                t7 = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
                if (t7 != 0) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x28))) = (u16) (t7 - 5);
                    reg_d0.w = 0x50;
block_60:
                    reg_d7.h[0] = 1;
                    reg_d1.w = 8;
                    func_001A9130();
                    if (reg_d6.h[0] == 0) {
                        func_001315D0();
                    }
                }
            }
            if (reg_d7.h[0] != 0) goto next_499;
            {
                (*(u8 *)((u8 *)(reg_a6) + (3))) |= 8;
                reg_d0.h[0] = 8;
                if (D_0028E648 == 0) {
                    reg_d0.h[0] = 1;
                }
                (*(u16 *)((u8 *)(reg_a6) + (0x2C))) = (u16) reg_d0.h[0];
            }
next_499:
            return;
        } else {
            if ((*(s16 *)((u8 *)(reg_a6) + (0x3E))) >= 0) {
                func_00132250();
                if ((*(s16 *)((u8 *)(reg_a6) + (0x3E))) < 0) {
                    D_0028E854 |= 4;
                }
            }
#ifdef DEATH_LABEL
            if ((D_0028E854 & 2) && (v2 = (*(u8 *)((u8 *)(reg_a5) + (7))), (v2 != 0xB)) && (v2 != 0x15) && (v2 != 0x16)) {
                if ((*(u16 *)((u8 *)(reg_a5) + (4))) != 0) {
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (4)));
                    func_00134FE0();
                } else {
                    reg_d0.h[0] = 0;
                    func_00134FE0();
                }
                if (((*(u16 *)((u8 *)(reg_a5) + (4))) == 0) && (D_0028ED80 != 1)) {
                    reg_a0 = (u8 *)(D_00269920);
                    (*(u8 *)((u8 *)(reg_a5) + (7))) = 0x15U;
                    D_0028ED60 = 1;
                    func_00141640();
                    if (D_0029F260[0] < 0) {
                        func_001A7E90();
                        func_0013FCA0();
                        func_0013EAF0();
                    }
                    if (D_0029F1F0[0] < 0) {
                        func_001A8070();
                        func_0013FCE0();
                        func_0013EB60();
                    }
                    reg_d0.h[0] = 0x13;
                    func_002071C0();
                } else if (D_0028E290 == 2) {
                    death_D_00290568 = 0;
                    reg_a0 = (u8 *)(D_00269920);
                    (*(u8 *)((u8 *)(reg_a5) + (7))) = 0x16U;
                    func_00141640();
                    if (D_0029F260[0] < 0) {
                        func_001A7E90();
                        func_0013FCA0();
                        func_0013EAF0();
                    }
                    if (D_0029F1F0[0] < 0) {
                        func_001A8070();
                        func_0013FCE0();
                        func_0013EB60();
                    }
                    reg_d0.h[0] = 0x13;
                    func_002071C0();
                } else {
                    if ((D_0028ED80 != 0) || (D_0028ED7C == 2)) {
                        reg_a0 = (u8 *)D_00269920;
                    } else {
                        reg_a0 = (u8 *)D_002698B0;
                    }
                    (*(u8 *)((u8 *)(reg_a5) + (7))) = 0xBU;
                    func_0013B920();
                    (*(u16 *)((u8 *)(reg_a5) + (8))) = (u16) reg_d0.h[1];
                    (*(u16 *)((u8 *)(reg_a5) + (0xA))) = (u16) reg_d0.h[0];
                }
                reg_d1.w = 0;
                func_0018DED0();
            }
#else
            if ((D_0028E854 & 2) && (v2 = (*(u8 *)((u8 *)(reg_a5) + (7))), (v2 != 0xB)) && (v2 != 0x15)) {
                if ((D_0028ED80 != 0) || (v2 = D_0028ED7C, (v2 == 2))) {
                    if (D_0028E2A4 != 0) {
                        D_0028E2A4 -= 1;
                        return;
                    }
                    D_0028E2A4 = 0;
                    D_0028E2A0 = 0;
                    goto block_77;
                }
block_77:
                t4 = (*(u16 *)((u8 *)(reg_a5) + (4)));
                if (t4 != 0) {
                    if ((D_0028ED80 != 0) || (D_0028ED7C == 2)) {
                        D_0028E2A4 = 0;
                        D_0028E2A0 = 0;
                    } else {
                        reg_d0.h[0] = t4;
                        func_00134FE0();
                        if (D_0028E2A4 != 0) {
                            D_0028E2A4 -= 1;
                        }
                        if ((D_0028E3FC != D_0028E91C) && (D_0028E2A4 == 0)) {
                            func_00218B50(D_0028E3FC);
                        }
                    }
                    if ((D_0028E2A0 == 0) && (func_00133070() != 0)) {
                        if (func_0022B660() != 0) {
                            D_0028E2A0 = 1;
                            goto block_90;
                        }
                    } else {
block_90:
                        if (D_0028E3FC == D_0028E91C) {
                            goto block_91;
                        }
                    }
                } else {
block_91:
                    if (((*(u16 *)((u8 *)(reg_a5) + (4))) == 0) && (v2 = 1, (D_0028ED80 != 1))) {
                        reg_a0 = (u8 *)(D_00269920);
                        (*(u8 *)((u8 *)(reg_a5) + (7))) = 0x15U;
                        D_0028ED60 = 1;
                        reg_d0.h[0] = 0x13;
                        func_002071C0();
                    } else {
                        if ((D_0028ED80 != 0) || (D_0028ED7C == 2)) {
                            reg_a0 = (u8 *)D_00269920;
                        } else {
                            reg_a0 = (u8 *)D_002698B0;
                        }
                        (*(u8 *)((u8 *)(reg_a5) + (7))) = 0xBU;
                        func_0013B920();
                        (*(u16 *)((u8 *)(reg_a5) + (8))) = (u16) reg_d0.h[1];
                        (*(u16 *)((u8 *)(reg_a5) + (0xA))) = (u16) reg_d0.h[0];
                    }
                    reg_d1.w = 0;
                    func_0018DED0();
                }
            }
#endif
        }
    }
}
