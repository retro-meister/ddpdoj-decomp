#include "common.h"
#include "test_mode.h"

s32 sprite_palette_load();
s32 input_get_p1_held();
s32 sprite_draw();

extern s32 g_default_sprite_palette[];
extern s32 test_crosshatch_text_exit[];

void test_crosshatch_begin(void) {
    layers_clear_all();
    test_palettes_load();
    reg_d0.h[0] = 0;
    reg_a0 = (u8 *)g_default_sprite_palette;
    sprite_palette_load();
    g_test_cursor = 0;
    g_test_redraw = 1;
    reg_d0.h[0] = 0;
    reg_a0 = (u8 *)test_crosshatch_text_exit;
    test_print_lines();
    reg_d0.w = 0;
}

void test_crosshatch_update(void) {
    u32 held;

    reg_d2.w = 0xC2F;
    reg_d1.w = 0;
    reg_d3.h[0] = 0x38E0;
    reg_d4.h[0] = 0;
    sprite_draw();
    input_get_p1_held();
    held = reg_d0.w;
    if ((held & 0x8000) && (held & 0x10)) {
        reg_d0.w = 0;
        test_screen_request(held);
    }
    reg_d0.w = 0;
}

s32 test_crosshatch_text_exit[8] = {
    1157627907, 542394712, 1345396797, 1096045344, 639652946, 1330139936, -14667436, 0,
};
