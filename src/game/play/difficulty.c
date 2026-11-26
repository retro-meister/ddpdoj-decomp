#include "common.h"
#include "entity.h"

extern u8 *g_stage_base_ranks_by_difficulty[];
extern s16 g_bullet_speed_bonus_by_difficulty[];
extern u8 g_setting_difficulty;
extern u16 g_bullet_speed_bonus;
extern u8 *g_stage_base_ranks;

#ifdef DEATH_LABEL
extern u16 g_attract_demo;
#endif

void difficulty_apply(void) {
    reg_d0.w = 0;
    reg_d0.b[0] = g_setting_difficulty;
#ifdef DEATH_LABEL
    if (g_attract_demo != 0) {
        reg_d0.b[0] = 1;
    }
#endif
    reg_a0 = (u8 *)g_bullet_speed_bonus_by_difficulty;
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    g_bullet_speed_bonus = *(u16 *)reg_a0;
    g_stage_base_ranks = g_stage_base_ranks_by_difficulty[reg_d0.h[0] >> 1];
}

extern u8 D_0028E2D4;
extern u16 g_p2_hyper_total;
extern u16 g_p1_hyper_total;
extern u16 g_p2_hyper_active;
extern u16 g_p1_hyper_active;
extern u32 g_play_time_as_u32;
extern u8 g_rank_1_16_as_u8;
extern u8 g_rank_2_16_as_u8;
extern u8 g_rank_3_16_as_u8;
extern u8 g_rank_4_16_as_u8;
extern u8 g_rank_5_16_as_u8;
extern u8 g_rank_6_16_as_u8;
extern u8 g_rank_7_16_as_u8;
extern u8 g_rank_8_16_as_u8;
extern u8 g_rank_9_16_as_u8;
extern u8 g_rank_10_16_as_u8;
extern u8 g_rank_11_16_as_u8;
extern u8 g_rank_12_16_as_u8;
extern u8 g_rank_13_16_as_u8;
extern u8 g_rank_14_16_as_u8;
extern u8 g_rank_15_16_as_u8;
extern u16 g_rank;
extern u16 g_loop;
extern u16 g_stage;
extern u8 g_simulation_active;
extern u16 D_006E5C02[];

void rank_update(void) {
    reg_a0 = g_stage_base_ranks;
    reg_d2.h[0] = g_stage;
    reg_d1.w = 0;
    reg_d1.b[0] = *(s8 *) (reg_a0 + reg_d2.h[0]);
    reg_d2.w = g_play_time_as_u32;
    reg_d3.w = 8;
    if (g_simulation_active != 0 && D_006E5C02[0] != 0) {
        reg_d1.b[0] = D_0028E2D4;
    }
    reg_d2.w >>= reg_d3.w;
    reg_d1.h[0] += reg_d2.h[0];
    reg_d2.h[0] = 0xDF;
    reg_d0.h[0] = g_p1_hyper_active;
    if (((reg_d0.h[0] |= g_p2_hyper_active) & 0xFFFF) == 0) {
        goto next_2;
    }
    reg_d0.h[0] = g_p1_hyper_total;
    if ((s32) g_p2_hyper_total <= (s32) reg_d0.h[0]) {
        goto next_1;
    }
    reg_d0.h[0] = g_p2_hyper_total;
next_1:
    reg_d0.h[0] <<= 4;
    reg_d1.h[0] += reg_d0.h[0];
next_2:
    if (g_loop == 0) {
        goto next_3;
    }
    if (g_simulation_active != 0 && D_006E5C02[0] != 0) {
        goto next_3;
    }
    g_rank = 0xFF;
    reg_d0.h[0] = g_p1_hyper_active;
    reg_d0.h[0] |= g_p2_hyper_active;
    if (reg_d0.h[0] != 0) {
        goto next_5;
    }
    g_rank = 0xF8;
    goto next_5;
next_3:
    g_rank = reg_d1.h[0];
    reg_d0.h[0] = g_p1_hyper_active;
    reg_d0.h[0] |= g_p2_hyper_active;
    if (reg_d0.h[0] != 0) {
        goto next_4;
    }
    if (g_rank <= 0xF0) {
        goto next_5;
    }
    g_rank = 0xF0;
    goto next_5;
next_4:
    if (g_rank <= 0xFF) {
        goto next_5;
    }
    g_rank = 0xFF;
next_5:
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *) &g_rank;
    reg_d7.h[0] = reg_d0.h[0];
    reg_d7.h[0] >>= 4;
    reg_d0.h[0] >>= 1;
    reg_d1.b[0] = reg_d0.b[0];
    reg_d6.b[0] = reg_d0.b[0];
    g_rank_8_16_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    g_rank_9_16_as_u8 = reg_d6.b[0];
    reg_d0.h[0] >>= 1;
    reg_d2.h[0] = reg_d0.h[0];
    reg_d6.b[0] = reg_d0.b[0];
    g_rank_4_16_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    g_rank_5_16_as_u8 = reg_d6.b[0];
    reg_d1.b[0] += reg_d0.b[0];
    reg_d6.b[0] = reg_d1.b[0];
    g_rank_12_16_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    g_rank_13_16_as_u8 = reg_d6.b[0];
    reg_d0.h[0] >>= 1;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d1.b[0] += reg_d0.b[0];
    reg_d6.b[0] = reg_d1.b[0];
    g_rank_14_16_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    g_rank_15_16_as_u8 = reg_d6.b[0];
    reg_d3.b[0] -= reg_d0.b[0];
    reg_d6.b[0] = reg_d3.b[0];
    g_rank_10_16_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    g_rank_11_16_as_u8 = reg_d6.b[0];
    reg_d3.h[0] = reg_d2.h[0];
    reg_d2.b[0] += reg_d0.b[0];
    reg_d6.b[0] = reg_d2.b[0];
    g_rank_6_16_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    g_rank_7_16_as_u8 = reg_d6.b[0];
    reg_d3.b[0] -= reg_d0.b[0];
    reg_d6.b[0] = reg_d3.b[0];
    g_rank_2_16_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    g_rank_3_16_as_u8 = reg_d6.b[0];
    g_rank_1_16_as_u8 = reg_d7.b[0];
}

/* .sbss (the compiler lays these out in reverse) */
u8 *g_stage_base_ranks;
u16 g_bullet_speed_bonus __attribute__((aligned(4)));

/* Base rank of each stage, for each difficulty setting. */
u8 g_stage_base_ranks_easy[8] = { 0x10, 0x10, 0x18, 0x20, 0x20 };
u8 g_stage_base_ranks_normal[8] = { 0x34, 0x44, 0x54, 0x64, 0x64 };
u8 g_stage_base_ranks_hard[8] = { 0x90, 0xA8, 0xC0, 0xD8, 0xF0 };
u8 g_stage_base_ranks_very_hard[8] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

u8 *g_stage_base_ranks_by_difficulty[4] = {
    g_stage_base_ranks_easy,
    g_stage_base_ranks_normal,
    g_stage_base_ranks_hard,
    g_stage_base_ranks_very_hard,
};

/* Added to the speed of enemy bullets, for each difficulty setting. */
s16 g_bullet_speed_bonus_by_difficulty[4] = { -1, 0, 1, 2 };
