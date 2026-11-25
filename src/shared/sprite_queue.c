#include "common.h"
#include "entity.h"

void func_0019B510(void);

extern s16 D_0028E124_as_s16;
extern s16 g_sprite_last_boss_used_as_s16;
extern s16 g_sprite_hyper_display_used_as_s16;
extern s16 g_sprite_hyper_ready_used_as_s16;
extern s16 g_sprite_maximum_used_as_s16;
extern s16 g_sprite_stage_clear2_used_as_s16;
extern s16 g_sprite_stage_clear1_used_as_s16;
extern s16 g_sprite_ship_select_used_as_s16;
extern s16 g_sprite_bombs_used_as_s16;
extern s16 g_sprite_laser_trail_used_as_s16;
extern s16 g_sprite_sight_used_as_s16;
extern s16 g_sprite_score_used_as_s16;
extern s16 g_sprite_warning_used_as_s16;
extern s16 g_sprite_bullets2_used_as_s16;
extern s16 g_sprite_bullets_used_as_s16;
extern s16 g_sprite_sparks_used_as_s16;
extern s16 g_sprite_players_used_as_s16;
extern s16 g_sprite_options_used_as_s16;
extern s16 g_sprite_player_lasers_used_as_s16;
extern s16 g_sprite_player_shots_used_as_s16;
extern s16 g_sprite_debris2_used_as_s16;
extern s16 g_sprite_debris1_used_as_s16;
extern s16 g_sprite_player_shadows_used_as_s16;
extern s16 g_sprite_items_used_as_s16;
extern s16 g_sprite_items_first_used_as_s16;
extern s16 g_sprite_special_items_used_as_s16;
extern s16 D_0028E18C_as_s16;
extern s16 g_sprite_layer5_used_as_s16;
extern s16 g_sprite_layer4_used_as_s16;
extern s16 g_sprite_layer3_used_as_s16;
extern s16 g_sprite_layer2_used_as_s16;
extern s16 g_sprite_layer1_used_as_s16;

void sprite_lists_reset(void) {
    g_sprite_layer1_used_as_s16 = 0;
    g_sprite_layer2_used_as_s16 = 0;
    g_sprite_layer3_used_as_s16 = 0;
    g_sprite_layer4_used_as_s16 = 0;
    g_sprite_layer5_used_as_s16 = 0;
    D_0028E18C_as_s16 = 0;
    g_sprite_special_items_used_as_s16 = 0;
    g_sprite_items_first_used_as_s16 = 0;
    g_sprite_items_used_as_s16 = 0;
    g_sprite_player_shadows_used_as_s16 = 0;
    g_sprite_debris1_used_as_s16 = 0;
    g_sprite_debris2_used_as_s16 = 0;
    g_sprite_sparks_used_as_s16 = 0;
    g_sprite_bullets_used_as_s16 = 0;
    g_sprite_bullets2_used_as_s16 = 0;
    g_sprite_player_shots_used_as_s16 = 0;
    g_sprite_player_lasers_used_as_s16 = 0;
    g_sprite_options_used_as_s16 = 0;
    g_sprite_players_used_as_s16 = 0;
    g_sprite_warning_used_as_s16 = 0;
    g_sprite_score_used_as_s16 = 0;
    g_sprite_sight_used_as_s16 = 0;
    g_sprite_laser_trail_used_as_s16 = 0;
    g_sprite_bombs_used_as_s16 = 0;
    g_sprite_ship_select_used_as_s16 = 0;
    g_sprite_stage_clear1_used_as_s16 = 0;
    g_sprite_stage_clear2_used_as_s16 = 0;
    g_sprite_maximum_used_as_s16 = 0;
    g_sprite_hyper_ready_used_as_s16 = 0;
    g_sprite_hyper_display_used_as_s16 = 0;
    g_sprite_last_boss_used_as_s16 = 0;
    D_0028E124_as_s16 = 0;
}


s32 func_00206D10();
s32 func_00206D30();
extern s16 D_0028E114;
extern s16 D_0028E118;
extern u16 D_0028E11C;
extern u16 D_0028E120;
extern u16 D_0028E124;
extern u16 g_sprite_last_boss_used;
extern u16 g_sprite_hyper_display_used;
extern u16 g_sprite_hyper_ready_used;
extern u16 g_sprite_maximum_used;
extern u16 g_sprite_stage_clear2_used;
extern u16 g_sprite_stage_clear1_used;
extern u16 g_sprite_ship_select_used;
extern u16 g_sprite_bombs_used;
extern u16 g_sprite_laser_trail_used;
extern u16 g_sprite_sight_used;
extern u16 g_sprite_score_used;
extern u16 g_sprite_warning_used;
extern u16 g_sprite_bullets2_used;
extern u16 g_sprite_bullets_used;
extern u16 g_sprite_sparks_used;
extern u16 g_sprite_players_used;
extern u16 g_sprite_options_used;
extern u16 g_sprite_player_lasers_used;
extern u16 g_sprite_player_shots_used;
extern u16 g_sprite_debris2_used;
extern u16 g_sprite_debris1_used;
extern u16 g_sprite_player_shadows_used;
extern u16 g_sprite_items_used;
extern u16 g_sprite_items_first_used;
extern u16 g_sprite_special_items_used;
extern u16 D_0028E18C;
extern u16 g_sprite_layer5_used;
extern u16 g_sprite_layer4_used;
extern u16 g_sprite_layer3_used;
extern u16 g_sprite_layer2_used;
extern u16 g_sprite_layer1_used;
extern u8 D_0028E308;
extern u8 D_0028E30C;
extern u8 g_sprite_last_boss_buf[];
extern u8 g_sprite_laser_trail_buf[];
extern u8 g_sprite_hyper_display_buf[];
extern u8 g_sprite_hyper_ready_buf[];
extern u8 g_sprite_maximum_buf[];
extern u8 D_002A3DF0[];
extern u8 D_002A3E70[];
extern u8 g_sprite_ship_select_buf[];
extern u8 g_sprite_bombs_buf[];
extern u8 D_002A43B0[];
extern u8 g_sprite_score_buf[];
extern u8 g_sprite_warning_buf[];
extern u8 D_002A4670[];
extern u8 g_sprite_bullets_buf[];
extern u8 D_002A5A30[];
extern u8 g_sprite_players_buf[];
extern u8 g_sprite_options_buf[];
extern u8 g_sprite_player_lasers_buf[];
extern u8 g_sprite_player_shots_buf[];
extern u8 D_002A6450[];
extern u8 D_002A6540[];
extern u8 g_sprite_player_shadows_buf[];
extern u8 g_sprite_items_buf[];
extern u8 D_002A67B0[];
extern u8 g_sprite_special_items_buf[];
extern u8 D_002A6C30[];
extern u8 g_sprite_layer5_buf[];
extern u8 g_sprite_layer4_buf[];
extern u8 g_sprite_layer3_buf[];
extern u8 g_sprite_layer2_buf[];
extern u16 g_sprite_layer1_buf_as_u16_a[];
extern u8 g_arcade_sprites[];

void sprite_lists_build(void) {
    u16 count;
    u8 bits;

    func_00206D30();
    reg_d0.h[0] = g_sprite_layer1_used;
    reg_d0.h[0] += g_sprite_layer2_used;
    reg_d0.h[0] += g_sprite_layer3_used;
    reg_d0.h[0] += g_sprite_layer4_used;
    reg_d0.h[0] += g_sprite_debris1_used;
    reg_d0.h[0] += g_sprite_layer5_used;
    reg_d0.h[0] += g_sprite_debris2_used;
    reg_d0.h[0] += g_sprite_player_shadows_used;
    reg_d0.h[0] += g_sprite_special_items_used;
    reg_d0.h[0] += g_sprite_items_first_used;
    reg_d0.h[0] += g_sprite_items_used;
    reg_d0.h[0] += g_sprite_player_shots_used;
    reg_d0.h[0] += g_sprite_player_lasers_used;
    reg_d0.h[0] += g_sprite_options_used;
    reg_d0.h[0] += g_sprite_players_used;
    reg_d0.h[0] += g_sprite_sparks_used;
    if ((D_0028E30C == 0) || (D_0028E308 == 0)) {
        reg_d0.h[0] += g_sprite_bullets_used;
        reg_d0.h[0] += g_sprite_bullets2_used;
    }
    if (D_0028E30C != 0) {
        reg_d0.h[0] += D_0028E18C;
    }
    reg_d0.h[0] += g_sprite_warning_used;
    D_0028E118 = 0;
    reg_d0.h[0] += g_sprite_score_used;
    D_0028E114 = 0;
    reg_d0.h[0] += g_sprite_sight_used;
    reg_d0.h[0] += g_sprite_laser_trail_used;
    reg_d0.h[0] += g_sprite_bombs_used;
    reg_d0.h[0] += g_sprite_ship_select_used;
    reg_d0.h[0] += g_sprite_stage_clear1_used;
    reg_d0.h[0] += g_sprite_stage_clear2_used;
    reg_d0.h[0] += g_sprite_maximum_used;
    reg_d0.h[0] += g_sprite_hyper_ready_used;
    reg_d0.h[0] += g_sprite_hyper_display_used;
    reg_d0.h[0] += g_sprite_last_boss_used;
    reg_d0.h[0] -= MAIN_OR_DEATH_LABEL(0x1764, 0x36CC);
    reg_tmp.w = (u32) (s16) reg_d0.h[0];
    reg_d0.w = reg_tmp.w;
    D_0028E11C = reg_d0.h[0];
    reg_d0.h[0] /= 0xC;
    D_0028E120 = reg_d0.h[0];
    if ((s16)(D_0028E11C) >= 0) {
        reg_d0.h[0] = g_sprite_sparks_used;
        g_sprite_sparks_used = 0;
        D_0028E11C -= reg_d0.h[0];
        D_0028E118 = 1;
        if ((s16) D_0028E11C >= 0) {
            D_0028E114 = 1;
            g_sprite_debris1_used = 0;
            g_sprite_debris2_used = 0;
        }
    }
    reg_a0 = (u8 *)g_sprite_layer2_buf;
    reg_a1 = (u8 *)(&g_sprite_layer2_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_layer3_buf;
    reg_a1 = (u8 *)(&g_sprite_layer3_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_layer4_buf;
    reg_a1 = (u8 *)(&g_sprite_layer4_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)D_002A67B0;
    reg_a1 = (u8 *)(&g_sprite_items_first_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_player_shadows_buf;
    reg_a1 = (u8 *)(&g_sprite_player_shadows_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)D_002A6540;
    reg_a1 = (u8 *)(&g_sprite_debris1_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_layer5_buf;
    reg_a1 = (u8 *)(&g_sprite_layer5_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_special_items_buf;
    reg_a1 = (u8 *)(&g_sprite_special_items_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)D_002A6450;
    reg_a1 = (u8 *)(&g_sprite_debris2_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)D_002A43B0;
    reg_a1 = (u8 *)(&g_sprite_sight_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)D_002A3E70;
    reg_a1 = (u8 *)(&g_sprite_stage_clear1_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_laser_trail_buf;
    reg_a1 = (u8 *)(&g_sprite_laser_trail_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_bombs_buf;
    reg_a1 = (u8 *)(&g_sprite_bombs_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_player_shots_buf;
    reg_a1 = (u8 *)(&g_sprite_player_shots_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_options_buf;
    reg_a1 = (u8 *)(&g_sprite_options_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_player_lasers_buf;
    reg_a1 = (u8 *)(&g_sprite_player_lasers_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_items_buf;
    reg_a1 = (u8 *)(&g_sprite_items_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_hyper_display_buf;
    reg_a1 = (u8 *)(&g_sprite_hyper_display_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_players_buf;
    reg_a1 = (u8 *)(&g_sprite_players_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)D_002A5A30;
    reg_a1 = (u8 *)(&g_sprite_sparks_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_warning_buf;
    reg_a1 = (u8 *)(&g_sprite_warning_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    if (D_0028E30C == 0) goto next_30;
    if (D_0028E308 != 0) goto next_32;
next_30:
    reg_a0 = (u8 *)g_sprite_bullets_buf;
    reg_a1 = (u8 *)(&g_sprite_bullets_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
next_32:
    if (D_0028E30C == 0) goto next_34;
    if (D_0028E308 != 0) goto next_36;
next_34:
    reg_a0 = (u8 *)D_002A4670;
    reg_a1 = (u8 *)(&g_sprite_bullets2_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
next_36:
    if (D_0028E30C == 0) goto next_40;
    reg_a0 = (u8 *)D_002A6C30;
    reg_a1 = (u8 *)(&D_0028E18C);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
next_40:
    reg_a0 = (u8 *)g_sprite_last_boss_buf;
    reg_a1 = (u8 *)(&g_sprite_last_boss_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_score_buf;
    reg_a1 = (u8 *)(&g_sprite_score_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_ship_select_buf;
    reg_a1 = (u8 *)(&g_sprite_ship_select_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)D_002A3DF0;
    reg_a1 = (u8 *)(&g_sprite_stage_clear2_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_maximum_buf;
    reg_a1 = (u8 *)(&g_sprite_maximum_used);
    func_0019B510();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_hyper_ready_buf;
    reg_a1 = (u8 *)(&g_sprite_hyper_ready_used);
    func_0019B510();
next_50:
    count = g_sprite_layer1_used;
    reg_a0 = (u8 *)g_arcade_sprites;
    reg_d7.h[0] = D_0028E124;
    reg_d1.h[0] = 0xA;
    reg_d0.h[0] = count;
    D_0028E124 = count;
    reg_d3.h[0] = count;
    reg_d7.h[0] -= count;
    if (reg_d0.h[0] != 0) {
        reg_a1 = (u8 *)(g_sprite_layer1_buf_as_u16_a);
        if (reg_d0.h[0] > MAIN_OR_DEATH_LABEL(0x1758, 0x36C0)) {
            reg_d0.h[0] = MAIN_OR_DEATH_LABEL(0x1758, 0x36C0);
        }
        reg_d2.w = 0;
        reg_d4.w = 0x33;
        reg_d5.w = 0;
        reg_d1.h[0] = reg_d0.h[0];
        count = 0x32;
        do {
            reg_d4.h[0] -= 1;
            if ((s16) reg_d4.h[0] < 0) {
                reg_d4.w = 0x32;
                reg_tmp.w = 0xFBFFFC00;
                *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
                reg_a0 += 2;
                *(u16 *)reg_a0 = (u16) reg_tmp.h[0];
                reg_a0 += 2;
                *(u16 *)reg_a0 = 0U;
                reg_a0 += 2;
                *(u16 *)reg_a0 = 0U;
                reg_a0 += 2;
                *(u16 *)reg_a0 = 0x201U;
                reg_a0 += 2;
                reg_d2.h[0] += 0xC;
                reg_d4.h[0] -= 1;
            }
            *(u16 *)reg_a0 = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            reg_a0 += 2;
            *(u16 *)reg_a0 = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            reg_a0 += 2;
            *(u16 *)reg_a0 = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            reg_a0 += 2;
            *(u16 *)reg_a0 = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            reg_a0 += 2;
            *(u16 *)reg_a0 = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            reg_a0 += 2;
            reg_d3.b[0] = *(u8 *)(reg_a1 + 1);
            bits = *(u8 *)reg_a1;
            reg_d3.b[0] |= bits;
            reg_a1 += 2;
            (*(u8 *)((u8 *)(reg_a0) + (-5))) = (u8) reg_d3.b[0];
            reg_d5.h[0] += 1;
            reg_d2.h[0] += 0xC;
            reg_d0.h[0] -= 0xC;
        } while (reg_d0.h[0] != 0);
        g_sprite_layer1_used = reg_d0.h[0];
        if (reg_d1.h[0] != MAIN_OR_DEATH_LABEL(0x1758, 0x36C0)) {
            goto block_51;
        }
    } else {
block_51:
        *(u16 *)reg_a0 = 0U;
        reg_a0 += 2;
        *(u16 *)reg_a0 = 0U;
        reg_a0 += 2;
        *(u16 *)reg_a0 = 0U;
        reg_a0 += 2;
        *(u16 *)reg_a0 = 0U;
        reg_a0 += 2;
        *(u16 *)reg_a0 = 0U;
        reg_a0 += 2;
    }
    g_sprite_layer1_used = 0;
    g_sprite_layer2_used = 0;
    g_sprite_layer3_used = 0;
    g_sprite_layer4_used = 0;
    g_sprite_layer5_used = 0;
    g_sprite_special_items_used = 0;
    g_sprite_items_first_used = 0;
    g_sprite_items_used = 0;
    g_sprite_player_shadows_used = 0;
    g_sprite_debris1_used = 0;
    g_sprite_debris2_used = 0;
    g_sprite_player_shots_used = 0;
    g_sprite_player_lasers_used = 0;
    g_sprite_options_used = 0;
    g_sprite_players_used = 0;
    g_sprite_sparks_used = 0;
    g_sprite_bullets_used = 0;
    g_sprite_bullets2_used = 0;
    g_sprite_warning_used = 0;
    g_sprite_score_used = 0;
    g_sprite_sight_used = 0;
    g_sprite_laser_trail_used = 0;
    g_sprite_bombs_used = 0;
    g_sprite_ship_select_used = 0;
    g_sprite_stage_clear1_used = 0;
    g_sprite_stage_clear2_used = 0;
    g_sprite_maximum_used = 0;
    g_sprite_hyper_ready_used = 0;
    g_sprite_hyper_display_used = 0;
    g_sprite_last_boss_used = 0;
    func_00206D10();
}



void func_0019B510(void) {
    cond_flag = 0;
    reg_d0.h[0] = *(u16 *)reg_a1;
    switch (reg_d0.h[0]) {
    case 0:
        goto block_rts;
    default:
        reg_a2 = (u8 *)g_sprite_layer1_buf_as_u16_a;
        reg_a2 += g_sprite_layer1_used;
loop_1:
        *(u16 *)reg_a2 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 += 2;
        *(u16 *)reg_a2 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 += 2;
        *(u16 *)reg_a2 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 += 2;
        *(u16 *)reg_a2 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 += 2;
        *(u16 *)reg_a2 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 += 2;
        *(u16 *)reg_a2 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 += 2;
        *(u16 *)reg_a2 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 += 2;
        *(u16 *)reg_a2 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 += 2;
        g_sprite_layer1_used += 0xC;
        if (g_sprite_layer1_used != MAIN_OR_DEATH_LABEL(0x1758, 0x36C0)) {
            reg_d0.h[0] -= 0xC;
            if (reg_d0.h[0] != 0) goto loop_1;
            *(u16 *)reg_a1 = reg_d0.h[0];
block_rts:
            return;
        } else {
            *(u16 *)reg_a1 = 0;
            cond_flag = 1;
        }
        break;
    }
}


void sprite_entry_from_entity(void) {
    u32 temp_a3;
    u32 temp_t0;

    reg_a1 = (u8 *)(reg_a6 + 2);
    reg_d0.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    temp_t0 = reg_d0.h[0] + *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] = temp_t0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    temp_a3 = reg_d0.h[0] + *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] = temp_a3;
    reg_d0.w = (u32) ((s32) reg_d0.w >> 6);
    reg_d0.w &= 0x07FF03FF;
    reg_d0.w |= 0x80008000;
    *(u16 *)reg_a0 = reg_d0.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d0.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = ENTITY(reg_a6)->attr.h;
    reg_a0 += 2;
}

typedef void (*Fn)(void);

extern u8 D_0025EAF0[];
extern Fn reg_call_target_as_Fn;

void sprite_zoom_prepare_entity(void) {
    u32 k;
    u16 t;

    k = 0xFFFF;
    reg_a0 = (u8 *)D_0025EAF0;
    reg_d1.w = reg_d6.w;
    reg_d1.w = (u32) reg_d1.w >> 8;
    reg_d1.h[0] *= (u16)k;
    reg_d1.h[0] += 0x80;
    reg_d0.h[0] = ENTITY(reg_a6)->look.h;
    reg_d0.h[0] &= 0x1FF;
    reg_d0.h[0] >>= 1;
    reg_call_target_as_Fn = *(Fn *)(D_0025EAF0 + (reg_d0.h[0] & ~3));
    reg_call_target_as_Fn();
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_a0 = (u8 *)D_0025EAF0;
    reg_d0.w = 0x3E;
    t = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = t;
    reg_d1.h[0] *= 0xFFFF;
    reg_d1.h[0] += 0x80;
    reg_d0.b[0] &= ENTITY(reg_a6)->look.b.size;
    reg_d0.h[0] *= 4;
    reg_call_target_as_Fn = *(Fn *)(D_0025EAF0 + (reg_d0.h[0] & ~3));
    reg_call_target_as_Fn();
}

void sprite_entry_from_entity_zoomed(void) {
    reg_a1 = reg_a6 + 2;
    reg_d1.h[0] += *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] += *(u16 *)(reg_a1 + 2);
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] += *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] += *(u16 *)(reg_a1 + 2);
    reg_d1.w = (u32) ((s32) reg_d1.w >> 6);
    reg_d1.w &= 0x07FF03FF;
    reg_d1.w |= reg_d6.w;
    *(u16 *)reg_a0 = reg_d1.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = ENTITY(reg_a6)->attr.h;
    reg_a0 += 2;
}

extern u16 *reg_a0_as_u16_p;

void sprite_entry_from_regs(void) {
    reg_d0.w = reg_d1.w;
    reg_d0.w = (u32) ((s32) reg_d0.w >> 6);
    reg_d0.w &= 0x07FF03FF;
    reg_d0.w |= 0x80008000;
    *reg_a0_as_u16_p = reg_d0.h[1];
    reg_a0_as_u16_p += 1;
    *reg_a0_as_u16_p = reg_d0.h[0];
    reg_a0_as_u16_p += 1;
    *reg_a0_as_u16_p = reg_d2.h[1];
    reg_a0_as_u16_p += 1;
    *reg_a0_as_u16_p = reg_d2.h[0];
    reg_a0_as_u16_p += 1;
    *reg_a0_as_u16_p = reg_d3.h[0];
    reg_a0_as_u16_p += 1;
    *reg_a0_as_u16_p = reg_d4.h[0];
    reg_a0_as_u16_p += 1;
}

extern u8 D_0025EBF0[];

void sprite_zoom_prepare_regs(void) {
    u16 t;
    Fn *entry;

    reg_a0 = (u8 *)D_0025EBF0;
    reg_d7.w = reg_d6.w;
    reg_d7.w = (u32) reg_d7.w >> 8;
    reg_d7.h[0] *= 0xFFFF;
    reg_d7.h[0] += 0x80;
    reg_tmp4.h[0] = reg_d4.h[0];
    reg_d4.h[0] = reg_d4.h[1];
    reg_d4.h[1] = reg_tmp4.h[0];
    reg_d4.h[0] = reg_d3.h[0];
    reg_d4.h[0] &= 0x1FF;
    reg_d4.h[0] >>= 1;
    reg_call_target_as_Fn = *(entry = (Fn *)(D_0025EBF0 + (reg_d4.h[0] & ~3)));
    reg_call_target_as_Fn();
    reg_tmp7.h[0] = reg_d7.h[0];
    reg_a0 = (u8 *)D_0025EBF0;
    t = reg_d7.h[1];
    reg_d7.h[1] = reg_tmp7.h[0];
    reg_d7.h[0] = t;
    reg_d7.h[0] *= 0xFFFF;
    reg_d7.h[0] += 0x80;
    reg_d4.h[0] = reg_d3.h[0];
    reg_d4.h[0] &= 0x3E00;
    reg_d4.h[0] >>= 6;
    reg_call_target_as_Fn = *(entry = (Fn *)(D_0025EBF0 + (reg_d4.h[0] & ~3)));
    reg_call_target_as_Fn();
}

void sprite_entry_from_regs_zoomed(void) {
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d7.h[0] += reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_tmp7.h[0] = reg_d7.h[0];
    reg_d7.h[0] = reg_d7.h[1];
    reg_d7.h[1] = reg_tmp7.h[0];
    reg_d7.h[0] += reg_d1.h[0];
    reg_d7.w = (u32) ((s32) reg_d7.w >> 6);
    reg_d7.w &= 0x07FF03FF;
    reg_d7.w |= reg_d6.w;
    *(u16 *)reg_a0 = reg_d7.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d7.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d2.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    reg_tmp4.h[0] = reg_d4.h[0];
    reg_d4.h[0] = reg_d4.h[1];
    reg_d4.h[1] = reg_tmp4.h[0];
    *(u16 *)reg_a0 = reg_d4.h[0];
    reg_a0 += 2;
}

extern u8 g_sprite_layer1_buf[];

void entity_draw(void) {
    reg_a0 = g_sprite_layer1_buf;
    reg_a0 += g_sprite_layer1_used;
    sprite_entry_from_entity();
    g_sprite_layer1_used += 0xC;
}

void entity_draw_layer1(void) {
    reg_a0 = g_sprite_layer1_buf;
    reg_a0 += g_sprite_layer1_used;
    sprite_entry_from_entity();
    g_sprite_layer1_used += 0xC;
}

void entity_draw_layer2(void) {
    reg_a0 = g_sprite_layer2_buf;
    reg_a0 += g_sprite_layer2_used;
    sprite_entry_from_entity();
    g_sprite_layer2_used += 0xC;
}

void entity_draw_layer3(void) {
    reg_a0 = g_sprite_layer3_buf;
    reg_a0 += g_sprite_layer3_used;
    sprite_entry_from_entity();
    g_sprite_layer3_used += 0xC;
}

void entity_draw_layer4(void) {
    reg_a0 = g_sprite_layer4_buf;
    reg_a0 += g_sprite_layer4_used;
    sprite_entry_from_entity();
    g_sprite_layer4_used += 0xC;
}

void entity_draw_layer5(void) {
    reg_a0 = g_sprite_layer5_buf;
    reg_a0 += g_sprite_layer5_used;
    sprite_entry_from_entity();
    g_sprite_layer5_used += 0xC;
}


void entity_draw_keep(void) {
    u8 *temp_s1;
    s32 temp_s2;
    u32 temp_s0;

    temp_s1 = reg_a0;
    temp_s0 = reg_d0.w;
    temp_s2 = (s32)reg_a1;
    reg_a0 = g_sprite_layer1_buf;
    reg_a0 += g_sprite_layer1_used;
    sprite_entry_from_entity();
    reg_d0.w = temp_s0;
    reg_a0 = temp_s1;
    reg_a1 = (u8 *)temp_s2;
    g_sprite_layer1_used += 0xC;
}

void entity_draw_layer1_keep(void) {
    u8 *temp_s1;
    s32 temp_s2;
    u32 temp_s0;

    temp_s1 = reg_a0;
    temp_s0 = reg_d0.w;
    temp_s2 = (s32)reg_a1;
    reg_a0 = g_sprite_layer1_buf;
    reg_a0 += g_sprite_layer1_used;
    sprite_entry_from_entity();
    reg_d0.w = temp_s0;
    reg_a0 = temp_s1;
    reg_a1 = (u8 *)temp_s2;
    g_sprite_layer1_used += 0xC;
}

void entity_draw_layer2_keep(void) {
    u8 *temp_s1;
    s32 temp_s2;
    u32 temp_s0;

    temp_s1 = reg_a0;
    temp_s0 = reg_d0.w;
    temp_s2 = (s32)reg_a1;
    reg_a0 = g_sprite_layer2_buf;
    reg_a0 += g_sprite_layer2_used;
    sprite_entry_from_entity();
    reg_d0.w = temp_s0;
    reg_a0 = temp_s1;
    reg_a1 = (u8 *)temp_s2;
    g_sprite_layer2_used += 0xC;
}

void entity_draw_layer3_keep(void) {
    u8 *temp_s1;
    s32 temp_s2;
    u32 temp_s0;

    temp_s1 = reg_a0;
    temp_s0 = reg_d0.w;
    temp_s2 = (s32)reg_a1;
    reg_a0 = g_sprite_layer3_buf;
    reg_a0 += g_sprite_layer3_used;
    sprite_entry_from_entity();
    reg_d0.w = temp_s0;
    reg_a0 = temp_s1;
    reg_a1 = (u8 *)temp_s2;
    g_sprite_layer3_used += 0xC;
}

void entity_draw_layer4_keep(void) {
    u8 *temp_s1;
    s32 temp_s2;
    u32 temp_s0;

    temp_s1 = reg_a0;
    temp_s0 = reg_d0.w;
    temp_s2 = (s32)reg_a1;
    reg_a0 = g_sprite_layer4_buf;
    reg_a0 += g_sprite_layer4_used;
    sprite_entry_from_entity();
    reg_d0.w = temp_s0;
    reg_a0 = temp_s1;
    reg_a1 = (u8 *)temp_s2;
    g_sprite_layer4_used += 0xC;
}

void entity_draw_layer5_keep(void) {
    u8 *temp_s1;
    s32 temp_s2;
    u32 temp_s0;

    temp_s1 = reg_a0;
    temp_s0 = reg_d0.w;
    temp_s2 = (s32)reg_a1;
    reg_a0 = g_sprite_layer5_buf;
    reg_a0 += g_sprite_layer5_used;
    sprite_entry_from_entity();
    reg_d0.w = temp_s0;
    reg_a0 = temp_s1;
    reg_a1 = (u8 *)temp_s2;
    g_sprite_layer5_used += 0xC;
}


void entity_draw_layer1_zoom(void) {
    sprite_zoom_prepare_entity();
    reg_a0 = g_sprite_layer1_buf;
    reg_a0 += g_sprite_layer1_used;
    sprite_entry_from_entity_zoomed();
    g_sprite_layer1_used += 0xC;
}

void entity_draw_layer2_zoom(void) {
    sprite_zoom_prepare_entity();
    reg_a0 = g_sprite_layer2_buf;
    reg_a0 += g_sprite_layer2_used;
    sprite_entry_from_entity_zoomed();
    g_sprite_layer2_used += 0xC;
}

void entity_draw_layer3_zoom(void) {
    sprite_zoom_prepare_entity();
    reg_a0 = g_sprite_layer3_buf;
    reg_a0 += g_sprite_layer3_used;
    sprite_entry_from_entity_zoomed();
    g_sprite_layer3_used += 0xC;
}

void entity_draw_layer4_zoom(void) {
    sprite_zoom_prepare_entity();
    reg_a0 = g_sprite_layer4_buf;
    reg_a0 += g_sprite_layer4_used;
    sprite_entry_from_entity_zoomed();
    g_sprite_layer4_used += 0xC;
}

void entity_draw_layer5_zoom(void) {
    sprite_zoom_prepare_entity();
    reg_a0 = g_sprite_layer5_buf;
    reg_a0 += g_sprite_layer5_used;
    sprite_entry_from_entity_zoomed();
    g_sprite_layer5_used += 0xC;
}


void sprite_draw(void) {
    reg_a0 = g_sprite_layer1_buf;
    reg_a0 += g_sprite_layer1_used;
    sprite_entry_from_regs();
    g_sprite_layer1_used += 0xC;
}

void sprite_draw_layer1(void) {
    reg_a0 = g_sprite_layer1_buf;
    reg_a0 += g_sprite_layer1_used;
    sprite_entry_from_regs();
    g_sprite_layer1_used += 0xC;
}

void sprite_draw_layer2(void) {
    reg_a0 = g_sprite_layer2_buf;
    reg_a0 += g_sprite_layer2_used;
    sprite_entry_from_regs();
    g_sprite_layer2_used += 0xC;
}

void sprite_draw_layer3(void) {
    reg_a0 = g_sprite_layer3_buf;
    reg_a0 += g_sprite_layer3_used;
    sprite_entry_from_regs();
    g_sprite_layer3_used += 0xC;
}

void sprite_draw_layer4(void) {
    reg_a0 = g_sprite_layer4_buf;
    reg_a0 += g_sprite_layer4_used;
    sprite_entry_from_regs();
    g_sprite_layer4_used += 0xC;
}

void sprite_draw_layer5(void) {
    reg_a0 = g_sprite_layer5_buf;
    reg_a0 += g_sprite_layer5_used;
    sprite_entry_from_regs();
    g_sprite_layer5_used += 0xC;
}

void sprite_draw_keep(void) {
    u8 *temp_s0;
    u32 temp_s1;

    temp_s0 = reg_a0;
    temp_s1 = reg_d0.w;
    reg_a0 = g_sprite_layer1_buf;
    reg_a0 += g_sprite_layer1_used;
    sprite_entry_from_regs();
    reg_d0.w = temp_s1;
    reg_a0 = temp_s0;
    g_sprite_layer1_used += 0xC;
}

void sprite_draw_layer1_keep(void) {
    u8 *temp_s0;
    u32 temp_s1;

    temp_s0 = reg_a0;
    temp_s1 = reg_d0.w;
    reg_a0 = g_sprite_layer1_buf;
    reg_a0 += g_sprite_layer1_used;
    sprite_entry_from_regs();
    reg_d0.w = temp_s1;
    reg_a0 = temp_s0;
    g_sprite_layer1_used += 0xC;
}

void sprite_draw_layer2_keep(void) {
    u8 *temp_s0;
    u32 temp_s1;

    temp_s0 = reg_a0;
    temp_s1 = reg_d0.w;
    reg_a0 = g_sprite_layer2_buf;
    reg_a0 += g_sprite_layer2_used;
    sprite_entry_from_regs();
    reg_d0.w = temp_s1;
    reg_a0 = temp_s0;
    g_sprite_layer2_used += 0xC;
}

void sprite_draw_layer3_keep(void) {
    u8 *temp_s0;
    u32 temp_s1;

    temp_s0 = reg_a0;
    temp_s1 = reg_d0.w;
    reg_a0 = g_sprite_layer3_buf;
    reg_a0 += g_sprite_layer3_used;
    sprite_entry_from_regs();
    reg_d0.w = temp_s1;
    reg_a0 = temp_s0;
    g_sprite_layer3_used += 0xC;
}

void sprite_draw_layer4_keep(void) {
    u8 *temp_s0;
    u32 temp_s1;

    temp_s0 = reg_a0;
    temp_s1 = reg_d0.w;
    reg_a0 = g_sprite_layer4_buf;
    reg_a0 += g_sprite_layer4_used;
    sprite_entry_from_regs();
    reg_d0.w = temp_s1;
    reg_a0 = temp_s0;
    g_sprite_layer4_used += 0xC;
}

void sprite_draw_layer5_keep(void) {
    u8 *temp_s0;
    u32 temp_s1;

    temp_s0 = reg_a0;
    temp_s1 = reg_d0.w;
    reg_a0 = g_sprite_layer5_buf;
    reg_a0 += g_sprite_layer5_used;
    sprite_entry_from_regs();
    reg_d0.w = temp_s1;
    reg_a0 = temp_s0;
    g_sprite_layer5_used += 0xC;
}


void sprite_draw_layer5_zoom(void) {
    sprite_zoom_prepare_regs();
    reg_a0 = g_sprite_layer5_buf;
    reg_a0 += g_sprite_layer5_used;
    sprite_entry_from_regs_zoomed();
    g_sprite_layer5_used += 0xC;
}


void sprite_draw_layer1_zoom_keep(void)
{
    u8 *savedA0;
    u32 savedD4;
    u32 savedD7;

    savedD4 = reg_d4.w;
    savedD7 = reg_d7.w;
    savedA0 = reg_a0;
    sprite_zoom_prepare_regs();

    reg_a0 = g_sprite_layer1_buf;
    reg_a0 += g_sprite_layer1_used;
    sprite_entry_from_regs_zoomed();

    reg_d4.w = savedD4;
    reg_d7.w = savedD7;
    reg_a0 = savedA0;
    g_sprite_layer1_used += 0xC;
}

void sprite_draw_layer2_zoom_keep(void)
{
    u8 *savedAddress;
    u32 savedD4;
    u32 savedD7;

    savedD4 = reg_d4.w;
    savedD7 = reg_d7.w;
    savedAddress = reg_a0;
    sprite_zoom_prepare_regs();

    reg_a0 = g_sprite_layer2_buf;
    reg_a0 += g_sprite_layer2_used;
    sprite_entry_from_regs_zoomed();

    reg_d4.w = savedD4;
    reg_d7.w = savedD7;
    reg_a0 = savedAddress;
    g_sprite_layer2_used += 0xC;
}

void sprite_draw_layer3_zoom_keep(void)
{
    u8 *saved_a0;
    u32 saved_d4;
    u32 saved_d7;

    saved_d4 = reg_d4.w;
    saved_d7 = reg_d7.w;
    saved_a0 = reg_a0;

    sprite_zoom_prepare_regs();
    reg_a0 = g_sprite_layer3_buf;
    reg_a0 += g_sprite_layer3_used;
    sprite_entry_from_regs_zoomed();

    reg_d4.w = saved_d4;
    reg_d7.w = saved_d7;
    reg_a0 = saved_a0;
    g_sprite_layer3_used += 0xC;
}

void sprite_draw_layer4_zoom_keep(void)
{
    u8 *savedAddress;
    u32 savedD4;
    u32 savedD7;

    savedD4 = reg_d4.w;
    savedD7 = reg_d7.w;
    savedAddress = reg_a0;

    sprite_zoom_prepare_regs();
    reg_a0 = g_sprite_layer4_buf;
    reg_a0 += g_sprite_layer4_used;
    sprite_entry_from_regs_zoomed();

    reg_d4.w = savedD4;
    reg_d7.w = savedD7;
    reg_a0 = savedAddress;
    g_sprite_layer4_used += 0xC;
}

void sprite_draw_layer5_zoom_keep(void)
{
    u8 *saved_a0;
    u32 saved_d4;
    u32 saved_d7;

    saved_d4 = reg_d4.w;
    saved_d7 = reg_d7.w;
    saved_a0 = reg_a0;

    sprite_zoom_prepare_regs();
    reg_a0 = g_sprite_layer5_buf;
    reg_a0 += g_sprite_layer5_used;
    sprite_entry_from_regs_zoomed();

    reg_d4.w = saved_d4;
    reg_d7.w = saved_d7;
    reg_a0 = saved_a0;
    g_sprite_layer5_used += 0xC;
}

void func_0019CAC0(void) {
}

void func_0019CAD0(void) {
    u32 half = *(u16 *)&reg_d1;
    *(u16 *)&reg_d1 = (u16)(half << 1);
}

void func_0019CAE0(void) {
    reg_d0.h[0] = reg_d1.h[0];
    reg_d1.h[0] *= 3;
}

extern Reg32 reg_d1;

void func_0019CB00(void) {
    u32 value = *(u16 *)&reg_d1;
    *(u16 *)&reg_d1 = value << 2;
}

void func_0019CB10(void) {
    reg_d0.h[0] = reg_d1.h[0];
    reg_d1.h[0] *= 5;
}

void func_0019CB30(void) {
    reg_d1.h[0] *= 6;
}

void func_0019CB50(void) {
    reg_d1.h[0] *= 7;
}

void func_0019CB70(void) {
    u16 value = *(u16 *)&reg_d1;
    *(u16 *)&reg_d1 = (u16)((u32)value << 3);
}

void func_0019CB80(void) {
    reg_d1.h[0] *= 9;
}

void func_0019CBA0(void) {
    reg_d1.h[0] *= 0xA;
}

void func_0019CBC0(void) {
    reg_d1.h[0] *= 0xB;
}

void func_0019CBE0(void) {
    reg_d1.h[0] *= 0xC;
}

void func_0019CC00(void) {
    reg_d1.h[0] *= 0xD;
}

void func_0019CC20(void) {
    reg_d1.h[0] *= 0xE;
}

void func_0019CC40(void) {
    reg_d1.h[0] *= 0xF;
}

void func_0019CC60(void) {
    u32 v = *(u16 *)&reg_d1;
    *(u16 *)&reg_d1 = v << 4;
}

void func_0019CC70(void) {
    reg_d1.h[0] *= 0x11;
}

void func_0019CC90(void) {
    reg_d1.h[0] *= 0x12;
}

void func_0019CCB0(void) {
    reg_d1.h[0] *= 0x13;
}

void func_0019CCD0(void) {
    reg_d1.h[0] *= 0x14;
}

void func_0019CCF0(void) {
    reg_d1.h[0] *= 0x15;
}

void func_0019CD10(void) {
    reg_d1.h[0] *= 0x16;
}

void func_0019CD30(void) {
    reg_d1.h[0] *= 0x17;
}

void func_0019CD50(void) {
    reg_d1.h[0] *= 0x18;
}

void func_0019CD70(void) {
    reg_d1.h[0] *= 0x19;
}

void func_0019CD90(void) {
    reg_d1.h[0] *= 0x1A;
}

void func_0019CDB0(void) {
    reg_d1.h[0] *= 0x1B;
}

void func_0019CDD0(void) {
    reg_d1.h[0] *= 0x1C;
}

void func_0019CDF0(void) {
    reg_d1.h[0] *= 0x1D;
}

void func_0019CE10(void) {
    reg_d1.h[0] *= 0x1E;
}

void func_0019CE30(void) {
    reg_d1.h[0] *= 0x1F;
}

void func_0019CE50(void) {
}

void func_0019CE60(void) {
    u32 value = reg_d7.h[0];
    reg_d7.h[0] = (u16)(value << 1);
}

void func_0019CE70(void) {
    reg_d7.h[0] *= 3;
}

void func_0019CE90(void) {
    reg_d7.h[0] = (u16)((u32)reg_d7.h[0] << 2);
}

void func_0019CEA0(void) {
    reg_d7.h[0] *= 5;
}

void func_0019CEC0(void) {
    reg_d7.h[0] *= 6;
}

void func_0019CEE0(void) {
    reg_d7.h[0] *= 7;
}

void func_0019CF00(void) {
    reg_d7.h[0] = (u16)((u32)reg_d7.h[0] << 3);
}

void func_0019CF10(void) {
    reg_d7.h[0] *= 9;
}

void func_0019CF30(void) {
    reg_d7.h[0] *= 0xA;
}

void func_0019CF50(void) {
    reg_d7.h[0] *= 0xB;
}

void func_0019CF70(void) {
    reg_d7.h[0] *= 0xC;
}

void func_0019CF90(void) {
    reg_d7.h[0] *= 0xD;
}

void func_0019CFB0(void) {
    reg_d7.h[0] *= 0xE;
}

void func_0019CFD0(void) {
    reg_d7.h[0] *= 0xF;
}

void func_0019CFF0(void) {
    u32 value = (u16)reg_d7.h[0];
    reg_d7.h[0] = (u16)(value << 4);
}

void func_0019D000(void) {
    reg_d7.h[0] *= 0x11;
}

void func_0019D020(void) {
    reg_d7.h[0] *= 0x12;
}

void func_0019D040(void) {
    reg_d7.h[0] *= 0x13;
}

void func_0019D060(void) {
    reg_d7.h[0] *= 0x14;
}

void func_0019D080(void) {
    reg_d7.h[0] *= 0x15;
}

void func_0019D0A0(void) {
    reg_d7.h[0] *= 0x16;
}

void func_0019D0C0(void) {
    reg_d7.h[0] *= 0x17;
}

void func_0019D0E0(void) {
    reg_d7.h[0] *= 0x18;
}

void func_0019D100(void) {
    reg_d7.h[0] *= 0x19;
}

void func_0019D120(void) {
    reg_d7.h[0] *= 0x1A;
}

void func_0019D140(void) {
    reg_d7.h[0] *= 0x1B;
}

void func_0019D160(void) {
    reg_d7.h[0] *= 0x1C;
}

void func_0019D180(void) {
    reg_d7.h[0] *= 0x1D;
}

void func_0019D1A0(void) {
    reg_d7.h[0] *= 0x1E;
}

void func_0019D1C0(void) {
    reg_d7.h[0] *= 0x1F;
}

void func_0019D1E0(void) {
    reg_d7.h[0] *= 0x38;
}

void sprite_items_take_entry(void) {
    u32 old_value;

    reg_a0 = g_sprite_items_buf;
    old_value = g_sprite_items_used;
    reg_a0 += old_value;
    g_sprite_items_used = old_value + 0xC;
}


void sprite_draw_with_items(void) {
    sprite_items_take_entry();
    sprite_entry_from_regs();
}

void sprite_special_items_take_entry(void) {
    u8 *base;
    s32 step;

    base = g_sprite_special_items_buf;
    reg_a0 = base;
    step = g_sprite_special_items_used;
    reg_a0 += step;
    g_sprite_special_items_used = step + 0xC;
}


void entity_draw_with_special_items(void) {
    sprite_special_items_take_entry();
    sprite_entry_from_entity();
}

void sprite_draw_with_special_items(void) {
    sprite_special_items_take_entry();
    sprite_entry_from_regs();
}


void sprite_draw_with_special_items_keep(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = (s32)reg_a0;
    temp_s1 = reg_d0.w;
    sprite_special_items_take_entry();
    sprite_entry_from_regs();
    reg_d0.w = temp_s1;
    reg_a0 = (u8 *)temp_s0;
}

void sprite_player_shadows_take_entry(void) {
    u8 *base;
    s32 step;

    base = g_sprite_player_shadows_buf;
    reg_a0 = base;
    step = g_sprite_player_shadows_used;
    reg_a0 += step;
    g_sprite_player_shadows_used = step + 0xC;
}


void sprite_draw_with_player_shadows(void) {
    sprite_player_shadows_take_entry();
    sprite_entry_from_regs();
}

void sprite_draw_with_player_shadows_keep(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = (s32)reg_a0;
    temp_s1 = reg_d0.w;
    sprite_player_shadows_take_entry();
    sprite_entry_from_regs();
    reg_d0.w = temp_s1;
    reg_a0 = (u8 *)temp_s0;
}

void sprite_players_take_entry(void) {
    u8 *base;
    s32 step;

    base = g_sprite_players_buf;
    reg_a0 = base;
    step = g_sprite_players_used;
    reg_a0 += step;
    g_sprite_players_used = step + 0xC;
}


void entity_draw_with_players(void) {
    sprite_players_take_entry();
    sprite_entry_from_entity();
}

void sprite_draw_with_players(void) {
    sprite_players_take_entry();
    sprite_entry_from_regs();
}

void sprite_draw_with_players_keep(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = (s32)reg_a0;
    temp_s1 = reg_d0.w;
    sprite_players_take_entry();
    sprite_entry_from_regs();
    reg_d0.w = temp_s1;
    reg_a0 = (u8 *)temp_s0;
}

void sprite_options_take_entry(void) {
    u8 *base;
    s32 step;

    base = g_sprite_options_buf;
    reg_a0 = base;
    step = g_sprite_options_used;
    reg_a0 += step;
    g_sprite_options_used = step + 0xC;
}


void entity_draw_with_options(void) {
    sprite_options_take_entry();
    sprite_entry_from_entity();
}

void sprite_player_shots_take_entry(void) {
    u8 *base;
    s32 step;

    base = g_sprite_player_shots_buf;
    reg_a0 = base;
    step = g_sprite_player_shots_used;
    reg_a0 += step;
    g_sprite_player_shots_used = step + 0xC;
}


void entity_draw_with_player_shots(void) {
    sprite_player_shots_take_entry();
    sprite_entry_from_entity();
}


void entity_draw_with_player_shots_zoom(void) {
    sprite_zoom_prepare_entity();
    sprite_player_shots_take_entry();
    sprite_entry_from_entity_zoomed();
}

void sprite_player_lasers_take_entry(void) {
    u8 *base;
    s32 step;

    base = g_sprite_player_lasers_buf;
    reg_a0 = base;
    step = g_sprite_player_lasers_used;
    reg_a0 += step;
    g_sprite_player_lasers_used = step + 0xC;
}


void entity_draw_with_player_lasers(void) {
    sprite_player_lasers_take_entry();
    sprite_entry_from_entity();
}

void sprite_bullets_take_entry(void) {
    u32 offset;

    reg_a0 = g_sprite_bullets_buf;
    offset = g_sprite_bullets_used;
    reg_a0 += offset;
    g_sprite_bullets_used = offset + 0xC;
}


void entity_draw_with_bullets(void) {
    sprite_bullets_take_entry();
    sprite_entry_from_entity();
}


void entity_draw_with_bullets_keep(void)
{
    s32 saved_a0;
    s32 saved_a1;
    u32 saved_d0;

    saved_d0 = reg_d0.w;
    saved_a0 = (s32)reg_a0;
    saved_a1 = (s32)reg_a1;

    sprite_bullets_take_entry();
    sprite_entry_from_entity();

    reg_d0.w = saved_d0;
    reg_a0 = (u8 *)saved_a0;
    reg_a1 = (u8 *)saved_a1;
}

void sprite_draw_with_bullets(void) {
    sprite_bullets_take_entry();
    sprite_entry_from_regs();
}

void sprite_draw_with_bullets_keep(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = (s32)reg_a0;
    temp_s1 = reg_d0.w;
    sprite_bullets_take_entry();
    sprite_entry_from_regs();
    reg_d0.w = temp_s1;
    reg_a0 = (u8 *)temp_s0;
}


void sprite_draw_with_bullets_zoom(void) {
    sprite_zoom_prepare_regs();
    sprite_bullets_take_entry();
    sprite_entry_from_regs_zoomed();
}

extern u16 g_sprite_warning_used;
extern u8 g_sprite_warning_buf[];

void sprite_warning_take_entry(void) {
    u8 *base;
    s32 step;

    base = g_sprite_warning_buf;
    reg_a0 = base;
    step = g_sprite_warning_used;
    reg_a0 += step;
    g_sprite_warning_used = step + 0xC;
}


void entity_draw_with_warning(void) {
    sprite_warning_take_entry();
    sprite_entry_from_entity();
}

void sprite_draw_with_warning_keep(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = (s32)reg_a0;
    temp_s1 = reg_d0.w;
    sprite_warning_take_entry();
    sprite_entry_from_regs();
    reg_d0.w = temp_s1;
    reg_a0 = (u8 *)temp_s0;
}

extern u16 g_sprite_score_used;
extern u8 g_sprite_score_buf[];

void sprite_score_take_entry(void) {
    u32 counter;

    reg_a0 = g_sprite_score_buf;
    counter = g_sprite_score_used;
    reg_a0 += counter;
    g_sprite_score_used = counter + 0xC;
}


void sprite_draw_with_score(void) {
    sprite_score_take_entry();
    sprite_entry_from_regs();
}

void sprite_draw_with_score_keep(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = (s32)reg_a0;
    temp_s1 = reg_d0.w;
    sprite_score_take_entry();
    sprite_entry_from_regs();
    reg_d0.w = temp_s1;
    reg_a0 = (u8 *)temp_s0;
}

extern u16 g_sprite_laser_trail_used;
extern u8 g_sprite_laser_trail_buf[];

void sprite_laser_trail_take_entry(void) {
    u32 temp;

    reg_a0 = g_sprite_laser_trail_buf;
    temp = g_sprite_laser_trail_used;
    reg_a0 += temp;
    g_sprite_laser_trail_used = temp + 0xC;
}


void sprite_draw_with_laser_trail_keep(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = (s32)reg_a0;
    temp_s1 = reg_d0.w;
    sprite_laser_trail_take_entry();
    sprite_entry_from_regs();
    reg_d0.w = temp_s1;
    reg_a0 = (u8 *)temp_s0;
}

extern u16 g_sprite_last_boss_used;
extern u8 g_sprite_last_boss_buf[];
void sprite_last_boss_take_entry(void) {
    u8 *base;
    s32 step;

    base = g_sprite_last_boss_buf;
    reg_a0 = base;
    step = g_sprite_last_boss_used;
    reg_a0 += step;
    g_sprite_last_boss_used = step + 0xC;
}


void sprite_draw_with_last_boss_keep(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = (s32)reg_a0;
    temp_s1 = reg_d0.w;
    sprite_last_boss_take_entry();
    sprite_entry_from_regs();
    reg_d0.w = temp_s1;
    reg_a0 = (u8 *)temp_s0;
}

extern u16 g_sprite_bombs_used;
extern u8 g_sprite_bombs_buf[];
void sprite_bombs_take_entry(void) {
    s32 step; reg_a0 = g_sprite_bombs_buf; step = g_sprite_bombs_used; reg_a0 += step; g_sprite_bombs_used = step + 0xC;
}


void entity_draw_with_bombs(void) {
    sprite_bombs_take_entry();
    sprite_entry_from_entity();
}



void entity_draw_with_bombs_keep(void)
{
    extern void sprite_entry_from_entity(void);
    s32 saved_a0;
    s32 saved_a1;
    u32 saved_d0;

    saved_d0 = reg_d0.w;
    saved_a0 = (s32)reg_a0;
    saved_a1 = (s32)reg_a1;
    sprite_bombs_take_entry();
    sprite_entry_from_entity();
    reg_d0.w = saved_d0;
    reg_a0 = (u8 *)saved_a0;
    reg_a1 = (u8 *)saved_a1;
}

void sprite_draw_with_bombs_keep(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = (s32)reg_a0;
    temp_s1 = reg_d0.w;
    sprite_bombs_take_entry();
    sprite_entry_from_regs();
    reg_d0.w = temp_s1;
    reg_a0 = (u8 *)temp_s0;
}

extern u16 g_sprite_ship_select_used;
extern u8 g_sprite_ship_select_buf[];

void sprite_ship_select_take_entry(void) {
    u32 offset;
    u8 *cursor;

    reg_a0 = g_sprite_ship_select_buf;
    offset = g_sprite_ship_select_used;
    cursor = reg_a0;
    reg_a0 = cursor + offset;
    g_sprite_ship_select_used = offset + 0xC;
}


void sprite_draw_with_ship_select_keep(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = (s32)reg_a0;
    temp_s1 = reg_d0.w;
    sprite_ship_select_take_entry();
    sprite_entry_from_regs();
    reg_d0.w = temp_s1;
    reg_a0 = (u8 *)temp_s0;
}

extern u16 g_sprite_maximum_used;
extern u8 g_sprite_maximum_buf[];

void sprite_maximum_take_entry(void) {
    u32 offset;

    reg_a0 = g_sprite_maximum_buf;
    offset = g_sprite_maximum_used;
    reg_a0 += offset;
    g_sprite_maximum_used = offset + 0xC;
}


void sprite_draw_with_maximum(void) {
    sprite_maximum_take_entry();
    sprite_entry_from_regs();
}

extern u16 g_sprite_hyper_ready_used;
extern u8 g_sprite_hyper_ready_buf[];

void sprite_hyper_ready_take_entry(void) {
    u8 *base;
    s32 step;

    base = g_sprite_hyper_ready_buf;
    reg_a0 = base;
    step = g_sprite_hyper_ready_used;
    reg_a0 += step;
    g_sprite_hyper_ready_used = step + 0xC;
}


void sprite_draw_with_hyper_ready(void) {
    sprite_hyper_ready_take_entry();
    sprite_entry_from_regs();
}

extern u16 g_sprite_hyper_display_used;
extern u8 g_sprite_hyper_display_buf[];

void sprite_hyper_display_take_entry(void) {
    u32 temp;

    reg_a0 = g_sprite_hyper_display_buf;
    temp = g_sprite_hyper_display_used;
    reg_a0 += temp;
    g_sprite_hyper_display_used = temp + 0xC;
}


void sprite_draw_with_hyper_display(void) {
    sprite_hyper_display_take_entry();
    sprite_entry_from_regs();
}

void sprite_draw_with_hyper_display_keep(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = (s32)reg_a0;
    temp_s1 = reg_d0.w;
    sprite_hyper_display_take_entry();
    sprite_entry_from_regs();
    reg_d0.w = temp_s1;
    reg_a0 = (u8 *)temp_s0;
}
