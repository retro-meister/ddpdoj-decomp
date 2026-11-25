#include "common.h"
#include "test_mode.h"

void test_sound_print_labels(void);
s32 input_get_p1_held();
s32 input_get_p1_pressed();
s32 text_layer_put();
s32 sound_stop_effects();
s32 sound_stop_loops();
s32 music_stop();

extern s32 test_sound_text_title[];
extern s32 test_sound_text_exit[];
extern s32 test_sound_text_code[];
extern s32 test_sound_text_help_up[];
extern s32 test_sound_text_help_down[];
extern s32 test_sound_text_help_right[];
extern s32 test_sound_text_help_left[];
extern s32 test_sound_text_help_request[];
extern s32 test_sound_text_help_stop[];
extern u8 test_sound_requests[];

void test_sound_begin(void) {
    layers_clear_all();
    test_palettes_load();
    g_test_cursor = 0;
    g_test_redraw = 1;
    test_sound_print_labels();
    reg_d0.h[0] = 0;
    reg_a0 = (u8 *)test_sound_text_title;
    test_print_lines();
    reg_a0 = (u8 *)test_sound_text_exit;
    test_print_lines();
    reg_d0.w = 0;
}

void test_sound_print_labels(void) {
    reg_a0 = (u8 *)test_sound_text_code;
    reg_d0.h[0] = 0;
    test_print_lines();
    reg_a0 = (u8 *)test_sound_text_help_up;
    test_print_lines();
    reg_a0 = (u8 *)test_sound_text_help_down;
    test_print_lines();
    reg_a0 = (u8 *)test_sound_text_help_right;
    test_print_lines();
    reg_a0 = (u8 *)test_sound_text_help_left;
    test_print_lines();
    reg_a0 = (u8 *)test_sound_text_help_request;
    test_print_lines();
    reg_a0 = (u8 *)test_sound_text_help_stop;
    test_print_lines();
}

void test_print_hex4(void) {
    s32 s_d0;
    s32 s_d1;
    s32 s_d2;
    s32 s_d3;
    s32 s_d4;
    s32 s_d5;
    s32 s_d6;
    s32 s_d7;
    s32 i;

    s_d0 = reg_d0.w;
    s_d1 = reg_d1.w;
    s_d2 = reg_d2.w;
    s_d3 = reg_d3.w;
    s_d4 = reg_d4.w;
    s_d5 = reg_d5.w;
    s_d6 = reg_d6.w;
    s_d7 = reg_d7.w;
    reg_d3.w &= 0xFFFF;
    reg_d5.w = reg_d3.w;
    reg_tmp5.h[0] = reg_d5.h[0];
    reg_d5.h[0] = reg_d5.h[1];
    reg_d5.h[1] = reg_tmp5.h[0];
    reg_d6.h[0] = reg_d2.h[0];
    reg_d2.w = 0;
    reg_d3.w = 0;
    reg_d7.w = 3;
next_digit:
    i = 0;
rotate_bit:
    if (reg_d5.w & 0x80000000) {
        reg_d5.w = reg_d5.w * 2;
        reg_d5.w = reg_d5.w | 1;
    } else {
        reg_d5.w = reg_d5.w * 2;
    }
    i += 1;
    if (i < 4) {
        goto rotate_bit;
    }
    reg_d4.w = reg_d5.w;
    reg_d4.w &= 0xF;
    if (reg_d4.b[0] < 0xA) goto digit_ready;
    reg_d4.h[0] += 7;
digit_ready:
    reg_d4.h[0] += 0x30;
    reg_tmp4.h[0] = reg_d4.h[0];
    reg_d4.h[0] = reg_d4.h[1];
    reg_d4.h[1] = reg_tmp4.h[0];
    reg_d4.h[0] = reg_d6.h[0];
    text_layer_put();
    reg_d0.h[0] += 1;
    if ((s16)(--reg_d7.h[0]) >= 0) goto next_digit;
    reg_d0.w = s_d0;
    reg_d1.w = s_d1;
    reg_d2.w = s_d2;
    reg_d3.w = s_d3;
    reg_d4.w = s_d4;
    reg_d5.w = s_d5;
    reg_d6.w = s_d6;
    reg_d7.w = s_d7;
}

typedef void (*Fn)();


void test_sound_update(void) {
    u32 held;

    test_sound_print_labels();
    input_get_p1_pressed();
    if (!(reg_d0.w & 1)) goto check_down;
    g_test_cursor += 1;
    if (g_test_cursor < 0x2F) goto check_down;
    g_test_cursor = 0x2E;
check_down:
    if (!(reg_d0.w & 2)) goto check_right;
    g_test_cursor -= 1;
    if (0 <= g_test_cursor) goto check_right;
    g_test_cursor = 0;
check_right:
    if (!(reg_d0.w & 8)) goto check_left;
    g_test_cursor += 0x10;
    if (g_test_cursor < 0x2F) goto check_left;
    g_test_cursor = 0x2E;
check_left:
    if (!(reg_d0.w & 4)) goto check_request;
    g_test_cursor -= 0x10;
    if (0 <= g_test_cursor) goto check_request;
    g_test_cursor = 0;
check_request:
    if (!(reg_d0.w & 0x10)) goto check_stop;
    reg_d1.w = 0;
    reg_d1.b[0] = (u8) g_test_cursor;
    reg_a0 = *(u8 **)((u8 *)test_sound_requests + (reg_d1.h[0] * 4));
    reg_call_target = (Fn)(reg_a0);
    reg_call_target();
check_stop:
    if (!(reg_d0.w & 0x20)) goto print_code;
    music_stop();
    sound_stop_effects();
    sound_stop_loops();
print_code:
    reg_d3.w = 0;
    reg_d0.h[0] = 0x13;
    reg_d2.h[0] = 0;
    reg_d1.h[0] = 0x2A;
    reg_d3.b[0] = (u8) g_test_cursor;
    test_print_hex4();
    input_get_p1_held();
    held = reg_d0.w;
    if ((held & 0x8000) && (held & 0x10)) {
        reg_d0.w = 0;
        test_screen_request();
        music_stop();
        sound_stop_effects();
        sound_stop_loops();
    }
    reg_d0.w = 0;
}
