#include "common.h"
#include "test_mode.h"

extern void (*test_sound_requests[72])();

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
    reg_a0 = *(u8 **)((u8 *)((u8 *)test_sound_requests) + (reg_d1.h[0] * 4));
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

void music_play_bgm1();
void music_play_bgm2();
void music_play_bgm3();
void music_play_bgm4();
void music_play_bgm5();
void music_play_bgm6();
void music_play_bgm7();
void music_play_bgm8();
void music_play_bgm9();
void music_play_bgm10();
void music_play_bgm11();
void music_play_bgm12();
void music_play_bgm13();
void sfx_explosion_air_small();
void sfx_explosion_air_medium();
void sfx_explosion_air_large();
void sfx_explosion_ground_small();
void sfx_explosion_ground_medium();
void sfx_explosion_ground_large();
void sfx_explosion_extra_0();
void sfx_explosion_extra_1();
void sfx_explosion_extra_2();
void sfx_explosion_extra_3();
void sfx_explosion_extra_4();
void sfx_explosion_extra_5();
void sfx_player_explosion();
void sfx_shot_a();
void sfx_shot_b();
void sfx_shot_hyper();
void sfx_p1_laser_a_start();
void sfx_p1_laser_b_start();
void sfx_p1_laser_hyper_start();
void sfx_laser_bomb_a();
void sfx_laser_bomb_b();
void sfx_spread_bomb_a();
void sfx_spread_bomb_b();
void sfx_coin();
void sfx_item_pickup();
void sfx_score_item_pickup();
void sfx_bee_pickup();
void sfx_hyper_pickup();
void sfx_extend();
void sfx_warning();
void sfx_countdown();
void sfx_bonus_count();
void sfx_confirm();
void sfx_cursor_move();
void sfx_enemy_fire_0();
void sfx_enemy_fire_1();
void sfx_enemy_fire_2();
void sfx_enemy_fire_3();
void sfx_heli_start();
void sfx_shockwave();
void sfx_charge_begin();
void sfx_charge_loop_start();
void sfx_beam_fire();
void sfx_beam_loop_start();
void sfx_misc_0();
void sfx_misc_1();
void sfx_misc_2();
void sfx_misc_3();
void voice_power_up();
void voice_bomb();
void voice_continue();
void voice_game_over();
void voice_warning();
void voice_hyper();
void voice_select();
void voice_ok();
void voice_bye();
void voice_logo();

s32 test_sound_text_title[4] = {
    0x53003209, 0x444E554F, 0x53455420, 0x0000FF54,
};

s32 test_sound_text_code[8] = {
    0x53002A04, 0x444E554F, 0x444F4320, 0x6F4E2045, 0x0000FF2E, 0x00000000, 0x00000000, 0x00000000,
};

s32 test_sound_text_help_up[8] = {
    0x43002204, 0x2045444F, 0x6831302B, 0x31203D20, 0x50552050, 0x000000FF, 0x00000000, 0x00000000,
};

s32 test_sound_text_help_down[8] = {
    0x43002004, 0x2045444F, 0x6831302D, 0x31203D20, 0x4F442050, 0x00FF4E57, 0x00000000, 0x00000000,
};

s32 test_sound_text_help_right[8] = {
    0x43001E04, 0x2045444F, 0x6830312B, 0x31203D20, 0x49522050, 0xFF544847, 0x00000000, 0x00000000,
};

s32 test_sound_text_help_left[8] = {
    0x43001C04, 0x2045444F, 0x6830312D, 0x31203D20, 0x454C2050, 0x00FF5446, 0x00000000, 0x00000000,
};

s32 test_sound_text_help_request[8] = {
    0x52001A04, 0x45555145, 0x20205453, 0x31203D20, 0x48532050, 0xFF31544F, 0x00000000, 0x00000000,
};

s32 test_sound_text_help_stop[8] = {
    0x53001804, 0x20504F54, 0x20202020, 0x31203D20, 0x48532050, 0xFF32544F, 0x00000000, 0x00000000,
};

s32 test_sound_text_exit[8] = {
    0x45000803, 0x20544958, 0x5031203D, 0x41545320, 0x26205452, 0x4F485320, 0xFF203154, 0x00000000,
};

void (*test_sound_requests[72])() = {
    music_play_bgm1,
    music_play_bgm2,
    music_play_bgm3,
    music_play_bgm4,
    music_play_bgm5,
    music_play_bgm6,
    music_play_bgm7,
    music_play_bgm8,
    music_play_bgm9,
    music_play_bgm10,
    music_play_bgm11,
    music_play_bgm12,
    music_play_bgm13,
    sfx_explosion_air_small,
    sfx_explosion_air_medium,
    sfx_explosion_air_large,
    sfx_explosion_ground_small,
    sfx_explosion_ground_medium,
    sfx_explosion_ground_large,
    sfx_explosion_extra_0,
    sfx_explosion_extra_1,
    sfx_explosion_extra_2,
    sfx_explosion_extra_3,
    sfx_explosion_extra_4,
    sfx_explosion_extra_5,
    sfx_player_explosion,
    sfx_shot_a,
    sfx_shot_b,
    sfx_shot_hyper,
    sfx_p1_laser_a_start,
    sfx_p1_laser_b_start,
    sfx_p1_laser_hyper_start,
    sfx_laser_bomb_a,
    sfx_laser_bomb_b,
    sfx_spread_bomb_a,
    sfx_spread_bomb_b,
    sfx_coin,
    sfx_item_pickup,
    sfx_score_item_pickup,
    sfx_bee_pickup,
    sfx_hyper_pickup,
    sfx_extend,
    sfx_warning,
    sfx_countdown,
    sfx_bonus_count,
    sfx_confirm,
    sfx_cursor_move,
    sfx_enemy_fire_0,
    sfx_enemy_fire_1,
    sfx_enemy_fire_2,
    sfx_enemy_fire_3,
    sfx_heli_start,
    sfx_shockwave,
    sfx_charge_begin,
    sfx_charge_loop_start,
    sfx_beam_fire,
    sfx_beam_loop_start,
    sfx_misc_0,
    sfx_misc_1,
    sfx_misc_2,
    sfx_misc_3,
    voice_power_up,
    voice_bomb,
    voice_continue,
    voice_game_over,
    voice_warning,
    voice_hyper,
    voice_select,
    voice_ok,
    voice_bye,
    voice_logo,
    0,
};
