#include "common.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

#ifdef DDPDOJ_PC
#include "pc_frontend_abi.h"
#endif

void join_select_ship_step(void);
void join_select_doll_step(void);
void join_select_prompt_update(void);
void join_select_prompt_clear(void);
void join_select_prompt_draw(void);
void join_select_object_update(void);

extern u16 g_two_player_game;
extern u8 join_select_p2_table_at_8[];
extern u8 join_select_p1_table_at_8[];

void join_select_doll_store(void) {
    reg_a0 = join_select_p1_table_at_8;
    if (*(u8 *)(reg_a5 + 6) == 0) {
        reg_a0 = join_select_p2_table_at_8;
    }
    reg_d0.b[0] = *reg_a0;
    if (g_two_player_game == 0) {
        reg_d0.h[0] = 0xFFFF;
    }
}


void join_select_doll_taken_check(void) {
    s32 d1 = reg_d1.w;

    reg_a0 = (u8 *)join_select_p1_table_at_8;
    if (reg_a5[6] != 0) goto next_1;
    reg_a0 = (u8 *)join_select_p2_table_at_8;
next_1:
    reg_d1.b[0] = *reg_a0;
    if (g_two_player_game != 0) goto next_2;
    reg_d1.h[0] = 0xFFFF;
next_2:
    if ((s8) reg_d1.b[0] == -1) goto next_3;
    if (reg_d7.b[0] != reg_d1.b[0]) goto next_3;
    reg_d1.w = d1;
    cond_flag = 1;
    return;
next_3:
    reg_d1.w = d1;
    cond_flag = 0;
}

s32 p1_bomb_stock_draw_empty();
s32 p2_bomb_stock_draw_empty();
extern u8 join_select_p1_table[];
extern u8 join_select_p2_table[];

void join_select_task_begin() {
#ifndef DDPDOJ_PC
    s32 player_panel_show();
#endif
    *(s8 *)(reg_a5 + 3) = 1;
    reg_a4 = join_select_p1_table;
    if (*(u8 *)(reg_a5 + 6) != 0) {
        reg_a4 = join_select_p2_table;
    }
    reg_tmp.w = (u32) reg_a4;
    *(u16 *)(reg_a5 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0xA) = (u16) reg_tmp.h[0];
    if (*(u8 *)(reg_a5 + 6) == 0) {
        p1_bomb_stock_draw_empty();
    } else {
        p2_bomb_stock_draw_empty();
    }
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    player_panel_show();
    *(s8 *)(reg_a5 + 0xD) = 0;
    *(s16 *)(reg_a5 + 0x12) = 0x4B0;
    *(s16 *)(reg_a5 + 0x14) = 4;
}

s32 player_join();
s32 task_stop_self();
extern u16 D_0028C11C[];
extern u16 D_0028C120[];

void join_select_task_finish(void) {
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 8);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0xA);
    reg_d0.w = 0;
    reg_a4 = (u8 *)reg_tmp.w;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0xF);
    reg_a0 = (u8 *)(D_0028C11C);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d1.w = 0;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0xE);
    reg_a0 = (u8 *)(D_0028C120);
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 0;
    reg_d2.b[0] = *(u8 *)(reg_a5 + 6);
    player_join();
    task_stop_self();
}

typedef void (*Fn)(void);


void screen_clear_unused(void);
void p1_credits_get(void);
void player_slot_request(void);
void player_panel_show_unless_step_4(void);
void player_panel_show_by_coin_mode(void);
void join_select_ship_get(void);
void join_select_doll_next_free(void);
extern u8 D_002623B0[];
extern u8 D_0028E304;
extern u16 D_0028E314;
extern u16 D_0028E318;
extern u16 g_attract_demo;
extern u16 g_loop;
extern u8 g_replay_taken_over;
extern u8 g_replay_mode;
extern u8 g_simulation_active;
extern u8 *reg_call_target_as_u8_p;

void join_select_task(void) {
#ifndef DDPDOJ_PC
    void stage_clear_running_check(void);
    void sprite_palette_load(void);
    void player_panel_show(void);
#endif
    u8 state;
    u8 seq;

    state = *(u8 *)(reg_a5 + 3);
    if (state == 0) {
        join_select_task_begin();
        return;
    }
    if (state == 2) {
        join_select_task_finish();
        return;
    }
    stage_clear_running_check();
    if (cond_flag != 0) {
        goto block_50;
    }
    if (*(u8 *)(reg_a5 + 0xD) != 0) {
        goto block_51;
    }
    if (g_loop != 0) {
        goto block_50;
    }
    if (D_0028E304 != 0) {
        goto block_50;
    }
    if (g_simulation_active == 1) {
        goto block_50;
    }
#ifdef DEATH_LABEL
    if ((g_replay_mode == 2) && (g_replay_taken_over == 0)) {
        goto block_50;
    }
#else
    if ((g_attract_demo == 0) && (g_replay_mode == 2) && (g_replay_taken_over == 0)) {
        goto block_50;
    }
#endif
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    if (reg_d0.b[0] == 0) {
        if (D_0028E318 == 0) {
            goto block_50;
        }
    } else {
        if (D_0028E314 == 0) {
            goto block_50;
        }
    }
    p1_credits_get();
    if (reg_d0.h[0] != 0) {
        goto next_1;
    }
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    player_panel_show_by_coin_mode();
    goto block_51;
next_1:
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    player_panel_show();
    goto block_51;
block_50:
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    player_panel_show_unless_step_4();
    return;
block_51:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 8);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0xA);
    reg_a4 = (u8 *)reg_tmp.w;
    if (*(u8 *)(reg_a5 + 0xD) != 0) {
        goto block_52;
    }
    if (g_loop != 0) {
        goto block_52;
    }
    if (g_attract_demo != 0) {
        goto block_52;
    }
    if (g_simulation_active == 1) {
        goto block_52;
    }
#ifdef DEATH_LABEL
    if ((g_replay_mode == 2) && (g_replay_taken_over == 0)) {
        goto block_50;
    }
#else
    if ((g_attract_demo == 0) && (g_replay_mode == 2) && (g_replay_taken_over == 0)) {
        goto block_50;
    }
#endif
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    if (reg_d0.b[0] == 0) {
        if (D_0028E318 == 0) {
            goto block_52;
        }
    } else {
        if (D_0028E314 == 0) {
            goto block_52;
        }
    }
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 4);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 6);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
    if (!(reg_d0.w & 0x8000)) {
        goto block_52;
    }
    stage_clear_running_check();
    if (cond_flag != 0) {
        goto block_52;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0xC);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xE);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
    if (cond_flag != 0) {
        goto block_52;
    }
    join_select_ship_get();
    join_select_doll_next_free();
    *(u8 *)(reg_a5 + 0xD) = 1;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    player_panel_show();
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
#ifdef DEATH_LABEL
    if (reg_d0.b[0] == 0) {
        if (D_0028E318 != 0) {
            D_0028E318 -= 1;
        }
    } else {
        if (D_0028E314 != 0) {
            D_0028E314 -= 1;
        }
    }
#endif
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x14);
    reg_a0 = (u8 *)D_002623B0;
    sprite_palette_load();
    screen_clear_unused();
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    reg_d1.h[0] = 7;
    player_slot_request();
    join_select_prompt_clear();
block_52:
    seq = *(u8 *)(reg_a5 + 0xD);
    if (seq == 1) {
        reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
        player_panel_show();
        join_select_ship_step();
        if (cond_flag != 0) {
            *(u8 *)(reg_a5 + 0xD) = 2;
            *(s8 *)(reg_a5 + 0xC) = 1;
        }
        return;
    }
    if (seq == 2) {
        reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
        player_panel_show();
        join_select_doll_step();
        return;
    }
    join_select_prompt_update();
}

#ifndef DDPDOJ_PC
typedef void (*Fn)();
#endif


s32 sfx_confirm();
s32 sfx_cursor_move();
s32 sprite_draw_with_ship_select_keep();
extern u16 D_00251B20[];
extern u16 D_00251B30[];
extern u16 join_select_ship_step_table[];
extern u16 g_game_frame;
extern s32 D_0028E998;
extern s32 D_0028E99C;

void join_select_ship_step(void) {
    u32 temp_a1_3;
    u32 temp_v1;
    u32 temp_a1;
    u32 temp_a1_2;

    reg_tmp.h[1] = *(u16 *)(reg_a4 + 8);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xA);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
    if (reg_d0.w & 4) {
        *(u8 *)(reg_a5 + 0xF) -= 1;
        *(s8 *)(reg_a5 + 0xC) = 1;
        sfx_cursor_move();
    }
    if (reg_d0.w & 8) {
        *(u8 *)(reg_a5 + 0xF) += 1;
        *(s8 *)(reg_a5 + 0xC) = 1;
        sfx_cursor_move();
    }
    *(u8 *)(reg_a5 + 0xF) &= 1;
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0x10);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x12);
    reg_a0 = (u8 *)reg_tmp.w;
    *(u8 *)(reg_a0 + 1) = (u8) *(u8 *)(reg_a5 + 0xF);
    *(u16 *)(reg_a5 + 0x12) -= 1;
    if ((*(u8 *)(reg_a5 + 0x13) == 0) || (reg_d0.h[0] &= 0x70, (reg_d0.h[0] != 0))) {
        sfx_confirm();
        *(u16 *)(reg_a5 + 0x12) = 0x4B0U;
        if (reg_a0 == join_select_p1_table_at_8) {
            D_0028E99C = (s32) *(u8 *)(reg_a0 + 1);
        } else {
            D_0028E998 = *(u8 *)(reg_a0 + 1) + 2;
        }
        cond_flag = 1;
        return;
    }
    reg_d1.w = 0x5BC00000;
    if (*(u8 *)(reg_a5 + 6) != 0) {
        reg_d1.w = 0x5BC02C00;
    }
    reg_d2.w = 0x1552;
    reg_d4.w = 0;
    reg_d3.h[0] = 0x630;
    reg_d7.w = reg_d1.w;
    reg_d4.h[0] = *(u16 *)(reg_a4 + 0x14);
    sprite_draw_with_ship_select_keep();
    if (*(u8 *)(reg_a5 + 6) == 0) {
        temp_a1 = reg_d1.w;
        reg_d1.w = temp_a1 + 0x04000100;
        reg_d2.w = 0x1553;
        reg_d3.h[0] = 0x410;
        reg_d4.w = 0;
        reg_d4.h[0] = *(u16 *)(reg_a4 + 0x16);
        sprite_draw_with_ship_select_keep();
        reg_d2.w = 0x1554;
        reg_d4.w = 0;
        reg_d3.h[0] = 0x410;
        reg_d1.w += 0x600;
        reg_d4.h[0] = *(u16 *)(reg_a4 + 0x18);
        sprite_draw_with_ship_select_keep();
    } else {
        temp_a1_2 = reg_d1.w;
        reg_d1.w = temp_a1_2 + 0x04000100;
        reg_d2.w = 0x1555;
        reg_d3.h[0] = 0x410;
        reg_d4.w = 0;
        reg_d4.h[0] = *(u16 *)(reg_a4 + 0x16);
        sprite_draw_with_ship_select_keep();
        reg_d2.w = 0x1556;
        reg_d4.w = 0;
        reg_d3.h[0] = 0x410;
        reg_d1.w += 0x600;
        reg_d4.h[0] = *(u16 *)(reg_a4 + 0x18);
        sprite_draw_with_ship_select_keep();
    }
    reg_d0.w = 0;
    reg_d1.w = reg_d7.w;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0xF);
    reg_a2 = (u8 *)(join_select_ship_step_table);
    reg_d0.h[0] += reg_d0.h[0];
    temp_a1_3 = reg_d0.h[0];
    reg_a2 += temp_a1_3;
    temp_v1 = reg_d1.h[0] + *(u16 *)reg_a2;
    reg_a2 = (u8 *)(D_00251B20);
    reg_d1.h[0] = temp_v1;
    if (*(u8 *)(reg_a5 + 6) != 0) {
        reg_a2 = (u8 *)(D_00251B30);
    }
    reg_d0.h[0] = g_game_frame;
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    reg_d0.h[0] &= 3;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a2;
    reg_d4.w = 0;
    reg_d3.h[0] = 0x618;
    reg_d4.h[0] = *(u16 *)(reg_a4 + 0x14);
    sprite_draw_with_ship_select_keep();
    reg_d0.w = 0;
    cond_flag = 0;
}

extern u16 join_select_doll_step_table[];

void join_select_doll_step(void) {
    u16 var_a0;
    reg_d7.w = 0;
    reg_d7.b[0] = *(u8 *)(reg_a5 + 0xE);
    join_select_doll_taken_check();
    if (cond_flag != 0) {
        reg_d7.b[0] -= 1;
        if (0 > reg_d7.sb[0]) {
            reg_d7.b[0] = 2;
        }
        *(u8 *)(reg_a5 + 0xE) = (u8) reg_d7.b[0];
    }
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 8);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xA);
    reg_a0 = (u8 *)(reg_tmp.w);
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
    reg_d7.w = 0;
    reg_d7.b[0] = *(u8 *)(reg_a5 + 0xE);
    reg_d6.h[0] = reg_d7.h[0];
    if (reg_d0.w & 4) {
        *(s8 *)(reg_a5 + 0xC) = 1;
        do {
            reg_d7.b[0] -= 1;
            if (0 > reg_d7.sb[0]) {
                reg_d7.b[0] = 2;
            }
            join_select_doll_taken_check();
        } while (cond_flag != 0);
    }
    if (reg_d0.w & 8) {
        *(s8 *)(reg_a5 + 0xC) = 1;
        do {
            reg_d7.b[0] += 1;
            if ((s8) reg_d7.b[0] > 2) {
                reg_d7.b[0] = 0;
            }
            join_select_doll_taken_check();
        } while (cond_flag != 0);
    }
    if (reg_d6.b[0] != reg_d7.b[0]) {
        sfx_cursor_move();
    }
    *(u8 *)(reg_a5 + 0xE) = (u8) reg_d7.b[0];
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0x10);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x12);
    reg_a0 = (u8 *)(reg_tmp.w);
    *(u8 *)reg_a0 = *(u8 *)(reg_a5 + 0xE);
    *(u16 *)(reg_a5 + 0x12) -= 1;
    if ((*(u16 *)(reg_a5 + 0x12) == 0) || (reg_d0.h[0] &= 0x70, (reg_d0.h[0] != 0))) {
        sfx_confirm();
        join_select_task_finish();
        return;
    }
    reg_d1.w = 0x5BC00000;
    if (*(u8 *)(reg_a5 + 6) != 0) {
        reg_d1.w = 0x5BC02600;
    }
    reg_d2.w = 0x1551;
    reg_d4.w = 0;
    reg_d3.h[0] = 0x648;
    reg_d7.w = reg_d1.w;
    reg_d4.h[0] = *(u16 *)(reg_a4 + 0x14);
    sprite_draw_with_ship_select_keep();
    reg_d0.w = 0;
    reg_d1.w = reg_d7.w;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0xE);
    reg_a0 = (u8 *)((u32) join_select_doll_step_table);
    reg_d0.h[0] += reg_d0.h[0];
    if (reg_d0.h[0] != 0) {
        var_a0 = *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1));
    } else {
        var_a0 = *(u16 *)reg_a0;
    }
    reg_d1.h[0] += var_a0;
    reg_a2 = (u8 *)(D_00251B20);
    if (*(u8 *)(reg_a5 + 6) != 0) {
        reg_a2 = (u8 *)(D_00251B30);
    }
    reg_d0.h[0] = g_game_frame;
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    reg_d0.h[0] &= 3;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a2;
    reg_d4.w = 0;
    reg_d3.h[0] = 0x618;
    reg_d4.h[0] = *(u16 *)(reg_a4 + 0x14);
    sprite_draw_with_ship_select_keep();
    join_select_doll_store();
    if (0 <= (s16)(reg_d0.h[0])) {
        reg_d0.h[0] += reg_d0.h[0];
        reg_d1.w = reg_d7.w;
        reg_a2 = (u8 *)(join_select_doll_step_table);
        reg_a2 += reg_d0.h[0];
        reg_d1.h[0] += *(u16 *)reg_a2;
        reg_d2.w = 0x1557;
        reg_d3.h[0] = 0x618;
        reg_d4.w = 0;
        reg_d4.h[0] = *(u16 *)(reg_a4 + 0x14);
        sprite_draw_with_ship_select_keep();
    }
}


void join_select_prompt_update(void) {
#ifndef DDPDOJ_PC
    s32 stage_clear_running_check();
#endif
    stage_clear_running_check();
    if (cond_flag == 0) {
        join_select_prompt_draw();
    }
}

extern u8 D_00251B40[];

void join_select_prompt_clear(void) {
#ifndef DDPDOJ_PC
    s32 text_layer_print();
#endif
    reg_a0 = D_00251B40;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] = *(u16 *)reg_a4;
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    text_layer_print();
}

void credits_get(void);
void coins_get(void);
void text_layer_put_hex_digit(void);
void player_panel_step_get(void);
extern u8 join_select_prompt_draw_table[];
extern u8 join_select_prompt_draw_table_2[];
extern u8 join_select_prompt_draw_table_3[];
extern u8 D_00251BC0[];
extern u8 D_00251BE0[];
extern u8 D_00251C00[];
extern u8 g_setting_chute_type;
extern u8 g_setting_coin_mode;

void join_select_prompt_draw(void) {
#ifndef DDPDOJ_PC
    void text_layer_print(void);
#endif
    p1_credits_get();
    if (*(u8 *)(reg_a5 + 6) == 0) {
        goto next_1;
    }
    if (g_setting_chute_type != 1) {
        goto next_1;
    }
    reg_d0.h[0] = reg_d1.h[0];
next_1:
    if (reg_d0.h[0] != 0) {
        goto block_50;
    }
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        goto block_51;
    }
    if (reg_d0.b[0] == 0x11) {
        goto block_52;
    }
    if ((s8) reg_d0.b[0] >= 9) {
        goto block_52;
    }
    goto block_53;
block_50:
    reg_a0 = (u8 *)join_select_prompt_draw_table;
    goto block_54;
block_51:
    reg_a0 = (u8 *)join_select_prompt_draw_table_2;
    goto block_54;
block_53:
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    player_panel_step_get();
    if (reg_d0.h[0] == 0xC) {
        return;
    }
    reg_a0 = (u8 *)join_select_prompt_draw_table_3;
    goto block_54;
block_52:
    if (*(u8 *)(reg_a5 + 6) == 0) {
        goto next_2;
    }
    coins_get();
    goto next_3;
next_2:
    credits_get();
next_3:
    if (reg_d0.h[0] != 1) {
        goto next_4;
    }
    if (reg_d1.h[0] != 0) {
        goto block_50;
    }
    goto block_53;
next_4:
    if (reg_d1.h[0] != 0) {
        goto next_5;
    }
    reg_d4.h[0] = reg_d0.h[0];
    reg_a0 = (u8 *)D_00251BC0;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0);
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    text_layer_print();
    reg_d0.h[0] = 1;
    reg_d0.h[0] += *(u16 *)(reg_a4 + 2);
    text_layer_put_hex_digit();
    return;
next_5:
    reg_d0.h[0] -= reg_d1.h[0];
    if (!(0 < (s16) reg_d0.h[0])) {
        goto block_50;
    }
    if ((reg_d0.h[0] & 0xFFFF) == 1) {
        goto next_6;
    }
    reg_d4.h[0] = reg_d0.h[0];
    reg_a0 = (u8 *)D_00251BE0;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0);
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    text_layer_print();
    reg_d0.h[0] = 1;
    reg_d0.h[0] += *(u16 *)(reg_a4 + 2);
    text_layer_put_hex_digit();
    return;
next_6:
    reg_a0 = (u8 *)D_00251C00;
block_54:
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0);
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    text_layer_print();
}

extern u16 join_select_object_defaults_set_table[];

void join_select_object_defaults_set(void) {
    reg_a0 = (u8 *)join_select_object_defaults_set_table;
    *(u16 *)(reg_a1 + 2) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a1 + 0x10) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a1 + 0x14) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a1 + 0x16) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a1 + 0x18) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a1 + 0x1A) = (u16) reg_d0.h[0];
}

s32 sprite_draw_layer5();                            /* extern */
s32 sprite_draw_layer5_zoom_keep();                            /* extern */

void sprite_draw_layer5_blinking(void) {
    if (g_game_frame & 2) {
        sprite_draw_layer5();
        return;
    }
    sprite_draw_layer5_zoom_keep();
}

extern u8 D_0029BEE0[];


void join_select_objects_clear(void) {
    memset(((s32 *)D_0029BEE0), 0, 0x48);
}

extern u16 D_00251CC0[];
extern u8 D_0029BEE0[];
extern u8 D_0029BEE1[];
extern s16 D_0029BEE4[];
extern s16 D_0029BEE6[];
extern s16 D_0029BEEE[];
extern u16 D_0029BEFC[];
extern u16 D_0029BEFE[];
extern u16 join_select_object_spawn_buffer[];
extern u16 D_0029BF02[];
extern u8 D_0029BF04[];
extern u8 D_0029BF05[];
extern s16 D_0029BF08[];
extern s16 D_0029BF0A[];
extern s16 D_0029BF12[];
extern u16 join_select_object_spawn_buffer_2[];
extern u16 D_0029BF22[];
extern u16 D_0029BF24[];
extern u16 D_0029BF26[];

void join_select_object_spawn(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

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
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 5);
    if (0 <= (s8) reg_d0.b[0]) {
        reg_a0 = (u8 *)(D_00251CC0);
        reg_d0.h[0] -= 2;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        join_select_object_spawn_buffer[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        D_0029BF02[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        D_0029BEFC[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        D_0029BEFE[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        D_0029BEE1[0] |= 1;
        D_0029BEEE[0] = 0x17;
        D_0029BEE4[0] = 0x5E00;
        D_0029BEE6[0] = 0x1C00;
        reg_a1 = (u8 *)D_0029BEE0;
        join_select_object_defaults_set();
    }
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 4);
    if (0 <= (s8) reg_d0.b[0]) {
        reg_a0 = (u8 *)(D_00251CC0);
        reg_d0.h[0] -= 2;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        D_0029BF24[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        D_0029BF26[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        join_select_object_spawn_buffer_2[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        D_0029BF22[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        D_0029BF05[0] |= 1;
        D_0029BF12[0] = 0x18;
        D_0029BF08[0] = 0x1200;
        D_0029BF0A[0] = 0x1C00;
        reg_a1 = (u8 *)D_0029BF04;
        join_select_object_defaults_set();
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
    reg_a6 = save_a6;
    reg_a5 = save_a5;
}


void join_select_objects_update(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

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
    if ((reg_d7.h[0] != 0) && (D_0029BEE1[0] & 1) && !(D_0029BEE1[0] & 4)) {
        reg_a6 = (u8 *)D_0029BEE0;
        join_select_object_update();
    } else if ((D_0029BF05[0] & 1) && !(D_0029BF05[0] & 4)) {
        reg_a6 = (u8 *)D_0029BF04;
        join_select_object_update();
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

s32 sprite_draw_layer5();
s32 sprite_draw_layer5_zoom_keep();
extern u8 join_select_object_update_table[];
extern u8 join_select_object_update_table_2[];
extern u8 join_select_object_update_table_3[];
extern u8 join_select_object_update_table_4[];
extern u16 g_frame_mod8;
extern u16 g_frame_mod2;

void join_select_object_update(void) {
#ifndef DDPDOJ_PC
    s32 sprite_palette_load();
#endif
    u8 flag;

    if (ENTITY(reg_a6)->y.h != 0) {
        ENTITY(reg_a6)->y.h -= 1;
        return;
    }
    flag = ENTITY(reg_a6)->flags.b[1];
    if (!(flag & 2)) {
        ENTITY(reg_a6)->flags.b[1] = flag | 2;
        reg_a0 = (u8 *)join_select_object_update_table_4;
        reg_d0.w = 0x16;
        sprite_palette_load();
        reg_tmp.h[1] = (*(u16 *)(reg_a6 + (0x1C)));
        reg_tmp.h[0] = (*(u16 *)(reg_a6 + (0x1E)));
        reg_a0 = (u8 *) reg_tmp.w;
        reg_d0.h[0] = (*(u16 *)(reg_a6 + (0xE)));
        sprite_palette_load();
    }
    reg_d1.h[1] = (*(u16 *)(reg_a6 + (4)));
    reg_d1.h[0] = (*(u16 *)(reg_a6 + (6)));
    reg_d1.w += 0xF400E400;
    reg_d0.h[0] = (*(u16 *)(reg_a6 + (0xA)));
    reg_a0 = (u8 *)join_select_object_update_table;
    reg_a0 += reg_d0.h[0];
    reg_d2.h[1] = (*(u16 *)(reg_a0 + (0)));
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = 0xCE0;
    reg_d4.h[0] = 0x16;
    sprite_draw_layer5();
    if (ENTITY(reg_a6)->sprite.h != 0) {
        ENTITY(reg_a6)->sprite.h -= 1;
        reg_tmp.h[1] = (*(u16 *)(reg_a6 + (0x20)));
        reg_tmp.h[0] = (*(u16 *)(reg_a6 + (0x22)));
        reg_a0 = (u8 *) reg_tmp.w;
        reg_d0.h[0] = (*(u16 *)(reg_a6 + (0x12)));
        reg_a0 += reg_d0.h[0];
        reg_d2.h[1] = (*(u16 *)(reg_a0 + (0)));
        reg_a0 += 2;
        reg_d2.h[0] = (*(u16 *)(reg_a0 + (0)));
        reg_a0 += 2;
        reg_d1.h[1] = (*(u16 *)(reg_a6 + (4)));
        reg_d1.h[0] = (*(u16 *)(reg_a6 + (6)));
        reg_d1.w += 0xF600F800;
        reg_d3.h[0] = 0xA40;
        reg_d1.h[0] += 0x7FFF + 0x6E01;
        reg_d4.h[0] = (*(u16 *)(reg_a6 + (0xE)));
        reg_d6.w = 0x80008000;
        sprite_draw_layer5_zoom_keep();
        if (g_frame_mod8 != 0) {
            reg_a1 = (u8 *)join_select_object_update_table_3;
            reg_d0.h[0] = 0x1E;
            reg_d6.w = 0x80005000;
            reg_d0.h[0] &= g_game_frame;
            reg_d0.h[0] += reg_d0.h[0];
            reg_a1 += reg_d0.h[0];
        }
        sprite_draw_layer5_zoom_keep();
        reg_d2.h[1] = (*(u16 *)(reg_a0 + (0)));
        reg_a0 += 2;
        reg_d2.h[0] = (*(u16 *)(reg_a0 + (0)));
        reg_a0 += 2;
        if (ENTITY(reg_a6)->hit_x_plus.h == 0x280) goto skip_1;
        ENTITY(reg_a6)->hit_x_plus.h += 8;
        goto skip_4;
skip_1:
        if (ENTITY(reg_a6)->hit_x_minus.h == 0x280) goto skip_2;
        ENTITY(reg_a6)->hit_x_minus.h += 8;
        goto skip_4;
skip_2:
        if (ENTITY(reg_a6)->hp.h == 0x280) goto skip_3;
        ENTITY(reg_a6)->hp.h += 8;
        goto skip_4;
skip_3:
        if (ENTITY(reg_a6)->move.h == 0x280) goto skip_4;
        ENTITY(reg_a6)->move.h += 8;
skip_4:
        if (g_frame_mod2 != 0) {
            reg_a0 = (u8 *)join_select_object_update_table_2;
            reg_d0.h[0] = 0x1E;
            reg_d0.h[0] &= g_game_frame;
            reg_d0.h[0] += reg_d0.h[0];
            reg_a0 += reg_d0.h[0];
            reg_d6.h[1] = (*(u16 *)(reg_a0 + (0)));
            reg_d6.h[0] = (*(u16 *)(reg_a0 + (2)));
            reg_d1.h[1] = (*(u16 *)(reg_a6 + (4)));
            reg_d1.h[0] = (*(u16 *)(reg_a6 + (6)));
            reg_d1.w += 0xFE00F000;
            reg_d1.h[0] += 0x900;
            reg_tmp.w = reg_d1.w;
            reg_d1.h[1] = reg_tmp.h[0];
            reg_d1.h[0] = reg_tmp.h[1];
            reg_d1.h[0] += 0x600;
            reg_tmp.w = reg_d1.w;
            reg_d1.h[1] = reg_tmp.h[0];
            reg_d1.h[0] = reg_tmp.h[1];
            reg_d3.h[0] = (*(u16 *)(reg_a6 + (0x14)));
            reg_d4.h[0] = (*(u16 *)(reg_a6 + (0xE)));
            sprite_draw_layer5_blinking();
            reg_d3.h[0] = (*(u16 *)(reg_a6 + (0x16)));
            if (reg_d3.h[0] != 0x200) {
                reg_d1.w += 0xFC000000;
                reg_d2.w += 1;
                sprite_draw_layer5_blinking();
            }
            reg_d3.h[0] = (*(u16 *)(reg_a6 + (0x18)));
            if (reg_d3.h[0] != 0x200) {
                reg_d1.w += 0xFC000000;
                reg_d2.w += 1;
                sprite_draw_layer5_blinking();
            }
            reg_d3.h[0] = (*(u16 *)(reg_a6 + (0x1A)));
            if (reg_d3.h[0] != 0x200) {
                reg_d1.w += 0xFC000000;
                reg_d2.w += 1;
                sprite_draw_layer5_blinking();
            }
        }
        reg_tmp.b[0] = (*(u8 *)(reg_a6 + (0x11)));
        (*(u8 *)(reg_a6 + (0x11))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)(reg_a6 + (0x11))) = (u8) (*(u8 *)(reg_a6 + (0x10)));
            (*(u16 *)(reg_a6 + (0x12))) += 8;
            if ((*(u16 *)(reg_a6 + (0x12))) == 0x28) {
                (*(u16 *)(reg_a6 + (0x12))) = 0U;
            }
        }
    } else {
        reg_tmp.b[0] = (*(u8 *)(reg_a6 + (9)));
        (*(u8 *)(reg_a6 + (9))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)(reg_a6 + (9))) = (u8) (*(u8 *)(reg_a6 + (8)));
            (*(u16 *)(reg_a6 + (0xA))) += 4;
            if (ENTITY(reg_a6)->draw.h != 0x5C) goto skip_5;
            ENTITY(reg_a6)->sprite.h = 0x90;
            return;
skip_5:
            if (ENTITY(reg_a6)->draw.h != 0x9C) return;
            ENTITY(reg_a6)->flags.b[1] |= 4;
        }
    }
}

u8 join_select_p1_table[32] = {
    0x37, 0x00, 0x00, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00,
    0x08, 0x00, 0x09, 0x00, 0x00, 0x00, 0x19, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 join_select_p2_table[32] = {
    0x37, 0x00, 0x0E, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00,
    0x08, 0x00, 0x09, 0x00, 0x01, 0x00, 0x19, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u16 D_00251B20[8] = {
    0x0000, 0x1549, 0x0000, 0x154A, 0x0000, 0x154B, 0x0000, 0x154C,
};

u16 D_00251B30[8] = {
    0x0000, 0x154D, 0x0000, 0x154E, 0x0000, 0x154F, 0x0000, 0x1550,
};

u8 D_00251B40[32] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
};

u8 join_select_prompt_draw_table[32] = {
    0x20, 0x50, 0x52, 0x45, 0x53, 0x53, 0x20, 0x53, 0x54, 0x41, 0x52, 0x54, 0x20, 0x20, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
};

u8 join_select_prompt_draw_table_2[32] = {
    0x20, 0x20, 0x46, 0x52, 0x45, 0x45, 0x20, 0x50, 0x4C, 0x41, 0x59, 0x20, 0x20, 0x20, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
};

u8 join_select_prompt_draw_table_3[32] = {
    0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x43, 0x4F, 0x49, 0x4E, 0x20, 0x20, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
};

u8 D_00251BC0[32] = {
    0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x43, 0x4F, 0x49, 0x4E, 0x53, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
};

u8 D_00251BE0[32] = {
    0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x4D, 0x4F, 0x52, 0x45, 0x20, 0x43, 0x4F, 0x49, 0x4E, 0x20, 0x20, 0x00, 0x00,
};

u8 D_00251C00[32] = {
    0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
    0x20, 0x31, 0x20, 0x4D, 0x4F, 0x52, 0x45, 0x20, 0x43, 0x4F, 0x49, 0x4E, 0x20, 0x20, 0x00, 0x00,
};

u8 join_select_object_update_table[160] = {
    0x00, 0x00, 0xF7, 0x0A, 0x00, 0x00, 0xF8, 0x0A, 0x00, 0x00, 0xF9, 0x0A, 0x00, 0x00, 0xFA, 0x0A,
    0x00, 0x00, 0xFB, 0x0A, 0x00, 0x00, 0xFC, 0x0A, 0x00, 0x00, 0xFD, 0x0A, 0x00, 0x00, 0xFE, 0x0A,
    0x00, 0x00, 0xFF, 0x0A, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x01, 0x0B, 0x00, 0x00, 0x02, 0x0B,
    0x00, 0x00, 0x03, 0x0B, 0x00, 0x00, 0x04, 0x0B, 0x00, 0x00, 0x05, 0x0B, 0x00, 0x00, 0x06, 0x0B,
    0x00, 0x00, 0x07, 0x0B, 0x00, 0x00, 0x08, 0x0B, 0x00, 0x00, 0x09, 0x0B, 0x00, 0x00, 0x0A, 0x0B,
    0x00, 0x00, 0x0B, 0x0B, 0x00, 0x00, 0x0C, 0x0B, 0x00, 0x00, 0x0D, 0x0B, 0x00, 0x00, 0x0E, 0x0B,
    0x00, 0x00, 0x0F, 0x0B, 0x00, 0x00, 0x10, 0x0B, 0x00, 0x00, 0x11, 0x0B, 0x00, 0x00, 0x12, 0x0B,
    0x00, 0x00, 0x13, 0x0B, 0x00, 0x00, 0x14, 0x0B, 0x00, 0x00, 0x15, 0x0B, 0x00, 0x00, 0x16, 0x0B,
    0x00, 0x00, 0x17, 0x0B, 0x00, 0x00, 0x18, 0x0B, 0x00, 0x00, 0x19, 0x0B, 0x00, 0x00, 0x1A, 0x0B,
    0x00, 0x00, 0x1B, 0x0B, 0x00, 0x00, 0x1C, 0x0B, 0x00, 0x00, 0x1D, 0x0B, 0x00, 0x00, 0x1E, 0x0B,
};

u16 D_00251CC0[16] = {
    0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
    0x0008, 0x0009, 0x000A, 0x000B, 0x0000, 0x0000, 0x0000, 0x0000,
};

u8 D_00251CE0[48] = {
    0x00, 0x00, 0x31, 0x0B, 0x00, 0x00, 0x36, 0x0B, 0x00, 0x00, 0x32, 0x0B, 0x00, 0x00, 0x36, 0x0B,
    0x00, 0x00, 0x33, 0x0B, 0x00, 0x00, 0x36, 0x0B, 0x00, 0x00, 0x34, 0x0B, 0x00, 0x00, 0x36, 0x0B,
    0x00, 0x00, 0x35, 0x0B, 0x00, 0x00, 0x36, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 D_00251D10[48] = {
    0x00, 0x00, 0x28, 0x0B, 0x00, 0x00, 0x2D, 0x0B, 0x00, 0x00, 0x29, 0x0B, 0x00, 0x00, 0x2D, 0x0B,
    0x00, 0x00, 0x2A, 0x0B, 0x00, 0x00, 0x2D, 0x0B, 0x00, 0x00, 0x2B, 0x0B, 0x00, 0x00, 0x2D, 0x0B,
    0x00, 0x00, 0x2C, 0x0B, 0x00, 0x00, 0x2D, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 D_00251D40[48] = {
    0x00, 0x00, 0x1F, 0x0B, 0x00, 0x00, 0x24, 0x0B, 0x00, 0x00, 0x20, 0x0B, 0x00, 0x00, 0x24, 0x0B,
    0x00, 0x00, 0x21, 0x0B, 0x00, 0x00, 0x24, 0x0B, 0x00, 0x00, 0x22, 0x0B, 0x00, 0x00, 0x24, 0x0B,
    0x00, 0x00, 0x23, 0x0B, 0x00, 0x00, 0x24, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 join_select_object_update_table_2[128] = {
    0x00, 0x08, 0x00, 0x80, 0x00, 0x10, 0x00, 0x80, 0x00, 0x18, 0x00, 0x80, 0x00, 0x20, 0x00, 0x80,
    0x00, 0x28, 0x00, 0x80, 0x00, 0x30, 0x00, 0x80, 0x00, 0x38, 0x00, 0x80, 0x00, 0x40, 0x00, 0x80,
    0x00, 0x48, 0x00, 0x80, 0x00, 0x50, 0x00, 0x80, 0x00, 0x58, 0x00, 0x80, 0x00, 0x60, 0x00, 0x80,
    0x00, 0x68, 0x00, 0x80, 0x00, 0x70, 0x00, 0x80, 0x00, 0x78, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80,
    0x00, 0x08, 0x00, 0x80, 0x00, 0x10, 0x00, 0x80, 0x00, 0x18, 0x00, 0x80, 0x00, 0x20, 0x00, 0x80,
    0x00, 0x28, 0x00, 0x80, 0x00, 0x30, 0x00, 0x80, 0x00, 0x38, 0x00, 0x80, 0x00, 0x40, 0x00, 0x80,
    0x00, 0x48, 0x00, 0x80, 0x00, 0x50, 0x00, 0x80, 0x00, 0x58, 0x00, 0x80, 0x00, 0x60, 0x00, 0x80,
    0x00, 0x68, 0x00, 0x80, 0x00, 0x70, 0x00, 0x80, 0x00, 0x78, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80,
};

u8 join_select_object_update_table_3[256] = {
    0x00, 0x80, 0x00, 0x08, 0x00, 0x80, 0x00, 0x10, 0x00, 0x80, 0x00, 0x18, 0x00, 0x80, 0x00, 0x20,
    0x00, 0x80, 0x00, 0x28, 0x00, 0x80, 0x00, 0x30, 0x00, 0x80, 0x00, 0x38, 0x00, 0x80, 0x00, 0x40,
    0x00, 0x80, 0x00, 0x48, 0x00, 0x80, 0x00, 0x50, 0x00, 0x80, 0x00, 0x58, 0x00, 0x80, 0x00, 0x60,
    0x00, 0x80, 0x00, 0x68, 0x00, 0x80, 0x00, 0x70, 0x00, 0x80, 0x00, 0x78, 0x00, 0x80, 0x00, 0x80,
    0x00, 0x80, 0x00, 0x78, 0x00, 0x80, 0x00, 0x70, 0x00, 0x80, 0x00, 0x68, 0x00, 0x80, 0x00, 0x60,
    0x00, 0x80, 0x00, 0x58, 0x00, 0x80, 0x00, 0x50, 0x00, 0x80, 0x00, 0x48, 0x00, 0x80, 0x00, 0x40,
    0x00, 0x80, 0x00, 0x38, 0x00, 0x80, 0x00, 0x30, 0x00, 0x80, 0x00, 0x28, 0x00, 0x80, 0x00, 0x20,
    0x00, 0x80, 0x00, 0x18, 0x00, 0x80, 0x00, 0x10, 0x00, 0x80, 0x00, 0x08, 0x00, 0x80, 0x00, 0x80,
    0x00, 0x80, 0x00, 0x08, 0x00, 0x80, 0x00, 0x10, 0x00, 0x80, 0x00, 0x18, 0x00, 0x80, 0x00, 0x20,
    0x00, 0x80, 0x00, 0x28, 0x00, 0x80, 0x00, 0x30, 0x00, 0x80, 0x00, 0x38, 0x00, 0x80, 0x00, 0x40,
    0x00, 0x80, 0x00, 0x48, 0x00, 0x80, 0x00, 0x50, 0x00, 0x80, 0x00, 0x58, 0x00, 0x80, 0x00, 0x60,
    0x00, 0x80, 0x00, 0x68, 0x00, 0x80, 0x00, 0x70, 0x00, 0x80, 0x00, 0x78, 0x00, 0x80, 0x00, 0x80,
    0x00, 0x80, 0x00, 0x08, 0x00, 0x80, 0x00, 0x10, 0x00, 0x80, 0x00, 0x18, 0x00, 0x80, 0x00, 0x20,
    0x00, 0x80, 0x00, 0x28, 0x00, 0x80, 0x00, 0x30, 0x00, 0x80, 0x00, 0x38, 0x00, 0x80, 0x00, 0x40,
    0x00, 0x80, 0x00, 0x48, 0x00, 0x80, 0x00, 0x50, 0x00, 0x80, 0x00, 0x58, 0x00, 0x80, 0x00, 0x60,
    0x00, 0x80, 0x00, 0x68, 0x00, 0x80, 0x00, 0x70, 0x00, 0x80, 0x00, 0x78, 0x00, 0x80, 0x00, 0x80,
};

u16 join_select_ship_step_table[4] = {
    0x0000, 0x0600, 0x0000, 0x0000,
};

u16 join_select_doll_step_table[4] = {
    0x0000, 0x0600, 0x0C00, 0x0000,
};

u16 join_select_object_defaults_set_table[4] = {
    0x0000, 0x0101, 0x0200, 0x0000,
};

/* .bss (the compiler lays these out in reverse) */
u8 join_select_p1_table_at_8[16];
u8 join_select_p2_table_at_8[16];
u16 join_select_object_spawn_buffer_2[8];
u16 join_select_object_spawn_buffer[16];
u8 D_0029BEE0[32];

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

PC_DATA_ALIAS(D_0029BEE1, D_0029BEE0, 0x1);
PC_DATA_ALIAS(D_0029BEE4, D_0029BEE0, 0x4);
PC_DATA_ALIAS(D_0029BEE6, D_0029BEE0, 0x6);
PC_DATA_ALIAS(D_0029BEEE, D_0029BEE0, 0xe);
PC_DATA_ALIAS(D_0029BEFC, D_0029BEE0, 0x1c);
PC_DATA_ALIAS(D_0029BEFE, D_0029BEE0, 0x1e);
#endif
