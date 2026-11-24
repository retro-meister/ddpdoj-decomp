#include "common.h"

extern void sceGsResetGraph(s32, s32, s32, s32);
extern void sceDmaPutEnv(void *);
extern void sceDmaGetEnv(void *);
extern void sceGsSetDefDBuffDc(void *, s32, s32, s32, s32, s32, s32);
extern u8 D_0057C7E0[];
extern s64 D_0057C960[];
extern s64 D_0057CAD0[];

void func_002163F0(void) {
    s16 env[16];

    sceDmaGetEnv(env);
    env[3] = 2;
    sceDmaPutEnv(env);
    sceGsResetGraph(0, 1, 2, 0);
    sceGsSetDefDBuffDc(D_0057C7E0, 2, 0x200, 0x1C0, 1, 0x31, 0);
    D_0057C960[0] = 0;
    D_0057CAD0[0] = 0;
}
