#include "common.h"

typedef void (*Fn)();

extern u8 D_00255510[];
extern u8 D_00255710[];
extern u8 D_00255950[];
extern u8 D_00255970[];
extern u8 D_00255990[];
extern u8 D_0028C610[];
extern u8 D_0028C618[];
extern u8 D_0028C620[];
extern u8 D_0028C948[4];
extern u8 D_0028C94C[4];
extern u8 D_0028E580[4];
extern u8 D_0028E584[4];
extern u8 D_0028E5BC[4];
extern u8 D_0028E5C0[4];
extern u8 D_0029CD80[];
extern u8 D_0029CD90[];
extern u8 D_0029CEA0[];
extern u8 D_0029E390[];
extern u8 D_0029EA50[];
extern u8 D_0029F110[];
extern u8 D_0029F180[];
s32 func_001340C0();
s32 func_001340D0();
s32 func_00138A20();
s32 func_0013C980();
s32 func_0013C9A0();
s32 func_0013CA90();
s32 func_0013CAB0();
s32 func_0013EBD0();
void func_00140280(u8 *, s32 *);
s32 func_001417D0();
s32 func_001440D0();
s32 func_00144400();
s32 func_00144AD0();
s32 func_00144B20();
s32 func_00144B70();
s32 func_00144B80();
s32 func_00144C10();
s32 func_00144C20();
s32 func_00144CB0();
s32 func_0016A8B0();
s32 func_0016A8C0();
s32 func_0016A8D0();
s32 func_0016A8E0();
s32 func_0018D6F0();
s32 func_0018D710();
s32 func_0018D730();
s32 func_0018DC20();
s32 func_0019D360();
s32 func_001A7E90();
s32 func_001A8070();
s32 func_001ABB80();
s32 func_001ABD80();
s32 func_00200EE0();
s32 func_002014D0();
s32 func_002015B0();
s32 func_00201690();
s32 func_00201C60();
extern u8 D_00255700[];
extern u16 D_00255750[];
extern u16 D_00255760[];
extern u16 D_0028DFBC;
extern u16 D_0028DFC0;
extern u16 D_0028DFC4;
extern s32 D_0028DFF4;
extern u8 D_0028E000;
extern u8 D_0028E004;
extern s16 D_0028E010;
extern s16 D_0028E014;
extern u16 D_0028E018;
extern u16 D_0028E01C;
extern u16 D_0028E064;
extern u16 D_0028E06C;
extern u16 D_0028E078[];
extern u16 D_0028E07A[];
extern u16 D_0028E080[];
extern u16 D_0028E082[];
extern s16 D_0028E088;
extern u8 D_0028E290;
extern u8 D_0028E370;
extern u8 D_0028E380;
extern s16 D_0028E3A0;
extern s16 D_0028E3B0;
extern u16 D_0028E3B4;
extern u16 D_0028E3EC;
extern u16 D_0028E484;
extern u8 D_0028E5C4;
extern u8 D_0028E5C8;
extern u16 D_0028E5E8;
extern u16 D_0028E5EC;
extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern u16 D_0028E688;
extern u16 D_0028E6C8;
extern u16 D_0028E6E0;
extern u16 D_0028E6E4;
extern u8 D_0028E718;
extern u8 D_0028E71C;
extern u8 D_0028E855;
extern u16 D_0028E8A8;
extern u16 D_0028E908;
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern u16 D_0028E928;
extern u8 D_0028EC4C;
extern u16 D_00299764[];
extern u16 D_00299766[];
extern u16 D_0029C06C[];
extern s32 D_0029CD84[];
extern s32 D_0029CD94[];
extern u8 D_0029F1F0[];
extern u8 D_0029F260[];
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001420E0(void) {
    u32 tmp_dec;
    u8 *p0;
    s32 *p1;
    u8 *temp_a0_10;
    u8 *temp_a2_5;
    u8 *temp_a3;
    u8 *temp_a3_3;
    u8 *temp_s0;
    s16 temp_a0_11;
    s16 temp_a0_14;
    s16 temp_a0_16;
    u32 temp_a0_4;
    u32 temp_a0_5;
    u32 temp_a0_9;
    u32 temp_a1_9;
    u32 temp_v0_2;
    u32 temp_v1_2;
    u16 var_a3;
    u16 var_v1;
    u8 temp_a0;
    u8 temp_a0_3;
    u8 temp_a0_6;
    u8 temp_a0_7;
    u8 temp_v0;
    u8 temp_v1;
    u8 *temp_a0_8;
    u8 *temp_a1;
    u8 *temp_a1_3;
    u8 *temp_a1_8;
    u8 *temp_a2_2;
    u8 *var_a0;

    (*(u8 *)((u8 *)(reg_a6) + (0x56))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (6)));
    temp_a0 = (*(u8 *)((u8 *)(reg_a6) + (1)));
    temp_a1 = (u8 *)(reg_a6 + 1);
    if (temp_a0 & 1) {
        func_00144400();
        return;
    }
    if (D_0028DFBC != 0) goto L_else;
    {
        reg_tmp.b[0] = temp_a0;
        (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xDF;
        if (reg_tmp.b[0] & 0x20) {
            if (D_0028E290 == 2) {
                func_001417D0();
            }
            (*(u8 *)((u8 *)(reg_a6) + (0))) &= 0xFB;
            (*(u8 *)((u8 *)(reg_a6) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x38)));
        }
        var_a0 = (u8 *)(reg_a6);
        switch ((*(u8 *)((u8 *)(var_a0) + (0x3F)))) { case 0: break; default:
            (*(u8 *)((u8 *)(var_a0) + (1))) &= 0xEF;
            var_a0 = (u8 *)(reg_a6 + 0x3F);
            temp_v1 = (*(u8 *)((u8 *)(reg_a6) + (0x3F)));
            if ((temp_v1 != 0xFF) && (D_0028E370 != 0)) {
                (*(u8 *)((u8 *)(reg_a6) + (0x3F))) = (u8) (temp_v1 - 1);
            }
            goto block_13;
        }
        (*(u8 *)((u8 *)(var_a0) + (0x1C))) = (u8) (*(u8 *)((u8 *)(var_a0) + (0x3A)));
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xEF;
        if (reg_tmp.b[0] & 0x10) {
            func_001440D0();
            return;
        }
block_13:
        (*(u16 *)((u8 *)(reg_a6) + (0))) &= 0xFFDF;
        temp_v0 = (*(u8 *)((u8 *)(reg_a6) + (0x3B)));
        if (temp_v0 != 0) {
            (*(u8 *)((u8 *)(reg_a6) + (0x3B))) = (u8) (temp_v0 - 1);
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (6))) == 0) {
            func_0016A8B0();
            (*(u8 *)((u8 *)(reg_a6) + (0x19))) = (u8) reg_d0.b[0];
            func_0016A8D0();
            (*(u8 *)((u8 *)(reg_a6) + (0x18))) = reg_d0.b[0];
        } else {
            func_0016A8C0();
            (*(u8 *)((u8 *)(reg_a6) + (0x19))) = (u8) reg_d0.b[0];
            func_0016A8E0();
            (*(u8 *)((u8 *)(reg_a6) + (0x18))) = reg_d0.b[0];
        }
        reg_d0.w = 0;
        (*(u16 *)((u8 *)(reg_a6) + (0x30))) = 0U;
        (*(u16 *)((u8 *)(reg_a6) + (0x32))) = 0U;
        if (D_0028DFC4 != 0) {
            (*(u8 *)((u8 *)(reg_a6) + (0x19))) &= 0xF;
            (*(u8 *)((u8 *)(reg_a6) + (0x18))) &= 0xF;
            (*(u8 *)((u8 *)(reg_a6) + (0x3F))) = 0xFFU;
        }
        reg_d0.w = 0xF;
        reg_d0.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (0x19)));
        reg_a2 = (u8 *)D_00255700;
        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) *(reg_a2 + reg_d0.h[0] + ((reg_d0.h[0] & 1) ? -1 : 1));
        if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0x1A))) < 0) {
            func_00144CB0();
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        } else {
            func_00201C60();
            (*(u16 *)((u8 *)(reg_a6) + (0x30))) = (u16) reg_d2.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (0x32))) = (u16) reg_d3.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (0x5C))) = (u16) reg_d3.h[0];
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            temp_a0_3 = (*(u8 *)((u8 *)(reg_a6) + (0x19)));
            if (temp_a0_3 & 4) {
                (*(u16 *)((u8 *)(reg_a6) + (0))) |= 0x20;
                if ((*(s16 *)((u8 *)(reg_a6) + (0x4E))) != -0x20) {
                    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x4C)));
                    (*(u16 *)((u8 *)(reg_a6) + (0x4C))) -= 1;
                    if ((s32) reg_tmp.h[0] <= 0) {
                        (*(u16 *)((u8 *)(reg_a6) + (0x4C))) = 2U;
                        (*(u16 *)((u8 *)(reg_a6) + (0x4E))) += 0x7FFF + 0x7FFD;
                    }
                }
                if ((s32) reg_d3.h[0] < 0x301) {
                    reg_d3.h[0] -= 0x300;
                    temp_a0_4 = (*(u16 *)((u8 *)(reg_a6) + (0x32)));
                    (*(u16 *)((u8 *)(reg_a6) + (0x32))) = (u16) (temp_a0_4 - reg_d3.h[0]);
                    reg_d3.h[0] = 0x300;
                    func_00138A20();
                }
            } else if (temp_a0_3 & 8) {
                (*(u16 *)((u8 *)(reg_a6) + (0))) |= 0x20;
                if ((*(u16 *)((u8 *)(reg_a6) + (0x4E))) != 0x20) {
                    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x4C)));
                    (*(u16 *)((u8 *)(reg_a6) + (0x4C))) -= 1;
                    if ((s32) reg_tmp.h[0] <= 0) {
                        (*(u16 *)((u8 *)(reg_a6) + (0x4C))) = 2U;
                        (*(u16 *)((u8 *)(reg_a6) + (0x4E))) += 4;
                    }
                }
                if ((s32) reg_d3.h[0] >= 0x3500) {
                    reg_d3.h[0] -= 0x3500;
                    temp_a0_5 = (*(u16 *)((u8 *)(reg_a6) + (0x32)));
                    (*(u16 *)((u8 *)(reg_a6) + (0x32))) = (u16) (temp_a0_5 - reg_d3.h[0]);
                    reg_d3.h[0] = 0x3500;
                    func_00138A20();
                }
            } else {
                func_00144CB0();
            }
            temp_a0_6 = (*(u8 *)((u8 *)(reg_a6) + (0x19)));
            if (temp_a0_6 & 1) {
                if ((s32) reg_d2.h[0] > 0x6500) {
                    reg_d2.h[0] -= 0x6500;
                    (*(u16 *)((u8 *)(reg_a6) + (0x30))) -= reg_d2.h[0];
                    reg_d2.h[0] = 0x6500;
                }
            } else if ((temp_a0_6 & 2) && ((s32) reg_d2.h[0] < 0x800)) {
                reg_d2.h[0] -= 0x800;
                var_v1 = 0x800;
                (*(u16 *)((u8 *)(reg_a6) + (0x30))) -= reg_d2.h[0];
                reg_d2.h[0] = var_v1;
            }
        }
        if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0))) < 0) {
            temp_v1_2 = (*(u16 *)((u8 *)(reg_a6) + (0x46)));
            if (temp_v1_2 != 0) {
                reg_d0.h[0] = temp_v1_2;
                reg_a0 = (u8 *)D_00255710;
                reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                (*(u16 *)((u8 *)(reg_a6) + (6))) -= reg_d0.h[0];
                (*(u16 *)((u8 *)(reg_a6) + (0x5E))) = (u16) reg_d0.h[0];
                (*(u16 *)((u8 *)(reg_a6) + (0x46))) -= 2;
            }
            if (D_0028DFF4 != 0) {
                (*(u16 *)((u8 *)(reg_a6) + (0x30))) -= 0x48;
                reg_d2.h[0] -= 0x48;
            }
            if ((s32) reg_d2.h[0] < 0x800) {
                reg_d0.h[0] = 0x800;
                reg_d0.h[0] -= reg_d2.h[0];
                (*(u16 *)((u8 *)(reg_a6) + (0x30))) += reg_d0.h[0];
                reg_d2.h[0] = 0x800;
            }
        }
        (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d2.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_d3.h[0];
        if ((D_0028E928 == 0) && !((*(u8 *)((u8 *)(reg_a6) + (0))) & 0x20)) {
            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d0.h[0] = D_0029C06C[0];
            reg_d3.h[0] -= reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_d3.h[0];
        }
        if ((D_0028E380 != 0) && ((*(u8 *)((u8 *)(reg_a6) + (0x19))) & 0x40) && ((*(u8 *)((u8 *)(reg_a6) + (0x3D))) == 0)) {
            reg_a0 = (u8 *)D_0029F180;
            if ((*(u8 *)((u8 *)(reg_a5) + (6))) != 0) {
                reg_a0 = (u8 *)D_0029F110;
            }
            (*(u8 *)((u8 *)(reg_a6) + (0x18))) &= 0xEF;
            (*(u8 *)((u8 *)(reg_a6) + (0))) &= 0xF7;
            *reg_a0 &= 0xF7;
            temp_a0_7 = (*(u8 *)((u8 *)(reg_a6) + (0)));
            if (temp_a0_7 & 0x10) {
                (*(u8 *)((u8 *)(reg_a6) + (0))) = (u8) (temp_a0_7 & 0xEF);
            } else {
                (*(u8 *)((u8 *)(reg_a6) + (0))) = (u8) (temp_a0_7 | 0x10);
                (*(u8 *)((u8 *)(reg_a6) + (0))) |= 8;
                *reg_a0 |= 8;
                (*(u8 *)((u8 *)(reg_a6) + (0x18))) |= 0x10;
            }
        }
        if (((s32) D_0028E8A8 >= 4) && ((*(u8 *)((u8 *)(reg_a6) + (0x19))) & 0x20)) {
            temp_a2_2 = (u8 *)(reg_a5 + 6);
            if ((*(u8 *)((u8 *)(reg_a5) + (6))) == 0) {
                reg_a0 = (u8 *)func_0013C980;
                reg_a1 = (u8 *)D_0028E5C0;
                reg_a2 = &D_0028E5C8;
                reg_a3 = (u8 *)(D_00255750);
                reg_d6.h[0] = D_0028E5EC;
                reg_d7.h[0] = *(u16 *)D_0029CD90;
            } else {
                reg_a0 = (u8 *)func_0013CA90;
                reg_a1 = (u8 *)D_0028E5BC;
                reg_a2 = &D_0028E5C4;
                reg_a3 = (u8 *)(D_00255760);
                reg_d6.h[0] = D_0028E5E8;
                reg_d7.h[0] = *(u16 *)D_0029CD80;
            }
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (0)));
            if (reg_d1.h[0] != 0) {
                reg_d1.h[0] -= 1;
                reg_d1.h[0] *= 2;
                reg_a1 = (u8 *)D_00255510;
                reg_d6.h[0] -= 1;
                reg_d6.h[0] *= 2;
                reg_d6.h[0] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d6.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a1) + (0)));
                D_00299764[0] += 8;
                D_00299766[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                jtbl_0028E3F4 = (Fn)(reg_a0);
                jtbl_0028E3F4();
                (*(s16 *)((u8 *)(reg_a2) + (0))) = 1;
                (*(u8 *)((u8 *)(reg_a6) + (0))) |= 1;
                func_0018DC20();
                reg_a0 = (u8 *)func_002014D0;
                if ((*(u8 *)((u8 *)(reg_a5) + (6))) != 0) {
                    reg_a0 = (u8 *)func_002015B0;
                }
                jtbl_0028E3F4 = (Fn)(reg_a0);
                jtbl_0028E3F4();
                (*(u8 *)((u8 *)(reg_a6) + (0x3F))) = 2U;
                D_0028E3B0 = 0x14;
                if (((*(u8 *)((u8 *)(reg_a6) + (1))) & 0x40) || (reg_d7.h[0] == 0)) {
                    func_0013EBD0();
                }
                goto block_122;
            }
            temp_a0_8 = (u8 *)(reg_a6 + 0x25);
            if ((*(u8 *)((u8 *)(reg_a6) + (0x25))) != 0) {
                reg_a1 = (u8 *)D_0028E584;
                if ((*(u8 *)((u8 *)(reg_a5) + (6))) != 0) {
                    reg_a1 = (u8 *)D_0028E580;
                }
                if (((*(u16 *)((u8 *)(reg_a1) + (0))) == 0) && (reg_a1 = (u8 *)D_0029CEA0, ((s16) (*(u16 *)((u8 *)(reg_a1) + (0))) >= 0))) {
                    D_0028E3A0 = 1;
                    (*(u8 *)((u8 *)(reg_a6) + (0x25))) -= 1;
                    if ((*(u8 *)((u8 *)(reg_a6) + (0x25))) == 0) {
                        if ((*(u8 *)((u8 *)(reg_a5) + (6))) == 0) {
                            func_001ABB80();
                        } else {
                            func_001ABD80();
                        }
                    }
                    if ((*(u8 *)((u8 *)(reg_a5) + (6))) == 0) {
                        D_0028E014 = 1;
                        if ((s32) D_0028E01C < 0x63) {
                            D_0028E01C += 1;
                        }
                        reg_a2 = (u8 *)D_0029F1F0;
                        reg_a3 = (u8 *)(&D_0028E6E4);
                        reg_a4 = (u8 *)D_0029CD90;
                        reg_d0.h[0] = D_0028E6C8;
                        if (D_0028E5FC != 0) {
                            func_001A7E90();
                            reg_tmp.h[0] = D_0028E5EC;
                            D_0028E5EC -= 3;
                            if ((s32) reg_tmp.h[0] < 3) {
                                D_0028E5EC = 0;
                            }
                        }
                    } else {
                        D_0028E010 = 1;
                        if ((s32) D_0028E018 < 0x63) {
                            D_0028E018 += 1;
                        }
                        reg_a2 = (u8 *)D_0029F260;
                        reg_a3 = (u8 *)(&D_0028E6E0);
                        reg_a4 = (u8 *)D_0029CD80;
                        reg_d0.h[0] = D_0028E688;
                        if (D_0028E5F8 != 0) {
                            func_001A8070();
                            reg_tmp.h[0] = D_0028E5E8;
                            D_0028E5E8 -= 3;
                            if ((s32) reg_tmp.h[0] < 3) {
                                D_0028E5E8 = 0;
                            }
                        }
                    }
                    if (reg_d0.h[0] != 0) {
                        *(u16 *)reg_a3 = 1;
                    }
                    if (!((*(u8 *)((u8 *)(reg_a6) + (1))) & 0x40)) {
                        temp_v0_2 = (*(u16 *)((u8 *)(reg_a4) + (0)));
                        if (temp_v0_2 != 0) {
                            (*(u16 *)((u8 *)(reg_a4) + (0))) = (u16) (temp_v0_2 - 0x2C);
                            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
                            (*(u16 *)((u8 *)(reg_a4) + (0xC))) -= 2;
                            if ((s32) reg_tmp.h[0] < 2) {
                                (*(u16 *)((u8 *)(reg_a4) + (0))) = 0U;
                                (*(u16 *)((u8 *)(reg_a4) + (0xC))) = 0U;
                            }
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0)));
                            reg_d5.h[0] = reg_d0.h[0];
                            func_00200EE0();
                            (*(u16 *)((u8 *)(reg_a4) + (4))) = (u16) reg_d2.h[1];
                            (*(u16 *)((u8 *)(reg_a4) + (6))) = (u16) reg_d2.h[0];
                            reg_d5.h[0] >>= 1;
                            reg_d0.h[0] = reg_d5.h[0];
                            func_00200EE0();
                            (*(u16 *)((u8 *)(reg_a4) + (8))) = (u16) reg_d2.h[1];
                            (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) reg_d2.h[0];
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
                            func_00200EE0();
                            (*(u16 *)((u8 *)(reg_a4) + (0xE))) = (u16) reg_d2.h[0];
                        }
                    }
                    func_0013EBD0();
                    (*(u8 *)((u8 *)(reg_a6) + (1))) |= 0x40;
                    (*(u8 *)((u8 *)(reg_a6) + (0))) |= 0x40;
                    reg_d2.w = 0;
                    reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (6)));
                    reg_d2.h[0] <<= 7;
                    reg_d2.h[0] |= 0x8000;
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x58)));
                    reg_d2.b[0] |= reg_d0.b[0];
                    (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_d2.h[0];
                    reg_d0.h[0] *= 2;
                    reg_d1.h[0] = reg_d0.h[0];
                    (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
                    temp_a0_9 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    (*(u16 *)((u8 *)(reg_a1) + (4))) = temp_a0_9;
                    (*(u8 *)((u8 *)(reg_a6) + (0x3F))) = 0xFFU;
                    if ((*(u8 *)((u8 *)(reg_a6) + (0x3E))) == 0) {
                        func_001340C0();
                        (*(u16 *)((u8 *)(reg_a6) + (0x26))) = 0U;
                        (*(u16 *)((u8 *)(reg_a6) + (0x28))) = 0x3CU;
                        (*(u8 *)((u8 *)(reg_a6) + (0x1B))) += 6;
                        reg_a0 = (u8 *)D_0028C948;
                    } else {
                        func_001340D0();
                        (*(u16 *)((u8 *)(reg_a6) + (0x26))) = 0x101U;
                        (*(u16 *)((u8 *)(reg_a6) + (0x28))) = 0xCU;
                        (*(u8 *)((u8 *)(reg_a6) + (0))) |= 0x80;
                        temp_a0_10 = (u8 *)(reg_a1);
                        (*(u8 *)((u8 *)(temp_a0_10) + (0))) |= 1;
                        D_0028E088 = 0;
                        (*(u16 *)((u8 *)(reg_a6) + (0x46))) = 0x2EU;
                        temp_s0 = (u8 *)(reg_a2);
                        if ((*(u8 *)((u8 *)(reg_a5) + (6))) == 0) {
                            reg_a1 = (u8 *)D_0029F180;
                            reg_a2 = &D_0028E004;
                            func_0013C9A0();
                        } else {
                            reg_a1 = (u8 *)D_0029F110;
                            reg_a2 = &D_0028E000;
                            func_0013CAB0();
                        }
                        (*(s16 *)((u8 *)(reg_a1) + (0x38))) = 0x26;
                        (*(s16 *)((u8 *)(reg_a1) + (0x56))) = 8;
                        (*(s16 *)((u8 *)(reg_a2) + (0))) = 1;
                        reg_a2 = temp_s0;
                        func_00201690();
                        reg_a0 = (u8 *)D_0028C94C;
                    }
                    reg_a0 += reg_d1.h[0];
                    reg_d0.h[0] = *(u16 *)reg_a0;
                    reg_a0 += 2;
                    if (((reg_d0.h[0] == 0) || !((*(u8 *)((u8 *)(reg_a6) + (0x5A))) & 4)) && ((*(u8 *)((u8 *)(reg_a5) + (6))) != 0)) {
                        reg_d0.h[0] += 0xC;
                    }
                    if ((*(s16 *)((u8 *)(reg_a2) + (0))) < 0) {
                        (*(u8 *)((u8 *)(reg_a2) + (0x3F))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x3F)));
                        (*(u16 *)((u8 *)(reg_a2) + (0x28))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x28)));
                        (*(u16 *)((u8 *)(reg_a2) + (0x26))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x26)));
                    }
                } else {
                    goto block_122;
                }
            } else {
                goto block_122;
            }
        } else {
block_122:
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x55)));
            if ((*(u8 *)((u8 *)(reg_a6) + (0))) & 1) {
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x54)));
            }
            (*(u8 *)((u8 *)(reg_a6) + (0x57))) = (u8) reg_d0.b[0];
            if ((*(u8 *)((u8 *)(reg_a6) + (0x3E))) == 0) {
                if ((*(u8 *)((u8 *)(reg_a6) + (0x18))) & 0x10) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x3D))) = 1U;
                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x20)));
                    if ((*(u8 *)((u8 *)(reg_a6) + (0))) & 1) {
                        reg_d0.h[0] = 8;
                    }
                    reg_d0.h[0] >>= 1;
                    reg_d0.b[0] &= 6;
                    reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
                    (*(u8 *)((u8 *)(reg_a6) + (0x2A))) = (u8) reg_d0.b[0];
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0)));
                    (*(u8 *)((u8 *)(reg_a6) + (0))) &= 0xF7;
                    if (reg_tmp.b[0] & 8) {
                        (*(u8 *)((u8 *)(reg_a6) + (1))) |= 8;
                        (*(u8 *)((u8 *)(reg_a6) + (0x2A))) = 0U;
                        goto block_135;
                    }
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
                    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xF7;
                    if (reg_tmp.b[0] & 8) {
                        (*(u8 *)((u8 *)(reg_a6) + (0x2B))) = 1U;
                    } else {
                        goto block_135;
                    }
                } else {
                    (*(u8 *)((u8 *)(reg_a6) + (0x3D))) = 0U;
                    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xF7;
                    (*(u8 *)((u8 *)(reg_a6) + (0))) &= 0xEF;
                    if ((*(u8 *)((u8 *)(reg_a6) + (0x2A))) != 0) {
                        (*(u8 *)((u8 *)(reg_a6) + (0x2B))) -= 1;
                        if ((*(u8 *)((u8 *)(reg_a6) + (0x2B))) == 0) {
                            (*(u8 *)((u8 *)(reg_a6) + (0x2A))) -= 1;
                            (*(u8 *)((u8 *)(reg_a6) + (1))) |= 8;
                            (*(u8 *)((u8 *)(reg_a6) + (0))) |= 0x10;
block_135:
                            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
                            if (((*(u8 *)((u8 *)(reg_a6) + (0))) & 1) || (((*(u16 *)((u8 *)(reg_a6) + (0x58))) == 0) && ((*(u16 *)((u8 *)(reg_a6) + (0x20))) == 8))) {
                                reg_d0.w = 2;
                            }
                            (*(u8 *)((u8 *)(reg_a6) + (0x2B))) = (u8) reg_d0.b[0];
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x58)));
                            if (reg_d0.h[0] == 0) {
                                reg_a0 = (u8 *)D_0029E390;
                                reg_tmp.h[1] = D_0028E080[0];
                                reg_tmp.h[0] = D_0028E082[0];
                                reg_a2 = (u8 *) reg_tmp.w;
                                if ((*(u8 *)((u8 *)(reg_a5) + (6))) != 0) {
                                    reg_a0 = (u8 *)D_0029EA50;
                                    reg_tmp.h[1] = D_0028E078[0];
                                    reg_tmp.h[0] = D_0028E07A[0];
                                    reg_a2 = (u8 *) reg_tmp.w;
                                }
                                reg_d7.h[0] = (*(u16 *)((u8 *)(reg_a2) + (0)));
                                if ((*(u8 *)((u8 *)(reg_a6) + (0))) & 1) {
                                    reg_d7.h[0] = 6;
                                }
                                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x5A)));
                                reg_d0.h[0] -= 2;
                                reg_d0.h[0] *= 4;
                                if ((*(u8 *)((u8 *)(reg_a6) + (0))) & 1) {
                                    reg_d0.h[0] += 4;
                                }
                                var_a3 = reg_d0.h[0];
                                reg_a1 = (u8 *)D_00255950;
                                reg_d5.h[0] = var_a3;
                                reg_tmp.h[1] = (var_a3 != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)var_a3 & ~1)) : (*(u16 *)((u8 *)(reg_a1) + (0)));
                                reg_tmp.h[0] = (((var_a3 & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((var_a3 & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a1;
                                reg_a1 = (u8 *) reg_tmp.w;
                                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x20)));
                                reg_d0.h[0] *= 2;
                                temp_a1_3 = (u8 *)(reg_a6 + 0x20);
                                reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a1) + (0)));
                                reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                                reg_a1 = (u8 *) reg_tmp.w;
                                if ((*(u16 *)((u8 *)(reg_a6) + (0x5A))) != 4) {
                                    reg_a0 += 0x2A0;
                                    reg_a4 = reg_a0 + 0x150;
                                    if ((D_0028E928 == 0) && ((s32) reg_d7.h[0] > 3)) {
                                        reg_d7.w = 3;
                                    }
                                    reg_d6.h[0] = reg_d7.h[0];
loop_164:
                                    if ((*(s16 *)reg_a0) < 0) {
                                        reg_a0 += 0x30;
                                        tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
                                        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                                            goto loop_164;
                                        }
                                    } else {
                                        func_00144AD0();
                                    }
                                    reg_a1 = (u8 *)D_00255970;
                                    reg_tmp.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d5.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a1) + (0)));
                                    reg_tmp.h[0] = (((u16)reg_d5.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                                    reg_a1 = (u8 *) reg_tmp.w;
                                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x20)));
                                    reg_d0.h[0] *= 2;
                                    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a1) + (0)));
                                    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                                    reg_a1 = (u8 *) reg_tmp.w;
loop_181:
                                    if ((*(s16 *)reg_a4) < 0) {
                                        reg_a4 += 0x30;
                                        tmp_dec = reg_d6.h[0] - 1; reg_d6.h[0] = tmp_dec;
                                        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                                            goto loop_181;
                                        }
                                        if ((*(u16 *)((u8 *)(reg_a6) + (0x20))) != 8) {
                                            (*(u8 *)((u8 *)(reg_a6) + (0x2A))) = 0U;
                                            (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xF7;
                                        }
                                        if ((s16) reg_d7.h[0] >= 0) {
                                            goto block_196;
                                        }
                                    } else {
                                        reg_a0 = reg_a4;
                                        func_00144B70();
                                        goto block_196;
                                    }
                                } else {
                                    temp_a3 = (u8 *)(reg_a0 + 0x1B0);
                                    reg_a0 = temp_a3;
                                    reg_d7.h[0] += 2;
                                    if ((D_0028E928 == 0) && ((s32) reg_d7.h[0] > 4)) {
                                        reg_d7.w = 4;
                                    }
loop_191:
                                    temp_a0_11 = (*(s16 *)reg_a0);
                                    if (temp_a0_11 < 0) {
                                        reg_a0 += 0x30;
                                        tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
                                        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                                            goto loop_191;
                                        }
                                            if ((*(u16 *)((u8 *)(reg_a6) + (0x20))) != 8) {
                                                (*(u8 *)((u8 *)(reg_a6) + (0x2A))) = 0U;
                                                (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xF7;
                                            }
                                    } else {
                                        func_00144B80();
block_196:
                                        if ((*(u8 *)((u8 *)(reg_a6) + (0x3B))) == 0) {
                                            (*(u8 *)((u8 *)(reg_a6) + (0x3B))) = 2U;
                                            reg_a0 = (u8 *)func_0018D6F0;
                                            if ((*(u8 *)((u8 *)(reg_a6) + (0))) & 1) {
                                                reg_a0 = (u8 *)func_0018D730;
                                            }
                                            jtbl_0028E3F4 = (Fn)(reg_a0);
                                            jtbl_0028E3F4();
                                        }
                                    }
                                }
                            } else {
                                reg_a0 = (u8 *)D_0029E390;
                                reg_tmp.h[1] = D_0028E080[0];
                                reg_tmp.h[0] = D_0028E082[0];
                                reg_a2 = (u8 *) reg_tmp.w;
                                if ((*(u8 *)((u8 *)(reg_a5) + (6))) != 0) {
                                    reg_a0 = (u8 *)D_0029EA50;
                                    reg_tmp.h[1] = D_0028E078[0];
                                    reg_tmp.h[0] = D_0028E07A[0];
                                    reg_a2 = (u8 *) reg_tmp.w;
                                }
                                reg_d7.h[0] = (*(u16 *)((u8 *)(reg_a2) + (0)));
                                if ((*(u8 *)((u8 *)(reg_a6) + (0))) & 1) {
                                    reg_d7.h[0] = 6;
                                }
                                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x5A)));
                                reg_d0.h[0] -= 2;
                                reg_d0.h[0] *= 4;
                                if ((*(u8 *)((u8 *)(reg_a6) + (0))) & 1) {
                                    reg_d0.h[0] += 4;
                                }
                                reg_a1 = (u8 *)D_00255990;
                                reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a1) + (0)));
                                reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                                reg_a1 = (u8 *) reg_tmp.w;
                                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x20)));
                                reg_d0.h[0] *= 2;
                                temp_a1_8 = (u8 *)(reg_a6 + 0x20);
                                reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a1) + (0)));
                                reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                                reg_a1 = (u8 *) reg_tmp.w;
                                if ((*(u16 *)((u8 *)(reg_a6) + (0x5A))) != 4) {
                                    reg_a0 += 0x2A0;
                                    reg_d7.h[0] *= 2;
                                    reg_d7.h[0] += 1;
                                    if ((D_0028E928 == 0) && ((s32) reg_d7.h[0] > 7)) {
                                        reg_d7.w = 7;
                                    }
loop_222:
                                    temp_a2_5 = (u8 *)(reg_a0);
                                    if ((*(s16 *)temp_a2_5) < 0) {
                                        reg_a0 = temp_a2_5 + 0x30;
                                        tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
                                        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                                            goto loop_222;
                                        }
                                            if ((*(u16 *)((u8 *)(reg_a6) + (0x20))) != 8) {
                                                (*(u8 *)((u8 *)(reg_a6) + (0x2A))) = 0U;
                                                (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xF7;
                                            }
                                    } else {
                                        reg_a4 = temp_a2_5;
loop_227:
                                        reg_a0 += 0x30;
                                        temp_a0_14 = (*(s16 *)reg_a0);
                                        if (temp_a0_14 < 0) {
                                            tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
                                            if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                                                goto loop_227;
                                            }
                                            if ((*(u16 *)((u8 *)(reg_a6) + (0x20))) != 8) {
                                                (*(u8 *)((u8 *)(reg_a6) + (0x2A))) = 0U;
                                                (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xF7;
                                            }
                                        } else {
                                            func_00144B20();
                                            reg_a0 = reg_a4;
                                            func_00144C10();
                                            goto block_240;
                                        }
                                    }
                                } else {
                                    temp_a3_3 = (u8 *)(reg_a0 + 0x1B0);
                                    reg_a0 = temp_a3_3;
                                    reg_d7.h[0] += 2;
                                    if ((D_0028E928 == 0) && ((s32) reg_d7.h[0] > 4)) {
                                        reg_d7.w = 4;
                                    }
loop_235:
                                    temp_a0_16 = (*(s16 *)reg_a0);
                                    if (temp_a0_16 < 0) {
                                        reg_a0 += 0x30;
                                        tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
                                        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                                            goto loop_235;
                                        }
                                            if ((*(u16 *)((u8 *)(reg_a6) + (0x20))) != 8) {
                                                (*(u8 *)((u8 *)(reg_a6) + (0x2A))) = 0U;
                                                (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xF7;
                                            }
                                    } else {
                                        func_00144C20();
block_240:
                                        if ((*(u8 *)((u8 *)(reg_a6) + (0x3B))) == 0) {
                                            (*(u8 *)((u8 *)(reg_a6) + (0x3B))) = 2U;
                                            reg_a0 = (u8 *)func_0018D710;
                                            if ((*(u8 *)((u8 *)(reg_a6) + (0))) & 1) {
                                                reg_a0 = (u8 *)func_0018D730;
                                            }
                                            jtbl_0028E3F4 = (Fn)(reg_a0);
                                            jtbl_0028E3F4();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
block_244:
    reg_a0 = (u8 *)D_0028C610;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x58)));
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x4E)));
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)D_0028C618;
    reg_d1.w = 0;
    reg_d1.h[0] *= 4;
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    (*(u16 *)((u8 *)(reg_a6) + (0x14))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0x16))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    if ((D_0028DFC0 == 0) && (D_0028E3EC == 0) && (D_0028E910 == 0) && (D_0028E91C != 2)) {
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d5.h[0] = 0x1C00;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        D_0028E484 = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = D_0028E484;
        reg_d5.h[0] = 0x1400;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        D_0028E484 = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = D_0028E484;
        reg_d1.w += 0xFE00FE00;
        reg_a0 = (u8 *)D_0028C620;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x58)));
        reg_d0.h[0] *= 2;
        temp_a1_9 = reg_d0.h[0];
        reg_tmp.h[1] = (temp_a1_9 != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)temp_a1_9 & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((temp_a1_9 & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((temp_a1_9 & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *) reg_tmp.w;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x4E)));
        reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = 0x210;
        reg_d4.h[0] = 0x18;
        func_0019D360();
    }
    if ((D_0028E370 != 0) && (D_0028EC4C == 0) && (D_0028E3B4 == 0) && !(D_0028E855 & 1) && (D_0028E908 == 0) && !((*(u8 *)((u8 *)(reg_a6) + (1))) & 0x40)) {
        if ((*(u8 *)((u8 *)(reg_a5) + (6))) == 0) {
            if (D_0028E06C == 0) {
                p0 = &D_0028E71C;
                p1 = (s32 *)(p0 - 0x34);
                *p1 = D_0029CD94[0];
                func_00140280(p0, p1);
                if (D_0028E910 != 0) {
                    func_00140280(p0, p1);
                }
                return;
            }
        } else if (D_0028E064 == 0) {
            p0 = &D_0028E718;
            p1 = (s32 *)(p0 - 0x30);
            *p1 = D_0029CD84[0];
            func_00140280(p0, p1);
            if (D_0028E910 != 0) {
                func_00140280(p0, p1);
            }
        }
    }
    return;
L_else:
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0)));
    (*(u8 *)((u8 *)(reg_a6) + (0))) |= 4;
    if (!(reg_tmp.b[0] & 4)) {
        reg_d0.w = 0;
        reg_d7.w = 0x2C;
        reg_a0 = (u8 *)D_0029CEA0;
        do {
            *(u16 *)reg_a0 = reg_d0.h[0];
            reg_a0 += 0x30;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        (*(u16 *)((u8 *)(reg_a6) + (0))) &= 0xFF3F;
        (*(u8 *)((u8 *)(reg_a6) + (0x3F))) = 1U;
        reg_d0.w = 0;
        (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x34))) = (u16) reg_d0.h[0];
    }
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xEF;
    reg_d7.h[0] = 0xE00;
    if ((*(u8 *)((u8 *)(reg_a5) + (6))) != 0) {
        reg_d7.h[0] = 0x2A00;
    }
    if (D_0028DFC0 != 0) {
        reg_d2.h[0] = 0xC00;
        (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d2.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_d7.h[0];
    }
    goto block_244;
}
