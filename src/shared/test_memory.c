#include "common.h"
#include "test_mode.h"

void test_memory_print_labels(void);

extern s32 test_memory_text_title[];
extern s32 test_memory_text_work_ram[];
extern s32 test_memory_text_bg_ram[];
extern s32 test_memory_text_text_ram[];
extern s32 test_memory_text_line_offset_ram[];
extern s32 test_memory_text_palette_ram[];
extern u8 test_memory_ok;

void test_memory_begin(void) {
    layers_clear_all();
    test_palettes_load();
    g_test_cursor = 0;
    g_test_redraw = 0x50;
    test_memory_print_labels();
    reg_d0.h[0] = 0;
    reg_a0 = (u8 *)test_memory_text_title;
    test_print_lines();
    reg_d0.w = 0;
}

void test_memory_print_labels(void) {
    reg_a0 = (u8 *)test_memory_text_work_ram;
    reg_d0.h[0] = 0;
    test_print_lines();
    reg_a0 = (u8 *)test_memory_text_bg_ram;
    test_print_lines();
    reg_a0 = (u8 *)test_memory_text_text_ram;
    test_print_lines();
    reg_a0 = (u8 *)test_memory_text_line_offset_ram;
    test_print_lines();
    reg_a0 = (u8 *)test_memory_text_palette_ram;
    test_print_lines();
}

void test_memory_update(void) {
    test_memory_print_labels();
    if (g_test_cursor == 0) {
        reg_d0.w = 0x15;
        reg_d1.w = 0x26;
        reg_d2.h[0] = 2;
        reg_a0 = &test_memory_ok;
        test_print_at();
        g_test_cursor = 1;
    }
    if (g_test_cursor == 1) {
        reg_d0.w = 0x15;
        reg_d1.w = 0x24;
        reg_d2.h[0] = 2;
        reg_a0 = &test_memory_ok;
        test_print_at(g_test_cursor);
        g_test_cursor = 2;
    }
    if (g_test_cursor == 2) {
        reg_d2.h[0] = 2;
        reg_d0.w = 0x15;
        reg_d1.w = 0x22;
        reg_a0 = &test_memory_ok;
        test_print_at(g_test_cursor);
        g_test_cursor = 3;
    }
    if (g_test_cursor == 3) {
        reg_d0.w = 0x15;
        reg_d1.w = 0x20;
        reg_d2.h[0] = 2;
        reg_a0 = &test_memory_ok;
        test_print_at(g_test_cursor);
        g_test_cursor = 4;
    }
    if (g_test_cursor == 4) {
        reg_d0.w = 0x15;
        reg_d1.w = 0x1E;
        reg_d2.h[0] = 2;
        reg_a0 = &test_memory_ok;
        test_print_at(g_test_cursor);
        g_test_cursor = 5;
    }
    if (g_test_cursor == 5) {
        g_test_redraw -= 1;
        if (g_test_redraw == 0) {
            reg_d0.w = 0;
            test_screen_request(g_test_cursor);
        }
    }
    reg_d0.w = 0;
}
