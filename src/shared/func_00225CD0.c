#include "common.h"

s32 func_00225B90();
s32 func_00225CB0();
s32 func_00226260();
s32 func_002263C0();
s32 func_002263D0();
s32 func_0022A870();
extern s32 D_0028EAC0;
extern s32 D_0028EAC4;
extern s8 D_0028EAC8;
extern s8 D_0028EACC;
extern s8 D_0028EB04;
extern s32 D_0028EB8C;
extern s32 D_0028EB90;
extern s8 D_0028EC24;

s8 func_00225CD0(void) {
    s8 var_s0;

    var_s0 = 0;
    switch (D_0028EACC) {
    default:
        if (D_0028EACC != 0) {
            D_0028EACC += 1;
        }
        break;
    case 0x1:
        func_00225B90();
        break;
    case 0x2:
        var_s0 = D_0028EAC8;
        D_0028EACC += 1;
        break;
    case 0x3:
        func_00225CB0();
        break;
    case 0x20:
        D_0028EACC = 0;
        break;
    case 0x40:
        func_002263D0(1, D_0028EC24, 0);
        D_0028EACC += 1;
        break;
    case 0x41:
        switch (func_00226260()) {
        case 0:
            D_0028EACC = 1;
            D_0028EAC0 = 1;
            break;
        }
        break;
    case 0x50:
        func_0022A870();
        break;
    case 0x51:
        D_0028EAC4 = 0;
        D_0028EACC = 1;
        D_0028EAC0 = 1;
        D_0028EB04 = 1;
        D_0028EB90 = 0;
        D_0028EB8C = 0;
        func_002263C0();
        break;
    }
    return var_s0;
}
