#include "common.h"
#include "black_label.h"
#include "entity.h"

void sprite_list_emit(void);

extern u16 g_sprite_unused_count;
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
extern u16 g_sprite_extra_used;
extern u16 g_sprite_layer5_used;
extern u16 g_sprite_layer4_used;
extern u16 g_sprite_layer3_used;
extern u16 g_sprite_layer2_used;
extern u16 g_sprite_layer1_used;

void sprite_lists_reset(void) {
    g_sprite_layer1_used = 0;
    g_sprite_layer2_used = 0;
    g_sprite_layer3_used = 0;
    g_sprite_layer4_used = 0;
    g_sprite_layer5_used = 0;
    g_sprite_extra_used = 0;
    g_sprite_special_items_used = 0;
    g_sprite_items_first_used = 0;
    g_sprite_items_used = 0;
    g_sprite_player_shadows_used = 0;
    g_sprite_debris1_used = 0;
    g_sprite_debris2_used = 0;
    g_sprite_sparks_used = 0;
    g_sprite_bullets_used = 0;
    g_sprite_bullets2_used = 0;
    g_sprite_player_shots_used = 0;
    g_sprite_player_lasers_used = 0;
    g_sprite_options_used = 0;
    g_sprite_players_used = 0;
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
    g_sprite_unused_count = 0;
}


s32 display_control_bit_0_on();
s32 display_control_bit_0_off();
extern s16 g_sprite_debris_dropped;
extern s16 g_sprite_sparks_dropped;
extern u16 g_sprite_overflow_bytes;
extern u16 g_sprite_overflow_count;
extern u16 g_sprite_unused_count;
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
extern u16 g_sprite_extra_used;
extern u16 g_sprite_layer5_used;
extern u16 g_sprite_layer4_used;
extern u16 g_sprite_layer3_used;
extern u16 g_sprite_layer2_used;
extern u16 g_sprite_layer1_used;
extern u8 g_setting_hitbox_bullets_shown;
extern u8 g_setting_hitbox_display;
extern u8 g_sprite_last_boss_buf[];
extern u8 g_sprite_laser_trail_buf[];
extern u8 g_sprite_hyper_display_buf[];
extern u8 g_sprite_hyper_ready_buf[];
extern u8 g_sprite_maximum_buf[];
extern u8 g_sprite_stage_clear2_buf[];
extern u8 g_sprite_stage_clear1_buf[];
extern u8 g_sprite_ship_select_buf[];
extern u8 g_sprite_bombs_buf[];
extern u8 g_sprite_sight_buf[];
extern u8 g_sprite_score_buf[];
extern u8 g_sprite_warning_buf[];
extern u8 g_sprite_bullets2_buf[];
extern u8 g_sprite_bullets_buf[];
extern u8 g_sprite_sparks_buf[];
extern u8 g_sprite_players_buf[];
extern u8 g_sprite_options_buf[];
extern u8 g_sprite_player_lasers_buf[];
extern u8 g_sprite_player_shots_buf[];
extern u8 g_sprite_debris2_buf[];
extern u8 g_sprite_debris1_buf[];
extern u8 g_sprite_player_shadows_buf[];
extern u8 g_sprite_items_buf[];
extern u8 g_sprite_items_first_buf[];
extern u8 g_sprite_special_items_buf[];
extern u8 g_sprite_extra_buf[];
extern u8 g_sprite_layer5_buf[];
extern u8 g_sprite_layer4_buf[];
extern u8 g_sprite_layer3_buf[];
extern u8 g_sprite_layer2_buf[];
extern u8 g_sprite_layer1_buf[];
extern u8 g_arcade_sprites[];

void sprite_lists_build(void) {
    u16 count;
    u8 bits;

    display_control_bit_0_off();
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
    if ((g_setting_hitbox_display == 0) || (g_setting_hitbox_bullets_shown == 0)) {
        reg_d0.h[0] += g_sprite_bullets_used;
        reg_d0.h[0] += g_sprite_bullets2_used;
    }
    if (g_setting_hitbox_display != 0) {
        reg_d0.h[0] += g_sprite_extra_used;
    }
    reg_d0.h[0] += g_sprite_warning_used;
    g_sprite_sparks_dropped = 0;
    reg_d0.h[0] += g_sprite_score_used;
    g_sprite_debris_dropped = 0;
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
    g_sprite_overflow_bytes = reg_d0.h[0];
    reg_d0.h[0] /= 0xC;
    g_sprite_overflow_count = reg_d0.h[0];
    if ((s16)(g_sprite_overflow_bytes) >= 0) {
        reg_d0.h[0] = g_sprite_sparks_used;
        g_sprite_sparks_used = 0;
        g_sprite_overflow_bytes -= reg_d0.h[0];
        g_sprite_sparks_dropped = 1;
        if ((s16) g_sprite_overflow_bytes >= 0) {
            g_sprite_debris_dropped = 1;
            g_sprite_debris1_used = 0;
            g_sprite_debris2_used = 0;
        }
    }
    reg_a0 = (u8 *)g_sprite_layer2_buf;
    reg_a1 = (u8 *)(&g_sprite_layer2_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_layer3_buf;
    reg_a1 = (u8 *)(&g_sprite_layer3_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_layer4_buf;
    reg_a1 = (u8 *)(&g_sprite_layer4_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_items_first_buf;
    reg_a1 = (u8 *)(&g_sprite_items_first_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_player_shadows_buf;
    reg_a1 = (u8 *)(&g_sprite_player_shadows_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_debris1_buf;
    reg_a1 = (u8 *)(&g_sprite_debris1_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_layer5_buf;
    reg_a1 = (u8 *)(&g_sprite_layer5_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_special_items_buf;
    reg_a1 = (u8 *)(&g_sprite_special_items_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_debris2_buf;
    reg_a1 = (u8 *)(&g_sprite_debris2_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_sight_buf;
    reg_a1 = (u8 *)(&g_sprite_sight_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_stage_clear1_buf;
    reg_a1 = (u8 *)(&g_sprite_stage_clear1_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_laser_trail_buf;
    reg_a1 = (u8 *)(&g_sprite_laser_trail_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_bombs_buf;
    reg_a1 = (u8 *)(&g_sprite_bombs_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_player_shots_buf;
    reg_a1 = (u8 *)(&g_sprite_player_shots_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_options_buf;
    reg_a1 = (u8 *)(&g_sprite_options_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_player_lasers_buf;
    reg_a1 = (u8 *)(&g_sprite_player_lasers_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_items_buf;
    reg_a1 = (u8 *)(&g_sprite_items_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_hyper_display_buf;
    reg_a1 = (u8 *)(&g_sprite_hyper_display_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_players_buf;
    reg_a1 = (u8 *)(&g_sprite_players_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_sparks_buf;
    reg_a1 = (u8 *)(&g_sprite_sparks_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_warning_buf;
    reg_a1 = (u8 *)(&g_sprite_warning_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    if (g_setting_hitbox_display == 0) goto next_30;
    if (g_setting_hitbox_bullets_shown != 0) goto next_32;
next_30:
    reg_a0 = (u8 *)g_sprite_bullets_buf;
    reg_a1 = (u8 *)(&g_sprite_bullets_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
next_32:
    if (g_setting_hitbox_display == 0) goto next_34;
    if (g_setting_hitbox_bullets_shown != 0) goto next_36;
next_34:
    reg_a0 = (u8 *)g_sprite_bullets2_buf;
    reg_a1 = (u8 *)(&g_sprite_bullets2_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
next_36:
    if (g_setting_hitbox_display == 0) goto next_40;
    reg_a0 = (u8 *)g_sprite_extra_buf;
    reg_a1 = (u8 *)(&g_sprite_extra_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
next_40:
    reg_a0 = (u8 *)g_sprite_last_boss_buf;
    reg_a1 = (u8 *)(&g_sprite_last_boss_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_score_buf;
    reg_a1 = (u8 *)(&g_sprite_score_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_ship_select_buf;
    reg_a1 = (u8 *)(&g_sprite_ship_select_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_stage_clear2_buf;
    reg_a1 = (u8 *)(&g_sprite_stage_clear2_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_maximum_buf;
    reg_a1 = (u8 *)(&g_sprite_maximum_used);
    sprite_list_emit();
    if (cond_flag != 0) goto next_50;
    reg_a0 = (u8 *)g_sprite_hyper_ready_buf;
    reg_a1 = (u8 *)(&g_sprite_hyper_ready_used);
    sprite_list_emit();
next_50:
    count = g_sprite_layer1_used;
    reg_a0 = (u8 *)g_arcade_sprites;
    reg_d7.h[0] = g_sprite_unused_count;
    reg_d1.h[0] = 0xA;
    reg_d0.h[0] = count;
    g_sprite_unused_count = count;
    reg_d3.h[0] = count;
    reg_d7.h[0] -= count;
    if (reg_d0.h[0] != 0) {
        reg_a1 = (u8 *)(((u16 *)g_sprite_layer1_buf));
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
                reg_tmp.w = GAME_RULE(0xFBFFFC00, 0xFC003800);
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
#ifdef DDPDOJ_BONUS_FEATURES
            if (g_black_label_active) {
                u32 pos = ((u32)*(u16 *)reg_a1 << 16) | *(u16 *)(reg_a1 + 2);
                u32 shake = ((u32)(u16)g_boss_shake_y << 16) | (u16)g_boss_shake_x;
                pos = (pos & 0xF800F800) | (((pos & 0x07FF3FFF) + shake) & 0x07FF3FFF);
                *(u16 *)reg_a0 = pos >> 16;
                *(u16 *)(reg_a0 + 2) = pos;
                reg_a0 += 4;
                reg_a1 += 4;
            } else
#endif
            {
                *(u16 *)reg_a0 = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                reg_a0 += 2;
                *(u16 *)reg_a0 = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                reg_a0 += 2;
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
    display_control_bit_0_on();
}



void sprite_list_emit(void) {
    cond_flag = 0;
    reg_d0.h[0] = *(u16 *)reg_a1;
    switch (reg_d0.h[0]) {
    case 0:
        goto block_rts;
    default:
        reg_a2 = (u8 *)((u16 *)g_sprite_layer1_buf);
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

extern Fn multiply_d1_routines[64];

void sprite_zoom_prepare_entity(void) {
    u32 k;
    u16 t;

    k = 0xFFFF;
    reg_a0 = (u8 *)multiply_d1_routines;
    reg_d1.w = reg_d6.w;
    reg_d1.w = (u32) reg_d1.w >> 8;
    reg_d1.h[0] *= (u16)k;
    reg_d1.h[0] += 0x80;
    reg_d0.h[0] = ENTITY(reg_a6)->look.h;
    reg_d0.h[0] &= 0x1FF;
    reg_d0.h[0] >>= 1;
    reg_call_target = multiply_d1_routines[reg_d0.h[0] >> 2];
    reg_call_target();
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_a0 = (u8 *)multiply_d1_routines;
    reg_d0.w = 0x3E;
    t = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = t;
    reg_d1.h[0] *= 0xFFFF;
    reg_d1.h[0] += 0x80;
    reg_d0.b[0] &= ENTITY(reg_a6)->look.b.size;
    reg_d0.h[0] *= 4;
    reg_call_target = multiply_d1_routines[reg_d0.h[0] >> 2];
    reg_call_target();
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


void sprite_entry_from_regs(void) {
    reg_d0.w = reg_d1.w;
    reg_d0.w = (u32) ((s32) reg_d0.w >> 6);
    reg_d0.w &= 0x07FF03FF;
    reg_d0.w |= 0x80008000;
    *(*(u16 **)&reg_a0) = reg_d0.h[1];
    (*(u16 **)&reg_a0) += 1;
    *(*(u16 **)&reg_a0) = reg_d0.h[0];
    (*(u16 **)&reg_a0) += 1;
    *(*(u16 **)&reg_a0) = reg_d2.h[1];
    (*(u16 **)&reg_a0) += 1;
    *(*(u16 **)&reg_a0) = reg_d2.h[0];
    (*(u16 **)&reg_a0) += 1;
    *(*(u16 **)&reg_a0) = reg_d3.h[0];
    (*(u16 **)&reg_a0) += 1;
    *(*(u16 **)&reg_a0) = reg_d4.h[0];
    (*(u16 **)&reg_a0) += 1;
}

#ifdef DDPDOJ_PC
extern Fn multiply_d7_routines[64];
#else
extern u8 multiply_d7_routines[];
#endif

void sprite_zoom_prepare_regs(void) {
    u16 t;
#ifndef DDPDOJ_PC
    Fn *entry;
#endif

    reg_a0 = (u8 *)multiply_d7_routines;
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
#ifdef DDPDOJ_PC
    reg_call_target = multiply_d7_routines[reg_d4.h[0] >> 2];
#else
    reg_call_target = *(entry = (Fn *)(multiply_d7_routines + (reg_d4.h[0] & ~3)));
#endif
    reg_call_target();
    reg_tmp7.h[0] = reg_d7.h[0];
    reg_a0 = (u8 *)multiply_d7_routines;
    t = reg_d7.h[1];
    reg_d7.h[1] = reg_tmp7.h[0];
    reg_d7.h[0] = t;
    reg_d7.h[0] *= 0xFFFF;
    reg_d7.h[0] += 0x80;
    reg_d4.h[0] = reg_d3.h[0];
    reg_d4.h[0] &= 0x3E00;
    reg_d4.h[0] >>= 6;
#ifdef DDPDOJ_PC
    reg_call_target = multiply_d7_routines[reg_d4.h[0] >> 2];
#else
    reg_call_target = *(entry = (Fn *)(multiply_d7_routines + (reg_d4.h[0] & ~3)));
#endif
    reg_call_target();
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
    ArcadeSavedAddress temp_s2;
    u32 temp_s0;

    temp_s1 = reg_a0;
    temp_s0 = reg_d0.w;
    temp_s2 = (ArcadeSavedAddress)reg_a1;
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
    ArcadeSavedAddress temp_s2;
    u32 temp_s0;

    temp_s1 = reg_a0;
    temp_s0 = reg_d0.w;
    temp_s2 = (ArcadeSavedAddress)reg_a1;
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
    ArcadeSavedAddress temp_s2;
    u32 temp_s0;

    temp_s1 = reg_a0;
    temp_s0 = reg_d0.w;
    temp_s2 = (ArcadeSavedAddress)reg_a1;
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
    ArcadeSavedAddress temp_s2;
    u32 temp_s0;

    temp_s1 = reg_a0;
    temp_s0 = reg_d0.w;
    temp_s2 = (ArcadeSavedAddress)reg_a1;
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
    ArcadeSavedAddress temp_s2;
    u32 temp_s0;

    temp_s1 = reg_a0;
    temp_s0 = reg_d0.w;
    temp_s2 = (ArcadeSavedAddress)reg_a1;
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
    ArcadeSavedAddress temp_s2;
    u32 temp_s0;

    temp_s1 = reg_a0;
    temp_s0 = reg_d0.w;
    temp_s2 = (ArcadeSavedAddress)reg_a1;
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

void multiply_d1_by_1(void) {
}

void multiply_d1_by_2(void) {
    u32 half = *(u16 *)&reg_d1;
    *(u16 *)&reg_d1 = (u16)(half << 1);
}

void multiply_d1_by_3(void) {
    reg_d0.h[0] = reg_d1.h[0];
    reg_d1.h[0] *= 3;
}

extern Reg32 reg_d1;

void multiply_d1_by_4(void) {
    u32 value = *(u16 *)&reg_d1;
    *(u16 *)&reg_d1 = value << 2;
}

void multiply_d1_by_5(void) {
    reg_d0.h[0] = reg_d1.h[0];
    reg_d1.h[0] *= 5;
}

void multiply_d1_by_6(void) {
    reg_d1.h[0] *= 6;
}

void multiply_d1_by_7(void) {
    reg_d1.h[0] *= 7;
}

void multiply_d1_by_8(void) {
    u16 value = *(u16 *)&reg_d1;
    *(u16 *)&reg_d1 = (u16)((u32)value << 3);
}

void multiply_d1_by_9(void) {
    reg_d1.h[0] *= 9;
}

void multiply_d1_by_10(void) {
    reg_d1.h[0] *= 0xA;
}

void multiply_d1_by_11(void) {
    reg_d1.h[0] *= 0xB;
}

void multiply_d1_by_12(void) {
    reg_d1.h[0] *= 0xC;
}

void multiply_d1_by_13(void) {
    reg_d1.h[0] *= 0xD;
}

void multiply_d1_by_14(void) {
    reg_d1.h[0] *= 0xE;
}

void multiply_d1_by_15(void) {
    reg_d1.h[0] *= 0xF;
}

void multiply_d1_by_16(void) {
    u32 v = *(u16 *)&reg_d1;
    *(u16 *)&reg_d1 = v << 4;
}

void multiply_d1_by_17(void) {
    reg_d1.h[0] *= 0x11;
}

void multiply_d1_by_18(void) {
    reg_d1.h[0] *= 0x12;
}

void multiply_d1_by_19(void) {
    reg_d1.h[0] *= 0x13;
}

void multiply_d1_by_20(void) {
    reg_d1.h[0] *= 0x14;
}

void multiply_d1_by_21(void) {
    reg_d1.h[0] *= 0x15;
}

void multiply_d1_by_22(void) {
    reg_d1.h[0] *= 0x16;
}

void multiply_d1_by_23(void) {
    reg_d1.h[0] *= 0x17;
}

void multiply_d1_by_24(void) {
    reg_d1.h[0] *= 0x18;
}

void multiply_d1_by_25(void) {
    reg_d1.h[0] *= 0x19;
}

void multiply_d1_by_26(void) {
    reg_d1.h[0] *= 0x1A;
}

void multiply_d1_by_27(void) {
    reg_d1.h[0] *= 0x1B;
}

void multiply_d1_by_28(void) {
    reg_d1.h[0] *= 0x1C;
}

void multiply_d1_by_29(void) {
    reg_d1.h[0] *= 0x1D;
}

void multiply_d1_by_30(void) {
    reg_d1.h[0] *= 0x1E;
}

void multiply_d1_by_31(void) {
    reg_d1.h[0] *= 0x1F;
}

void multiply_d7_by_1(void) {
}

void multiply_d7_by_2(void) {
    u32 value = reg_d7.h[0];
    reg_d7.h[0] = (u16)(value << 1);
}

void multiply_d7_by_3(void) {
    reg_d7.h[0] *= 3;
}

void multiply_d7_by_4(void) {
    reg_d7.h[0] = (u16)((u32)reg_d7.h[0] << 2);
}

void multiply_d7_by_5(void) {
    reg_d7.h[0] *= 5;
}

void multiply_d7_by_6(void) {
    reg_d7.h[0] *= 6;
}

void multiply_d7_by_7(void) {
    reg_d7.h[0] *= 7;
}

void multiply_d7_by_8(void) {
    reg_d7.h[0] = (u16)((u32)reg_d7.h[0] << 3);
}

void multiply_d7_by_9(void) {
    reg_d7.h[0] *= 9;
}

void multiply_d7_by_10(void) {
    reg_d7.h[0] *= 0xA;
}

void multiply_d7_by_11(void) {
    reg_d7.h[0] *= 0xB;
}

void multiply_d7_by_12(void) {
    reg_d7.h[0] *= 0xC;
}

void multiply_d7_by_13(void) {
    reg_d7.h[0] *= 0xD;
}

void multiply_d7_by_14(void) {
    reg_d7.h[0] *= 0xE;
}

void multiply_d7_by_15(void) {
    reg_d7.h[0] *= 0xF;
}

void multiply_d7_by_16(void) {
    u32 value = (u16)reg_d7.h[0];
    reg_d7.h[0] = (u16)(value << 4);
}

void multiply_d7_by_17(void) {
    reg_d7.h[0] *= 0x11;
}

void multiply_d7_by_18(void) {
    reg_d7.h[0] *= 0x12;
}

void multiply_d7_by_19(void) {
    reg_d7.h[0] *= 0x13;
}

void multiply_d7_by_20(void) {
    reg_d7.h[0] *= 0x14;
}

void multiply_d7_by_21(void) {
    reg_d7.h[0] *= 0x15;
}

void multiply_d7_by_22(void) {
    reg_d7.h[0] *= 0x16;
}

void multiply_d7_by_23(void) {
    reg_d7.h[0] *= 0x17;
}

void multiply_d7_by_24(void) {
    reg_d7.h[0] *= 0x18;
}

void multiply_d7_by_25(void) {
    reg_d7.h[0] *= 0x19;
}

void multiply_d7_by_26(void) {
    reg_d7.h[0] *= 0x1A;
}

void multiply_d7_by_27(void) {
    reg_d7.h[0] *= 0x1B;
}

void multiply_d7_by_28(void) {
    reg_d7.h[0] *= 0x1C;
}

void multiply_d7_by_29(void) {
    reg_d7.h[0] *= 0x1D;
}

void multiply_d7_by_30(void) {
    reg_d7.h[0] *= 0x1E;
}

void multiply_d7_by_31(void) {
    reg_d7.h[0] *= 0x1F;
}

void multiply_d7_by_56(void) {
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
    ArcadeSavedAddress temp_s0;
    u32 temp_s1;

    temp_s0 = (ArcadeSavedAddress)reg_a0;
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
    ArcadeSavedAddress temp_s0;
    u32 temp_s1;

    temp_s0 = (ArcadeSavedAddress)reg_a0;
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
    ArcadeSavedAddress temp_s0;
    u32 temp_s1;

    temp_s0 = (ArcadeSavedAddress)reg_a0;
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
    ArcadeSavedAddress saved_a0;
    ArcadeSavedAddress saved_a1;
    u32 saved_d0;

    saved_d0 = reg_d0.w;
    saved_a0 = (ArcadeSavedAddress)reg_a0;
    saved_a1 = (ArcadeSavedAddress)reg_a1;

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
    ArcadeSavedAddress temp_s0;
    u32 temp_s1;

    temp_s0 = (ArcadeSavedAddress)reg_a0;
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
    ArcadeSavedAddress temp_s0;
    u32 temp_s1;

    temp_s0 = (ArcadeSavedAddress)reg_a0;
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
    ArcadeSavedAddress temp_s0;
    u32 temp_s1;

    temp_s0 = (ArcadeSavedAddress)reg_a0;
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
    ArcadeSavedAddress temp_s0;
    u32 temp_s1;

    temp_s0 = (ArcadeSavedAddress)reg_a0;
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
    ArcadeSavedAddress temp_s0;
    u32 temp_s1;

    temp_s0 = (ArcadeSavedAddress)reg_a0;
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
    ArcadeSavedAddress saved_a0;
    ArcadeSavedAddress saved_a1;
    u32 saved_d0;

    saved_d0 = reg_d0.w;
    saved_a0 = (ArcadeSavedAddress)reg_a0;
    saved_a1 = (ArcadeSavedAddress)reg_a1;
    sprite_bombs_take_entry();
    sprite_entry_from_entity();
    reg_d0.w = saved_d0;
    reg_a0 = (u8 *)saved_a0;
    reg_a1 = (u8 *)saved_a1;
}

void sprite_draw_with_bombs_keep(void) {
    ArcadeSavedAddress temp_s0;
    u32 temp_s1;

    temp_s0 = (ArcadeSavedAddress)reg_a0;
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
    ArcadeSavedAddress temp_s0;
    u32 temp_s1;

    temp_s0 = (ArcadeSavedAddress)reg_a0;
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
    ArcadeSavedAddress temp_s0;
    u32 temp_s1;

    temp_s0 = (ArcadeSavedAddress)reg_a0;
    temp_s1 = reg_d0.w;
    sprite_hyper_display_take_entry();
    sprite_entry_from_regs();
    reg_d0.w = temp_s1;
    reg_a0 = (u8 *)temp_s0;
}

/* .sbss (the compiler lays these out in reverse) */
u16 g_sprite_layer1_used __attribute__((aligned(4)));
u16 g_sprite_layer2_used __attribute__((aligned(4)));
u16 g_sprite_layer3_used __attribute__((aligned(4)));
u16 g_sprite_layer4_used __attribute__((aligned(4)));
u16 g_sprite_layer5_used __attribute__((aligned(4)));
u16 g_sprite_extra_used __attribute__((aligned(4)));
u16 g_sprite_special_items_used __attribute__((aligned(4)));
u16 g_sprite_items_first_used __attribute__((aligned(4)));
u16 g_sprite_items_used __attribute__((aligned(4)));
u16 g_sprite_player_shadows_used __attribute__((aligned(4)));
u16 g_sprite_debris1_used __attribute__((aligned(4)));
u16 g_sprite_debris2_used __attribute__((aligned(4)));
u16 g_sprite_player_shots_used __attribute__((aligned(4)));
u16 g_sprite_player_lasers_used __attribute__((aligned(4)));
u16 g_sprite_options_used __attribute__((aligned(4)));
u16 g_sprite_players_used __attribute__((aligned(4)));
u16 g_sprite_sparks_used __attribute__((aligned(4)));
u16 g_sprite_bullets_used __attribute__((aligned(4)));
u16 g_sprite_bullets2_used __attribute__((aligned(4)));
u16 g_sprite_warning_used __attribute__((aligned(4)));
u16 g_sprite_score_used __attribute__((aligned(4)));
u16 g_sprite_sight_used __attribute__((aligned(4)));
u16 g_sprite_laser_trail_used __attribute__((aligned(4)));
u16 g_sprite_bombs_used __attribute__((aligned(4)));
u16 g_sprite_ship_select_used __attribute__((aligned(4)));
u16 g_sprite_stage_clear1_used __attribute__((aligned(4)));
u16 g_sprite_stage_clear2_used __attribute__((aligned(4)));
u16 g_sprite_maximum_used __attribute__((aligned(4)));
u16 g_sprite_hyper_ready_used __attribute__((aligned(4)));
u16 g_sprite_hyper_display_used __attribute__((aligned(4)));
u16 g_sprite_last_boss_used __attribute__((aligned(4)));
u16 g_sprite_unused_count __attribute__((aligned(4)));
u16 g_sprite_overflow_count __attribute__((aligned(4)));
u16 g_sprite_overflow_bytes __attribute__((aligned(4)));
s16 g_sprite_sparks_dropped __attribute__((aligned(4)));
s16 g_sprite_debris_dropped __attribute__((aligned(4)));

/* .bss (the compiler lays these out in reverse) */
#ifndef DDPDOJ_PC
#ifdef DEATH_LABEL
u8 g_sprite_layer1_buf[28032];
#else
u8 g_sprite_layer1_buf[11952];
#endif
#ifdef DEATH_LABEL
u8 g_sprite_layer2_buf[14016];
#else
u8 g_sprite_layer2_buf[5984];
#endif
#ifdef DEATH_LABEL
u8 g_sprite_layer3_buf[14016];
#else
u8 g_sprite_layer3_buf[5984];
#endif
#ifdef DEATH_LABEL
u8 g_sprite_layer4_buf[14016];
#else
u8 g_sprite_layer4_buf[5984];
#endif
#ifdef DEATH_LABEL
u8 g_sprite_layer5_buf[14016];
#else
u8 g_sprite_layer5_buf[5984];
#endif
#ifdef DEATH_LABEL
u8 g_sprite_extra_buf[28032];
#else
u8 g_sprite_extra_buf[11952];
#endif
u8 g_sprite_special_items_buf[848];
u8 g_sprite_items_first_buf[304];
u8 g_sprite_items_buf[304];
u8 g_sprite_player_shadows_buf[80];
u8 g_sprite_debris1_buf[240];
u8 g_sprite_debris2_buf[240];
u8 g_sprite_player_shots_buf[864];
u8 g_sprite_player_lasers_buf[768];
u8 g_sprite_options_buf[48];
u8 g_sprite_players_buf[192];
u8 g_sprite_sparks_buf[720];
#ifdef DEATH_LABEL
u8 g_sprite_bullets_buf[12608];
#else
u8 g_sprite_bullets_buf[2528];
#endif
#ifdef DEATH_LABEL
u8 g_sprite_bullets2_buf[12608];
#else
u8 g_sprite_bullets2_buf[2528];
#endif
u8 g_sprite_warning_buf[192];
u8 g_sprite_score_buf[384];
u8 g_sprite_sight_buf[128];
u8 g_sprite_bombs_buf[1088];
u8 g_sprite_ship_select_buf[128];
u8 g_sprite_stage_clear1_buf[128];
u8 g_sprite_stage_clear2_buf[128];
u8 g_sprite_maximum_buf[32];
u8 g_sprite_hyper_ready_buf[32];
u8 g_sprite_hyper_display_buf[128];
u8 g_sprite_laser_trail_buf[128];
u8 g_sprite_last_boss_buf[48];
#else
#ifdef DEATH_LABEL
u8 g_sprite_last_boss_buf[0x23470];
#else
u8 g_sprite_last_boss_buf[0xea90];
#endif

#include "pc_data_alias.h"

PC_DATA_ALIAS(g_sprite_laser_trail_buf, g_sprite_last_boss_buf, 0x0030);
PC_DATA_ALIAS(g_sprite_hyper_display_buf, g_sprite_last_boss_buf, 0x00b0);
PC_DATA_ALIAS(g_sprite_hyper_ready_buf, g_sprite_last_boss_buf, 0x0130);
PC_DATA_ALIAS(g_sprite_maximum_buf, g_sprite_last_boss_buf, 0x0150);
PC_DATA_ALIAS(g_sprite_stage_clear2_buf, g_sprite_last_boss_buf, 0x0170);
PC_DATA_ALIAS(g_sprite_stage_clear1_buf, g_sprite_last_boss_buf, 0x01f0);
PC_DATA_ALIAS(g_sprite_ship_select_buf, g_sprite_last_boss_buf, 0x0270);
PC_DATA_ALIAS(g_sprite_bombs_buf, g_sprite_last_boss_buf, 0x02f0);
PC_DATA_ALIAS(g_sprite_sight_buf, g_sprite_last_boss_buf, 0x0730);
PC_DATA_ALIAS(g_sprite_score_buf, g_sprite_last_boss_buf, 0x07b0);
PC_DATA_ALIAS(g_sprite_warning_buf, g_sprite_last_boss_buf, 0x0930);
PC_DATA_ALIAS(g_sprite_bullets2_buf, g_sprite_last_boss_buf, 0x09f0);
#ifdef DEATH_LABEL
PC_DATA_ALIAS(g_sprite_bullets_buf, g_sprite_last_boss_buf, 0x3b30);
PC_DATA_ALIAS(g_sprite_sparks_buf, g_sprite_last_boss_buf, 0x6c70);
PC_DATA_ALIAS(g_sprite_players_buf, g_sprite_last_boss_buf, 0x6f40);
PC_DATA_ALIAS(g_sprite_options_buf, g_sprite_last_boss_buf, 0x7000);
PC_DATA_ALIAS(g_sprite_player_lasers_buf, g_sprite_last_boss_buf, 0x7030);
PC_DATA_ALIAS(g_sprite_player_shots_buf, g_sprite_last_boss_buf, 0x7330);
PC_DATA_ALIAS(g_sprite_debris2_buf, g_sprite_last_boss_buf, 0x7690);
PC_DATA_ALIAS(g_sprite_debris1_buf, g_sprite_last_boss_buf, 0x7780);
PC_DATA_ALIAS(g_sprite_player_shadows_buf, g_sprite_last_boss_buf, 0x7870);
PC_DATA_ALIAS(g_sprite_items_buf, g_sprite_last_boss_buf, 0x78c0);
PC_DATA_ALIAS(g_sprite_items_first_buf, g_sprite_last_boss_buf, 0x79f0);
PC_DATA_ALIAS(g_sprite_special_items_buf, g_sprite_last_boss_buf, 0x7b20);
PC_DATA_ALIAS(g_sprite_extra_buf, g_sprite_last_boss_buf, 0x7e70);
PC_DATA_ALIAS(g_sprite_layer5_buf, g_sprite_last_boss_buf, 0xebf0);
PC_DATA_ALIAS(g_sprite_layer4_buf, g_sprite_last_boss_buf, 0x122b0);
PC_DATA_ALIAS(g_sprite_layer3_buf, g_sprite_last_boss_buf, 0x15970);
PC_DATA_ALIAS(g_sprite_layer2_buf, g_sprite_last_boss_buf, 0x19030);
PC_DATA_ALIAS(g_sprite_layer1_buf, g_sprite_last_boss_buf, 0x1c6f0);
#else
PC_DATA_ALIAS(g_sprite_bullets_buf, g_sprite_last_boss_buf, 0x13d0);
PC_DATA_ALIAS(g_sprite_sparks_buf, g_sprite_last_boss_buf, 0x1db0);
PC_DATA_ALIAS(g_sprite_players_buf, g_sprite_last_boss_buf, 0x2080);
PC_DATA_ALIAS(g_sprite_options_buf, g_sprite_last_boss_buf, 0x2140);
PC_DATA_ALIAS(g_sprite_player_lasers_buf, g_sprite_last_boss_buf, 0x2170);
PC_DATA_ALIAS(g_sprite_player_shots_buf, g_sprite_last_boss_buf, 0x2470);
PC_DATA_ALIAS(g_sprite_debris2_buf, g_sprite_last_boss_buf, 0x27d0);
PC_DATA_ALIAS(g_sprite_debris1_buf, g_sprite_last_boss_buf, 0x28c0);
PC_DATA_ALIAS(g_sprite_player_shadows_buf, g_sprite_last_boss_buf, 0x29b0);
PC_DATA_ALIAS(g_sprite_items_buf, g_sprite_last_boss_buf, 0x2a00);
PC_DATA_ALIAS(g_sprite_items_first_buf, g_sprite_last_boss_buf, 0x2b30);
PC_DATA_ALIAS(g_sprite_special_items_buf, g_sprite_last_boss_buf, 0x2c60);
PC_DATA_ALIAS(g_sprite_extra_buf, g_sprite_last_boss_buf, 0x2fb0);
PC_DATA_ALIAS(g_sprite_layer5_buf, g_sprite_last_boss_buf, 0x5e60);
PC_DATA_ALIAS(g_sprite_layer4_buf, g_sprite_last_boss_buf, 0x75c0);
PC_DATA_ALIAS(g_sprite_layer3_buf, g_sprite_last_boss_buf, 0x8d20);
PC_DATA_ALIAS(g_sprite_layer2_buf, g_sprite_last_boss_buf, 0xa480);
PC_DATA_ALIAS(g_sprite_layer1_buf, g_sprite_last_boss_buf, 0xbbe0);
#endif
#endif

#ifdef DDPDOJ_PC
#include "pc_frame_regions.h"

const PcFrameRegion pc_sprite_queue_regions[] = {
    PC_FRAME_REGION(g_sprite_layer1_used),
    PC_FRAME_REGION(g_sprite_layer2_used),
    PC_FRAME_REGION(g_sprite_layer3_used),
    PC_FRAME_REGION(g_sprite_layer4_used),
    PC_FRAME_REGION(g_sprite_layer5_used),
    PC_FRAME_REGION(g_sprite_extra_used),
    PC_FRAME_REGION(g_sprite_special_items_used),
    PC_FRAME_REGION(g_sprite_items_first_used),
    PC_FRAME_REGION(g_sprite_items_used),
    PC_FRAME_REGION(g_sprite_player_shadows_used),
    PC_FRAME_REGION(g_sprite_debris1_used),
    PC_FRAME_REGION(g_sprite_debris2_used),
    PC_FRAME_REGION(g_sprite_player_shots_used),
    PC_FRAME_REGION(g_sprite_player_lasers_used),
    PC_FRAME_REGION(g_sprite_options_used),
    PC_FRAME_REGION(g_sprite_players_used),
    PC_FRAME_REGION(g_sprite_sparks_used),
    PC_FRAME_REGION(g_sprite_bullets_used),
    PC_FRAME_REGION(g_sprite_bullets2_used),
    PC_FRAME_REGION(g_sprite_warning_used),
    PC_FRAME_REGION(g_sprite_score_used),
    PC_FRAME_REGION(g_sprite_sight_used),
    PC_FRAME_REGION(g_sprite_laser_trail_used),
    PC_FRAME_REGION(g_sprite_bombs_used),
    PC_FRAME_REGION(g_sprite_ship_select_used),
    PC_FRAME_REGION(g_sprite_stage_clear1_used),
    PC_FRAME_REGION(g_sprite_stage_clear2_used),
    PC_FRAME_REGION(g_sprite_maximum_used),
    PC_FRAME_REGION(g_sprite_hyper_ready_used),
    PC_FRAME_REGION(g_sprite_hyper_display_used),
    PC_FRAME_REGION(g_sprite_last_boss_used),
    PC_FRAME_REGION(g_sprite_unused_count),
    PC_FRAME_REGION(g_sprite_overflow_count),
    PC_FRAME_REGION(g_sprite_overflow_bytes),
    PC_FRAME_REGION(g_sprite_sparks_dropped),
    PC_FRAME_REGION(g_sprite_debris_dropped),
#ifdef DEATH_LABEL
    PC_FRAME_REGION_BYTES(g_sprite_layer1_buf, 28032),
    PC_FRAME_REGION_BYTES(g_sprite_layer2_buf, 14016),
    PC_FRAME_REGION_BYTES(g_sprite_layer3_buf, 14016),
    PC_FRAME_REGION_BYTES(g_sprite_layer4_buf, 14016),
    PC_FRAME_REGION_BYTES(g_sprite_layer5_buf, 14016),
    PC_FRAME_REGION_BYTES(g_sprite_extra_buf, 28032),
#else
    PC_FRAME_REGION_BYTES(g_sprite_layer1_buf, 11952),
    PC_FRAME_REGION_BYTES(g_sprite_layer2_buf, 5984),
    PC_FRAME_REGION_BYTES(g_sprite_layer3_buf, 5984),
    PC_FRAME_REGION_BYTES(g_sprite_layer4_buf, 5984),
    PC_FRAME_REGION_BYTES(g_sprite_layer5_buf, 5984),
    PC_FRAME_REGION_BYTES(g_sprite_extra_buf, 11952),
#endif
    PC_FRAME_REGION_BYTES(g_sprite_special_items_buf, 848),
    PC_FRAME_REGION_BYTES(g_sprite_items_first_buf, 304),
    PC_FRAME_REGION_BYTES(g_sprite_items_buf, 304),
    PC_FRAME_REGION_BYTES(g_sprite_player_shadows_buf, 80),
    PC_FRAME_REGION_BYTES(g_sprite_debris1_buf, 240),
    PC_FRAME_REGION_BYTES(g_sprite_debris2_buf, 240),
    PC_FRAME_REGION_BYTES(g_sprite_player_shots_buf, 864),
    PC_FRAME_REGION_BYTES(g_sprite_player_lasers_buf, 768),
    PC_FRAME_REGION_BYTES(g_sprite_options_buf, 48),
    PC_FRAME_REGION_BYTES(g_sprite_players_buf, 192),
    PC_FRAME_REGION_BYTES(g_sprite_sparks_buf, 720),
#ifdef DEATH_LABEL
    PC_FRAME_REGION_BYTES(g_sprite_bullets_buf, 12608),
    PC_FRAME_REGION_BYTES(g_sprite_bullets2_buf, 12608),
#else
    PC_FRAME_REGION_BYTES(g_sprite_bullets_buf, 2528),
    PC_FRAME_REGION_BYTES(g_sprite_bullets2_buf, 2528),
#endif
    PC_FRAME_REGION_BYTES(g_sprite_warning_buf, 192),
    PC_FRAME_REGION_BYTES(g_sprite_score_buf, 384),
    PC_FRAME_REGION_BYTES(g_sprite_sight_buf, 128),
    PC_FRAME_REGION_BYTES(g_sprite_bombs_buf, 1088),
    PC_FRAME_REGION_BYTES(g_sprite_ship_select_buf, 128),
    PC_FRAME_REGION_BYTES(g_sprite_stage_clear1_buf, 128),
    PC_FRAME_REGION_BYTES(g_sprite_stage_clear2_buf, 128),
    PC_FRAME_REGION_BYTES(g_sprite_maximum_buf, 32),
    PC_FRAME_REGION_BYTES(g_sprite_hyper_ready_buf, 32),
    PC_FRAME_REGION_BYTES(g_sprite_hyper_display_buf, 128),
    PC_FRAME_REGION_BYTES(g_sprite_laser_trail_buf, 128),
    PC_FRAME_REGION_BYTES(g_sprite_last_boss_buf, 48),
    { NULL, 0 },
};
#endif
