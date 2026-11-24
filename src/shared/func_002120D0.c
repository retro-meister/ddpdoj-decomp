#include "common.h"

s32 memalign();
s32 func_0011BEA0();
s32 func_0012FD00();
s32 func_0012FD40();
s32 func_00131490();
s32 func_00131500();
s32 func_00135EC0();
s32 func_00137C20();
s32 func_00137C50();
s32 func_0013B190();
s32 func_0013C3F0();
s32 func_0013FD80();
s32 func_0016A6F0();
s32 func_0016A7F0();
s32 func_00172320();
s32 func_0018DE70();
s32 func_0018DE80();
s32 func_0018E5A0();
s32 func_0019AA90();
s32 func_0019AB20();
s32 func_001A2900();
s32 func_001A2FA0();
s32 func_001A53C0();
s32 func_001AD770();
s32 func_001AE490();
s32 func_00206C20();
s32 func_00206D10();
s32 func_00206D60();
s32 func_00206D70();
s32 func_00206DF0();
s32 func_002071C0();
s32 func_002076B0();
s32 func_00208B60();
s32 func_00209410();
s32 func_0020B690();
s32 func_0020EAA0();
s32 func_0020EAB0();
s32 func_0020F550();
s32 func_002108C0();
s32 func_00212720();
s32 func_00216470();
s32 func_00216570();
s32 func_00216610();
s32 func_00218B50();
s32 func_00219930();
s32 func_00219990();
s32 func_0021B840();
s32 func_0021C530();
s32 func_0021C770();
s32 func_0021C790();
s32 func_0021D8C0();
s32 func_002232F0();
s32 func_00225630();
s32 func_002256B0();
s32 func_00236900();
s32 func_00237CC0();
s32 memset();
s32 printf();
extern u8 D_002620F0[];
extern u8 D_00269160[];
extern u8 D_00269180[];
extern u8 D_002691A0[];
extern u8 D_002691C0[];
extern u8 D_002691E0[];
extern u8 D_00286E20[];
extern u8 D_00286E40[];
extern u8 D_00286E60[];
extern u8 D_00286E78[];
extern u8 D_00286E88[];
extern u8 D_0028DF08;
#ifdef DEATH_LABEL
extern u8 D_0028E290;
#endif
extern u16 D_0028E1A4;
extern u16 D_0028E1A8;
extern u16 D_0028E1B0;
extern u16 D_0028E1B4;
extern s8 D_0028E248[];
extern s8 D_0028E249[];
extern u8 D_0028E350;
extern u8 D_0028E36C;
extern s8 D_0028E370;
extern u8 D_0028E374;
extern u16 D_0028E3C0;
extern s16 D_0028E91C;
extern s8 D_0028E9A4;
extern s8 D_0028E9A5;
extern u16 D_0028E9A8;
extern u16 D_0028E9AC;
extern u16 D_0028E9B0;
extern u16 D_0028E9B4;
extern s8 D_0028E9B8;
extern s8 D_0028E9BC;
extern s8 D_0028EC58;
extern u8 D_006A4800[];
extern u8 D_006C58A0[];
extern u8 *reg_a0;

void func_002120D0(void) {
    s32 t1;
    s32 t2;
    u32 t3;

#ifdef DEATH_LABEL
    D_0028E290 = 2;
#endif
    D_0028E9B8 = 0;
    printf(D_00286E20, 0x9A8);
    printf(D_00286E40, 0x206EC);
    printf(D_00286E60, 0x202E8);
    func_00236900();
    memset(D_006C58A0, 0, 0x202E8);
    memset(D_006A4800, 0, 0x202E8);
    func_0021D8C0();
    func_00216470();
    func_00172320();
    func_0018E5A0();
    func_0020F550();
    func_002108C0();
    func_0018DE70();
    func_0021C530();
    func_00208B60();
    func_00209410();
    func_00206C20();
    func_001A53C0();
    func_00131490();
    func_0018DE80();
    func_0020B690();
    func_0020EAA0();
    func_002076B0();
    func_0012FD00();
    func_0012FD40();
    func_0016A6F0();
    func_001A2900();
    func_0013B190();
    func_0019AA90();
    func_00206D70();
    func_00135EC0();
    func_0011BEA0();
    func_00137C20();
    func_0013FD80();
    func_00137C50();
    func_001AE490();
    func_001AD770();
    func_00206D10();
    func_00206D60();
    reg_a0 = (u8 *)D_00269160;
    reg_d0.w = 0;
    func_001A2FA0();
    reg_a0 = (u8 *)D_00269180;
    reg_d0.w = 1;
    func_001A2FA0();
    reg_a0 = (u8 *)D_002691A0;
    reg_d0.w = 2;
    func_001A2FA0();
    reg_a0 = (u8 *)D_002691C0;
    reg_d0.w = 3;
    func_001A2FA0();
    reg_a0 = (u8 *)D_002691E0;
    reg_d0.w = 4;
    func_001A2FA0();
    reg_d0.h[0] = 8;
    func_002071C0();
    *(s16 *)(reg_a0 + 4) = 0x11;
    printf(D_00286E78, memalign(0x40, 0x10));
    D_0028E9B8 = 0;
    t3 = 0;
    func_00225630();
    printf(D_00286E88);
    do {
        func_00216570();
        switch (t3) {
        case 0:
            func_00212720();
            if (D_0028E9BC == 0) {
                D_0028E9B8 = 0;
                t3 += 1;
                D_0028E9BC = 1;
            }
            break;
        case 1:
            func_0021C770();
            if (D_0028E9BC == 0) {
                D_0028E9B8 = 0;
                t3 += 1;
                D_0028E9BC = 1;
            }
            break;
        case 2:
            func_0021C790();
            if (D_0028E9BC == 0) {
                D_0028E9B8 = 0;
                t3 += 1;
                D_0028E91C = 0;
                D_0028E9BC = 1;
                D_0028E350 = 0;
            }
            break;
        case 3:
            func_00218B50();
            if (D_0028E350 == 0) {
                D_0028E9B8 = 0;
                D_0028E9BC = 1;
                t3 += 1;
                func_002256B0();
            }
            break;
        case 4:
            if (D_0028E374 == 0) {
                t3 += 1;
            }
            break;
        case 5:
            break;
        }
        func_00216610();
    } while (t3 != 5);
    func_0021B840(0x14B5, D_002620F0);
loop_15:
    func_00216570();
    func_0016A7F0();
    t1 = 0;
    t2 = 0;
    if (D_0028E36C != 0) {
        func_002232F0();
        if (D_0028E36C == 0) {
            t1 = 1;
            D_0028E1B0 = D_0028E9B4;
            D_0028E1A4 = D_0028E9B0;
            D_0028E1B4 = D_0028E9AC;
            D_0028E1A8 = D_0028E9A8;
            D_0028E248[0] = D_0028E9A4;
            D_0028E249[0] = D_0028E9A5;
        }
    } else {
        func_00206DF0();
        func_00131500();
        func_0013C3F0();
        func_0019AB20();
        if (D_0028EC58 != 0) {
            D_0028E370 = 1;
        }
        t2 = 1;
    }
    if ((D_0028E36C == 0) && (t1 == 0)) {
        D_0028E9B4 = D_0028E1B0;
        D_0028E9B0 = D_0028E1A4;
        D_0028E9AC = D_0028E1B4;
        D_0028E9A8 = D_0028E1A8;
        D_0028E9A4 = D_0028E248[0];
        D_0028E9A5 = D_0028E249[0];
    }
    func_0020EAB0();
#ifndef DEATH_LABEL
    if ((D_0028E3C0 != 0) && ((s32) D_0028DF08 < 4)) {
        func_00219930();
        func_00219990();
    }
#endif
    func_00216610();
    if (t2 == 0) {
        goto loop_15;
    }
    func_00237CC0();
    goto loop_15;
}
