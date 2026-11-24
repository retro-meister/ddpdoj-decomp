#include "common.h"

extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
extern s16 D_00271760[];
extern s16 D_00271784[];
extern s8 D_0028EB50;
extern s8 D_0028EB54;
extern s8 D_0028EB58;

void func_0022B1D0(void) {
    s32 x;

    switch (D_0028EB54) {
    case 0:
        break;
    case 1:
        D_0028EB50 += 4;
        if (D_0028EB50 >= 0x40) {
            D_0028EB54 = 0;
            D_0028EB50 = 0x40;
        }
        break;
    case 2:
        D_0028EB50 -= 4;
        if (D_0028EB50 <= 0) {
            D_0028EB50 = 0;
            D_0028EB54 = 0;
        }
        break;
    }
    if (D_0028EB58 != -1) {
        x = D_00271760[D_0028EB58 * 2];
        if (D_0028EB50 != 0) {
            gfx_draw_color_box(x - 8, 0, 0x12, 0xE0, 0x5A, D_0028EB50, 0xB4, 1, 1);
        }
    }
    if (D_0028EB50 != 0) {
        gfx_draw_color_box(D_00271784[0] - 8, 0, 0x12, 0xE0, 0x5A, D_0028EB50, 0xB4, 1, 1);
    }
}
