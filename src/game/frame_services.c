#include "common.h"
#include "task.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

void func_00132420(void);

#ifndef DEATH_LABEL
s32 func_00130D80();
s32 func_00130DB0();
s32 func_00130DC0();
s32 func_00130E00();
s32 func_00130E70();
s32 func_00130EC0();
s32 func_00130F10();
s32 func_00130FB0();
s32 func_00131050();
s32 func_001310F0();
s32 func_00131150();
s32 func_001311A0();
extern u8 g_setting_chute_type;
extern u8 g_setting_coin_mode;

void func_00131200(void) {
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = g_setting_coin_mode;
    reg_d1.b[0] = g_setting_chute_type;
    if (reg_d0.h[0] == 0x12) {
        if (reg_d1.b[0] != 1) {
            func_00130D80();
            return;
        }
        func_00130DB0();
        func_00130DC0();
        return;
    }
    if (reg_d0.h[0] == 0x11) {
        if (reg_d1.b[0] != 1) {
            func_00130E00();
            return;
        }
        func_00130E70();
        func_00130EC0();
        return;
    }
    if (((s16) reg_d0.h[0] < 0x11) && ((s16) reg_d0.h[0] >= 9)) {
        if (reg_d1.b[0] != 1) {
            func_00130F10();
            return;
        }
        func_00130FB0();
        func_00131050();
        return;
    }
    if (reg_d1.b[0] != 1) {
        func_001310F0();
        return;
    }
    func_00131150();
    func_001311A0();
}
#endif

extern u8 D_0028E1E6[];

void func_00131340(void) {
    reg_d0.b[0] = D_0028E1E6[0];
    if (reg_d0.b[0] != 0) {
        D_0028E1E6[0] -= 1;
    }
}

extern u8 D_0028E1DA[];

void func_00131370(void) {
    reg_d0.b[0] = D_0028E1DA[0];
    if (reg_d0.b[0] != 0) {
        D_0028E1DA[0] -= 1;
    }
}

extern u8 D_0028E1E4[];

void func_001313A0(void) {
    reg_d1.b[0] = D_0028E1E4[0];
    reg_d1.b[0] -= reg_d0.b[0];
    if ((s8) reg_d1.b[0] < 0) {
        reg_d1.w = 0;
    }
    D_0028E1E4[0] = reg_d1.b[0];
}

extern u8 D_0028E1D8[];

void func_001313E0(void) {
    reg_d1.b[0] = D_0028E1D8[0];
    reg_d1.b[0] -= reg_d0.b[0];
    if ((s8) reg_d1.b[0] < 0) {
        reg_d1.w = 0;
    }
    D_0028E1D8[0] = reg_d1.b[0];
}

extern s8 D_0028E1FC;
extern s8 D_0028E200;
extern s8 D_0028E204_as_s8;
extern s8 D_0028E208_as_s8;

void coin_counters_pulse(void) {
    D_0028E208_as_s8 = 1;
    D_0028E204_as_s8 = 1;
    D_0028E200 = 1;
    D_0028E1FC = 1;
}

extern s16 g_frame_mod16_as_s16;
extern s16 g_frame_mod8_as_s16;
extern s16 g_frame_mod4_as_s16;
extern s16 g_frame_mod3_as_s16;
extern s16 g_frame_mod2_as_s16;
extern s16 g_game_frame_as_s16;

void frame_counters_reset(void) {
    g_game_frame_as_s16 = 0;
    g_frame_mod2_as_s16 = 0;
    g_frame_mod3_as_s16 = 0;
    g_frame_mod4_as_s16 = 0;
    g_frame_mod8_as_s16 = 0;
    g_frame_mod16_as_s16 = 0;
    rng_cursor = 0;
}

extern s16 D_0028E22C;
extern s16 g_test_switch_on;

void test_switch_read(void) {
    reg_d0.h[0] = (u16) D_0028E22C;
    g_test_switch_on = 0;
    if (!(reg_d0.w & 0x80)) {
        g_test_switch_on = 1;
    }
}

s32 slowdown_reset();                            /* extern */
s32 replay_header_clear();                            /* extern */
extern s16 g_select_screen_active_as_s16;
extern s16 g_test_mode_entered;
extern s16 g_attract_demo_stage_as_s16;
extern s16 g_attract_demo_as_s16;
extern s16 D_0028E3C4;
extern s16 g_debug_build;
extern s16 g_publicity_build;
extern s16 g_location_test_build;
extern s8 g_replay_mode_as_s8;
extern s8 g_simulation_active_as_s8;

void func_00131490(void) {
    D_0028E3C4 = 0;
    g_game_frame_as_s16 = 0;
    g_frame_mod2_as_s16 = 0;
    g_frame_mod3_as_s16 = 0;
    g_frame_mod4_as_s16 = 0;
    g_frame_mod8_as_s16 = 0;
    g_frame_mod16_as_s16 = 0;
    rng_cursor = 0;
    g_location_test_build = 0;
    g_select_screen_active_as_s16 = 0;
    slowdown_reset();
    g_publicity_build = 0;
    g_debug_build = 0;
    g_simulation_active_as_s8 = 0;
    g_replay_mode_as_s8 = 0;
    replay_header_clear();
    g_attract_demo_as_s16 = 0;
    g_attract_demo_stage_as_s16 = 0;
    g_test_mode_entered = 0;
    test_switch_read();
}

extern u16 g_frame_mod16;
extern u16 g_frame_mod8;
extern u16 g_frame_mod4;
extern u16 g_frame_mod3;
extern u16 g_frame_mod2;
extern u16 g_game_frame;

void frame_counters_advance(void) {
    g_game_frame += 1;
    if (g_frame_mod2 & 1) {
        g_frame_mod2 &= 0xFFFE;
    } else {
        g_frame_mod2 |= 1;
    }
    g_frame_mod3 += 1;
    if (g_frame_mod3 == 3) {
        g_frame_mod3 = 0;
    }
    g_frame_mod4 = g_game_frame;
    g_frame_mod8 = g_game_frame;
    g_frame_mod16 = g_game_frame;
    g_frame_mod4 &= 3;
    g_frame_mod8 &= 7;
    g_frame_mod16 &= 0xF;
}
