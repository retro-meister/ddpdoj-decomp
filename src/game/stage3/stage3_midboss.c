#include "common.h"
#include "enemy.h"
#include "entity.h"
#include "explosion.h"
#include "enemy.h"

struct Stage3MidbossTableRecord { u16 w0[100]; void *p1; u16 w2[10]; };
extern struct Stage3MidbossTableRecord stage3_midboss_table;

void stage3_midboss_side1_blow_off(void);
void stage3_midboss_side2_blow_off(void);
void stage3_midboss_dying(void);
void stage3_midboss_next_mode(void);
void func_001D6690(void);
void func_001D66A0(void);
void func_001D66B0(void);
void func_001D66E0(void);
void func_001D6710(void);
void func_001D6790(void);
void func_001D6990(void);
void func_001D6A40(void);
void func_001D6B60(void);


/* The stage 3 mid-boss. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u16 unused_16;
    /* 0x18 */ u16 mode;
    /* 0x1A */ u8 unused_1A;
    /* 0x1B */ u8 step;
    /* 0x1C */ u16 next_attack;
    /* 0x1E */ u8 sides_lost;
    /* 0x1F */ u8 weak;
    /* 0x20 */ u16 hp[2];             /* high word first */
    /* 0x24 */ u8 dying_step;
    /* 0x25 */ u8 dying;
    /* 0x26 */ EnemyTimer blast_timer;
    /* 0x28 */ u16 blast_rounds;
    /* 0x2A */ u16 blast;
    /* 0x2C */ u16 shown;
    /* 0x2E */ u16 time_left;
    /* 0x30 */ u16 gone;
    /* 0x32 */ u16 frame;
    /* 0x34 */ u8 unused_34[0x10];
    /* 0x44 */ u16 after_entities[2];
} Stage3MidbossState;

/* Kind 0x13, started by the mid-boss. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct { u16 y; u16 x; u16 move; } at_start;
        struct { u8 unused_16; u8 seen; EnemyTimer shot; EnemyTimer accel; } now;
    };
    /* 0x1C */ u16 unused_1C;
    /* 0x1E */ EnemyTimer frame_timer;
    /* 0x20 */ u16 frame;
    /* 0x22 */ EnemyTimer grow_timer;
    /* 0x24 */ u16 grow_frame;
    /* 0x26 */ u8 unused_26;
    /* 0x27 */ u8 shots_left;
} Stage3MidbossPodState;

#define STAGE3_MIDBOSS(pointer) ((Stage3MidbossState *)(pointer))
#define POD(pointer) ((Stage3MidbossPodState *)(pointer))

extern u16 g_enemies_stopped;
s32 bullet_fire();
extern u16 g_direction64_offsets_2CC[];

void stage3_midboss_fan7(void) {
    reg_d0.w = 0xFFFC0004;
    reg_d1.h[0] -= 0xC;
    reg_d7.w = 6;
    reg_a0 = (u8 *)(g_direction64_offsets_2CC);
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] *= 4;
        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w += reg_d5.w;
        bullet_fire();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

void func_001D61B0();

void enemy_set_entity_count(s32);

void stage3_midboss_first(void) {
    enemy_set_entity_count(6);
}

s32 enemy_set_task_state();
s32 enemy_init_entities();
s32 sprite_palette_load();
extern u16 D_00260330[];
extern u16 D_00260370[];
extern u16 D_002603B0[];
extern u16 D_00263370[];
extern s16 g_enemy_signal_e_as_s16;
extern s16 g_enemy_signal_4_as_s16;
extern u16 *reg_a0_as_u16_p;

void stage3_midboss_start(void) {
    reg_a0_as_u16_p = ((u16 *)&stage3_midboss_table);
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0_as_u16_p;
    STAGE3_MIDBOSS(reg_a5)->after_entities[0] = (u16) reg_tmp.h[1];
    STAGE3_MIDBOSS(reg_a5)->after_entities[1] = (u16) reg_tmp.h[0];
    reg_a0_as_u16_p = D_00263370;
    reg_d0.h[0] = 0xE;
    enemy_set_task_state();
    reg_tmp.w = 0xF0001C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
    reg_a0_as_u16_p = (u16 *)g_spare_entities;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.w = 9;
    do {
        *reg_a0_as_u16_p = reg_d1.h[1];
        reg_a0_as_u16_p += 1;
        *reg_a0_as_u16_p = reg_d1.h[0];
        reg_a0_as_u16_p += 1;
        *reg_a0_as_u16_p = 0;
        reg_a0_as_u16_p += 1;
        *reg_a0_as_u16_p = 0;
        reg_a0_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = 0x12;
    g_enemy_signal_e_as_s16 = 1;
    g_enemy_signal_4_as_s16 = 1;
    reg_a0_as_u16_p = D_00260330;
    sprite_palette_load();
    reg_d0.h[0] = 0x13;
    reg_a0_as_u16_p = D_00260370;
    sprite_palette_load();
    reg_d0.h[0] = 0xA;
    reg_a0_as_u16_p = D_002603B0;
    sprite_palette_load();
}

typedef void (*Fn)();

extern u8 stage3_midboss_mode_routines[];
extern u8 D_002BDAA8[];
s32 enemy_hitbox_debug_draw();
s32 enemy_remove();
s32 score_add_no_chain();
s32 score_add();
s32 func_00201800();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u16 g_enemy_signal_4;
extern u16 g_side_scroll_step[];
extern u16 D_002BDAA4[];
extern u16 D_002BDAA6[];

void stage3_midboss_main(void) {
    u32 saved;
    u32 saved_d1;
    u8 *p;

    if (g_enemies_stopped != 0) goto next_1;
    reg_d7.h[1] = ENTITY(reg_a6)->y.h;
    reg_d7.h[0] = ENTITY(reg_a6)->x.h;
    saved = reg_d7.w;
    reg_a0 = (u8 *)stage3_midboss_mode_routines;
    reg_d0.h[0] = STAGE3_MIDBOSS(reg_a5)->mode;
    reg_d0.h[0] *= 4;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)(reg_a0 + 0);
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_call_target = (Fn)(reg_a0);
    reg_call_target();
    reg_d7.w = saved;
    if (STAGE3_MIDBOSS(reg_a5)->dying != 0) goto next_3;
    if (STAGE3_MIDBOSS(reg_a5)->time_left == 0) goto next_3;
    if (STAGE3_MIDBOSS(reg_a5)->sides_lost != 0) goto next_2;
    if ((s16) STAGE3_MIDBOSS(reg_a5)->time_left <= 0x258) goto block_1;
next_2:
    STAGE3_MIDBOSS(reg_a5)->time_left -= 1;
    if (STAGE3_MIDBOSS(reg_a5)->time_left != 0) goto next_3;
    stage3_midboss_next_mode();
next_3:
    func_001D61B0();
    func_001D66E0();
    stage3_midboss_dying();
    if (STAGE3_MIDBOSS(reg_a5)->gone == 0) goto next_1;
    enemy_remove();
    return;
next_1:
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_a0 = (u8 *)D_002BDAA8;
    p = (u8 *) D_002BDAA4;
    reg_a1 = p;
    reg_d1.w = 8;
loop_1:
    reg_a1 -= 4;
    reg_d2.h[1] = *(u16 *)(reg_a1 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a1 + 2);
    reg_d2.h[0] -= g_side_scroll_step[0];
    reg_a0 -= 4;
    *(u16 *)(reg_a0 + 0) = reg_d2.h[1];
    *(u16 *)(reg_a0 + 2) = reg_d2.h[0];
    if ((s16) --reg_d1.h[0] >= 0) goto loop_1;
    reg_d0.h[0] -= g_side_scroll_step[0];
    *(u16 *)(reg_a1 + 0) = reg_d0.h[1];
    *(u16 *)(reg_a1 + 2) = reg_d0.h[0];
    reg_d0.h[1] = *(u16 *)p;
    reg_d0.h[0] = D_002BDAA6[0];
    ENTITY(reg_a6)[1].y.h = reg_d0.h[1];
    ENTITY(reg_a6)[1].x.h = reg_d0.h[0];
    ENTITY(reg_a6)[1].x.h -= 0x1000;
    ENTITY(reg_a6)[2].y.h = reg_d0.h[1];
    ENTITY(reg_a6)[2].x.h = reg_d0.h[0];
    ENTITY(reg_a6)[2].x.h += 0x1000;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto next_6;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    reg_d2.b[0] = ENTITY(reg_a6)->misc.b.draw_layer;
    reg_d0.b[0] ^= reg_d2.b[0];
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    reg_d0.w = 0x7FFF;
    reg_d0.h[0] -= ENTITY(reg_a6)->hp.h;
    if (STAGE3_MIDBOSS(reg_a5)->time_left == 0) goto next_4;
    reg_tmp.h[1] = STAGE3_MIDBOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE3_MIDBOSS(reg_a5)->hp[1];
    reg_tmp.w -= reg_d0.w;
    STAGE3_MIDBOSS(reg_a5)->hp[0] = reg_tmp.h[1];
    STAGE3_MIDBOSS(reg_a5)->hp[1] = reg_tmp.h[0];
next_4:
    ENTITY(reg_a6)->hp.h = 0x7FFF;
    if (STAGE3_MIDBOSS(reg_a5)->sides_lost != 0) goto next_5;
    reg_tmp.h[1] = STAGE3_MIDBOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE3_MIDBOSS(reg_a5)->hp[1];
    if ((s32) reg_tmp.w > 0x2800) goto next_5;
block_1:
    stage3_midboss_side1_blow_off();
    stage3_midboss_side2_blow_off();
    STAGE3_MIDBOSS(reg_a5)->sides_lost = 1;
    goto next_7;
next_5:
    reg_tmp.h[1] = STAGE3_MIDBOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE3_MIDBOSS(reg_a5)->hp[1];
    if ((s32) reg_tmp.w >= 0) goto next_7;
    saved_d1 = reg_d1.w;
    reg_d0.w = 0x712;
    score_add();
    vibration_start_pad1(0xB4, 0x78);
    vibration_start_pad2(0xB4, 0x78);
    reg_d1.w = saved_d1;
    func_00201800();
    ENTITY(reg_a6)->flags.h = 0x8000;
    STAGE3_MIDBOSS(reg_a5)->dying = 1;
    g_enemy_signal_4 = 0;
next_6:
    ENTITY(reg_a6)->attr.b.palette = ENTITY(reg_a6)->misc.b.user;
next_7:
    if (STAGE3_MIDBOSS(reg_a5)->weak != 0) goto next_8;
    reg_tmp.h[1] = STAGE3_MIDBOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE3_MIDBOSS(reg_a5)->hp[1];
    if ((s32) reg_tmp.w > 0x1000) goto next_8;
    STAGE3_MIDBOSS(reg_a5)->weak = 1;
next_8:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)[1].flags.b[1];
    if (reg_d1.b[0] == 0) goto next_10;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)[1].move.b.speed;
    reg_d2.b[0] = ENTITY(reg_a6)[1].attr.b.palette;
    reg_d0.b[0] ^= reg_d2.b[0];
    ENTITY(reg_a6)[1].move.b.speed = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[1].move.b.dir;
    reg_d2.b[0] = ENTITY(reg_a6)[1].misc.b.draw_layer;
    reg_d0.b[0] ^= reg_d2.b[0];
    ENTITY(reg_a6)[1].move.b.dir = reg_d0.b[0];
    if (STAGE3_MIDBOSS(reg_a5)->time_left != 0) goto next_9;
    ENTITY(reg_a6)[1].hp.h = 0x4000;
next_9:
    if (ENTITY(reg_a6)[1].hp.sh >= 0) goto next_11;
    reg_d0.w = 0x173;
    score_add();
    stage3_midboss_side1_blow_off();
next_10:
    ENTITY(reg_a6)[1].move.b.speed = ENTITY(reg_a6)[1].attr.b.flip;
    ENTITY(reg_a6)[1].move.b.dir = ENTITY(reg_a6)[1].misc.b.user;
next_11:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)[2].flags.b[1];
    if (reg_d1.b[0] == 0) goto next_13;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[2].flags.b[1] &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)[2].move.b.speed;
    reg_d2.b[0] = ENTITY(reg_a6)[2].attr.b.palette;
    reg_d0.b[0] ^= reg_d2.b[0];
    ENTITY(reg_a6)[2].move.b.speed = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[2].move.b.dir;
    reg_d2.b[0] = ENTITY(reg_a6)[2].misc.b.draw_layer;
    reg_d0.b[0] ^= reg_d2.b[0];
    ENTITY(reg_a6)[2].move.b.dir = reg_d0.b[0];
    if (STAGE3_MIDBOSS(reg_a5)->time_left != 0) goto next_12;
    ENTITY(reg_a6)[2].hp.h = 0x4000;
next_12:
    if (ENTITY(reg_a6)[2].hp.sh >= 0) goto next_14;
    reg_d0.w = 0x173;
    score_add();
    stage3_midboss_side2_blow_off();
next_13:
    ENTITY(reg_a6)[2].move.b.speed = ENTITY(reg_a6)[2].attr.b.flip;
    ENTITY(reg_a6)[2].move.b.dir = ENTITY(reg_a6)[2].misc.b.user;
next_14:
    STAGE3_MIDBOSS(reg_a5)->frame += 4;
    STAGE3_MIDBOSS(reg_a5)->frame &= 0x1F;
    if (STAGE3_MIDBOSS(reg_a5)->shown == 0) return;
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x20;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x40;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x60;
    enemy_hitbox_debug_draw();
    func_001D6990();
    func_001D6A40();
    func_001D6B60();
}

s32 explosion_spawn();

void func_001D5040(arg2)
    u16 *arg2;
{
    u16 *var_a2;
    u16 temp_a1;

    var_a2 = (u16 *)(arg2);
loop_1:
    temp_a1 = *(u16 *)reg_a1;
    reg_d1.h[0] = temp_a1;
    reg_a1 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        explosion_spawn();
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        EXPLOSION(reg_a0)->attr.b.flip = (u8) reg_d0.b[0];
        EXPLOSION(reg_a0)->delay = (u16) reg_d1.h[0];
        EXPLOSION(reg_a0)->start_y = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        EXPLOSION(reg_a0)->start_x = (u16) *(u16 *)reg_a1;
        var_a2 = (u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)(var_a2);
        EXPLOSION(reg_a0)->y = (u16) reg_d2.h[1];
        EXPLOSION(reg_a0)->x = (u16) reg_d2.h[0];
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0;
        EXPLOSION(reg_a0)->move.h = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        goto loop_1;
    }
}

s32 sfx_explosion_ground_large();
extern u8 D_00263470[];

void stage3_midboss_side1_blow_off() {
    if (ENTITY(reg_a6)[1].look.b.size == 0) {
        ENTITY(reg_a6)[1].look.b.size = 1U;
        ENTITY(reg_a6)[1].flags.h = 0x8000;
        reg_a1 = D_00263470;
        reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
        func_001D5040();
        sfx_explosion_ground_large();
    }
}

void stage3_midboss_side2_blow_off() {
    if (ENTITY(reg_a6)[2].look.b.size == 0) {
        ENTITY(reg_a6)[2].look.b.size = 1U;
        ENTITY(reg_a6)[2].flags.h = 0x8000;
        reg_a1 = D_00263470;
        reg_d2.h[1] = ENTITY(reg_a6)[2].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[2].x.h;
        func_001D5040();
        sfx_explosion_ground_large();
    }
}


s32 scroll_line_release();
s32 explosion_burst_small();
s32 fade_in_and_release();
s32 sfx_explosion_air_medium();
s32 sfx_explosion_extra_1();
s32 rng_next();
extern u16 D_002634F0[];
extern u16 D_00263540[];
extern u8 stage3_midboss_flash_palettes[];

void stage3_midboss_dying(void) {
    u16 temp_a0_2;
    u16 temp_a0_3;
    u8 temp_a0;
    u8 *var_a1;

    if (STAGE3_MIDBOSS(reg_a5)->dying != 0) {
        temp_a0 = STAGE3_MIDBOSS(reg_a5)->dying_step;
        if (temp_a0 == 2) {
            STAGE3_MIDBOSS(reg_a5)->blast_timer.b.countdown -= 1;
            if (STAGE3_MIDBOSS(reg_a5)->blast_timer.b.countdown == 0) {
                scroll_line_release();
                g_enemy_signal_e_as_s16 = 0;
                STAGE3_MIDBOSS(reg_a5)->gone = 1;
                goto block_set;
            }
        }
        var_a1 = (u8 *)(reg_a5);
        if ((*(u8 *)((u8 *)(var_a1) + (0x24))) == 1) {
            (*(u8 *)((u8 *)(var_a1) + (0x27))) -= 1;
            if (STAGE3_MIDBOSS(reg_a5)->blast_timer.b.countdown == 0) {
                STAGE3_MIDBOSS(reg_a5)->shown = 0;
                reg_a0 = (u8 *)stage3_midboss_flash_palettes;
                fade_in_and_release();
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_a1 = (u8 *)(D_00263540);
                func_001D5040();
                rng_next();
                reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
                reg_d1.b[0] = reg_d0.b[0];
                reg_d1.b[0] += 0x40;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                temp_a0_2 = ENTITY(reg_a6)->x.h;
                reg_d2.h[0] = temp_a0_2;
                reg_d2.w += 0xF8000800;
                reg_d3.h[0] = 0xC;
                reg_d0.h[0] = 0;
                explosion_burst_small();
                rng_next();
                reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
                reg_d1.b[0] = reg_d0.b[0];
                reg_d1.b[0] += 0xC0;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                temp_a0_3 = ENTITY(reg_a6)->x.h;
                reg_d2.h[0] = temp_a0_3;
                reg_d2.w += 0x01FFF800;
                reg_d3.h[0] = 0xC;
                reg_d0.h[0] = 0;
                explosion_burst_small();
                sfx_explosion_extra_1();
                var_a1 = (u8 *)((void *)0x10);
                STAGE3_MIDBOSS(reg_a5)->blast_timer.b.countdown = 0x10U;
                STAGE3_MIDBOSS(reg_a5)->dying_step = 2U;
            }
        }
        if (STAGE3_MIDBOSS(reg_a5)->dying_step == 0) {
            reg_tmp.b[0] = STAGE3_MIDBOSS(reg_a5)->blast_timer.b.countdown;
            STAGE3_MIDBOSS(reg_a5)->blast_timer.b.countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                STAGE3_MIDBOSS(reg_a5)->blast_timer.b.countdown = (u8) STAGE3_MIDBOSS(reg_a5)->blast_timer.b.interval;
                sfx_explosion_air_medium();
                reg_a1 = (u8 *)(D_002634F0);
                reg_a1 += STAGE3_MIDBOSS(reg_a5)->blast;
                reg_d1.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                explosion_spawn();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                EXPLOSION(reg_a0)->attr.b.flip = (u8) reg_d0.b[0];
                EXPLOSION(reg_a0)->delay = (u16) reg_d1.h[0];
                EXPLOSION(reg_a0)->start_y = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                EXPLOSION(reg_a0)->start_x = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
                EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
                EXPLOSION(reg_a0)->draw_layer = 0x10;
                EXPLOSION(reg_a0)->debris = 0;
                EXPLOSION(reg_a0)->debris_arg = 0;
                EXPLOSION(reg_a0)->move.b.speed = (u8) ENTITY(reg_a6)->move.b.speed;
                reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
                reg_d0.b[0] *= 4;
                EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
                STAGE3_MIDBOSS(reg_a5)->blast += 0xC;
                if (STAGE3_MIDBOSS(reg_a5)->blast == 0x48) {
                    STAGE3_MIDBOSS(reg_a5)->blast = 0U;
                    STAGE3_MIDBOSS(reg_a5)->blast_rounds -= 1;
                    if (STAGE3_MIDBOSS(reg_a5)->blast_rounds == 0) {
                        STAGE3_MIDBOSS(reg_a5)->blast_timer.both = 0x1006;
                        STAGE3_MIDBOSS(reg_a5)->dying_step = 1U;
                    }
                }
            }
        }
        goto block_12;
    }
block_12:
    cond_flag = 0;
    return;
block_set:
    cond_flag = 1;
}

void stage3_midboss_next_mode(void) {
    STAGE3_MIDBOSS(reg_a5)->step = 0;
    if (STAGE3_MIDBOSS(reg_a5)->time_left != 0) {
        reg_d0.b[0] = ENTITY(reg_a6)[1].look.b.size;
        reg_d0.b[0] += ENTITY(reg_a6)[2].look.b.size;
        if (reg_d0.b[0] != 2) {
            reg_d0.h[0] = STAGE3_MIDBOSS(reg_a5)->next_attack;
            reg_d0.h[0] += 1;
            STAGE3_MIDBOSS(reg_a5)->mode = (u16) reg_d0.h[0];
            STAGE3_MIDBOSS(reg_a5)->next_attack += 1;
            STAGE3_MIDBOSS(reg_a5)->next_attack &= 3;
            return;
        }
        reg_d0.h[0] = STAGE3_MIDBOSS(reg_a5)->mode;
        if (reg_d0.h[0] == 5) {
            STAGE3_MIDBOSS(reg_a5)->mode = 2U;
            return;
        }
        STAGE3_MIDBOSS(reg_a5)->mode = 5U;
        return;
    }
    g_enemy_signal_4_as_s16 = 0;
    STAGE3_MIDBOSS(reg_a5)->mode = 6U;
}

s32 entity_velocity();
s32 direction_between();
s32 direction_turn_toward();
s32 entity_distance_to();
extern u8 stage3_midboss2_state_routines_0[];

void func_001D5670(void) {
    if (STAGE3_MIDBOSS(reg_a5)->dying != 0) {
        ENTITY(reg_a6)->move.sh = 0x420;
        entity_velocity();
        return;
    }
    reg_a0 = stage3_midboss2_state_routines_0;
    reg_a0 += ENTITY(reg_a6)[4].offset_y.h;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    entity_velocity();
    reg_a0 = stage3_midboss2_state_routines_0;
    reg_a0 += ENTITY(reg_a6)[4].offset_y.h;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    entity_distance_to();
    if ((s16) reg_d0.h[0] < 0x101) {
        ENTITY(reg_a6)[4].offset_y.h += 4;
        ENTITY(reg_a6)[4].offset_y.h &= 0xF;
    }
}

s32 spawn_request_add();

void stage3_midboss_mode_00(void) {
    if (STAGE3_MIDBOSS(reg_a5)->step == 0) {
        reg_d0.h[0] = ENTITY(reg_a6)[3].offset_y.h;
        ENTITY(reg_a6)->y.h += reg_d0.h[0];
        if ((s16) ENTITY(reg_a6)->y.h > 0x3C00) {
            ENTITY(reg_a6)[3].offset_y.h -= 9;
            if (0 >= (s16) ENTITY(reg_a6)[3].offset_y.h) {
                STAGE3_MIDBOSS(reg_a5)->step = 1U;
                reg_d0.w = 0x14;
                spawn_request_add();
                stage3_midboss_next_mode();
                ENTITY(reg_a6)->flags.h = 0xA001;
                ENTITY(reg_a6)[1].flags.h = 0xA001;
                ENTITY(reg_a6)[2].flags.h = 0xA001;
            }
        }
    }
}

s32 aim_at_player();

void func_001D5830(void) {
    reg_d0.h[0] = ENTITY(reg_a6)[1].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[1].x.h;
    reg_d0.h[0] += ENTITY(reg_a6)[1].offset_y.h;
    reg_d1.h[0] += ENTITY(reg_a6)[1].offset_x.h;
    aim_at_player();
    if (cond_flag != 0) {
        reg_d1.h[0] = 0x20;
    }
    ENTITY(reg_a6)[4].hit_y_plus.b[1] = (u8) reg_d1.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)[2].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[2].x.h;
    reg_d0.h[0] += ENTITY(reg_a6)[2].offset_y.h;
    reg_d1.h[0] += ENTITY(reg_a6)[2].offset_x.h;
    aim_at_player();
    if (cond_flag != 0) {
        reg_d1.h[0] = 0x20;
    }
    ENTITY(reg_a6)[4].hit_y_plus.b[0] = (u8) reg_d1.b[0];
}

extern u16 g_rank_1_16;

void stage3_midboss_mode_attack_a(void) {
    s32 var_a1;
    u16 temp_v1;
    u8 temp_a0;
    u8 *var_a0;
    if (STAGE3_MIDBOSS(reg_a5)->step == 0) {
        var_a1 = 0x404;
        STAGE3_MIDBOSS(reg_a5)->step = 1U;
        ENTITY(reg_a6)[4].offset_x.sh = 0x404;
        ENTITY(reg_a6)[4].draw.sh = 0x1020;
        ENTITY(reg_a6)[4].sprite.h = 6U;
        reg_d0.b[0] = ENTITY(reg_a6)[1].look.b.size;
        reg_d0.b[0] += ENTITY(reg_a6)[2].look.b.size;
        if (reg_d0.b[0] != 0) {
            ENTITY(reg_a6)[4].draw.sh = 0x1008;
            ENTITY(reg_a6)[4].sprite.h = 0x20U;
        }
        ENTITY(reg_a6)[1].sprite.sh = 0;
        STAGE3_MIDBOSS(reg_a5)->step = 1U;
    }
    reg_d0.b[0] = ENTITY(reg_a6)[1].look.b.size;
    reg_d0.b[0] += ENTITY(reg_a6)[2].look.b.size;
    if (reg_d0.b[0] != 2) {
        func_001D5670();
        if (STAGE3_MIDBOSS(reg_a5)->step == 1) {
            temp_v1 = ENTITY(reg_a6)[4].look.h;
            if (temp_v1 != 0) {
                ENTITY(reg_a6)[4].look.h = (u16) (temp_v1 - 1);
            } else {
                reg_tmp.b[0] = ENTITY(reg_a6)[1].sprite.b[1];
                ENTITY(reg_a6)[1].sprite.b[1] -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    ENTITY(reg_a6)[1].sprite.b[1] = (u8) ENTITY(reg_a6)[1].sprite.b[0];
                    ENTITY(reg_a6)[2].draw.h += 4;
                    ENTITY(reg_a6)[1].draw.h += 4;
                    if ((s16) ENTITY(reg_a6)[1].draw.h >= 0x1C) {
                        ENTITY(reg_a6)[1].draw.h = 0x1CU;
                        ENTITY(reg_a6)[2].draw.h = 0x1CU;
                        STAGE3_MIDBOSS(reg_a5)->step = 2U;
                        func_001D5830();
                    }
                }
            }
        }
        if (STAGE3_MIDBOSS(reg_a5)->step == 2) {
            reg_tmp.b[0] = ENTITY(reg_a6)[4].offset_x.b[1];
            ENTITY(reg_a6)[4].offset_x.b[1] -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ENTITY(reg_a6)[4].offset_x.b[1] = (u8) ENTITY(reg_a6)[4].offset_x.b[0];
                temp_a0 = ENTITY(reg_a6)->move.b.speed;
                if (temp_a0 != 8) {
                    ENTITY(reg_a6)->move.b.speed = (u8) (temp_a0 + 1);
                }
            }
            reg_tmp.b[0] = ENTITY(reg_a6)[4].draw.b.priority;
            ENTITY(reg_a6)[4].draw.b.priority -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                reg_d0.h[0] = 0x20;
                reg_d0.h[0] -= g_rank_1_16;
                ENTITY(reg_a6)[4].draw.b.priority = (u8) reg_d0.b[0];
                reg_d0.b[0] = ENTITY(reg_a6)[1].look.b.size;
                reg_d0.b[0] += ENTITY(reg_a6)[2].look.b.size;
                if (reg_d0.b[0] != 0) {
                    ENTITY(reg_a6)[4].draw.b.flip = 8;
                }
                if (ENTITY(reg_a6)[1].look.b.size == 0) {
                    reg_d1.w = 0;
                    reg_d1.b[0] = ENTITY(reg_a6)[4].hit_y_plus.b[1];
                    reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
                    reg_d5.h[1] = ENTITY(reg_a6)[1].offset_y.h;
                    reg_d5.h[0] = ENTITY(reg_a6)[1].offset_x.h;
                    reg_d4.w = 0;
                    stage3_midboss_fan7();
                }
                if (ENTITY(reg_a6)[2].look.b.size == 0) {
                    reg_d1.w = 0;
                    reg_d1.b[0] = ENTITY(reg_a6)[4].hit_y_plus.b[0];
                    reg_d2.h[1] = ENTITY(reg_a6)[2].y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)[2].x.h;
                    reg_d5.h[1] = ENTITY(reg_a6)[2].offset_y.h;
                    reg_d5.h[0] = ENTITY(reg_a6)[2].offset_x.h;
                    reg_d4.w = 0;
                    stage3_midboss_fan7();
                }
                ENTITY(reg_a6)[4].sprite.h -= 1;
                if (ENTITY(reg_a6)[4].sprite.h == 0) {
                    STAGE3_MIDBOSS(reg_a5)->step = 3U;
                    ENTITY(reg_a6)[1].sprite.sh = 0x2000;
                }
            }
        }
        if (STAGE3_MIDBOSS(reg_a5)->step == 3) {
            reg_tmp.b[0] = ENTITY(reg_a6)[1].sprite.b[1];
            ENTITY(reg_a6)[1].sprite.b[1] -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ENTITY(reg_a6)[1].sprite.b[1] = (u8) ENTITY(reg_a6)[1].sprite.b[0];
                ENTITY(reg_a6)[2].draw.h -= 4;
                ENTITY(reg_a6)[1].draw.h -= 4;
                var_a0 = (unsigned char *)((reg_a6 + 0x2A));
                if (0 >= (s16) ENTITY(reg_a6)[1].draw.h) {
                    *(u16 *)var_a0 = 0;
                    ENTITY(reg_a6)[2].draw.h = 0U;
                    goto block_28;
                }
            }
        }
    } else {
block_28:
        stage3_midboss_next_mode();
    }
}

extern u8 stage3_midboss2_state_routines_1[];


void stage3_midboss_mode_attack_b(void) {
    u32 temp_a0_2;
    u32 temp_a0_4;
    u8 *var_a0;
    u8 *var_a1;
    if (STAGE3_MIDBOSS(reg_a5)->step == 0) {
        ENTITY(reg_a6)[5].draw.h = (u16) ENTITY(reg_a6)[5].hit_y_plus.h;
        ENTITY(reg_a6)[5].hit_y_plus.b[0] -= 4;
        if ((s8) ENTITY(reg_a6)[5].hit_y_plus.h < 0x11) {
            ENTITY(reg_a6)[5].hit_y_plus.b[0] = 0x10;
        }
        ENTITY(reg_a6)[5].sprite.h = 8U;
        var_a1 = (u8 *)(reg_a6);
        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a1) + (0x2F)));
        reg_d0.b[0] += (*(u8 *)((u8 *)(var_a1) + (0x4F)));
        if (reg_d0.b[0] != 0) {
            (*(s16 *)((u8 *)(var_a1) + (0x8A))) = 0x1008;
            ENTITY(reg_a6)[5].sprite.h = 0x10U;
            ENTITY(reg_a6)[5].hit_y_plus.b[0] = 8;
            ENTITY(reg_a6)[5].draw.h = (u16) ENTITY(reg_a6)[5].hit_y_plus.h;
        }
        ENTITY(reg_a6)[5].look.h = 0U;
        ENTITY(reg_a6)[1].sprite.sh = 0;
        STAGE3_MIDBOSS(reg_a5)->step = 1U;
    }
    reg_d0.b[0] = ENTITY(reg_a6)[1].look.b.size;
    reg_d0.b[0] += ENTITY(reg_a6)[2].look.b.size;
    if (reg_d0.b[0] != 2) {
        func_001D5670();
        if (STAGE3_MIDBOSS(reg_a5)->step == 1) {
            reg_tmp.b[0] = ENTITY(reg_a6)[1].sprite.b[1];
            ENTITY(reg_a6)[1].sprite.b[1] -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ENTITY(reg_a6)[1].sprite.b[1] = ENTITY(reg_a6)[1].sprite.b[0];
                ENTITY(reg_a6)[2].draw.h += 4;
                ENTITY(reg_a6)[1].draw.h += 4;
                if ((s16) ENTITY(reg_a6)[1].draw.h >= 0x1C) {
                    ENTITY(reg_a6)[1].draw.h = 0x1CU;
                    ENTITY(reg_a6)[2].draw.h = 0x1CU;
                    STAGE3_MIDBOSS(reg_a5)->step = 2U;
                }
            }
        }
        if (STAGE3_MIDBOSS(reg_a5)->step == 2) {
            reg_tmp.b[0] = ENTITY(reg_a6)[5].draw.b.priority;
            ENTITY(reg_a6)[5].draw.b.priority -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ENTITY(reg_a6)[5].draw.b.priority = ENTITY(reg_a6)[5].draw.b.flip;
                reg_d0.b[0] = ENTITY(reg_a6)[1].look.b.size;
                reg_d0.b[0] += ENTITY(reg_a6)[2].look.b.size;
                if (reg_d0.b[0] != 0) {
                    ENTITY(reg_a6)[5].draw.b.flip = 8;
                }
                reg_a4 = (u8 *)stage3_midboss2_state_routines_1;
                reg_a4 += ENTITY(reg_a6)[5].look.h;
                reg_tmp.h[1] = *(u16 *)reg_a4;
                reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
                reg_a4 = (u8 *) reg_tmp.w;
                ENTITY(reg_a6)[5].look.h += 4;
                ENTITY(reg_a6)[5].look.h &= 0x1F;
                if (ENTITY(reg_a6)[1].look.b.size == 0) {
                    reg_d0.h[0] = ENTITY(reg_a6)[1].y.h;
                    reg_d1.h[0] = ENTITY(reg_a6)[1].x.h;
                    reg_d0.h[0] += ENTITY(reg_a6)[1].offset_y.h;
                    reg_d1.h[0] += ENTITY(reg_a6)[1].offset_x.h;
                    aim_at_player();
                    if (cond_flag != 0) {
                        reg_d1.h[0] = 0x20;
                    }
                    reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
                    reg_d3.h[1] = ENTITY(reg_a6)[1].offset_y.h;
                    temp_a0_2 = ENTITY(reg_a6)[1].offset_x.h;
                    reg_d3.h[0] = temp_a0_2;
                    reg_a0 = reg_a6 + 0x20;
                    reg_call_target = (Fn)(reg_a4);
                    reg_call_target();
                }
                if (ENTITY(reg_a6)[2].look.b.size == 0) {
                    reg_d0.h[0] = ENTITY(reg_a6)[2].y.h;
                    reg_d1.h[0] = ENTITY(reg_a6)[2].x.h;
                    reg_d0.h[0] += ENTITY(reg_a6)[2].offset_y.h;
                    reg_d1.h[0] += ENTITY(reg_a6)[2].offset_x.h;
                    aim_at_player();
                    if (cond_flag != 0) {
                        reg_d1.h[0] = 0x20;
                    }
                    reg_d2.h[1] = ENTITY(reg_a6)[2].y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)[2].x.h;
                    reg_d3.h[1] = ENTITY(reg_a6)[2].offset_y.h;
                    temp_a0_4 = ENTITY(reg_a6)[2].offset_x.h;
                    reg_d3.h[0] = temp_a0_4;
                    reg_a0 = reg_a6 + 0x40;
                    reg_call_target = (Fn)(reg_a4);
                    reg_call_target();
                }
                ENTITY(reg_a6)[5].sprite.h -= 1;
                if (ENTITY(reg_a6)[5].sprite.h == 0) {
                    STAGE3_MIDBOSS(reg_a5)->step = 3U;
                    ENTITY(reg_a6)[1].sprite.sh = 0x2000;
                }
            }
        }
        if (STAGE3_MIDBOSS(reg_a5)->step == 3) {
            reg_tmp.b[0] = ENTITY(reg_a6)[1].sprite.b[1];
            ENTITY(reg_a6)[1].sprite.b[1] -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ENTITY(reg_a6)[1].sprite.b[1] = ENTITY(reg_a6)[1].sprite.b[0];
                ENTITY(reg_a6)[2].draw.h -= 4;
                ENTITY(reg_a6)[1].draw.h -= 4;
                var_a0 = (unsigned char *)((reg_a6 + 0x2A));
                if (0 >= (s16) ENTITY(reg_a6)[1].draw.h) {
                    *(u16 *)var_a0 = 0;
                    ENTITY(reg_a6)[2].draw.h = 0U;
                    goto block_29;
                }
            }
        }
    } else {
block_29:
        stage3_midboss_next_mode();
    }
}

extern void bullet_fire256_fixed(void);
extern u32 g_direction64_offsets_432[];

void stage3_midboss2_state_0_04(void)
{
    reg_d0.w = 0x80004;
    reg_d4.w = 0;
    reg_d7.w = 0xF;
    reg_a0 = (u8 *)g_direction64_offsets_432;

    do {
        bullet_fire256_fixed();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern void bullet_fire256_double(void);

void func_001D6160(void)
{
    reg_d1.b[0] *= 4;
    reg_d0.w = 0x80003;
    reg_d4.w = 0;
    reg_d1.b[0] -= 2;
    bullet_fire256_double();
    reg_d1.b[0] += 4;
    bullet_fire256_double();
}

s32 func_00202730();

void func_001D61B0(arg1, arg2)
    s32 arg1;
    s32 arg2;
{
    s32 var_a1;
    s32 var_a2;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;

    var_a1 = arg1;
    var_a2 = arg2;
    if (ENTITY(reg_a6)[6].offset_y.b[1] == 0) {
        var_a2 = 0x1010;
        ENTITY(reg_a6)[6].offset_y.b[1] = 1U;
        var_a1 = 0x505;
        ENTITY(reg_a6)[6].draw.sh = 0x1010;
        ENTITY(reg_a6)[6].sprite.sh = 0x505;
        ENTITY(reg_a6)[6].move.h = 0x60U;
    }
    if (STAGE3_MIDBOSS(reg_a5)->time_left != 0) {
        temp_a0 = ENTITY(reg_a6)[6].offset_y.b[1];
        if (temp_a0 == 1) {
            func_001D66B0();
            if (cond_flag == 0) {
                ENTITY(reg_a6)[6].move.h -= 1;
                if (ENTITY(reg_a6)[6].move.h == 0) {
                    func_001D6690();
                    ENTITY(reg_a6)[6].offset_y.b[1] = 2U;
                }
            }
        }
        temp_a0_2 = ENTITY(reg_a6)[6].offset_y.b[1];
        if (temp_a0_2 == 2) {
            func_001D66B0();
            if ((cond_flag == 0) && (STAGE3_MIDBOSS(reg_a5)->dying == 0)) {
                reg_tmp.b[0] = ENTITY(reg_a6)[6].draw.b.priority;
                ENTITY(reg_a6)[6].draw.b.priority -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    ENTITY(reg_a6)[6].draw.b.priority = ENTITY(reg_a6)[6].draw.b.flip;
                    reg_d1.h[0] = 0x80;
                    func_00202730();
                    reg_d7.b[0] = reg_d1.b[0];
                    reg_d0.w = 0x13;
                    spawn_request_add();
                    *(u16 *)(reg_a0 + 0x16) = (u16) ENTITY(reg_a6)->y.h;
                    *(u16 *)(reg_a0 + 0x18) = (u16) ENTITY(reg_a6)->x.h;
                    *(u16 *)(reg_a0 + 0x16) -= 0x800;
                    *(s8 *)(reg_a0 + 0x1B) = 0;
                    rng_next();
                    reg_d0.b[0] += reg_d7.b[0];
                    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
                    ENTITY(reg_a6)[6].sprite.b[1] -= 1;
                    if (ENTITY(reg_a6)[6].sprite.b[1] == 0) {
                        ENTITY(reg_a6)[6].offset_y.b[1] = 3U;
                        ENTITY(reg_a6)[6].move.h = 0x40U;
                    }
                }
            }
        }
    }
    temp_a0_3 = ENTITY(reg_a6)[6].offset_y.b[1];
    if (temp_a0_3 == 3) {
        ENTITY(reg_a6)[6].move.h -= 1;
        if (ENTITY(reg_a6)[6].move.h == 0) {
            func_001D66A0();
            ENTITY(reg_a6)[6].move.h = 0x60U;
            ENTITY(reg_a6)[6].offset_y.b[1] = 1U;
            ENTITY(reg_a6)[6].sprite.b[1] = ENTITY(reg_a6)[6].sprite.b[0];
            reg_d0.b[0] = ENTITY(reg_a6)[1].look.b.size;
            reg_d0.b[0] += ENTITY(reg_a6)[2].look.b.size;
            if (reg_d0.b[0] != 0) {
                ENTITY(reg_a6)[6].sprite.b[1] = 0xAU;
            }
        }
    }
}

s32 bullet_fire256();

void stage3_midboss_mode_05(void) {
    u8 t1;

    if (STAGE3_MIDBOSS(reg_a5)->step == 0) {
        STAGE3_MIDBOSS(reg_a5)->step = 1U;
        ENTITY(reg_a6)[6].look.sh = 0x810;
        ENTITY(reg_a6)[6].hit_y_plus.sh = 0x20;
        ENTITY(reg_a6)[6].hit_x_minus.b[1] = 1U;
        ENTITY(reg_a6)[6].hp.b[1] = 0U;
        ENTITY(reg_a6)[6].hit_x_plus.sb[1] = 0;
        ENTITY(reg_a6)->sprite.sh = 0x3001;
        func_001D6690();
    }
    func_001D5670();
    if (STAGE3_MIDBOSS(reg_a5)->dying == 0) {
        reg_tmp.b[0] = ENTITY(reg_a6)[6].look.b.size;
        ENTITY(reg_a6)[6].look.b.size -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            reg_d0.h[0] = 0x10;
            reg_d1.h[0] = g_rank_1_16;
            reg_d1.h[0] >>= 2;
            reg_d0.b[0] -= reg_d1.b[0];
            ENTITY(reg_a6)[6].look.b.size = (u8) reg_d0.b[0];
            func_00202730();
            if (cond_flag == 0) {
                reg_d0.w = 0x70004;
                t1 = 0xF6000000;
                reg_d1.h[0] -= 0x20;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d5.w = 0xF6000000;
                reg_d7.w = 8;
                reg_a0 = (u8 *)(g_direction64_offsets_432);
                reg_d4.w = 0;
                do {
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d3.h[0] += 2;
                    reg_d3.h[0] &= 0xFC;
                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d3.w += reg_d5.w;
                    bullet_fire256();
                    reg_d1.b[0] += 8;
                } while ((s16)(--reg_d7.h[0]) >= 0);
                reg_d0.b[0] = ENTITY(reg_a6)[6].hit_x_minus.b[1];
                ENTITY(reg_a6)[6].hp.b[1] += reg_d0.b[0];
                if ((s8) reg_d0.b[0] < 0) {
                    if (ENTITY(reg_a6)[6].hp.sb[1] < -4) {
                        ENTITY(reg_a6)[6].hit_x_minus.b[1] *= -1;
                    }
                } else if (ENTITY(reg_a6)[6].hp.sb[1] > 4) {
                    ENTITY(reg_a6)[6].hit_x_minus.b[1] *= -1;
                }
            }
        }
    }
}

void func_001D6690(void) {
    ENTITY(reg_a6)[3].offset_x.b[1] = 1;
}

void func_001D66A0(void) {
    ENTITY(reg_a6)[3].offset_x.b[1] = 2;
}

void func_001D66B0(void) {
    if (ENTITY(reg_a6)[3].offset_x.b[1] == 0) {
        cond_flag = 0;
        return;
    }
    cond_flag = 1;
}


void func_001D66E0(void) {
    func_001D6710();
    func_001D6790();
}

void func_001D6710(void) {
    if (ENTITY(reg_a6)[3].offset_x.b[1] == 1) {
        reg_tmp.b[0] = ENTITY(reg_a6)[3].draw.b.priority;
        ENTITY(reg_a6)[3].draw.b.priority -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            ENTITY(reg_a6)[3].draw.b.priority = (u8) ENTITY(reg_a6)[3].draw.b.flip;
            ENTITY(reg_a6)->draw.h += 4;
            if ((s16) ENTITY(reg_a6)->draw.h >= 0x1C) {
                ENTITY(reg_a6)->draw.h = 0x1CU;
                ENTITY(reg_a6)[3].offset_x.b[1] = 0U;
            }
        }
    }
}

void func_001D6790(void) {
    if (ENTITY(reg_a6)[3].offset_x.b[1] == 2) {
        reg_d0.b[0] = ENTITY(reg_a6)[1].look.b.size;
        reg_d0.b[0] += ENTITY(reg_a6)[2].look.b.size;
        if (reg_d0.b[0] != 2) {
            reg_tmp.b[0] = ENTITY(reg_a6)[3].draw.b.priority;
            ENTITY(reg_a6)[3].draw.b.priority -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ENTITY(reg_a6)[3].draw.b.priority = (u8) ENTITY(reg_a6)[3].draw.b.flip;
                ENTITY(reg_a6)->draw.h -= 4;
                if (0 >= (s16) ENTITY(reg_a6)->draw.h) {
                    ENTITY(reg_a6)->draw.h = 0U;
                    goto block_5;
                }
            }
        } else {
block_5:
            ENTITY(reg_a6)[3].offset_x.b[1] = 0U;
        }
    }
}

void stage3_midboss_mode_leave(s32 arg0) {
    s16 temp_v0;
    s32 var_a0;

    var_a0 = arg0;
    if (STAGE3_MIDBOSS(reg_a5)->step == 0) {
        func_001D66A0();
        var_a0 = 0x600;
        ENTITY(reg_a6)->move.sh = 0x600;
        STAGE3_MIDBOSS(reg_a5)->step = 1U;
    }
    if (STAGE3_MIDBOSS(reg_a5)->step == 1) {
        reg_tmp.b[0] = ENTITY(reg_a6)[1].sprite.b[1];
        ENTITY(reg_a6)[1].sprite.b[1] -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            ENTITY(reg_a6)[1].sprite.b[1] = (u8) ENTITY(reg_a6)[1].sprite.b[0];
            ENTITY(reg_a6)[2].draw.h -= 4;
            ENTITY(reg_a6)[1].draw.h -= 4;
            if (0 >= (s16) ENTITY(reg_a6)[1].draw.h) {
                ENTITY(reg_a6)[1].draw.h = 0U;
                ENTITY(reg_a6)[2].draw.h = 0U;
                STAGE3_MIDBOSS(reg_a5)->step = 2U;
            }
        }
    }
    if ((STAGE3_MIDBOSS(reg_a5)->step == 2) && (ENTITY(reg_a6)->y.sh >= 0x6A00)) {
        scroll_line_release();
        g_enemy_signal_e_as_s16 = 0;
        STAGE3_MIDBOSS(reg_a5)->step = 3U;
    }
    if (STAGE3_MIDBOSS(reg_a5)->step == 3) {
        temp_v0 = ENTITY(reg_a6)->y.sh;
        if ((temp_v0 < -0x63FF) && (temp_v0 > -0x6800)) {
            STAGE3_MIDBOSS(reg_a5)->gone = 1;
        }
    }
    entity_velocity();
}

s32 sprite_draw_layer4();
extern u8 D_00263630[];
extern u8 D_00263650[];

void func_001D6990(void) {
    u16 temp_a0;

    reg_a0 = D_00263650;
    reg_a0 += ENTITY(reg_a6)->draw.h;
    ENTITY(reg_a6)->hit_x_plus.h = (u16) *(u16 *)reg_a0;
    ENTITY(reg_a6)->hit_x_minus.h = (u16) *(u16 *)(reg_a0 + 2);
    reg_a0 = D_00263630;
    reg_a0 += ENTITY(reg_a6)->draw.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF200F100;
    reg_d3.h[0] = 0xE78;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    sprite_draw_layer4();
}

extern u8 D_00263670[];
extern u8 D_00263690[];

void func_001D6A40(void) {
    u16 temp_a0;
    u16 temp_a1;

    if (ENTITY(reg_a6)[1].look.b.size == 0) {
        reg_a0 = (u8 *)D_00263670;
        reg_a0 += STAGE3_MIDBOSS(reg_a5)->frame;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)[1].y.h;
        temp_a0 = ENTITY(reg_a6)[1].x.h;
        reg_d1.h[0] = temp_a0;
        reg_d1.w += 0xF000F900;
        reg_d3.h[0] = 0x1038;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)[1].move.b.speed;
        sprite_draw_layer4();
        reg_a0 = (u8 *)D_00263690;
        reg_a0 += ENTITY(reg_a6)[1].draw.h;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)[1].y.h;
        temp_a1 = ENTITY(reg_a6)[1].x.h;
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xEC000200;
        reg_d4.w = 0;
        reg_d1.w += 0xF200F900;
        reg_d3.h[0] = 0xE38;
        reg_d4.b[0] = ENTITY(reg_a6)[1].move.b.dir;
        sprite_draw_layer4();
    }
}

extern u8 D_002636B0[];
extern u8 D_002636D0[];

void func_001D6B60(void) {
    u16 temp_a0;
    u16 temp_a1;

    if (ENTITY(reg_a6)[2].look.b.size == 0) {
        reg_a0 = (u8 *)D_002636B0;
        reg_a0 += STAGE3_MIDBOSS(reg_a5)->frame;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)[2].y.h;
        temp_a0 = ENTITY(reg_a6)[2].x.h;
        reg_d1.h[0] = temp_a0;
        reg_d1.w += 0xF000F900;
        reg_d3.h[0] = 0x1038;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)[2].move.b.speed;
        sprite_draw_layer4();
        reg_a0 = (u8 *)D_002636D0;
        reg_a0 += ENTITY(reg_a6)[2].draw.h;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)[2].y.h;
        temp_a1 = ENTITY(reg_a6)[2].x.h;
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xF200F900;
        reg_d4.w = 0;
        reg_d1.w += 0xEBFFFE00;
        reg_d3.h[0] = 0xE38;
        reg_d4.b[0] = ENTITY(reg_a6)[2].move.b.dir;
        sprite_draw_layer4();
    }
}

void stage3_midboss_pod_first(void) {
    enemy_set_entity_count(0);
}

extern u8 D_002636F0[];

void stage3_midboss_pod_start(void) {
    reg_a0 = D_002636F0;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) POD(reg_a5)->at_start.y;
    ENTITY(reg_a6)->x.h = (u16) POD(reg_a5)->at_start.x;
    ENTITY(reg_a6)->move.h = (u16) POD(reg_a5)->at_start.move;
    rng_next();
    reg_d0.b[0] *= 2;
    ENTITY(reg_a6)->move.b.dir += reg_d0.b[0];
    POD(reg_a5)->now.shot.both = 0x408U;
    POD(reg_a5)->now.accel.both = 2U;
    POD(reg_a5)->frame_timer.both = 0;
    POD(reg_a5)->frame = 0;
    POD(reg_a5)->grow_timer.both = 0x101;
    POD(reg_a5)->grow_frame = 0;
    POD(reg_a5)->shots_left = 6;
    POD(reg_a5)->now.seen = 0;
}

s32 sfx_explosion_air_small();
s32 entity_draw_layer5_zoom();
s32 func_00201F20();
s32 entity_check_bounds();
extern u8 D_00263710[];
extern u8 D_00263750[];
extern u8 D_0028E2E4;
extern u16 g_enemy_signal_e;

void stage3_midboss_pod(void) {
    if (D_0028E2E4 != 0) {
        goto next_1;
    }
    if (g_enemy_signal_4 == 0) {
        goto next_2;
    }
    if (g_enemy_signal_e == 0) {
        goto next_2;
    }
    if (g_enemy_signal_e == 2) {
        goto next_2;
    }
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *) (reg_a6 + 1);
    if (reg_d1.b[0] == 0) {
        goto next_3;
    }
    reg_d0.b[0] = 0xA3;
    *(u8 *) (reg_a6 + 1) &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = *(u8 *) (reg_a6 + 0x1C);
    reg_d2.b[0] = 0x15;
    reg_d0.b[0] ^= reg_d2.b[0];
    *(u8 *) (reg_a6 + 0x1C) = reg_d0.b[0];
    if (*(s16 *) (reg_a6 + 0x18) >= 0) {
        goto next_4;
    }
next_2:
    reg_d0.w = 2;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->move.h = *(u16 *) (reg_a6 + 0x1A);
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    sfx_explosion_air_small();
next_1:
    enemy_remove();
    return;
next_3:
    *(u8 *) (reg_a6 + 0x1C) = 0xA;
next_4:
    entity_check_bounds();
    if (cond_flag == 0) {
        goto next_5;
    }
    if (POD(reg_a5)->now.seen == 0) {
        goto next_6;
    }
    enemy_remove();
    return;
next_5:
    POD(reg_a5)->now.seen = 1;
next_6:
    if (g_enemies_stopped != 0) {
        goto next_15;
    }
    func_00201F20();
    reg_tmp.b[0] = POD(reg_a5)->now.accel.b.countdown;
    POD(reg_a5)->now.accel.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_8;
    }
    POD(reg_a5)->now.accel.b.countdown = POD(reg_a5)->now.accel.b.interval;
    if (POD(reg_a5)->shots_left == 0) {
        goto next_7;
    }
    if (ENTITY(reg_a6)->move.b.speed == 4) {
        goto next_8;
    }
next_7:
    ENTITY(reg_a6)->move.b.speed += 1;
next_8:
    if (ENTITY(reg_a6)->y.sh <= 0x600) {
        goto next_9;
    }
    if (POD(reg_a5)->shots_left == 0) {
        goto next_10;
    }
    if (ENTITY(reg_a6)->move.sb.speed < 4) {
        goto next_10;
    }
    reg_tmp.b[0] = POD(reg_a5)->now.shot.b.countdown;
    POD(reg_a5)->now.shot.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_10;
    }
    POD(reg_a5)->now.shot.b.countdown = POD(reg_a5)->now.shot.b.interval;
    func_00202730();
    if (cond_flag != 0) {
        goto next_10;
    }
    rng_next();
    reg_d0.b[0] = (s8) reg_d0.b[0] >> 1;
    reg_d1.b[0] += reg_d0.b[0];
    reg_d0.w = 0x16;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.w = 0;
    reg_d3.w = 0;
    bullet_fire256();
next_9:
    POD(reg_a5)->shots_left -= 1;
next_10:
    reg_tmp.b[0] = POD(reg_a5)->frame_timer.b.countdown;
    POD(reg_a5)->frame_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_11;
    }
    POD(reg_a5)->frame_timer.b.countdown = POD(reg_a5)->frame_timer.b.interval;
    reg_a0 = (u8 *)D_00263710;
    reg_d0.h[0] = POD(reg_a5)->frame;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    POD(reg_a5)->frame += 4;
    POD(reg_a5)->frame &= 0x3F;
next_11:
    reg_tmp.b[0] = POD(reg_a5)->grow_timer.b.countdown;
    POD(reg_a5)->grow_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_15;
    }
    POD(reg_a5)->grow_timer.b.countdown = POD(reg_a5)->grow_timer.b.interval;
    if (POD(reg_a5)->grow_frame == 0x5C) {
        goto next_15;
    }
    POD(reg_a5)->grow_frame += 4;
    ENTITY(reg_a6)->hit_y_plus.h += 0x40;
    ENTITY(reg_a6)->hit_y_minus.h += 0x40;
    ENTITY(reg_a6)->hit_x_plus.h += 0x20;
    ENTITY(reg_a6)->hit_x_minus.h += 0x20;
next_15:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = (u8 *)D_00263750;
    reg_a0 += POD(reg_a5)->grow_frame;
    reg_d6.h[1] = *(u16 *) reg_a0;
    reg_d6.h[0] = *(u16 *) (reg_a0 + 2);
    entity_draw_layer5_zoom();
}

extern u8 func_00100000[];

u16 D_00263370[16] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7800, 0x0000,
    0x0808, 0x0002, 0x0000, 0x0001, 0x0708, 0x0000, 0x0000, 0x0000,
};

struct Stage3MidbossTableRecord stage3_midboss_table = {
    { 0x8000, 0x1001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0C00, 0x0700, 0x0E00, 0x0E00, 0x7FFF, 0x0800, 0x0000, 0x120D, 0x8000, 0xE800, 0x0200, 0x0000, 0x0000, 0x0000, 0x0F00, 0x1B80, 0x0500, 0x0200, 0x4000, 0x1312, 0x130C, 0x120D, 0x8000, 0xE7FF, 0xFE00, 0x0000, 0x0000, 0x0000, 0x0F00, 0x1B80, 0x0200, 0x0500, 0x4000, 0x1312, 0x130C, 0x120D, 0x8000, 0x0180, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0080, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x401C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8000, 0x0000, 0x0000, 0x0000, 0x0008, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6900, 0x0000 },
    func_00100000,
    { 0xFFBF, 0x0067, 0x0068, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

u8 D_00263470[128] = {
    0x00, 0x00, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x01, 0x00, 0x82, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x30, 0x07, 0x01, 0x00, 0x87, 0x00, 0x40, 0x00, 0x00, 0xFA,
    0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x82, 0x00, 0x00, 0x00, 0x00, 0xEE, 0x00, 0x00, 0xC0, 0x08,
    0x02, 0x00, 0x85, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x02, 0x00, 0x00, 0x01, 0x00, 0x82, 0x00,
    0x00, 0x00, 0x00, 0xFA, 0x00, 0x02, 0x50, 0x07, 0x00, 0x00, 0x87, 0x00, 0x00, 0x00, 0x00, 0xF0,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x82, 0x00, 0x40, 0x00, 0x00, 0xFC, 0x00, 0xFE, 0xD0, 0x08,
    0x00, 0x00, 0x85, 0x00, 0x40, 0x00, 0x00, 0xE8, 0x00, 0xFE, 0x00, 0x00, 0x01, 0x00, 0x82, 0x00,
    0x40, 0x00, 0x00, 0xEC, 0x00, 0xFE, 0x40, 0x07, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u16 D_002634F0[40] = {
    0x0000, 0x0008, 0x0000, 0x0800, 0x0400, 0x0000, 0x0000, 0x0085,
    0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x008D, 0x0000, 0xF800,
    0x0000, 0x0000, 0x0000, 0x0008, 0x0040, 0xF000, 0xFC00, 0x0000,
    0x0000, 0x0085, 0x0000, 0xE800, 0xFC00, 0x0000, 0x0000, 0x008D,
    0x0000, 0xE800, 0x0800, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000,
};

u16 D_00263540[40] = {
    0x0002, 0x0008, 0x0000, 0x0800, 0x0400, 0x0000, 0x0004, 0x0085,
    0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x008D, 0x0000, 0xF800,
    0x0000, 0x0000, 0x0006, 0x0008, 0x0040, 0xF000, 0xFC00, 0x0000,
    0x0008, 0x0085, 0x0000, 0xE800, 0xFC00, 0x0000, 0x000A, 0x008D,
    0x0000, 0xE800, 0x0800, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000,
};

u8 stage3_midboss_flash_palettes[48] = {
    0x03, 0x00, 0xFF, 0x7F, 0x00, 0x00, 0x80, 0x07, 0x04, 0x00, 0x05, 0x00, 0x1F, 0x00, 0x04, 0x00,
    0xFF, 0x7F, 0x00, 0x00, 0xC0, 0x05, 0x0B, 0x00, 0x0C, 0x00, 0x1F, 0x00, 0x05, 0x00, 0xFF, 0x7F,
    0x08, 0x00, 0x00, 0x00, 0x12, 0x00, 0x13, 0x00, 0x1F, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage3_midboss_mode_routines[32] = {
    0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00,
    0x08, 0x00, 0x09, 0x00, 0x0A, 0x00, 0x0B, 0x00, 0x0C, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage3_midboss2_state_routines_0[48] = {
    0x00, 0x68, 0x00, 0x28, 0x00, 0x64, 0x00, 0x22, 0x00, 0x66, 0x00, 0x16, 0x00, 0x62, 0x00, 0x10,
    0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00,
    0x08, 0x00, 0x09, 0x00, 0x0A, 0x00, 0x0B, 0x00, 0x0C, 0x00, 0x0D, 0x00, 0x0E, 0x00, 0x0F, 0x00,
};

u8 stage3_midboss2_state_routines_1[32] = {
    0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00,
    0x08, 0x00, 0x09, 0x00, 0x0A, 0x00, 0x0B, 0x00, 0x0C, 0x00, 0x0D, 0x00, 0x0E, 0x00, 0x0F, 0x00,
};

u8 D_00263630[32] = {
    0x00, 0x00, 0x62, 0x1C, 0x00, 0x00, 0x63, 0x1C, 0x00, 0x00, 0x64, 0x1C, 0x00, 0x00, 0x65, 0x1C,
    0x00, 0x00, 0x66, 0x1C, 0x00, 0x00, 0x67, 0x1C, 0x00, 0x00, 0x68, 0x1C, 0x00, 0x00, 0x69, 0x1C,
};

u8 D_00263650[32] = {
    0x00, 0x0B, 0x00, 0x0B, 0x80, 0x0B, 0x80, 0x0B, 0x00, 0x0C, 0x00, 0x0C, 0x80, 0x0C, 0x80, 0x0C,
    0x00, 0x0D, 0x00, 0x0D, 0x80, 0x0D, 0x80, 0x0D, 0x00, 0x0E, 0x00, 0x0E, 0x80, 0x0E, 0x80, 0x0E,
};

u8 D_00263670[32] = {
    0x00, 0x00, 0x6B, 0x1C, 0x00, 0x00, 0x6C, 0x1C, 0x00, 0x00, 0x6D, 0x1C, 0x00, 0x00, 0x6E, 0x1C,
    0x00, 0x00, 0x6F, 0x1C, 0x00, 0x00, 0x70, 0x1C, 0x00, 0x00, 0x71, 0x1C, 0x00, 0x00, 0x72, 0x1C,
};

u8 D_00263690[32] = {
    0x00, 0x00, 0x73, 0x1C, 0x00, 0x00, 0x74, 0x1C, 0x00, 0x00, 0x75, 0x1C, 0x00, 0x00, 0x76, 0x1C,
    0x00, 0x00, 0x77, 0x1C, 0x00, 0x00, 0x78, 0x1C, 0x00, 0x00, 0x79, 0x1C, 0x00, 0x00, 0x7A, 0x1C,
};

u8 D_002636B0[32] = {
    0x00, 0x00, 0x7B, 0x1C, 0x00, 0x00, 0x7C, 0x1C, 0x00, 0x00, 0x7D, 0x1C, 0x00, 0x00, 0x7E, 0x1C,
    0x00, 0x00, 0x7F, 0x1C, 0x00, 0x00, 0x80, 0x1C, 0x00, 0x00, 0x81, 0x1C, 0x00, 0x00, 0x82, 0x1C,
};

u8 D_002636D0[32] = {
    0x00, 0x00, 0x83, 0x1C, 0x00, 0x00, 0x84, 0x1C, 0x00, 0x00, 0x85, 0x1C, 0x00, 0x00, 0x86, 0x1C,
    0x00, 0x00, 0x87, 0x1C, 0x00, 0x00, 0x88, 0x1C, 0x00, 0x00, 0x89, 0x1C, 0x00, 0x00, 0x8A, 0x1C,
};

u8 D_002636F0[32] = {
    0x01, 0xA0, 0x00, 0xF8, 0x00, 0xFC, 0x00, 0x00, 0xB8, 0x01, 0x20, 0x08, 0x00, 0x04, 0x00, 0x04,
    0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 D_00263710[64] = {
    0x00, 0x00, 0x8B, 0x1C, 0x00, 0x00, 0x8C, 0x1C, 0x00, 0x00, 0x8D, 0x1C, 0x00, 0x00, 0x8E, 0x1C,
    0x00, 0x00, 0x8F, 0x1C, 0x00, 0x00, 0x90, 0x1C, 0x00, 0x00, 0x91, 0x1C, 0x00, 0x00, 0x92, 0x1C,
    0x00, 0x00, 0x93, 0x1C, 0x00, 0x00, 0x94, 0x1C, 0x00, 0x00, 0x95, 0x1C, 0x00, 0x00, 0x96, 0x1C,
    0x00, 0x00, 0x97, 0x1C, 0x00, 0x00, 0x98, 0x1C, 0x00, 0x00, 0x99, 0x1C, 0x00, 0x00, 0x9A, 0x1C,
};

u8 D_00263750[96] = {
    0x00, 0x40, 0x00, 0x40, 0x00, 0x48, 0x00, 0x48, 0x00, 0x50, 0x00, 0x50, 0x00, 0x58, 0x00, 0x58,
    0x00, 0x60, 0x00, 0x60, 0x00, 0x68, 0x00, 0x68, 0x00, 0x70, 0x00, 0x70, 0x00, 0x78, 0x00, 0x78,
    0x00, 0x80, 0x00, 0x80, 0x00, 0x88, 0x00, 0x88, 0x00, 0x90, 0x00, 0x90, 0x00, 0x98, 0x00, 0x98,
    0x00, 0xA0, 0x00, 0xA0, 0x00, 0xA8, 0x00, 0xA8, 0x00, 0xB0, 0x00, 0xB0, 0x00, 0xB8, 0x00, 0xB8,
    0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC8, 0x00, 0xC8, 0x00, 0xD0, 0x00, 0xD0, 0x00, 0xD8, 0x00, 0xD8,
    0x00, 0xE0, 0x00, 0xE0, 0x00, 0xE8, 0x00, 0xE8, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0xF8, 0x00, 0xF8,
};
