#include "common.h"

s32 memset(s32 *, s32, s32);        /* extern */
extern s32 D_006E5BE0_as_s32_a[];
extern s16 D_006E5BE2[];
extern s16 D_006E5BE4[];
extern s16 D_006E5BE6[];
extern s16 D_006E5BE8[];

void func_00236D50(void) {
    memset(D_006E5BE0_as_s32_a, 0, 0x42);
    D_006E5BE2[0] = 0xFF;
    D_006E5BE4[0] = 0xFF;
    D_006E5BE6[0] = 0xFF;
    D_006E5BE8[0] = 0xFF;
}
