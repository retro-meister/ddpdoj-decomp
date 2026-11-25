/* Data of the test sound unit, still to be merged into it. */
#include "common.h"

void music_play_bgm1();
void music_play_bgm10();
void music_play_bgm11();
void music_play_bgm12();
void music_play_bgm13();
void music_play_bgm2();
void music_play_bgm3();
void music_play_bgm4();
void music_play_bgm5();
void music_play_bgm6();
void music_play_bgm7();
void music_play_bgm8();
void music_play_bgm9();
void sfx_beam_fire();
void sfx_beam_loop_start();
void sfx_bee_pickup();
void sfx_bonus_count();
void sfx_charge_begin();
void sfx_charge_loop_start();
void sfx_coin();
void sfx_confirm();
void sfx_countdown();
void sfx_cursor_move();
void sfx_enemy_fire_0();
void sfx_enemy_fire_1();
void sfx_enemy_fire_2();
void sfx_enemy_fire_3();
void sfx_explosion_air_large();
void sfx_explosion_air_medium();
void sfx_explosion_air_small();
void sfx_explosion_extra_0();
void sfx_explosion_extra_1();
void sfx_explosion_extra_2();
void sfx_explosion_extra_3();
void sfx_explosion_extra_4();
void sfx_explosion_extra_5();
void sfx_explosion_ground_large();
void sfx_explosion_ground_medium();
void sfx_explosion_ground_small();
void sfx_extend();
void sfx_heli_start();
void sfx_hyper_pickup();
void sfx_item_pickup();
void sfx_laser_bomb_a();
void sfx_laser_bomb_b();
void sfx_misc_0();
void sfx_misc_1();
void sfx_misc_2();
void sfx_misc_3();
void sfx_p1_laser_a_start();
void sfx_p1_laser_b_start();
void sfx_p1_laser_hyper_start();
void sfx_player_explosion();
void sfx_score_item_pickup();
void sfx_shockwave();
void sfx_shot_a();
void sfx_shot_b();
void sfx_shot_hyper();
void sfx_spread_bomb_a();
void sfx_spread_bomb_b();
void sfx_warning();
void voice_bomb();
void voice_bye();
void voice_continue();
void voice_game_over();
void voice_hyper();
void voice_logo();
void voice_ok();
void voice_power_up();
void voice_select();
void voice_warning();

extern u16 test_sound_text_title[8];
extern u16 test_sound_text_code[16];
extern u16 test_sound_text_help_up[16];
extern u16 test_sound_text_help_down[16];
extern u16 test_sound_text_help_right[16];
extern u16 test_sound_text_help_left[16];
extern u16 test_sound_text_help_request[16];
extern u16 test_sound_text_help_stop[16];
extern u16 test_sound_text_exit[16];
struct TestSoundRequestsRecord { void *p0; void *p1; void *p2; void *p3; void *p4; void *p5; void *p6; void *p7; void *p8; void *p9; void *p10; void *p11; void *p12; void *p13; void *p14; void *p15; void *p16; void *p17; void *p18; void *p19; void *p20; void *p21; void *p22; void *p23; void *p24; void *p25; void *p26; void *p27; void *p28; void *p29; void *p30; void *p31; void *p32; void *p33; void *p34; void *p35; void *p36; void *p37; void *p38; void *p39; void *p40; void *p41; void *p42; void *p43; void *p44; void *p45; void *p46; void *p47; void *p48; void *p49; void *p50; void *p51; void *p52; void *p53; void *p54; void *p55; void *p56; void *p57; void *p58; void *p59; void *p60; void *p61; void *p62; void *p63; void *p64; void *p65; void *p66; void *p67; void *p68; void *p69; void *p70; u16 w71[2]; };
extern struct TestSoundRequestsRecord test_sound_requests;

u16 test_sound_text_title[8] = {
    0x3209, 0x5300, 0x554F, 0x444E, 0x5420, 0x5345, 0xFF54, 0x0000,
};

u16 test_sound_text_code[16] = {
    0x2A04, 0x5300, 0x554F, 0x444E, 0x4320, 0x444F, 0x2045, 0x6F4E,
    0xFF2E, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 test_sound_text_help_up[16] = {
    0x2204, 0x4300, 0x444F, 0x2045, 0x302B, 0x6831, 0x3D20, 0x3120,
    0x2050, 0x5055, 0x00FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 test_sound_text_help_down[16] = {
    0x2004, 0x4300, 0x444F, 0x2045, 0x302D, 0x6831, 0x3D20, 0x3120,
    0x2050, 0x4F44, 0x4E57, 0x00FF, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 test_sound_text_help_right[16] = {
    0x1E04, 0x4300, 0x444F, 0x2045, 0x312B, 0x6830, 0x3D20, 0x3120,
    0x2050, 0x4952, 0x4847, 0xFF54, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 test_sound_text_help_left[16] = {
    0x1C04, 0x4300, 0x444F, 0x2045, 0x312D, 0x6830, 0x3D20, 0x3120,
    0x2050, 0x454C, 0x5446, 0x00FF, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 test_sound_text_help_request[16] = {
    0x1A04, 0x5200, 0x5145, 0x4555, 0x5453, 0x2020, 0x3D20, 0x3120,
    0x2050, 0x4853, 0x544F, 0xFF31, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 test_sound_text_help_stop[16] = {
    0x1804, 0x5300, 0x4F54, 0x2050, 0x2020, 0x2020, 0x3D20, 0x3120,
    0x2050, 0x4853, 0x544F, 0xFF32, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 test_sound_text_exit[16] = {
    0x0803, 0x4500, 0x4958, 0x2054, 0x203D, 0x5031, 0x5320, 0x4154,
    0x5452, 0x2620, 0x5320, 0x4F48, 0x3154, 0xFF20, 0x0000, 0x0000,
};

struct TestSoundRequestsRecord test_sound_requests = {
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
    { 0x0000, 0x0000 },
};
