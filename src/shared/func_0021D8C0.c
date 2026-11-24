#include "common.h"

s32 memcpy(s32 *, s32 *, s32);      /* extern */
extern s32 D_00270810[];
extern s32 D_00270828[];
extern s32 D_00270838[];
extern s32 D_0068DE90[];
extern s32 D_0068DEA0[];
extern s32 D_0068DEB0[];
extern s32 D_0068DEC8_as_s32_a[];
extern s32 D_0068DED8_as_s32_a[];
extern s32 D_0068DEF0_as_s32_a[];

void func_0021D8C0(void) {
    memcpy(D_0068DEF0_as_s32_a, D_00270810, 0x16);
    memcpy(D_0068DED8_as_s32_a, D_00270828, 0xA);
    memcpy(D_0068DEC8_as_s32_a, D_00270838, 0xC);
    memcpy(D_0068DEB0, D_00270810, 0x16);
    memcpy(D_0068DE90, D_00270828, 0xA);
    memcpy(D_0068DEA0, D_00270838, 0xC);
}
