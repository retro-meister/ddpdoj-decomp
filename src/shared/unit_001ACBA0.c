#include "common.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

void func_001ACD30(void);
void func_001ACF80(void);
void func_001AD580(void);
void func_001AEB10(void);
void func_001AED30(void);
void func_001AED60(void);
void func_001AED90(void);
void func_001AF010(void);

extern u8 *reg_save3_a6;
extern u8 *reg_save3_a5;
extern u8 *reg_save3_a4;
extern u8 *reg_save3_a3;
extern u8 *reg_save3_a2;
extern u8 *reg_save3_a1;
extern u8 *reg_save3_a0;
extern u32 reg_save3_d7;
extern u32 reg_save3_d6;
extern u32 reg_save3_d5;
extern u32 reg_save3_d4;
extern u32 reg_save3_d3;
extern u32 reg_save3_d2;
extern u32 reg_save3_d1;
extern u32 reg_save3_d0;
extern u16 g_p1_max_hits;
extern u16 g_p1_score_digits;
extern u16 g_p1_score_billions;
extern u32 g_p1_score;
extern u16 g_p1_power_style;
extern u16 g_p1_ship_type;
extern u8 D_002BB420[];

void func_001ACBA0(void) {
    reg_save3_d0 = reg_d0.w;
    reg_save3_d1 = reg_d1.w;
    reg_save3_d2 = reg_d2.w;
    reg_save3_d3 = reg_d3.w;
    reg_save3_d4 = reg_d4.w;
    reg_save3_d5 = reg_d5.w;
    reg_save3_d6 = reg_d6.w;
    reg_save3_d7 = reg_d7.w;
    reg_save3_a0 = reg_a0;
    reg_save3_a1 = reg_a1;
    reg_save3_a2 = reg_a2;
    reg_save3_a3 = reg_a3;
    reg_save3_a4 = reg_a4;
    reg_save3_a5 = reg_a5;
    reg_save3_a6 = reg_a6;
    reg_a4 = (u8 *)D_002BB420;
    reg_d6.w = 0xFF;
    reg_d7.w = g_p1_score;
    reg_d5.h[0] = g_p1_score_billions;
    reg_d0.h[0] = g_p1_ship_type;
    reg_d1.h[0] = g_p1_power_style;
    reg_d2.h[0] = g_p1_max_hits;
    reg_d3.h[0] = g_p1_score_digits;
    func_001ACD30();
}

extern u16 g_p2_max_hits;
extern u16 g_p2_score_digits;
extern u16 g_p2_score_billions;
extern u32 g_p2_score;
extern u16 g_p2_power_style;
extern u16 g_p2_ship_type;
extern u8 D_002BB410[];

void func_001ACC60(void) {
    reg_save3_d0 = reg_d0.w;
    reg_save3_d1 = reg_d1.w;
    reg_save3_d2 = reg_d2.w;
    reg_save3_d3 = reg_d3.w;
    reg_save3_d4 = reg_d4.w;
    reg_save3_d5 = reg_d5.w;
    reg_save3_d6 = reg_d6.w;
    reg_save3_d7 = reg_d7.w;
    reg_save3_a0 = reg_a0;
    reg_save3_a1 = reg_a1;
    reg_save3_a2 = reg_a2;
    reg_save3_a3 = reg_a3;
    reg_save3_a4 = reg_a4;
    reg_save3_a5 = reg_a5;
    reg_save3_a6 = reg_a6;
    reg_a4 = (u8 *)D_002BB410;
    reg_d6.w = 0xFE;
    reg_d7.w = g_p2_score;
    reg_d5.h[0] = g_p2_score_billions;
    reg_d0.h[0] = g_p2_ship_type;
    reg_d0.h[0] += 4;
    reg_d1.h[0] = g_p2_power_style;
    reg_d2.h[0] = g_p2_max_hits;
    reg_d3.h[0] = g_p2_score_digits;
    func_001ACD30();
}


extern u16 g_p2_score_billions_saved;
extern u16 g_p1_score_billions_saved;
extern u32 g_p2_score_saved;
extern u32 g_p1_score_saved;
extern u16 g_game_completed;
extern u16 g_loop;
extern u16 g_stage;

#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
#endif

void func_001ACD30(void) {
    *(u16 *)(reg_a4 + 0) = MAIN_OR_DEATH_LABEL(g_loop, death_D_00290DC0);
    *(u16 *)(reg_a4 + 2) = g_stage;
    if (g_game_completed != 0) {
        *(u16 *)(reg_a4 + 0) = 1;
        *(u16 *)(reg_a4 + 2) = 5;
    }
    *(u16 *)(reg_a4 + 4) = reg_d0.h[0];
    *(u16 *)(reg_a4 + 6) = reg_d1.h[0];
    *(u16 *)(reg_a4 + 8) = reg_d2.h[0];
    *(u16 *)(reg_a4 + 0xA) = reg_d3.h[0];
    func_001ACF80();
    if (cond_flag != 0) {
        goto block_50;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0xC);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xE);
    reg_a4 = (u8 *)reg_tmp.w;
    *(u32 *)(reg_a4 + 0) = reg_d6.w;
    if (reg_d6.w == 0xFF) {
        reg_d0.h[0] = g_p1_score_billions;
        if ((s32) g_p1_score_billions_saved > (s32) reg_d0.h[0]) {
            goto block_51;
        }
        g_p1_score_billions_saved = reg_d0.h[0];
        reg_d0.w = g_p1_score;
        if ((u32) g_p1_score_saved > (u32) reg_d0.w) {
            goto block_51;
        }
        g_p1_score_saved = reg_d0.w;
    } else {
        reg_d0.h[0] = g_p2_score_billions;
        if ((s32) g_p2_score_billions_saved > (s32) reg_d0.h[0]) {
            goto block_51;
        }
        g_p2_score_billions_saved = reg_d0.h[0];
        reg_d0.w = g_p2_score;
        if ((u32) g_p2_score_saved > (u32) reg_d0.w) {
            goto block_51;
        }
        g_p2_score_saved = reg_d0.w;
    }
block_51:
    cond_flag = 0;
    reg_d0.w = reg_save3_d0;
    reg_d1.w = reg_save3_d1;
    reg_d2.w = reg_save3_d2;
    reg_d3.w = reg_save3_d3;
    reg_d4.w = reg_save3_d4;
    reg_d5.w = reg_save3_d5;
    reg_d6.w = reg_save3_d6;
    reg_d7.w = reg_save3_d7;
    reg_a0 = (u8 *)reg_save3_a0;
    reg_a1 = (u8 *)reg_save3_a1;
    reg_a2 = (u8 *)reg_save3_a2;
    reg_a3 = (u8 *)reg_save3_a3;
    reg_a4 = (u8 *)reg_save3_a4;
    reg_a5 = (u8 *)reg_save3_a5;
    reg_a6 = (u8 *)reg_save3_a6;
    return;
block_50:
    cond_flag = 1;
    reg_d0.w = reg_save3_d0;
    reg_d1.w = reg_save3_d1;
    reg_d2.w = reg_save3_d2;
    reg_d3.w = reg_save3_d3;
    reg_d4.w = reg_save3_d4;
    reg_d5.w = reg_save3_d5;
    reg_d6.w = reg_save3_d6;
    reg_d7.w = reg_save3_d7;
    reg_a0 = (u8 *)reg_save3_a0;
    reg_a1 = (u8 *)reg_save3_a1;
    reg_a2 = (u8 *)reg_save3_a2;
    reg_a3 = (u8 *)reg_save3_a3;
    reg_a4 = (u8 *)reg_save3_a4;
    reg_a5 = (u8 *)reg_save3_a5;
    reg_a6 = (u8 *)reg_save3_a6;
}

extern s8 D_0025F6B0[];
extern u8 g_game_mode;
extern s32 D_0028EAFC;
extern u8 g_replay_mode;
extern u8 D_002BB060[5][30];
extern u8 D_002BB100[5][30];
extern u8 D_002BB352[];
extern u8 D_002BB362[];
extern u8 D_002BB372[];
extern u8 D_002BB382[];
extern u8 D_002BB392[];
extern u8 D_002BB3A2[];
extern u8 D_002BB3EC[];

void func_001ACF80(void) {
    u8 *save_a5;
    u8 *save_a6;
    s32 i;
    s32 j;
    u8 *p;

    save_a5 = reg_a5;
    save_a6 = reg_a6;
    cond_flag = 0;
    if (g_replay_mode == 2) {
        printf((const char *)"replay nameentry skip\n");
        cond_flag = 1;
        goto block_rts;
    }
    func_001AD580();
    if ((s16) reg_d1.h[0] < 0) {
        cond_flag = 1;
        goto block_rts;
    }
    cond_flag = 0;
    if (g_game_mode == 2) {
        D_0028EAFC = 4 - reg_d1.w;
        printf((const char *)"---death--rank[%d]\n", D_0028EAFC);
        if (D_0028EAFC != 4) {
            for (i = 4; D_0028EAFC < i; i--) {
                for (j = 0; j < 30; j++) {
                    D_002BB060[i][j] = D_002BB060[i - 1][j];
                }
            }
        }
    } else {
        D_0028EAFC = 4 - reg_d1.w;
        printf((const char *)"-----rank[%d]\n", D_0028EAFC);
        if (D_0028EAFC != 4) {
            for (i = 4; D_0028EAFC < i; i--) {
                for (j = 0; j < 30; j++) {
                    D_002BB100[i][j] = D_002BB100[i - 1][j];
                }
            }
        }
        for (j = 0; j < 30; j++) {
            D_002BB100[D_0028EAFC][j] = D_0025F6B0[j];
        }
    }
    reg_d2.w = reg_d1.w;
    if (reg_d2.w == 0) goto next_60;
    reg_d1.h[0] -= 1;
loop_50:
    reg_a2 -= 4;
    *(u16 *)(reg_a2 + 0) = *(u16 *)(reg_a2 - 4);
    *(u16 *)(reg_a2 + 2) = *(u16 *)(reg_a2 - 2);
    reg_a5 -= 2;
    *(u16 *)reg_a5 = *(u16 *)(reg_a5 - 2);
    if ((s16) --reg_d1.h[0] >= 0) goto loop_50;
next_60:
    reg_a2 -= 4;
    *(u32 *)reg_a2 = reg_d7.w;
    reg_a5 -= 2;
    *(u16 *)reg_a5 = reg_d5.h[0];
    reg_a1 = (u8 *)D_002BB3EC;
    reg_d1.w = reg_d2.w;
    if (reg_d1.w == 0) goto next_80;
    reg_d1.h[0] -= 1;
loop_70:
    p = reg_a1;
    *(u32 *)(p - 4) = *(u32 *)(p - 0x10);
    *(u32 *)(p - 8) = *(u32 *)(p - 0x14);
    *(u32 *)(p - 0xC) = *(u32 *)(p - 0x18);
    reg_a1 = p - 0xC;
    if ((s16) --reg_d1.h[0] >= 0) goto loop_70;
next_80:
    reg_a1 -= 0xC;
    reg_tmp.w = (u32) reg_a1;
    *(u16 *)(reg_a4 + 0xC) = reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0xE) = reg_tmp.h[0];
    reg_a1 = (u8 *)D_002BB3A2;
    reg_a2 = (u8 *)D_002BB392;
    reg_a3 = (u8 *)D_002BB382;
    reg_a0 = (u8 *)D_002BB372;
    reg_a5 = (u8 *)D_002BB362;
    reg_a6 = (u8 *)D_002BB352;
    reg_d3.h[0] = reg_d2.h[0];
    reg_tmp2.w = reg_d2.h[0];
    reg_tmp2.w -= 1;
    reg_d2.h[0] = reg_tmp2.h[0];
    if (reg_tmp2.h[1] != 0) goto next_98;
loop_90:
    reg_a1 -= 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a1 - 2);
    reg_a2 -= 2;
    *(u16 *)reg_a2 = *(u16 *)(reg_a2 - 2);
    reg_a3 -= 2;
    *(u16 *)reg_a3 = *(u16 *)(reg_a3 - 2);
    reg_a0 -= 2;
    *(u16 *)reg_a0 = *(u16 *)(reg_a0 - 2);
    reg_a5 -= 2;
    *(u16 *)reg_a5 = *(u16 *)(reg_a5 - 2);
    reg_a6 -= 2;
    ENTITY(reg_a6)->flags.h = *(u16 *)(reg_a6 - 2);
    if ((s16) --reg_d2.h[0] >= 0) goto loop_90;
next_98:
    reg_a1 -= 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a4 + 0);
    reg_a2 -= 2;
    *(u16 *)reg_a2 = *(u16 *)(reg_a4 + 2);
    reg_a3 -= 2;
    *(u16 *)reg_a3 = *(u16 *)(reg_a4 + 4);
    reg_a0 -= 2;
    *(u16 *)reg_a0 = *(u16 *)(reg_a4 + 6);
    reg_a5 -= 2;
    *(u16 *)reg_a5 = *(u16 *)(reg_a4 + 8);
    reg_a6 -= 2;
    ENTITY(reg_a6)->flags.h = *(u16 *)(reg_a4 + 0xA);
block_rts:
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

extern u16 D_002BB342[];
extern u32 D_002BB404[];

void func_001AD580(void) {
    u32 tmp;

    reg_a1 = (u8 *)D_002BB404;
    reg_a3 = (u8 *)D_002BB342;
    reg_d0.w = 4;
    reg_a2 = reg_a1;
    reg_a5 = reg_a3;
loop_1:
    reg_a1 -= 4;
    reg_d1.w = *(u32 *)reg_a1;
    reg_a3 -= 2;
    reg_d2.h[0] = *(u16 *)reg_a3;
    if ((s32) reg_d5.h[0] < (s32) reg_d2.h[0]) {
        goto next_1;
    }
    if ((s32) reg_d5.h[0] > (s32) reg_d2.h[0]) {
        goto next_2;
    }
    if ((u32) reg_d1.w >= (u32) reg_d7.w) {
        goto next_1;
    }
next_2:
    tmp = reg_d0.h[0] - 1;
    reg_d0.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
next_1:
    reg_d0.h[0] += 1;
    reg_d1.w = 4;
    reg_d2.h[0] = reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] -= reg_d2.h[0];
    reg_d0.h[0] += reg_d0.h[0];
}

extern s16 g_p2_laser_hit_step_as_s16;
extern s16 g_p2_laser_hit_timer_as_s16;
extern s16 g_p2_hits_shown_as_s16;
extern u16 g_p2_hits;
extern s32 g_p2_chain_points_shown2;
extern s32 g_p2_chain_points_shown;
extern s32 g_p2_chain_points;
extern s16 g_p2_hit10_anim_count_as_s16;
extern s16 g_p2_hit10_color_timer_as_s16;
extern s16 g_p2_hit10_display_timer;
extern s16 g_p2_combo_break_color_timer_as_s16;
extern s16 g_p2_hit_display_timer_as_s16;
extern s16 g_p2_chain_points_display_timer;
extern u16 g_p2_combo_timer;
extern s32 g_p2_chain_first_score_shown;
extern s32 g_p2_chain_first_score;
extern s16 g_p1_laser_hit_step_as_s16;
extern s16 g_p1_laser_hit_timer_as_s16;
extern s16 g_p1_hits_shown_as_s16;
extern u16 g_p1_hits;
extern s32 g_p1_chain_points_shown2;
extern s32 g_p1_chain_points_shown;
extern s32 g_p1_chain_points;
extern s16 g_p1_hit10_anim_count_as_s16;
extern s16 g_p1_hit10_color_timer_as_s16;
extern s16 g_p1_hit10_display_timer;
extern s16 g_p1_combo_break_color_timer_as_s16;
extern s16 g_p1_hit_display_timer_as_s16;
extern s16 g_p1_chain_points_display_timer;
extern u16 g_p1_combo_timer;
extern s32 g_p1_chain_first_score_shown;
extern s32 g_p1_chain_first_score;
extern s16 g_score_player_flag_as_s16;

void func_001AD690(void) {
    g_p2_laser_hit_step_as_s16 = 0;
    g_p2_laser_hit_timer_as_s16 = 0;
    g_p2_hits_shown_as_s16 = 0;
    g_p2_chain_points = g_p2_chain_points_shown = g_p2_chain_points_shown2 = (g_p2_hits = 0);
    g_p2_hit10_anim_count_as_s16 = 0;
    g_p2_hit10_color_timer_as_s16 = 0;
    g_p2_hit10_display_timer = 0;
    g_p2_combo_break_color_timer_as_s16 = 0;
    g_p2_hit_display_timer_as_s16 = 0;
    g_p2_chain_points_display_timer = 0;
    g_p2_chain_first_score = g_p2_chain_first_score_shown = (g_p2_combo_timer = 0);
    g_p1_laser_hit_step_as_s16 = 0;
    g_p1_laser_hit_timer_as_s16 = 0;
    g_p1_hits_shown_as_s16 = 0;
    g_p1_chain_points = g_p1_chain_points_shown = g_p1_chain_points_shown2 = (g_p1_hits = 0);
    g_p1_hit10_anim_count_as_s16 = 0;
    g_p1_hit10_color_timer_as_s16 = 0;
    g_p1_hit10_display_timer = 0;
    g_p1_combo_break_color_timer_as_s16 = 0;
    g_p1_hit_display_timer_as_s16 = 0;
    g_p1_chain_points_display_timer = 0;
    g_p1_chain_first_score = g_p1_chain_first_score_shown = (g_p1_combo_timer = 0);
    g_score_player_flag_as_s16 = 0;
}

extern s16 g_boss_explosion_flash_as_s16;
extern s16 g_boss_near_death_as_s16;
extern s32 g_boss_hp_as_s32;
extern s32 g_boss_hp_unit;
extern s16 g_lives_display_move_x_as_s16;
extern s16 g_lives_display_move_y_as_s16;
extern s16 g_boss_hp_bar_move_count_as_s16;
extern s16 g_boss_hp_bar_flags_as_s16;
extern s32 g_boss_score;
extern s32 g_boss_hit_bonus;
extern s16 g_boss_hit_bonus_timer_as_s16;
extern s16 g_boss_hit_palette;
extern s16 g_boss_hits_as_s16;
extern s16 g_boss_hit_anim_count_as_s16;
extern s16 g_boss_hit_decay_timer_as_s16;

void func_001AD720(void)
{
    s32 lowHalfword;

    lowHalfword = (u16)(reg_d0.w = 0);
    g_boss_explosion_flash_as_s16 = 0;
    g_boss_near_death_as_s16 = 0;
    g_boss_hp_as_s32 = lowHalfword;
    g_boss_hp_unit = lowHalfword;
    g_lives_display_move_x_as_s16 = 0;
    g_lives_display_move_y_as_s16 = 0;
    g_boss_hp_bar_move_count_as_s16 = 0;
    g_boss_hp_bar_flags_as_s16 = 0;
    g_boss_score = lowHalfword;
    g_boss_hit_bonus = lowHalfword;
    g_boss_hit_bonus_timer_as_s16 = 0;
    g_boss_hit_palette = 0;
    g_boss_hits_as_s16 = 0;
    g_boss_hit_anim_count_as_s16 = 0;
    g_boss_hit_decay_timer_as_s16 = 0;
}

extern s32 D_0026B920[];
extern u16 D_0026B938[];
extern u8 D_0026B950[];
extern u16 D_0026B990[];
extern u16 D_0026B9A0[];
extern u16 D_0026B9B0[];
extern u16 D_0026B9C0[];
extern u16 D_0026B9D0[];
extern s32 D_0026B9E0[];
extern u16 D_0026B9F8[];
extern u16 D_0026BA08[];
extern u8 D_0026BA20[];
extern u16 D_0026BA60[];
extern s8 D_0025F6D0[5][30];
extern s32 g_high_score;
extern s8 D_002BB060_as_s8_a5_a30[5][30];
extern s8 D_002BB100_as_s8_a5_a30[5][30];
extern u16 D_002BB198_as_u16_a[];
extern u16 D_002BB1A8_as_u16_a[];
extern u16 D_002BB1B8_as_u16_a[];
extern u16 D_002BB1C8_as_u16_a[];
extern u16 D_002BB1D8_as_u16_a[];
extern u16 D_002BB1E8_as_u16_a[];
extern u16 D_002BB1F8_as_u16_a[];
extern s32 D_002BB210_as_s32_a[];
extern s32 D_002BB250_as_s32_a[];
extern u16 D_002BB268_as_u16_a[];
extern u16 D_002BB278_as_u16_a[];
extern u16 D_002BB288_as_u16_a[];
extern u16 D_002BB298_as_u16_a[];
extern u16 D_002BB2A8_as_u16_a[];
extern u16 D_002BB2B8_as_u16_a[];
extern u16 D_002BB2C8_as_u16_a[];
extern s32 D_002BB2E0_as_s32_a[];
extern s32 D_002BB320_as_s32_a[];
extern u16 D_002BB338_as_u16_a[];
extern u16 D_002BB348_as_u16_a[];
extern u16 D_002BB358_as_u16_a[];
extern u16 D_002BB368_as_u16_a[];
extern u16 D_002BB378_as_u16_a[];
extern u16 D_002BB388_as_u16_a[];
extern u16 D_002BB398_as_u16_a[];
extern s32 D_002BB3B0_as_s32_a[];
extern s32 D_002BB3F0_as_s32_a[];

void func_001AD770(void) {
    s32 *dst;
    s32 *src;
    s32 i;
    s32 j;

    dst = D_002BB3F0_as_s32_a;
    src = D_0026B920;
    reg_d0.w = 4;
    do {
        *dst = *src;
        src++;
        dst++;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    g_high_score = D_002BB3F0_as_s32_a[0];
    reg_a0 = (u8 *) D_002BB338_as_u16_a;
    reg_a1 = (u8 *) D_0026B938;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB3B0_as_s32_a;
    reg_a1 = (u8 *)D_0026B950;
    reg_d0.w = 4;
    do {
        *(s32 *) reg_a0 = *(s32 *) reg_a1;
        reg_a1 += 4;
        reg_a0 += 4;
        *(s32 *) reg_a0 = *(s32 *) reg_a1;
        reg_a1 += 4;
        reg_a0 += 4;
        *(s32 *) reg_a0 = *(s32 *) reg_a1;
        reg_a1 += 4;
        reg_a0 += 4;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB358_as_u16_a;
    reg_a1 = (u8 *) D_0026B990;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB378_as_u16_a;
    reg_a1 = (u8 *) D_0026B9A0;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB368_as_u16_a;
    reg_a1 = (u8 *) D_0026B9B0;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB348_as_u16_a;
    reg_a1 = (u8 *) D_0026B9C0;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB398_as_u16_a;
    reg_a1 = (u8 *) D_0026B9D0;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB388_as_u16_a;
    reg_a1 = (u8 *) D_0026BA60;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    for (i = 0; i < 5; i++) {
        D_002BB2A8_as_u16_a[i] = D_002BB378_as_u16_a[i];
        D_002BB298_as_u16_a[i] = D_002BB368_as_u16_a[i];
        D_002BB2C8_as_u16_a[i] = D_002BB398_as_u16_a[i];
        D_002BB2B8_as_u16_a[i] = D_002BB388_as_u16_a[i];
        D_002BB288_as_u16_a[i] = D_002BB358_as_u16_a[i];
        D_002BB320_as_s32_a[i] = D_002BB3F0_as_s32_a[i];
        D_002BB268_as_u16_a[i] = D_002BB338_as_u16_a[i];
        D_002BB278_as_u16_a[i] = D_002BB348_as_u16_a[i];
        D_002BB1D8_as_u16_a[i] = D_002BB378_as_u16_a[i];
        D_002BB1C8_as_u16_a[i] = D_002BB368_as_u16_a[i];
        D_002BB1F8_as_u16_a[i] = D_002BB398_as_u16_a[i];
        D_002BB1E8_as_u16_a[i] = D_002BB388_as_u16_a[i];
        D_002BB1B8_as_u16_a[i] = D_002BB358_as_u16_a[i];
        D_002BB250_as_s32_a[i] = D_002BB3F0_as_s32_a[i];
        D_002BB198_as_u16_a[i] = D_002BB338_as_u16_a[i];
        D_002BB1A8_as_u16_a[i] = D_002BB348_as_u16_a[i];
    }
    for (i = 0; i < 15; i++) {
        D_002BB2E0_as_s32_a[i] = D_002BB3B0_as_s32_a[i];
        D_002BB210_as_s32_a[i] = D_002BB3B0_as_s32_a[i];
    }
    for (i = 0; i < 5; i++) {
        D_002BB320_as_s32_a[i] = D_0026B9E0[i];
        D_002BB278_as_u16_a[i] = 0;
        D_002BB2C8_as_u16_a[i] = 0;
        D_002BB288_as_u16_a[i] = 0x99;
        for (j = 0; j < 30; j++) {
            D_002BB100_as_s8_a5_a30[i][j] = D_0025F6D0[i][j];
        }
        for (j = 23; j < 30; j++) {
            D_002BB100_as_s8_a5_a30[i][j] = 0;
        }
        for (j = 0; j < 30; j++) {
            D_002BB060_as_s8_a5_a30[i][j] = D_0025F6D0[i][j];
        }
        for (j = 23; j < 30; j++) {
            D_002BB060_as_s8_a5_a30[i][j] = 0;
        }
    }
    reg_a0 = (u8 *) D_002BB2E0_as_s32_a;
    reg_a1 = (u8 *)D_0026BA20;
    reg_d0.w = 4;
    do {
        *(s32 *) reg_a0 = *(s32 *) reg_a1;
        reg_a1 += 4;
        reg_a0 += 4;
        *(s32 *) reg_a0 = *(s32 *) reg_a1;
        reg_a1 += 4;
        reg_a0 += 4;
        *(s32 *) reg_a0 = *(s32 *) reg_a1;
        reg_a1 += 4;
        reg_a0 += 4;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB2A8_as_u16_a;
    reg_a1 = (u8 *) D_0026B9F8;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB298_as_u16_a;
    reg_a1 = (u8 *) D_0026BA08;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    if (g_game_mode == 2) {
        for (i = 0; i < 5; i++) {
            D_002BB348_as_u16_a[i] = 0;
            D_002BB398_as_u16_a[i] = 0;
        }
        for (i = 0; i < 5; i++) {
            D_002BB3F0_as_s32_a[i] = D_002BB320_as_s32_a[i];
            D_002BB358_as_u16_a[i] = D_002BB288_as_u16_a[i];
            D_002BB378_as_u16_a[i] = D_002BB2A8_as_u16_a[i];
            D_002BB368_as_u16_a[i] = D_002BB298_as_u16_a[i];
        }
        for (i = 0; i < 15; i++) {
            D_002BB3B0_as_s32_a[i] = D_002BB2E0_as_s32_a[i];
        }
    }
}

typedef struct {
    u8 a[0x5A];
    u8 b[0x5A];
} Pair90;

typedef struct {
    u8 a[0xA];
    u8 b[0xA];
} Pair10;

extern u16 g_p2_hyper_effect_delay;
extern s16 g_p1_hyper_effect_delay_as_s16;
extern s16 g_p2_hyper_effect_flag_as_s16;
extern s16 g_p1_hyper_effect_flag_as_s16;
extern s16 g_p2_hyper_effect_frame_as_s16;
extern u16 g_p1_hyper_effect_frame;
extern s32 g_p2_hyper_effect_sprite;
extern s32 g_p1_hyper_effect_sprite;
extern s16 g_score_task_active_as_s16;
extern s16 g_score_panel_intro_as_s16;
extern u16 g_hyper_debug_check;
extern s16 g_boss_double_speed_as_s16;
extern s16 g_hyper_level_hit_scratch_as_s16;
extern s16 g_hyper_hit_scratch_as_s16;
extern s16 g_boss_hyper_wait_as_s16;
extern s16 g_p2_hyper_items_pending_as_s16;
extern u16 g_p1_hyper_items_pending;
extern s16 g_p2_hyper_items_as_s16;
extern s16 g_p1_hyper_items_as_s16;
extern s16 g_p2_hyper_in_effect_as_s16;
extern s16 g_p1_hyper_in_effect_as_s16;
extern s16 g_p2_hyper_level_as_s16;
extern s16 g_p1_hyper_level_as_s16;
extern s16 g_hyper_text_slide_as_s16;
extern s16 g_p2_hyper_combo_decay_as_s16;
extern s16 g_p1_hyper_combo_decay_as_s16;
extern s16 g_p2_hyper_gauge_as_s16;
extern s16 g_p1_hyper_gauge_as_s16;
extern s16 g_p2_hyper_total_as_s16;
extern s16 g_p1_hyper_total_as_s16;
extern s16 g_p2_hyper_time_as_s16;
extern s16 g_p1_hyper_time_as_s16;
extern s16 g_p2_hyper_active_as_s16;
extern s16 g_p1_hyper_active_as_s16;
extern s16 g_p2_shot_hyper_timer_as_s16;
extern s16 g_p1_shot_hyper_timer_as_s16;
extern s16 g_p2_laser_hyper_timer_as_s16;
extern s16 g_p1_laser_hyper_timer_as_s16;
extern s16 g_p2_max_hits_as_s16;
extern s16 g_p1_max_hits_as_s16;
extern u16 g_boss_near_death;
extern s16 g_boss_hit_carry_as_s16;
extern s16 g_max_combo_time_as_s16;
extern s16 g_p2_combo_at_bomb_as_s16;
extern u16 g_p1_combo_at_bomb;
extern s32 g_score_scratch;
extern s16 g_max_level_display_timer_as_s16;
extern s32 g_maximum_text_anim_sprite;
extern s16 g_maximum_text_anim_frame_as_s16;
extern u16 g_maximum_text_anim_delay;
extern s32 g_hyper_text_anim_sprite;
extern s16 g_hyper_text_anim_frame_as_s16;
extern s16 g_hyper_text_anim_delay_as_s16;
extern u8 g_p2_score_panel_flags;
extern u8 g_p1_score_panel_flags;
extern u16 g_score_check_billions;
extern s32 g_score_check_scratch;
extern s32 g_p2_score_pending;
extern s32 g_p1_score_pending;
extern s32 g_p2_extend_table_as_s32;
extern s32 g_p1_extend_table;
extern s16 g_p2_extend_setting_as_s16;
extern u16 g_p1_extend_setting;
extern u32 g_p2_extend_score_as_u32;
extern u32 g_p1_extend_score_as_u32;
extern s16 g_high_score_digits_as_s16;
extern s16 g_high_score_billions_as_s16;
extern u32 g_high_score_as_u32;
extern u8 g_p2_position_trail_as_u8_a[];
extern u8 g_p1_position_trail_as_u8_a[];
extern Pair10 D_002BAF30_as_Pair10;
extern Pair90 D_002BAF50_as_Pair90;
extern u8 D_002BB010[];

void func_001AE490(void) {
    s32 i;

    g_high_score_billions_as_s16 = 0;
    g_p2_score_billions = 0;
    g_p1_score = g_p2_score = g_high_score_as_u32 = (g_p1_score_billions = 0);
    for (i = 0; i < 0x24; i++) {
        ((u16 *)D_002BB010)[i] = 0;
    }
    g_p2_score_pending = 0;
    g_p1_score_pending = 0;
    g_p2_extend_table_as_s32 = 0;
    g_p1_extend_table = 0;
    g_p2_extend_setting_as_s16 = 0;
    g_p1_extend_score_as_u32 = g_p2_extend_score_as_u32 = (g_p1_extend_setting = 0);
    g_p2_score_billions_saved = 0;
    g_p1_score_saved = g_p2_score_saved = (g_p1_score_billions_saved = 0);
    g_p2_score_digits = 0;
    g_high_score_digits_as_s16 = 0;
    g_p1_score_digits = 0;
    for (i = 0; i < 0x5A; i++) {
        D_002BAF50_as_Pair90.a[i] = 0;
    }
    for (i = 0; i < 0x5A; i++) {
        D_002BAF50_as_Pair90.b[i] = 0;
    }
    for (i = 0; i < 0xA; i++) {
        D_002BAF30_as_Pair10.a[i] = 0;
    }
    for (i = 0; i < 0xA; i++) {
        D_002BAF30_as_Pair10.b[i] = 0;
    }
    g_p2_score_panel_flags = 0;
    g_score_check_scratch = g_score_check_billions = (g_p1_score_panel_flags = 0);
    g_maximum_text_anim_sprite = 0;
    g_maximum_text_anim_frame_as_s16 = 0;
    g_hyper_text_anim_sprite = (g_maximum_text_anim_delay = 0);
    g_hyper_text_anim_frame_as_s16 = 0;
    g_hyper_text_anim_delay_as_s16 = 0;
    g_boss_hit_carry_as_s16 = 0;
    g_max_combo_time_as_s16 = 0;
    g_p2_combo_at_bomb_as_s16 = 0;
    g_score_scratch = (g_p1_combo_at_bomb = 0);
    g_max_level_display_timer_as_s16 = 0;
    g_p1_hit_display_timer_as_s16 = 0;
    g_p1_chain_points_display_timer = 0;
    g_p1_chain_first_score = g_p1_chain_first_score_shown = (g_p1_combo_timer = 0);
    g_score_player_flag_as_s16 = 0;
    g_p1_hit10_anim_count_as_s16 = 0;
    g_p1_hit10_color_timer_as_s16 = 0;
    g_p1_hit10_display_timer = 0;
    g_p1_combo_break_color_timer_as_s16 = 0;
    g_p1_laser_hit_timer_as_s16 = 0;
    g_p1_hits_shown_as_s16 = 0;
    g_p1_chain_points = g_p1_chain_points_shown = g_p1_chain_points_shown2 = (g_p1_hits = 0);
    g_p2_chain_points_display_timer = 0;
    g_p2_chain_first_score = g_p2_chain_first_score_shown = (g_p2_combo_timer = 0);
    g_p1_laser_hit_step_as_s16 = 0;
    g_p2_hit10_color_timer_as_s16 = 0;
    g_p2_hit10_display_timer = 0;
    g_p2_combo_break_color_timer_as_s16 = 0;
    g_p2_hit_display_timer_as_s16 = 0;
    g_p2_laser_hit_step_as_s16 = 0;
    g_p2_laser_hit_timer_as_s16 = 0;
    g_p2_hits_shown_as_s16 = 0;
    g_p2_chain_points = g_p2_chain_points_shown = g_p2_chain_points_shown2 = (g_p2_hits = 0);
    g_p2_hit10_anim_count_as_s16 = 0;
    g_boss_score = 0;
    g_boss_hit_bonus = 0;
    g_boss_hit_bonus_timer_as_s16 = 0;
    g_boss_hit_palette = 0;
    g_boss_hits_as_s16 = 0;
    g_boss_hit_anim_count_as_s16 = 0;
    g_boss_hit_decay_timer_as_s16 = 0;
    g_boss_hp_bar_move_count_as_s16 = 0;
    g_boss_hp_bar_flags_as_s16 = 0;
    g_lives_display_move_x_as_s16 = 0;
    g_lives_display_move_y_as_s16 = 0;
    g_boss_explosion_flash_as_s16 = 0;
    g_boss_hp_unit = g_boss_hp_as_s32 = (g_boss_near_death = 0);
    g_p2_shot_hyper_timer_as_s16 = 0;
    g_p1_shot_hyper_timer_as_s16 = 0;
    g_p2_laser_hyper_timer_as_s16 = 0;
    g_p1_laser_hyper_timer_as_s16 = 0;
    g_p2_max_hits_as_s16 = 0;
    g_p1_max_hits_as_s16 = 0;
    g_hyper_text_slide_as_s16 = 0;
    g_p2_hyper_combo_decay_as_s16 = 0;
    g_p1_hyper_combo_decay_as_s16 = 0;
    g_p2_hyper_gauge_as_s16 = 0;
    g_p1_hyper_gauge_as_s16 = 0;
    g_p2_hyper_total_as_s16 = 0;
    g_p1_hyper_total_as_s16 = 0;
    g_p2_hyper_time_as_s16 = 0;
    g_p1_hyper_time_as_s16 = 0;
    g_p2_hyper_active_as_s16 = 0;
    g_p1_hyper_active_as_s16 = 0;
    g_p2_hyper_items_as_s16 = 0;
    g_p1_hyper_items_as_s16 = 0;
    g_p2_hyper_in_effect_as_s16 = 0;
    g_p1_hyper_in_effect_as_s16 = 0;
    g_p2_hyper_level_as_s16 = 0;
    g_p1_hyper_level_as_s16 = 0;
    for (i = 0; i < 0x10; i++) {
        ((s32 *)g_p1_position_trail_as_u8_a)[i] = 0;
    }
    for (i = 0; i < 0x10; i++) {
        ((s32 *)g_p2_position_trail_as_u8_a)[i] = 0;
    }
    g_hyper_text_anim_delay_as_s16 = 1;
    g_hyper_text_anim_frame_as_s16 = 0x38;
    g_p1_hyper_effect_sprite = g_p2_hyper_effect_sprite = (u16)(reg_d0.w = 0);
    g_maximum_text_anim_frame_as_s16 = 0x54;
    g_boss_double_speed_as_s16 = 0;
    g_hyper_level_hit_scratch_as_s16 = 0;
    g_hyper_hit_scratch_as_s16 = 0;
    g_boss_hyper_wait_as_s16 = 0;
    g_p2_hyper_items_pending_as_s16 = 0;
    g_p1_hyper_items_pending = 0;
    g_score_task_active_as_s16 = 0;
    g_score_panel_intro_as_s16 = 0;
    g_hyper_debug_check = 0;
    g_p2_hyper_effect_delay = 0;
    g_p1_hyper_effect_delay_as_s16 = 0;
    g_p2_hyper_effect_flag_as_s16 = 0;
    g_p1_hyper_effect_flag_as_s16 = 0;
    g_p2_hyper_effect_frame_as_s16 = 0;
    g_p1_hyper_effect_frame = 0;
    g_maximum_text_anim_delay = 0;
    g_p1_score = reg_d0.w;
    g_p2_score = reg_d0.w;
    g_p1_score_saved = reg_d0.w;
    g_p2_score_saved = reg_d0.w;
    g_p1_score_billions = reg_d0.h[0];
    g_p2_score_billions = reg_d0.h[0];
    g_p1_score_billions_saved = reg_d0.h[0];
    g_p2_score_billions_saved = reg_d0.h[0];
    g_p1_score_digits = reg_d0.h[0];
    g_p2_score_digits = reg_d0.h[0];
    g_p1_score_panel_flags = reg_d0.b[0];
    g_p2_score_panel_flags = reg_d0.b[0];
}

s32 func_001AE9A0(u32 *arg0, u32 *arg1) {
    u32 b;
    u32 a;
    u32 tmp;
    u32 res;
    u32 digit;
    s32 carry;
    s32 i;

    a = *arg0;
    b = *arg1;
    tmp = 0;
    carry = 0;
    for (i = 0; i < 8; i++) {
        digit = carry + ((b & 0xF) + (a & 0xF));
        carry = 0;
        if (digit >= 0xAU) {
            carry = 1;
            digit -= 0xA;
        }
        tmp <<= 4;
        tmp |= digit;
        b >>= 4;
        a >>= 4;
    }
    res = 0;
    for (i = 0; i < 8; i++) {
        res <<= 4;
        res |= tmp & 0xF;
        tmp >>= 4;
    }
    *arg1 = res;
    return carry;
}

extern s32 g_p2_extend_setting_as_s32;
extern s32 g_p1_extend_setting_as_s32;
extern s32 g_p2_extend_score;
extern s32 g_p1_extend_score;
extern s32 g_p2_score_billions_as_s32;
extern s32 g_p1_score_billions_as_s32;
extern s32 g_p1_score_as_s32;
extern s32 D_0028E76C_as_s32;
extern s32 g_p2_lives_as_s32;
extern s32 g_p1_lives_as_s32;

void func_001AEA80(void) {
    reg_a0 = (u8 *)(&D_0028E76C_as_s32);
    reg_a1 = (u8 *)(&g_p1_score_pending);
    reg_a2 = (u8 *)(&g_p1_extend_score);
    reg_a3 = (u8 *)(&g_p1_lives_as_s32);
    reg_a4 = (u8 *)(&g_p1_extend_setting_as_s32);
    reg_a6 = (u8 *)(&g_p1_score_billions_as_s32);
    reg_d7.w = 0;
    func_001AEB10();
    reg_a0 = (u8 *)(&g_p1_score_as_s32);
    reg_a1 = (u8 *)(&g_p2_score_pending);
    reg_a2 = (u8 *)(&g_p2_extend_score);
    reg_a3 = (u8 *)(&g_p2_lives_as_s32);
    reg_a4 = (u8 *)(&g_p2_extend_setting_as_s32);
    reg_a6 = (u8 *)(&g_p2_score_billions_as_s32);
    reg_d7.w = 1;
    func_001AEB10();
}

s32 sfx_extend();
s32 func_001AAC00();
s32 func_001AC3A0();
s32 func_001AC5F0();
extern u8 D_0028E304;
extern u16 g_high_score_digits;
extern u16 g_high_score_billions;
extern u8 g_simulation_active;
extern u16 D_006E5C06[];
#ifdef DEATH_LABEL
extern u8 death_D_00290DBC;
extern s16 g_player2[];
extern s16 g_player1[];
extern u16 death_D_0068DAA6[];
extern u16 death_D_0068DAA8[];
extern u16 death_D_0068DAB0[];
extern u16 death_D_0068DAB2[];
extern u16 D_002BAF30[];
extern u16 D_002BAF3A[];
extern u32 D_0028ED50_as_u32;
extern u16 D_0028ED4C;
extern u32 D_0028ED44_as_u32;
extern u16 D_0028ED40;
extern u32 g_p1_score;
extern u16 g_p1_score_billions;
extern u32 g_p2_score;
extern u16 g_p2_score_billions;
#endif

void func_001AEB10(void) {
    u16 t1;
    u16 t2;
    u32 *t3;

#ifdef DEATH_LABEL
    if (death_D_00290DBC != 0) {
        if (g_player1[0] < 0) {
            death_D_0068DAA8[0] = 0;
            D_002BAF30[0] = 1;
            death_D_0068DAA6[0] = 0xC030;
            g_p1_score = D_0028ED50_as_u32;
            g_p1_score_billions = D_0028ED4C;
        }
        if (g_player2[0] < 0) {
            death_D_0068DAB2[0] = 0;
            D_002BAF3A[0] = 1;
            death_D_0068DAB0[0] = 0xC030;
            g_p2_score = D_0028ED44_as_u32;
            g_p2_score_billions = D_0028ED40;
        }
        g_score_check_billions = 0;
        g_score_check_scratch = 0;
        goto no_extend;
    }
#endif
    t3 = (u32 *)(reg_a1);
    reg_a1 = (u8 *)t3 + 4;
    switch (*(u32 *)t3) {
    case 0:
        break;
    default:
        if (*(s16 *)reg_a3 < 0) {
            reg_d6.w = 0;
            *(u32 *)(reg_a1 - 4) = (u32) reg_d6.w;
            return;
        }
        g_score_check_scratch = *(s32 *)(reg_a0 - 4);
        g_score_check_billions = ENTITY(reg_a6)->flags.h;
        reg_a0 -= 4;
        reg_a1 -= 4;
        cond_flag = 0;
        reg_d6.h[0] = 0;
        if (func_001AE9A0((void *)reg_a1, (void *)reg_a0) != 0) {
            *(u16 *)reg_a6 += 1;
            if (ENTITY(reg_a6)->flags.h == 0xA) {
                *(u32 *)reg_a0 = 0x99999999U;
                ENTITY(reg_a6)->flags.h = 9;
            }
        } else {
#ifdef DEATH_LABEL
no_extend:
#endif
            reg_d0.w = *(u32 *)reg_a2;
            if (((g_simulation_active == 0) || (D_006E5C06[0] != 0x14)) && (D_0028E304 == 0) && (reg_d0.w != -1U) && ((u32) *(u32 *)reg_a0 >= (u32) reg_d0.w)) {
                t2 = (u16) *(s16 *)reg_a3;
                if (t2 != 0x14) {
                    *(s16 *)reg_a3 = t2 + 1;
                    func_001AAC00();
                    sfx_extend();
                    if (reg_d7.h[0] == 0) {
                        func_001AC3A0();
                    } else {
                        func_001AC5F0();
                    }
                }
            }
        }
        reg_d6.w = 0;
        *(u32 *)reg_a1 = reg_d6.w;
        reg_a1 += 4;
        if (reg_d7.h[0] == 0) {
            func_001AED30();
        } else {
            func_001AED60();
        }
        reg_d0.h[0] = g_high_score_billions;
        t1 = ENTITY(reg_a6)->flags.h;
        if ((s32) t1 >= (s32) reg_d0.h[0]) {
            if (t1 != reg_d0.h[0]) {
                g_high_score_billions = t1;
                goto next_1;
            }
            reg_d0.w = g_high_score_as_u32;
            if ((u32) reg_d4.w > (u32) reg_d0.w) {
next_1:
                g_high_score_as_u32 = reg_d4.w;
                g_high_score_digits = reg_d6.h[0];
            }
        }
    }
}

extern Reg32 reg_d0;
extern u8 D_002BAF50_as_u8_a[];


void func_001AED30(void) {
    reg_a0 = (u8 *)((u32 *)D_002BAF50_as_u8_a);
    reg_d0.w = g_p1_score;
    reg_d6.h[0] = g_p1_score_digits;
    reg_d4.w = reg_d0.w;
    func_001AED90();
}

extern u8 D_002BAFAA_as_u8_a[];

void func_001AED60(void) {
    reg_a0 = D_002BAFAA_as_u8_a;
    reg_d0.w = g_p2_score;
    reg_d6.h[0] = g_p2_score_digits;
    reg_d4.w = reg_d0.w;
    func_001AED90();
}

extern u32 g_score_check_scratch_as_u32;

void func_001AED90(void) {
    u32 tmp;
    u32 d2;

    reg_d5.w = 8;
    reg_tmp7.w = reg_d7.w;
    reg_d7.h[1] = reg_d7.h[0];
    reg_d7.h[0] = 0;
    reg_d1.h[0] = ENTITY(reg_a6)->flags.h;
    if (g_score_check_billions != reg_d1.h[0]) {
        reg_d7.h[0] = 1;
        *(s16 *)(reg_a0 + 0) = 1;
        reg_d1.h[0] += 0xC030;
        *(u16 *)(reg_a0 + 6) = reg_d1.h[0];
    }
    if (reg_d1.h[0] != 0) {
        reg_d7.h[0] = 1;
    }
    reg_d1.w = g_score_check_scratch_as_u32;
    goto next_2;
loop_1:
    reg_d2.w = 0xF;
    reg_tmp.w = reg_d0.w;
    reg_d0.w <<= 4;
    reg_tmp1.w = reg_d1.w;
    reg_d1.w <<= 4;
    reg_d0.w |= reg_tmp.w >> 0x1C;
    reg_d1.w |= reg_tmp1.w >> 0x1C;
    d2 = reg_d2.w & reg_d0.w;
    reg_d2.w = d2;
    if ((d2 == 0) && (reg_d7.h[0] == 0)) {
        if (*(u16 *)(reg_a0 + 6) != 0) {
            *(s16 *)(reg_a0 + 0) = 1;
            *(u16 *)(reg_a0 + 6) = 0;
        }
    } else {
        reg_d7.h[0] = 1;
        if (*(u16 *)(reg_a0 + 6) == 0) {
            goto next_1;
        }
        reg_d3.w = 0xF;
        reg_d3.w &= reg_d1.w;
        if (reg_d2.h[0] != reg_d3.h[0]) {
next_1:
            *(s16 *)(reg_a0 + 0) = 1;
            reg_d2.h[0] += 0xC030;
            *(u16 *)(reg_a0 + 6) = reg_d2.h[0];
        }
    }
next_2:
    reg_a0 += 0xA;
    tmp = reg_d5.h[0] - 1;
    reg_d5.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
    reg_tmp7.w = reg_d7.w;
    reg_d7.h[1] = reg_d7.h[0];
    reg_d7.h[0] = reg_tmp7.h[1];
}

extern u8 D_0029BF30[];
extern u8 D_0029BF31[];
extern u8 D_0029BF40[];
extern u8 D_0029BF41[];

void func_001AEF50(void) {
    u8 *p;

    *(p = D_0029BF41) = 0xFF;
    D_0029BF40[0] = 0xFF;
    reg_d5.w = 0;
    reg_d6.h[0] = reg_d0.h[0];
    reg_d7.h[0] = reg_d2.h[0];
    func_001AF010();
    if (cond_flag != 0) goto next_1;
    *p = reg_d6.b[0];
    D_0029BF40[0] = reg_d7.b[0];
next_1:
    *(p = D_0029BF31) = 0xFF;
    D_0029BF30[0] = 0xFF;
    reg_d5.w = 1;
    reg_d6.h[0] = reg_d1.h[0];
    reg_d7.h[0] = reg_d3.h[0];
    func_001AF010();
    if (cond_flag != 0) goto next_2;
    *p = reg_d6.b[0];
    D_0029BF30[0] = reg_d7.b[0];
next_2:
    return;
}

extern u16 D_0028C11C[];
extern u16 D_0028C120[];


void func_001AF010(void) {
    u32 save_d0;
    u32 save_d1;
    u32 t;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    if (reg_d6.h[0] != 0xFF) goto next_3;
    if (reg_d5.h[0] != 0) goto next_1;
    reg_d6.h[0] = 0;
    reg_d7.h[0] = 0;
    goto block_set;
next_1:
    reg_d6.h[0] = 1;
    reg_d7.h[0] = 2;
    goto block_set;
next_3:
    reg_d0.w = 1;
loop_4:
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_a0 = (u8 *)D_0028C11C;
    reg_d1.h[0] = (reg_d1.h[0]) ? *(u16 *)(reg_a0 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    if (reg_d6.h[0] != reg_d1.h[0]) goto next_5;
    reg_d6.h[0] = reg_d0.h[0];
    goto next_6;
next_5:
    t = --reg_d0.h[0];
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_4;
next_6:
    reg_d0.w = 2;
loop_7:
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_a0 = (u8 *)D_0028C120;
    reg_d1.h[0] = (reg_d1.h[0]) ? *(u16 *)(reg_a0 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    if (reg_d7.h[0] != reg_d1.h[0]) goto next_8;
    reg_d7.h[0] = reg_d0.h[0];
    goto next_9;
next_8:
    t = --reg_d0.h[0];
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_7;
next_9:
    reg_d1.w = save_d1;
    reg_d0.w = save_d0;
    cond_flag = 0;
    return;
block_set:
    reg_d1.w = save_d1;
    reg_d0.w = save_d0;
    cond_flag = 1;
}

void func_001AF1A0() {
    reg_d6.h[0] = g_p1_ship_type;
    reg_d7.h[0] = g_p1_power_style;
    if (*(u8 *)(reg_a5 + 6) != 0) {
        reg_d6.h[0] = g_p2_ship_type;
        reg_d7.h[0] = g_p2_power_style;
    }
    reg_d5.w = 0;
    reg_d5.b[0] = *(u8 *)(reg_a5 + 6);
    func_001AF010();
    *(u8 *)(reg_a5 + 0xF) = (u8) reg_d6.b[0];
    *(u8 *)(reg_a5 + 0xE) = (u8) reg_d7.b[0];
}

s32 func_001AF310();

void func_001AF210(void) {
    reg_d7.w = 0;
    reg_d7.b[0] = *(u8 *)(reg_a5 + 0xE);
loop_1:
    func_001AF310();
    if (cond_flag != 0) {
        reg_d7.b[0] += 1;
        if ((s8) reg_d7.b[0] > 2) {
            reg_d7.w = 0;
        }
        goto loop_1;
    }
    *(u8 *)(reg_a5 + 0xE) = (u8) reg_d7.b[0];
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 8);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0xA);
    reg_a4 = (u8 *)reg_tmp.w;
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0x10);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x12);
    reg_a0 = (u8 *)(reg_tmp.w);
    *(u8 *)reg_a0 = *(u8 *)(reg_a5 + 0xE);
}
