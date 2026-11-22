#include "common.h"

extern void func_001001E0(s32, s32, s32, s32);
extern void func_00101D20(void *);
extern void func_00101EF8(void *);
extern void sceGsSetDefDBuffDc(void *, s32, s32, s32, s32, s32, s32);
extern u8 D_0057C7E0[];
extern s64 D_0057C960[];
extern s64 D_0057CAD0[];

void func_002163F0(void) {
    s16 env[16];

    func_00101EF8(env);
    env[3] = 2;
    func_00101D20(env);
    func_001001E0(0, 1, 2, 0);
    sceGsSetDefDBuffDc(D_0057C7E0, 2, 0x200, 0x1C0, 1, 0x31, 0);
    D_0057C960[0] = 0;
    D_0057CAD0[0] = 0;
}
