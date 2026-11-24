#include "common.h"

typedef struct {
    s16 x;
    s16 y;
} Point;

extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
extern void glyph_queue_clear(void);
extern void glyph_queue_add(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern void glyph_queue_flush(void);
extern void func_00225E20(void);
extern void func_002260F0(void);
extern void func_00227000(void);
extern void func_0022AA20(void);
extern u8 *D_00271CC0[];
extern Point D_00271CE0_as_Point_a[];
extern s32 D_0028EAC4;
extern s8 D_0028EACC;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00225EF0(void) {
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
    u32 save_d6;
    u32 save_d7;
    s32 alpha;
    s32 i;

    if (D_0028EACC != 0) {
        save_d0 = reg_d0.w;
        save_d1 = reg_d1.w;
        save_d2 = reg_d2.w;
        save_d3 = reg_d3.w;
        save_d4 = reg_d4.w;
        save_d5 = reg_d5.w;
        save_d6 = reg_d6.w;
        save_d7 = reg_d7.w;
        save_a0 = reg_a0;
        save_a1 = reg_a1;
        save_a2 = reg_a2;
        save_a3 = reg_a3;
        save_a4 = reg_a4;
        save_a5 = reg_a5;
        save_a6 = reg_a6;
        gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, 0x20, 1, 1, 1);
        if (D_0028EACC == 0x50 || D_0028EACC == 0x51) {
            func_0022AA20();
        } else {
            func_00225E20();
            func_002260F0();
            func_00227000();
            glyph_queue_clear();
            alpha = D_0028EAC4 * 2;
            for (i = 0; i < 3; i++) {
                reg_a0 = D_00271CC0[i];
                glyph_queue_add(D_00271CE0_as_Point_a[i].x, D_00271CE0_as_Point_a[i].y, 0x12C, 0, 0x80, alpha, 1);
            }
            glyph_queue_flush();
        }
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
}
