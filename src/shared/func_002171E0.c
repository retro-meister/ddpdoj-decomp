#include "common.h"

s32 scePadInit(s32);                     /* extern */
s32 scePadPortOpen(s32, s32, s32 *); /* extern */
s32 memset(s32 *, s32, s32);        /* extern */
extern s32 D_0057CC10[];
extern s32 D_0057CC14[];
extern s32 D_0057CC18[];
extern s32 D_0057CC30[];
extern s32 D_0057CC34[];
extern s32 D_0057CC38[];
extern s32 D_0057CC40[];
extern s32 D_0057CC44[];
extern s32 D_0057CC48[];
extern s32 D_0057CC60[];
extern s32 D_0057CC64[];
extern s32 D_0057CC68[];
extern s32 D_0057CC70[];
extern s32 D_0057CC74[];
extern s32 D_0057CC78[];
extern s32 D_0057CC80[];
extern s32 D_0057CC84[];
extern s32 D_0057CC88[];
extern s32 D_0057CC90[];
extern s32 D_0057CD80[];
extern s32 D_0057CE80[];

void func_002171E0(void) {
    memset(D_0057CC90, 0, 0xB4);
    D_0057CC80[0] = 0;
    D_0057CC70[0] = 0;
    D_0057CC60[0] = 0;
    D_0057CC40[0] = 0;
    D_0057CC30[0] = 0;
    D_0057CC10[0] = 0;
    D_0057CC84[0] = 0;
    D_0057CC74[0] = 0;
    D_0057CC64[0] = 0;
    D_0057CC44[0] = 0;
    D_0057CC34[0] = 0;
    D_0057CC14[0] = 0;
    D_0057CC88[0] = 0;
    D_0057CC78[0] = 0;
    D_0057CC68[0] = 0;
    D_0057CC48[0] = 0;
    D_0057CC38[0] = 0;
    D_0057CC18[0] = 0;
    scePadInit(0);
    scePadPortOpen(0, 0, D_0057CD80);
    scePadPortOpen(1, 0, D_0057CE80);
}
