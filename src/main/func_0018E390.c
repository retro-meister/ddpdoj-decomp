#include "common.h"

void func_00216210(s32);
extern s32 D_0025BCC0[];
extern s32 D_0029CB50[][2];
extern s32 D_002C0100[];
extern s32 D_002C0104[];

void func_0018E390(void) {
    s32 i;

    for (i = 0; i < 0xA; i++) {
        func_00216210(D_0025BCC0[i]);
        D_0029CB50[i][0] = D_002C0104[0];
        D_0029CB50[i][1] = D_002C0100[0];
    }
}
