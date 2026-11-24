#include "common.h"

void func_00216210(s32);
extern s32 D_0025BCF0[];
extern s32 D_0029CAB0[][2];
extern s32 D_002C0100[];
extern s32 D_002C0104[];

void func_0018E420(void) {
    s32 i;

    for (i = 0; i < MAIN_OR_DEATH_LABEL(0xE, 0x10); i++) {
        func_00216210(D_0025BCF0[i]);
        D_0029CAB0[i][0] = D_002C0104[0];
        D_0029CAB0[i][1] = D_002C0100[0];
    }
}
