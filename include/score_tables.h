#ifndef DDPDOJ_SCORE_TABLES_H
#define DDPDOJ_SCORE_TABLES_H

#include "types.h"

/* The PS2 score helpers receive the adjacent symbol and subtract four. */
#ifdef DDPDOJ_PC
#define SCORE_VALUE_TARGET(original, target) ((u8 *)&(target))
#else
#define SCORE_VALUE_TARGET(original, target) (original)
#endif

extern u32 hyper_text_frames[];
typedef union {
    struct {
        u32 frames[44];
        u16 max_level[4][2];
        u16 multiplier_units[12][2];
        u16 multiplier_tens[12][2];
    } rows;
    u32 animation[72];
} MaximumTextData;

extern MaximumTextData g_maximum_text;
extern u16 multiplier_ones_text[][2];
extern u16 hit_count_digit_text[][2];
extern u16 combo_gauge_levels_loop1[];
extern u16 combo_gauge_levels_loop2[];
extern u32 hyper_gauge_frames[];
extern u32 hyper_stock_frames_p1[];
extern u32 hyper_stock_frames_p2[];
extern u32 boss_hit_bonus_digits[];
extern u32 hyper_item_count_sprites[];
extern u16 hyper_item_count_text[][2];
extern u32 extend_scores_first[];
extern u32 extend_scores_later[];
extern u16 combo_time_by_loop[];
extern u16 laser_hit_step_by_ship[];
extern u16 *combo_gauge_levels_by_loop[];
extern u32 lives_sprites_p1[];
extern u32 lives_sprites_p2[];
extern u16 lives_text_p1[][2];
extern u16 lives_text_p2[][2];

#endif
