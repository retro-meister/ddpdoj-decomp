#include "common.h"

/* NONMATCHING: 97.38%; remaining diffs are nop placement at if-join labels (delay-slot fill around `if (reg_dN) reg_dN.w = K;`) */
#include "sdk/ps2sdk.h"

#include "common.h"
#include "sdk/ps2sdk.h"

#include "common.h"
#include "sdk/ps2sdk.h"

#include "common.h"

typedef void (*Fn)();

extern u8 D_0025F3B0[];
extern u8 D_0025F3C0[];
extern u8 D_0025F400[];
extern u8 D_0025F430[];
extern u8 D_0029F110[];
s32 func_0013C9A0();
s32 func_0013CAB0();
s32 func_0013F800();
s32 func_0013F850();
s32 func_0013F960();
s32 func_0013F990();
s32 func_0019F410();
s32 func_0019F750();
s32 func_001A0E90();
s32 func_001A1040();
s32 func_001A1360();
s32 func_001A17C0();
s32 func_001A1850();
s32 func_001A18B0();
s32 func_001A19B0();
s32 func_001A1AA0();
s32 func_001A1B60();
s32 func_001A2680();
extern u8 D_0028E370;
extern s8 D_0028E408;
extern s32 D_0028ED70;
extern u8 D_0028ED7C;
extern u8 D_0029D710[];
extern u8 D_0029F1F0[];
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_0019FD30(void) {
    s32 temp_a0_6;
    s64 temp_v1;
    u16 temp_a0_7;
    u16 temp_a1;
    u16 temp_a1_3;
    u16 temp_v1_3;
    u16 temp_v1_4;
    u16 temp_v1_6;
    u16 temp_v1_7;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_a0_4;
    u8 temp_a0_5;
    u8 temp_a1_2;
    u8 temp_v1_2;
    u8 var_v1_4;

    goto loop_2;
block_1:
    reg_a6 = D_0029F110;
    reg_a4 = D_0029F1F0;
    reg_a2 = D_0029D710;
    if (*(s16 *)reg_a6 >= 0) {
        return;
    }
loop_2:
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0)));
    (*(u8 *)((u8 *)(reg_a6) + (0))) |= 1;
    if (!(reg_tmp.b[0] & 1)) {
        reg_a0 = D_0025F3B0;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x5A)));
        reg_d0.h[0] -= 2;
        reg_d0.h[0] *= 2;
        reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *) reg_tmp.w;
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
        reg_a1 += 4;
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
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1C)));
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x3C))) = (u8) reg_d0.b[0];
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x57)));
        (*(u8 *)((u8 *)(reg_a2) + (0x1C))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a2) + (0x1F))) = (u8) reg_d0.b[0];
        (*(s16 *)((u8 *)(reg_a2) + (0x16))) = 0;
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x41))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0x19)));
    (*(u8 *)((u8 *)(reg_a6) + (0x40))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0x18)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0)));
    temp_a1 = reg_d0.h[0];
    if (!(temp_a1 & 0x200)) {
        temp_a0 = (*(u8 *)((u8 *)(reg_a4) + (1)));
        if (!(temp_a0 & 1)) {
            if (temp_a1 & 2) {
                if (temp_a0 & 0x20) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x40))) = 0;
                }
                if ((*(u8 *)((u8 *)(reg_a6) + (0x41))) & 0x10) {
                    temp_v1_2 = (*(u8 *)((u8 *)(reg_a6) + (0x3E)));
                    if (temp_v1_2 != 0) {
                        (*(u8 *)((u8 *)(reg_a6) + (0x3E))) = (u8) (temp_v1_2 - 1);
                        if ((*(u8 *)((u8 *)(reg_a6) + (0x3E))) == 0) {
                            (*(u8 *)((u8 *)(reg_a6) + (1))) |= 0x40;
                            goto block_19;
                        }
                        goto block_54;
                    }
block_19:
                    func_0013F960();
                    if ((*(u8 *)((u8 *)(reg_a6) + (0))) & 4) {
                        func_001A17C0();
                    } else if ((*(u8 *)((u8 *)(reg_a6) + (0x1A))) == 0) {
                        func_001A17C0();
                        func_001A18B0();
                        if (D_0028E408 != 0) {
                            (*(u8 *)((u8 *)(reg_a6) + (0))) |= 4;
                            (*(s16 *)((u8 *)(reg_a6) + (0x4E))) = 0;
                            if (!((*(u8 *)((u8 *)(reg_a4) + (0))) & 1)) {
                                if (!((u8) (*(u16 *)((u8 *)(reg_a4) + (0x5A))) & 4)) {
                                    func_001A19B0();
                                } else {
                                    reg_a0 = D_0025F400;
                                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x58)));
                                    if (reg_d0.h[0] != 0) {
                                        reg_d0.w = 0x14;
                                    }
                                    reg_a0 = D_0025F400;
                                    reg_a0 += reg_d0.h[0];
                                    func_001A1AA0();
                                }
                            } else {
                                reg_a0 = D_0025F430;
                                func_001A1AA0();
                            }
                        }
                    } else if ((*(u16 *)((u8 *)(reg_a6) + (0x10))) == 4) {
                        temp_a0_2 = (*(u8 *)((u8 *)(reg_a6) + (1)));
                        if (!(temp_a0_2 & 4) && ((*(u8 *)((u8 *)(reg_a6) + (1))) = (u8) (temp_a0_2 | 8), temp_a0_3 = (*(u8 *)((u8 *)(reg_a6) + (0x14))), (temp_a0_3 != 0x10))) {
                            if (temp_a0_3 == 0x30) {
                                temp_a0_4 = (*(u8 *)((u8 *)(reg_a6) + (0x1D)));
                                (*(u8 *)((u8 *)(reg_a6) + (0x1D))) = (temp_a0_4 & 0x40) ? temp_a0_4 & 0xBF : temp_a0_4 | 0x40;
                                temp_a0_5 = (*(u8 *)((u8 *)(reg_a6) + (0x3D)));
                                var_v1_4 = temp_a0_5 & 0xBF;
                                if (temp_a0_5 & 0x40) {

                                } else {
                                    var_v1_4 = temp_a0_5 | 0x40;
                                }
                                (*(u8 *)((u8 *)(reg_a6) + (0x3D))) = var_v1_4;
                                (*(u8 *)((u8 *)(reg_a6) + (0x14))) = 0x10U;
                                (*(s8 *)((u8 *)(reg_a6) + (0x34))) = 0x30;
                                goto block_41;
                            }
                        } else {
block_41:
                            (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xF7;
                            (*(u8 *)((u8 *)(reg_a6) + (1))) |= 4;
                            goto block_42;
                        }
                    } else {
block_42:
                        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x3F)));
                        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) -= reg_d0.b[0];
                        (*(u8 *)((u8 *)(reg_a6) + (0x3A))) += reg_d0.b[0];
                        if ((s32) (*(u8 *)((u8 *)(reg_a6) + (0x3A))) >= 0x40) {
                            (*(u8 *)((u8 *)(reg_a6) + (1))) |= 0x10;
                            reg_d0.w = 0;
                            (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d0.b[0];
                            (*(u8 *)((u8 *)(reg_a6) + (0x3A))) = (u8) reg_d0.b[0];
                            (*(s8 *)((u8 *)(reg_a6) + (0x4B))) = 8;
                            (*(s8 *)((u8 *)(reg_a6) + (0x4A))) = 4;
                            (*(u16 *)((u8 *)(reg_a6) + (0x16))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x30)));
                            (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x32)));
                            func_001A18B0();
                            (*(u16 *)((u8 *)(reg_a6) + (0xE))) = 0x418U;
                            reg_tmp.w = 0xFC00FD00;
                            (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
                            (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
                            (*(u8 *)((u8 *)(reg_a4) + (0x3E))) = 1U;
                            reg_a0 = (u8 *)func_0013F800;
                            if (reg_d7.h[0] == 0) {
                                reg_a0 = (u8 *)func_0013F850;
                            }
                            jtbl_0028E3F4 = (Fn)(reg_a0);
                            jtbl_0028E3F4();
                        }
                    }
                } else if ((s8) (*(u8 *)((u8 *)(reg_a4) + (0))) < 0) {
                    func_001A17C0();
                } else {
                    func_0013F990();
                    func_001A1850();
                    (*(u8 *)((u8 *)(reg_a6) + (0x3E))) = 0xAU;
                    if ((*(u8 *)((u8 *)(reg_a6) + (1))) & 0x40) {
                        reg_d0.w = 0;
                        (*(u8 *)((u8 *)(reg_a4) + (0x2B))) = (u8) reg_d0.b[0];
                        (*(u8 *)((u8 *)(reg_a4) + (0x2A))) = (u8) reg_d0.b[0];
                        (*(u8 *)((u8 *)(reg_a4) + (0x35))) = (u8) reg_d0.b[0];
                        (*(u8 *)((u8 *)(reg_a4) + (0x34))) = (u8) reg_d0.b[0];
                        (*(u8 *)((u8 *)(reg_a4) + (0x3E))) = (u8) reg_d0.b[0];
                        if (reg_d7.h[0] != 0) {
                            func_0013C9A0();
                        } else {
                            func_0013CAB0();
                        }
                        (*(s8 *)((u8 *)(reg_a6) + (0x4B))) = 8;
                        (*(s8 *)((u8 *)(reg_a6) + (0x4A))) = 4;
                        (*(u16 *)((u8 *)(reg_a6) + (0))) &= 0xDFDB;
                        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
                        (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xEF;
                        if (reg_tmp.b[0] & 0x10) {
                            (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
                            (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x2C)));
                            (*(u16 *)((u8 *)(reg_a6) + (0xE))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x2E)));
                            (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x26)));
                            (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x28)));
                        }
block_54:
                        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x37)));
                        temp_a1_2 = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                        if ((s32) temp_a1_2 >= (s32) reg_d0.b[0]) {
                            (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d0.b[0];
                            (*(u8 *)((u8 *)(reg_a6) + (0x3A))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x36)));
                            (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xB3;
                        } else {
                            (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) (temp_a1_2 + 2);
                            (*(u8 *)((u8 *)(reg_a6) + (0x3A))) -= 2;
                            (*(u8 *)((u8 *)(reg_a6) + (0x3A))) &= 0x3F;
                        }
                    }
                }
                reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (2)));
                temp_a1_3 = (*(u16 *)((u8 *)(reg_a4) + (4)));
                reg_d0.h[0] = temp_a1_3;
                (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d0.h[1];
                (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_d0.h[0];
                (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_d0.h[1];
                (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_d0.h[0];
                if ((*(u8 *)((u8 *)(reg_a6) + (0x1A))) != 0) {
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x5A)));
                    reg_d0.h[0] -= 2;
                    if ((D_0028E370 != 0) && ((D_0028ED7C != 2) || (D_0028ED70 != 0))) {
                        temp_a0_6 = (s32) reg_d0.h[0] >> 1;
                        switch (temp_a0_6) {        /* irregular */
                        case 0:
                            func_001A0E90();
                            break;
                        case 1:
                            func_001A1040();
                            break;
                        case 2:
                            func_001A1360();
                            break;
                        }
                    }
                    reg_a6 += 0x20;
                } else {
                    func_001A2680();
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1E)));
                    (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d0.h[0];
                    func_001A1B60();
                }
                if ((s16)(--reg_d7.h[0]) >= 0) {
                    goto block_1;
                }
                return;
            }
            if ((D_0028E370 != 0) && ((D_0028ED7C != 2) || (D_0028ED70 != 0))) {
                (*(u8 *)((u8 *)(reg_a6) + (0x1B))) += 8;
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x58)));
                if (reg_d1.h[0] != 0) {
                    reg_d1.w = 6;
                }
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x5A)));
                reg_a0 = D_0025F3C0;
                reg_d0.h[0] -= 2;
                reg_d0.h[0] += reg_d1.h[0];
                reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) == reg_d0.b[0]) {
                    (*(u8 *)((u8 *)(reg_a6) + (0))) = 3U;
                }
                (*(u8 *)((u8 *)(reg_a6) + (0x3B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                if ((*(u16 *)((u8 *)(reg_a4) + (0x5A))) != 4) {
                    func_0019F750();
                }
                reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (2)));
                temp_a0_7 = (*(u16 *)((u8 *)(reg_a4) + (4)));
                reg_d0.h[0] = temp_a0_7;
                (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d0.h[1];
                (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_d0.h[0];
                (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_d0.h[1];
                (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_d0.h[0];
                func_0019F410();
                func_001A2680();
                reg_a6 += 0x20;
                func_001A2680();
                if ((s16)(--reg_d7.h[0]) >= 0) {
                    goto block_1;
                }
                return;
            }
        } else {
            reg_a0 = reg_a6;
            reg_d0.w = 0x31;
            reg_d1.w = 0;
            do {
                *(u16 *)reg_a0 = reg_d1.h[0];
                reg_a0 += 2;
            } while ((s16)(--reg_d0.h[0]) >= 0);
            reg_a6 += 0x20;
            if ((s16)(--reg_d7.h[0]) >= 0) {
                goto block_1;
            }
            return;
        }
    } else {
        reg_a6 += 0x20;
        if ((s16)(--reg_d7.h[0]) >= 0) {
            goto block_1;
        }
        return;
    }
}
