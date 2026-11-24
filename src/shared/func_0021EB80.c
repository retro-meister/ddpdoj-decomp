#include "common.h"

extern s32 func_00221120(s32 id);
extern void func_0021EDC0(void);
extern void func_0018D4B0(void);
extern void func_00169BC0(void);
extern void func_00217A40(void);
extern void func_00222260(s32 arg0);
extern u8 D_0028E290;
extern u8 D_0028E2E4;
extern u16 D_0028E320;
extern s32 D_0028EAFC;
extern s8 D_0028EB00;
extern s8 D_0028EB04;
extern s8 D_0028EB18;
extern s8 D_0028EB24;
extern s8 D_0028EB3C;
extern s8 D_0028EB4C;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB6C;
extern s8 D_0028EB78;
extern s8 D_0028EB7C;
extern s8 D_0028EB84;
extern s8 D_0028EB88;
extern s32 D_0028EB90;
extern s32 D_0057CC78[];
extern s32 D_0057CC88[];

void func_0021EB80(void) {
    s32 var_a1;

    if (func_00221120(0xE) == 0) {
        func_0021EDC0();
    }
    var_a1 = 0;
    D_0028E320 = 0xE10;
    if (D_0057CC88[0] == 0) {
        D_0028E320 -= 1;
        if ((s32) D_0028E320 <= 0) {
            var_a1 = 1;
            D_0028EB58 = 5;
        }
    } else {
        D_0028E320 = 0xE10;
    }
    if (D_0057CC78[0] & 0x20) {
        var_a1 = 1;
    }
    D_0028EB18 = D_0028EB58;
    if (D_0057CC78[0] & 0x40) {
        var_a1 = 1;
        D_0028EB58 = 5;
    }
    if (var_a1 != 0) {
        switch (D_0028EB58) {
        case 1:
            D_0028EB3C = 2;
#ifndef DEATH_LABEL
            D_0028EAFC = 0xFF;
#endif
            D_0028EB54 = 2;
            D_0028E290 = 0;
            D_0028E2E4 = 0;
            func_0018D4B0();
            func_00169BC0();
            func_00217A40();
            D_0028EB88 = 2;
            D_0028EB00 = 2;
            break;
        case 2:
            D_0028E290 = 1;
            D_0028E2E4 = 1;
#ifndef DEATH_LABEL
            D_0028EAFC = 0xFF;
#endif
            D_0028EB3C = 2;
            D_0028EB54 = 2;
            func_0018D4B0();
            func_00169BC0();
            func_00217A40();
            D_0028EB88 = 2;
            D_0028EB00 = 2;
            break;
        case 3:
            D_0028EB3C = 2;
            D_0028EB54 = 2;
            func_0018D4B0();
            D_0028EB78 = 0;
            D_0028EB84 = 1;
            D_0028EB24 = 0;
            break;
        case 4:
            break;
        case 5:
            func_0018D4B0();
            func_00222260(0);
            D_0028EB7C = 3;
            D_0028EB84 = 0;
            D_0028EB90 = 0x40;
            D_0028EB4C = 1;
            D_0028EB54 = 2;
            D_0028EB3C = 2;
            D_0028EB04 = 1;
            D_0028EB6C += 1;
            break;
        }
    }
}
