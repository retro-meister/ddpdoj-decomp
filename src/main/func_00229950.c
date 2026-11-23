#include "common.h"

extern void func_00215DB0(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
extern void func_0021C100(s32 x, s32 y, s32 z, s32 page, s32 alpha, s32 attr, s32 wide);
extern u8 *D_00270AB0[];
extern u8 *D_0028DCE0;
extern s16 D_0068DEF0[];
extern u8 *reg_a0;

void func_00229950(s32 x, s32 y, s32 alpha, s32 mode, s32 kind) {
    u8 *saved;
    s32 c;
    s32 level;
    s32 h;

    saved = reg_a0;
    level = D_0068DEF0[kind];
    if (kind == 2) {
        h = level * 60000 / 255000;
    } else if (kind == 8) {
        h = level * 60000 / 500000;
    } else if (kind == 6) {
        h = level * 60000 / 100000;
    }
    c = 0xC8;
    if (mode != 0x80) {
        c = 0x40;
    }
    func_00215DB0(x - 8, y, 0x10, 0x40, 0xC8, alpha, 0x14, 0x14, 0x14);
    if (h != 0) {
        if (h == 0x3C) {
            func_00215DB0(x - 6, y + 2, 0xE, h + 1, 0xC8, alpha, c, 0, 0);
        } else {
            func_00215DB0(x - 6, y + 2, 0xE, h + 1, 0xC8, alpha, 0, 0, c);
        }
        if (kind == 8 && level >= 100) {
            if (level >= 100 && level < 200) {
                h = 12;
            }
            if (level >= 200 && level < 300) {
                h = 24;
            }
            if (level >= 300 && level < 400) {
                h = 36;
            }
            if (level >= 400 && level < 500) {
                h = 48;
            }
            func_00215DB0(x - 6, y + 2, 0xE, h + 1, 0xC8, alpha, c, 0, 0);
        }
    }
    func_00215DB0(x - 7, y, 0xE, 1, 0xC8, alpha, c, c, c);
    func_00215DB0(x - 8, y + 1, 0x10, 1, 0xC8, alpha, c, c, c);
    func_00215DB0(x - 8, y + 0x3E, 0x10, 1, 0xC8, alpha, c, c, c);
    func_00215DB0(x - 7, y + 0x3F, 0xE, 1, 0xC8, alpha, c, c, c);
    if (kind == 8) {
        func_00215DB0(x - 8, y + 0xE, 0x10, 1, 0xC8, alpha, c, c, c);
        func_00215DB0(x - 8, y + 0x1A, 0x10, 1, 0xC8, alpha, c, c, c);
        func_00215DB0(x - 8, y + 0x26, 0x10, 1, 0xC8, alpha, c, c, c);
        func_00215DB0(x - 8, y + 0x32, 0x10, 1, 0xC8, alpha, c, c, c);
    }
    func_00215DB0(x - 8, y + 1, 2, 0x3E, 0xC8, alpha, c, c, c);
    func_00215DB0(x + 6, y + 1, 2, 0x3E, 0xC8, alpha, c, c, c);
    if (kind != 2) {
        reg_a0 = D_00270AB0[level];
        func_0021C100(x - 4, y + 0x42, 0xC8, 0, c, alpha, 0);
        reg_a0 = (u8 *)D_0028DCE0;
        func_0021C100(x - 4, y + 0x5A, 0xC8, 0, c, alpha, 0);
    }
    reg_a0 = saved;
}
