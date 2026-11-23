#include "common.h"

extern void func_00215DB0(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
extern s16 D_00271C8C[];
extern s16 D_00271C90[];
extern s16 D_0028EBC8;
extern s8 D_0028EBCC;
extern s8 D_0028EBD0;
extern u8 D_0028ED80;

void func_00223D70(void) {
    s32 x;

    switch (D_0028EBCC) {
    case 0:
        break;
    case 1:
        D_0028EBC8 += 4;
        if (D_0028EBC8 >= 0x40) {
            D_0028EBCC = 0;
            D_0028EBC8 = 0x40;
        }
        break;
    case 2:
        D_0028EBC8 -= 4;
        if (D_0028EBC8 <= 0) {
            D_0028EBC8 = 0;
            D_0028EBCC = 0;
        }
        break;
    }
    if (D_0028ED80 == 0 && D_0028EBD0 > 6) {
        x = D_00271C8C[D_0028EBD0 * 2];
    } else {
        x = D_00271C90[D_0028EBD0 * 2];
    }
    if (D_0028EBC8 != 0) {
        func_00215DB0(x - 8, 0, 0x12, 0xE0, 0x5A, D_0028EBC8, 0xB4, 1, 1);
    }
}
