#include "common.h"
#include "entity.h"
#include "explosion.h"
#include "stage1_boss.h"

void stage1_boss_breakable_bullet_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 enemy_init_entities();
extern u16 D_0024EBC0[];
extern u16 D_0024EC80[];
extern u16 D_0024EEF0[];
extern u16 stage1_boss_breakable_bullet_start_table[];

void stage1_boss_breakable_bullet_start(void) {
    reg_a0 = (u8 *)(stage1_boss_breakable_bullet_start_table);
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) BREAKABLE_BULLET(reg_a5)->at_start.y;
    ENTITY(reg_a6)->x.h = (u16) BREAKABLE_BULLET(reg_a5)->at_start.x;
    ENTITY(reg_a6)->move.h = (u16) BREAKABLE_BULLET(reg_a5)->at_start.move;
    reg_d1.w = 0;
    reg_d1.b[0] = (u8) ENTITY(reg_a6)->move.h;
    reg_a0 = (u8 *)(D_0024EEF0);
    reg_d1.b[0] += 1;
    reg_d1.h[0] &= 0xFE;
    reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->attr.b.flip = (u8) reg_d0.b[0];
    reg_a0 = (u8 *)(D_0024EC80);
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(((u16 *)D_0024EBC0));
    BREAKABLE_BULLET(reg_a5)->now.frame_list[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    BREAKABLE_BULLET(reg_a5)->now.frame_list[1] = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    BREAKABLE_BULLET(reg_a5)->frame_timer.both = 2;
    BREAKABLE_BULLET(reg_a5)->frame = 0;
    BREAKABLE_BULLET(reg_a5)->unread_22 = 2;
}


s32 explosion_spawn();
s32 enemy_remove();
s32 entity_draw_layer4();
s32 breakable_bullet_check();
s32 entity_velocity();
extern u8 g_boss_present_b1;
extern u16 g_enemies_stopped;

#define W(o) (*(u16 *)(reg_a6 + (o)))
#define B(o) (*(u8 *)(reg_a6 + (o)))

void stage1_boss_breakable_bullet(void) {
    if (!(g_boss_present_b1 & 0x40)) goto block_5;
    reg_d1.b[0] = B(1);
    breakable_bullet_check();
    if (cond_flag != 0) goto block_6;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= B(1);
    if (reg_d1.b[0] == 0) goto next_1;
    reg_d0.b[0] = 0xA3;
    B(1) &= reg_d0.b[0];
    if ((s32) B(0x19) >= 0) goto next_1;
block_5:
    reg_d0.w = 1;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = W(2);
    EXPLOSION(reg_a0)->x = W(4);
    EXPLOSION(reg_a0)->move.b.speed = B(0x1B);
    reg_d0.b[0] = B(0x1A);
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += reg_d0.b[0];
    EXPLOSION(reg_a0)->move.b.dir = reg_d0.b[0];
    EXPLOSION(reg_a0)->draw_layer = 0xC;
block_6:
    enemy_remove();
    return;
next_1:
    if (g_enemies_stopped != 0) goto next_2;
    entity_velocity();
    if (!((s16) W(2) < -0x400)) goto next_3;
    enemy_remove();
    return;
next_3:
    reg_tmp.b[0] = BREAKABLE_BULLET(reg_a5)->frame_timer.b.countdown;
    BREAKABLE_BULLET(reg_a5)->frame_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_2;
    BREAKABLE_BULLET(reg_a5)->frame_timer.b.countdown = BREAKABLE_BULLET(reg_a5)->frame_timer.b.interval;
    EXPLOSION(reg_a0)->kind.h = BREAKABLE_BULLET(reg_a5)->now.frame_list[0];
    EXPLOSION(reg_a0)->y = BREAKABLE_BULLET(reg_a5)->now.frame_list[1];
    reg_d0.h[0] = BREAKABLE_BULLET(reg_a5)->frame;
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : EXPLOSION(reg_a0)->kind.h;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : EXPLOSION(reg_a0)->kind.h;
    BREAKABLE_BULLET(reg_a5)->frame += 4;
    BREAKABLE_BULLET(reg_a5)->frame &= 0xF;
next_2:
    entity_draw_layer4();
}

void stage1_boss_breakable_bullet_b_first(void) {
    extern void enemy_set_entity_count(s32 flag);
    enemy_set_entity_count(1);
}

extern u8 D_0024ED80[];
extern u16 D_0024EEB0[];
extern u8 stage1_boss_breakable_bullet_b_start_table[];

void stage1_boss_breakable_bullet_b_start(void) {
    reg_a0 = stage1_boss_breakable_bullet_b_start_table;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) BREAKABLE_BULLET_B(reg_a5)->at_start.y;
    ENTITY(reg_a6)->x.h = (u16) BREAKABLE_BULLET_B(reg_a5)->at_start.x;
    ENTITY(reg_a6)->move.h = (u16) BREAKABLE_BULLET_B(reg_a5)->at_start.move;
    BREAKABLE_BULLET_B(reg_a5)->unread_2C = (u16) BREAKABLE_BULLET_B(reg_a5)->at_start.word_24;
    BREAKABLE_BULLET_B(reg_a5)->unread_2E = (u16) BREAKABLE_BULLET_B(reg_a5)->at_start.word_26;
    BREAKABLE_BULLET_B(reg_a5)->now.burst_speed = (u16) BREAKABLE_BULLET_B(reg_a5)->at_start.burst_speed;
    reg_d0.h[0] = BREAKABLE_BULLET_B(reg_a5)->at_start.word_1E;
    reg_d0.h[0] += 0x20;
    BREAKABLE_BULLET_B(reg_a5)->now.unread_26 = (u16) reg_d0.h[0];
    BREAKABLE_BULLET_B(reg_a5)->scatter = (u8) BREAKABLE_BULLET_B(reg_a5)->at_start.scatter;
    BREAKABLE_BULLET_B(reg_a5)->unread_28 = 0;
    reg_d1.w = 0;
    reg_d1.b[0] = (u8) ENTITY(reg_a6)->move.h;
    reg_a0 = D_0024ED80;
    reg_a1 = (u8 *)(D_0024EEB0);
    reg_d1.h[0] = (u16) reg_d1.b[0];
    reg_d1.h[0] += 4;
    reg_d1.h[0] = (u16) ((s32) reg_d1.h[0] >> 2);
    reg_d1.h[0] &= 0x3E;
    reg_a1 += reg_d1.h[0];
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a0 += reg_d1.h[0];
    reg_d0.h[1] = *(u16 *)reg_a0;
    reg_d0.h[0] = *(u16 *)(reg_a0 + 2);
    ENTITY(reg_a6)->draw.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_d0.h[0];
    reg_d0.w += 3;
    BREAKABLE_BULLET_B(reg_a5)->now.last_sprite[0] = (u16) reg_d0.h[1];
    BREAKABLE_BULLET_B(reg_a5)->now.last_sprite[1] = (u16) reg_d0.h[0];
    BREAKABLE_BULLET_B(reg_a5)->now.frame_timer.both = 2U;
    BREAKABLE_BULLET_B(reg_a5)->now.frame = 0;
    BREAKABLE_BULLET_B(reg_a5)->now.unread_22 = 0;
}

s32 bullet_fire256_fixed();
s32 enemy_hitbox_debug_draw();
s32 entity_draw_with_bullets();
s32 score_add_no_chain();
s32 rng_next();
s32 velocity_from_dir256();
s32 entity_check_bounds();

#define W(o) (*(u16 *)(reg_a6 + (o)))
#define B(o) (*(u8 *)(reg_a6 + (o)))

void stage1_boss_breakable_bullet_b(void) {
    u32 count;

    W(0x22) = W(2);
    W(0x24) = W(4);
    if (!(g_boss_present_b1 & 0x40)) goto block_20;
    reg_d1.b[0] = B(1);
    breakable_bullet_check();
    if (cond_flag != 0) goto block_end;
    B(0x1C) = B(0x3D);
    reg_d1.b[0] = B(1);
    reg_d1.b[0] |= B(0x21);
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] == 0) goto next_100;
    reg_d0.b[0] = 0xA3;
    B(1) &= reg_d0.b[0];
    B(0x21) &= reg_d0.b[0];
    reg_d0.b[0] = B(0x1C);
    reg_d2.b[0] = B(0x3C);
    reg_d0.b[0] ^= reg_d2.b[0];
    B(0x1C) = reg_d0.b[0];
    score_add_no_chain();
    reg_d2.w = 0x7FFF;
    reg_d2.h[0] -= W(0x18);
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= W(0x38);
    if ((s32) reg_d2.w >= (s32) reg_d3.w) goto next_10;
    reg_d2.w = reg_d3.w;
next_10:
    reg_tmp.h[1] = W(0x26);
    reg_tmp.h[0] = W(0x28);
    reg_tmp.w -= reg_d2.w;
    W(0x26) = reg_tmp.h[1];
    W(0x28) = reg_tmp.h[0];
    reg_d0.h[0] = 0x7FFF;
    W(0x18) = reg_d0.h[0];
    W(0x38) = reg_d0.h[0];
    reg_tmp.h[1] = W(0x26);
    reg_tmp.h[0] = W(0x28);
    goto next_100;
block_20:
    reg_d2.h[1] = W(2);
    reg_d2.h[0] = W(4);
    reg_d3.w = 0;
    reg_d7.w = 3;
loop_20:
    reg_d1.w = 0;
    reg_d1.b[0] = B(0x1A);
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.b[0] += reg_d1.b[0];
    rng_next();
    reg_d4.w = 0;
    reg_d4.b[0] = BREAKABLE_BULLET_B(reg_a5)->scatter;
loop_30:
    reg_d1.b[0] += reg_d0.b[0];
    count = reg_d4.h[0] - 1;
    reg_d4.h[0] = count;
    if (((s64) ((s64) (u16) count << 0x30) >> 0x30) >= 0) goto loop_30;
    rng_next();
    reg_d0.h[0] = (s8) reg_d0.b[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 1;
    reg_d0.h[0] += 0xFFFA;
    reg_d0.h[0] += BREAKABLE_BULLET_B(reg_a5)->now.burst_speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d3.w = 0;
    reg_d4.w = 0;
    bullet_fire256_fixed();
    count = reg_d7.h[0] - 1;
    reg_d7.h[0] = count;
    if (((s64) ((s64) (count & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_20;
    reg_d0.w = 2;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = W(2);
    EXPLOSION(reg_a0)->x = W(4);
    EXPLOSION(reg_a0)->move.b.speed = B(0x1B);
    reg_d0.b[0] = B(0x1A);
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += reg_d0.b[0];
    EXPLOSION(reg_a0)->move.b.dir = reg_d0.b[0];
    EXPLOSION(reg_a0)->draw_layer = 0xC;
block_end:
    enemy_remove();
    return;
next_100:
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = B(0x1B);
    reg_d1.b[0] = B(0x1A);
    velocity_from_dir256();
    W(2) += reg_d2.h[0];
    W(4) += reg_d3.h[0];
    entity_check_bounds();
    if (cond_flag == 0) goto next_110;
    enemy_remove();
    return;
next_110:
    reg_tmp.b[0] = BREAKABLE_BULLET_B(reg_a5)->now.frame_timer.b.countdown;
    BREAKABLE_BULLET_B(reg_a5)->now.frame_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_120;
    BREAKABLE_BULLET_B(reg_a5)->now.frame_timer.b.countdown = BREAKABLE_BULLET_B(reg_a5)->now.frame_timer.b.interval;
    BREAKABLE_BULLET_B(reg_a5)->now.frame += 4;
    BREAKABLE_BULLET_B(reg_a5)->now.frame &= 0xF;
    reg_tmp.h[1] = W(0xA);
    reg_tmp.h[0] = W(0xC);
    reg_tmp.w += 1;
    W(0xA) = reg_tmp.h[1];
    W(0xC) = reg_tmp.h[0];
    reg_d0.h[1] = BREAKABLE_BULLET_B(reg_a5)->now.last_sprite[0];
    reg_d0.h[0] = BREAKABLE_BULLET_B(reg_a5)->now.last_sprite[1];
    reg_tmp.h[1] = W(0xA);
    reg_tmp.h[0] = W(0xC);
    if (reg_tmp.w != reg_d0.w) goto next_120;
    reg_tmp.h[1] = W(0xA);
    reg_tmp.h[0] = W(0xC);
    reg_tmp.w -= 3;
    W(0xA) = reg_tmp.h[1];
    W(0xC) = reg_tmp.h[0];
next_120:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x20;
    enemy_hitbox_debug_draw();
    entity_draw_with_bullets();
}

void stage1_boss_shell_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 enemy_init_entities();                            /* extern */
extern s32 stage1_boss_shell_start_table[];

void stage1_boss_shell_start(void) {
    reg_a0 = (u8 *)stage1_boss_shell_start_table;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) STAGE1_SHELL(reg_a5)->at_start.y;
    ENTITY(reg_a6)->x.h = (u16) STAGE1_SHELL(reg_a5)->at_start.x;
    ENTITY(reg_a6)->move.h = (u16) STAGE1_SHELL(reg_a5)->at_start.move;
    STAGE1_SHELL(reg_a5)->unread_24 = (u16) STAGE1_SHELL(reg_a5)->at_start.spare;
    STAGE1_SHELL(reg_a5)->slow_timer.both = 0;
    STAGE1_SHELL(reg_a5)->now.frame_timer.both = 0x101U;
    STAGE1_SHELL(reg_a5)->frame = 0;
}

s32 bullet_fire_fixed();
s32 sprite_draw_with_bullets();
s32 rng_next_unsigned();
extern u16 g_direction64_offsets_166[];
extern u16 g_direction64_offsets_2CC[];
extern u16 g_direction64_offsets_432[];
extern u32 stage1_boss_shell_table[];
extern u16 g_bullets_blocked;

#define W(o) (*(u16 *)(reg_a6 + (o)))
#define AW(o) (*(u16 *)(reg_a0 + (o)))
#define LOOKUP(d) (((d) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(d) & ~1)) : *(u16 *)reg_a0)

void stage1_boss_shell(void) {
    if (g_boss_present_b1 & 0x40) goto next_1;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto next_2;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    W(0x18) = 0x7FFF;
    goto next_2;
next_1:
    reg_d0.w = 1;
    explosion_spawn();
    AW(2) = W(2);
    AW(4) = W(4);
    EXPLOSION(reg_a0)->move.b.speed = ENTITY(reg_a6)->move.b.speed;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += reg_d0.b[0];
    EXPLOSION(reg_a0)->move.b.dir = reg_d0.b[0];
    AW(0x1E) = 0x10;
    enemy_remove();
    return;
next_2:
    entity_velocity();
    reg_tmp.b[0] = STAGE1_SHELL(reg_a5)->slow_timer.b.countdown;
    STAGE1_SHELL(reg_a5)->slow_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_3;
    STAGE1_SHELL(reg_a5)->slow_timer.b.countdown = STAGE1_SHELL(reg_a5)->slow_timer.b.interval;
    ENTITY(reg_a6)->move.b.speed -= 1;
next_3:
    if (ENTITY(reg_a6)->move.b.speed != 0) goto block_saku;
    reg_d0.w = 1;
    explosion_spawn();
    AW(2) = W(2);
    AW(4) = W(4);
    EXPLOSION(reg_a0)->move.b.speed = ENTITY(reg_a6)->move.b.speed;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += reg_d0.b[0];
    EXPLOSION(reg_a0)->move.b.dir = reg_d0.b[0];
    AW(0x1E) = 0x10;
    rng_next_unsigned();
    reg_d0.h[0] &= 0x3F;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d2.h[1] = W(2);
    reg_d2.h[0] = W(4);
    reg_d3.w = 0;
    reg_d4.w = 0;
    reg_d0.h[0] = 0;
    reg_d0.h[0] = reg_d0.sb[0];
    reg_d0.h[0] += STAGE1_SHELL(reg_a5)->now.burst_speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 3;
    if (g_enemies_stopped != 0) goto block_end;
    if (g_bullets_blocked != 0) goto block_end;
    reg_d7.w = 0xF;
    reg_a0 = (u8 *) g_direction64_offsets_432;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[1] = LOOKUP(reg_d3.h[0]);
        reg_d3.h[0] = LOOKUP((u16) reg_d3.h[0] + 2);
        bullet_fire_fixed();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w -= 0x50000;
    reg_d0.h[0] = 4;
    reg_d1.b[0] += 2;
    reg_d7.w = 0xF;
    reg_a0 = (u8 *) g_direction64_offsets_2CC;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[1] = LOOKUP(reg_d3.h[0]);
        reg_d3.h[0] = LOOKUP((u16) reg_d3.h[0] + 2);
        bullet_fire_fixed();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w -= 0x50000;
    reg_d0.h[0] = 5;
    reg_d1.b[0] += 2;
    reg_d7.w = 0xF;
    reg_a0 = (u8 *) g_direction64_offsets_166;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[1] = LOOKUP(reg_d3.h[0]);
        reg_d3.h[0] = LOOKUP((u16) reg_d3.h[0] + 2);
        bullet_fire_fixed();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
block_end:
    enemy_remove();
    return;
block_saku:
    reg_tmp.b[0] = STAGE1_SHELL(reg_a5)->now.frame_timer.b.countdown;
    STAGE1_SHELL(reg_a5)->now.frame_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_4;
    STAGE1_SHELL(reg_a5)->now.frame_timer.b.countdown = STAGE1_SHELL(reg_a5)->now.frame_timer.b.interval;
    STAGE1_SHELL(reg_a5)->frame += 4;
    STAGE1_SHELL(reg_a5)->frame &= 0x3F;
next_4:
    reg_a0 = (u8 *) stage1_boss_shell_table;
    reg_a0 += STAGE1_SHELL(reg_a5)->frame;
    reg_d2.h[1] = AW(0);
    reg_d2.h[0] = AW(2);
    reg_d1.h[1] = W(2);
    reg_d1.h[0] = W(4);
    reg_d1.w += 0xFA00FD00;
    reg_d3.h[0] = 0x618;
    reg_d4.w = 0x11;
    sprite_draw_with_bullets();
}

void stage1_boss_entrance_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

s32 enemy_path_start();
s32 sprite_palette_load();
extern u8 stage1_boss_entrance_start_table[];
extern u8 stage1_boss_entrance_start_table_2[];
extern s8 enemy_move_end_requested;

void stage1_boss_entrance_start(void) {
    reg_a0 = stage1_boss_entrance_start_table_2;
    enemy_init_entities();
    reg_d0.h[0] = 0x13;
    reg_a0 = stage1_boss_entrance_start_table;
    sprite_palette_load();
    STAGE1_ENTRANCE(reg_a5)->frame = 0;
    STAGE1_ENTRANCE(reg_a5)->frame_timer.both = 0;
    STAGE1_ENTRANCE(reg_a5)->timer.both = 0x120;
    STAGE1_ENTRANCE(reg_a5)->phase = 0;
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        ENTITY(reg_a6)->y.h += 0x200;
    }
}

s32 sprite_draw_layer1();
s32 entity_follow_scroll();
extern u8 stage1_boss_entrance_table[];

void stage1_boss_entrance(void) {
    u16 temp_a0;
    u16 temp_a1;

    if (g_enemies_stopped == 0) {
        entity_follow_scroll();
        entity_velocity();
        if (STAGE1_ENTRANCE(reg_a5)->phase == 0) {
            STAGE1_ENTRANCE(reg_a5)->timer.both -= 1;
            if (STAGE1_ENTRANCE(reg_a5)->timer.both == 0) {
                ENTITY(reg_a6)->move.sh = 0x537;
                STAGE1_ENTRANCE(reg_a5)->phase = 1U;
                STAGE1_ENTRANCE(reg_a5)->timer.both = 0x808U;
            }
        }
        if (STAGE1_ENTRANCE(reg_a5)->phase == 1) {
            reg_tmp.b[0] = STAGE1_ENTRANCE(reg_a5)->timer.b.countdown;
            STAGE1_ENTRANCE(reg_a5)->timer.b.countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                STAGE1_ENTRANCE(reg_a5)->timer.b.countdown = (u8) STAGE1_ENTRANCE(reg_a5)->timer.b.interval;
                ENTITY(reg_a6)->move.b.speed += 1;
            }
        }
        if (ENTITY(reg_a6)->x.sh < -0x21FF) {
            enemy_remove();
            return;
        }
        reg_tmp.b[0] = STAGE1_ENTRANCE(reg_a5)->frame_timer.b.countdown;
        STAGE1_ENTRANCE(reg_a5)->frame_timer.b.countdown -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            STAGE1_ENTRANCE(reg_a5)->frame_timer.b.countdown = (u8) STAGE1_ENTRANCE(reg_a5)->frame_timer.b.interval;
            STAGE1_ENTRANCE(reg_a5)->frame += 4;
            if ((s8) ENTITY(reg_a6)->move.b.speed >= 0x10) {
                STAGE1_ENTRANCE(reg_a5)->frame += 4;
                STAGE1_ENTRANCE(reg_a5)->frame += 4;
            }
            STAGE1_ENTRANCE(reg_a5)->frame &= 0x3F;
        }
        goto block_13;
    }
block_13:
    reg_d2.w = 0x1A3A;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_d3.h[0] = 0x1488;
    reg_d4.w = 0x13;
    sprite_draw_layer1();
    reg_a0 = (u8 *)stage1_boss_entrance_table;
    reg_a0 += STAGE1_ENTRANCE(reg_a5)->frame;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a1 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFDC00080;
    reg_d3.h[0] = 0x1488;
    reg_d4.w = 0x13;
    sprite_draw_layer1();
}

u16 stage1_boss_breakable_bullet_start_table[16] = {
    0xA201, 0xFE00, 0xFE00, 0x0000, 0x0000, 0x0210, 0x0080, 0x0080,
    0x0080, 0x0080, 0x0008, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u8 stage1_boss_breakable_bullet_b_start_table[64] = {
    0x01, 0x80, 0x00, 0xFC, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x10, 0x04, 0x80, 0x00, 0x80, 0x00,
    0x80, 0x00, 0x80, 0x00, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
    0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x10, 0x02, 0x00, 0x05, 0x00, 0x05, 0x00, 0x05, 0x00, 0x05,
    0xFF, 0x7F, 0x00, 0x00, 0x05, 0x1A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

s32 stage1_boss_shell_start_table[8] = {
    0xFC008001, 0x0000FE00, 0x041001B8, 0x02000200, 0x02000200, 0x00007FFF, 0x0000001A, 0x00000000,
};

u32 stage1_boss_shell_table[16] = {
    0x1A4B0000, 0x1A4C0000, 0x1A4D0000, 0x1A4E0000, 0x1A4F0000, 0x1A500000, 0x1A510000, 0x1A520000,
    0x1A530000, 0x1A540000, 0x1A550000, 0x1A560000, 0x1A570000, 0x1A580000, 0x1A590000, 0x1A5A0000,
};

u8 stage1_boss_entrance_start_table_2[32] = {
    0x00, 0x80, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x10, 0x02, 0x80, 0x00, 0x80, 0x00,
    0x80, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage1_boss_entrance_table[64] = {
    0x00, 0x00, 0x3B, 0x1A, 0x00, 0x00, 0x3C, 0x1A, 0x00, 0x00, 0x3D, 0x1A, 0x00, 0x00, 0x3E, 0x1A,
    0x00, 0x00, 0x3F, 0x1A, 0x00, 0x00, 0x40, 0x1A, 0x00, 0x00, 0x41, 0x1A, 0x00, 0x00, 0x42, 0x1A,
    0x00, 0x00, 0x43, 0x1A, 0x00, 0x00, 0x44, 0x1A, 0x00, 0x00, 0x45, 0x1A, 0x00, 0x00, 0x46, 0x1A,
    0x00, 0x00, 0x47, 0x1A, 0x00, 0x00, 0x48, 0x1A, 0x00, 0x00, 0x49, 0x1A, 0x00, 0x00, 0x4A, 0x1A,
};
