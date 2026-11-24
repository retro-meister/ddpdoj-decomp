#include "common.h"

s32 func_0012FAB0();
s32 func_001A2FA0();
s32 func_001A3020();
s32 func_001A33C0();
s32 func_001A35A0();
s32 func_001B04B0();
s32 func_002071C0();
s32 func_0023C1E0();
extern u8 D_0025F770[];
extern u8 D_00260930[];
extern u8 D_00260970[];
extern u8 D_002609B0[];
extern u8 D_002609F0[];
extern u8 D_00260A30[];
extern u8 D_00260CB0[];
extern u8 D_00260CF0[];
extern u8 D_00260D30[];
extern u8 D_00260D70[];
extern u8 D_00260DB0[];
extern u8 D_00260DF0[];
extern u8 D_00260E30[];
extern u8 D_00260E70[];
extern u8 D_00269140[];
extern s16 D_0028DF14;
extern s16 D_0028DF18;
extern s16 D_0028E3B4;
extern u16 D_0028E934;
extern u16 D_0028E938;
extern u8 D_0028ED7C;
extern u8 D_0029BE00[];
extern s16 D_0029F1F0[];
extern u16 D_0029F248[];
extern u16 D_0029F24A[];
extern s16 D_0029F260[];
extern u16 D_0029F2B8[];
extern u16 D_0029F2BA[];
extern u8 D_006CB1D4[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001B1D70(void) {
    (*(s8 *)((u8 *)(reg_a5) + (3))) = 1;
    func_001B04B0();
    D_0028DF14 = 0;
    D_0028E3B4 = 1;
    reg_a0 = (u8 *)D_0029BE00;
    reg_d0.h[0] = 0x6F;
    do {
        (*(s16 *)((u8 *)(reg_a0) + (0))) = 0;
        reg_a0 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *)D_0029BE00;
    reg_d0.w = 1;
    do {
        (*(s8 *)((u8 *)(reg_a0) + (1))) = 0;
        (*(u8 *)((u8 *)(reg_a0) + (0))) = 0;
        reg_tmp.w = -1U;
        (*(u16 *)((u8 *)(reg_a0) + (0x56))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a0) + (0x58))) = (u16) reg_tmp.h[0];
        (*(s16 *)((u8 *)(reg_a0) + (0x60))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x62))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x64))) = 1;
        (*(s16 *)((u8 *)(reg_a0) + (0x66))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x68))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x6A))) = 2;
        (*(s16 *)((u8 *)(reg_a0) + (0x6C))) = 0x140;
        reg_a0 += 0x70;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    D_0028DF18 = 0;
    (*(s8 *)((u8 *)(reg_a5) + (2))) = 0;
    (*(u8 *)((u8 *)(reg_a5) + (5))) = 0xFFU;
    (*(u8 *)((u8 *)(reg_a5) + (4))) = 0xFFU;
    (*(u8 *)((u8 *)(reg_a5) + (7))) = 0xFFU;
    (*(u8 *)((u8 *)(reg_a5) + (6))) = 0xFFU;
    (*(u8 *)((u8 *)(reg_a5) + (9))) = 0xFFU;
    (*(u8 *)((u8 *)(reg_a5) + (8))) = 0xFFU;
    (*(s16 *)((u8 *)(reg_a5) + (0xA))) = 0;
    reg_a0 = (u8 *)D_0029BE00;
    reg_d0.w = 0;
    if (0 > D_0029F260[0]) {
        reg_d0.h[0] = 1;
    } else if (0 > D_0029F1F0[0]) {
        reg_d0.h[0] = 2;
    }
    reg_a6 = (u8 *)D_0029BE00;
    if (reg_d0.b[0] == 2) {
        (*(s8 *)((u8 *)(reg_a0) + (0x71))) = 1;
        reg_d1.h[0] = D_0029F248[0];
        (*(u8 *)((u8 *)(reg_a5) + (8))) = (u8) reg_d1.b[0];
        reg_d1.h[0] = D_0029F24A[0];
        (*(u8 *)((u8 *)(reg_a5) + (4))) = (u8) reg_d1.b[0];
        (*(u8 *)((u8 *)(reg_a5) + (6))) = (u8) reg_d1.b[0];
        (*(s8 *)((u8 *)(reg_a6) + (0x70))) = 3;
        reg_d1.w = 0;
        if (D_0028E934 != 0) {
            reg_d1.w = 1;
        }
        (*(u16 *)((u8 *)(reg_a6) + (0x72))) = (u16) reg_d1.h[0];
        reg_d0.w = 1;
        func_001A33C0();
        reg_d0.w = 1;
        func_001A35A0();
    } else if (reg_d0.b[0] == 1) {
        (*(s8 *)((u8 *)(reg_a0) + (1))) = 1;
        reg_d1.h[0] = D_0029F2B8[0];
        (*(u8 *)((u8 *)(reg_a5) + (9))) = (u8) reg_d1.b[0];
        reg_d1.h[0] = D_0029F2BA[0];
        (*(u8 *)((u8 *)(reg_a5) + (5))) = (u8) reg_d1.b[0];
        (*(u8 *)((u8 *)(reg_a5) + (7))) = (u8) reg_d1.b[0];
        (*(s8 *)((u8 *)(reg_a6) + (0))) = 3;
        reg_d1.w = 0;
        if (D_0028E938 != 0) {
            reg_d1.w = 1;
        }
        (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d1.h[0];
        reg_d0.w = 0;
        func_001A33C0();
        reg_d0.w = 0;
        func_001A35A0();
    }
    func_0012FAB0();
    reg_a0 = (u8 *)D_00269140;
    reg_d0.w = 0;
    func_001A2FA0();
    reg_a0 = (u8 *)D_0025F770;
    reg_d0.w = 2;
    func_001A3020();
    reg_a0 = (u8 *)D_00260930;
    reg_d0.w = 0x18;
    func_001A3020();
    reg_a0 = (u8 *)D_00260970;
    reg_d0.w = 0x19;
    func_001A3020();
    reg_a0 = (u8 *)D_002609B0;
    reg_d0.w = 0x1B;
    func_001A3020();
    reg_a0 = (u8 *)D_002609F0;
    reg_d0.w = 0x1A;
    func_001A3020();
    reg_a0 = (u8 *)D_00260A30;
    reg_d0.w = 0x1C;
    func_001A3020();
    reg_a0 = (u8 *)D_00260CB0;
    reg_d0.w = 0x12;
    func_001A3020();
    reg_a0 = (u8 *)D_00260D70;
    reg_d0.w = 0x13;
    func_001A3020();
    reg_a0 = (u8 *)D_00260E70;
    reg_d0.w = 0x14;
    func_001A3020();
    reg_a0 = (u8 *)D_00260DB0;
    reg_d0.w = 0x10;
    func_001A3020();
    reg_a0 = (u8 *)D_00260CF0;
    reg_d0.w = 0x15;
    func_001A3020();
    reg_a0 = (u8 *)D_00260E30;
    reg_d0.w = 0x16;
    func_001A3020();
    reg_a0 = (u8 *)D_00260DF0;
    reg_d0.w = 0x17;
    func_001A3020();
    reg_a0 = (u8 *)D_00260D30;
    reg_d0.w = 0x11;
    func_001A3020();
    if (D_0028ED7C == 1) {
        func_0023C1E0(D_006CB1D4);
    }
    reg_d0.h[0] = 0xA;
    func_002071C0();
    (*(s16 *)((u8 *)(reg_a0) + (4))) = 0;
}
