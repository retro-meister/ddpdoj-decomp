#include "common.h"

extern void text_queue_clear(void);
extern void frame_draw_right_panel(s32 level);
extern void text_flush(void);
extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
extern s32 glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 alpha, s32 attr, s32 wide);
extern void func_00222C30(s32 x, s32 y, s32 alpha);
extern char *D_0028DD90;
extern s32 D_0028EAEC;
extern s32 D_0028EAF0;
extern s8 D_0028EB58;
extern char D_002BB060_as_char_a[];
extern char D_002BB100_as_char_a[];
extern char *reg_a0_as_char_p;

void func_00221E20(void) {
    char buf[2];
    s32 alpha;
    s32 i;
    char *p;
    s32 y;

    switch (D_0028EAF0) {
    case 0:
    case 3:
        break;
    case 1:
        D_0028EAEC += 4;
        if (D_0028EAEC >= 0x80) {
            D_0028EAEC = 0x80;
            D_0028EAF0 = 3;
        }
        break;
    case 2:
        D_0028EAEC -= 4;
        if (D_0028EAEC <= 0) {
            D_0028EAEC = 0;
            D_0028EAF0 = 0;
        }
        break;
    }
    if (D_0028EAEC != 0) {
        text_queue_clear();
        alpha = D_0028EAEC;
        if (D_0028EAEC >= 0x60) {
            alpha = 0x60;
        }
        if (alpha != 0) {
            frame_draw_right_panel(D_0028EAEC);
            gfx_draw_color_box(0xEC, 8, 0x40, 0xD0, 0x12C, alpha, 1, 1, 0x40);
        }
        reg_a0_as_char_p = (char *)D_0028DD90;
        func_00222C30(0x116, 8, D_0028EAEC);
        buf[1] = 0;
        i = 0;
        y = 0;
        p = MAIN_OR_DEATH_LABEL(D_002BB100_as_char_a, D_002BB060_as_char_a) + D_0028EB58 * 0x1E;
        do {
            reg_a0_as_char_p = buf;
            *reg_a0_as_char_p = *p++;
            glyph_queue_add(0x106, y + 0xE + (i / 5) * 5, 0x136, 0, 0x80, D_0028EAEC, 1);
            i++;
            y += 9;
        } while (i < 0x14);
    }
    text_flush();
}
