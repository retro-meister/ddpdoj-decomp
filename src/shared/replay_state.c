#include "common.h"
#include "sdk/ps2sdk.h"

typedef struct {
    u8 pad[0x3511];
    s8 data[0x2000];
} Src;

void func_0023B6B0(const Src *src);

typedef struct {
    f32 v[4];
} Vec4;

typedef struct {
    s16 h[16];
} Row16;

typedef struct {
    u8 a[90];
    u8 b[90];
} Bank90;

typedef struct {
    u8 a[10];
    u8 b[10];
} Bank10;

typedef struct {
    u8 f0000[0xC08];
    u8 padC08[0xE];
    u8 fC16[98];
    u8 fC78[98];
    u8 fCDA[100];
    u8 fD3E[100];
    u8 fDA2[0xD80];
    u8 f1B22[0x600];
    u8 f2122[0x600];
    u8 f2722[0x20];
    u8 f2742[0x20];
    u8 f2762[0x20];
    u8 f2782[0x20];
    u8 f27A2[0x870];
    u8 pad3012[0x1A];
    s32 f302C[16];
    s32 f306C[16];
    s32 f30AC[16];
    s32 f30EC[16];
    u8 pad312C[0xF2];
    u8 f321E[0x48];
    u8 pad3266[0x4E];
    u8 f32B4[90];
    u8 f330E[90];
    u8 f3368[10];
    u8 f3372[10];
    u8 pad337C[0xDC];
    s32 f3458[16];
    s32 f3498[16];
    u8 pad34D8[0x39];
    s8 f3511[0x2000];
    Row16 f5512;
} Buf;

extern char D_0028BF40[];
extern char D_0028BF58[];
extern char D_0028BF68[];
extern char D_0028BF78[];
extern char D_0028BF88[];
extern char D_0028BF98[];
extern u16 D_0028DFB4;
extern u16 D_0028DFB8;
extern u16 D_0028DFBC;
extern u16 D_0028DFC0;
extern u16 D_0028DFC4;
extern u16 D_0028DFC8;
extern u16 D_0028DFCC;
extern u16 D_0028DFD0;
extern u16 D_0028DFD4;
extern u16 D_0028DFD8;
extern u16 D_0028DFDC;
extern u16 D_0028DFE0;
extern u16 D_0028DFE4;
extern u16 D_0028DFE8;
extern u16 D_0028DFEC;
extern u16 D_0028DFF0;
extern s32 D_0028DFF4;
extern u16 D_0028DFF8;
extern u16 g_hyper_bullet_speed;
extern u16 D_0028E000;
extern u16 D_0028E004;
extern u16 D_0028E008;
extern u16 D_0028E00C;
extern u16 D_0028E010;
extern u16 D_0028E014;
extern u16 D_0028E018;
extern u16 D_0028E01C;
extern u16 D_0028E020;
extern u16 D_0028E024;
extern u16 D_0028E028;
extern u16 D_0028E02C;
extern u16 D_0028E030;
extern u16 D_0028E034;
extern u16 D_0028E038;
extern u16 D_0028E03C;
extern u16 D_0028E040;
extern u16 D_0028E044;
extern u16 D_0028E050;
extern u16 D_0028E054;
extern s32 D_0028E058;
extern s32 D_0028E05C;
extern u16 D_0028E060;
extern u16 D_0028E064;
extern u16 D_0028E068;
extern u16 D_0028E06C;
extern u16 D_0028E070;
extern u16 D_0028E074;
extern s32 D_0028E078_as_s32_a[];
extern s32 D_0028E07C_as_s32_a[];
extern s32 D_0028E080_as_s32_a[];
extern s32 D_0028E084_as_s32_a[];
extern u16 D_0028E088;
extern u8 D_0028E284;
extern u8 D_0028E288;
extern u8 D_0028E2EC;
extern u8 D_0028E304;
extern u8 g_setting_ship_stock;
extern u8 g_setting_extend;
extern u8 g_setting_difficulty;
extern u16 D_0028E3DC;
extern u16 D_0028E3E0;
extern u16 D_0028E3E4;
extern u16 D_0028E3E8;
extern u16 D_0028E3EC;
extern u16 g_game_frame;
extern u16 g_p2_hyper_effect_delay;
extern u16 g_p1_hyper_effect_delay;
extern u16 g_p2_hyper_effect_flag;
extern u16 g_p1_hyper_effect_flag;
extern u16 g_p2_hyper_effect_frame;
extern u16 g_p1_hyper_effect_frame;
extern s32 g_p2_hyper_effect_sprite;
extern s32 g_p1_hyper_effect_sprite;
extern u16 g_score_task_active;
extern u16 g_score_panel_intro;
extern u16 D_0028E5A0;
extern u16 g_boss_double_speed;
extern u16 g_hyper_level_hit_scratch;
extern u16 g_hyper_hit_scratch;
extern u16 g_boss_hyper_wait;
extern u16 g_p2_hyper_items_pending;
extern u16 g_p1_hyper_items_pending;
extern u16 g_p2_hyper_items;
extern u16 g_p1_hyper_items;
extern u16 g_p2_hyper_in_effect;
extern u16 g_p1_hyper_in_effect;
extern u16 g_p2_hyper_level;
extern u16 g_p1_hyper_level;
extern u16 g_hyper_text_slide;
extern u16 g_p2_hyper_combo_decay;
extern u16 g_p1_hyper_combo_decay;
extern u16 g_p2_hyper_gauge;
extern u16 g_p1_hyper_gauge;
extern u16 g_p2_hyper_total;
extern u16 g_p1_hyper_total;
extern u16 g_p2_hyper_time;
extern u16 g_p1_hyper_time;
extern u16 g_p2_hyper_active;
extern u16 g_p1_hyper_active;
extern u16 g_p2_shot_hyper_timer;
extern u16 g_p1_shot_hyper_timer;
extern u16 g_p2_laser_hyper_timer;
extern u16 g_p1_laser_hyper_timer;
extern u16 g_p2_max_hits;
extern u16 g_p1_max_hits;
extern u16 g_boss_explosion_flash;
extern u16 g_boss_near_death;
extern s32 g_boss_hp_as_s32;
extern s32 g_boss_hp_unit;
extern u16 g_lives_display_move_x;
extern u16 g_lives_display_move_y;
extern u16 g_boss_hp_bar_move_count;
extern u16 g_boss_hp_bar_flags_as_u16;
extern s32 g_boss_score;
extern s32 g_boss_hit_bonus;
extern u16 g_boss_hit_bonus_timer;
extern u16 g_boss_hit_palette_as_u16;
extern u16 g_boss_hits;
extern u16 g_boss_hit_anim_count;
extern u16 g_boss_hit_decay_timer;
extern u16 g_p2_laser_hit_step;
extern u16 g_p2_laser_hit_timer;
extern u16 g_p2_hits_shown;
extern u16 g_p2_hits;
extern s32 g_p2_chain_points_shown2;
extern s32 g_p2_chain_points_shown;
extern s32 g_p2_chain_points;
extern u16 g_p2_hit10_anim_count;
extern u16 g_p2_hit10_color_timer;
extern u16 g_p2_hit10_display_timer_as_u16;
extern u16 g_p2_combo_break_color_timer;
extern u16 g_p2_hit_display_timer;
extern u16 g_p2_chain_points_display_timer_as_u16;
extern u16 g_p2_combo_timer;
extern s32 g_p2_chain_first_score_shown;
extern s32 g_p2_chain_first_score;
extern u16 g_p1_laser_hit_step;
extern u16 g_p1_laser_hit_timer;
extern u16 g_p1_hits_shown;
extern u16 g_p1_hits;
extern s32 g_p1_chain_points_shown2;
extern s32 g_p1_chain_points_shown;
extern s32 g_p1_chain_points;
extern u16 g_p1_hit10_anim_count;
extern u16 g_p1_hit10_color_timer;
extern u16 g_p1_hit10_display_timer_as_u16;
extern u16 g_p1_combo_break_color_timer;
extern u16 g_p1_hit_display_timer;
extern u16 g_p1_chain_points_display_timer_as_u16;
extern u16 g_p1_combo_timer;
extern s32 g_p1_chain_first_score_shown;
extern s32 g_p1_chain_first_score;
extern u16 D_0028E6D4;
extern u16 g_boss_hit_carry;
extern u16 g_max_combo_time;
extern u16 D_0028E6E0;
extern u16 D_0028E6E4;
extern s32 g_score_scratch;
extern u16 g_max_level_display_timer;
extern s32 g_maximum_text_anim_sprite;
extern u16 g_maximum_text_anim_frame;
extern u16 g_maximum_text_anim_delay;
extern s32 g_hyper_text_anim_sprite;
extern u16 g_hyper_text_anim_frame;
extern u16 g_hyper_text_anim_delay;
extern u8 g_p2_score_panel_flags;
extern u8 g_p1_score_panel_flags;
extern u16 D_0028E710;
extern s32 D_0028E714;
extern s32 D_0028E718;
extern s32 D_0028E71C;
extern u16 g_p2_extend_setting;
extern u16 g_p1_extend_setting;
extern s32 g_p2_extend_score;
extern s32 g_p1_extend_score;
extern u16 g_p2_score_billions_saved;
extern u16 g_p1_score_billions_saved;
extern s32 g_p2_score_saved_as_s32;
extern s32 g_p1_score_saved_as_s32;
extern u16 g_p2_score_digits;
extern u16 g_high_score_digits;
extern u16 g_p1_score_digits;
extern u16 g_high_score_billions;
extern u16 g_p2_score_billions;
extern u16 g_p1_score_billions;
extern s32 g_high_score;
extern s32 g_p2_score_as_s32;
extern s32 g_p1_score_as_s32;
extern u16 D_0028E850;
extern u16 D_0028E854_as_u16;
extern u16 g_enemy_signal_f;
extern u16 g_enemy_signal_e;
extern u16 g_enemy_signal_d;
extern u16 g_enemy_signal_c;
extern u16 g_enemy_signal_b;
extern u16 g_enemy_signal_a;
extern u16 g_enemy_signal_9;
extern u16 g_enemy_signal_8;
extern u16 g_enemy_signal_7;
extern u16 g_enemy_signal_6;
extern u16 g_enemy_signal_5;
extern u16 g_enemy_signal_4;
extern u16 g_enemy_signal_3;
extern u16 g_enemy_signal_2;
extern u16 g_enemy_signal_1;
extern u16 g_enemy_signal_0;
extern u16 D_0028E8A4;
extern u16 g_scroll_line;
extern u16 D_0028E8AC;
extern u8 D_0028E8B0;
extern u8 D_0028E8B4;
extern u16 D_0028E8B8;
extern s32 D_0028E8BC;
extern u16 g_p2_lives;
extern u16 g_p1_lives;
extern u16 g_rank_1_16;
extern u16 g_rank_2_16;
extern u16 g_rank_3_16;
extern u16 g_rank_4_16;
extern u16 g_rank_5_16;
extern u16 g_rank_6_16;
extern u16 g_rank_7_16;
extern u16 g_rank_8_16;
extern u16 g_rank_9_16;
extern u16 g_rank_10_16;
extern u16 g_rank_11_16;
extern u16 g_rank_12_16;
extern u16 g_rank_13_16;
extern u16 g_rank_14_16;
extern u16 g_rank_15_16;
extern u16 g_rank;
extern u16 g_true_last_boss;
extern u16 g_game_completed;
extern u16 g_loop;
extern u16 g_stage_x4;
extern u16 g_stage_x2;
extern u16 g_stage;
extern u16 g_two_player_seen;
extern u16 g_two_player_state;
extern u16 g_two_player_game;
extern u16 D_0028E970;
extern u16 D_0028E974;
extern u16 D_0028E978;
extern u16 D_0028E97C;
extern u16 D_0028E980;
extern u16 D_0028E984;
extern u16 g_bullet_count;
extern s16 D_0029C060_as_s16_a[];
extern f32 D_0029CD80_as_f32_a[];
extern u16 D_0029CD8C[];
extern f32 D_0029CD90_as_f32_a[];
extern u16 D_0029CD9C[];
extern s32 D_0029CDA0_as_s32_a[];
extern s32 D_0029CDE0[];
extern s32 D_0029CE20_as_s32_a[];
extern s32 D_0029CE60[];
extern u8 D_0029CEA0_as_u8_a[];
extern u8 D_0029D710[];
extern u8 D_0029D730[];
extern u8 D_0029D750[];
extern u8 D_0029D770[];
extern u8 D_0029D790[];
extern u8 D_0029DD90[];
extern u8 D_0029E390[];
extern u8 D_0029F110[];
extern u8 D_0029F180[];
extern u8 g_player2_as_u8_a[];
extern u8 D_0029F1F1[];
extern u16 D_0029F210[];
extern u16 D_0029F212[];
extern u8 D_0029F214[];
extern u8 D_0029F215[];
extern u8 g_player1_as_u8_a[];
extern u8 D_0029F261[];
extern u16 D_0029F280[];
extern u16 D_0029F282[];
extern u8 D_0029F284[];
extern u8 D_0029F285[];
extern s8 g_text_layer_as_s8_a[];
extern s32 D_002BAEB0[];
extern s32 D_002BAEF0[];
extern Bank10 D_002BAF30_as_Bank10;
extern Bank90 D_002BAF50_as_Bank90;
extern u8 D_002BF390[];
extern u8 D_002BF4F0[];
extern s16 D_006C58AA_as_s16_a[];
extern u16 D_006C58B0[];
extern u16 D_006C58B2[];
extern u16 D_006C58B4[];
extern s16 D_006C58B6_as_s16_a[];
extern s16 D_006C58B8_as_s16_a[];
extern s16 D_006C58BA_as_s16_a[];
extern u16 D_006C58BC[];
extern u16 D_006C58BE[];
extern u16 D_006C58C0[];
extern s16 D_006C58C2_as_s16_a[];
extern u16 D_006C58C6[];
extern s16 D_006C58C8_as_s16_a[];
extern s16 D_006C58CA_as_s16_a[];
extern s16 D_006C58CC_as_s16_a[];
extern s16 D_006C58CE_as_s16_a[];
extern s16 D_006C58D0_as_s16_a[];
extern u16 D_006C58D2[];
extern u16 D_006C58D4[];
extern s16 D_006C58D6_as_s16_a[];
void func_00238B90(Buf *buf) {
    s32 i;
    s32 v;
    u8 *p = (u8 *)buf;

    printf(D_0028BF40, 0x5534);
    for (i = 0; i < 0xC08; i++) {
        buf->f0000[i] = D_002BF4F0[i];
    }
    *(u16 *)(p + 0xC08) = g_bullet_count;
    *(u16 *)(p + 0xC0A) = D_0028E984;
    *(u16 *)(p + 0xC0C) = D_0028E980;
    *(u16 *)(p + 0xC0E) = D_0028E97C;
    *(u16 *)(p + 0xC10) = D_0028E978;
    *(u16 *)(p + 0xC12) = D_0028E974;
    *(u16 *)(p + 0xC14) = D_0028E970;
    for (i = 0; i < 98; i++) {
        buf->fC16[i] = g_player1_as_u8_a[i];
        buf->fC78[i] = g_player2_as_u8_a[i];
    }
    for (i = 0; i < 100; i++) {
        buf->fCDA[i] = D_0029F180[i];
        buf->fD3E[i] = D_0029F110[i];
    }
    for (i = 0; i < 0xD80; i++) {
        buf->fDA2[i] = D_0029E390[i];
    }
    for (i = 0; i < 0x600; i++) {
        buf->f1B22[i] = D_0029DD90[i];
        buf->f2122[i] = D_0029D790[i];
    }
    for (i = 0; i < 0x20; i++) {
        buf->f2722[i] = D_0029D770[i];
        buf->f2742[i] = D_0029D750[i];
    }
    for (i = 0; i < 0x20; i++) {
        buf->f2762[i] = D_0029D730[i];
        buf->f2782[i] = D_0029D710[i];
    }
    for (i = 0; i < 0x870; i++) {
        buf->f27A2[i] = D_0029CEA0_as_u8_a[i];
    }
    *(u16 *)(p + 0x301A) = D_0028E088;
    *(s32 *)(p + 0x301C) = D_0028E080_as_s32_a[0];
    *(s32 *)(p + 0x3024) = D_0028E078_as_s32_a[0];
    *(s32 *)(p + 0x3020) = D_0028E084_as_s32_a[0];
    *(s32 *)(p + 0x3028) = D_0028E07C_as_s32_a[0];
    for (i = 0; i < 16; i++) {
        buf->f302C[i] = D_0029CE60[i];
        buf->f306C[i] = D_0029CE20_as_s32_a[i];
        buf->f30AC[i] = D_0029CDE0[i];
        buf->f30EC[i] = D_0029CDA0_as_s32_a[i];
    }
    *(Vec4 *)(p + 0x312C) = *(Vec4 *)D_0029CD90_as_f32_a;
    *(Vec4 *)(p + 0x313C) = *(Vec4 *)D_0029CD80_as_f32_a;
    *(u16 *)(p + 0x314C) = D_0028E074;
    *(u16 *)(p + 0x314E) = D_0028E070;
    *(u16 *)(p + 0x3150) = D_0028E06C;
    *(u16 *)(p + 0x3152) = D_0028E068;
    *(u16 *)(p + 0x3154) = D_0028E064;
    *(u16 *)(p + 0x3156) = D_0028E060;
    *(s32 *)(p + 0x3158) = D_0028E05C;
    *(s32 *)(p + 0x315C) = D_0028E058;
    *(u16 *)(p + 0x3160) = D_0028E054;
    *(u16 *)(p + 0x3162) = D_0028E050;
    *(u16 *)(p + 0x3164) = D_0028E044;
    *(u16 *)(p + 0x3166) = D_0028E040;
    *(u16 *)(p + 0x3168) = D_0028E03C;
    *(u16 *)(p + 0x316A) = D_0028E038;
    *(u16 *)(p + 0x316C) = D_0028E034;
    *(u16 *)(p + 0x316E) = D_0028E030;
    *(u16 *)(p + 0x3170) = D_0028E02C;
    *(u16 *)(p + 0x3172) = D_0028E028;
    *(u16 *)(p + 0x3174) = D_0028E024;
    *(u16 *)(p + 0x3176) = D_0028E020;
    *(u16 *)(p + 0x3178) = D_0028E01C;
    *(u16 *)(p + 0x317A) = D_0028E018;
    *(u16 *)(p + 0x317C) = D_0028E014;
    *(u16 *)(p + 0x317E) = D_0028E010;
    *(u16 *)(p + 0x3180) = D_0028E00C;
    *(u16 *)(p + 0x3182) = D_0028E008;
    *(u16 *)(p + 0x3184) = D_0028E004;
    *(u16 *)(p + 0x3186) = D_0028E000;
    *(u16 *)(p + 0x3188) = g_hyper_bullet_speed;
    *(u16 *)(p + 0x318A) = D_0028DFF8;
    *(s32 *)(p + 0x318C) = D_0028DFF4;
    *(u16 *)(p + 0x3190) = D_0028DFF0;
    *(u16 *)(p + 0x3192) = D_0028DFEC;
    *(u16 *)(p + 0x3194) = D_0028DFE8;
    *(u16 *)(p + 0x3196) = D_0028DFE4;
    *(u16 *)(p + 0x3198) = D_0028DFE0;
    *(u16 *)(p + 0x319A) = D_0028DFDC;
    *(u16 *)(p + 0x319C) = D_0028DFD8;
    *(u16 *)(p + 0x319E) = D_0028DFD4;
    *(u16 *)(p + 0x31A0) = D_0028DFD0;
    *(u16 *)(p + 0x31A2) = D_0028DFCC;
    *(u16 *)(p + 0x31A4) = D_0028DFC8;
    *(u16 *)(p + 0x31A6) = D_0028DFC4;
    *(u16 *)(p + 0x31A8) = D_0028DFC0;
    *(u16 *)(p + 0x31AA) = D_0028DFBC;
    *(u16 *)(p + 0x31AC) = D_0028DFB8;
    *(u16 *)(p + 0x31AE) = D_0028DFB4;
    *(u16 *)(p + 0x31B0) = g_two_player_game;
    *(u16 *)(p + 0x31B2) = g_two_player_state;
    *(u16 *)(p + 0x31B4) = g_two_player_seen;
    *(u16 *)(p + 0x31B6) = g_stage;
    *(u16 *)(p + 0x31B8) = g_stage_x2;
    *(u16 *)(p + 0x31BA) = g_stage_x4;
    *(u16 *)(p + 0x31BC) = g_loop;
    *(u16 *)(p + 0x31BE) = g_game_completed;
    *(u16 *)(p + 0x31C0) = g_true_last_boss;
    *(u16 *)(p + 0x31C2) = g_rank;
    *(u16 *)(p + 0x31C4) = g_rank_15_16;
    *(u16 *)(p + 0x31C6) = g_rank_14_16;
    *(u16 *)(p + 0x31C8) = g_rank_13_16;
    *(u16 *)(p + 0x31CA) = g_rank_12_16;
    *(u16 *)(p + 0x31CC) = g_rank_11_16;
    *(u16 *)(p + 0x31CE) = g_rank_10_16;
    *(u16 *)(p + 0x31D0) = g_rank_9_16;
    *(u16 *)(p + 0x31D2) = g_rank_8_16;
    *(u16 *)(p + 0x31D4) = g_rank_7_16;
    *(u16 *)(p + 0x31D6) = g_rank_6_16;
    *(u16 *)(p + 0x31D8) = g_rank_5_16;
    *(u16 *)(p + 0x31DA) = g_rank_4_16;
    *(u16 *)(p + 0x31DC) = g_rank_3_16;
    *(u16 *)(p + 0x31DE) = g_rank_2_16;
    *(u16 *)(p + 0x31E0) = g_rank_1_16;
    *(u16 *)(p + 0x31E2) = g_p1_lives;
    *(u16 *)(p + 0x31E4) = g_p2_lives;
    *(s32 *)(p + 0x31E8) = D_0028E8BC;
    *(u16 *)(p + 0x31EC) = D_0028E8B8;
    p[0x31EE] = D_0028E8B4;
    p[0x31EF] = D_0028E8B0;
    *(u16 *)(p + 0x31F0) = g_scroll_line;
    *(u16 *)(p + 0x31F2) = D_0028E8A4;
    *(u16 *)(p + 0x31F4) = D_0028E8AC;
    *(u16 *)(p + 0x31FC) = g_enemy_signal_0;
    *(u16 *)(p + 0x31FE) = g_enemy_signal_1;
    *(u16 *)(p + 0x3200) = g_enemy_signal_2;
    *(u16 *)(p + 0x3202) = g_enemy_signal_3;
    *(u16 *)(p + 0x3204) = g_enemy_signal_4;
    *(u16 *)(p + 0x3206) = g_enemy_signal_5;
    *(u16 *)(p + 0x3208) = g_enemy_signal_6;
    *(u16 *)(p + 0x320A) = g_enemy_signal_7;
    *(u16 *)(p + 0x320C) = g_enemy_signal_8;
    *(u16 *)(p + 0x320E) = g_enemy_signal_9;
    *(u16 *)(p + 0x3210) = g_enemy_signal_a;
    *(u16 *)(p + 0x3212) = g_enemy_signal_b;
    *(u16 *)(p + 0x3214) = g_enemy_signal_c;
    *(u16 *)(p + 0x3216) = g_enemy_signal_d;
    *(u16 *)(p + 0x3218) = g_enemy_signal_e;
    *(u16 *)(p + 0x321A) = g_enemy_signal_f;
    *(u16 *)(p + 0x321C) = D_0028E854_as_u16;
    for (i = 0; i < 0x48; i++) {
        buf->f321E[i] = D_002BF390[i];
    }
    *(u16 *)(p + 0x3266) = D_0028E850;
    *(s32 *)(p + 0x327C) = g_p1_score_as_s32;
    *(s32 *)(p + 0x3280) = g_p2_score_as_s32;
    *(s32 *)(p + 0x3284) = g_high_score;
    *(u16 *)(p + 0x3288) = g_p1_score_billions;
    *(u16 *)(p + 0x328A) = g_p2_score_billions;
    *(u16 *)(p + 0x328C) = g_high_score_billions;
    *(u16 *)(p + 0x328E) = g_p1_score_digits;
    *(u16 *)(p + 0x3290) = g_high_score_digits;
    *(u16 *)(p + 0x3292) = g_p2_score_digits;
    *(s32 *)(p + 0x3294) = g_p1_score_saved_as_s32;
    *(s32 *)(p + 0x3298) = g_p2_score_saved_as_s32;
    *(u16 *)(p + 0x329C) = g_p1_score_billions_saved;
    *(u16 *)(p + 0x329E) = g_p2_score_billions_saved;
    *(s32 *)(p + 0x32A0) = g_p1_extend_score;
    *(s32 *)(p + 0x32A4) = g_p2_extend_score;
    *(u16 *)(p + 0x32A8) = g_p1_extend_setting;
    *(u16 *)(p + 0x32AA) = g_p2_extend_setting;
    *(s32 *)(p + 0x32AC) = D_0028E71C;
    *(s32 *)(p + 0x32B0) = D_0028E718;
    for (i = 0; i < 90; i++) {
        buf->f32B4[i] = D_002BAF50_as_Bank90.a[i];
    }
    for (i = 0; i < 90; i++) {
        buf->f330E[i] = D_002BAF50_as_Bank90.b[i];
    }
    for (i = 0; i < 10; i++) {
        buf->f3368[i] = D_002BAF30_as_Bank10.a[i];
    }
    for (i = 0; i < 10; i++) {
        buf->f3372[i] = D_002BAF30_as_Bank10.b[i];
    }
    *(s32 *)(p + 0x337C) = D_0028E714;
    *(u16 *)(p + 0x3380) = D_0028E710;
    p[0x3382] = g_p1_score_panel_flags;
    p[0x3383] = g_p2_score_panel_flags;
    *(u16 *)(p + 0x3384) = g_hyper_text_anim_delay;
    *(u16 *)(p + 0x3386) = g_hyper_text_anim_frame;
    *(s32 *)(p + 0x3388) = g_hyper_text_anim_sprite;
    *(u16 *)(p + 0x338C) = g_maximum_text_anim_delay;
    *(u16 *)(p + 0x338E) = g_maximum_text_anim_frame;
    *(s32 *)(p + 0x3390) = g_maximum_text_anim_sprite;
    *(u16 *)(p + 0x3394) = g_max_level_display_timer;
    *(s32 *)(p + 0x3398) = g_score_scratch;
    *(u16 *)(p + 0x339C) = D_0028E6E4;
    *(u16 *)(p + 0x339E) = D_0028E6E0;
    *(u16 *)(p + 0x33A0) = g_max_combo_time;
    *(u16 *)(p + 0x33A2) = g_boss_hit_carry;
    *(u16 *)(p + 0x33A4) = D_0028E6D4;
    *(s32 *)(p + 0x33A8) = g_p1_chain_first_score;
    *(s32 *)(p + 0x33AC) = g_p1_chain_first_score_shown;
    *(u16 *)(p + 0x33B0) = g_p1_combo_timer;
    *(u16 *)(p + 0x33B2) = g_p1_chain_points_display_timer_as_u16;
    *(u16 *)(p + 0x33B4) = g_p1_hit_display_timer;
    *(u16 *)(p + 0x33B6) = g_p1_combo_break_color_timer;
    *(u16 *)(p + 0x33B8) = g_p1_hit10_display_timer_as_u16;
    *(u16 *)(p + 0x33BA) = g_p1_hit10_color_timer;
    *(u16 *)(p + 0x33BC) = g_p1_hit10_anim_count;
    *(s32 *)(p + 0x33C0) = g_p1_chain_points;
    *(s32 *)(p + 0x33C4) = g_p1_chain_points_shown;
    *(s32 *)(p + 0x33C8) = g_p1_chain_points_shown2;
    *(u16 *)(p + 0x33CC) = g_p1_hits;
    *(u16 *)(p + 0x33CE) = g_p1_hits_shown;
    *(u16 *)(p + 0x33D0) = g_p1_laser_hit_timer;
    *(u16 *)(p + 0x33D2) = g_p1_laser_hit_step;
    *(s32 *)(p + 0x33D4) = g_p2_chain_first_score;
    *(s32 *)(p + 0x33D8) = g_p2_chain_first_score_shown;
    *(u16 *)(p + 0x33DC) = g_p2_combo_timer;
    *(u16 *)(p + 0x33DE) = g_p2_chain_points_display_timer_as_u16;
    *(u16 *)(p + 0x33E0) = g_p2_hit_display_timer;
    *(u16 *)(p + 0x33E2) = g_p2_combo_break_color_timer;
    *(u16 *)(p + 0x33E4) = g_p2_hit10_display_timer_as_u16;
    *(u16 *)(p + 0x33E6) = g_p2_hit10_color_timer;
    *(u16 *)(p + 0x33E8) = g_p2_hit10_anim_count;
    *(s32 *)(p + 0x33EC) = g_p2_chain_points;
    *(s32 *)(p + 0x33F0) = g_p2_chain_points_shown;
    *(s32 *)(p + 0x33F4) = g_p2_chain_points_shown2;
    *(u16 *)(p + 0x33F8) = g_p2_hits;
    *(u16 *)(p + 0x33FA) = g_p2_hits_shown;
    *(u16 *)(p + 0x33FC) = g_p2_laser_hit_timer;
    *(u16 *)(p + 0x33FE) = g_p2_laser_hit_step;
    *(u16 *)(p + 0x3400) = g_boss_hit_decay_timer;
    *(u16 *)(p + 0x3402) = g_boss_hit_anim_count;
    *(u16 *)(p + 0x3404) = g_boss_hits;
    *(u16 *)(p + 0x3406) = g_boss_hit_palette_as_u16;
    *(u16 *)(p + 0x3408) = g_boss_hit_bonus_timer;
    *(s32 *)(p + 0x340C) = g_boss_hit_bonus;
    *(s32 *)(p + 0x3410) = g_boss_score;
    *(u16 *)(p + 0x3414) = g_boss_hp_bar_flags_as_u16;
    *(u16 *)(p + 0x3416) = g_boss_hp_bar_move_count;
    *(u16 *)(p + 0x3418) = g_lives_display_move_y;
    *(u16 *)(p + 0x341A) = g_lives_display_move_x;
    *(s32 *)(p + 0x341C) = g_boss_hp_unit;
    *(s32 *)(p + 0x3420) = g_boss_hp_as_s32;
    *(u16 *)(p + 0x3424) = g_boss_near_death;
    *(u16 *)(p + 0x3426) = g_boss_explosion_flash;
    *(u16 *)(p + 0x3428) = g_p1_max_hits;
    *(u16 *)(p + 0x342A) = g_p2_max_hits;
    *(u16 *)(p + 0x342C) = g_p1_laser_hyper_timer;
    *(u16 *)(p + 0x342E) = g_p2_laser_hyper_timer;
    *(u16 *)(p + 0x3430) = g_p1_shot_hyper_timer;
    *(u16 *)(p + 0x3432) = g_p2_shot_hyper_timer;
    *(u16 *)(p + 0x3434) = g_p1_hyper_active;
    *(u16 *)(p + 0x3436) = g_p2_hyper_active;
    *(u16 *)(p + 0x3438) = g_p1_hyper_time;
    *(u16 *)(p + 0x343A) = g_p2_hyper_time;
    *(u16 *)(p + 0x343C) = g_p1_hyper_total;
    *(u16 *)(p + 0x343E) = g_p2_hyper_total;
    *(u16 *)(p + 0x3440) = g_p1_hyper_gauge;
    *(u16 *)(p + 0x3442) = g_p2_hyper_gauge;
    *(u16 *)(p + 0x3444) = g_p1_hyper_combo_decay;
    *(u16 *)(p + 0x3446) = g_p2_hyper_combo_decay;
    *(u16 *)(p + 0x3448) = g_hyper_text_slide;
    *(u16 *)(p + 0x344A) = g_p1_hyper_level;
    *(u16 *)(p + 0x344C) = g_p2_hyper_level;
    *(u16 *)(p + 0x344E) = g_p1_hyper_in_effect;
    *(u16 *)(p + 0x3450) = g_p2_hyper_in_effect;
    *(u16 *)(p + 0x3452) = g_p1_hyper_items;
    *(u16 *)(p + 0x3454) = g_p2_hyper_items;
    for (i = 0; i < 16; i++) {
        buf->f3458[i] = D_002BAEF0[i];
    }
    for (i = 0; i < 16; i++) {
        buf->f3498[i] = D_002BAEB0[i];
    }
    *(u16 *)(p + 0x34D8) = g_p1_hyper_items_pending;
    *(u16 *)(p + 0x34DA) = g_p2_hyper_items_pending;
    *(u16 *)(p + 0x34DC) = g_boss_hyper_wait;
    *(u16 *)(p + 0x34DE) = g_hyper_hit_scratch;
    *(u16 *)(p + 0x34E0) = g_hyper_level_hit_scratch;
    *(u16 *)(p + 0x34E2) = g_boss_double_speed;
    *(u16 *)(p + 0x34E4) = D_0028E5A0;
    *(u16 *)(p + 0x34E6) = g_score_panel_intro;
    *(u16 *)(p + 0x34E8) = g_score_task_active;
    *(s32 *)(p + 0x34EC) = g_p1_hyper_effect_sprite;
    *(s32 *)(p + 0x34F0) = g_p2_hyper_effect_sprite;
    *(u16 *)(p + 0x34F4) = g_p1_hyper_effect_frame;
    *(u16 *)(p + 0x34F6) = g_p2_hyper_effect_frame;
    *(u16 *)(p + 0x34F8) = g_p1_hyper_effect_flag;
    *(u16 *)(p + 0x34FA) = g_p2_hyper_effect_flag;
    *(u16 *)(p + 0x34FC) = g_p1_hyper_effect_delay;
    *(u16 *)(p + 0x34FE) = g_p2_hyper_effect_delay;
    p[0x350C] = g_setting_difficulty;
    p[0x350D] = g_setting_extend;
    p[0x350E] = g_setting_ship_stock;
    p[0x350F] = D_0028E2EC;
    p[0x3510] = D_0028E304;
    *(u16 *)(p + 0x3500) = g_game_frame;
    *(u16 *)(p + 0x3502) = D_0028E3EC;
    *(u16 *)(p + 0x3504) = D_0028E3E8;
    *(u16 *)(p + 0x3506) = D_0028E3E4;
    *(u16 *)(p + 0x3508) = D_0028E3E0;
    *(u16 *)(p + 0x350A) = D_0028E3DC;
    *(Row16 *)(p + 0x5512) = *(Row16 *)D_0029C060_as_s16_a;
    for (i = 0; i < 0x2000; i++) {
        buf->f3511[i] = g_text_layer_as_s8_a[i];
    }
    p[0x5532] = D_0028E288;
    p[0x5533] = D_0028E284;
    D_006C58D6_as_s16_a[0] = MAIN_OR_DEATH_LABEL(0xCB, 0x6E);
    D_006C58AA_as_s16_a[0] = g_setting_difficulty;
    D_006C58C8_as_s16_a[0] = g_setting_extend;
    if (*(s16 *)g_player1_as_u8_a < 0) {
        D_006C58C6[0] = g_p1_lives;
    } else {
        D_006C58C6[0] = g_p2_lives;
    }
    D_006C58B8_as_s16_a[0] = 0;
    D_006C58C2_as_s16_a[0] = 1;
    D_006C58BA_as_s16_a[0] = 0;
#ifdef DEATH_LABEL
    D_006C58D4[0] = 0;
#endif
    D_006C58C0[0] = g_rank;
    if (*(s16 *)g_player1_as_u8_a < 0) {
#ifndef DEATH_LABEL
        D_006C58D4[0] = D_0028E02C;
        if (D_006C58D4[0] > 8) {
            D_006C58D4[0] = 8;
        }
#endif
        v = D_0029F280[0];
        if (v != 0) {
            v /= 2;
        }
        D_006C58B2[0] = v;
        v = D_0029F282[0];
        if (v != 0) {
            v /= 2;
        }
        D_006C58B0[0] = v;
        D_006C58D2[0] = g_p1_hyper_total;
        if (g_p1_hyper_gauge != 0) {
            v = (u16)g_p1_hyper_gauge * 100 / 2400;
        } else {
            v = MAIN_OR_DEATH_LABEL(0, 1);
        }
        v += g_p1_hyper_items_pending * 100;
        D_006C58BE[0] = v;
        if (g_p1_hyper_time != 0) {
            v = (u16)g_p1_hyper_time * 100 / 2400;
        } else {
            v = 0;
        }
        D_006C58CC_as_s16_a[0] = v;
        if (g_p1_hyper_in_effect != 0) {
            D_006C58CA_as_s16_a[0] = 1;
            D_006C58BC[0] = g_p1_hyper_level;
        } else {
            D_006C58CA_as_s16_a[0] = 0;
            D_006C58CC_as_s16_a[0] = 0;
            D_006C58BC[0] = g_p1_hyper_items;
        }
        D_006C58B4[0] = D_0029F284[0];
        if (D_006C58B4[0] != 0) {
            D_006C58B4[0] -= 1;
        }
        D_006C58B6_as_s16_a[0] = D_0029F285[0];
#ifdef DEATH_LABEL
        if (g_player1_as_u8_a[0] & 2) {
            D_006C58B6_as_s16_a[0] = 7;
        }
#else
        if ((g_player1_as_u8_a[0] & 2) && !(D_0029F261[0] & 0x40) && *(u16 *)D_0029CD90_as_f32_a != 0) {
            D_006C58B6_as_s16_a[0] = 7;
        }
        if (*(u8 *)g_player1_as_u8_a & 2) {
            printf(D_0028BF58);
        } else {
            printf(D_0028BF68);
        }
        if (D_0029F261[0] & 0x40) {
            printf(D_0028BF78);
        } else {
            printf(D_0028BF88);
        }
        printf(D_0028BF98, *(u16 *)D_0029CD90_as_f32_a);
#endif
        if (D_0029CD9C[0] != 0) {
            v = (u16)D_0029CD9C[0] - 1;
        } else {
            v = 0;
        }
        D_006C58D0_as_s16_a[0] = v;
        if (D_0028E074 != 0) {
            v = (u16)D_0028E074 / 4;
        } else {
            v = 0;
        }
        D_006C58CE_as_s16_a[0] = v;
    } else {
#ifndef DEATH_LABEL
        D_006C58D4[0] = D_0028E028;
        if (D_006C58D4[0] > 8) {
            D_006C58D4[0] = 8;
        }
#endif
        v = D_0029F210[0];
        if (v != 0) {
            v /= 2;
        }
        D_006C58B2[0] = v;
        v = D_0029F212[0];
        if (v != 0) {
            v /= 2;
        }
        D_006C58B0[0] = v;
        D_006C58D2[0] = g_p2_hyper_total;
        if (g_p2_hyper_gauge != 0) {
            v = (u16)g_p2_hyper_gauge * 100 / 2400;
        } else {
            v = MAIN_OR_DEATH_LABEL(0, 1);
        }
        v += g_p2_hyper_items_pending * 100;
        D_006C58BE[0] = v;
        if (g_p2_hyper_time != 0) {
            v = (u16)g_p2_hyper_time * 100 / 2400;
        } else {
            v = 0;
        }
        D_006C58CC_as_s16_a[0] = v;
        if (g_p2_hyper_in_effect != 0) {
            D_006C58CA_as_s16_a[0] = 1;
            D_006C58BC[0] = g_p2_hyper_level;
        } else {
            D_006C58CA_as_s16_a[0] = 0;
            D_006C58CC_as_s16_a[0] = 0;
            D_006C58BC[0] = g_p2_hyper_items;
        }
        D_006C58B4[0] = D_0029F214[0];
        if (D_006C58B4[0] != 0) {
            D_006C58B4[0] -= 1;
        }
        D_006C58B6_as_s16_a[0] = D_0029F215[0];
#ifdef DEATH_LABEL
        if (g_player2_as_u8_a[0] & 2) {
            D_006C58B6_as_s16_a[0] = 7;
        }
#else
        if ((g_player2_as_u8_a[0] & 2) && !(D_0029F1F1[0] & 0x40) && *(u16 *)D_0029CD80_as_f32_a != 0) {
            D_006C58B6_as_s16_a[0] = 7;
        }
        if (*(u8 *)g_player2_as_u8_a & 2) {
            printf(D_0028BF58);
        } else {
            printf(D_0028BF68);
        }
        if (D_0029F1F1[0] & 0x40) {
            printf(D_0028BF78);
        } else {
            printf(D_0028BF88);
        }
        printf(D_0028BF98, *(u16 *)D_0029CD80_as_f32_a);
#endif
        if (D_0029CD8C[0] != 0) {
            v = (u16)D_0029CD8C[0] - 1;
        } else {
            v = 0;
        }
        D_006C58D0_as_s16_a[0] = v;
        if (D_0028E070 != 0) {
            v = (u16)D_0028E070 / 4;
        } else {
            v = 0;
        }
        D_006C58CE_as_s16_a[0] = v;
    }
}

typedef struct {
    u8 pad[0x302C];
    s32 a[16];
    s32 b[16];
    s32 c[16];
    s32 d[16];
} QuadSrc;

typedef struct {
    u8 pad[0x3458];
    s32 a[16];
    s32 b[16];
} PairSrc;

typedef struct {
    u8 pad[0x5512];
    Row16 row;
} RowSrc;

extern u8 D_0029CD80_as_u8_a[];
extern u8 D_0029CD90_as_u8_a[];
void func_0023A490(u8 *p) {
    s32 i;

    for (i = 0; i < 0xC08; i++) {
        D_002BF4F0[i] = p[0x0 + i];
    }
    g_bullet_count = *(u16 *)(p + 0xC08);
    D_0028E984 = *(u16 *)(p + 0xC0A);
    D_0028E980 = *(u16 *)(p + 0xC0C);
    D_0028E97C = *(u16 *)(p + 0xC0E);
    D_0028E978 = *(u16 *)(p + 0xC10);
    D_0028E974 = *(u16 *)(p + 0xC12);
    D_0028E970 = *(u16 *)(p + 0xC14);
    for (i = 0; i < 98; i++) {
        g_player1_as_u8_a[i] = p[0xC16 + i];
        g_player2_as_u8_a[i] = p[0xC78 + i];
    }
    for (i = 0; i < 100; i++) {
        D_0029F180[i] = p[0xCDA + i];
        D_0029F110[i] = p[0xD3E + i];
    }
    for (i = 0; i < 0xD80; i++) {
        D_0029E390[i] = p[0xDA2 + i];
    }
    for (i = 0; i < 0x600; i++) {
        D_0029DD90[i] = p[0x1B22 + i];
        D_0029D790[i] = p[0x2122 + i];
    }
    for (i = 0; i < 0x20; i++) {
        D_0029D770[i] = p[0x2722 + i];
        D_0029D750[i] = p[0x2742 + i];
    }
    for (i = 0; i < 0x20; i++) {
        D_0029D730[i] = p[0x2762 + i];
        D_0029D710[i] = p[0x2782 + i];
    }
    for (i = 0; i < 0x870; i++) {
        D_0029CEA0_as_u8_a[i] = p[0x27A2 + i];
    }
    D_0028E088 = *(u16 *)(p + 0x301A);
    for (i = 0; i < 16; i++) {
        D_0029CE60[i] = ((QuadSrc *)p)->a[i];
        D_0029CE20_as_s32_a[i] = ((QuadSrc *)p)->b[i];
        D_0029CDE0[i] = ((QuadSrc *)p)->c[i];
        D_0029CDA0_as_s32_a[i] = ((QuadSrc *)p)->d[i];
    }
    D_0028E080_as_s32_a[0] = *(s32 *)(p + 0x301C);
    D_0028E078_as_s32_a[0] = *(s32 *)(p + 0x3024);
    D_0028E084_as_s32_a[0] = *(s32 *)(p + 0x3020);
    D_0028E07C_as_s32_a[0] = *(s32 *)(p + 0x3028);
    *(Vec4 *)D_0029CD90_as_u8_a = *(Vec4 *)(p + 0x312C);
    *(Vec4 *)D_0029CD80_as_u8_a = *(Vec4 *)(p + 0x313C);
    D_0028E074 = *(u16 *)(p + 0x314C);
    D_0028E070 = *(u16 *)(p + 0x314E);
    D_0028E06C = *(u16 *)(p + 0x3150);
    D_0028E068 = *(u16 *)(p + 0x3152);
    D_0028E064 = *(u16 *)(p + 0x3154);
    D_0028E060 = *(u16 *)(p + 0x3156);
    D_0028E05C = *(s32 *)(p + 0x3158);
    D_0028E058 = *(s32 *)(p + 0x315C);
    D_0028E054 = *(u16 *)(p + 0x3160);
    D_0028E050 = *(u16 *)(p + 0x3162);
    D_0028E044 = *(u16 *)(p + 0x3164);
    D_0028E040 = *(u16 *)(p + 0x3166);
    D_0028E03C = *(u16 *)(p + 0x3168);
    D_0028E038 = *(u16 *)(p + 0x316A);
    D_0028E034 = *(u16 *)(p + 0x316C);
    D_0028E030 = *(u16 *)(p + 0x316E);
    D_0028E02C = *(u16 *)(p + 0x3170);
    D_0028E028 = *(u16 *)(p + 0x3172);
    D_0028E024 = *(u16 *)(p + 0x3174);
    D_0028E020 = *(u16 *)(p + 0x3176);
    D_0028E01C = *(u16 *)(p + 0x3178);
    D_0028E018 = *(u16 *)(p + 0x317A);
    D_0028E014 = *(u16 *)(p + 0x317C);
    D_0028E010 = *(u16 *)(p + 0x317E);
    D_0028E00C = *(u16 *)(p + 0x3180);
    D_0028E008 = *(u16 *)(p + 0x3182);
    D_0028E004 = *(u16 *)(p + 0x3184);
    D_0028E000 = *(u16 *)(p + 0x3186);
    g_hyper_bullet_speed = *(u16 *)(p + 0x3188);
    D_0028DFF8 = *(u16 *)(p + 0x318A);
    D_0028DFF4 = *(s32 *)(p + 0x318C);
    D_0028DFF0 = *(u16 *)(p + 0x3190);
    D_0028DFEC = *(u16 *)(p + 0x3192);
    D_0028DFE8 = *(u16 *)(p + 0x3194);
    D_0028DFE4 = *(u16 *)(p + 0x3196);
    D_0028DFE0 = *(u16 *)(p + 0x3198);
    D_0028DFDC = *(u16 *)(p + 0x319A);
    D_0028DFD8 = *(u16 *)(p + 0x319C);
    D_0028DFD4 = *(u16 *)(p + 0x319E);
    D_0028DFD0 = *(u16 *)(p + 0x31A0);
    D_0028DFCC = *(u16 *)(p + 0x31A2);
    D_0028DFC8 = *(u16 *)(p + 0x31A4);
    D_0028DFC4 = *(u16 *)(p + 0x31A6);
    D_0028DFC0 = *(u16 *)(p + 0x31A8);
    D_0028DFBC = *(u16 *)(p + 0x31AA);
    D_0028DFB8 = *(u16 *)(p + 0x31AC);
    D_0028DFB4 = *(u16 *)(p + 0x31AE);
    g_two_player_game = *(u16 *)(p + 0x31B0);
    g_two_player_state = *(u16 *)(p + 0x31B2);
    g_two_player_seen = *(u16 *)(p + 0x31B4);
    g_stage = *(u16 *)(p + 0x31B6);
    g_stage_x2 = *(u16 *)(p + 0x31B8);
    g_stage_x4 = *(u16 *)(p + 0x31BA);
    g_loop = *(u16 *)(p + 0x31BC);
    g_game_completed = *(u16 *)(p + 0x31BE);
    g_true_last_boss = *(u16 *)(p + 0x31C0);
    g_rank = *(u16 *)(p + 0x31C2);
    g_rank_15_16 = *(u16 *)(p + 0x31C4);
    g_rank_14_16 = *(u16 *)(p + 0x31C6);
    g_rank_13_16 = *(u16 *)(p + 0x31C8);
    g_rank_12_16 = *(u16 *)(p + 0x31CA);
    g_rank_11_16 = *(u16 *)(p + 0x31CC);
    g_rank_10_16 = *(u16 *)(p + 0x31CE);
    g_rank_9_16 = *(u16 *)(p + 0x31D0);
    g_rank_8_16 = *(u16 *)(p + 0x31D2);
    g_rank_7_16 = *(u16 *)(p + 0x31D4);
    g_rank_6_16 = *(u16 *)(p + 0x31D6);
    g_rank_5_16 = *(u16 *)(p + 0x31D8);
    g_rank_4_16 = *(u16 *)(p + 0x31DA);
    g_rank_3_16 = *(u16 *)(p + 0x31DC);
    g_rank_2_16 = *(u16 *)(p + 0x31DE);
    g_rank_1_16 = *(u16 *)(p + 0x31E0);
    g_p1_lives = *(u16 *)(p + 0x31E2);
    g_p2_lives = *(u16 *)(p + 0x31E4);
    D_0028E8BC = *(s32 *)(p + 0x31E8);
    D_0028E8B8 = *(u16 *)(p + 0x31EC);
    D_0028E8B4 = p[0x31EE];
    D_0028E8B0 = p[0x31EF];
    g_scroll_line = *(u16 *)(p + 0x31F0);
    D_0028E8A4 = *(u16 *)(p + 0x31F2);
    D_0028E8AC = *(u16 *)(p + 0x31F4);
    g_enemy_signal_0 = *(u16 *)(p + 0x31FC);
    g_enemy_signal_1 = *(u16 *)(p + 0x31FE);
    g_enemy_signal_2 = *(u16 *)(p + 0x3200);
    g_enemy_signal_3 = *(u16 *)(p + 0x3202);
    g_enemy_signal_4 = *(u16 *)(p + 0x3204);
    g_enemy_signal_5 = *(u16 *)(p + 0x3206);
    g_enemy_signal_6 = *(u16 *)(p + 0x3208);
    g_enemy_signal_7 = *(u16 *)(p + 0x320A);
    g_enemy_signal_8 = *(u16 *)(p + 0x320C);
    g_enemy_signal_9 = *(u16 *)(p + 0x320E);
    g_enemy_signal_a = *(u16 *)(p + 0x3210);
    g_enemy_signal_b = *(u16 *)(p + 0x3212);
    g_enemy_signal_c = *(u16 *)(p + 0x3214);
    g_enemy_signal_d = *(u16 *)(p + 0x3216);
    g_enemy_signal_e = *(u16 *)(p + 0x3218);
    g_enemy_signal_f = *(u16 *)(p + 0x321A);
    D_0028E854_as_u16 = *(u16 *)(p + 0x321C);
    for (i = 0; i < 0x48; i++) {
        D_002BF390[i] = p[0x321E + i];
    }
    D_0028E850 = *(u16 *)(p + 0x3266);
    g_p1_score_as_s32 = *(s32 *)(p + 0x327C);
    g_p2_score_as_s32 = *(s32 *)(p + 0x3280);
    g_high_score = *(s32 *)(p + 0x3284);
    g_p1_score_billions = *(u16 *)(p + 0x3288);
    g_p2_score_billions = *(u16 *)(p + 0x328A);
    g_high_score_billions = *(u16 *)(p + 0x328C);
    g_p1_score_digits = *(u16 *)(p + 0x328E);
    g_high_score_digits = *(u16 *)(p + 0x3290);
    g_p2_score_digits = *(u16 *)(p + 0x3292);
    g_p1_score_saved_as_s32 = *(s32 *)(p + 0x3294);
    g_p2_score_saved_as_s32 = *(s32 *)(p + 0x3298);
    g_p1_score_billions_saved = *(u16 *)(p + 0x329C);
    g_p2_score_billions_saved = *(u16 *)(p + 0x329E);
    g_p1_extend_score = *(s32 *)(p + 0x32A0);
    g_p2_extend_score = *(s32 *)(p + 0x32A4);
    g_p1_extend_setting = *(u16 *)(p + 0x32A8);
    g_p2_extend_setting = *(u16 *)(p + 0x32AA);
    D_0028E71C = *(s32 *)(p + 0x32AC);
    D_0028E718 = *(s32 *)(p + 0x32B0);
    for (i = 0; i < 90; i++) {
        D_002BAF50_as_Bank90.a[i] = p[0x32B4 + i];
    }
    for (i = 0; i < 90; i++) {
        D_002BAF50_as_Bank90.b[i] = p[0x330E + i];
    }
    for (i = 0; i < 10; i++) {
        D_002BAF30_as_Bank10.a[i] = p[0x3368 + i];
    }
    for (i = 0; i < 10; i++) {
        D_002BAF30_as_Bank10.b[i] = p[0x3372 + i];
    }
    D_0028E714 = *(s32 *)(p + 0x337C);
    D_0028E710 = *(u16 *)(p + 0x3380);
    g_p1_score_panel_flags = p[0x3382];
    g_p2_score_panel_flags = p[0x3383];
    g_hyper_text_anim_delay = *(u16 *)(p + 0x3384);
    g_hyper_text_anim_frame = *(u16 *)(p + 0x3386);
    g_hyper_text_anim_sprite = *(s32 *)(p + 0x3388);
    g_maximum_text_anim_delay = *(u16 *)(p + 0x338C);
    g_maximum_text_anim_frame = *(u16 *)(p + 0x338E);
    g_maximum_text_anim_sprite = *(s32 *)(p + 0x3390);
    g_max_level_display_timer = *(u16 *)(p + 0x3394);
    g_score_scratch = *(s32 *)(p + 0x3398);
    D_0028E6E4 = *(u16 *)(p + 0x339C);
    D_0028E6E0 = *(u16 *)(p + 0x339E);
    g_max_combo_time = *(u16 *)(p + 0x33A0);
    g_boss_hit_carry = *(u16 *)(p + 0x33A2);
    D_0028E6D4 = *(u16 *)(p + 0x33A4);
    g_p1_chain_first_score = *(s32 *)(p + 0x33A8);
    g_p1_chain_first_score_shown = *(s32 *)(p + 0x33AC);
    g_p1_combo_timer = *(u16 *)(p + 0x33B0);
    g_p1_chain_points_display_timer_as_u16 = *(u16 *)(p + 0x33B2);
    g_p1_hit_display_timer = *(u16 *)(p + 0x33B4);
    g_p1_combo_break_color_timer = *(u16 *)(p + 0x33B6);
    g_p1_hit10_display_timer_as_u16 = *(u16 *)(p + 0x33B8);
    g_p1_hit10_color_timer = *(u16 *)(p + 0x33BA);
    g_p1_hit10_anim_count = *(u16 *)(p + 0x33BC);
    g_p1_chain_points = *(s32 *)(p + 0x33C0);
    g_p1_chain_points_shown = *(s32 *)(p + 0x33C4);
    g_p1_chain_points_shown2 = *(s32 *)(p + 0x33C8);
    g_p1_hits = *(u16 *)(p + 0x33CC);
    g_p1_hits_shown = *(u16 *)(p + 0x33CE);
    g_p1_laser_hit_timer = *(u16 *)(p + 0x33D0);
    g_p1_laser_hit_step = *(u16 *)(p + 0x33D2);
    g_p2_chain_first_score = *(s32 *)(p + 0x33D4);
    g_p2_chain_first_score_shown = *(s32 *)(p + 0x33D8);
    g_p2_combo_timer = *(u16 *)(p + 0x33DC);
    g_p2_chain_points_display_timer_as_u16 = *(u16 *)(p + 0x33DE);
    g_p2_hit_display_timer = *(u16 *)(p + 0x33E0);
    g_p2_combo_break_color_timer = *(u16 *)(p + 0x33E2);
    g_p2_hit10_display_timer_as_u16 = *(u16 *)(p + 0x33E4);
    g_p2_hit10_color_timer = *(u16 *)(p + 0x33E6);
    g_p2_hit10_anim_count = *(u16 *)(p + 0x33E8);
    g_p2_chain_points = *(s32 *)(p + 0x33EC);
    g_p2_chain_points_shown = *(s32 *)(p + 0x33F0);
    g_p2_chain_points_shown2 = *(s32 *)(p + 0x33F4);
    g_p2_hits = *(u16 *)(p + 0x33F8);
    g_p2_hits_shown = *(u16 *)(p + 0x33FA);
    g_p2_laser_hit_timer = *(u16 *)(p + 0x33FC);
    g_p2_laser_hit_step = *(u16 *)(p + 0x33FE);
    g_boss_hit_decay_timer = *(u16 *)(p + 0x3400);
    g_boss_hit_anim_count = *(u16 *)(p + 0x3402);
    g_boss_hits = *(u16 *)(p + 0x3404);
    g_boss_hit_palette_as_u16 = *(u16 *)(p + 0x3406);
    g_boss_hit_bonus_timer = *(u16 *)(p + 0x3408);
    g_boss_hit_bonus = *(s32 *)(p + 0x340C);
    g_boss_score = *(s32 *)(p + 0x3410);
    g_boss_hp_bar_flags_as_u16 = *(u16 *)(p + 0x3414);
    if (g_stage != 0) {
        g_boss_hp_bar_move_count = *(u16 *)(p + 0x3416);
    }
    g_lives_display_move_y = *(u16 *)(p + 0x3418);
    g_lives_display_move_x = *(u16 *)(p + 0x341A);
    g_boss_hp_unit = *(s32 *)(p + 0x341C);
    g_boss_hp_as_s32 = *(s32 *)(p + 0x3420);
    g_boss_near_death = *(u16 *)(p + 0x3424);
    g_boss_explosion_flash = *(u16 *)(p + 0x3426);
    g_p1_max_hits = *(u16 *)(p + 0x3428);
    g_p2_max_hits = *(u16 *)(p + 0x342A);
    g_p1_laser_hyper_timer = *(u16 *)(p + 0x342C);
    g_p2_laser_hyper_timer = *(u16 *)(p + 0x342E);
    g_p1_shot_hyper_timer = *(u16 *)(p + 0x3430);
    g_p2_shot_hyper_timer = *(u16 *)(p + 0x3432);
    g_p1_hyper_active = *(u16 *)(p + 0x3434);
    g_p2_hyper_active = *(u16 *)(p + 0x3436);
    g_p1_hyper_time = *(u16 *)(p + 0x3438);
    g_p2_hyper_time = *(u16 *)(p + 0x343A);
    g_p1_hyper_total = *(u16 *)(p + 0x343C);
    g_p2_hyper_total = *(u16 *)(p + 0x343E);
    g_p1_hyper_gauge = *(u16 *)(p + 0x3440);
    g_p2_hyper_gauge = *(u16 *)(p + 0x3442);
    g_p1_hyper_combo_decay = *(u16 *)(p + 0x3444);
    g_p2_hyper_combo_decay = *(u16 *)(p + 0x3446);
    g_hyper_text_slide = *(u16 *)(p + 0x3448);
    g_p1_hyper_level = *(u16 *)(p + 0x344A);
    g_p2_hyper_level = *(u16 *)(p + 0x344C);
    g_p1_hyper_in_effect = *(u16 *)(p + 0x344E);
    g_p2_hyper_in_effect = *(u16 *)(p + 0x3450);
    g_p1_hyper_items = *(u16 *)(p + 0x3452);
    g_p2_hyper_items = *(u16 *)(p + 0x3454);
    for (i = 0; i < 16; i++) {
        D_002BAEF0[i] = ((PairSrc *)p)->a[i];
    }
    for (i = 0; i < 16; i++) {
        D_002BAEB0[i] = ((PairSrc *)p)->b[i];
    }
    g_p1_hyper_items_pending = *(u16 *)(p + 0x34D8);
    g_p2_hyper_items_pending = *(u16 *)(p + 0x34DA);
    g_boss_hyper_wait = *(u16 *)(p + 0x34DC);
    g_hyper_hit_scratch = *(u16 *)(p + 0x34DE);
    g_hyper_level_hit_scratch = *(u16 *)(p + 0x34E0);
    g_boss_double_speed = *(u16 *)(p + 0x34E2);
    D_0028E5A0 = *(u16 *)(p + 0x34E4);
    g_score_panel_intro = *(u16 *)(p + 0x34E6);
    g_score_task_active = *(u16 *)(p + 0x34E8);
    g_p1_hyper_effect_sprite = *(s32 *)(p + 0x34EC);
    g_p2_hyper_effect_sprite = *(s32 *)(p + 0x34F0);
    g_p1_hyper_effect_frame = *(u16 *)(p + 0x34F4);
    g_p2_hyper_effect_frame = *(u16 *)(p + 0x34F6);
    g_p1_hyper_effect_flag = *(u16 *)(p + 0x34F8);
    g_p2_hyper_effect_flag = *(u16 *)(p + 0x34FA);
    g_p1_hyper_effect_delay = *(u16 *)(p + 0x34FC);
    g_p2_hyper_effect_delay = *(u16 *)(p + 0x34FE);
    g_setting_difficulty = p[0x350C];
    g_setting_extend = p[0x350D];
    g_setting_ship_stock = p[0x350E];
    D_0028E2EC = p[0x350F];
    D_0028E304 = p[0x3510];
    g_game_frame = *(u16 *)(p + 0x3500);
    D_0028E3EC = *(u16 *)(p + 0x3502);
    D_0028E3E8 = *(u16 *)(p + 0x3504);
    D_0028E3E4 = *(u16 *)(p + 0x3506);
    D_0028E3E0 = *(u16 *)(p + 0x3508);
    D_0028E3DC = *(u16 *)(p + 0x350A);
    *(Row16 *)D_0029C060_as_s16_a = ((RowSrc *)p)->row;
    D_0028E288 = p[0x5532];
    D_0028E284 = p[0x5533];
    func_0023B6B0((const Src *)p);
}

extern s8 g_text_layer_as_s8_a0x2000[0x2000];

void func_0023B6B0(const Src *src) {
    s32 i;
    for (i = 0; i < 0x2000; i++) {
        g_text_layer_as_s8_a0x2000[i] = src->data[i];
    }
}

extern void func_00125DE0(void);
extern void func_00128660(void);
extern void func_00135ED0(void);
extern void func_001368C0(void);
extern void func_00139EB0(void);
extern void func_0013FD80(void);
extern void func_0014D260(void);
extern void func_0016AAB0(void);
extern void func_001AACC0(void);
extern void func_001AE490(void);
extern void func_001B82D0(void);
extern void func_00209E60(void);
extern void func_002114A0(void);
void func_0023B720(u8 *p) {
    s32 i;

    func_0014D260();
    func_00139EB0();
    func_001B82D0();
    func_002114A0();
    func_001368C0();
    func_00209E60();
    func_0016AAB0();
    func_00128660();
    func_00135ED0();
    func_00125DE0();
    func_001AE490();
    func_001AACC0();
    func_0013FD80();
    D_0028E984 = *(u16 *)(p + 0x0);
    D_0028E980 = *(u16 *)(p + 0x2);
    D_0028E97C = *(u16 *)(p + 0x4);
    D_0028E978 = *(u16 *)(p + 0x6);
    D_0028E974 = *(u16 *)(p + 0x8);
    D_0028E970 = *(u16 *)(p + 0xA);
    for (i = 0; i < 98; i++) {
        g_player1_as_u8_a[i] = p[12 + i];
        g_player2_as_u8_a[i] = p[110 + i];
    }
    *(Vec4 *)D_0029CD90_as_u8_a = *(Vec4 *)(p + 0xD0);
    *(Vec4 *)D_0029CD80_as_u8_a = *(Vec4 *)(p + 0xE0);
    D_0028E074 = *(u16 *)(p + 0xF0);
    D_0028E070 = *(u16 *)(p + 0xF2);
    D_0028E06C = *(u16 *)(p + 0xF4);
    D_0028E068 = *(u16 *)(p + 0xF6);
    D_0028E064 = *(u16 *)(p + 0xF8);
    D_0028E060 = *(u16 *)(p + 0xFA);
    D_0028E05C = *(s32 *)(p + 0xFC);
    D_0028E058 = *(s32 *)(p + 0x100);
    D_0028E054 = *(u16 *)(p + 0x104);
    D_0028E050 = *(u16 *)(p + 0x106);
    D_0028E044 = *(u16 *)(p + 0x108);
    D_0028E040 = *(u16 *)(p + 0x10A);
    D_0028E03C = *(u16 *)(p + 0x10C);
    D_0028E038 = *(u16 *)(p + 0x10E);
    D_0028E034 = *(u16 *)(p + 0x110);
    D_0028E030 = *(u16 *)(p + 0x112);
    D_0028E02C = *(u16 *)(p + 0x114);
    D_0028E028 = *(u16 *)(p + 0x116);
    D_0028E024 = *(u16 *)(p + 0x118);
    D_0028E020 = *(u16 *)(p + 0x11A);
    D_0028E01C = *(u16 *)(p + 0x11C);
    D_0028E018 = *(u16 *)(p + 0x11E);
    D_0028E014 = *(u16 *)(p + 0x120);
    D_0028E010 = *(u16 *)(p + 0x122);
    D_0028E00C = *(u16 *)(p + 0x124);
    D_0028E008 = *(u16 *)(p + 0x126);
    D_0028E004 = *(u16 *)(p + 0x128);
    D_0028E000 = *(u16 *)(p + 0x12A);
    g_hyper_bullet_speed = *(u16 *)(p + 0x12C);
    D_0028DFF8 = *(u16 *)(p + 0x12E);
    D_0028DFF0 = *(u16 *)(p + 0x130);
    D_0028DFEC = *(u16 *)(p + 0x132);
    D_0028DFE8 = *(u16 *)(p + 0x134);
    D_0028DFE4 = *(u16 *)(p + 0x136);
    D_0028DFE0 = *(u16 *)(p + 0x138);
    D_0028DFDC = *(u16 *)(p + 0x13A);
    D_0028DFD8 = *(u16 *)(p + 0x13C);
    D_0028DFD4 = *(u16 *)(p + 0x13E);
    D_0028DFD0 = *(u16 *)(p + 0x140);
    D_0028DFCC = *(u16 *)(p + 0x142);
    D_0028DFC8 = *(u16 *)(p + 0x144);
    D_0028DFC4 = *(u16 *)(p + 0x146);
    D_0028DFC0 = *(u16 *)(p + 0x148);
    D_0028DFBC = *(u16 *)(p + 0x14A);
    D_0028DFB8 = *(u16 *)(p + 0x14C);
    D_0028DFB4 = *(u16 *)(p + 0x14E);
    g_two_player_game = *(u16 *)(p + 0x150);
    g_two_player_state = *(u16 *)(p + 0x152);
    g_two_player_seen = *(u16 *)(p + 0x154);
    g_stage = *(u16 *)(p + 0x156);
    g_stage_x2 = *(u16 *)(p + 0x158);
    g_stage_x4 = *(u16 *)(p + 0x15A);
    g_loop = *(u16 *)(p + 0x15C);
    g_game_completed = *(u16 *)(p + 0x15E);
    g_true_last_boss = *(u16 *)(p + 0x160);
    g_rank = *(u16 *)(p + 0x162);
    g_rank_15_16 = *(u16 *)(p + 0x164);
    g_rank_14_16 = *(u16 *)(p + 0x166);
    g_rank_13_16 = *(u16 *)(p + 0x168);
    g_rank_12_16 = *(u16 *)(p + 0x16A);
    g_rank_11_16 = *(u16 *)(p + 0x16C);
    g_rank_10_16 = *(u16 *)(p + 0x16E);
    g_rank_9_16 = *(u16 *)(p + 0x170);
    g_rank_8_16 = *(u16 *)(p + 0x172);
    g_rank_7_16 = *(u16 *)(p + 0x174);
    g_rank_6_16 = *(u16 *)(p + 0x176);
    g_rank_5_16 = *(u16 *)(p + 0x178);
    g_rank_4_16 = *(u16 *)(p + 0x17A);
    g_rank_3_16 = *(u16 *)(p + 0x17C);
    g_rank_2_16 = *(u16 *)(p + 0x17E);
    g_rank_1_16 = *(u16 *)(p + 0x180);
    g_p1_lives = *(u16 *)(p + 0x182);
    g_p2_lives = *(u16 *)(p + 0x184);
    D_0028E8BC = *(s32 *)(p + 0x188);
    D_0028E8B8 = *(u16 *)(p + 0x18C);
    D_0028E8B4 = p[0x18E];
    D_0028E8B0 = p[0x18F];
    g_enemy_signal_0 = *(u16 *)(p + 0x190);
    g_enemy_signal_1 = *(u16 *)(p + 0x192);
    g_enemy_signal_2 = *(u16 *)(p + 0x194);
    g_enemy_signal_3 = *(u16 *)(p + 0x196);
    g_enemy_signal_4 = *(u16 *)(p + 0x198);
    g_enemy_signal_5 = *(u16 *)(p + 0x19A);
    g_enemy_signal_6 = *(u16 *)(p + 0x19C);
    g_enemy_signal_7 = *(u16 *)(p + 0x19E);
    g_enemy_signal_8 = *(u16 *)(p + 0x1A0);
    g_enemy_signal_9 = *(u16 *)(p + 0x1A2);
    g_enemy_signal_a = *(u16 *)(p + 0x1A4);
    g_enemy_signal_b = *(u16 *)(p + 0x1A6);
    g_enemy_signal_c = *(u16 *)(p + 0x1A8);
    g_enemy_signal_d = *(u16 *)(p + 0x1AA);
    g_enemy_signal_e = *(u16 *)(p + 0x1AC);
    g_enemy_signal_f = *(u16 *)(p + 0x1AE);
    D_0028E854_as_u16 = *(u16 *)(p + 0x1B0);
    g_p1_score_as_s32 = *(s32 *)(p + 0x1B4);
    g_p2_score_as_s32 = *(s32 *)(p + 0x1B8);
    g_high_score = *(s32 *)(p + 0x1BC);
    g_p1_score_billions = *(u16 *)(p + 0x1C0);
    g_p2_score_billions = *(u16 *)(p + 0x1C2);
    g_high_score_billions = *(u16 *)(p + 0x1C4);
    g_p1_score_digits = *(u16 *)(p + 0x1C6);
    g_high_score_digits = *(u16 *)(p + 0x1C8);
    g_p2_score_digits = *(u16 *)(p + 0x1CA);
    g_p1_score_saved_as_s32 = *(s32 *)(p + 0x1CC);
    g_p2_score_saved_as_s32 = *(s32 *)(p + 0x1D0);
    g_p1_score_billions_saved = *(u16 *)(p + 0x1D4);
    g_p2_score_billions_saved = *(u16 *)(p + 0x1D6);
    g_p1_extend_score = *(s32 *)(p + 0x1D8);
    g_p2_extend_score = *(s32 *)(p + 0x1DC);
    g_p1_extend_setting = *(u16 *)(p + 0x1E0);
    g_p2_extend_setting = *(u16 *)(p + 0x1E2);
    D_0028E71C = *(s32 *)(p + 0x1E4);
    D_0028E718 = *(s32 *)(p + 0x1E8);
    for (i = 0; i < 90; i++) {
        D_002BAF50_as_Bank90.a[i] = p[0x1EC + i];
    }
    for (i = 0; i < 90; i++) {
        D_002BAF50_as_Bank90.b[i] = p[0x246 + i];
    }
    for (i = 0; i < 10; i++) {
        D_002BAF30_as_Bank10.a[i] = p[0x2A0 + i];
    }
    for (i = 0; i < 10; i++) {
        D_002BAF30_as_Bank10.b[i] = p[0x2AA + i];
    }
    D_0028E714 = *(s32 *)(p + 0x2B4);
    D_0028E710 = *(u16 *)(p + 0x2B8);
    g_p1_score_panel_flags = p[0x2BA];
    g_p2_score_panel_flags = p[0x2BB];
    g_hyper_text_anim_delay = *(u16 *)(p + 0x2BC);
    g_hyper_text_anim_frame = *(u16 *)(p + 0x2BE);
    g_hyper_text_anim_sprite = *(s32 *)(p + 0x2C0);
    g_maximum_text_anim_delay = *(u16 *)(p + 0x2C4);
    g_maximum_text_anim_frame = *(u16 *)(p + 0x2C6);
    g_maximum_text_anim_sprite = *(s32 *)(p + 0x2C8);
    g_max_level_display_timer = *(u16 *)(p + 0x2CC);
    g_score_scratch = *(s32 *)(p + 0x2D0);
    D_0028E6E4 = *(u16 *)(p + 0x2D4);
    D_0028E6E0 = *(u16 *)(p + 0x2D6);
    g_max_combo_time = *(u16 *)(p + 0x2D8);
    g_boss_hit_carry = *(u16 *)(p + 0x2DA);
    D_0028E6D4 = *(u16 *)(p + 0x2DC);
    g_p1_chain_first_score = *(s32 *)(p + 0x2E0);
    g_p1_chain_first_score_shown = *(s32 *)(p + 0x2E4);
    g_p1_combo_timer = *(u16 *)(p + 0x2E8);
    g_p1_chain_points_display_timer_as_u16 = *(u16 *)(p + 0x2EA);
    g_p1_hit_display_timer = *(u16 *)(p + 0x2EC);
    g_p1_combo_break_color_timer = *(u16 *)(p + 0x2EE);
    g_p1_hit10_display_timer_as_u16 = *(u16 *)(p + 0x2F0);
    g_p1_hit10_color_timer = *(u16 *)(p + 0x2F2);
    g_p1_hit10_anim_count = *(u16 *)(p + 0x2F4);
    g_p1_chain_points = *(s32 *)(p + 0x2F8);
    g_p1_chain_points_shown = *(s32 *)(p + 0x2FC);
    g_p1_chain_points_shown2 = *(s32 *)(p + 0x300);
    g_p1_hits = *(u16 *)(p + 0x304);
    g_p1_hits_shown = *(u16 *)(p + 0x306);
    g_p1_laser_hit_timer = *(u16 *)(p + 0x308);
    g_p1_laser_hit_step = *(u16 *)(p + 0x30A);
    g_p2_chain_first_score = *(s32 *)(p + 0x30C);
    g_p2_chain_first_score_shown = *(s32 *)(p + 0x310);
    g_p2_combo_timer = *(u16 *)(p + 0x314);
    g_p2_chain_points_display_timer_as_u16 = *(u16 *)(p + 0x316);
    g_p2_hit_display_timer = *(u16 *)(p + 0x318);
    g_p2_combo_break_color_timer = *(u16 *)(p + 0x31A);
    g_p2_hit10_display_timer_as_u16 = *(u16 *)(p + 0x31C);
    g_p2_hit10_color_timer = *(u16 *)(p + 0x31E);
    g_p2_hit10_anim_count = *(u16 *)(p + 0x320);
    g_p2_chain_points = *(s32 *)(p + 0x324);
    g_p2_chain_points_shown = *(s32 *)(p + 0x328);
    g_p2_chain_points_shown2 = *(s32 *)(p + 0x32C);
    g_p2_hits = *(u16 *)(p + 0x330);
    g_p2_hits_shown = *(u16 *)(p + 0x332);
    g_p2_laser_hit_timer = *(u16 *)(p + 0x334);
    g_p2_laser_hit_step = *(u16 *)(p + 0x336);
    g_boss_hit_decay_timer = *(u16 *)(p + 0x338);
    g_boss_hit_anim_count = *(u16 *)(p + 0x33A);
    g_boss_hits = *(u16 *)(p + 0x33C);
    g_boss_hit_palette_as_u16 = *(u16 *)(p + 0x33E);
    g_boss_hit_bonus_timer = *(u16 *)(p + 0x340);
    g_boss_hit_bonus = *(s32 *)(p + 0x344);
    g_boss_score = *(s32 *)(p + 0x348);
    g_boss_hp_bar_flags_as_u16 = *(u16 *)(p + 0x34C);
    g_p1_max_hits = *(u16 *)(p + 0x34E);
    g_p2_max_hits = *(u16 *)(p + 0x350);
    g_p1_laser_hyper_timer = *(u16 *)(p + 0x352);
    g_p2_laser_hyper_timer = *(u16 *)(p + 0x354);
    g_p1_shot_hyper_timer = *(u16 *)(p + 0x356);
    g_p2_shot_hyper_timer = *(u16 *)(p + 0x358);
    g_p1_hyper_active = *(u16 *)(p + 0x35A);
    g_p2_hyper_active = *(u16 *)(p + 0x35C);
    g_p1_hyper_time = *(u16 *)(p + 0x35E);
    g_p2_hyper_time = *(u16 *)(p + 0x360);
    g_p1_hyper_total = *(u16 *)(p + 0x362);
    g_p2_hyper_total = *(u16 *)(p + 0x364);
    g_p1_hyper_gauge = *(u16 *)(p + 0x366);
    g_p2_hyper_gauge = *(u16 *)(p + 0x368);
    g_p1_hyper_combo_decay = *(u16 *)(p + 0x36A);
    g_p2_hyper_combo_decay = *(u16 *)(p + 0x36C);
    g_hyper_text_slide = *(u16 *)(p + 0x36E);
    g_p1_hyper_level = *(u16 *)(p + 0x370);
    g_p2_hyper_level = *(u16 *)(p + 0x372);
    g_p1_hyper_in_effect = *(u16 *)(p + 0x374);
    g_p2_hyper_in_effect = *(u16 *)(p + 0x376);
    g_p1_hyper_items = *(u16 *)(p + 0x378);
    g_p2_hyper_items = *(u16 *)(p + 0x37A);
    g_p1_hyper_items_pending = *(u16 *)(p + 0x37C);
    g_p2_hyper_items_pending = *(u16 *)(p + 0x37E);
    g_boss_hyper_wait = *(u16 *)(p + 0x380);
    g_hyper_hit_scratch = *(u16 *)(p + 0x382);
    g_hyper_level_hit_scratch = *(u16 *)(p + 0x384);
    g_boss_double_speed = *(u16 *)(p + 0x386);
    D_0028E5A0 = *(u16 *)(p + 0x388);
    g_score_panel_intro = *(u16 *)(p + 0x38A);
    g_score_task_active = *(u16 *)(p + 0x38C);
    g_p1_hyper_effect_sprite = *(s32 *)(p + 0x390);
    g_p2_hyper_effect_sprite = *(s32 *)(p + 0x394);
    g_p1_hyper_effect_frame = *(u16 *)(p + 0x398);
    g_p2_hyper_effect_frame = *(u16 *)(p + 0x39A);
    g_p1_hyper_effect_flag = *(u16 *)(p + 0x39C);
    g_p2_hyper_effect_flag = *(u16 *)(p + 0x39E);
    g_p1_hyper_effect_delay = *(u16 *)(p + 0x3A0);
    g_p2_hyper_effect_delay = *(u16 *)(p + 0x3A2);
}

typedef struct {
    u8 pad0[0x1EC];
    u8 a[90];
    u8 b[90];
    u8 c[10];
    u8 d[10];
} Buf2;

void func_0023C1E0(Buf2 *buf) {
    s32 i;
    u8 *p = (u8 *)buf;

    *(u16 *)(p + 0x0) = D_0028E984;
    *(u16 *)(p + 0x2) = D_0028E980;
    *(u16 *)(p + 0x4) = D_0028E97C;
    *(u16 *)(p + 0x6) = D_0028E978;
    *(u16 *)(p + 0x8) = D_0028E974;
    *(u16 *)(p + 0xA) = D_0028E970;
    for (i = 0; i < 98; i++) {
        p[12 + i] = g_player1_as_u8_a[i];
        p[110 + i] = g_player2_as_u8_a[i];
    }
    *(Vec4 *)(p + 0xD0) = *(Vec4 *)D_0029CD90_as_u8_a;
    *(Vec4 *)(p + 0xE0) = *(Vec4 *)D_0029CD80_as_u8_a;
    *(u16 *)(p + 0xF0) = D_0028E074;
    *(u16 *)(p + 0xF2) = D_0028E070;
    *(u16 *)(p + 0xF4) = D_0028E06C;
    *(u16 *)(p + 0xF6) = D_0028E068;
    *(u16 *)(p + 0xF8) = D_0028E064;
    *(u16 *)(p + 0xFA) = D_0028E060;
    *(s32 *)(p + 0xFC) = D_0028E05C;
    *(s32 *)(p + 0x100) = D_0028E058;
    *(u16 *)(p + 0x104) = D_0028E054;
    *(u16 *)(p + 0x106) = D_0028E050;
    *(u16 *)(p + 0x108) = D_0028E044;
    *(u16 *)(p + 0x10A) = D_0028E040;
    *(u16 *)(p + 0x10C) = D_0028E03C;
    *(u16 *)(p + 0x10E) = D_0028E038;
    *(u16 *)(p + 0x110) = D_0028E034;
    *(u16 *)(p + 0x112) = D_0028E030;
    *(u16 *)(p + 0x114) = D_0028E02C;
    *(u16 *)(p + 0x116) = D_0028E028;
    *(u16 *)(p + 0x118) = D_0028E024;
    *(u16 *)(p + 0x11A) = D_0028E020;
    *(u16 *)(p + 0x11C) = D_0028E01C;
    *(u16 *)(p + 0x11E) = D_0028E018;
    *(u16 *)(p + 0x120) = D_0028E014;
    *(u16 *)(p + 0x122) = D_0028E010;
    *(u16 *)(p + 0x124) = D_0028E00C;
    *(u16 *)(p + 0x126) = D_0028E008;
    *(u16 *)(p + 0x128) = D_0028E004;
    *(u16 *)(p + 0x12A) = D_0028E000;
    *(u16 *)(p + 0x12C) = g_hyper_bullet_speed;
    *(u16 *)(p + 0x12E) = D_0028DFF8;
    *(u16 *)(p + 0x130) = D_0028DFF0;
    *(u16 *)(p + 0x132) = D_0028DFEC;
    *(u16 *)(p + 0x134) = D_0028DFE8;
    *(u16 *)(p + 0x136) = D_0028DFE4;
    *(u16 *)(p + 0x138) = D_0028DFE0;
    *(u16 *)(p + 0x13A) = D_0028DFDC;
    *(u16 *)(p + 0x13C) = D_0028DFD8;
    *(u16 *)(p + 0x13E) = D_0028DFD4;
    *(u16 *)(p + 0x140) = D_0028DFD0;
    *(u16 *)(p + 0x142) = D_0028DFCC;
    *(u16 *)(p + 0x144) = D_0028DFC8;
    *(u16 *)(p + 0x146) = D_0028DFC4;
    *(u16 *)(p + 0x148) = D_0028DFC0;
    *(u16 *)(p + 0x14A) = D_0028DFBC;
    *(u16 *)(p + 0x14C) = D_0028DFB8;
    *(u16 *)(p + 0x14E) = D_0028DFB4;
    *(u16 *)(p + 0x150) = g_two_player_game;
    *(u16 *)(p + 0x152) = g_two_player_state;
    *(u16 *)(p + 0x154) = g_two_player_seen;
    *(u16 *)(p + 0x156) = g_stage;
    *(u16 *)(p + 0x158) = g_stage_x2;
    *(u16 *)(p + 0x15A) = g_stage_x4;
    *(u16 *)(p + 0x15C) = g_loop;
    *(u16 *)(p + 0x15E) = g_game_completed;
    *(u16 *)(p + 0x160) = g_true_last_boss;
    *(u16 *)(p + 0x162) = g_rank;
    *(u16 *)(p + 0x164) = g_rank_15_16;
    *(u16 *)(p + 0x166) = g_rank_14_16;
    *(u16 *)(p + 0x168) = g_rank_13_16;
    *(u16 *)(p + 0x16A) = g_rank_12_16;
    *(u16 *)(p + 0x16C) = g_rank_11_16;
    *(u16 *)(p + 0x16E) = g_rank_10_16;
    *(u16 *)(p + 0x170) = g_rank_9_16;
    *(u16 *)(p + 0x172) = g_rank_8_16;
    *(u16 *)(p + 0x174) = g_rank_7_16;
    *(u16 *)(p + 0x176) = g_rank_6_16;
    *(u16 *)(p + 0x178) = g_rank_5_16;
    *(u16 *)(p + 0x17A) = g_rank_4_16;
    *(u16 *)(p + 0x17C) = g_rank_3_16;
    *(u16 *)(p + 0x17E) = g_rank_2_16;
    *(u16 *)(p + 0x180) = g_rank_1_16;
    *(u16 *)(p + 0x182) = g_p1_lives;
    *(u16 *)(p + 0x184) = g_p2_lives;
    *(s32 *)(p + 0x188) = D_0028E8BC;
    *(u16 *)(p + 0x18C) = D_0028E8B8;
    p[0x18E] = D_0028E8B4;
    p[0x18F] = D_0028E8B0;
    *(u16 *)(p + 0x190) = g_enemy_signal_0;
    *(u16 *)(p + 0x192) = g_enemy_signal_1;
    *(u16 *)(p + 0x194) = g_enemy_signal_2;
    *(u16 *)(p + 0x196) = g_enemy_signal_3;
    *(u16 *)(p + 0x198) = g_enemy_signal_4;
    *(u16 *)(p + 0x19A) = g_enemy_signal_5;
    *(u16 *)(p + 0x19C) = g_enemy_signal_6;
    *(u16 *)(p + 0x19E) = g_enemy_signal_7;
    *(u16 *)(p + 0x1A0) = g_enemy_signal_8;
    *(u16 *)(p + 0x1A2) = g_enemy_signal_9;
    *(u16 *)(p + 0x1A4) = g_enemy_signal_a;
    *(u16 *)(p + 0x1A6) = g_enemy_signal_b;
    *(u16 *)(p + 0x1A8) = g_enemy_signal_c;
    *(u16 *)(p + 0x1AA) = g_enemy_signal_d;
    *(u16 *)(p + 0x1AC) = g_enemy_signal_e;
    *(u16 *)(p + 0x1AE) = g_enemy_signal_f;
    *(u16 *)(p + 0x1B0) = D_0028E854_as_u16;
    *(s32 *)(p + 0x1B4) = g_p1_score_as_s32;
    *(s32 *)(p + 0x1B8) = g_p2_score_as_s32;
    *(s32 *)(p + 0x1BC) = g_high_score;
    *(u16 *)(p + 0x1C0) = g_p1_score_billions;
    *(u16 *)(p + 0x1C2) = g_p2_score_billions;
    *(u16 *)(p + 0x1C4) = g_high_score_billions;
    *(u16 *)(p + 0x1C6) = g_p1_score_digits;
    *(u16 *)(p + 0x1C8) = g_high_score_digits;
    *(u16 *)(p + 0x1CA) = g_p2_score_digits;
    *(s32 *)(p + 0x1CC) = g_p1_score_saved_as_s32;
    *(s32 *)(p + 0x1D0) = g_p2_score_saved_as_s32;
    *(u16 *)(p + 0x1D4) = g_p1_score_billions_saved;
    *(u16 *)(p + 0x1D6) = g_p2_score_billions_saved;
    *(s32 *)(p + 0x1D8) = g_p1_extend_score;
    *(s32 *)(p + 0x1DC) = g_p2_extend_score;
    *(u16 *)(p + 0x1E0) = g_p1_extend_setting;
    *(u16 *)(p + 0x1E2) = g_p2_extend_setting;
    *(s32 *)(p + 0x1E4) = D_0028E71C;
    *(s32 *)(p + 0x1E8) = D_0028E718;
    for (i = 0; i < 90; i++) {
        buf->a[i] = D_002BAF50_as_Bank90.a[i];
    }
    for (i = 0; i < 90; i++) {
        buf->b[i] = D_002BAF50_as_Bank90.b[i];
    }
    for (i = 0; i < 10; i++) {
        buf->c[i] = D_002BAF30_as_Bank10.a[i];
    }
    for (i = 0; i < 10; i++) {
        buf->d[i] = D_002BAF30_as_Bank10.b[i];
    }
    *(s32 *)(p + 0x2B4) = D_0028E714;
    *(u16 *)(p + 0x2B8) = D_0028E710;
    p[0x2BA] = g_p1_score_panel_flags;
    p[0x2BB] = g_p2_score_panel_flags;
    *(u16 *)(p + 0x2BC) = g_hyper_text_anim_delay;
    *(u16 *)(p + 0x2BE) = g_hyper_text_anim_frame;
    *(s32 *)(p + 0x2C0) = g_hyper_text_anim_sprite;
    *(u16 *)(p + 0x2C4) = g_maximum_text_anim_delay;
    *(u16 *)(p + 0x2C6) = g_maximum_text_anim_frame;
    *(s32 *)(p + 0x2C8) = g_maximum_text_anim_sprite;
    *(u16 *)(p + 0x2CC) = g_max_level_display_timer;
    *(s32 *)(p + 0x2D0) = g_score_scratch;
    *(u16 *)(p + 0x2D4) = D_0028E6E4;
    *(u16 *)(p + 0x2D6) = D_0028E6E0;
    *(u16 *)(p + 0x2D8) = g_max_combo_time;
    *(u16 *)(p + 0x2DA) = g_boss_hit_carry;
    *(u16 *)(p + 0x2DC) = D_0028E6D4;
    *(s32 *)(p + 0x2E0) = g_p1_chain_first_score;
    *(s32 *)(p + 0x2E4) = g_p1_chain_first_score_shown;
    *(u16 *)(p + 0x2E8) = g_p1_combo_timer;
    *(u16 *)(p + 0x2EA) = g_p1_chain_points_display_timer_as_u16;
    *(u16 *)(p + 0x2EC) = g_p1_hit_display_timer;
    *(u16 *)(p + 0x2EE) = g_p1_combo_break_color_timer;
    *(u16 *)(p + 0x2F0) = g_p1_hit10_display_timer_as_u16;
    *(u16 *)(p + 0x2F2) = g_p1_hit10_color_timer;
    *(u16 *)(p + 0x2F4) = g_p1_hit10_anim_count;
    *(s32 *)(p + 0x2F8) = g_p1_chain_points;
    *(s32 *)(p + 0x2FC) = g_p1_chain_points_shown;
    *(s32 *)(p + 0x300) = g_p1_chain_points_shown2;
    *(u16 *)(p + 0x304) = g_p1_hits;
    *(u16 *)(p + 0x306) = g_p1_hits_shown;
    *(u16 *)(p + 0x308) = g_p1_laser_hit_timer;
    *(u16 *)(p + 0x30A) = g_p1_laser_hit_step;
    *(s32 *)(p + 0x30C) = g_p2_chain_first_score;
    *(s32 *)(p + 0x310) = g_p2_chain_first_score_shown;
    *(u16 *)(p + 0x314) = g_p2_combo_timer;
    *(u16 *)(p + 0x316) = g_p2_chain_points_display_timer_as_u16;
    *(u16 *)(p + 0x318) = g_p2_hit_display_timer;
    *(u16 *)(p + 0x31A) = g_p2_combo_break_color_timer;
    *(u16 *)(p + 0x31C) = g_p2_hit10_display_timer_as_u16;
    *(u16 *)(p + 0x31E) = g_p2_hit10_color_timer;
    *(u16 *)(p + 0x320) = g_p2_hit10_anim_count;
    *(s32 *)(p + 0x324) = g_p2_chain_points;
    *(s32 *)(p + 0x328) = g_p2_chain_points_shown;
    *(s32 *)(p + 0x32C) = g_p2_chain_points_shown2;
    *(u16 *)(p + 0x330) = g_p2_hits;
    *(u16 *)(p + 0x332) = g_p2_hits_shown;
    *(u16 *)(p + 0x334) = g_p2_laser_hit_timer;
    *(u16 *)(p + 0x336) = g_p2_laser_hit_step;
    *(u16 *)(p + 0x338) = g_boss_hit_decay_timer;
    *(u16 *)(p + 0x33A) = g_boss_hit_anim_count;
    *(u16 *)(p + 0x33C) = g_boss_hits;
    *(u16 *)(p + 0x33E) = g_boss_hit_palette_as_u16;
    *(u16 *)(p + 0x340) = g_boss_hit_bonus_timer;
    *(s32 *)(p + 0x344) = g_boss_hit_bonus;
    *(s32 *)(p + 0x348) = g_boss_score;
    *(u16 *)(p + 0x34C) = g_boss_hp_bar_flags_as_u16;
    *(u16 *)(p + 0x34E) = g_p1_max_hits;
    *(u16 *)(p + 0x350) = g_p2_max_hits;
    *(u16 *)(p + 0x352) = g_p1_laser_hyper_timer;
    *(u16 *)(p + 0x354) = g_p2_laser_hyper_timer;
    *(u16 *)(p + 0x356) = g_p1_shot_hyper_timer;
    *(u16 *)(p + 0x358) = g_p2_shot_hyper_timer;
    *(u16 *)(p + 0x35A) = g_p1_hyper_active;
    *(u16 *)(p + 0x35C) = g_p2_hyper_active;
    *(u16 *)(p + 0x35E) = g_p1_hyper_time;
    *(u16 *)(p + 0x360) = g_p2_hyper_time;
    *(u16 *)(p + 0x362) = g_p1_hyper_total;
    *(u16 *)(p + 0x364) = g_p2_hyper_total;
    *(u16 *)(p + 0x366) = g_p1_hyper_gauge;
    *(u16 *)(p + 0x368) = g_p2_hyper_gauge;
    *(u16 *)(p + 0x36A) = g_p1_hyper_combo_decay;
    *(u16 *)(p + 0x36C) = g_p2_hyper_combo_decay;
    *(u16 *)(p + 0x36E) = g_hyper_text_slide;
    *(u16 *)(p + 0x370) = g_p1_hyper_level;
    *(u16 *)(p + 0x372) = g_p2_hyper_level;
    *(u16 *)(p + 0x374) = g_p1_hyper_in_effect;
    *(u16 *)(p + 0x376) = g_p2_hyper_in_effect;
    *(u16 *)(p + 0x378) = g_p1_hyper_items;
    *(u16 *)(p + 0x37A) = g_p2_hyper_items;
    *(u16 *)(p + 0x37C) = g_p1_hyper_items_pending;
    *(u16 *)(p + 0x37E) = g_p2_hyper_items_pending;
    *(u16 *)(p + 0x380) = g_boss_hyper_wait;
    *(u16 *)(p + 0x382) = g_hyper_hit_scratch;
    *(u16 *)(p + 0x384) = g_hyper_level_hit_scratch;
    *(u16 *)(p + 0x386) = g_boss_double_speed;
    *(u16 *)(p + 0x388) = D_0028E5A0;
    *(u16 *)(p + 0x38A) = g_score_panel_intro;
    *(u16 *)(p + 0x38C) = g_score_task_active;
    *(s32 *)(p + 0x390) = g_p1_hyper_effect_sprite;
    *(s32 *)(p + 0x394) = g_p2_hyper_effect_sprite;
    *(u16 *)(p + 0x398) = g_p1_hyper_effect_frame;
    *(u16 *)(p + 0x39A) = g_p2_hyper_effect_frame;
    *(u16 *)(p + 0x39C) = g_p1_hyper_effect_flag;
    *(u16 *)(p + 0x39E) = g_p2_hyper_effect_flag;
    *(u16 *)(p + 0x3A0) = g_p1_hyper_effect_delay;
    *(u16 *)(p + 0x3A2) = g_p2_hyper_effect_delay;
}

extern s32 D_0028ED88;

s32 func_0023CC30(Reg32 *entry, Reg32 *table, s32 count) {
    Reg32 key;
    Reg32 cur;
    s32 offset;
    u8 *mark = &entry->b[2];

    key.h[1] = entry->h[0];
    key.h[0] = entry->h[1];
    if (key.w == 0) {
        return -1;
    }
    for (offset = 0; offset < count * 4; offset += 4) {
        cur.h[1] = table->h[1];
        cur.h[0] = table->h[0];
        if (cur.w == key.w) {
            entry->h[0] = offset;
            entry->b[3] = 0x80;
            *mark = 0x99;
            return 1;
        }
        table++;
    }
    D_0028ED88 = 1;
    return 0;
}

typedef union {
    u16 h[2];
    u32 w;
} HalfPair;


s32 func_0023CCD0(u16 *addr, u16 *starts, s32 *sizes, s32 count) {
    HalfPair target;
    HalfPair start;
    s32 i;
    s32 size;
    s32 j;
    u32 pos;

    u8 *hi = (u8 *)(addr + 1);

    target.h[1] = addr[0];
    target.h[0] = addr[1];
    if (target.w == 0) {
        return -1;
    }
    for (i = 0; i < count * 4; i += 4) {
        start.h[1] = starts[1];
        start.h[0] = starts[0];
        pos = start.w;
        size = *(s32 *)((u8 *)sizes + i);
        if (pos <= target.w && target.w < pos + size) {
            for (j = 0; j < size; j += 2) {
                if (pos == target.w) {
                    ((u8 *)addr)[1] = i;
                    ((u8 *)addr)[0] = j;
                    ((u8 *)addr)[3] = 0x81;
                    *hi = 0x99;
                    return 1;
                }
                pos += 2;
            }
        }
        starts += 2;
    }
    D_0028ED88 = 1;
    return 0;
}

s32 func_0023CDA0(Reg32 *entry, u8 *code, u32 count, u32 stride) {
    Reg32 key;
    u32 offset;
    u8 *mark = &entry->b[2];

    key.h[1] = entry->h[0];
    key.h[0] = entry->h[1];
    if (key.w == 0) {
        return -1;
    }
    for (offset = 0; offset < count * stride; offset += stride) {
        if ((u32)code == key.w) {
            entry->h[0] = offset;
            entry->b[3] = 0x82;
            *mark = 0x99;
            return 1;
        }
        code += stride;
    }
    D_0028ED88 = 1;
    return 0;
}

s32 func_0023CE20(Reg32 *entry, u8 *code, u32 count, u32 stride) {
    Reg32 key;
    u32 offset;
    u8 *mark = &entry->b[2];

    key.h[0] = entry->h[0];
    key.h[1] = entry->h[1];
    if (key.w == 0) {
        return -1;
    }
    for (offset = 0; offset < count * stride; offset += stride) {
        if ((u32)code == key.w) {
            entry->h[0] = offset;
            entry->b[3] = 0x83;
            *mark = 0x99;
            return 1;
        }
        code += stride;
    }
    D_0028ED88 = 1;
    return 0;
}

extern u16 D_00269530[];
extern u16 D_00272128[];
extern u16 D_00272138[];
extern u16 D_00272148[];
extern u16 D_00272160[];
extern u16 D_002726A0[];
extern u16 D_00272750[];
extern u16 D_00272770[];
extern s32 D_002727D0[];
extern u16 D_00272820[];
extern u16 D_00272870[];
extern s32 D_00272890[];
extern u16 D_002728B0[];
extern u16 D_00272990[];
extern s32 D_002729C0[];
extern u16 D_0028DE50[4];
extern u16 D_0028DE58[4];
extern u16 g_text_layer_as_u16_a[];
extern u16 D_002BD440[];

void func_0023CEA0(u8 *base) {
    s32 off;
    u8 *p;
    u8 *q;
    s32 j;
    u8 *r;
    s32 k;
    u8 *t;
    s32 m;
    s32 n;

    for (off = 0; off < 0xC08; off += 0x2C) {
        p = base + off;
        func_0023CC30((void *)(p + 0x24), (void *)D_0028DE50, 2);
        func_0023CC30((void *)(p + 0x28), (void *)D_00269530, 6);
    }
    func_0023CC30((void *)(base + 0xCF0), (void *)D_00272128, 3);
    func_0023CC30((void *)(base + 0xD0A), (void *)D_00272128, 3);
    func_0023CC30((void *)(base + 0xD20), (void *)D_00272138, 3);
    func_0023CC30((void *)(base + 0xD32), (void *)D_00272148, 3);
    func_0023CC30((void *)(base + 0xD54), (void *)D_00272128, 3);
    func_0023CC30((void *)(base + 0xD6E), (void *)D_00272128, 3);
    func_0023CC30((void *)(base + 0xD84), (void *)D_00272138, 3);
    func_0023CC30((void *)(base + 0xD96), (void *)D_00272148, 3);
    for (off = 0; off < 0xD80; off += 0x30) {
        func_0023CC30((void *)(base + off + 0xDC0), (void *)D_00272160, 0x150);
    }
    for (j = 0; j < 0x510; j += 0x30) {
        q = base + j;
        func_0023CC30((void *)(q + 0x1B40), (void *)D_002726A0, 0x2C);
        func_0023CC30((void *)(q + 0x1B4A), (void *)D_00272750, 5);
        func_0023CCD0((void *)(q + 0x1B4E), (void *)D_00272770, (void *)D_002727D0, 0x18);
        func_0023CC30((void *)(q + 0x2140), (void *)D_002726A0, 0x2C);
        func_0023CC30((void *)(q + 0x214A), (void *)D_00272750, 5);
        func_0023CCD0((void *)(q + 0x214E), (void *)D_00272770, (void *)D_002727D0, 0x18);
    }
    q = base + j;
    func_0023CC30((void *)(q + 0x1B40), (void *)D_002726A0, 0x2C);
    func_0023CC30((void *)(q + 0x1B4A), (void *)D_00272750, 5);
    func_0023CCD0((void *)(q + 0x1B4E), (void *)D_00272770, (void *)D_002727D0, 0x18);
    func_0023CC30((void *)(q + 0x2140), (void *)D_002726A0, 0x2C);
    func_0023CC30((void *)(q + 0x214A), (void *)D_00272750, 5);
    func_0023CCD0((void *)(q + 0x214E), (void *)D_00272770, (void *)D_002727D0, 0x18);
    for (k = 0x540; k < 0x5A0; k += 0x30) {
        r = base + k;
        func_0023CCD0((void *)(r + 0x1B40), (void *)D_00272770, (void *)D_002727D0, 0x18);
        func_0023CC30((void *)(r + 0x1B4A), (void *)D_00272750, 5);
        func_0023CCD0((void *)(r + 0x1B4E), (void *)D_00272770, (void *)D_002727D0, 0x18);
        func_0023CCD0((void *)(r + 0x2140), (void *)D_00272770, (void *)D_002727D0, 0x18);
        func_0023CC30((void *)(r + 0x214A), (void *)D_00272750, 5);
        func_0023CCD0((void *)(r + 0x214E), (void *)D_00272770, (void *)D_002727D0, 0x18);
    }
    r = base + k;
    func_0023CC30((void *)(r + 0x1B40), (void *)D_002726A0, 0x2C);
    func_0023CC30((void *)(r + 0x1B4A), (void *)D_00272750, 5);
    func_0023CCD0((void *)(r + 0x1B4E), (void *)D_00272770, (void *)D_002727D0, 0x18);
    func_0023CC30((void *)(r + 0x2140), (void *)D_002726A0, 0x2C);
    func_0023CC30((void *)(r + 0x214A), (void *)D_00272750, 5);
    func_0023CCD0((void *)(r + 0x214E), (void *)D_00272770, (void *)D_002727D0, 0x18);
    r = base + (k + 0x30);
    func_0023CC30((void *)(r + 0x1B40), (void *)D_002726A0, 0x2C);
    func_0023CC30((void *)(r + 0x1B4C), (void *)D_00272820, 0x14);
    func_0023CC30((void *)(r + 0x2140), (void *)D_002726A0, 0x2C);
    func_0023CC30((void *)(r + 0x214C), (void *)D_00272820, 0x14);
    for (m = 0; m < 0x7E0; m += 0x30) {
        t = base + m + 0x27C0;
        if (func_0023CC30((void *)(t), (void *)D_002728B0, 0x36) == 0 && func_0023CCD0((void *)(t), (void *)D_00272870, (void *)D_00272890, 6) != 0) {
            D_0028ED88 = 0;
        }
    }
    for (off = 0x7E0; off < 0x870; off += 0x30) {
        func_0023CC30((void *)(base + off + 0x27C0), (void *)D_002728B0, 0x36);
    }
    func_0023CCD0((void *)(base + 0x301C), (void *)D_00272990, (void *)D_002729C0, 0xC);
    func_0023CCD0((void *)(base + 0x3020), (void *)D_00272990, (void *)D_002729C0, 0xC);
    func_0023CCD0((void *)(base + 0x3024), (void *)D_00272990, (void *)D_002729C0, 0xC);
    func_0023CCD0((void *)(base + 0x3028), (void *)D_00272990, (void *)D_002729C0, 0xC);
    func_0023CE20((void *)(base + 0x318C), (void *)D_002BD440, 0x32, 0x20);
    func_0023CC30((void *)(base + 0x3226), (void *)D_0028DE58, 2);
    func_0023CC30((void *)(base + 0x324A), (void *)D_0028DE58, 2);
    for (n = 0; n < 0x5A; n += 10) {
        func_0023CDA0((void *)(&((u8 (*)[10])(base + 0x32B6))[0][n]), (void *)g_text_layer_as_u16_a, 0x800, 4);
        func_0023CDA0((void *)(&((u8 (*)[10])(base + 0x3310))[0][n]), (void *)g_text_layer_as_u16_a, 0x800, 4);
    }
}

#pragma push
#pragma opt_common_subs off
extern u8 g_text_layer[];


void func_0023D420(s32 baseAddress)
{
    s32 entryOffset = 0;

    do {
        func_0023CDA0((void *)(entryOffset + baseAddress + 0x1EE), (void *)g_text_layer, 0x800, 4);
        func_0023CDA0((void *)(entryOffset + baseAddress + 0x248), (void *)g_text_layer, 0x800, 4);
        entryOffset += 0xA;
    } while (entryOffset < 0x5A);
}
#pragma pop

s32 func_0022BB20();

void func_0023D4A0(u8 *arg0) {
    D_0028ED88 = 0;
    func_0023CEA0(arg0 + 0x400);
    func_0023D420((s32)(arg0 + 0x5934));
    (*(s32 *)((u8 *)(arg0) + (0x5CE4))) = func_0022BB20(arg0 + 0x400);
}

typedef union {
    u32 w;
    u16 h[2];
} Pair;

static inline void func_0023D4E0_read(u16 *dst, u16 *mem, s32 addr) {
    u16 value;

    if (addr != 0) {
        value = *(u16 *)((u8 *)mem + ((s16)addr & ~1));
    } else {
        value = *mem;
    }
    *dst = value;
}

s32 func_0023D4E0(u8 *entry, u16 *mem, s32 op) {
    Pair r;
    u8 *tag;
    u16 addr;
    u8 lo;
    s32 base;

    tag = entry + 2;
    if (*tag != 0x99) {
        return -1;
    }
    if (entry[3] != op) {
        return 0;
    }
    switch (op) {
    case 0x80:
        addr = *(u16 *)entry;
        func_0023D4E0_read(&r.h[0], mem, addr);
        func_0023D4E0_read(&r.h[1], mem, addr + 2);
        *(u16 *)entry = r.h[1];
        *(u16 *)tag = r.h[0];
        break;
    case 0x81:
        lo = entry[1];
        base = entry[0];
        func_0023D4E0_read(&r.h[0], mem, lo);
        func_0023D4E0_read(&r.h[1], mem, lo + 2);
        r.w += base;
        *(u16 *)entry = r.h[1];
        *(u16 *)tag = r.h[0];
        break;
    case 0x82:
        r.w = (u32)mem + *(u16 *)entry;
        *(u16 *)entry = r.h[1];
        *(u16 *)tag = r.h[0];
        break;
    case 0x83:
        r.w = (u32)mem + *(u16 *)entry;
        *(u16 *)entry = r.h[0];
        *(u16 *)tag = r.h[1];
        break;
    default:
        return 0;
    }
    return 1;
}


void func_0023D6A0(u8 *base) {
    s32 off;
    u8 *p;
    u8 *q;
    s32 j;
    u8 *r;
    s32 k;
    u8 *t;
    s32 m;
    s32 n;

    for (off = 0; off < 0xC08; off += 0x2C) {
        p = base + off;
        func_0023D4E0(p + 0x24, D_0028DE50, 0x80);
        func_0023D4E0(p + 0x28, D_00269530, 0x80);
    }
    func_0023D4E0(base + 0xCF0, D_00272128, 0x80);
    func_0023D4E0(base + 0xD0A, D_00272128, 0x80);
    func_0023D4E0(base + 0xD20, D_00272138, 0x80);
    func_0023D4E0(base + 0xD32, D_00272148, 0x80);
    func_0023D4E0(base + 0xD54, D_00272128, 0x80);
    func_0023D4E0(base + 0xD6E, D_00272128, 0x80);
    func_0023D4E0(base + 0xD84, D_00272138, 0x80);
    func_0023D4E0(base + 0xD96, D_00272148, 0x80);
    for (off = 0; off < 0xD80; off += 0x30) {
        func_0023D4E0(base + off + 0xDC0, D_00272160, 0x80);
    }
    for (j = 0; j < 0x510; j += 0x30) {
        q = base + j;
        func_0023D4E0(q + 0x1B40, D_002726A0, 0x80);
        func_0023D4E0(q + 0x1B4A, D_00272750, 0x80);
        func_0023D4E0(q + 0x1B4E, D_00272770, 0x81);
        func_0023D4E0(q + 0x2140, D_002726A0, 0x80);
        func_0023D4E0(q + 0x214A, D_00272750, 0x80);
        func_0023D4E0(q + 0x214E, D_00272770, 0x81);
    }
    q = base + j;
    func_0023D4E0(q + 0x1B40, D_002726A0, 0x80);
    func_0023D4E0(q + 0x1B4A, D_00272750, 0x80);
    func_0023D4E0(q + 0x1B4E, D_00272770, 0x81);
    func_0023D4E0(q + 0x2140, D_002726A0, 0x80);
    func_0023D4E0(q + 0x214A, D_00272750, 0x80);
    func_0023D4E0(q + 0x214E, D_00272770, 0x81);
    for (k = 0x540; k < 0x5A0; k += 0x30) {
        r = base + k;
        func_0023D4E0(r + 0x1B40, D_00272770, 0x81);
        func_0023D4E0(r + 0x1B4A, D_00272750, 0x80);
        func_0023D4E0(r + 0x1B4E, D_00272770, 0x81);
        func_0023D4E0(r + 0x2140, D_00272770, 0x81);
        func_0023D4E0(r + 0x214A, D_00272750, 0x80);
        func_0023D4E0(r + 0x214E, D_00272770, 0x81);
    }
    r = base + k;
    func_0023D4E0(r + 0x1B40, D_002726A0, 0x80);
    func_0023D4E0(r + 0x1B4A, D_00272750, 0x80);
    func_0023D4E0(r + 0x1B4E, D_00272770, 0x81);
    func_0023D4E0(r + 0x2140, D_002726A0, 0x80);
    func_0023D4E0(r + 0x214A, D_00272750, 0x80);
    func_0023D4E0(r + 0x214E, D_00272770, 0x81);
    r = base + (k + 0x30);
    func_0023D4E0(r + 0x1B40, D_002726A0, 0x80);
    func_0023D4E0(r + 0x1B4C, D_00272820, 0x80);
    func_0023D4E0(r + 0x2140, D_002726A0, 0x80);
    func_0023D4E0(r + 0x214C, D_00272820, 0x80);
    for (m = 0; m < 0x7E0; m += 0x30) {
        t = base + m + 0x27C0;
        func_0023D4E0(t, D_002728B0, 0x80);
        func_0023D4E0(t, D_00272870, 0x81);
    }
    for (off = 0x7E0; off < 0x870; off += 0x30) {
        func_0023D4E0(base + off + 0x27C0, D_002728B0, 0x80);
    }
    func_0023D4E0(base + 0x301C, D_00272990, 0x81);
    func_0023D4E0(base + 0x3020, D_00272990, 0x81);
    func_0023D4E0(base + 0x3024, D_00272990, 0x81);
    func_0023D4E0(base + 0x3028, D_00272990, 0x81);
    func_0023D4E0(base + 0x318C, D_002BD440, 0x83);
    func_0023D4E0(base + 0x3226, D_0028DE58, 0x80);
    func_0023D4E0(base + 0x324A, D_0028DE58, 0x80);
    for (n = 0; n < 0x5A; n += 10) {
        func_0023D4E0(&((u8 (*)[10])(base + 0x32B6))[0][n], g_text_layer_as_u16_a, 0x82);
        func_0023D4E0(&((u8 (*)[10])(base + 0x3310))[0][n], g_text_layer_as_u16_a, 0x82);
    }
}


void func_0023DB80(u8 *base)
{
    s32 offset = 0;

    do {
        func_0023D4E0((void *)((u8 *)offset + (s32)base + 0x1EE), (void *)g_text_layer, 0x82);
        func_0023D4E0((void *)((u8 *)(offset + (s32)base) + 0x248), (void *)g_text_layer, 0x82);
        offset += 0xA;
    } while (offset < 0x5A);
}

s32 func_0022BB20(s32);                             /* extern */
extern s32 D_0028ED3C;

void func_0023DBF0(s32 arg0) {
    D_0028ED3C = func_0022BB20(arg0 + 0x400);
    func_0023D6A0((void *)(arg0 + 0x400));
    func_0023DB80((void *)(arg0 + 0x5934));
}
