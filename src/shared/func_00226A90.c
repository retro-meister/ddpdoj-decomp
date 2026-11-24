#include "common.h"

typedef struct {
    u16 status;
    u16 f02;
    u16 f04;
    u16 f06;
    u16 f08;
    u16 f0A;
    u16 f0C;
    u16 f0E;
    u8 pad10[0x28];
    u8 f38;
    u8 f39;
    u8 f3A;
    u8 f3B;
} SaveInfo;

extern s32 sprintf(char *buf, const char *format, ...);
extern char *strcpy(char *dst, const char *src);
extern void text_queue_clear(void);
extern void frame_draw_column(s32 x, s32 y, s32 alpha);
extern void text_flush(void);
extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
extern void glyph_queue_clear(void);
extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 alpha, s32 attr, s32 wide);
extern void glyph_queue_flush(void);
extern char *D_00271D00[];
extern char *D_00271D10[];
extern char *D_0028DDB0[2];
extern s32 D_00289D70[];
extern char D_00289DD8[];
extern char D_00289DE0[];
extern char D_00289DE8[];
extern char D_00289DF8[];
extern char D_00289E08[];
extern char D_00289E18[];
extern char D_00289E20[];
extern char D_00289E28[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00226A90(s32 slot, s32 x, s32 y, s32 alpha, s32 selected, SaveInfo *info) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    char buf[16];
    u32 save_d6;
    u32 save_d7;
    s32 a;
    s32 b;
    s32 fade;

    if (alpha == 0) {
        return;
    }
    save_d0 = reg_d0.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    text_queue_clear();
    frame_draw_column(x, y, alpha);
    if (selected != 0) {
        gfx_draw_color_box(x + 8, y + 8, 0x1A, 0xD0, 0x12C, alpha, 0xFF, 1, 1);
    } else {
        fade = alpha >= 0x40 ? 0x40 : alpha;
        gfx_draw_color_box(x + 8, y + 8, 0x1A, 0xD0, 0x12C, fade, 1, 1, 0x40);
    }
    text_flush();
    glyph_queue_clear();
    reg_a0 = (u8 *)buf;
    a = info->f04;
    if (a != 0xFF) {
        b = info->f02;
    } else {
        b = info->f06;
        a = info->f08;
    }
    sprintf(buf, D_00289DD8, slot + 1);
    glyph_queue_add(x + D_00289D70[0], y + D_00289D70[1], 0x12C, 0, 0x80, alpha, 1);
    switch (info->status) {
    case 0:
        strcpy(buf, D_00289DE0);
        glyph_queue_add(x + D_00289D70[0], y + D_00289D70[1] + 0x60, 0x12C, 0, 0x80, alpha, 1);
        break;
    case 2:
        strcpy(buf, D_00289DE8);
        glyph_queue_add(x + D_00289D70[0], y + D_00289D70[1] + 0x60, 0x12C, 0, 0x80, alpha, 1);
        break;
    case 3:
        strcpy(buf, D_00289DF8);
        glyph_queue_add(x + D_00289D70[0], y + D_00289D70[1] + 0x60, 0x12C, 0, 0x80, alpha, 1);
        break;
    default:
        sprintf(buf, D_00289E08, info->f0C + 1, info->f0E + 1);
        glyph_queue_add(x + D_00289D70[2], y + D_00289D70[3], 0x12C, 0, 0x80, alpha, 0);
        sprintf(buf, D_00289E18, D_00271D10[info->f0A]);
        glyph_queue_add(x + D_00289D70[4], y + D_00289D70[5], 0x12C, 0, 0x80, alpha, 0);
        sprintf(buf, D_00289E18, D_0028DDB0[b / 2]);
        glyph_queue_add(x + D_00289D70[6], y + D_00289D70[7], 0x12C, 0, 0x80, alpha, 0);
        sprintf(buf, D_00289E18, D_00271D00[a / 2]);
        glyph_queue_add(x + D_00289D70[8], y + D_00289D70[9], 0x12C, 0, 0x80, alpha, 0);
        sprintf(buf, D_00289E20, info->f38, info->f39);
        glyph_queue_add(x + D_00289D70[10], y + D_00289D70[11], 0x12C, 0, 0x80, alpha, 0);
        sprintf(buf, D_00289E28, info->f3A, info->f3B);
        glyph_queue_add(x + D_00289D70[12], y + D_00289D70[13], 0x12C, 0, 0x80, alpha, 0);
        break;
    }
    glyph_queue_flush();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}
