#ifndef TEST_MODE_H
#define TEST_MODE_H

#include "common.h"

/* The screens of the test mode; index into test_screen_routines. */
enum {
    TEST_SCREEN_MENU,
    TEST_SCREEN_INPUT,
    TEST_SCREEN_OUTPUT,
    TEST_SCREEN_SOUND,
    TEST_SCREEN_COLOR,
    TEST_SCREEN_CROSSHATCH,
    TEST_SCREEN_SYSTEM,
    TEST_SCREEN_GAME,
    TEST_SCREEN_MEMORY,
    TEST_SCREEN_DEFAULT
};

/* g_test_screen_state */
enum {
    TEST_SCREEN_REQUESTED = 1, /* run the screen's begin routine next frame */
    TEST_SCREEN_RUNNING = 2
};

extern s8 g_test_screen;
extern s8 g_test_screen_state;
extern s8 g_test_cursor; /* selected line; the sound and memory screens use it as a counter */
extern s8 g_test_redraw; /* values need printing again; the memory and default screens use it as a timer */

/* The settings the system and game screens edit, as indices into their name tables. */
extern u8 g_setting_coin_mode;
extern u8 g_setting_continue;
extern u8 g_setting_demo_sound;
extern u8 g_setting_chute_type;
extern u8 g_setting_difficulty;
extern u8 g_setting_extend;
extern u8 g_setting_ship_stock;
extern u8 g_setting_rapid_fire;

/* Arguments are in the register bank. */
void test_palettes_load();
void test_print_lines();    /* reg_a0: records of column, row, a pad byte and text; 0x7F starts the next record, 0xFF ends. reg_d0: palette */
void test_print_at();       /* reg_a0: text ended by 0xFF, reg_d0: column, reg_d1: row, reg_d2: palette */
void test_print_hex4();     /* reg_d3: value, reg_d0: column, reg_d1: row, reg_d2: palette */
void test_cursor_put();     /* reg_d0: column, reg_d1: row, reg_d2: negative erases */
void test_screen_request(); /* reg_d0: screen */
void settings_reset();
void settings_validate();   /* cond_flag set when a setting is out of range */
void layers_clear_all();

#endif
