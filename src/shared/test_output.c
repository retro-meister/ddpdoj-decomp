#include "common.h"
#include "test_mode.h"

void test_output_print_labels(void);
s32 coin_counters_pulse();
s32 input_get_p1_held();
s32 input_get_p1_pressed();

extern s32 test_output_text_title[];
extern s32 test_output_text_exit[];
extern s32 test_output_text_coin_counter[];

void test_output_begin(void) {
    layers_clear_all();
    test_palettes_load();
    g_test_cursor = 0;
    g_test_redraw = 1;
    test_output_print_labels();
    reg_d0.h[0] = 0;
    reg_a0 = (u8 *)test_output_text_title;
    test_print_lines();
    reg_a0 = (u8 *)test_output_text_exit;
    test_print_lines();
    reg_d0.w = 0;
}

void test_output_print_labels(void) {
    reg_d0.h[0] = 0;
    reg_a0 = (u8 *)test_output_text_coin_counter;
    test_print_lines();
}

void test_output_update(void) {
    u32 held;

    test_output_print_labels();
    input_get_p1_pressed();
    if (reg_d0.w & 0x20) {
        coin_counters_pulse();
    }
    input_get_p1_held();
    held = reg_d0.w;
    if ((held & 0x8000) && (held & 0x10)) {
        reg_d0.w = 0;
        test_screen_request(held);
    }
    reg_d0.w = 0;
}
