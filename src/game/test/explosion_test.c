#include "common.h"
#include "entity.h"
#include "explosion.h"

/*
 * Debug enemy: sets off nine explosions in a 3 by 3 grid again and again, with each one's number drawn next to it.
 * Up or down on the second player's stick switches between the two pages of explosion kinds, and the second
 * player's B button selects the alternate set. This is its own part of the enemy state block (reg_a5).
 */
typedef struct {
    /* 0x00 */ u8 common[0x16];   /* EnemyState */
    /* 0x16 */ u8 page;
    /* 0x17 */ u8 seen_on_screen;
    /* 0x18 */ u8 interval;
    /* 0x19 */ u8 countdown;
} ExplosionTestState;

#define EXPLOSION_TEST(pointer) ((ExplosionTestState *)(pointer))

void enemy_set_entity_count(s32);

void explosion_test_first(void) {
    enemy_set_entity_count(0);
}

s32 enemy_set_task_state();                            /* extern */
s32 enemy_init_entities();                            /* extern */
extern s32 g_explosion_test_entities[];
extern s32 g_explosion_test_state;

void explosion_test_setup(void) {
    reg_a0 = (u8 *)g_explosion_test_entities;
    enemy_init_entities();
    reg_a0 = (u8 *)(&g_explosion_test_state);
    reg_d0.w = 1;
    enemy_set_task_state();
    reg_tmp.w = 0x38001C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
}

s32 explosion_spawn();
s32 input_get_p2_held();
s32 input_get_p2_pressed();
s32 sprite_draw_layer5_keep();
extern u16 g_explosion_test_positions[];
extern u16 g_explosion_test_labels[4]; /* one address per page, high word first */

void explosion_test_main(void) {
    u32 label_x;
    u32 label_y;
    u32 label_sprite;

    input_get_p2_pressed();
    reg_d0.h[0] &= 3;
    if (reg_d0.h[0] != 0) {
        EXPLOSION_TEST(reg_a5)->page += 1;
        EXPLOSION_TEST(reg_a5)->page &= 1;
    }
    EXPLOSION_TEST(reg_a5)->countdown -= 1;
    if ((s8) EXPLOSION_TEST(reg_a5)->countdown < 0) {
        EXPLOSION_TEST(reg_a5)->countdown = EXPLOSION_TEST(reg_a5)->interval;
        reg_d6.w = 0;
        reg_d6.b[0] = EXPLOSION_TEST(reg_a5)->page;
        reg_d4.h[0] = reg_d6.h[0];
        reg_d4.h[0] *= 8;
        reg_d6.h[0] += reg_d4.h[0];
        input_get_p2_held();
        reg_d0.h[0] &= 0x20;
        if (reg_d0.h[0] != 0) {
            reg_d6.h[0] |= 0x80;
        }
        reg_a1 = (u8 *)(g_explosion_test_positions);
        reg_d7.w = 8;
        do {
            reg_d0.h[0] = reg_d6.h[0];
            explosion_spawn();
            ENTITY(reg_a0)->y.h = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            ENTITY(reg_a0)->x.h = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            ENTITY(reg_a0)->misc.sh = 0x10;
            reg_d6.h[0] += 1;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    reg_d0.w = 0;
    reg_a0 = (u8 *)g_explosion_test_labels;
    reg_d0.b[0] = EXPLOSION_TEST(reg_a5)->page;
    reg_d0.h[0] *= 4;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(g_explosion_test_positions);
    reg_d7.w = 8;
    reg_a1 = (u8 *) reg_tmp.w;
    do {
        reg_d1.h[0] = *(u16 *)reg_a0;
        reg_d1.h[0] += 0x7FFF + 0x7D01;
        label_y = reg_d1.h[0];
        reg_tmp1.h[0] = label_y;
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        label_x = *(u16 *)(reg_a0 + 2);
        reg_d1.h[0] = label_x;
        reg_d2.w = 0x2B;
        reg_d3.h[0] = 0x208;
        reg_d4.h[0] = 0;
        reg_d1.h[0] += 0x7FFF + 0x7F01;
        sprite_draw_layer5_keep();
        reg_d1.w += 0xFC000400;
        label_sprite = *(u16 *)reg_a1;
        reg_a1 += 2;
        reg_d2.h[1] = label_sprite;
        reg_d2.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        sprite_draw_layer5_keep();
        reg_a0 += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
