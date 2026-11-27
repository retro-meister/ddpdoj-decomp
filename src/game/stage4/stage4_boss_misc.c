#include "common.h"
#include "entity.h"
#include "explosion.h"
#include "enemy.h"
#include "stage4_boss.h"

void stage4_boss_missile_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 enemy_init_entities();
extern u8 stage4_boss_missile_start_table[];

void stage4_boss_missile_start(void) {
    reg_a0 = stage4_boss_missile_start_table;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) STAGE4_MISSILE(reg_a5)->at_start.y;
    ENTITY(reg_a6)->x.h = (u16) STAGE4_MISSILE(reg_a5)->at_start.x;
    ENTITY(reg_a6)->move.h = (u16) STAGE4_MISSILE(reg_a5)->at_start.move.h;
    STAGE4_MISSILE(reg_a5)->now.seen = 0;
    STAGE4_MISSILE(reg_a5)->now.step = 0;
    STAGE4_MISSILE(reg_a5)->now.speed_timer.both = 0U;
    STAGE4_MISSILE(reg_a5)->now.direction = (u8) ENTITY(reg_a6)->move.h;
    STAGE4_MISSILE(reg_a5)->unread_1C = 0x804;
    STAGE4_MISSILE(reg_a5)->unread_1E = 2;
    STAGE4_MISSILE(reg_a5)->unread_20 = 0;
}


s32 enemy_remove();
s32 sprite_draw_with_bullets_zoom();
s32 breakable_bullet_check();
s32 entity_velocity();
s32 direction_to_target_player();
s32 entity_check_bounds();
extern u8 D_0024EBC0[];
extern u16 D_0024EC80[];
extern u16 D_0024EEF0[];
extern u8 g_no_enemy_bullets;

void stage4_boss_missile(void) {
    u16 temp_a0;
    u16 temp_a1;
    u8 temp_v1;
    if (g_no_enemy_bullets == 0) {
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
            ENTITY(reg_a6)->hp.sh = 0x7FFF;
        }
        breakable_bullet_check();
        if (cond_flag == 0) {
            entity_check_bounds();
            if (cond_flag != 0) {
                if (STAGE4_MISSILE(reg_a5)->now.seen != 0) {
block_6:
                    enemy_remove();
                    return;
                }
                goto block_8;
            }
            STAGE4_MISSILE(reg_a5)->now.seen = 1U;
block_8:
            entity_velocity();
            if (STAGE4_MISSILE(reg_a5)->now.step == 0) {
                STAGE4_MISSILE(reg_a5)->now.direction += 4;
                STAGE4_MISSILE(reg_a5)->now.direction &= 0x3F;
                reg_tmp.b[0] = STAGE4_MISSILE(reg_a5)->now.speed_timer.b.countdown;
                STAGE4_MISSILE(reg_a5)->now.speed_timer.b.countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    STAGE4_MISSILE(reg_a5)->now.speed_timer.b.countdown = (u8) STAGE4_MISSILE(reg_a5)->now.speed_timer.b.interval;
                    ENTITY(reg_a6)->move.b.speed -= 1;
                    if (ENTITY(reg_a6)->move.b.speed == 0) {
                        STAGE4_MISSILE(reg_a5)->now.step = 1U;
                        STAGE4_MISSILE(reg_a5)->now.speed_timer.both = 0;
                        direction_to_target_player();
                        STAGE4_MISSILE(reg_a5)->now.direction = (u8) reg_d1.b[0];
                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                    }
                }
            }
            if (STAGE4_MISSILE(reg_a5)->now.step == 1) {
                reg_tmp.b[0] = STAGE4_MISSILE(reg_a5)->now.speed_timer.b.countdown;
                STAGE4_MISSILE(reg_a5)->now.speed_timer.b.countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    STAGE4_MISSILE(reg_a5)->now.speed_timer.b.countdown = (u8) STAGE4_MISSILE(reg_a5)->now.speed_timer.b.interval;
                    temp_v1 = ENTITY(reg_a6)->move.b.speed;
                    if (temp_v1 != 0x24) {
                        ENTITY(reg_a6)->move.b.speed = (u8) (temp_v1 + 1);
                    }
                }
            }
            reg_d1.w = 0;
            reg_d1.b[0] = STAGE4_MISSILE(reg_a5)->now.direction;
            reg_a0 = (u8 *)((u8 *)D_0024EEF0);
            reg_d1.b[0] += 1;
            reg_d1.h[0] &= 0x3E;
            reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            ENTITY(reg_a6)->attr.b.flip = (u8) reg_d0.b[0];
            reg_a0 = (u8 *)((u8 *)D_0024EC80);
            reg_d1.h[0] += reg_d1.h[0];
            reg_d1.h[0] += reg_d1.h[0];
            reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_a0 = (u8 *)D_0024EBC0;
            reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
            reg_d2.h[1] = *(u16 *)reg_a0;
            temp_a1 = *(u16 *)(reg_a0 + 2);
            reg_d2.h[0] = temp_a1;
            reg_d3.h[0] = 0x210;
            reg_d4.w = 0;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            temp_a0 = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] = temp_a0;
            reg_d1.w += 0xFE00FE00;
            reg_d6.w = 0xF800F800;
            sprite_draw_with_bullets_zoom();
            return;
        }
        goto block_6;
    }
    goto block_6;
}

void stage4_boss_cutter_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(4);
}

s32 velocity_from_dir256();
extern u8 stage4_boss_cutter_start_table[];

void stage4_boss_cutter_start(void) {
    u8 temp_a0;

    reg_a0 = (u8 *)stage4_boss_cutter_start_table;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) STAGE4_CUTTER(reg_a5)->at_start.y;
    ENTITY(reg_a6)->x.h = (u16) STAGE4_CUTTER(reg_a5)->at_start.x;
    ENTITY(reg_a6)->move.sb.speed = 0;
    STAGE4_CUTTER(reg_a5)->now.seen = 0;
    STAGE4_CUTTER(reg_a5)->now.unread_16 = 0;
    ENTITY(reg_a6)[1].attr.b.flip = (u8) STAGE4_CUTTER(reg_a5)->at_start.look;
    reg_d0.w = 0;
    reg_d0.b[0] = STAGE4_CUTTER(reg_a5)->at_start.turn;
    reg_d0.h[0] = (u16) (s8) reg_d0.b[0];
    ENTITY(reg_a6)[1].offset_y.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[1].hp.h = (u16) ENTITY(reg_a6)[1].offset_y.h;
    ENTITY(reg_a6)[2].offset_x.h = (u16) ENTITY(reg_a6)[1].offset_y.h;
    ENTITY(reg_a6)[3].sprite.sh = 0;
    if ((s16) ENTITY(reg_a6)[1].offset_y.h < 0) {
        ENTITY(reg_a6)[3].sprite.sh = 1;
    }
    reg_d0.w = 0;
    reg_d0.b[0] = STAGE4_CUTTER(reg_a5)->at_start.radius;
    reg_d0.h[0] = (u16) reg_d0.b[0];
    if ((reg_d0.b[0] == 0x10) || (reg_d0.b[0] == 0x65) || (reg_d0.b[0] == 0xBB) || (reg_d0.b[0] == -0x10U) || (reg_d0.b[0] == 0x45) || (reg_d0.b[0] == 0x9B)) {
        ENTITY(reg_a6)[4].sprite.sb[0] = 1;
    }
    reg_d0.h[0] = (s16) reg_d0.h[0] * 0x10;
    ENTITY(reg_a6)[1].offset_x.h = (u16) reg_d0.h[0];
    STAGE4_CUTTER(reg_a5)->now.unread_18 = 0;
    STAGE4_CUTTER(reg_a5)->now.angle = (u8) STAGE4_CUTTER(reg_a5)->at_start.angle;
    reg_d0.w = 0;
    reg_d0.b[0] = STAGE4_CUTTER(reg_a5)->now.angle;
    reg_d1.h[0] = ENTITY(reg_a6)[1].offset_x.h;
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 4);
    velocity_from_dir256();
    reg_d2.h[0] = (s16) reg_d2.h[0] * 8;
    reg_d0.h[0] = 0x2000;
    reg_d3.h[0] = (s16) reg_d3.h[0] * 8;
    STAGE4_CUTTER(reg_a5)->now.y_offset = (u16) reg_d0.h[0];
    reg_tmp.h[1] = STAGE4_CUTTER(reg_a5)->now.owner[0];
    reg_tmp.h[0] = STAGE4_CUTTER(reg_a5)->now.owner[1];
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d2.h[0] += ENTITY(reg_a0)[1].y.h;
    reg_d2.h[0] -= (u16) STAGE4_CUTTER(reg_a5)->now.y_offset;
    reg_d3.h[0] += ENTITY(reg_a0)[1].x.h;
    ENTITY(reg_a6)->y.h = (u16) reg_d2.h[0];
    ENTITY(reg_a6)->x.h = (u16) reg_d3.h[0];
    STAGE4_CUTTER(reg_a5)->unread_22 = 0x404;
    STAGE4_CUTTER(reg_a5)->released = 0;
    STAGE4_CUTTER(reg_a5)->unread_3A = 0x18;
    STAGE4_CUTTER(reg_a5)->frame = 0;
    STAGE4_CUTTER(reg_a5)->frame_timer.both = 0;
    temp_a0 = ENTITY(reg_a6)[1].attr.b.flip;
    if ((temp_a0 != 0x70) && (temp_a0 != 0x71)) {
        ENTITY(reg_a6)->flags.h = 0x8000;
    }
}

s32 bullet_fire256_fixed();
s32 bullet_fire256_fast();
s32 bullet_fire256_2way();
s32 explosion_spawn();
s32 enemy_hitbox_debug_draw();
s32 sfx_explosion_air_small();
s32 sprite_draw_layer3();
s32 sprite_draw_with_bullets();
s32 score_add_no_chain();
s32 score_add();
s32 entity_advance256();
s32 direction256_between();
s32 distance_between();
extern u8 stage4_boss_cutter_table[];
extern u16 stage4_boss_cutter_table_2[];
extern u16 g_game_frame;
extern u16 g_enemy_signal_e;
extern u16 g_enemy_signal_d;
extern u16 g_enemy_signal_c;
extern u16 g_enemy_signal_9;
extern u16 g_enemy_signal_8;
extern u8 g_enemy_signal_6_as_u8;
extern u8 D_0028E87D;
extern u16 g_enemies_stopped;
extern u16 g_side_scroll_step[];
extern u16 *reg_a4_as_u16_p;

void stage4_boss_cutter(void) {
    switch (g_enemy_signal_c) { case 0: goto next_10; }
    g_enemy_signal_8 = 0;
    g_enemy_signal_9 = 0;
    if (ENTITY(reg_a6)->misc.b.draw_layer == 0) goto next_5;
    reg_d0.w = 2;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->move.h = ENTITY(reg_a6)->move.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
next_5:
    enemy_remove();
    return;
next_10:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto next_100;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.h[0] = 0x7FFF;
    reg_d0.h[0] -= ENTITY(reg_a6)->hp.h;
    if (!((s16) g_enemy_signal_8 < (s16) reg_d0.h[0])) goto next_20;
    g_enemy_signal_8 = reg_d0.h[0];
    g_enemy_signal_9 = reg_d1.h[0];
next_20:
    ENTITY(reg_a6)->hp.h = 0x7FFF;
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    reg_d2.b[0] = ENTITY(reg_a6)[1].misc.b.draw_layer;
    reg_d0.b[0] ^= reg_d2.b[0];
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    if (ENTITY(reg_a6)->hp.sh >= 0) goto next_110;
    reg_d0.w = 0x20;
    score_add();
    reg_d0.w = 2;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->move.h = ENTITY(reg_a6)->move.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    sfx_explosion_air_small();
    if (g_enemy_signal_e == 2) goto next_30;
    enemy_remove();
    return;
next_30:
    ENTITY(reg_a6)->flags.h = 0x8000;
    ENTITY(reg_a6)->hp.h = 0xFFFF;
    ENTITY(reg_a6)->misc.b.draw_layer = 0;
next_100:
    ENTITY(reg_a6)->attr.b.palette = ENTITY(reg_a6)[1].misc.b.user;
next_110:
    if (STAGE4_CUTTER(reg_a5)->released != 1) goto next_130;
    if (ENTITY(reg_a6)->x.sh <= -0x400) goto block_b;
    if (!(ENTITY(reg_a6)->x.sh < 0x3C00)) goto block_b;
    entity_check_bounds();
    if ((s8) (*(u8 *)&cond_flag) == 0) goto next_120;
    if (STAGE4_CUTTER(reg_a5)->now.seen == 0) goto next_130;
block_b:
    enemy_remove();
    return;
next_120:
    STAGE4_CUTTER(reg_a5)->now.seen = 1;
next_130:
    if (g_enemies_stopped != 0) goto block_c;
    reg_tmp.h[1] = STAGE4_CUTTER(reg_a5)->now.owner[0];
    reg_tmp.h[0] = STAGE4_CUTTER(reg_a5)->now.owner[1];
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    STAGE4_CUTTER(reg_a5)->center_y = ENTITY(reg_a0)[1].y.h;
    STAGE4_CUTTER(reg_a5)->center_x = ENTITY(reg_a0)[1].x.h;
    reg_d0.h[0] = STAGE4_CUTTER(reg_a5)->now.y_offset;
    STAGE4_CUTTER(reg_a5)->center_y -= reg_d0.h[0];
    reg_d0.w = 0;
    reg_d0.b[0] = STAGE4_CUTTER(reg_a5)->now.angle;
    reg_d1.h[0] = ENTITY(reg_a6)[1].offset_x.h;
    reg_d1.h[0] = (s16) reg_d1.h[0] >> 4;
    velocity_from_dir256();
    reg_d2.h[0] = (s16) reg_d2.h[0] * 8;
    reg_d3.h[0] = (s16) reg_d3.h[0] * 8;
    if (STAGE4_CUTTER(reg_a5)->released != 1) goto next_140;
    reg_d0.h[0] = g_side_scroll_step[0];
    ENTITY(reg_a6)[1].hit_y_minus.h -= reg_d0.h[0];
    reg_d2.h[0] += ENTITY(reg_a6)[1].hit_y_plus.h;
    reg_d3.h[0] += ENTITY(reg_a6)[1].hit_y_minus.h;
    goto next_150;
next_140:
    reg_tmp.h[1] = STAGE4_CUTTER(reg_a5)->now.owner[0];
    reg_tmp.h[0] = STAGE4_CUTTER(reg_a5)->now.owner[1];
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d2.h[0] += ENTITY(reg_a0)[1].y.h;
    reg_d3.h[0] += ENTITY(reg_a0)[1].x.h;
next_150:
    reg_d2.h[0] -= STAGE4_CUTTER(reg_a5)->now.y_offset;
    ENTITY(reg_a6)->offset_y.h = reg_d2.h[0];
    ENTITY(reg_a6)->offset_x.h = reg_d3.h[0];
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.h[0] = ENTITY(reg_a6)->offset_y.h;
    reg_d3.h[0] = ENTITY(reg_a6)->offset_x.h;
    direction256_between();
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.h[0] = ENTITY(reg_a6)->offset_y.h;
    reg_d3.h[0] = ENTITY(reg_a6)->offset_x.h;
    distance_between();
    ENTITY(reg_a6)->move.b.speed = 0x40;
    reg_a4_as_u16_p = (u16 *)stage4_boss_cutter_table_2;
loop_160:
    reg_d1.h[0] = *reg_a4_as_u16_p++;
    if ((s16) reg_d1.h[0] == -1) goto next_170;
    reg_d2.h[0] = *reg_a4_as_u16_p++;
    if ((s16) reg_d1.h[0] < (s16) reg_d0.h[0]) goto loop_160;
    ENTITY(reg_a6)->move.b.speed = reg_d2.b[0];
next_170:
    entity_advance256();
    reg_d0.h[0] = ENTITY(reg_a6)[1].offset_y.h;
    ENTITY(reg_a6)[1].offset_x.h += reg_d0.h[0];
    ENTITY(reg_a6)[1].offset_x.h &= 0xFFF;
    reg_tmp.b[0] = ENTITY(reg_a6)[1].move.b.speed;
    ENTITY(reg_a6)[1].move.b.speed -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_190;
    ENTITY(reg_a6)[1].move.b.speed = ENTITY(reg_a6)[1].move.b.dir;
    reg_d0.h[0] = ENTITY(reg_a6)[1].hp.h;
    reg_d1.h[0] = ENTITY(reg_a6)[1].offset_y.h;
    if (reg_d0.h[0] == reg_d1.h[0]) goto next_190;
    if ((s16) reg_d0.h[0] < (s16) reg_d1.h[0]) goto next_180;
    ENTITY(reg_a6)[1].offset_y.h += 1;
    goto next_190;
next_180:
    ENTITY(reg_a6)[1].offset_y.h -= 1;
next_190:
    reg_d0.h[0] = ENTITY(reg_a6)[1].offset_x.h;
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 4;
    reg_d0.h[0] = reg_d0.b[0];
    if (!((s16) reg_d0.h[0] < 0xFF)) goto next_200;
    if (!((s16) reg_d0.h[0] < 2)) goto next_210;
next_200:
    if (ENTITY(reg_a6)->misc.b.draw_layer != 0) goto next_210;
    ENTITY(reg_a6)->misc.b.draw_layer = 1;
    ENTITY(reg_a6)->hp.h = 0x7FFF;
    ENTITY(reg_a6)->flags.h = 0xA001;
    reg_tmp.h[1] = STAGE4_CUTTER(reg_a5)->now.owner[0];
    reg_tmp.h[0] = STAGE4_CUTTER(reg_a5)->now.owner[1];
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    STAGE4_EXTRA(reg_a0)->cutters_gone += 1;
next_210:
    if (STAGE4_CUTTER(reg_a5)->released != 1) goto next_250;
    if (ENTITY(reg_a6)[2].hit_x_minus.h == 0) goto next_220;
    ENTITY(reg_a6)[2].hit_x_minus.h -= 1;
    if (ENTITY(reg_a6)[2].hit_x_minus.h != 0) goto next_250;
    ENTITY(reg_a6)[1].offset_y.h = ENTITY(reg_a6)[2].offset_x.h;
    ENTITY(reg_a6)[1].hp.h = ENTITY(reg_a6)[2].offset_x.h;
    ENTITY(reg_a6)[3].hit_y_plus.b[0] = 0;
    goto next_250;
next_220:
    if (ENTITY(reg_a6)[3].hit_y_plus.b[0] != 0) goto next_230;
    STAGE4_CUTTER(reg_a5)->now.angle -= 1;
    if (!((s8) STAGE4_CUTTER(reg_a5)->now.angle < 9)) goto next_230;
    STAGE4_CUTTER(reg_a5)->now.angle = 8;
    ENTITY(reg_a6)[3].hit_y_plus.b[0] = 1;
    ENTITY(reg_a6)[3].misc.b.user = 0x40;
    ENTITY(reg_a6)[3].misc.b.draw_layer = 0;
next_230:
    if (ENTITY(reg_a6)[3].hit_y_plus.b[0] != 1) goto next_250;
    reg_d0.w = 0;
    reg_d0.b[0] = STAGE4_CUTTER(reg_a5)->now.angle;
    reg_d0.h[0] += 2;
    if (!((s16) reg_d0.h[0] < 0x100)) goto block_b;
    STAGE4_CUTTER(reg_a5)->now.angle = reg_d0.b[0];
next_250:
    if (STAGE4_CUTTER(reg_a5)->released == 1) goto next_260;
    if (g_enemy_signal_e != 1) goto next_260;
    STAGE4_CUTTER(reg_a5)->released = 1;
    ENTITY(reg_a6)[2].offset_x.h = ENTITY(reg_a6)[1].offset_y.h;
    ENTITY(reg_a6)[1].offset_y.h = 0;
    ENTITY(reg_a6)[1].hp.h = 0;
    ENTITY(reg_a6)[2].hit_x_minus.h = 0x60;
    reg_tmp.h[1] = STAGE4_CUTTER(reg_a5)->now.owner[0];
    reg_tmp.h[0] = STAGE4_CUTTER(reg_a5)->now.owner[1];
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    ENTITY(reg_a6)[1].hit_y_plus.h = ENTITY(reg_a0)[1].y.h;
    ENTITY(reg_a6)[1].hit_y_minus.h = ENTITY(reg_a0)[1].x.h;
next_260:
    if (g_enemy_signal_e != 2) goto next_300;
    if (ENTITY(reg_a6)[3].sprite.h == 0) goto next_300;
    reg_tmp.b[0] = ENTITY(reg_a6)[3].hit_x_plus.b[1];
    ENTITY(reg_a6)[3].hit_x_plus.b[1] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_270;
    ENTITY(reg_a6)[3].hit_x_plus.b[1] = ENTITY(reg_a6)[3].hit_x_plus.b[0];
    if (ENTITY(reg_a6)->misc.b.draw_layer == 0) goto next_270;
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.h[0] = ENTITY(reg_a6)[1].offset_x.h;
    reg_d1.h[0] = (s16) reg_d1.h[0] >> 4;
    reg_d1.h[0] += 0x80;
    reg_d1.h[0] = reg_d1.b[0];
    reg_d0.w = 0x20003;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = 0;
    reg_d4.w = 0;
next_270:
    reg_tmp.b[0] = ENTITY(reg_a6)[2].misc.b.user;
    ENTITY(reg_a6)[2].misc.b.user -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_300;
    ENTITY(reg_a6)[2].misc.b.user = ENTITY(reg_a6)[2].misc.b.draw_layer;
    if (ENTITY(reg_a6)->misc.b.draw_layer == 0) goto next_300;
    reg_d1.h[0] = ENTITY(reg_a6)[1].offset_x.h;
    reg_d1.h[0] = (s16) reg_d1.h[0] >> 4;
    reg_d1.h[0] = reg_d1.b[0];
    reg_d1.b[0] += 0x80;
    reg_d0.w = 0xFFFA0023;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = 0;
    reg_d4.w = 0;
next_300:
    if (g_enemy_signal_e != 2) goto next_600;
    if (ENTITY(reg_a6)[3].sprite.h != 0) goto next_600;
    if (ENTITY(reg_a6)[4].offset_y.h != 0) goto next_310;
    reg_tmp.b[0] = ENTITY(reg_a6)[4].draw.b.priority;
    ENTITY(reg_a6)[4].draw.b.priority -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_310;
    ENTITY(reg_a6)[4].draw.b.priority = ENTITY(reg_a6)[4].draw.b.flip;
    ENTITY(reg_a6)[4].offset_y.h = 1;
next_310:
    if (ENTITY(reg_a6)[4].offset_y.h != 1) goto next_330;
    reg_tmp.b[0] = ENTITY(reg_a6)[4].offset_x.b[1];
    ENTITY(reg_a6)[4].offset_x.b[1] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_330;
    ENTITY(reg_a6)[4].offset_x.b[1] = ENTITY(reg_a6)[4].offset_x.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[4].sprite.b[1];
    STAGE4_CUTTER(reg_a5)->now.angle += reg_d0.b[0];
    if (ENTITY(reg_a6)[4].sprite.sb[1] >= 0) goto next_320;
    reg_d0.w = 0;
    reg_d0.b[0] = STAGE4_CUTTER(reg_a5)->now.angle;
    if (!((s16) reg_d0.h[0] < 0x21)) goto next_330;
    ENTITY(reg_a6)[4].sprite.b[1] *= -1;
    ENTITY(reg_a6)[4].offset_y.h = 0;
    goto next_330;
next_320:
    reg_d0.w = 0;
    reg_d0.b[0] = STAGE4_CUTTER(reg_a5)->now.angle;
    if ((s16) reg_d0.h[0] < 0x60) goto next_330;
    ENTITY(reg_a6)[4].sprite.b[1] *= -1;
    ENTITY(reg_a6)[4].offset_y.h = 0;
next_330:
    if (ENTITY(reg_a6)[3].offset_y.h != 0) goto next_340;
    if (g_enemy_signal_d == 0) goto next_340;
    ENTITY(reg_a6)[3].offset_y.h = 1;
    ENTITY(reg_a6)[3].attr.h = 1;
next_340:
    if (ENTITY(reg_a6)[3].offset_y.h != 1) goto next_350;
    reg_tmp.b[0] = ENTITY(reg_a6)[3].look.b.size;
    ENTITY(reg_a6)[3].look.b.size -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_350;
    ENTITY(reg_a6)[3].look.b.size = ENTITY(reg_a6)[3].look.b.palette;
    reg_d0.h[0] = ENTITY(reg_a6)[3].draw.h;
    ENTITY(reg_a6)[1].hp.h -= reg_d0.h[0];
    if (!(ENTITY(reg_a6)[1].hp.sh < 5)) goto next_350;
    ENTITY(reg_a6)[3].offset_y.h = 2;
    ENTITY(reg_a6)[3].look.b.size = 0x60;
next_350:
    if (ENTITY(reg_a6)[3].offset_y.h != 2) goto next_370;
    reg_tmp.b[0] = ENTITY(reg_a6)[3].look.b.size;
    ENTITY(reg_a6)[3].look.b.size -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_370;
    ENTITY(reg_a6)[3].look.b.size = ENTITY(reg_a6)[3].look.b.palette;
    reg_d0.h[0] = ENTITY(reg_a6)[3].draw.h;
    ENTITY(reg_a6)[1].hp.h -= reg_d0.h[0];
    reg_d0.h[0] = ENTITY(reg_a6)[1].hp.h;
    if ((s16) reg_d0.h[0] >= 0) goto next_360;
    reg_d0.h[0] *= 0xFFFF;
next_360:
    reg_d1.h[0] = ENTITY(reg_a6)[3].hp.h;
    if ((s16) reg_d1.h[0] > (s16) reg_d0.h[0]) goto next_370;
    ENTITY(reg_a6)[3].offset_y.h = 0;
    ENTITY(reg_a6)[3].draw.h *= 0xFFFF;
    if (ENTITY(reg_a6)[3].hp.h == 0x10) goto next_370;
    ENTITY(reg_a6)[3].hp.h += 2;
next_370:
    reg_d7.b[0] = ENTITY(reg_a6)[1].attr.b.flip;
    if (reg_d7.b[0] == 0x70) goto next_380;
    if (reg_d7.b[0] != 0x71) goto next_400;
next_380:
    reg_d1.h[0] = ENTITY(reg_a6)[1].offset_x.h;
    reg_d1.h[0] = (s16) reg_d1.h[0] >> 4;
    reg_d1.h[0] = reg_d1.b[0];
    reg_d1.b[0] += ENTITY(reg_a6)[2].move.b.speed;
    if (reg_d7.b[0] == 0x70) goto next_390;
    g_enemy_signal_6_as_u8 = reg_d1.b[0];
    goto next_400;
next_390:
    D_0028E87D = reg_d1.b[0];
next_400:
    reg_tmp.b[0] = ENTITY(reg_a6)[4].look.b.size;
    ENTITY(reg_a6)[4].look.b.size -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_500;
    ENTITY(reg_a6)[4].look.b.size = ENTITY(reg_a6)[4].look.b.palette;
    reg_d7.b[0] = ENTITY(reg_a6)[1].attr.b.flip;
    if (reg_d7.b[0] == 0x70) goto next_500;
    if (reg_d7.b[0] == 0x71) goto next_500;
    if (ENTITY(reg_a6)->misc.b.draw_layer == 0) goto next_500;
    reg_d1.w = 0;
    reg_d1.b[0] = D_0028E87D;
    if (ENTITY(reg_a6)[1].attr.sb.flip <= 3) goto next_410;
    reg_d1.b[0] = g_enemy_signal_6_as_u8;
next_410:
    reg_d1.b[0] += 0x80;
    reg_d0.w = 0xFFFD0007;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = 0;
    reg_d4.w = 0;
    reg_d6.w = 0;
    if (ENTITY(reg_a6)[1].attr.b.flip != 0) goto next_420;
    reg_d1.b[0] -= 0x10;
    reg_d6.w = 1;
next_420:
    if (ENTITY(reg_a6)[1].attr.b.flip != 1) goto next_430;
    reg_d1.b[0] -= 4;
next_430:
    if (ENTITY(reg_a6)[1].attr.b.flip != 2) goto next_440;
    reg_d1.b[0] += 4;
next_440:
    if (ENTITY(reg_a6)[1].attr.b.flip != 3) goto next_450;
    reg_d1.b[0] += 0x10;
    reg_d6.w = 1;
next_450:
    if (ENTITY(reg_a6)[1].attr.b.flip != 4) goto next_460;
    reg_d1.b[0] -= 0x10;
    reg_d6.w = 1;
next_460:
    if (ENTITY(reg_a6)[1].attr.b.flip != 5) goto next_470;
    reg_d1.b[0] -= 4;
next_470:
    if (ENTITY(reg_a6)[1].attr.b.flip != 6) goto next_480;
    reg_d1.b[0] += 4;
next_480:
    if (ENTITY(reg_a6)[1].attr.b.flip != 7) goto next_490;
    reg_d1.b[0] += 0x10;
    reg_d6.w = 1;
next_490:
    if (reg_d6.h[0] != 0) goto next_495;
    bullet_fire256_fixed();
    goto next_500;
next_495:
    bullet_fire256_2way();
next_500:
    if (ENTITY(reg_a6)->misc.b.draw_layer == 0) goto next_600;
    reg_tmp.b[0] = ENTITY(reg_a6)[2].hp.b[1];
    ENTITY(reg_a6)[2].hp.b[1] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_600;
    ENTITY(reg_a6)[2].hp.b[1] = ENTITY(reg_a6)[2].hp.b[0];
    reg_d1.h[0] = ENTITY(reg_a6)[1].offset_x.h;
    reg_d1.h[0] = (s16) reg_d1.h[0] >> 4;
    reg_d1.h[0] = reg_d1.b[0];
    reg_d0.w = 0xFFFE000B;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = 0;
    reg_d4.w = 0;
next_600:
    if (g_enemy_signal_e == 2) goto block_c;
    if (ENTITY(reg_a6)->misc.b.draw_layer == 0) goto block_c;
    if (STAGE4_CUTTER(reg_a5)->released == 1) goto next_620;
    if (ENTITY(reg_a6)[2].look.b.size != 0) goto next_650;
    reg_d0.h[0] = g_game_frame;
    reg_d0.h[0] &= 0x1F;
    if (reg_d0.h[0] != 0) goto block_c;
    goto next_640;
next_620:
    reg_d1.h[0] = ENTITY(reg_a6)[1].offset_x.h;
    reg_d1.h[0] = (s16) reg_d1.h[0] >> 4;
    reg_d1.h[0] = reg_d1.b[0];
    ENTITY(reg_a6)[2].hit_y_plus.b[1] = reg_d1.b[0];
    reg_d0.h[0] = g_game_frame;
    reg_d0.h[0] &= 3;
    if (reg_d0.h[0] != 0) goto block_c;
    reg_d0.w = 7;
    reg_d1.b[0] = ENTITY(reg_a6)[2].hit_y_plus.b[1];
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = 0;
    reg_d4.w = 0;
    if (ENTITY(reg_a6)[3].hit_y_plus.b[0] != 1) goto next_630;
    reg_d1.b[0] += 0x80;
    reg_d0.w += 0xFFFA0000;
    if (ENTITY(reg_a6)->y.sh <= 0x600) goto block_c;
    if (ENTITY(reg_a6)[4].sprite.b[0] != 0) goto block_c;
next_630:
    bullet_fire256_2way();
    goto block_c;
next_640:
    ENTITY(reg_a6)[2].look.b.size = ENTITY(reg_a6)[2].look.b.palette;
    reg_d1.h[0] = ENTITY(reg_a6)[1].offset_x.h;
    reg_d1.h[0] = (s16) reg_d1.h[0] >> 4;
    reg_d1.h[0] = reg_d1.b[0];
    ENTITY(reg_a6)[2].hit_y_plus.b[1] = reg_d1.b[0];
next_650:
    reg_tmp.b[0] = ENTITY(reg_a6)[2].sprite.b[1];
    ENTITY(reg_a6)[2].sprite.b[1] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_c;
    ENTITY(reg_a6)[2].sprite.b[1] = ENTITY(reg_a6)[2].sprite.b[0];
    reg_d0.w = 7;
    reg_d1.b[0] = ENTITY(reg_a6)[2].hit_y_plus.b[1];
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = 0;
    reg_d4.w = 0;
    bullet_fire256_fast();
    ENTITY(reg_a6)[2].look.b.size -= 1;
block_c:
    reg_tmp.b[0] = STAGE4_CUTTER(reg_a5)->frame_timer.b.countdown;
    STAGE4_CUTTER(reg_a5)->frame_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_700;
    STAGE4_CUTTER(reg_a5)->frame_timer.b.countdown = STAGE4_CUTTER(reg_a5)->frame_timer.b.interval;
    STAGE4_CUTTER(reg_a5)->frame += 4;
    STAGE4_CUTTER(reg_a5)->frame &= 0x1F;
next_700:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    if (ENTITY(reg_a6)->misc.b.draw_layer == 0) goto block_rts;
    if (ENTITY(reg_a6)[1].attr.b.flip == 0x70) goto block_rts;
    if (ENTITY(reg_a6)[1].attr.b.flip == 0x71) goto block_rts;
    reg_a0 = (u8 *)stage4_boss_cutter_table;
    reg_a0 += STAGE4_CUTTER(reg_a5)->frame;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = 0x620;
    reg_d4.w = 0;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFA00FC00;
    if (ENTITY(reg_a6)[3].hit_y_plus.b[0] == 1) goto next_710;
    sprite_draw_layer3();
    return;
next_710:
    sprite_draw_with_bullets();
block_rts:
    return;
}

u8 stage4_boss_missile_start_table[32] = {
    0x01, 0x80, 0x00, 0xFC, 0x00, 0xFE, 0x00, 0x00, 0xB8, 0x01, 0x10, 0x04, 0x80, 0x00, 0x80, 0x00,
    0x80, 0x00, 0x80, 0x00, 0xFF, 0x7F, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage4_boss_cutter_start_table[144] = {
    0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB8, 0x01, 0x10, 0x04, 0x00, 0x02, 0x00, 0x01,
    0x00, 0x01, 0x00, 0x01, 0xFF, 0x7F, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x01,
    0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x13, 0x00, 0x80, 0x38, 0x38, 0x00, 0x00, 0x20, 0x40,
    0x02, 0x02, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x80, 0x80, 0x00, 0x00, 0x08, 0x08, 0x00, 0x00,
    0x04, 0x04, 0x0E, 0x0E, 0x00, 0x80, 0x00, 0x00, 0x80, 0x01, 0x01, 0x00, 0x00, 0x00, 0x04, 0x04,
    0x00, 0x18, 0x01, 0x01, 0x05, 0x05, 0x03, 0x03, 0x0A, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x00, 0x00, 0x01, 0x01, 0x40, 0x40, 0x00, 0x01, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage4_boss_cutter_table[32] = {
    0x00, 0x00, 0x42, 0x1D, 0x00, 0x00, 0x43, 0x1D, 0x00, 0x00, 0x44, 0x1D, 0x00, 0x00, 0x45, 0x1D,
    0x00, 0x00, 0x46, 0x1D, 0x00, 0x00, 0x47, 0x1D, 0x00, 0x00, 0x48, 0x1D, 0x00, 0x00, 0x49, 0x1D,
};

u16 stage4_boss_cutter_table_2[56] = {
    0x0040, 0x0001, 0x0080, 0x0002, 0x00C0, 0x0004, 0x0100, 0x0006,
    0x0140, 0x0008, 0x0180, 0x000A, 0x01C0, 0x000C, 0x0200, 0x000E,
    0x0240, 0x0010, 0x0280, 0x0012, 0x02C0, 0x0014, 0x0300, 0x0016,
    0x0340, 0x0018, 0x0380, 0x001A, 0x03C0, 0x001C, 0x0400, 0x001E,
    0x0440, 0x0020, 0x0480, 0x0022, 0x04C0, 0x0024, 0x0500, 0x0026,
    0x0540, 0x0028, 0x0580, 0x002A, 0x05C0, 0x002C, 0x0600, 0x002E,
    0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};
