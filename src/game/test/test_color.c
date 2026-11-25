#include "common.h"
#include "test_mode.h"

s32 sprite_palette_load();
s32 input_get_p1_held();
s32 sprite_draw_keep();

extern s32 test_color_text_title[];
extern s32 test_color_text_digits[];
extern s32 test_color_text_exit[];
extern s32 test_color_palette_blue[];
extern s32 test_color_palette_green[];
extern s32 test_color_palette_red[];
extern s32 test_color_palette_grey[];
extern u32 test_color_sprites[];

void test_color_begin(void) {
    layers_clear_all();
    test_palettes_load();
    g_test_cursor = 0;
    g_test_redraw = 1;
    reg_d0.h[0] = 0;
    reg_a0 = (u8 *)test_color_text_title;
    test_print_lines();
    reg_a0 = (u8 *)test_color_text_digits;
    test_print_lines();
    reg_a0 = (u8 *)test_color_text_exit;
    test_print_lines();
    reg_d0.h[0] = 0;
    reg_a0 = (u8 *)test_color_palette_blue;
    sprite_palette_load();
    reg_d0.h[0] = 1;
    reg_a0 = (u8 *)test_color_palette_green;
    sprite_palette_load();
    reg_d0.h[0] = 2;
    reg_a0 = (u8 *)test_color_palette_red;
    sprite_palette_load();
    reg_d0.h[0] = 3;
    reg_a0 = (u8 *)test_color_palette_grey;
    sprite_palette_load();
    reg_d0.w = 0;
}

void test_color_update(void) {
    u32 *sprite;
    u32 *sprite_2;
    u32 *sprite_3;
    u32 *sprite_4;
    u32 held;

    reg_d6.w = 0x50000E00;
    reg_d4.h[0] = 0;
    sprite = (u32 *)(test_color_sprites);
    reg_d3.h[0] = 0x208;
    reg_d7.w = 0xE;
    do {
        reg_d1.w = reg_d6.w;
        reg_d2.w = *sprite;
        sprite_draw_keep();
        reg_d1.w += 0xFE000000;
        sprite_draw_keep();
        reg_d1.w += 0xFE000000;
        sprite_draw_keep();
        sprite += 1;
        reg_d6.h[0] += 0x200;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    sprite_2 = (u32 *)(test_color_sprites);
    reg_d6.w = 0x48000E00;
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 1;
    reg_d7.w = 0xE;
    do {
        reg_d1.w = reg_d6.w;
        reg_d2.w = *sprite_2;
        sprite_draw_keep();
        reg_d1.w += 0xFE000000;
        sprite_draw_keep();
        reg_d1.w += 0xFE000000;
        sprite_draw_keep();
        sprite_2 += 1;
        reg_d6.h[0] += 0x200;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    sprite_3 = (u32 *)(test_color_sprites);
    reg_d6.w = 0x40000E00;
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 2;
    reg_d7.w = 0xE;
    do {
        reg_d1.w = reg_d6.w;
        reg_d2.w = *sprite_3;
        sprite_draw_keep();
        reg_d1.w += 0xFE000000;
        sprite_draw_keep();
        reg_d1.w += 0xFE000000;
        sprite_draw_keep();
        sprite_3 += 1;
        reg_d6.h[0] += 0x200;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    sprite_4 = (u32 *)(test_color_sprites);
    reg_d6.w = 0x38000E00;
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 3;
    reg_d7.w = 0xE;
    do {
        reg_d1.w = reg_d6.w;
        reg_d2.w = *sprite_4;
        sprite_draw_keep();
        reg_d1.w += 0xFE000000;
        sprite_draw_keep();
        reg_d1.w += 0xFE000000;
        sprite_draw_keep();
        sprite_4 += 1;
        reg_d6.h[0] += 0x200;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    input_get_p1_held();
    held = reg_d0.w;
    if ((held & 0x8000) && (held & 0x10)) {
        reg_d0.w = 0;
        test_screen_request();
    }
    reg_d0.w = 0;
}

s32 test_color_text_title[4] = {
    1124086281, 1380928591, 1397052448, 65364,
};

s32 test_color_text_digits[8] = {
    805317638, 875770417, 943142453, 1128415545, -12171964, 0, 0, 0,
};

s32 test_color_text_exit[8] = {
    1157629955, 542394712, 1345396797, 1096045344, 639652946, 1330139936, -14667436, 0,
};

s32 test_color_palette_blue[16] = {
    1900575, 1638427, 1376279, 1114131, 851983, 589835, 327687, 65539,
    1900575, 1638427, 1376279, 1114131, 851983, 589835, 327687, 65539,
};

s32 test_color_palette_green[16] = {
    60818400, 52429664, 44040928, 35652192, 27263456, 18874720, 10485984, 2097248,
    60818400, 52429664, 44040928, 35652192, 27263456, 18874720, 10485984, 2097248,
};

s32 test_color_palette_red[16] = {
    1946188800, 1677749248, 1409309696, 1140870144, 872430592, 603991040, 335551488, 67111936,
    1946188800, 1677749248, 1409309696, 1140870144, 872430592, 603991040, 335551488, 67111936,
};

s32 test_color_palette_grey[16] = {
    2008907775, 1731817339, 1454726903, 1177636467, 900546031, 623455595, 346365159, 69274723,
    2008907775, 1731817339, 1454726903, 1177636467, 900546031, 623455595, 346365159, 69274723,
};

u32 test_color_sprites[16] = {
    0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000005, 0x00000006, 0x00000007, 0x00000008,
    0x00000009, 0x0000000A, 0x0000000B, 0x0000000C, 0x0000000D, 0x0000000E, 0x0000000F, 0x00000000,
};
