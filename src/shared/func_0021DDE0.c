#include "common.h"

s32 func_0018D4B0();
s32 func_0021E000();
s32 func_0021E160();
s32 func_0021E2D0();
s32 func_00221120();
s32 func_00222260();
extern u16 D_0028E320_as_u16;
extern s8 D_0028EB04;
extern s8 D_0028EB24;
extern s8 D_0028EB3C;
extern s8 D_0028EB48;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB6C;
extern s8 D_0028EB78;
extern s8 D_0028EB84;
extern s32 D_0028EB90;
extern s32 D_0057CC78[];
extern s32 D_0057CC88[];
void func_0021DDE0(void) {
    s32 var_a1;

    if (func_00221120(1) == 0) {
        func_0021E000();
    }
    func_0021E160();
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (D_0057CC88[0] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            D_0028EB58 = 6;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (D_0057CC78[0] & 0x20) {
        var_a1 = 1;
    }
    D_0028EB24 = D_0028EB58;
    if ((D_0028EB24 >= 7) && (D_0028EB24 < 0xB)) {
        if (D_0057CC78[0] != 0) {
            var_a1 = 1;
        }
    } else if (D_0057CC78[0] & 0x40) {
        var_a1 = 1;
        D_0028EB58 = 6;
    }
    if (var_a1 != 0) {
        switch (D_0028EB58) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            break;
        case 5:
            func_0018D4B0();
            func_0021E2D0();
            func_0021E160();
            break;
        case 6:
            func_0018D4B0();
            func_00222260(0xE);
            D_0028EB6C = 3;
            D_0028EB84 = 0xE;
            D_0028EB90 = 0x40;
            D_0028EB3C = 1;
            D_0028EB54 = 2;
            D_0028EB48 = 2;
            D_0028EB04 = 1;
            D_0028EB78 += 1;
            break;
        }
    }
}
