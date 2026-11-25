/* Data of the test mode unit, still to be merged into it. */
#include "common.h"

void test_color_begin();
void test_color_update();
void test_crosshatch_begin();
void test_crosshatch_update();
void test_default_begin();
void test_default_update();
void test_game_begin();
void test_game_update();
void test_input_begin();
void test_input_update();
void test_memory_begin();
void test_memory_update();
void test_menu_begin();
void test_menu_update();
void test_output_begin();
void test_output_update();
void test_sound_begin();
void test_sound_update();
void test_system_begin();
void test_system_update();

extern void *test_screen_routines[20];

void *test_screen_routines[20] = {
    test_menu_begin,
    test_menu_update,
    test_input_begin,
    test_input_update,
    test_output_begin,
    test_output_update,
    test_sound_begin,
    test_sound_update,
    test_color_begin,
    test_color_update,
    test_crosshatch_begin,
    test_crosshatch_update,
    test_system_begin,
    test_system_update,
    test_game_begin,
    test_game_update,
    test_memory_begin,
    test_memory_update,
    test_default_begin,
    test_default_update,
};
