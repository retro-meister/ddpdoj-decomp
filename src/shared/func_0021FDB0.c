#include "common.h"

extern void func_00213060(void);
extern void func_00215350(void);
extern void func_0021C100(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
extern void func_00224BA0(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag, s32 kind);
extern s8 D_002714F1[];
extern u8 *D_00271540[];
extern u8 *D_00271640[];
extern u8 *D_00271650[];
extern u8 *D_00271670[][2];
extern s16 D_00271800[];
extern u8 *D_0028DD18[2];
extern s8 D_0028EB24;
extern s8 D_0028EB48;
extern s32 D_0028EBB0;
extern u8 D_00685010[];
extern s8 D_0068DC10[];
extern u8 *reg_a0;

void func_0021FDB0(void) {
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 count;
    s32 index;
    s32 top;
    u8 *item;
    u8 **pair;

    count = D_002714F1[0];
    switch (D_0028EB48) {
    case 0:
        break;
    case 1:
        D_0028EBB0 += 4;
        if (D_0028EBB0 >= 0x80) {
            D_0028EB48 = 0;
            D_0028EBB0 = 0x80;
        }
        break;
    case 2:
        D_0028EBB0 -= 4;
        if (D_0028EBB0 <= 0) {
            D_0028EBB0 = 0;
            D_0028EB48 = 0;
        }
        break;
    }
    func_00213060();
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x3B4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x3AC) = D_0028EBB0;
        reg_a0 = D_00271540[i];
        x = *(s32 *)(item + 0x380);
        alpha = *(s32 *)(item + 0x3AC);
        top = *(s32 *)(item + 0x384);
        z = *(s32 *)(item + 0x3B0);
        if (alpha == 0) {
            continue;
        }
        func_0021C100(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0x10 + i];
        if (i == 1) {
            reg_a0 = D_00271640[index];
            func_0021C100(x, y, z, 0, 0x80, alpha, 1);
            if (D_0028EB24 == 1) {
                func_00224BA0(x, y, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 2) {
            reg_a0 = D_00271650[index];
            func_0021C100(x, y, z, 0, 0x80, alpha, 1);
            if (D_0028EB24 == 2) {
                func_00224BA0(x, y, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 3) {
            if (index == 3) {
                reg_a0 = D_00271670[index][0];
                func_0021C100(x, y, z, 0, 0x80, alpha, 1);
            } else {
                pair = D_00271670[index];
                reg_a0 = pair[0];
                func_0021C100(x, y, z, 0, 0x80, alpha, 0);
                reg_a0 = pair[1];
                func_0021C100(x - 8, y, z, 0, 0x80, alpha, 0);
            }
            if (D_0028EB24 == 3) {
                func_00224BA0(x, y, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 4) {
            reg_a0 = D_0028DD18[index];
            func_0021C100(x, y, z, 0, 0x80, alpha, 1);
            if (D_0028EB24 == 4) {
                func_00224BA0(x, y, z, 0, 0x80, alpha, 1, 3);
            }
        }
    }
    func_00215350();
}
