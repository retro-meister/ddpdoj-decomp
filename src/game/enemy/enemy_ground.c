#include "common.h"
#ifdef DDPDOJ_PC
#include "pc_gameplay_abi.h"
#endif
#include "entity.h"
#include "explosion.h"

#include "enemy.h"
#include "enemy_small.h"

/*
 * What the enemies of this unit keep in the enemy state block (reg_a5), after what every enemy has
 * (EnemyState). A pair named interval/countdown or shots/shots_left is a value and the counter loaded from it.
 */

/* The battleship: several entities with one count of hit points. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 other_16;
    /* 0x17 */ u8 seen;               /* it has been on the screen; when it is off it again it is removed */
    /* 0x18 */ u8 hit_palette;        /* mixed into the palette on the frame of a hit */
    /* 0x19 */ u8 palette;
    /* 0x1A */ u16 hp[2];             /* hit points as a 32-bit value, high word first */
    /* 0x1E */ u8 other_1E[0x26];
    /* 0x44 */ u16 after_entities[2]; /* where enemy_init_entities stopped in its table */
} BattleshipState;

#define BATTLESHIP(pointer) ((BattleshipState *)(pointer))

/* The four guns of stage 3: they turn towards the player and fire bursts. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 other_16;
    /* 0x17 */ u8 seen;
    /* 0x18 */ u8 other_18[2];
    /* 0x1A */ u8 palette_now;
    /* 0x1B */ u8 dir;
    /* 0x1C */ u8 hit_palette;
    /* 0x1D */ u8 palette;
    /* 0x1E */ u8 fire_dir;           /* the direction a burst keeps */
    /* 0x1F */ u8 destroyed;
    /* 0x20 */ u8 other_20;
    /* 0x21 */ u8 pause_countdown;    /* frames to the next burst */
    /* 0x22 */ u8 shot_interval;
    /* 0x23 */ u8 shot_countdown;
    /* 0x24 */ u8 other_24;
    /* 0x25 */ u8 shots_left;
    /* 0x26 */ u16 size;
    /* 0x28 */ u16 sprite[2];
    /* 0x2C */ u16 draw_at[2];
    /* 0x30 */ u16 frame;
} Stage3GunState;

#define STAGE3_GUN(pointer) ((Stage3GunState *)(pointer))

/* The large gun of stage 3: four arms that go round and fire. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 fire_dir;
    /* 0x17 */ u8 seen;
    /* 0x18 */ u8 other_18[2];
    /* 0x1A */ u8 palette_now;
    /* 0x1B */ u8 angle;              /* of the arms; one step a frame */
    /* 0x1C */ u8 hit_palette;
    /* 0x1D */ u8 palette;
    /* 0x1E */ u8 pause;
    /* 0x1F */ u8 pause_countdown;
    /* 0x20 */ u8 other_20[4];
    /* 0x24 */ u8 shot_interval;
    /* 0x25 */ u8 shot_countdown;
    /* 0x26 */ u8 shots;
    /* 0x27 */ u8 shots_left;
    /* 0x28 */ u16 arm[8];            /* the four arms' positions, y and x each */
    /* 0x38 */ u8 other_38;
    /* 0x39 */ u8 spin;               /* +2 or -2: which way the firing direction goes round */
    /* 0x3A */ u16 start_line;        /* the scroll line it started at; it tells the three of the stage apart */
    /* 0x3C */ u16 frame;
    /* 0x3E */ u16 hp;
} Stage3LargeGunState;

#define STAGE3_LARGE_GUN(pointer) ((Stage3LargeGunState *)(pointer))

/* Starts a small flyer B every `interval` frames. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 other_16[2];
    /* 0x18 */ union { s16 both; struct { u8 interval; u8 countdown; } b; } spawn;
} FlyerSpawnerState;

#define FLYER_SPAWNER(pointer) ((FlyerSpawnerState *)(pointer))

/* The cloud bank of stage 3: two entities that take turns to be put back at the top. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 other_16[2];
    /* 0x18 */ u16 travelled;         /* since an entity was last put back */
    /* 0x1A */ u16 next_entity;       /* byte offset of the entity to put back next: 0 or 0x20 */
    /* 0x1C */ u16 picture;           /* byte offset into its table of pictures */
    /* 0x1E */ u16 rounds_left;
    /* 0x20 */ u8 interval;
    /* 0x21 */ u8 countdown;
    /* 0x22 */ u16 ending;            /* no more entities are shown */
} Stage3CloudState;

#define STAGE3_CLOUD(pointer) ((Stage3CloudState *)(pointer))

/* The carrier of stage 3, which starts a battleship B or C on itself. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 other_16;
    /* 0x17 */ u8 seen;
} Stage3CarrierState;

#define STAGE3_CARRIER(pointer) ((Stage3CarrierState *)(pointer))

/*
 * Battleships B and C. Whoever starts one leaves its position and movement in the first words; the start
 * routine takes them and then loads the block from its table.
 */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct { u16 y; u16 x; } at_start;
        struct {
            u8 phase;                 /* 0: coming, 1: opening, 2: open and firing */
            u8 other_17;
            u8 hit_palette;
            u8 palette;
        } now;
    };
    /* 0x1A */ u16 start_move;
    /* 0x1C */ u8 other_1C[2];
    /* 0x1E */ u16 frame;             /* byte offset into its pictures while it opens */
    /* 0x20 */ u8 frame_interval;
    /* 0x21 */ u8 frame_countdown;
    /* 0x22 */ u8 low_layer_frames;   /* frames it is still drawn on the lower layer */
    /* 0x23 */ u8 falling;
    /* 0x24 */ u8 fall_interval;      /* frames between two steps of speed */
    /* 0x25 */ u8 fall_countdown;
    /* 0x26 */ u16 fall_speed;
    /* 0x28 */ u8 fire_interval;
    /* 0x29 */ u8 fire_countdown;
    /* 0x2A */ u16 salvo;             /* 0 to 3: which of its four salvos is next */
    /* 0x2C */ u16 fire_step;         /* 0: waiting, then the steps of a salvo */
    /* 0x2E */ u16 dying;             /* 1: destroyed this frame, 2: blowing up */
    /* 0x30 */ u16 explosion;         /* byte offset into its table of explosions */
    /* 0x32 */ union { s16 both; struct { u8 interval; u8 countdown; } b; } explosion_timer;
    /* 0x34 */ u16 explosions;
    /* 0x36 */ u16 dying_frames;
    /* 0x38 */ u16 dying_dir;
} BattleshipBState;

#define BATTLESHIP_B(pointer) ((BattleshipBState *)(pointer))

/* The wing gunner: its two sides move apart, it fires while they are, and they close again. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 phase;              /* 0: shut, 1: opening, 2: firing, 3: shutting */
    /* 0x17 */ u8 seen;
    /* 0x18 */ u8 hit_palette;
    /* 0x19 */ u8 palette;
    /* 0x1A */ u16 spread;            /* how far apart the sides are, 0 to 0x380 */
    /* 0x1C */ u8 wait;
    /* 0x1D */ u8 wait_countdown;
    /* 0x1E */ u8 shot_interval;
    /* 0x1F */ u8 shot_countdown;
    /* 0x20 */ u8 open_time;
    /* 0x21 */ u8 open_countdown;     /* loaded when it has opened */
    /* 0x22 */ u16 shot_step;
    /* 0x24 */ u16 shots_fired;
    /* 0x26 */ u8 other_26;
    /* 0x27 */ u8 has_fired;
} WingGunnerState;

#define WING_GUNNER(pointer) ((WingGunnerState *)(pointer))

/* The hover gunner: it bobs, turns its gun towards the player and fires bursts. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 other_16;
    /* 0x17 */ u8 seen;
    /* 0x18 */ u8 hit_palette;
    /* 0x19 */ u8 palette;
    /* 0x1A */ u16 frame;             /* 0 or 4 */
    /* 0x1C */ u8 frame_interval;
    /* 0x1D */ u8 frame_countdown;
    /* 0x1E */ u16 bob;               /* what the bobbing adds to its position this frame */
    /* 0x20 */ u8 bob_angle;
    /* 0x21 */ u8 other_21[2];
    /* 0x23 */ u8 turret_dir;
    /* 0x24 */ u8 shot_interval;
    /* 0x25 */ u8 shot_countdown;
    /* 0x26 */ u8 shots;
    /* 0x27 */ u8 shots_left;
} HoverGunnerState;

#define HOVER_GUNNER(pointer) ((HoverGunnerState *)(pointer))

/* Sets enemy signal 8 for one frame in bursts of pulses. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union { s16 both; struct { u8 interval; u8 countdown; } b; } pulse;
    /* 0x18 */ union { s16 both; struct { u8 pulses; u8 pulses_left; } b; } burst;
} SignalTimerState;

#define SIGNAL_TIMER(pointer) ((SignalTimerState *)(pointer))

/*
 * The two small flyers keep these in the enemy state block (reg_a5), after what every enemy has. They are
 * two entities with one count of hit points between them.
 */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 fire_dir;
    /* 0x17 */ u8 seen;               /* it has been on the screen; when it is off it again it is removed */
    /* 0x18 */ u8 hit_palette;        /* mixed into the palette on the frame of a hit */
    /* 0x19 */ u8 palette;
    /* 0x1A */ u8 turn_interval;      /* frames between two turns towards the player */
    /* 0x1B */ u8 turn_countdown;
    /* 0x1C */ u16 turning_frames;    /* frames it still turns for */
    /* 0x1E */ u8 other_1E;
    /* 0x1F */ u8 burst_countdown;
    /* 0x20 */ u8 fire_interval;
    /* 0x21 */ u8 fire_countdown;
    /* 0x22 */ u8 shots;
    /* 0x23 */ u8 shots_left;
    /* 0x24 */ u16 hp[2];             /* hit points as a 32-bit value, high word first */
    /* 0x28 */ u16 frame;             /* 0 or 4: which of the two pictures of its direction */
} SmallFlyerState;

#define SMALL_FLYER(pointer) ((SmallFlyerState *)(pointer))

void battleship_turret_2_draw(void);
void battleship_turret_3_draw(void);
void battleship_turret_4_draw(void);
void battleship_turret_5_draw(void);
void battleship_part_6_update(void);
void stage3_gun_draw_barrel(void);
void small_flyer_draw(void);
void battleship_b_fire(void);
void ground_gun_a_fire(void);
void ground_gun_b_fire(void);
void battleship_b_blow_up(void);
void battleship_c_volley_update(void);
void battleship_c_fire(void);
void ground_gun_c_fire(void);

s32 explosion_spawn();

void enemy_explode_by_table(arg2)
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
        EXPLOSION(reg_a0)->draw_layer = (u16) reg_d3.h[0];
        EXPLOSION(reg_a0)->follows_scroll = 2;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0;
        EXPLOSION(reg_a0)->move.h = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        goto loop_1;
    }
}

#ifndef DDPDOJ_PC
s32 bullet_fire();
#endif
s32 rng_next();
extern u16 g_direction64_offsets_2CC[];

void battleship_shot_random(void) {
    u16 temp_a0;
    rng_next();
    temp_a0 = reg_d0.h[0];
    reg_a1 = (u8 *)(g_direction64_offsets_2CC);
    reg_d4.w = 0;
    reg_tmp.h[0] = temp_a0;
    reg_d0.h[0] = 5;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d5.w;
    bullet_fire();
    reg_d1.b[0] -= 4;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d5.w;
    bullet_fire();
    reg_d1.b[0] -= 4;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d5.w;
    bullet_fire();
    reg_d1.b[0] -= 4;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d5.w;
    bullet_fire();
    reg_d1.b[0] += 0x10;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d5.w;
    bullet_fire();
    reg_d1.b[0] += 4;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d5.w;
    bullet_fire();
    reg_d1.b[0] += 4;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d5.w;
    bullet_fire();
}

extern void enemy_set_entity_count(s32);

void battleship_first(void) {
    enemy_set_entity_count(6);
}

extern u8 D_00257C10[];
extern u8 D_0028C9B0;
extern u16 g_enemy_signal_f;
extern u16 g_enemy_signal_e;
extern u16 g_enemy_signal_d;
extern u16 g_scroll_line;
extern s8 enemy_move_end_requested;

void battleship_start(void) {
#ifndef DDPDOJ_PC
    s32 enemy_remove();
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
#endif
    reg_a0 = (u8 *)D_00257C10;
    enemy_init_entities();
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a0);
    BATTLESHIP(reg_a5)->after_entities[0] = (u16) reg_tmp.h[1];
    BATTLESHIP(reg_a5)->after_entities[1] = (u16) reg_tmp.h[0];
    reg_a0 = &D_0028C9B0;
    reg_d0.w = 3;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested != 0) return;
    ENTITY(reg_a6)[2].attr.sb.flip = 0x10;
    ENTITY(reg_a6)[2].misc.sb.user = 0xF;
    ENTITY(reg_a6)[3].attr.sb.flip = 0x10;
    ENTITY(reg_a6)[3].misc.sb.user = 0xF;
    ENTITY(reg_a6)[4].attr.sb.flip = 0x10;
    ENTITY(reg_a6)[4].misc.sb.user = 0xF;
    ENTITY(reg_a6)[5].attr.sb.flip = 0x10;
    ENTITY(reg_a6)[5].misc.sb.user = 0xF;
    if (g_scroll_line != 0x26) goto next_1;
    if (g_enemy_signal_e == 0) goto block_f3;
    enemy_remove();
    return;
next_1:
    if (g_scroll_line != 0x1B) goto next_2;
    if (g_enemy_signal_f == 0) goto block_f2;
    enemy_remove();
    return;
next_2:
    g_enemy_signal_f = 1;
    g_enemy_signal_e = 1;
    g_enemy_signal_d = 1;
    return;
block_f2:
    ENTITY(reg_a6)[6].hp.sb[0] = 1;
    g_enemy_signal_e = 1;
    g_enemy_signal_d = 1;
    return;
block_f3:
    g_enemy_signal_d = 1;
}

s32 bullet_fire_fast();
s32 bullet_fire_2way();
s32 enemy_anims_spawn_listed_long();
#ifndef DDPDOJ_PC
s32 enemy_hitbox_debug_draw();
#endif
s32 sfx_explosion_air_small();
s32 sfx_explosion_ground_large();
s32 sprite_draw_layer4_keep();
s32 score_add_no_chain();
s32 score_add();
s32 aim_at_player();
s32 direction_turn_toward();
extern u16 D_00257D20[];
extern u8 g_direction_twin_offsets_400[];
extern u8 g_direction_offsets_500[];
extern u16 g_enemy_signal_d;
extern u16 g_bullets_blocked;
extern u16 g_enemies_stopped;
extern u16 g_rank_1_16;
extern u16 g_rank_2_16;

void battleship(void) {
#ifndef DDPDOJ_PC
    s32 enemy_remove();
    s32 enemy_path_step();
#endif
    u16 temp_a0;
    u16 temp_a1_2;
    u16 temp_a2;
    u16 temp_a2_2;
    u16 temp_a2_3;
    u16 var_a0;
    u8 *temp_a3;
    u8 *var_a1;

    if ((s16)ENTITY(reg_a6)->y.h <= -0x2400) {
        if (BATTLESHIP(reg_a5)->seen != 0) {
            g_enemy_signal_d = 0;
            enemy_remove();
            return;
        }
        goto block_4;
    }
    BATTLESHIP(reg_a5)->seen = 1U;
block_4:
    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        if ((s32) g_scroll_line >= 0x7F) {
            g_enemy_signal_d = 0;
            g_enemy_signal_f = 0;
        }
        reg_d0.h[1] = ENTITY(reg_a6)->y.h;
        reg_d0.h[0] = ENTITY(reg_a6)->x.h;
        ENTITY(reg_a6)[1].y.h = (u16) reg_d0.h[1];
        ENTITY(reg_a6)[1].x.h = (u16) reg_d0.h[0];
        ENTITY(reg_a6)[2].y.h = (u16) reg_d0.h[1];
        ENTITY(reg_a6)[2].x.h = (u16) reg_d0.h[0];
        ENTITY(reg_a6)[2].y.h += 0xA00;
        ENTITY(reg_a6)[2].x.h -= 0x600;
        ENTITY(reg_a6)[3].y.h = (u16) reg_d0.h[1];
        ENTITY(reg_a6)[3].x.h = (u16) reg_d0.h[0];
        ENTITY(reg_a6)[3].y.h += 0xA00;
        ENTITY(reg_a6)[3].x.h += 0x600;
        ENTITY(reg_a6)[4].y.h = (u16) reg_d0.h[1];
        ENTITY(reg_a6)[4].x.h = (u16) reg_d0.h[0];
        ENTITY(reg_a6)[4].y.h -= 0x300;
        ENTITY(reg_a6)[5].y.h = (u16) reg_d0.h[1];
        ENTITY(reg_a6)[5].x.h = (u16) reg_d0.h[0];
        ENTITY(reg_a6)[5].y.h -= 0x1000;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        reg_d1.b[0] |= ENTITY(reg_a6)[1].flags.b[1];
        reg_d1.h[0] &= 0x5C;
        if (reg_d1.h[0] != 0) {
            reg_d0.b[0] = 0xA3;
            ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
            ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
            score_add_no_chain();
            reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
            reg_d2.b[0] = BATTLESHIP(reg_a5)->hit_palette;
            reg_d0.b[0] ^= reg_d2.b[0];
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            reg_d0.b[0] = ENTITY(reg_a6)[2].attr.b.palette;
            reg_d2.b[0] = ENTITY(reg_a6)[2].misc.b.user;
            reg_d0.b[0] ^= reg_d2.b[0];
            ENTITY(reg_a6)[2].attr.b.palette = (u8) reg_d0.b[0];
            reg_d0.b[0] = ENTITY(reg_a6)[3].attr.b.palette;
            reg_d2.b[0] = ENTITY(reg_a6)[3].misc.b.user;
            reg_d0.b[0] ^= reg_d2.b[0];
            ENTITY(reg_a6)[3].attr.b.palette = (u8) reg_d0.b[0];
            reg_d0.b[0] = ENTITY(reg_a6)[4].attr.b.palette;
            reg_d2.b[0] = ENTITY(reg_a6)[4].misc.b.user;
            reg_d0.b[0] ^= reg_d2.b[0];
            ENTITY(reg_a6)[4].attr.b.palette = (u8) reg_d0.b[0];
            reg_d0.b[0] = ENTITY(reg_a6)[5].attr.b.palette;
            reg_d2.b[0] = ENTITY(reg_a6)[5].misc.b.user;
            reg_d0.b[0] ^= reg_d2.b[0];
            ENTITY(reg_a6)[5].attr.b.palette = (u8) reg_d0.b[0];
            reg_d2.w = 0x7FFF;
            reg_d2.h[0] -= ENTITY(reg_a6)->hp.h;
            reg_tmp.h[1] = BATTLESHIP(reg_a5)->hp[0];
            reg_tmp.h[0] = BATTLESHIP(reg_a5)->hp[1];
            reg_tmp.w -= reg_d2.w;
            BATTLESHIP(reg_a5)->hp[0] = (u16) reg_tmp.h[1];
            BATTLESHIP(reg_a5)->hp[1] = (u16) reg_tmp.h[0];
            reg_d2.w = 0x7FFF;
            var_a1 = reg_a5;
            reg_d2.h[0] -= ENTITY(reg_a6)[1].hp.h;
            reg_tmp.h[1] = BATTLESHIP(var_a1)->hp[0];
            reg_tmp.h[0] = BATTLESHIP(var_a1)->hp[1];
            reg_tmp.w -= reg_d2.w;
            BATTLESHIP(var_a1)->hp[0] = (u16) reg_tmp.h[1];
            var_a0 = reg_tmp.h[0];
            BATTLESHIP(reg_a5)->hp[1] = var_a0;
            reg_d0.h[0] = 0x7FFF;
            ENTITY(reg_a6)->hp.h = (u16) reg_d0.h[0];
            ENTITY(reg_a6)[1].hp.h = (u16) reg_d0.h[0];
            if (ENTITY(reg_a6)[2].misc.b.draw_layer == 0) {
                reg_tmp.h[1] = BATTLESHIP(reg_a5)->hp[0];
                reg_tmp.h[0] = BATTLESHIP(reg_a5)->hp[1];
                if ((s32) reg_tmp.w < 0x1001) {
                    reg_d0.w = 0x13;
                    score_add();
                    reg_d0.w = 0x13;
                    score_add();
                    sfx_explosion_air_small();
                    ENTITY(reg_a6)[2].misc.b.draw_layer = 1U;
                    ENTITY(reg_a6)[3].misc.b.draw_layer = 1U;
                    reg_d0.h[0] = 0x83;
                    explosion_spawn();
                    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)[2].y.h;
                    temp_a2 = ENTITY(reg_a6)[2].x.h;
                    EXPLOSION(reg_a0)->x = temp_a2;
                    EXPLOSION(reg_a0)->debris = 0;
                    EXPLOSION(reg_a0)->debris_arg = 0;
                    EXPLOSION(reg_a0)->draw_layer = 0x10;
                    EXPLOSION(reg_a0)->follows_scroll = 2;
                    EXPLOSION(reg_a0)->move.b.speed = (u8) ENTITY(reg_a6)->move.b.speed;
                    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
                    reg_d0.b[0] *= 4;
                    EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
                    reg_d0.h[0] = 0x83;
                    explosion_spawn();
                    var_a0 = 0x10;
                    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)[3].y.h;
                    var_a1 = (void *) ENTITY(reg_a6)[3].x.h;
                    EXPLOSION(reg_a0)->x = (u16) var_a1;
                    EXPLOSION(reg_a0)->debris = 0;
                    EXPLOSION(reg_a0)->debris_arg = 0;
                    EXPLOSION(reg_a0)->draw_layer = 0x10;
                    EXPLOSION(reg_a0)->follows_scroll = 2;
                    EXPLOSION(reg_a0)->move.b.speed = (u8) ENTITY(reg_a6)->move.b.speed;
                    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
                    reg_d0.b[0] *= 4;
                    EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
                }
            }
            if (ENTITY(reg_a6)[5].misc.b.draw_layer == 0) {
                reg_tmp.h[1] = BATTLESHIP(reg_a5)->hp[0];
                reg_tmp.h[0] = BATTLESHIP(reg_a5)->hp[1];
                if ((s32) reg_tmp.w < 0x2A01) {
                    reg_d0.w = 0x11;
                    score_add();
                    ENTITY(reg_a6)[5].misc.b.draw_layer = 1U;
                    reg_d0.h[0] = 0x84;
                    explosion_spawn();
                    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)[5].y.h;
                    temp_a2_2 = ENTITY(reg_a6)[5].x.h;
                    EXPLOSION(reg_a0)->x = temp_a2_2;
                    EXPLOSION(reg_a0)->debris = 0;
                    EXPLOSION(reg_a0)->debris_arg = 0x800;
                    EXPLOSION(reg_a0)->draw_layer = 0x10;
                    EXPLOSION(reg_a0)->follows_scroll = 2;
                    EXPLOSION(reg_a0)->move.b.speed = (u8) ENTITY(reg_a6)->move.b.speed;
                    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
                    reg_d0.b[0] *= 4;
                    EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
                    sfx_explosion_air_small();
                }
            }
            if (ENTITY(reg_a6)[4].misc.b.draw_layer == 0) {
                reg_tmp.h[1] = BATTLESHIP(reg_a5)->hp[0];
                reg_tmp.h[0] = BATTLESHIP(reg_a5)->hp[1];
                if ((s32) reg_tmp.w < 0x2001) {
                    reg_d0.w = 0x32;
                    score_add();
                    ENTITY(reg_a6)[4].misc.b.draw_layer = 1U;
                    reg_d0.h[0] = 0x84;
                    explosion_spawn();
                    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)[4].y.h;
                    temp_a2_3 = ENTITY(reg_a6)[4].x.h;
                    EXPLOSION(reg_a0)->x = temp_a2_3;
                    EXPLOSION(reg_a0)->debris = 0;
                    EXPLOSION(reg_a0)->debris_arg = 0x800;
                    EXPLOSION(reg_a0)->draw_layer = 0x10;
                    EXPLOSION(reg_a0)->follows_scroll = 2;
                    EXPLOSION(reg_a0)->move.b.speed = (u8) ENTITY(reg_a6)->move.b.speed;
                    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
                    reg_d0.b[0] *= 4;
                    EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
                    sfx_explosion_air_small();
                }
            }
            reg_tmp.h[1] = BATTLESHIP(reg_a5)->hp[0];
            reg_tmp.h[0] = BATTLESHIP(reg_a5)->hp[1];
            if ((s32) reg_tmp.w < 0) {
                reg_d0.w = 0x174;
                score_add();
                reg_a1 = (u8 *)((u16 *)D_00257D20);
loop_19:
                temp_a0 = *(u16 *)reg_a1;
                reg_d1.h[0] = temp_a0;
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
                    reg_a1 += 2;
                    EXPLOSION(reg_a0)->y = ENTITY(reg_a6)->y.h;
                    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
                    EXPLOSION(reg_a0)->draw_layer = 0x10;
                    EXPLOSION(reg_a0)->debris = 0;
                    EXPLOSION(reg_a0)->debris_arg = 0;
                    EXPLOSION(reg_a0)->move.b.speed = (u8) ENTITY(reg_a6)->move.b.speed;
                    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
                    reg_d0.b[0] *= 4;
                    EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
                    reg_a1 += 2;
                    goto loop_19;
                }
                sfx_explosion_ground_large();
                battleship_part_6_update();
                if (ENTITY(reg_a6)[6].hp.b[0] != 0) {
                    g_enemy_signal_e = 0;
                }
                g_enemy_signal_f = 0;
                g_enemy_signal_d = 0;
                ENTITY(reg_a6)->flags.h = 0x8000;
                ENTITY(reg_a6)[1].flags.h = 0x8000;
                ENTITY(reg_a6)[6].move.b.speed = 1U;
                goto block_24;
            }
        } else {
block_24:
            ENTITY(reg_a6)->attr.b.palette = (u8) BATTLESHIP(reg_a5)->palette;
            ENTITY(reg_a6)[2].attr.b.palette = (u8) ENTITY(reg_a6)[2].attr.b.flip;
            ENTITY(reg_a6)[3].attr.b.palette = (u8) ENTITY(reg_a6)[3].attr.b.flip;
            ENTITY(reg_a6)[4].attr.b.palette = (u8) ENTITY(reg_a6)[4].attr.b.flip;
            ENTITY(reg_a6)[5].attr.b.palette = (u8) ENTITY(reg_a6)[5].attr.b.flip;
        }
        if (ENTITY(reg_a6)[6].move.b.speed != 0) {
            ENTITY(reg_a6)[6].move.b.dir -= 1;
            if (ENTITY(reg_a6)[6].move.b.dir == 0) {
                enemy_remove();
                return;
            }
        }
        reg_d0.h[1] = BATTLESHIP(reg_a5)->hp[0];
        reg_d0.h[0] = BATTLESHIP(reg_a5)->hp[1];
        enemy_anims_spawn_listed_long();
        if (g_enemies_stopped == 0) {
            reg_d0.h[0] = ENTITY(reg_a6)[2].y.h;
            reg_d1.h[0] = ENTITY(reg_a6)[2].x.h;
            aim_at_player();
            if (cond_flag == 0) {
                reg_d0.b[0] = ENTITY(reg_a6)[2].move.b.dir;
                direction_turn_toward();
                ENTITY(reg_a6)[2].move.b.dir = (u8) reg_d1.b[0];
                reg_d0.h[0] = ENTITY(reg_a6)[3].y.h;
                reg_d1.h[0] = ENTITY(reg_a6)[3].x.h;
                aim_at_player();
                reg_d0.b[0] = ENTITY(reg_a6)[3].move.b.dir;
                direction_turn_toward();
                ENTITY(reg_a6)[3].move.b.dir = (u8) reg_d1.b[0];
                reg_tmp.b[0] = ENTITY(reg_a6)[6].offset_y.b[1];
                ENTITY(reg_a6)[6].offset_y.b[1] -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    reg_d0.h[0] = 0x20;
                    reg_d0.h[0] -= g_rank_1_16;
                    ENTITY(reg_a6)[6].offset_y.b[1] = (u8) reg_d0.b[0];
                    if ((s16) ENTITY(reg_a6)[3].y.h > 0x1800) {
                        if ((ENTITY(reg_a6)[2].misc.b.draw_layer == 0) && (g_bullets_blocked == 0)) {
                            reg_d3.w = 0;
                            reg_a4 = g_direction_offsets_500;
                            reg_d3.b[0] = ENTITY(reg_a6)[2].move.b.dir;
                            reg_d3.b[0] += 1;
                            reg_d3.h[0] &= 0x3E;
                            reg_d3.h[0] += reg_d3.h[0];
                            reg_a4 += reg_d3.h[0];
                            reg_d5.h[1] = *(u16 *)reg_a4;
                            reg_d5.h[0] = *(u16 *)(reg_a4 + 2);
                            reg_d1.w = 0;
                            reg_d1.b[0] = ENTITY(reg_a6)[2].move.b.dir;
                            reg_d2.h[1] = ENTITY(reg_a6)[2].y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)[2].x.h;
                            reg_a0 = reg_a6 + 0x40;
                            battleship_shot_random();
                        }
                        if ((ENTITY(reg_a6)[3].misc.b.draw_layer == 0) && (g_bullets_blocked == 0)) {
                            reg_d3.w = 0;
                            reg_a4 = g_direction_offsets_500;
                            reg_d3.b[0] = ENTITY(reg_a6)[3].move.b.dir;
                            reg_d3.b[0] += 1;
                            reg_d3.h[0] &= 0x3E;
                            reg_d3.h[0] += reg_d3.h[0];
                            reg_a4 += reg_d3.h[0];
                            reg_d5.h[1] = *(u16 *)reg_a4;
                            reg_d5.h[0] = *(u16 *)(reg_a4 + 2);
                            reg_d1.w = 0;
                            reg_d1.b[0] = ENTITY(reg_a6)[3].move.b.dir;
                            reg_d2.h[1] = ENTITY(reg_a6)[3].y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)[3].x.h;
                            reg_a0 = reg_a6 + 0x60;
                            battleship_shot_random();
                        }
                    }
                }
                if (ENTITY(reg_a6)[4].misc.b.draw_layer == 0) {
                    reg_d0.h[0] = ENTITY(reg_a6)[4].y.h;
                    reg_d1.h[0] = ENTITY(reg_a6)[4].x.h;
                    aim_at_player();
                    reg_d0.b[0] = ENTITY(reg_a6)[4].move.b.dir;
                    direction_turn_toward();
                    ENTITY(reg_a6)[4].move.b.dir = (u8) reg_d1.b[0];
                    reg_tmp.b[0] = ENTITY(reg_a6)[6].offset_x.b[1];
                    ENTITY(reg_a6)[6].offset_x.b[1] -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        reg_d0.h[0] = 0x30;
                        reg_d0.h[0] -= g_rank_2_16;
                        ENTITY(reg_a6)[6].offset_x.b[1] = (u8) reg_d0.b[0];
                        if (((s16) ENTITY(reg_a6)[4].y.h > 0x1800) && (g_bullets_blocked == 0)) {
                            reg_d3.w = 0;
                            reg_a4 = g_direction_twin_offsets_400;
                            reg_d3.b[0] = ENTITY(reg_a6)[4].move.b.dir;
                            reg_d1.w = 0;
                            reg_d3.h[0] &= 0x3E;
                            reg_d3.h[0] *= 4;
                            reg_a4 += reg_d3.h[0];
                            reg_d1.b[0] = ENTITY(reg_a6)[4].move.b.dir;
                            reg_d1.b[0] += 1;
                            reg_d1.b[0] &= 0x3E;
                            reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
                            reg_d3.h[1] = *(u16 *)reg_a4;
                            reg_d3.h[0] = *(u16 *)(reg_a4 + 2);
                            reg_a0 = reg_a6 + 0x80;
                            reg_d0.w = 0x60004;
                            reg_d4.w = 0;
                            bullet_fire_2way();
                            reg_d0.w = 0x20004;
                            bullet_fire_2way();
                            reg_d1.b[0] += 2;
                            reg_d0.w = 0x60004;
                            bullet_fire_2way();
                            reg_d0.w = 0x20004;
                            bullet_fire_2way();
                            reg_d1.b[0] -= 4;
                            reg_d0.w = 0x60004;
                            bullet_fire_2way();
                            reg_d0.w = 0x20004;
                            bullet_fire_2way();
                        }
                    }
                }
                if (ENTITY(reg_a6)[5].misc.b.draw_layer == 0) {
                    if (ENTITY(reg_a6)[6].look.b.size == 0) {
                        reg_d0.h[0] = ENTITY(reg_a6)[5].y.h;
                        reg_d1.h[0] = ENTITY(reg_a6)[5].x.h;
                        aim_at_player();
                        reg_d0.b[0] = ENTITY(reg_a6)[5].move.b.dir;
                        direction_turn_toward();
                        ENTITY(reg_a6)[5].move.b.dir = (u8) reg_d1.b[0];
                        ENTITY(reg_a6)[6].draw.b.priority -= 1;
                        if (ENTITY(reg_a6)[6].draw.b.priority == 0) {
                            ENTITY(reg_a6)[6].draw.b.priority = (u8) ENTITY(reg_a6)[6].draw.b.flip;
                            ENTITY(reg_a6)[6].look.b.size = (u8) ENTITY(reg_a6)[6].look.b.palette;
                            goto block_47;
                        }
                    } else {
block_47:
                        reg_tmp.b[0] = ENTITY(reg_a6)[6].sprite.b[1];
                        ENTITY(reg_a6)[6].sprite.b[1] -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            reg_d0.h[0] = 8;
                            reg_d1.h[0] = g_rank_1_16;
                            reg_d1.h[0] >>= 3;
                            reg_d0.h[0] -= reg_d1.h[0];
                            ENTITY(reg_a6)[6].sprite.b[1] = (u8) reg_d0.b[0];
                            if (((s16) ENTITY(reg_a6)[5].y.h > 0x1800) && (g_bullets_blocked == 0)) {
                                reg_d3.w = 0;
                                reg_a4 = g_direction_twin_offsets_400;
                                reg_d3.b[0] = ENTITY(reg_a6)[5].move.b.dir;
                                reg_d1.w = 0;
                                reg_d3.b[0] += 1;
                                reg_d3.h[0] &= 0x3E;
                                reg_d3.h[0] *= 4;
                                reg_a4 += reg_d3.h[0];
                                reg_d0.w = 0x10005;
                                reg_d1.b[0] = ENTITY(reg_a6)[5].move.b.dir;
                                reg_d1.b[0] += 1;
                                reg_d1.b[0] &= 0x3E;
                                reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
                                reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
                                reg_d3.h[1] = *(u16 *)reg_a4;
                                reg_d3.h[0] = *(u16 *)(reg_a4 + 2);
                                reg_a0 = reg_a6 + 0xA0;
                                reg_d4.w = 0;
                                bullet_fire_fast();
                                reg_d3.h[1] = *(u16 *)(reg_a4 + 4);
                                reg_d3.h[0] = *(u16 *)(reg_a4 + 6);
                                bullet_fire_fast();
                                ENTITY(reg_a6)[6].look.b.size -= 1;
                            }
                        }
                    }
                }
                reg_d0.b[0] = ENTITY(reg_a6)[5].misc.b.draw_layer;
                reg_d0.b[0] += ENTITY(reg_a6)[4].misc.b.draw_layer;
                reg_d0.b[0] += ENTITY(reg_a6)[3].misc.b.draw_layer;
                reg_d0.b[0] += ENTITY(reg_a6)[2].misc.b.draw_layer;
                if (reg_d0.b[0] == 4) {
                    ENTITY(reg_a6)[6].hit_x_minus.sb[0] = 1;
                    if (ENTITY(reg_a6)[6].hit_x_plus.b[1] == 0) {
                        reg_tmp.b[0] = ENTITY(reg_a6)[6].hit_y_plus.b[1];
                        ENTITY(reg_a6)[6].hit_y_plus.b[1] -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            ENTITY(reg_a6)[6].hit_y_plus.b[1] = (u8) ENTITY(reg_a6)[6].hit_y_plus.b[0];
                            ENTITY(reg_a6)[6].hit_x_plus.b[1] = (u8) ENTITY(reg_a6)[6].hit_x_plus.b[0];
                            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d0.h[0] += 0x400;
                            aim_at_player();
                            if (cond_flag == 0) {
                                ENTITY(reg_a6)[6].hit_x_minus.b[1] = (u8) reg_d1.b[0];
                            }
                            goto block_56;
                        }
                    } else {
block_56:
                        reg_tmp.b[0] = ENTITY(reg_a6)[6].hit_y_minus.b[1];
                        ENTITY(reg_a6)[6].hit_y_minus.b[1] -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            reg_d0.h[0] = 0x10;
                            reg_d1.h[0] = g_rank_1_16;
                            reg_d1.h[0] >>= 2;
                            reg_d0.h[0] -= reg_d1.h[0];
                            ENTITY(reg_a6)[6].hit_y_minus.b[1] = (u8) reg_d0.b[0];
                            temp_a3 = reg_a6 + 2;
                            if ((ENTITY(reg_a6)->y.sh > 0x1800) && (g_bullets_blocked == 0)) {
                                reg_d1.w = 0;
                                reg_d1.b[0] = ENTITY(reg_a6)[6].hit_x_minus.b[1];
                                reg_d0.w = 0x20004;
                                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                temp_a1_2 = ENTITY(reg_a6)->x.h;
                                reg_d2.h[0] = temp_a1_2;
                                reg_d5.w = 0x04000000;
                                reg_a0 = (u8 *)g_direction64_offsets_2CC;
                                reg_d4.w = 0;
                                reg_d7.b[0] = reg_d1.b[0];
                                if (!(ENTITY(reg_a6)[6].hit_x_plus.b[1] & 1)) {
                                    ENTITY(reg_a6)[6].hp.sb[1] = 1;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    bullet_fire();
                                    reg_d1.b[0] += 4;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    bullet_fire();
                                    reg_d1.b[0] += 4;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    bullet_fire();
                                    reg_d1.b[0] = reg_d7.b[0];
                                    reg_d1.b[0] -= 4;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    bullet_fire();
                                    reg_d1.b[0] -= 4;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    bullet_fire();
                                } else {
                                    reg_d1.b[0] += 2;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    bullet_fire();
                                    reg_d1.b[0] += 4;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    bullet_fire();
                                    reg_d1.b[0] = reg_d7.b[0];
                                    reg_d1.b[0] -= 2;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    bullet_fire();
                                    reg_d1.b[0] -= 4;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    bullet_fire();
                                }
                                ENTITY(reg_a6)[6].hit_x_plus.b[1] -= 1;
                            }
                        }
                    }
                }
            }
        }
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.w += 0xDC00F600;
        reg_d3.h[0] = 0x2450;
        reg_d2.w = 0x18C9;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
        sprite_draw_layer4_keep();
        battleship_turret_2_draw();
        battleship_turret_3_draw();
        battleship_turret_5_draw();
        battleship_turret_4_draw();
        reg_a0 = reg_a6;
        enemy_hitbox_debug_draw();
        reg_a0 = reg_a6 + 0x20;
        enemy_hitbox_debug_draw();
    }
}

extern u16 g_direction_sprites_d[];

void battleship_turret_2_draw(void) {
    u16 temp_a1;
    if (ENTITY(reg_a6)[2].misc.b.draw_layer == 0) {
        reg_d2.w = 0;
        reg_a0 = (u8 *)(g_direction_sprites_d);
        reg_d2.b[0] = ENTITY(reg_a6)[2].move.b.dir;
        reg_d2.b[0] += 1;
        reg_d2.h[0] &= 0x3E;
        reg_d2.h[0] += reg_d2.h[0];
        reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d1.h[1] = ENTITY(reg_a6)[2].y.h;
        temp_a1 = ENTITY(reg_a6)[2].x.h;
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)[2].attr.b.palette;
        sprite_draw_layer4_keep();
    }
}

void battleship_turret_3_draw(void) {
    u16 temp_a1;
    if (ENTITY(reg_a6)[3].misc.b.draw_layer == 0) {
        reg_d2.w = 0;
        reg_a0 = (u8 *)(g_direction_sprites_d);
        reg_d2.b[0] = ENTITY(reg_a6)[3].move.b.dir;
        reg_d2.b[0] += 1;
        reg_d2.h[0] &= 0x3E;
        reg_d2.h[0] += reg_d2.h[0];
        reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d1.h[1] = ENTITY(reg_a6)[3].y.h;
        temp_a1 = ENTITY(reg_a6)[3].x.h;
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)[3].attr.b.palette;
        sprite_draw_layer4_keep();
    }
}

extern u16 g_direction_sprites_b[];

void battleship_turret_4_draw(void) {
    u16 temp_a1;
    if (ENTITY(reg_a6)[4].misc.b.draw_layer == 0) {
        reg_d2.w = 0;
        reg_a0 = (u8 *)(g_direction_sprites_b);
        reg_d2.b[0] = ENTITY(reg_a6)[4].move.b.dir;
        reg_d2.b[0] += 1;
        reg_d2.h[0] &= 0x3E;
        reg_d2.h[0] += reg_d2.h[0];
        reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d1.h[1] = ENTITY(reg_a6)[4].y.h;
        temp_a1 = ENTITY(reg_a6)[4].x.h;
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)[4].attr.b.palette;
        sprite_draw_layer4_keep();
    }
}

void battleship_turret_5_draw(void) {
    u16 temp_a1;
    if (ENTITY(reg_a6)[5].misc.b.draw_layer == 0) {
        reg_d2.w = 0;
        reg_a0 = (u8 *)(g_direction_sprites_b);
        reg_d2.b[0] = ENTITY(reg_a6)[5].move.b.dir;
        reg_d2.b[0] += 1;
        reg_d2.h[0] &= 0x3E;
        reg_d2.h[0] += reg_d2.h[0];
        reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d1.h[1] = ENTITY(reg_a6)[5].y.h;
        temp_a1 = ENTITY(reg_a6)[5].x.h;
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)[5].attr.b.palette;
        sprite_draw_layer4_keep();
    }
}

extern u16 g_direction64_offsets_432[];

void battleship_part_6_update(void) {
    u16 temp_a0;
    if (ENTITY(reg_a6)[6].hp.b[1] == 0) {
        temp_a0 = ENTITY(reg_a6)->y.h;
        if ((s16)(temp_a0) > 0x1000) {
            reg_d0.h[0] = temp_a0;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.h[0] += 0x400;
            aim_at_player();
            if (cond_flag == 0) {
                reg_d0.w = 0x40004;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d5.w = 0x04000000;
                reg_d4.w = 0;
                reg_d7.b[0] = reg_d1.b[0];
                reg_a0 = (u8 *)(g_direction64_offsets_432);
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                bullet_fire_2way();
                reg_d1.b[0] += 2;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                bullet_fire_2way();
                reg_d1.b[0] += 2;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                bullet_fire_2way();
                reg_d1.b[0] += 2;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                bullet_fire_2way();
                reg_d1.b[0] = reg_d7.b[0];
                reg_d1.b[0] -= 2;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                bullet_fire_2way();
                reg_d1.b[0] -= 2;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                bullet_fire_2way();
                reg_d1.b[0] -= 2;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                bullet_fire_2way();
            }
        }
    }
}

void stage3_gun_a_first(void) {
    enemy_set_entity_count(0);
}

extern u32 D_00257D70[];
extern u32 D_00257D90[];

void stage3_gun_a_start(void)
{
#ifndef DDPDOJ_PC
    extern void enemy_set_task_state(void);
    extern void enemy_init_entities(void);
    extern void enemy_path_start(void);
#endif
    reg_a0 = (u8 *)D_00257D90;
    enemy_init_entities();

    reg_a0 = (u8 *)D_00257D70;
    reg_d0.w = 0xD;
    enemy_set_task_state();
    enemy_path_start();

    if (enemy_move_end_requested == 0) {
        ENTITY(reg_a6)->x.h -= 0x280;
        ENTITY(reg_a6)->y.h -= 0x80;
    }
}

#ifndef DDPDOJ_PC
s32 bullet_fire256_fixed();
#endif
s32 bullet_fire256_2way();
s32 sfx_explosion_ground_medium();
s32 entity_follow_scroll();
s32 entity_in_shot_limits_y();
s32 wreck_spawn_b();
extern u8 D_00257FB0[];
extern u8 D_00258030[];

void stage3_gun_a(void) {
#ifndef DDPDOJ_PC
    s32 enemy_remove();
    s32 sprite_draw_layer3_keep();
#endif
    u32 temp_a0;
    u32 temp_a0_3;
    u32 temp_a1;
    u32 temp_a0_2;
    u32 temp_a0_4;
    u32 temp_a0_5;

    if (ENTITY(reg_a6)->y.sh < -0x1800) {
        if (STAGE3_GUN(reg_a5)->seen != 0) {
            enemy_remove();
            return;
        }
        goto block_4;
    }
    STAGE3_GUN(reg_a5)->seen = 1U;
block_4:
    entity_follow_scroll();
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = STAGE3_GUN(reg_a5)->palette_now;
        reg_d2.b[0] = STAGE3_GUN(reg_a5)->hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        STAGE3_GUN(reg_a5)->palette_now = (u8) reg_d0.b[0];
        if (ENTITY(reg_a6)->hp.sh < 0) {
            reg_d0.w = 0x47;
            score_add();
            ENTITY(reg_a6)->flags.h = 0x8000;
            STAGE3_GUN(reg_a5)->destroyed = 1U;
            reg_a1 = (u8 *)D_00258030;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_tmp.h[1] = ENTITY(reg_a6)->offset_y.h;
            temp_a0 = ENTITY(reg_a6)->offset_x.h;
            reg_tmp.h[0] = temp_a0;
            reg_d3.h[0] = 0xC;
            reg_d2.w += reg_tmp.w;
            enemy_explode_by_table();
            reg_d0.w = 4;
            reg_d1.h[0] = 0xC;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            temp_a0_2 = reg_d2.w;
            reg_tmp.h[1] = ENTITY(reg_a6)->offset_y.h;
            reg_tmp.h[0] = ENTITY(reg_a6)->offset_x.h;
            reg_d2.w = temp_a0_2 + reg_tmp.w;
            reg_d2.w += 0xFC000000;
            wreck_spawn_b();
            sfx_explosion_ground_medium();
            goto block_7;
        }
    } else {
block_7:
        STAGE3_GUN(reg_a5)->palette_now = (u8) STAGE3_GUN(reg_a5)->palette;
    }
    if (STAGE3_GUN(reg_a5)->destroyed == 0) {
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        temp_a0_3 = reg_d0.h[0];
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] = temp_a0_3 + *(u32 *)(reg_a6 + 6);
        reg_d1.h[0] += ENTITY(reg_a6)->offset_x.h;
        aim_at_player();
        if (cond_flag == 0) {
            reg_d0.b[0] = STAGE3_GUN(reg_a5)->dir;
            direction_turn_toward();
            STAGE3_GUN(reg_a5)->dir = (u8) reg_d1.b[0];
            if (STAGE3_GUN(reg_a5)->shots_left == 0) {
                reg_tmp.b[0] = STAGE3_GUN(reg_a5)->pause_countdown;
                STAGE3_GUN(reg_a5)->pause_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    reg_d0.h[0] = 0x18;
                    reg_d0.h[0] -= g_rank_1_16;
                    STAGE3_GUN(reg_a5)->pause_countdown = (u8) reg_d0.b[0];
                    reg_d0.h[0] = 4;
                    reg_d1.h[0] = g_rank_1_16;
                    reg_d1.h[0] >>= 3;
                    reg_d0.h[0] -= reg_d1.h[0];
                    STAGE3_GUN(reg_a5)->shots_left = (u8) reg_d0.b[0];
                    STAGE3_GUN(reg_a5)->fire_dir = (u8) STAGE3_GUN(reg_a5)->dir;
                    goto block_13;
                }
            } else {
block_13:
                reg_tmp.b[0] = STAGE3_GUN(reg_a5)->shot_countdown;
                STAGE3_GUN(reg_a5)->shot_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    STAGE3_GUN(reg_a5)->shot_countdown = (u8) STAGE3_GUN(reg_a5)->shot_interval;
                    entity_in_shot_limits_y();
                    if (cond_flag == 0) {
                        reg_d3.w = 0;
                        reg_a4 = (u8 *)D_00257FB0;
                        reg_d3.b[0] = STAGE3_GUN(reg_a5)->dir;
                        reg_d3.b[0] += 1;
                        reg_d3.h[0] &= 0x3E;
                        reg_d3.h[0] += reg_d3.h[0];
                        reg_a4 += reg_d3.h[0];
                        reg_d3.h[1] = *(u16 *)reg_a4;
                        reg_d3.h[0] = *(u16 *)(reg_a4 + 2);
                        temp_a0_4 = reg_d3.w;
                        reg_tmp.h[1] = ENTITY(reg_a6)->offset_y.h;
                        temp_a1 = ENTITY(reg_a6)->offset_x.h;
                        reg_tmp.h[0] = temp_a1;
                        reg_d0.w = 0xA0016;
                        reg_d1.w = 0;
                        reg_d3.w = temp_a0_4 + reg_tmp.w;
                        reg_d1.b[0] = STAGE3_GUN(reg_a5)->dir;
                        reg_d1.b[0] += 1;
                        reg_d1.h[0] &= 0x3E;
                        reg_d1.h[0] *= 4;
                        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d4.w = 0;
                        bullet_fire256_fixed();
                        reg_d1.b[0] += 2;
                        bullet_fire256_2way();
                        reg_d1.b[0] -= 4;
                        bullet_fire256_2way();
                        STAGE3_GUN(reg_a5)->shots_left -= 1;
                    }
                }
            }
        }
    }
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    temp_a0_5 = reg_d1.w;
    reg_tmp.h[1] = STAGE3_GUN(reg_a5)->draw_at[0];
    reg_tmp.h[0] = STAGE3_GUN(reg_a5)->draw_at[1];
    reg_d1.w = temp_a0_5 + reg_tmp.w;
    reg_d3.h[0] = STAGE3_GUN(reg_a5)->size;
    reg_d2.h[1] = STAGE3_GUN(reg_a5)->sprite[0];
    reg_d2.h[0] = STAGE3_GUN(reg_a5)->sprite[1];
    reg_d4.w = 0;
    reg_d4.h[0] = 0x15;
    sprite_draw_layer3_keep();
    stage3_gun_draw_barrel();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

s32 sprite_draw_layer5_keep();
extern u16 D_00257DB0[];

void stage3_gun_draw_barrel(void) {
    u16 temp_a2;
    u32 temp_a1;

    if (STAGE3_GUN(reg_a5)->destroyed == 0) {
        STAGE3_GUN(reg_a5)->frame += 4;
        STAGE3_GUN(reg_a5)->frame &= 0xF;
        reg_a0 = (u8 *)(D_00257DB0);
        reg_d2.w = 0;
        reg_d2.b[0] = STAGE3_GUN(reg_a5)->dir;
        reg_d2.b[0] += 1;
        reg_d2.h[0] &= 0x3E;
        reg_d2.h[0] *= 4;
        reg_d2.h[0] += reg_d2.h[0];
        reg_d2.h[0] += STAGE3_GUN(reg_a5)->frame;
        reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        temp_a1 = reg_d1.w;
        reg_tmp.h[1] = ENTITY(reg_a6)->offset_y.h;
        temp_a2 = ENTITY(reg_a6)->offset_x.h;
        reg_tmp.h[0] = temp_a2;
        reg_d4.w = 0;
        reg_d1.w = temp_a1 + reg_tmp.w;
        reg_d1.w += 0xF400F600;
        reg_d3.h[0] = 0xC50;
        reg_d4.b[0] = STAGE3_GUN(reg_a5)->palette_now;
        sprite_draw_layer5_keep();
    }
}

void enemy_set_entity_count(s32);

void stage3_gun_b_first(void) {
    enemy_set_entity_count(0);
}

extern u8 D_00258040[];
extern u8 D_00258060[];

void stage3_gun_b_start(void)
{
#ifndef DDPDOJ_PC
    extern void enemy_set_task_state(void);
    extern void enemy_init_entities(void);
    extern void enemy_path_start(void);
#endif
    reg_a0 = D_00258060;
    enemy_init_entities();

    reg_a0 = D_00258040;
    reg_d0.w = 0xD;
    enemy_set_task_state();
    enemy_path_start();

    if (enemy_move_end_requested == 0) {
        ((u16 *)reg_a6)[1] -= 0x180;
    }
}

void stage3_gun_c_first(void) {
    enemy_set_entity_count(0);
}

extern u8 D_00258080[];
extern u8 D_002580A0[];


void stage3_gun_c_start(void)
{
#ifndef DDPDOJ_PC
    extern void enemy_set_task_state(void);
    extern void enemy_init_entities(void);
    extern void enemy_path_start(void);
#endif
    reg_a0 = D_002580A0;
    enemy_init_entities();

    reg_a0 = D_00258080;
    reg_d0.w = 0xD;
    enemy_set_task_state();
    enemy_path_start();

    if (enemy_move_end_requested == 0) {
        ((u16 *)reg_a6)[1] -= 0x400;
    }
}

void stage3_gun_d_first(void) {
    enemy_set_entity_count(0);
}

extern u8 D_002580C0[];
extern u8 D_002580E0[];

void stage3_gun_d_start(void)
{
#ifndef DDPDOJ_PC
    extern void enemy_set_task_state(void);
    extern void enemy_init_entities(void);
    extern void enemy_path_start(void);
#endif
    reg_a0 = D_002580E0;
    enemy_init_entities();

    reg_a0 = D_002580C0;
    reg_d0.w = 0xD;
    enemy_set_task_state();
    enemy_path_start();

    if (enemy_move_end_requested == 0) {
        ENTITY(reg_a6)->x.h -= 0x400;
        ENTITY(reg_a6)->y.h -= 0x600;
    }
}

extern u16 g_loop;

void second_loop_speed_bonus_get(void) {
    reg_d6.sw = 0;
    if (g_loop != 0) {
        reg_d6.sw = 0x20000;
    }
}

void stage3_large_gun_first(void) {
    enemy_set_entity_count(0);
}

s32 rng_next_unsigned();
extern u8 D_00258100[];
extern u8 D_00258130[];
extern u16 g_enemy_signal_2;
extern u16 g_enemy_signal_1;
extern u16 g_enemy_signal_0;
extern s16 g_bullet_limit_raised_1[];

void stage3_large_gun_start(void) {
#ifndef DDPDOJ_PC
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
#endif
    reg_a0 = D_00258130;
    enemy_init_entities();
    reg_a0 = D_00258100;
    reg_d0.w = 0x14;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        g_bullet_limit_raised_1[0] = 1;
        reg_d0.h[0] = g_scroll_line;
        STAGE3_LARGE_GUN(reg_a5)->start_line = (u16) reg_d0.h[0];
        if (reg_d0.h[0] == 0x48) {
            g_enemy_signal_0 = 1;
            g_enemy_signal_1 = 1;
            g_enemy_signal_2 = 1;
            ENTITY(reg_a6)->y.h += 0x900;
            ENTITY(reg_a6)->x.h -= 0x100;
        }
        if (reg_d0.h[0] == 0x8D) {
            g_enemy_signal_1 = 1;
            ENTITY(reg_a6)->y.h += 0x900;
            ENTITY(reg_a6)->x.h -= 0x100;
        }
        if (reg_d0.h[0] == 0xAC) {
            g_enemy_signal_2 = 1;
            ENTITY(reg_a6)->y.h += 0x900;
            ENTITY(reg_a6)->x.h -= 0x100;
        }
        STAGE3_LARGE_GUN(reg_a5)->spin = 0xFE;
        rng_next_unsigned();
        if ((s8) reg_d0.b[0] < 0) {
            STAGE3_LARGE_GUN(reg_a5)->spin = 2;
        }
    }
}

void stage3_large_gun_clear_signal(void) {
    reg_d0.h[0] = STAGE3_LARGE_GUN(reg_a5)->start_line;
    if (reg_d0.h[0] == 0x48) {
        g_enemy_signal_0 = 0;
    }
    if (reg_d0.h[0] == 0x8D) {
        g_enemy_signal_1 = 0;
    }
    if (reg_d0.h[0] == 0xAC) {
        g_enemy_signal_2 = 0;
    }
}

s32 velocity_from_dir256();
extern u8 D_00258150[];
extern u8 D_00258190[];
extern u8 D_002581D0[];
extern u16 g_rank;
extern u16 g_bomb_entities[];

void stage3_large_gun(void) {
#ifndef DDPDOJ_PC
    s32 enemy_remove();
    s32 sprite_draw_layer3_keep();
#endif
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_5;
    u16 temp_a0_6;
    u32 temp_a0_7;
    u32 temp_a0_8;
    u32 temp_a0_9;

    if (ENTITY(reg_a6)->y.sh < -0x2200) {
        if (STAGE3_LARGE_GUN(reg_a5)->seen != 0) {
            stage3_large_gun_clear_signal();
            enemy_remove();
            return;
        }
        goto block_4;
    }
    STAGE3_LARGE_GUN(reg_a5)->seen = 1U;
block_4:
    entity_follow_scroll();
    if ((s16) STAGE3_LARGE_GUN(reg_a5)->hp >= 0) {
        ENTITY(reg_a6)->hp.sh = 0x7FFF;
        reg_d0.h[0] = 1;
        if (g_bomb_entities[0] != 0) {
            reg_d0.h[0] = 2;
        }
        reg_tmp.h[0] = STAGE3_LARGE_GUN(reg_a5)->hp;
        STAGE3_LARGE_GUN(reg_a5)->hp -= reg_d0.h[0];
        if ((s32) reg_tmp.h[0] < (s32) reg_d0.h[0]) {
            ENTITY(reg_a6)->hp.sh = 0x1C00;
        }
    }
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = STAGE3_LARGE_GUN(reg_a5)->palette_now;
        reg_d2.b[0] = STAGE3_LARGE_GUN(reg_a5)->hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        STAGE3_LARGE_GUN(reg_a5)->palette_now = (u8) reg_d0.b[0];
        if (ENTITY(reg_a6)->hp.sh < 0) {
            reg_d0.w = 0x632;
            score_add();
            stage3_large_gun_clear_signal();
            reg_a1 = (u8 *)D_002581D0;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d3.h[0] = 0xC;
            enemy_explode_by_table();
            sfx_explosion_ground_large();
            enemy_remove();
            return;
        }
        goto block_13;
    }
    STAGE3_LARGE_GUN(reg_a5)->palette_now = (u8) STAGE3_LARGE_GUN(reg_a5)->palette;
block_13:
    STAGE3_LARGE_GUN(reg_a5)->angle += 1;
    reg_d0.b[0] = STAGE3_LARGE_GUN(reg_a5)->spin;
    STAGE3_LARGE_GUN(reg_a5)->fire_dir += reg_d0.b[0];
    reg_d7.h[0] = 0x40;
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.b[0] = STAGE3_LARGE_GUN(reg_a5)->angle;
    velocity_from_dir256();
    temp_a0_2 = (s16) reg_d2.h[0] * 4;
    reg_d2.h[0] = temp_a0_2;
    reg_d3.h[0] = (s16) reg_d3.h[0] * 4;
    reg_d2.h[0] += 0x400;
    STAGE3_LARGE_GUN(reg_a5)->arm[0] = (u16) reg_d2.h[0];
    STAGE3_LARGE_GUN(reg_a5)->arm[1] = (u16) reg_d3.h[0];
    reg_d1.b[0] = STAGE3_LARGE_GUN(reg_a5)->angle;
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.b[0] += 0x40;
    reg_d1.h[0] = (u16) reg_d1.b[0];
    velocity_from_dir256();
    temp_a0_3 = (s16) reg_d2.h[0] * 4;
    reg_d2.h[0] = temp_a0_3;
    reg_d3.h[0] = (s16) reg_d3.h[0] * 4;
    reg_d2.h[0] += 0x400;
    STAGE3_LARGE_GUN(reg_a5)->arm[2] = (u16) reg_d2.h[0];
    STAGE3_LARGE_GUN(reg_a5)->arm[3] = (u16) reg_d3.h[0];
    reg_d1.b[0] = STAGE3_LARGE_GUN(reg_a5)->angle;
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.b[0] += 0x80;
    reg_d1.h[0] = (u16) reg_d1.b[0];
    velocity_from_dir256();
    temp_a0_4 = (s16) reg_d2.h[0] * 4;
    reg_d2.h[0] = temp_a0_4;
    reg_d3.h[0] = (s16) reg_d3.h[0] * 4;
    reg_d2.h[0] += 0x400;
    STAGE3_LARGE_GUN(reg_a5)->arm[4] = (u16) reg_d2.h[0];
    STAGE3_LARGE_GUN(reg_a5)->arm[5] = (u16) reg_d3.h[0];
    reg_d1.b[0] = STAGE3_LARGE_GUN(reg_a5)->angle;
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.b[0] += 0xC0;
    reg_d1.h[0] = (u16) reg_d1.b[0];
    velocity_from_dir256();
    reg_d2.h[0] = (s16) reg_d2.h[0] * 4;
    reg_d3.h[0] = (s16) reg_d3.h[0] * 4;
    reg_d2.h[0] += 0x400;
    STAGE3_LARGE_GUN(reg_a5)->arm[6] = (u16) reg_d2.h[0];
    STAGE3_LARGE_GUN(reg_a5)->arm[7] = (u16) reg_d3.h[0];
    if (STAGE3_LARGE_GUN(reg_a5)->shots_left == 0) {
        reg_tmp.b[0] = STAGE3_LARGE_GUN(reg_a5)->pause_countdown;
        STAGE3_LARGE_GUN(reg_a5)->pause_countdown -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            STAGE3_LARGE_GUN(reg_a5)->pause_countdown = (u8) STAGE3_LARGE_GUN(reg_a5)->pause;
            STAGE3_LARGE_GUN(reg_a5)->shots_left = (u8) STAGE3_LARGE_GUN(reg_a5)->shots;
            reg_d0.h[0] = 4;
            if ((s32) g_rank >= 0xC0) {
                reg_d0.h[0] = 3;
                if ((s32) g_rank >= 0xE0) {
                    reg_d0.h[0] = 2;
                }
            }
            STAGE3_LARGE_GUN(reg_a5)->shot_interval = (u8) reg_d0.b[0];
            goto block_19;
        }
    } else {
block_19:
        reg_tmp.b[0] = STAGE3_LARGE_GUN(reg_a5)->shot_countdown;
        STAGE3_LARGE_GUN(reg_a5)->shot_countdown -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            STAGE3_LARGE_GUN(reg_a5)->shot_countdown = (u8) STAGE3_LARGE_GUN(reg_a5)->shot_interval;
            if (ENTITY(reg_a6)->y.sh > 0x1800) {
                reg_d1.w = 0;
                reg_d1.b[0] = STAGE3_LARGE_GUN(reg_a5)->fire_dir;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d5.h[0] = 0x40;
                reg_d4.w = 0;
                if ((s8) STAGE3_LARGE_GUN(reg_a5)->spin < 0) {
                    reg_d5.h[0] *= 0xFFFF;
                }
                reg_d3.h[1] = STAGE3_LARGE_GUN(reg_a5)->arm[0];
                reg_d3.h[0] = STAGE3_LARGE_GUN(reg_a5)->arm[1];
                second_loop_speed_bonus_get();
                reg_d0.w = 0x20004;
                reg_d0.w += reg_d6.w;
                bullet_fire256_fixed();
                reg_d1.b[0] += reg_d5.b[0];
                second_loop_speed_bonus_get();
                reg_d0.w = 4;
                reg_d0.w += reg_d6.w;
                bullet_fire256_2way();
                reg_d3.h[1] = STAGE3_LARGE_GUN(reg_a5)->arm[2];
                reg_d3.h[0] = STAGE3_LARGE_GUN(reg_a5)->arm[3];
                second_loop_speed_bonus_get();
                reg_d0.w = 0x20004;
                reg_d0.w += reg_d6.w;
                bullet_fire256_fixed();
                reg_d1.b[0] += reg_d5.b[0];
                second_loop_speed_bonus_get();
                reg_d0.w = 4;
                reg_d0.w += reg_d6.w;
                bullet_fire256_2way();
                reg_d3.h[1] = STAGE3_LARGE_GUN(reg_a5)->arm[4];
                reg_d3.h[0] = STAGE3_LARGE_GUN(reg_a5)->arm[5];
                second_loop_speed_bonus_get();
                reg_d0.w = 0x20004;
                reg_d0.w += reg_d6.w;
                bullet_fire256_fixed();
                reg_d1.b[0] += reg_d5.b[0];
                second_loop_speed_bonus_get();
                reg_d0.w = 4;
                reg_d0.w += reg_d6.w;
                bullet_fire256_2way();
                reg_d3.h[1] = STAGE3_LARGE_GUN(reg_a5)->arm[6];
                reg_d3.h[0] = STAGE3_LARGE_GUN(reg_a5)->arm[7];
                second_loop_speed_bonus_get();
                reg_d0.w = 0x20004;
                reg_d0.w += reg_d6.w;
                bullet_fire256_fixed();
                reg_d1.b[0] += reg_d5.b[0];
                second_loop_speed_bonus_get();
                reg_d0.w = 4;
                reg_d0.w += reg_d6.w;
                bullet_fire256_2way();
                STAGE3_LARGE_GUN(reg_a5)->shots_left -= 1;
            }
        }
    }
    STAGE3_LARGE_GUN(reg_a5)->frame += 4;
    STAGE3_LARGE_GUN(reg_a5)->frame &= 0x3C;
    reg_a0 = (u8 *)D_00258150;
    reg_a0 += STAGE3_LARGE_GUN(reg_a5)->frame;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0_5 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0_5;
    reg_d1.w += 0xDE00EB00;
    reg_d3.h[0] = 0x22A8;
    reg_d4.w = 0;
    reg_d4.b[0] = STAGE3_LARGE_GUN(reg_a5)->palette_now;
    sprite_draw_layer3_keep();
    reg_a0 = (u8 *)D_00258190;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = STAGE3_LARGE_GUN(reg_a5)->arm[0];
    reg_d1.h[0] = STAGE3_LARGE_GUN(reg_a5)->arm[1];
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0_6 = ENTITY(reg_a6)->x.h;
    reg_tmp.h[0] = temp_a0_6;
    reg_d4.w = 0;
    reg_d1.w += reg_tmp.w;
    reg_d1.w += 0xFC00FD00;
    reg_d3.h[0] = 0x418;
    reg_d4.b[0] = STAGE3_LARGE_GUN(reg_a5)->palette_now;
    sprite_draw_layer4_keep();
    reg_d1.h[1] = STAGE3_LARGE_GUN(reg_a5)->arm[2];
    reg_d1.h[0] = STAGE3_LARGE_GUN(reg_a5)->arm[3];
    temp_a0_7 = reg_d1.w;
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w = temp_a0_7 + reg_tmp.w;
    reg_d1.w += 0xFC00FD00;
    sprite_draw_layer4_keep();
    reg_d1.h[1] = STAGE3_LARGE_GUN(reg_a5)->arm[4];
    reg_d1.h[0] = STAGE3_LARGE_GUN(reg_a5)->arm[5];
    temp_a0_8 = reg_d1.w;
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w = temp_a0_8 + reg_tmp.w;
    reg_d1.w += 0xFC00FD00;
    sprite_draw_layer4_keep();
    reg_d1.h[1] = STAGE3_LARGE_GUN(reg_a5)->arm[6];
    reg_d1.h[0] = STAGE3_LARGE_GUN(reg_a5)->arm[7];
    temp_a0_9 = reg_d1.w;
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w = temp_a0_9 + reg_tmp.w;
    reg_d1.w += 0xFC00FD00;
    sprite_draw_layer4_keep();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

#ifndef DDPDOJ_PC
s32 bullet_fire_fixed();
#endif
s32 rng_next_masked();

void ground_shot_random_a(void) {
    u8 var_a0;

    rng_next_masked();
    var_a0 = reg_d0.b[0];
    reg_d1.b[0] = var_a0;
    reg_d0.w = 0xFFFC0005;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d7.w = 0xF;
    reg_d3.w = 0;
    reg_d4.w = 0;
    do {
        bullet_fire_fixed();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

void ground_shot_random_b(void) {
    rng_next_masked();
    reg_d1.b[0] = reg_d0.b[0];
    reg_d0.w = 0x80004;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d7.w = 0xF;
    reg_d4.w = 0;
    reg_d3.w = 0;
    do {
        bullet_fire_fixed();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

void small_flyer_a_first(void) {
    enemy_set_entity_count(1);
}

extern u8 D_00258220[];
extern u8 D_00258240[];

void small_flyer_a_start(void) {
#ifndef DDPDOJ_PC
    s32 enemy_remove();
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
#endif
    reg_a0 = D_00258240;
    enemy_init_entities();
    reg_a0 = D_00258220;
    reg_d0.w = 9;
    enemy_set_task_state();
    enemy_path_start();
    if ((enemy_move_end_requested == 0) && ((s16)g_scroll_line > 0x10) && ((s16)g_scroll_line < 0x36) && (g_enemy_signal_d != 0)) {
        enemy_remove();
    }
}

s32 bullet_fire256_3way();
#ifndef DDPDOJ_PC
s32 bullet_fire256();
#endif
s32 sfx_explosion_ground_small();
#ifndef DDPDOJ_PC
s32 entity_velocity();
#endif
s32 entity_turn_to_target_player();
s32 entity_check_bounds();
extern u16 g_rank_3_16;
extern u16 g_stage;

void small_flyer_a(void) {
#ifndef DDPDOJ_PC
    s32 enemy_remove();
#endif
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a1;
    u16 temp_v1;

    entity_check_bounds();
    if (cond_flag != 0) {
        if (SMALL_FLYER(reg_a5)->seen != 0) {
            enemy_remove();
            return;
        }
        goto block_4;
    }
    SMALL_FLYER(reg_a5)->seen = 1U;
block_4:
    entity_velocity();
    temp_v1 = SMALL_FLYER(reg_a5)->turning_frames;
    if ((temp_v1 != 0) && (g_enemies_stopped == 0)) {
        SMALL_FLYER(reg_a5)->turning_frames = (u16) (temp_v1 - 1);
        reg_tmp.b[0] = SMALL_FLYER(reg_a5)->turn_countdown;
        SMALL_FLYER(reg_a5)->turn_countdown -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            SMALL_FLYER(reg_a5)->turn_countdown = (u8) SMALL_FLYER(reg_a5)->turn_interval;
            entity_turn_to_target_player();
        }
    }
    ENTITY(reg_a6)[1].y.h = (u16) ENTITY(reg_a6)->y.h;
    ENTITY(reg_a6)[1].x.h = (u16) ENTITY(reg_a6)->x.h;
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[1].flags.b[1];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = SMALL_FLYER(reg_a5)->palette;
        reg_d2.b[0] = SMALL_FLYER(reg_a5)->hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
        reg_d2.w = 0x7FFF;
        reg_d2.h[0] -= ENTITY(reg_a6)->hp.h;
        reg_d3.w = 0x7FFF;
        reg_d3.h[0] -= ENTITY(reg_a6)[1].hp.h;
        if ((s32) reg_d2.w < (s32) reg_d3.w) {
            reg_d2.w = reg_d3.w;
        }
        reg_tmp.h[1] = SMALL_FLYER(reg_a5)->hp[0];
        reg_tmp.h[0] = SMALL_FLYER(reg_a5)->hp[1];
        reg_tmp.w -= reg_d2.w;
        SMALL_FLYER(reg_a5)->hp[0] = (u16) reg_tmp.h[1];
        temp_a0 = reg_tmp.h[0];
        SMALL_FLYER(reg_a5)->hp[1] = temp_a0;
        reg_d0.h[0] = 0x7FFF;
        ENTITY(reg_a6)->hp.h = (u16) reg_d0.h[0];
        ENTITY(reg_a6)[1].hp.h = (u16) reg_d0.h[0];
        reg_tmp.h[1] = SMALL_FLYER(reg_a5)->hp[0];
        reg_tmp.h[0] = SMALL_FLYER(reg_a5)->hp[1];
        if ((s32) reg_tmp.w < 0) {
            reg_d0.w = 0x19;
            score_add();
            reg_d0.h[0] = 0x82;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            temp_a0_2 = ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->x = temp_a0_2;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0;
            EXPLOSION(reg_a0)->move.b.speed = (u8) ENTITY(reg_a6)->move.b.speed;
            reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d0.b[0] *= 4;
            EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
            sfx_explosion_ground_small();
            enemy_remove();
            return;
        }
        goto block_14;
    }
    ENTITY(reg_a6)->attr.b.palette = (u8) SMALL_FLYER(reg_a5)->palette;
block_14:
    reg_tmp.b[0] = SMALL_FLYER(reg_a5)->burst_countdown;
    SMALL_FLYER(reg_a5)->burst_countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        reg_d0.h[0] = 0x30;
        reg_d0.h[0] -= g_rank_3_16;
        reg_d0.h[0] += 0xA;
        SMALL_FLYER(reg_a5)->burst_countdown = (u8) reg_d0.b[0];
        SMALL_FLYER(reg_a5)->shots_left = (u8) SMALL_FLYER(reg_a5)->shots;
        SMALL_FLYER(reg_a5)->fire_dir = (u8) ENTITY(reg_a6)->move.b.dir;
        if ((s16) ENTITY(reg_a6)->y.h >= 0x2800) {
            reg_d1.w = 0;
            reg_d1.b[0] = SMALL_FLYER(reg_a5)->fire_dir;
            reg_d1.b[0] *= 4;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            temp_a1 = ENTITY(reg_a6)->x.h;
            reg_d2.h[0] = temp_a1;
            reg_a0 = (u8 *)g_direction64_offsets_432;
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] += 2;
            reg_d3.h[0] &= 0xFC;
            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            SMALL_FLYER(reg_a5)->shots_left -= 1;
            if (g_stage != 4) {
                reg_d0.w = 0x2000C;
                bullet_fire256_3way();
                reg_d1.b[0] += 8;
                bullet_fire256_fixed();
                reg_d1.b[0] -= 0x10;
                bullet_fire256_fixed();
            } else {
                reg_d0.w = 0x6000C;
                reg_d7.h[0] = reg_d1.h[0];
                bullet_fire256();
                reg_d1.b[0] += 8;
                bullet_fire256();
                reg_d1.b[0] -= 0x10;
                bullet_fire256();
                reg_d0.w = 0x4000D;
                reg_d1.h[0] = reg_d7.h[0];
                reg_d1.b[0] += 4;
                bullet_fire256();
                reg_d1.h[0] = reg_d7.h[0];
                reg_d1.b[0] -= 4;
                bullet_fire256();
            }
        }
    }
    small_flyer_draw();
}

#ifndef DDPDOJ_PC
s32 sprite_draw_layer5();
#endif
extern u16 D_00258280[];
extern u16 g_game_frame;

void small_flyer_draw(void) {
    u16 temp_a1;
    if (g_game_frame & 1) {
        SMALL_FLYER(reg_a5)->frame += 4;
        SMALL_FLYER(reg_a5)->frame &= 7;
    }
    reg_d0.w = 0;
    reg_a0 = (u8 *)(D_00258280);
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d0.b[0] += 1;
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] *= 4;
    reg_d0.h[0] += SMALL_FLYER(reg_a5)->frame;
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a1 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFA00FB00;
    reg_d3.h[0] = 0x628;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer5();
    reg_a0 = (u8 *)(reg_a6);
    enemy_hitbox_debug_draw();
}

void small_flyer_b_first(void) {
    enemy_set_entity_count(1);
}

s32 rng_next_word();
extern u8 D_00258380[];
extern u8 D_002583A0[];
extern u16 g_side_scroll_x[];

void small_flyer_b_start(void) {
#ifndef DDPDOJ_PC
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
#endif
    reg_a0 = D_002583A0;
    enemy_init_entities();
    reg_a0 = D_00258380;
    reg_d0.w = 9;
    enemy_set_task_state();
    if (g_stage == 4) {
        SMALL_FLYER(reg_a5)->palette = 0xF;
        SMALL_FLYER(reg_a5)->hit_palette = 0x10;
        reg_tmp.w = 0x74001C00;
        ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
        reg_d0.h[0] = g_side_scroll_x[0];
        ENTITY(reg_a6)->x.h -= reg_d0.h[0];
        goto block_3;
    }
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
block_3:
        rng_next_word();
        reg_d0.h[0] += 0x1C00;
        ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
        ENTITY(reg_a6)->move.sh = 0x2820;
    }
}

s32 bullet_fire_3way();

void small_flyer_b(void) {
#ifndef DDPDOJ_PC
    s32 enemy_remove();
#endif
    u16 temp_a0;
    u16 temp_v1;
    u8 temp_a0_2;
    u8 *var_a0;
    u8 *var_a1;

    entity_check_bounds();
    if (cond_flag != 0) {
        if (SMALL_FLYER(reg_a5)->seen != 0) {
            enemy_remove();
            return;
        }
        goto block_4;
    }
    SMALL_FLYER(reg_a5)->seen = 1U;
block_4:
    entity_velocity();
    temp_v1 = SMALL_FLYER(reg_a5)->turning_frames;
    if ((temp_v1 != 0) && (g_enemies_stopped == 0)) {
        SMALL_FLYER(reg_a5)->turning_frames = (u16) (temp_v1 - 1);
        reg_tmp.b[0] = SMALL_FLYER(reg_a5)->turn_countdown;
        SMALL_FLYER(reg_a5)->turn_countdown -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            SMALL_FLYER(reg_a5)->turn_countdown = (u8) SMALL_FLYER(reg_a5)->turn_interval;
            entity_turn_to_target_player();
        }
    }
    ENTITY(reg_a6)[1].y.h = (u16) ENTITY(reg_a6)->y.h;
    ENTITY(reg_a6)[1].x.h = (u16) ENTITY(reg_a6)->x.h;
    var_a0 = (u8 *)(reg_a6);
    reg_d1.b[0] = (*(u8 *)((u8 *)(var_a0) + (1)));
    reg_d1.b[0] |= (*(u8 *)((u8 *)(var_a0) + (0x21)));
    reg_d1.h[0] &= 0x5C;
    var_a1 = (u8 *)(var_a0 + 1);
    if (reg_d1.h[0] != 0) {
        reg_d0.b[0] = 0xA3;
        (*(u8 *)((u8 *)(var_a0) + (1))) &= reg_d0.b[0];
        ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = SMALL_FLYER(reg_a5)->palette;
        reg_d2.b[0] = SMALL_FLYER(reg_a5)->hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
        reg_d2.w = 0x7FFF;
        reg_d2.h[0] -= ENTITY(reg_a6)->hp.h;
        reg_d3.w = 0x7FFF;
        reg_d3.h[0] -= ENTITY(reg_a6)[1].hp.h;
        if ((s32) reg_d2.w < (s32) reg_d3.w) {
            reg_d2.w = reg_d3.w;
        }
        var_a1 = (u8 *)(reg_a5);
        reg_tmp.h[1] = SMALL_FLYER(var_a1)->hp[0];
        reg_tmp.h[0] = SMALL_FLYER(var_a1)->hp[1];
        reg_tmp.w -= reg_d2.w;
        SMALL_FLYER(var_a1)->hp[0] = (u16) reg_tmp.h[1];
        var_a0 = (u8 *)((void *) reg_tmp.h[0]);
        SMALL_FLYER(reg_a5)->hp[1] = (u16) var_a0;
        reg_d0.h[0] = 0x7FFF;
        ENTITY(reg_a6)->hp.h = (u16) reg_d0.h[0];
        ENTITY(reg_a6)[1].hp.h = (u16) reg_d0.h[0];
        reg_tmp.h[1] = SMALL_FLYER(reg_a5)->hp[0];
        reg_tmp.h[0] = SMALL_FLYER(reg_a5)->hp[1];
        if ((s32) reg_tmp.w < 0) {
            reg_d0.w = 0x19;
            score_add();
            reg_d0.h[0] = 0x82;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            temp_a0 = ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->x = temp_a0;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0;
            EXPLOSION(reg_a0)->move.b.speed = (u8) ENTITY(reg_a6)->move.b.speed;
            reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d0.b[0] *= 4;
            EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
            sfx_explosion_ground_small();
            if ((s32) ENTITY(reg_a6)->y.h >= 0x3200) {
                reg_d1.w = 0;
                reg_d0.w = 0x1000C;
                reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0;
                bullet_fire_2way();
            }
            enemy_remove();
            return;
        }
        goto block_16;
    }
    (*(u8 *)((u8 *)(var_a0) + (0x1C))) = (u8) SMALL_FLYER(reg_a5)->palette;
block_16:
    reg_tmp.b[0] = SMALL_FLYER(reg_a5)->fire_countdown;
    SMALL_FLYER(reg_a5)->fire_countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        SMALL_FLYER(reg_a5)->fire_countdown = (u8) SMALL_FLYER(reg_a5)->fire_interval;
        entity_in_shot_limits_y();
        if (cond_flag == 0) {
            reg_d1.w = 0;
            temp_a0_2 = ENTITY(reg_a6)->move.b.dir;
            reg_d1.b[0] = temp_a0_2;
            if (g_stage != 4) {
                reg_d0.w = 0x1000C;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0;
                bullet_fire_3way();
            } else {
                reg_d0.w = 0xFFFC000C;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0;
                bullet_fire_2way();
                reg_d1.h[0] += 2;
                bullet_fire_fast();
                reg_d1.h[0] -= 4;
                bullet_fire_2way();
            }
        }
    }
    small_flyer_draw();
}

void flyer_spawner_first(void) {
    enemy_set_entity_count(0);
}

#ifndef DDPDOJ_PC
s32 enemy_init_entities();                            /* extern */
#endif
extern s32 D_002583E0[];

void flyer_spawner_start(void) {
    reg_a0 = (u8 *)D_002583E0;
    enemy_init_entities();
    FLYER_SPAWNER(reg_a5)->spawn.both = 6;
}

s32 spawn_request_add();
extern u16 g_enemy_signal_0;

void flyer_spawner() {
#ifndef DDPDOJ_PC
    s32 enemy_remove();
#endif
    if ((s16)g_scroll_line >= 0x9C) {
        enemy_remove();
        return;
    }
    if ((g_enemies_stopped == 0) && (g_enemy_signal_0 == 0)) {
        reg_tmp.b[0] = FLYER_SPAWNER(reg_a5)->spawn.b.countdown;
        FLYER_SPAWNER(reg_a5)->spawn.b.countdown -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            FLYER_SPAWNER(reg_a5)->spawn.b.countdown = (u8) FLYER_SPAWNER(reg_a5)->spawn.b.interval;
            reg_d0.w = 0x3F; /* ENEMY_SMALL_FLYER_B */
            spawn_request_add();
        }
    }
}

void stage3_cloud_first(void) {
    enemy_set_entity_count(1);
}

extern u8 D_00258400[];
extern u8 D_00258410[];
extern u16 g_side_scroll_x_prev[];

void stage3_cloud_start(void) {
#ifndef DDPDOJ_PC
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
#endif
    reg_a0 = D_00258410;
    enemy_init_entities();
    reg_a0 = D_00258400;
    reg_d0.w = 6;
    enemy_set_task_state();
    reg_tmp.w = 0x70000000;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
    reg_d1.w = 0;
    reg_d1.h[0] -= 0x800;
    reg_d1.h[0] -= g_side_scroll_x_prev[0];
    ENTITY(reg_a6)->x.h = (u16) reg_d1.h[0];
    ENTITY(reg_a6)[1].y.h = (u16) ENTITY(reg_a6)->y.h;
    ENTITY(reg_a6)[1].x.h = (u16) ENTITY(reg_a6)->x.h;
}

s32 entity_draw_layer3_keep();
#ifndef DDPDOJ_PC
s32 velocity_from_direction();
#endif
extern u8 D_00258450[];

void stage3_cloud(void) {
#ifndef DDPDOJ_PC
    s32 enemy_remove();
#endif
    u16 t1;

    if (g_scroll_line == 0x118) {
        enemy_remove();
        return;
    }
    if (g_enemies_stopped == 0) {
        if ((s16) STAGE3_CLOUD(reg_a5)->rounds_left < 2) {
            reg_tmp.b[0] = STAGE3_CLOUD(reg_a5)->countdown;
            STAGE3_CLOUD(reg_a5)->countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                STAGE3_CLOUD(reg_a5)->countdown = (u8) STAGE3_CLOUD(reg_a5)->interval;
            }
        }
        reg_d1.w = 0;
        reg_d0.w = 0;
        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        velocity_from_direction();
        ENTITY(reg_a6)->y.h += reg_d2.h[0];
        ENTITY(reg_a6)[1].y.h += reg_d2.h[0];
        ENTITY(reg_a6)[1].x.h = (u16) ENTITY(reg_a6)->x.h;
        STAGE3_CLOUD(reg_a5)->travelled += reg_d2.h[0];
        reg_d0.h[0] = STAGE3_CLOUD(reg_a5)->travelled;
        reg_d0.h[0] *= -1;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7000;
        reg_tmp.w = 0;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] -= 0x7000;
        reg_tmp.w -= reg_tmp1.sw;
        if (reg_tmp.h[1] == 0) {
            reg_d0.h[0] *= -1;
            STAGE3_CLOUD(reg_a5)->travelled = (u16) reg_d0.h[0];
            reg_a0 = reg_a6;
            reg_a0 += STAGE3_CLOUD(reg_a5)->next_entity;
            STAGE3_CLOUD(reg_a5)->next_entity += 0x20;
            STAGE3_CLOUD(reg_a5)->next_entity &= 0x3F;
            *(s8 *)(reg_a0 + 0x1E) = 1;
            reg_d1.h[0] = 0x7000;
            reg_d1.h[0] += reg_d0.h[0];
            *(u16 *)(reg_a0 + 2) = (u16) reg_d1.h[0];
            reg_a1 = (u8 *)D_00258450;
            reg_a1 += STAGE3_CLOUD(reg_a5)->picture;
            *(u16 *)(reg_a0 + 0xA) = (u16) *(u16 *)reg_a1;
            *(u16 *)(reg_a0 + 0xC) = (u16) *(u16 *)(reg_a1 + 2);
            if ((STAGE3_CLOUD(reg_a5)->picture == 0) && (g_enemy_signal_e == 0)) {
                t1 = STAGE3_CLOUD(reg_a5)->rounds_left;
                if (t1 != 0) {
                    STAGE3_CLOUD(reg_a5)->rounds_left = (s16) (t1 - 1);
                    if (STAGE3_CLOUD(reg_a5)->rounds_left == 0) {
                        STAGE3_CLOUD(reg_a5)->ending = 1U;
                    }
                }
            }
            STAGE3_CLOUD(reg_a5)->picture += 4;
            STAGE3_CLOUD(reg_a5)->picture &= 0xF;
            if (STAGE3_CLOUD(reg_a5)->ending != 0) {
                *(s8 *)(reg_a0 + 0x1E) = 0;
            }
        }
    }
    reg_d7.w = 1;
    do {
        if (ENTITY(reg_a6)->misc.b.draw_layer != 0) {
            entity_draw_layer3_keep();
        }
        reg_a6 += 0x20;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

void stage3_carrier_first(void) {
    enemy_set_entity_count(0);
}

s32 enemy_request_start();
s32 enemy_request_start_flags();
extern u8 D_00258460[];
extern u8 D_00258490[];

void stage3_carrier_start(void) {
#ifndef DDPDOJ_PC
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
#endif
    reg_a0 = (u8 *)D_00258490;
    enemy_init_entities();
    reg_a0 = (u8 *)D_00258460;
    reg_d0.w = 0x10;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if (g_scroll_line == 0x168) {
            reg_d0.w = 0x18;
            enemy_request_start();
            *(u16 *)(reg_a0 + 0x16) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 0x18) = (u16) ENTITY(reg_a6)->x.h;
            reg_tmp.h[1] = *(u16 *)(reg_a0 + 0x16);
            reg_tmp.h[0] = *(u16 *)(reg_a0 + 0x18);
            reg_tmp.w += 0x10000400;
            *(u16 *)(reg_a0 + 0x16) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_tmp.h[0];
            *(u16 *)(reg_a0 + 0x1A) = (u16) ENTITY(reg_a6)->move.h;
            *(u16 *)(reg_a0 + 0x1C) = ENTITY(reg_a6)->attr.h;
        } else {
            reg_d0.w = 0x17;
            reg_d1.h[0] = 0x20;
            enemy_request_start_flags();
            *(u16 *)(reg_a0 + 0x16) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 0x18) = (u16) ENTITY(reg_a6)->x.h;
            reg_tmp.h[1] = *(u16 *)(reg_a0 + 0x16);
            reg_tmp.h[0] = *(u16 *)(reg_a0 + 0x18);
            reg_tmp.w += 0x10000400;
            *(u16 *)(reg_a0 + 0x16) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_tmp.h[0];
            *(u16 *)(reg_a0 + 0x1A) = (u16) ENTITY(reg_a6)->move.h;
            *(u16 *)(reg_a0 + 0x1C) = ENTITY(reg_a6)->attr.h;
        }
    }
}

void sprite_draw_layer1_keep(void);

void stage3_carrier(void) {
#ifndef DDPDOJ_PC
    void enemy_remove(void);
    void enemy_path_step(void);
    void sprite_draw_layer3_keep(void);
#endif
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    if ((s16) reg_d2.h[0] >= 0x6000) {
        goto next_1;
    }
    if ((s16) reg_d2.h[0] <= -0x2800) {
        goto next_1;
    }
    if ((s16) reg_d1.h[0] <= -0x3C00) {
        goto next_1;
    }
    STAGE3_CARRIER(reg_a5)->seen = 1;
    goto next_2;
next_1:
    if (STAGE3_CARRIER(reg_a5)->seen == 0) {
        goto next_2;
    }
    enemy_remove();
    return;
next_2:
    enemy_path_step();
    if (enemy_move_end_requested != 0) {
        return;
    }
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    reg_d2.w = 0x1CBB;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] -= 0x2800;
    reg_d7.h[0] = reg_d1.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d6.h[0] = reg_d1.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    if ((s16) reg_d7.h[0] <= -0x2800) {
        goto next_3;
    }
    if ((s16) reg_d7.h[0] >= 0x3900) {
        goto next_3;
    }
    if ((s16) reg_d6.h[0] <= -0x3C00) {
        goto next_3;
    }
    if ((s16) reg_d6.h[0] >= 0x7000) {
        goto next_3;
    }
    reg_d3.h[0] = 0x1EA0;
    sprite_draw_layer1_keep();
next_3:
    reg_d2.w = 0x1CBC;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d7.h[0] = reg_d1.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d6.h[0] = reg_d1.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    if ((s16) reg_d7.h[0] <= -0x2800) {
        goto next_4;
    }
    if ((s16) reg_d7.h[0] >= 0x3900) {
        goto next_4;
    }
    if ((s16) reg_d6.h[0] <= -0x3C00) {
        goto next_4;
    }
    if ((s16) reg_d6.h[0] >= 0x7000) {
        goto next_4;
    }
    reg_d3.h[0] = 0x1EA0;
    sprite_draw_layer1_keep();
next_4:
    reg_d2.w = 0x1CBD;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w -= 0x2C002000;
    reg_d7.h[0] = reg_d1.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d6.h[0] = reg_d1.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    if ((s16) reg_d7.h[0] <= -0x2400) {
        goto next_5;
    }
    if ((s16) reg_d7.h[0] >= 0x3900) {
        goto next_5;
    }
    if ((s16) reg_d6.h[0] <= -0x4000) {
        goto next_5;
    }
    if ((s16) reg_d6.h[0] >= 0x7000) {
        goto next_5;
    }
    reg_d3.h[0] = 0x2090;
    sprite_draw_layer3_keep();
next_5:
    reg_d2.w = 0x1CBE;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w -= 0x2BFFFC00;
    reg_d7.h[0] = reg_d1.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d6.h[0] = reg_d1.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    if ((s16) reg_d7.h[0] <= -0x2400) {
        return;
    }
    if ((s16) reg_d7.h[0] >= 0x3900) {
        return;
    }
    if ((s16) reg_d6.h[0] <= -0x4000) {
        return;
    }
    if ((s16) reg_d6.h[0] >= 0x7000) {
        return;
    }
    reg_d3.h[0] = 0x2090;
    sprite_draw_layer3_keep();
}

void battleship_b_first(void) {
    enemy_set_entity_count(1);
}

extern u8 D_002584B0[];
extern u8 D_002584E0[];
extern s16 g_slowdown_boss_allowed;

void battleship_b_start() {
#ifndef DDPDOJ_PC
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
#endif
    u16 temp_a1;

    reg_a0 = D_002584E0;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) BATTLESHIP_B(reg_a5)->at_start.y;
    ENTITY(reg_a6)->x.h = (u16) BATTLESHIP_B(reg_a5)->at_start.x;
    temp_a1 = BATTLESHIP_B(reg_a5)->start_move;
    ENTITY(reg_a6)->move.h = temp_a1;
    reg_a0 = D_002584B0;
    reg_d0.w = 0x11;
    enemy_set_task_state();
    g_bullet_limit_raised_1[0] = 1;
    g_slowdown_boss_allowed = 1;
}

#ifndef DDPDOJ_PC
s32 sprite_draw_layer4();
#endif
s32 bullet_cancel_with_flags();
extern u8 D_00258520[];

void battleship_b(void) {
#ifndef DDPDOJ_PC
    s32 enemy_remove();
    s32 sprite_draw_layer2();
#endif
    s16 temp_v1_2;
    u32 temp_a0;
    u32 temp_a0_2;
    u32 temp_a0_3;
    u32 temp_a0_4;
    u32 temp_a1;
    u8 temp_v1;
    u8 var_a0_2;
    u8 *var_p;
    u8 *var_a0;

    entity_velocity();
    reg_d1.w = 0x5C;
    var_a0 = (u8 *)(reg_a6 + 1);
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        var_a0 = (u8 *)((void *) reg_d0.b[0]);
        reg_d2.b[0] = BATTLESHIP_B(reg_a5)->now.hit_palette;
        reg_d0.b[0] = (s32) var_a0 ^ reg_d2.b[0];
        ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
        if (BATTLESHIP_B(reg_a5)->now.phase != 2) {
            ENTITY(reg_a6)->hp.sh = 0x2400;
        }
        if (ENTITY(reg_a6)->hp.sh < 0) {
            BATTLESHIP_B(reg_a5)->dying_frames = 0x40U;
            BATTLESHIP_B(reg_a5)->dying_dir = (u16) reg_d1.h[0];
            reg_d0.w = 0x234;
            score_add();
            var_a0 = (u8 *)((void *)0x8000);
            g_slowdown_boss_allowed = 0;
            ENTITY(reg_a6)->flags.h = 0x8000;
            BATTLESHIP_B(reg_a5)->dying = 1U;
            goto block_5;
        }
    } else {
block_5:
        ENTITY(reg_a6)->attr.b.palette = (u8) BATTLESHIP_B(reg_a5)->now.palette;
    }
    battleship_b_blow_up();
    if (BATTLESHIP_B(reg_a5)->dying_frames != 0) {
        reg_d1.h[0] = BATTLESHIP_B(reg_a5)->dying_dir;
        bullet_cancel_with_flags();
        BATTLESHIP_B(reg_a5)->dying_frames -= 1;
        if (BATTLESHIP_B(reg_a5)->dying_frames == 0) {
            enemy_remove();
            return;
        }
        if (BATTLESHIP_B(reg_a5)->dying == 0) {
            return;
        }
        goto block_37;
    }
    if ((g_enemies_stopped == 0) && (BATTLESHIP_B(reg_a5)->dying == 0)) {
        temp_a0 = ENTITY(reg_a6)->y.h;
        if (((s16)(temp_a0) >= 0) && ((s32)(temp_a0 & 0xFFFF) < 0x6401)) {
            BATTLESHIP_B(reg_a5)->falling = 1U;
        }
        if (BATTLESHIP_B(reg_a5)->falling != 0) {
            temp_v1 = BATTLESHIP_B(reg_a5)->low_layer_frames;
            if (temp_v1 != 0) {
                BATTLESHIP_B(reg_a5)->low_layer_frames = (u8) (temp_v1 - 1);
            }
            reg_tmp.b[0] = BATTLESHIP_B(reg_a5)->fall_countdown;
            BATTLESHIP_B(reg_a5)->fall_countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                BATTLESHIP_B(reg_a5)->fall_countdown = (u8) BATTLESHIP_B(reg_a5)->fall_interval;
                temp_a0_2 = BATTLESHIP_B(reg_a5)->fall_speed;
                if ((s16)(temp_a0_2) < 0x80) {
                    BATTLESHIP_B(reg_a5)->fall_speed = (u16) (temp_a0_2 + 1);
                }
            }
            reg_d0.h[0] = BATTLESHIP_B(reg_a5)->fall_speed;
            temp_a1 = ENTITY(reg_a6)->y.h;
            ENTITY(reg_a6)->y.h = (u16) (temp_a1 + reg_d0.h[0]);
            temp_a0_3 = ENTITY(reg_a6)->y.h;
            if ((s32) temp_a0_3 >= 0x9800) {
                g_slowdown_boss_allowed = 0;
                enemy_remove();
                return;
            }
            goto block_24;
        }
block_24:
        if (BATTLESHIP_B(reg_a5)->now.phase == 0) {
            temp_v1_2 = (s16) ENTITY(reg_a6)->y.h;
            if ((temp_v1_2 >= 0) && (temp_v1_2 < 0x6601)) {
                BATTLESHIP_B(reg_a5)->now.phase = 1U;
            }
        }
        if (BATTLESHIP_B(reg_a5)->now.phase == 1) {
            reg_tmp.b[0] = BATTLESHIP_B(reg_a5)->frame_countdown;
            BATTLESHIP_B(reg_a5)->frame_countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                BATTLESHIP_B(reg_a5)->frame_countdown = (u8) BATTLESHIP_B(reg_a5)->frame_interval;
                BATTLESHIP_B(reg_a5)->frame += 4;
                if ((s16) BATTLESHIP_B(reg_a5)->frame >= 0x3C) {
                    BATTLESHIP_B(reg_a5)->now.phase = 2U;
                }
            }
        }
        var_a0_2 = BATTLESHIP_B(reg_a5)->now.phase;
        if (var_a0_2 == 2) {
            if (BATTLESHIP_B(reg_a5)->fire_step == 0) {
                reg_tmp.b[0] = BATTLESHIP_B(reg_a5)->fire_countdown;
                BATTLESHIP_B(reg_a5)->fire_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    var_p = reg_a5;
                    BATTLESHIP_B(var_p)->fire_countdown = (u8) BATTLESHIP_B(var_p)->fire_interval;
                    BATTLESHIP_B(reg_a5)->fire_step = 1U;
                    goto block_36;
                }
            } else {
block_36:
                battleship_b_fire();
            }
        }
        goto block_37;
    }
block_37:
    if (ENTITY(reg_a6)->misc.b.draw_layer == 0) {
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
        reg_a0 = (u8 *)D_00258520;
        reg_a0 += BATTLESHIP_B(reg_a5)->frame;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a0_4 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a0_4;
        reg_d1.w += 0xD800F200;
        reg_d3.h[0] = 0x2870;
        if (BATTLESHIP_B(reg_a5)->low_layer_frames == 0) {
            sprite_draw_layer4();
        } else {
            sprite_draw_layer2();
        }
        reg_a0 = reg_a6;
        enemy_hitbox_debug_draw();
    }
}

void battleship_b_next_salvo(void) {
    BATTLESHIP_B(reg_a5)->fire_step = 0;
    BATTLESHIP_B(reg_a5)->salvo += 1;
    if (BATTLESHIP_B(reg_a5)->salvo == 4) {
        BATTLESHIP_B(reg_a5)->salvo = 0U;
    }
}

typedef void (*Fn)(void);
extern u8 *reg_call_target_as_u8_p;
extern u16 D_00258560[];

void battleship_b_fire(void) {
    reg_d0.h[0] = BATTLESHIP_B(reg_a5)->fire_step;
    if (BATTLESHIP_B(reg_a5)->fire_step != 2) {
        BATTLESHIP_B(reg_a5)->fire_step += 1;
    }
    reg_d0.h[0] -= 1;
    reg_d0.h[0] <<= 2;
    reg_d1.h[0] = BATTLESHIP_B(reg_a5)->salvo;
    reg_a0 = (u8 *)D_00258560;
    reg_d1.h[0] <<= 3;
    reg_a0 += reg_d1.h[0];
    reg_a0 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    reg_call_target_as_u8_p = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    ((Fn)reg_call_target_as_u8_p)();
}


void ground_gun_a_aim(void) {
#ifndef DDPDOJ_PC
    void aim256_at_player();
#endif
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x7FFF + 0x7D01;
    aim256_at_player();
    if (cond_flag == 0) {
        reg_d1.b[0] -= 0x40;
        ENTITY(reg_a6)[1].hit_y_plus.b[0] = reg_d1.b[0];
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x7FFF + 0x7501;
        aim256_at_player();
        reg_d1.b[0] += 0x38;
        ENTITY(reg_a6)[1].hit_y_plus.b[1] = reg_d1.b[0];
        ENTITY(reg_a6)[1].offset_x.h = 4;
        ENTITY(reg_a6)[1].sprite.h = 8;
        ground_gun_a_fire();
    }
}


void ground_gun_a_fire() {
    reg_tmp.b[0] = ENTITY(reg_a6)[1].offset_x.b[1];
    ENTITY(reg_a6)[1].offset_x.b[1] -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ENTITY(reg_a6)[1].offset_x.b[1] = (u8) ENTITY(reg_a6)[1].offset_x.b[0];
        reg_d0.w = 0x40007;
        reg_d4.w = 0;
        reg_d3.w = 0;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.b[0] = ENTITY(reg_a6)[1].hit_y_plus.b[0];
        reg_d3.w = 0xFD000000;
        bullet_fire256();
        reg_d3.w = 0xFCFFFF00;
        bullet_fire256();
        reg_d3.w = 0xFD000100;
        bullet_fire256();
        ENTITY(reg_a6)[1].hit_y_plus.b[0] += 0x14;
        reg_d1.b[0] = ENTITY(reg_a6)[1].hit_y_plus.b[1];
        reg_d3.w = 0xF5000000;
        bullet_fire256();
        reg_d3.w = 0xF4FFFF00;
        bullet_fire256();
        reg_d3.w = 0xF5000100;
        bullet_fire256();
        ENTITY(reg_a6)[1].hit_y_plus.b[1] -= 0x14;
        ENTITY(reg_a6)[1].sprite.h -= 1;
        if (ENTITY(reg_a6)[1].sprite.h == 0) {
            battleship_b_next_salvo();
        }
    }
}


void ground_gun_b_aim() {
#ifndef DDPDOJ_PC
    s32 aim256_at_player();
#endif
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    aim256_at_player();
    if (cond_flag == 0) {
        ENTITY(reg_a6)[1].look.b.palette = (u8) reg_d1.b[0];
        reg_d1.b[0] -= 0x30;
        ENTITY(reg_a6)[1].hit_y_plus.b[0] = (u8) reg_d1.b[0];
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        aim256_at_player();
        ENTITY(reg_a6)[1].look.b.size = (u8) reg_d1.b[0];
        reg_d1.b[0] += 0x30;
        ENTITY(reg_a6)[1].hit_y_plus.b[1] = (u8) reg_d1.b[0];
        ENTITY(reg_a6)[1].offset_x.sh = 2;
        ENTITY(reg_a6)[1].sprite.sh = 0x16;
        ground_gun_b_fire();
    }
}

#ifndef DDPDOJ_PC
s32 bullet_fire256_fast();
#endif
s32 direction_step_toward();

void ground_gun_b_fire(void) {
    reg_tmp.b[0] = ENTITY(reg_a6)[1].offset_x.b[1];
    ENTITY(reg_a6)[1].offset_x.b[1] -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ENTITY(reg_a6)[1].offset_x.b[1] = (u8) ENTITY(reg_a6)[1].offset_x.b[0];
        reg_d7.w = 1;
        do {
            reg_d1.b[0] = ENTITY(reg_a6)[1].look.b.palette;
            reg_d0.b[0] = ENTITY(reg_a6)[1].hit_y_plus.b[0];
            direction_step_toward();
            ENTITY(reg_a6)[1].hit_y_plus.b[0] = (u8) reg_d1.b[0];
            reg_d1.b[0] = ENTITY(reg_a6)[1].look.b.size;
            reg_d0.b[0] = ENTITY(reg_a6)[1].hit_y_plus.b[1];
            direction_step_toward();
            ENTITY(reg_a6)[1].hit_y_plus.b[1] = (u8) reg_d1.b[0];
        } while ((s16)(--reg_d7.h[0]) >= 0);
        reg_d4.w = 0;
        reg_d0.w = 0x160007;
        reg_d3.w = 0;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.b[0] = ENTITY(reg_a6)[1].hit_y_plus.b[0];
        reg_d3.w = 0x078005C0;
        bullet_fire256_fixed();
        reg_d1.b[0] += 6;
        bullet_fire256_fast();
        reg_d1.b[0] = ENTITY(reg_a6)[1].hit_y_plus.b[1];
        reg_d3.w = 0x077FFA40;
        bullet_fire256_fixed();
        reg_d1.b[0] -= 6;
        bullet_fire256_fast();
        ENTITY(reg_a6)[1].sprite.h -= 1;
        if (ENTITY(reg_a6)[1].sprite.h == 0) {
            battleship_b_next_salvo();
        }
    }
}

void battleship_c_first(void) {
    enemy_set_entity_count(3);
}

extern u8 D_00258580[];
extern u8 D_002585B0[];

void battleship_c_start() {
#ifndef DDPDOJ_PC
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
#endif
    u16 temp_a1;

    reg_a0 = D_002585B0;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) BATTLESHIP_B(reg_a5)->at_start.y;
    ENTITY(reg_a6)->x.h = (u16) BATTLESHIP_B(reg_a5)->at_start.x;
    temp_a1 = BATTLESHIP_B(reg_a5)->start_move;
    ENTITY(reg_a6)->move.h = temp_a1;
    reg_a0 = D_00258580;
    reg_d0.w = 0x11;
    enemy_set_task_state();
}

extern u8 D_00258620[];

void battleship_c(void) {
#ifndef DDPDOJ_PC
    s32 enemy_remove();
    s32 sprite_draw_layer2();
#endif
    s16 temp_v1;
    s16 temp_v1_3;
    u32 temp_a0;
    u32 temp_a0_2;
    u32 temp_a0_4;
    u32 temp_a1;
    u8 temp_a0_3;
    u8 temp_v1_2;
    u8 *var_a0;

    entity_velocity();
    reg_d1.w = 0x5C;
    var_a0 = (u8 *)(reg_a6 + 1);
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        var_a0 = (u8 *)((void *) reg_d0.b[0]);
        reg_d2.b[0] = BATTLESHIP_B(reg_a5)->now.hit_palette;
        reg_d0.b[0] = (s32) var_a0 ^ reg_d2.b[0];
        ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
        if (BATTLESHIP_B(reg_a5)->now.phase != 2) {
            ENTITY(reg_a6)->hp.sh = 0x2400;
        }
        if (ENTITY(reg_a6)->hp.sh < 0) {
            BATTLESHIP_B(reg_a5)->dying_frames = 0x40U;
            BATTLESHIP_B(reg_a5)->dying_dir = (u16) reg_d1.h[0];
            reg_d0.w = 0x563;
            score_add();
            var_a0 = (u8 *)((void *)0x8000);
            ENTITY(reg_a6)->flags.h = 0x8000;
            BATTLESHIP_B(reg_a5)->dying = 1U;
            goto block_5;
        }
    } else {
block_5:
        ENTITY(reg_a6)->attr.b.palette = (u8) BATTLESHIP_B(reg_a5)->now.palette;
    }
    battleship_b_blow_up();
    if (BATTLESHIP_B(reg_a5)->dying_frames != 0) {
        reg_d1.h[0] = BATTLESHIP_B(reg_a5)->dying_dir;
        bullet_cancel_with_flags();
        BATTLESHIP_B(reg_a5)->dying_frames -= 1;
        if (BATTLESHIP_B(reg_a5)->dying_frames == 0) {
            enemy_remove();
            return;
        }
        if (BATTLESHIP_B(reg_a5)->dying == 0) {
            return;
        }
        goto block_37;
    }
    if ((g_enemies_stopped == 0) && (BATTLESHIP_B(reg_a5)->dying == 0)) {
        temp_v1 = ENTITY(reg_a6)->y.sh;
        if ((temp_v1 >= 0) && (temp_v1 < 0x5A01)) {
            BATTLESHIP_B(reg_a5)->falling = 1U;
        }
        if (BATTLESHIP_B(reg_a5)->falling != 0) {
            temp_v1_2 = BATTLESHIP_B(reg_a5)->low_layer_frames;
            if (temp_v1_2 != 0) {
                BATTLESHIP_B(reg_a5)->low_layer_frames = (u8) (temp_v1_2 - 1);
            }
            reg_tmp.b[0] = BATTLESHIP_B(reg_a5)->fall_countdown;
            BATTLESHIP_B(reg_a5)->fall_countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                BATTLESHIP_B(reg_a5)->fall_countdown = (u8) BATTLESHIP_B(reg_a5)->fall_interval;
                temp_a0 = BATTLESHIP_B(reg_a5)->fall_speed;
                if ((s16)(temp_a0) < 0x80) {
                    BATTLESHIP_B(reg_a5)->fall_speed = (u16) (temp_a0 + 1);
                }
            }
            reg_d0.h[0] = BATTLESHIP_B(reg_a5)->fall_speed;
            temp_a1 = ENTITY(reg_a6)->y.h;
            ENTITY(reg_a6)->y.sh = (s16) (temp_a1 + reg_d0.h[0]);
            temp_a0_2 = ENTITY(reg_a6)->y.h;
            if ((s32) temp_a0_2 >= 0x9800) {
                enemy_remove();
                return;
            }
            goto block_24;
        }
block_24:
        if (BATTLESHIP_B(reg_a5)->now.phase == 0) {
            temp_v1_3 = ENTITY(reg_a6)->y.sh;
            if ((temp_v1_3 >= 0) && (temp_v1_3 < 0x6601)) {
                BATTLESHIP_B(reg_a5)->now.phase = 1U;
            }
        }
        if (BATTLESHIP_B(reg_a5)->now.phase == 1) {
            reg_tmp.b[0] = BATTLESHIP_B(reg_a5)->frame_countdown;
            BATTLESHIP_B(reg_a5)->frame_countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                BATTLESHIP_B(reg_a5)->frame_countdown = (u8) BATTLESHIP_B(reg_a5)->frame_interval;
                BATTLESHIP_B(reg_a5)->frame += 4;
                if ((s16) BATTLESHIP_B(reg_a5)->frame >= 0x3C) {
                    BATTLESHIP_B(reg_a5)->now.phase = 2U;
                }
            }
        }
        temp_a0_3 = BATTLESHIP_B(reg_a5)->now.phase;
        if (temp_a0_3 == 2) {
            battleship_c_volley_update();
            if (BATTLESHIP_B(reg_a5)->fire_step == 0) {
                reg_tmp.b[0] = BATTLESHIP_B(reg_a5)->fire_countdown;
                BATTLESHIP_B(reg_a5)->fire_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    BATTLESHIP_B(reg_a5)->fire_countdown = (u8) BATTLESHIP_B(reg_a5)->fire_interval;
                    BATTLESHIP_B(reg_a5)->fire_step = 1U;
                    goto block_36;
                }
            } else {
block_36:
                battleship_c_fire();
            }
        }
        goto block_37;
    }
block_37:
    if (ENTITY(reg_a6)->misc.b.draw_layer == 0) {
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
        reg_a0 = (u8 *)D_00258620;
        reg_a0 += BATTLESHIP_B(reg_a5)->frame;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a0_4 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a0_4;
        reg_d1.w += 0xD600F000;
        reg_d3.h[0] = 0x2A80;
        if (BATTLESHIP_B(reg_a5)->low_layer_frames == 0) {
            sprite_draw_layer4();
        } else {
            sprite_draw_layer2();
        }
        reg_a0 = reg_a6;
        enemy_hitbox_debug_draw();
    }
}

extern u16 D_00258660[];

void battleship_b_blow_up(void) {
    u16 temp_a0;
    u16 *temp_a2;
    u16 temp_a1;
    u16 temp_v1;

    temp_v1 = BATTLESHIP_B(reg_a5)->dying;
    temp_a0 = temp_v1 & 0xFFFF;
    if (temp_v1 == 0) {
        cond_flag = 0;
        return;
    }
    if (temp_a0 == 1) {
        BATTLESHIP_B(reg_a5)->dying = 2U;
        BATTLESHIP_B(reg_a5)->explosion = 0U;
        BATTLESHIP_B(reg_a5)->explosion_timer.both = 3;
        BATTLESHIP_B(reg_a5)->explosions = 0U;
        sfx_explosion_ground_large();
    }
    ENTITY(reg_a6)->y.h -= 0x26;
    if (BATTLESHIP_B(reg_a5)->dying == 2) {
        reg_tmp.b[0] = BATTLESHIP_B(reg_a5)->explosion_timer.b.countdown;
        BATTLESHIP_B(reg_a5)->explosion_timer.b.countdown -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            BATTLESHIP_B(reg_a5)->explosion_timer.b.countdown = BATTLESHIP_B(reg_a5)->explosion_timer.b.interval;
            reg_a1 = (u8 *)(D_00258660);
            reg_a1 += BATTLESHIP_B(reg_a5)->explosion;
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
            temp_a2 = (u16 *)(reg_a1 + 2);
            reg_a1 = (u8 *)(temp_a2);
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            temp_a1 = ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->x = temp_a1;
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0;
            if (BATTLESHIP_B(reg_a5)->explosions != 0) {
                rng_next();
                reg_d0.b[0] += 0xC;
                EXPLOSION(reg_a0)->move.b.speed = (u8) reg_d0.b[0];
                rng_next_unsigned();
                EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
            }
            reg_a1 += 2;
            BATTLESHIP_B(reg_a5)->explosion += 0xC;
            if ((s16) BATTLESHIP_B(reg_a5)->explosion >= 0x54) {
                BATTLESHIP_B(reg_a5)->explosion_timer.both = 0x601;
                BATTLESHIP_B(reg_a5)->explosion = 0U;
                ENTITY(reg_a6)->misc.sb.draw_layer = 1;
                BATTLESHIP_B(reg_a5)->explosions += 1;
                if (BATTLESHIP_B(reg_a5)->explosions == 1) {
                    BATTLESHIP_B(reg_a5)->dying = 0U;
                    reg_d0.w = 0;
                    cond_flag = 1;
                    reg_d0.h[0] -= 1;
                    return;
                }
            }
            goto block_11;
        }
    }
block_11:
    cond_flag = 0;
}

void battleship_c_volley_reset(void) {
    ENTITY(reg_a6)[2].offset_y.sb[1] = 1;
    reg_d7.w = 5;
    reg_a0 = reg_a6 + 0x66;
    do {
        *(s16 *)reg_a0 = 0;
        *(s16 *)(reg_a0 + 2) = 4;
        reg_a0 += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    ENTITY(reg_a6)[2].offset_x.sh = 8;
    ENTITY(reg_a6)[2].draw.sh = 0;
    battleship_c_volley_update();
}

extern u16 D_002586C0[];
extern s8 battleship_c_volley_update_table;

void battleship_c_volley_update(void) {
    u32 temp_a1;
    if (ENTITY(reg_a6)[2].offset_y.b[1] == 0) {
        battleship_c_volley_reset();
        return;
    }
    reg_tmp.b[0] = ENTITY(reg_a6)[2].offset_x.b[1];
    ENTITY(reg_a6)[2].offset_x.b[1] -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ENTITY(reg_a6)[2].offset_x.b[1] = (u8) ENTITY(reg_a6)[2].offset_x.b[0];
        reg_a4 = reg_a6 + 0x66;
        reg_a4 += ENTITY(reg_a6)[2].draw.h;
        *(u8 *)(reg_a4 + 1) = 4U;
        *(s16 *)(reg_a4 + 2) = 4;
        ENTITY(reg_a6)[2].draw.h += 4;
        if ((s16) ENTITY(reg_a6)[2].draw.h >= 0x18) {
            ENTITY(reg_a6)[2].draw.h = 0U;
        }
    }
    reg_a4 = reg_a6 + 0x66;
    reg_d7.w = 5;
    do {
        if (*(u8 *)(reg_a4 + 1) != 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
            *(u8 *)(reg_a4 + 3) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 3) = *(u8 *)(reg_a4 + 2);
                reg_d6.h[0] = reg_d7.h[0];
                temp_a1 = reg_d6.h[0];
                reg_d1.b[0] = *(&battleship_c_volley_update_table + temp_a1);
                reg_a0 = (u8 *)(D_002586C0);
                reg_d6.h[0] = temp_a1 * 4;
                reg_d3.h[1] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = (((reg_d6.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d6.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d4.w = 0;
                reg_d0.w = 5;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                bullet_fire256_2way();
                *(u8 *)(reg_a4 + 1) -= 1;
            }
        }
        reg_a4 += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

void battleship_c_next_salvo(void) {
    BATTLESHIP_B(reg_a5)->fire_step = 0;
    BATTLESHIP_B(reg_a5)->salvo += 1;
    if (BATTLESHIP_B(reg_a5)->salvo == 2) {
        BATTLESHIP_B(reg_a5)->salvo = 0U;
    }
}

extern u16 D_002586E0[];

void battleship_c_fire(void) {
    reg_d0.h[0] = BATTLESHIP_B(reg_a5)->fire_step;
    if (BATTLESHIP_B(reg_a5)->fire_step != 2) {
        BATTLESHIP_B(reg_a5)->fire_step += 1;
    }
    reg_d0.h[0] -= 1;
    reg_d0.h[0] <<= 2;
    reg_d1.h[0] = BATTLESHIP_B(reg_a5)->salvo;
    reg_a0 = (u8 *)D_002586E0;
    reg_d1.h[0] <<= 3;
    reg_a0 += reg_d1.h[0];
    reg_a0 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    reg_call_target_as_u8_p = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    ((Fn)reg_call_target_as_u8_p)();
}


void ground_gun_c_aim(void) {
#ifndef DDPDOJ_PC
    void aim256_at_player();
#endif
    ENTITY(reg_a6)[1].offset_y.h = 2;
    ENTITY(reg_a6)[1].offset_x.h = 0xE;
    ENTITY(reg_a6)[1].sprite.h = 4;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    aim256_at_player();
    ENTITY(reg_a6)[1].look.b.size = reg_d1.b[0];
    ground_gun_c_fire();
}


void ground_gun_c_fire() {
#ifndef DDPDOJ_PC
    s32 aim256_at_player();
#endif
    u16 temp_a0;

    reg_tmp.b[0] = ENTITY(reg_a6)[1].offset_y.b[1];
    ENTITY(reg_a6)[1].offset_y.b[1] -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ENTITY(reg_a6)[1].offset_y.b[1] = (u8) ENTITY(reg_a6)[1].offset_y.b[0];
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        aim256_at_player();
        reg_d0.b[0] = ENTITY(reg_a6)[1].look.b.size;
        direction_step_toward();
        ENTITY(reg_a6)[1].look.b.size = (u8) reg_d0.b[0];
        reg_d1.b[0] = ENTITY(reg_a6)[1].look.b.size;
        reg_d4.w = 0;
        reg_d3.w = 0;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] = ENTITY(reg_a6)[1].sprite.h;
        temp_a0 = reg_d0.h[0];
        reg_tmp.h[0] = temp_a0;
        reg_d0.h[0] = 7;
        reg_d0.h[1] = reg_tmp.h[0];
        ENTITY(reg_a6)[1].sprite.h += 4;
        reg_d3.w = 0x133FFD00;
        bullet_fire256_fast();
        reg_d3.w = 0x13400300;
        bullet_fire256_fast();
        reg_d3.w = 0x13400640;
        bullet_fire256_fast();
        reg_d3.w = 0x133FF9C0;
        bullet_fire256_fast();
        ENTITY(reg_a6)[1].offset_x.h -= 1;
        if (ENTITY(reg_a6)[1].offset_x.h == 0) {
            battleship_c_next_salvo();
        }
    }
}

void wing_gunner_first(void) {
    enemy_set_entity_count(0);
}

extern u8 D_002586F0[];
extern u8 D_00258720[];


void wing_gunner_start(void)
{
#ifndef DDPDOJ_PC
    extern void enemy_set_task_state(void);
    extern void enemy_init_entities(void);
    extern void enemy_path_start(void);
#endif
    reg_a0 = D_00258720;
    enemy_init_entities();

    reg_a0 = D_002586F0;
    reg_d0.w = 0x11;
    enemy_set_task_state();

    enemy_path_start();
    if (enemy_move_end_requested != 0) {
        return;
    }
}

#ifndef DDPDOJ_PC
typedef void (*Fn)();
#endif

s32 sfx_explosion_air_medium();
extern u16 D_00258760[];
extern u16 D_00258770[];
extern u8 D_00258790[];
#ifndef DDPDOJ_PC
extern u32 reg_call_target_as_u32;
#endif

void wing_gunner(void) {
#ifndef DDPDOJ_PC
    s32 enemy_remove();
    s32 enemy_path_step();
#endif
    u16 temp_a1;
    u32 temp_a0;

    if (ENTITY(reg_a6)->y.sh < -0x1000) {
        if (WING_GUNNER(reg_a5)->seen != 0) {
            enemy_remove();
            return;
        }
        goto block_4;
    }
    WING_GUNNER(reg_a5)->seen = 1U;
block_4:
    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
            score_add_no_chain();
            reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
            reg_d2.b[0] = WING_GUNNER(reg_a5)->hit_palette;
            reg_d0.b[0] ^= reg_d2.b[0];
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            if (WING_GUNNER(reg_a5)->has_fired == 0) {
                ENTITY(reg_a6)->hp.sh = 0xC00;
            }
            if (ENTITY(reg_a6)->hp.sh < 0) {
                reg_d0.w = 0x72;
                score_add();
                sfx_explosion_air_medium();
                reg_a1 = (u8 *)D_00258790;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.h[0] = 0x10;
                enemy_explode_by_table();
                enemy_remove();
                return;
            }
            goto block_11;
        }
        ENTITY(reg_a6)->attr.b.palette = (u8) WING_GUNNER(reg_a5)->palette;
block_11:
        if (g_enemies_stopped == 0) {
            if (WING_GUNNER(reg_a5)->phase == 3) {
                WING_GUNNER(reg_a5)->spread -= 0x40;
                ENTITY(reg_a6)->hit_x_plus.h -= 0x40;
                ENTITY(reg_a6)->hit_x_minus.h -= 0x40;
                if (0 >= (s16) WING_GUNNER(reg_a5)->spread) {
                    WING_GUNNER(reg_a5)->spread = 0U;
                    WING_GUNNER(reg_a5)->phase = 0U;
                }
            }
            if (WING_GUNNER(reg_a5)->phase == 2) {
                WING_GUNNER(reg_a5)->has_fired = 1U;
                reg_tmp.b[0] = WING_GUNNER(reg_a5)->shot_countdown;
                WING_GUNNER(reg_a5)->shot_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    WING_GUNNER(reg_a5)->shot_countdown = (u8) WING_GUNNER(reg_a5)->shot_interval;
                    reg_a0 = (u8 *)(D_00258760);
                    if ((s32) g_scroll_line >= 0x100) {
                        reg_a0 = (u8 *)(D_00258770);
                    }
                    reg_d0.h[0] = WING_GUNNER(reg_a5)->shots_fired;
                    reg_d0.h[0] *= 4;
                    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
#ifdef DDPDOJ_PC
                    ARCADE_ADDRESS_DECODE(Fn, reg_tmp.w)();
#else
                    reg_call_target_as_u32 = reg_tmp.w;
                    ((Fn)reg_call_target_as_u32)();
#endif
                    WING_GUNNER(reg_a5)->shots_fired += 1;
                    reg_d0.w = 4;
                    reg_d1.w = 3;
                    if ((s32) g_scroll_line >= 0x100) {
                        reg_d0.w = 8;
                        reg_d1.w = 2;
                    }
                    WING_GUNNER(reg_a5)->shot_step += reg_d1.h[0];
                    if (WING_GUNNER(reg_a5)->shots_fired == reg_d0.h[0]) {
                        WING_GUNNER(reg_a5)->phase = 3U;
                    }
                }
            }
            if (WING_GUNNER(reg_a5)->phase == 1) {
                WING_GUNNER(reg_a5)->spread += 0x40;
                ENTITY(reg_a6)->hit_x_plus.h += 0x40;
                ENTITY(reg_a6)->hit_x_minus.h += 0x40;
                if ((s16) WING_GUNNER(reg_a5)->spread >= 0x380) {
                    WING_GUNNER(reg_a5)->spread = 0x380U;
                    WING_GUNNER(reg_a5)->open_countdown = (u8) WING_GUNNER(reg_a5)->open_time;
                    WING_GUNNER(reg_a5)->shot_step = 1U;
                    WING_GUNNER(reg_a5)->shots_fired = 0U;
                    WING_GUNNER(reg_a5)->phase = 2U;
                }
            }
            if (WING_GUNNER(reg_a5)->phase == 0) {
                reg_tmp.b[0] = WING_GUNNER(reg_a5)->wait_countdown;
                WING_GUNNER(reg_a5)->wait_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    WING_GUNNER(reg_a5)->wait_countdown = (u8) WING_GUNNER(reg_a5)->wait;
                    WING_GUNNER(reg_a5)->phase = 1U;
                }
            }
        }
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a1 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xF200F900;
        reg_d3.h[0] = 0xE38;
        reg_d2.w = 0x187A;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
        sprite_draw_layer5_keep();
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.w += 0xFEBFFB40;
        reg_d7.h[0] = WING_GUNNER(reg_a5)->spread;
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.h[0] -= reg_d7.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.h[0] -= WING_GUNNER(reg_a5)->spread;
        temp_a0 = reg_d1.w;
        reg_d3.h[0] = 0xE28;
        reg_d2.w = 0x187B;
        reg_d4.w = 0;
        reg_d1.w = temp_a0 + 0xF200FB00;
        reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
        sprite_draw_layer5_keep();
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.w += 0xFEC00480;
        reg_d7.h[0] = WING_GUNNER(reg_a5)->spread;
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.h[0] -= reg_d7.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.h[0] += WING_GUNNER(reg_a5)->spread;
        reg_d1.w += 0xF200FB00;
        reg_d3.h[0] = 0xE28;
        reg_d2.w = 0x187C;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
        sprite_draw_layer5_keep();
        reg_a0 = (u8 *)(reg_a6);
        enemy_hitbox_debug_draw();
    }
}

extern u8 D_00258740[];

void wing_gunner_fire(void) {
    u32 t1;

    reg_a4 = (u8 *)D_00258740;
    reg_d7.w = 5;
loop_1:
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += *(u16 *)reg_a4;
    reg_d1.h[0] += *(u16 *)(reg_a4 + 2);
    aim_at_player();
    if (cond_flag == 0) {
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d4.w = 0;
        reg_d3.h[1] = *(u16 *)reg_a4;
        reg_d3.h[0] = *(u16 *)(reg_a4 + 2);
        reg_d0.h[0] = WING_GUNNER(reg_a5)->shot_step;
        reg_d0.h[0] += 4;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] = 5;
        reg_d0.h[1] = reg_tmp.h[0];
        bullet_fire_fast();
        reg_a4 += 4;
        t1 = reg_d7.h[0] - 1;
        reg_d7.h[0] = t1;
        if (((s64) ((s64) (t1 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
            goto loop_1;
        }
    }
}

extern s8 ground_pointer_rows_fill_table;
extern u8 ground_pointer_rows_fill_table_2;

void ground_pointer_rows_fill(void) {
    u16 temp_a0;
    reg_a4 = D_00258740;
    reg_a3 = (u8 *)(&ground_pointer_rows_fill_table);
    reg_a2 = &ground_pointer_rows_fill_table_2;
    reg_d7.w = 5;
    do {
        reg_d1.w = 0;
        reg_d1.b[0] = (u8) *(s8 *)reg_a3;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d4.w = (u32) reg_a6;
        reg_d3.h[1] = *(u16 *)reg_a4;
        temp_a0 = *(u16 *)(reg_a4 + 2);
        reg_d3.h[0] = temp_a0;
        if (g_stage != 4) {
            reg_d0.h[0] = 6;
            reg_tmp.h[0] = reg_d0.h[0];
            reg_d0.h[0] = 0xB;
            reg_d0.h[1] = reg_tmp.h[0];
            bullet_fire256_2way();
        } else {
            reg_d0.h[0] = 0xFFFC;
            reg_tmp.h[0] = reg_d0.h[0];
            reg_d0.h[0] = 0xB;
            reg_d0.h[1] = reg_tmp.h[0];
            bullet_fire256_fixed();
            reg_d0.w += 0x40000;
            bullet_fire256_2way();
            reg_d0.w += 0x40000;
            bullet_fire256_fixed();
            reg_d0.w += 0x40000;
            bullet_fire256_2way();
            reg_d0.w += 0x40000;
            bullet_fire256_fixed();
        }
        reg_a4 += 4;
        reg_a3 += 1;
        reg_a2 += 1;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

void hover_gunner_first(void) {
    enemy_set_entity_count(0);
}

s32 direction_to_target_player();
extern u8 D_002587C0[];
extern u8 D_002587E0[];

void hover_gunner_start(void) {
#ifndef DDPDOJ_PC
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
#endif
    reg_a0 = D_002587E0;
    enemy_init_entities();
    reg_a0 = D_002587C0;
    reg_d0.w = 0xA;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        direction_to_target_player();
        HOVER_GUNNER(reg_a5)->turret_dir = (u8) reg_d1.b[0];
        if (g_stage == 4) {
            ENTITY(reg_a6)->flags.h = 0xA200;
            HOVER_GUNNER(reg_a5)->palette = 0xF;
            HOVER_GUNNER(reg_a5)->hit_palette = 0x10;
        }
    }
}

s32 bullet_fire256_double();
extern u8 D_00258800[];
extern u8 D_0028C9D8;

void hover_gunner(void) {
#ifndef DDPDOJ_PC
    s32 enemy_remove();
    s32 enemy_path_step();
    s32 aim256_at_player();
#endif
    u16 temp_a1;
    u16 temp_a2;
    u8 temp_a0_3;
    u8 *temp_a0_2;

    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] -= HOVER_GUNNER(reg_a5)->bob;
    ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        entity_check_bounds();
        if (cond_flag != 0) {
            if (HOVER_GUNNER(reg_a5)->seen != 0) {
                enemy_remove();
                return;
            }
            goto block_5;
        }
        HOVER_GUNNER(reg_a5)->seen = 1U;
block_5:
        if (g_stage != 4) {
            reg_d1.w = 0;
            reg_d0.w = 0;
            reg_d0.b[0] = 0x28;
            reg_d1.b[0] = HOVER_GUNNER(reg_a5)->bob_angle;
            HOVER_GUNNER(reg_a5)->bob_angle += 2;
            velocity_from_dir256();
            HOVER_GUNNER(reg_a5)->bob = (u16) reg_d2.h[0];
            reg_d1.h[0] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] += HOVER_GUNNER(reg_a5)->bob;
            ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
        }
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
            score_add_no_chain();
            reg_d0.b[0] = HOVER_GUNNER(reg_a5)->palette;
            reg_d2.b[0] = HOVER_GUNNER(reg_a5)->hit_palette;
            reg_d0.b[0] ^= reg_d2.b[0];
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            if (ENTITY(reg_a6)->hp.sh < 0) {
                reg_d0.w = 0x31;
                score_add();
                reg_d0.h[0] = 2;
                explosion_spawn();
                EXPLOSION(reg_a0)->start_y = (u16) ENTITY(reg_a6)->offset_y.h;
                EXPLOSION(reg_a0)->start_x = (u16) ENTITY(reg_a6)->offset_x.h;
                EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
                temp_a1 = ENTITY(reg_a6)->x.h;
                EXPLOSION(reg_a0)->x = temp_a1;
                EXPLOSION(reg_a0)->draw_layer = 0xC;
                EXPLOSION(reg_a0)->debris = 0;
                EXPLOSION(reg_a0)->debris_arg = 0;
                EXPLOSION(reg_a0)->follows_scroll = 2;
                EXPLOSION(reg_a0)->move.b.speed = (u8) ENTITY(reg_a6)->move.b.speed;
                reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
                reg_d0.b[0] *= 4;
                EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
                sfx_explosion_ground_small();
                enemy_remove();
                return;
            }
            goto block_11;
        }
        ENTITY(reg_a6)->attr.b.palette = (u8) HOVER_GUNNER(reg_a5)->palette;
block_11:
        temp_a0_2 = (u8 *)(reg_a6 + 2);
        if ((s16) ENTITY(reg_a6)->y.h > 0x1400) {
            if (g_stage == 4) {
                reg_d0.b[0] = HOVER_GUNNER(reg_a5)->shots;
                if (HOVER_GUNNER(reg_a5)->shots_left == reg_d0.b[0]) {
                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d0.h[0] += 0x3C0;
                    aim_at_player();
                    if (cond_flag == 0) {
                        reg_d0.b[0] = HOVER_GUNNER(reg_a5)->turret_dir;
                        direction_turn_toward();
                        HOVER_GUNNER(reg_a5)->turret_dir = (u8) reg_d1.b[0];
                    }
                }
                reg_tmp.b[0] = HOVER_GUNNER(reg_a5)->shot_countdown;
                HOVER_GUNNER(reg_a5)->shot_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    HOVER_GUNNER(reg_a5)->shot_countdown = (u8) HOVER_GUNNER(reg_a5)->shot_interval;
                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d0.h[0] += 0x3C0;
                    aim256_at_player();
                    if (cond_flag == 0) {
                        reg_d0.h[0] = reg_d1.h[0];
                        reg_a0 = (u8 *)D_00258800;
                        reg_d0.h[0] &= 0xF8;
                        reg_d0.h[0] >>= 1;
                        reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                        reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                        reg_d4.w = 0;
                        reg_d0.w = 0x10007;
                        reg_d1.h[0] += 4;
                        reg_d1.h[0] &= 0xF8;
                        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d0.w = 0xFFFC0007;
                        bullet_fire256_double();
                        reg_tmp.b[0] = HOVER_GUNNER(reg_a5)->shots_left;
                        HOVER_GUNNER(reg_a5)->shots_left -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            HOVER_GUNNER(reg_a5)->shots_left = (u8) HOVER_GUNNER(reg_a5)->shots;
                            reg_d0.h[0] = 0xA;
                            reg_d1.h[0] = g_rank_1_16;
                            reg_d1.h[0] >>= 1;
                            reg_d0.h[0] -= reg_d1.h[0];
                            HOVER_GUNNER(reg_a5)->shot_countdown = reg_d0.b[0];
                        }
                    }
                }
            } else {
                reg_d0.b[0] = HOVER_GUNNER(reg_a5)->shots;
                if (HOVER_GUNNER(reg_a5)->shots_left == reg_d0.b[0]) {
                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d0.h[0] += 0x3C0;
                    aim_at_player();
                    if (cond_flag == 0) {
                        reg_d0.b[0] = HOVER_GUNNER(reg_a5)->turret_dir;
                        direction_turn_toward();
                        HOVER_GUNNER(reg_a5)->turret_dir = (u8) reg_d1.b[0];
                    }
                }
                reg_tmp.b[0] = HOVER_GUNNER(reg_a5)->shot_countdown;
                HOVER_GUNNER(reg_a5)->shot_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    HOVER_GUNNER(reg_a5)->shot_countdown = (u8) HOVER_GUNNER(reg_a5)->shot_interval;
                    reg_d1.w = 0;
                    reg_d1.b[0] = HOVER_GUNNER(reg_a5)->turret_dir;
                    reg_a0 = (u8 *)D_00258800;
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d1.b[0] += 1;
                    reg_d1.h[0] &= 0x3E;
                    reg_d3.b[0] += 2;
                    reg_d7.b[0] = reg_d1.b[0];
                    reg_d0.h[0] = reg_d1.h[0];
                    reg_d3.h[0] &= 0x3C;
                    reg_d0.h[0] *= 2;
                    reg_d1.h[0] = reg_d3.h[0];
                    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d4.w = 0;
                    reg_d0.w = 0x4000C;
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    bullet_fire_fixed();
                    reg_d0.w = 0xFFFE000D;
                    reg_d1.h[0] = reg_d7.h[0];
                    bullet_fire_2way();
                    reg_tmp.b[0] = HOVER_GUNNER(reg_a5)->shots_left;
                    HOVER_GUNNER(reg_a5)->shots_left -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        HOVER_GUNNER(reg_a5)->shots_left = (u8) HOVER_GUNNER(reg_a5)->shots;
                        reg_d0.h[0] = 0xA;
                        reg_d1.h[0] = g_rank_1_16;
                        reg_d1.h[0] >>= 2;
                        reg_d0.h[0] -= reg_d1.h[0];
                        HOVER_GUNNER(reg_a5)->shot_countdown = reg_d0.b[0];
                    }
                }
            }
        }
        reg_tmp.b[0] = HOVER_GUNNER(reg_a5)->frame_countdown;
        HOVER_GUNNER(reg_a5)->frame_countdown -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            HOVER_GUNNER(reg_a5)->frame_countdown = (u8) HOVER_GUNNER(reg_a5)->frame_interval;
            HOVER_GUNNER(reg_a5)->frame += 4;
            HOVER_GUNNER(reg_a5)->frame &= 7;
        }
        reg_a0 = &D_0028C9D8;
        reg_a0 += HOVER_GUNNER(reg_a5)->frame;
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d0.w = 0;
        reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        reg_d0.b[0] = HOVER_GUNNER(reg_a5)->turret_dir;
        reg_d0.b[0] += 1;
        reg_d0.h[0] &= 0x3E;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a2 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a2;
        reg_d1.w += 0xF600FA00;
        reg_d3.h[0] = 0xA30;
        reg_d4.w = 0;
        temp_a0_3 = ENTITY(reg_a6)->attr.b.palette;
        reg_d4.b[0] = temp_a0_3;
        if (g_stage != 4) {
            sprite_draw_layer5_keep();
        } else {
            sprite_draw_layer4_keep();
        }
        reg_a0 = reg_a6;
        enemy_hitbox_debug_draw();
    }
}

void signal_timer_first(void) {
    enemy_set_entity_count(0);
}

#ifndef DDPDOJ_PC
s32 enemy_init_entities();                            /* extern */
#endif
extern s32 D_00258980[];

void signal_timer_start(void) {
    reg_a0 = (u8 *)D_00258980;
    enemy_init_entities();
    reg_tmp.w = 0x38001C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
    SIGNAL_TIMER(reg_a5)->pulse.both = 4;
    SIGNAL_TIMER(reg_a5)->burst.both = 0x303;
}

extern u16 g_enemy_signal_8;

void signal_timer(void) {
    g_enemy_signal_8 = 0;
    reg_tmp.b[0] = SIGNAL_TIMER(reg_a5)->pulse.b.countdown;
    SIGNAL_TIMER(reg_a5)->pulse.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        SIGNAL_TIMER(reg_a5)->pulse.b.countdown = (u8) SIGNAL_TIMER(reg_a5)->pulse.b.interval;
        g_enemy_signal_8 = 1;
        reg_tmp.b[0] = SIGNAL_TIMER(reg_a5)->burst.b.pulses_left;
        SIGNAL_TIMER(reg_a5)->burst.b.pulses_left -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            SIGNAL_TIMER(reg_a5)->burst.b.pulses_left = (u8) SIGNAL_TIMER(reg_a5)->burst.b.pulses;
            SIGNAL_TIMER(reg_a5)->pulse.b.countdown = 0x10U;
        }
    }
}

void small_tank_c_first(void) {
    enemy_set_entity_count(0);
}

extern u16 D_002589A0[];
extern u16 D_002589B0[];
extern u16 D_002589D0[];
extern u16 small_tank_b_turret_sprites[];
extern u16 g_enemy_signal_2;
extern u16 g_enemy_signal_1;
extern u16 g_rank_6_16;
extern u16 g_stage_x2;
void entity_draw_layer2();

void small_tank_c_start(void) {
#ifndef DDPDOJ_PC
    s32 enemy_remove();
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    void sprite_draw_layer2();
#endif
    s16 temp_v1_2;
    u16 *temp_a2;
    u16 temp_a3;
    reg_a0 = (u8 *)(D_002589D0);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_002589B0);
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
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_tmp.h[1] = ENEMY_STATE(reg_a5)->entities[0];
        reg_tmp.h[0] = ENEMY_STATE(reg_a5)->entities[1];
        reg_a6 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        SMALL_TANK(reg_a5)->turret_dir = (u8) reg_d1.b[0];
        reg_a0 = (u8 *)(small_tank_b_turret_sprites);
        reg_d1.b[0] += 1;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        SMALL_TANK(reg_a5)->turret_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        SMALL_TANK(reg_a5)->turret_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_002589A0);
        reg_d0.h[0] = g_stage_x2;
        temp_a3 = reg_d0.h[0];
        reg_a0 += temp_a3;
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        SMALL_TANK(reg_a5)->palette = *(s8 *)reg_a0;
        reg_a0 += 1;
        SMALL_TANK(reg_a5)->hit_palette = *(s8 *)reg_a0;
        reg_tmp.w = ARCADE_ADDRESS_ENCODE((void *)entity_draw_layer2);
        temp_a2 = (u16 *)(reg_a0 + 1);
        reg_a0 = (u8 *)(temp_a2);
        SMALL_TANK(reg_a5)->draw_body[0] = (u16) reg_tmp.h[1];
        SMALL_TANK(reg_a5)->draw_body[1] = (u16) reg_tmp.h[0];
        reg_tmp.w = ARCADE_ADDRESS_ENCODE((void *)sprite_draw_layer2);
        SMALL_TANK(reg_a5)->draw_turret[0] = (u16) reg_tmp.h[1];
        SMALL_TANK(reg_a5)->draw_turret[1] = (u16) reg_tmp.h[0];
        reg_d0.h[0] = g_scroll_line;
        if ((s16) reg_d0.h[0] >= 0xAC) {
            if ((ENTITY(reg_a6)->y.sh < 0x6400) && (g_enemy_signal_2 == 0)) {
                enemy_remove();
            }
        } else if ((s16) reg_d0.h[0] >= 0x8D) {
            temp_v1_2 = ENTITY(reg_a6)->y.sh;
            if ((temp_v1_2 > -0x3C00) && (temp_v1_2 < 0x6400) && (g_enemy_signal_1 == 0)) {
                enemy_remove();
            }
        } else if (((s16) reg_d0.h[0] >= 0x48) && (g_enemy_signal_0 == 0)) {
            enemy_remove();
        }
    }
}

extern u8 small_tank_b_muzzles[];
extern u8 small_tank_b_body_sprites[];

s32 enemy_fire_zone_check();
s32 score_add_masked();
s32 entity_bounds_check_narrow();
s32 wreck_spawn();
extern u16 g_frame_mod2;
extern u16 g_rank_10_16;

void small_tank_c(void) {
#ifndef DDPDOJ_PC
    s32 enemy_remove();
    s32 enemy_path_step();
    s32 sprite_draw_layer2();
#endif
    enemy_path_step();
    if (enemy_move_end_requested != 0) return;
    entity_bounds_check_narrow();
    switch (cond_flag) { case 0: goto skip_1; }
    if (SMALL_TANK(reg_a5)->seen == 0) goto block_touch;
    enemy_remove();
    return;
skip_1:
    SMALL_TANK(reg_a5)->seen = 1;
block_touch:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto block_pal;
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    reg_d0.b[0] = SMALL_TANK(reg_a5)->hit_palette;
    ENTITY(reg_a6)->attr.b.palette ^= reg_d0.b[0];
    score_add_no_chain();
    if (ENTITY(reg_a6)->hp.sh >= 0) goto block_body;
    if ((s8) SMALL_TANK(reg_a5)->damage < 0) goto block_dead;
    ENTITY(reg_a6)->hp.h = SMALL_TANK(reg_a5)->second_hp;
    reg_d0.w = 8;
    score_add_masked();
    SMALL_TANK(reg_a5)->damage |= 0x80;
    reg_d0.w = 3;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 8;
    EXPLOSION(reg_a0)->follows_scroll = 2;
    EXPLOSION(reg_a0)->start_y = 0xFE00;
    goto block_body;
block_pal:
    ENTITY(reg_a6)->attr.b.palette = SMALL_TANK(reg_a5)->palette;
block_body:
    if (g_enemies_stopped != 0) goto block_obj;
    reg_d7.h[0] = ENTITY(reg_a6)->move.h;
    reg_d1.w = 0x3E;
    reg_d1.h[0] &= reg_d7.h[0];
    reg_d1.h[0] *= 4;
    if (reg_d7.h[0] & 0x40) goto skip_2;
    if (!(g_game_frame & 4)) goto skip_2;
    reg_d1.h[0] += 4;
skip_2:
    reg_a0 = (u8 *)small_tank_b_body_sprites;
    ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
block_obj:
    reg_tmp.h[1] = SMALL_TANK(reg_a5)->draw_body[0];
    reg_tmp.h[0] = SMALL_TANK(reg_a5)->draw_body[1];
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_call_target = (Fn)reg_a0;
    reg_call_target();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    if ((s8) SMALL_TANK(reg_a5)->damage >= 0) goto block_turret;
    if (g_frame_mod2 == 0) return;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.w = 0;
    reg_d1.w += 0x0100FE00;
    reg_d2.h[0] = SMALL_TANK(reg_a5)->smoke_frame;
    reg_d2.h[0] += 1;
    if (reg_d2.h[0] != 4) goto skip_3;
    reg_d2.w = 0;
skip_3:
    SMALL_TANK(reg_a5)->smoke_frame = reg_d2.h[0];
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = 0x1E;
    reg_d2.w += 0x13D8;
    sprite_draw_layer2();
    return;
block_turret:
    if (g_enemies_stopped != 0) goto block_turret_obj;
    reg_d1.b[0] = SMALL_TANK(reg_a5)->turret_dir;
    reg_tmp.b[0] = SMALL_TANK(reg_a5)->turn_countdown;
    SMALL_TANK(reg_a5)->turn_countdown -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto block_shotint;
    SMALL_TANK(reg_a5)->turn_countdown = SMALL_TANK(reg_a5)->turn_interval;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x200;
    aim_at_player();
    if (cond_flag != 0) goto block_turret_obj;
    reg_d0.b[0] = SMALL_TANK(reg_a5)->turret_dir;
    direction_turn_toward();
    SMALL_TANK(reg_a5)->turret_dir = reg_d1.b[0];
    reg_a0 = (u8 *)small_tank_b_turret_sprites;
    reg_d1.b[0] += 1;
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    SMALL_TANK(reg_a5)->turret_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    SMALL_TANK(reg_a5)->turret_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
block_shotint:
    SMALL_TANK(reg_a5)->fire_countdown -= 1;
    if (SMALL_TANK(reg_a5)->fire_countdown == 0) goto block_shot;
block_turret_obj:
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFC00FC00;
    reg_d2.h[1] = SMALL_TANK(reg_a5)->turret_sprite[0];
    reg_d2.h[0] = SMALL_TANK(reg_a5)->turret_sprite[1];
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_tmp.h[1] = SMALL_TANK(reg_a5)->draw_turret[0];
    reg_tmp.h[0] = SMALL_TANK(reg_a5)->draw_turret[1];
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_call_target = (Fn)reg_a0;
    reg_call_target();
    return;
block_shot:
    reg_d0.h[0] = 0xA0;
    reg_d0.h[0] -= g_rank_10_16;
    reg_d0.h[0] += 4;
    SMALL_TANK(reg_a5)->fire_countdown = reg_d0.b[0];
    enemy_fire_zone_check();
    if (cond_flag != 0) goto block_turret_obj;
    if (!(ENTITY(reg_a6)->flags.b[1] & 0x20)) goto block_turret_obj;
    reg_d1.b[0] = SMALL_TANK(reg_a5)->turret_dir;
    reg_a0 = (u8 *)small_tank_b_muzzles;
    reg_d1.b[0] += 2;
    reg_d1.h[0] &= 0x3C;
    reg_d2.h[0] = reg_d1.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.w += reg_tmp.w;
    reg_d0.w = 0xD;
    reg_d3.w = 0x02000000;
    bullet_fire_fast();
    goto block_turret_obj;
block_dead:
    reg_d0.w = 0x10;
    score_add();
    reg_d0.w = 7;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 8;
    EXPLOSION(reg_a0)->follows_scroll = 2;
    EXPLOSION(reg_a0)->start_y = 0xFE00;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0;
    reg_d0.w = 4;
    reg_d1.h[0] = 4;
    wreck_spawn();
    sfx_explosion_air_small();
    enemy_remove();
}
