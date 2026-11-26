#include "common.h"
#include "entity.h"
#include "explosion.h"
#include "enemy.h"

/* State blocks of the stage 2 ground enemies. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 dying;
    /* 0x17 */ u8 seen;
    /* 0x18 */ u16 next_drop_hp;
    /* 0x1A */ u8 hit_flash;
    /* 0x1B */ u8 palette;
    /* 0x1C */ u16 armed;
    /* 0x1E */ u16 drops;
    /* 0x20 */ u16 rearmed;
} BloomingBaseState;

/* The long warehouse, the square warehouse and the gymnasium. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 dying;
    /* 0x17 */ u8 seen;
    /* 0x18 */ u8 hit_flash;
    /* 0x19 */ u8 palette;
} BuildingState;

/* What the sliding gun and the wrecker gun share. */
#define STAGE2_GUN_HEAD \
    /* 0x00 */ u8 common[0x16]; \
    /* 0x16 */ u8 shot_interval; \
    /* 0x17 */ u8 seen; \
    /* 0x18 */ u16 phase;             /* 0: waiting, 1: opening, 2: firing, 3: closing */ \
    /* 0x1A */ u8 hit_flash; \
    /* 0x1B */ u8 palette; \
    /* 0x1C */ u8 first_wait; \
    /* 0x1D */ u8 wait; \
    /* 0x1E */ u8 volleys; \
    /* 0x1F */ u8 volleys_left; \
    /* 0x20 */ u16 frame;             /* 0: shut, 0x78: open */ \
    /* 0x22 */ EnemyTimer frame_timer;

typedef struct {
    STAGE2_GUN_HEAD
    /* 0x24 */ u16 hit_side[2];       /* address of the side of its hit box that moves, high word first */
    /* 0x28 */ u16 muzzle_x;
} SlidingGunState;

typedef struct {
    STAGE2_GUN_HEAD
    /* 0x24 */ u16 shield;
    /* 0x26 */ u16 unused_26;
    /* 0x28 */ u16 shake;
    /* 0x2A */ u16 wreck_delay;
    /* 0x2C */ u16 wreck_value;
} WreckerGunState;

typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 unused_16[4];
    /* 0x1A */ EnemyTimer frame_timer;
    /* 0x1C */ u16 frame;
    /* 0x1E */ u16 door_sprite[2];
} HangarState;

#define BLOOMING_BASE(pointer) ((BloomingBaseState *)(pointer))
#define BUILDING(pointer) ((BuildingState *)(pointer))
#define SLIDING_GUN(pointer) ((SlidingGunState *)(pointer))
#define WRECKER_GUN(pointer) ((WreckerGunState *)(pointer))
#define HANGAR(pointer) ((HangarState *)(pointer))

void stage2_blooming_base_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern s8 D_00262C40[];
extern s8 D_00262C50[];
extern s8 D_00262C60[];
extern u16 g_loop;
extern u16 g_stage_x2;
extern s8 enemy_move_end_requested;

void stage2_blooming_base_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    (*(s8 **)&reg_a0) = D_00262C60;
    enemy_init_entities();
    (*(s8 **)&reg_a0) = D_00262C50;
    reg_d0.w = 5;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        (*(s8 **)&reg_a0) = D_00262C40;
        reg_d0.h[0] = g_stage_x2;
        (*(s8 **)&reg_a0) = &(*(s8 **)&reg_a0)[reg_d0.h[0]];
        ENTITY(reg_a6)->attr.sb.palette = (s8) *((s8 *)reg_a0);
        BLOOMING_BASE(reg_a5)->palette = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
        BLOOMING_BASE(reg_a5)->hit_flash = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
        if (g_loop != 0) {
            BLOOMING_BASE(reg_a5)->drops = 0;
        }
    }
}

s32 pickup_spawn_plain();
s32 explosion_spawn();
s32 enemy_hitbox_debug_draw();
s32 enemy_remove();
s32 enemy_path_step();
s32 func_00170D00();
s32 sfx_explosion_ground_large();
s32 entity_draw_layer1();
s32 score_add_no_chain();
s32 score_add();
s32 rng_next_0_to_3();
extern u8 D_0028D998[8];
extern u16 g_damage_blink_counter;

void stage2_blooming_base(void) {
    u32 t;

    if (ENTITY(reg_a6)->flags.sb[0] < 0) goto block_explos;
    enemy_path_step();
    if (enemy_move_end_requested != 0) return;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x7000;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x1000;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x7000;
    if (reg_tmp.h[1] == 0) goto next_30;
    if (BLOOMING_BASE(reg_a5)->seen == 0) goto next_40;
    enemy_remove();
    return;
next_30:
    BLOOMING_BASE(reg_a5)->seen = 1;
next_40:
    if (BLOOMING_BASE(reg_a5)->armed == 0) goto next_45;
    if ((s32) ENTITY(reg_a6)->y.h < 0x3C00) goto next_43;
    if (ENTITY(reg_a6)->hp.sh >= 0) goto next_45;
    ENTITY(reg_a6)->hp.sh = 0x7FFF;
    BLOOMING_BASE(reg_a5)->next_drop_hp = 0x7EFF;
    BLOOMING_BASE(reg_a5)->drops += 1;
    BLOOMING_BASE(reg_a5)->rearmed = 1;
    goto next_45;
next_43:
    BLOOMING_BASE(reg_a5)->armed = 0;
    if (BLOOMING_BASE(reg_a5)->rearmed == 0) goto next_44;
    ENTITY(reg_a6)->hp.sh = 0x400;
    BLOOMING_BASE(reg_a5)->next_drop_hp = 0x300;
    goto next_45;
next_44:
    if ((s32) ENTITY(reg_a6)->hp.h < 0x1000) goto next_45;
    ENTITY(reg_a6)->hp.sh = 0x1000;
    BLOOMING_BASE(reg_a5)->next_drop_hp = 0xF00;
next_45:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) goto next_50;
    reg_d0.b[0] = BLOOMING_BASE(reg_a5)->palette;
    if ((s32) ENTITY(reg_a6)->hp.h >= 0x400) goto next_90;
    if (g_damage_blink_counter != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    if (reg_d0.b[0] == 0x19) {
        reg_d0.b[0] = BLOOMING_BASE(reg_a5)->palette;
    }
    reg_d2.b[0] = BLOOMING_BASE(reg_a5)->hit_flash;
    reg_d0.b[0] ^= reg_d2.b[0];
    reg_d2.h[0] = ENTITY(reg_a6)->hp.h;
    if ((s16)(reg_d2.h[0]) < 0) goto block_dead;
    if ((s32) BLOOMING_BASE(reg_a5)->next_drop_hp <= (s32)(reg_d2.h[0] & 0xFFFF)) goto next_90;
    reg_d6.h[0] = BLOOMING_BASE(reg_a5)->drops;
    t = reg_d0.w;
    do {
        reg_d1.h[0] = 0x8C0;
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        rng_next_0_to_3();
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 = D_0028D998;
        reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d0.w = 0x10;
        pickup_spawn_plain();
    } while ((s16)(--reg_d6.h[0]) >= 0);
    reg_d0.w = t;
    BLOOMING_BASE(reg_a5)->next_drop_hp -= 0x100;
next_90:
    ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
block_objset:
    entity_draw_layer1();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    return;
block_dead:
    sfx_explosion_ground_large();
    reg_d0.w = 0x32;
    score_add();
    ENTITY(reg_a6)->flags.h = 0x8080;
    ENTITY(reg_a6)->attr.b.palette = BLOOMING_BASE(reg_a5)->palette;
    reg_d0.w = 0xD;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    func_00170D00();
    EXPLOSION(reg_a0)->debris = 2;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->start_y = 0xFA00;
    EXPLOSION(reg_a0)->start_x = 0x600;
    EXPLOSION(reg_a0)->follows_scroll = 1;
    EXPLOSION(reg_a0)->delay = 4;
    reg_d0.w = 0xD;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    func_00170D00();
    EXPLOSION(reg_a0)->debris = 2;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    EXPLOSION(reg_a0)->start_y = 0xFA00;
    EXPLOSION(reg_a0)->start_x = 0xFA00;
    EXPLOSION(reg_a0)->follows_scroll = 1;
    EXPLOSION(reg_a0)->delay = 2;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    func_00170D00();
    EXPLOSION(reg_a0)->debris = 2;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->start_y = 0xFE00;
    EXPLOSION(reg_a0)->start_x = 0;
    EXPLOSION(reg_a0)->follows_scroll = 1;
    goto block_objset;
block_explos:
    reg_tmp.b[0] = BLOOMING_BASE(reg_a5)->dying;
    BLOOMING_BASE(reg_a5)->dying -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_objset;
    enemy_remove();
}

void stage2_long_warehouse_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 enemy_set_task_state();                            /* extern */
s32 enemy_init_entities();                            /* extern */
s32 enemy_path_start();                            /* extern */
extern s8 D_00262C80[];
extern s8 D_00262C90[];
extern s8 D_0028D9A0;

void stage2_long_warehouse_start(void) {
    (*(s8 **)&reg_a0) = D_00262C90;
    enemy_init_entities();
    (*(s8 **)&reg_a0) = &D_0028D9A0;
    reg_d0.w = 1;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        (*(s8 **)&reg_a0) = D_00262C80;
        reg_d0.h[0] = g_stage_x2;
        (*(s8 **)&reg_a0) = &(*(s8 **)&reg_a0)[reg_d0.h[0]];
        ENTITY(reg_a6)->attr.sb.palette = (s8) *((s8 *)reg_a0);
        BUILDING(reg_a5)->palette = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
        BUILDING(reg_a5)->hit_flash = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
    }
}

s32 func_00170A60();
extern u16 D_00262CB0[];

void stage2_long_warehouse(void) {
    u8 t1;

    enemy_path_step();
    if (enemy_move_end_requested != 0) return;
    {
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x6C00;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1200;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x6C00;
        if (reg_tmp.h[1] != 0) {
            if (BUILDING(reg_a5)->seen != 0) {
                enemy_remove();
                return;
            }
            goto next_1;
        }
        BUILDING(reg_a5)->seen = 1U;
    }
next_1:
    if (ENTITY(reg_a6)->flags.sb[0] < 0) goto block_explos;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) goto next_50;
    reg_d0.b[0] = BUILDING(reg_a5)->palette;
    if ((s32) ENTITY(reg_a6)->hp.h >= 0x380) goto next_90;
    if (g_damage_blink_counter != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    if (reg_d0.b[0] == 0x19) {
        reg_d0.b[0] = BUILDING(reg_a5)->palette;
    }
    reg_d2.b[0] = BUILDING(reg_a5)->hit_flash;
    reg_d0.b[0] ^= reg_d2.b[0];
    reg_d2.h[0] = ENTITY(reg_a6)->hp.h;
    if ((s16) reg_d2.h[0] < 0) goto block_dead;
next_90:
    ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
block_objset:
    func_00170A60();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    return;
block_dead:
    sfx_explosion_ground_large();
    reg_d0.w = 0x13;
    score_add();
    ENTITY(reg_a6)->flags.h = 0x8080;
    t1 = BUILDING(reg_a5)->palette;
    ENTITY(reg_a6)->attr.b.palette = t1;
    reg_d0.w = 5;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    func_00170D00();
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->start_y = 0xA00;
    EXPLOSION(reg_a0)->start_x = 0x80;
    EXPLOSION(reg_a0)->follows_scroll = 1;
    EXPLOSION(reg_a0)->delay = 6;
    reg_d0.w = 5;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    func_00170D00();
    EXPLOSION(reg_a0)->debris = 2;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    EXPLOSION(reg_a0)->start_y = 0xFC00;
    EXPLOSION(reg_a0)->start_x = 0xFF80;
    EXPLOSION(reg_a0)->follows_scroll = 1;
    EXPLOSION(reg_a0)->attr.b.flip = 0x40;
    EXPLOSION(reg_a0)->delay = 3;
    reg_d0.w = 5;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    func_00170D00();
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->start_y = 0xEE00;
    EXPLOSION(reg_a0)->start_x = 0x80;
    EXPLOSION(reg_a0)->follows_scroll = 1;
    EXPLOSION(reg_a0)->delay = 0;
    goto block_objset;
block_explos:
    reg_tmp.b[0] = BUILDING(reg_a5)->dying;
    BUILDING(reg_a5)->dying -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_objset;
    reg_a4 = (u8 *)(D_00262CB0);
    reg_d0.h[0] = *(u16 *)reg_a4;
    reg_a4 += 2;
    reg_d6.h[0] = *(u16 *)reg_a4;
    reg_a4 += 2;
    do {
        reg_d1.h[1] = *(u16 *)reg_a4;
        reg_a4 += 2;
        reg_d1.h[0] = *(u16 *)reg_a4;
        reg_a4 += 2;
        pickup_spawn_plain();
    } while ((s16)(--reg_d6.h[0]) >= 0);
    enemy_remove();
}

void stage2_square_warehouse_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern s8 D_00262CD0[];
extern s8 D_00262CE0[];
extern s8 D_0028D9A4;

void stage2_square_warehouse_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    (*(s8 **)&reg_a0) = D_00262CE0;
    enemy_init_entities();
    (*(s8 **)&reg_a0) = &D_0028D9A4;
    reg_d0.w = 1;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        (*(s8 **)&reg_a0) = D_00262CD0;
        reg_d0.h[0] = g_stage_x2;
        (*(s8 **)&reg_a0) = &(*(s8 **)&reg_a0)[reg_d0.h[0]];
        ENTITY(reg_a6)->attr.sb.palette = (s8) *((s8 *)reg_a0);
        BUILDING(reg_a5)->palette = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
        BUILDING(reg_a5)->hit_flash = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
        if (ENTITY(reg_a6)->misc.b.user != 0) {
            ENTITY(reg_a6)->misc.b.user = 0U;
            ENTITY(reg_a6)->attr.b.flip |= 0x40;
        }
    }
}

s32 pickup_spawn_variant();

void stage2_square_warehouse(void) {
    enemy_path_step();
    if (enemy_move_end_requested != 0) return;
    {
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x6800;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1400;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x6800;
        if (reg_tmp.h[1] != 0) {
            if (BUILDING(reg_a5)->seen != 0) {
                enemy_remove();
                return;
            }
            goto next_1;
        }
        BUILDING(reg_a5)->seen = 1U;
    }
next_1:
    if (ENTITY(reg_a6)->flags.sb[0] < 0) goto next_2;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) goto next_50;
    reg_d0.b[0] = BUILDING(reg_a5)->palette;
    if ((s32) ENTITY(reg_a6)->hp.h >= 0x380) goto next_90;
    if (g_damage_blink_counter != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    if (reg_d0.b[0] == 0x19) {
        reg_d0.b[0] = BUILDING(reg_a5)->palette;
    }
    reg_d2.b[0] = BUILDING(reg_a5)->hit_flash;
    reg_d0.b[0] ^= reg_d2.b[0];
    reg_d2.h[0] = ENTITY(reg_a6)->hp.h;
    if ((s16) reg_d2.h[0] < 0) goto next_3;
next_90:
    ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
next_4:
    func_00170A60();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    return;
next_3:
    sfx_explosion_ground_large();
    reg_d0.w = 0x14;
    score_add();
    ENTITY(reg_a6)->flags.h = 0x8080;
    ENTITY(reg_a6)->attr.b.palette = BUILDING(reg_a5)->palette;
    reg_d0.w = 0xD;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    func_00170D00();
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    EXPLOSION(reg_a0)->start_y = 0;
    EXPLOSION(reg_a0)->start_x = 0;
    EXPLOSION(reg_a0)->follows_scroll = 1;
    EXPLOSION(reg_a0)->delay = 3;
    reg_d0.w = 5;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    func_00170D00();
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->start_y = 0xF200;
    EXPLOSION(reg_a0)->start_x = 0x80;
    EXPLOSION(reg_a0)->follows_scroll = 1;
    EXPLOSION(reg_a0)->delay = 0;
    goto next_4;
next_2:
    reg_tmp.b[0] = BUILDING(reg_a5)->dying;
    BUILDING(reg_a5)->dying -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_4;
    reg_d0.w = 0xC;
    reg_d1.w = 0xFF00FE00;
    if (ENTITY(reg_a6)->attr.b.flip & 0x40) {
        reg_d1.h[0] *= -1;
    }
    reg_d2.b[0] = ENTITY(reg_a6)->misc.b.draw_layer;
    pickup_spawn_variant();
    enemy_remove();
}

void stage2_gymnasium_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

s32 enemy_set_task_state();                            /* extern */
s32 enemy_init_entities();                            /* extern */
s32 enemy_path_start();                            /* extern */
extern s8 D_00262D00[];
extern s8 D_00262D10[];
extern s8 D_0028D9A8;

void stage2_gymnasium_start(void) {
    (*(s8 **)&reg_a0) = D_00262D10;
    enemy_init_entities();
    (*(s8 **)&reg_a0) = &D_0028D9A8;
    reg_d0.w = 1;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        (*(s8 **)&reg_a0) = D_00262D00;
        reg_d0.h[0] = g_stage_x2;
        (*(s8 **)&reg_a0) = &(*(s8 **)&reg_a0)[reg_d0.h[0]];
        ENTITY(reg_a6)->attr.sb.palette = (s8) *((s8 *)reg_a0);
        BUILDING(reg_a5)->palette = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
        BUILDING(reg_a5)->hit_flash = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
    }
}

void stage2_gymnasium(void) {
    u8 *t1;

    enemy_path_step();
    if (enemy_move_end_requested != 0) return;
    {
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x6800;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1400;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x6800;
        if (reg_tmp.h[1] != 0) {
            if (BUILDING(reg_a5)->seen != 0) {
                enemy_remove();
                return;
            }
            goto next_1;
        }
        BUILDING(reg_a5)->seen = 1U;
    }
next_1:
    if (ENTITY(reg_a6)->flags.sb[0] < 0) goto next_2;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) goto next_50;
    reg_d0.b[0] = BUILDING(reg_a5)->palette;
    if ((s32) ENTITY(reg_a6)->hp.h >= 0x380) goto next_90;
    if (g_damage_blink_counter != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    if (reg_d0.b[0] == 0x19) {
        reg_d0.b[0] = BUILDING(reg_a5)->palette;
    }
    reg_d2.b[0] = BUILDING(reg_a5)->hit_flash;
    reg_d0.b[0] ^= reg_d2.b[0];
    reg_d2.h[0] = ENTITY(reg_a6)->hp.h;
    if ((s16) reg_d2.h[0] < 0) goto next_3;
next_90:
    ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
next_4:
    func_00170A60();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    return;
next_3:
    sfx_explosion_ground_large();
    reg_d0.w = 0x15;
    score_add();
    ENTITY(reg_a6)->flags.h = 0x8080;
    ENTITY(reg_a6)->attr.b.palette = BUILDING(reg_a5)->palette;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    func_00170D00();
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->start_y = 0xC00;
    EXPLOSION(reg_a0)->start_x = 0xFE80;
    EXPLOSION(reg_a0)->follows_scroll = 1;
    EXPLOSION(reg_a0)->attr.b.flip = 0x40;
    EXPLOSION(reg_a0)->delay = 2;
    reg_d0.w = 0xD;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    func_00170D00();
    EXPLOSION(reg_a0)->debris = 2;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    EXPLOSION(reg_a0)->start_y = 0xFA00;
    EXPLOSION(reg_a0)->start_x = 0xFF00;
    EXPLOSION(reg_a0)->follows_scroll = 1;
    EXPLOSION(reg_a0)->delay = 1;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    func_00170D00();
    t1 = (u8 *)((void *)1);
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->start_y = 0xEE00;
    EXPLOSION(reg_a0)->start_x = 0;
    EXPLOSION(reg_a0)->follows_scroll = 1;
    EXPLOSION(reg_a0)->delay = 0;
    goto next_4;
next_2:
    reg_tmp.b[0] = BUILDING(reg_a5)->dying;
    BUILDING(reg_a5)->dying -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_4;
    reg_d0.w = 0xC;
    reg_d1.w = 0xFAC0FA40;
    reg_d2.b[0] = ENTITY(reg_a6)->misc.b.draw_layer;
    pickup_spawn_variant();
    enemy_remove();
}

void stage2_sliding_gun_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

extern u16 D_00262D30[];
extern u16 D_00262D40[];
extern u16 D_00262D60[];
extern u16 D_00262D80[];
extern u16 g_rank_6_16;
extern u16 g_stage;

void stage2_sliding_gun_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)(D_00262D60);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_00262D40);
    reg_d0.w = 9;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_d0.b[0] = 6;
        if ((s32) g_stage > 1) {
            reg_d0.b[0] = 2;
        }
        SLIDING_GUN(reg_a5)->shot_interval = (u8) reg_d0.b[0];
        reg_d0.h[0] = g_rank_6_16;
        SLIDING_GUN(reg_a5)->wait -= reg_d0.b[0];
        if (ENTITY(reg_a6)->misc.b.user != 0) {
            ENTITY(reg_a6)->misc.b.user = 0U;
            ENTITY(reg_a6)->attr.b.flip |= 0x40;
            reg_tmp.w = 0x14;
            SLIDING_GUN(reg_a5)->hit_side[0] = (u16) reg_tmp.h[1];
            SLIDING_GUN(reg_a5)->hit_side[1] = (u16) reg_tmp.h[0];
            SLIDING_GUN(reg_a5)->muzzle_x = 0;
        }
        reg_d0.w = (u32) reg_a6;
        reg_tmp.h[1] = SLIDING_GUN(reg_a5)->hit_side[0];
        reg_tmp.h[0] = SLIDING_GUN(reg_a5)->hit_side[1];
        reg_tmp.w += reg_d0.w;
        SLIDING_GUN(reg_a5)->hit_side[0] = (u16) reg_tmp.h[1];
        SLIDING_GUN(reg_a5)->hit_side[1] = (u16) reg_tmp.h[0];
        reg_d0.h[0] = SLIDING_GUN(reg_a5)->frame;
        reg_a0 = (u8 *)(D_00262D80);
        reg_tmp.h[1] = SLIDING_GUN(reg_a5)->hit_side[0];
        reg_tmp.h[0] = SLIDING_GUN(reg_a5)->hit_side[1];
        reg_a1 = (u8 *)(reg_tmp.w);
        *(u16 *)reg_a1 = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_00262D30);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        SLIDING_GUN(reg_a5)->palette = *(s8 *)reg_a0;
        reg_a0 += 1;
        SLIDING_GUN(reg_a5)->hit_flash = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}


s32 pickup_spawn_variant_here();
s32 bullet_fire256_2way();
s32 enemy_fire_distance_check();
s32 func_00170DE0();
s32 sfx_explosion_ground_medium();
s32 direction256_between();
extern u16 g_bullets_blocked;
extern u16 g_enemies_stopped;
extern u16 g_rank_4_16;
extern s16 g_player2[56];
extern s16 g_player1[56];

void stage2_sliding_gun(void) {
    s16 *temp_v1;
    u16 temp_a0_3;
    u8 temp_v0;

    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7C00;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0xA00;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x7C00;
        if (reg_tmp.h[1] != 0) {
            if (SLIDING_GUN(reg_a5)->seen != 0) {
                enemy_remove();
                return;
            }
            goto block_5;
        }
        SLIDING_GUN(reg_a5)->seen = 1U;
block_5:
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = SLIDING_GUN(reg_a5)->palette;
            if (((s32) ENTITY(reg_a6)->hp.h < 0x180) && (g_damage_blink_counter == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_12;
        }
        ENTITY(reg_a6)->flags.b[1] &= 0xA3;
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = SLIDING_GUN(reg_a5)->palette;
        }
        reg_d2.b[0] = SLIDING_GUN(reg_a5)->hit_flash;
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
block_12:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0) && ((s16) ENTITY(reg_a6)->y.h >= 0x2C00)) {
                reg_d0.h[0] = SLIDING_GUN(reg_a5)->phase;
                if (reg_d0.h[0] == 0) {
                    reg_tmp.b[0] = SLIDING_GUN(reg_a5)->wait;
                    SLIDING_GUN(reg_a5)->wait -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        SLIDING_GUN(reg_a5)->wait = 0x10U;
                        SLIDING_GUN(reg_a5)->phase = 1U;
                    }
                } else if ((reg_d0.h[0] & 0xFFFF) == 1) {
                    reg_tmp.b[0] = SLIDING_GUN(reg_a5)->frame_timer.b.countdown;
                    SLIDING_GUN(reg_a5)->frame_timer.b.countdown -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        SLIDING_GUN(reg_a5)->frame_timer.b.countdown = (u8) SLIDING_GUN(reg_a5)->frame_timer.b.interval;
                        SLIDING_GUN(reg_a5)->frame += 8;
                        if (SLIDING_GUN(reg_a5)->frame == 0x78) {
                            SLIDING_GUN(reg_a5)->phase = 2U;
                        }
                        goto block_38;
                    }
                } else if ((reg_d0.h[0] & 0xFFFF) == 2) {
                    reg_tmp.b[0] = SLIDING_GUN(reg_a5)->wait;
                    SLIDING_GUN(reg_a5)->wait -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        SLIDING_GUN(reg_a5)->wait = (u8) SLIDING_GUN(reg_a5)->shot_interval;
                        enemy_fire_distance_check();
                        if (cond_flag == 0) {
                            reg_a0 = (u8 *)(((u16 *)g_player1));
                            reg_a1 = (u8 *)(((u16 *)g_player2));
                            if (ENEMY_STATE(reg_a5)->target_player != 0) {
                                reg_atmp = (u8 *)(reg_a0);
                                reg_a0 = (u8 *)(reg_a1);
                                reg_a1 = (u8 *)(reg_atmp);
                            }
                            temp_v1 = (s16 *)(reg_a0);
                            if ((*(s16 *)((u8 *)(temp_v1) + (0))) >= 0) {
                                if (*(s16 *)reg_a1 < 0) {
                                    reg_a0 = (u8 *)(reg_a1);
                                    reg_atmp = (u8 *)(temp_v1);
                                    reg_a1 = (u8 *)(temp_v1);
                                    goto block_30;
                                }
                            } else {
block_30:
                                reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                                reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                                reg_d7.h[0] = 0x300;
                                reg_tmp7.h[0] = reg_d7.h[0];
                                reg_d0.h[0] += reg_d7.h[0];
                                reg_d7.h[0] = reg_d7.h[1];
                                reg_d7.h[1] = reg_tmp7.h[0];
                                reg_d7.h[0] = SLIDING_GUN(reg_a5)->muzzle_x;
                                reg_d1.h[0] += reg_d7.h[0];
                                direction256_between();
                                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                temp_a0_3 = ENTITY(reg_a6)->x.h;
                                reg_d2.h[0] = temp_a0_3;
                                reg_d3.w = reg_d7.w;
                                reg_d4.w = (u32) reg_a6;
                                reg_d0.w = 0x1000C;
                                bullet_fire256_2way();
                            }
                            reg_tmp.b[0] = SLIDING_GUN(reg_a5)->volleys_left;
                            SLIDING_GUN(reg_a5)->volleys_left -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                SLIDING_GUN(reg_a5)->volleys_left = (u8) SLIDING_GUN(reg_a5)->volleys;
                                SLIDING_GUN(reg_a5)->wait = 0x10U;
                                SLIDING_GUN(reg_a5)->phase = 3U;
                            }
                        }
                    }
                } else {
                    temp_v0 = SLIDING_GUN(reg_a5)->wait;
                    if (temp_v0 != 0) {
                        SLIDING_GUN(reg_a5)->wait = (u8) (temp_v0 - 1);
                    } else {
                        reg_tmp.b[0] = SLIDING_GUN(reg_a5)->frame_timer.b.countdown;
                        SLIDING_GUN(reg_a5)->frame_timer.b.countdown -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            SLIDING_GUN(reg_a5)->frame_timer.b.countdown = (u8) SLIDING_GUN(reg_a5)->frame_timer.b.interval;
                            SLIDING_GUN(reg_a5)->frame -= 8;
                            if (SLIDING_GUN(reg_a5)->frame == 0) {
                                reg_d0.h[0] = 0x40;
                                reg_d0.h[0] -= g_rank_4_16;
                                SLIDING_GUN(reg_a5)->wait = (u8) reg_d0.b[0];
                                SLIDING_GUN(reg_a5)->phase = 0U;
                            }
block_38:
                            reg_d0.h[0] = SLIDING_GUN(reg_a5)->frame;
                            reg_a0 = (u8 *)(D_00262D80);
                            reg_a0 += reg_d0.h[0];
                            ENTITY(reg_a6)->draw.h = *(u16 *)reg_a0;
                            reg_a0 += 2;
                            ENTITY(reg_a6)->sprite.h = *(u16 *)reg_a0;
                            reg_a0 += 2;
                            reg_tmp.h[1] = SLIDING_GUN(reg_a5)->hit_side[0];
                            reg_tmp.h[0] = SLIDING_GUN(reg_a5)->hit_side[1];
                            reg_a1 = (u8 *) reg_tmp.w;
                            *(s16 *)reg_a1 = (s16) *(u16 *)reg_a0;
                            reg_a0 += 2;
                        }
                    }
                }
            }
            func_00170A60();
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            return;
        }
        sfx_explosion_ground_medium();
        reg_d0.w = 0x34;
        score_add();
        reg_d0.w = 8;
        func_00170DE0();
        pickup_spawn_variant_here();
        reg_d0.w = 0xC;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        func_00170D00();
        EXPLOSION(reg_a0)->debris = 1;
        EXPLOSION(reg_a0)->debris_arg = 0;
        EXPLOSION(reg_a0)->start_y = 0xFD00;
        EXPLOSION(reg_a0)->start_x = 0;
        EXPLOSION(reg_a0)->follows_scroll = 1;
        enemy_remove();
    }
}

void stage2_wrecker_gun_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

extern s8 D_00262E00[];
extern s8 D_00262E10[];
extern s8 D_00262E30[];
extern u16 g_rank_1_16;

void stage2_wrecker_gun_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    (*(s8 **)&reg_a0) = D_00262E30;
    enemy_init_entities();
    (*(s8 **)&reg_a0) = D_00262E10;
    reg_d0.w = 0xB;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_d0.b[0] = 6;
        if ((s32) g_stage > 0x1) {
            reg_d0.b[0] = 2;
        }
        WRECKER_GUN(reg_a5)->shot_interval = (u8) reg_d0.b[0];
        reg_d0.h[0] = g_rank_1_16;
        WRECKER_GUN(reg_a5)->first_wait -= reg_d0.b[0];
        (*(s8 **)&reg_a0) = D_00262E00;
        reg_d0.h[0] = g_stage_x2;
        (*(s8 **)&reg_a0) = &(*(s8 **)&reg_a0)[reg_d0.h[0]];
        ENTITY(reg_a6)->attr.sb.palette = (s8) *((s8 *)reg_a0);
        WRECKER_GUN(reg_a5)->palette = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
        WRECKER_GUN(reg_a5)->hit_flash = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
    }
}

s32 bullet_fire256();
s32 enemy_switch_target_player();
s32 bullet_cancel_with_flags();
extern u16 g_direction64_offsets_432[];
extern u16 D_00262E50[];
extern u16 g_rank_2_16;
extern u16 g_bomb_entities[24];

void stage2_wrecker_gun(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 *temp_v1;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    u16 temp_v0_6;
    u8 temp_a0;
    u8 temp_v0_5;

    var_a0 = arg0;
    var_a1 = arg1;
    var_a2 = arg2;
    var_a3 = arg3;
    if (ENTITY(reg_a6)->flags.sb[0] >= 0) {
        enemy_path_step();
        if (enemy_move_end_requested == 0) {
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            reg_tmp1.w = 0;
            reg_tmp1.h[0] = 0x6000;
            reg_tmp.w = 0;
            reg_d0.h[0] += 0x1800;
            reg_tmp.h[0] = reg_d0.h[0];
            reg_tmp.w += reg_tmp1.w;
            reg_d0.h[0] += 0x6000;
            if (reg_tmp.h[1] != 0) {
                if (WRECKER_GUN(reg_a5)->seen != 0) {
                    enemy_remove();
                    return;
                }
                goto block_6;
            }
            WRECKER_GUN(reg_a5)->seen = 1U;
block_6:
            if ((s16) WRECKER_GUN(reg_a5)->shield >= 0) {
                ENTITY(reg_a6)->hp.h = 0x7FFFU;
                reg_d0.w = 1;
                if (((s16 *)g_bomb_entities)[0] < 0) {
                    reg_d0.w = 2;
                }
                WRECKER_GUN(reg_a5)->shield -= reg_d0.h[0];
                if ((s16) WRECKER_GUN(reg_a5)->shield < 0) {
                    ENTITY(reg_a6)->hp.h = 0x600U;
                }
            }
            reg_d1.w = 0x5C;
            reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
            if (reg_d1.b[0] == 0) {
                reg_d0.b[0] = WRECKER_GUN(reg_a5)->palette;
                if (((s32) ENTITY(reg_a6)->hp.h < 0x180) && (g_damage_blink_counter == 0)) {
                    reg_d0.w = 0x19;
                }
                goto block_18;
            }
            ENTITY(reg_a6)->flags.b[1] &= 0xA3;
            score_add_no_chain();
            reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
            if (reg_d0.b[0] == 0x19) {
                reg_d0.b[0] = WRECKER_GUN(reg_a5)->palette;
            }
            reg_d2.b[0] = WRECKER_GUN(reg_a5)->hit_flash;
            reg_d0.b[0] ^= reg_d2.b[0];
            if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
block_18:
                ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
                if (g_enemies_stopped == 0) {
                    reg_d0.h[0] = WRECKER_GUN(reg_a5)->phase;
                    if (reg_d0.h[0] == 0) {
                        if ((s16) ENTITY(reg_a6)->y.h >= 0x1000) {
                            reg_tmp.b[0] = WRECKER_GUN(reg_a5)->wait;
                            WRECKER_GUN(reg_a5)->wait -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                reg_d0.h[0] = 0x10;
                                reg_d0.h[0] -= g_rank_1_16;
                                reg_d0.h[0] += 8;
                                WRECKER_GUN(reg_a5)->wait = (u8) reg_d0.b[0];
                                WRECKER_GUN(reg_a5)->phase = 1U;
                            }
                        }
                    } else if ((reg_d0.h[0] & 0xFFFF) == 1) {
                        reg_tmp.b[0] = WRECKER_GUN(reg_a5)->frame_timer.b.countdown;
                        WRECKER_GUN(reg_a5)->frame_timer.b.countdown -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            WRECKER_GUN(reg_a5)->frame_timer.b.countdown = (u8) WRECKER_GUN(reg_a5)->frame_timer.b.interval;
                            WRECKER_GUN(reg_a5)->frame += 8;
                            reg_tmp.h[0] = WRECKER_GUN(reg_a5)->frame;
                            if (WRECKER_GUN(reg_a5)->frame == 0x78) {
                                WRECKER_GUN(reg_a5)->phase = 2U;
                            }
                            goto block_60;
                        }
                    } else if ((reg_d0.h[0] & 0xFFFF) == 2) {
                        reg_tmp.b[0] = WRECKER_GUN(reg_a5)->wait;
                        WRECKER_GUN(reg_a5)->wait -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            WRECKER_GUN(reg_a5)->wait = (u8) WRECKER_GUN(reg_a5)->shot_interval;
                            if ((s16) ENTITY(reg_a6)->y.h >= 0x1000) {
                                reg_a0 = (u8 *)(((u16 *)g_player1));
                                reg_a1 = (u8 *)(((u16 *)g_player2));
                                if (ENEMY_STATE(reg_a5)->target_player != 0) {
                                    reg_atmp = (u8 *)(reg_a0);
                                    reg_a0 = (u8 *)(reg_a1);
                                    reg_a1 = (u8 *)(reg_atmp);
                                }
                                temp_v1 = (s16 *)(reg_a0);
                                if ((*(s16 *)((u8 *)(temp_v1) + (0))) >= 0) {
                                    if (*(s16 *)reg_a1 < 0) {
                                        reg_a0 = (u8 *)(reg_a1);
                                        reg_atmp = (u8 *)(temp_v1);
                                        reg_a1 = (u8 *)(temp_v1);
                                        goto block_35;
                                    }
                                } else {
block_35:
                                    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                                    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                                    reg_d0.h[0] += 0xA00;
                                    direction256_between();
                                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                                    reg_d5.w = 0x0A000000;
                                    reg_d0.w = 0xB;
                                    reg_a0 = (u8 *)(g_direction64_offsets_432);
                                    reg_d4.w = 0;
                                    if (WRECKER_GUN(reg_a5)->volleys_left & 1) {
                                        reg_d1.h[0] -= 0x28;
                                        reg_d7.w = 5;
                                        do {
                                            reg_d3.h[0] = reg_d1.h[0];
                                            reg_d3.h[0] += 2;
                                            reg_d3.h[0] &= 0xFC;
                                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                            reg_d3.w += reg_d5.w;
                                            bullet_fire256();
                                            reg_d1.h[0] += 0x10;
                                        } while ((s16)(--reg_d7.h[0]) >= 0);
                                    } else {
                                        reg_d1.h[0] -= 0x30;
                                        reg_d7.w = 6;
                                        do {
                                            reg_d3.h[0] = reg_d1.h[0];
                                            reg_d3.h[0] += 2;
                                            reg_d3.h[0] &= 0xFC;
                                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                            reg_d3.w += reg_d5.w;
                                            bullet_fire256();
                                            reg_d1.h[0] += 0x10;
                                        } while ((s16)(--reg_d7.h[0]) >= 0);
                                    }
                                }
                            }
                            reg_tmp.b[0] = WRECKER_GUN(reg_a5)->volleys_left;
                            WRECKER_GUN(reg_a5)->volleys_left -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                WRECKER_GUN(reg_a5)->volleys_left = (u8) WRECKER_GUN(reg_a5)->volleys;
                                reg_d0.h[0] = 0x10;
                                reg_d0.h[0] -= g_rank_1_16;
                                reg_d0.h[0] += 8;
                                WRECKER_GUN(reg_a5)->wait = (u8) reg_d0.b[0];
                                WRECKER_GUN(reg_a5)->phase = 3U;
                            }
                        }
                    } else {
                        temp_v0_5 = WRECKER_GUN(reg_a5)->wait;
                        if (temp_v0_5 != 0) {
                            WRECKER_GUN(reg_a5)->wait = (u8) (temp_v0_5 - 1);
                        } else {
                            reg_tmp.b[0] = WRECKER_GUN(reg_a5)->frame_timer.b.countdown;
                            WRECKER_GUN(reg_a5)->frame_timer.b.countdown -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                WRECKER_GUN(reg_a5)->frame_timer.b.countdown = (u8) WRECKER_GUN(reg_a5)->frame_timer.b.interval;
                                WRECKER_GUN(reg_a5)->frame -= 8;
                                if (WRECKER_GUN(reg_a5)->frame == 0) {
                                    enemy_switch_target_player();
                                    reg_d0.h[0] = 0x20;
                                    reg_d0.h[0] -= g_rank_2_16;
                                    WRECKER_GUN(reg_a5)->wait = (u8) reg_d0.b[0];
                                    WRECKER_GUN(reg_a5)->phase = 0U;
                                }
block_60:
                                reg_d0.h[0] = WRECKER_GUN(reg_a5)->frame;
                                reg_a0 = (u8 *)(D_00262E50);
                                reg_a0 += reg_d0.h[0];
                                ENTITY(reg_a6)->draw.h = *(u16 *)reg_a0;
                                reg_a0 += 2;
                                ENTITY(reg_a6)->sprite.h = *(u16 *)reg_a0;
                                reg_a0 += 2;
                                ENTITY(reg_a6)->hit_x_plus.h = *(u16 *)reg_a0;
                                reg_a0 += 2;
                                ENTITY(reg_a6)->hit_x_minus.h = *(u16 *)reg_a0;
                                reg_a0 += 2;
                            }
                        }
                    }
                }
                func_00170A60();
                reg_a0 = (u8 *)(reg_a6);
                enemy_hitbox_debug_draw();
                return;
            }
            WRECKER_GUN(reg_a5)->wreck_value = (u16) reg_d1.h[0];
            reg_d0.w = 0x256;
            score_add();
            sfx_explosion_ground_large();
            ENTITY(reg_a6)->flags.h = 0x8080;
            temp_a0 = WRECKER_GUN(reg_a5)->palette;
            ENTITY(reg_a6)->attr.b.palette = temp_a0;
            reg_d0.h[0] = 0x85;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0x400;
            EXPLOSION(reg_a0)->start_y = 0;
            EXPLOSION(reg_a0)->start_x = 0;
            EXPLOSION(reg_a0)->follows_scroll = 1;
            EXPLOSION(reg_a0)->move.h = 0x700;
            EXPLOSION(reg_a0)->delay = 0;
            reg_d0.h[0] = 0x85;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0x400;
            EXPLOSION(reg_a0)->start_y = 0xFC00;
            EXPLOSION(reg_a0)->start_x = 0x800;
            EXPLOSION(reg_a0)->follows_scroll = 1;
            EXPLOSION(reg_a0)->move.h = 0x740;
            EXPLOSION(reg_a0)->delay = 2;
            reg_d0.h[0] = 0x85;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0x400;
            EXPLOSION(reg_a0)->start_y = 0xF200;
            EXPLOSION(reg_a0)->start_x = 0;
            EXPLOSION(reg_a0)->follows_scroll = 1;
            EXPLOSION(reg_a0)->move.h = 0x880;
            EXPLOSION(reg_a0)->delay = 4;
            reg_d0.h[0] = 0x85;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0x400;
            EXPLOSION(reg_a0)->start_y = 0xFC00;
            EXPLOSION(reg_a0)->start_x = 0xF800;
            EXPLOSION(reg_a0)->follows_scroll = 1;
            EXPLOSION(reg_a0)->move.h = 0x7C0;
            EXPLOSION(reg_a0)->delay = 6;
            reg_d0.h[0] = 0x85;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0;
            EXPLOSION(reg_a0)->start_y = 0x600;
            EXPLOSION(reg_a0)->start_x = 0xF600;
            EXPLOSION(reg_a0)->follows_scroll = 1;
            EXPLOSION(reg_a0)->move.h = 0x4D0;
            EXPLOSION(reg_a0)->attr.b.flip = 0x40;
            EXPLOSION(reg_a0)->delay = 8;
            reg_d0.h[0] = 0xD;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0x400;
            EXPLOSION(reg_a0)->start_y = 0x200;
            EXPLOSION(reg_a0)->start_x = 0x600;
            EXPLOSION(reg_a0)->follows_scroll = 1;
            EXPLOSION(reg_a0)->move.h = 0x430;
            EXPLOSION(reg_a0)->delay = 0xA;
            reg_d0.h[0] = 0x85;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0;
            EXPLOSION(reg_a0)->start_y = 0xF000;
            EXPLOSION(reg_a0)->start_x = 0xA00;
            EXPLOSION(reg_a0)->follows_scroll = 1;
            EXPLOSION(reg_a0)->move.h = 0x450;
            EXPLOSION(reg_a0)->delay = 0xC;
            reg_d0.h[0] = 0xD;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0x400;
            EXPLOSION(reg_a0)->start_y = 0xF000;
            EXPLOSION(reg_a0)->start_x = 0xFA00;
            EXPLOSION(reg_a0)->follows_scroll = 1;
            EXPLOSION(reg_a0)->move.h = 0x4B0;
            EXPLOSION(reg_a0)->delay = 0xE;
            reg_d0.h[0] = 0xD;
            explosion_spawn();
            var_a3 = 0xC;
            var_a2 = 0x400;
            var_a1 = 0xF400;
            var_a0 = 1;
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0x400;
            EXPLOSION(reg_a0)->start_y = 0xF400;
            EXPLOSION(reg_a0)->start_x = 0;
            EXPLOSION(reg_a0)->follows_scroll = 1;
            EXPLOSION(reg_a0)->delay = 0x10;
            goto block_63;
        }
    } else {
block_63:
        if (WRECKER_GUN(reg_a5)->shake != 0) {
            reg_d1.h[0] = WRECKER_GUN(reg_a5)->wreck_value;
            bullet_cancel_with_flags();
            WRECKER_GUN(reg_a5)->shake -= 1;
        }
        temp_v0_6 = WRECKER_GUN(reg_a5)->wreck_delay;
        if (temp_v0_6 != 0) {
            WRECKER_GUN(reg_a5)->wreck_delay = (u16) (temp_v0_6 - 1);
            if (WRECKER_GUN(reg_a5)->wreck_delay == 0) {
                reg_tmp.w = 0x1BF7;
                ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
            }
        }
        enemy_path_step();
        if (enemy_move_end_requested == 0) {
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            reg_tmp1.w = 0;
            reg_tmp1.h[0] = 0x6000;
            reg_tmp.w = 0;
            reg_d0.h[0] += 0x1800;
            reg_tmp.h[0] = reg_d0.h[0];
            reg_tmp.w += reg_tmp1.w;
            reg_d0.h[0] += 0x6000;
            if (reg_tmp.h[1] != 0) {
                enemy_remove();
                return;
            }
            func_00170A60();
        }
    }
}

void stage2_boss_hangar_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern u32 D_00262ED0[];
extern u32 D_00262EE0[];


void stage2_boss_hangar_start(void)
{
    extern void enemy_set_task_state(void);
    extern void enemy_init_entities(void);
    extern void enemy_path_start(void);
    reg_a0 = (u8 *)((u32)D_00262EE0);
    enemy_init_entities();

    reg_a0 = (u8 *)((u32)D_00262ED0);
    reg_d0.w = 5;
    enemy_set_task_state();
    enemy_path_start();

    if (enemy_move_end_requested) {
        return;
    }
}

s32 entity_draw_layer4();
s32 sprite_draw_layer4();
extern u16 D_00262F00[];
extern u16 g_scroll_line;

void stage2_boss_hangar(void) {
    u32 temp_a1;

    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        if ((s32) g_scroll_line >= 0x22F) {
            enemy_remove();
            return;
        }
        if (((s32) g_scroll_line >= 0x1F8) && ((s16) HANGAR(reg_a5)->frame >= 0)) {
            reg_tmp.b[0] = HANGAR(reg_a5)->frame_timer.b.countdown;
            HANGAR(reg_a5)->frame_timer.b.countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                HANGAR(reg_a5)->frame_timer.b.countdown = (u8) HANGAR(reg_a5)->frame_timer.b.interval;
                reg_d0.h[0] = HANGAR(reg_a5)->frame;
                reg_a0 = (u8 *)(D_00262F00);
                reg_a0 += reg_d0.h[0];
                ENTITY(reg_a6)->draw.h = (u16) *(u16 *)reg_a0;
                reg_a0 += 2;
                ENTITY(reg_a6)->sprite.h = (u16) *(u16 *)reg_a0;
                reg_a0 += 2;
                HANGAR(reg_a5)->door_sprite[0] = (u16) *(u16 *)reg_a0;
                reg_a0 += 2;
                HANGAR(reg_a5)->door_sprite[1] = (u16) *(u16 *)reg_a0;
                reg_a0 += 2;
                HANGAR(reg_a5)->frame -= 8;
            }
        }
        if ((s32) g_scroll_line < 0x21A) {
            entity_draw_layer4();
        }
        reg_d1.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] += 0x4C00;
        temp_a1 = reg_d1.h[0];
        reg_tmp1.h[0] = temp_a1;
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.w += 0xFE00DC00;
        reg_d2.h[1] = HANGAR(reg_a5)->door_sprite[0];
        reg_d2.h[0] = HANGAR(reg_a5)->door_sprite[1];
        reg_d3.h[0] = 0x2320;
        reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
        sprite_draw_layer4();
    }
}

s8 D_00262C40[16] = {
    0x10, 0x0F, 0x11, 0x0E, 0x10, 0x0F, 0x10, 0x0F, 0x10, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

s8 D_00262C50[16] = {
    0x04, 0x00, 0xFF, 0x7E, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

s8 D_00262C60[32] = {
    0x00, 0xA0, 0x00, 0xF0, 0x00, 0xF5, 0x00, 0x00, 0xA1, 0x1B, 0x58, 0x10, 0x00, 0x0C, 0x00, 0x0C,
    0x00, 0x0C, 0x00, 0x0C, 0xFF, 0x7F, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

s8 D_00262C80[16] = {
    0x10, 0x0F, 0x11, 0x0E, 0x10, 0x0F, 0x10, 0x0F, 0x10, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

s8 D_00262C90[32] = {
    0x00, 0xA0, 0x00, 0xEE, 0x00, 0xF8, 0x00, 0x00, 0xA2, 0x1B, 0x40, 0x12, 0x00, 0x12, 0x00, 0x12,
    0x00, 0x06, 0x00, 0x06, 0x00, 0x0E, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u16 D_00262CB0[16] = {
    0x0008, 0x0006, 0x0C00, 0x0100, 0x0800, 0xFF00, 0x0400, 0x0100,
    0x0000, 0xFF00, 0xFC00, 0x0100, 0xF800, 0xFF00, 0xF400, 0x0100,
};

s8 D_00262CD0[16] = {
    0x10, 0x0F, 0x12, 0x0D, 0x10, 0x0F, 0x10, 0x0F, 0x10, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

s8 D_00262CE0[32] = {
    0x00, 0xA0, 0x00, 0xEC, 0x00, 0xFA, 0x00, 0x00, 0xA5, 0x1B, 0x30, 0x14, 0x00, 0x14, 0x00, 0x14,
    0x00, 0x06, 0x00, 0x06, 0x00, 0x0E, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

s8 D_00262D00[16] = {
    0x10, 0x0F, 0x14, 0x0B, 0x10, 0x0F, 0x10, 0x0F, 0x10, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

s8 D_00262D10[32] = {
    0x00, 0xA0, 0x00, 0xEC, 0x00, 0xF8, 0x00, 0x00, 0xB6, 0x1B, 0x40, 0x14, 0x00, 0x14, 0x00, 0x10,
    0x00, 0x08, 0x00, 0x08, 0x00, 0x0E, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u16 D_00262D30[8] = {
    0x0D12, 0x0C13, 0x0D12, 0x0D12, 0x0D12, 0x0000, 0x0000, 0x0000,
};

u16 D_00262D40[16] = {
    0x0000, 0x0000, 0x0000, 0x6040, 0x0404, 0x0000, 0x0001, 0x0000,
    0x0016, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00262D60[16] = {
    0xA000, 0xF800, 0xF800, 0x0000, 0x1BA6, 0x0840, 0x0800, 0x0A00,
    0x0600, 0x0600, 0x0600, 0x1000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00262D80[64] = {
    0x0000, 0x1BA6, 0x0600, 0x0000, 0x0000, 0x1BA7, 0x0640, 0x0000,
    0x0000, 0x1BA8, 0x0680, 0x0000, 0x0000, 0x1BA9, 0x06C0, 0x0000,
    0x0000, 0x1BAA, 0x0700, 0x0000, 0x0000, 0x1BAB, 0x0740, 0x0000,
    0x0000, 0x1BAC, 0x0780, 0x0000, 0x0000, 0x1BAD, 0x07C0, 0x0000,
    0x0000, 0x1BAE, 0x0800, 0x0000, 0x0000, 0x1BAF, 0x0840, 0x0000,
    0x0000, 0x1BB0, 0x0880, 0x0000, 0x0000, 0x1BB1, 0x08C0, 0x0000,
    0x0000, 0x1BB2, 0x0900, 0x0000, 0x0000, 0x1BB3, 0x0940, 0x0000,
    0x0000, 0x1BB4, 0x0980, 0x0000, 0x0000, 0x1BB5, 0x09C0, 0x0000,
};

s8 D_00262E00[16] = {
    0x12, 0x0D, 0x12, 0x0D, 0x12, 0x0D, 0x12, 0x0D, 0x12, 0x0D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

s8 D_00262E10[32] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x98, 0x06, 0x06, 0x00, 0x00, 0x01, 0x00, 0x12, 0x02,
    0x10, 0x10, 0x64, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

s8 D_00262E30[32] = {
    0x00, 0xA0, 0x00, 0xE6, 0x00, 0xF0, 0x00, 0x00, 0xE7, 0x1B, 0x80, 0x1A, 0x00, 0x14, 0x00, 0x14,
    0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u16 D_00262E50[64] = {
    0x0000, 0x1BE7, 0x0600, 0x0600, 0x0000, 0x1BE8, 0x0640, 0x0640,
    0x0000, 0x1BE9, 0x0680, 0x0680, 0x0000, 0x1BEA, 0x06C0, 0x06C0,
    0x0000, 0x1BEB, 0x0700, 0x0700, 0x0000, 0x1BEC, 0x0740, 0x0740,
    0x0000, 0x1BED, 0x0780, 0x0780, 0x0000, 0x1BEE, 0x07C0, 0x07C0,
    0x0000, 0x1BEF, 0x0800, 0x0800, 0x0000, 0x1BF0, 0x0840, 0x0840,
    0x0000, 0x1BF1, 0x0880, 0x0880, 0x0000, 0x1BF2, 0x08C0, 0x08C0,
    0x0000, 0x1BF3, 0x0900, 0x0900, 0x0000, 0x1BF4, 0x0940, 0x0940,
    0x0000, 0x1BF5, 0x0980, 0x0980, 0x0000, 0x1BF6, 0x09C0, 0x09C0,
};

u32 D_00262ED0[4] = {
    0x01E00000, 0x00F80202, 0x1BC70000, 0x00000000,
};

u32 D_00262EE0[8] = {
    0xFE008000, 0x0000DC00, 0x27201BB7, 0x00000000, 0x00000000, 0x10000000, 0x00001500, 0x00000000,
};

u16 D_00262F00[128] = {
    0x0000, 0x1BC6, 0x0000, 0x1BE6, 0x0000, 0x1BC6, 0x0000, 0x1BE5,
    0x0000, 0x1BC6, 0x0000, 0x1BE4, 0x0000, 0x1BC6, 0x0000, 0x1BE3,
    0x0000, 0x1BC6, 0x0000, 0x1BE2, 0x0000, 0x1BC6, 0x0000, 0x1BE1,
    0x0000, 0x1BC6, 0x0000, 0x1BE0, 0x0000, 0x1BC6, 0x0000, 0x1BDF,
    0x0000, 0x1BC6, 0x0000, 0x1BDE, 0x0000, 0x1BC6, 0x0000, 0x1BDD,
    0x0000, 0x1BC6, 0x0000, 0x1BDC, 0x0000, 0x1BC6, 0x0000, 0x1BDB,
    0x0000, 0x1BC6, 0x0000, 0x1BDA, 0x0000, 0x1BC6, 0x0000, 0x1BD9,
    0x0000, 0x1BC6, 0x0000, 0x1BD8, 0x0000, 0x1BC6, 0x0000, 0x1BD7,
    0x0000, 0x1BC6, 0x0000, 0x1BD6, 0x0000, 0x1BC5, 0x0000, 0x1BD5,
    0x0000, 0x1BC4, 0x0000, 0x1BD4, 0x0000, 0x1BC3, 0x0000, 0x1BD3,
    0x0000, 0x1BC2, 0x0000, 0x1BD2, 0x0000, 0x1BC1, 0x0000, 0x1BD1,
    0x0000, 0x1BC0, 0x0000, 0x1BD0, 0x0000, 0x1BBF, 0x0000, 0x1BCF,
    0x0000, 0x1BBE, 0x0000, 0x1BCE, 0x0000, 0x1BBD, 0x0000, 0x1BCD,
    0x0000, 0x1BBC, 0x0000, 0x1BCC, 0x0000, 0x1BBB, 0x0000, 0x1BCB,
    0x0000, 0x1BBA, 0x0000, 0x1BCA, 0x0000, 0x1BB9, 0x0000, 0x1BC9,
    0x0000, 0x1BB8, 0x0000, 0x1BC8, 0x0000, 0x1BB7, 0x0000, 0x1BC7,
};

u8 D_0028D998[8] = { 0x80, 0x04, 0x00, 0x06, 0x40, 0x07, 0xC0, 0x08 };

s8 D_0028D9A0 __attribute__((aligned(4))) = 0xC;

s8 D_0028D9A4 __attribute__((aligned(4))) = 0x12;

s8 D_0028D9A8 __attribute__((aligned(4))) = 0x12;
