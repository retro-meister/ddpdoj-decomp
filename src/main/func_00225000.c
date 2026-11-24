#include "common.h"
#pragma opt_propagation off

s32 func_0018D4B0();
s32 func_0018D4C0();
s32 func_0021B570();
s32 func_00222260();
extern s32 D_0028DC98;
extern s8 D_0028E250;
extern s8 D_0028E254;
extern s8 D_0028EAE0;
extern s8 D_0028EAE4;
extern s8 D_0028EB04;
extern s8 D_0028EB38;
extern s8 D_0028EB68;
extern s8 D_0028EB84;
extern s32 D_0028EB90;
extern s32 D_0057CC68[];
extern s32 D_0057CC78[];
void func_00225000(void) {
    if (D_0057CC78[0] & 0x20) {
        func_0018D4B0();
        D_0028E254 = D_0028EAE4;
        D_0028E250 = D_0028EAE0;
        func_0021B570(D_0028E254, D_0028E250);
        D_0028EB04 = 1;
        D_0028EB90 = 0;
        func_00222260(0xF);
        D_0028EB84 = 0xF;
        D_0028EB68 = 3;
        D_0028EB38 = 1;
        return;
    }
    if (D_0057CC78[0] & 0x40) {
        func_0018D4B0();
        func_0021B570(D_0028E254, D_0028E250);
        D_0028EB04 = 1;
        D_0028EB90 = 0;
        func_00222260(0xF);
        D_0028EB84 = 0xF;
        D_0028EB68 = 3;
        D_0028EB38 = 1;
        return;
    }
    if (D_0057CC78[0] & 0x100) {
        func_0018D4B0();
        D_0028EAE4 = 0;
        D_0028EAE0 = 0;
        func_0021B570(D_0028EAE4, 0);
    }
    if ((D_0028DC98 != 2) && (D_0028DC98 != 3)) {
        if ((D_0057CC68[0] & 0x4000) && (D_0028EAE4 > -8)) {
            func_0018D4C0();
            D_0028EAE4 -= 1;
        }
        if ((D_0057CC68[0] & 0x1000) && (D_0028EAE4 < 8)) {
            func_0018D4C0();
            D_0028EAE4 += 1;
        }
        if ((D_0057CC68[0] & 0x2000) && (D_0028EAE0 < 8)) {
            func_0018D4C0();
            D_0028EAE0 += 1;
        }
        if ((D_0057CC68[0] & 0x8000) && (D_0028EAE0 > -8)) {
            func_0018D4C0();
            D_0028EAE0 -= 1;
        }
    } else {
        if ((D_0057CC68[0] & 0x4000) && (D_0028EAE0 < 8)) {
            func_0018D4C0();
            D_0028EAE0 += 1;
        }
        if ((D_0057CC68[0] & 0x1000) && (D_0028EAE0 > -8)) {
            func_0018D4C0();
            D_0028EAE0 -= 1;
        }
        if ((D_0057CC68[0] & 0x2000) && (D_0028EAE4 < 8)) {
            func_0018D4C0();
            D_0028EAE4 += 1;
        }
        if ((D_0057CC68[0] & 0x8000) && (D_0028EAE4 > -8)) {
            func_0018D4C0();
            D_0028EAE4 -= 1;
        }
    }
    func_0021B570(D_0028EAE4, D_0028EAE0);
}
