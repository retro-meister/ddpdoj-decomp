#include "common.h"

extern void func_00213060(void);
extern void func_00215350(void);
extern void func_0021C100(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
extern void func_002228D0(s32 x, s32 y);
extern void func_00224BA0(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag, s32 kind);
extern void func_00227440(u8 *state);
extern void func_0022AD20(s32 page, s32 sel);
extern u8 *D_002714B0[];
extern s8 D_002714FD[];
extern u8 *D_002716E0[];
extern u8 *D_0028DD98;
extern s32 D_0028EB90;
extern u8 D_0028EBD8;
extern s8 D_0028EBDA;
extern s16 D_0028EBDC;
extern u8 D_00684CA0[];
extern u8 D_00685010[];
extern s32 D_006880A0[];
extern s32 D_006880A4[];
extern u8 *reg_a0;

void func_0022A480(void) {
    s32 i;
    s32 x;
    s32 y;
    s32 z;
    s32 alpha;
    s32 count;
    u8 *item;

    func_00227440(&D_0028EBD8);
    if (D_0028EBDC == 0) {
        return;
    }
    count = D_002714FD[0];
    func_00213060();
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBDC;
        reg_a0 = D_002714B0[i];
        x = *(s32 *)(item + 0x2D80);
        alpha = *(s32 *)(item + 0x2DAC);
        y = *(s32 *)(item + 0x2D84);
        z = *(s32 *)(item + 0x2DB0);
        if (alpha == 0) {
            continue;
        }
        if (i == 1) {
            func_00224BA0(x, y, z, 0, 0x80, alpha, 1, 3);
        }
        func_0021C100(x, y, z, 0, 0x80, alpha, 1);
        if (i == 1) {
            reg_a0 = D_002716E0[D_0028EBDA];
            func_0021C100(x, y + 0x70, z, 0, 0x80, alpha, 1);
        }
    }
    func_0022AD20(D_0028EBDA, 0);
    for (i = 3; i < 8; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBDC;
        reg_a0 = (u8 *)D_00684CA0 + (i - 3) * 11;
        y = *(s32 *)(item + 0x2D84) + 16;
        x = *(s32 *)(item + 0x2D80);
        z = *(s32 *)(item + 0x2DB0);
        alpha = *(s32 *)(item + 0x2DAC);
        if (alpha != 0) {
            func_0021C100(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    func_0022AD20(D_0028EBDA, 1);
    for (i = 3; i < 8; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBDC;
        reg_a0 = (u8 *)D_00684CA0 + (i - 3) * 11;
        y = *(s32 *)(item + 0x2D84) + 0x80;
        x = *(s32 *)(item + 0x2D80);
        z = *(s32 *)(item + 0x2DB0);
        alpha = *(s32 *)(item + 0x2DAC);
        if (alpha != 0) {
            func_0021C100(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    func_0022AD20(D_0028EBDA, 2);
    for (i = 9; i < 14; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBDC;
        reg_a0 = (u8 *)D_00684CA0 + (i - 9) * 11;
        y = *(s32 *)(item + 0x2D84) + 16;
        x = *(s32 *)(item + 0x2D80);
        z = *(s32 *)(item + 0x2DB0);
        alpha = *(s32 *)(item + 0x2DAC);
        if (alpha != 0) {
            func_0021C100(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    func_0022AD20(D_0028EBDA, 3);
    for (i = 9; i < 14; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBDC;
        reg_a0 = (u8 *)D_00684CA0 + (i - 9) * 11;
        y = *(s32 *)(item + 0x2D84) + 0x80;
        x = *(s32 *)(item + 0x2D80);
        z = *(s32 *)(item + 0x2DB0);
        alpha = *(s32 *)(item + 0x2DAC);
        if (alpha != 0) {
            func_0021C100(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    D_0028EB90 = D_0028EBDC;
    reg_a0 = (u8 *)D_0028DD98;
    func_002228D0(D_006880A0[0] - 10, D_006880A4[0] + 0x58);
    func_00215350();
}
