#include "common.h"

extern void func_00215DB0(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
extern s16 D_00271760[];
extern s16 D_002717A0[];
extern s8 D_0028EB50;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB84;

void func_00221440(void) {
    s32 sel;
    s32 x;

    switch (D_0028EB54) {
    case 0:
        break;
    case 1:
        D_0028EB50 += 4;
        if (D_0028EB50 >= 0x40) {
            D_0028EB54 = 0;
            D_0028EB50 = 0x40;
        }
        break;
    case 2:
        D_0028EB50 -= 4;
        if (D_0028EB50 <= 0) {
            D_0028EB50 = 0;
            D_0028EB54 = 0;
        }
        break;
    }
    sel = D_0028EB58;
    if (sel != -1) {
        if (D_0028EB84 == 0xF) {
            x = D_002717A0[sel * 2];
        } else {
            x = D_00271760[sel * 2];
        }
        if (D_0028EB50 != 0 && sel != 0) {
            func_00215DB0(x - 8, 0, 0x12, 0xE0, 0x5A, D_0028EB50, 0xB4, 1, 1);
        }
    }
}
