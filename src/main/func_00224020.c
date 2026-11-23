#include "common.h"

extern s32 func_00117550(char *buf, const char *format, ...);
extern void func_002144D0(s16 x, s16 y, const char *text, u16 texturePage, u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth);
extern char D_00289C28[];
extern char D_00289C30[];
extern char D_00289C38[];
extern char *D_0028E9F8;
extern u8 *reg_a0;
extern u8 *D_00271BC8[];
extern u8 *D_00271BCC[];
extern u8 *D_00271BD0[];
extern u8 *D_00271BD4[];
extern s8 D_0028EBC4;
extern s8 D_0028EBD0;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;
extern void func_002228D0(s32 x, s32 y);
extern s8 D_0028EBC0;

void func_00224020(s32 x, s32 y) {
    s32 shrink;
    s32 w;
    s32 h;
    s32 px;
    s32 py;

    if (D_0028EBC0 < 4) {
        D_0028EBC0 += 2;
    }
    px = x + 40;
    py = y + 10;
    shrink = 0;
    if (D_0028EBC0 != 0) {
        shrink = (s32)(s8)D_0028EBC0 / 2;
    }
    w = (s32)(s8)D_0028EBC0 + 20;
    h = (s32)(s8)D_0028EBC0 + 16;
    if (D_0028EBD0 == 6) {
        reg_a0 = D_00271BD0[0];
    } else if (D_0028ED7C == 2) {
        reg_a0 = D_00271BCC[0];
    } else if (D_0028ED80 != 0) {
        reg_a0 = D_00271BD4[0];
    } else {
        reg_a0 = D_00271BC8[0];
    }
    func_002228D0(x + 42, y);
    if (D_0028EBC4 == 0) {
        func_00117550(D_0028E9F8, D_00289C28);
        func_002144D0(py - shrink, px - shrink, D_0028E9F8, 4, w, h, 128, 300);
        func_00117550(D_0028E9F8, D_00289C30);
        func_002144D0(py, px + 50, D_0028E9F8, 0, 20, 16, 128, 300);
        func_00117550(D_0028E9F8, D_00289C38);
        func_002144D0(py, px + 75, D_0028E9F8, 0, 20, 16, 128, 300);
    } else {
        func_00117550(D_0028E9F8, D_00289C28);
        func_002144D0(py, px, D_0028E9F8, 0, 20, 16, 128, 300);
        func_00117550(D_0028E9F8, D_00289C30);
        func_002144D0(py, px + 50, D_0028E9F8, 0, 20, 16, 128, 300);
        func_00117550(D_0028E9F8, D_00289C38);
        func_002144D0(py - shrink, px + 75 - shrink, D_0028E9F8, 4, w, h, 128, 300);
    }
}
