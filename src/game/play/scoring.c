#include "common.h"
#include "score_cell.h"
#include "black_label.h"
#include "score_tables.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

void rank_entry_fill(void);
void rank_entry_place(void);
void rank_tables_shift(void);
void score_pending_apply_side(void);
void p1_score_cells_refresh(void);
void p2_score_cells_refresh(void);
void score_cells_refresh(void);
void join_select_choice_from_game(void);

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
extern u8 p1_rank_entry_insert_buffer[];

void p1_rank_entry_insert(void) {
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
    reg_a4 = (u8 *)p1_rank_entry_insert_buffer;
    reg_d6.w = 0xFF;
    reg_d7.w = g_p1_score;
    reg_d5.h[0] = g_p1_score_billions;
    reg_d0.h[0] = g_p1_ship_type;
    reg_d1.h[0] = g_p1_power_style;
    reg_d2.h[0] = g_p1_max_hits;
    reg_d3.h[0] = g_p1_score_digits;
    rank_entry_fill();
}

extern u16 g_p2_max_hits;
extern u16 g_p2_score_digits;
extern u16 g_p2_score_billions;
extern u32 g_p2_score;
extern u16 g_p2_power_style;
extern u16 g_p2_ship_type;
extern u8 p2_rank_entry_insert_buffer[];

void p2_rank_entry_insert(void) {
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
    reg_a4 = (u8 *)p2_rank_entry_insert_buffer;
    reg_d6.w = 0xFE;
    reg_d7.w = g_p2_score;
    reg_d5.h[0] = g_p2_score_billions;
    reg_d0.h[0] = g_p2_ship_type;
    reg_d0.h[0] += 4;
    reg_d1.h[0] = g_p2_power_style;
    reg_d2.h[0] = g_p2_max_hits;
    reg_d3.h[0] = g_p2_score_digits;
    rank_entry_fill();
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

void rank_entry_fill(void) {
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
    rank_entry_place();
    if (cond_flag != 0) {
        goto block_50;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0xC);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xE);
    reg_a4 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
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

extern s8 rank_text_blank[30];
extern u8 g_game_mode;
extern s32 g_ranking_entry_index;
extern u8 g_replay_mode;
extern u8 g_stored_ranking_texts[5][30];
extern u8 g_death_label_ranking_texts[5][30];
extern u8 D_002BB352[];
extern u8 D_002BB362[];
extern u8 D_002BB372[];
extern u8 D_002BB382[];
extern u8 D_002BB392[];
extern u8 D_002BB3A2[];
extern u8 D_002BB3EC[];

void rank_entry_place(void) {
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
    rank_tables_shift();
    if ((s16) reg_d1.h[0] < 0) {
        cond_flag = 1;
        goto block_rts;
    }
    cond_flag = 0;
    if (g_game_mode == 2) {
        g_ranking_entry_index = 4 - reg_d1.w;
        printf((const char *)"---death--rank[%d]\n", g_ranking_entry_index);
        if (g_ranking_entry_index != 4) {
            for (i = 4; g_ranking_entry_index < i; i--) {
                for (j = 0; j < 30; j++) {
                    g_stored_ranking_texts[i][j] = g_stored_ranking_texts[i - 1][j];
                }
            }
        }
    } else {
        g_ranking_entry_index = 4 - reg_d1.w;
        printf((const char *)"-----rank[%d]\n", g_ranking_entry_index);
        if (g_ranking_entry_index != 4) {
            for (i = 4; g_ranking_entry_index < i; i--) {
                for (j = 0; j < 30; j++) {
                    g_death_label_ranking_texts[i][j] = g_death_label_ranking_texts[i - 1][j];
                }
            }
        }
        for (j = 0; j < 30; j++) {
            g_death_label_ranking_texts[g_ranking_entry_index][j] = rank_text_blank[j];
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
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a1);
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

void rank_tables_shift(void) {
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

extern u16 g_p2_laser_hit_step;
extern u16 g_p2_laser_hit_timer;
extern u16 g_p2_hits_shown;
extern u16 g_p2_hits;
extern s32 g_p2_chain_points_shown2;
extern s32 g_p2_chain_points_shown;
extern s32 g_p2_chain_points;
extern u16 g_p2_hit10_anim_count;
extern u16 g_p2_hit10_color_timer;
extern s16 g_p2_hit10_display_timer;
extern u16 g_p2_combo_break_color_timer;
extern u16 g_p2_hit_display_timer;
extern s16 g_p2_chain_points_display_timer;
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
extern s16 g_p1_hit10_display_timer;
extern u16 g_p1_combo_break_color_timer;
extern u16 g_p1_hit_display_timer;
extern s16 g_p1_chain_points_display_timer;
extern u16 g_p1_combo_timer;
extern s32 g_p1_chain_first_score_shown;
extern s32 g_p1_chain_first_score;
extern u16 g_score_player_flag;

void chain_states_clear(void) {
    g_p2_laser_hit_step = 0;
    g_p2_laser_hit_timer = 0;
    g_p2_hits_shown = 0;
    g_p2_chain_points = g_p2_chain_points_shown = g_p2_chain_points_shown2 = (g_p2_hits = 0);
    g_p2_hit10_anim_count = 0;
    g_p2_hit10_color_timer = 0;
    g_p2_hit10_display_timer = 0;
    g_p2_combo_break_color_timer = 0;
    g_p2_hit_display_timer = 0;
    g_p2_chain_points_display_timer = 0;
    g_p2_chain_first_score = g_p2_chain_first_score_shown = (g_p2_combo_timer = 0);
    g_p1_laser_hit_step = 0;
    g_p1_laser_hit_timer = 0;
    g_p1_hits_shown = 0;
    g_p1_chain_points = g_p1_chain_points_shown = g_p1_chain_points_shown2 = (g_p1_hits = 0);
    g_p1_hit10_anim_count = 0;
    g_p1_hit10_color_timer = 0;
    g_p1_hit10_display_timer = 0;
    g_p1_combo_break_color_timer = 0;
    g_p1_hit_display_timer = 0;
    g_p1_chain_points_display_timer = 0;
    g_p1_chain_first_score = g_p1_chain_first_score_shown = (g_p1_combo_timer = 0);
    g_score_player_flag = 0;
}

extern u16 g_boss_explosion_flash;
extern u16 g_boss_near_death;
extern u8 *g_boss_hp;
extern s32 g_boss_hp_unit;
extern u16 g_lives_display_move_x;
extern u16 g_lives_display_move_y;
extern u16 g_boss_hp_bar_move_count;
extern s8 g_boss_hp_bar_flags;
extern s32 g_boss_score;
extern s32 g_boss_hit_bonus;
extern u16 g_boss_hit_bonus_timer;
extern s16 g_boss_hit_palette;
extern u16 g_boss_hits;
extern u16 g_boss_hit_anim_count;
extern u16 g_boss_hit_decay_timer;

void boss_hit_state_clear(void)
{
    s32 lowHalfword;

    lowHalfword = (u16)(reg_d0.w = 0);
    g_boss_explosion_flash = 0;
    g_boss_near_death = 0;
#ifdef DDPDOJ_PC
    g_boss_hp = NULL;
#else
    (*(s32 *)&g_boss_hp) = lowHalfword;
#endif
    g_boss_hp_unit = lowHalfword;
    g_lives_display_move_x = 0;
    g_lives_display_move_y = 0;
    g_boss_hp_bar_move_count = 0;
    (*(s16 *)&g_boss_hp_bar_flags) = 0;
    g_boss_score = lowHalfword;
    g_boss_hit_bonus = lowHalfword;
    g_boss_hit_bonus_timer = 0;
    g_boss_hit_palette = 0;
    g_boss_hits = 0;
    g_boss_hit_anim_count = 0;
    g_boss_hit_decay_timer = 0;
}

extern s8 default_rank_texts[5][30];

/* The ranking boards as they are before anyone has played, best place first. */
s32 default_rank_scores[5] = { 0x729671, 0x728094, 0x719354, 0x704468, 0x694352 };
u16 default_rank_score_tops[5] = { 0, 0, 0, 0, 0 };
s32 default_rank_names[5][3] = {
    { 0x60, 0x0C, 0x5C },
    { 0x58, 0x4C, 0x34 },
    { 0x34, 0x00, 0x20 },
    { 0x34, 0x00, 0x2C },
    { 0x1C, 0x00, 0x4C },
};
u16 default_rank_hits[5] = { 0x57, 0x53, 0x24, 0x44, 0x38 };
u16 default_rank_ship_types[5] = { 0, 0, 4, 2, 2 };
u16 default_rank_power_styles[5] = { 4, 4, 2, 4, 2 };
u16 default_rank_continues[5] = { 4, 5, 7, 3, 2 };
u16 default_rank_loops[5] = { 0, 0, 0, 0, 0 };
s32 default_death_label_rank_scores[5] = { 0x770000, 0x760000, 0x750000, 0x740000, 0x730000 };
u16 default_death_label_rank_ship_types[5] = { 0, 2, 0, 0, 2 };
u16 default_death_label_rank_power_styles[5] = { 6, 4, 6, 6, 2 };
s32 default_death_label_rank_names[5][3] = {
    { 0x34, 0x00, 0x2C },
    { 0x4C, 0x00, 0x08 },
    { 0x38, 0x48, 0x0C },
    { 0x30, 0x1C, 0x44 },
    { 0x60, 0x34, 0x48 },
};
u16 default_rank_stages[5] = { 3, 3, 2, 2, 1 };

#ifdef DDPDOJ_BONUS_FEATURES
static s32 black_label_rank_scores[5] = { 0x1182223, 0x846001, 0x816579, 0x775305, 0x699653 };
static s32 black_label_rank_names[5][3] = {
    { 0x38, 0x48, 0x0C }, { 0x28, 0x58, 0x48 }, { 0x20, 0x48, 0x38 },
    { 0x20, 0x30, 0x28 }, { 0x28, 0x30, 0x4C },
};
static u16 black_label_rank_hits[5] = { 0x719, 0x719, 0x719, 0x719, 0x720 };
static u16 black_label_rank_ship_types[5] = { 0, 6, 2, 2, 2 };
static u16 black_label_rank_power_styles[5] = { 6, 4, 6, 4, 4 };
static u16 black_label_rank_continues[5] = { 4, 4, 2, 0, 6 };
static u16 black_label_rank_stages[5] = { 3, 2, 2, 1, 1 };
#endif

extern s32 g_high_score;
extern s8 g_stored_ranking_texts_as_s8_a5_a30[5][30];
extern s8 g_death_label_ranking_texts_as_s8_a5_a30[5][30];
extern u16 g_stored_ranking_score_tops_as_u16_a[];
extern u16 g_stored_ranking_continues[5];
extern u16 g_stored_ranking_hits_as_u16_a[];
extern u16 g_stored_ranking_power_styles_as_u16_a[];
extern u16 g_stored_ranking_ship_types_as_u16_a[];
extern u16 g_stored_ranking_stages_as_u16_a[];
extern u16 g_stored_ranking_loops_as_u16_a[];
extern s32 g_stored_ranking_names[16];
extern s32 g_stored_ranking_scores_as_s32_a[];
extern u16 g_death_label_ranking_score_tops_as_u16_a[];
extern u16 g_death_label_ranking_continues_as_u16_a[];
extern u16 g_death_label_ranking_hits_as_u16_a[];
extern u16 g_death_label_ranking_power_styles_as_u16_a[];
extern u16 g_death_label_ranking_ship_types_as_u16_a[];
extern u16 g_death_label_ranking_stages_as_u16_a[];
extern u16 g_death_label_ranking_loops_as_u16_a[];
extern s32 g_death_label_ranking_names_as_s32_a[];
extern s32 g_death_label_ranking_scores_as_s32_a[];
extern u16 g_ranking_score_tops_as_u16_a[];
extern u16 g_ranking_continues_as_u16_a[];
extern u16 g_ranking_hits_as_u16_a[];
extern u16 g_ranking_power_styles_as_u16_a[];
extern u16 g_ranking_ship_types_as_u16_a[];
extern u16 g_ranking_stages_as_u16_a[];
extern u16 g_ranking_loops_as_u16_a[];
extern s32 g_ranking_names_as_s32_a[];
extern s32 g_ranking_scores_as_s32_a[];

void rankings_set_defaults(void) {
    s32 *dst;
    s32 *src;
    s32 i;
    s32 j;

    dst = g_ranking_scores_as_s32_a;
    src = GAME_RULE(default_rank_scores, black_label_rank_scores);
    reg_d0.w = 4;
    do {
        *dst = *src;
        src++;
        dst++;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    g_high_score = g_ranking_scores_as_s32_a[0];
    reg_a0 = (u8 *) g_ranking_score_tops_as_u16_a;
    reg_a1 = (u8 *) default_rank_score_tops;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) g_ranking_names_as_s32_a;
    reg_a1 = (u8 *)GAME_RULE(default_rank_names, black_label_rank_names);
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
    reg_a0 = (u8 *) g_ranking_hits_as_u16_a;
    reg_a1 = (u8 *) GAME_RULE(default_rank_hits, black_label_rank_hits);
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) g_ranking_ship_types_as_u16_a;
    reg_a1 = (u8 *) GAME_RULE(default_rank_ship_types, black_label_rank_ship_types);
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) g_ranking_power_styles_as_u16_a;
    reg_a1 = (u8 *) GAME_RULE(default_rank_power_styles, black_label_rank_power_styles);
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) g_ranking_continues_as_u16_a;
    reg_a1 = (u8 *) GAME_RULE(default_rank_continues, black_label_rank_continues);
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) g_ranking_loops_as_u16_a;
    reg_a1 = (u8 *) default_rank_loops;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) g_ranking_stages_as_u16_a;
    reg_a1 = (u8 *) GAME_RULE(default_rank_stages, black_label_rank_stages);
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    for (i = 0; i < 5; i++) {
        g_death_label_ranking_ship_types_as_u16_a[i] = g_ranking_ship_types_as_u16_a[i];
        g_death_label_ranking_power_styles_as_u16_a[i] = g_ranking_power_styles_as_u16_a[i];
        g_death_label_ranking_loops_as_u16_a[i] = g_ranking_loops_as_u16_a[i];
        g_death_label_ranking_stages_as_u16_a[i] = g_ranking_stages_as_u16_a[i];
        g_death_label_ranking_hits_as_u16_a[i] = g_ranking_hits_as_u16_a[i];
        g_death_label_ranking_scores_as_s32_a[i] = g_ranking_scores_as_s32_a[i];
        g_death_label_ranking_score_tops_as_u16_a[i] = g_ranking_score_tops_as_u16_a[i];
        g_death_label_ranking_continues_as_u16_a[i] = g_ranking_continues_as_u16_a[i];
        g_stored_ranking_ship_types_as_u16_a[i] = g_ranking_ship_types_as_u16_a[i];
        g_stored_ranking_power_styles_as_u16_a[i] = g_ranking_power_styles_as_u16_a[i];
        g_stored_ranking_loops_as_u16_a[i] = g_ranking_loops_as_u16_a[i];
        g_stored_ranking_stages_as_u16_a[i] = g_ranking_stages_as_u16_a[i];
        g_stored_ranking_hits_as_u16_a[i] = g_ranking_hits_as_u16_a[i];
        g_stored_ranking_scores_as_s32_a[i] = g_ranking_scores_as_s32_a[i];
        g_stored_ranking_score_tops_as_u16_a[i] = g_ranking_score_tops_as_u16_a[i];
        ((u16 *)g_stored_ranking_continues)[i] = g_ranking_continues_as_u16_a[i];
    }
    for (i = 0; i < 15; i++) {
        g_death_label_ranking_names_as_s32_a[i] = g_ranking_names_as_s32_a[i];
        ((s32 *)g_stored_ranking_names)[i] = g_ranking_names_as_s32_a[i];
    }
    for (i = 0; i < 5; i++) {
        g_death_label_ranking_scores_as_s32_a[i] = default_death_label_rank_scores[i];
        g_death_label_ranking_continues_as_u16_a[i] = 0;
        g_death_label_ranking_loops_as_u16_a[i] = 0;
        g_death_label_ranking_hits_as_u16_a[i] = 0x99;
        for (j = 0; j < 30; j++) {
            g_death_label_ranking_texts_as_s8_a5_a30[i][j] = default_rank_texts[i][j];
        }
        for (j = 23; j < 30; j++) {
            g_death_label_ranking_texts_as_s8_a5_a30[i][j] = 0;
        }
        for (j = 0; j < 30; j++) {
            g_stored_ranking_texts_as_s8_a5_a30[i][j] = default_rank_texts[i][j];
        }
        for (j = 23; j < 30; j++) {
            g_stored_ranking_texts_as_s8_a5_a30[i][j] = 0;
        }
    }
    reg_a0 = (u8 *) g_death_label_ranking_names_as_s32_a;
    reg_a1 = (u8 *)default_death_label_rank_names;
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
    reg_a0 = (u8 *) g_death_label_ranking_ship_types_as_u16_a;
    reg_a1 = (u8 *) default_death_label_rank_ship_types;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) g_death_label_ranking_power_styles_as_u16_a;
    reg_a1 = (u8 *) default_death_label_rank_power_styles;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    if (g_game_mode == 2) {
        for (i = 0; i < 5; i++) {
            g_ranking_continues_as_u16_a[i] = 0;
            g_ranking_loops_as_u16_a[i] = 0;
        }
        for (i = 0; i < 5; i++) {
            g_ranking_scores_as_s32_a[i] = g_death_label_ranking_scores_as_s32_a[i];
            g_ranking_hits_as_u16_a[i] = g_death_label_ranking_hits_as_u16_a[i];
            g_ranking_ship_types_as_u16_a[i] = g_death_label_ranking_ship_types_as_u16_a[i];
            g_ranking_power_styles_as_u16_a[i] = g_death_label_ranking_power_styles_as_u16_a[i];
        }
        for (i = 0; i < 15; i++) {
            g_ranking_names_as_s32_a[i] = g_death_label_ranking_names_as_s32_a[i];
        }
    }
}

typedef struct {
    u8 a[0x5A];
    u8 b[0x5A];
} Pair90;

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
extern u16 g_hyper_debug_check;
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
extern u16 g_boss_near_death;
extern u16 g_boss_hit_carry;
extern u16 g_max_combo_time;
extern u16 g_p2_combo_at_bomb;
extern u16 g_p1_combo_at_bomb;
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
extern u16 g_score_check_billions;
extern s32 g_score_check_scratch;
extern s32 g_p2_score_pending;
extern s32 g_p1_score_pending;
extern s32 g_p2_extend_table;
extern s32 g_p1_extend_table;
extern u16 g_p2_extend_setting;
extern u16 g_p1_extend_setting;
extern s32 g_p2_extend_score;
extern s32 g_p1_extend_score;
extern u16 g_high_score_digits;
extern u16 g_high_score_billions;
extern s32 g_p2_position_trail[16];
extern s32 g_p1_position_trail[16];
extern Pair90 g_p1_score_cells_as_Pair90;
extern u8 scores_reset_buffer[];

void scores_reset(void) {
    s32 i;

    g_high_score_billions = 0;
    g_p2_score_billions = 0;
    g_p1_score = g_p2_score = g_high_score = (g_p1_score_billions = 0);
    for (i = 0; i < 0x24; i++) {
        ((u16 *)scores_reset_buffer)[i] = 0;
    }
    g_p2_score_pending = 0;
    g_p1_score_pending = 0;
    g_p2_extend_table = 0;
    g_p1_extend_table = 0;
    g_p2_extend_setting = 0;
    g_p1_extend_score = g_p2_extend_score = (g_p1_extend_setting = 0);
    g_p2_score_billions_saved = 0;
    g_p1_score_saved = g_p2_score_saved = (g_p1_score_billions_saved = 0);
    g_p2_score_digits = 0;
    g_high_score_digits = 0;
    g_p1_score_digits = 0;
    for (i = 0; i < 0x5A; i++) {
        g_p1_score_cells_as_Pair90.a[i] = 0;
    }
    for (i = 0; i < 0x5A; i++) {
        g_p1_score_cells_as_Pair90.b[i] = 0;
    }
    for (i = 0; i < 0xA; i++) {
        g_extra_score_cells.pair.bytes.p1[i] = 0;
    }
    for (i = 0; i < 0xA; i++) {
        g_extra_score_cells.pair.bytes.p2[i] = 0;
    }
    g_p2_score_panel_flags = 0;
    g_score_check_scratch = g_score_check_billions = (g_p1_score_panel_flags = 0);
    g_maximum_text_anim_sprite = 0;
    g_maximum_text_anim_frame = 0;
    g_hyper_text_anim_sprite = (g_maximum_text_anim_delay = 0);
    g_hyper_text_anim_frame = 0;
    g_hyper_text_anim_delay = 0;
    g_boss_hit_carry = 0;
    g_max_combo_time = 0;
    g_p2_combo_at_bomb = 0;
    g_score_scratch = (g_p1_combo_at_bomb = 0);
    g_max_level_display_timer = 0;
    g_p1_hit_display_timer = 0;
    g_p1_chain_points_display_timer = 0;
    g_p1_chain_first_score = g_p1_chain_first_score_shown = (g_p1_combo_timer = 0);
    g_score_player_flag = 0;
    g_p1_hit10_anim_count = 0;
    g_p1_hit10_color_timer = 0;
    g_p1_hit10_display_timer = 0;
    g_p1_combo_break_color_timer = 0;
    g_p1_laser_hit_timer = 0;
    g_p1_hits_shown = 0;
    g_p1_chain_points = g_p1_chain_points_shown = g_p1_chain_points_shown2 = (g_p1_hits = 0);
    g_p2_chain_points_display_timer = 0;
    g_p2_chain_first_score = g_p2_chain_first_score_shown = (g_p2_combo_timer = 0);
    g_p1_laser_hit_step = 0;
    g_p2_hit10_color_timer = 0;
    g_p2_hit10_display_timer = 0;
    g_p2_combo_break_color_timer = 0;
    g_p2_hit_display_timer = 0;
    g_p2_laser_hit_step = 0;
    g_p2_laser_hit_timer = 0;
    g_p2_hits_shown = 0;
    g_p2_chain_points = g_p2_chain_points_shown = g_p2_chain_points_shown2 = (g_p2_hits = 0);
    g_p2_hit10_anim_count = 0;
    g_boss_score = 0;
    g_boss_hit_bonus = 0;
    g_boss_hit_bonus_timer = 0;
    g_boss_hit_palette = 0;
    g_boss_hits = 0;
    g_boss_hit_anim_count = 0;
    g_boss_hit_decay_timer = 0;
    g_boss_hp_bar_move_count = 0;
    (*(s16 *)&g_boss_hp_bar_flags) = 0;
    g_lives_display_move_x = 0;
    g_lives_display_move_y = 0;
    g_boss_explosion_flash = 0;
#ifdef DDPDOJ_PC
    g_boss_hp = NULL;
    g_boss_hp_unit = g_boss_near_death = 0;
#else
    g_boss_hp_unit = (*(s32 *)&g_boss_hp) = (g_boss_near_death = 0);
#endif
    g_p2_shot_hyper_timer = 0;
    g_p1_shot_hyper_timer = 0;
    g_p2_laser_hyper_timer = 0;
    g_p1_laser_hyper_timer = 0;
    g_p2_max_hits = 0;
    g_p1_max_hits = 0;
    g_hyper_text_slide = 0;
    g_p2_hyper_combo_decay = 0;
    g_p1_hyper_combo_decay = 0;
    g_p2_hyper_gauge = 0;
    g_p1_hyper_gauge = 0;
    g_p2_hyper_total = 0;
    g_p1_hyper_total = 0;
    g_p2_hyper_time = 0;
    g_p1_hyper_time = 0;
    g_p2_hyper_active = 0;
    g_p1_hyper_active = 0;
    g_p2_hyper_items = 0;
    g_p1_hyper_items = 0;
    g_p2_hyper_in_effect = 0;
    g_p1_hyper_in_effect = 0;
    g_p2_hyper_level = 0;
    g_p1_hyper_level = 0;
    for (i = 0; i < 0x10; i++) {
        ((s32 *)((u8 *)g_p1_position_trail))[i] = 0;
    }
    for (i = 0; i < 0x10; i++) {
        ((s32 *)((u8 *)g_p2_position_trail))[i] = 0;
    }
    g_hyper_text_anim_delay = 1;
    g_hyper_text_anim_frame = 0x38;
    g_p1_hyper_effect_sprite = g_p2_hyper_effect_sprite = (u16)(reg_d0.w = 0);
    g_maximum_text_anim_frame = 0x54;
    g_boss_double_speed = 0;
    g_hyper_level_hit_scratch = 0;
    g_hyper_hit_scratch = 0;
    g_boss_hyper_wait = 0;
    g_p2_hyper_items_pending = 0;
    g_p1_hyper_items_pending = 0;
    g_score_task_active = 0;
    g_score_panel_intro = 0;
    g_hyper_debug_check = 0;
    g_p2_hyper_effect_delay = 0;
    g_p1_hyper_effect_delay = 0;
    g_p2_hyper_effect_flag = 0;
    g_p1_hyper_effect_flag = 0;
    g_p2_hyper_effect_frame = 0;
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

s32 bcd_add_registers(u32 *arg0, u32 *arg1) {
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

extern s32 g_p2_extend_score;
extern s32 g_p1_extend_score;
extern u16 D_0028E76C;
extern u16 g_p2_lives;
extern u16 g_p1_lives;

void score_pending_apply(void) {
    reg_a0 = SCORE_VALUE_TARGET((u8 *)(&(*(s32 *)&D_0028E76C)), g_p1_score);
    reg_a1 = (u8 *)(&g_p1_score_pending);
    reg_a2 = (u8 *)(&g_p1_extend_score);
    reg_a3 = (u8 *)(&(*(s32 *)&g_p1_lives));
    reg_a4 = (u8 *)(&(*(s32 *)&g_p1_extend_setting));
    reg_a6 = (u8 *)(&(*(s32 *)&g_p1_score_billions));
    reg_d7.w = 0;
    score_pending_apply_side();
    reg_a0 = SCORE_VALUE_TARGET((u8 *)(&(*(s32 *)&g_p1_score)), g_p2_score);
    reg_a1 = (u8 *)(&g_p2_score_pending);
    reg_a2 = (u8 *)(&g_p2_extend_score);
    reg_a3 = (u8 *)(&(*(s32 *)&g_p2_lives));
    reg_a4 = (u8 *)(&(*(s32 *)&g_p2_extend_setting));
    reg_a6 = (u8 *)(&(*(s32 *)&g_p2_score_billions));
    reg_d7.w = 1;
    score_pending_apply_side();
}

s32 sfx_extend();
s32 extend_score_advance();
s32 hud_p1_lives_put();
s32 hud_p2_lives_put();
extern u8 g_setting_start_round;
extern u16 g_high_score_digits;
extern u16 g_high_score_billions;
extern u8 g_simulation_active;
extern u16 D_006E5C06[];
#ifdef DEATH_LABEL
extern u8 death_D_00290DBC;
extern s16 g_player2[];
extern s16 g_player1[];
extern s32 g_replay_start_p1_score;
extern u16 g_replay_start_p1_score_billions;
extern s32 g_replay_start_p2_score;
extern u16 g_replay_start_p2_score_billions;
extern u32 g_p1_score;
extern u16 g_p1_score_billions;
extern u32 g_p2_score;
extern u16 g_p2_score_billions;
#endif

void score_pending_apply_side(void) {
    u16 t1;
    u16 t2;
    u32 *t3;

#ifdef DEATH_LABEL
    if (death_D_00290DBC != 0) {
        if (g_player1[0] < 0) {
            g_extra_score_cells.pair.players[0].attributes = 0;
            g_extra_score_cells.pair.players[0].dirty = 1;
            g_extra_score_cells.pair.players[0].tile = 0xC030;
            g_p1_score = (u32)g_replay_start_p1_score;
            g_p1_score_billions = g_replay_start_p1_score_billions;
        }
        if (g_player2[0] < 0) {
            g_extra_score_cells.pair.players[1].attributes = 0;
            g_extra_score_cells.pair.players[1].dirty = 1;
            g_extra_score_cells.pair.players[1].tile = 0xC030;
            g_p2_score = (u32)g_replay_start_p2_score;
            g_p2_score_billions = g_replay_start_p2_score_billions;
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
#ifdef DDPDOJ_PC
        g_score_check_scratch = *(s32 *)reg_a0;
        g_score_check_billions = ENTITY(reg_a6)->flags.h;
#else
        g_score_check_scratch = *(s32 *)(reg_a0 - 4);
        g_score_check_billions = ENTITY(reg_a6)->flags.h;
        reg_a0 -= 4;
#endif
        reg_a1 -= 4;
        cond_flag = 0;
        reg_d6.h[0] = 0;
        if (bcd_add_registers((void *)reg_a1, (void *)reg_a0) != 0) {
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
            if (((g_simulation_active == 0) || (D_006E5C06[0] != 0x14)) && (g_setting_start_round == 0) && (reg_d0.w != -1U) && ((u32) *(u32 *)reg_a0 >= (u32) reg_d0.w)) {
                t2 = (u16) *(s16 *)reg_a3;
                if (t2 != 0x14) {
                    *(s16 *)reg_a3 = t2 + 1;
                    extend_score_advance();
                    sfx_extend();
                    if (reg_d7.h[0] == 0) {
                        hud_p1_lives_put();
                    } else {
                        hud_p2_lives_put();
                    }
                }
            }
        }
        reg_d6.w = 0;
        *(u32 *)reg_a1 = reg_d6.w;
        reg_a1 += 4;
        if (reg_d7.h[0] == 0) {
            p1_score_cells_refresh();
        } else {
            p2_score_cells_refresh();
        }
        reg_d0.h[0] = g_high_score_billions;
        t1 = ENTITY(reg_a6)->flags.h;
        if ((s32) t1 >= (s32) reg_d0.h[0]) {
            if (t1 != reg_d0.h[0]) {
                g_high_score_billions = t1;
                goto next_1;
            }
            reg_d0.w = (u32)g_high_score;
            if ((u32) reg_d4.w > (u32) reg_d0.w) {
next_1:
                g_high_score = reg_d4.w;
                g_high_score_digits = reg_d6.h[0];
            }
        }
    }
}

extern Reg32 reg_d0;
extern u16 g_p1_score_cells[96];


void p1_score_cells_refresh(void) {
    reg_a0 = (u8 *)((u32 *)((u8 *)g_p1_score_cells));
    reg_d0.w = g_p1_score;
    reg_d6.h[0] = g_p1_score_digits;
    reg_d4.w = reg_d0.w;
    score_cells_refresh();
}

extern u16 g_p2_score_cells[];

void p2_score_cells_refresh(void) {
    reg_a0 = ((u8 *)g_p2_score_cells);
    reg_d0.w = g_p2_score;
    reg_d6.h[0] = g_p2_score_digits;
    reg_d4.w = reg_d0.w;
    score_cells_refresh();
}


void score_cells_refresh(void) {
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
    reg_d1.w = (u32)g_score_check_scratch;
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

extern u8 join_select_p2_table_at_8[];
extern u8 D_0029BF31[];
extern u8 join_select_p1_table_at_8[];
extern u8 D_0029BF41[];

void join_select_choices_init(void) {
    u8 *p;

    *(p = D_0029BF41) = 0xFF;
    join_select_p1_table_at_8[0] = 0xFF;
    reg_d5.w = 0;
    reg_d6.h[0] = reg_d0.h[0];
    reg_d7.h[0] = reg_d2.h[0];
    join_select_choice_from_game();
    if (cond_flag != 0) goto next_1;
    *p = reg_d6.b[0];
    join_select_p1_table_at_8[0] = reg_d7.b[0];
next_1:
    *(p = D_0029BF31) = 0xFF;
    join_select_p2_table_at_8[0] = 0xFF;
    reg_d5.w = 1;
    reg_d6.h[0] = reg_d1.h[0];
    reg_d7.h[0] = reg_d3.h[0];
    join_select_choice_from_game();
    if (cond_flag != 0) goto next_2;
    *p = reg_d6.b[0];
    join_select_p2_table_at_8[0] = reg_d7.b[0];
next_2:
    return;
}

extern u16 D_0028C11C[];
extern u16 D_0028C120[];


void join_select_choice_from_game(void) {
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

void join_select_ship_get() {
    reg_d6.h[0] = g_p1_ship_type;
    reg_d7.h[0] = g_p1_power_style;
    if (*(u8 *)(reg_a5 + 6) != 0) {
        reg_d6.h[0] = g_p2_ship_type;
        reg_d7.h[0] = g_p2_power_style;
    }
    reg_d5.w = 0;
    reg_d5.b[0] = *(u8 *)(reg_a5 + 6);
    join_select_choice_from_game();
    *(u8 *)(reg_a5 + 0xF) = (u8) reg_d6.b[0];
    *(u8 *)(reg_a5 + 0xE) = (u8) reg_d7.b[0];
}

s32 join_select_doll_taken_check();

void join_select_doll_next_free(void) {
    reg_d7.w = 0;
    reg_d7.b[0] = *(u8 *)(reg_a5 + 0xE);
loop_1:
    join_select_doll_taken_check();
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
    reg_a4 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0x10);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x12);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    *(u8 *)reg_a0 = *(u8 *)(reg_a5 + 0xE);
}

/* .sbss (the compiler lays these out in reverse) */
u32 reg_save3_d0;
u32 reg_save3_d1;
u32 reg_save3_d2;
u32 reg_save3_d3;
u32 reg_save3_d4;
u32 reg_save3_d5;
u32 reg_save3_d6;
u32 reg_save3_d7;
u8 *reg_save3_a0;
u8 *reg_save3_a1;
u8 *reg_save3_a2;
u8 *reg_save3_a3;
u8 *reg_save3_a4;
u8 *reg_save3_a5;
u8 *reg_save3_a6;
