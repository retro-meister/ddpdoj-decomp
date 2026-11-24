#include "common.h"

extern void func_00215C20(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha);
extern void func_0021BD80(void *buffer, s32 x, s32 y, s32 w, s32 h);
extern void func_0021C0F0(void);
extern void func_0021C100(s32 x, s32 y, s32 z, s32 page, s32 alpha, s32 attr, s32 wide);
extern void func_0021C2F0(void);
extern s32 strlen(u8 *s);
extern s32 D_0028DC98;
extern u8 D_0028E36C;
extern s32 D_0028EA48;
extern s32 D_0028EA4C;
extern s32 D_0028EA50;
extern u8 D_00558780[];
extern u8 *reg_a0;

void func_0021BEA0(s32 *rect, s32 x, s32 y, u8 *text) {
    u8 *saved;
    s32 bright;

    if (text == 0) {
        D_0028EA4C = 0;
        D_0028EA48 = 0;
        return;
    }
    saved = reg_a0;
    bright = 0x80;
    if (text != 0) {
        func_00215C20(x, y - 16, 17, (strlen(text) + 2) * 8, 100, D_0028EA48);
    } else {
        func_00215C20(x, y - 16, 17, 64, 100, D_0028EA48);
    }
    if (D_0028EA48 < 0x60) {
        D_0028EA48++;
        return;
    }
    if (D_0028DC98 < 2) {
        func_0021BD80(D_00558780, D_0028EA50 + 2 + x, 1, 16, 223);
    } else {
        func_0021BD80(D_00558780, x + 1, 0, 16, rect[2]);
    }
    func_0021C0F0();
    reg_a0 = text;
    if (D_0028E36C == 0) {
        D_0028EA4C++;
    }
    switch (D_0028EA4C >> 6) {
    case 4:
        D_0028EA4C = 0;
    case 0:
    case 1:
        x += ((D_0028EA4C >> 1) & 0x1F) - 15;
        break;
    case 2:
        bright = (D_0028EA4C << 1) & 0x7F;
        break;
    case 3:
        bright = (0x7F - (D_0028EA4C << 1)) & 0x7F;
        break;
    }
    if (text != 0) {
        func_0021C100(x + 8, y, 100, 0, 0x80, bright, 1);
    }
    func_0021C2F0();
    if (D_0028DC98 < 2) {
        func_0021BD80(D_00558780, D_0028EA50 + 1, 1, 447, 223);
    } else {
        func_0021BD80(D_00558780, 0, 0, rect[1], rect[2]);
    }
    reg_a0 = saved;
}
