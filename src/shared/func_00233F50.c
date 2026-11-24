#include "common.h"

extern s32 func_00117550(char *buf, const char *format, ...);
extern void func_00233F30(s16 x, s16 y, char *text, s32 mode, u16 w, u16 h, u16 color, s32 depth);
extern char D_0028BCA0[];
extern char D_0028BCA8[];
extern char D_0028BCB0[];
extern char *D_0028E9F8;
extern u8 D_0028ECDC;
extern u8 D_0028ECEC;
extern s32 D_0028ED10;

void func_00233F50(void) {
    s32 shrink;
    s32 color;
    s32 w;
    s32 h;

    if (D_0028ECDC < 4) {
        D_0028ECDC += 2;
    }
    color = D_0028ED10;
    shrink = 0;
    if (D_0028ECDC != 0) {
        shrink = (s32)(D_0028ECDC & 0xFF) / 2;
    }
    w = (D_0028ECDC & 0xFF) + 20;
    h = (D_0028ECDC & 0xFF) + 14;
    if (D_0028ECEC == 0) {
        func_00117550(D_0028E9F8, D_0028BCA0);
        func_00233F30(48 - shrink, 364 - shrink, D_0028E9F8, 4, w, h, color, 100);
        func_00117550(D_0028E9F8, D_0028BCA8);
        func_00233F30(104, 364, D_0028E9F8, 0, 20, 14, color, 100);
        func_00117550(D_0028E9F8, D_0028BCB0);
        func_00233F30(136, 364, D_0028E9F8, 0, 20, 14, color, 100);
    } else {
        func_00117550(D_0028E9F8, D_0028BCA0);
        func_00233F30(48, 364, D_0028E9F8, 0, 20, 14, color, 100);
        func_00117550(D_0028E9F8, D_0028BCA8);
        func_00233F30(104, 364, D_0028E9F8, 0, 20, 14, color, 100);
        func_00117550(D_0028E9F8, D_0028BCB0);
        func_00233F30(136 - shrink, 364 - shrink, D_0028E9F8, 4, w, h, color, 100);
    }
}
