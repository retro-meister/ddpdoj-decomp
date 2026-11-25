#include "common.h"
#include "entity.h"
#include "enemy.h"

/*
 * An invisible enemy that starts other enemies at a fixed interval from its own position, a set number of times
 * or until it leaves the screen. This is its own part of the enemy work block (reg_a5).
 */
typedef struct {
    /* 0x00 */ u8 common[0x16];   /* EnemyWork */
    /* 0x16 */ u16 kind;          /* which enemy it starts */
    /* 0x18 */ Field16 remaining; /* how many are left to start; 0 from the beginning: no limit */
    /* 0x1A */ u8 interval;
    /* 0x1B */ u8 countdown;
} SpawnerWork;

#define SPAWNER(pointer) ((SpawnerWork *)(pointer))

void enemy_set_entity_count(s32);

void enemy_spawner_first(void) {
    enemy_set_entity_count(0);
}

s32 enemy_init_entities();
extern u8 g_enemy_spawner_entities[];

void enemy_spawner_setup(void) {
    s8 high_byte;
    s8 high_byte2;
    u32 mask;

    reg_a0 = (u8 *)((s8 *)g_enemy_spawner_entities);
    enemy_init_entities();
    reg_tmp.h[1] = ENEMY_WORK(reg_a5)->script[0];
    reg_tmp.h[0] = ENEMY_WORK(reg_a5)->script[1];
    reg_a0 = (u8 *)((s8 *) reg_tmp.w);
    reg_tmp.b[1] = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_tmp.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
    reg_tmp.b[1] = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_tmp.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
    reg_d0.h[0] = 0xFF;
    mask = reg_d0.h[0];
    reg_d1.h[0] = mask;
    reg_d2.h[0] = mask;
    high_byte = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_tmp.b[1] = high_byte;
    reg_tmp.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d0.h[0] = mask & reg_tmp.h[0];
    if (reg_d0.h[0] == 2) {
        ENTITY(reg_a6)->offset_x.sh = 1;
        reg_d0.h[0] = 0xFF;
        reg_tmp.b[1] = *(s8 *)reg_a0;
        reg_a0 += 1;
        reg_tmp.b[0] = (u8) *(s8 *)reg_a0;
        reg_a0 += 1;
        reg_d0.h[0] = mask & reg_tmp.h[0];
    }
    reg_tmp.b[1] = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_tmp.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d1.h[0] &= reg_tmp.h[0];
    high_byte2 = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_tmp.b[1] = high_byte2;
    reg_tmp.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d2.h[0] &= reg_tmp.h[0];
    SPAWNER(reg_a5)->kind = (u16) reg_d0.h[0];
    SPAWNER(reg_a5)->remaining.h = (u16) reg_d1.h[0];
    *(u16 *)&SPAWNER(reg_a5)->interval = (u16) reg_d2.h[0];
    reg_tmp.w = (u32) ((s8 *)reg_a0);
    ENEMY_WORK(reg_a5)->script[0] = (u16) reg_tmp.h[1];
    ENEMY_WORK(reg_a5)->script[1] = (u16) reg_tmp.h[0];
}

s32 enemy_request_start_flags();
s32 enemy_remove();
s32 entity_follow_scroll();
extern u16 g_enemies_stopped;
extern u16 g_side_scroll_x[];

void enemy_spawner_main(void) {
    if (ENTITY(reg_a6)->offset_x.h != 0) goto scroll_done;
    entity_follow_scroll();
scroll_done:
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp1.w = 0;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x1C00;
    reg_d0.h[0] += g_side_scroll_x[0];
    reg_tmp1.h[0] = 0x9000;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x9000;
    if (reg_tmp.h[1] != 0) goto off_screen;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_d0.h[0];
    reg_tmp1.w = (s16)reg_d1.h[0];
    reg_d1.w = reg_tmp1.w;
    reg_d1.w += 0x4000;
    if ((s32)reg_d1.w <= 0x3800) goto off_screen;
    if ((s32)reg_d1.w < 0xB800) goto on_screen;
off_screen:
    if (ENTITY(reg_a6)->offset_y.h == 0) goto run_timer;
remove:
    enemy_remove();
    return;
on_screen:
    ENTITY(reg_a6)->offset_y.h = 1;
run_timer:
    if (g_enemies_stopped != 0) return;
    reg_tmp.b[0] = SPAWNER(reg_a5)->countdown;
    SPAWNER(reg_a5)->countdown -= 1;
    if ((s32)reg_tmp.b[0] > 0) return;
    SPAWNER(reg_a5)->countdown = SPAWNER(reg_a5)->interval;
    reg_d0.h[0] = SPAWNER(reg_a5)->kind;
    reg_d1.w = 0;
    reg_d1.b[0] = ENEMY_WORK(reg_a5)->start_flags;
    enemy_request_start_flags();
    ENEMY_WORK(reg_a0)->script[0] = ENEMY_WORK(reg_a5)->script[0];
    ENEMY_WORK(reg_a0)->script[1] = ENEMY_WORK(reg_a5)->script[1];
    ENEMY_WORK(reg_a0)->start_y = ENTITY(reg_a6)->y.h;
    ENEMY_WORK(reg_a0)->start_x = ENTITY(reg_a6)->x.h;
    ENEMY_WORK(reg_a0)->flags |= ENEMY_FLAG_FROM_SPAWNER;
    if (SPAWNER(reg_a5)->remaining.h == 0) return;
    SPAWNER(reg_a5)->remaining.b[0] -= 1;
    if (SPAWNER(reg_a5)->remaining.b[0] == 0) goto remove;
}
