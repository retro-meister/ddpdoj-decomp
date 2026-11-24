#include "common.h"

extern void func_0021C0F0(void);
extern void func_0021C2F0(void);
extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
extern void func_00227000(void);
extern void func_0022BA60(void);
extern s8 D_0028EB04;
extern s32 D_0028EB90;
extern s32 D_0028EC50;
extern u8 D_0028ED7C;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0022B870(void) {
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

    if (D_0028EC50 != 0) {
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
        func_0021C0F0();
        switch (D_0028EB04) {
        case 0:
            break;
        case 1:
            D_0028EB90 += 8;
            if (D_0028EB90 >= 0x80) {
                D_0028EB04 = 0;
                D_0028EB90 = 0x80;
            }
            break;
        case 2:
            D_0028EB90 -= 8;
            if (D_0028EB90 <= 0) {
                D_0028EB90 = 0;
                D_0028EB04 = 0;
            }
            break;
        }
        gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, D_0028EB90 / 2, 1, 1, 1);
        if (D_0028ED7C == 1) {
            func_0022BA60();
            func_00227000();
        }
        func_0021C2F0();
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
