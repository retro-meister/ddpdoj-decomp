#include "common.h"

s32 func_0018D4B0();
s32 func_0021F1C0();
s32 func_0021F2C0();
s32 func_0021F440();
s32 func_00221120();
s32 func_00222260();
s32 func_00222780();
extern s8 D_0028E250;
extern s8 D_0028E254;
extern u16 D_0028E320;
extern s8 D_0028EAE0;
extern s8 D_0028EAE4;
extern s8 D_0028EB04;
extern s8 D_0028EB14;
extern s8 D_0028EB38;
extern s8 D_0028EB4C;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB68;
extern s8 D_0028EB7C;
extern s8 D_0028EB84;
extern s32 D_0028EB90;
extern s32 D_0057CC78[];
extern s32 D_0057CC88[];
void func_0021EFB0(void) {
    s32 var_a1;

    if (func_00221120(0xF) == 0) {
        func_0021F1C0();
    }
    func_0021F2C0();
    var_a1 = 0;
    D_0028E320 = 0xE10;
    if (D_0057CC88[0] == 0) {
        D_0028E320 -= 1;
        if ((s32) D_0028E320 <= 0) {
            var_a1 = 1;
            D_0028EB58 = 0xD;
        }
    } else {
        D_0028E320 = 0xE10;
    }
    D_0028EB14 = D_0028EB58;
    if (D_0057CC78[0] & 0x20) {
        var_a1 = 1;
    }
    if ((D_0028EB14 >= 9) && (D_0028EB14 < 0xC)) {
        if (D_0057CC78[0] != 0) {
            var_a1 = 1;
        }
    } else if (D_0057CC78[0] & 0x40) {
        var_a1 = 1;
        D_0028EB58 = 0xD;
    }
    if (var_a1 != 0) {
        switch (D_0028EB58) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 8:
            break;
        case 7:
            func_0018D4B0();
            D_0028EB90 = 0x80;
            D_0028EAE4 = D_0028E254;
            D_0028EB84 = 0x10;
            D_0028EAE0 = D_0028E250;
            break;
        case 9:
            func_00222780();
            break;
        case 10:
            func_00222780();
            break;
        case 11:
            func_00222780();
            break;
        case 12:
            func_0018D4B0();
            func_0021F440();
            func_0021F2C0();
            break;
        case 13:
            func_0018D4B0();
            func_00222260(0);
            D_0028EB7C = 3;
            D_0028EB84 = 0;
            D_0028EB90 = 0x40;
            D_0028EB4C = 1;
            D_0028EB54 = 2;
            D_0028EB38 = 2;
            D_0028EB04 = 1;
            D_0028EB68 += 1;
            break;
        }
    }
}
