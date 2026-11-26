#include "common.h"
#ifdef DDPDOJ_PC
#include "pc_replay_storage.h"
#endif
#include "score_tables.h"
extern s16 g_player1[];
extern s16 g_player2[];
#include "player.h"
#include "entity.h"

void p1_laser_hit(void);
void p2_laser_hit(void);
void score_value_add(void);
void p1_combo_timer_add(void);
void p2_combo_timer_add(void);
void p1_boss_hit(void);
void p1_boss_hit_chain(void);
void p1_boss_hit_late_phase(void);
void p1_boss_hits_restart(void);
void p1_boss_hits_continue(void);
void p1_boss_hits_add(void);
void p1_boss_hits_score();
void p2_boss_hit(void);
void p2_boss_hit_late_phase(void);
void p2_boss_hits_restart(void);
void p2_boss_hits_continue(void);
void p2_boss_hits_add(void);
void p2_boss_hits_score();
void extend_score_set(void);
void p1_hyper_gauge_check_full(void);
void p2_hyper_gauge_check_full(void);
void hud_p1_caption_put(void);
void hud_p2_caption_put(void);


void bcd_word_increment(void) {
    s32 bcd_add_registers(Reg32 *, Reg32 *);
    reg_d0.w = 1;
    reg_d2.w = (u32) *((u16 *)reg_a0);
    bcd_add_registers(&reg_d0, &reg_d2);
    *(*(u16 **)&reg_a0) = reg_d2.h[0];
}

extern u16 g_p2_hyper_active;
extern u16 g_p1_hyper_active;
extern s32 g_p1_score_pending;
extern u8 g_p2_extend_table;
extern u8 g_boss_present_b1;
extern u16 g_bomb_entities[];

void score_add_no_chain(void) {
    if (!(ENTITY(reg_a6)->flags.b[1] & 2)) {
        if ((g_boss_present_b1 & 4) && (reg_d2.h[0] = g_bomb_entities[0], ((s16) reg_d2.h[0] < 0)) && (reg_d2.w & 1) && (reg_d0.w = 1, ((s8) reg_d2.b[0] >= 0))) {
            if (reg_d1.w & 0x10) {
                reg_d0.h[0] += g_p1_hyper_active;
                p1_boss_hit_chain();
                goto block_7;
            }
        } else {
block_7:
            if (reg_d1.w & 0x10) {
                reg_d0.w = 1;
                reg_d0.h[0] += g_p1_hyper_active;
                if (reg_d1.w & 4) {
                    p1_boss_hit();
                } else {
                    reg_a0 = &g_p2_extend_table;
                    score_value_add();
                }
            }
        }
        if (reg_d1.w & 8) {
            reg_d0.w = 1;
            reg_d0.h[0] += g_p2_hyper_active;
            switch (reg_d1.w & 4) { case 0: break; default:
                p2_boss_hit();
                return;
            }
            reg_a0 = &(*(u8 *)&g_p1_score_pending);
            score_value_add();
        }
    }
}

extern s32 g_p1_score_pending;

void score_add_masked(void) {
    if (reg_d1.w & 0x10) {
        reg_a0 = (u8 *)(&(*(s32 *)&g_p2_extend_table));
        score_value_add();
    }
    if (reg_d1.w & 8) {
        reg_a0 = (u8 *)(&g_p1_score_pending);
        score_value_add();
    }
}



void score_add_p1(void) {
    reg_a0 = (u8 *)(&g_p2_extend_table);
    score_value_add();
}

void score_add_p2(void) {
    reg_a0 = (u8 *)(&g_p1_score_pending);
    score_value_add();
}

extern u16 g_p2_hyper_level;
extern u16 g_p1_hyper_level;
extern s32 g_p2_chain_points;
extern s32 g_p1_chain_points;
extern u16 g_max_combo_time;
extern u16 g_loop;

void score_add(void) {
    u32 temp_s0;
    u32 temp_s0_2;
    u32 temp_s1;
    u32 temp_s1_2;

    reg_d2.h[0] = g_loop;
    reg_a0 = (u8 *)(combo_time_by_loop);
    reg_d2.h[0] += reg_d2.h[0];
    g_max_combo_time = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    if (reg_d1.w & 0x10) {
        p1_laser_hit();
        if (g_p1_hyper_active != 0) {
            reg_d2.h[0] = g_p1_hyper_level;
            reg_d2.h[0] -= 1;
            do {
                temp_s1 = reg_d2.w;
                reg_d0.w = (u32)g_p1_chain_points;
                temp_s0 = reg_d0.w;
                reg_d0.w >>= 4;
                g_p1_chain_points = reg_d0.w;
                reg_d0.w = 0;
                p1_laser_hit();
                reg_d0.w = 0;
                score_add_p1();
                reg_d0.w = 0;
                score_add_p1();
                reg_d0.w = 0;
                score_add_p1();
                reg_d0.w = 0;
                score_add_p1();
                reg_d2.w = temp_s1;
                g_p1_chain_points = temp_s0;
            } while ((s16)(--reg_d2.h[0]) >= 0);
        }
    }
    if (reg_d1.w & 8) {
        p2_laser_hit();
        if (g_p2_hyper_active != 0) {
            reg_d2.h[0] = g_p2_hyper_level;
            reg_d2.h[0] -= 1;
            do {
                temp_s0_2 = reg_d2.w;
                reg_d0.w = (u32)g_p2_chain_points;
                temp_s1_2 = reg_d0.w;
                reg_d0.w >>= 4;
                g_p2_chain_points = reg_d0.w;
                reg_d0.w = 0;
                p2_laser_hit();
                reg_d0.w = 0;
                score_add_p2();
                reg_d0.w = 0;
                score_add_p2();
                reg_d0.w = 0;
                score_add_p2();
                reg_d0.w = 0;
                score_add_p2();
                reg_d2.w = temp_s0_2;
                g_p2_chain_points = temp_s1_2;
            } while ((s16)(--reg_d2.h[0]) >= 0);
        }
    }
}

extern u16 g_p1_max_hits;
extern u16 g_p1_laser_hit_step;
extern u16 g_p1_laser_hit_timer;
extern u16 g_p1_hits_shown;
extern u16 g_p1_hits;
extern s32 g_p1_chain_points_shown2;
extern s32 g_p1_chain_points_shown;
extern u16 g_p1_hit10_anim_count;
extern u16 g_p1_hit10_color_timer;
extern s16 g_p1_hit10_display_timer;
extern u16 g_p1_combo_break_color_timer;
extern u16 g_p1_hit_display_timer;
extern s16 g_p1_chain_points_display_timer;
extern u16 g_p1_combo_timer;
extern s32 g_p1_chain_first_score_shown;
extern s32 g_p1_chain_first_score;
extern u16 g_p1_combo_at_bomb;
extern u8 g_boss_present;

void p1_laser_hit(void) {
    reg_d3.w = reg_d0.w;
    reg_d2.h[0] = PLAYER(((u8 *)g_player1))->ship_type.h;
    reg_a0 = (u8 *)laser_hit_step_by_ship;
    g_p1_laser_hit_step = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = g_bomb_entities[0];
    if ((s16) reg_d2.h[0] >= 0) {
        goto next_1;
    }
    if (reg_d2.w & 0x80) {
        goto next_1;
    }
    if (g_p1_combo_at_bomb == 0) {
        goto block_11;
    }
next_1:
    if (g_boss_present & 1) {
        goto block_12;
    }
    g_p1_laser_hit_timer = 0x1E;
    if (g_p1_hyper_active != 0) {
        g_p1_laser_hit_timer = 1;
    }
    if (g_p1_combo_timer != 0) {
        goto next_2;
    }
    p1_combo_timer_add();
block_11:
    g_p1_hits = 0;
block_12:
    reg_d0.w = reg_d3.w;
    reg_a0 = (u8 *)&(*(u16 *)&g_p2_extend_table);
    score_value_add();
    g_p1_chain_first_score = reg_d3.w;
    g_p1_chain_first_score_shown = reg_d3.w;
    if ((u32)g_p1_chain_points_shown2 == 0) {
        g_p1_chain_points_display_timer = 0x50;
    }
    reg_d2.w = 0;
    g_p1_chain_points = reg_d2.w;
    g_p1_chain_points_shown = reg_d2.w;
    g_p1_hit_display_timer = reg_d2.h[0];
    goto block_end;
next_2:
    if ((u32)g_p1_chain_first_score != 0) {
        reg_d0.w = (u32)g_p1_chain_first_score;
        g_p1_hits = 1;
        g_p1_chain_points = reg_d0.w;
        g_p1_chain_points_shown = reg_d0.w;
        reg_d0.w = 0;
        g_p1_chain_first_score = reg_d0.w;
    }
    reg_a0 = (u8 *)&g_p1_hits;
    bcd_word_increment();
    reg_d0.h[0] = g_p1_max_hits;
    if ((s32) g_p1_hits > (s32) reg_d0.h[0]) {
        g_p1_max_hits = g_p1_hits;
    }
    reg_d0.w = reg_d3.w;
    reg_a0 = (u8 *)&g_p1_hit10_anim_count;
    score_value_add();
    reg_d0.w = (u32)g_p1_chain_points;
    reg_a0 = (u8 *)&(*(u32 *)&g_p1_chain_points);
    score_value_add();
    p1_combo_timer_add();
    reg_d0.w = (u32)g_p1_chain_points;
    reg_a0 = (u8 *)&(*(u16 *)&g_p2_extend_table);
    score_value_add();
    if ((s32) g_p1_hits < 0x10) {
        if ((s32) g_p1_hits > 1) {
            g_p1_hit_display_timer = 0x78;
        }
        g_p1_combo_break_color_timer = g_p1_combo_timer;
        if ((u32)g_p1_chain_points_shown2 == 0) {
            g_p1_chain_points_display_timer = 0xB4;
        }
        goto block_end;
    }
    if (g_p1_hits == 0x10) {
        g_p1_hit10_anim_count = 0;
        g_p1_hit_display_timer = 0;
    }
    g_p1_hits_shown = g_p1_hits;
    g_p1_hit10_display_timer = 0xF0;
    g_p1_chain_points_display_timer = 0xF0;
    g_p1_hit10_color_timer = g_p1_combo_timer;
    g_p1_chain_points_shown2 = (u32)g_p1_chain_points_shown;
block_end:
    reg_d0.w = reg_d3.w;
}

extern u16 g_p2_max_hits;
extern u16 g_p2_laser_hit_timer;
extern u16 g_p2_hits_shown;
extern u16 g_p2_hits;
extern s32 g_p2_chain_points_shown2;
extern s32 g_p2_chain_points_shown;
extern u16 g_p2_hit10_anim_count;
extern u16 g_p2_hit10_color_timer;
extern s16 g_p2_hit10_display_timer;
extern u16 g_p2_combo_break_color_timer;
extern u16 g_p2_hit_display_timer;
extern s16 g_p2_chain_points_display_timer;
extern u16 g_p2_combo_timer;
extern s32 g_p2_chain_first_score_shown;
extern s32 g_p2_chain_first_score;
extern u16 g_p2_combo_at_bomb;

void p2_laser_hit(void) {
    reg_d3.w = reg_d0.w;
    reg_d2.h[0] = PLAYER(((u8 *)g_player2))->ship_type.h;
    reg_a0 = (u8 *)laser_hit_step_by_ship;
    g_p1_laser_hit_step = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = g_bomb_entities[0];
    if ((s16) reg_d2.h[0] >= 0) {
        goto next_1;
    }
    if (!(reg_d2.w & 0x80)) {
        goto next_1;
    }
    if (g_p2_combo_at_bomb == 0) {
        goto block_11;
    }
next_1:
    if (g_boss_present & 1) {
        goto block_12;
    }
    g_p2_laser_hit_timer = 0x1E;
    if (g_p2_hyper_active != 0) {
        g_p2_laser_hit_timer = 1;
    }
    if (g_p2_combo_timer != 0) {
        goto next_2;
    }
    p2_combo_timer_add();
block_11:
    g_p2_hits = 0;
block_12:
    reg_d0.w = reg_d3.w;
    reg_a0 = (u8 *)&(*(u16 *)&g_p1_score_pending);
    score_value_add();
    g_p2_chain_first_score = reg_d3.w;
    g_p2_chain_first_score_shown = reg_d3.w;
    if ((u32)g_p2_chain_points_shown2 == 0) {
        g_p2_chain_points_display_timer = 0x50;
    }
    reg_d2.w = 0;
    g_p2_chain_points = reg_d2.w;
    g_p2_chain_points_shown = reg_d2.w;
    g_p2_hit_display_timer = reg_d2.h[0];
    goto block_end;
next_2:
    if ((u32)g_p2_chain_first_score != 0) {
        reg_d0.w = (u32)g_p2_chain_first_score;
        g_p2_hits = 1;
        g_p2_chain_points = reg_d0.w;
        g_p2_chain_points_shown = reg_d0.w;
        reg_d0.w = 0;
        g_p2_chain_first_score = reg_d0.w;
    }
    reg_a0 = (u8 *)&g_p2_hits;
    bcd_word_increment();
    reg_d0.h[0] = g_p2_max_hits;
    if ((s32) g_p2_hits > (s32) reg_d0.h[0]) {
        g_p2_max_hits = g_p2_hits;
    }
    reg_d0.w = reg_d3.w;
    reg_a0 = (u8 *)&g_p2_hit10_anim_count;
    score_value_add();
    reg_d0.w = (u32)g_p2_chain_points;
    reg_a0 = (u8 *)&(*(u32 *)&g_p2_chain_points);
    score_value_add();
    p2_combo_timer_add();
    reg_d0.w = (u32)g_p2_chain_points;
    reg_a0 = (u8 *)&(*(u16 *)&g_p1_score_pending);
    score_value_add();
    if ((s32) g_p2_hits < 0x10) {
        if ((s32) g_p2_hits > 1) {
            g_p2_hit_display_timer = 0x78;
        }
        g_p2_combo_break_color_timer = g_p2_combo_timer;
        if ((u32)g_p2_chain_points_shown2 == 0) {
            g_p2_chain_points_display_timer = 0xB4;
        }
        goto block_end;
    }
    if (g_p2_hits == 0x10) {
        g_p2_hit10_anim_count = 0;
        g_p2_hit_display_timer = 0;
    }
    g_p2_hits_shown = g_p2_hits;
    g_p2_hit10_display_timer = 0xF0;
    g_p2_chain_points_display_timer = 0xF0;
    g_p2_hit10_color_timer = g_p2_combo_timer;
    g_p2_chain_points_shown2 = (u32)g_p2_chain_points_shown;
block_end:
    reg_d0.w = reg_d3.w;
}

extern s32 g_score_scratch;


void score_value_add(void) {
    extern void bcd_add_registers(s32 *, s32);
    (*(s32 *)&reg_a0) -= 4;
    (*(s32 **)&reg_a1) = &g_score_scratch;
    *(*(s32 **)&reg_a1) = reg_d0.w;
    reg_d2.sh[0] = 0;
    bcd_add_registers(((s32 *)reg_a1), (*(s32 *)&reg_a0));
}

extern u16 D_0026B898[];
extern u16 D_0026B8A8[];
extern u16 D_0026B8B8[];
extern u16 g_p1_hyper_items;
extern u16 g_p1_hyper_gauge;
extern u16 g_stage_x2;
extern u8 g_simulation_active;

void p1_combo_timer_add(void) {
    u32 bits;
    u16 idx;
    u16 val;
    u32 add;

    bits = reg_d1.w & 4;
    reg_d0.h[0] = g_p1_laser_hit_step;
    if ((bits != 0) || (g_loop == 0)) {
        g_p1_combo_timer += reg_d0.h[0];
        reg_d0.h[0] = g_max_combo_time;
        if ((s32) g_p1_combo_timer < (s32) reg_d0.h[0]) {
        block_rts:
            return;
        }
    }
    g_p1_combo_timer = g_max_combo_time;
    if ((s16) reg_d1.h[0] < 0) {
        goto block_rts;
    }
    reg_a0 = (u8 *)D_0026B8A8;
    reg_d0.h[0] = g_stage_x2;
    idx = reg_d0.h[0];
    reg_a0 += idx;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_d2.h[0] = g_p1_hyper_items;
    if (g_p1_hyper_active != 0) {
        reg_d0.h[0] = g_stage_x2;
        reg_a0 = (u8 *)D_0026B8B8;
        reg_a0 += idx;
        reg_d0.h[0] = *(u16 *)reg_a0;
    } else {
        reg_d2.h[0] += reg_d2.h[0];
        reg_a0 = (u8 *)D_0026B898;
        switch (reg_d2.h[0]) {
        case 0:
            goto skip_1;
        }
        val = *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1));
        goto next_1;
    skip_1:
        val = *(u16 *)reg_a0;
    next_1:
        reg_d0.h[0] += val;
    }
    if ((g_p1_hyper_items != 5) && (bits == 0)) {
        reg_d0.h[0] += reg_d0.h[0];
    }
    if (g_simulation_active != 0) {
        add = reg_d0.h[0];
        g_p1_hyper_gauge += add;
    } else {
        g_p1_hyper_gauge += reg_d0.h[0];
    }
    p1_hyper_gauge_check_full();
}

extern u16 g_p2_hyper_items;
extern u16 g_p2_hyper_gauge;

void p2_combo_timer_add(void) {
    u32 bits;
    u16 idx;
    u16 val;
    u32 add;

    bits = reg_d1.w & 4;
    reg_d0.h[0] = g_p1_laser_hit_step;
    if ((bits != 0) || (g_loop == 0)) {
        g_p2_combo_timer += reg_d0.h[0];
        reg_d0.h[0] = g_max_combo_time;
        if ((s32) g_p2_combo_timer < (s32) reg_d0.h[0]) {
        block_rts:
            return;
        }
    }
    g_p2_combo_timer = g_max_combo_time;
    if ((s16) reg_d1.h[0] < 0) {
        goto block_rts;
    }
    reg_a0 = (u8 *)D_0026B8A8;
    reg_d0.h[0] = g_stage_x2;
    idx = reg_d0.h[0];
    reg_a0 += idx;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_d2.h[0] = g_p2_hyper_items;
    if (g_p2_hyper_active != 0) {
        reg_d0.h[0] = g_stage_x2;
        reg_a0 = (u8 *)D_0026B8B8;
        reg_a0 += idx;
        reg_d0.h[0] = *(u16 *)reg_a0;
    } else {
        reg_d2.h[0] += reg_d2.h[0];
        reg_a0 = (u8 *)D_0026B898;
        switch (reg_d2.h[0]) {
        case 0:
            goto skip_1;
        }
        val = *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1));
        goto next_1;
    skip_1:
        val = *(u16 *)reg_a0;
    next_1:
        reg_d0.h[0] += val;
    }
    if ((g_p2_hyper_items != 5) && (bits == 0)) {
        reg_d0.h[0] += reg_d0.h[0];
    }
    if (g_simulation_active != 0) {
        add = reg_d0.h[0];
        g_p2_hyper_gauge += add;
    } else {
        g_p2_hyper_gauge += reg_d0.h[0];
    }
    p2_hyper_gauge_check_full();
}

extern u16 g_p1_laser_hyper_timer;

void p1_laser_hyper_gauge_tick(void) {
    g_p1_laser_hyper_timer -= 1;
    if ((s16)g_p1_laser_hyper_timer < 0) {
        reg_d2.w = 0;
        reg_d2.h[0] += 0x10;
        if (g_simulation_active != 0) {
            g_p1_hyper_gauge += reg_d2.h[0];
        } else {
            g_p1_hyper_gauge += reg_d2.h[0];
        }
        p1_hyper_gauge_check_full();
        reg_d2.w = 8;
        g_p1_laser_hyper_timer = reg_d2.h[0];
    }
}

void p1_boss_hyper_gauge_tick(void) {
    g_p1_laser_hyper_timer -= 1;
    if ((s16) g_p1_laser_hyper_timer < 0) {
        reg_d2.w = 4;
        if (g_p1_hyper_active != 0) {
            reg_d2.w = 0x30;
        }
        if (g_simulation_active != 0) {
            g_p1_hyper_gauge += reg_d2.h[0];
        } else {
            g_p1_hyper_gauge += reg_d2.h[0];
        }
        p1_hyper_gauge_check_full();
        reg_d2.w = 8;
        g_p1_laser_hyper_timer = reg_d2.h[0];
    }
}

extern u16 g_p2_laser_hyper_timer;

void p2_laser_hyper_gauge_tick(void) {
    g_p2_laser_hyper_timer -= 1;
    if ((s16)g_p2_laser_hyper_timer < 0) {
        reg_d2.w = 0;
        reg_d2.h[0] += 0x10;
        if (g_simulation_active != 0) {
            g_p2_hyper_gauge += reg_d2.h[0];
        } else {
            g_p2_hyper_gauge += reg_d2.h[0];
        }
        p2_hyper_gauge_check_full();
        reg_d2.w = 8;
        g_p2_laser_hyper_timer = reg_d2.h[0];
    }
}

void p2_boss_hyper_gauge_tick(void) {
    g_p2_laser_hyper_timer -= 1;
    if ((s16) g_p2_laser_hyper_timer < 0) {
        reg_d2.w = 4;
        if (g_p2_hyper_active != 0) {
            reg_d2.w = 0x30;
        }
        if (g_simulation_active != 0) {
            g_p2_hyper_gauge += reg_d2.h[0];
        } else {
            g_p2_hyper_gauge += reg_d2.h[0];
        }
        p2_hyper_gauge_check_full();
        reg_d2.w = 8;
        g_p2_laser_hyper_timer = reg_d2.h[0];
    }
}

extern u16 g_p1_laser_hit_timer;

void p1_boss_hit(void) {
    u16 saved_d0;

    switch (g_boss_present_b1 & 4) {
    case 0:
        break;
    default:
        p1_boss_hit_late_phase();
        return;
    }
    reg_d3.w = reg_d0.w;
    if ((((s16 *)g_bomb_entities)[0] >= 0) && (g_p1_combo_timer == 0)) {
        reg_d0.w = 0;
        g_p1_combo_timer = 0xA;
        reg_d2.w = 8;
        g_p1_chain_first_score = reg_d0.w;
        g_p1_chain_first_score_shown = reg_d0.w;
        g_p1_chain_points = reg_d0.w;
        g_p1_chain_points_shown = reg_d0.w;
        g_p1_hits = reg_d0.h[0];
        g_p1_hit_display_timer = reg_d0.h[0];
        reg_d2.h[0] -= (s16) (u16) PLAYER(((u8 *)g_player1))->laser_power.h;
        reg_d0.h[0] = reg_d2.h[0];
        reg_d0.h[0] >>= 1;
        reg_d2.h[0] += reg_d0.h[0];
        reg_d2.h[0] += 0x12;
        g_p1_laser_hyper_timer = reg_d2.h[0];
        if (g_p1_hyper_active != 0) {
            reg_d2.h[0] -= 0xC;
        }
        g_p1_laser_hit_timer = reg_d2.h[0];
        return;
    }
    p1_laser_hyper_gauge_tick();
    g_p1_laser_hit_timer -= 1;
    if ((s16) g_p1_laser_hit_timer < 0) {
        if (g_p1_hyper_active != 0) {
            reg_d2.w = 6;
            reg_d2.h[0] -= g_p1_hyper_level;
        } else {
            reg_d2.w = 8;
            reg_d2.h[0] -= (s16) (u16) PLAYER(((u8 *)g_player1))->laser_power.h;
            reg_d0.h[0] = reg_d2.h[0];
            reg_d0.h[0] >>= 1;
            reg_d2.h[0] += reg_d0.h[0];
            reg_d2.h[0] += 1;
            reg_d2.h[0] += 0x11;
            if (PLAYER(((u8 *)g_player1))->power_style.h != 2) {
                reg_d2.h[0] -= 3;
            }
        }
        g_p1_laser_hit_timer = reg_d2.h[0];
        if ((u32)g_p1_chain_first_score != 0) {
            reg_d0.w = (u32)g_p1_chain_first_score;
            g_p1_hits = 1;
            g_p1_chain_points = reg_d0.w;
            g_p1_chain_points_shown = reg_d0.w;
            reg_d0.w = 0;
            g_p1_chain_first_score = reg_d0.w;
        }
        reg_a0 = (u8 *)&g_p1_hits;
        reg_d0.w = 0;
        if (reg_d1.w & 0x40) {
            reg_d0.h[0] += reg_d0.h[0];
        }
        do {
            saved_d0 = reg_d0.h[0];
            bcd_word_increment();
            reg_d0.h[0] = saved_d0;
        } while ((s16)(--reg_d0.h[0]) >= 0);
        reg_d0.h[0] = g_p1_max_hits;
        if ((s32) g_p1_hits > (s32) reg_d0.h[0]) {
            g_p1_max_hits = g_p1_hits;
        }
        reg_d0.w = reg_d3.w;
        reg_a0 = (u8 *)&g_p1_hit10_anim_count;
        score_value_add();
        reg_d0.w = (u32)g_p1_chain_points;
        reg_a0 = (u8 *)&(*(u32 *)&g_p1_chain_points);
        score_value_add();
        reg_d0.w = (u32)g_p1_chain_points;
        reg_a0 = (u8 *)&(*(u32 *)&g_p2_extend_table);
        score_value_add();
    }
    if (g_p1_hyper_active == 0) {
        if ((s32) g_p1_combo_timer < 0xA) {
            g_p1_combo_timer = 0xA;
        }
    } else if ((s32) g_p1_combo_timer < 0x19) {
        g_p1_combo_timer = 0x19;
    }
    if ((s32) g_p1_hits < 0x10) {
        if ((s32) g_p1_hits > 1) {
            g_p1_hit_display_timer = 0x78;
        }
        g_p1_combo_break_color_timer = g_p1_combo_timer;
        if ((u32)g_p1_chain_points_shown2 == 0) {
            g_p1_chain_points_display_timer = 0xB4;
        }
        return;
    }
    if (g_p1_hit10_color_timer == 0) {
        g_p1_hit10_anim_count = 0;
        g_p1_hit_display_timer = 0;
    }
    g_p1_hits_shown = g_p1_hits;
    g_p1_hit10_display_timer = 0xF0;
    g_p1_chain_points_display_timer = 0xF0;
    g_p1_hit10_color_timer = g_p1_combo_timer;
    g_p1_chain_points_shown2 = (u32)g_p1_chain_points_shown;
}

extern u16 g_boss_near_death;
extern u16 g_boss_hit_decay_timer;

void p1_boss_hit_chain(void) {
    reg_d3.w = reg_d0.w;
    if (g_boss_hit_decay_timer == 0) {
        p1_boss_hits_restart();
        return;
    }
    if (g_boss_near_death == 0) {
        p1_boss_hits_continue();
        return;
    }
    reg_d0.w = 1;
    if (g_p1_hyper_active == 0) {
        p1_boss_hits_add();
        return;
    }
    reg_d0.h[0] += g_p1_hyper_level;
    p1_boss_hits_add();
}

void p1_boss_hit_late_phase(void) {
    reg_d3.w = reg_d0.w;
    if (((s16 *)g_bomb_entities)[0] < 0) {
        p1_boss_hits_continue();
        return;
    }
    if (g_boss_hit_decay_timer != 0) {
        p1_boss_hits_continue();
        return;
    }
    p1_boss_hits_restart();
}

#pragma push
#pragma opt_propagation off
extern s16 g_boss_hit_palette;
extern u16 g_boss_hits;
extern u16 g_boss_hit_anim_count;

void p1_boss_hits_restart(void)
{
    u16 adjustment;

    g_boss_hit_decay_timer = 10;
    adjustment = PLAYER(((u8 *)g_player1))->laser_power.h;
    g_boss_hit_palette = 7;
    g_boss_hits = 0;
    reg_d2.w = 8;
    g_boss_hit_anim_count = 0;
    reg_d2.h[0] -= adjustment;
    reg_d2.h[0] += 8;
    g_p1_laser_hit_timer = reg_d2.h[0];
}
#pragma pop


void p1_boss_hits_continue(void) {
    if ((s16)g_boss_hits < 0) {
        g_boss_hits = 0;
    }
    p1_boss_hyper_gauge_tick();
    g_p1_laser_hit_timer -= 1;
    if ((s16) g_p1_laser_hit_timer >= 0) {
        p1_boss_hits_score();
        return;
    }
    reg_d0.w = 1;
    reg_d2.w = 0;
    if (g_p1_hyper_active != 0) {
        reg_d0.h[0] += g_p1_hyper_level;
    } else {
        reg_d2.w = 8;
        reg_d2.h[0] -= (s16) (u16) PLAYER(((u8 *)g_player1))->laser_power.h;
        reg_d2.h[0] += 8;
        if (PLAYER(((u8 *)g_player1))->power_style.h != 2) {
            reg_d2.h[0] -= 3;
        }
    }
    g_p1_laser_hit_timer = reg_d2.h[0];
    p1_boss_hits_add();
}

extern u16 g_boss_hits;

void p1_boss_hits_add(void) {
    extern void p1_boss_hits_score(u16);
    g_boss_hits += reg_d0.h[0];
    if (!(reg_d1.w & 0x40)) {
        p1_boss_hits_score(reg_d0.h[0]);
        return;
    }
    g_boss_hits += reg_d0.h[0];
    p1_boss_hits_score(reg_d0.h[0]);
}


void p1_boss_hits_score()
{
    if ((s32)g_boss_hits > 0x7FFF) {
        g_boss_hits = 0x7FFF;
    }

    reg_d0.w = reg_d3.w;
    reg_a0 = &g_p2_extend_table;
    score_value_add();
    g_boss_hit_decay_timer = 10;
    g_boss_hit_palette = 7;
}

extern u16 g_p2_laser_hit_timer;

void p2_boss_hit(void) {
    u16 saved_d0;

    switch (g_boss_present_b1 & 4) {
    case 0:
        break;
    default:
        p2_boss_hit_late_phase();
        return;
    }
    reg_d3.w = reg_d0.w;
    if ((((s16 *)g_bomb_entities)[0] >= 0) && (g_p2_combo_timer == 0)) {
        reg_d0.w = 0;
        g_p2_combo_timer = 0xA;
        reg_d2.w = 8;
        g_p2_chain_first_score = reg_d0.w;
        g_p2_chain_first_score_shown = reg_d0.w;
        g_p2_chain_points = reg_d0.w;
        g_p2_chain_points_shown = reg_d0.w;
        g_p2_hits = reg_d0.h[0];
        g_p2_hit_display_timer = reg_d0.h[0];
        reg_d2.h[0] -= (s16) (u16) PLAYER(((u8 *)g_player2))->laser_power.h;
        reg_d0.h[0] = reg_d2.h[0];
        reg_d0.h[0] >>= 1;
        reg_d2.h[0] += reg_d0.h[0];
        reg_d2.h[0] += 0x12;
        g_p2_laser_hyper_timer = reg_d2.h[0];
        if (g_p2_hyper_active != 0) {
            reg_d2.h[0] -= 0xC;
        }
        g_p2_laser_hit_timer = reg_d2.h[0];
        return;
    }
    p2_laser_hyper_gauge_tick();
    g_p2_laser_hit_timer -= 1;
    if ((s16) g_p2_laser_hit_timer < 0) {
        if (g_p2_hyper_active != 0) {
            reg_d2.w = 6;
            reg_d2.h[0] -= g_p2_hyper_level;
        } else {
            reg_d2.w = 8;
            reg_d2.h[0] -= (s16) (u16) PLAYER(((u8 *)g_player2))->laser_power.h;
            reg_d0.h[0] = reg_d2.h[0];
            reg_d0.h[0] >>= 1;
            reg_d2.h[0] += reg_d0.h[0];
            reg_d2.h[0] += 1;
            reg_d2.h[0] += 0x11;
            if (PLAYER(((u8 *)g_player2))->power_style.h != 2) {
                reg_d2.h[0] -= 3;
            }
        }
        g_p2_laser_hit_timer = reg_d2.h[0];
        if ((u32)g_p2_chain_first_score != 0) {
            reg_d0.w = (u32)g_p2_chain_first_score;
            g_p2_hits = 1;
            g_p2_chain_points = reg_d0.w;
            g_p2_chain_points_shown = reg_d0.w;
            reg_d0.w = 0;
            g_p2_chain_first_score = reg_d0.w;
        }
        reg_a0 = (u8 *)&g_p2_hits;
        reg_d0.w = 0;
        if (reg_d1.w & 0x40) {
            reg_d0.h[0] += reg_d0.h[0];
        }
        do {
            saved_d0 = reg_d0.h[0];
            bcd_word_increment();
            reg_d0.h[0] = saved_d0;
        } while ((s16)(--reg_d0.h[0]) >= 0);
        reg_d0.h[0] = g_p2_max_hits;
        if ((s32) g_p2_hits > (s32) reg_d0.h[0]) {
            g_p2_max_hits = g_p2_hits;
        }
        reg_d0.w = reg_d3.w;
        reg_a0 = (u8 *)&g_p2_hit10_anim_count;
        score_value_add();
        reg_d0.w = (u32)g_p2_chain_points;
        reg_a0 = (u8 *)&(*(u32 *)&g_p2_chain_points);
        score_value_add();
        reg_d0.w = (u32)g_p2_chain_points;
        reg_a0 = (u8 *)&(*(u32 *)&g_p1_score_pending);
        score_value_add();
    }
    if (g_p2_hyper_active == 0) {
        if ((s32) g_p2_combo_timer < 0xA) {
            g_p2_combo_timer = 0xA;
        }
    } else if ((s32) g_p2_combo_timer < 0x19) {
        g_p2_combo_timer = 0x19;
    }
    if ((s32) g_p2_hits < 0x10) {
        if ((s32) g_p2_hits > 1) {
            g_p2_hit_display_timer = 0x78;
        }
        g_p2_combo_break_color_timer = g_p2_combo_timer;
        if ((u32)g_p2_chain_points_shown2 == 0) {
            g_p2_chain_points_display_timer = 0xB4;
        }
        return;
    }
    if (g_p2_hit10_color_timer == 0) {
        g_p2_hit10_anim_count = 0;
        g_p2_hit_display_timer = 0;
    }
    g_p2_hits_shown = g_p2_hits;
    g_p2_hit10_display_timer = 0xF0;
    g_p2_chain_points_display_timer = 0xF0;
    g_p2_hit10_color_timer = g_p2_combo_timer;
    g_p2_chain_points_shown2 = (u32)g_p2_chain_points_shown;
}


void p2_boss_hit_late_phase(void) {
    reg_d3.w = reg_d0.w;
    if (((s16 *)g_bomb_entities)[0] < 0) {
        p2_boss_hits_continue();
        return;
    }
    if (g_boss_hit_decay_timer != 0) {
        p2_boss_hits_continue();
        return;
    }
    p2_boss_hits_restart();
}

#pragma push
#pragma opt_propagation off
void p2_boss_hits_restart(void)
{
    u32 adjustment;
    u32 counter;

    g_boss_hit_decay_timer = 10;
    adjustment = PLAYER(((u8 *)g_player2))->laser_power.h;
    g_boss_hit_palette = 7;
    g_boss_hits = 0;
    reg_d2.w = 8;
    counter = reg_d2.h[0];
    g_boss_hit_anim_count = 0;
    reg_d2.h[0] = counter - adjustment;
    reg_d2.h[0] += 8;
    g_p2_laser_hit_timer = reg_d2.h[0];
}
#pragma pop


void p2_boss_hits_continue(void) {
    if ((s16)g_boss_hits < 0) {
        g_boss_hits = 0;
    }
    p2_boss_hyper_gauge_tick();
    g_p2_laser_hit_timer -= 1;
    if ((s16) g_p2_laser_hit_timer >= 0) {
        p2_boss_hits_score();
        return;
    }
    reg_d0.w = 1;
    reg_d2.w = 0;
    if (g_p2_hyper_active != 0) {
        reg_d0.h[0] += g_p2_hyper_level;
    } else {
        reg_d2.w = 8;
        reg_d2.h[0] -= (s16) (u16) PLAYER(((u8 *)g_player2))->laser_power.h;
        reg_d2.h[0] += 8;
        if (PLAYER(((u8 *)g_player2))->power_style.h != 2) {
            reg_d2.h[0] -= 3;
        }
    }
    g_p2_laser_hit_timer = reg_d2.h[0];
    p2_boss_hits_add();
}


void p2_boss_hits_add(void) {
    extern void p2_boss_hits_score(u16);
    g_boss_hits += reg_d0.h[0];
    if (!(reg_d1.w & 0x40)) {
        p2_boss_hits_score(reg_d0.h[0]);
        return;
    }
    g_boss_hits += reg_d0.h[0];
    p2_boss_hits_score(reg_d0.h[0]);
}

void p2_boss_hits_score()
{
    if ((s32)g_boss_hits > 0x7FFF) {
        g_boss_hits = 0x7FFF;
    }

    reg_d0.w = reg_d3.w;
    reg_a0 = (u8 *)(&(*(u8 *)&g_p1_score_pending));
    score_value_add();
    g_boss_hit_decay_timer = 10;
    g_boss_hit_palette = 7;
}

extern s8 g_boss_hp_bar_flags;
extern u8 D_0028E635;

void hud_p1_hyper_count_put(void) {
    s32 deferred_text_put();
    reg_d0.h[0] = 0xC8;
    reg_d1.h[0] = 0x200;
    if ((g_boss_present & 1) && (g_boss_hp_bar_flags >= 0)) {
        if (D_0028E635 & 0x10) {
            reg_d1.h[0] = 0;
            reg_d0.h[0] = 0xCC;
            goto block_4;
        }
    } else {
block_4:
        reg_d2.h[0] = 2;
        reg_d3.h[0] = 5;
        if (g_p1_hyper_active == 0) {
            reg_d4.h[0] = g_p1_hyper_items;
            reg_a0 = (u8 *)(hyper_item_count_text);
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d4.h[0] = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            deferred_text_put();
            return;
        }
        reg_d4.w = 0x0414000A;
        deferred_text_put();
    }
}

void hud_p2_hyper_count_put(void) {
    s32 deferred_text_put();
    reg_d0.h[0] = 0xC8;
    reg_d1.h[0] = 0x1400;
    if ((g_boss_present & 1) && (g_boss_hp_bar_flags >= 0)) {
        if (D_0028E635 & 0x10) {
            reg_d0.h[0] = 0xCC;
            reg_d1.h[0] = 0x1600;
            goto block_4;
        }
    } else {
block_4:
        reg_d2.h[0] = 2;
        reg_d3.h[0] = 5;
        if (g_p2_hyper_active == 0) {
            reg_d4.h[0] = g_p2_hyper_items;
            reg_a0 = (u8 *)(hyper_item_count_text);
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d4.h[0] = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            deferred_text_put();
            return;
        }
        reg_d4.w = 0x0414000A;
        deferred_text_put();
    }
}

extern u16 g_p1_extend_setting;
extern s32 g_p1_extend_score;

void p1_extend_score_set(void) {
    reg_a0 = (u8 *)(&g_p1_extend_score);
    reg_a1 = (u8 *)(&(*(s32 *)&g_p1_extend_setting));
    extend_score_set();
}

extern u16 g_p2_extend_setting;
extern s32 g_p2_extend_score;

void p2_extend_score_set(void) {
    reg_a0 = (u8 *)(&(*(u8 *)&g_p2_extend_score));
    reg_a1 = (u8 *)(&(*(u8 *)&g_p2_extend_setting));
    extend_score_set();
}

extern u8 g_setting_extend;
extern u8 D_006E5C08[];

void extend_score_set(void)
{
    reg_d0.w = 0;
    reg_d0.b[0] = g_setting_extend;
    if (g_simulation_active != 0) {
        reg_d0.b[0] = D_006E5C08[0];
    }

    reg_a2 = (u8 *)extend_scores_first;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    *(*(s32 **)&reg_a0) = *(s32 *)(reg_a2 + reg_d0.h[0]);
    *(*(u16 **)&reg_a1) = reg_d0.h[0];
}


void extend_score_advance(void) {
    s32 bcd_add_registers(Reg32 *, Reg32 *);
    u8 *a5 = reg_a5;

    reg_d0.h[0] = *(u16 *) reg_a4;
    reg_a5 = (u8 *)extend_scores_later;
    reg_d1.w = *(u32 *) (reg_a5 + reg_d0.h[0]);
    if (reg_d1.w != -1U) goto next_1;
    *(u32 *) reg_a2 = -1U;
    goto block_end;
next_1:
    if (!(reg_d1.w & 0x80000000)) goto next_2;
    reg_d1.w &= 0x7FFFFFFF;
    goto next_3;
next_2:
    *(u16 *) reg_a4 = 0xC;
next_3:
    reg_d2.w = *(u32 *) reg_a2;
    reg_d0.h[0] = 0;
    bcd_add_registers(&reg_d1, &reg_d2);
    *(u32 *) reg_a2 = reg_d2.w;
block_end:
    reg_a5 = a5;
}

extern u8 D_002B4E28[];
extern u8 D_002B5728[];
extern u8 D_002B5F28[];
extern u8 D_002B6828[];
extern u16 g_p1_score_extra_cell[];
extern u16 g_p2_score_extra_cell[];
extern u16 g_p1_score_cells[];
extern u16 g_p2_score_cells[];

void score_cells_init(void) {
    u32 t;
    s32 t2;

    reg_d0.w = 0;
    reg_d2.w = 0;
    reg_d1.w = (u32) D_002B4E28;
    reg_d3.w = 0;
    reg_d6.w = 1;
    reg_a0 = (u8 *)g_p1_score_cells;
loop_1:
    reg_d7.w = 8;
loop_2:
    *(u16 *)reg_a0 = reg_d0.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d1.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    reg_d1.w += 0x100;
    t2 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t2;
    if (((s64) ((s64) (u16) t2 << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_d1.w = (u32) D_002B5F28;
    reg_a0 = (u8 *)g_p2_score_cells;
    t = reg_d6.h[0] - 1;
    reg_d6.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_a0 = (u8 *)g_p1_score_extra_cell;
    *(u16 *)reg_a0 = reg_d0.h[0];
    reg_tmp.w = (u32) D_002B5728;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = 0xC030;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 = (u8 *)g_p2_score_extra_cell;
    *(u16 *)reg_a0 = reg_d0.h[0];
    reg_tmp.w = (u32) D_002B6828;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = 0xC030;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
}

extern u8 g_p1_score_panel_flags;
extern u16 g_p1_score_billions_saved;
extern u32 g_p1_score_saved;
extern u16 g_p1_score_digits;
extern u16 g_p1_score_billions;
extern u32 g_p1_score;

void p1_score_cells_reset(void) {
    reg_d0.w = 0;
    reg_d2.w = 0;
    reg_d1.w = (u32) D_002B4E28;
    reg_d3.w = 0;
    reg_a0 = (u8 *)(g_p1_score_cells);
    reg_d7.w = 8;
    do {
        *(u16 *)reg_a0 = reg_d0.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[1];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d2.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d3.h[0];
        reg_a0 += 2;
        reg_d1.w += 0x100;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_a0 = (u8 *)(g_p1_score_extra_cell);
    *(u16 *)reg_a0 = 1;
    reg_tmp.w = (u32) D_002B5728;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = 0xC030;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_d0.w = 0;
    g_p1_score = reg_d0.w;
    g_p1_score_saved = reg_d0.w;
    reg_a0 += 2;
    g_p1_score_billions = reg_d0.h[0];
    g_p1_score_panel_flags = reg_d0.b[0];
    g_p1_score_billions_saved = reg_d0.h[0];
    g_p1_score_digits = reg_d0.h[0];
}

extern u8 g_p2_score_panel_flags;
extern u16 g_p2_score_billions_saved;
extern u32 g_p2_score_saved;
extern u16 g_p2_score_digits;
extern u16 g_p2_score_billions;
extern u32 g_p2_score;

void p2_score_cells_reset(void) {
    reg_d0.w = 0;
    reg_d2.w = 0;
    reg_d1.w = (u32) D_002B5F28;
    reg_d3.w = 0;
    reg_a0 = (u8 *)(g_p2_score_cells);
    reg_d7.w = 8;
    do {
        *(u16 *)reg_a0 = reg_d0.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[1];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d2.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d3.h[0];
        reg_a0 += 2;
        reg_d1.w += 0x100;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_a0 = (u8 *)(g_p2_score_extra_cell);
    *(u16 *)reg_a0 = 1;
    reg_tmp.w = (u32) D_002B6828;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = 0xC030;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_d0.w = 0;
    g_p2_score = reg_d0.w;
    g_p2_score_saved = reg_d0.w;
    reg_a0 += 2;
    g_p2_score_billions = reg_d0.h[0];
    g_p2_score_panel_flags = reg_d0.b[0];
    g_p2_score_billions_saved = reg_d0.h[0];
    g_p2_score_digits = reg_d0.h[0];
}

void p1_score_cells_reset_short(void) {
    reg_d0.w = 0;
    reg_d2.w = 0;
    reg_d1.w = (u32) D_002B4E28;
    reg_d3.w = 0;
    reg_a0 = (u8 *)(g_p1_score_cells);
    reg_d7.w = 8;
    do {
        *(u16 *)reg_a0 = reg_d0.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[1];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d2.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d3.h[0];
        reg_a0 += 2;
        reg_d1.w += 0x100;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_a0 = (u8 *)(g_p1_score_extra_cell);
    *(u16 *)reg_a0 = 1;
    reg_d0.w = 0;
    g_p1_score = reg_d0.w;
    g_p1_score_saved = reg_d0.w;
    reg_a0 += 2;
    g_p1_score_billions = reg_d0.h[0];
    g_p1_score_panel_flags = reg_d0.b[0];
    g_p1_score_billions_saved = reg_d0.h[0];
}

void p2_score_cells_reset_short(void) {
    reg_d0.w = 0;
    reg_d2.w = 0;
    reg_d1.w = (u32) D_002B5F28;
    reg_d3.w = 0;
    reg_a0 = (u8 *)(g_p2_score_cells);
    reg_d7.w = 8;
    do {
        *(u16 *)reg_a0 = reg_d0.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[1];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d2.h[0];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d3.h[0];
        reg_a0 += 2;
        reg_d1.w += 0x100;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_a0 = (u8 *)(g_p2_score_extra_cell);
    *(u16 *)reg_a0 = 1;
    reg_d0.w = 0;
    g_p2_score = reg_d0.w;
    g_p2_score_saved = reg_d0.w;
    reg_a0 += 2;
    g_p2_score_billions = reg_d0.h[0];
    g_p2_score_panel_flags = reg_d0.b[0];
    g_p2_score_billions_saved = reg_d0.h[0];
}

extern s32 g_p1_chain_points_shown2;
extern s32 g_p1_chain_points_shown;
extern s32 g_p1_chain_points;
extern s32 g_p1_chain_first_score;

void p1_chain_state_clear(void) {
    u32 savedD0 = reg_d0.w;
    s32 zero = (u16)(reg_d0.w = 0);

    g_p1_laser_hit_timer = 0;
    g_p1_hits_shown = 0;
    g_p1_hits = 0;
    g_p1_chain_points_shown2 = zero;
    g_p1_chain_points_shown = zero;
    g_p1_chain_points = zero;
    g_p1_hit10_anim_count = 0;
    g_p1_hit10_color_timer = 0;
    g_p1_hit10_display_timer = 0;
    g_p1_combo_break_color_timer = 0;
    g_p1_hit_display_timer = 0;
    g_p1_chain_points_display_timer = 0;
    g_p1_combo_timer = 0;
    g_p1_max_hits = reg_d0.h[0];
    g_p1_chain_first_score_shown = reg_d0.w;
    g_p1_chain_first_score = zero;
    reg_d0.w = savedD0;
}

extern s32 g_p2_chain_points_shown2;
extern s32 g_p2_chain_points_shown;
extern s32 g_p2_chain_points;
extern s32 g_p2_chain_first_score;

void p2_chain_state_clear(void)
{
    u32 savedD0;
    u32 clearedHalfword;

    savedD0 = reg_d0.w;
    clearedHalfword = (g_p2_laser_hit_timer = 0);
    g_p2_chain_points_shown2 = clearedHalfword;
    g_p2_chain_points_shown = clearedHalfword;
    g_p2_chain_points = clearedHalfword;
    g_p2_chain_first_score = clearedHalfword;
    reg_d0.w = 0;
    g_p2_hits_shown = 0;
    g_p2_hits = 0;
    g_p2_hit10_anim_count = 0;
    g_p2_hit10_color_timer = 0;
    g_p2_hit10_display_timer = 0;
    g_p2_combo_break_color_timer = 0;
    g_p2_hit_display_timer = 0;
    g_p2_chain_points_display_timer = 0;
    g_p2_combo_timer = 0;
    g_p2_max_hits = reg_d0.h[0];
    g_p2_chain_first_score_shown = reg_d0.w;
    reg_d0.w = savedD0;
}

void score_cell_bump() {
    *(u16 *)(reg_a0 + 6) += 1;
    *(u16 *)reg_a0 = 1;
}


void p1_score_digits_grow(void) {
    u8 *temp_s0;
    u16 temp_a0;

    temp_a0 = (s16)g_p1_score_digits;
    if (temp_a0 != 9) {
        temp_s0 = reg_a0;
        g_p1_score_digits = temp_a0 + 1;
        reg_a0 = ((u8 *)g_p1_score_extra_cell);
        score_cell_bump(temp_a0);
        reg_a0 = temp_s0;
    }
}


void p2_score_digits_grow(void) {
    u8 *temp_s0;
    u16 temp_a0;

    temp_a0 = (s16)g_p2_score_digits;
    if (temp_a0 != 9) {
        temp_s0 = reg_a0;
        g_p2_score_digits = temp_a0 + 1;
        reg_a0 = ((u8 *)g_p2_score_extra_cell);
        score_cell_bump(temp_a0);
        reg_a0 = temp_s0;
    }
}

extern u16 g_score_task_active;

void score_cells_flush(void) {
    u32 tmp;

    switch (g_score_task_active) {
    case 0:
        break;
    default:
        reg_a0 = (u8 *)g_p1_score_cells;
        reg_d0.w = 0x11;
loop_1:
        if (*(u16 *)reg_a0 != 0) {
            *(u16 *)reg_a0 = 0;
            reg_a0 += 2;
            reg_tmp.h[1] = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_tmp.h[0] = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 = (u8 *)reg_tmp.w;
            *(u16 *)(reg_a1 + 2) = *(u16 *)reg_a0;
            reg_a0 += 2;
            *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
            reg_a0 += 2;
            tmp = reg_d0.h[0] - 1;
            reg_d0.h[0] = tmp;
            if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                goto loop_1;
            }
            return;
        }
        reg_a0 += 0xA;
        tmp = reg_d0.h[0] - 1;
        reg_d0.h[0] = tmp;
        if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
            goto loop_1;
        }
        if (g_p1_score_extra_cell[0] != 0) {
            reg_a0 = (u8 *)g_p1_score_extra_cell;
            *(u16 *)reg_a0 = 0;
            reg_a0 += 2;
            reg_tmp.h[1] = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_tmp.h[0] = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 = (u8 *)reg_tmp.w;
            *(u16 *)(reg_a1 + 2) = *(u16 *)reg_a0;
            reg_a0 += 2;
            *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
            reg_a0 += 2;
        }
        if (g_p2_score_extra_cell[0] != 0) {
            reg_a0 = (u8 *)g_p2_score_extra_cell;
            *(u16 *)reg_a0 = 0;
            reg_a0 += 2;
            reg_tmp.h[1] = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_tmp.h[0] = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 = (u8 *)reg_tmp.w;
            *(u16 *)(reg_a1 + 2) = *(u16 *)reg_a0;
            reg_a0 += 2;
            *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
            reg_a0 += 2;
        }
    }
}


void p1_score_cells_mark(void)
{
    u32 saved_d0 = reg_d0.w;
    s16 *saved_a0 = ((s16 *)reg_a0);

    (*(s16 **)&reg_a0) = ((s16 *)g_p1_score_cells);
    reg_d0.w = 8;

    do {
        *(*(s16 **)&reg_a0) = 1;
        (*(s16 **)&reg_a0) += 5;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_d0.w = saved_d0;
    ((s16 *)g_p1_score_extra_cell)[0] = 1;
    (*(s16 **)&reg_a0) = saved_a0;
}


void p2_score_cells_mark(void)
{
    u32 saved_d0 = reg_d0.w;
    u32 saved_a0 = (*(u32 *)&reg_a0);

    (*(u32 *)&reg_a0) = (u32)((s16 *)g_p2_score_cells);
    reg_d0.w = 8;

    do {
        *(s16 *)(*(u32 *)&reg_a0) = 1;
        (*(u32 *)&reg_a0) += 10;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_d0.w = saved_d0;
    ((s16 *)g_p2_score_extra_cell)[0] = 1;
    (*(u32 *)&reg_a0) = saved_a0;
}

extern u16 g_players_hidden;
extern void sprite_draw_with_hyper_display(u32 originalD1);

void hyper_effect_sprite_draw(void)
{
    u32 originalD1;

    if (g_players_hidden == 0) {
        originalD1 = reg_d1.w;
        reg_d1.w = originalD1 + 0xF200F600u;
        reg_d3.h[0] = 0xE50;
        reg_d4.h[0] = 4;
        sprite_draw_with_hyper_display(originalD1);
        return;
    }
}

extern u16 g_p1_hyper_effect_delay;
extern u16 g_p1_hyper_effect_flag;
extern s32 g_p1_hyper_effect_sprite;

void p1_hyper_effect_start(void) {
    g_p1_hyper_effect_sprite = 0x9E8;
    g_p1_hyper_effect_flag = 1;
    g_p1_hyper_effect_delay = 1;
}

extern u8 D_0028E57D;
extern u16 g_p1_hyper_effect_flag;
extern s16 g_player1[];
void p1_hyper_effect_draw_first(void) {
    if (g_p1_hyper_effect_flag != 0) {
        if (g_player1[0] < 0) {
            reg_d1.h[1] = PLAYER(g_player1)->y.h;
            reg_d1.h[0] = PLAYER(g_player1)->x.h;
            reg_d2.w = (u32)g_p1_hyper_effect_sprite;
            hyper_effect_sprite_draw();
        }
        D_0028E57D -= 1;
        if ((s8) D_0028E57D < 0) {
            D_0028E57D = (*(u8 *)&g_p1_hyper_effect_delay);
            (*(u32 *)&g_p1_hyper_effect_sprite) += 1;
            if ((u32)g_p1_hyper_effect_sprite == 0xA04) {
                g_p1_hyper_effect_flag = 0;
            }
        }
    }
}

extern u8 D_0026B8D0[];
extern u16 g_p1_hyper_effect_frame;

void p1_hyper_effect_draw(void) {
    if (g_p1_hyper_effect_frame != 0) {
        reg_d0.h[0] = g_p1_hyper_effect_frame;
        reg_a0 = D_0026B8D0;
        g_p1_hyper_effect_sprite = *(u32 *)(reg_a0 + reg_d0.h[0]);
        if (g_player1[0] < 0) {
            reg_d1.h[1] = PLAYER(g_player1)->y.h;
            reg_d1.h[0] = PLAYER(g_player1)->x.h;
            reg_d2.w = (u32)g_p1_hyper_effect_sprite;
            hyper_effect_sprite_draw();
        }
        g_p1_hyper_effect_frame -= 4;
    }
}

extern u16 g_p2_hyper_effect_delay;
extern u16 g_p2_hyper_effect_flag;
extern s32 g_p2_hyper_effect_sprite;

void p2_hyper_effect_start(void) {
    g_p2_hyper_effect_sprite = 0x9E8;
    g_p2_hyper_effect_flag = 1;
    g_p2_hyper_effect_delay = 1;
}

extern u8 D_0028E579;
extern u16 g_p2_hyper_effect_flag;
extern s16 g_player2[];
void p2_hyper_effect_draw_first(void) {
    if (g_p2_hyper_effect_flag != 0) {
        if (g_player2[0] < 0) {
            reg_d1.h[1] = PLAYER(g_player2)->y.h;
            reg_d1.h[0] = PLAYER(g_player2)->x.h;
            reg_d2.w = (u32)g_p2_hyper_effect_sprite;
            hyper_effect_sprite_draw();
        }
        D_0028E579 -= 1;
        if ((s8) D_0028E579 < 0) {
            D_0028E579 = (*(u8 *)&g_p2_hyper_effect_delay);
            (*(u32 *)&g_p2_hyper_effect_sprite) += 1;
            if ((u32)g_p2_hyper_effect_sprite == 0xA04) {
                g_p2_hyper_effect_flag = 0;
            }
        }
    }
}

extern u16 g_p2_hyper_effect_frame;

void p2_hyper_effect_draw(void) {
    if (g_p2_hyper_effect_frame != 0) {
        reg_d0.h[0] = g_p2_hyper_effect_frame;
        reg_a0 = D_0026B8D0;
        g_p2_hyper_effect_sprite = *(u32 *)(reg_a0 + reg_d0.h[0]);
        if (g_player2[0] < 0) {
            reg_d1.h[1] = PLAYER(g_player2)->y.h;
            reg_d1.h[0] = PLAYER(g_player2)->x.h;
            reg_d2.w = (u32)g_p2_hyper_effect_sprite;
            hyper_effect_sprite_draw();
        }
        g_p2_hyper_effect_frame -= 4;
    }
}

s32 item_spawn_at_y();
extern u16 g_boss_hyper_wait;
extern u16 g_p1_hyper_items_pending;
extern u16 g_p1_lives;

void p1_hyper_items_update(void) {
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    u16 var_a0;
    if (g_boss_hyper_wait != 0) {
        if (g_player1[0] >= 0) {
            if ((s16)g_p1_lives >= 0) {
                return;
            }
            goto block_5;
        }
        if (PLAYER(g_player1)->bombs.b.count == 0) {
            goto block_5;
        }
    } else {
block_5:
        reg_d7.h[0] = g_p1_hyper_items_pending;
        if (g_p1_hyper_items_pending != 0) {
            if (g_p1_hyper_gauge == 0x95F) {
                g_p1_hyper_gauge = 0;
                reg_d7.h[0] += 1;
            }
            reg_d7.h[0] -= 1;
            reg_d6.h[0] = 0x7000;
            temp_s0 = reg_d0.w;
            temp_s1 = reg_d2.w;
            temp_s2 = reg_d6.w;
            temp_s3 = (s32)reg_a0;
            temp_s4 = (s32)reg_a2;
            do {
                reg_d0.w = 0xC;
                item_spawn_at_y();
                var_a0 = (u32)reg_d6.h[0] + 0x800;
                reg_d6.h[0] = var_a0;
            } while ((s16)(--reg_d7.h[0]) >= 0);
            reg_d0.w = temp_s0;
            reg_d2.w = temp_s1;
            reg_d6.w = temp_s2;
            reg_a0 = (u8 *)temp_s3;
            reg_a2 = (u8 *)temp_s4;
            g_p1_hyper_items_pending = 0;
        }
    }
}

#ifndef DEATH_LABEL
void p1_hyper_items_pending_take(void) {
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    u16 var_a0;
    reg_d7.h[0] = g_p1_hyper_items_pending;
    if (g_p1_hyper_items_pending != 0) {
        if (g_p1_hyper_gauge == 0x95F) {
            g_p1_hyper_gauge = 0;
            reg_d7.h[0] += 1;
        }
        reg_d7.h[0] -= 1;
        reg_d6.h[0] = 0x7000;
        temp_s0 = reg_d0.w;
        temp_s1 = reg_d2.w;
        temp_s2 = reg_d6.w;
        temp_s3 = (s32)reg_a0;
        temp_s4 = (s32)reg_a2;
        do {
            reg_d0.w = 0xC;
            item_spawn_at_y();
            var_a0 = (u32)reg_d6.h[0] + 0x800;
            reg_d6.h[0] = var_a0;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        reg_d0.w = temp_s0;
        reg_d2.w = temp_s1;
        reg_d6.w = temp_s2;
        reg_a0 = (u8 *)temp_s3;
        reg_a2 = (u8 *)temp_s4;
        g_p1_hyper_items_pending = 0;
    }
}
#endif

extern u16 g_p2_hyper_items_pending;
extern u16 g_p2_lives;

void p2_hyper_items_update(void) {
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    u16 var_a0;
    if (g_boss_hyper_wait != 0) {
        if (g_player2[0] >= 0) {
            if ((s16)g_p2_lives >= 0) {
                return;
            }
            goto block_5;
        }
        if (PLAYER(g_player2)->bombs.b.count == 0) {
            goto block_5;
        }
    } else {
block_5:
        reg_d7.h[0] = g_p2_hyper_items_pending;
        if (g_p2_hyper_items_pending != 0) {
            if (g_p2_hyper_gauge == 0x95F) {
                g_p2_hyper_gauge = 0;
                reg_d7.h[0] += 1;
            }
            reg_d7.h[0] -= 1;
            reg_d6.h[0] = 0x7000;
            temp_s0 = reg_d0.w;
            temp_s1 = reg_d2.w;
            temp_s2 = reg_d6.w;
            temp_s3 = (s32)reg_a0;
            temp_s4 = (s32)reg_a2;
            do {
                reg_d0.w = 0x14;
                item_spawn_at_y();
                var_a0 = (u32)reg_d6.h[0] + 0x800;
                reg_d6.h[0] = var_a0;
            } while ((s16)(--reg_d7.h[0]) >= 0);
            reg_d0.w = temp_s0;
            reg_d2.w = temp_s1;
            reg_d6.w = temp_s2;
            reg_a0 = (u8 *)temp_s3;
            reg_a2 = (u8 *)temp_s4;
            g_p2_hyper_items_pending = 0;
        }
    }
}

#ifndef DEATH_LABEL
void p2_hyper_items_pending_take(void) {
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    u16 var_a0;
    reg_d7.h[0] = g_p2_hyper_items_pending;
    if (g_p2_hyper_items_pending != 0) {
        if (g_p2_hyper_gauge == 0x95F) {
            g_p2_hyper_gauge = 0;
            reg_d7.h[0] += 1;
        }
        reg_d7.h[0] -= 1;
        reg_d6.h[0] = 0x7000;
        temp_s0 = reg_d0.w;
        temp_s1 = reg_d2.w;
        temp_s2 = reg_d6.w;
        temp_s3 = (s32)reg_a0;
        temp_s4 = (s32)reg_a2;
        do {
            reg_d0.w = 0x14;
            item_spawn_at_y();
            var_a0 = (u32)reg_d6.h[0] + 0x800;
            reg_d6.h[0] = var_a0;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        reg_d0.w = temp_s0;
        reg_d2.w = temp_s1;
        reg_d6.w = temp_s2;
        reg_a0 = (u8 *)temp_s3;
        reg_a2 = (u8 *)temp_s4;
        g_p2_hyper_items_pending = 0;
    }
}
#endif


void p1_hyper_gauge_hold_full(void) {
    g_p1_hyper_gauge = 0x95F;
}

extern u16 D_00255740[];
extern u16 g_bullet_cancel[];
extern u16 g_bullet_cancel_kind[];

void p1_hyper_gauge_check_full(void) {
    u32 save_d0;
    u32 save_d2;
    u32 save_d6;
    u8 *save_a0;
    u8 *save_a2;

    if (!((s32) g_p1_hyper_gauge > 0x95F)) goto block_end;
    if (g_p1_hyper_items == 5) {
        p1_hyper_gauge_hold_full();
        return;
    }
    if (g_p1_hyper_items_pending == 4) {
        p1_hyper_gauge_hold_full();
        goto block_end;
    }
    g_p1_hyper_gauge = 0;
    switch (g_boss_hyper_wait) { case 0: goto next_1; }
    if (g_player1[0] >= 0) goto next_2;
    if (PLAYER(g_player1)->bombs.b.count != 0) goto next_2;
next_1:
    if (g_p1_hyper_active == 0) goto next_3;
next_2:
    g_p1_hyper_items_pending += 1;
    if (g_player1[0] < 0) {
        reg_a0 = (u8 *)(D_00255740);
        reg_d0.h[0] = g_p1_hyper_items_pending;
        reg_d0.h[0] -= 1;
        reg_d0.h[0] += reg_d0.h[0];
        g_bullet_cancel[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d0.w = 0x20;
        if ((g_p1_hyper_items_pending & 0xFFFF) == 5) {
            reg_d0.w = 0x2C;
        }
        g_bullet_cancel_kind[0] = reg_d0.h[0];
    }
    return;
next_3:
    reg_d0.w = 0xC;
    save_d6 = reg_d6.w;
    save_d2 = reg_d2.w;
    save_d0 = reg_d0.w;
    save_a0 = reg_a0;
    save_a2 = reg_a2;
    reg_d6.h[0] = 0x7000;
    item_spawn_at_y();
    reg_d0.w = save_d0;
    reg_d2.w = save_d2;
    reg_d6.w = save_d6;
    reg_a0 = save_a0;
    reg_a2 = save_a2;
block_end:
    return;
}

void p2_hyper_gauge_hold_full(void) {
    g_p2_hyper_gauge = 0x95F;
}


void p2_hyper_gauge_check_full(void) {
    u32 save_d0;
    u32 save_d2;
    u32 save_d6;
    u8 *save_a0;
    u8 *save_a2;

    if (!((s32) g_p2_hyper_gauge > 0x95F)) goto block_end;
    if (g_p2_hyper_items == 5) {
        p2_hyper_gauge_hold_full();
        return;
    }
    if (g_p2_hyper_items_pending == 4) {
        p2_hyper_gauge_hold_full();
        goto block_end;
    }
    g_p2_hyper_gauge = 0;
    switch (g_boss_hyper_wait) { case 0: goto next_1; }
    if (g_player2[0] >= 0) goto next_2;
    if (PLAYER(g_player2)->bombs.b.count != 0) goto next_2;
next_1:
    if (g_p2_hyper_active == 0) goto next_3;
next_2:
    g_p2_hyper_items_pending += 1;
    if (g_player2[0] < 0) {
        reg_a0 = (u8 *)(D_00255740);
        reg_d0.h[0] = g_p2_hyper_items_pending;
        reg_d0.h[0] -= 1;
        reg_d0.h[0] += reg_d0.h[0];
        g_bullet_cancel[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d0.w = 0x30;
        if ((g_p2_hyper_items_pending & 0xFFFF) == 5) {
            reg_d0.w = 0x3C;
        }
        g_bullet_cancel_kind[0] = reg_d0.h[0];
    }
    return;
next_3:
    reg_d0.w = 0x14;
    save_d6 = reg_d6.w;
    save_d2 = reg_d2.w;
    save_d0 = reg_d0.w;
    save_a0 = reg_a0;
    save_a2 = reg_a2;
    reg_d6.h[0] = 0x7000;
    item_spawn_at_y();
    reg_d0.w = save_d0;
    reg_d2.w = save_d2;
    reg_d6.w = save_d6;
    reg_a0 = save_a0;
    reg_a2 = save_a2;
block_end:
    return;
}

extern u16 g_boss_hit_anim_count;

void boss_hits_display_reset(void) {
    u16 halfword;

    g_boss_hits = 0xFFFF;
    reg_d0.w = 0x17;
    halfword = reg_d0.h[0];
    g_boss_hit_anim_count = halfword;
    g_boss_hit_decay_timer = halfword;
}

void p1_chain_reset(void) {
    reg_d0.w = 0;
    g_p1_chain_first_score = reg_d0.w;
    g_p1_chain_first_score_shown = reg_d0.w;
    g_p1_combo_timer = reg_d0.h[0];
    g_p1_hit10_color_timer = reg_d0.h[0];
    g_p1_hits = reg_d0.h[0];
    g_p1_chain_points = reg_d0.w;
    g_p1_chain_points_shown = reg_d0.w;
}

void p2_chain_reset(void) {
    reg_d0.w = 0;
    g_p2_chain_first_score = reg_d0.w;
    g_p2_chain_first_score_shown = reg_d0.w;
    g_p2_combo_timer = reg_d0.h[0];
    g_p2_hit10_color_timer = reg_d0.h[0];
    g_p2_hits = reg_d0.h[0];
    g_p2_chain_points = reg_d0.w;
    g_p2_chain_points_shown = reg_d0.w;
}

extern u16 g_p1_lives;
extern u16 g_p1_ship_type;

void hud_p1_lives_put(void) {
    s32 deferred_text_put();
    s32 deferred_text_clear();
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    reg_d0.h[0] = 0xBC;
    reg_d1.h[0] = 0x200;
    if ((g_boss_present & 1) && (g_boss_hp_bar_flags >= 0)) {
        if (D_0028E635 & 0x10) {
            reg_d1.h[0] = 0;
            reg_d0.h[0] = 0xC0;
            goto block_4;
        }
    } else {
block_4:
        reg_d2.h[0] = 1;
        reg_d3.h[0] = 0;
        reg_d7.w = 5;
        reg_d6.h[0] = g_p1_lives;
        if (g_p1_lives != 0) {
            reg_d6.h[0] -= 1;
            reg_d7.h[0] -= 1;
            if ((s32) reg_d6.h[0] > 5) {
                reg_d6.w = 5;
            }
            reg_a0 = (u8 *)(lives_text_p1);
            reg_d7.h[0] -= reg_d6.h[0];
            reg_d4.h[0] = g_p1_ship_type;
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d4.h[0] = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d5.h[0] = reg_d1.h[0];
            do {
                deferred_text_put();
                reg_d1.h[0] += 0x100;
            } while ((s16)(--reg_d6.h[0]) >= 0);
            if ((s16) reg_d7.h[0] < 0) {
                goto block_end;
            }
        }
        do {
            deferred_text_clear();
            reg_d1.h[0] += 0x100;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
block_end:
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
}

extern u16 g_p2_lives;
extern u16 g_p2_ship_type;

void hud_p2_lives_put(void) {
    s32 deferred_text_put();
    s32 deferred_text_clear();
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    reg_d0.h[0] = 0xBC;
    reg_d1.h[0] = 0x1900;
    if ((g_boss_present & 1) && (g_boss_hp_bar_flags >= 0)) {
        if (D_0028E635 & 0x10) {
            reg_d0.h[0] = 0xC0;
            reg_d1.h[0] = 0x1B00;
            goto block_4;
        }
    } else {
block_4:
        reg_d2.h[0] = 1;
        reg_d3.h[0] = 0;
        reg_d7.w = 5;
        reg_d6.h[0] = g_p2_lives;
        if (g_p2_lives != 0) {
            reg_d6.h[0] -= 1;
            reg_d7.h[0] -= 1;
            if ((s32) reg_d6.h[0] > 5) {
                reg_d6.w = 5;
            }
            reg_a0 = (u8 *)(lives_text_p2);
            reg_d7.h[0] -= reg_d6.h[0];
            reg_d4.h[0] = g_p2_ship_type;
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d4.h[0] = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d5.h[0] = reg_d1.h[0];
            do {
                deferred_text_put();
                reg_d1.h[0] -= 0x100;
            } while ((s16)(--reg_d6.h[0]) >= 0);
            if ((s16) reg_d7.h[0] < 0) {
                goto block_end;
            }
        }
        do {
            deferred_text_clear();
            reg_d1.h[0] -= 0x100;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
block_end:
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
}

extern u16 g_score_panel_intro;
extern u16 g_boss_hp_bar_move_count;
extern u16 g_stage;
extern u8 g_replay_mode;
#ifndef DDPDOJ_PC
extern u16 D_006C8E5C[];
#endif

void score_panel_intro_begin(void) {
    if (!(g_boss_present & 1)) {
        g_boss_hp_bar_move_count = 0x53;
        if (g_stage == 0 && g_replay_mode == 2) {
            if (D_006C8E5C[0] == 0) {
                g_boss_hp_bar_move_count += 0x42;
            } else {
                g_boss_hp_bar_move_count += 0x6B;
            }
        }
        if (g_simulation_active != 0) {
            g_boss_hp_bar_move_count = 1;
        }
    }
    g_score_panel_intro = 1;
}

void hud_p1_caption_clear(void) {
    void deferred_text_clear(void);
    reg_d0.h[0] = 0xD4;
    reg_d2.sh[0] = 7;
    reg_d3.sh[0] = 7;
    reg_d1.h[0] = 0;
    deferred_text_clear();
}

void hud_p2_caption_clear(void) {
    void deferred_text_clear(void);
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0x1400;
    reg_d2.sh[0] = 7;
    reg_d3.sh[0] = 7;
    deferred_text_clear();
}


void hud_p1_caption_refresh(void) {
    if (!(g_boss_present & 1)) {
        hud_p1_caption_put();
        return;
    }
    if (g_boss_hp_bar_flags < 0) {
        hud_p1_caption_put();
    }
}

extern Reg32 reg_d0;
extern Reg32 reg_d1;

void hud_p1_caption_put(void) {
    extern void deferred_text_put(void);
    reg_d0.h[0] = 0xD4;
    reg_d2.sh[0] = 7;
    reg_d3.sh[0] = 1;
    reg_d4.sw = 0x0404000A;
    reg_d1.h[0] = 0;
    deferred_text_put();
}


void hud_p2_caption_refresh(void) {
    if (!(g_boss_present & 1)) {
        hud_p2_caption_put();
        return;
    }
    if (g_boss_hp_bar_flags < 0) {
        hud_p2_caption_put();
    }
}

void hud_p2_caption_put(void) {
    extern void deferred_text_put(void);
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0x1A00;
    reg_d2.sh[0] = 7;
    reg_d3.sh[0] = 1;
    reg_d4.sw = 0x3EE000A;
    deferred_text_put();
}

void hud_p1_caption_clear_shifted(void)
{
    extern void deferred_text_clear(void);
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0;
    reg_d2.h[0] = 7;
    reg_d3.h[0] = 7;

    if ((g_boss_present & 1) && g_boss_hp_bar_flags >= 0) {
        if (!(D_0028E635 & 0x10)) {
            return;
        }

        reg_d1.h[0] = 0;
        reg_d0.h[0] = 0xCC;
        reg_d2.h[0] = 5;
        reg_d3.h[0] = 5;
    }

    deferred_text_clear();
}

void hud_p2_caption_clear_shifted(void) {
    s32 deferred_text_clear();
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0x1400;
    reg_d2.h[0] = 7;
    reg_d3.h[0] = 7;
    if ((g_boss_present & 1) && (g_boss_hp_bar_flags >= 0)) {
        if (D_0028E635 & 0x10) {
            reg_d0.h[0] = 0xCC;
            reg_d1.h[0] = 0x1600;
            reg_d2.h[0] = 5;
            reg_d3.h[0] = 5;
            goto block_4;
        }
    } else {
block_4:
        deferred_text_clear();
    }
}

void p1_hyper_gauge_bonus_add(void)
{
    if (g_simulation_active != 0) {
        g_p1_hyper_gauge += 0x258;
    } else {
        g_p1_hyper_gauge += 0x258;
    }

    if ((s32)g_p1_hyper_gauge >= 0x95F) {
        g_p1_hyper_gauge = 0x95E;
    }
}

void p2_hyper_gauge_bonus_add(void)
{
    if (g_simulation_active != 0) {
        g_p2_hyper_gauge += 0x258;
    } else {
        g_p2_hyper_gauge += 0x258;
    }

    if ((s32)g_p2_hyper_gauge >= 0x95F) {
        g_p2_hyper_gauge = 0x95E;
    }
}

u16 D_0026B898[7] = {
    0x0000, 0xFFFF, 0x0000, 0x0001, 0x0002, 0x0003, 0x0000,
};

u16 D_0026B8A8[7] = {
    0x0002, 0x0002, 0x0003, 0x0002, 0x0002, 0x0000, 0x0000,
};

u16 D_0026B8B8[7] = {
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0000, 0x0000,
};

u8 D_0026B8D0[80] = {
    0x00, 0x00, 0x00, 0x00, 0x09, 0x0A, 0x00, 0x00, 0x08, 0x0A, 0x00, 0x00, 0x07, 0x0A, 0x00, 0x00,
    0x06, 0x0A, 0x00, 0x00, 0x05, 0x0A, 0x00, 0x00, 0x04, 0x0A, 0x00, 0x00, 0xF4, 0x09, 0x00, 0x00,
    0xF5, 0x09, 0x00, 0x00, 0xF6, 0x09, 0x00, 0x00, 0xF7, 0x09, 0x00, 0x00, 0xF8, 0x09, 0x00, 0x00,
    0xF9, 0x09, 0x00, 0x00, 0xFA, 0x09, 0x00, 0x00, 0xFB, 0x09, 0x00, 0x00, 0xFC, 0x09, 0x00, 0x00,
    0xFD, 0x09, 0x00, 0x00, 0xFE, 0x09, 0x00, 0x00, 0xFF, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
