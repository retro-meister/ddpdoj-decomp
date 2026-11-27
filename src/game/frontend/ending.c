#include "common.h"
#include "enemy.h"
#include "ending_data.h"
#include "player.h"
#include "task.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

#ifdef DDPDOJ_PC
#include "pc_frontend_abi.h"
#endif

void ending_text_script_event(void);
void ending_task_reset(void);

void p1_hyper_state_clear_for_ending(void);
void p2_hyper_state_clear_for_ending(void);
void hyper_ready_displays_reset(void);
void p1_hyper_end(void);
void p2_hyper_end(void);
extern u8 D_0028C608[];
extern u16 g_p2_loop2_extend_ok;
extern u16 g_p1_loop2_extend_ok;
extern u16 g_p2_bombs_used;
extern u16 g_p1_bombs_used;
extern u16 g_p2_death_count;
extern u16 g_p1_death_count;
extern u8 g_game_mode;
extern u8 g_setting_loop_count;
extern u16 g_boss_hyper_wait;
extern u16 g_p2_hyper_active;
extern u16 g_p1_hyper_active;
extern u16 g_p2_score_digits;
extern u16 g_p1_score_digits;
extern u16 g_p1_lives;
extern u16 g_loop;
extern u16 g_two_player_seen;
extern u16 g_bee_value_step;
extern s16 g_player2[];
extern s16 g_player1[];

void ending_second_loop_check(void) {
    if (g_setting_loop_count != 0) goto block_1;
    if (g_game_mode == 1) goto block_1;
#ifdef DEATH_LABEL
    if (g_game_mode == 2) goto block_1;
#endif
    if (g_loop != 0) goto block_1;
    if (g_p1_hyper_active != 0) {
        p1_hyper_end();
        p1_hyper_state_clear_for_ending();
    }
    if (g_p2_hyper_active != 0) {
        p2_hyper_end();
        p2_hyper_state_clear_for_ending();
    }
    hyper_ready_displays_reset();
    g_boss_hyper_wait = 0;
    if (g_two_player_seen == 3) goto block_1;
    reg_a0 = &(*(u8 *)&g_p1_loop2_extend_ok);
    reg_d0.h[0] = g_bee_value_step;
    reg_a1 = (u8 *)((u8 *)g_player1);
    reg_d1.h[0] = g_p1_bombs_used;
    reg_d2.h[0] = g_p1_score_digits;
    reg_d3.h[0] = g_p1_death_count;
    if (0 > (s16)g_p1_lives) {
        reg_a0 = &(*(u8 *)&g_p2_loop2_extend_ok);
        reg_d1.h[0] = g_p2_bombs_used;
        reg_a1 = (u8 *)((u8 *)g_player2);
        reg_d2.h[0] = g_p2_score_digits;
        reg_d3.h[0] = g_p2_death_count;
    }
    if (reg_d2.h[0] != 0) goto block_1;
    if (reg_d3.h[0] == 0 || reg_d1.h[0] == 0) {
        *(s16 *)(reg_a0 + 0) = 1;
    }
    if ((s32)reg_d0.h[0] < 0xC && (s32)reg_d3.h[0] > 2 && (s32)reg_d1.h[0] > 3) {
    block_1:
        cond_flag = 0;
        return;
    }
    reg_d0.h[0] = *(u16 *)(reg_a1 + 0x5A);
    reg_a0 = (u8 *)D_0028C608;
    reg_d0.h[0] -= 2;
    reg_a0 += reg_d0.h[0];
    *(u8 *)(reg_a1 + 0x25) = *(u8 *)(reg_a0 + 1);
    *(u8 *)(reg_a1 + 0x24) = *(u8 *)(reg_a0 + 0);
    cond_flag = 1;
    reg_a0 += 2;
}

s32 stage_load_step();
s32 disc_notice_begin();
s32 disc_notice_end();
extern u8 g_stage_load_state;
extern s16 g_loaded_stage;
extern u16 g_stage;
extern s8 g_cd_async_state;
extern s8 g_cd_async_busy;
extern u16 D_00295E38[];
extern u16 D_00295E3C[];

void ending_finish(void) {
    u16 temp_a0;

    temp_a0 = D_00295E3C[0];
    if (temp_a0 != 0) {
        if (temp_a0 == 1) {
            switch (D_00295E38[0]) { case 0: break; default:
                D_00295E3C[0] = 0;
                ending_task_reset();
                return;
            }
            g_cd_async_busy = 1;
            D_00295E3C[0] = 2;
            g_stage_load_state = 0;
            g_cd_async_state = 0;
            disc_notice_begin(temp_a0);
            goto block_6;
        }
block_6:
        if (D_00295E3C[0] == 2) {
            g_stage = 0;
            stage_load_step(D_00295E3C[0]);
            if (g_loaded_stage == g_stage) {
                g_loop = 1;
                D_00295E3C[0] = 0;
                disc_notice_end(g_loaded_stage);
                reg_d0.h[0] = 0x11;
                task_start();
                task_stop_self();
            }
        }
    } else {
        ENTITY(reg_a6)->hit_y_minus.h += 1;
        reg_d0.h[0] = ENTITY(reg_a6)->hit_y_minus.h;
        if (ENTITY(reg_a6)->hit_y_plus.h != reg_d0.h[0]) {
            ending_task_reset();
            return;
        }
        reg_d0.h[0] = TASK_CREDITS;
        task_start();
        task_stop_self();
    }
}

extern u16 g_picture_change_state[];
extern u16 D_00295E30[];
extern u16 D_00295E32[];
extern u32 D_00295E34[];

void picture_change_reset(void) {
    ((s16 *)g_picture_change_state)[0] = 0;
    ((s16 *)D_00295E30)[0] = 0;
    ((s16 *)D_00295E32)[0] = 0;
    ((s32 *)D_00295E34)[0] = 0;
}

#ifndef DEATH_LABEL
extern u16 g_picture_change_state[];
extern u16 D_00295E30[];
extern u16 D_00295E32[];

void picture_change_request(void) {
    if (g_picture_change_state[0] == 0) {
        g_picture_change_state[0] = 1;
        D_00295E30[0] = reg_d0.h[0];
        D_00295E32[0] = reg_d1.h[0];
    }
}
#endif

#ifndef DEATH_LABEL
s32 fade_in();
extern u16 *picture_change_update_table[];
extern u16 D_00295E2C[];
extern u32 D_00295E34[];

void picture_change_update(void) {
#ifndef DDPDOJ_PC
    s32 fade_to_black();
    s32 fade_release();
    s32 fade_is_running();
#endif
    if (g_picture_change_state[0] == 0) goto block_rts;
    if (g_picture_change_state[0] != 1) goto next_1;
    if (D_00295E2C[0] == 0) goto next_2;
    reg_a0 = (u8 *)picture_change_update_table;
    reg_d0.h[0] = D_00295E32[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += ENDING_POINTER_OFFSET(reg_d0.h[0]);
    reg_a0 = *(u8 **)reg_a0;
    fade_to_black();
    D_00295E34[0] = reg_d0.w;
    g_picture_change_state[0] = 2;
next_1:
    if (g_picture_change_state[0] != 2) goto next_3;
    reg_d0.w = D_00295E34[0];
    fade_is_running();
    if (cond_flag != 0) goto next_3;
    fade_release();
next_2:
    D_00295E2C[0] = D_00295E30[0];
    g_picture_change_state[0] = 3;
    if (D_00295E2C[0] != 0) goto next_3;
    g_picture_change_state[0] = 0;
next_3:
    if (g_picture_change_state[0] != 3) goto next_4;
    reg_a0 = (u8 *)ending_picture_fades.groups;
    reg_d0.h[0] = D_00295E32[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += ENDING_POINTER_OFFSET(reg_d0.h[0]);
    reg_a0 = *(u8 **)reg_a0;
    fade_in();
    D_00295E34[0] = reg_d0.w;
    g_picture_change_state[0] = 4;
next_4:
    if (g_picture_change_state[0] != 4) goto block_rts;
    reg_d0.w = D_00295E34[0];
    fade_is_running();
    if (cond_flag != 0) goto block_rts;
    fade_release();
    g_picture_change_state[0] = 0;
block_rts:
    return;
}
#endif

extern Reg32 reg_d0;
extern u8 D_00295E00[];

void ending_mode_set(void) {
    reg_a6 = (u8 *)D_00295E00;
    *(u16 *)(reg_a6 + 8) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 6) = 0;
}

#ifndef DDPDOJ_PC
s32 sprite_palette_load();
#endif
extern u8 ending_fade_in_table_at_4[];
extern u16 D_00295E1C[];
extern u8 D_00295E1E[];
extern u16 D_00295E20[];
extern u32 D_00295E24[];
extern u32 D_00295E28[];

void ending_text_lines_clear(void) {
    reg_a3 = (u8 *)g_spare_entities;
    reg_d7.h[0] = 0xC7;
    do {
        *(s16 *)reg_a3 = 0;
        *(s16 *)(reg_a3 + 2) = 0;
        *(s16 *)(reg_a3 + 4) = 0;
        *(s16 *)(reg_a3 + 6) = 0;
        reg_a3 += 8;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    ((s16 *)D_00295E1C)[0] = 0;
    reg_a0 = ending_fade_in_table_at_4;
    ((s16 *)D_00295E1E)[0] = 0;
    reg_d0.h[0] = 0;
    ((s16 *)D_00295E20)[0] = 0;
    ((s32 *)D_00295E24)[0] = 0;
    ((s32 *)D_00295E28)[0] = 0;
    sprite_palette_load();
}

#ifndef DEATH_LABEL
#ifndef DDPDOJ_PC
s32 sprite_draw_keep();
#endif

void ending_text_lines_draw(void) {
    reg_a3 = (u8 *)g_spare_entities;
    reg_d7.h[0] = 0xC7;
    do {
        reg_d2.h[1] = *(u16 *)reg_a3;
        reg_d2.h[0] = *(u16 *)(reg_a3 + 2);
        if (reg_d2.w != 0) {
            reg_d1.h[1] = *(u16 *)(reg_a3 + 4);
            reg_d1.h[0] = *(u16 *)(reg_a3 + 6);
            reg_d3.h[0] = 0x410;
            reg_d4.h[0] = 0;
            sprite_draw_keep();
        }
        reg_a3 += 8;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
#endif

#ifndef DEATH_LABEL
void ending_text_lines_place(void) {
    u32 tmp;

    reg_a3 = (u8 *)g_spare_entities;
    reg_d7.h[0] = 0xC7;
loop_1:
    reg_tmp.h[1] = *(u16 *) (reg_a3 + 0);
    reg_tmp.h[0] = *(u16 *) (reg_a3 + 2);
    if (reg_tmp.w != 0) goto next_1;
    *(u16 *) (reg_a3 + 0) = reg_d0.h[1];
    *(u16 *) (reg_a3 + 2) = reg_d0.h[0];
    *(u16 *) (reg_a3 + 4) = reg_d1.h[1];
    *(u16 *) (reg_a3 + 6) = reg_d1.h[0];
    goto block_rts;
next_1:
    reg_a3 += 8;
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
block_rts:
    return;
}
#endif

#ifndef DEATH_LABEL
extern u32 ending_text_script_step_table[];
extern u16 D_00295E1C[];
extern u8 D_00295E1E[];
extern u8 D_00295E1F[];
extern u32 D_00295E28[];

void ending_text_script_step(void) {
    reg_a2 = reg_a0;
    reg_a2 += D_00295E1C[0];
    reg_d0.h[0] = *(u16 *) reg_a2;
    reg_a2 += 2;
    if (0 > (s16) reg_d0.h[0]) {
        ending_text_script_event();
        return;
    }
    D_00295E1F[0] -= 1;
    if (0 > (s8) D_00295E1F[0]) goto next_1;
    cond_flag = 1;
    return;
next_1:
    D_00295E1F[0] = D_00295E1E[0];
    reg_a1 = (u8 *) ending_text_script_step_table;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 += reg_d0.h[0];
    reg_d0.w = *(u32 *) reg_a1;
    reg_d1.w = D_00295E28[0];
    ending_text_lines_place();
    cond_flag = 1;
    ((u16 *) D_00295E28)[0] += 0x400;
    D_00295E1C[0] += 2;
}
#endif

#ifndef DEATH_LABEL
extern u16 D_00295E20[];
extern u32 D_00295E24[];

void ending_text_script_event(void) {
#ifndef DDPDOJ_PC
    void fade_to_black(void);
    void fade_release(void);
    void fade_is_running(void);
#endif
    if (reg_d0.h[0] == 0x8000) {
        ((u16 *)D_00295E1E)[0] = *(u16 *)reg_a2;
        reg_a2 += 2;
        D_00295E1C[0] += 4;
        ending_text_script_step();
    } else if (reg_d0.h[0] == 0x8001) {
        reg_tmp.h[1] = *(u16 *)reg_a2;
        reg_a2 += 2;
        reg_tmp.h[0] = *(u16 *)reg_a2;
        reg_a2 += 2;
        D_00295E1C[0] += 6;
        D_00295E28[0] = reg_tmp.w;
        ending_text_script_step();
    } else if (reg_d0.h[0] == 0x8002) {
        reg_d1.h[0] = D_00295E20[0];
        if (*(u16 *)reg_a2 == reg_d1.h[0]) {
            D_00295E20[0] = 0;
            D_00295E1C[0] += 4;
            ending_text_script_step();
            return;
        }
        D_00295E20[0] += 1;
        cond_flag = 1;
    } else if (reg_d0.h[0] == 0x8003) {
        reg_d0.w = D_00295E24[0];
        if (reg_d0.w == 0) {
            reg_d0.h[0] = *(u16 *)reg_a2;
            reg_a0 = (u8 *)ending_common.fades;
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += reg_d0.h[0];
            reg_a0 += ENDING_POINTER_OFFSET(reg_d0.h[0]);
            reg_a0 = *(u8 **)reg_a0;
            fade_to_black();
            D_00295E24[0] = reg_d0.w;
            cond_flag = 1;
            return;
        }
        fade_is_running();
        if (cond_flag != 0) {
            cond_flag = 1;
            return;
        }
        fade_release();
        D_00295E24[0] = 0;
        D_00295E1C[0] += 4;
        ending_text_script_step();
    } else if (reg_d0.h[0] == 0x8005) {
        reg_d0.h[0] = *(u16 *)reg_a2;
        reg_d1.h[0] = *(u16 *)(reg_a2 + 2);
        picture_change_request();
        D_00295E1C[0] += 6;
        ending_text_script_step();
    } else {
        cond_flag = 0;
    }
}
#endif

s32 layers_clear_all();
s32 sound_stop_effects();
s32 sound_stop_loops();
#ifndef DDPDOJ_PC
s32 music_stop();
#endif
extern s16 g_ending_started;
extern u8 D_00295E3E[];
extern u16 D_00295E40[];
extern s16 g_player2[];
extern s16 g_player1[];

void ending_task_begin(void) {
    *(s8 *)(reg_a5 + 3) = 1;
    g_ending_started = 1;
    reg_a0 = (u8 *)D_00295E00;
    memset(D_00295E00, 0, 0x44);
    reg_a6 = (u8 *)D_00295E00;
    reg_d0.w = 0;
    if (0 > g_player1[0]) {
        reg_d0.h[0] += 1;
    }
    if (0 > g_player2[0]) {
        reg_d0.h[0] += 1;
    }
    ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_d0.h[0];
    ((s16 *)D_00295E3E)[0] = 0x101;
    ((s16 *)D_00295E40)[0] = 0;
    layers_clear_all();
    music_stop();
    sound_stop_effects();
    sound_stop_loops();
    ending_task_reset();
    ending_second_loop_check();
    if (cond_flag != 0) {
        reg_d0.w = 4;
        ending_mode_set();
    }
}

extern u16 g_p2_power_style;
extern u16 g_p1_power_style;
extern u16 D_00295E2C[];

void ending_task_reset(void) {
    *(s8 *)(reg_a5 + 3) = 1;
    ending_text_lines_clear();
    picture_change_reset();
    reg_d0.w = 0;
    ending_mode_set();
    ((s16 *)D_00295E2C)[0] = 0;
    reg_a6 = (u8 *)D_00295E00;
    if (ENTITY(reg_a6)->hit_y_plus.h != 1) goto next_0;
    reg_d0.h[0] = g_p1_power_style;
    if (0 > PLAYER(((u8 *)g_player1))->flags.sb[1]) goto next_1;
    reg_d0.h[0] = g_p2_power_style;
    goto next_1;
next_0:
    reg_d0.h[0] = g_p1_power_style;
    if (ENTITY(reg_a6)->hit_y_minus.h == 0) goto next_1;
    reg_d0.h[0] = g_p2_power_style;
next_1:
    if (reg_d0.h[0] == 2) {
        ENTITY(reg_a6)->look.h = 0U;
    }
    if (reg_d0.h[0] == 4) {
        ENTITY(reg_a6)->look.h = 1U;
    }
    if (reg_d0.h[0] == 6) {
        ENTITY(reg_a6)->look.h = 2U;
    }
    if (ENTITY(reg_a6)->hit_y_minus.h != 0) {
        reg_d0.w = 0;
        reg_d0.h[0] = ENTITY(reg_a6)->look.h;
        reg_d0.h[0] += 1;
        ending_mode_set();
    }
}

typedef void (*Fn)();

#ifndef DDPDOJ_PC
s32 sprite_draw_keep();
#endif
#ifdef DEATH_LABEL
void intro_text_update(void);
#endif
extern u32 ending_task_table[];
extern void (*ending_task_table_2[])(void);
extern u8 g_replay_file_finalized;
extern u8 g_stage_jump_state;
extern u16 D_00295E2C[];
extern u8 D_00295E3E[];
extern u8 D_00295E3F[];
extern u16 D_00295E40[];

void ending_task(void) {
    u8 mode;

    mode = *(u8 *)(reg_a5 + 3);
    if (mode == 0) {
        g_replay_file_finalized = 0;
        g_stage_jump_state = 0xFF;
        ending_task_begin();
        return;
    }
    if (mode == 2) {
        ending_finish();
        return;
    }
    reg_a6 = (u8 *)D_00295E00;
#ifdef DEATH_LABEL
    intro_text_update();
#else
    reg_d0.h[0] = ENTITY(reg_a6)->offset_x.h;
    ending_task_table_2[reg_d0.h[0]]();
    ending_text_lines_draw();
    picture_change_update();
    reg_d0.h[0] = D_00295E2C[0];
    if (reg_d0.h[0] != 0) {
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 = (u8 *)(ending_task_table);
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        reg_d2.w = *(u32 *)reg_a0;
        reg_d1.w = 0x38000000;
        reg_d3.h[0] = 0x1CE0;
        reg_d4.h[0] = 1;
        reg_d4.h[0] += D_00295E40[0];
        sprite_draw_keep();
        D_00295E3F[0] -= 1;
        if (0 > (s8) D_00295E3F[0]) {
            D_00295E3F[0] = D_00295E3E[0];
            D_00295E40[0] += 1;
            D_00295E40[0] &= 1;
        }
    }
#endif
}

#ifndef DEATH_LABEL
s32 text_layer_clear();
s32 music_play_bgm11();


void ending_mode_common(void) {
    u16 temp_a0;
    u8 *temp_a2;

    text_layer_clear();
    if (ENTITY(reg_a6)->offset_y.h == 0) {
        ENTITY(reg_a6)->offset_y.h = 1U;
        ending_text_lines_clear();
        ENTITY(reg_a6)->sprite.h = 0U;
        music_play_bgm11();
    }
    if (ENTITY(reg_a6)->offset_y.h == 1) {
        reg_a0 = (u8 *)ending_common.dolls;
        reg_d0.h[0] = ENTITY(reg_a6)->look.h;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += ENDING_POINTER_OFFSET(reg_d0.h[0]);
        reg_a0 = *(u8 **)reg_a0;
        temp_a0 = ENTITY(reg_a6)->sprite.h;
        reg_a0 += ENDING_POINTER_OFFSET(temp_a0);
        reg_d0.w = ENDING_PAGE_WORD(reg_a0);
        temp_a2 = (u8 *)(reg_a6 + 0xE);
        if (reg_d0.w == -1U) {
            reg_d0.h[0] = ENTITY(reg_a6)->look.h;
            reg_d0.h[0] += 1;
            ending_mode_set();
            return;
        }
        reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_d0.w);
        ending_text_script_step();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->sprite.h += 4;
            ending_text_lines_clear();
        }
    }
}
#endif

#ifndef DEATH_LABEL
s32 sfx_confirm();
s32 sfx_cursor_move();
s32 sprite_draw_layer5_keep();
extern u32 ending_mode_doll_a_table[];
extern u32 ending_mode_doll_a_table_2[];
extern u16 settings_notice_fade_palettes_at_18[32];
extern u32 ending_mode_doll_a_table_3;
extern u8 *ending_mode_doll_a_table_4[2];
extern u16 D_00295E3A[];
void input_get_p1_pressed();
void input_get_p2_pressed();
#ifndef DDPDOJ_PC
extern u32 reg_call_target_as_u32;
#endif

#define W(o) (*(u16 *)(reg_a6 + (o)))

void ending_mode_doll_a(void) {
#ifndef DDPDOJ_PC
    s32 fade_to_black();
    s32 fade_release();
    s32 fade_is_running();
#endif
    if (W(6) != 0) goto next_10;
    W(6) = 1;
    ending_text_lines_clear();
    W(0xC) = 0;
    ((s16 *)D_00295E3C)[0] = 1;
    D_00295E38[0] = 1;
    D_00295E3A[0] = 0x258;
    reg_a0 = (u8 *) ((u32 *)settings_notice_fade_palettes_at_18);
    reg_d0.h[0] = 3;
    sprite_palette_load();
next_10:
    if (W(6) != 1) goto next_20;
    reg_a0 = (u8 *) &ending_mode_doll_a_table_4;
    reg_a0 += ENDING_POINTER_OFFSET(W(0xC));
    reg_d0.w = ENDING_PAGE_WORD(reg_a0);
    if (reg_d0.w != -1U) goto next_15;
    W(6) = 2;
    reg_tmp.w = ARCADE_ADDRESS_ENCODE((void *) input_get_p1_pressed);
    W(0x18) = reg_tmp.h[1];
    W(0x1A) = reg_tmp.h[0];
    if (0 > g_player1[0]) goto next_20;
    reg_tmp.w = ARCADE_ADDRESS_ENCODE((void *) input_get_p2_pressed);
    W(0x18) = reg_tmp.h[1];
    W(0x1A) = reg_tmp.h[0];
    goto next_20;
next_15:
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_d0.w);
    ending_text_script_step();
    if (cond_flag != 0) goto next_20;
    W(0xC) += 4;
next_20:
    if (W(6) != 2) goto next_40;
    reg_tmp.h[1] = W(0x18);
    reg_tmp.h[0] = W(0x1A);
#ifdef DDPDOJ_PC
    ARCADE_ADDRESS_DECODE(Fn, reg_tmp.w)();
#else
    reg_call_target_as_u32 = reg_tmp.w;
    ((Fn) reg_call_target_as_u32)();
#endif
    if (!(reg_d0.h[0] & 4)) goto next_25;
    D_00295E38[0] += 1;
    sfx_cursor_move();
next_25:
    reg_tmp.h[1] = W(0x18);
    reg_tmp.h[0] = W(0x1A);
#ifdef DDPDOJ_PC
    ARCADE_ADDRESS_DECODE(Fn, reg_tmp.w)();
#else
    reg_call_target_as_u32 = reg_tmp.w;
    ((Fn) reg_call_target_as_u32)();
#endif
    if (!(reg_d0.h[0] & 8)) goto next_28;
    D_00295E38[0] += 1;
    sfx_cursor_move();
next_28:
    D_00295E38[0] &= 1;
    reg_tmp.h[1] = W(0x18);
    reg_tmp.h[0] = W(0x1A);
#ifdef DDPDOJ_PC
    ARCADE_ADDRESS_DECODE(Fn, reg_tmp.w)();
#else
    reg_call_target_as_u32 = reg_tmp.w;
    ((Fn) reg_call_target_as_u32)();
#endif
    reg_d0.h[0] &= 0x70;
    if (reg_d0.h[0] == 0) goto next_35;
next_32:
    sfx_confirm();
    reg_a0 = (u8 *) ending_mode_doll_a_table;
    fade_to_black();
    W(0x14) = reg_d0.h[1];
    W(0x16) = reg_d0.h[0];
    W(6) = 3;
    goto next_40;
next_35:
    D_00295E3A[0] -= 1;
    if (D_00295E3A[0] == 0) goto next_32;
next_40:
    if (W(6) != 3) goto next_50;
    reg_d0.h[1] = W(0x14);
    reg_d0.h[0] = W(0x16);
    fade_is_running();
    if (cond_flag != 0) goto next_50;
    fade_release();
    *(s8 *)(reg_a5 + 3) = 2;
next_50:
    if ((s16) W(6) < 2) goto block_rts;
    reg_a0 = (u8 *) &ending_mode_doll_a_table_3;
    reg_d0.h[0] = D_00295E38[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 0xE8;
    reg_d3.h[0] = 0x210;
    reg_d4.h[0] = 3;
    sprite_draw_layer5_keep();
    reg_d1.h[0] += 0x1000;
    reg_d4.h[0] |= 0x40;
    sprite_draw_layer5_keep();
    reg_d0.w = 0;
    reg_d0.h[0] = D_00295E3A[0];
    reg_d0.w /= 0x3C;
    reg_a0 = (u8 *) ending_mode_doll_a_table_2;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.w = 0x5E001C00;
    reg_d3.h[0] = 0x210;
    reg_d4.h[0] = 3;
    sprite_draw_layer5_keep();
block_rts:
    return;
}
#endif

#ifndef DEATH_LABEL
void ending_mode_doll_b(void) {
    u16 temp_a1;

    if (ENTITY(reg_a6)->offset_y.h == 0) {
        ENTITY(reg_a6)->offset_y.h = 1U;
        ending_text_lines_clear();
        ENTITY(reg_a6)->sprite.h = 0U;
    }
    if (ENTITY(reg_a6)->offset_y.h == 1) {
        reg_a0 = (u8 *)ending_doll_b.pages;
        temp_a1 = ENTITY(reg_a6)->sprite.h;
        reg_a0 += ENDING_POINTER_OFFSET(temp_a1);
        reg_d0.w = ENDING_PAGE_WORD(reg_a0);
        if (reg_d0.w == -1U) {
            *(s8 *)(reg_a5 + 3) = 2;
            return;
        }
        reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_d0.w);
        ending_text_script_step();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->sprite.h += 4;
            ending_text_lines_clear();
        }
    }
}
#endif

#ifndef DEATH_LABEL
void ending_mode_doll_c(void) {
    u16 temp_a1;

    if (ENTITY(reg_a6)->offset_y.h == 0) {
        ENTITY(reg_a6)->offset_y.h = 1U;
        ending_text_lines_clear();
        ENTITY(reg_a6)->sprite.h = 0U;
    }
    if (ENTITY(reg_a6)->offset_y.h == 1) {
        reg_a0 = (u8 *)ending_doll_c.pages;
        temp_a1 = ENTITY(reg_a6)->sprite.h;
        reg_a0 += ENDING_POINTER_OFFSET(temp_a1);
        reg_d0.w = ENDING_PAGE_WORD(reg_a0);
        if (reg_d0.w == -1U) {
            *(s8 *)(reg_a5 + 3) = 2;
            return;
        }
        reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_d0.w);
        ending_text_script_step();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->sprite.h += 4;
            ending_text_lines_clear();
        }
    }
}
#endif

#ifndef DEATH_LABEL
extern u8 *ending_mode_second_loop_message_table[];

void ending_mode_second_loop_message(void) {
    u16 temp_a1;

    if (ENTITY(reg_a6)->offset_y.h == 0) {
        ENTITY(reg_a6)->offset_y.h = 1U;
        ending_text_lines_clear();
        ENTITY(reg_a6)->sprite.h = 0U;
    }
    if (ENTITY(reg_a6)->offset_y.h == 1) {
        reg_a0 = (u8 *)(ending_mode_second_loop_message_table);
        temp_a1 = ENTITY(reg_a6)->sprite.h;
        reg_a0 += ENDING_POINTER_OFFSET(temp_a1);
        reg_d0.w = ENDING_PAGE_WORD(reg_a0);
        if (reg_d0.w == -1U) {
            *(s8 *)(reg_a5 + 3) = 2;
            return;
        }
        reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_d0.w);
        ending_text_script_step();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->sprite.h += 4;
            ending_text_lines_clear();
        }
    }
}
#endif

/* .bss (the compiler lays these out in reverse) */
#ifdef DDPDOJ_PC
/* The ending clears through the first two halfwords of its animation counter. */
_Alignas(16) u8 D_00295E00[0x50];
#else
u16 D_00295E40[8];
u8 D_00295E00[64];
#endif

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

PC_DATA_ALIAS(D_00295E1C, D_00295E00, 0x1c);
PC_DATA_ALIAS(D_00295E1E, D_00295E00, 0x1e);
PC_DATA_ALIAS(D_00295E20, D_00295E00, 0x20);
PC_DATA_ALIAS(D_00295E24, D_00295E00, 0x24);
PC_DATA_ALIAS(D_00295E28, D_00295E00, 0x28);
PC_DATA_ALIAS(D_00295E2C, D_00295E00, 0x2c);
PC_DATA_ALIAS(g_picture_change_state, D_00295E00, 0x2e);
PC_DATA_ALIAS(D_00295E30, D_00295E00, 0x30);
PC_DATA_ALIAS(D_00295E32, D_00295E00, 0x32);
PC_DATA_ALIAS(D_00295E34, D_00295E00, 0x34);
PC_DATA_ALIAS(D_00295E38, D_00295E00, 0x38);
PC_DATA_ALIAS(D_00295E3C, D_00295E00, 0x3c);
PC_DATA_ALIAS(D_00295E3E, D_00295E00, 0x3e);
PC_DATA_ALIAS(D_00295E40, D_00295E00, 0x40);

#ifndef DEATH_LABEL
PC_DATA_ALIAS(D_00295E1F, D_00295E00, 0x1f);
PC_DATA_ALIAS(D_00295E3A, D_00295E00, 0x3a);
PC_DATA_ALIAS(D_00295E3F, D_00295E00, 0x3f);
#endif
#endif
