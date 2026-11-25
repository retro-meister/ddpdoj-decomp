#include "common.h"
#include "test_mode.h"

void test_input_print_labels(void);
s32 input_get_p1_held();
s32 input_get_p2_held();

extern s32 test_input_text_title[];
extern s32 test_input_text_exit[];
extern s32 test_input_text_service[];
extern s32 test_input_text_test[];
extern s32 test_input_text_players[];
extern s32 test_input_text_coin[];
extern s32 test_input_text_start[];
extern s32 test_input_text_lever_top[];
extern s32 test_input_text_lever_middle[];
extern s32 test_input_text_lever_bottom[];
extern s32 test_input_text_shot[];
extern u8 test_input_lever_marks[];
extern u8 test_input_mark_service;
extern u8 test_input_mark_test;
extern u8 test_input_mark_coin1;
extern u8 test_input_mark_coin2;
extern u8 test_input_mark_start1;
extern u8 test_input_mark_start2;
extern u8 test_input_mark;
extern u8 g_arcade_coin_port;

void test_input_begin(void) {
    layers_clear_all();
    test_palettes_load();
    g_test_cursor = 0;
    g_test_redraw = 1;
    test_input_print_labels();
    reg_d0.h[0] = 0;
    reg_a0 = (u8 *)test_input_text_title;
    test_print_lines();
    reg_a0 = (u8 *)test_input_text_exit;
    test_print_lines();
    reg_d0.w = 0;
}

void test_input_print_labels(void) {
    reg_a0 = (u8 *)test_input_text_service;
    reg_d0.h[0] = 0;
    test_print_lines();
    reg_a0 = (u8 *)test_input_text_test;
    test_print_lines();
    reg_a0 = (u8 *)test_input_text_players;
    test_print_lines();
    reg_a0 = (u8 *)test_input_text_coin;
    test_print_lines();
    reg_a0 = (u8 *)test_input_text_start;
    test_print_lines();
    reg_a0 = (u8 *)test_input_text_lever_top;
    test_print_lines();
    reg_a0 = (u8 *)test_input_text_lever_middle;
    test_print_lines();
    reg_a0 = (u8 *)test_input_text_lever_bottom;
    test_print_lines();
    reg_a0 = (u8 *)test_input_text_shot;
    test_print_lines();
}

void test_input_update(void) {
    u8 *mark_p1;
    u8 *mark_p2;
    u32 held;
    u8 column_p1;
    u8 column_p2;

    test_input_print_labels();
    reg_a0 = &g_arcade_coin_port;
    reg_d0.h[0] = *(u16 *)reg_a0;
    if (!(reg_d0.w & 0x20)) {
        reg_d0.h[0] = 2;
        reg_a0 = &test_input_mark_service;
        test_print_lines();
    }
    reg_a0 = &g_arcade_coin_port;
    reg_d0.h[0] = *(u16 *)reg_a0;
    if (!(reg_d0.w & 0x10)) {
        reg_d0.h[0] = 2;
        reg_a0 = &test_input_mark_test;
        test_print_lines();
    }
    reg_a0 = &g_arcade_coin_port;
    reg_d0.h[0] = *(u16 *)reg_a0;
    if (!(reg_d0.w & 1)) {
        reg_d0.h[0] = 2;
        reg_a0 = &test_input_mark_coin1;
        test_print_lines();
    }
    reg_a0 = &g_arcade_coin_port;
    reg_d0.h[0] = *(u16 *)reg_a0;
    if (!(reg_d0.w & 2)) {
        reg_d0.h[0] = 2;
        reg_a0 = &test_input_mark_coin2;
        test_print_lines();
    }
    input_get_p1_held();
    if (reg_d0.w & 0x8000) {
        reg_d0.h[0] = 2;
        reg_a0 = &test_input_mark_start1;
        test_print_lines();
    }
    input_get_p2_held();
    if (reg_d0.w & 0x8000) {
        reg_d0.h[0] = 2;
        reg_a0 = &test_input_mark_start2;
        test_print_lines();
    }
    input_get_p1_held();
    reg_d0.h[0] &= 0xF;
    if (reg_d0.b[0] != 0) {
        reg_d1.w = 0;
        reg_a0 = (u8 *)test_input_lever_marks;
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        reg_d0.w = 0;
        mark_p1 = (u8 *)(reg_a0);
        reg_d0.b[0] = (*(u8 *)((u8 *)(mark_p1) + (1)));
        reg_d0.b[0] += 0xD;
        column_p1 = (*(u8 *)((u8 *)(mark_p1) + (0)));
        reg_d2.h[0] = 2;
        reg_d1.b[0] = column_p1;
        reg_a0 = &test_input_mark;
        reg_d1.b[0] += 0x1E;
        test_print_at();
    }
    input_get_p2_held();
    reg_d0.h[0] &= 0xF;
    if (reg_d0.b[0] != 0) {
        reg_d1.w = 0;
        reg_a0 = (u8 *)test_input_lever_marks;
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        reg_d0.w = 0;
        mark_p2 = (u8 *)(reg_a0);
        reg_d0.b[0] = (*(u8 *)((u8 *)(mark_p2) + (1)));
        reg_d0.b[0] += 0x15;
        column_p2 = (*(u8 *)((u8 *)(mark_p2) + (0)));
        reg_d1.b[0] = column_p2;
        reg_d2.h[0] = 2;
        reg_a0 = &test_input_mark;
        reg_d1.b[0] += 0x1E;
        test_print_at();
    }
    input_get_p1_held();
    reg_d0.h[0] &= 0x70;
    reg_d0.h[0] >>= 4;
    if (reg_d0.b[0] != 0) {
        reg_d7.b[0] = reg_d0.b[0];
        reg_d2.h[0] = 2;
        reg_a0 = &test_input_mark;
        reg_d0.w = 0xD;
        reg_d1.w = 0x18;
        if (reg_d7.w & 1) {
            test_print_at();
        }
        reg_d0.h[0] += 1;
        if (reg_d7.w & 2) {
            test_print_at();
        }
        reg_d0.h[0] += 1;
        if (reg_d7.w & 4) {
            test_print_at();
        }
    }
    input_get_p2_held();
    reg_d0.h[0] &= 0x70;
    reg_d0.h[0] >>= 4;
    if (reg_d0.b[0] != 0) {
        reg_d7.b[0] = reg_d0.b[0];
        reg_d2.h[0] = 2;
        reg_a0 = &test_input_mark;
        reg_d0.w = 0x15;
        reg_d1.w = 0x18;
        if (reg_d7.w & 1) {
            test_print_at();
        }
        reg_d0.h[0] += 1;
        if (reg_d7.w & 2) {
            test_print_at();
        }
        reg_d0.h[0] += 1;
        if (reg_d7.w & 4) {
            test_print_at();
        }
    }
    input_get_p1_held();
    held = reg_d0.w;
    if ((held & 0x8000) && (held & 0x10)) {
        reg_d0.w = 0;
        test_screen_request();
    }
    reg_d0.w = 0;
}
