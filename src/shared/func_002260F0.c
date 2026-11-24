#include "common.h"

extern void text_queue_clear(void);
extern void frame_draw_left_panel(s32 level);
extern void text_flush(void);
extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
extern void func_002228D0(s32 x, s32 y);
extern u8 *D_00271CD0[];
extern u8 *D_0028DDA8;
extern s8 D_0028EAC8;
extern s8 D_0028EACC;
extern s8 D_0028EB04;
extern s32 D_0028EB90;
extern u8 D_0028EC3C_as_u8;
extern u8 *reg_a0;

void func_002260F0(void) {
    s32 alpha;

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
        text_queue_clear();
        alpha = D_0028EB90;
        if (D_0028EB90 >= 0x40) {
            alpha = 0x40;
        }
        if (alpha != 0) {
            frame_draw_left_panel(D_0028EB90);
            gfx_draw_color_box(0xC, 8, 0x40, 0xD0, 0x12C, alpha, 1, 1, 0x40);
        }
        if (D_0028EACC >= 0x40) {
            if (D_0028EC3C_as_u8 != 0 && (u32)(D_0028EC3C_as_u8 - 1) > 1 && (u32)(D_0028EC3C_as_u8 - 5) > 1) {
                reg_a0 = (u8 *)D_0028DDA8;
                func_002228D0(0x36, 8);
            }
        } else {
            reg_a0 = D_00271CD0[D_0028EAC8];
            func_002228D0(0x36, 8);
        }
        text_flush();
    }
}
