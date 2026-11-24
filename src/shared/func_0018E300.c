#include "common.h"

void func_00216210(s32);
extern s32 D_0025BC50[];
extern s32 D_0029CBF0[][2];
extern s32 D_002C0100[];
extern s32 D_002C0104[];

void func_0018E300(void) {
    s32 i;

    for (i = 0; i < 0x1A; i++) {
        func_00216210(D_0025BC50[i]);
        D_0029CBF0[i][0] = D_002C0104[0];
        D_0029CBF0[i][1] = D_002C0100[0];
    }
}
