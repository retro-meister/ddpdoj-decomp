#include "common.h"
#include "player.h"
#include "entity.h"
#include "explosion.h"
#include "enemy.h"
#include "enemy_small.h"

/*
 * The enemies of this unit keep these in the enemy state block (reg_a5), after what every enemy has
 * (EnemyState). A pair of bytes named interval/countdown or shots/shots_left is a value and the counter that
 * is loaded from it.
 */

/* The large tank: a turret that turns towards a player and fires bursts, and a gun on either side. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 other_16;
    /* 0x17 */ u8 seen;
    /* 0x18 */ u8 other_18[4];
    /* 0x1C */ u8 hit_palette;
    /* 0x1D */ u8 palette;
    /* 0x1E */ u8 turret_pause;       /* frames between two bursts */
    /* 0x1F */ u8 turret_countdown;
    /* 0x20 */ u8 turret_shots;
    /* 0x21 */ u8 turret_shots_left;
    /* 0x22 */ u8 turn_interval;
    /* 0x23 */ u8 turn_countdown;
    /* 0x24 */ u16 turret_sprite[2];
    /* 0x28 */ Field16 turret_dir;
    /* 0x2A */ u8 turret_interval;    /* frames between the shots of a burst */
    /* 0x2B */ u8 gun_interval;
    /* 0x2C */ u8 other_2C[2];
    /* 0x2E */ u8 gun_pause;
    /* 0x2F */ u8 gun_countdown;
    /* 0x30 */ u8 gun_shots;
    /* 0x31 */ u8 gun_shots_left;
    /* 0x32 */ u8 gun_aim[2];         /* the direction (of 256) each gun's burst goes in */
    /* 0x34 */ u8 other_34[0x10];
    /* 0x44 */ u16 after_entities[2]; /* where enemy_init_entities stopped in its table */
} LargeTankState;

#define LARGE_TANK(pointer) ((LargeTankState *)(pointer))

/* The hatch gunner: a hatch that opens, fires a run of shots and closes again, and a gun that fires bursts. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 other_16;
    /* 0x17 */ u8 seen;
    /* 0x18 */ u16 hatch_state;       /* 0: shut, 1: opening, 2: firing, 3: shutting */
    /* 0x1A */ u8 other_1A[2];
    /* 0x1C */ u8 hit_palette;
    /* 0x1D */ u8 palette;
    /* 0x1E */ u8 hatch_pause;
    /* 0x1F */ u8 hatch_countdown;
    /* 0x20 */ u8 hatch_shots;
    /* 0x21 */ u8 hatch_shots_left;
    /* 0x22 */ u8 frame_interval;     /* frames a picture of the moving hatch stays */
    /* 0x23 */ u8 frame_countdown;
    /* 0x24 */ u16 hatch_frame;       /* byte offset into its table of pictures */
    /* 0x26 */ u16 hatch_sprite[2];
    /* 0x2A */ u8 other_2A[4];
    /* 0x2E */ u8 gun_interval;
    /* 0x2F */ u8 hatch_interval;
    /* 0x30 */ u8 gun_pause;
    /* 0x31 */ u8 gun_countdown;
    /* 0x32 */ u8 gun_shots;
    /* 0x33 */ u8 gun_shots_left;
    /* 0x34 */ u16 shot_number;       /* of the hatch's run; it sets how each shot spreads */
    /* 0x36 */ u8 other_36[0xE];
    /* 0x44 */ u16 after_entities[2];
} HatchGunnerState;

#define HATCH_GUNNER(pointer) ((HatchGunnerState *)(pointer))

/* The warning sign before a boss: it comes on, flashes a number of times and goes off. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u16 phase;             /* 0: coming on, 1: flashing, 2: going off */
    /* 0x18 */ u16 frame_time;        /* frames the present picture still stays */
    /* 0x1A */ u16 frame;             /* byte offset into its table of pictures */
    /* 0x1C */ u16 flashes_left;
    /* 0x1E */ u8 sound_interval;
    /* 0x1F */ u8 sound_countdown;
    /* 0x20 */ u16 sounds_left;
} WarningSignState;

#define WARNING_SIGN(pointer) ((WarningSignState *)(pointer))

void enemy_fire_distance_check(void);

extern u8 small_tank_draw_routines[];

/* Takes the two sprite queue routines of the tank's draw layer. */
void small_tank_set_draw_routines(void) {
    u8 temp_v1;

    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->misc.b.draw_layer;
    reg_a0 = small_tank_draw_routines;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d0.h[0] *= 8;
    reg_a0 += reg_d0.h[0];
    SMALL_TANK(reg_a5)->draw_body[0] = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    SMALL_TANK(reg_a5)->draw_body[1] = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    SMALL_TANK(reg_a5)->draw_turret[0] = (u16) *(u16 *)reg_a0;
    SMALL_TANK(reg_a5)->draw_turret[1] = (u16) *(u16 *)(reg_a0 + 2);
    temp_v1 = ENTITY(reg_a6)->misc.b.user;
    if (temp_v1 != 0) {
        reg_d1.b[0] = temp_v1;
    }
    reg_d1.h[0] += reg_d1.h[0];
    ENTITY(reg_a6)->misc.b.user = (u8) reg_d1.b[0];
}

s32 explosion_spawn();

void small_tank_explosion(void) {
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->misc.b.user;
    EXPLOSION(reg_a0)->draw_layer = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)((u16 *)reg_a1) + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    EXPLOSION(reg_a0)->follows_scroll = 1;
}

s32 wreck_spawn();
extern u16 small_tank_wrecks[];

void small_tank_wreck(void) {
    reg_d1.w = 0;
    reg_d1.b[0] = ENTITY(reg_a6)->misc.b.draw_layer;
    reg_a0 = (u8 *)small_tank_wrecks;
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)((u16 *)reg_a0) + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    wreck_spawn();
}

typedef void (*Fn)(void);
extern u8 *reg_call_target_as_u8_p;

void small_tank_smoke(void) {
    reg_d2.w = 0;
    reg_d2.h[0] = SMALL_TANK(reg_a5)->smoke_frame;
    reg_d2.h[0] += 1;
    if (reg_d2.h[0] == 4) {
        reg_d2.w = 0;
    }
    SMALL_TANK(reg_a5)->smoke_frame = reg_d2.h[0];
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = 0x1E;
    reg_d2.w += 0x13D8;
    reg_tmp.h[1] = SMALL_TANK(reg_a5)->draw_turret[0];
    reg_tmp.h[0] = SMALL_TANK(reg_a5)->draw_turret[1];
    reg_a0 = (u8 *)reg_tmp.w;
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
}


extern u8 shot_limits_y[];
extern u8 shot_limits_x[];
extern u8 shot_limits_y_second_loop[];
extern u8 shot_limits_x_second_loop[];
extern u16 g_loop;
extern u16 g_stage_x4;

/* Sets cond_flag (hold fire) unless the enemy is inside the stage's box and no player is too near. */
void enemy_fire_zone_check(void) {
    cond_flag = 0;
    reg_d0.h[0] = g_stage_x4;
    reg_a0 = (u8 *)shot_limits_x;
    if (g_loop != 0) {
        reg_a0 = (u8 *)shot_limits_x_second_loop;
    }
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)shot_limits_y;
    if (g_loop != 0) {
        reg_a0 = (u8 *)shot_limits_y_second_loop;
    }
    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = reg_a6 + 2;
    reg_d1.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d1.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[0] -= reg_d2.h[0];
    reg_tmp2.h[0] = reg_d2.h[0];
    reg_d2.h[0] = reg_d2.h[1];
    reg_d2.h[1] = reg_tmp2.h[0];
    reg_tmp.w = 0;
    reg_tmp1.w = 0;
    reg_tmp.h[0] = reg_d2.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_tmp1.w += reg_tmp.w;
    reg_d1.h[0] += reg_d2.h[0];
    if (reg_tmp1.h[1] == 0) {
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.h[0] -= reg_d3.h[0];
        reg_tmp3.h[0] = reg_d3.h[0];
        reg_d3.h[0] = reg_d3.h[1];
        reg_d3.h[1] = reg_tmp3.h[0];
        reg_tmp.w = 0;
        reg_tmp1.w = 0;
        reg_tmp.h[0] = reg_d3.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_tmp1.w += reg_tmp.w;
        reg_d1.h[0] += reg_d3.h[0];
        if (reg_tmp1.h[1] == 0) {
            enemy_fire_distance_check();
            return;
        }
    }
    cond_flag = 1;
}

extern u16 enemy_fire_distances[];
extern u16 g_stage;
extern s16 g_player2[];
extern s16 g_player1[];


/* Sets cond_flag (hold fire) when a player is nearer than the stage's distance. */
void enemy_fire_distance_check(void) {
    reg_d0.h[0] = 0x7FFF;
    if (g_player1[0] < 0) {
        reg_d2.h[0] = PLAYER(g_player1)->y.h;
        reg_d3.h[0] = PLAYER(g_player1)->x.h;
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] -= reg_d2.h[0];
        if ((s16)(reg_d0.h[0]) < 0) {
            reg_d0.h[0] *= 0xFFFF;
        }
        reg_d2.h[0] = reg_d0.h[0];
        reg_d2.h[0] >>= 2;
        reg_d1.h[0] -= reg_d3.h[0];
        reg_d0.h[0] -= reg_d2.h[0];
        if ((s16)(reg_d1.h[0]) < 0) {
            reg_d1.h[0] *= 0xFFFF;
        }
        if ((s32) reg_d1.h[0] > (s32) reg_d0.h[0]) {
            reg_tmp1.w = reg_d1.w;
            reg_d1.w = reg_d0.w;
            reg_d0.w = reg_tmp1.w;
        }
        reg_d1.h[0] >>= 1;
        reg_d0.h[0] += reg_d1.h[0];
    }
    reg_d4.h[0] = reg_d0.h[0];
    reg_d0.h[0] = 0x7FFF;
    if (g_player2[0] < 0) {
        reg_d2.h[0] = PLAYER(g_player2)->y.h;
        reg_d3.h[0] = PLAYER(g_player2)->x.h;
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] -= reg_d2.h[0];
        if ((s16)(reg_d0.h[0]) < 0) {
            reg_d0.h[0] *= 0xFFFF;
        }
        reg_d2.h[0] = reg_d0.h[0];
        reg_d2.h[0] >>= 2;
        reg_d1.h[0] -= reg_d3.h[0];
        reg_d0.h[0] -= reg_d2.h[0];
        if ((s16)(reg_d1.h[0]) < 0) {
            reg_d1.h[0] *= 0xFFFF;
        }
        if ((s32) reg_d1.h[0] > (s32) reg_d0.h[0]) {
            reg_tmp1.w = reg_d1.w;
            reg_d1.w = reg_d0.w;
            reg_d0.w = reg_tmp1.w;
        }
        reg_d1.h[0] >>= 1;
        reg_d0.h[0] += reg_d1.h[0];
    }
    if ((s32) reg_d0.h[0] > (s32) reg_d4.h[0]) {
        reg_d0.h[0] = reg_d4.h[0];
    }
    reg_a0 = (u8 *)(enemy_fire_distances);
    reg_d4.h[0] = g_stage;
    reg_d4.h[0] += reg_d4.h[0];
    reg_a0 += reg_d4.h[0];
    reg_d4.h[0] = *(u16 *)reg_a0;
    if ((s32) reg_d4.h[0] > (s32) reg_d0.h[0]) {
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

void small_tank_a_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 enemy_set_task_state();
s32 enemy_init_entities();
s32 enemy_path_start();
extern u16 small_tank_a_palettes[];
extern u16 small_tank_a_state[];
extern u16 small_tank_a_entities[];
extern u16 small_tank_a_turret_sprites[];
extern u16 g_rank_1_16;
extern u16 g_rank_5_16;
extern u16 g_stage_x2;
extern s8 enemy_move_end_requested;

void small_tank_a_start(void) {
    reg_a0 = (u8 *)(small_tank_a_entities);
    enemy_init_entities();
    reg_a0 = (u8 *)(small_tank_a_state);
    reg_d0.w = 0xF;
    enemy_set_task_state();
    reg_d0.h[0] = g_stage;
    reg_d0.h[0] >>= 1;
    reg_d0.h[0] += 2;
    SMALL_TANK(reg_a5)->burst_left = (u8) reg_d0.b[0];
    SMALL_TANK(reg_a5)->burst_shots = (u8) reg_d0.b[0];
    reg_d0.h[0] = g_rank_5_16;
    SMALL_TANK(reg_a5)->fire_countdown -= reg_d0.b[0];
    reg_d0.h[0] = g_rank_1_16;
    reg_d0.h[0] >>= 4;
    SMALL_TANK(reg_a5)->turn_interval -= reg_d0.b[0];
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if ((s32) ENTITY(reg_a6)->y.h >= 0x7600) {
            SMALL_TANK(reg_a5)->entering = 1;
        }
        if (g_stage == 2) {
            ENTITY(reg_a6)->misc.sb.draw_layer = 2;
        }
        small_tank_set_draw_routines();
        reg_tmp.h[1] = ENEMY_STATE(reg_a5)->entities[0];
        reg_tmp.h[0] = ENEMY_STATE(reg_a5)->entities[1];
        reg_a6 = (void *) reg_tmp.w;
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        SMALL_TANK(reg_a5)->turret_dir = (u8) reg_d1.b[0];
        reg_a0 = (u8 *)(small_tank_a_turret_sprites);
        reg_d1.b[0] += 1;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        SMALL_TANK(reg_a5)->turret_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        SMALL_TANK(reg_a5)->turret_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(small_tank_a_palettes);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        SMALL_TANK(reg_a5)->palette = *(s8 *)reg_a0;
        reg_a0 += 1;
        SMALL_TANK(reg_a5)->hit_palette = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}

typedef void (*Fn)();

extern u8 small_tank_a_muzzles[];
extern u8 small_tank_a_body_sprites[];

s32 bullet_fire_fast();
s32 enemy_hitbox_debug_draw();
s32 enemy_remove();
s32 enemy_path_step();
s32 sfx_explosion_air_small();
s32 score_add_no_chain();
s32 score_add();
s32 aim_at_player();
s32 direction_turn_toward();
extern u8 small_tank_destroyed_explosions[];
extern u8 small_tank_damaged_explosions[];
extern u16 g_frame_mod2;
extern u16 g_game_frame;
extern u16 g_enemy_signal_0;
extern u16 g_enemies_stopped;
extern u16 g_rank_3_16;
extern u16 g_side_scroll_x[];

void small_tank_a(void) {
    enemy_path_step();
    if (enemy_move_end_requested != 0) goto block_rts;
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp1.w = 0;
    reg_d0.h[0] += 0x1200;
    reg_tmp.w = 0;
    reg_d0.h[0] += g_side_scroll_x[0];
    reg_tmp1.h[0] = 0xA400;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0xA400;
    if (reg_tmp.h[1] != 0) goto block_a;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    if (SMALL_TANK(reg_a5)->entering == 0) goto next_1;
    if (!((s32) reg_d0.h[0] < 0x7600)) goto next_1;
    SMALL_TANK(reg_a5)->entering = 0;
next_1:
    reg_tmp1.w = 0;
    reg_tmp.w = 0;
    reg_tmp1.h[0] = 0x7C00;
    reg_d0.h[0] += 0xA00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x7C00;
    if (reg_tmp.h[1] == 0) goto next_2;
block_a:
    if (SMALL_TANK(reg_a5)->seen == 0) goto next_3;
    enemy_remove();
    return;
next_2:
    SMALL_TANK(reg_a5)->seen = 1;
next_3:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    switch (reg_d1.b[0]) { case 0: goto next_4; }
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    reg_d0.b[0] = SMALL_TANK(reg_a5)->hit_palette;
    ENTITY(reg_a6)->attr.b.palette ^= reg_d0.b[0];
    score_add_no_chain();
    if (ENTITY(reg_a6)->hp.sh >= 0) goto next_5;
    if ((s8) SMALL_TANK(reg_a5)->damage < 0) goto block_e;
    ENTITY(reg_a6)->flags.b[1] &= 0xFD;
    ENTITY(reg_a6)->hp.h = SMALL_TANK(reg_a5)->second_hp;
    reg_d0.w = 8;
    score_add();
    SMALL_TANK(reg_a5)->damage |= 0x80;
    reg_d0.w = 3;
    reg_a1 = (u8 *)small_tank_damaged_explosions;
    small_tank_explosion();
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0;
    goto next_5;
next_4:
    ENTITY(reg_a6)->attr.b.palette = SMALL_TANK(reg_a5)->palette;
next_5:
    if (g_enemies_stopped != 0) goto next_7;
    reg_d7.h[0] = ENTITY(reg_a6)->move.h;
    reg_d1.w = 0x3E;
    reg_d1.h[0] &= reg_d7.h[0];
    reg_d1.h[0] *= 4;
    if (reg_d7.h[0] & 0x40) goto next_6;
    if (!(g_game_frame & 4)) goto next_6;
    reg_d1.h[0] += 4;
next_6:
    reg_a0 = (u8 *)small_tank_a_body_sprites;
    ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
next_7:
    reg_tmp.h[1] = SMALL_TANK(reg_a5)->draw_body[0];
    reg_tmp.h[0] = SMALL_TANK(reg_a5)->draw_body[1];
    reg_a0 = (u8 *) reg_tmp.w;
    reg_call_target = (Fn)(reg_a0);
    reg_call_target();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    if ((s8) SMALL_TANK(reg_a5)->damage >= 0) goto block_b;
    if (g_frame_mod2 == 0) goto block_rts;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFE00;
    small_tank_smoke();
    goto block_rts;
block_b:
    if (g_enemies_stopped != 0) goto block_c;
    reg_d1.b[0] = SMALL_TANK(reg_a5)->turret_dir;
    reg_tmp.b[0] = SMALL_TANK(reg_a5)->turn_countdown;
    SMALL_TANK(reg_a5)->turn_countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_8;
    SMALL_TANK(reg_a5)->turn_countdown = SMALL_TANK(reg_a5)->turn_interval;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x200;
    aim_at_player();
    if (cond_flag != 0) goto block_c;
    reg_d0.b[0] = SMALL_TANK(reg_a5)->turret_dir;
    direction_turn_toward();
    SMALL_TANK(reg_a5)->turret_dir = reg_d1.b[0];
    reg_a0 = (u8 *)small_tank_a_turret_sprites;
    reg_d1.b[0] += 1;
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    SMALL_TANK(reg_a5)->turret_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    SMALL_TANK(reg_a5)->turret_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
next_8:
    if (!(ENTITY(reg_a6)->flags.b[1] & 0x20)) goto block_c;
    SMALL_TANK(reg_a5)->fire_countdown -= 1;
    if (SMALL_TANK(reg_a5)->fire_countdown == 0) goto block_d;
block_c:
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFA00FA00;
    reg_d2.h[1] = SMALL_TANK(reg_a5)->turret_sprite[0];
    reg_d2.h[0] = SMALL_TANK(reg_a5)->turret_sprite[1];
    reg_d3.h[0] = 0x830;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_tmp.h[1] = SMALL_TANK(reg_a5)->draw_turret[0];
    reg_tmp.h[0] = SMALL_TANK(reg_a5)->draw_turret[1];
    reg_a0 = (u8 *) reg_tmp.w;
    reg_call_target = (Fn)(reg_a0);
    reg_call_target();
    goto block_rts;
block_d:
    reg_d0.w = 0x18;
    reg_d0.h[0] -= g_rank_1_16;
    SMALL_TANK(reg_a5)->fire_countdown = reg_d0.b[0];
    enemy_fire_zone_check();
    if (cond_flag != 0) goto block_c;
    if (g_stage != 1) goto next_9;
    if (g_enemy_signal_0 != 0) goto block_c;
next_9:
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x200;
    aim_at_player();
    if (cond_flag != 0) goto block_c;
    reg_d2.h[0] = reg_d1.h[0];
    reg_d0.w = 0x3C;
    reg_d2.b[0] += 2;
    reg_d2.h[0] &= reg_d0.h[0];
    reg_d3.b[0] = SMALL_TANK(reg_a5)->turret_dir;
    reg_d3.b[0] += 2;
    reg_d3.h[0] &= reg_d0.h[0];
    if (reg_d3.b[0] == reg_d2.b[0]) goto next_10;
    reg_d0.b[0] = SMALL_TANK(reg_a5)->burst_shots;
    if (SMALL_TANK(reg_a5)->burst_left == reg_d0.b[0]) goto block_c;
next_10:
    SMALL_TANK(reg_a5)->fire_countdown = SMALL_TANK(reg_a5)->fire_interval;
    reg_tmp.b[0] = SMALL_TANK(reg_a5)->burst_left;
    SMALL_TANK(reg_a5)->burst_left -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_11;
    SMALL_TANK(reg_a5)->burst_left = SMALL_TANK(reg_a5)->burst_shots;
    reg_d0.w = 0x40;
    reg_d0.h[0] -= g_rank_3_16;
    SMALL_TANK(reg_a5)->fire_countdown = reg_d0.b[0];
next_11:
    reg_d1.b[0] = SMALL_TANK(reg_a5)->turret_dir;
    reg_a0 = (u8 *)small_tank_a_muzzles;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 1;
    reg_d3.h[0] &= 0x3E;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d2.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((u16) reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.w += reg_tmp.w;
    reg_d1.b[0] += 2;
    reg_d1.h[0] &= 0x3C;
    reg_d0.w = 0xC;
    reg_d3.w = 0x02000000;
    bullet_fire_fast();
    goto block_c;
block_e:
    reg_d0.w = 0x10;
    score_add();
    reg_d0.w = 4;
    reg_a1 = (u8 *)small_tank_destroyed_explosions;
    small_tank_explosion();
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0;
    reg_d0.w = 4;
    small_tank_wreck();
    sfx_explosion_air_small();
    enemy_remove();
block_rts:
    return;
}

void small_tank_b_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 rng_next_masked();
extern u16 small_tank_b_palettes[];
extern u16 small_tank_b_state[];
extern u16 small_tank_b_entities[];
extern u16 small_tank_b_turret_sprites[];
extern u16 g_scroll_line;
extern u16 g_rank_2_16;
extern u16 g_rank_6_16;

void small_tank_b_start(void) {
    reg_a0 = (u8 *)(small_tank_b_entities);
    enemy_init_entities();
    reg_a0 = (u8 *)(small_tank_b_state);
    reg_d0.w = 0xF;
    enemy_set_task_state();
    reg_d0.h[0] = g_rank_6_16;
    SMALL_TANK(reg_a5)->fire_countdown -= reg_d0.b[0];
    SMALL_TANK(reg_a5)->other_1B -= reg_d0.b[0];
    rng_next_masked();
    reg_d0.b[0] >>= 1;
    SMALL_TANK(reg_a5)->fire_countdown += reg_d0.b[0];
    reg_d0.h[0] = g_rank_1_16;
    reg_d0.h[0] >>= 4;
    SMALL_TANK(reg_a5)->turn_countdown -= reg_d0.b[0];
    if ((g_stage == 1) && ((s32) g_scroll_line >= 0x159)) {
        reg_d0.w = 0x30;
        reg_d0.h[0] -= g_rank_2_16;
        reg_d0.h[0] -= 6;
        SMALL_TANK(reg_a5)->fire_countdown = (u8) reg_d0.b[0];
    }
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if (g_stage == 2) {
            ENTITY(reg_a6)->misc.sb.draw_layer = 2;
        }
        small_tank_set_draw_routines();
        reg_tmp.h[1] = ENEMY_STATE(reg_a5)->entities[0];
        reg_tmp.h[0] = ENEMY_STATE(reg_a5)->entities[1];
        reg_a6 = (void *) reg_tmp.w;
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        SMALL_TANK(reg_a5)->turret_dir = (u8) reg_d1.b[0];
        reg_a0 = (u8 *)(small_tank_b_turret_sprites);
        reg_d1.b[0] += 1;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        SMALL_TANK(reg_a5)->turret_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        SMALL_TANK(reg_a5)->turret_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(small_tank_b_palettes);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        SMALL_TANK(reg_a5)->palette = *(s8 *)reg_a0;
        reg_a0 += 1;
        SMALL_TANK(reg_a5)->hit_palette = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}

extern u16 small_tank_b_muzzles[];
extern u16 small_tank_b_body_sprites[];
extern s16 D_0028E7DC;
extern s16 D_0028E7E0;
extern u16 g_rank_10_16;

void small_tank_b(void) {
    u32 swap;

    enemy_path_step();
    if (enemy_move_end_requested != 0) {
        return;
    }
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0xE00;
    reg_d0.h[0] += g_side_scroll_x[0];
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xAC00;
    reg_tmp1.w += reg_tmp.w;
    reg_d0.h[0] += 0xAC00;
    if (reg_tmp1.h[1] != 0) goto next_lim;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x8400;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    swap = reg_tmp.h[0];
    reg_d0.h[0] += 0x600;
    reg_tmp.w = 0;
    reg_d0.h[1] = swap;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp1.w += reg_tmp.w;
    reg_d0.h[0] += 0x8400;
next_lim:
    if (reg_tmp1.h[1] == 0) goto next_40;
    if (SMALL_TANK(reg_a5)->seen == 0) goto next_50;
    enemy_remove();
    return;
next_40:
    SMALL_TANK(reg_a5)->seen = 1;
next_50:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto next_100;
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    reg_d0.b[0] = SMALL_TANK(reg_a5)->hit_palette;
    ENTITY(reg_a6)->attr.b.palette ^= reg_d0.b[0];
    score_add_no_chain();
    if (ENTITY(reg_a6)->hp.sh >= 0) goto next_110;
    if ((s8) SMALL_TANK(reg_a5)->damage < 0) goto block_70;
    ENTITY(reg_a6)->hp.h = SMALL_TANK(reg_a5)->second_hp;
    reg_d0.w = 8;
    score_add();
    SMALL_TANK(reg_a5)->damage |= 0x80;
    if ((u16)D_0028E7E0 != 0) goto next_110;
    D_0028E7E0 = 1;
    reg_d0.w = 3;
    reg_a1 = (u8 *)((u16 *)small_tank_damaged_explosions);
    small_tank_explosion();
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    goto next_110;
next_100:
    ENTITY(reg_a6)->attr.b.palette = SMALL_TANK(reg_a5)->palette;
next_110:
    if (g_enemies_stopped != 0) goto next_225;
    reg_d7.h[0] = ENTITY(reg_a6)->move.h;
    reg_d1.w = 0x3E;
    reg_d1.h[0] &= reg_d7.h[0];
    reg_d1.h[0] <<= 2;
    if (reg_d7.h[0] & 0x40) goto next_220;
    if (!(g_game_frame & 4)) goto next_220;
    reg_d1.h[0] += 4;
next_220:
    reg_a0 = (u8 *) small_tank_b_body_sprites;
    ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
next_225:
    reg_tmp.h[1] = SMALL_TANK(reg_a5)->draw_body[0];
    reg_tmp.h[0] = SMALL_TANK(reg_a5)->draw_body[1];
    reg_a0 = (u8 *) reg_tmp.w;
    reg_call_target = (Fn) reg_a0;
    reg_call_target();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    if ((s8) SMALL_TANK(reg_a5)->damage >= 0) goto next_300;
    if (g_frame_mod2 == 0) goto block_rts;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0x100FE00;
    small_tank_smoke();
    return;
next_300:
    if (g_enemies_stopped != 0) goto block_objset;
    reg_d1.b[0] = SMALL_TANK(reg_a5)->turret_dir;
    reg_tmp.b[0] = SMALL_TANK(reg_a5)->turn_countdown;
    SMALL_TANK(reg_a5)->turn_countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_500;
    SMALL_TANK(reg_a5)->turn_countdown = SMALL_TANK(reg_a5)->turn_interval;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x200;
    aim_at_player();
    if (cond_flag != 0) goto block_objset;
    reg_d0.b[0] = SMALL_TANK(reg_a5)->turret_dir;
    direction_turn_toward();
    SMALL_TANK(reg_a5)->turret_dir = reg_d1.b[0];
    reg_a0 = (u8 *) small_tank_b_turret_sprites;
    reg_d1.b[0] += 1;
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    SMALL_TANK(reg_a5)->turret_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    SMALL_TANK(reg_a5)->turret_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
next_500:
    if (!(ENTITY(reg_a6)->flags.b[1] & 0x20)) goto block_objset;
    SMALL_TANK(reg_a5)->fire_countdown -= 1;
    if (SMALL_TANK(reg_a5)->fire_countdown == 0) goto block_shot;
block_objset:
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFC00FC00;
    reg_d2.h[1] = SMALL_TANK(reg_a5)->turret_sprite[0];
    reg_d2.h[0] = SMALL_TANK(reg_a5)->turret_sprite[1];
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_tmp.h[1] = SMALL_TANK(reg_a5)->draw_turret[0];
    reg_tmp.h[0] = SMALL_TANK(reg_a5)->draw_turret[1];
    reg_a0 = (u8 *) reg_tmp.w;
    reg_call_target = (Fn) reg_a0;
    reg_call_target();
block_rts:
    return;
block_shot:
    reg_d0.h[0] = 0xA0;
    reg_d0.h[0] -= g_rank_10_16;
    reg_d0.h[0] += 4;
    if (g_loop != 0) goto next_610;
    if (g_stage != 1) goto next_610;
    if ((s32) g_scroll_line < 0x159) goto next_610;
    reg_d0.w = 0x30;
    reg_d0.h[0] -= g_rank_2_16;
    reg_d0.h[0] -= 6;
next_610:
    SMALL_TANK(reg_a5)->fire_countdown = reg_d0.b[0];
    enemy_fire_zone_check();
    if (cond_flag != 0) goto block_objset;
    if (g_stage != 1) goto next_620;
    if (g_enemy_signal_0 != 0) goto block_objset;
next_620:
    if (!(ENTITY(reg_a6)->flags.b[1] & 0x20)) goto block_objset;
    reg_d1.b[0] = SMALL_TANK(reg_a5)->turret_dir;
    reg_a0 = (u8 *) small_tank_b_muzzles;
    reg_d1.b[0] += 2;
    reg_d1.h[0] &= 0x3C;
    reg_d2.h[0] = reg_d1.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.w += reg_tmp.w;
    reg_d0.w = 0xD;
    if ((s32) g_stage < 3) goto next_630;
    reg_d0.w = 0xFFFC000D;
next_630:
    reg_d3.w = 0x2000000;
    bullet_fire_fast();
    goto block_objset;
block_70:
    reg_d0.w = 0x10;
    score_add();
    reg_d0.w = 7;
    reg_a1 = (u8 *)((u16 *)small_tank_destroyed_explosions);
    small_tank_explosion();
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    if ((u16)D_0028E7E0 == 0) goto next_71;
    *(u16 *)(reg_a0 + 0x12) = 0xFFFF;
next_71:
    D_0028E7E0 = 1;
    (*(u16 *)&D_0028E7DC) += 1;
    if (!((u16)D_0028E7DC & 1)) goto next_72;
    reg_d0.w = 4;
    small_tank_wreck();
next_72:
    sfx_explosion_air_small();
    enemy_remove();
}

void large_tank_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(1);
}

s32 direction_between();
extern u16 g_direction_sprites_a[];
extern u16 large_tank_palettes[];
extern u16 large_tank_state[];
extern u16 large_tank_entities[];
extern u16 large_tank_part_sprites[];

void large_tank_start(void) {
    reg_a0 = (u8 *)(large_tank_entities);
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0;
    LARGE_TANK(reg_a5)->after_entities[0] = (u16) reg_tmp.h[1];
    LARGE_TANK(reg_a5)->after_entities[1] = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)(large_tank_state);
    reg_d0.w = 0xE;
    enemy_set_task_state();
    reg_d0.b[0] = 4;
    reg_d2.b[0] = 2;
    reg_d1.b[0] = 4;
    if ((s32) g_stage > 1) {
        reg_d0.b[0] = 3;
        reg_d1.b[0] = 6;
        reg_d2.b[0] = 1;
    }
    LARGE_TANK(reg_a5)->gun_interval = (u8) reg_d0.b[0];
    LARGE_TANK(reg_a5)->turret_interval = (u8) reg_d1.b[0];
    ENTITY(reg_a6)[1].hit_y_plus.b[1] = (u8) reg_d2.b[0];
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_a0 = (u8 *)(g_direction_sprites_a);
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0xB00;
        direction_between();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        LARGE_TANK(reg_a5)->turret_dir.b[0] = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        LARGE_TANK(reg_a5)->turret_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        LARGE_TANK(reg_a5)->turret_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = ENTITY(reg_a6)[1].offset_x.h;
        reg_a0 = (u8 *)(large_tank_part_sprites);
        ENTITY(reg_a6)[1].draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)[1].sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(large_tank_palettes);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        LARGE_TANK(reg_a5)->palette = *(s8 *)reg_a0;
        reg_a0 += 1;
        LARGE_TANK(reg_a5)->hit_palette = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}

s32 bullet_fire256_fast();
s32 bullet_fire256_double();
s32 enemy_anims_spawn_listed();
s32 sfx_explosion_ground_large();
s32 entity_draw_layer1();
s32 sprite_draw_layer1();
s32 rng_next();
s32 rng_next_d5();
s32 aim256_at_player();
s32 wreck_spawn_a();
extern u16 g_direction_offsets_540[];
extern u16 g_direction64_offsets_2CC[];
extern u16 g_bullets_blocked;
extern u16 g_damage_blink_counter;

void large_tank(void) {
    s16 *t1;
    s16 *t2;
    u16 t3;
    u16 t4;
    u16 t5;

    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x6E00;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1000;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x6E00;
        if (reg_tmp.h[1] != 0) {
            if (LARGE_TANK(reg_a5)->seen != 0) {
                enemy_remove();
                return;
            }
            goto next_1;
        }
        LARGE_TANK(reg_a5)->seen = 1U;
next_1:
        t1 = (s16 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(t1) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = LARGE_TANK(reg_a5)->palette;
            if (((s32) (*(u16 *)((u8 *)(t1) + (0x18))) < 0x7C0) && (g_damage_blink_counter == 0)) {
                reg_d0.w = 0x19;
            }
            goto next_2;
        }
        (*(u8 *)((u8 *)(t1) + (1))) &= 0xA3;
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = LARGE_TANK(reg_a5)->palette;
        }
        reg_d2.b[0] = LARGE_TANK(reg_a5)->hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
next_2:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            enemy_anims_spawn_listed();
            if (g_enemies_stopped == 0) {
                ENTITY(reg_a6)->offset_y.h = 0xF000U;
                if ((s32) ENTITY(reg_a6)->move.b.dir < 0x40) {
                    ENTITY(reg_a6)[1].hit_x_minus.h += 0x20;
                    reg_d0.h[0] = ENTITY(reg_a6)[1].hit_x_minus.h;
                    reg_d0.h[0] &= 0x40;
                    ENTITY(reg_a6)->offset_y.h += reg_d0.h[0];
                    reg_tmp.b[0] = ENTITY(reg_a6)[1].offset_y.b[1];
                    ENTITY(reg_a6)[1].offset_y.b[1] -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        ENTITY(reg_a6)[1].offset_y.b[1] = (u8) ENTITY(reg_a6)[1].offset_y.b[0];
                        if (ENTITY(reg_a6)->move.b.dir == 0) {
                            ENTITY(reg_a6)[1].offset_x.h += 4;
                            if (ENTITY(reg_a6)[1].offset_x.h == 0x10) {
                                ENTITY(reg_a6)[1].offset_x.h = 0U;
                            }
                        } else {
                            reg_tmp.h[0] = ENTITY(reg_a6)[1].offset_x.h;
                            ENTITY(reg_a6)[1].offset_x.h -= 4;
                            if ((s32) reg_tmp.h[0] < 4) {
                                ENTITY(reg_a6)[1].offset_x.h = 0xCU;
                            }
                        }
                        reg_d0.h[0] = ENTITY(reg_a6)[1].offset_x.h;
                        reg_a0 = (u8 *)(large_tank_part_sprites);
                        ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                        ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    }
                }
            }
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0)) {
                reg_tmp.b[0] = LARGE_TANK(reg_a5)->turn_countdown;
                LARGE_TANK(reg_a5)->turn_countdown -= 1;
                if (((s32) reg_tmp.b[0] <= 0) && (LARGE_TANK(reg_a5)->turn_countdown = (u8) LARGE_TANK(reg_a5)->turn_interval, reg_d0.b[0] = LARGE_TANK(reg_a5)->turret_shots_left, (LARGE_TANK(reg_a5)->turret_shots == reg_d0.b[0]))) {
                    reg_a0 = (u8 *)(((u16 *)g_player1));
                    reg_a1 = (u8 *)(((u16 *)g_player2));
                    if (ENEMY_STATE(reg_a5)->target_player != 0) {
                        reg_atmp = (u8 *)(reg_a0);
                        reg_a0 = (u8 *)(reg_a1);
                        reg_a1 = (u8 *)(reg_atmp);
                    }
                    t2 = (s16 *)(reg_a0);
                    if ((*(s16 *)((u8 *)(t2) + (0))) >= 0) {
                        if (*(s16 *)reg_a1 < 0) {
                            reg_a0 = (u8 *)(reg_a1);
                            reg_atmp = (u8 *)(t2);
                            reg_a1 = (u8 *)(t2);
                            goto next_3;
                        }
                    } else {
next_3:
                        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                        reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                        t3 = ENTITY(reg_a6)->x.h;
                        reg_d1.h[0] = t3;
                        reg_a3 = (u8 *)(g_direction_sprites_a);
                        reg_d0.h[0] += 0xB00;
                        direction_between();
                        reg_d0.h[0] = LARGE_TANK(reg_a5)->turret_dir.h;
                        direction_turn_toward();
                        LARGE_TANK(reg_a5)->turret_dir.h = (u16) reg_d1.h[0];
                        reg_d1.h[0] &= 0x3E;
                        reg_d1.h[0] += reg_d1.h[0];
                        LARGE_TANK(reg_a5)->turret_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                        LARGE_TANK(reg_a5)->turret_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                        goto next_4;
                    }
                } else {
next_4:
                    if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0) && ((s16) ENTITY(reg_a6)->y.h >= 0x1000)) {
                        reg_tmp.b[0] = LARGE_TANK(reg_a5)->turret_countdown;
                        LARGE_TANK(reg_a5)->turret_countdown -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            LARGE_TANK(reg_a5)->turret_countdown = (u8) LARGE_TANK(reg_a5)->turret_interval;
                            reg_a4 = (u8 *)(g_direction_offsets_540);
                            reg_d1.h[0] = LARGE_TANK(reg_a5)->turret_dir.h;
                            reg_d0.h[0] = reg_d1.h[0];
                            reg_d1.h[0] *= 4;
                            rng_next_d5();
                            reg_d1.b[0] += reg_d5.b[0];
                            reg_d0.h[0] &= 0x3E;
                            reg_d0.h[0] += reg_d0.h[0];
                            reg_d5.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
                            reg_d5.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a4;
                            reg_d0.w = 5;
                            reg_d4.w = 0;
                            reg_tmp5.h[0] = reg_d5.h[0];
                            reg_d5.h[0] = reg_d5.h[1];
                            reg_d5.h[1] = reg_tmp5.h[0];
                            reg_d5.h[0] += 0xB00;
                            reg_tmp5.h[0] = reg_d5.h[0];
                            reg_d5.h[0] = reg_d5.h[1];
                            reg_d5.h[1] = reg_tmp5.h[0];
                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d1.h[0] -= 0x24;
                            reg_d7.h[0] = 6;
                            reg_a0 = (u8 *)(g_direction64_offsets_2CC);
                            do {
                                reg_d3.h[0] = reg_d1.h[0];
                                reg_d3.h[0] += 2;
                                reg_d3.h[0] &= 0xFC;
                                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                reg_d3.w += reg_d5.w;
                                bullet_fire256_double();
                                reg_d1.h[0] += 0xC;
                            } while ((s16)(--reg_d7.h[0]) >= 0);
                            reg_tmp.b[0] = LARGE_TANK(reg_a5)->turret_shots_left;
                            LARGE_TANK(reg_a5)->turret_shots_left -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                LARGE_TANK(reg_a5)->turret_shots_left = (u8) LARGE_TANK(reg_a5)->turret_shots;
                                LARGE_TANK(reg_a5)->turret_countdown = (u8) LARGE_TANK(reg_a5)->turret_pause;
                            }
                        }
                    }
                }
            }
            entity_draw_layer1();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            t4 = reg_d1.h[0];
            reg_d1.h[1] += 0x500;
            reg_d1.h[0] = (u32)t4 + 0x7FFF + 0x7C01;
            reg_d2.h[1] = LARGE_TANK(reg_a5)->turret_sprite[0];
            reg_d2.h[0] = LARGE_TANK(reg_a5)->turret_sprite[1];
            reg_d3.h[0] = 0x620;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer1();
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            if (g_enemies_stopped != 0) {
                return;
            }
            switch (g_bullets_blocked) {
            case 0:
                goto next_5;
            }
            return;
next_5:
            if ((s16) (ENTITY(reg_a6)->y.h) >= 0x1000) {
                if (LARGE_TANK(reg_a5)->gun_shots_left != 0) {
                    goto next_6;
                }
                reg_tmp.b[0] = LARGE_TANK(reg_a5)->gun_countdown;
                LARGE_TANK(reg_a5)->gun_countdown -= 1;
                if ((s32) reg_tmp.b[0] > 0) {
                    goto block_rts;
                }
                LARGE_TANK(reg_a5)->gun_countdown = LARGE_TANK(reg_a5)->gun_interval;
                LARGE_TANK(reg_a5)->gun_shots_left = LARGE_TANK(reg_a5)->gun_shots;
                LARGE_TANK(reg_a5)->gun_aim[1] = 0x80;
                LARGE_TANK(reg_a5)->gun_aim[0] = 0x80;
                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d0.h[0] += 0xFA00;
                reg_d1.h[0] += 0x680;
                aim256_at_player();
                if (cond_flag != 0) {
                    goto next_6;
                }
                LARGE_TANK(reg_a5)->gun_aim[1] = reg_d1.b[0];
                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d0.h[0] += 0x7FFF + 0x7A01;
                reg_d1.h[0] += 0x7FFF + 0x7981;
                aim256_at_player();
                LARGE_TANK(reg_a5)->gun_aim[0] = reg_d1.b[0];
next_6:
                reg_tmp.b[0] = LARGE_TANK(reg_a5)->gun_countdown;
                LARGE_TANK(reg_a5)->gun_countdown -= 1;
                if ((s32) reg_tmp.b[0] > 0) {
                    goto block_rts;
                }
                LARGE_TANK(reg_a5)->gun_countdown = LARGE_TANK(reg_a5)->gun_interval;
                reg_d1.w = 0;
                reg_d1.b[0] = LARGE_TANK(reg_a5)->gun_aim[1];
                rng_next();
                reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
                reg_d1.b[0] += reg_d0.b[0];
                reg_d0.w = 0x20016;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0xFA000680;
                reg_d4.w = 0;
                bullet_fire256_fast();
                reg_d1.w = 0;
                reg_d1.b[0] = LARGE_TANK(reg_a5)->gun_aim[0];
                rng_next();
                reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
                reg_d1.b[0] += reg_d0.b[0];
                reg_d0.w = 0x20016;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0xF9FFF980;
                reg_d4.w = 0;
                bullet_fire256_fast();
                reg_tmp.b[0] = LARGE_TANK(reg_a5)->gun_shots_left;
                LARGE_TANK(reg_a5)->gun_shots_left -= 1;
                if ((s32) reg_tmp.b[0] > 0) {
                    goto block_rts;
                }
                LARGE_TANK(reg_a5)->gun_countdown = LARGE_TANK(reg_a5)->gun_pause;
block_rts:
                return;
            }
        } else {
            reg_d0.w = 0x550;
            score_add();
            sfx_explosion_ground_large();
            reg_d1.h[0] = 0;
            reg_d0.w = 0xC;
            reg_d2.w = 0xF8000000;
            wreck_spawn_a();
            if (g_stage == 4) {
                if ((s32) g_scroll_line < 0x2B0) {
                    reg_d2.w = 0x08000000;
                    wreck_spawn_a();
                }
            }
            reg_d0.w = 0xD;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            t5 = ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->x = t5;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0;
            EXPLOSION(reg_a0)->start_y = 0x400;
            EXPLOSION(reg_a0)->start_x = 0;
            EXPLOSION(reg_a0)->follows_scroll = 1;
            reg_d0.w = 5;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0x400;
            EXPLOSION(reg_a0)->start_y = 0xF800;
            EXPLOSION(reg_a0)->start_x = 0x600;
            EXPLOSION(reg_a0)->follows_scroll = 1;
            reg_d0.w = 5;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0x400;
            EXPLOSION(reg_a0)->start_y = 0xF600;
            EXPLOSION(reg_a0)->start_x = 0xFA00;
            EXPLOSION(reg_a0)->follows_scroll = 1;
            enemy_remove();
        }
    }
}

void hatch_gunner_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(1);
}

extern u16 hatch_gunner_palettes[];
extern u16 hatch_gunner_state[];
extern u16 hatch_gunner_entities[];
extern u16 hatch_gunner_part_sprites[];

void hatch_gunner_start(void) {
    reg_a0 = (u8 *)(hatch_gunner_entities);
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0;
    HATCH_GUNNER(reg_a5)->after_entities[0] = (u16) reg_tmp.h[1];
    HATCH_GUNNER(reg_a5)->after_entities[1] = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)(hatch_gunner_state);
    reg_d0.w = 0xE;
    enemy_set_task_state();
    reg_d0.b[0] = 4;
    reg_d1.b[0] = 4;
    if ((s32) g_stage > 1) {
        reg_d1.b[0] = 0;
        reg_d0.b[0] = 3;
    }
    HATCH_GUNNER(reg_a5)->gun_interval = (u8) reg_d0.b[0];
    HATCH_GUNNER(reg_a5)->hatch_interval = (u8) reg_d1.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)[1].offset_x.h;
    reg_a0 = (u8 *)(hatch_gunner_part_sprites);
    ENTITY(reg_a6)[1].draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)[1].sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(hatch_gunner_palettes);
    reg_d0.h[0] = g_stage_x2;
    reg_a0 += reg_d0.h[0];
    HATCH_GUNNER(reg_a5)->palette = *(s8 *)reg_a0;
    reg_a0 += 1;
    HATCH_GUNNER(reg_a5)->hit_palette = *(s8 *)reg_a0;
    reg_a0 += 1;
    g_enemy_signal_0 += 1;
    enemy_path_start();
    if (enemy_move_end_requested != 0) {
        return;
    }
}

s32 pickup_spawn_variant();
s32 sfx_explosion_air_large();
s32 entity_draw_layer4();
s32 sprite_draw_layer4();
extern u16 hatch_gunner_explosion_offsets[];
extern u8 hatch_gunner_hatch_sprites[];

void hatch_gunner(void) {
    u8 *t1;
    u32 t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;

    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7800;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0xC00;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x7800;
        if (reg_tmp.h[1] != 0) {
            if (HATCH_GUNNER(reg_a5)->seen != 0) {
                g_enemy_signal_0 -= 1;
                enemy_remove();
                return;
            }
            goto next_1;
        }
        HATCH_GUNNER(reg_a5)->seen = 1U;
next_1:
        t1 = (u8 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(t1) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = HATCH_GUNNER(reg_a5)->palette;
            if (((s32) (*(u16 *)((u8 *)(t1) + (0x18))) < 0x380) && (g_damage_blink_counter == 0)) {
                reg_d0.w = 0x19;
            }
            goto next_2;
        }
        (*(u8 *)((u8 *)(t1) + (1))) &= 0xA3;
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = HATCH_GUNNER(reg_a5)->palette;
        }
        reg_d2.b[0] = HATCH_GUNNER(reg_a5)->hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
next_2:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            enemy_anims_spawn_listed();
            if (g_enemies_stopped == 0) {
                ENTITY(reg_a6)->offset_y.h = 0xF400U;
                if ((s32) ENTITY(reg_a6)->move.b.dir < 0x40) {
                    ENTITY(reg_a6)[1].look.h += 0x20;
                    reg_d0.h[0] = ENTITY(reg_a6)[1].look.h;
                    reg_d0.h[0] &= 0x40;
                    ENTITY(reg_a6)->offset_y.h -= reg_d0.h[0];
                    reg_tmp.b[0] = ENTITY(reg_a6)[1].offset_y.b[1];
                    ENTITY(reg_a6)[1].offset_y.b[1] -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        ENTITY(reg_a6)[1].offset_y.b[1] = (u8) ENTITY(reg_a6)[1].offset_y.b[0];
                        if (ENTITY(reg_a6)->move.b.dir == 0) {
                            ENTITY(reg_a6)[1].offset_x.h += 4;
                            if (ENTITY(reg_a6)[1].offset_x.h == 0x10) {
                                ENTITY(reg_a6)[1].offset_x.h = 0U;
                            }
                        } else {
                            reg_tmp.h[0] = ENTITY(reg_a6)[1].offset_x.h;
                            ENTITY(reg_a6)[1].offset_x.h -= 4;
                            if ((s32) reg_tmp.h[0] < 4) {
                                ENTITY(reg_a6)[1].offset_x.h = 0xCU;
                            }
                        }
                        reg_d0.h[0] = ENTITY(reg_a6)[1].offset_x.h;
                        reg_a0 = (u8 *)hatch_gunner_part_sprites;
                        ENTITY(reg_a6)[1].draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                        ENTITY(reg_a6)[1].sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    }
                }
            }
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0) && (g_enemies_stopped == 0) && (g_bullets_blocked == 0) && ((s16) ENTITY(reg_a6)->y.h >= 0x1000)) {
                reg_d0.h[0] = HATCH_GUNNER(reg_a5)->hatch_state;
                if (reg_d0.h[0] == 0) {
                    reg_tmp.b[0] = HATCH_GUNNER(reg_a5)->hatch_countdown;
                    HATCH_GUNNER(reg_a5)->hatch_countdown -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        HATCH_GUNNER(reg_a5)->hatch_countdown = 0x10U;
                        HATCH_GUNNER(reg_a5)->hatch_state = 1U;
                    }
                } else if ((reg_d0.h[0] & 0xFFFF) == 1) {
                    reg_tmp.b[0] = HATCH_GUNNER(reg_a5)->frame_countdown;
                    HATCH_GUNNER(reg_a5)->frame_countdown -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        HATCH_GUNNER(reg_a5)->frame_countdown = (u8) HATCH_GUNNER(reg_a5)->frame_interval;
                        if ((s16) ENTITY(reg_a6)->y.h < 0x6C00) {
                            HATCH_GUNNER(reg_a5)->hatch_frame += 4;
                            reg_d0.h[0] = HATCH_GUNNER(reg_a5)->hatch_frame;
                            reg_a0 = (u8 *)hatch_gunner_hatch_sprites;
                            HATCH_GUNNER(reg_a5)->hatch_sprite[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                            HATCH_GUNNER(reg_a5)->hatch_sprite[1] = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            if (reg_d0.h[0] == 0x1C) {
                                HATCH_GUNNER(reg_a5)->shot_number = 0xFFFEU;
                                HATCH_GUNNER(reg_a5)->hatch_state = 2U;
                            }
                        }
                    }
                } else if ((reg_d0.h[0] & 0xFFFF) == 2) {
                    reg_tmp.b[0] = HATCH_GUNNER(reg_a5)->hatch_countdown;
                    HATCH_GUNNER(reg_a5)->hatch_countdown -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        HATCH_GUNNER(reg_a5)->hatch_countdown = (u8) HATCH_GUNNER(reg_a5)->hatch_interval;
                        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d0.h[0] += 0xA80;
                        aim256_at_player();
                        reg_d7.h[0] = reg_d1.h[0];
                        rng_next();
                        reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
                        reg_d1.b[0] += reg_d0.b[0];
                        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                        t4 = ENTITY(reg_a6)->x.h;
                        reg_d2.h[0] = t4;
                        reg_d3.w = 0x0A800400;
                        reg_d4.w = 0;
                        reg_d0.h[0] = HATCH_GUNNER(reg_a5)->shot_number;
                        reg_tmp.h[0] = reg_d0.h[0];
                        reg_d0.h[0] = 0x13;
                        reg_d0.h[1] = reg_tmp.h[0];
                        bullet_fire256_fast();
                        reg_d1.h[0] = reg_d7.h[0];
                        rng_next();
                        reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
                        reg_d1.b[0] += reg_d0.b[0];
                        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                        t5 = ENTITY(reg_a6)->x.h;
                        reg_d2.h[0] = t5;
                        reg_d3.w = 0x0A7FFC00;
                        reg_d4.w = 0;
                        reg_d0.h[0] = HATCH_GUNNER(reg_a5)->shot_number;
                        reg_tmp.h[0] = reg_d0.h[0];
                        reg_d0.h[0] = 0x13;
                        reg_d0.h[1] = reg_tmp.h[0];
                        bullet_fire256_fast();
                        HATCH_GUNNER(reg_a5)->shot_number += 1;
                        reg_tmp.b[0] = HATCH_GUNNER(reg_a5)->hatch_shots_left;
                        HATCH_GUNNER(reg_a5)->hatch_shots_left -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            HATCH_GUNNER(reg_a5)->hatch_shots_left = (u8) HATCH_GUNNER(reg_a5)->hatch_shots;
                            if (HATCH_GUNNER(reg_a5)->hatch_shots_left != 0) {
                                HATCH_GUNNER(reg_a5)->hatch_countdown = (u8) HATCH_GUNNER(reg_a5)->hatch_pause;
                                HATCH_GUNNER(reg_a5)->hatch_state = 3U;
                                HATCH_GUNNER(reg_a5)->frame_countdown = 0x10U;
                            }
                        }
                    }
                } else {
                    reg_tmp.b[0] = HATCH_GUNNER(reg_a5)->frame_countdown;
                    HATCH_GUNNER(reg_a5)->frame_countdown -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        HATCH_GUNNER(reg_a5)->frame_countdown = (u8) HATCH_GUNNER(reg_a5)->frame_interval;
                        HATCH_GUNNER(reg_a5)->hatch_frame -= 4;
                        reg_d0.h[0] = HATCH_GUNNER(reg_a5)->hatch_frame;
                        reg_a0 = (u8 *)hatch_gunner_hatch_sprites;
                        HATCH_GUNNER(reg_a5)->hatch_sprite[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                        HATCH_GUNNER(reg_a5)->hatch_sprite[1] = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                        if (reg_d0.h[0] == 0) {
                            HATCH_GUNNER(reg_a5)->hatch_state = 0U;
                        }
                    }
                }
            }
            t2 = 0xFA00 & 0xFFFF;
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] += t2;
            reg_tmp1.h[0] = reg_d1.h[0];
            reg_d1.h[0] = reg_d1.h[1];
            reg_d1.h[1] = reg_tmp1.h[0];
            reg_d1.h[0] += 0x7FFF + 0x7201;
            reg_tmp1.h[0] = reg_d1.h[0];
            reg_d1.h[0] = reg_d1.h[1];
            reg_d1.h[1] = reg_tmp1.h[0];
            reg_d2.h[1] = ENTITY(reg_a6)[1].draw.h;
            reg_d2.h[0] = ENTITY(reg_a6)[1].sprite.h;
            reg_d3.h[0] = 0x230;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer4();
            entity_draw_layer4();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] += 0x7FFF + 0x7A01;
            reg_tmp1.h[0] = reg_d1.h[0];
            reg_d1.h[0] = reg_d1.h[1];
            reg_d1.h[1] = reg_tmp1.h[0];
            reg_d1.h[0] += 0x800;
            reg_d0.h[0] = ENTITY(reg_a6)[1].look.h;
            reg_d0.h[0] &= 0x40;
            reg_d1.h[0] -= reg_d0.h[0];
            reg_tmp1.h[0] = reg_d1.h[0];
            reg_d1.h[0] = reg_d1.h[1];
            reg_d1.h[1] = reg_tmp1.h[0];
            reg_d2.h[1] = HATCH_GUNNER(reg_a5)->hatch_sprite[0];
            reg_d2.h[0] = HATCH_GUNNER(reg_a5)->hatch_sprite[1];
            reg_d3.h[0] = 0x430;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer4();
            reg_a0 = reg_a6;
            enemy_hitbox_debug_draw();
            if (g_enemies_stopped != 0) {
                goto block_rts;
            }
            switch (g_bullets_blocked) {
            case 0:
                break;
            default:
                return;
            }
            if ((s16) ENTITY(reg_a6)->y.h < 0x1000) {
                goto block_rts;
            }
            reg_tmp.b[0] = HATCH_GUNNER(reg_a5)->gun_countdown;
            HATCH_GUNNER(reg_a5)->gun_countdown -= 1;
            if ((s32) reg_tmp.b[0] > 0) {
                goto block_rts;
            }
            HATCH_GUNNER(reg_a5)->gun_countdown = (u8) HATCH_GUNNER(reg_a5)->gun_interval;
            reg_d0.w = 0xFFFE0004;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d3.w = 0xFE000000;
            reg_d7.h[0] = 7;
            reg_d1.h[0] = 0x6B;
            reg_d4.w = 0;
            do {
                bullet_fire256_fast();
                reg_d1.h[0] += 7;
            } while ((s16)(--reg_d7.h[0]) >= 0);
            reg_tmp.b[0] = HATCH_GUNNER(reg_a5)->gun_shots_left;
            HATCH_GUNNER(reg_a5)->gun_shots_left -= 1;
            if ((s32) reg_tmp.b[0] > 0) {
                goto block_rts;
            }
            HATCH_GUNNER(reg_a5)->gun_shots_left = (u8) HATCH_GUNNER(reg_a5)->gun_shots;
            HATCH_GUNNER(reg_a5)->gun_countdown = (u8) HATCH_GUNNER(reg_a5)->gun_pause;
block_rts:
            return;
        } else {
            reg_d0.w = 0x130;
            score_add();
            sfx_explosion_air_large();
            reg_d0.w = 0xC;
            reg_d1.h[0] = 8;
            wreck_spawn_a();
            reg_d0.w = 0xD;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            t6 = ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->x = t6;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->debris = 1;
            EXPLOSION(reg_a0)->debris_arg = 0x400;
            EXPLOSION(reg_a0)->start_y = 0x400;
            EXPLOSION(reg_a0)->start_x = 0;
            EXPLOSION(reg_a0)->follows_scroll = 1;
            reg_d0.w = 0xC;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->debris = 1;
            EXPLOSION(reg_a0)->debris_arg = 0;
            EXPLOSION(reg_a0)->start_y = 0xFA00;
            EXPLOSION(reg_a0)->start_x = 0x600;
            EXPLOSION(reg_a0)->follows_scroll = 1;
            reg_d0.w = 0x84;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->debris = 1;
            EXPLOSION(reg_a0)->debris_arg = 0;
            EXPLOSION(reg_a0)->start_y = 0xFA00;
            EXPLOSION(reg_a0)->start_x = 0xFA00;
            EXPLOSION(reg_a0)->follows_scroll = 1;
            g_enemy_signal_0 -= 1;
            reg_d0.w = 8;
            reg_a4 = (u8 *)(hatch_gunner_explosion_offsets);
            reg_d6.w = 3;
            do {
                reg_d1.h[1] = *(u16 *)reg_a4;
                reg_a4 += 2;
                t3 = *(u16 *)reg_a4;
                reg_d1.h[0] = t3;
                reg_a4 += 2;
                reg_d2.w = 3;
                pickup_spawn_variant();
            } while ((s16)(--reg_d6.h[0]) >= 0);
            enemy_remove();
        }
    }
}

extern u8 warning_sign_frames[];

void warning_sign_set_frame(void) {
    reg_d0.h[0] = WARNING_SIGN(reg_a5)->frame;
    reg_a0 = warning_sign_frames;
    reg_a0 += reg_d0.h[0];
    ENTITY(reg_a6)->draw.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->sprite.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    WARNING_SIGN(reg_a5)->frame_time = *(u16 *)reg_a0;
    reg_a0 += 2;
}

void warning_sign_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 voice_warning();
s32 sprite_palette_load();
extern u16 warning_sign_palette_numbers[];
extern u16 warning_sign_second_palette_numbers[];
extern u8 warning_sign_state[];
extern u8 warning_sign_entities[];
extern u8 D_00261C30[];
extern u8 warning_sign_start_table[];

void warning_sign_start(void) {
    reg_a0 = warning_sign_entities;
    enemy_init_entities();
    reg_a0 = warning_sign_state;
    reg_d0.w = 5;
    enemy_set_task_state();
    reg_tmp.w = 0x40001C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
    voice_warning();
    reg_a0 = warning_sign_start_table;
    reg_d6.h[0] = g_stage_x2;
    reg_a1 = (u8 *)(warning_sign_palette_numbers);
    reg_d0.h[0] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a1;
    ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
    sprite_palette_load();
    reg_a0 = D_00261C30;
    reg_a1 = (u8 *)(warning_sign_second_palette_numbers);
    reg_d0.h[0] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a1;
    sprite_palette_load();
}

s32 sfx_warning();
s32 entity_draw_with_warning();

void warning_sign(void) {
    u16 m;

    if (WARNING_SIGN(reg_a5)->sounds_left == 0) goto next_20;
    reg_tmp.b[0] = WARNING_SIGN(reg_a5)->sound_countdown;
    WARNING_SIGN(reg_a5)->sound_countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_20;
    WARNING_SIGN(reg_a5)->sound_countdown = WARNING_SIGN(reg_a5)->sound_interval;
    sfx_warning();
    WARNING_SIGN(reg_a5)->sounds_left -= 1;
next_20:
    ENTITY(reg_a6)->x.sh = 0x1C00;
    reg_tmp.h[0] = WARNING_SIGN(reg_a5)->frame_time;
    WARNING_SIGN(reg_a5)->frame_time -= 1;
    if ((s32) reg_tmp.h[0] > 0) goto block_objset;
    m = WARNING_SIGN(reg_a5)->phase;
    if (m != 0) goto next_100;
    warning_sign_set_frame();
    WARNING_SIGN(reg_a5)->frame += 8;
    if (WARNING_SIGN(reg_a5)->frame != 0xF0) goto block_objset;
    WARNING_SIGN(reg_a5)->phase = 1;
    goto block_objset;
next_100:
    if ((m & 0xFFFF) != 1) goto next_200;
    warning_sign_set_frame();
    WARNING_SIGN(reg_a5)->frame += 8;
    if (WARNING_SIGN(reg_a5)->frame != 0x128) goto block_objset;
    WARNING_SIGN(reg_a5)->frame = 0x100;
    reg_tmp.h[0] = WARNING_SIGN(reg_a5)->flashes_left;
    WARNING_SIGN(reg_a5)->flashes_left -= 1;
    if ((s32) reg_tmp.h[0] > 0) goto block_objset;
    WARNING_SIGN(reg_a5)->phase = 2;
    goto block_objset;
next_200:
    warning_sign_set_frame();
    WARNING_SIGN(reg_a5)->frame += 8;
    if (WARNING_SIGN(reg_a5)->frame != 0x230) goto block_objset;
    enemy_remove();
    return;
block_objset:
    entity_draw_with_warning();
    switch (g_frame_mod2) {
    case 0:
        return;
    default:
        break;
    }
    if (g_game_frame & 2) {
        ENTITY(reg_a6)->y.h -= 0x40;
        entity_draw_with_warning();
        ENTITY(reg_a6)->y.h += 0x40;
        return;
    }
    ENTITY(reg_a6)->y.h += 0x40;
    entity_draw_with_warning();
    ENTITY(reg_a6)->y.h -= 0x40;
}
