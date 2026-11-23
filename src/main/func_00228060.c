#include "common.h"

extern void *memcpy(void *dst, const void *src, u32 n);
extern s16 D_00270810[];
extern s16 D_00270828[];
extern s16 D_00270838[];
extern s16 D_0068DE90[];
extern s16 D_0068DEA0[];
extern s16 D_0068DEB0[];
extern s16 D_0068DEC8[];
extern s16 D_0068DECA[];
extern s16 D_0068DECC[];
extern s16 D_0068DECE[];
extern s16 D_0068DED0[];
extern s16 D_0068DED2[];
extern s16 D_0068DED8[];
extern s16 D_0068DEDA[];
extern s16 D_0068DEDC[];
extern s16 D_0068DEDE[];
extern s16 D_0068DEE0[];
extern s16 D_0068DEF0[];
extern s16 D_0068DEF2[];
extern s16 D_0068DEF4[];
extern s16 D_0068DEF6[];
extern s16 D_0068DEF8[];
extern s16 D_0068DEFA[];
extern s16 D_0068DEFC[];
extern s16 D_0068DEFE[];
extern s16 D_0068DF00[];
extern s16 D_0068DF04[];
extern u16 D_006C58A2[];
extern u16 D_006C58A4[];
extern u16 D_006C58A6[];
extern u16 D_006C58A8[];
extern u16 D_006C58AA[];
extern u16 D_006C58B0[];
extern u16 D_006C58B2[];
extern u16 D_006C58B4[];
extern u16 D_006C58B6[];
extern u16 D_006C58B8[];
extern u16 D_006C58BA[];
extern u16 D_006C58BC[];
extern u16 D_006C58BE[];
extern u16 D_006C58C0[];
extern u16 D_006C58C2[];
extern u16 D_006C58C6[];
extern u16 D_006C58C8[];
extern u16 D_006C58CA[];
extern u16 D_006C58CC[];
extern u16 D_006C58CE[];
extern u16 D_006C58D0[];
extern u16 D_006C58D2[];
extern u16 D_006C58D4[];

void func_00228060(void) {
    memcpy(D_0068DEF0, D_00270810, 0x16);
    memcpy(D_0068DED8, D_00270828, 0xA);
    memcpy(D_0068DEC8, D_00270838, 0xC);
    D_0068DED8[0] = D_006C58AA[0];
    D_0068DEDE[0] = D_006C58C6[0];
    D_0068DEE0[0] = D_006C58C8[0];
    if (D_006C58A2[0] == 0xFF) {
        if (D_006C58A6[0] == 0) {
            D_0068DEDA[0] = 0;
        } else {
            D_0068DEDA[0] = 1;
        }
        if (D_006C58A8[0] == 2) {
            D_0068DEDC[0] = 0;
        } else if (D_006C58A8[0] == 4) {
            D_0068DEDC[0] = 1;
        } else {
            D_0068DEDC[0] = 2;
        }
    } else {
        if (D_006C58A2[0] == 0) {
            D_0068DEDA[0] = 0;
        } else {
            D_0068DEDA[0] = 1;
        }
        if (D_006C58A4[0] == 2) {
            D_0068DEDC[0] = 0;
        } else if (D_006C58A4[0] == 4) {
            D_0068DEDC[0] = 1;
        } else {
            D_0068DEDC[0] = 2;
        }
    }
    D_0068DEF0[0] = D_006C58B8[0];
    D_0068DEF2[0] = D_006C58BA[0];
    D_0068DEF4[0] = D_006C58C0[0];
    D_0068DF04[0] = D_006C58C2[0];
    D_0068DEF6[0] = D_006C58B4[0];
    D_0068DEF8[0] = D_006C58B6[0];
    D_0068DEFA[0] = D_006C58CA[0];
    D_0068DEFE[0] = D_006C58BC[0];
    D_0068DF00[0] = D_006C58BE[0];
    D_0068DEFC[0] = D_006C58CC[0];
    D_0068DEC8[0] = D_006C58CE[0];
    D_0068DECA[0] = D_006C58D0[0];
    D_0068DECC[0] = D_006C58D2[0];
    D_0068DECE[0] = D_006C58B0[0];
    D_0068DED0[0] = D_006C58B2[0];
    D_0068DED2[0] = D_006C58D4[0];
    if (D_0068DED8[0] > 3) {
        D_0068DED8[0] = 1;
    }
    if (D_0068DEDE[0] > 19) {
        D_0068DEDE[0] = 20;
    }
    if (D_0068DEE0[0] > 3) {
        D_0068DEE0[0] = 0;
    }
    if (D_0068DEF0[0] > 1) {
        D_0068DEF0[0] = 0;
    }
    if (D_0068DEF2[0] > 1) {
        D_0068DEF2[0] = 0;
    }
    if (D_0068DEF4[0] > 255) {
        D_0068DEF4[0] = 0;
    }
    if (D_0068DF04[0] > 1) {
        D_0068DF04[0] = 0;
    }
    if (D_0068DEF6[0] > 5) {
        D_0068DEF6[0] = 6;
    }
    if (D_0068DEF8[0] > 7) {
        D_0068DEF8[0] = 8;
    }
    if (D_0068DEFA[0] > 1) {
        D_0068DEFA[0] = 0;
    }
    if (D_0068DEFE[0] > 5) {
        D_0068DEFE[0] = 0;
    }
    if (D_0068DF00[0] > 500) {
        D_0068DF00[0] = 0;
    }
    if (D_0068DEFC[0] > 100) {
        D_0068DEFC[0] = 0;
    }
    if (D_0068DEC8[0] > 2) {
        D_0068DEC8[0] = 0;
    }
    if (D_0068DECA[0] > 9) {
        D_0068DECA[0] = 0;
    }
    if (D_0068DECC[0] > 15) {
        D_0068DECC[0] = 0;
    }
    if (D_0068DECE[0] > 4) {
        D_0068DECE[0] = 0;
    }
    if (D_0068DED0[0] > 4) {
        D_0068DED0[0] = 0;
    }
    if (D_0068DED2[0] > 10) {
        D_0068DED2[0] = 0;
    }
    memcpy(D_0068DEB0, D_0068DEF0, 0x16);
    memcpy(D_0068DE90, D_0068DED8, 0xA);
    memcpy(D_0068DEA0, D_0068DEC8, 0xC);
}
