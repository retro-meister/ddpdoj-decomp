#include "common.h"

extern void func_00213060(void);
extern void func_00215350(void);
extern void func_0021C100(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
extern void func_00224BA0(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag, s32 kind);
extern s8 D_002714F3[];
extern u8 *D_00271580[];
extern u8 *D_00271598[];
extern s16 D_00271800[];
extern u8 *D_0028DD28[2];
extern u8 *D_0028DD30[2];
extern u8 *D_0028DD38[2];
extern u8 *D_0028DD40[2];
extern u16 D_0028E300;
extern s8 D_0028EB1C;
extern s8 D_0028EB40;
extern s32 D_0028EBA8;
extern u8 D_00685010[];
extern s8 D_0068DC10[];
extern u8 *reg_a0;

void func_00220390(void) {
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 count;
    s32 index;
    s32 top;
    u8 *item;

    count = D_002714F3[0];
    switch (D_0028EB40) {
    case 0:
        break;
    case 1:
        D_0028EBA8 += 4;
        if (D_0028EBA8 >= 0x80) {
            D_0028EB40 = 0;
            D_0028EBA8 = 0x80;
        }
        break;
    case 2:
        D_0028EBA8 -= 4;
        if (D_0028EBA8 <= 0) {
            D_0028EBA8 = 0;
            D_0028EB40 = 0;
        }
        break;
    }
    func_00213060();
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0xAB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0xAAC) = D_0028EBA8;
        reg_a0 = D_00271580[i];
        x = *(s32 *)(item + 0xA80);
        alpha = *(s32 *)(item + 0xAAC);
        top = *(s32 *)(item + 0xA84);
        z = *(s32 *)(item + 0xAB0);
        if (alpha == 0) {
            continue;
        }
        if (i == 1 && !(D_0028E300 & 1)) {
            reg_a0 = D_00271598[0];
        }
        if (i == 2 && !(D_0028E300 & 2)) {
            reg_a0 = D_00271598[0];
        }
        if (i == 3 && !(D_0028E300 & 4)) {
            reg_a0 = D_00271598[0];
        }
        if (i == 4 && !(D_0028E300 & 8)) {
            reg_a0 = D_00271598[0];
        }
        func_0021C100(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0x30 + i];
        if (i == 1 && (D_0028E300 & 1)) {
            reg_a0 = D_0028DD28[index];
            func_0021C100(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB1C == 1) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 2 && (D_0028E300 & 2)) {
            reg_a0 = D_0028DD30[index];
            func_0021C100(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB1C == 2) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 3 && (D_0028E300 & 4)) {
            reg_a0 = D_0028DD38[index];
            func_0021C100(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB1C == 3) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 4 && (D_0028E300 & 8)) {
            reg_a0 = D_0028DD40[index];
            func_0021C100(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB1C == 4) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
    }
    func_00215350();
}
