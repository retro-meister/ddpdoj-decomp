#include "common.h"
#include "player.h"
#include "entity.h"

void p2_options_update(void);
void options_update(void);
void options_update_style_a(void);
void options_update_style_b(void);
void options_update_style_c(void);
void option_aim(void);
void options_narrow_step(void);
void options_widen_step(void);
void option_frames_load(void);
void option_power_values_load(void);
void option_table_load(void);
void options_laser_fire(void);
void option_move(void);

s32 entity_draw_keep();                            /* extern */
s32 option_shot_fire();                            /* extern */

void option_pair_draw(void) {
#ifdef DDPDOJ_PC
    u8 *first = reg_a6;
    option_shot_fire();
    reg_a6 = reg_a0 - 0x2C;
    entity_draw_keep();
    u8 *second = first + 0x20;
    reg_a6 = second;
    reg_a0 = reg_a3;
    option_shot_fire();
    reg_a6 = reg_a0 - 0x2C;
    entity_draw_keep();
    reg_a6 = second;
#else
    s32 temp_s0;
    s32 temp_s0_2;

    temp_s0 = (s32)reg_a6;
    option_shot_fire();
    reg_a6 = (u8 *)(((s32)reg_a0) - 0x2C);
    entity_draw_keep();
    reg_a6 = (u8 *)temp_s0;
    reg_a6 += 0x20;
    temp_s0_2 = (s32)reg_a6;
    reg_a0 = (u8 *)(((s32)reg_a3));
    option_shot_fire();
    reg_a6 = (u8 *)(((s32)reg_a0) - 0x2C);
    entity_draw_keep();
    reg_a6 = (u8 *)temp_s0_2;
#endif
}

void sprite_draw_with_player_shadows_keep(void);
extern u16 g_players_hidden;
extern u16 g_frame_mod2;
extern u16 g_loop;
extern u16 g_stage;

void option_shadow_draw(void) {
    if (g_players_hidden != 0) return;
    if (g_frame_mod2 != 0) return;
    if (g_loop != 0) return;
    if (g_stage == 2) return;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d5.h[0] = 0x1C00;
    reg_d1.h[0] -= reg_d5.h[0];
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d1.h[0] += reg_d5.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d5.h[0] = 0x1400;
    reg_d1.h[0] -= reg_d5.h[0];
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d1.h[0] += reg_d5.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.w += 0xFE00FF00;
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = 0x18;
    reg_d2.w = reg_d6.w;
    sprite_draw_with_player_shadows_keep();
}

void option_pair_shadows_draw(void) {
    if ((g_players_hidden == 0) && (g_frame_mod2 == 0) && (g_loop == 0) && (g_stage != 2)) {
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d5.h[0] = 0x1C00;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d5.h[0] = 0x1400;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.w += 0xFE00FF00;
        reg_d3.h[0] = 0x208;
        reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
        reg_d4.b[0] = 0x18;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x5C);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x5E);
        sprite_draw_with_player_shadows_keep();
        reg_d1.h[1] = *(u16 *)(reg_a6 + 0x22);
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0x24);
        reg_d5.h[0] = 0x1C00;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d5.h[0] = 0x1400;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.w += 0xFE00FF00;
        reg_d3.h[0] = 0x208;
        reg_d4.h[0] = *(u16 *)(reg_a6 + 0x3C);
        reg_d4.b[0] = 0x18;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x60);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x62);
        sprite_draw_with_player_shadows_keep();
    }
}

void option_shadow_draw_single(void) {
    if ((g_players_hidden == 0) && (g_loop == 0) && (g_frame_mod2 == 0) && (g_stage != 2)) {
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d5.h[0] = 0x1C00;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d5.h[0] = 0x1400;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.w += 0xFE00FE00;
        reg_d3.h[0] = 0x210;
        reg_d4.h[0] = 0x18;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x5C);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x5E);
        sprite_draw_with_player_shadows_keep();
    }
}


void option_animate(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x43);
    *(u8 *)(reg_a6 + 0x43) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a6 + 0x43) = (u8) *(u8 *)(reg_a6 + 0x42);
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x44);
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x46);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x48);
        reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        reg_d1.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d1.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->draw.h = (u16) reg_d1.h[1];
        ENTITY(reg_a6)->sprite.h = (u16) reg_d1.h[0];
        *(u16 *)(reg_a6 + 0x2A) = (u16) reg_d1.h[1];
        *(u16 *)(reg_a6 + 0x2C) = (u16) reg_d1.h[0];
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x58);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x5A);
        reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        reg_d0.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x5C) = (u16) reg_d0.h[1];
        *(u16 *)(reg_a6 + 0x5E) = (u16) reg_d0.h[0];
        *(u16 *)(reg_a6 + 0x60) = (u16) reg_d0.h[1];
        *(u16 *)(reg_a6 + 0x62) = (u16) reg_d0.h[0];
        *(u16 *)(reg_a6 + 0x44) -= 4;
        if ((s16) *(u16 *)(reg_a6 + 0x44) < 0) {
            *(u16 *)(reg_a6 + 0x44) = (u16) *(u16 *)(reg_a6 + 0x4C);
        }
    }
}


void option_setup_from_template(void) {
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) reg_d7.h[0];
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    (*(u8 *)((u8 *)(reg_a1) + (-2))) = (u8) *(u8 *)(reg_a4 + 0x57);
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
}

extern u8 D_0029D730[];
extern u8 g_p1_options[80];
extern s16 g_player1[56];

void p1_options_update(void) {
    reg_a6 = (u8 *)((s16 *)g_p1_options);
    reg_a4 = (u8 *)((s32 *)g_player1);
    reg_a2 = (u8 *)((s32 *)D_0029D730);
    reg_d7.w = 1;
    if (*(s16 *)reg_a6 < 0) {
        options_update();
        return;
    }
    reg_d7.w = 0;
    p2_options_update();
}

extern u8 D_0029D710[];
extern u8 g_p2_options[];
extern s16 g_player2[56];

void p2_options_update(void) {
    reg_a6 = (u8 *)((s16 *)g_p2_options);
    reg_a4 = (u8 *)((s32 *)g_player2);
    reg_a2 = (u8 *)((s32 *)D_0029D710);
    if (*(s16 *)reg_a6 < 0) {
        options_update();
    }
}

typedef void (*Fn)();

extern u8 option_style_params[];
extern u8 options_update_table[];
extern u8 option_strong_params[];
extern u8 option_hyper_params[];
extern u8 g_p2_options[];

s32 p1_laser_clear();
s32 p2_laser_clear();
s32 p1_afterimage_reset();
s32 p2_afterimage_reset();
s32 player_zoom_in_step();
s32 player_option_delay_clear();
extern u8 g_game_frame_ran;
extern s32 g_replay_position;
extern u8 g_replay_mode;
extern u8 D_0029D710[];

void options_update(void) {
    u32 temp;
    u8 bits;
    s32 temp2;

    goto next_20;
loop_10:
    reg_a6 = (u8 *)g_p2_options;
    reg_a4 = (u8 *)((u8 *)g_player2);
    reg_a2 = (u8 *)D_0029D710;
    if (*(s16 *)reg_a6 < 0) goto next_20;
    return;
next_20:
    reg_tmp.b[0] = *(u8 *)reg_a6;
    *(u8 *)reg_a6 |= 1;
    if (reg_tmp.b[0] & 1) goto next_100;
    reg_a0 = (u8 *)option_style_params;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x5A);
    reg_d0.h[0] -= 2;
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_a1 = (u8 *)(reg_a6 + 6);
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_d0.b[0] = *(u8 *)(reg_a4 + 0x1C);
    *(u8 *)(reg_a6 + 0x1C) = (u8) reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x3C) = (u8) reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a4 + 0x57);
    *(u8 *)(reg_a2 + 0x1C) = (u8) reg_d0.b[0];
    *(u8 *)(reg_a2 + 0x1F) = (u8) reg_d0.b[0];
    *(s16 *)(reg_a2 + 0x16) = 0;
next_100:
    *(u8 *)(reg_a6 + 0x41) = *(u8 *)(reg_a4 + 0x19);
    *(u8 *)(reg_a6 + 0x40) = *(u8 *)(reg_a4 + 0x18);
    reg_d0.h[0] = *(u16 *)reg_a6;
    if (reg_d0.h[0] & 0x200) goto block_e;
    if (*(u8 *)(reg_a4 + 1) & 1) goto block_d;
    if (!(reg_d0.h[0] & 2)) goto block_c;
    if (!(*(u8 *)(reg_a4 + 1) & 0x20)) goto next_210;
    *(u16 *)(reg_a6 + 0x40) = 0;
next_210:
    if (!(*(u8 *)(reg_a6 + 0x41) & 0x10)) goto next_400;
    if (*(u8 *)(reg_a6 + 0x3E) == 0) goto next_310;
    *(u8 *)(reg_a6 + 0x3E) -= 1;
    if (*(u8 *)(reg_a6 + 0x3E) != 0) goto next_470;
    *(u8 *)(reg_a6 + 1) |= 0x40;
next_310:
    player_zoom_in_step();
    if (!(*(u8 *)reg_a6 & 4)) goto next_320;
    options_narrow_step();
    goto block_b;
next_320:
    if (*(u8 *)(reg_a6 + 0x1A) != 0) goto next_330;
    options_narrow_step();
    option_frames_load();
    if (cond_flag == 0) goto block_b;
    *(u8 *)reg_a6 |= 4;
    *(s16 *)(reg_a6 + 0x4E) = 0;
    if (*(u8 *)reg_a4 & 1) goto next_328;
    if (*(u8 *)(reg_a4 + 0x5A) & 4) goto next_326;
    option_power_values_load();
    goto block_b;
next_326:
    reg_a0 = (u8 *)option_strong_params;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x58);
    if (reg_d0.h[0] == 0) goto next_327;
    reg_d0.w = 0x14;
next_327:
    reg_a0 = (u8 *)option_strong_params;
    reg_a0 += reg_d0.h[0];
    option_table_load();
    goto block_b;
next_328:
    reg_a0 = (u8 *)option_hyper_params;
    option_table_load();
    goto block_b;
next_330:
    if (*(u16 *)(reg_a6 + 0x10) != 4) goto next_350;
    if (*(u8 *)(reg_a6 + 1) & 4) goto next_340;
    *(u8 *)(reg_a6 + 1) |= 8;
    if (*(u8 *)(reg_a6 + 0x14) == 0x10) goto next_340;
    if (*(u8 *)(reg_a6 + 0x14) != 0x30) goto block_b;
    bits = *(u8 *)(reg_a6 + 0x1D);
    if (!(bits & 0x40)) goto next_332;
    *(u8 *)(reg_a6 + 0x1D) = bits & 0xBF;
    goto next_334;
next_332:
    *(u8 *)(reg_a6 + 0x1D) = bits | 0x40;
next_334:
    bits = *(u8 *)(reg_a6 + 0x3D);
    if (!(bits & 0x40)) goto next_336;
    *(u8 *)(reg_a6 + 0x3D) = bits & 0xBF;
    goto next_338;
next_336:
    *(u8 *)(reg_a6 + 0x3D) = bits | 0x40;
next_338:
    *(u8 *)(reg_a6 + 0x14) = 0x10;
    *(u8 *)(reg_a6 + 0x34) = 0x30;
next_340:
    *(u8 *)(reg_a6 + 1) &= 0xF7;
    *(u8 *)(reg_a6 + 1) |= 4;
next_350:
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3F);
    *(u8 *)(reg_a6 + 0x1A) -= reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x3A) += reg_d0.b[0];
    if ((s32) *(u8 *)(reg_a6 + 0x3A) < 0x40) goto block_b;
    *(u8 *)(reg_a6 + 1) |= 0x10;
    reg_d0.w = 0;
    *(u8 *)(reg_a6 + 0x1A) = reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x3A) = reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x4B) = 8;
    *(u8 *)(reg_a6 + 0x4A) = 4;
    *(u16 *)(reg_a6 + 0x16) = *(u16 *)(reg_a6 + 0x30);
    *(u16 *)(reg_a6 + 0x18) = *(u16 *)(reg_a6 + 0x32);
    option_frames_load();
    *(u16 *)(reg_a6 + 0xE) = 0x418;
    reg_tmp.w = 0xFC00FD00;
    *(u16 *)(reg_a6 + 6) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 8) = reg_tmp.h[0];
    *(u8 *)(reg_a4 + 0x3E) = 1;
    reg_a0 = (u8 *) p1_afterimage_reset;
    if (reg_d7.h[0] != 0) goto next_360;
    reg_a0 = (u8 *) p2_afterimage_reset;
next_360:
    reg_call_target = (Fn) reg_a0;
    reg_call_target();
    goto block_b;
next_400:
    if (*(s8 *)reg_a4 >= 0) goto next_410;
    options_narrow_step();
    goto block_b;
next_410:
    player_option_delay_clear();
    options_widen_step();
    *(u8 *)(reg_a6 + 0x3E) = 0xA;
    if (!(*(u8 *)(reg_a6 + 1) & 0x40)) goto block_b;
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 0x2B) = reg_d0.b[0];
    *(u8 *)(reg_a4 + 0x2A) = reg_d0.b[0];
    *(u8 *)(reg_a4 + 0x35) = reg_d0.b[0];
    *(u8 *)(reg_a4 + 0x34) = reg_d0.b[0];
    *(u8 *)(reg_a4 + 0x3E) = reg_d0.b[0];
    if (reg_d7.h[0] == 0) goto next_430;
    p1_laser_clear();
    goto next_440;
next_430:
    p2_laser_clear();
next_440:
    *(u8 *)(reg_a6 + 0x4B) = 8;
    *(u8 *)(reg_a6 + 0x4A) = 4;
    *(u16 *)reg_a6 &= 0xDFDB;
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 1);
    *(u8 *)(reg_a6 + 1) &= 0xEF;
    if (!(reg_tmp.b[0] & 0x10)) goto next_470;
    *(u16 *)(reg_a6 + 0xA) = *(u16 *)(reg_a6 + 0x2A);
    *(u16 *)(reg_a6 + 0xC) = *(u16 *)(reg_a6 + 0x2C);
    *(u16 *)(reg_a6 + 0xE) = *(u16 *)(reg_a6 + 0x2E);
    *(u16 *)(reg_a6 + 6) = *(u16 *)(reg_a6 + 0x26);
    *(u16 *)(reg_a6 + 8) = *(u16 *)(reg_a6 + 0x28);
next_470:
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x37);
    if ((s32) *(u8 *)(reg_a6 + 0x1A) < (s32) reg_d0.b[0]) goto next_480;
    *(u8 *)(reg_a6 + 0x1A) = reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x3A) = *(u8 *)(reg_a6 + 0x36);
    *(u8 *)(reg_a6 + 1) &= 0xB3;
    goto block_b;
next_480:
    *(u8 *)(reg_a6 + 0x1A) += 2;
    *(u8 *)(reg_a6 + 0x3A) -= 2;
    *(u8 *)(reg_a6 + 0x3A) &= 0x3F;
block_b:
    reg_d0.h[1] = *(u16 *)(reg_a4 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 4);
    *(u16 *)(reg_a6 + 2) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 4) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x22) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x24) = reg_d0.h[0];
    if (*(u8 *)(reg_a6 + 0x1A) == 0) goto next_530;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x5A);
    reg_d0.h[0] -= 2;
    if (g_game_frame_ran == 0) goto next_520;
    if (g_replay_mode != 2) goto next_510;
    if (g_replay_position == 0) goto next_520;
next_510:
    switch ((s32) reg_d0.h[0] >> 1) {
    case 0:
        options_update_style_a();
        break;
    case 1:
        options_update_style_b();
        break;
    case 2:
        options_update_style_c();
        break;
    }
next_520:
    reg_a6 += 0x20;
    goto next_540;
next_530:
    option_move();
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1E);
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    options_laser_fire();
next_540:
    temp = reg_d7.h[0] - 1;
    reg_d7.h[0] = temp;
    if (((s64) ((s64) (temp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_10;
    return;
block_c:
    if (g_game_frame_ran == 0) goto block_rts;
    if (g_replay_mode != 2) goto next_610;
    if (g_replay_position == 0) goto block_rts;
next_610:
    *(u8 *)(reg_a6 + 0x1B) += 8;
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x58);
    if (reg_d1.h[0] == 0) goto next_620;
    reg_d1.w = 6;
next_620:
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x5A);
    reg_d0.h[0] -= 2;
    reg_d0.h[0] += reg_d1.h[0];
    reg_a0 = (u8 *)options_update_table;
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    if (*(u8 *)(reg_a6 + 0x1B) != reg_d0.b[0]) goto next_630;
    *(u8 *)reg_a6 = 3;
next_630:
    *(u8 *)(reg_a6 + 0x3B) = *(u8 *)(reg_a6 + 0x1B);
    if (*(u16 *)(reg_a4 + 0x5A) == 4) goto next_640;
    option_animate();
next_640:
    reg_d0.h[1] = *(u16 *)(reg_a4 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 4);
    *(u16 *)(reg_a6 + 2) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 4) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x22) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x24) = reg_d0.h[0];
    option_pair_shadows_draw();
    option_move();
    reg_a6 += 0x20;
    option_move();
    temp = reg_d7.h[0] - 1;
    reg_d7.h[0] = temp;
    if (((s64) ((s64) (temp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_10;
    return;
block_d:
    reg_d0.w = 0x31;
    reg_d1.w = 0;
    reg_a0 = reg_a6;
loop_710:
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    temp2 = reg_d0.h[0] - 1;
    reg_d0.h[0] = temp2;
    if (((s64) ((s64) (u16) temp2 << 0x30) >> 0x30) >= 0) goto loop_710;
    reg_a6 += 0x20;
    temp = reg_d7.h[0] - 1;
    reg_d7.h[0] = temp;
    if (((s64) ((s64) (temp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_10;
    return;
block_e:
    reg_a6 += 0x20;
    temp = reg_d7.h[0] - 1;
    reg_d7.h[0] = temp;
    if (((s64) ((s64) (temp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_10;
block_rts:
    return;
}

s32 option_shots_fire_style_a();

void options_update_style_a(void) {
    option_animate();
    option_move();
    reg_a6 += 0x20;
    option_move();
    reg_a6 -= 0x20;
    option_pair_shadows_draw();
    if (*(u8 *)(reg_a6 + 0x40) & 0x10) {
        reg_d0.b[0] = *(u8 *)(reg_a4 + 0x20);
        if (*(u8 *)reg_a4 & 1) {
            reg_d0.h[0] = 8;
        }
        reg_d0.b[0] >>= 1;
        reg_d0.b[0] += *(u8 *)(reg_a4 + 0x36);
        *(u8 *)(reg_a4 + 0x34) = (u8) reg_d0.b[0];
        reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
        ENTITY(reg_a6)->flags.b[0] &= 0xF7;
        if (reg_tmp.b[0] & 8) {
            ENTITY(reg_a6)->flags.b[0] |= 0x10;
            *(u8 *)(reg_a4 + 0x34) = 0U;
            goto block_10;
        }
        reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
        ENTITY(reg_a6)->flags.b[0] &= 0xEF;
        if (reg_tmp.b[0] & 0x10) {
            *(u8 *)(reg_a4 + 0x35) = 1U;
            return;
        }
        goto block_10;
    }
    ENTITY(reg_a6)->flags.b[0] &= 0xEF;
    if (*(u8 *)(reg_a4 + 0x34) != 0) {
        *(u8 *)(reg_a4 + 0x35) -= 1;
        if (*(u8 *)(reg_a4 + 0x35) == 0) {
            *(u8 *)(reg_a4 + 0x34) -= 1;
            ENTITY(reg_a6)->flags.b[0] |= 0x10;
block_10:
            reg_d0.b[0] = *(u8 *)(reg_a4 + 0x37);
            if (!(*(u8 *)reg_a4 & 1)) {
                if ((u16) *(u16 *)(reg_a4 + 0x20) == 8) {
                    goto block_13;
                }
            } else {
block_13:
                reg_d0.w = 2;
            }
            *(u8 *)(reg_a4 + 0x35) = (u8) reg_d0.b[0];
            option_shots_fire_style_a();
        }
    }
}

s32 option_shots_fire_style_b();

void options_update_style_b(void) {
    u32 t;
    u8 *p0;

    if (*(u8 *)(reg_a6 + 1) & 4) {
        option_move();
        reg_a6 += 0x20;
        option_move();
        reg_a6 -= 0x20;
        option_pair_shadows_draw();
    } else {
        reg_d3.w = 0;
        if (*(u8 *)(reg_a6 + 1) & 8) {
            reg_d3.w = 3;
        }
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x14);
loop_5:
        reg_d0.b[0] += 1;
        reg_d0.b[0] &= 0x3F;
        if (reg_d0.b[0] == 0x10) goto next_6;
        if (reg_d0.b[0] == 0x30) goto next_6;
        t = reg_d3.h[0] - 1;
        reg_d3.h[0] = t;
        if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_5;
next_6:
        *(u8 *)(reg_a6 + 0x14) = (u8) reg_d0.b[0];
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0x20;
        reg_d1.b[0] &= 0x3F;
        *(u8 *)(reg_a6 + 0x34) = (u8) reg_d1.b[0];
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x46);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x48);
        reg_a2 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        reg_d1.b[0] = *(u8 *)(reg_a6 + 0x14);
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x58);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x5A);
        reg_a3 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        option_aim();
        *(u16 *)(reg_a6 + 0x5C) = (u16) reg_d6.h[1];
        *(u16 *)(reg_a6 + 0x5E) = (u16) reg_d6.h[0];
        p0 = (u8 *)(reg_a6);
        reg_d1.b[0] = *(u8 *)(p0 + 0x34);
        reg_tmp.h[1] = *(u16 *)(p0 + 0x58);
        reg_tmp.h[0] = *(u16 *)(p0 + 0x5A);
        reg_a6 = p0 + 0x20;
        reg_a3 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        option_aim();
        reg_a6 -= 0x20;
        *(u16 *)(reg_a6 + 0x60) = (u16) reg_d6.h[1];
        *(u16 *)(reg_a6 + 0x62) = (u16) reg_d6.h[0];
    }
    if (*(u8 *)(reg_a6 + 0x40) & 0x10) {
        reg_d0.b[0] = *(u8 *)(reg_a4 + 0x20);
        if (*(u8 *)reg_a4 & 1) {
            reg_d0.h[0] = 8;
        }
        reg_d0.b[0] >>= 1;
        reg_d0.b[0] += *(u8 *)(reg_a4 + 0x36);
        *(u8 *)(reg_a4 + 0x34) = (u8) reg_d0.b[0];
        reg_tmp.b[0] = *(u8 *)reg_a6;
        *(u8 *)reg_a6 &= 0xF7;
        if (reg_tmp.b[0] & 8) {
            *(u8 *)reg_a6 |= 0x10;
            *(u8 *)(reg_a4 + 0x34) = 0U;
            goto block_19;
        }
        reg_tmp.b[0] = *(u8 *)reg_a6;
        *(u8 *)reg_a6 &= 0xEF;
        if (reg_tmp.b[0] & 0x10) {
            *(u8 *)(reg_a4 + 0x35) = 1U;
            return;
        }
        goto block_19;
    }
    *(u8 *)reg_a6 &= 0xEF;
    if (*(u8 *)(reg_a4 + 0x34) != 0) {
        *(u8 *)(reg_a4 + 0x35) -= 1;
        if (*(u8 *)(reg_a4 + 0x35) == 0) {
            *(u8 *)(reg_a4 + 0x34) -= 1;
            *(u8 *)reg_a6 |= 0x10;
block_19:
            reg_d0.b[0] = *(u8 *)(reg_a4 + 0x37);
            if (!(*(u8 *)reg_a4 & 1)) {
                if ((u16) *(u16 *)(reg_a4 + 0x20) == 8) {
                    goto block_22;
                }
            } else {
block_22:
                reg_d0.w = 2;
            }
            *(u8 *)(reg_a4 + 0x35) = (u8) reg_d0.b[0];
            option_shots_fire_style_b();
        }
    }
}

s32 option_shots_fire_style_c();

void options_update_style_c(void) {
    option_animate();
    option_move();
    reg_a6 += 0x20;
    option_move();
    reg_a6 -= 0x20;
    option_pair_shadows_draw();
    if (*(u8 *)(reg_a6 + 0x40) & 0x10) {
        reg_d0.b[0] = *(u8 *)(reg_a4 + 0x20);
        if (*(u8 *)reg_a4 & 1) {
            reg_d0.h[0] = 8;
        }
        reg_d0.b[0] >>= 1;
        reg_d0.b[0] += *(u8 *)(reg_a4 + 0x36);
        *(u8 *)(reg_a4 + 0x34) = (u8) reg_d0.b[0];
        reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
        ENTITY(reg_a6)->flags.b[0] &= 0xF7;
        if (reg_tmp.b[0] & 8) {
            ENTITY(reg_a6)->flags.b[0] |= 0x10;
            *(u8 *)(reg_a4 + 0x34) = 0U;
            goto block_10;
        }
        reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
        ENTITY(reg_a6)->flags.b[0] &= 0xEF;
        if (reg_tmp.b[0] & 0x10) {
            *(u8 *)(reg_a4 + 0x35) = 1U;
            return;
        }
        goto block_10;
    }
    ENTITY(reg_a6)->flags.b[0] &= 0xEF;
    if (*(u8 *)(reg_a4 + 0x34) != 0) {
        *(u8 *)(reg_a4 + 0x35) -= 1;
        if (*(u8 *)(reg_a4 + 0x35) == 0) {
            *(u8 *)(reg_a4 + 0x34) -= 1;
            ENTITY(reg_a6)->flags.b[0] |= 0x10;
block_10:
            reg_d0.b[0] = *(u8 *)(reg_a4 + 0x37);
            if (!(*(u8 *)reg_a4 & 1)) {
                if ((u16) *(u16 *)(reg_a4 + 0x20) == 8) {
                    goto block_13;
                }
            } else {
block_13:
                reg_d0.w = 2;
            }
            *(u8 *)(reg_a4 + 0x35) = (u8) reg_d0.b[0];
            option_shots_fire_style_c();
        }
    }
}

s32 entity_draw_with_options();
extern u16 option_aim_table[];

void option_aim(void) {
    u32 p0;
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a4 + 2);
    ENTITY(reg_a6)->x.h = (u16) *(u16 *)(reg_a4 + 4);
    reg_d2.w = 0;
    reg_d1.h[0] &= 0x3F;
    reg_d5.h[0] = reg_d1.h[0];
    ENTITY(reg_a6)->attr.b.flip &= 0xBF;
    if ((s32) reg_d5.b[0] > 0x20) {
        ENTITY(reg_a6)->attr.b.flip |= 0x40;
        reg_d5.b[0] *= -1;
        reg_d2.w = 1;
        reg_d5.h[0] &= 0x3F;
    }
    reg_d5.h[0] *= 4;
    ENTITY(reg_a6)->draw.h = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a2;
    ENTITY(reg_a6)->sprite.h = ((reg_d5.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_d6.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_d6.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a3;
    reg_a3 = (u8 *)(option_aim_table);
    reg_d0.h[0] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_d5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a3;
    if (*(u8 *)reg_a4 & 1) {
        reg_d1.h[0] = reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 2);
        reg_d5.h[0] += reg_d1.h[0];
    }
    if (reg_d2.h[0] != 0) {
        reg_d5.h[0] *= 0xFFFF;
    }
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    p0 = ENTITY(reg_a6)->x.h;
    ENTITY(reg_a6)->x.h = (u16) (p0 + reg_d5.h[0]);
    if (g_players_hidden == 0) {
        option_shadow_draw();
        entity_draw_with_options();
    }
}

void options_narrow_step(void) {
    reg_d0.b[0] = *(u8 *)(reg_a4 + 0x1B);
    if (*(u8 *)(reg_a4 + 0x39) != reg_d0.b[0]) {
        *(u8 *)(reg_a6 + 0x4A) -= 1;
        if (*(u8 *)(reg_a6 + 0x4A) == 0) {
            *(u8 *)(reg_a4 + 0x1B) -= 1;
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x5A);
            reg_d0.h[0] -= 2;
            reg_d0.h[0] >>= 1;
            reg_d0.h[0] += 4;
            *(u8 *)(reg_a6 + 0x4A) = (u8) reg_d0.b[0];
        }
    }
}

extern u16 g_bomb_entities[];

void options_widen_step(void) {
    if ((g_bomb_entities[0] == 0) || !(*(u8 *)reg_a4 & 0x40)) {
        reg_d0.b[0] = *(u8 *)(reg_a4 + 0x1B);
        if (*(u8 *)(reg_a4 + 0x38) != reg_d0.b[0]) {
            *(u8 *)(reg_a4 + 0x1B) += 1;
        }
    }
}

void option_frames_load(void) {
    reg_tmp.h[1] = ENTITY(reg_a6)->hit_x_minus.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->hp.h;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    ENTITY(reg_a6)->draw.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->sprite.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x5C) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x5E) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->misc.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->hit_y_minus.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    if ((s16) ENTITY(reg_a6)->hit_y_minus.h >= 0) {
        reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a0);
        ENTITY(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hp.h = (u16) reg_tmp.h[0];
        cond_flag = 0;
        return;
    }
    cond_flag = 1;
}

extern u16 option_power_values[];
extern u8 D_0029DCD0[];
extern u8 D_0029E2D0[];

void option_power_values_load(void) {
    reg_a1 = D_0029E2D0;
    if (reg_d7.h[0] == 0) {
        reg_a1 = D_0029DCD0;
    }
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x58);
    if (reg_d0.h[0] != 0) {
        reg_d0.w = 0x14;
    }
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x22);
    reg_a0 = (u8 *)(option_power_values);
    reg_d1.h[0] += reg_d1.h[0];
    reg_d0.h[0] += reg_d1.h[0];
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    option_setup_from_template();
}

void option_table_load(void) {
    reg_a1 = D_0029E2D0;
    if (reg_d7.h[0] == 0) {
        reg_a1 = D_0029DCD0;
    }
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x22);
    reg_d0.h[0] += reg_d0.h[0];
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    option_setup_from_template();
}

extern u16 option_strong_sprites_a[];
extern u16 option_hyper_sprites_a[];
extern u16 option_hyper_sprites_b[];
extern u16 option_sprites_a_tables[2];
extern u16 option_sprites_b_tables[2];
extern u16 option_strong_sprites_b_tables[2];
extern u16 g_p2_laser_stop_y;
extern u16 g_p1_laser_stop_y;
extern u8 D_0029D730[];
extern u8 g_p2_laser_segments[];
extern u8 g_p1_laser_segments[];
extern u8 g_p2_laser_entities[];
extern u8 g_p1_laser_entities[];


void options_laser_fire(void) {
    u32 cnt;

    switch (ENTITY(reg_a6)->flags.b[1] & 0x20) {
    case 0:
        goto next_100;
    }
    reg_a0 = (u8 *)&g_p1_laser_stop_y;
    reg_a1 = (u8 *)g_p1_laser_entities;
    reg_a2 = (u8 *)D_0029D730;
    reg_a3 = (u8 *)g_p1_laser_segments;
    reg_d4.h[0] = PLAYER(((s32 *)g_player1))->moved_y.h;
    if (reg_d7.h[0] != 0) goto next_10;
    reg_a0 = (u8 *)&g_p2_laser_stop_y;
    reg_a1 = (u8 *)g_p2_laser_entities;
    reg_a2 = (u8 *)D_0029D710;
    reg_a3 = (u8 *)g_p2_laser_segments;
    reg_d4.h[0] = PLAYER(((u8 *)g_player2))->moved_y.h;
next_10:
    reg_d4.h[0] += 0x300;
    reg_d0.h[1] = *(u16 *)(reg_a4 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 4);
    reg_d0.w += 0x8000000;
    *(u16 *)(reg_a3 + 2) = reg_d0.h[1];
    *(u16 *)(reg_a3 + 4) = reg_d0.h[0];
    if (reg_a3[1] & 0x10) goto next_30;
    if (*(u16 *)(reg_a3 + 0xC) != 0) goto next_40;
    if (*(u16 *)(reg_a2 + 0x16) == 0) goto next_20;
    *(u16 *)(reg_a2 + 0x16) -= 1;
    if (*(u16 *)(reg_a2 + 0x16) != 0) goto next_60;
next_20:
    *(u16 *)(reg_a3 + 6) += 0x800;
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
    ENTITY(reg_a6)->flags.b[0] |= 0x80;
    if (!(reg_tmp.b[0] & 0x80)) goto block_sen;
    goto next_60;
next_30:
    *(u16 *)(reg_a6 + 0x4E) = 0;
    *(u16 *)(reg_a3 + 0xE) = *(u16 *)(reg_a3 + 0x1C);
    *(u16 *)(reg_a3 + 0xC) = 0;
next_40:
    ENTITY(reg_a6)->flags.b[0] &= 0x7F;
    reg_d0.h[0] = *(u16 *)(reg_a3 + 0x10);
    reg_d1.h[0] = reg_d0.h[0];
    *(u16 *)reg_a0 = reg_d1.h[0];
    *(u16 *)(reg_a3 + 0x12) = reg_d1.h[0];
    reg_d0.h[0] -= *(u16 *)(reg_a3 + 2);
    if ((s16)reg_d0.h[0] >= 0) goto next_50;
    reg_d0.w = 0;
next_50:
    *(u16 *)(reg_a3 + 6) = reg_d0.h[0];
next_60:
    reg_d0.w = 0x1D;
    if (reg_a4[0] & 1) {
        reg_a0 = (u8 *)option_hyper_sprites_a;
        goto next_64;
    }
    reg_a0 = (u8 *)option_strong_sprites_a;
    if (reg_a4[0x5A] & 4) goto next_64;
    reg_d3.h[0] = *(u16 *)(reg_a4 + 0x58);
    reg_a0 = (u8 *)&(*(u16 *)option_sprites_a_tables);
    reg_d3.h[0] += reg_d3.h[0];
    reg_tmp.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
next_64:
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x22);
    reg_d2.h[0] = reg_d1.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
loop_70:
    if (*(s16 *)reg_a1 >= 0) goto next_80;
    reg_a1 += 0x30;
    cnt = reg_d0.h[0] - 1;
    reg_d0.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_70;
    goto next_100;
next_80:
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = ENTITY(reg_a6)->y.h;
    reg_a1 += 2;
    *(u16 *)reg_a1 = ENTITY(reg_a6)->x.h;
    reg_a1 += 2;
    *(u16 *)(reg_a1 - 4) -= reg_d4.h[0];
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a2 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x50);
    *(u16 *)reg_a1 = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 0xA;
    *(u16 *)reg_a1 = reg_d7.h[0];
    reg_a1 += 2;
    reg_a1[1] = 0;
    reg_a1[0] = reg_a4[0x57];
    reg_a1 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x50) += 4;
    if (*(u16 *)(reg_a6 + 0x50) != reg_d1.h[0]) goto next_100;
    *(u16 *)(reg_a6 + 0x50) = 0;
next_100:
    if ((s8)reg_a4[0] < 0) return;
    option_shadow_draw_single();
    entity_draw_with_options();
    return;
block_sen:
    reg_a2 = reg_a1;
    reg_a1 += 0x510;
    reg_d3.h[0] = *(u16 *)(reg_a4 + 0x58);
    reg_a0 = (u8 *)&(*(u16 *)option_sprites_b_tables);
    reg_d3.h[0] += reg_d3.h[0];
    if (reg_a4[0x5A] & 4) {
        reg_a0 = (u8 *)&(*(u16 *)option_strong_sprites_b_tables);
    }
    reg_tmp.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x22);
    reg_d2.h[0] = reg_d1.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    if (reg_a4[0] & 1) {
        reg_a0 = (u8 *)option_hyper_sprites_b;
    }
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = ENTITY(reg_a6)->y.h;
    reg_a1 += 2;
    *(u16 *)reg_a1 = ENTITY(reg_a6)->x.h;
    reg_a1 += 2;
    *(u16 *)(reg_a1 - 4) -= 0x600;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = reg_d7.h[0];
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1[-2] = reg_a4[0x57];
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.b[0] = reg_a3[0];
    reg_a3[0] |= 1;
    if (!(reg_tmp.b[0] & 1)) goto next_sen10;
    reg_a1[-0x28] |= 0x80;
    reg_d0.h[0] = *(u16 *)(reg_a3 + 0x12);
    reg_d0.h[0] += reg_d1.h[0];
    reg_d0.h[0] += 0x400;
    *(u16 *)(reg_a1 - 0x26) = reg_d0.h[0];
    reg_a1 = reg_a2;
    goto next_60;
next_sen10:
    *(u16 *)(reg_a6 + 0x4E) = 2;
    option_shadow_draw_single();
    entity_draw_with_options();
}

s32 velocity_from_dir_unless_stopped();
s32 velocity_from_direction();
extern u16 D_0025F5A8[];
extern u16 option_offsets[];

void option_move(void) {
    u32 temp_a0;
    u32 temp_a0_2;
    reg_d1.w = 0x3F;
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] &= ENTITY(reg_a6)->move.b.dir;
    velocity_from_direction();
    reg_d0.h[0] = reg_d2.h[0];
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
    reg_d2.h[0] -= reg_d0.h[0];
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    if (*(u8 *)reg_a4 & 1) {
        reg_d0.h[0] = reg_d3.h[0];
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
        reg_d3.h[0] += reg_d0.h[0];
    }
    if (*(u16 *)(reg_a4 + 0x5A) != 6) {
        reg_d0.h[0] = reg_d3.h[0];
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
    } else {
        reg_d0.h[0] = reg_d3.h[0];
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    }
    reg_d3.h[0] += reg_d0.h[0];
    temp_a0 = ENTITY(reg_a6)->x.h;
    ENTITY(reg_a6)->x.h = (u16) (temp_a0 + reg_d3.h[0]);
    if (g_players_hidden == 0) {
        if ((s8) *(u8 *)reg_a4 >= 0) {
            entity_draw_with_options();
            return;
        }
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x38);
        switch (reg_d0.h[0]) { case 0: break; default:
            reg_a0 = (u8 *)(option_offsets);
            reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
            ENTITY(reg_a6)->y.h -= reg_d0.h[0];
            *(u16 *)(reg_a6 + 0x38) -= 2;
            option_shadow_draw_single();
            entity_draw_with_options();
        }
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x56);
        *(u16 *)(reg_a6 + 0x56) -= 4;
        if ((s16) *(u16 *)(reg_a6 + 0x56) < 0) {
            *(u16 *)(reg_a6 + 0x56) = 8U;
        }
        temp_a0_2 = reg_d0.h[0];
        reg_a0 = (u8 *)(D_0025F5A8);
        reg_d1.h[0] = ((temp_a0_2 + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(temp_a0_2 + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = (temp_a0_2 != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)temp_a0_2 & ~1)) : *(u16 *)reg_a0;
        velocity_from_dir_unless_stopped();
        option_shadow_draw_single();
        entity_draw_with_options();
    }
}
