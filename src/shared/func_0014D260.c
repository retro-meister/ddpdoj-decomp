#include "common.h"

s32 func_0014D4A0();
extern s16 D_0028E7D4_as_s16;
extern s16 D_0028E7D8;
extern s16 D_0028E7DC;
extern s16 D_0028E7E0;
extern s16 D_0028E7E4_as_s16;
extern s16 D_0028E7E8_as_s16;
extern s16 D_0028E7EC_as_s16;
extern s8 D_002BBAF0_as_s8_a[];
extern s8 D_002BBB40_as_s8_a[];
typedef struct { s8 a[0xC80]; s8 b[0x640]; s8 c[0x640]; } S1;
extern S1 D_002BC7C0_as_S1;
typedef struct { s8 a[0xA0]; s8 b[0x280]; s8 c[0xF00]; s8 d[0x50]; } S0;
extern S0 D_002BE0C0_as_S0;

void func_0014D260(void) {
    s32 i;

    for (i = 0; i < 0xA0; i++) {
        D_002BE0C0_as_S0.a[i] = 0;
    }
    for (i = 0; i < 0x280; i++) {
        D_002BE0C0_as_S0.b[i] = 0;
    }
    for (i = 0; i < 0xF00; i++) {
        D_002BE0C0_as_S0.c[i] = 0;
    }
    for (i = 0; i < 0x50; i++) {
        D_002BE0C0_as_S0.d[i] = 0;
    }
    for (i = 0; i < 0xC80; i++) {
        D_002BC7C0_as_S1.a[i] = 0;
    }
    for (i = 0; i < 0x640; i++) {
        D_002BC7C0_as_S1.b[i] = 0;
    }
    for (i = 0; i < 0x640; i++) {
        D_002BC7C0_as_S1.c[i] = 0;
    }
    D_0028E7D4_as_s16 = 0;
    D_0028E7D8 = 0;
    D_0028E7DC = 0;
    D_0028E7E0 = 0;
    D_0028E7E4_as_s16 = 0;
    D_0028E7E8_as_s16 = 0;
    D_0028E7EC_as_s16 = 0;
    for (i = 0; i < 0xC80; i++) {
        D_002BBB40_as_s8_a[i] = 0;
    }
    for (i = 0; i < 0x50; i++) {
        D_002BBAF0_as_s8_a[i] = 0;
    }
    func_0014D4A0();
}
