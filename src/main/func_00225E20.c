#include "common.h"

extern void func_00215DB0(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
extern s16 D_00271CE0[];
extern s32 D_0028EAC0;
extern s32 D_0028EAC4;
extern s8 D_0028EAC8;

void func_00225E20(void) {
    s32 x;

    switch (D_0028EAC0) {
    case 0:
        break;
    case 1:
        D_0028EAC4 += 4;
        if (D_0028EAC4 >= 0x40) {
            D_0028EAC0 = 0;
            D_0028EAC4 = 0x3C;
        }
        break;
    case 2:
        D_0028EAC4 -= 4;
        if (0 >= D_0028EAC4) {
            D_0028EAC4 = 0;
            D_0028EAC0 = 0;
        }
        break;
    }
    x = D_00271CE0[D_0028EAC8 * 2];
    if (D_0028EAC4 != 0) {
        func_00215DB0(x - 8, 0, 0x12, 0xE0, 0x5A, D_0028EAC4, 0xB4, 1, 1);
    }
}
