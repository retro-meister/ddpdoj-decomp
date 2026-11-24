#include "common.h"

void func_00215DB0(s32 a, s32 b, s32 c, s32 d, s32 e, s64 alpha, s32 g, s32 h, s32 i);
extern s16 D_0028E9E0;
extern s16 D_0028E9E4;
extern s8 D_0028E9E8;

#ifdef DEATH_LABEL
extern s8 death_D_00290B60;
#endif

void func_00217A50(void) {
    switch (D_0028E9E8) {                           /* irregular */
    case 0:
        break;
    case 1:
        D_0028E9E8 = 3;
        D_0028E9E0 = 0x80;
        D_0028E9E4 = -8;
        break;
    case 2:
        D_0028E9E8 = 3;
        D_0028E9E4 = 8;
        D_0028E9E0 = 0;
        break;
    case 3:
        D_0028E9E0 += D_0028E9E4;
        if (D_0028E9E0 < 0) {
            D_0028E9E0 = 0;
            D_0028E9E8 = 0;
        }
        if (D_0028E9E0 > 0x80) {
            D_0028E9E8 = 0;
            D_0028E9E0 = 0x80;
        }
        break;
    }
#ifdef DEATH_LABEL
    if (D_0028E9E0 != 0) {
        if (death_D_00290B60 == 0) {
            func_00215DB0(0, 0, 0x1C2, 0xE0, 0x1F4, D_0028E9E0, 1, 1, 1);
        } else {
            func_00215DB0(0, 0, 0x1C2, 0xE0, 0x1F4, D_0028E9E0, 0xFF, 0xFF, 0xFF);
        }
    }
#else
    if (D_0028E9E0 != 0) {
        func_00215DB0(0, 0, 0x1C2, 0xE0, 0x1F4, D_0028E9E0, 1, 1, 1);
    }
#endif
}
