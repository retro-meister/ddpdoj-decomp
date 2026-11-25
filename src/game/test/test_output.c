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

s32 test_output_text_title[4] = {
    1325412873, 1431327829, 1163141204, 16733267,
};

s32 test_output_text_coin_counter[8] = {
    1124083203, 542001487, 1314213699, 542262612, 542126376, 1414482003, 16722226, 0,
};

s32 test_output_text_exit[8] = {
    1157629955, 542394712, 1345396797, 1096045344, 639652946, 1330139936, -14667436, 0,
};
