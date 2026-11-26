#include "common.h"
#include "test_mode.h"

extern u8 test_memory_text_palette_ram[14];

void test_memory_print_labels(void);

extern s32 test_memory_text_title[];
extern s32 test_memory_text_main_ram[];
extern s32 test_memory_text_bg_ram[];
extern s32 test_memory_text_text_ram[];
extern s32 test_memory_text_line_offset_ram[];
extern u8 test_memory_ok[4];

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
    reg_a0 = (u8 *)test_memory_text_main_ram;
    reg_d0.h[0] = 0;
    test_print_lines();
    reg_a0 = (u8 *)test_memory_text_bg_ram;
    test_print_lines();
    reg_a0 = (u8 *)test_memory_text_text_ram;
    test_print_lines();
    reg_a0 = (u8 *)test_memory_text_line_offset_ram;
    test_print_lines();
    reg_a0 = (u8 *)((s32 *)test_memory_text_palette_ram);
    test_print_lines();
}

void test_memory_update(void) {
    test_memory_print_labels();
    if (g_test_cursor == 0) {
        reg_d0.w = 0x15;
        reg_d1.w = 0x26;
        reg_d2.h[0] = 2;
        reg_a0 = test_memory_ok;
        test_print_at();
        g_test_cursor = 1;
    }
    if (g_test_cursor == 1) {
        reg_d0.w = 0x15;
        reg_d1.w = 0x24;
        reg_d2.h[0] = 2;
        reg_a0 = test_memory_ok;
        test_print_at(g_test_cursor);
        g_test_cursor = 2;
    }
    if (g_test_cursor == 2) {
        reg_d2.h[0] = 2;
        reg_d0.w = 0x15;
        reg_d1.w = 0x22;
        reg_a0 = test_memory_ok;
        test_print_at(g_test_cursor);
        g_test_cursor = 3;
    }
    if (g_test_cursor == 3) {
        reg_d0.w = 0x15;
        reg_d1.w = 0x20;
        reg_d2.h[0] = 2;
        reg_a0 = test_memory_ok;
        test_print_at(g_test_cursor);
        g_test_cursor = 4;
    }
    if (g_test_cursor == 4) {
        reg_d0.w = 0x15;
        reg_d1.w = 0x1E;
        reg_d2.h[0] = 2;
        reg_a0 = test_memory_ok;
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

s32 test_memory_text_title[4] = {
    0x4D003209, 0x524F4D45, 0x48432059, 0xFF4B4345,
};

s32 test_memory_text_main_ram[4] = {
    0x57002603, 0x204B524F, 0xFF4D4152, 0x00000000,
};

s32 test_memory_text_bg_ram[4] = {
    0x42002403, 0x41522047, 0x0000FF4D, 0x00000000,
};

s32 test_memory_text_text_ram[4] = {
    0x54002203, 0x20545845, 0xFF4D4152, 0x00000000,
};

s32 test_memory_text_line_offset_ram[6] = {
    0x4C002003, 0x20454E49, 0x5346464F, 0x52205445, 0x00FF4D41, 0x00000000,
};

u8 test_memory_text_palette_ram[14] = {
    0x03, 0x1E, 0x00, 0x50, 0x41, 0x4C, 0x45, 0x54, 0x20, 0x52, 0x41, 0x4D, 0xFF, 0x00,
};

u8 test_memory_ok[4] = { 0x4F, 0x4B, 0xFF, 0x00 };
