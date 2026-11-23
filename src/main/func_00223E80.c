#include "common.h"

extern void func_00213060(void);
extern void func_00214C70(s32 level);
extern void func_00215350(void);
extern void func_00215DB0(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
extern void func_002228D0(s32 x, s32 y);
extern void func_00224020(s32 x, s32 y);
extern u8 *D_00271B30[];
extern u8 *D_00271B60[];
extern u8 *D_00271B90[];
extern u8 D_0028E36C;
extern s8 D_0028EB04;
extern s32 D_0028EB90;
extern s8 D_0028EBD0;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;
extern u8 *reg_a0;

void func_00223E80(void) {
    s64 alpha;

    switch (D_0028EB04) {
    case 0:
        break;
    case 1:
        D_0028EB90 += 4;
        if (D_0028EB90 >= 0x80) {
            D_0028EB04 = 0;
            D_0028EB90 = 0x80;
        }
        break;
    case 2:
        D_0028EB90 -= 4;
        if (D_0028EB90 <= 0) {
            D_0028EB90 = 0;
            D_0028EB04 = 0;
        }
        break;
    }
    if (D_0028EB90 != 0) {
        func_00213060();
        alpha = D_0028EB90;
        if (D_0028EB90 >= 0x40) {
            alpha = 0x40;
        }
        if (alpha != 0) {
            func_00214C70(D_0028EB90);
            func_00215DB0(0xC, 8, 0x40, 0xD0, 0x12C, alpha, 1, 1, 0x40);
        }
        if (D_0028E36C != 5) {
            if (D_0028ED7C == 2) {
                reg_a0 = D_00271B90[D_0028EBD0];
            } else if (D_0028ED80 != 0) {
                reg_a0 = D_00271B60[D_0028EBD0];
            } else {
                reg_a0 = D_00271B30[D_0028EBD0];
            }
            func_002228D0(0x36, 8);
        } else {
            func_00224020(0xC, 8);
        }
        func_00215350();
    }
}
