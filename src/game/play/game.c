#include "common.h"
#include "player_slot.h"
#ifdef DDPDOJ_PC
#include "pc_enemy_animation.h"
#endif

extern u8 g_player_slots[];
extern u8 g_player_slot2[];
#include "enemy.h"
#include "task.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

void enemies_stop();
void player_slot_join(void);
void game_state_clear(void);
void enemy_anims_clear(void);
void enemy_anims_spawn_done(void);
void enemy_anim_spawn(void);
void enemy_anim_init(void);
void enemy_anim_restart(void);

extern s32 g_ground_task_handle;

void game_ground_task_stop(void) {
    enemies_stop();
    reg_a0 = (u8 *)(&g_ground_task_handle);
    task_request_stop();
}

extern u16 g_stage_x4;
extern u16 g_stage_x2;
extern u16 g_stage;

void game_stage_set(void) {
    u32 value;

    value = reg_d0.h[0];
    g_stage = value;
    value = value + value;
    reg_d0.h[0] = value;
    value = reg_d0.h[0];
    g_stage_x2 = value;
    value = value + value;
    reg_d0.h[0] = value;
    value = reg_d0.h[0];
    g_stage_x4 = value;
}

extern u8 g_boss_present;
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
extern u16 g_stopped_and_blocked;
extern u16 g_bullets_blocked;
extern u16 g_enemies_stopped;
extern u16 g_scroll_line_step;
extern u16 g_scroll_line;

void game_stage_signals_clear(void) {
    (*(s16 *)&g_boss_present) = 0;
    g_enemy_signal_f = 0;
    g_enemy_signal_e = 0;
    g_enemy_signal_d = 0;
    g_enemy_signal_c = 0;
    g_enemy_signal_b = 0;
    g_enemy_signal_a = 0;
    g_enemy_signal_9 = 0;
    g_enemy_signal_8 = 0;
    g_enemy_signal_7 = 0;
    g_enemy_signal_6 = 0;
    g_enemy_signal_5 = 0;
    g_enemy_signal_4 = 0;
    g_enemy_signal_3 = 0;
    g_enemy_signal_2 = 0;
    g_enemy_signal_1 = 0;
    g_enemy_signal_0 = 0;
    g_stopped_and_blocked = 0;
    g_bullets_blocked = 0;
    g_enemies_stopped = 0;
    g_scroll_line_step = 0;
    g_scroll_line = 0;
}

s32 bullets_clear();                            /* extern */
s32 explosions_clear();                            /* extern */
s32 enemies_reset();                            /* extern */
s32 items_clear();                            /* extern */
s32 debris_clear();                            /* extern */
s32 sparks_clear();                            /* extern */
s32 wrecks_clear();                            /* extern */

void game_stage_objects_clear(void) {
    game_stage_signals_clear();
    enemies_reset();
    explosions_clear();
    debris_clear();
    wrecks_clear();
    enemy_anims_clear();
    sparks_clear();
    items_clear();
    bullets_clear();
    reg_d0.h[0] = 1;
    task_start();
    reg_tmp.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[0];
    g_ground_task_handle = reg_d0.w;
    *(s16 *)(reg_a0 + 6) = 0;
}

void enemies_stop() {
    g_enemies_stopped = 1;
}

void enemies_resume(void) {
    g_enemies_stopped = 0;
}

extern u16 g_two_player_state;
extern u16 g_two_player_game;

void game_players_count(void) {
    reg_a2 = (u8 *)g_player_slots;
    g_two_player_game = 0;
    reg_a3 = (u8 *)g_player_slot2;
    reg_d0.h[1] = PLAYER_SLOT(reg_a2)->ship_task[0];
    reg_d0.h[0] = PLAYER_SLOT(reg_a2)->ship_task[1];
    if (reg_d0.w != 0) {
        g_two_player_game += 1;
    }
    reg_d0.h[1] = PLAYER_SLOT(reg_a3)->ship_task[0];
    reg_d0.h[0] = PLAYER_SLOT(reg_a3)->ship_task[1];
    if (reg_d0.w != 0) {
        g_two_player_game += 1;
    }
    g_two_player_game -= 1;
    g_two_player_state = g_two_player_game;
    enemies_resume();
    if ((s16) g_two_player_state == -1) {
        enemies_stop((s16) g_two_player_state);
    }
    if (g_two_player_game == 0) {
        g_two_player_game = 1;
        return;
    }
    g_two_player_game = 0;
}

extern u16 g_continue_pending_count;

void game_both_players_out_check(void) {
    if ((g_continue_pending_count == 0) && ((s16)g_two_player_state == -1)) {
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

PlayerStart player_starts[2] = {
    { { 0x1000, 0x0E00 }, { 0x1000, 0x0E00 }, 2, 0, { 6, 7 } },
    { { 0x1000, 0x2A00 }, { 0x1000, 0x2A00 }, 3, 1, { 6, 7 } },
};

void player_slot_next_ship();
void player_slot_out_of_ships();
void player_slot_join_step();
void player_slot_start();
void player_slot_game_over();
void player_slot_set_game_step();
void player_slot_continue_wait();
void player_slot_clear_task_flags();
void player_slot_draw_bombs();

void (*player_slot_steps[12])(void) = {
    0,
    player_slot_next_ship,
    player_slot_out_of_ships,
    player_slot_join_step,
    player_slot_start,
    player_slot_game_over,
    player_slot_set_game_step,
    player_slot_continue_wait,
    player_slot_clear_task_flags,
    player_slot_draw_bombs,
    0,
    0,
};

extern s32 g_player_panel2_task_handle;
extern s32 g_player_panel1_task_handle;
extern s32 g_gauge_task_handle;

void player_slots_init(void) {
    u16 temp_a0;
    u16 temp_a1;
    reg_a0 = (u8 *)&player_starts[0];
    reg_a6 = (u8 *)g_player_slots;
    reg_d7.w = 1;
    do {
        PLAYER_SLOT(reg_a6)->other_0C[0] = ((PlayerStart *)reg_a0)->other_00[0];
        PLAYER_SLOT(reg_a6)->other_0C[1] = ((PlayerStart *)reg_a0)->other_00[1];
        PLAYER_SLOT(reg_a6)->other_10[0] = ((PlayerStart *)reg_a0)->other_04[0];
        PLAYER_SLOT(reg_a6)->other_10[1] = ((PlayerStart *)reg_a0)->other_04[1];
        PLAYER_SLOT(reg_a6)->task = ((PlayerStart *)reg_a0)->task;
        *(u16 *)&PLAYER_SLOT(reg_a6)->player = ((PlayerStart *)reg_a0)->player;
        PLAYER_SLOT(reg_a6)->lives[0] = ((PlayerStart *)reg_a0)->lives[0];
        PLAYER_SLOT(reg_a6)->lives[1] = ((PlayerStart *)reg_a0)->lives[1];
        PLAYER_SLOT(reg_a6)->ship_task[0] = 0;
        PLAYER_SLOT(reg_a6)->ship_task[1] = 0;
        PLAYER_SLOT(reg_a6)->other_task_1C[0] = 0;
        PLAYER_SLOT(reg_a6)->other_task_1C[1] = 0;
        PLAYER_SLOT(reg_a6)->other_04 = 0;
        PLAYER_SLOT(reg_a6)->other_06 = 0;
        PLAYER_SLOT(reg_a6)->other_task_20[0] = 0;
        PLAYER_SLOT(reg_a6)->other_task_20[1] = 0;
        reg_a0 = (u8 *)&player_starts[1];
        reg_a6 += 0x24;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.h[0] = TASK_SCORE;
    task_start();
    temp_a0 = reg_d0.h[1];
    reg_tmp.h[0] = temp_a0;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[0];
    g_gauge_task_handle = reg_d0.w;
    reg_d0.h[0] = 4;
    task_start();
    temp_a1 = reg_d0.h[1];
    reg_tmp.h[0] = temp_a1;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[0];
    g_player_panel1_task_handle = reg_d0.w;
    *(u8 *)(reg_a0 + 6) = 0;
    reg_d0.h[0] = 4;
    task_start();
    reg_tmp.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[0];
    g_player_panel2_task_handle = reg_d0.w;
    *(u8 *)(reg_a0 + 6) = 1;
}

void player_slot_request(void) {
    reg_a0 = (u8 *)g_player_slots;
    if (reg_d0.h[0] != 0) {
        reg_a0 = (u8 *)g_player_slot2;
    }
    PLAYER_SLOT(reg_a0)->step = reg_d1.h[0];
    PLAYER_SLOT(reg_a0)->other_02 = 0;
}

typedef void (*Fn)();


void player_slots_update(arg0)
    u16 *arg0;
{
    u16 *var_a0;
    u32 temp_s0;

    var_a0 = (u16 *)(arg0);
    reg_a6 = (u8 *)(g_player_slots);
    reg_d7.w = 1;
    do {
        reg_d0.h[0] = PLAYER_SLOT(reg_a6)->step;
        if (reg_d0.h[0] != 0) {
            temp_s0 = reg_d7.w;
            player_slot_steps[reg_d0.h[0]]();
            reg_d7.w = temp_s0;
        }
        var_a0 = (u16 *)(reg_a6 + 0x24);
        reg_a6 = (u8 *)(var_a0);
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

s32 screen_clear_unused();
s32 side_scroll_reset();
s32 hud_p1_lives_put();
s32 hud_p2_lives_put();
extern u16 g_p2_death_count;
extern u16 g_p1_death_count;
extern u16 g_p2_continued;
extern u16 g_p1_continued;
extern u16 g_p2_past_first_ship;
extern u16 g_p1_past_first_ship;
extern u8 g_simulation_active;
extern u16 D_006E5C06[];

void player_slot_next_ship(void) {
    u16 var_a0;

    screen_clear_unused();
    PLAYER_SLOT(reg_a6)->ship_task[0] = 0U;
    PLAYER_SLOT(reg_a6)->ship_task[1] = 0U;
    g_bullets_blocked = 0x78;
    side_scroll_reset();
    reg_tmp.h[1] = PLAYER_SLOT(reg_a6)->lives[0];
    reg_tmp.h[0] = PLAYER_SLOT(reg_a6)->lives[1];
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    *(u16 *)reg_a0 -= 1;
    var_a0 = g_simulation_active;
    if ((var_a0 == 1) && ((s16) *(u16 *)reg_a0 < 0)) {
        var_a0 = D_006E5C06[0];
        if (var_a0 == 0x14) {
            *(u16 *)reg_a0 = 0U;
        }
    }
    if ((s16) *(u16 *)reg_a0 < 0) {
        if (PLAYER_SLOT(reg_a6)->player == 0) {
            g_p1_past_first_ship = 0;
            g_p1_continued = 1;
            g_p1_death_count = 0;
        } else {
            g_p2_past_first_ship = 0;
            g_p2_continued = 1;
            g_p2_death_count = 0;
        }
        PLAYER_SLOT(reg_a6)->step = 2;
    } else {
        if (PLAYER_SLOT(reg_a6)->player == 0) {
            hud_p1_lives_put();
        } else {
            hud_p2_lives_put();
        }
        reg_d0.h[0] = PLAYER_SLOT(reg_a6)->task;
        task_start();
        PLAYER_SLOT(reg_a6)->ship_task[0] = (u16) reg_d0.h[1];
        PLAYER_SLOT(reg_a6)->ship_task[1] = (u16) reg_d0.h[0];
        *(s8 *)(reg_a0 + 7) = 0;
        *(u8 *)(reg_a0 + 6) = (u8) PLAYER_SLOT(reg_a6)->player;
        *(u16 *)(reg_a0 + 8) = (u16) PLAYER_SLOT(reg_a6)->other_0C[0];
        *(u16 *)(reg_a0 + 0xA) = (u16) PLAYER_SLOT(reg_a6)->other_0C[1];
        PLAYER_SLOT(reg_a6)->step = 0;
    }
    PLAYER_SLOT(reg_a6)->other_02 = 0;
}

s32 p1_rank_entry_insert();
s32 p2_rank_entry_insert();
extern u16 g_attract_demo;
extern u8 g_name_entry_player;

void player_slot_out_of_ships(void) {
    u8 temp_a0;

    screen_clear_unused();
    game_players_count();
    if (g_attract_demo == 0) {
        if (PLAYER_SLOT(reg_a6)->player == 0) {
            p1_rank_entry_insert();
            if (cond_flag == 0) {
                g_name_entry_player |= 1;
            }
        } else {
            p2_rank_entry_insert();
            if (cond_flag == 0) {
                g_name_entry_player |= 2;
            }
        }
        reg_d0.h[0] = 0xD;
        task_start();
        PLAYER_SLOT(reg_a6)->other_task_20[0] = (u16) reg_d0.h[1];
        PLAYER_SLOT(reg_a6)->other_task_20[1] = (u16) reg_d0.h[0];
        temp_a0 = PLAYER_SLOT(reg_a6)->player;
        *(u8 *)(reg_a0 + 6) = temp_a0;
        reg_d0.h[0] = 0xB;
        task_start();
        PLAYER_SLOT(reg_a6)->other_task_1C[0] = (u16) reg_d0.h[1];
        PLAYER_SLOT(reg_a6)->other_task_1C[1] = (u16) reg_d0.h[0];
        *(u8 *)(reg_a0 + 6) = (u8) PLAYER_SLOT(reg_a6)->player;
    }
    PLAYER_SLOT(reg_a6)->step = 0;
    PLAYER_SLOT(reg_a6)->other_02 = 0;
}

extern void *D_0028DEB8;
extern u8 *D_0028DEBC;
extern u8 *D_0028DEC0;
extern u8 *D_0028DEC4;
extern u8 *D_0028DEC8;
extern u8 *D_0028DECC;
extern u8 *D_0028DED0;
extern u32 D_0028DED4;
extern u32 D_0028DED8;
extern u32 D_0028DEDC;
extern u32 D_0028DEE0;
extern u32 D_0028DEE4;
extern u32 D_0028DEE8;
extern u32 D_0028DEEC;
extern u32 D_0028DEF0;
extern u16 g_p2_power_style;
extern u16 g_p1_power_style;
extern u16 g_p2_ship_type;
extern u16 g_p1_ship_type;

void player_join(void) {
    D_0028DEF0 = reg_d0.w;
    D_0028DEEC = reg_d1.w;
    D_0028DEE8 = reg_d2.w;
    D_0028DEE4 = reg_d3.w;
    D_0028DEE0 = reg_d4.w;
    D_0028DEDC = reg_d5.w;
    D_0028DED8 = reg_d6.w;
    D_0028DED4 = reg_d7.w;
    D_0028DED0 = reg_a0;
    D_0028DECC = reg_a1;
    D_0028DEC8 = reg_a2;
    D_0028DEC4 = reg_a3;
    D_0028DEC0 = reg_a4;
    D_0028DEBC = reg_a5;
    (*(u8 **)&D_0028DEB8) = (u8 *)(reg_a6);
    if (reg_d2.h[0] != 0) {
        reg_a6 = (u8 *)g_player_slot2;
        g_p2_ship_type = reg_d0.h[0];
        g_p2_power_style = reg_d1.h[0];
        player_slot_join();
        return;
    }
    reg_a6 = (u8 *)g_player_slots;
    g_p1_ship_type = reg_d0.h[0];
    g_p1_power_style = reg_d1.h[0];
    player_slot_join();
}

extern void *D_0028DEB8;

void player_slot_join_step(void) {
    D_0028DEF0 = reg_d0.w;
    D_0028DEEC = reg_d1.w;
    D_0028DEE8 = reg_d2.w;
    D_0028DEE4 = reg_d3.w;
    D_0028DEE0 = reg_d4.w;
    D_0028DEDC = reg_d5.w;
    D_0028DED8 = reg_d6.w;
    D_0028DED4 = reg_d7.w;
#ifdef DDPDOJ_PC
    D_0028DED0 = reg_a0;
    D_0028DECC = reg_a1;
    D_0028DEC8 = reg_a2;
    D_0028DEC4 = reg_a3;
    D_0028DEC0 = reg_a4;
    D_0028DEBC = reg_a5;
    D_0028DEB8 = reg_a6;
#else
    (*(s32 *)&D_0028DED0) = (s32)reg_a0;
    (*(s32 *)&D_0028DECC) = (s32)reg_a1;
    (*(s32 *)&D_0028DEC8) = (s32)reg_a2;
    (*(s32 *)&D_0028DEC4) = (s32)reg_a3;
    (*(s32 *)&D_0028DEC0) = (s32)reg_a4;
    (*(s32 *)&D_0028DEBC) = (s32)reg_a5;
    (*(s32 *)&D_0028DEB8) = (s32)reg_a6;
#endif
    player_slot_join();
}

s32 ship_palettes_load();
s32 player_panel_show_step_8();
s32 hud_p1_hyper_count_put();
s32 hud_p2_hyper_count_put();
s32 p1_extend_score_set();
s32 p2_extend_score_set();
s32 p1_score_cells_reset_short();
s32 p2_score_cells_reset_short();
s32 p1_chain_state_clear();
s32 p2_chain_state_clear();
s32 p1_score_digits_grow();
s32 p2_score_digits_grow();
s32 hud_p1_caption_refresh();
s32 hud_p2_caption_refresh();
extern u16 D_0024F3A8[];
extern void *D_0028DEB8;
extern u8 g_setting_ship_stock;

void player_slot_join(void) {
    u16 temp_a0;

    g_continue_pending_count -= 1;
    reg_tmp.h[1] = PLAYER_SLOT(reg_a6)->lives[0];
    reg_tmp.h[0] = PLAYER_SLOT(reg_a6)->lives[1];
    reg_d0.b[0] = g_setting_ship_stock;
    reg_a1 = (u8 *)(D_0024F3A8);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[0] += reg_d0.h[0];
    temp_a0 = reg_d0.h[0];
    reg_a1 += temp_a0;
    *(u16 *)reg_a0 = (u16) *(u16 *)reg_a1;
    reg_d0.h[0] = PLAYER_SLOT(reg_a6)->task;
    task_start();
    PLAYER_SLOT(reg_a6)->ship_task[0] = (u16) reg_d0.h[1];
    PLAYER_SLOT(reg_a6)->ship_task[1] = (u16) reg_d0.h[0];
    *(s8 *)(reg_a0 + 7) = 0;
    *(u8 *)(reg_a0 + 6) = (u8) PLAYER_SLOT(reg_a6)->player;
    *(u16 *)(reg_a0 + 8) = (u16) PLAYER_SLOT(reg_a6)->other_10[0];
    *(u16 *)(reg_a0 + 0xA) = (u16) PLAYER_SLOT(reg_a6)->other_10[1];
    reg_d0.w = 0;
    reg_d0.b[0] = PLAYER_SLOT(reg_a6)->player;
    if (reg_d0.h[0] == 0) {
        reg_d1.h[0] = g_p1_ship_type;
        ship_palettes_load();
        p1_score_digits_grow();
        p1_score_cells_reset_short();
        p1_extend_score_set();
        hud_p1_caption_refresh();
        p1_chain_state_clear();
        hud_p1_hyper_count_put();
        hud_p1_lives_put();
    } else {
        reg_d1.h[0] = g_p2_ship_type;
        ship_palettes_load();
        p2_score_digits_grow();
        p2_score_cells_reset_short();
        p2_extend_score_set();
        hud_p2_caption_refresh();
        p2_chain_state_clear();
        hud_p2_hyper_count_put();
        hud_p2_lives_put();
    }
    PLAYER_SLOT(reg_a6)->step = 0;
    PLAYER_SLOT(reg_a6)->other_02 = 0;
    reg_d0.b[0] = PLAYER_SLOT(reg_a6)->player;
    player_panel_show_step_8();
    game_players_count();
    screen_clear_unused();
    reg_d0.w = D_0028DEF0;
    reg_d1.w = D_0028DEEC;
    reg_d2.w = D_0028DEE8;
    reg_d3.w = D_0028DEE4;
    reg_d4.w = D_0028DEE0;
    reg_d5.w = D_0028DEDC;
    reg_d6.w = D_0028DED8;
    reg_d7.w = D_0028DED4;
#ifdef DDPDOJ_PC
    reg_a0 = D_0028DED0;
    reg_a1 = D_0028DECC;
    reg_a2 = D_0028DEC8;
    reg_a3 = D_0028DEC4;
    reg_a4 = D_0028DEC0;
    reg_a5 = D_0028DEBC;
    reg_a6 = D_0028DEB8;
#else
    reg_a0 = (u8 *)(*(u32 *)&D_0028DED0);
    reg_a1 = (u8 *)(*(s32 *)&D_0028DECC);
    reg_a2 = (u8 *)(*(s32 *)&D_0028DEC8);
    reg_a3 = (u8 *)(*(s32 *)&D_0028DEC4);
    reg_a4 = (u8 *)(*(s32 *)&D_0028DEC0);
    reg_a5 = (u8 *)(*(s32 *)&D_0028DEBC);
    reg_a6 = (u8 *)D_0028DEB8;
#endif
}

extern u16 g_loop;

void player_slot_start(void) {
    u16 temp_a0;
    reg_tmp.h[1] = PLAYER_SLOT(reg_a6)->lives[0];
    temp_a0 = PLAYER_SLOT(reg_a6)->lives[1];
    reg_d0.b[0] = g_setting_ship_stock;
    reg_a1 = (u8 *)(D_0024F3A8);
    reg_tmp.h[0] = temp_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[0] += reg_d0.h[0];
    *(u16 *)reg_a0 = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    if (g_loop != 0) {
        *(u16 *)reg_a0 = 0U;
    }
    if (g_simulation_active == 1) {
        if (D_006E5C06[0] == 0x14) {
            *(u16 *)reg_a0 = 0U;
        } else {
            *(u16 *)reg_a0 = (u16) D_006E5C06[0];
        }
    }
    reg_d0.h[0] = PLAYER_SLOT(reg_a6)->task;
    task_start();
    PLAYER_SLOT(reg_a6)->ship_task[0] = (u16) reg_d0.h[1];
    PLAYER_SLOT(reg_a6)->ship_task[1] = (u16) reg_d0.h[0];
    *(u8 *)(reg_a0 + 7) = (u8) g_loop;
    *(u8 *)(reg_a0 + 6) = (u8) PLAYER_SLOT(reg_a6)->player;
    *(u16 *)(reg_a0 + 8) = (u16) PLAYER_SLOT(reg_a6)->other_10[0];
    *(u16 *)(reg_a0 + 0xA) = (u16) PLAYER_SLOT(reg_a6)->other_10[1];
    reg_d0.w = 0;
    reg_d0.b[0] = PLAYER_SLOT(reg_a6)->player;
    if (reg_d0.h[0] == 0) {
        reg_d1.h[0] = g_p1_ship_type;
        ship_palettes_load();
        if (g_loop == 0) {
            p1_extend_score_set();
        }
    } else {
        reg_d1.h[0] = g_p2_ship_type;
        ship_palettes_load();
        if (g_loop == 0) {
            p2_extend_score_set();
        }
    }
    reg_d0.b[0] = PLAYER_SLOT(reg_a6)->player;
    player_panel_show_step_8();
    PLAYER_SLOT(reg_a6)->step = 0;
    PLAYER_SLOT(reg_a6)->other_02 = 0;
    game_players_count();
}

s32 sound_stop_effects();
s32 music_stop();
extern s32 g_misc_task_handle;

void player_slot_game_over(void) {
    reg_a2 = g_player_slots;
    reg_a3 = g_player_slot2;
    reg_a0 = (u8 *)PLAYER_SLOT(reg_a2)->other_task_1C;
    task_request_stop();
    reg_a0 = (u8 *)PLAYER_SLOT(reg_a3)->other_task_1C;
    task_request_stop();
    reg_a0 = (u8 *)PLAYER_SLOT(reg_a2)->other_task_20;
    task_request_stop();
    reg_a0 = (u8 *)PLAYER_SLOT(reg_a3)->other_task_20;
    task_request_stop();
    reg_a0 = &(*(u8 *)&g_misc_task_handle);
    task_request_stop();
    reg_a0 = &(*(u8 *)&g_ground_task_handle);
    task_request_stop();
    reg_a0 = &(*(u8 *)&g_gauge_task_handle);
    task_request_stop();
    reg_a0 = &(*(u8 *)&g_player_panel1_task_handle);
    task_request_stop();
    reg_a0 = &(*(u8 *)&g_player_panel2_task_handle);
    task_request_stop();
    music_stop();
    sound_stop_effects();
    reg_d0.h[0] = TASK_GAME_OVER;
    task_start();
    PLAYER_SLOT(reg_a6)->step = 0;
    PLAYER_SLOT(reg_a6)->other_02 = 0;
}

typedef struct {
    u8 pad0[3];
    u8 unk3;
} FlagByte3;



void player_slot_set_game_step(void) {
    ((FlagByte3 *)reg_a5)->unk3 = 2;
    PLAYER_SLOT(reg_a6)->step = 0;
    PLAYER_SLOT(reg_a6)->other_02 = 0;
}


void player_slot_continue_wait(void) {
    g_continue_pending_count += 1;
    reg_d0.h[1] = PLAYER_SLOT(reg_a6)->other_task_20[0];
    reg_d0.h[0] = PLAYER_SLOT(reg_a6)->other_task_20[1];
    task_find();
    *(s8 *)(reg_a0 + 3) = 3;
    PLAYER_SLOT(reg_a6)->step = 0;
    PLAYER_SLOT(reg_a6)->other_02 = 0;
}

void player_slot_clear_task_flags(void) {
    reg_a2 = (u8 *)g_player_slots;
    reg_a3 = (u8 *)g_player_slot2;
    reg_d0.h[1] = PLAYER_SLOT(reg_a2)->other_task_20[0];
    reg_d0.h[0] = PLAYER_SLOT(reg_a2)->other_task_20[1];
    task_find();
    *(s8 *)(reg_a0 + 4) = 0;
    reg_d0.h[1] = PLAYER_SLOT(reg_a3)->other_task_20[0];
    reg_d0.h[0] = PLAYER_SLOT(reg_a3)->other_task_20[1];
    task_find();
    *(s8 *)(reg_a0 + 4) = 0;
    PLAYER_SLOT(reg_a6)->step = 0;
    PLAYER_SLOT(reg_a6)->other_02 = 0;
}

s32 p1_bomb_panel_draw();                            /* extern */
s32 p2_bomb_panel_draw();                            /* extern */

void player_slot_draw_bombs(void) {
    if (PLAYER_SLOT(reg_a6)->player == 0) {
        p1_bomb_panel_draw();
    } else {
        p2_bomb_panel_draw();
    }
    PLAYER_SLOT(reg_a6)->step = 0;
    PLAYER_SLOT(reg_a6)->other_02 = 0;
}


void game_init(void) {
    game_state_clear();
}

extern s32 g_player_panel2_task_handle;
extern s32 g_player_panel1_task_handle;
extern s32 g_gauge_task_handle;
extern s32 g_misc_task_handle;
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
extern u16 g_stopped_and_blocked;
extern u16 g_bullets_blocked;
extern u16 g_enemies_stopped;
extern u16 g_scroll_line_step;
extern u16 g_scroll_line;
extern u8 g_name_entry_player_pad;
extern u16 g_damage_blink_counter;
extern s32 g_play_time;
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
extern u16 g_two_player_seen;
void game_state_clear(void) {
    s32 var_a1;
    u8 *temp_a2;

    var_a1 = 0;
    g_two_player_game = g_two_player_state = g_two_player_seen = g_stage = g_stage_x2 = g_stage_x4 = g_loop = g_game_completed = g_true_last_boss = g_rank = g_rank_15_16 = g_rank_14_16 = g_rank_13_16 = g_rank_12_16 = g_rank_11_16 = g_rank_10_16 = g_rank_9_16 = g_rank_8_16 = g_rank_7_16 = g_rank_6_16 = g_rank_5_16 = g_rank_4_16 = g_rank_3_16 = g_rank_2_16 = g_rank_1_16 = g_p1_lives = g_p2_lives = g_play_time = g_damage_blink_counter = (g_name_entry_player = g_name_entry_player_pad = (g_scroll_line = g_scroll_line_step = g_enemies_stopped = g_bullets_blocked = g_stopped_and_blocked = 0));
    (*(u16 *)&g_boss_present) = 0;
    g_enemy_signal_f = 0;
    g_enemy_signal_e = 0;
    g_enemy_signal_d = 0;
    g_enemy_signal_c = 0;
    g_enemy_signal_b = 0;
    g_enemy_signal_a = 0;
    g_enemy_signal_9 = 0;
    g_enemy_signal_8 = 0;
    g_enemy_signal_7 = 0;
    g_enemy_signal_6 = 0;
    g_enemy_signal_5 = 0;
    g_enemy_signal_4 = 0;
    g_enemy_signal_3 = 0;
    g_enemy_signal_2 = 0;
    g_enemy_signal_1 = 0;
    g_enemy_signal_0 = 0;
    do {
        temp_a2 = (u8 *)(g_player_slots + var_a1);
        (*(s8 *)((u8 *)(temp_a2) + (0))) = 0;
        var_a1 += 8;
        (*(s8 *)((u8 *)(temp_a2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (7))) = 0;
    } while (var_a1 < 0x48);
    g_continue_pending_count = 0;
    g_player_panel2_task_handle = 0;
    g_player_panel1_task_handle = 0;
    g_gauge_task_handle = 0;
    g_misc_task_handle = 0;
    g_ground_task_handle = 0;
    g_p1_lives = 0xFFFF;
    g_p2_lives = 0xFFFF;
}

s32 p1_score_cells_reset();
s32 p2_score_cells_reset();
s32 score_panel_intro_begin();

void game_ships_start(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    reg_a2 = (u8 *)g_player_slots;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    reg_a3 = (u8 *)g_player_slot2;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    if ((s32) save_d0 >= 0) {
        PLAYER_SLOT(reg_a2)->other_10[0] = (u16) reg_d0.h[1];
        PLAYER_SLOT(reg_a2)->other_10[1] = (u16) reg_d0.h[0];
    }
    if ((s32) reg_d1.w >= 0) {
        PLAYER_SLOT(reg_a3)->other_10[0] = (u16) reg_d1.h[1];
        PLAYER_SLOT(reg_a3)->other_10[1] = (u16) reg_d1.h[0];
    }
    reg_d0.h[0] = g_p1_ship_type;
    if (reg_d0.h[0] != 0xFF) {
        reg_d0.w = 0;
        reg_d1.h[0] = 4;
        player_slot_request();
        if (g_loop == 0) {
            p1_score_cells_reset();
        }
    } else {
        reg_d0.h[0] = 0xB;
        task_start();
        PLAYER_SLOT(reg_a2)->other_task_1C[0] = (u16) reg_d0.h[1];
        PLAYER_SLOT(reg_a2)->other_task_1C[1] = (u16) reg_d0.h[0];
        *(s8 *)(reg_a0 + 6) = 0;
    }
    reg_d0.h[0] = g_p2_ship_type;
    if (reg_d0.h[0] != 0xFF) {
        reg_d0.w = 1;
        reg_d1.h[0] = 4;
        player_slot_request();
        if (g_loop == 0) {
            p2_score_cells_reset();
        }
    } else {
        reg_d0.h[0] = 0xB;
        task_start();
        PLAYER_SLOT(reg_a3)->other_task_1C[0] = (u16) reg_d0.h[1];
        PLAYER_SLOT(reg_a3)->other_task_1C[1] = (u16) reg_d0.h[0];
        *(s8 *)(reg_a0 + 6) = 1;
    }
    score_panel_intro_begin();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

void game_ships_stop(void) {
    reg_a2 = g_player_slots;
    reg_a3 = g_player_slot2;
    reg_a0 = (u8 *)PLAYER_SLOT(reg_a2)->ship_task;
    task_request_stop();
    reg_a0 = (u8 *)PLAYER_SLOT(reg_a3)->ship_task;
    task_request_stop();
    reg_a0 = (u8 *)PLAYER_SLOT(reg_a2)->other_task_1C;
    task_request_stop();
    reg_a0 = (u8 *)PLAYER_SLOT(reg_a3)->other_task_1C;
    task_request_stop();
    reg_a0 = (u8 *)PLAYER_SLOT(reg_a2)->other_task_20;
    task_request_stop();
    reg_a0 = (u8 *)PLAYER_SLOT(reg_a3)->other_task_20;
    task_request_stop();
}

extern u16 g_player_start_request;

void game_tasks_stop(void) {
    reg_a0 = (u8 *)(&g_misc_task_handle);
    task_request_stop();
    reg_a0 = (u8 *)(&g_ground_task_handle);
    task_request_stop();
    if (g_player_start_request != 0) {
        game_ships_stop();
    }
}

s32 difficulty_apply();
s32 text_palette_load();
s32 stage_palettes_load();
extern u8 g_default_text_palette[];
extern u16 g_game_flow_scroll_line;

void game_tasks_start() {
    u16 temp_a0;
    u16 temp_a1;
    u32 temp_a0_2;

    reg_d0.h[0] = 5;
    task_start();
    temp_a0 = reg_d0.h[1];
    reg_tmp.h[0] = temp_a0;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[0];
    g_misc_task_handle = reg_d0.w;
    reg_d0.h[0] = 1;
    task_start();
    temp_a1 = reg_d0.h[1];
    reg_tmp.h[0] = temp_a1;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[0];
    temp_a0_2 = reg_d0.w;
    g_ground_task_handle = temp_a0_2;
    *(u16 *)(reg_a0 + 6) = (u16) g_game_flow_scroll_line;
    if (g_player_start_request != 0) {
        reg_d0.w = 0x10000E00;
        reg_d1.w = 0x10002A00;
        game_ships_start();
        g_player_start_request = 0;
    }
    reg_d0.w = 0;
    reg_a0 = g_default_text_palette;
    text_palette_load();
    stage_palettes_load();
    difficulty_apply();
}

extern u16 g_player_shots_disabled;

void game_restart(void) {
    g_player_shots_disabled = 0;
    g_game_flow_scroll_line = reg_d7.h[0];
    g_player_start_request = reg_d6.h[0];
    game_tasks_stop();
    game_stage_signals_clear();
    game_tasks_start();
    player_slots_update();
}

s32 pickups_clear();
s32 stage_clear_state_clear();
s32 continue_panels_clear();
s32 players_clear();
s32 stage_clear_color_orders_shuffle();
s32 score_cells_init();
s32 scores_reset();
extern u8 text_palette_0[];
extern u8 text_palette_1[];
extern u8 text_palette_2[];
extern u8 text_palette_3[];
extern u8 text_palette_4[];
extern u16 text_palette_5[];
extern u16 text_palette_6[];
extern u16 text_palette_7[];
extern u16 text_palette_8[];
extern u16 text_palette_11[];
extern u16 g_game_flow_paused;

void game_task_begin(void) {
    *(s8 *)(reg_a5 + 3) = 1;
    reg_a0 = (u8 *)text_palette_0;
    reg_d0.w = 0;
    text_palette_load();
    reg_a0 = (u8 *)text_palette_1;
    reg_d0.w = 1;
    text_palette_load();
    reg_a0 = (u8 *)text_palette_2;
    reg_d0.w = 2;
    text_palette_load();
    reg_a0 = (u8 *)text_palette_3;
    reg_d0.w = 3;
    text_palette_load();
    reg_a0 = (u8 *)text_palette_4;
    reg_d0.w = 4;
    text_palette_load();
    reg_a0 = (u8 *)text_palette_5;
    reg_d0.w = 5;
    text_palette_load();
    reg_a0 = (u8 *)text_palette_6;
    reg_d0.w = 6;
    text_palette_load();
    reg_a0 = (u8 *)text_palette_7;
    reg_d0.w = 7;
    text_palette_load();
    reg_a0 = (u8 *)text_palette_8;
    reg_d0.w = 8;
    text_palette_load();
    reg_a0 = (u8 *)text_palette_11;
    reg_d0.w = 0xB;
    text_palette_load();
    g_game_flow_paused = 1;
    g_player_start_request = 0;
    if (g_loop == 0) {
        game_state_clear();
    } else {
        g_continue_pending_count = 0;
        g_p1_lives = 0xFFFF;
        g_p2_lives = 0xFFFF;
        g_ground_task_handle = 0;
        g_misc_task_handle = 0;
        g_gauge_task_handle = 0;
        g_player_panel1_task_handle = 0;
        g_player_panel2_task_handle = 0;
    }
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    game_stage_set();
    stage_clear_state_clear();
    stage_clear_color_orders_shuffle();
    if (g_loop == 0) {
        pickups_clear();
        scores_reset();
        score_cells_init();
        players_clear();
    }
    player_slots_init();
    continue_panels_clear();
}

s32 join_select_choices_init();
extern s32 D_0028E998;
extern s32 D_0028E99C;
extern u8 g_replay_mode;

void ship_select_apply(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    s32 var_v0;
    u32 temp_a2;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    if (g_game_flow_paused != 0) {
        temp_a2 = reg_d0.h[0];
        D_0028E99C = -1;
        D_0028E998 = -1;
        g_p1_ship_type = temp_a2;
        g_game_flow_paused = 0;
        g_p1_power_style = reg_d1.h[0];
        g_p2_ship_type = reg_d2.h[0];
        g_p2_power_style = reg_d3.h[0];
        g_player_start_request = reg_d4.h[0];
        reg_d0.h[0] = g_p1_ship_type;
        reg_d1.h[0] = g_p2_ship_type;
        reg_d2.h[0] = g_p1_power_style;
        reg_d3.h[0] = g_p2_power_style;
        join_select_choices_init();
        var_v0 = g_simulation_active == 1;
        reg_d7.w = 0;
        if (var_v0 == 0) {
            var_v0 = g_replay_mode == 2;
        }
        if (((var_v0 != 0) || (g_attract_demo != 0)) && (g_stage == 0)) {
            reg_d7.h[0] = 0x38;
        }
        reg_d6.h[0] = g_player_start_request;
        game_restart();
    }
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

s32 continue_panels_update();
s32 rank_update();
extern u8 g_stage_load_state;
extern u16 g_game_frame;
extern u8 g_replay_save_prompt_active;
extern s16 g_bullet_limit_raised_1[];

void game_task(void) {
    u8 t;

    t = *(u8 *)(reg_a5 + 3);
    if (t == 0) {
        game_task_begin();
        return;
    }
    if (t == 2) goto block_end1;
    player_slots_update();
    if (g_game_flow_paused == 0) {
        if (g_enemies_stopped == 0) {
            if (g_bullets_blocked != 0) {
                g_bullets_blocked -= 1;
            }
        }
        reg_d0.w = 0xE;
        reg_d0.h[0] &= g_game_frame;
        g_damage_blink_counter = reg_d0.h[0];
        if ((g_enemies_stopped == 0) && (g_stage_load_state == 0) && (g_replay_save_prompt_active == 0)) {
            g_play_time += 1;
        }
        rank_update();
        continue_panels_update();
        if (g_loop != 0) {
            g_bullet_limit_raised_1[0] = 1;
        }
    }
    return;
block_end1:
    game_state_clear();
    task_stop_self();
}

extern u8 g_enemy_anims[];


void enemy_anims_clear(void) {
    memset(&((s32 *)g_enemy_anims)[0], 0, 0x180);
}


void enemy_anims_spawn_listed(void) {
loop_1:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x44);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x46);
    reg_a1 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    if (0 > (s16) reg_d0.h[0]) {
        enemy_anims_spawn_done();
        return;
    }
    if ((s16) reg_d0.h[0] < (s32) ENTITY(reg_a6)->hp.h) {
        enemy_anims_spawn_done();
        return;
    }
    enemy_anim_spawn();
    goto loop_1;
}

void enemy_anims_spawn_listed_long(void) {
    u32 temp_s0;

loop_1:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x44);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x46);
    reg_a1 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d1.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    if (0 > (s32) reg_d1.w) {
        enemy_anims_spawn_done();
        return;
    }
    temp_s0 = reg_d0.w;
    if ((s32) reg_d1.w < (s32) temp_s0) {
        enemy_anims_spawn_done();
        return;
    }
    enemy_anim_spawn();
    reg_d0.w = temp_s0;
    goto loop_1;
}


void enemy_anims_spawn_done(void) {
    (*(u8 *)&cond_flag) = 0;
}

extern u16 g_enemy_anim_count[];

void enemy_anim_spawn(void) {
    reg_a0 = (u8 *)((u16 *)g_enemy_anims);
    reg_d0.w = 9;
loop_0:
    if (*(u16 *)reg_a0 == 0) goto next_0;
    reg_a0 += 0x26;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_0;
    reg_a1 += 0xC;
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a1);
    *(u16 *)(reg_a5 + 0x44) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = reg_tmp.h[0];
    cond_flag = 1;
    reg_d0.w = 0;
    reg_d0.h[0] -= 1;
    return;
next_0:
    reg_d1.h[1] = *(u16 *)(reg_a5 + 6);
    reg_d1.h[0] = *(u16 *)(reg_a5 + 8);
    reg_d2.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d2.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d3.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d3.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a2 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a1);
    *(u16 *)(reg_a5 + 0x44) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = reg_tmp.h[0];
    g_enemy_anim_count[0] += 1;
    enemy_anim_init();
}

s32 rng_next_bit();
extern u16 enemy_anim_definitions[];
extern u8 g_enemy_anim_count_as_u8_a[];

void enemy_anim_init(void) {
    u8 *save;

    save = reg_a0;
    reg_d0.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
#ifdef DDPDOJ_PC
    reg_a3 = pc_enemy_animation_definition(reg_d0.h[0]);
#else
    reg_a3 = (u8 *)enemy_anim_definitions;
    reg_a3 = *(u8 **)(reg_a3 + reg_d0.h[0]);
#endif
    reg_d0.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    if (0 <= (s64)*(s16 *)reg_a2) goto next_0;
    reg_d0.w |= 0x80;
next_0:
    *(u16 *)reg_a0 = reg_d0.h[0];
    reg_a0 += 2;
    reg_a1 = ARCADE_ADDRESS_DECODE(u8 *, reg_d1.w);
    *(u16 *)reg_a0 = *(u16 *)(reg_a1 + 2);
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)(reg_a1 + 4);
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    reg_a0 += 4;
    *(u16 *)reg_a0 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d1.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d2.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d2.h[0];
    reg_a0 += 2;
    if (0 <= (s64)(s8)reg_d3.b[0]) goto next_2;
    reg_d3.b[0] = ~reg_d3.b[0];
    if (!(reg_d3.w & 0x20)) goto next_1;
    rng_next_bit();
    if (reg_d0.b[0] != 0) goto next_1;
    reg_d3.b[0] ^= 0x20;
next_1:
    if (!(reg_d3.h[0] & 0x40)) goto next_2;
    rng_next_bit();
    if (reg_d0.b[0] != 0) goto next_2;
    reg_d3.b[0] ^= 0x40;
next_2:
    *(u16 *)reg_a0 = reg_d3.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    reg_a0[-1] = reg_d3.b[0];
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a2);
    *(u16 *)reg_a0 = reg_tmp.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[0];
    reg_a0 += 2;
    reg_d3.h[1] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d3.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d3.h[0] -= *(u16 *)(g_enemy_anim_count_as_u8_a + 2);
    *(u16 *)reg_a0 = reg_d3.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    *(u16 *)(g_enemy_anim_count_as_u8_a + 2) -= 4;
    if (0 <= (s64)*(s16 *)(g_enemy_anim_count_as_u8_a + 2)) goto next_3;
    *(u16 *)(g_enemy_anim_count_as_u8_a + 2) = 0xC;
next_3:
    reg_a0 = save;
    cond_flag = 0;
}

extern u8 enemy_anims_update_value[];
extern u8 D_0024F3F0[];
extern u8 D_0024F410[];
extern u8 D_0024F430[];
extern u8 D_0024F460[];
extern u8 D_0024F480[];
extern u8 D_0024F4A0[];
extern u16 g_frame_mod2;
extern u8 g_boss_present_b1;
extern u8 g_enemy_anims[];

void enemy_anims_update(void) {
    u32 count;
    u8 bits;

    reg_d0.h[0] = 0x95;
    reg_d1.w = 0;
    reg_a0 = (u8 *)g_enemy_entities;
loop_10:
    bits = *(u8 *)(reg_a0 + 1);
    if (bits == 0) goto next_20;
    if (0 > (s8)bits) goto next_20;
    *(u16 *)reg_a0 = reg_d1.h[0];
next_20:
    reg_a0 += 0x20;
    count = reg_d0.h[0] - 1;
    reg_d0.h[0] = count;
    if (((s64)((s64)(u16)count << 0x30) >> 0x30) >= 0) goto loop_10;
    reg_d7.h[0] = g_enemy_anim_count[0];
    if (reg_d7.h[0] == 0) return;
    reg_d7.h[0] -= 1;
    reg_a6 = (u8 *)g_enemy_anims;
    goto loop_40;
loop_30:
    reg_a6 += 0x26;
loop_40:
    reg_d2.h[0] = ENTITY(reg_a6)->flags.h;
    if (reg_d2.h[0] == 0) goto loop_30;
    if (reg_d2.w & 0x200) goto next_50;
    reg_tmp.h[1] = ENTITY(reg_a6)->hit_y_plus.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->hit_y_minus.h;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d1.h[0] = *(u16 *)reg_a0;
    if (!(0 > (s16)reg_d1.h[0])) goto block_clr;
    if (0 > (s8)reg_d1.b[0]) goto block_clr;
    if (0 > (s8)g_boss_present_b1) goto block_clr;
next_50:
    if (g_frame_mod2 == 0) goto next_90;
    if (0 > (s8)reg_d2.b[0]) goto next_60;
    *(u16 *)(reg_a6 + 0x22) -= 1;
    if (*(u16 *)(reg_a6 + 0x22) != 0) goto next_60;
    enemy_anim_restart();
    reg_d2.h[0] = ENTITY(reg_a6)->flags.h;
next_60:
    reg_d0.w = 0x7C;
    reg_d0.h[0] &= reg_d2.h[0];
    switch (reg_d0.h[0]) {
    case 0x00: goto block_a0;
    case 0x04: goto block_a1;
    case 0x08: goto block_a2;
    case 0x0C: goto block_a3;
    case 0x10: goto block_a4;
    case 0x14: goto block_a5;
    case 0x18: goto block_objset;
    case 0x1C: goto block_objset;
    case 0x20: goto block_objset;
    case 0x24: goto block_objset;
    case 0x28: goto block_a0;
    case 0x2C: goto block_a1;
    case 0x30: goto block_a2;
    case 0x34: goto block_a3;
    case 0x38: goto block_a4;
    case 0x3C: goto block_a5;
    case 0x40: goto block_objset;
    case 0x44: goto block_objset;
    case 0x48: goto block_objset;
    case 0x4C: goto block_objset;
    }
next_90:
    reg_a6 += 0x26;
    count = reg_d7.h[0] - 1;
    reg_d7.h[0] = count;
    if (((s64)((s64)(count & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_40;
    return;
block_clr:
    ENTITY(reg_a6)->flags.h = 0;
    g_enemy_anim_count[0] -= 1;
    reg_a6 += 0x26;
    count = reg_d7.h[0] - 1;
    reg_d7.h[0] = count;
    if (((s64)((s64)(count & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_40;
    return;
block_a0:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_a0 = (u8 *)D_0024F3F0;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (!(0 > *(s16 *)(reg_a6 + 0x24))) goto block_objset;
    *(u16 *)(reg_a6 + 0x24) = 0xC;
    goto block_objset;
block_a1:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_a0 = (u8 *)D_0024F410;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (!(0 > *(s16 *)(reg_a6 + 0x24))) goto block_objset;
    *(u16 *)(reg_a6 + 0x24) = 0xC;
    goto block_objset;
block_a2:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_a0 = (u8 *)D_0024F430;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (!(0 > *(s16 *)(reg_a6 + 0x24))) goto block_objset;
    *(u16 *)(reg_a6 + 0x24) = 0x1C;
    goto block_objset;
block_a3:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_a0 = (u8 *)D_0024F460;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (!(0 > *(s16 *)(reg_a6 + 0x24))) goto block_objset;
    *(u16 *)(reg_a6 + 0x24) = 0xC;
    goto block_objset;
block_a4:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_a0 = (u8 *)D_0024F480;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (!(0 > *(s16 *)(reg_a6 + 0x24))) goto block_objset;
    *(u16 *)(reg_a6 + 0x24) = 0xC;
    goto block_objset;
block_a5:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_a0 = (u8 *)D_0024F4A0;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (!(0 > *(s16 *)(reg_a6 + 0x24))) goto block_objset;
    *(u16 *)(reg_a6 + 0x24) = 0x1C;
block_objset:
    reg_tmp.h[1] = ENTITY(reg_a6)->hit_y_plus.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->hit_y_minus.h;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[1] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a0 + 4);
    reg_tmp.h[1] = ENTITY(reg_a6)->hit_x_plus.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->hit_x_minus.h;
    reg_d0.w += reg_tmp.w;
    ENTITY(reg_a6)->y.h = reg_d0.h[1];
    ENTITY(reg_a6)->x.h = reg_d0.h[0];
    reg_d0.h[0] = ENTITY(reg_a6)->hp.h;
    if (!(ENTITY(reg_a6)->flags.b[1] & 1)) goto next_obj10;
    reg_d0.b[0] = *(u8 *)(reg_a0 + 0x1F);
    reg_d0.h[0] <<= 2;
next_obj10:
#ifdef DDPDOJ_PC
    reg_call_target = pc_enemy_animation_draw(reg_d0.h[0]);
    reg_a0 = (u8 *)reg_call_target;
#else
    reg_a0 = (u8 *)enemy_anims_update_value;
    reg_a0 += reg_d0.h[0];
    reg_a0 = *(u8 **)reg_a0;
    reg_call_target = (Fn)(reg_a0);
#endif
    reg_call_target();
    reg_a6 += 0x26;
    count = reg_d7.h[0] - 1;
    reg_d7.h[0] = count;
    if (((s64)((s64)(count & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_40;
}


void enemy_anim_restart(void) {
    u32 temp_s0;

    reg_d1.h[1] = ENTITY(reg_a6)->hit_y_plus.h;
    reg_d1.h[0] = ENTITY(reg_a6)->hit_y_minus.h;
    reg_d2.h[1] = ENTITY(reg_a6)->hit_x_plus.h;
    reg_d2.h[0] = ENTITY(reg_a6)->hit_x_minus.h;
    reg_d3.h[1] = ENTITY(reg_a6)->hp.h;
    reg_d3.h[0] = ENTITY(reg_a6)->move.h;
    reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a2 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    if (ENTITY(reg_a6)->flags.b[1] & 2) {
        temp_s0 = reg_d1.w;
        reg_a0 = reg_a6;
        enemy_anim_init();
        reg_a1 = ARCADE_ADDRESS_DECODE(u8 *, temp_s0);
        *(u8 *)(reg_a0 + 1) |= 2;
        *(u16 *)(reg_a0 + 2) = (u16) (*(u16 *)(reg_a1 + 2));
        *(u16 *)(reg_a0 + 4) = (u16) (*(u16 *)(reg_a1 + 4));
        reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a1);
        *(u16 *)(reg_a0 + 0x10) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a0 + 0x12) = (u16) reg_tmp.h[0];
        return;
    }
    reg_a0 = reg_a6;
    enemy_anim_init();
}

/* .sbss (the compiler lays these out in reverse) */
u32 D_0028DEF0;
u32 D_0028DEEC;
u32 D_0028DEE8;
u32 D_0028DEE4;
u32 D_0028DEE0;
u32 D_0028DEDC;
u32 D_0028DED8;
u32 D_0028DED4;
u8 *D_0028DED0;
u8 *D_0028DECC;
u8 *D_0028DEC8;
u8 *D_0028DEC4;
u8 *D_0028DEC0;
u8 *D_0028DEBC;
void *D_0028DEB8;

/* .bss (the compiler lays these out in reverse) */
u8 g_enemy_anims[384];

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

PC_DATA_ALIAS(g_enemy_anim_count, g_enemy_anims, 0x17c);
PC_DATA_ALIAS(g_enemy_anim_count_as_u8_a, g_enemy_anims, 0x17c);
#endif
