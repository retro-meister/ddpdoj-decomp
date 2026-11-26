#include "common.h"
#include "test_mode.h"
#include "task.h"

/* own[1] of the task: the test mode has been set up */
#define TEST_TASK_STARTED(task) (TASK(task)->own[1])

s32 func_00137C50();
s32 sound_stop_effects();
s32 sound_stop_loops();
s32 music_stop();

extern s32 g_text_palette[];
extern u8 text_palette_0[];
extern u8 text_palette_1[];
extern u8 text_palette_2[];
extern u8 text_palette_3[];
extern u8 text_palette_4[];
extern s8 g_test_mode_flag;
extern s8 g_test_mode_timer;
extern u8 test_screen_routines[];
extern s16 g_test_mode_entered;

void test_palette_load(void)
{
    s32 *source = (s32 *)reg_a0;
    s32 *destination = g_text_palette;
    s32 offset;

    reg_d0.h[0] <<= 5;
    offset = (s32)reg_d0.h[0] >> 2;
    reg_a1 += offset;
    reg_d0.w = 7;

    do {
        *destination++ = *source++;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

void test_palettes_load(void) {
    reg_a0 = text_palette_0;
    reg_d0.w = 0;
    test_palette_load();
    reg_a0 = text_palette_1;
    reg_d0.w = 1;
    test_palette_load();
    reg_a0 = text_palette_2;
    reg_d0.w = 2;
    test_palette_load();
    reg_a0 = text_palette_3;
    reg_d0.w = 3;
    test_palette_load();
    reg_a0 = text_palette_4;
    reg_d0.w = 4;
    test_palette_load();
}

void test_mode_init(void) {
    g_test_mode_timer = 0x3C;
    g_test_mode_flag = 0;
    settings_validate();
    if (cond_flag != 0) {
        settings_reset();
    }
}

typedef void (*Fn)();


void test_mode_task(void) {
    if (TEST_TASK_STARTED(reg_a5) != 0) {
        if (g_test_screen_state == TEST_SCREEN_REQUESTED) {
            reg_d0.w = 0;
            g_test_screen_state = TEST_SCREEN_RUNNING;
            reg_d0.b[0] = (u8) g_test_screen;
            reg_d0.h[0] += reg_d0.h[0];
            reg_a0 = *(u8 **)((u8 *)test_screen_routines + (reg_d0.h[0] * 4));
            reg_call_target = (Fn)(reg_a0);
            reg_call_target();
        }
        reg_d0.w = 0;
        reg_d0.b[0] = (u8) g_test_screen;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += 1;
        reg_a0 = *(u8 **)((u8 *)test_screen_routines + (reg_d0.h[0] * 4));
        reg_call_target = (Fn)(reg_a0);
        reg_call_target();
        return;
    }
    g_test_screen = TEST_SCREEN_MENU;
    g_test_mode_timer = 0x3C;
    g_test_screen_state = TEST_SCREEN_REQUESTED;
    test_palettes_load();
    TEST_TASK_STARTED(reg_a5) = 1U;
    music_stop();
    sound_stop_effects();
    sound_stop_loops();
    func_00137C50();
    g_test_mode_entered = 1;
}

/* .sbss (the compiler lays these out in reverse) */
s8 g_test_mode_timer __attribute__((aligned(4)));
s8 g_test_screen_state __attribute__((aligned(4)));
s8 g_test_screen __attribute__((aligned(4)));
s8 g_test_mode_flag __attribute__((aligned(4)));
s8 g_test_cursor __attribute__((aligned(4)));
s8 g_test_redraw __attribute__((aligned(4)));
