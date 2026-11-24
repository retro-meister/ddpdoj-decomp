#include "common.h"

extern void func_00215DB0(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
extern void func_00219860(void);
extern s32 D_0026F940[];
extern s32 D_0028DC98;
extern u8 D_0028E28C;
extern u8 D_0028E2F0;
extern u8 D_0028E36C;
extern u16 D_0028E91C;
extern s32 D_0028E9DC;
extern s32 D_0028EA64;
extern s32 D_0028EA68;
extern s32 D_0028EA6C;
extern s32 D_0028EA70;

void func_002195F0(void) {
    s32 level;
    s32 top;
    s32 h;

    if (D_0028E2F0 == 0) {
        return;
    }
    switch (D_0028EA64) {
    case 0:
        break;
    case 1:
        D_0028EA70 += 8;
        if (D_0028EA70 >= 0x80) {
            D_0028EA64 = 3;
            D_0028EA70 = 0x80;
        }
        break;
    case 2:
        D_0028EA70 -= 8;
        if (D_0028EA70 <= 0) {
            D_0028EA70 = 0;
            D_0028EA64 = 0;
            D_0028E2F0 = 0;
        }
        break;
    case 3:
        break;
    }
    if (D_0028E36C == 0) {
        D_0028EA6C += D_0028EA68;
    }
    if (D_0028EA68 >= 0) {
        if (D_0028EA6C >= 0xFF) {
            D_0028EA6C = 0xFF;
            D_0028EA68 = -1;
        }
    } else if (D_0028EA6C <= 0x80) {
        D_0028EA6C = 0x80;
        D_0028EA68 = 1;
    }
    if ((D_0028DC98 == 2 || D_0028DC98 == 3) && D_0028EA70 != 0 && D_0028E28C != 0) {
        func_00219860();
        level = D_0028E9DC * D_0026F940[D_0028E91C] / 1000;
        level += 2;
        if (level >= 0x170) {
            level = 0x170;
        }
        top = 0x190 - level;
        h = top - 0x20;
        if (h > 0) {
            func_00215DB0(0x188, -0x50, 0x20, h, 12, D_0028EA70, 1, 1, 1);
        }
        func_00215DB0(0x188, top - 0x50, 0x20, 2, 12, D_0028EA70, D_0028EA6C, 0, 0);
        func_00215DB0(0x188, top - 0x70, 0x20, 2, 12, D_0028EA70, D_0028EA6C, 0, 0);
        func_00215DB0(0x188, top - 0x70, 2, 0x20, 12, D_0028EA70, D_0028EA6C, 0, 0);
        func_00215DB0(0x1A6, top - 0x70, 2, 0x20, 12, D_0028EA70, D_0028EA6C, 0, 0);
    }
}
