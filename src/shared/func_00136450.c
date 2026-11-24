#include "common.h"

s32 func_00125DE0();
s32 func_00131630();
s32 func_001340F0();
s32 func_00134FE0();
s32 func_00135220();
s32 func_00135ED0();
s32 func_0013FD80();
s32 func_00171ED0();
s32 func_001A2FA0();
s32 func_001AACC0();
s32 func_001AE490();
extern u8 D_00269160[];
extern u8 D_00269180[];
extern u8 D_002691A0[];
extern u8 D_002691C0[];
extern u8 D_002691E0[];
extern u8 D_00269200[];
extern u8 D_002692A0[];
extern u8 D_002692C0[];
extern u8 D_002692E0[];
extern u8 D_00269300[];
extern s32 D_0028E83C;
extern s32 D_0028E840;
extern s32 D_0028E844;
extern s32 D_0028E848;
extern s32 D_0028E84C;
extern u16 D_0028E850;
extern u16 D_0028E8C0;
extern u16 D_0028E8C4;
extern u16 D_0028E910;
extern u16 D_0028E93C;
extern u16 D_0028E940;
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_00136450(void) {
    (*(s8 *)((u8 *)(reg_a5) + (3))) = 1;
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
    reg_a0 = (u8 *)D_00269200;
    reg_d0.w = 5;
    func_001A2FA0();
    reg_a0 = (u8 *)D_002692A0;
    reg_d0.w = 6;
    func_001A2FA0();
    reg_a0 = (u8 *)D_002692C0;
    reg_d0.w = 7;
    func_001A2FA0();
    reg_a0 = (u8 *)D_002692E0;
    reg_d0.w = 8;
    func_001A2FA0();
    reg_a0 = (u8 *)D_00269300;
    reg_d0.w = 0xB;
    func_001A2FA0();
    D_0028E93C = 1;
    D_0028E940 = 0;
    if (D_0028E910 == 0) {
        func_00135ED0();
    } else {
        D_0028E850 = 0;
        D_0028E8C4 = 0xFFFF;
        D_0028E8C0 = 0xFFFF;
        D_0028E84C = 0;
        D_0028E848 = 0;
        D_0028E844 = 0;
        D_0028E840 = 0;
        D_0028E83C = 0;
    }
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (4)));
    func_00134FE0();
    func_00131630();
    func_00171ED0();
    if (D_0028E910 == 0) {
        func_00125DE0();
        func_001AE490();
        func_001AACC0();
        func_0013FD80();
    }
    func_00135220();
    func_001340F0();
}
