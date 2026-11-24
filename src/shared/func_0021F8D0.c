#include "common.h"

s32 func_0015BDD0();
s32 func_0018CBB0();
s32 func_0018D4B0();
s32 func_001A3E70();
s32 func_002212C0();
s32 func_00222260();
extern s8 D_0028E294_as_s8;
extern u16 D_0028E320_as_u16;
extern s32 D_0028EAEC;
extern s32 D_0028EAF0;
extern s32 D_0028EAF4;
extern s8 D_0028EB04;
extern s8 D_0028EB08;
extern s8 D_0028EB2C;
extern s8 D_0028EB4C;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB5C;
extern s8 D_0028EB7C;
extern s8 D_0028EB84;
extern s32 D_0028EB90;
extern s32 D_0028EB94;
extern s32 D_0057CC78[];
extern s32 D_0057CC88[];
void func_0021F8D0(void) {
    s32 var_s0;

    if (D_0028EAF0 == 0) {
        func_002212C0(0x18);
    }
    var_s0 = 0;
    D_0028E294_as_s8 = 1;
    func_001A3E70();
    D_0028E320_as_u16 = 0xE10;
    if (D_0057CC88[0] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_s0 = 1;
            D_0028EB58 = 5;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (D_0057CC78[0] & 0x40) {
        var_s0 = 1;
        D_0028EB58 = 5;
    } else if (D_0057CC78[0] & 0x20) {
        var_s0 = 1;
    }
    D_0028EB08 = D_0028EB58;
    if (var_s0 != 0) {
        switch (D_0028EB58) {
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            func_0018D4B0();
            if (D_0028EAF4 == 0) {
                D_0028EAEC = 0;
                D_0028EAF0 = 1;
                D_0028EAF4 = 1;
                break;
            }
            D_0028EAF4 = 0;
            D_0028EAF0 = 2;
            break;
        case 5:
            func_0018CBB0();
            func_00222260(0);
            D_0028EB7C = 3;
            D_0028EB4C = 1;
            D_0028EB90 = 0x40;
            D_0028EB04 = 1;
            D_0028EB54 = 2;
            D_0028EB84 = 0;
            D_0028EB2C = 0;
            D_0028EB94 = 0;
            D_0028EAF0 = 0;
            D_0028EAEC = 0;
            D_0028EAF4 = 0;
            D_0028EB5C += 1;
            func_0015BDD0();
            func_0018D4B0();
            break;
        }
    }
}
