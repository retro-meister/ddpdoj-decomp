#include "common.h"
#include "test_mode.h"

extern u8 test_default_text_wait[];
extern u8 test_default_text_blank[];

void test_default_begin(void) {
    layers_clear_all();
    test_palettes_load();
    g_test_cursor = 0;
    g_test_redraw = 0;
    reg_d0.w = 0;
}

void test_default_update(void) {
    g_test_redraw += 1;
    if (g_test_redraw >= 7) {
        g_test_redraw = 0;
        g_test_cursor += 1;
    }
    reg_d0.b[0] = (u8) g_test_cursor;
    reg_d0.b[0] &= 1;
    if (reg_d0.b[0] == 0) {
        reg_d0.h[0] = 8;
        reg_d1.h[0] = 0x1E;
        reg_d2.h[0] = 2;
        reg_a0 = (u8 *)test_default_text_wait;
        test_print_at();
    } else {
        reg_d0.h[0] = 8;
        reg_d1.h[0] = 0x1E;
        reg_d2.h[0] = 2;
        reg_a0 = (u8 *)test_default_text_blank;
        test_print_at();
    }
    if (g_test_cursor == 8) {
        settings_reset();
        reg_d0.w = 0;
        test_screen_request();
        reg_d0.w = 0;
    } else {
        reg_d0.w = 0;
    }
}

u8 test_default_text_wait[32] = {
    0x50, 0x4C, 0x45, 0x41, 0x53, 0x45, 0x20, 0x57, 0x41, 0x49, 0x54, 0x21, 0x21, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xFF,
};

u8 test_default_text_blank[32] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xFF,
};
