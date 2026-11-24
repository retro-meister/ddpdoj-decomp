#include "common.h"

s32 func_0014D4A0();
extern s16 D_0028E7D4;
extern s16 D_0028E7D8;
extern s16 D_0028E7DC;
extern s16 D_0028E7E0;
extern s16 D_0028E7E4;
extern s16 D_0028E7E8;
extern s16 D_0028E7EC;
extern s8 D_002BBAF0[];
extern s8 D_002BBB40[];
typedef struct { s8 a[0xC80]; s8 b[0x640]; s8 c[0x640]; } S1;
extern S1 D_002BC7C0;
typedef struct { s8 a[0xA0]; s8 b[0x280]; s8 c[0xF00]; s8 d[0x50]; } S0;
extern S0 D_002BE0C0;

void func_0014D260(void) {
    s32 i;

    for (i = 0; i < 0xA0; i++) {
        D_002BE0C0.a[i] = 0;
    }
    for (i = 0; i < 0x280; i++) {
        D_002BE0C0.b[i] = 0;
    }
    for (i = 0; i < 0xF00; i++) {
        D_002BE0C0.c[i] = 0;
    }
    for (i = 0; i < 0x50; i++) {
        D_002BE0C0.d[i] = 0;
    }
    for (i = 0; i < 0xC80; i++) {
        D_002BC7C0.a[i] = 0;
    }
    for (i = 0; i < 0x640; i++) {
        D_002BC7C0.b[i] = 0;
    }
    for (i = 0; i < 0x640; i++) {
        D_002BC7C0.c[i] = 0;
    }
    D_0028E7D4 = 0;
    D_0028E7D8 = 0;
    D_0028E7DC = 0;
    D_0028E7E0 = 0;
    D_0028E7E4 = 0;
    D_0028E7E8 = 0;
    D_0028E7EC = 0;
    for (i = 0; i < 0xC80; i++) {
        D_002BBB40[i] = 0;
    }
    for (i = 0; i < 0x50; i++) {
        D_002BBAF0[i] = 0;
    }
    func_0014D4A0();
}
