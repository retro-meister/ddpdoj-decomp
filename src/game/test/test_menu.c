#include "common.h"
#include "test_mode.h"

void test_menu_print_items(void);
s32 input_get_p1_pressed();
s32 sfx_confirm();
s32 sfx_cursor_move();

extern s32 test_menu_text_title[];
extern s32 test_menu_text_help_select[];
extern u8 test_menu_text_input[];
extern u8 test_menu_text_output[];
extern u8 test_menu_text_sound[];
extern u8 test_menu_text_color[];
extern u8 test_menu_text_crosshatch[];
extern u8 test_menu_text_system[];
extern u8 test_menu_text_game[];
extern u8 test_menu_text_memory[];
extern u8 test_menu_text_default[];
extern u8 test_menu_text_exit[];
extern u8 *test_menu_item_texts[];
extern u8 test_menu_text_help_start[];
extern u8 test_menu_text_help_reset[];

void test_menu_cursor_erase(void) {
    reg_d0.w = 5;
    reg_d1.w = 9;
    reg_d2.w = -1U;
    reg_d1.b[0] -= *(u8 *)&g_test_cursor;
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] += 0x18;
    test_cursor_put();
}

void test_menu_cursor_draw(void)
{
    reg_d0.w = 5;
    reg_d1.w = 9;
    reg_d2.w = 0;
    reg_d1.b[0] -= *(u8 *)&g_test_cursor;
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] += 0x18;
    test_cursor_put();
}

void test_menu_begin(void) {
    layers_clear_all();
    test_palettes_load();
    g_test_cursor = 0;
    g_test_redraw = 0;
    test_menu_print_items();
    reg_d0.h[0] = 0;
    reg_a0 = (u8 *)test_menu_text_title;
    test_print_lines();
    reg_a0 = (u8 *)test_menu_text_help_select;
    test_print_lines();
    reg_a0 = (u8 *)test_menu_text_help_start;
    test_print_lines();
    test_menu_cursor_draw();
    reg_d0.w = 0;
}

void test_menu_print_items(void) {
    u8 **table;

    reg_a0 = (u8 *)test_menu_text_input;
    reg_d0.h[0] = 0;
    test_print_lines();
    reg_a0 = (u8 *)test_menu_text_output;
    test_print_lines();
    reg_a0 = (u8 *)test_menu_text_sound;
    test_print_lines();
    reg_a0 = (u8 *)test_menu_text_color;
    test_print_lines();
    reg_a0 = (u8 *)test_menu_text_crosshatch;
    test_print_lines();
    reg_a0 = (u8 *)test_menu_text_system;
    test_print_lines();
    reg_a0 = (u8 *)test_menu_text_game;
    test_print_lines();
    reg_a0 = (u8 *)test_menu_text_memory;
    test_print_lines();
    reg_a0 = (u8 *)test_menu_text_default;
    test_print_lines();
    reg_a0 = (u8 *)test_menu_text_exit;
    test_print_lines();
    table = test_menu_item_texts;
    reg_d0.w = 0;
    reg_d0.b[0] = g_test_cursor;
    table += reg_d0.h[0];
    reg_a0 = *table;
    reg_d0.h[0] = 2;
    test_print_lines();
}

void test_menu_update(void) {
    input_get_p1_pressed();
    if (reg_d0.w & 1) {
        sfx_cursor_move();
        test_menu_cursor_erase();
        g_test_cursor -= 1;
        if (0 > g_test_cursor) {
            g_test_cursor = 9;
        }
        test_menu_cursor_draw();
        test_menu_print_items();
        reg_d0.h[0] = 0;
        reg_a0 = (u8 *)test_menu_text_help_start;
        test_print_lines();
        if (g_test_cursor == 8) {
            reg_a0 = (u8 *)test_menu_text_help_reset;
            test_print_lines();
        }
    }
    input_get_p1_pressed();
    if (reg_d0.w & 2) {
        sfx_cursor_move();
        test_menu_cursor_erase();
        g_test_cursor += 1;
        if (g_test_cursor > 9) {
            g_test_cursor = 0;
        }
        test_menu_cursor_draw();
        test_menu_print_items();
        reg_d0.h[0] = 0;
        reg_a0 = (u8 *)test_menu_text_help_start;
        test_print_lines();
        if (g_test_cursor == 8) {
            reg_a0 = (u8 *)test_menu_text_help_reset;
            test_print_lines();
        }
    }
    input_get_p1_pressed();
    if (reg_d0.w & 0x10) {
        sfx_confirm();
        if (g_test_cursor == 0) {
            reg_d0.w = TEST_SCREEN_INPUT;
            test_screen_request();
        }
        if (g_test_cursor == 1) {
            reg_d0.w = TEST_SCREEN_OUTPUT;
            test_screen_request();
        }
        if (g_test_cursor == 2) {
            reg_d0.w = TEST_SCREEN_SOUND;
            test_screen_request();
        }
        if (g_test_cursor == 3) {
            reg_d0.w = TEST_SCREEN_COLOR;
            test_screen_request();
        }
        if (g_test_cursor == 4) {
            reg_d0.w = TEST_SCREEN_CROSSHATCH;
            test_screen_request();
        }
        if (g_test_cursor == 5) {
            reg_d0.w = TEST_SCREEN_SYSTEM;
            test_screen_request();
        }
        if (g_test_cursor == 6) {
            reg_d0.w = TEST_SCREEN_GAME;
            test_screen_request();
        }
        if (g_test_cursor == 7) {
            reg_d0.w = TEST_SCREEN_MEMORY;
            test_screen_request();
        }
        if (g_test_cursor == 8) {
            reg_d0.w = TEST_SCREEN_DEFAULT;
            test_screen_request();
        }
        if (g_test_cursor == 9) {
            cond_flag = 1;
            return;
        }
        goto not_exit;
    }
not_exit:
    cond_flag = 0;
}
