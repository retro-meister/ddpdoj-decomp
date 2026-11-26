#include "common.h"
#include "fade.h"
#include "enemy.h"
#include "player.h"
#include "entity.h"
#include "sdk/ps2sdk.h"
#include "continue_screen.h"
#include "debug_views.h"
#include "player_slot.h"

extern u16 D_0026ED10[];
extern u16 D_0028DC68[];

extern u8 D_00269920[];

extern u16 slowdown_budget_limits_loop2[];
extern u16 D_00269708[];
extern u16 D_00269800[];
extern u16 D_00269840[];
extern u16 D_002698B0[];
extern u16 D_0026A3F0[];
extern u16 settings_notice_fade_palettes[];
extern u16 D_0026B580[];
extern u16 stage2_boss_flash_palettes[];
extern u16 stage2_boss_fade_palettes[];
extern u16 stage2_boss_enter_flash[];
extern u16 stage3_boss_enter_flash[];
extern u16 stage3_boss_final_flash[];
extern u16 stage3_boss_final_fade[];
extern u16 stage1_boss_blast_flash[];
extern u16 stage1_boss_final_flash[];
extern u16 stage1_boss_enter_flash[];
extern u16 stage4_boss_flash_palettes[];
extern u16 stage4_boss_fade_palettes[];
extern u16 stage4_boss_enter_flash[];

void func_00210EA0(void);
void func_00211140(void);
void func_00211420(void);
void func_00211720(void);
void func_00211920(void);
void func_002119A0(void);
void func_00211E90(void);
void func_00211F40(void);

extern u16 D_00246C50[];
extern u16 g_stage3_map_palettes[];
extern u16 D_0025F770[352];
extern u8 D_0025FBB0[];
extern u8 D_0025FBF0[];
extern u8 D_0025FC30[];
extern u8 D_0025FC70[];
extern u8 D_0025FCB0[];
extern u8 D_0025FCF0[];
extern u8 D_0025FD30[];
extern u8 D_0025FD70[];
extern u8 D_0025FDB0[];
extern u16 D_00260FF0[];
extern u16 D_002610F0[];
extern u16 D_00261D30[];
extern u16 D_00261DF0[];
extern u16 D_00261F30[];
extern u16 D_00261FF0[];
extern u16 D_00262030[];
extern u16 D_00262070[];
extern u16 D_002620B0[];
extern u16 D_00262230[];
extern u16 D_00262270[];
extern u16 D_002622B0[];
extern u16 D_002622F0[];
extern u16 D_00262330[];
extern u16 D_00262370[];
extern u8 D_002623F0[];
extern u8 D_00262430[];
extern u16 D_00262470[];
extern u16 D_002624B0[];
extern struct D002687b0Record D_002687B0;
extern u16 D_00269750[];
extern u16 D_00269780[];
extern u16 D_002697B0[];
extern u16 D_00274040[];
extern u16 D_00274840[];
extern u16 D_00275040[];
extern u16 g_p2_laser_stop_y;
extern u16 g_p1_laser_stop_y;
extern u16 g_p2_weapon_level_data_as_u16_a[];
extern u16 g_p1_weapon_level_data_as_u16_a[];
extern u16 g_p2_lives;
extern u16 g_p1_lives;
extern u8 g_bullets[67216];
extern u16 g_bullet_cancel[];
extern u16 D_00299780[];
extern u8 g_sparks[2048];
extern u8 g_sparks_second_half[];
extern u16 D_0029A530[];
extern u8 g_explosions[4480];
extern u16 g_bomb_entities[];
extern u8 D_0029D710[32];
extern u8 D_0029D730[32];
extern u8 D_0029D750[32];
extern u8 D_0029D770[32];
extern u8 g_p2_laser_entities[1296];
extern u8 g_p1_laser_entities[1296];
extern u8 D_0029E390[1728];
extern u8 D_0029EA50[1728];
extern u8 g_p2_options[80];
extern u8 g_p1_options[80];
extern s16 g_player2[];
extern s16 g_player1[];
extern u32 g_deferred_text[1568];
extern u16 g_p1_score_extra_cell[];
extern u16 g_p2_score_extra_cell[];
extern u16 g_p1_score_cells[];
extern u16 g_p2_score_cells[];
extern u8 D_002BB470[64];
extern u8 g_items[512];
extern u8 D_002BF3EA[];
extern u16 D_002BF400[];
extern u8 g_pickups[3080];
extern void p1_continue_discount_reset(void);
extern void p2_continue_discount_reset(void);
extern void input_get_p1_held(void);
extern void input_get_p2_held(void);
extern void input_get_p1_pressed(void);
extern void input_get_p2_pressed(void);


void func_0020F550(void) {
    STORE_POINTER(slowdown_budget_limits_loop2 + 16, D_002624B0);
    STORE_POINTER(slowdown_budget_limits_loop2 + 23, palette_white);
    STORE_POINTER(D_00269708 + 8, D_00269750);
    STORE_POINTER(D_00269708 + 16, D_00269780);
    STORE_POINTER(D_00269708 + 24, D_002697B0);
    STORE_POINTER(D_00269800 + 4, D_00262470);
    STORE_POINTER(D_00269800 + 11, palette_white);
    STORE_POINTER(D_00269840 + 4, D_00261F30);
    STORE_POINTER(D_00269840 + 11, D_00261FF0);
    STORE_POINTER(D_00269840 + 18, D_00262030);
    STORE_POINTER(D_00269840 + 25, D_00262070);
    STORE_POINTER(D_00269840 + 32, D_002620B0);
    STORE_POINTER(D_00269840 + 39, D_002622B0);
    STORE_POINTER(D_00269840 + 46, D_00260FF0);
    STORE_POINTER(D_002698B0 + 3, palette_white);
    STORE_POINTER(D_002698B0 + 9, palette_white);
    STORE_POINTER(D_002698B0 + 15, palette_white);
    STORE_POINTER(D_002698B0 + 21, palette_white);
    STORE_POINTER(D_002698B0 + 27, palette_white);
    STORE_POINTER(D_002698B0 + 33, palette_white);
    STORE_POINTER(D_002698B0 + 39, palette_white);
    STORE_POINTER(D_002698B0 + 45, palette_white);
    STORE_POINTER((u16 *)D_00269920 + 3, palette_black);
    STORE_POINTER((u16 *)D_00269920 + 9, palette_black);
    STORE_POINTER((u16 *)D_00269920 + 15, palette_black);
    STORE_POINTER((u16 *)D_00269920 + 21, palette_black);
    STORE_POINTER((u16 *)D_00269920 + 27, palette_black);
    STORE_POINTER((u16 *)D_00269920 + 33, palette_black);
    STORE_POINTER((u16 *)D_00269920 + 39, palette_black);
    STORE_POINTER((u16 *)D_00269920 + 45, palette_black);
    STORE_POINTER((u16 *)D_00269920 + 51, palette_black);
    STORE_POINTER((u16 *)D_00269920 + 57, palette_black);
    STORE_POINTER((u16 *)D_00269920 + 63, palette_black);
    STORE_POINTER((u16 *)D_00269920 + 69, palette_black);
    STORE_POINTER((u16 *)D_00269920 + 75, palette_black);
    STORE_POINTER((u16 *)D_00269920 + 81, palette_black);
    STORE_POINTER((u16 *)D_00269920 + 87, palette_black);
    STORE_POINTER((u16 *)D_00269920 + 93, palette_black);
    STORE_POINTER((u16 *)D_00269920 + 99, palette_black);
    STORE_POINTER((u16 *)D_00269920 + 105, palette_black);
    STORE_POINTER((u16 *)D_00269920 + 111, palette_black);
    STORE_POINTER(continue_player1.other_routine, p1_continue_discount_reset);
    STORE_POINTER(continue_player1.held, input_get_p1_held);
    STORE_POINTER(continue_player1.pressed, input_get_p1_pressed);
    STORE_POINTER(continue_player1.other_state, ((u16 *)D_002BF3EA));
    STORE_POINTER(continue_player2.other_routine, p2_continue_discount_reset);
    STORE_POINTER(continue_player2.held, input_get_p2_held);
    STORE_POINTER(continue_player2.pressed, input_get_p2_pressed);
    STORE_POINTER(continue_player2.other_state, D_002BF400);
    STORE_POINTER(player_starts[0].lives, &(*(u32 *)&g_p1_lives));
    STORE_POINTER(player_starts[1].lives, &(*(u32 *)&g_p2_lives));
    STORE_POINTER(debug_list_views[0].entries, g_bomb_entities);
    STORE_POINTER(debug_list_views[1].entries, ((u16 *)g_player1));
    STORE_POINTER(debug_list_views[2].entries, ((u16 *)g_player2));
    STORE_POINTER(debug_list_views[3].entries, ((u16 *)g_p1_options));
    STORE_POINTER(debug_list_views[4].entries, ((u16 *)g_p2_options));
    STORE_POINTER(debug_list_views[5].entries, ((u16 *)D_0029E390));
    STORE_POINTER(debug_list_views[6].entries, ((u16 *)D_0029EA50));
    STORE_POINTER(debug_list_views[7].entries, ((u16 *)g_p1_laser_entities));
    STORE_POINTER(debug_list_views[8].entries, ((u16 *)g_p2_laser_entities));
    STORE_POINTER(debug_list_views[9].entries, ((u16 *)D_0029D770));
    STORE_POINTER(debug_list_views[10].entries, ((u16 *)D_0029D750));
    STORE_POINTER(debug_list_views[11].entries, ((u16 *)D_0029D730));
    STORE_POINTER(debug_list_views[12].entries, ((u16 *)D_0029D710));
    STORE_POINTER(debug_list_views[13].entries, g_p1_weapon_level_data_as_u16_a);
    STORE_POINTER(debug_list_views[14].entries, g_p2_weapon_level_data_as_u16_a);
    STORE_POINTER(debug_list_views[15].entries, ((u16 *)g_enemy_entities));
    STORE_POINTER(debug_list_views[16].entries, ((u16 *)g_enemy_entities_second));
    STORE_POINTER(debug_list_views[17].entries, ((u16 *)g_items));
    STORE_POINTER(debug_list_views[18].entries, &(*(u32 *)&g_p1_laser_stop_y));
    STORE_POINTER(debug_list_views[19].entries, &(*(u32 *)&g_p2_laser_stop_y));
    STORE_POINTER(debug_list_views[20].entries, ((u16 *)g_pickups));
    STORE_POINTER(debug_list_views[21].entries, ((u16 *)g_sparks));
    STORE_POINTER(debug_list_views[22].entries, ((u16 *)g_sparks_second_half));
    STORE_POINTER(debug_list_views[23].entries, ((u16 *)g_deferred_text));
    STORE_POINTER(debug_list_views[24].entries, g_p1_score_cells);
    STORE_POINTER(debug_list_views[25].entries, g_p2_score_cells);
    STORE_POINTER(debug_list_views[26].entries, g_p1_score_extra_cell);
    STORE_POINTER(debug_list_views[27].entries, g_p2_score_extra_cell);
    STORE_POINTER(debug_list_views[28].entries, ((u16 *)g_bullets));
    STORE_POINTER(debug_list_views[29].entries, ((u16 *)D_002BB470));
    STORE_POINTER(debug_list_views[30].entries, D_0029A530);
    STORE_POINTER(debug_list_views[31].entries, g_bullet_cancel);
    STORE_POINTER(debug_list_views[32].entries, ((u16 *)g_explosions));
    STORE_POINTER(debug_list_views[33].entries, D_00299780);
    STORE_POINTER(debug_table_views[0].table, D_00274040);
    STORE_POINTER(debug_table_views[1].table, D_00274840);
    STORE_POINTER(debug_table_views[2].table, D_00275040);
    STORE_POINTER(D_0026A3F0 + 4, D_00261DF0);
    STORE_POINTER(settings_notice_fade_palettes + 4, ((u16 *)D_00262430));
    STORE_POINTER(settings_notice_fade_palettes + 11, ((u16 *)D_002623F0));
    STORE_POINTER(settings_notice_fade_palettes + 18, ((u16 *)D_0025F770));
    STORE_POINTER(settings_notice_fade_palettes + 25, ((u16 *)&D_002687B0));
    STORE_POINTER(D_0026B580 + 4, D_00262230);
    STORE_POINTER(D_0026B580 + 11, D_00262270);
    STORE_POINTER(D_0026B580 + 18, D_002622F0);
    STORE_POINTER(D_0026B580 + 25, D_00262330);
    STORE_POINTER(D_0026B580 + 32, D_00262370);
    STORE_POINTER(D_0026B580 + 39, D_00261F30);
    STORE_POINTER(D_0026B580 + 46, D_002622B0);
    STORE_POINTER(stage2_boss_flash_palettes + 4, D_002610F0);
    STORE_POINTER(stage2_boss_flash_palettes + 11, D_00246C50);
    STORE_POINTER(stage2_boss_fade_palettes + 3, D_00261D30);
    STORE_POINTER(stage2_boss_fade_palettes + 9, D_00261D30);
    STORE_POINTER(stage2_boss_fade_palettes + 15, D_00261D30);
    STORE_POINTER(stage2_boss_fade_palettes + 21, D_00261D30);
    STORE_POINTER(stage2_boss_fade_palettes + 27, D_00261D30);
    STORE_POINTER(stage2_boss_fade_palettes + 33, D_00261D30);
    STORE_POINTER(stage2_boss_enter_flash + 4, ((u16 *)D_0025FBB0));
    STORE_POINTER(stage2_boss_enter_flash + 11, ((u16 *)D_0025FBF0));
    STORE_POINTER(stage2_boss_enter_flash + 18, ((u16 *)D_0025FC30));
    STORE_POINTER(stage2_boss_enter_flash + 25, ((u16 *)D_0025FC70));
    STORE_POINTER(stage2_boss_enter_flash + 32, ((u16 *)D_0025FCB0));
    STORE_POINTER(stage2_boss_enter_flash + 39, ((u16 *)D_0025FCF0));
    STORE_POINTER(stage3_boss_enter_flash + 4, ((u16 *)D_0025FD30));
    STORE_POINTER(stage3_boss_enter_flash + 11, ((u16 *)D_0025FD70));
    STORE_POINTER(stage3_boss_enter_flash + 18, ((u16 *)D_0025FDB0));
    STORE_POINTER(stage3_boss_final_flash + 4, D_002610F0);
    STORE_POINTER(stage3_boss_final_flash + 11, g_stage3_map_palettes);
    STORE_POINTER(stage3_boss_final_flash + 18, g_stage3_map_palettes);
    STORE_POINTER(stage3_boss_final_flash + 25, g_stage3_map_palettes);
    STORE_POINTER(stage3_boss_final_flash + 32, g_stage3_map_palettes);
    STORE_POINTER(stage3_boss_final_flash + 39, g_stage3_map_palettes);
    STORE_POINTER(stage3_boss_final_flash + 46, g_stage3_map_palettes);
    STORE_POINTER(stage3_boss_final_flash + 53, g_stage3_map_palettes);
    STORE_POINTER(stage3_boss_final_flash + 60, g_stage3_map_palettes);
    STORE_POINTER(stage3_boss_final_flash + 67, g_stage3_map_palettes);
    STORE_POINTER(stage3_boss_final_flash + 74, g_stage3_map_palettes);
    STORE_POINTER(stage3_boss_final_flash + 81, g_stage3_map_palettes);
    STORE_POINTER(stage3_boss_final_flash + 88, g_stage3_map_palettes);
    STORE_POINTER(stage3_boss_final_flash + 95, g_stage3_map_palettes);
    STORE_POINTER(stage3_boss_final_flash + 102, g_stage3_map_palettes);
    STORE_POINTER(stage3_boss_final_flash + 109, g_stage3_map_palettes);
    STORE_POINTER(stage3_boss_final_fade + 3, D_00261D30);
    STORE_POINTER(stage3_boss_final_fade + 9, D_00261D30);
    STORE_POINTER(stage3_boss_final_fade + 15, D_00261D30);
}

extern u16 D_00244930[];
extern u16 D_00249E90[];
extern u16 stage1_boss_palette[1504];
extern u8 D_0025FA70[];
extern u8 D_0025FE70[];
extern u8 D_0025FEB0[];
extern u8 D_0025FEF0[];
extern u16 D_00261D70[];
extern u16 D_0026ED30[];
extern u16 D_0026ED40[];
extern u16 D_0026ED50[];
extern u16 D_0026ED60[];
extern u16 D_0026ED70[];
extern u16 D_0028DC70[];


void func_002108C0(void) {
    STORE_POINTER(stage1_boss_blast_flash + 4, ((u16 *)stage1_boss_palette));
    STORE_POINTER(stage1_boss_blast_flash + 11, ((u16 *)D_0025FA70));
    STORE_POINTER(stage1_boss_blast_flash + 18, ((u16 *)D_0025FA70));
    STORE_POINTER(stage1_boss_blast_flash + 25, ((u16 *)D_0025FA70));
    STORE_POINTER(stage1_boss_blast_flash + 32, D_00244930);
    STORE_POINTER(stage1_boss_final_flash + 4, D_002610F0);
    STORE_POINTER(stage1_boss_final_flash + 11, D_00244930);
    STORE_POINTER(stage1_boss_enter_flash + 4, ((u16 *)stage1_boss_palette));
    STORE_POINTER(stage1_boss_enter_flash + 11, ((u16 *)D_0025FA70));
    STORE_POINTER(stage1_boss_enter_flash + 18, ((u16 *)D_0025FA70));
    STORE_POINTER(stage1_boss_enter_flash + 25, ((u16 *)D_0025FA70));
    STORE_POINTER(stage1_boss_enter_flash + 32, D_00261D70);
    STORE_POINTER(((u16 *)D_0026ED10), D_0026ED30);
    STORE_POINTER(D_0026ED10 + 2, D_0026ED40);
    STORE_POINTER(D_0026ED10 + 4, D_0026ED50);
    STORE_POINTER(D_0026ED10 + 6, D_0026ED60);
    STORE_POINTER(D_0026ED10 + 8, D_0026ED30);
    STORE_POINTER(D_0026ED10 + 10, D_0026ED40);
    STORE_POINTER(D_0026ED10 + 12, D_0026ED50);
    STORE_POINTER(D_0026ED10 + 14, D_0026ED60);
    STORE_POINTER(((u16 *)D_0028DC68), D_0026ED70);
    STORE_POINTER(D_0028DC68 + 2, D_0028DC70);
    STORE_POINTER(stage4_boss_flash_palettes + 4, D_002610F0);
    STORE_POINTER(stage4_boss_flash_palettes + 11, D_00249E90);
    STORE_POINTER(stage4_boss_fade_palettes + 3, D_00261D30);
    STORE_POINTER(stage4_boss_enter_flash + 4, ((u16 *)D_0025FE70));
    STORE_POINTER(stage4_boss_enter_flash + 11, ((u16 *)D_0025FEB0));
    STORE_POINTER(stage4_boss_enter_flash + 18, ((u16 *)D_0025FEF0));
    STORE_POINTER(stage4_boss_enter_flash + 25, D_00261D70);
}

extern u8 D_002BAE90[];

#ifdef DEATH_LABEL
extern u8 D_0028E2A4;
#endif

void func_00210C90(void) {
    s32 var_a1;
    u8 *temp_a2;

    var_a1 = 0;
    do {
        temp_a2 = D_002BAE90 + var_a1;
        (*(s8 *)((u8 *)(temp_a2) + (0))) = 0;
        var_a1 += 8;
        (*(s8 *)((u8 *)(temp_a2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (7))) = 0;
    } while (var_a1 < 0x20);
    *(s8 *)(reg_a5 + 3) = 1;
    ENTITY(reg_a6)->draw.sh = 0x60;
    ENTITY(reg_a6)->sprite.sh = 0x10;
#ifdef DEATH_LABEL
    D_0028E2A4 = 0x78;
#endif
}

s32 func_001317E0();
s32 func_00133070();
s32 fade_out();
s32 fade_release();
s32 fade_is_running();
s32 func_0022B660();
s32 replay_start_result();
s32 replay_start_run_end();
extern u8 D_00269920[];
extern u16 g_loop;
extern u16 g_stage;
extern u8 g_replay_mode;
#ifdef DEATH_LABEL
s32 stage_load_step();
extern u8 D_0028E2A4;
extern u8 g_game_mode;
extern s16 g_loaded_stage;
extern u8 D_0028ED60;
extern u8 death_D_00290568;
#endif

void func_00210D00() {
    u16 temp_a0;
    u16 temp_v1;

    reg_a6 = D_002BAE90;
    func_00211420();
    if (*(u8 *)(reg_a5 + 3) == 0) {
        func_00210C90();
        return;
    }
#ifdef DEATH_LABEL
    if (D_0028E2A4 != 0) {
        D_0028E2A4 -= 1;
    }
    if ((D_0028E2A4 == 0) && (g_loaded_stage != g_stage) && (D_0028E2A4 == 0)) {
        stage_load_step();
    }
#endif
    temp_v1 = ENTITY(reg_a6)->draw.h;
    if (temp_v1 != 0) {
        ENTITY(reg_a6)->draw.h = (u16) (temp_v1 - 1);
        return;
    }
    func_00210EA0();
    func_00211140();
    if (ENTITY(reg_a6)->look.h == 0) {
        temp_a0 = ENTITY(reg_a6)->sprite.h;
        if (temp_a0 != 0) {
#ifdef DEATH_LABEL
            if (temp_a0 == 1) {
                if (g_loaded_stage != g_stage) {
                    return;
                }
                if ((g_game_mode == 2) && (D_0028ED60 == 0)) {
                    death_D_00290568 = 1;
                    *(s16 *)reg_a5 = 0;
                    return;
                }
            }
            {
#else
            if ((temp_a0 != 1) || (func_00133070() == 0) || (func_0022B660() != 0)) {
#endif
                ENTITY(reg_a6)->sprite.h -= 1;
                if (ENTITY(reg_a6)->sprite.h == 0) {
                    reg_a0 = D_00269920;
                    fade_out();
                    ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_d0.h[1];
                    ENTITY(reg_a6)->hit_x_plus.h = (u16) reg_d0.h[0];
                }
            }
        } else {
            reg_d0.h[1] = ENTITY(reg_a6)->hit_y_minus.h;
            reg_d0.h[0] = ENTITY(reg_a6)->hit_x_plus.h;
            fade_is_running();
            if (cond_flag == 0) {
                reg_d0.h[1] = ENTITY(reg_a6)->hit_y_minus.h;
                reg_d0.h[0] = ENTITY(reg_a6)->hit_x_plus.h;
                fade_release();
                if (g_replay_mode == 2) {
                    if ((g_loop == 1) && (g_stage == 4)) {
                        replay_start_result();
                        return;
                    }
                    replay_start_run_end();
                    return;
                }
                func_001317E0();
                *(s16 *)reg_a5 = 0;
            }
        }
    }
}

s32 p1_bomb_stock_draw();
s32 sfx_score_item_pickup_2();
s32 sfx_hyper_pickup();
s32 sfx_extend();
s32 score_add_p1();
s32 hud_p1_lives_put();
extern s32 g_p1_extend_score;
extern u16 g_p1_score_digits;
extern u16 g_p1_lives;
extern u16 g_p1_maximum_value[];
extern s16 g_player1[];
#ifdef DEATH_LABEL
extern u16 D_00684C80[];
#endif

void func_00210EA0(void) {
    u8 *p;

    if (*(u8 *)(reg_a6 + 5) & 1) {
        goto block_3;
    }
    *(u8 *)(reg_a6 + 5) |= 1;
    if (g_player1[0] >= 0) {
        goto block_2;
    }
    g_p1_extend_score = -1;
    if (g_p1_score_digits != 0) {
        goto block_2;
    }
    *(u16 *)(reg_a6 + 0xE) += 1;
    if (g_loop == 0) {
        *(u16 *)(reg_a6 + 6) = 1;
        return;
    }
    *(u16 *)(reg_a6 + 6) = 2;
    return;
block_1:
    *(u16 *)(reg_a6 + 0xE) -= 1;
block_2:
    *(u8 *)(reg_a6 + 5) |= 0x80;
block_rts:
    return;
block_3:
    if (*(u8 *)(reg_a6 + 5) & 0x80) {
        goto block_rts;
    }
    if (*(u16 *)(reg_a6 + 6) == 1) {
        switch (g_p1_lives) {
        case 0:
            goto block_1;
        }
        reg_d0.w = 0x01000000;
        score_add_p1();
        g_p1_lives -= 1;
        hud_p1_lives_put();
        *(s16 *)(reg_a6 + 0xA) = 0x30;
        *(u8 *)(reg_a6 + 0x11) |= 1;
        sfx_extend();
        sfx_hyper_pickup();
        sfx_score_item_pickup_2();
    } else if (*(u16 *)(reg_a6 + 6) == 2) {
        if (g_p1_lives != 0) {
            reg_d0.w = MAIN_OR_DEATH_LABEL(0x05000000, 0x07000000);
            score_add_p1();
            g_p1_lives -= 1;
            hud_p1_lives_put();
            *(s16 *)(reg_a6 + 0xA) = 0x30;
            *(u8 *)(reg_a6 + 0x11) |= 1;
            sfx_extend();
            sfx_hyper_pickup();
            sfx_score_item_pickup_2();
        } else {
            *(u16 *)(reg_a6 + 6) = 3;
        }
    } else if (*(u16 *)(reg_a6 + 6) == 3) {
        if (!(PLAYER(g_player1)->flags.b[1] & 0x40) && g_p1_maximum_value[0] != 0) {
            reg_d0.w = 0x10000000;
            score_add_p1();
            g_p1_maximum_value[0] = 0;
            p1_bomb_stock_draw();
            *(s16 *)(reg_a6 + 0xA) = 0x30;
            *(u8 *)(reg_a6 + 0x11) |= 1;
            sfx_extend();
            sfx_hyper_pickup();
            sfx_score_item_pickup_2();
        } else {
            *(u16 *)(reg_a6 + 6) = 4;
        }
    } else {
        p = (u8 *)(u32)(&PLAYER(g_player1)->bombs.b.count);
        if (*p == 0) {
            goto block_1;
        }
        reg_d0.w = 0x01000000;
#ifdef DEATH_LABEL
        if (D_00684C80[1] == 2) {
            *(s32 *)&reg_d0 = 0x01000000;
        } else if (D_00684C80[1] == 4) {
            reg_d0.w = 0x01500000;
        } else {
            reg_d0.w = 0x03000000;
        }
#endif
        score_add_p1();
        *p -= 1;
        p1_bomb_stock_draw();
        *(s16 *)(reg_a6 + 0xA) = 0x30;
        *(u8 *)(reg_a6 + 0x11) |= 1;
        sfx_extend();
        sfx_hyper_pickup();
        sfx_score_item_pickup_2();
    }
}

s32 p2_bomb_stock_draw();
s32 score_add_p2();
s32 hud_p2_lives_put();
extern s32 g_p2_extend_score;
extern u16 g_p2_score_digits;
extern u16 g_p2_lives;
extern u16 g_p2_maximum_value[];
extern s16 g_player2[];
#ifdef DEATH_LABEL
extern u16 D_00684C80[];
#endif

void func_00211140(void) {
    u8 *p;

    if (*(u8 *)(reg_a6 + 4) & 1) {
        goto block_3;
    }
    *(u8 *)(reg_a6 + 4) |= 1;
    if (g_player2[0] >= 0) {
        goto block_2;
    }
    g_p2_extend_score = -1;
    if (g_p2_score_digits != 0) {
        goto block_2;
    }
    *(u16 *)(reg_a6 + 0xE) += 1;
    if (g_loop == 0) {
        *(u16 *)(reg_a6 + 8) = 1;
        return;
    }
    *(u16 *)(reg_a6 + 8) = 2;
    return;
block_1:
    *(u16 *)(reg_a6 + 0xE) -= 1;
block_2:
    *(u8 *)(reg_a6 + 4) |= 0x80;
block_rts:
    return;
block_3:
    if (*(u8 *)(reg_a6 + 4) & 0x80) {
        goto block_rts;
    }
    if (*(u16 *)(reg_a6 + 8) == 1) {
        switch (g_p2_lives) {
        case 0:
            goto block_1;
        }
        reg_d0.w = 0x01000000;
        score_add_p2();
        g_p2_lives -= 1;
        hud_p2_lives_put();
        *(s16 *)(reg_a6 + 0xA) = 0x30;
        if (*(u16 *)(reg_a6 + 0x10) & 1) {
            *(u8 *)(reg_a6 + 0x11) &= 0xFE;
        } else {
            sfx_extend();
            sfx_hyper_pickup();
            sfx_score_item_pickup_2();
        }
        return;
    }
    if (*(u16 *)(reg_a6 + 8) == 2) {
        if (g_p2_lives != 0) {
            reg_d0.w = MAIN_OR_DEATH_LABEL(0x05000000, 0x07000000);
            score_add_p2();
            g_p2_lives -= 1;
            hud_p2_lives_put();
            if (*(u16 *)(reg_a6 + 0x10) & 1) {
                *(u8 *)(reg_a6 + 0x11) &= 0xFE;
            } else {
                *(s16 *)(reg_a6 + 0xA) = 0x30;
                sfx_extend();
                sfx_hyper_pickup();
                sfx_score_item_pickup_2();
            }
            return;
        }
        *(u16 *)(reg_a6 + 8) = 3;
        return;
    }
    if (*(u16 *)(reg_a6 + 8) == 3) {
        if (!(PLAYER(g_player2)->flags.b[1] & 0x40) && g_p2_maximum_value[0] != 0) {
            reg_d0.w = 0x10000000;
            score_add_p2();
            g_p2_maximum_value[0] = 0;
            p2_bomb_stock_draw();
            if (*(u16 *)(reg_a6 + 0x10) & 1) {
                *(u8 *)(reg_a6 + 0x11) &= 0xFE;
            } else {
                *(s16 *)(reg_a6 + 0xA) = 0x30;
                sfx_extend();
                sfx_hyper_pickup();
                sfx_score_item_pickup_2();
            }
            return;
        }
        *(u16 *)(reg_a6 + 8) = 4;
        return;
    }
    p = (u8 *)(u32)(&PLAYER(g_player2)->bombs.b.count);
    if (*p == 0) {
        goto block_1;
    }
    reg_d0.w = 0x01000000;
#ifdef DEATH_LABEL
    if (D_00684C80[3] == 2) {
        *(s32 *)&reg_d0 = 0x01000000;
    } else if (D_00684C80[3] == 4) {
        reg_d0.w = 0x01500000;
    } else {
        reg_d0.w = 0x03000000;
    }
#endif
    score_add_p2();
    *p -= 1;
    p2_bomb_stock_draw();
    if (*(u16 *)(reg_a6 + 0x10) & 1) {
        *(u8 *)(reg_a6 + 0x11) &= 0xFE;
    } else {
        *(s16 *)(reg_a6 + 0xA) = 0x30;
        sfx_extend();
        sfx_hyper_pickup();
        sfx_score_item_pickup_2();
    }
}

void func_00211420(void) {
}

s32 entity_follow_scroll();
extern u16 g_side_scroll_step[];

void func_00211430(void) {
    entity_follow_scroll();
    reg_d1.h[0] = g_side_scroll_step[0];
    ENTITY(reg_a6)->x.h -= reg_d1.h[0];
}

extern u16 g_two_player_game;

void func_00211470(void) {
    reg_d3.sw = 0x1D;
    if (g_loop == 0) {
        if (g_two_player_game == 0) {
            goto block_3;
        }
    } else {
block_3:
        reg_d3.sw = 0xE;
    }
}



void func_002114A0(void) {
    memset(((s32 *)D_00299780), 0, 0x5A6);
}


void wreck_spawn(void) {
    u32 tmp;

    func_00211470();
    reg_a0 = (u8 *) D_00299780;
loop_1:
    if (*(u16 *) reg_a0 != 0) goto next_1;
    func_00211920();
    cond_flag = 0;
    return;
next_1:
    reg_a0 += 0x30;
    tmp = reg_d3.h[0] - 1;
    reg_d3.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d3.w = 0;
    cond_flag = 1;
    reg_d3.h[0] -= 1;
}


void func_00211550(void) {
    u32 tmp;

    func_00211470();
    reg_a0 = (u8 *) D_00299780;
loop_1:
    if (*(u16 *) reg_a0 != 0) goto next_1;
    func_00211E90();
    cond_flag = 0;
    return;
next_1:
    reg_a0 += 0x30;
    tmp = reg_d3.h[0] - 1;
    reg_d3.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d3.w = 0;
    cond_flag = 1;
    reg_d3.h[0] -= 1;
}


void func_002115E0(void) {
    u32 tmp;

    func_00211470();
    reg_a0 = (u8 *) D_00299780;
loop_1:
    if (*(u16 *) reg_a0 != 0) goto next_1;
    func_00211F40();
    cond_flag = 0;
    return;
next_1:
    reg_a0 += 0x30;
    tmp = reg_d3.h[0] - 1;
    reg_d3.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d3.w = 0;
    cond_flag = 1;
    reg_d3.h[0] -= 1;
}

extern u8 wreck_draw_routines[];
extern u16 g_frame_mod8;
extern u16 g_frame_mod2;
extern u16 D_00299D20[];

void func_00211670(void) {
    u32 temp_a0;

    reg_d7.h[0] = D_00299D20[0];
    if (reg_d7.h[0] != 0) {
        reg_d5.w = 0;
        reg_d7.h[0] -= 1;
        reg_d4.h[0] = 0xFFC0;
        reg_d2.h[0] = 0x3FF;
        reg_d6.h[0] = g_frame_mod2;
        reg_a4 = wreck_draw_routines;
        reg_tmp.h[0] = reg_d6.h[0];
        reg_d6.h[0] <<= 0xF;
        temp_a0 = reg_d6.h[0];
        reg_tmp.h[0] >>= 1;
        reg_d6.h[0] = temp_a0 | reg_tmp.h[0];
        reg_tmp.w = reg_d6.w;
        reg_d6.h[0] = g_frame_mod8;
        reg_d6.h[1] = reg_tmp.h[0];
        func_00211720();
    }
}

typedef void (*Fn)(void);

extern u8 *reg_call_target_as_u8_p;

void func_00211720(void) {
    u32 t1;

    reg_a6 = (u8 *)((u8 *)D_00299780);
    goto loop_1;
skip_1:
    reg_a6 += 0x30;
loop_1:
    if (!(0 > (s64)ENTITY(reg_a6)->flags.sh)) {
        goto skip_1;
    }
    if (0 > (s64)(s32)reg_d6.w) {
        goto block_1;
    }
    reg_tmp.h[1] = ENTITY(reg_a6)->hit_x_plus.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->hit_x_minus.h;
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = ENTITY(reg_a6)->hit_y_plus.h;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->hit_y_plus.h -= 4;
    if (0 > (s64)ENTITY(reg_a6)->hit_y_plus.sh) {
        ENTITY(reg_a6)->hit_y_plus.h = ENTITY(reg_a6)->hit_y_minus.h;
    }
block_1:
    func_00211430();
    if (reg_d6.h[0] != 0) {
        goto block_2;
    }
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x20);
    if (ENTITY(reg_a6)->y.sh < reg_d0.sh[0]) {
        goto block_3;
    }
block_2:
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->misc.b.user;
    reg_a0 = *(u8 **)(reg_a4 + reg_d0.h[0]);
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
    reg_a6 += 0x30;
    t1 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t1;
    if (((s64)((s64)(t1 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
    return;
block_3:
    ENTITY(reg_a6)->flags.sh = 0;
    D_00299D20[0] -= 1;
    reg_a6 += 0x30;
    t1 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t1;
    if (((s64)((s64)(t1 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
}

extern u8 wreck_setups[];
extern u32 D_0028E9A0;

void func_00211920(void) {
    D_0028E9A0 = reg_d0.w;
    reg_d3.h[0] = reg_d0.h[0];
    reg_d3.h[0] &= 0x3C;
    reg_a2 = (u8 *)(*(u16 **)(wreck_setups + (reg_d3.h[0] & ~3)));
    *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
    reg_a2 += 2;
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    func_002119A0();
}

s32 rng_next_bit();
s32 rng_next_0_to_2();
s32 rng_next_0_to_3();
s32 entity_distance_to();
extern u8 g_boss_present_b1;
extern u16 D_00299D22[];
extern u16 D_00299D24[];

#define W0(o) (*(u16 *)(reg_a0 + (o)))
#define W6(o) (*(u16 *)(reg_a6 + (o)))
#define NEXT_W() (*(u16 *)reg_a2)

void func_002119A0(void) {
    u32 save_d0;
    u8 *save_a6;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

    if (g_stage != 4) goto next_1;
    if (g_boss_present_b1 & 0x40) goto block_set;
next_1:
    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a6 = reg_a6;
    reg_d5.h[0] = W0(2);
    reg_d7.h[0] = W0(4);
    W0(2) += 0x4400;
    func_00211470();
    reg_d6.h[0] = reg_d3.h[0];
    D_00299D22[0] = 2;
    D_00299D24[0] = 0xA;
    reg_a6 = (u8 *)((u8 *)D_00299780);
loop_2:
    if (W6(0) == 0) goto next_6;
    if (W6(4) != reg_d7.h[0]) goto next_3;
    if (D_00299D22[0] == 0) goto block_kill;
    D_00299D22[0] -= 1;
next_3:
    if (g_loop == 0) goto next_4;
    reg_d0.h[0] = W6(0);
    reg_d0.h[0] &= 0x3C;
    reg_d0.h[0] -= 4;
    if (reg_d0.h[0] != 0) goto next_4;
    reg_tmp.h[0] = D_00299D24[0];
    D_00299D24[0] -= 1;
    if (reg_tmp.h[0] == 0) goto block_kill;
    reg_d3.h[0] = reg_d7.h[0];
    reg_d2.h[0] = reg_d5.h[0];
    entity_distance_to();
    if (reg_d0.h[0] >= 0xA00) goto next_6;
    goto block_kill;
next_4:
    reg_d3.h[0] = reg_d7.h[0];
    reg_d2.h[0] = reg_d5.h[0];
    entity_distance_to();
    if (reg_d0.h[0] >= 0x800) goto next_6;
block_kill:
    W0(0) = 0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a6 = save_a6;
    reg_d0.w = D_0028E9A0;
    return;
next_6:
    reg_a6 += 0x30;
    if ((s16)(--reg_d6.h[0]) >= 0) goto loop_2;
    W0(2) = reg_d5.h[0];
    W0(4) = reg_d7.h[0];
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a6 = save_a6;
block_set:
    W0(6) = NEXT_W();
    reg_a2 += 2;
    W0(8) = NEXT_W();
    reg_a2 += 2;
    reg_d3.w = 0;
    rng_next_bit();
    if (reg_d0.b[0] != 0) goto next_7;
    reg_d3.b[0] |= 0x20;
next_7:
    reg_a0[0x1D] = reg_d3.b[0];
    W0(0xE) = NEXT_W();
    reg_a2 += 2;
    W0(0x18) = NEXT_W();
    reg_a2 += 2;
    reg_a0[0x1C] = 0x1E;
    rng_next_0_to_2();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    W0(0x10) = reg_d0.h[0];
    W0(0x12) = NEXT_W();
    reg_a2 += 2;
    reg_a0[0x1F] = reg_d1.b[0];
    W0(0x20) = NEXT_W();
    reg_a2 += 2;
    reg_tmp.h[0] = NEXT_W();
    reg_a2 += 2;
    if (0 > (s16) reg_tmp.h[0]) {
        rng_next_bit();
    } else if (!reg_tmp.h[0]) {
        rng_next_0_to_2();
    } else {
        rng_next_0_to_3();
    }
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a2 += reg_d0.h[0];
    W0(0x14) = *(u16 *)(reg_a2 + 0);
    W0(0x16) = *(u16 *)(reg_a2 + 2);
    reg_tmp.h[1] = W0(0x14);
    reg_tmp.h[0] = W0(0x16);
    reg_a2 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W0(0x10);
    W0(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a2 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    W0(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a2 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_d0.w = 0;
    reg_a0[0x1E] = reg_d0.b[0];
    cond_flag = 0;
    reg_d0.w = D_0028E9A0;
    D_00299D20[0] += 1;
}

void func_00211E90(void) {
    D_0028E9A0 = reg_d0.w;
    *(s8 *)(reg_a0 + 0x1E) = 0x1F;
    reg_d3.h[0] = reg_d0.h[0];
    reg_d3.h[0] &= 0x3C;
    reg_a2 = *(u8 **)(wreck_setups + (reg_d3.h[0] & ~3));
    *(u16 *)reg_a0 = (u16) *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_d3.h[1] = ENTITY(reg_a6)->y.h;
    reg_d3.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w += reg_d2.w;
    *(u16 *)(reg_a0 + 2) = (u16) reg_d3.h[1];
    *(u16 *)(reg_a0 + 4) = (u16) reg_d3.h[0];
    func_002119A0();
}

void func_00211F40(void) {
    D_0028E9A0 = reg_d0.w;
    *(s8 *)(reg_a0 + 0x1E) = 0x1F;
    reg_d3.h[0] = reg_d0.h[0];
    reg_d3.h[0] &= 0x3C;
    reg_a2 = (u8 *)(*(u16 **)(wreck_setups + (reg_d3.h[0] & ~3)));
    *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
    reg_a2 += 2;
    *(u16 *)(reg_a0 + 2) = reg_d2.h[1];
    *(u16 *)(reg_a0 + 4) = reg_d2.h[0];
    func_002119A0();
}

/* .sbss (the compiler lays these out in reverse) */
#ifdef DEATH_LABEL
u8 death_D_00290568 __attribute__((aligned(4)));
#endif

/* .bss (the compiler lays these out in reverse) */
u16 D_00299D20[8];
u16 D_00299780[720];
