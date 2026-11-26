#include "common.h"
#include "player.h"
#include "enemy.h"

/*
 * What the enemies of this unit keep in the enemy state block (reg_a5), after what every enemy has
 * (EnemyState). The mid flyers have two sets of guns that fire bursts in turn: `first` and `second`. A pair
 * named interval/countdown or shots/shots_left is a value and the counter loaded from it.
 */
#define MID_FLYER_GUNS \
    /* 0x16 */ u8 other_16; \
    /* 0x17 */ u8 seen;               /* it has been on the screen; when it is off it again it is removed */ \
    /* 0x18 */ u16 second_guns;       /* 0: the first guns fire, 1: the second */ \
    /* 0x1A */ u8 other_1A[2]; \
    /* 0x1C */ u8 hit_palette;        /* mixed into the palette on the frame of a hit */ \
    /* 0x1D */ u8 palette; \
    /* 0x1E */ u8 first_pause; \
    /* 0x1F */ u8 first_countdown; \
    /* 0x20 */ u8 first_shots; \
    /* 0x21 */ u8 first_shots_left; \
    /* 0x22 */ u8 second_pause; \
    /* 0x23 */ u8 second_countdown; \
    /* 0x24 */ u8 second_shots; \
    /* 0x25 */ u8 second_shots_left; \
    /* 0x26 */ u8 turn_interval;      /* frames between two turns of the turrets towards the player */ \
    /* 0x27 */ u8 turn_countdown;

typedef struct {
    /* 0x00 */ u8 common[0x16];
    MID_FLYER_GUNS
    /* 0x28 */ u16 turret_a_sprite[2];
    /* 0x2C */ Field16 turret_a_dir;
    /* 0x2E */ u16 turret_b_sprite[2];
    /* 0x32 */ Field16 turret_b_dir;
    /* 0x34 */ u8 second_interval;    /* frames between the shots of a burst */
    /* 0x35 */ u8 first_interval;
    /* 0x36 */ u16 hp;
    /* 0x38 */ u8 other_38[0xC];
    /* 0x44 */ u16 after_entities[2]; /* where enemy_init_entities stopped in its table */
} MidFlyerAState;

#define MID_FLYER_A(pointer) ((MidFlyerAState *)(pointer))

typedef struct {
    /* 0x00 */ u8 common[0x16];
    MID_FLYER_GUNS
    /* 0x28 */ u8 second_interval;
    /* 0x29 */ u8 first_interval;
    /* 0x2A */ u16 hp;
    /* 0x2C */ u8 other_2C[0x18];
    /* 0x44 */ u16 after_entities[2];
} MidFlyerBState;

#define MID_FLYER_B(pointer) ((MidFlyerBState *)(pointer))

typedef struct {
    /* 0x00 */ u8 common[0x16];
    MID_FLYER_GUNS
    /* 0x28 */ u16 turret_sprite[2];
    /* 0x2C */ Field16 turret_dir;
    /* 0x2E */ u8 second_interval;
    /* 0x2F */ u8 first_interval;
    /* 0x30 */ u8 aim[2];             /* the directions its two first guns' burst goes in */
    /* 0x32 */ u8 other_32[0x12];
    /* 0x44 */ u16 after_entities[2];
} MidFlyerCState;

#define MID_FLYER_C(pointer) ((MidFlyerCState *)(pointer))

/* The item carrier and the bomb carrier: one turret that turns towards the player and fires bursts. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 other_16;
    /* 0x17 */ u8 seen;
    /* 0x18 */ u8 other_18[4];
    /* 0x1C */ u8 hit_palette;
    /* 0x1D */ u8 palette;
    /* 0x1E */ u8 other_1E;
    /* 0x1F */ u8 shot_countdown;
    /* 0x20 */ u8 shots;
    /* 0x21 */ u8 shots_left;
    /* 0x22 */ u8 turn_interval;
    /* 0x23 */ u8 turn_countdown;
    /* 0x24 */ u16 turret_sprite[2];
    /* 0x28 */ Field16 turret_dir;
    /* 0x2A */ u8 other_2A[0x1A];
    /* 0x44 */ u16 after_entities[2]; /* where enemy_init_entities stopped in its table */
} CarrierState;

#define CARRIER(pointer) ((CarrierState *)(pointer))

/* The mid tank that crosses the screen: two turrets that turn together and fire bursts. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 other_16;
    /* 0x17 */ u8 seen;
    /* 0x18 */ u8 other_18[4];
    /* 0x1C */ u8 hit_palette;
    /* 0x1D */ u8 palette;
    /* 0x1E */ u8 other_1E;
    /* 0x1F */ u8 shot_countdown;
    /* 0x20 */ u8 shots;
    /* 0x21 */ u8 shots_left;
    /* 0x22 */ u8 turn_interval;
    /* 0x23 */ u8 turn_countdown;
    /* 0x24 */ u16 turret_a_sprite[2];
    /* 0x28 */ Field16 turret_a_dir;
    /* 0x2A */ u16 turret_b_sprite[2];
    /* 0x2E */ Field16 turret_b_dir;
    /* 0x30 */ u8 shot_interval;
    /* 0x31 */ u8 other_31;
    /* 0x32 */ u8 variants;
    /* 0x33 */ u8 variant;            /* counts down from `variants`; its bits pick what a burst fires */
    /* 0x34 */ u8 other_34[0x10];
    /* 0x44 */ u16 after_entities[2];
} MidTankHState;

#define MID_TANK_H(pointer) ((MidTankHState *)(pointer))

/* Mid flyer E: a hatch that opens, fires and shuts, and a gun that fires bursts. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 other_16;
    /* 0x17 */ u8 seen;
    /* 0x18 */ u16 hatch_state;       /* 0: shut, 1: opening, 2: firing, 3: shutting */
    /* 0x1A */ u8 hit_palette;
    /* 0x1B */ u8 palette;
    /* 0x1C */ u8 other_1C;
    /* 0x1D */ u8 hatch_wait;         /* frames to the hatch's next step or shot */
    /* 0x1E */ u8 hatch_shots;
    /* 0x1F */ u8 hatch_shots_left;
    /* 0x20 */ u16 hatch_frame;       /* byte offset into its table of pictures */
    /* 0x22 */ u8 frame_interval;
    /* 0x23 */ u8 frame_countdown;
    /* 0x24 */ u16 hatch_sprite[2];
    /* 0x28 */ u8 other_28[2];
    /* 0x2A */ u8 gun_pause;
    /* 0x2B */ u8 gun_countdown;
    /* 0x2C */ u8 gun_shots;
    /* 0x2D */ u8 gun_shots_left;
    /* 0x2E */ u8 hatch_shot_interval;
    /* 0x2F */ u8 gun_interval;
} MidFlyerEState;

#define MID_FLYER_E(pointer) ((MidFlyerEState *)(pointer))

/* Mid flyer D: guns that fire bursts while a player is in range, and a cannon that slides out to fire. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 player_in_range;
    /* 0x17 */ u8 seen;
    /* 0x18 */ u8 other_18[4];
    /* 0x1C */ u8 hit_palette;
    /* 0x1D */ u8 palette;
    /* 0x1E */ u8 other_1E;
    /* 0x1F */ u8 first_countdown;
    /* 0x20 */ u8 first_shots;
    /* 0x21 */ u8 first_shots_left;
    /* 0x22 */ u8 second_pause;
    /* 0x23 */ u8 second_countdown;
    /* 0x24 */ u8 other_24[4];
    /* 0x28 */ u16 part_sprite[2];
    /* 0x2C */ u16 cannon_step;       /* byte offset into the cannon's table of steps; it counts down from 0x48 */
    /* 0x2E */ u16 cannon_offset;     /* how far out the cannon is drawn */
    /* 0x30 */ u8 second_interval;
    /* 0x31 */ u8 first_interval;
    /* 0x32 */ u16 cannon_firing;
    /* 0x34 */ u8 other_34[0x10];
    /* 0x44 */ u16 after_entities[2];
} MidFlyerDState;

#define MID_FLYER_D(pointer) ((MidFlyerDState *)(pointer))

/* The bee container and the star container. The words are not identified: the star container hands
   `first` on when it is destroyed, the bee container counts `first` down and hands `second` on. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 other_16;
    /* 0x17 */ u8 seen;
    /* 0x18 */ u16 first;
    /* 0x1A */ u16 second;
} ContainerState;

#define CONTAINER(pointer) ((ContainerState *)(pointer))

typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 other_16[2];
    /* 0x18 */ u16 hp[2];             /* hit points as a 32-bit value, high word first */
} ShooterDroneState;

#define SHOOTER_DRONE(pointer) ((ShooterDroneState *)(pointer))

/* The mid tank that drives up or down the screen: a hatch that opens for two barrels to fire. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 other_16;
    /* 0x17 */ u8 seen;
    /* 0x18 */ u16 hatch_state;       /* 0: shut, 1: opening, 2: firing, 3: shutting */
    /* 0x1A */ u8 other_1A[2];
    /* 0x1C */ u8 hit_palette;
    /* 0x1D */ u8 palette;
    /* 0x1E */ u8 other_1E;
    /* 0x1F */ u8 shot_countdown;
    /* 0x20 */ u8 shots;
    /* 0x21 */ u8 shots_left;
    /* 0x22 */ u16 hatch_frame;
    /* 0x24 */ u16 hatch_offset;      /* how far the hatch's halves are apart */
    /* 0x26 */ u16 barrel_a_x;
    /* 0x28 */ u16 barrel_b_x;
    /* 0x2A */ u8 unread_2A;          /* the three `unread` bytes are set at the start and not read here */
    /* 0x2B */ u8 unread_2B;
    /* 0x2C */ u16 recoil;
    /* 0x2E */ u8 other_2E;
    /* 0x2F */ u8 unread_2F;
    /* 0x30 */ u8 other_30[0x14];
    /* 0x44 */ u16 after_entities[2];
} MidTankVState;

#define MID_TANK_V(pointer) ((MidTankVState *)(pointer))

/* The second mid tank that crosses the screen: one turret, and tracks that are animated. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 other_16;
    /* 0x17 */ u8 seen;
    /* 0x18 */ u8 other_18[4];
    /* 0x1C */ u8 hit_palette;
    /* 0x1D */ u8 palette;
    /* 0x1E */ u8 other_1E;
    /* 0x1F */ u8 shot_countdown;
    /* 0x20 */ u8 shots;
    /* 0x21 */ u8 shots_left;
    /* 0x22 */ u8 turn_interval;
    /* 0x23 */ u8 turn_countdown;
    /* 0x24 */ u16 turret_sprite[2];
    /* 0x28 */ Field16 turret_dir;
    /* 0x2A */ u8 other_2A;
    /* 0x2B */ u8 shot_interval;
    /* 0x2C */ u8 pause;
    /* 0x2D */ u8 pause_countdown;
    /* 0x2E */ u16 turret_x;          /* where the turret sits on the body */
    /* 0x30 */ u16 armed;
    /* 0x32 */ Field16 variant;       /* from its path's PATH_USER */
    /* 0x34 */ u8 other_34;
    /* 0x35 */ u8 track_countdown;
    /* 0x36 */ u16 track_frame;
    /* 0x38 */ u8 other_38[0xC];
    /* 0x44 */ u16 after_entities[2];
} MidTankHBState;

#define MID_TANK_HB(pointer) ((MidTankHBState *)(pointer))

/* The water flower turret: it bobs, its petals are animated, and it turns and fires bursts like a turret. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 other_16;
    /* 0x17 */ u8 seen;
    /* 0x18 */ u8 hit_palette;
    /* 0x19 */ u8 palette;
    /* 0x1A */ u8 other_1A;
    /* 0x1B */ u8 shot_countdown;
    /* 0x1C */ u8 shots;
    /* 0x1D */ u8 shots_left;
    /* 0x1E */ u8 turn_interval;
    /* 0x1F */ u8 turn_countdown;
    /* 0x20 */ u16 petal_sprite[2];
    /* 0x24 */ Field16 dir;
    /* 0x26 */ u8 frame_interval;
    /* 0x27 */ u8 frame_countdown;
    /* 0x28 */ u16 petal_frame;       /* byte offset into the petals' pictures; it counts down from 0x14 */
    /* 0x2A */ Field16 bob_angle;
    /* 0x2C */ u16 bob;               /* what the bobbing adds to its position this frame */
} WaterFlowerState;

#define WATER_FLOWER(pointer) ((WaterFlowerState *)(pointer))

/* The three ground turrets: they turn towards the player and fire bursts along their direction. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 shot_interval;
    /* 0x17 */ u8 seen;
    /* 0x18 */ u8 hit_palette;
    /* 0x19 */ u8 palette;
    /* 0x1A */ u8 other_1A;
    /* 0x1B */ u8 shot_countdown;
    /* 0x1C */ u8 shots;
    /* 0x1D */ u8 shots_left;
    /* 0x1E */ u8 turn_interval;
    /* 0x1F */ u8 turn_countdown;
    /* 0x20 */ Field16 dir;
} GroundTurretState;

#define GROUND_TURRET(pointer) ((GroundTurretState *)(pointer))
#include "entity.h"
#include "explosion.h"

extern void enemy_set_entity_count(s32);

void mid_flyer_a_first(void) {
    enemy_set_entity_count(1);
}


s32 aim_at_player();
extern u16 g_direction_sprites_g[];
extern s8 D_0025A070[];
extern s8 D_0025A080[];
extern s8 D_0025A0B0[];
extern u16 g_rank_2_16;
extern u16 g_loop;
extern u16 g_stage_x2;
extern u16 g_stage;
extern s8 enemy_move_end_requested;

void mid_flyer_a_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    (*(s8 **)&reg_a0) = D_0025A0B0;
    enemy_init_entities();
    reg_tmp.w = (u32) ((s8 *)reg_a0);
    MID_FLYER_A(reg_a5)->after_entities[0] = (u16) reg_tmp.h[1];
    MID_FLYER_A(reg_a5)->after_entities[1] = (u16) reg_tmp.h[0];
    (*(s8 **)&reg_a0) = D_0025A080;
    reg_d0.w = 0x10;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if (g_loop != 0) {
            reg_d0.h[0] = 0x1200;
            ENTITY(reg_a6)->hp.h = (u16) reg_d0.h[0];
            ENTITY(reg_a6)[1].hp.h = (u16) reg_d0.h[0];
        }
        reg_a2 = (u8 *)(g_direction_sprites_g);
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x680;
        reg_d1.h[0] += 0x500;
        aim_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        MID_FLYER_A(reg_a5)->turret_a_dir.b[0] = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        MID_FLYER_A(reg_a5)->turret_a_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        MID_FLYER_A(reg_a5)->turret_a_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x680;
        reg_d1.h[0] += 0x7FFF + 0x7B01;
        aim_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        MID_FLYER_A(reg_a5)->turret_b_dir.b[0] = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        MID_FLYER_A(reg_a5)->turret_b_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        MID_FLYER_A(reg_a5)->turret_b_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d0.b[0] = 0x10;
        reg_d1.b[0] = 4;
        if ((s32) g_stage > 1) {
            reg_d0.b[0] = 0x10;
            reg_d1.b[0] = 4;
        }
        MID_FLYER_A(reg_a5)->first_interval = (u8) reg_d0.b[0];
        MID_FLYER_A(reg_a5)->second_interval = (u8) reg_d1.b[0];
        if (g_stage == 4) {
            reg_d0.h[0] = 5;
            MID_FLYER_A(reg_a5)->first_shots_left = (u8) reg_d0.b[0];
            MID_FLYER_A(reg_a5)->first_shots = (u8) reg_d0.b[0];
            reg_d0.h[0] = 8;
            MID_FLYER_A(reg_a5)->second_shots_left = (u8) reg_d0.b[0];
            MID_FLYER_A(reg_a5)->second_shots = (u8) reg_d0.b[0];
            MID_FLYER_A(reg_a5)->first_interval = 0xCU;
            reg_d0.h[0] = 0x7FFF;
            ENTITY(reg_a6)->hp.h = (u16) reg_d0.h[0];
            ENTITY(reg_a6)[1].hp.h = (u16) reg_d0.h[0];
            MID_FLYER_A(reg_a5)->hp = 0x30;
        }
        reg_d0.h[0] = g_rank_2_16;
        MID_FLYER_A(reg_a5)->first_countdown -= reg_d0.b[0];
        reg_d0.h[0] = g_rank_2_16;
        reg_d0.b[0] -= 8;
        MID_FLYER_A(reg_a5)->second_countdown -= reg_d0.b[0];
        (*(s8 **)&reg_a0) = D_0025A070;
        reg_d0.h[0] = g_stage_x2;
        (*(s8 **)&reg_a0) = &(*(s8 **)&reg_a0)[reg_d0.h[0]];
        ENTITY(reg_a6)->attr.sb.palette = (s8) *((s8 *)reg_a0);
        MID_FLYER_A(reg_a5)->palette = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
        MID_FLYER_A(reg_a5)->hit_palette = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
    }
}

s32 bullet_fire_3way();
s32 bullet_fire256_3way();
s32 bullet_fire256();
s32 enemy_anims_spawn_listed();
s32 explosion_spawn();
s32 enemy_hitbox_debug_draw();
s32 enemy_remove();
s32 enemy_path_step();
s32 sfx_explosion_ground_large();
s32 entity_draw_layer5();
s32 sprite_draw_layer4();
s32 sprite_draw_layer5();
s32 score_add_no_chain();
s32 score_add();
s32 direction_between();
s32 direction_turn_toward();
s32 direction256_between();
extern u16 g_direction_offsets_600[];
extern u16 g_direction64_offsets_2CC[];
extern u16 g_direction64_offsets_432[];
extern u16 g_frame_mod2;
extern u16 g_bullets_blocked;
extern u16 g_enemies_stopped;
extern u16 g_damage_blink_counter;
extern u16 g_rank_3_16;
extern u16 g_side_scroll_x[];
extern u16 g_bomb_entities[];
extern s16 g_player2[];
extern s16 g_player1[];

void mid_flyer_a(void) {
    u32 cnt;
    u8 bits;
    u8 *ptr;

    enemy_path_step();
    if (enemy_move_end_requested != 0) return;
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x1800;
    reg_d0.h[0] += g_side_scroll_x[0];
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x9800;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x9800;
    if (reg_tmp.h[1] != 0) goto next_20;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x7400;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] += 0x1400;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x7400;
    if (reg_tmp.h[1] == 0) goto next_30;
next_20:
    if (MID_FLYER_A(reg_a5)->seen == 0) goto next_40;
    enemy_remove();
    return;
next_30:
    MID_FLYER_A(reg_a5)->seen = 1;
next_40:
    ENTITY(reg_a6)[1].y.h = ENTITY(reg_a6)->y.h;
    ENTITY(reg_a6)[1].x.h = ENTITY(reg_a6)->x.h;
    if ((s16) MID_FLYER_A(reg_a5)->hp < 0) goto next_45;
    reg_d0.h[0] = 0x7FFF;
    ENTITY(reg_a6)->hp.h = reg_d0.h[0];
    ENTITY(reg_a6)[1].hp.h = reg_d0.h[0];
    reg_d0.h[0] = 1;
    if (g_bomb_entities[0] == 0) goto next_42;
    reg_d0.h[0] = 2;
next_42:
    reg_tmp.h[0] = MID_FLYER_A(reg_a5)->hp;
    MID_FLYER_A(reg_a5)->hp -= reg_d0.h[0];
    if (!((s32) reg_tmp.h[0] < (s32) reg_d0.h[0])) goto next_45;
    reg_d0.h[0] = 0x1400;
    ENTITY(reg_a6)->hp.h = reg_d0.h[0];
    ENTITY(reg_a6)[1].hp.h = reg_d0.h[0];
next_45:
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[1].flags.b[1];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) goto next_50;
    reg_d0.b[0] = MID_FLYER_A(reg_a5)->palette;
    if (!((s32) ENTITY(reg_a6)->hp.h < 0x255)) goto next_90;
    if (g_damage_blink_counter != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    reg_d0.h[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    if (reg_d0.b[0] != 0x19) goto next_60;
    reg_d0.b[0] = MID_FLYER_A(reg_a5)->palette;
next_60:
    reg_d2.b[0] = MID_FLYER_A(reg_a5)->hit_palette;
    reg_d0.b[0] ^= reg_d2.b[0];
    reg_d4.h[0] = ENTITY(reg_a6)->hp.h;
    if (!((s16) ENTITY(reg_a6)[1].hp.h < (s16) reg_d4.h[0])) goto next_80;
    reg_d4.h[0] = ENTITY(reg_a6)[1].hp.h;
next_80:
    ENTITY(reg_a6)->hp.h = reg_d4.h[0];
    ENTITY(reg_a6)[1].hp.h = reg_d4.h[0];
    if ((s16) ENTITY(reg_a6)->hp.h < 0) goto next_700;
next_90:
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    enemy_anims_spawn_listed();
    if (g_enemies_stopped != 0) goto next_500;
    if (g_bullets_blocked != 0) goto next_500;
    if (MID_FLYER_A(reg_a5)->second_guns != 0) goto next_300;
    if ((s16) ENTITY(reg_a6)->y.h < 0x1000) goto next_300;
    reg_tmp.b[0] = MID_FLYER_A(reg_a5)->first_countdown;
    MID_FLYER_A(reg_a5)->first_countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_300;
    MID_FLYER_A(reg_a5)->first_countdown = MID_FLYER_A(reg_a5)->first_interval;
    reg_a0 = (u8 *) ((u16 *)g_player1);
    reg_a1 = (u8 *) ((u16 *)g_player2);
    if (ENEMY_STATE(reg_a5)->target_player == 0) goto next_240;
    reg_atmp = (u8 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) reg_atmp;
next_240:
    if (*(s16 *)reg_a0 < 0) goto next_260;
    if (*(s16 *)reg_a1 >= 0) goto next_290;
    ptr = reg_a0;
    reg_a0 = reg_a1;
    reg_atmp = (u8 *) ptr;
    reg_a1 = ptr;
next_260:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0xFE00;
    direction256_between();
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d5.w = 0xFE000000;
    reg_d4.w = 0;
    if (g_stage != 4) goto next_262;
    if (MID_FLYER_A(reg_a5)->first_shots_left != 5) goto next_261;
    reg_d0.w = 4;
    goto next_264;
next_261:
    if (MID_FLYER_A(reg_a5)->first_shots_left == 4) goto next_263;
    goto next_270;
next_262:
    if (MID_FLYER_A(reg_a5)->first_shots_left != 1) goto next_270;
next_263:
    reg_d0.w = 4;
    if (g_stage != 4) goto next_264;
    reg_d0.w = 0xFFFF0004;
next_264:
    reg_d1.b[0] -= 0x1C;
    reg_d6.w = 8;
    reg_d7.w = 7;
    reg_a0 = (u8 *) g_direction64_offsets_2CC;
loop_265:
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d5.w;
    bullet_fire256();
    reg_d1.h[0] += reg_d6.h[0];
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_265;
    goto next_290;
next_270:
    reg_d0.w = 0xFFFF0005;
    if (g_stage != 4) goto next_274;
    reg_d0.w = 0xFFFE0004;
next_274:
    reg_d1.b[0] -= 0x24;
    reg_d6.w = 0xC;
    reg_d7.w = 6;
    reg_a0 = (u8 *) g_direction64_offsets_432;
loop_280:
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d5.w;
    bullet_fire256_3way();
    reg_d1.h[0] += reg_d6.h[0];
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_280;
next_290:
    reg_tmp.b[0] = MID_FLYER_A(reg_a5)->first_shots_left;
    MID_FLYER_A(reg_a5)->first_shots_left -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_300;
    MID_FLYER_A(reg_a5)->first_shots_left = MID_FLYER_A(reg_a5)->first_shots;
    reg_d0.h[0] = 0x50;
    reg_d0.h[0] -= g_rank_3_16;
    MID_FLYER_A(reg_a5)->first_countdown = reg_d0.b[0];
    MID_FLYER_A(reg_a5)->second_guns = 1;
next_300:
    reg_tmp.b[0] = MID_FLYER_A(reg_a5)->turn_countdown;
    MID_FLYER_A(reg_a5)->turn_countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_500;
    MID_FLYER_A(reg_a5)->turn_countdown = MID_FLYER_A(reg_a5)->turn_interval;
    reg_d0.b[0] = MID_FLYER_A(reg_a5)->second_shots_left;
    if (MID_FLYER_A(reg_a5)->second_shots != reg_d0.b[0]) goto next_500;
    reg_a0 = (u8 *) ((u16 *)g_player1);
    reg_a1 = (u8 *) ((u16 *)g_player2);
    if (ENEMY_STATE(reg_a5)->target_player == 0) goto next_320;
    reg_atmp = (u8 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) reg_atmp;
next_320:
    if (*(s16 *)reg_a0 < 0) goto next_340;
    if (*(s16 *)reg_a1 >= 0) goto next_500;
    ptr = reg_a0;
    reg_a0 = reg_a1;
    reg_atmp = (u8 *) ptr;
    reg_a1 = ptr;
next_340:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_a3 = (u8 *) g_direction_sprites_g;
    bits = ENTITY(reg_a6)->flags.b[0];
    if (bits & 0x40) {
        ENTITY(reg_a6)->flags.b[0] = bits & 0xBF;
        goto next_380;
    }
    ENTITY(reg_a6)->flags.b[0] = bits | 0x40;
    reg_d0.h[0] += 0x680;
    reg_d1.h[0] += 0x500;
    direction_between();
    reg_d0.h[0] = MID_FLYER_A(reg_a5)->turret_a_dir.h;
    direction_turn_toward();
    MID_FLYER_A(reg_a5)->turret_a_dir.h = reg_d1.h[0];
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    MID_FLYER_A(reg_a5)->turret_a_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a3 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    MID_FLYER_A(reg_a5)->turret_a_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a3 + ((s16) (reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
    goto next_500;
next_380:
    reg_d0.h[0] += 0x680;
    reg_d1.h[0] += 0xFB00;
    direction_between();
    reg_d0.h[0] = MID_FLYER_A(reg_a5)->turret_b_dir.h;
    direction_turn_toward();
    MID_FLYER_A(reg_a5)->turret_b_dir.h = reg_d1.h[0];
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    MID_FLYER_A(reg_a5)->turret_b_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a3 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    MID_FLYER_A(reg_a5)->turret_b_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a3 + ((s16) (reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
next_500:
    entity_draw_layer5();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[1] += 0x80;
    reg_d2.h[1] = MID_FLYER_A(reg_a5)->turret_a_sprite[0];
    reg_d2.h[0] = MID_FLYER_A(reg_a5)->turret_a_sprite[1];
    reg_d3.h[0] = 0x628;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    sprite_draw_layer5();
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0xF600;
    reg_d2.h[1] = MID_FLYER_A(reg_a5)->turret_b_sprite[0];
    reg_d2.h[0] = MID_FLYER_A(reg_a5)->turret_b_sprite[1];
    sprite_draw_layer5();
    if (g_loop != 0) goto next_520;
    if (g_frame_mod2 == 0) goto next_520;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[1] += 0xD600;
    reg_d2.w = 0x186C;
    reg_d3.h[0] = 0xA40;
    reg_d4.h[0] = 0x18;
    sprite_draw_layer4();
next_520:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x20;
    enemy_hitbox_debug_draw();
    if (MID_FLYER_A(reg_a5)->second_guns == 0) goto block_rts;
    if (g_enemies_stopped != 0) goto block_rts;
    if (g_bullets_blocked != 0) goto block_rts;
    if ((s16) ENTITY(reg_a6)->y.h < 0x1000) goto block_rts;
    reg_tmp.b[0] = MID_FLYER_A(reg_a5)->second_countdown;
    MID_FLYER_A(reg_a5)->second_countdown -= 1;
    if (reg_tmp.b[0] == 0) goto next_600;
block_rts:
    return;
next_600:
    MID_FLYER_A(reg_a5)->second_countdown = MID_FLYER_A(reg_a5)->second_interval;
    reg_a4 = (u8 *) g_direction_offsets_600;
    reg_d0.w = 0x20013;
    if (g_stage != 4) goto next_620;
    reg_d0.w = 0x70013;
next_620:
    reg_d1.h[0] = MID_FLYER_A(reg_a5)->turret_a_dir.h;
    reg_d5.h[0] = reg_d1.h[0];
    reg_d5.h[0] &= 0x3E;
    reg_d5.h[0] += reg_d5.h[0];
    reg_d3.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)(reg_a4 + ((s16) reg_d5.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16) reg_d5.h[0] + 2) != 0) ? *(u16 *)(reg_a4 + ((s16) ((u16) reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] += 0x500;
    reg_d3.h[1] += 0x680;
    reg_d4.w = 0;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    bullet_fire_3way();
    reg_d1.h[0] = MID_FLYER_A(reg_a5)->turret_b_dir.h;
    reg_d5.h[0] = reg_d1.h[0];
    reg_d5.h[0] &= 0x3E;
    reg_d5.h[0] += reg_d5.h[0];
    reg_d3.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)(reg_a4 + ((s16) reg_d5.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16) reg_d5.h[0] + 2) != 0) ? *(u16 *)(reg_a4 + ((s16) ((u16) reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] += 0xFB00;
    reg_d3.h[1] += 0x680;
    bullet_fire_3way();
    reg_tmp.b[0] = MID_FLYER_A(reg_a5)->second_shots_left;
    MID_FLYER_A(reg_a5)->second_shots_left -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_650;
    MID_FLYER_A(reg_a5)->second_shots_left = MID_FLYER_A(reg_a5)->second_shots;
    reg_d0.h[0] = 0x30;
    reg_d0.h[0] -= g_rank_3_16;
    MID_FLYER_A(reg_a5)->second_countdown = reg_d0.b[0];
    MID_FLYER_A(reg_a5)->second_guns = 0;
next_650:
    return;
next_700:
    reg_d0.w = 0x83;
    score_add();
    sfx_explosion_ground_large();
    reg_d0.w = 0xD;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0xF800;
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    reg_d0.h[0] = 0x84;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0xF600;
    EXPLOSION(reg_a0)->start_x = 0x600;
    EXPLOSION(reg_a0)->move.h = 0x754;
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0;
    reg_d0.h[0] = 0x84;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0xF600;
    EXPLOSION(reg_a0)->start_x = 0xFA00;
    EXPLOSION(reg_a0)->move.h = 0x7AC;
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    EXPLOSION(reg_a0)->attr.b.flip = 0x40;
    reg_d0.w = 0xD;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0xF200;
    EXPLOSION(reg_a0)->start_x = 0xFE00;
    EXPLOSION(reg_a0)->move.h = 0x798;
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->delay = 2;
    reg_d0.w = 0xD;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0xF200;
    EXPLOSION(reg_a0)->start_x = 0x100;
    EXPLOSION(reg_a0)->move.h = 0x768;
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->delay = 4;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0xF600;
    EXPLOSION(reg_a0)->start_x = 0;
    EXPLOSION(reg_a0)->move.h = 0xC80;
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    EXPLOSION(reg_a0)->delay = 4;
    enemy_remove();
}

void mid_flyer_b_first(void) {
    enemy_set_entity_count(1);
}

extern u16 g_direction_sprites_d[];
extern s8 D_0025A128[];
extern s8 D_0025A140[];
extern s8 D_0025A160[];
extern u16 g_rank_7_16;
extern s16 g_bullet_limit_raised_1[];
extern s16 g_bullet_limit_raised_2[];

void mid_flyer_b_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    (*(s8 **)&reg_a0) = D_0025A160;
    enemy_init_entities();
    reg_tmp.w = (u32) ((s8 *)reg_a0);
    MID_FLYER_B(reg_a5)->after_entities[0] = (u16) reg_tmp.h[1];
    MID_FLYER_B(reg_a5)->after_entities[1] = (u16) reg_tmp.h[0];
    (*(s8 **)&reg_a0) = D_0025A140;
    reg_d0.w = 0xA;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_a2 = (u8 *)(g_direction_sprites_d);
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x5C0;
        reg_d1.h[0] += 0xA40;
        aim_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        ENTITY(reg_a6)[1].draw.b.flip = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)[1].offset_y.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        ENTITY(reg_a6)[1].offset_x.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x5C0;
        reg_d1.h[0] += 0x7FFF + 0x7601;
        aim_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        ENTITY(reg_a6)[1].hit_y_plus.b[0] = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)[1].sprite.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        ENTITY(reg_a6)[1].look.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d0.b[0] = 0x10;
        reg_d1.b[0] = 8;
        if ((s32) g_stage > 1) {
            reg_d0.b[0] = 0x10;
            reg_d1.b[0] = 8;
        }
        MID_FLYER_B(reg_a5)->first_interval = (u8) reg_d0.b[0];
        MID_FLYER_B(reg_a5)->second_interval = (u8) reg_d1.b[0];
        reg_d0.h[0] = g_rank_7_16;
        MID_FLYER_B(reg_a5)->first_countdown -= reg_d0.b[0];
        (*(s8 **)&reg_a0) = D_0025A128;
        reg_d0.h[0] = g_stage_x2;
        (*(s8 **)&reg_a0) = &(*(s8 **)&reg_a0)[reg_d0.h[0]];
        ENTITY(reg_a6)->attr.sb.palette = (s8) *((s8 *)reg_a0);
        MID_FLYER_B(reg_a5)->palette = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
        MID_FLYER_B(reg_a5)->hit_palette = (s8) *((s8 *)reg_a0);
        g_bullet_limit_raised_1[0] = 1;
        g_bullet_limit_raised_2[0] = 1;
        (*(s8 **)&reg_a0) += 1;
    }
}

s32 bullet_fire256_fixed();
s32 bullet_fire256_2way();
extern u16 g_direction_offsets_500[];
extern u16 g_direction64_offsets_166[];
extern u16 D_0025A1E0[];
extern u16 g_rank_4_16;
extern u16 g_rank_6_16;

void mid_flyer_b(void) {
    s16 *temp_a0;
    s16 *temp_v1;
    s16 *temp_v1_2;
    u32 temp_a0_3;
    u32 temp_a0_4;
    u32 temp_a1;
    u32 temp_a3;
    u32 temp_a3_2;
    u32 temp_a3_3;
    u16 var_a0_2;
    u8 temp_v1_3;

    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7A00;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0xE00;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x7A00;
        if (reg_tmp.h[1] != 0) {
            if (MID_FLYER_B(reg_a5)->seen != 0) {
                enemy_remove();
                return;
            }
            goto block_5;
        }
        MID_FLYER_B(reg_a5)->seen = 1U;
block_5:
        if ((s16) MID_FLYER_B(reg_a5)->hp >= 0) {
            ENTITY(reg_a6)->hp.h = 0x7FFFU;
            reg_d0.w = 1;
            if (((s16 *)g_bomb_entities)[0] < 0) {
                reg_d0.w = 2;
            }
            reg_tmp.h[0] = MID_FLYER_B(reg_a5)->hp;
            MID_FLYER_B(reg_a5)->hp -= reg_d0.h[0];
            if ((s32) reg_tmp.h[0] < (s32) reg_d0.h[0]) {
                ENTITY(reg_a6)->hp.h = 0x2600U;
            }
        }
        temp_a0 = (s16 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(temp_a0) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = MID_FLYER_B(reg_a5)->palette;
            if (((s32) (*(u16 *)((u8 *)(temp_a0) + (0x18))) < 0x980) && (g_damage_blink_counter == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_17;
        }
        (*(u8 *)((u8 *)(temp_a0) + (1))) &= 0xA3;
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = MID_FLYER_B(reg_a5)->palette;
        }
        reg_d2.b[0] = MID_FLYER_B(reg_a5)->hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
block_17:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            enemy_anims_spawn_listed();
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0)) {
                if ((s16) ENTITY(reg_a6)->y.h >= 0x1000) {
                    reg_d0.h[0] = ENTITY(reg_a6)[1].hp.h;
                    if (reg_d0.h[0] == 0) {
                        reg_tmp.b[0] = MID_FLYER_B(reg_a5)->first_countdown;
                        MID_FLYER_B(reg_a5)->first_countdown -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            MID_FLYER_B(reg_a5)->first_countdown = (u8) MID_FLYER_B(reg_a5)->first_interval;
                            ENTITY(reg_a6)[1].hp.h = 1U;
                        }
                    } else if ((reg_d0.h[0] & 0xFFFF) == 1) {
                        reg_tmp.b[0] = ENTITY(reg_a6)[1].move.b.speed;
                        ENTITY(reg_a6)[1].move.b.speed -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            ENTITY(reg_a6)[1].move.b.speed = (u8) ENTITY(reg_a6)[1].move.b.dir;
                            ENTITY(reg_a6)[1].hit_x_minus.h += 4;
                            reg_d0.h[0] = ENTITY(reg_a6)[1].hit_x_minus.h;
                            reg_a0 = (u8 *)(D_0025A1E0);
                            ENTITY(reg_a6)[1].hit_y_minus.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                            ENTITY(reg_a6)[1].hit_x_plus.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            if (reg_d0.h[0] == 0x14) {
                                ENTITY(reg_a6)[1].hp.h = 2U;
                            }
                        }
                    } else if ((reg_d0.h[0] & 0xFFFF) == 2) {
                        reg_tmp.b[0] = ENTITY(reg_a6)[1].move.b.speed;
                        ENTITY(reg_a6)[1].move.b.speed -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            ENTITY(reg_a6)[1].move.b.speed = (u8) ENTITY(reg_a6)[1].move.b.dir;
                            ENTITY(reg_a6)[1].hit_x_minus.h += 4;
                            if (ENTITY(reg_a6)[1].hit_x_minus.h == 0x18) {
                                ENTITY(reg_a6)[1].hit_x_minus.h = 0x10U;
                            }
                            reg_d0.h[0] = ENTITY(reg_a6)[1].hit_x_minus.h;
                            reg_a0 = (u8 *)(D_0025A1E0);
                            ENTITY(reg_a6)[1].hit_y_minus.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                            ENTITY(reg_a6)[1].hit_x_plus.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                        }
                        reg_tmp.b[0] = MID_FLYER_B(reg_a5)->first_countdown;
                        MID_FLYER_B(reg_a5)->first_countdown -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            MID_FLYER_B(reg_a5)->first_countdown = (u8) MID_FLYER_B(reg_a5)->first_interval;
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
                                    goto block_51;
                                }
                            } else {
block_51:
                                reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                                reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                                reg_d0.h[0] += 0xF780;
                                direction256_between();
                                reg_d6.h[0] = reg_d1.h[0];
                                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                temp_a1 = ENTITY(reg_a6)->x.h;
                                reg_d2.h[0] = temp_a1;
                                reg_d3.w = 0xF7800380;
                                reg_d0.w = 0xFFFD0005;
                                reg_d1.h[0] += 0xA;
                                reg_d4.w = 0;
                                bullet_fire256_2way();
                                reg_d1.h[0] -= 0x14;
                                bullet_fire256_2way();
                                reg_d3.w = 0xF780FC80;
                                reg_d1.h[0] = reg_d6.h[0];
                                reg_d1.h[0] += 0xA;
                                bullet_fire256_2way();
                                reg_d1.h[0] -= 0x14;
                                bullet_fire256_2way();
                            }
                            reg_tmp.b[0] = MID_FLYER_B(reg_a5)->first_shots_left;
                            MID_FLYER_B(reg_a5)->first_shots_left -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                MID_FLYER_B(reg_a5)->first_shots_left = (u8) MID_FLYER_B(reg_a5)->first_shots;
                                reg_d0.h[0] = 0x40;
                                reg_d0.h[0] -= g_rank_4_16;
                                MID_FLYER_B(reg_a5)->first_countdown = (u8) reg_d0.b[0];
                                ENTITY(reg_a6)[1].hp.h = 3U;
                            }
                        }
                    } else {
                        reg_tmp.b[0] = ENTITY(reg_a6)[1].move.b.speed;
                        ENTITY(reg_a6)[1].move.b.speed -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            ENTITY(reg_a6)[1].move.b.speed = (u8) ENTITY(reg_a6)[1].move.b.dir;
                            reg_tmp.h[0] = ENTITY(reg_a6)[1].hit_x_minus.h;
                            ENTITY(reg_a6)[1].hit_x_minus.h -= 4;
                            if ((s32) reg_tmp.h[0] < 4) {
                                ENTITY(reg_a6)[1].hp.h = 0U;
                            } else {
                                reg_d0.h[0] = ENTITY(reg_a6)[1].hit_x_minus.h;
                                reg_a0 = (u8 *)(D_0025A1E0);
                                ENTITY(reg_a6)[1].hit_y_minus.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                                ENTITY(reg_a6)[1].hit_x_plus.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            }
                        }
                    }
                }
                reg_tmp.b[0] = MID_FLYER_B(reg_a5)->turn_countdown;
                MID_FLYER_B(reg_a5)->turn_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    MID_FLYER_B(reg_a5)->turn_countdown = (u8) MID_FLYER_B(reg_a5)->turn_interval;
                    reg_d0.b[0] = MID_FLYER_B(reg_a5)->second_shots_left;
                    if (MID_FLYER_B(reg_a5)->second_shots == reg_d0.b[0]) {
                        reg_a0 = (u8 *)(((u16 *)g_player1));
                        reg_a1 = (u8 *)(((u16 *)g_player2));
                        switch (ENEMY_STATE(reg_a5)->target_player) { case 0: break; default:
                            reg_atmp = (u8 *)(reg_a0);
                            reg_a0 = (u8 *)(reg_a1);
                            reg_a1 = (u8 *)(reg_atmp);
                        }
                        temp_v1_2 = (s16 *)(reg_a0);
                        if ((*(s16 *)((u8 *)(temp_v1_2) + (0))) >= 0) {
                            if (*(s16 *)reg_a1 < 0) {
                                reg_a0 = (u8 *)(reg_a1);
                                reg_atmp = (u8 *)(temp_v1_2);
                                reg_a1 = (u8 *)(temp_v1_2);
                                goto block_71;
                            }
                        } else {
block_71:
                            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                            reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_a3 = (u8 *)(g_direction_sprites_d);
                            temp_v1_3 = ENTITY(reg_a6)->flags.b[0];
                            if (temp_v1_3 & 0x40) {
                                ENTITY(reg_a6)->flags.b[0] = (u8) (temp_v1_3 & 0xBF);
                                goto block_set;
                            }
                            ENTITY(reg_a6)->flags.b[0] = (u8) (temp_v1_3 | 0x40);
                            reg_d0.h[0] += 0x5C0;
                            reg_d1.h[0] += 0xA40;
                            direction_between();
                            reg_d0.h[0] = ENTITY(reg_a6)[1].draw.h;
                            direction_turn_toward();
                            ENTITY(reg_a6)[1].draw.h = (u16) reg_d1.h[0];
                            reg_d1.h[0] &= 0x3E;
                            reg_d1.h[0] += reg_d1.h[0];
                            ENTITY(reg_a6)[1].offset_y.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                            ENTITY(reg_a6)[1].offset_x.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                            goto block_join;
block_set:
                            reg_d0.h[0] += 0x5C0;
                            reg_d1.h[0] += 0xF600;
                            direction_between();
                            reg_d0.h[0] = ENTITY(reg_a6)[1].hit_y_plus.h;
                            direction_turn_toward();
                            ENTITY(reg_a6)[1].hit_y_plus.h = (u16) reg_d1.h[0];
                            reg_d1.h[0] &= 0x3E;
                            reg_d1.h[0] += reg_d1.h[0];
                            ENTITY(reg_a6)[1].sprite.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                            ENTITY(reg_a6)[1].look.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                        }
                    }
                }
            }
block_join:
            entity_draw_layer5();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            temp_a0_3 = reg_d1.h[0];
            reg_d1.h[1] += 0xF400;
            reg_d1.h[0] = (u32)temp_a0_3 + 0xFB00;
            reg_d2.h[1] = ENTITY(reg_a6)[1].hit_y_minus.h;
            reg_d2.h[0] = ENTITY(reg_a6)[1].hit_x_plus.h;
            reg_d3.h[0] = 0x428;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer5();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            temp_a0_4 = reg_d1.h[0];
            reg_d1.h[1] += 0xFFC0;
            reg_d1.h[0] = (u32)temp_a0_4 + 0x640;
            reg_d2.h[1] = ENTITY(reg_a6)[1].offset_y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[1].offset_x.h;
            reg_d3.h[0] = 0x620;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer5();
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] += 0xF200;
            reg_d2.h[1] = ENTITY(reg_a6)[1].sprite.h;
            reg_d2.h[0] = ENTITY(reg_a6)[1].look.h;
            sprite_draw_layer5();
            if ((g_loop == 0) && (g_frame_mod2 != 0)) {
                reg_d1.h[1] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d1.h[1] += 0xD400;
                reg_d1.h[0] += 0x100;
                reg_d2.w = 0x1874;
                reg_d3.h[0] = 0x848;
                reg_d4.h[0] = 0x18;
                sprite_draw_layer4();
            }
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0) && ((s16) ENTITY(reg_a6)->y.h >= 0x1000)) {
                reg_tmp.b[0] = MID_FLYER_B(reg_a5)->second_countdown;
                MID_FLYER_B(reg_a5)->second_countdown -= 1;
                switch (reg_tmp.b[0]) {
                case 0:
                    MID_FLYER_B(reg_a5)->second_countdown = (u8) MID_FLYER_B(reg_a5)->second_interval;
                    reg_a4 = (u8 *)(g_direction_offsets_500);
                    reg_d1.h[0] = ENTITY(reg_a6)[1].draw.h;
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] &= 0x3E;
                    reg_d5.h[0] += reg_d5.h[0];
                    reg_d5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a4;
                    reg_d5.h[0] = ((reg_d5.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)(reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
                    reg_d0.w = 0x40007;
                    reg_d4.w = 0;
                    reg_d5.h[0] += 0xA40;
                    reg_d5.h[1] += 0x5C0;
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d1.b[0] *= 4;
                    reg_d7.h[0] = 6;
                    reg_a0 = (u8 *)(g_direction64_offsets_166);
                    reg_d1.h[0] -= 0x2D;
                    do {
                        reg_d3.h[0] = reg_d1.h[0];
                        reg_d3.h[0] += 2;
                        reg_d3.h[0] &= 0xFC;
                        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                        reg_d3.w += reg_d5.w;
                        bullet_fire256_fixed();
                        reg_d1.h[0] += 0xF;
                    } while ((s16)(--reg_d7.h[0]) >= 0);
                    reg_d1.h[0] = ENTITY(reg_a6)[1].hit_y_plus.h;
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] &= 0x3E;
                    reg_d5.h[0] += reg_d5.h[0];
                    reg_d5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a4;
                    reg_d5.h[0] = ((reg_d5.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)(reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
                    reg_d7.h[0] = 6;
                    reg_a0 = (u8 *)(g_direction64_offsets_166);
                    reg_d5.h[0] += 0xF600;
                    reg_d5.h[1] += 0x5C0;
                    reg_d1.b[0] *= 4;
                    reg_d1.h[0] -= 0x2D;
                    do {
                        reg_d3.h[0] = reg_d1.h[0];
                        reg_d3.h[0] += 2;
                        reg_d3.h[0] &= 0xFC;
                        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                        reg_d3.w += reg_d5.w;
                        bullet_fire256_fixed();
                        var_a0_2 = (u32)reg_d1.h[0] + 0xF;
                        reg_d1.h[0] = var_a0_2;
                    } while ((s16)(--reg_d7.h[0]) >= 0);
                    reg_tmp.b[0] = MID_FLYER_B(reg_a5)->second_shots_left;
                    MID_FLYER_B(reg_a5)->second_shots_left -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        MID_FLYER_B(reg_a5)->second_shots_left = (u8) MID_FLYER_B(reg_a5)->second_shots;
                        reg_d0.h[0] = 0x80;
                        reg_d0.h[0] -= g_rank_6_16;
                        MID_FLYER_B(reg_a5)->second_countdown = (u8) reg_d0.b[0];
                    }
                    return;
                }
            }
        } else {
            reg_d0.w = 0x271;
            score_add();
            sfx_explosion_ground_large();
            reg_d0.w = 0xD;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->start_y = 0x600;
            EXPLOSION(reg_a0)->debris = 1;
            EXPLOSION(reg_a0)->debris_arg = 0x400;
            reg_d0.w = 5;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            temp_a3 = ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->x = temp_a3;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->start_y = 0xFC00;
            EXPLOSION(reg_a0)->debris = 1;
            EXPLOSION(reg_a0)->debris_arg = 0;
            reg_d0.w = 4;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->start_y = 0x200;
            EXPLOSION(reg_a0)->start_x = 0x800;
            EXPLOSION(reg_a0)->debris = 1;
            EXPLOSION(reg_a0)->debris_arg = 0;
            reg_d0.w = 4;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->start_y = 0x200;
            EXPLOSION(reg_a0)->start_x = 0xF600;
            EXPLOSION(reg_a0)->debris = 1;
            EXPLOSION(reg_a0)->debris_arg = 0x400;
            reg_d0.w = 8;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->start_y = 0xF800;
            EXPLOSION(reg_a0)->start_x = 0x600;
            EXPLOSION(reg_a0)->debris = 1;
            EXPLOSION(reg_a0)->debris_arg = 0;
            reg_d0.w = 8;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            temp_a3_2 = ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->x = temp_a3_2;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->start_y = 0xF800;
            EXPLOSION(reg_a0)->start_x = 0xF800;
            EXPLOSION(reg_a0)->debris = 1;
            EXPLOSION(reg_a0)->debris_arg = 0;
            reg_d0.w = 4;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->start_y = 0xFC00;
            EXPLOSION(reg_a0)->start_x = 0xE00;
            EXPLOSION(reg_a0)->debris = 1;
            EXPLOSION(reg_a0)->debris_arg = 0x400;
            reg_d0.w = 4;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            temp_a3_3 = ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->x = temp_a3_3;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->start_y = 0xFC00;
            EXPLOSION(reg_a0)->start_x = 0xF000;
            EXPLOSION(reg_a0)->debris = 1;
            EXPLOSION(reg_a0)->debris_arg = 0;
            enemy_remove();
        }
    }
}

void func_0015EF00(void)
{
    extern void bullet_fire256_fast(void);
  int new_var;
  u32 savedPosition;
  u32 nextPosition;
  u32 command;
  savedPosition = reg_d1.h[0];
  reg_d0.w = 0xFFFF000D;
  nextPosition = savedPosition + 2;
  reg_d6.h[0] = savedPosition;
  reg_d1.h[0] = nextPosition;
  bullet_fire256_fast();
  nextPosition = reg_d1.h[0] + 5U;
  command = (new_var = reg_d0.w) + 0xFFFE0000;
  reg_d1.h[0] = nextPosition;
  reg_d0.w = command;
  bullet_fire256_fast();
  reg_d1.h[0] = reg_d6.h[0];
}

void func_0015EF60(void)
{
    extern void bullet_fire256_fast(void);
  u32 saved_d0;
  reg_d6.h[0] = reg_d1.h[0];
  reg_d0.w = 0xFFFF000D;
  reg_d1.h[0] -= 2;
  bullet_fire256_fast();
  saved_d0 = reg_d0.w;
  reg_d0.w = saved_d0 + 0xFFFE0000;
  reg_d1.h[0] -= 5;
  bullet_fire256_fast();
  reg_d1.h[0] = reg_d6.h[0];
}

void enemy_set_entity_count(s32);

void mid_flyer_c_first(void) {
    enemy_set_entity_count(1);
}

extern s8 D_0025A1F8[];
extern s8 D_0025A210[];
extern s8 D_0025A230[];
extern u16 g_enemy_signal_3;
extern u16 g_enemy_signal_2;
extern u16 g_enemy_signal_1;
extern u16 g_enemy_signal_0;
extern u16 g_rank_5_16;

void mid_flyer_c_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    s8 *temp_a1;

    if ((g_stage == 0) && (g_enemy_signal_0 != 0)) {
        enemy_remove();
        return;
    }
    (*(s8 **)&reg_a0) = D_0025A230;
    enemy_init_entities();
    reg_tmp.w = (u32) ((s8 *)reg_a0);
    MID_FLYER_C(reg_a5)->after_entities[0] = (u16) reg_tmp.h[1];
    MID_FLYER_C(reg_a5)->after_entities[1] = (u16) reg_tmp.h[0];
    (*(s8 **)&reg_a0) = D_0025A210;
    reg_d0.w = 0xD;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_a2 = (u8 *)g_direction_sprites_d;
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x240;
        aim_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        MID_FLYER_C(reg_a5)->turret_dir.b[0] = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        reg_a2 += reg_d1.h[0];
        MID_FLYER_C(reg_a5)->turret_sprite[0] = (u16) *(u16 *)reg_a2;
        MID_FLYER_C(reg_a5)->turret_sprite[1] = (u16) *(u16 *)(reg_a2 + 2);
        reg_d0.b[0] = 4;
        reg_d1.b[0] = 5;
        if ((s32) g_stage > 1) {
            reg_d0.b[0] = 4;
            reg_d1.b[0] = 5;
        }
        MID_FLYER_C(reg_a5)->first_interval = (u8) reg_d0.b[0];
        MID_FLYER_C(reg_a5)->second_interval = (u8) reg_d1.b[0];
        reg_d0.h[0] = g_rank_3_16;
        MID_FLYER_C(reg_a5)->first_countdown -= reg_d0.b[0];
        reg_d0.h[0] = g_rank_5_16;
        MID_FLYER_C(reg_a5)->first_pause -= reg_d0.b[0];
        reg_d0.h[0] = g_rank_3_16;
        MID_FLYER_C(reg_a5)->second_countdown -= reg_d0.b[0];
        if (g_loop != 0) {
            MID_FLYER_C(reg_a5)->second_countdown -= 0x10;
        }
        reg_d0.h[0] = g_rank_6_16;
        MID_FLYER_C(reg_a5)->second_pause -= reg_d0.b[0];
        (*(s8 **)&reg_a0) = D_0025A1F8;
        reg_d0.h[0] = g_stage_x2;
        (*(s8 **)&reg_a0) = &(*(s8 **)&reg_a0)[reg_d0.h[0]];
        ENTITY(reg_a6)->attr.sb.palette = (s8) *((s8 *)reg_a0);
        MID_FLYER_C(reg_a5)->palette = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
        MID_FLYER_C(reg_a5)->hit_palette = (s8) *((s8 *)reg_a0);
        temp_a1 = (s8 *)(((s8 *)reg_a0) + 1);
        (*(s8 **)&reg_a0) = temp_a1;
        if (g_stage == 4) {
            if (g_enemy_signal_1 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_2 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_3 != 0) {
                enemy_remove();
            }
        }
    }
}

s32 sfx_explosion_air_medium();
s32 entity_draw_layer5_zoom();
s32 entity_check_bounds();

void mid_flyer_c(void) {
    s16 *temp_v1;
    s16 *temp_v1_2;
    s16 *var_a0;
    s16 *var_a1;
    u32 temp_a1;
    u32 temp_a0_2;
    u32 temp_s0;
    u32 temp_s1;
    u8 temp_a0;
    u8 temp_a1_2;

    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        entity_check_bounds();
        if (cond_flag != 0) {
            if (MID_FLYER_C(reg_a5)->seen != 0) {
                enemy_remove();
                return;
            }
            goto block_5;
        }
        MID_FLYER_C(reg_a5)->seen = 1U;
block_5:
        ENTITY(reg_a6)[1].y.h = (u16) ENTITY(reg_a6)->y.h;
        ENTITY(reg_a6)[1].x.h = (u16) ENTITY(reg_a6)->x.h;
        var_a0 = (s16 *)(reg_a6);
        reg_d1.b[0] = (*(u8 *)((u8 *)(var_a0) + (1)));
        reg_d1.b[0] |= (*(u8 *)((u8 *)(var_a0) + (0x21)));
        reg_d1.h[0] &= 0x5C;
        var_a1 = (s16 *)(var_a0 + 1);
        if (reg_d1.h[0] == 0) {
            reg_d0.b[0] = MID_FLYER_C(reg_a5)->palette;
            if (((s32) (*(u16 *)((u8 *)(var_a0) + (0x18))) < 0x80) && (g_damage_blink_counter == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_14;
        }
        reg_d0.h[0] = 0xA3;
        (*(u8 *)((u8 *)(var_a0) + (1))) &= reg_d0.b[0];
        ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = MID_FLYER_C(reg_a5)->palette;
        }
        var_a1 = (s16 *)(reg_a6 + 0x18);
        reg_d2.b[0] = MID_FLYER_C(reg_a5)->hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        reg_d4.h[0] = ENTITY(reg_a6)->hp.h;
        var_a0 = (s16 *) ENTITY(reg_a6)[1].hp.h;
        if ((s16)(var_a0) < (s16) reg_d4.h[0]) {
            reg_d4.h[0] = (u16) var_a0;
        }
        ENTITY(reg_a6)->hp.h = (u16) reg_d4.h[0];
        ENTITY(reg_a6)[1].hp.h = (u16) reg_d4.h[0];
        if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
block_14:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            enemy_anims_spawn_listed();
            if (g_enemies_stopped == 0) {
                if (g_bullets_blocked == 0) {
                    if ((s16) ENTITY(reg_a6)->y.h >= 0x1000) {
                        reg_tmp.b[0] = MID_FLYER_C(reg_a5)->first_countdown;
                        MID_FLYER_C(reg_a5)->first_countdown -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            MID_FLYER_C(reg_a5)->first_countdown = (u8) MID_FLYER_C(reg_a5)->first_interval;
                            reg_d0.b[0] = MID_FLYER_C(reg_a5)->first_shots_left;
                            if (MID_FLYER_C(reg_a5)->first_shots == reg_d0.b[0]) {
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
                                        goto block_24;
                                    }
                                } else {
block_24:
                                    temp_a1 = 0xF7C0 & 0xFFFF;
                                    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                                    temp_s0 = reg_d2.w;
                                    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                                    temp_s1 = reg_d3.w;
                                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                                    reg_d0.h[0] += temp_a1;
                                    reg_d1.h[0] += 0x7FFF + 0x7AC1;
                                    direction256_between();
                                    MID_FLYER_C(reg_a5)->aim[1] = (u8) reg_d1.b[0];
                                    reg_d2.w = temp_s0;
                                    reg_d3.w = temp_s1;
                                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                                    reg_d0.h[0] += 0x7FFF + 0x77C1;
                                    reg_d1.h[0] += 0x500;
                                    direction256_between();
                                    MID_FLYER_C(reg_a5)->aim[0] = (u8) reg_d1.b[0];
                                    goto block_25;
                                }
                            } else {
block_25:
                                reg_d0.w = 0x5000C;
                                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                                reg_d4.w = 0;
                                temp_a0 = MID_FLYER_C(reg_a5)->aim[1];
                                reg_d1.b[0] = temp_a0;
                                reg_d3.w = 0xF7C0FAC0;
                                reg_d0.w = 0x5000C;
                                if (((s32) g_stage >= 3) && (reg_d0.w = 0x5000C, reg_d5.b[0] = MID_FLYER_C(reg_a5)->first_shots_left, (MID_FLYER_C(reg_a5)->first_shots == reg_d5.b[0]))) {
                                    func_0015EF00();
                                } else {
                                    bullet_fire256_2way();
                                }
                                temp_a1_2 = MID_FLYER_C(reg_a5)->aim[0];
                                reg_d1.b[0] = temp_a1_2;
                                reg_d3.h[0] = 0x500;
                                reg_d0.w = 0x5000C;
                                if (((s32) g_stage >= 3) && (reg_d0.w = 0x5000C, reg_d5.b[0] = MID_FLYER_C(reg_a5)->first_shots_left, (MID_FLYER_C(reg_a5)->first_shots == reg_d5.b[0]))) {
                                    func_0015EF60();
                                } else {
                                    bullet_fire256_2way();
                                }
                                reg_tmp.b[0] = MID_FLYER_C(reg_a5)->first_shots_left;
                                MID_FLYER_C(reg_a5)->first_shots_left -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    MID_FLYER_C(reg_a5)->first_shots_left = (u8) MID_FLYER_C(reg_a5)->first_shots;
                                    reg_d0.h[0] = 0x70;
                                    reg_d0.h[0] -= g_rank_6_16;
                                    reg_d0.h[0] -= 4;
                                    MID_FLYER_C(reg_a5)->first_countdown = (u8) reg_d0.b[0];
                                }
                            }
                        }
                    }
                    reg_tmp.b[0] = MID_FLYER_C(reg_a5)->turn_countdown;
                    MID_FLYER_C(reg_a5)->turn_countdown -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        MID_FLYER_C(reg_a5)->turn_countdown = (u8) MID_FLYER_C(reg_a5)->turn_interval;
                        reg_d0.b[0] = MID_FLYER_C(reg_a5)->second_shots_left;
                        if (MID_FLYER_C(reg_a5)->second_shots == reg_d0.b[0]) {
                            reg_a0 = (u8 *)(((u16 *)g_player1));
                            reg_a1 = (u8 *)(((u16 *)g_player2));
                            switch (ENEMY_STATE(reg_a5)->target_player) { case 0: break; default:
                                reg_atmp = (u8 *)(reg_a0);
                                reg_a0 = (u8 *)(reg_a1);
                                reg_a1 = (u8 *)(reg_atmp);
                            }
                            temp_v1_2 = (s16 *)(reg_a0);
                            if ((*(s16 *)((u8 *)(temp_v1_2) + (0))) >= 0) {
                                if (*(s16 *)reg_a1 < 0) {
                                    reg_a0 = (u8 *)(reg_a1);
                                    reg_atmp = (u8 *)(temp_v1_2);
                                    reg_a1 = (u8 *)(temp_v1_2);
                                    goto block_42;
                                }
                            } else {
block_42:
                                reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                                reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                                reg_d0.h[0] += 0x240;
                                direction_between();
                                reg_d0.h[0] = MID_FLYER_C(reg_a5)->turret_dir.h;
                                direction_turn_toward();
                                MID_FLYER_C(reg_a5)->turret_dir.h = (u16) reg_d1.h[0];
                                reg_a3 = (u8 *)(g_direction_sprites_d);
                                reg_d1.h[0] &= 0x3E;
                                reg_d1.h[0] += reg_d1.h[0];
                                MID_FLYER_C(reg_a5)->turret_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                                MID_FLYER_C(reg_a5)->turret_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                            }
                        }
                    }
                }
            }
            reg_d6.w = 0x60005000;
            entity_draw_layer5_zoom();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            temp_a0_2 = reg_d1.h[0];
            reg_d1.h[1] += 0x7FFF + 0x7C41;
            reg_d1.h[0] = (u32)temp_a0_2 + 0x7FFF + 0x7C01;
            reg_d2.h[1] = MID_FLYER_C(reg_a5)->turret_sprite[0];
            reg_d2.h[0] = MID_FLYER_C(reg_a5)->turret_sprite[1];
            reg_d3.h[0] = 0x620;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer5();
            if ((g_loop == 0) && (g_frame_mod2 != 0)) {
                reg_d1.h[1] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d1.h[1] += 0xE200;
                reg_d1.h[0] += 0x300;
                reg_d2.w = 0x1876;
                reg_d3.h[0] = 0x628;
                reg_d4.h[0] = 0x18;
                sprite_draw_layer4();
            }
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            reg_a0 = (u8 *)(reg_a6 + 0x20);
            enemy_hitbox_debug_draw();
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0) && ((s16) ENTITY(reg_a6)->y.h >= 0x1000)) {
                reg_tmp.b[0] = MID_FLYER_C(reg_a5)->second_countdown;
                MID_FLYER_C(reg_a5)->second_countdown -= 1;
                switch (reg_tmp.b[0]) {
                case 0:
                    MID_FLYER_C(reg_a5)->second_countdown = (u8) MID_FLYER_C(reg_a5)->second_interval;
                    reg_a4 = (u8 *)(g_direction_offsets_500);
                    reg_d1.h[0] = MID_FLYER_C(reg_a5)->turret_dir.h;
                    reg_d0.h[0] = reg_d1.h[0];
                    reg_d0.h[0] &= 0x3E;
                    reg_d0.h[0] += reg_d0.h[0];
                    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
                    reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a4;
                    reg_d3.h[1] += 0x240;
                    reg_d0.w = 0x40007;
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d4.w = (u32) reg_a6;
                    bullet_fire_3way();
                    reg_tmp.b[0] = MID_FLYER_C(reg_a5)->second_shots_left;
                    MID_FLYER_C(reg_a5)->second_shots_left -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        MID_FLYER_C(reg_a5)->second_shots_left = (u8) MID_FLYER_C(reg_a5)->second_shots;
                        reg_d0.h[0] = 0x60;
                        reg_d0.h[0] -= g_rank_5_16;
                        reg_d0.h[0] += 4;
                        MID_FLYER_C(reg_a5)->second_countdown = (u8) reg_d0.b[0];
                    }
                    return;
                }
            }
        } else {
            reg_d0.w = 0x42;
            score_add();
            sfx_explosion_air_medium();
            reg_d0.w = 0xD;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->start_y = 0xF600;
            EXPLOSION(reg_a0)->start_x = 0;
            EXPLOSION(reg_a0)->debris = 1;
            EXPLOSION(reg_a0)->debris_arg = 0x400;
            reg_d0.h[0] = 8;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->start_y = 0xF600;
            EXPLOSION(reg_a0)->start_x = 0;
            EXPLOSION(reg_a0)->move.h = 0x680;
            EXPLOSION(reg_a0)->debris = 1;
            EXPLOSION(reg_a0)->debris_arg = 0x400;
            EXPLOSION(reg_a0)->attr.b.flip = 0x40;
            enemy_remove();
        }
    }
}

void mid_flyer_d_first(void) {
    enemy_set_entity_count(1);
}

extern s8 D_0025A288[];
extern s8 D_0025A2A0[];
extern s8 D_0025A2C0[];
extern u16 g_scroll_line;

void mid_flyer_d_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    (*(s8 **)&reg_a0) = D_0025A2C0;
    enemy_init_entities();
    reg_tmp.w = (u32) ((s8 *)reg_a0);
    MID_FLYER_D(reg_a5)->after_entities[0] = (u16) reg_tmp.h[1];
    MID_FLYER_D(reg_a5)->after_entities[1] = (u16) reg_tmp.h[0];
    (*(s8 **)&reg_a0) = D_0025A2A0;
    reg_d0.w = 0xE;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if (g_loop == 0) {
            reg_d0.b[0] = 0x18;
            reg_d1.b[0] = 0x10;
            if ((s32) g_stage > 0x3) {
                goto block_4;
            }
        } else {
block_4:
            reg_d0.b[0] = 0x10;
            reg_d1.b[0] = 0x10;
        }
        MID_FLYER_D(reg_a5)->first_interval = (u8) reg_d0.b[0];
        MID_FLYER_D(reg_a5)->second_interval = (u8) reg_d1.b[0];
        (*(s8 **)&reg_a0) = D_0025A288;
        reg_d0.h[0] = g_stage_x2;
        (*(s8 **)&reg_a0) = &(*(s8 **)&reg_a0)[reg_d0.h[0]];
        ENTITY(reg_a6)->attr.sb.palette = (s8) *((s8 *)reg_a0);
        MID_FLYER_D(reg_a5)->palette = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
        MID_FLYER_D(reg_a5)->hit_palette = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
        if (g_stage == 4) {
            ENTITY(reg_a6)->hp.sh = 0x1000;
            if ((s32) g_scroll_line > 0x2E0) {
                ENTITY(reg_a6)->hp.sh = 0xE80;
            }
        }
    }
}

s32 rng_next_0_to_3_d1();
s32 nearest_player_by_x();
extern u16 D_0025A330[];

void mid_flyer_d(void) {
    u32 cnt;
    u8 *ptr;

    enemy_path_step();
    if (enemy_move_end_requested != 0) return;
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x1600;
    reg_d0.h[0] += g_side_scroll_x[0];
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x9C00;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x9C00;
    if (reg_tmp.h[1] != 0) goto next_20;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x7600;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] += 0x1200;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x7600;
    if (reg_tmp.h[1] == 0) goto next_30;
next_20:
    if (MID_FLYER_D(reg_a5)->seen == 0) goto next_40;
    enemy_remove();
    return;
next_30:
    MID_FLYER_D(reg_a5)->seen = 1;
next_40:
    ENTITY(reg_a6)[1].y.h = ENTITY(reg_a6)->y.h;
    ENTITY(reg_a6)[1].x.h = ENTITY(reg_a6)->x.h;
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[1].flags.b[1];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) goto next_50;
    reg_d0.b[0] = MID_FLYER_D(reg_a5)->palette;
    if (!((s32) ENTITY(reg_a6)->hp.h < 0x5C0)) goto next_90;
    if (g_damage_blink_counter != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    reg_d0.h[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    if (reg_d0.b[0] != 0x19) goto next_60;
    reg_d0.b[0] = MID_FLYER_D(reg_a5)->palette;
next_60:
    reg_d2.b[0] = MID_FLYER_D(reg_a5)->hit_palette;
    reg_d0.b[0] ^= reg_d2.b[0];
    reg_d4.h[0] = ENTITY(reg_a6)->hp.h;
    if (!((s16) ENTITY(reg_a6)[1].hp.h < (s16) reg_d4.h[0])) goto next_80;
    reg_d4.h[0] = ENTITY(reg_a6)[1].hp.h;
next_80:
    ENTITY(reg_a6)->hp.h = reg_d4.h[0];
    ENTITY(reg_a6)[1].hp.h = reg_d4.h[0];
    if ((s16) ENTITY(reg_a6)->hp.h < 0) goto next_700;
next_90:
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    enemy_anims_spawn_listed();
    if (g_enemies_stopped != 0) goto next_500;
    if (g_bullets_blocked != 0) goto next_500;
    if (g_enemies_stopped != 0) goto next_500;
    if (g_bullets_blocked != 0) goto next_500;
    if ((s16) ENTITY(reg_a6)->y.h < 0x1000) goto next_500;
    MID_FLYER_D(reg_a5)->player_in_range = 0;
    if (g_stage == 4) goto next_200;
    nearest_player_by_x();
    reg_d1.h[0] = 0xC00;
    if (g_stage != 4) goto next_150;
    reg_d1.h[0] = 0x1800;
next_150:
    if ((s32) reg_d1.h[0] > (s32) reg_d0.h[0]) goto next_500;
    MID_FLYER_D(reg_a5)->player_in_range = 1;
next_200:
    reg_tmp.b[0] = MID_FLYER_D(reg_a5)->first_countdown;
    MID_FLYER_D(reg_a5)->first_countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_500;
    MID_FLYER_D(reg_a5)->first_countdown = MID_FLYER_D(reg_a5)->first_interval;
    reg_a0 = (u8 *) ((u16 *)g_player1);
    reg_a1 = (u8 *) ((u16 *)g_player2);
    if (ENEMY_STATE(reg_a5)->target_player == 0) goto next_240;
    reg_atmp = (u8 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) reg_atmp;
next_240:
    if (*(s16 *)reg_a0 < 0) goto next_260;
    if (*(s16 *)reg_a1 >= 0) goto next_500;
    ptr = reg_a0;
    reg_a0 = reg_a1;
    reg_atmp = (u8 *) ptr;
    reg_a1 = ptr;
next_260:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0xFE00;
    direction256_between();
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d5.w = 0xFE000000;
    reg_d4.w = 0;
    reg_a0 = (u8 *) g_direction64_offsets_2CC;
    if (g_stage == 4) goto next_265;
    reg_d1.h[0] -= 0x14;
    reg_d7.w = 4;
    reg_d0.w = 0xFFFD000B;
    goto loop_270;
next_265:
    reg_d1.h[0] -= 0x14;
    reg_d7.w = 4;
    reg_d0.w = 0xFFFD000C;
loop_270:
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d5.w;
    bullet_fire256();
    reg_d1.h[0] += 0xA;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (u16) cnt << 0x30) >> 0x30) >= 0) goto loop_270;
    if (g_stage != 4) goto next_500;
    reg_tmp.b[0] = MID_FLYER_D(reg_a5)->first_shots_left;
    MID_FLYER_D(reg_a5)->first_shots_left -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_500;
    MID_FLYER_D(reg_a5)->first_shots_left = MID_FLYER_D(reg_a5)->first_shots;
    MID_FLYER_D(reg_a5)->first_countdown = 0x40;
next_500:
    entity_draw_layer5();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0xF400;
    reg_d1.h[1] += 0xF200;
    reg_d1.h[1] += MID_FLYER_D(reg_a5)->cannon_offset;
    reg_d2.h[1] = MID_FLYER_D(reg_a5)->part_sprite[0];
    reg_d2.h[0] = MID_FLYER_D(reg_a5)->part_sprite[1];
    reg_d3.h[0] = 0xE60;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    sprite_draw_layer5();
    if (g_loop != 0) goto next_520;
    if (g_stage == 2) goto next_520;
    if (g_frame_mod2 == 0) goto next_520;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x900;
    reg_d1.h[1] += 0xD600;
    reg_d2.w = 0x1879;
    reg_d3.h[0] = 0xA38;
    reg_d4.h[0] = 0x18;
    sprite_draw_layer4();
next_520:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x20;
    enemy_hitbox_debug_draw();
    if (g_enemies_stopped != 0) goto block_rts;
    if (g_bullets_blocked != 0) goto block_rts;
    if ((s16) ENTITY(reg_a6)->y.h < 0x1000) goto block_rts;
    reg_d0.h[0] = MID_FLYER_D(reg_a5)->cannon_firing;
    if (reg_d0.h[0] != 0) goto next_600;
    if (MID_FLYER_D(reg_a5)->player_in_range == 0) goto next_599;
    MID_FLYER_D(reg_a5)->second_countdown = MID_FLYER_D(reg_a5)->second_pause;
    return;
next_599:
    reg_tmp.b[0] = MID_FLYER_D(reg_a5)->second_countdown;
    MID_FLYER_D(reg_a5)->second_countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    MID_FLYER_D(reg_a5)->second_countdown = MID_FLYER_D(reg_a5)->second_interval;
    MID_FLYER_D(reg_a5)->cannon_firing = 1;
block_rts:
    return;
next_600:
    reg_d0.h[0] = MID_FLYER_D(reg_a5)->cannon_step;
    reg_a0 = (u8 *) D_0025A330;
    reg_d7.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    if ((s16) reg_d7.h[0] != -1) goto next_660;
    reg_tmp.b[0] = MID_FLYER_D(reg_a5)->second_countdown;
    MID_FLYER_D(reg_a5)->second_countdown -= 1;
    if (reg_tmp.b[0] == 0) goto next_610;
    return;
next_610:
    MID_FLYER_D(reg_a5)->cannon_step -= 2;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d6.h[0] = reg_d7.h[0];
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = reg_tmp6.h[0];
    reg_d6.h[0] = 0x540;
    reg_d4.w = 0;
    reg_a0 = (u8 *) g_direction64_offsets_166;
    reg_d0.w = 0xFFFA0004;
    reg_d7.w = 5;
    reg_d5.w = 0x40000;
    if (g_stage != 4) goto loop_620;
    reg_d5.w = 0x30000;
loop_620:
    rng_next_0_to_3_d1();
    reg_d1.b[0] += 0x7E;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d6.w;
    bullet_fire256_fixed();
    if (reg_d7.h[0] > 4) goto next_6205;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d6.w;
    reg_d1.b[0] += 0xF0;
    bullet_fire256_2way();
    if (reg_d7.h[0] > 3) goto next_6205;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d6.w;
    reg_d1.b[0] += 0xF0;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0x20;
next_6205:
    reg_d0.w += reg_d5.w;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (u16) cnt << 0x30) >> 0x30) >= 0) goto loop_620;
    reg_d0.w = 0xFFFA0004;
    reg_d6.h[0] = 0xFAC0;
    reg_d7.w = 5;
loop_640:
    rng_next_0_to_3_d1();
    reg_d1.b[0] += 0x7F;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d6.w;
    bullet_fire256_fixed();
    if (reg_d7.h[0] > 4) goto next_6405;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d6.w;
    reg_d1.b[0] += 0x10;
    bullet_fire256_2way();
    if (reg_d7.h[0] > 3) goto next_6405;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d6.w;
    reg_d1.b[0] += 0x10;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xE0;
next_6405:
    reg_d0.w += reg_d5.w;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (u16) cnt << 0x30) >> 0x30) >= 0) goto loop_640;
next_660:
    MID_FLYER_D(reg_a5)->cannon_offset = reg_d7.h[0];
    reg_tmp.h[0] = MID_FLYER_D(reg_a5)->cannon_step;
    MID_FLYER_D(reg_a5)->cannon_step -= 2;
    if (!((s32) reg_tmp.h[0] < 2)) goto next_680;
    MID_FLYER_D(reg_a5)->cannon_step = 0x48;
    MID_FLYER_D(reg_a5)->second_countdown = MID_FLYER_D(reg_a5)->second_pause;
    MID_FLYER_D(reg_a5)->cannon_firing = 0;
next_680:
    return;
next_700:
    reg_d0.w = 0x320;
    score_add();
    sfx_explosion_ground_large();
    reg_d0.w = 5;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0xF600;
    EXPLOSION(reg_a0)->start_x = 0xFA00;
    EXPLOSION(reg_a0)->attr.b.flip = 0x40;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->move.h = 0x4A0;
    reg_d0.w = 5;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0xF600;
    EXPLOSION(reg_a0)->start_x = 0x500;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->move.h = 0x460;
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    cnt = ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->x = cnt;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0xFA00;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    enemy_remove();
}

void mid_tank_vertical_first(void) {
    enemy_set_entity_count(1);
}

extern u16 D_0025A380[];
extern u16 D_0025A390[];
extern u16 D_0025A3B0[];
extern u16 D_0025A430[];
extern u16 g_rank_8_16;
extern u16 g_rank_11_16;

void mid_tank_vertical_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)(D_0025A3B0);
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0;
    MID_TANK_V(reg_a5)->after_entities[0] = (u16) reg_tmp.h[1];
    MID_TANK_V(reg_a5)->after_entities[1] = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)(D_0025A390);
    reg_d0.w = 0xD;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_d0.b[0] = 6;
        reg_d1.b[0] = 5;
        if ((s32) g_stage > 1) {
            reg_d1.b[0] = 5;
            reg_d0.b[0] = 2;
        }
        MID_TANK_V(reg_a5)->unread_2B = (u8) reg_d0.b[0];
        MID_TANK_V(reg_a5)->unread_2A = (u8) reg_d1.b[0];
        reg_d0.h[0] = ENTITY(reg_a6)[1].offset_x.h;
        reg_a0 = (u8 *)(D_0025A430);
        ENTITY(reg_a6)[1].draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)[1].sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = g_rank_11_16;
        MID_TANK_V(reg_a5)->unread_2F -= reg_d0.b[0];
        reg_d0.h[0] = g_rank_8_16;
        MID_TANK_V(reg_a5)->shot_countdown -= reg_d0.b[0];
        reg_a0 = (u8 *)(D_0025A380);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        MID_TANK_V(reg_a5)->palette = *(s8 *)reg_a0;
        reg_a0 += 1;
        MID_TANK_V(reg_a5)->hit_palette = *(s8 *)reg_a0;
        reg_a0 += 1;
        if (!(ENTITY(reg_a6)->flags.b[1] & 0x20)) {
            ENTITY(reg_a6)[1].hit_y_plus.sh = 1;
            reg_d0.w = 0;
            reg_d0.b[0] = ENTITY(reg_a6)->misc.b.user;
            reg_d0.b[0] -= 1;
            ENTITY(reg_a6)[1].hit_y_minus.h = (u16) reg_d0.h[0];
            if (reg_d0.h[0] == 0) {
                reg_a0 = (u8 *)reg_a6 + 0x12;
            } else {
                reg_a0 = (u8 *)reg_a6 + 0x10;
            }
            *(u16 *)reg_a0 = 0xF000;
            ENTITY(reg_a6)->misc.b.user = 0U;
        }
        if (g_stage == 4) {
            ENTITY(reg_a6)->hp.sh = 0x1400;
        }
    }
}

s32 pickup_spawn_plain();
s32 entity_draw_layer1();
s32 sprite_draw_layer1();
s32 rng_next();
s32 rng_next_bit_d5();
s32 wreck_spawn_a();
extern u16 D_0025A440[];
extern u16 D_0025A460[];
extern u16 D_0028C9E0;
extern u16 g_rank_1_16;

void mid_tank_vertical(void) {
    s16 *temp_a0;
    s16 *temp_v1_3;
    u16 temp_v1_2;
    s64 temp_v0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_5;
    u16 temp_a0_6;
    u16 temp_a0_7;
    u16 temp_a1_3;
    u16 temp_a1_4;
    u16 temp_a2;
    u16 temp_a2_2;
    u16 temp_a3;
    u16 temp_v1;
    u8 temp_a1;
    u8 temp_a1_2;
    u8 temp_v1_4;

    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        if ((ENTITY(reg_a6)[1].hit_y_plus.h != 0) && (ENTITY(reg_a6)->flags.b[1] & 0x20)) {
            reg_a0 = (u8 *)(reg_a6 + 0x12);
            if (ENTITY(reg_a6)[1].hit_y_minus.h != 0) {
                reg_a0 = (u8 *)(reg_a6 + 0x10);
                reg_d2.h[0] *= 0xFFFF;
            }
            temp_v1 = *(u16 *)reg_a0;
            if ((s16)temp_v1 < 0x1000) {
                *(u16 *)reg_a0 += reg_d2.h[0];
                if ((s32) *(u16 *)reg_a0 < 0x800) {
                    ENTITY(reg_a6)->hp.h = 0x2D00U;
                }
            }
        }
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7200;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1600;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] += 0x7200;
        reg_tmp.w += reg_tmp1.h[0];
        if (reg_tmp.h[1] != 0) {
            if (MID_TANK_V(reg_a5)->seen != 0) {
                enemy_remove();
                return;
            }
            goto block_12;
        }
        MID_TANK_V(reg_a5)->seen = 1U;
block_12:
        temp_a0 = (s16 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(temp_a0) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = MID_TANK_V(reg_a5)->palette;
            if (((s32) (*(u16 *)((u8 *)(temp_a0) + (0x18))) < 0xB40) && (g_damage_blink_counter == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_19;
        }
        (*(u8 *)((u8 *)(temp_a0) + (1))) &= 0xA3;
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = MID_TANK_V(reg_a5)->palette;
        }
        reg_d2.b[0] = MID_TANK_V(reg_a5)->hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
block_19:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            enemy_anims_spawn_listed();
            if (g_enemies_stopped == 0) {
                ENTITY(reg_a6)->offset_y.h = 0xF000;
                if ((s32) ENTITY(reg_a6)->move.b.dir < 0x40) {
                    reg_tmp.b[0] = ENTITY(reg_a6)[1].offset_y.b[1];
                    ENTITY(reg_a6)[1].offset_y.b[1] -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        ENTITY(reg_a6)[1].offset_y.b[1] = (u8) ENTITY(reg_a6)[1].offset_y.b[0];
                        ENTITY(reg_a6)->offset_y.h = 0xF040;
                        if (ENTITY(reg_a6)->move.b.dir == 0) {
                            reg_tmp.h[0] = ENTITY(reg_a6)[1].offset_x.h;
                            ENTITY(reg_a6)[1].offset_x.h -= 4;
                            if ((s32) reg_tmp.h[0] < 4) {
                                ENTITY(reg_a6)[1].offset_x.h = 0xCU;
                            }
                        } else {
                            ENTITY(reg_a6)[1].offset_x.h += 4;
                            if (ENTITY(reg_a6)[1].offset_x.h == 0x10) {
                                ENTITY(reg_a6)[1].offset_x.h = 0U;
                            }
                        }
                        reg_d0.h[0] = ENTITY(reg_a6)[1].offset_x.h;
                        reg_a0 = (u8 *)(D_0025A430);
                        ENTITY(reg_a6)[1].draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                        ENTITY(reg_a6)[1].sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    }
                }
            }
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0) && (g_enemies_stopped == 0) && (g_bullets_blocked == 0) && ((s16) ENTITY(reg_a6)->y.h >= 0x1000)) {
                reg_d0.h[0] = MID_TANK_V(reg_a5)->hatch_state;
                temp_v1_2 = reg_d0.h[0] & 0xFFFF;
                if (reg_d0.h[0] == 0) {
                    reg_tmp.b[0] = MID_TANK_V(reg_a5)->shot_countdown;
                    MID_TANK_V(reg_a5)->shot_countdown -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        MID_TANK_V(reg_a5)->shot_countdown = 8U;
                        MID_TANK_V(reg_a5)->hatch_state = 1U;
                    }
                } else if (temp_v1_2 == 1) {
                    MID_TANK_V(reg_a5)->hatch_frame += 2;
                    reg_d0.h[0] = MID_TANK_V(reg_a5)->hatch_frame;
                    reg_a0 = (u8 *)(D_0025A440);
                    MID_TANK_V(reg_a5)->hatch_offset = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                    if (reg_d0.h[0] == 0x14) {
                        MID_TANK_V(reg_a5)->hatch_state = 2U;
                        MID_TANK_V(reg_a5)->hatch_frame = 0x10U;
                    }
                } else if (temp_v1_2 == 2) {
                    MID_TANK_V(reg_a5)->barrel_a_x = 0x2C0U;
                    MID_TANK_V(reg_a5)->barrel_b_x = 0xF940U;
                    ENTITY(reg_a6)[1].look.h = 0xF000U;
                    reg_tmp.b[0] = MID_TANK_V(reg_a5)->shot_countdown;
                    MID_TANK_V(reg_a5)->shot_countdown -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        reg_d0.h[0] = 5;
                        reg_d1.h[0] = g_rank_1_16;
                        reg_d1.h[0] >>= 3;
                        reg_d0.h[0] -= reg_d1.h[0];
                        MID_TANK_V(reg_a5)->shot_countdown = (u8) reg_d0.b[0];
                        reg_a0 = (u8 *)(((u16 *)g_player1));
                        reg_a1 = (u8 *)(((u16 *)g_player2));
                        if (ENEMY_STATE(reg_a5)->target_player != 0) {
                            reg_atmp = (u8 *)(reg_a0);
                            reg_a0 = (u8 *)(reg_a1);
                            reg_a1 = (u8 *)(reg_atmp);
                        }
                        temp_v1_3 = (s16 *)(reg_a0);
                        if ((*(s16 *)((u8 *)(temp_v1_3) + (0))) >= 0) {
                            if (*(s16 *)reg_a1 < 0) {
                                reg_a0 = (u8 *)(reg_a1);
                                reg_atmp = (u8 *)(temp_v1_3);
                                reg_a1 = (u8 *)(temp_v1_3);
                                goto block_55;
                            }
                        } else {
block_55:
                            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                            reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d0.h[0] += 0xE00;
                            if (!(ENTITY(reg_a6)->flags.b[0] & 0x40)) {
                                reg_d1.h[0] += 0x400;
                                direction256_between();
                                reg_d7.h[0] = reg_d1.h[0];
                                rng_next();
                                reg_d1.b[0] += reg_d0.b[0];
                                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                                reg_d0.h[0] = MID_TANK_V(reg_a5)->recoil;
                                reg_a0 = (u8 *)(&D_0028C9E0);
                                reg_d3.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                                reg_tmp3.h[0] = reg_d3.h[0];
                                reg_d3.h[0] = 0x400;
                                reg_d3.h[1] = reg_tmp3.h[0];
                                reg_d4.w = 0;
                                reg_d0.w = 0x30013;
                                bullet_fire256_2way();
                                reg_d1.h[0] -= 0x10;
                                rng_next_bit_d5();
                                if (reg_d5.h[0] != 0) {
                                    reg_d1.h[0] += 0x20;
                                }
                                bullet_fire256();
                            } else {
                                reg_d1.h[0] += 0xFC00 & 0xFFFF;
                                direction256_between();
                                reg_d7.h[0] = reg_d1.h[0];
                                rng_next();
                                reg_d1.b[0] += reg_d0.b[0];
                                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                                reg_d0.h[0] = MID_TANK_V(reg_a5)->recoil;
                                reg_a0 = (u8 *)(&D_0028C9E0);
                                reg_d3.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                                reg_tmp3.h[0] = reg_d3.h[0];
                                reg_d3.h[0] = 0xFC00;
                                reg_d3.h[1] = reg_tmp3.h[0];
                                reg_d4.w = 0;
                                reg_d0.w = 0x30013;
                                bullet_fire256_2way();
                                reg_d1.h[0] -= 0x10;
                                rng_next_bit_d5();
                                if (reg_d5.h[0] != 0) {
                                    reg_d1.h[0] += 0x20;
                                }
                                bullet_fire256();
                            }
                        }
                        MID_TANK_V(reg_a5)->barrel_a_x = 0x280U;
                        MID_TANK_V(reg_a5)->barrel_b_x = 0xF980U;
                        ENTITY(reg_a6)[1].look.h = 0xEFC0U;
                        reg_tmp.h[0] = MID_TANK_V(reg_a5)->recoil;
                        MID_TANK_V(reg_a5)->recoil -= 2;
                        if ((s32) reg_tmp.h[0] < 2) {
                            MID_TANK_V(reg_a5)->recoil = 4U;
                        }
                        reg_tmp.b[0] = MID_TANK_V(reg_a5)->shots_left;
                        MID_TANK_V(reg_a5)->shots_left -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            MID_TANK_V(reg_a5)->shots_left = (u8) MID_TANK_V(reg_a5)->shots;
                            temp_v1_4 = ENTITY(reg_a6)->flags.b[0];
                            if (!(temp_v1_4 & 0x40)) {
                                ENTITY(reg_a6)->flags.b[0] = (u8) (temp_v1_4 | 0x40);
                            } else {
                                ENTITY(reg_a6)->flags.b[0] = (u8) (temp_v1_4 & 0xBF);
                                reg_d0.h[0] = 0x40;
                                reg_d0.h[0] -= g_rank_4_16;
                                MID_TANK_V(reg_a5)->shot_countdown = (u8) reg_d0.b[0];
                                MID_TANK_V(reg_a5)->hatch_state = 3U;
                            }
                        }
                    }
                } else {
                    MID_TANK_V(reg_a5)->hatch_frame -= 2;
                    if (MID_TANK_V(reg_a5)->hatch_frame == 0) {
                        MID_TANK_V(reg_a5)->hatch_state = 0U;
                    }
                    reg_d0.h[0] = MID_TANK_V(reg_a5)->hatch_frame;
                    reg_a0 = (u8 *)(D_0025A440);
                    MID_TANK_V(reg_a5)->hatch_offset = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                }
            }
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            temp_a0_4 = reg_d1.h[0];
            reg_d1.h[1] += 0x7FFF + 0x6E01;
            reg_d1.h[0] = (u32)temp_a0_4 + 0x7FFF + 0x7801;
            reg_d2.h[1] = ENTITY(reg_a6)[1].draw.h;
            reg_d2.h[0] = ENTITY(reg_a6)[1].sprite.h;
            reg_d3.h[0] = 0x440;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer1();
            entity_draw_layer1();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] += 0x7FFF + 0x7901;
            reg_d1.h[1] += ENTITY(reg_a6)[1].look.h;
            reg_d2.w = 0x18E4;
            reg_d3.h[0] = 0x1438;
            sprite_draw_layer1();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] += MID_TANK_V(reg_a5)->barrel_a_x;
            reg_d1.h[0] += MID_TANK_V(reg_a5)->hatch_offset;
            reg_d1.h[1] += 0x600;
            reg_d2.w = 0x18E6;
            reg_d3.h[0] = 0x810;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer1();
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] += MID_TANK_V(reg_a5)->barrel_b_x;
            reg_d1.h[0] -= MID_TANK_V(reg_a5)->hatch_offset;
            reg_d2.w = 0x18E5;
            sprite_draw_layer1();
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            return;
        }
        reg_d0.w = 0x162;
        score_add();
        sfx_explosion_ground_large();
        reg_d1.h[0] = 0;
        reg_d2.w = 0xF8000000;
        reg_d0.w = 0xC;
        wreck_spawn_a();
        reg_d2.w = 0x08000000;
        wreck_spawn_a();
        reg_d0.w = 8;
        reg_a4 = (u8 *)(D_0025A460);
        reg_d6.w = 6;
        do {
            reg_d1.h[1] = *(u16 *)reg_a4;
            reg_a4 += 2;
            reg_d1.h[0] = *(u16 *)reg_a4;
            reg_a4 += 2;
            pickup_spawn_plain();
        } while ((s16)(--reg_d6.h[0]) >= 0);
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        temp_a3 = ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->x = temp_a3;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->debris = 1;
        EXPLOSION(reg_a0)->debris_arg = 0x400;
        EXPLOSION(reg_a0)->start_y = 0x400;
        EXPLOSION(reg_a0)->start_x = 0;
        EXPLOSION(reg_a0)->follows_scroll = 1;
        reg_d0.w = 0xD;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->debris = 1;
        EXPLOSION(reg_a0)->debris_arg = 0;
        EXPLOSION(reg_a0)->start_y = 0xFA00;
        EXPLOSION(reg_a0)->start_x = 0xFE00;
        EXPLOSION(reg_a0)->move.h = 0x3A0;
        EXPLOSION(reg_a0)->follows_scroll = 1;
        reg_d0.w = 0xD;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->debris = 1;
        EXPLOSION(reg_a0)->debris_arg = 0x400;
        EXPLOSION(reg_a0)->start_y = 0xFA00;
        EXPLOSION(reg_a0)->start_x = 0x200;
        EXPLOSION(reg_a0)->move.h = 0x360;
        EXPLOSION(reg_a0)->follows_scroll = 1;
        reg_d0.w = 0xC;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->debris = 1;
        EXPLOSION(reg_a0)->debris_arg = 0;
        EXPLOSION(reg_a0)->start_y = 0xFA00;
        EXPLOSION(reg_a0)->start_x = 0xFE00;
        EXPLOSION(reg_a0)->follows_scroll = 1;
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->debris = 1;
        EXPLOSION(reg_a0)->debris_arg = 0x400;
        EXPLOSION(reg_a0)->start_y = 0xF600;
        EXPLOSION(reg_a0)->start_x = 0;
        EXPLOSION(reg_a0)->move.h = 0x780;
        EXPLOSION(reg_a0)->follows_scroll = 1;
        enemy_remove();
    }
}

extern u8 D_0025A490[];
extern u8 D_0025A4B0[];

void carrier_start_common(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = D_0025A4B0;
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0;
    CARRIER(reg_a5)->after_entities[0] = (u16) reg_tmp.h[1];
    CARRIER(reg_a5)->after_entities[1] = (u16) reg_tmp.h[0];
    reg_a0 = D_0025A490;
    reg_d0.w = 0xA;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_a2 = (u8 *)(g_direction_sprites_d);
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x7FFF + 0x7901;
        aim_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        CARRIER(reg_a5)->turret_dir.b[0] = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        CARRIER(reg_a5)->turret_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        CARRIER(reg_a5)->turret_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d0.h[0] = g_rank_4_16;
        CARRIER(reg_a5)->shot_countdown -= reg_d0.b[0];
    }
}

void item_carrier_first(void) {
    enemy_set_entity_count(1);
}

extern s8 D_0025A480[];

void item_carrier_start(void) {
    carrier_start_common();
    (*(s8 **)&reg_a0) = D_0025A480;
    reg_d0.h[0] = g_stage_x2;
    (*(s8 **)&reg_a0) = &(*(s8 **)&reg_a0)[reg_d0.h[0]];
    ENTITY(reg_a6)->attr.sb.palette = (s8) *((s8 *)reg_a0);
    CARRIER(reg_a5)->palette = (s8) *((s8 *)reg_a0);
    (*(s8 **)&reg_a0) += 1;
    CARRIER(reg_a5)->hit_palette = (s8) *((s8 *)reg_a0);
    (*(s8 **)&reg_a0) += 1;
}

s32 bullet_fire_fixed();
s32 item_spawn();
s32 entity_bounds_check_wide();
extern u16 g_two_player_game;

void item_carrier(void) {
    s16 *temp_v1;
    s16 *var_a0;
    s16 *var_a1;
    u32 temp_a0;
    u32 temp_a2_2;
    u32 temp_a2_3;
    u32 temp_a3;
    u32 temp_a0_3;

    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        entity_bounds_check_wide();
        if (cond_flag != 0) {
            if (CARRIER(reg_a5)->seen != 0) {
                enemy_remove();
                return;
            }
            goto block_5;
        }
        CARRIER(reg_a5)->seen = 1U;
block_5:
        ENTITY(reg_a6)[1].y.h = (u16) ENTITY(reg_a6)->y.h;
        ENTITY(reg_a6)[1].x.h = (u16) ENTITY(reg_a6)->x.h;
        var_a0 = (s16 *)(reg_a6);
        reg_d1.b[0] = (*(u8 *)((u8 *)(var_a0) + (1)));
        reg_d1.b[0] |= (*(u8 *)((u8 *)(var_a0) + (0x21)));
        reg_d1.h[0] &= 0x5C;
        var_a1 = (s16 *)(var_a0 + 1);
        if (reg_d1.h[0] == 0) {
            reg_d0.b[0] = CARRIER(reg_a5)->palette;
            if (((s32) (*(u16 *)((u8 *)(var_a0) + (0x18))) < 0x1C0) && (g_damage_blink_counter == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_14;
        }
        reg_d0.h[0] = 0xA3;
        (*(u8 *)((u8 *)(var_a0) + (1))) &= reg_d0.b[0];
        ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = CARRIER(reg_a5)->palette;
        }
        var_a1 = (s16 *)(reg_a6 + 0x18);
        reg_d2.b[0] = CARRIER(reg_a5)->hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        reg_d4.h[0] = ENTITY(reg_a6)->hp.h;
        var_a0 = (s16 *) ENTITY(reg_a6)[1].hp.h;
        if ((s16)(var_a0) < (s16) reg_d4.h[0]) {
            reg_d4.h[0] = (u16) var_a0;
        }
        ENTITY(reg_a6)->hp.h = (u16) reg_d4.h[0];
        ENTITY(reg_a6)[1].hp.h = (u16) reg_d4.h[0];
        if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
block_14:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            enemy_anims_spawn_listed();
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0)) {
                reg_tmp.b[0] = CARRIER(reg_a5)->turn_countdown;
                CARRIER(reg_a5)->turn_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    CARRIER(reg_a5)->turn_countdown = (u8) CARRIER(reg_a5)->turn_interval;
                    reg_d0.b[0] = CARRIER(reg_a5)->shots_left;
                    if (CARRIER(reg_a5)->shots == reg_d0.b[0]) {
                        reg_a0 = (u8 *)(((u16 *)g_player1));
                        reg_a1 = (u8 *)(((u16 *)g_player2));
                        switch (ENEMY_STATE(reg_a5)->target_player) { case 0: break; default:
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
                                goto block_23;
                            }
                        } else {
block_23:
                            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                            reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d0.h[0] += 0x7FFF + 0x7901;
                            direction_between();
                            reg_d0.h[0] = CARRIER(reg_a5)->turret_dir.h;
                            direction_turn_toward();
                            CARRIER(reg_a5)->turret_dir.h = (u16) reg_d1.h[0];
                            reg_a3 = (u8 *)(g_direction_sprites_d);
                            reg_d1.h[0] &= 0x3E;
                            reg_d1.h[0] += reg_d1.h[0];
                            CARRIER(reg_a5)->turret_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                            CARRIER(reg_a5)->turret_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                        }
                    }
                }
            }
            entity_draw_layer5();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            temp_a0 = reg_d1.h[0];
            reg_d1.h[1] += 0x7FFF + 0x7301;
            reg_d1.h[0] = (u32)temp_a0 + 0x7FFF + 0x7C01;
            reg_d2.h[1] = CARRIER(reg_a5)->turret_sprite[0];
            reg_d2.h[0] = CARRIER(reg_a5)->turret_sprite[1];
            reg_d3.h[0] = 0x620;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer5();
            if ((g_loop == 0) && (g_frame_mod2 != 0) && (g_stage != 2)) {
                reg_d1.h[1] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d1.h[1] += 0xE400;
                reg_d1.h[0] += 0x400;
                reg_d2.w = 0x1936;
                reg_d3.h[0] = 0x820;
                reg_d4.h[0] = 0x18;
                sprite_draw_layer4();
            }
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            reg_a0 = (u8 *)(reg_a6 + 0x20);
            enemy_hitbox_debug_draw();
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0) && ((s16) ENTITY(reg_a6)->y.h >= 0x1000)) {
                reg_tmp.b[0] = CARRIER(reg_a5)->shot_countdown;
                CARRIER(reg_a5)->shot_countdown -= 1;
                switch (reg_tmp.b[0]) {
                case 0:
                    reg_d0.h[0] = 6;
                    CARRIER(reg_a5)->shot_countdown = (u8) reg_d0.b[0];
                    reg_a4 = (u8 *)(g_direction_offsets_500);
                    reg_d1.h[0] = CARRIER(reg_a5)->turret_dir.h;
                    reg_d0.h[0] = reg_d1.h[0];
                    reg_d0.h[0] &= 0x3E;
                    reg_d0.h[0] += reg_d0.h[0];
                    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
                    reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a4;
                    temp_a0_3 = reg_d3.w;
                    reg_d3.w = temp_a0_3 + 0xF9000000;
                    reg_d0.w = 0xFFFF000D;
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    bullet_fire_fixed();
                    reg_tmp.b[0] = CARRIER(reg_a5)->shots_left;
                    CARRIER(reg_a5)->shots_left -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        CARRIER(reg_a5)->shots_left = (u8) CARRIER(reg_a5)->shots;
                        reg_d0.h[0] = 0x50;
                        reg_d0.h[0] -= g_rank_2_16;
                        CARRIER(reg_a5)->shot_countdown = (u8) reg_d0.b[0];
                    }
                    return;
                }
            }
        } else {
            reg_d0.w = 0x25;
            score_add();
            reg_d0.w = 0;
            if (ENEMY_STATE(reg_a5)->kind == 0x86) {
                reg_d0.w = 8;
            }
            item_spawn();
            if (g_two_player_game == 0) {
                if (reg_d0.h[0] != 8) {
                    item_spawn();
                }
            }
            reg_d0.w = 5;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            temp_a3 = ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->x = temp_a3;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0x400;
            EXPLOSION(reg_a0)->start_y = 0x200;
            EXPLOSION(reg_a0)->start_x = 0x200;
            reg_d0.w = 0xC;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            temp_a2_2 = ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->x = temp_a2_2;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0;
            EXPLOSION(reg_a0)->start_y = 0xF600;
            reg_d0.h[0] = 0x84;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            temp_a2_3 = ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->x = temp_a2_3;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0;
            EXPLOSION(reg_a0)->start_y = 0xEE00;
            EXPLOSION(reg_a0)->start_x = 0xFE00;
            sfx_explosion_air_medium();
            enemy_remove();
        }
    }
}

void bomb_carrier_first(void) {
    enemy_set_entity_count(1);
}

extern s8 D_0025A518[];

void bomb_carrier_start(void) {
    carrier_start_common();
    (*(s8 **)&reg_a0) = D_0025A518;
    reg_d0.h[0] = g_stage_x2;
    (*(s8 **)&reg_a0) = &(*(s8 **)&reg_a0)[reg_d0.h[0]];
    ENTITY(reg_a6)->attr.sb.palette = (s8) *((s8 *)reg_a0);
    CARRIER(reg_a5)->palette = (s8) *((s8 *)reg_a0);
    (*(s8 **)&reg_a0) += 1;
    CARRIER(reg_a5)->hit_palette = (s8) *((s8 *)reg_a0);
    (*(s8 **)&reg_a0) += 1;
}

void shooter_drone_first(void) {
    enemy_set_entity_count(0);
}

extern u8 D_0025A530[];
extern u8 D_0025A550[];
extern u8 D_002623B0[];

extern void sprite_palette_load(void);

void shooter_drone_start(void)
{
    extern void enemy_set_task_state(void);
    extern void enemy_init_entities(void);
    reg_a0 = D_0025A550;
    enemy_init_entities();

    reg_a0 = D_0025A530;
    reg_d0.w = 8;
    enemy_set_task_state();

    reg_tmp.w = 0x38001C00;
    ENTITY(reg_a6)->y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = reg_tmp.h[0];

    reg_a0 = D_002623B0;
    reg_d0.h[0] = 0x16;
    sprite_palette_load();
}

s32 bullet_fire();
s32 debug_number_get();
s32 shooter_drone_debug_print();
s32 entity_draw_layer2();
s32 velocity_from_direction();
s32 direction_to_target_player();
s32 aim256_at_player();
s32 entity_in_shot_limits();
s32 entity_move_by_p2_stick();
extern u16 g_game_frame;

void shooter_drone(void) {
    u8 *ptr;
    u32 save_d0, save_d1, save_d2, save_d3, save_d4, save_d5, save_d6, save_d7;
    u8 *save_a0, *save_a1, *save_a2, *save_a3, *save_a4, *save_a5, *save_a6;

    entity_in_shot_limits();
    if (cond_flag == 0) {
        reg_d0.w = 0x7F;
        reg_d0.h[0] &= g_game_frame;
        if (reg_d0.h[0] == 0) {
            reg_d0.w = 7;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            direction_to_target_player();
            reg_d0.w = 0;
            debug_number_get();
            if ((s32) reg_d0.b[0] < 0x1B) {
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d4.w = (u32) reg_a6;
                reg_d3.w = 0;
                reg_d5.w = 0;
                bullet_fire();
                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d1.h[0] += 0x800;
                aim256_at_player();
                reg_d0.w = 0;
                debug_number_get();
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0x800;
                reg_d4.w = (u32) reg_a6;
                reg_d5.w = 0;
            }
        }
    }
    entity_move_by_p2_stick();
    reg_d1.w = 0x5C;
    ptr = (u8 *)(reg_a6 + 1);
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) {
        reg_d0.b[0] = 0;
        reg_tmp.h[1] = SHOOTER_DRONE(reg_a5)->hp[0];
        reg_tmp.h[0] = SHOOTER_DRONE(reg_a5)->hp[1];
        if (((u32) reg_tmp.w < 0x1FFFFU) && (g_damage_blink_counter == 0)) {
            reg_d0.w = 0x19;
        }
    } else {
        ENTITY(reg_a6)->flags.b[1] &= 0xA3;
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = 0;
        }
        reg_d0.b[0] ^= 0x1F;
        reg_d5.h[0] = ENTITY(reg_a6)->hp.h;
        reg_d6.w = 0x7FFF;
        ENTITY(reg_a6)->hp.h = (u16) reg_d6.h[0];
        ptr = (u8 *)(reg_a5);
        reg_d6.h[0] -= reg_d5.h[0];
        reg_tmp.h[1] = (*(u16 *)((u8 *)(ptr) + (0x18)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(ptr) + (0x1A)));
        reg_tmp.w -= reg_d6.w;
        (*(u16 *)((u8 *)(ptr) + (0x18))) = (u16) reg_tmp.h[1];
        SHOOTER_DRONE(reg_a5)->hp[1] = (u16) reg_tmp.h[0];
    }
    ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
    entity_draw_layer2();
    reg_d0.w = 0x20;
    reg_d1.h[0] = g_game_frame;
    reg_d1.h[0] &= 0x7E;
    reg_d1.h[0] >>= 1;
    reg_d7.h[0] = reg_d1.h[0];
    velocity_from_direction();
    save_d0 = reg_d0.w; save_d1 = reg_d1.w; save_d2 = reg_d2.w; save_d3 = reg_d3.w;
    save_d4 = reg_d4.w; save_d5 = reg_d5.w; save_d6 = reg_d6.w; save_d7 = reg_d7.w;
    save_a0 = reg_a0; save_a1 = reg_a1; save_a2 = reg_a2; save_a3 = reg_a3;
    save_a4 = reg_a4; save_a5 = reg_a5; save_a6 = reg_a6;
    reg_d3.h[0] = reg_d7.h[0];
    reg_d1.h[0] = 0x12;
    reg_d0.h[0] = 0xE;
    reg_d5.h[0] = 0;
    shooter_drone_debug_print();
    reg_d0.w = save_d0; reg_d1.w = save_d1; reg_d2.w = save_d2; reg_d3.w = save_d3;
    reg_d4.w = save_d4; reg_d5.w = save_d5; reg_d6.w = save_d6; reg_d7.w = save_d7;
    reg_a0 = save_a0; reg_a1 = save_a1; reg_a2 = save_a2; reg_a3 = save_a3;
    reg_a4 = save_a4; reg_a5 = save_a5; reg_a6 = save_a6;
    save_d0 = reg_d0.w; save_d1 = reg_d1.w; save_d2 = reg_d2.w; save_d3 = reg_d3.w;
    save_d4 = reg_d4.w; save_d5 = reg_d5.w; save_d6 = reg_d6.w; save_d7 = reg_d7.w;
    save_a0 = reg_a0; save_a1 = reg_a1; save_a2 = reg_a2; save_a3 = reg_a3;
    save_a4 = reg_a4; save_a5 = reg_a5; save_a6 = reg_a6;
    reg_d3.h[0] = reg_d2.h[0];
    reg_d1.h[0] = 0x11;
    reg_d0.h[0] = 0xE;
    reg_d5.h[0] = 0;
    shooter_drone_debug_print();
    reg_d0.w = save_d0; reg_d1.w = save_d1; reg_d2.w = save_d2; reg_d3.w = save_d3;
    reg_d4.w = save_d4; reg_d5.w = save_d5; reg_d6.w = save_d6; reg_d7.w = save_d7;
    reg_a0 = save_a0; reg_a1 = save_a1; reg_a2 = save_a2; reg_a3 = save_a3;
    reg_a4 = save_a4; reg_a5 = save_a5; reg_a6 = save_a6;
    save_d0 = reg_d0.w; save_d1 = reg_d1.w; save_d2 = reg_d2.w; save_d3 = reg_d3.w;
    save_d4 = reg_d4.w; save_d5 = reg_d5.w; save_d6 = reg_d6.w; save_d7 = reg_d7.w;
    save_a0 = reg_a0; save_a1 = reg_a1; save_a2 = reg_a2; save_a3 = reg_a3;
    save_a4 = reg_a4; save_a5 = reg_a5; save_a6 = reg_a6;
    reg_d1.h[0] = 0x10;
    reg_d0.h[0] = 0xE;
    reg_d5.h[0] = 0;
    shooter_drone_debug_print();
    reg_d0.w = save_d0; reg_d1.w = save_d1; reg_d2.w = save_d2; reg_d3.w = save_d3;
    reg_d4.w = save_d4; reg_d5.w = save_d5; reg_d6.w = save_d6; reg_d7.w = save_d7;
    reg_a0 = save_a0; reg_a1 = save_a1; reg_a2 = save_a2; reg_a3 = save_a3;
    reg_a4 = save_a4; reg_a5 = save_a5; reg_a6 = save_a6;
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

void mid_tank_horizontal_first(void) {
    enemy_set_entity_count(1);
}

extern u16 g_direction_sprites_c[];
extern u16 D_0025A570[];
extern u16 D_0025A580[];
extern u16 D_0025A5A0[];
extern u16 D_0025A610[];

void mid_tank_horizontal_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)(D_0025A5A0);
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0;
    MID_TANK_H(reg_a5)->after_entities[0] = (u16) reg_tmp.h[1];
    MID_TANK_H(reg_a5)->after_entities[1] = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)(D_0025A580);
    reg_d0.w = 0xF;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_a2 = (u8 *)(g_direction_sprites_c);
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x300;
        reg_d1.h[0] += 0x5C0;
        aim_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        MID_TANK_H(reg_a5)->turret_a_dir.b[0] = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        MID_TANK_H(reg_a5)->turret_a_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        MID_TANK_H(reg_a5)->turret_a_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x300;
        reg_d1.h[0] += 0x7FFF + 0x79C1;
        aim_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        MID_TANK_H(reg_a5)->turret_b_dir.b[0] = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        MID_TANK_H(reg_a5)->turret_b_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        MID_TANK_H(reg_a5)->turret_b_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d1.b[0] = 4;
        if ((s32) g_stage > 1) {
            reg_d1.b[0] = 4;
        }
        MID_TANK_H(reg_a5)->shot_interval = (u8) reg_d1.b[0];
        if (g_loop != 0) {
            MID_TANK_H(reg_a5)->shots_left += 1;
            MID_TANK_H(reg_a5)->shots += 1;
        }
        reg_d0.h[0] = ENTITY(reg_a6)[1].offset_x.h;
        reg_a0 = (u8 *)(D_0025A610);
        ENTITY(reg_a6)[1].draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)[1].sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = g_rank_8_16;
        MID_TANK_H(reg_a5)->shot_countdown -= reg_d0.b[0];
        reg_a0 = (u8 *)(D_0025A570);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        MID_TANK_H(reg_a5)->palette = *(s8 *)reg_a0;
        reg_a0 += 1;
        MID_TANK_H(reg_a5)->hit_palette = *(s8 *)reg_a0;
        reg_a0 += 1;
        if (!(ENTITY(reg_a6)->flags.b[1] & 0x20)) {
            ENTITY(reg_a6)[1].look.sh = 1;
            ENTITY(reg_a6)[1].hit_y_plus.b[0] = (u8) ENTITY(reg_a6)->misc.b.user;
            if (ENTITY(reg_a6)[1].hit_y_plus.b[0] == 0) {
                reg_a0 = reg_a6 + 0x16;
            } else {
                reg_a0 = reg_a6 + 0x14;
            }
            *(u16 *)reg_a0 = 0xF400;
            ENTITY(reg_a6)->misc.b.user = 0U;
        }
    }
}

s32 bullet_fire_2way();
s32 enemy_variant_offset_a_get();
s32 enemy_variant_timer_a_set();
extern u16 g_direction_offsets_400[];
extern u16 D_0025A620[];

void mid_tank_horizontal(void) {
    s32 enemy_variant_offset_c_get();
    u8 bits;
    u8 *ptr;
    u32 saved;

    enemy_path_step();
    if (enemy_move_end_requested != 0) {
        return;
    }
    if (ENTITY(reg_a6)[1].look.h == 0) goto next_90;
    if (!(ENTITY(reg_a6)->flags.b[1] & 0x20)) goto next_90;
    reg_a0 = reg_a6 + 0x16;
    if (ENTITY(reg_a6)[1].hit_y_plus.h == 0) goto next_20;
    reg_a0 = reg_a6 + 0x14;
    reg_d3.h[0] *= 0xFFFF;
next_20:
    if (!((s16) *(u16 *)reg_a0 < 0xC00)) goto next_90;
    *(u16 *)reg_a0 += reg_d3.h[0];
next_90:
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp1.w = 0;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x1400;
    reg_d0.h[0] += g_side_scroll_x[0];
    reg_tmp1.h[0] = 0xA000;
    reg_tmp.h[0] = reg_d0.h[0];
    saved = reg_tmp.w;
    reg_tmp.w = saved + reg_tmp1.w;
    reg_d0.h[0] += 0xA000;
    if (reg_tmp.h[1] != 0) goto next_120;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x7800;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    saved = reg_tmp.h[0];
    reg_d0.h[0] += 0xC00;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x7800;
    reg_d0.h[1] = saved;
    if (reg_tmp.h[1] == 0) goto next_130;
next_120:
    if (MID_TANK_H(reg_a5)->seen == 0) goto next_140;
    enemy_remove();
    return;
next_130:
    MID_TANK_H(reg_a5)->seen = 1;
next_140:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) goto next_150;
    reg_d0.b[0] = MID_TANK_H(reg_a5)->palette;
    if (!((s32) ENTITY(reg_a6)->hp.h < 0x4A0)) goto next_190;
    if (g_damage_blink_counter != 0) goto next_190;
    reg_d0.w = 0x19;
    goto next_190;
next_150:
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    if (reg_d0.b[0] != 0x19) goto next_160;
    reg_d0.b[0] = MID_TANK_H(reg_a5)->palette;
next_160:
    reg_d2.b[0] = MID_TANK_H(reg_a5)->hit_palette;
    reg_d0.b[0] ^= reg_d2.b[0];
    if (ENTITY(reg_a6)->hp.sh < 0) goto block_d;
next_190:
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    enemy_anims_spawn_listed();
    if (g_enemies_stopped != 0) goto next_280;
    ENTITY(reg_a6)->offset_y.h = 0xF400;
    if (!((s32) ENTITY(reg_a6)->move.b.dir < 0x40)) goto next_280;
    reg_tmp.b[0] = ENTITY(reg_a6)[1].offset_y.b[1];
    ENTITY(reg_a6)[1].offset_y.b[1] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_280;
    ENTITY(reg_a6)[1].offset_y.b[1] = ENTITY(reg_a6)[1].offset_y.b[0];
    ENTITY(reg_a6)->offset_y.h = 0xF3C0;
    if (ENTITY(reg_a6)->move.b.dir != 0x10) goto next_250;
    ENTITY(reg_a6)[1].offset_x.h += 4;
    if (ENTITY(reg_a6)[1].offset_x.h != 0x10) goto next_260;
    ENTITY(reg_a6)[1].offset_x.h = 0;
    goto next_260;
next_250:
    reg_tmp.h[0] = ENTITY(reg_a6)[1].offset_x.h;
    ENTITY(reg_a6)[1].offset_x.h -= 4;
    if (!((s32) reg_tmp.h[0] < 4)) goto next_260;
    ENTITY(reg_a6)[1].offset_x.h = 0xC;
next_260:
    reg_d0.h[0] = ENTITY(reg_a6)[1].offset_x.h;
    reg_a0 = (u8 *) D_0025A610;
    ENTITY(reg_a6)[1].draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)[1].sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
next_280:
    if (g_enemies_stopped != 0) goto block_b;
    if (g_bullets_blocked != 0) goto block_b;
    reg_tmp.b[0] = MID_TANK_H(reg_a5)->turn_countdown;
    MID_TANK_H(reg_a5)->turn_countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_b;
    MID_TANK_H(reg_a5)->turn_countdown = MID_TANK_H(reg_a5)->turn_interval;
    reg_d0.b[0] = MID_TANK_H(reg_a5)->shots_left;
    if (MID_TANK_H(reg_a5)->shots != reg_d0.b[0]) goto block_b;
    reg_a0 = (u8 *) ((u16 *)g_player1);
    reg_a1 = (u8 *) ((u16 *)g_player2);
    if (ENEMY_STATE(reg_a5)->target_player == 0) goto next_320;
    reg_atmp = (u8 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) reg_atmp;
next_320:
    ptr = reg_a0;
    if ((*(s16 *)ptr) < 0) goto next_340;
    if ((*(s16 *)reg_a1) >= 0) goto block_b;
    reg_a0 = reg_a1;
    reg_atmp = (u8 *) ptr;
    reg_a1 = ptr;
next_340:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_a3 = (u8 *) g_direction_sprites_c;
    bits = ENTITY(reg_a6)->flags.b[0];
    if (!(bits & 0x40)) goto next_350;
    ENTITY(reg_a6)->flags.b[0] = bits & 0xBF;
    goto next_380;
next_350:
    ENTITY(reg_a6)->flags.b[0] = bits | 0x40;
    reg_d0.h[0] += 0x300;
    reg_d1.h[0] += 0x5C0;
    direction_between();
    reg_d0.h[0] = MID_TANK_H(reg_a5)->turret_a_dir.h;
    direction_turn_toward();
    MID_TANK_H(reg_a5)->turret_a_dir.h = reg_d1.h[0];
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    MID_TANK_H(reg_a5)->turret_a_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    MID_TANK_H(reg_a5)->turret_a_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
    goto block_b;
next_380:
    reg_d0.h[0] += 0x300;
    reg_d1.h[0] += 0xF9C0;
    direction_between();
    reg_d0.h[0] = MID_TANK_H(reg_a5)->turret_b_dir.h;
    direction_turn_toward();
    MID_TANK_H(reg_a5)->turret_b_dir.h = reg_d1.h[0];
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    MID_TANK_H(reg_a5)->turret_b_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    MID_TANK_H(reg_a5)->turret_b_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
block_b:
    enemy_variant_offset_a_get();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0xF500;
    reg_d1.h[1] += 0xF200;
    reg_d2.h[1] = ENTITY(reg_a6)[1].draw.h;
    reg_d2.h[0] = ENTITY(reg_a6)[1].sprite.h;
    reg_d3.h[0] = 0x458;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    enemy_variant_offset_c_get();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2C0;
    reg_d1.h[1] += 0xFF00;
    reg_d2.h[1] = MID_TANK_H(reg_a5)->turret_a_sprite[0];
    reg_d2.h[0] = MID_TANK_H(reg_a5)->turret_a_sprite[1];
    reg_d3.h[0] = 0x418;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    enemy_variant_offset_c_get();
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0xF6C0;
    reg_d2.h[1] = MID_TANK_H(reg_a5)->turret_b_sprite[0];
    reg_d2.h[0] = MID_TANK_H(reg_a5)->turret_b_sprite[1];
    enemy_variant_offset_c_get();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    if (g_enemies_stopped != 0) goto block_rts;
    if (g_bullets_blocked != 0) goto block_rts;
    if (ENTITY(reg_a6)->y.sh < 0x1000) goto block_rts;
    reg_tmp.b[0] = MID_TANK_H(reg_a5)->shot_countdown;
    MID_TANK_H(reg_a5)->shot_countdown -= 1;
    switch (reg_tmp.b[0]) {
    case 0:
        goto block_c;
    }
block_rts:
    return;
block_c:
    MID_TANK_H(reg_a5)->shot_countdown = MID_TANK_H(reg_a5)->shot_interval;
    reg_a4 = (u8 *) g_direction_offsets_400;
    reg_d1.h[0] = MID_TANK_H(reg_a5)->turret_a_dir.h;
    reg_d0.h[0] = reg_d1.h[0];
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] += 0x5C0;
    reg_d3.h[1] += 0x300;
    reg_d4.w = 0;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.w = 0x30004;
    bits = MID_TANK_H(reg_a5)->variant;
    if (bits != 0) goto next_610;
    reg_d1.h[0] += 3;
    goto next_620;
next_610:
    if ((bits & 0xFF) != 1) goto next_620;
    reg_d1.h[0] += 5;
next_620:
    bullet_fire_2way();
    reg_d1.h[0] -= 5;
    bullet_fire_fixed();
    reg_d1.h[0] -= 5;
    bullet_fire_2way();
    reg_d1.h[0] = MID_TANK_H(reg_a5)->turret_b_dir.h;
    reg_d4.h[0] = reg_d1.h[0];
    reg_d4.h[0] &= 0x3E;
    reg_d4.h[0] += reg_d4.h[0];
    reg_d3.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16)reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((u16)reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] += 0xF9C0;
    reg_d3.h[1] += 0x300;
    reg_d4.w = 0;
    reg_d0.w = 0x30004;
    bits = MID_TANK_H(reg_a5)->variant;
    if (bits != 0) goto next_640;
    reg_d1.h[0] -= 3;
    goto next_650;
next_640:
    if ((bits & 0xFF) != 1) goto next_650;
    reg_d1.h[0] -= 5;
next_650:
    bullet_fire_2way();
    reg_d1.h[0] += 5;
    bullet_fire_fixed();
    reg_d1.h[0] += 5;
    bullet_fire_2way();
    reg_tmp.b[0] = MID_TANK_H(reg_a5)->shots_left;
    MID_TANK_H(reg_a5)->shots_left -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_690;
    MID_TANK_H(reg_a5)->shots_left = MID_TANK_H(reg_a5)->shots;
    reg_d0.h[0] = 0xA;
    reg_d1.h[0] = g_rank_1_16;
    reg_d1.h[0] >>= 2;
    reg_d0.h[0] -= reg_d1.h[0];
    MID_TANK_H(reg_a5)->shot_countdown = reg_d0.b[0];
    reg_tmp.b[0] = MID_TANK_H(reg_a5)->variant;
    MID_TANK_H(reg_a5)->variant -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_690;
    MID_TANK_H(reg_a5)->variant = MID_TANK_H(reg_a5)->variants;
    reg_d0.h[0] = 0x60;
    reg_d0.h[0] -= g_rank_5_16;
    MID_TANK_H(reg_a5)->shot_countdown = reg_d0.b[0];
next_690:
    return;
block_d:
    reg_d0.w = 0x115;
    score_add();
    sfx_explosion_ground_large();
    reg_d1.h[0] = 0;
    reg_d2.w = -0x600U;
    reg_d0.w = 0xC;
    wreck_spawn_a();
    reg_d2.w = 0x600;
    wreck_spawn_a();
    reg_d0.w = 8;
    reg_a4 = (u8 *)(D_0025A620);
    reg_d6.w = 6;
    do {
        reg_d1.h[1] = *(u16 *)reg_a4;
        reg_a4 += 2;
        reg_d1.h[0] = *(u16 *)reg_a4;
        reg_a4 += 2;
        pickup_spawn_plain();
    } while ((s16)(--reg_d6.h[0]) >= 0);
    reg_d0.w = 0xD;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    enemy_variant_timer_a_set();
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    EXPLOSION(reg_a0)->start_y = 0x200;
    EXPLOSION(reg_a0)->start_x = 0;
    EXPLOSION(reg_a0)->follows_scroll = 1;
    reg_d0.w = 0xC;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    enemy_variant_timer_a_set();
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->start_y = 0xFE00;
    EXPLOSION(reg_a0)->start_x = 0xFA00;
    EXPLOSION(reg_a0)->move.h = 0x5C0;
    EXPLOSION(reg_a0)->follows_scroll = 1;
    reg_d0.w = 0xC;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    enemy_variant_timer_a_set();
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    EXPLOSION(reg_a0)->start_y = 0xFC00;
    EXPLOSION(reg_a0)->start_x = 0x200;
    EXPLOSION(reg_a0)->move.h = 0x440;
    EXPLOSION(reg_a0)->follows_scroll = 1;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    enemy_variant_timer_a_set();
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->start_y = 0xFE00;
    EXPLOSION(reg_a0)->start_x = 0;
    EXPLOSION(reg_a0)->move.h = 0x380;
    EXPLOSION(reg_a0)->follows_scroll = 1;
    enemy_remove();
}

void ground_turret_a_first(void) {
    enemy_set_entity_count(0);
}

extern u16 D_0025A640[];
extern u16 D_0025A650[];
extern u16 D_0025A660[];

void ground_turret_a_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)(D_0025A660);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_0025A650);
    reg_d0.w = 5;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if ((g_stage == 0) && ((s32) g_scroll_line >= 0x156)) {
            ENTITY(reg_a6)->hp.sh = 0x500;
        }
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        direction_to_target_player();
        reg_a0 = (u8 *)(g_direction_sprites_c);
        GROUND_TURRET(reg_a5)->dir.b[0] = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.b[0] = 4;
        if ((s32) g_stage > 1) {
            reg_d0.b[0] = 4;
        }
        GROUND_TURRET(reg_a5)->shot_interval = (u8) reg_d0.b[0];
        reg_d0.h[0] = g_rank_5_16;
        GROUND_TURRET(reg_a5)->shot_countdown -= reg_d0.b[0];
        reg_a0 = (u8 *)(D_0025A640);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        GROUND_TURRET(reg_a5)->palette = *(s8 *)reg_a0;
        reg_a0 += 1;
        GROUND_TURRET(reg_a5)->hit_palette = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}

s32 pickup_spawn_variant_here();
s32 enemy_fire_distance_check();
s32 enemy_variant_offset_b_get();
s32 enemy_variant_word_get();
s32 enemy_variant_get();
s32 sfx_explosion_air_small();
s32 wreck_spawn();
extern s16 g_player2[];
extern s16 g_player1[];

void ground_turret_a(void) {
    s16 *temp_v1;
    s16 *var_a0;

    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        entity_check_bounds();
        if (cond_flag != 0) {
            if (GROUND_TURRET(reg_a5)->seen != 0) {
                enemy_remove();
                return;
            }
            goto block_5;
        }
        GROUND_TURRET(reg_a5)->seen = 1U;
block_5:
        var_a0 = (s16 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(var_a0) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = GROUND_TURRET(reg_a5)->palette;
            if (((s32) (*(u16 *)((u8 *)(var_a0) + (0x18))) < 0x140) && (g_damage_blink_counter == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_12;
        }
        (*(u8 *)((u8 *)(var_a0) + (1))) &= 0xA3;
        score_add_no_chain();
        var_a0 = (s16 *)(reg_a6);
        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x1C)));
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = GROUND_TURRET(reg_a5)->palette;
        }
        reg_d2.b[0] = GROUND_TURRET(reg_a5)->hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) (*(u16 *)((u8 *)(var_a0) + (0x18))) >= 0) {
block_12:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            if (g_enemies_stopped == 0) {
                if (g_bullets_blocked == 0) {
                    reg_tmp.b[0] = GROUND_TURRET(reg_a5)->turn_countdown;
                    GROUND_TURRET(reg_a5)->turn_countdown -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        GROUND_TURRET(reg_a5)->turn_countdown = (u8) GROUND_TURRET(reg_a5)->turn_interval;
                        var_a0 = (s16 *)(reg_a5);
                        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x1D)));
                        if ((*(u8 *)((u8 *)(var_a0) + (0x1C))) == reg_d0.b[0]) {
                            reg_a0 = (u8 *)(g_player1);
                            reg_a1 = (u8 *)(g_player2);
                            if ((*(u8 *)((u8 *)(var_a0) + (2))) != 0) {
                                reg_atmp = (u8 *)(reg_a0);
                                reg_a0 = (u8 *)(reg_a1);
                                reg_a1 = (u8 *)(reg_atmp);
                            }
                            temp_v1 = (s16 *)(reg_a0);
                            if ((*(s16 *)((u8 *)(temp_v1) + (0))) >= 0) {
                                var_a0 = (s16 *)(reg_a1);
                                if (*var_a0 < 0) {
                                    reg_a0 = (u8 *)(var_a0);
                                    reg_atmp = (u8 *)(temp_v1);
                                    reg_a1 = (u8 *)(temp_v1);
                                    goto block_21;
                                }
                            } else {
block_21:
                                reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                                reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                                direction_between();
                                reg_d0.h[0] = GROUND_TURRET(reg_a5)->dir.h;
                                direction_turn_toward();
                                var_a0 = (s16 *) reg_d1.h[0];
                                GROUND_TURRET(reg_a5)->dir.h = (u16) var_a0;
                                reg_a3 = (u8 *)(g_direction_sprites_c);
                                reg_d1.h[0] &= 0x3E;
                                reg_d1.h[0] += reg_d1.h[0];
                                ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                                ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                            }
                        }
                    }
                    if ((s16) ENTITY(reg_a6)->y.h >= 0x1000) {
                        reg_tmp.b[0] = GROUND_TURRET(reg_a5)->shot_countdown;
                        GROUND_TURRET(reg_a5)->shot_countdown -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            GROUND_TURRET(reg_a5)->shot_countdown = (u8) GROUND_TURRET(reg_a5)->shot_interval;
                            enemy_fire_distance_check();
                            if (cond_flag == 0) {
                                reg_a4 = (u8 *)(g_direction_offsets_500);
                                reg_d1.h[0] = GROUND_TURRET(reg_a5)->dir.h;
                                reg_d0.h[0] = reg_d1.h[0];
                                reg_d0.h[0] &= 0x3E;
                                reg_d0.h[0] += reg_d0.h[0];
                                reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
                                reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a4;
                                reg_d3.w = 0x80000 + reg_d3.w;
                                reg_d0.w = 0x20006;
                                reg_d4.w = 0;
                                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                                bullet_fire_fixed();
                                reg_tmp.b[0] = GROUND_TURRET(reg_a5)->shots_left;
                                GROUND_TURRET(reg_a5)->shots_left -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    GROUND_TURRET(reg_a5)->shots_left = (u8) GROUND_TURRET(reg_a5)->shots;
                                    reg_d0.h[0] = 0x40;
                                    reg_d0.h[0] -= g_rank_2_16;
                                    reg_d0.h[0] += 4;
                                    GROUND_TURRET(reg_a5)->shot_countdown = (u8) reg_d0.b[0];
                                }
                            }
                        }
                    }
                }
            }
            reg_d6.w = 0xF800F800;
            enemy_variant_offset_b_get();
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            return;
        }
        reg_d0.w = 0x20;
        score_add();
        sfx_explosion_air_small();
        enemy_variant_word_get();
        reg_d0.w = 8;
        wreck_spawn();
        reg_d0.w = 8;
        enemy_variant_get();
        pickup_spawn_variant_here();
        reg_d0.w = 0xC;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        enemy_variant_timer_a_set();
        EXPLOSION(reg_a0)->debris = 1;
        EXPLOSION(reg_a0)->debris_arg = 0;
        EXPLOSION(reg_a0)->start_y = 0;
        EXPLOSION(reg_a0)->start_x = 0;
        EXPLOSION(reg_a0)->follows_scroll = 1;
        enemy_remove();
    }
}

void bee_container_first(void) {
    enemy_set_entity_count(0);
}

s32 enemy_set_task_state();                            /* extern */
s32 enemy_init_entities();                            /* extern */
s32 enemy_path_start();                            /* extern */
extern s32 D_0025A680[];
extern s32 D_0028C9E8;

void bee_container_start(void) {
    reg_a0 = (u8 *)D_0025A680;
    enemy_init_entities();
    reg_a0 = (u8 *)(&D_0028C9E8);
    reg_d0.w = 2;
    enemy_set_task_state();
    enemy_path_start();
    if ((enemy_move_end_requested == 0) && (ENTITY(reg_a6)->misc.b.user != 0)) {
        ENTITY(reg_a6)->misc.b.user = 0U;
        CONTAINER(reg_a5)->second = 0x40;
    }
}

s32 entity_follow_scroll();
s32 players_alive_mask();
extern u8 g_boss_present_b1;

void bee_container(void) {
    u32 saved;
    u8 t;

    if ((s8)g_boss_present_b1 < 0) goto block_1;
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    entity_follow_scroll();
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0xC00;
    reg_d0.h[0] += g_side_scroll_x[0];
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    saved = reg_tmp.w;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xB000;
    reg_tmp.w = saved + reg_tmp1.w;
    reg_d0.h[0] += 0xB000;
    if (reg_tmp.h[1] != 0) goto next_1;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x8C00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    saved = reg_tmp.h[0];
    reg_d0.h[0] += 0x400;
    reg_tmp.w = 0;
    reg_d0.h[1] = saved;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x8C00;
    if (reg_tmp.h[1] == 0) goto next_2;
next_1:
    switch (CONTAINER(reg_a5)->seen) {
    case 0:
        goto next_3;
    }
block_1:
    enemy_remove();
    return;
next_2:
    CONTAINER(reg_a5)->seen = 1;
next_3:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto next_4;
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    if (ENTITY(reg_a6)->hp.sh < 0) goto block_3;
next_4:
    if (g_bomb_entities[0] != 0) goto next_9;
    players_alive_mask();
    if (reg_d0.h[0] == 0) goto block_rts;
    if (!(reg_d0.h[0] & 1)) goto next_6;
    reg_d2.h[0] = PLAYER(g_player1)->x.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] -= reg_d2.h[0];
    if ((s16) reg_d1.h[0] >= 0) goto next_5;
    reg_d1.h[0] *= 0xFFFF;
next_5:
    if ((s32) reg_d1.h[0] < 0x240) goto next_8;
    if (!(reg_d0.h[0] & 2)) goto block_rts;
next_6:
    reg_d2.h[0] = PLAYER(g_player2)->x.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] -= reg_d2.h[0];
    if ((s16) reg_d1.h[0] >= 0) goto next_7;
    reg_d1.h[0] *= 0xFFFF;
next_7:
    if ((s32) reg_d1.h[0] > 0x23F) goto block_rts;
next_8:
    CONTAINER(reg_a5)->first = 0xF;
next_9:
    CONTAINER(reg_a5)->first -= 1;
    t = ENTITY(reg_a6)->flags.b[0];
    if (!(t & 0x40)) goto next_10;
    ENTITY(reg_a6)->flags.b[0] = t & 0xBF;
    goto block_2;
next_10:
    ENTITY(reg_a6)->flags.b[0] = t | 0x40;
    reg_tmp.h[1] = ENTITY(reg_a6)->draw.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->sprite.h;
    reg_tmp.w ^= 3;
    ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
    enemy_variant_offset_a_get();
block_2:
    return;
block_3:
    reg_d0.w = 1;
    score_add();
    sfx_explosion_air_small();
    reg_d0.h[0] = CONTAINER(reg_a5)->second;
    reg_d2.b[0] = ENTITY(reg_a6)->misc.b.draw_layer;
    pickup_spawn_variant_here();
    reg_d0.w = 0xC;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = ENTITY(reg_a6)->x.h;
    enemy_variant_timer_a_set();
    reg_d0.h[0] = 1;
    EXPLOSION(reg_a0)->follows_scroll = reg_d0.h[0];
    enemy_remove();
block_rts:
    return;
}

void star_container_first(void) {
    enemy_set_entity_count(0);
}

extern u32 D_0025A6A0[];
extern u32 D_0028C9F0;

void star_container_start(void)
{
    extern void enemy_set_task_state(void);
    extern void enemy_init_entities(void);
    extern void enemy_path_start(void);
    reg_a0 = (u8 *)D_0025A6A0;
    enemy_init_entities();

    reg_a0 = (u8 *)&D_0028C9F0;
    reg_d0.w = 1;
    enemy_set_task_state();
    enemy_path_start();

    if (enemy_move_end_requested == 0 && g_stage == 1 && (s16)g_scroll_line < 4) {
        ENTITY(reg_a6)->flags.h = 0x8000;
    }
}

void star_container(void) {
    u32 saved;

    if ((s8)g_boss_present_b1 < 0) goto block_1;
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    entity_follow_scroll();
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp1.w = 0;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x400;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp1.h[0] = 0x8C00;
    saved = reg_tmp.w;
    reg_tmp.w = saved + reg_tmp1.w;
    reg_d0.h[0] += 0x8C00;
    if (reg_tmp.h[1] != 0) goto next_1;
    reg_d0.h[0] = g_side_scroll_x[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] + 0x800;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x400;
    reg_tmp1.w = 0;
    reg_tmp.w = 0;
    reg_tmp1.h[0] = 0xC000;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d1.h[0] += reg_d0.h[0];
    reg_d1.h[0] += 0xC000;
    if (reg_tmp.h[1] == 0) goto next_2;
next_1:
    if (CONTAINER(reg_a5)->seen == 0) goto next_3;
block_1:
    enemy_remove();
    return;
next_2:
    CONTAINER(reg_a5)->seen = 1;
next_3:
    if (g_stage != 1) goto next_4;
    if ((s16) g_scroll_line < 4) goto next_4;
    ENTITY(reg_a6)->flags.b[1] |= 0x20;
next_4:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto next_5;
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    if (ENTITY(reg_a6)->hp.sh < 0) goto block_2;
next_5:
    return;
block_2:
    reg_d0.w = 1;
    score_add();
    sfx_explosion_air_small();
    reg_d0.h[0] = CONTAINER(reg_a5)->first;
    reg_d2.b[0] = ENTITY(reg_a6)->misc.b.draw_layer;
    pickup_spawn_variant_here();
    reg_d0.w = 1;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = ENTITY(reg_a6)->x.h;
    enemy_variant_timer_a_set();
    reg_d0.h[0] = 1;
    EXPLOSION(reg_a0)->follows_scroll = reg_d0.h[0];
    enemy_remove();
}


void water_flower_draw_petals(void) {
    extern void enemy_variant_offset_c_get(void);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0xFB00;
    reg_d1.h[1] += 0xFC00;
    reg_d1.h[1] += WATER_FLOWER(reg_a5)->bob;
    reg_d2.h[1] = WATER_FLOWER(reg_a5)->petal_sprite[0];
    reg_d2.h[0] = WATER_FLOWER(reg_a5)->petal_sprite[1];
    reg_d3.h[0] = 0x428;
    reg_d4.h[0] = 0xD;
    enemy_variant_offset_c_get();
}

void water_flower_turret_first(void) {
    enemy_set_entity_count(0);
}

s32 rng_next_masked();
s32 rng_next_unsigned();
extern u16 D_0025A6C0[];
extern u16 D_0025A6D0[];
extern u16 D_0025A6F0[];
extern u16 D_0025A710[];

void water_flower_turret_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)(D_0025A6F0);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_0025A6D0);
    reg_d0.w = 0xB;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        direction_to_target_player();
        WATER_FLOWER(reg_a5)->dir.b[0] = (u8) reg_d1.b[0];
        reg_a0 = (u8 *)(D_0025A710);
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        rng_next_unsigned();
        WATER_FLOWER(reg_a5)->bob_angle.b[0] = (u8) reg_d0.b[0];
        reg_d0.h[0] = g_rank_4_16;
        reg_d0.b[0] -= 4;
        WATER_FLOWER(reg_a5)->shot_countdown -= reg_d0.b[0];
        rng_next_masked();
        reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
        WATER_FLOWER(reg_a5)->shot_countdown += reg_d0.b[0];
        reg_a0 = (u8 *)(D_0025A6C0);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        WATER_FLOWER(reg_a5)->palette = *(s8 *)reg_a0;
        reg_a0 += 1;
        WATER_FLOWER(reg_a5)->hit_palette = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}

s32 bullet_fire_double();
extern u16 D_0025A790[];
extern u16 D_0025A7B0[];
extern u16 D_0025A830[];
extern u16 D_0025AEE0[];

void water_flower_turret(void) {
    s32 enemy_variant_offset_c_get();
    u8 *ptr;

    enemy_path_step();
    if (enemy_move_end_requested != 0) {
        return;
    }
    entity_check_bounds();
    if (cond_flag == 0) goto next_30;
    if (WATER_FLOWER(reg_a5)->seen == 0) goto next_40;
    enemy_remove();
    return;
next_30:
    WATER_FLOWER(reg_a5)->seen = 1;
next_40:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) goto next_50;
    reg_d0.b[0] = WATER_FLOWER(reg_a5)->palette;
    if (!((s32) ENTITY(reg_a6)->hp.h < 0x50)) goto next_90;
    if (g_damage_blink_counter != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    if (reg_d0.b[0] != 0x19) goto next_60;
    reg_d0.b[0] = WATER_FLOWER(reg_a5)->palette;
next_60:
    reg_d2.b[0] = WATER_FLOWER(reg_a5)->hit_palette;
    reg_d0.b[0] ^= reg_d2.b[0];
    if (ENTITY(reg_a6)->hp.sh < 0) goto block_dead;
next_90:
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    reg_tmp.b[0] = WATER_FLOWER(reg_a5)->frame_countdown;
    WATER_FLOWER(reg_a5)->frame_countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_120;
    WATER_FLOWER(reg_a5)->frame_countdown = WATER_FLOWER(reg_a5)->frame_interval;
    reg_d0.h[0] = WATER_FLOWER(reg_a5)->petal_frame;
    reg_a0 = (u8 *) D_0025A790;
    WATER_FLOWER(reg_a5)->petal_sprite[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    WATER_FLOWER(reg_a5)->petal_sprite[1] = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = WATER_FLOWER(reg_a5)->petal_frame;
    WATER_FLOWER(reg_a5)->petal_frame -= 4;
    if (!((s32) reg_tmp.h[0] < 4)) goto next_120;
    WATER_FLOWER(reg_a5)->petal_frame = 0x14;
next_120:
    reg_d0.h[0] = WATER_FLOWER(reg_a5)->bob_angle.h;
    reg_a0 = (u8 *) D_0025A830;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    WATER_FLOWER(reg_a5)->bob = reg_d0.h[0];
    reg_d0.h[0] += 0xF800;
    ENTITY(reg_a6)->offset_y.h = reg_d0.h[0];
    WATER_FLOWER(reg_a5)->bob_angle.b[0] += 3;
    if ((s8) ENTITY(reg_a6)->flags.b[0] >= 0) goto next_200;
block_base:
    enemy_variant_offset_a_get();
    water_flower_draw_petals();
    if (g_frame_mod2 == 0) goto next_150;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[1] += 0x100;
    reg_d1.h[0] += 0xFE00;
    reg_d1.h[1] += WATER_FLOWER(reg_a5)->bob;
    reg_a0 = (u8 *) D_0025AEE0;
    reg_d2.w = 6;
    reg_d2.h[0] &= g_game_frame;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = 0x1E;
    enemy_variant_offset_c_get();
next_150:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    return;
next_200:
    if (g_enemies_stopped != 0) goto block_objset;
    if (g_bullets_blocked != 0) goto block_objset;
    reg_tmp.b[0] = WATER_FLOWER(reg_a5)->turn_countdown;
    WATER_FLOWER(reg_a5)->turn_countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_objset;
    WATER_FLOWER(reg_a5)->turn_countdown = WATER_FLOWER(reg_a5)->turn_interval;
    reg_d0.b[0] = WATER_FLOWER(reg_a5)->shots_left;
    if (WATER_FLOWER(reg_a5)->shots != reg_d0.b[0]) goto block_objset;
    reg_a0 = (u8 *) ((u16 *)g_player1);
    reg_a1 = (u8 *) ((u16 *)g_player2);
    if (ENEMY_STATE(reg_a5)->target_player == 0) goto next_220;
    reg_atmp = (u8 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) reg_atmp;
next_220:
    ptr = reg_a0;
    if ((*(s16 *)ptr) < 0) goto next_240;
    if ((*(s16 *)reg_a1) >= 0) goto block_objset;
    reg_a0 = reg_a1;
    reg_atmp = (u8 *) ptr;
    reg_a1 = ptr;
next_240:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    reg_d0.h[0] = WATER_FLOWER(reg_a5)->dir.h;
    direction_turn_toward();
    WATER_FLOWER(reg_a5)->dir.h = reg_d1.h[0];
    reg_a0 = (u8 *) D_0025A710;
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
block_objset:
    enemy_variant_offset_a_get();
    water_flower_draw_petals();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    if (g_enemies_stopped != 0) goto block_rts;
    if (g_bullets_blocked != 0) goto block_rts;
    if ((ENTITY(reg_a6)->y.sh) < 0x1000) goto block_rts;
    reg_tmp.b[0] = WATER_FLOWER(reg_a5)->shot_countdown;
    WATER_FLOWER(reg_a5)->shot_countdown -= 1;
    switch (reg_tmp.b[0]) {
    case 0:
        goto block_fire;
    }
block_rts:
    return;
block_fire:
    reg_d0.h[0] = 8;
    reg_d1.h[0] = g_rank_1_16;
    reg_d1.h[0] >>= 2;
    reg_d0.h[0] -= reg_d1.h[0];
    WATER_FLOWER(reg_a5)->shot_countdown = reg_d0.b[0];
    enemy_fire_distance_check();
    if (cond_flag != 0) goto block_rts;
    reg_a4 = (u8 *) D_0025A7B0;
    reg_d1.h[0] = WATER_FLOWER(reg_a5)->dir.h;
    reg_d0.h[0] = reg_d1.h[0];
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d4.w = (u32) reg_a6;
    reg_d0.w = 0xC;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    if (WATER_FLOWER(reg_a5)->shots_left != 2) goto next_620;
    bullet_fire_double();
    goto next_630;
next_620:
    bullet_fire_fixed();
next_630:
    reg_tmp.b[0] = WATER_FLOWER(reg_a5)->shots_left;
    WATER_FLOWER(reg_a5)->shots_left -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_650;
    WATER_FLOWER(reg_a5)->shots_left = WATER_FLOWER(reg_a5)->shots;
    reg_d0.h[0] = 0x50;
    reg_d0.h[0] -= g_rank_5_16;
    reg_d0.h[0] += 4;
    WATER_FLOWER(reg_a5)->shot_countdown = reg_d0.b[0];
next_650:
    return;
block_dead:
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
    ENTITY(reg_a6)->flags.b[0] |= 0x80;
    if (reg_tmp.b[0] & 0x80) goto block_dead2;
    reg_d0.w = 0x11;
    score_add();
    reg_d0.w = 0xB;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = ENTITY(reg_a6)->x.h;
    enemy_variant_timer_a_set();
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->start_y = 0;
    EXPLOSION(reg_a0)->start_x = 0;
    EXPLOSION(reg_a0)->follows_scroll = 2;
    ENTITY(reg_a6)->flags.b[1] &= 0xFD;
    reg_tmp.w = 0x1957;
    ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
    ENTITY(reg_a6)->hp.h = 0x140;
    goto block_base;
block_dead2:
    sfx_explosion_air_small();
    reg_d0.w = 8;
    score_add();
    reg_d0.h[0] = 0xC;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = ENTITY(reg_a6)->x.h;
    enemy_variant_timer_a_set();
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->start_y = 0xFC00;
    EXPLOSION(reg_a0)->start_x = 0;
    EXPLOSION(reg_a0)->follows_scroll = 1;
    enemy_remove();
}

void ground_turret_b_first(void) {
    enemy_set_entity_count(0);
}

extern u16 g_direction_sprites_e[];
extern u16 D_0025AC38[];
extern u16 D_0025AC48[];
extern u16 D_0025AC60[];

void ground_turret_b_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)(D_0025AC60);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_0025AC48);
    reg_d0.w = 5;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if ((g_stage == 0) && ((s32) g_scroll_line >= 0x156)) {
            ENTITY(reg_a6)->hp.sh = 0x280;
        }
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        direction_to_target_player();
        reg_a0 = (u8 *)(g_direction_sprites_e);
        GROUND_TURRET(reg_a5)->dir.b[0] = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.b[0] = 4;
        if ((s32) g_stage > 1) {
            reg_d0.b[0] = 4;
        }
        GROUND_TURRET(reg_a5)->shot_interval = (u8) reg_d0.b[0];
        reg_d0.h[0] = g_rank_5_16;
        GROUND_TURRET(reg_a5)->shot_countdown -= reg_d0.b[0];
        reg_a0 = (u8 *)(D_0025AC38);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        GROUND_TURRET(reg_a5)->palette = *(s8 *)reg_a0;
        reg_a0 += 1;
        GROUND_TURRET(reg_a5)->hit_palette = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}

extern u16 g_direction_twin_offsets_840[];

void ground_turret_b(void) {
    s16 *temp_a0;
    s16 *temp_v1;
    u16 temp_a0_2;
    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        entity_check_bounds();
        if (cond_flag != 0) {
            if (GROUND_TURRET(reg_a5)->seen != 0) {
                enemy_remove();
                return;
            }
            goto block_5;
        }
        GROUND_TURRET(reg_a5)->seen = 1U;
block_5:
        temp_a0 = (s16 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(temp_a0) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = GROUND_TURRET(reg_a5)->palette;
            if (((s32) (*(u16 *)((u8 *)(temp_a0) + (0x18))) < 0x120) && (g_damage_blink_counter == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_12;
        }
        (*(u8 *)((u8 *)(temp_a0) + (1))) &= 0xA3;
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = GROUND_TURRET(reg_a5)->palette;
        }
        reg_d2.b[0] = GROUND_TURRET(reg_a5)->hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
block_12:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0)) {
                reg_tmp.b[0] = GROUND_TURRET(reg_a5)->turn_countdown;
                GROUND_TURRET(reg_a5)->turn_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    GROUND_TURRET(reg_a5)->turn_countdown = (u8) GROUND_TURRET(reg_a5)->turn_interval;
                    enemy_fire_distance_check();
                    if (cond_flag == 0) {
                        reg_d0.b[0] = GROUND_TURRET(reg_a5)->shots_left;
                        if (GROUND_TURRET(reg_a5)->shots == reg_d0.b[0]) {
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
                                    goto block_22;
                                }
                            } else {
block_22:
                                reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                                reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                                direction_between();
                                reg_d0.h[0] = GROUND_TURRET(reg_a5)->dir.h;
                                direction_turn_toward();
                                GROUND_TURRET(reg_a5)->dir.h = (u16) reg_d1.h[0];
                                reg_a3 = (u8 *)(g_direction_sprites_e);
                                reg_d1.h[0] &= 0x3E;
                                reg_d1.h[0] += reg_d1.h[0];
                                ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                                ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                            }
                        }
                    }
                }
                if ((s16) ENTITY(reg_a6)->y.h >= 0x1000) {
                    reg_tmp.b[0] = GROUND_TURRET(reg_a5)->shot_countdown;
                    GROUND_TURRET(reg_a5)->shot_countdown -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        GROUND_TURRET(reg_a5)->shot_countdown = (u8) GROUND_TURRET(reg_a5)->shot_interval;
                        enemy_fire_distance_check();
                        if (cond_flag == 0) {
                            reg_a4 = (u8 *)(g_direction_twin_offsets_840);
                            reg_d1.h[0] = GROUND_TURRET(reg_a5)->dir.h;
                            reg_d0.h[0] = reg_d1.h[0];
                            reg_d0.h[0] &= 0x3E;
                            reg_d0.h[0] *= 4;
                            reg_a4 += reg_d0.h[0];
                            reg_d3.h[1] = *(u16 *)reg_a4;
                            reg_a4 += 2;
                            temp_a0_2 = *(u16 *)reg_a4;
                            reg_d3.h[0] = temp_a0_2;
                            reg_a4 += 2;
                            reg_d0.w = 6;
                            reg_d4.w = 0;
                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                            bullet_fire_fixed();
                            reg_d3.h[1] = *(u16 *)reg_a4;
                            reg_a4 += 2;
                            reg_d3.h[0] = *(u16 *)reg_a4;
                            reg_a4 += 2;
                            bullet_fire_fixed();
                            reg_tmp.b[0] = GROUND_TURRET(reg_a5)->shots_left;
                            GROUND_TURRET(reg_a5)->shots_left -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                GROUND_TURRET(reg_a5)->shots_left = (u8) GROUND_TURRET(reg_a5)->shots;
                                reg_d0.h[0] = 0x40;
                                reg_d0.h[0] -= g_rank_4_16;
                                reg_d0.h[0] += 8;
                                GROUND_TURRET(reg_a5)->shot_countdown = (u8) reg_d0.b[0];
                            }
                        }
                    }
                }
            }
            enemy_variant_offset_a_get();
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            return;
        }
        reg_d0.w = 0x34;
        score_add();
        sfx_explosion_air_small();
        enemy_variant_word_get();
        reg_d0.w = 8;
        wreck_spawn();
        reg_d0.w = 8;
        enemy_variant_get();
        pickup_spawn_variant_here();
        reg_d0.w = 0xC;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        enemy_variant_timer_a_set();
        EXPLOSION(reg_a0)->debris = 1;
        EXPLOSION(reg_a0)->debris_arg = 0;
        EXPLOSION(reg_a0)->start_y = 0xFE00;
        EXPLOSION(reg_a0)->start_x = 0;
        EXPLOSION(reg_a0)->follows_scroll = 1;
        enemy_remove();
    }
}

void ground_turret_c_first(void) {
    enemy_set_entity_count(0);
}

extern u16 g_direction_sprites_f[];
extern u16 D_0025AC80[];
extern u16 D_0025AC90[];
extern u16 D_0025ACA0[];

void ground_turret_c_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)(D_0025ACA0);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_0025AC90);
    reg_d0.w = 5;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        direction_to_target_player();
        reg_a0 = (u8 *)(g_direction_sprites_f);
        GROUND_TURRET(reg_a5)->dir.b[0] = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.b[0] = 4;
        if ((s32) g_stage > 1) {
            reg_d0.b[0] = 4;
        }
        GROUND_TURRET(reg_a5)->shot_interval = (u8) reg_d0.b[0];
        reg_d0.h[0] = g_rank_4_16;
        reg_d0.h[0] -= 4;
        GROUND_TURRET(reg_a5)->shot_countdown -= reg_d0.b[0];
        reg_a0 = (u8 *)(D_0025AC80);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        GROUND_TURRET(reg_a5)->palette = *(s8 *)reg_a0;
        reg_a0 += 1;
        GROUND_TURRET(reg_a5)->hit_palette = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}

s32 enemy_variant_timer_b_set();

void ground_turret_c(void) {
    u8 *swp;

    enemy_path_step();
    if (enemy_move_end_requested != 0) goto block_rts;
    entity_check_bounds();
    switch (cond_flag) {
    case 0:
        goto next_1;
    }
    if (GROUND_TURRET(reg_a5)->seen == 0) goto next_2;
    enemy_remove();
    return;
next_1:
    GROUND_TURRET(reg_a5)->seen = 1;
next_2:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) goto next_3;
    reg_d0.b[0] = GROUND_TURRET(reg_a5)->palette;
    if ((s32) ENTITY(reg_a6)->hp.h >= 0xC0) goto next_5;
    if (g_damage_blink_counter != 0) goto next_5;
    reg_d0.w = 0x19;
    goto next_5;
next_3:
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    if (reg_d0.b[0] != 0x19) goto next_4;
    reg_d0.b[0] = GROUND_TURRET(reg_a5)->palette;
next_4:
    reg_d2.b[0] = GROUND_TURRET(reg_a5)->hit_palette;
    reg_d0.b[0] ^= reg_d2.b[0];
    if (ENTITY(reg_a6)->hp.sh < 0) goto next_20;
next_5:
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    if (ENTITY(reg_a6)->flags.sb[0] >= 0) goto next_6;
    enemy_variant_offset_a_get();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    return;
next_6:
    if (g_enemies_stopped != 0) goto next_21;
    if (g_bullets_blocked != 0) goto next_21;
    reg_tmp.b[0] = GROUND_TURRET(reg_a5)->turn_countdown;
    GROUND_TURRET(reg_a5)->turn_countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_21;
    GROUND_TURRET(reg_a5)->turn_countdown = GROUND_TURRET(reg_a5)->turn_interval;
    reg_a0 = (u8 *) ((u16 *)g_player1);
    reg_a1 = (u8 *) ((u16 *)g_player2);
    if (ENEMY_STATE(reg_a5)->target_player == 0) goto next_7;
    reg_atmp = (u8 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) reg_atmp;
next_7:
    if (*(s16 *)reg_a0 < 0) goto next_8;
    if (*(s16 *)reg_a1 >= 0) goto next_21;
    swp = reg_a0;
    reg_a0 = reg_a1;
    reg_atmp = (u8 *) swp;
    reg_a1 = swp;
next_8:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    reg_d0.h[0] = GROUND_TURRET(reg_a5)->dir.h;
    direction_turn_toward();
    GROUND_TURRET(reg_a5)->dir.h = reg_d1.h[0];
    reg_a3 = (u8 *) g_direction_sprites_f;
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a3 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a3 + ((s16) (reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
next_21:
    enemy_variant_offset_a_get();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    if (g_enemies_stopped != 0) goto block_rts;
    if (g_bullets_blocked != 0) goto block_rts;
    if (ENTITY(reg_a6)->y.sh < 0x1000) goto block_rts;
    reg_tmp.b[0] = GROUND_TURRET(reg_a5)->shot_countdown;
    GROUND_TURRET(reg_a5)->shot_countdown -= 1;
    switch (reg_tmp.b[0]) {
    case 0:
        goto next_9;
    }
    goto block_rts;
next_9:
    GROUND_TURRET(reg_a5)->shot_countdown = GROUND_TURRET(reg_a5)->shot_interval;
    enemy_fire_distance_check();
    if (cond_flag != 0) goto block_rts;
    if (g_stage != 3) goto next_10;
    if (g_scroll_line < 0x2E) goto block_rts;
next_10:
    reg_a4 = (u8 *) g_direction_offsets_500;
    reg_d1.h[0] = GROUND_TURRET(reg_a5)->dir.h;
    reg_d0.h[0] = reg_d1.h[0];
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a4 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = ((u16) reg_d0.h[0] + 2 != 0) ? *(u16 *)(reg_a4 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d1.h[0] += 2;
    reg_d1.h[0] &= 0x3C;
    reg_d4.w = (u32) reg_a6;
    reg_d0.w = 0xD;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    bullet_fire_fixed();
    reg_tmp.b[0] = GROUND_TURRET(reg_a5)->shots_left;
    GROUND_TURRET(reg_a5)->shots_left -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_12;
    GROUND_TURRET(reg_a5)->shots_left = GROUND_TURRET(reg_a5)->shots;
    reg_d0.h[0] = 0x40;
    reg_d0.h[0] -= g_rank_4_16;
    reg_d0.h[0] += 4;
    GROUND_TURRET(reg_a5)->shot_countdown = reg_d0.b[0];
next_12:
    return;
next_20:
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
    ENTITY(reg_a6)->flags.b[0] |= 0x80;
    if (reg_tmp.b[0] & 0x80) goto next_11;
    reg_d0.w = 8;
    score_add();
    reg_d0.h[0] = 0x84;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = ENTITY(reg_a6)->x.h;
    enemy_variant_timer_b_set();
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->start_y = 0xFE00;
    EXPLOSION(reg_a0)->start_x = 0xFE00;
    EXPLOSION(reg_a0)->follows_scroll = 1;
    ENTITY(reg_a6)->flags.b[1] &= 0xFD;
    reg_tmp.w = 0x1626;
    ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
    ENTITY(reg_a6)->hp.h = 0x300;
    goto next_21;
next_11:
    sfx_explosion_air_small();
    reg_d0.w = 8;
    score_add();
    enemy_variant_word_get();
    reg_d0.w = 8;
    wreck_spawn();
    reg_d0.w = 8;
    enemy_variant_get();
    pickup_spawn_variant_here();
    reg_d0.w = 0xC;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = ENTITY(reg_a6)->x.h;
    enemy_variant_timer_a_set();
    EXPLOSION(reg_a0)->debris = 1;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->start_y = 0xFC00;
    EXPLOSION(reg_a0)->start_x = 0xFE00;
    EXPLOSION(reg_a0)->follows_scroll = 1;
    enemy_remove();
block_rts:
    return;
}

void mid_flyer_e_hatch_fire(void) {
    s32 bullet_fire256_fast();
    u16 temp_a1;

    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    temp_a1 = ENTITY(reg_a6)->x.h;
    reg_d2.h[0] = temp_a1;
    reg_d3.w = reg_d7.w;
    reg_d0.w = 0x3000C;
    reg_d0.h[0] = 0xB;
    reg_d4.w = 0;
    bullet_fire256();
    reg_d0.h[1] += 3;
    reg_d5.b[0] = MID_FLYER_E(reg_a5)->hatch_shots_left;
    reg_d5.b[0] *= 2;
    reg_d1.b[0] += reg_d5.b[0];
    bullet_fire256_fast();
}

void mid_flyer_e_first(void) {
    enemy_set_entity_count(1);
}

extern s8 D_0025ACC0[];
extern s8 D_0025ACD0[];
extern s8 D_0025ACF0[];
extern u16 g_enemy_signal_7;
extern u16 g_enemy_signal_6;
extern u16 g_enemy_signal_5;
extern u16 g_enemy_signal_4;

void mid_flyer_e_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    s8 *temp_a1_2;

    (*(s8 **)&reg_a0) = (s8 *)D_0025ACF0;
    enemy_init_entities();
    (*(s8 **)&reg_a0) = (s8 *)D_0025ACD0;
    reg_d0.w = 0xC;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_d0.b[0] = 5;
        if ((s32) g_stage > 1) {
            reg_d0.b[0] = 2;
        }
        MID_FLYER_E(reg_a5)->hatch_shot_interval = (u8) reg_d0.b[0];
        reg_d0.h[0] = g_rank_2_16;
        MID_FLYER_E(reg_a5)->gun_pause -= reg_d0.b[0];
        if (g_stage == 1) {
            if (((s32) g_scroll_line >= 0x100) && ((s32) g_scroll_line < 0x16C)) {
                if (g_enemy_signal_0 != 0) {
                    enemy_remove();
                    return;
                }
                goto block_10;
            }
            if ((s32) g_scroll_line >= 0x80) {
                ENTITY(reg_a6)->hp.sh = 0x680;
            }
            goto block_10;
        }
block_10:
        (*(s8 **)&reg_a0) = (s8 *)D_0025ACC0;
        reg_d0.h[0] = g_stage_x2;
        (*(s8 **)&reg_a0) = &(*(s8 **)&reg_a0)[reg_d0.h[0]];
        ENTITY(reg_a6)->attr.sb.palette = (s8) *((s8 *)reg_a0);
        MID_FLYER_E(reg_a5)->palette = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
        MID_FLYER_E(reg_a5)->hit_palette = (s8) *((s8 *)reg_a0);
        temp_a1_2 = (s8 *)(((s8 *)reg_a0) + 1);
        (*(s8 **)&reg_a0) = temp_a1_2;
        if (g_stage == 4) {
            ENTITY(reg_a6)->hp.sh = 0x880;
            if ((s32) g_scroll_line < 0x230) {
                if (g_enemy_signal_4 != 0) {
                    enemy_remove();
                }
            } else if ((s32) g_scroll_line < 0x250) {
                if (g_enemy_signal_5 != 0) {
                    enemy_remove();
                }
            } else if ((s32) g_scroll_line < 0x290) {
                if (g_enemy_signal_6 != 0) {
                    enemy_remove();
                }
            } else if ((g_enemy_signal_7 != 0) && ((s32) g_scroll_line > 0x240)) {
                enemy_remove();
            }
        }
    }
}

extern u16 D_0025AD30[];
extern u16 D_0028C9F8;

void mid_flyer_e(void) {
    s16 *temp_v1_2;
    s16 *var_a1;
    u16 temp_a0_2;
    s32 temp_a0_4;
    s64 temp_v0_2;
    u16 temp_a0;
    u16 temp_a0_3;
    u16 temp_a0_5;
    u16 temp_a1;
    u16 temp_a1_2;
    u16 temp_a2;
    u16 var_a2;
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    u32 temp_s3;
    u8 temp_v0;
    u8 temp_v1;
    u8 var_v0;

    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7000;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1000;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] += 0x7000;
        reg_tmp.w += reg_tmp1.sw;
        if (reg_tmp.h[1] != 0) {
            if (MID_FLYER_E(reg_a5)->seen != 0) {
                enemy_remove();
                return;
            }
            goto block_5;
        }
        MID_FLYER_E(reg_a5)->seen = 1U;
block_5:
        ENTITY(reg_a6)[1].y.h = (u16) ENTITY(reg_a6)->y.h;
        ENTITY(reg_a6)[1].x.h = (u16) ENTITY(reg_a6)->x.h;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        reg_d1.b[0] |= ENTITY(reg_a6)[1].flags.b[1];
        reg_d1.h[0] &= 0x5C;
        var_a1 = (s16 *)(reg_a6 + 1);
        if (reg_d1.h[0] == 0) {
            reg_d0.b[0] = MID_FLYER_E(reg_a5)->palette;
            if (((s32) ENTITY(reg_a6)->hp.h < 0x260) && (g_damage_blink_counter == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_14;
        }
        reg_d0.h[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = MID_FLYER_E(reg_a5)->palette;
        }
        var_a1 = (s16 *)(reg_a6 + 0x18);
        reg_d2.b[0] = MID_FLYER_E(reg_a5)->hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        reg_d4.h[0] = ENTITY(reg_a6)->hp.h;
        temp_a0 = ENTITY(reg_a6)[1].hp.h;
        if ((s16)(temp_a0) < (s16) reg_d4.h[0]) {
            reg_d4.h[0] = temp_a0;
        }
        ENTITY(reg_a6)->hp.h = (u16) reg_d4.h[0];
        ENTITY(reg_a6)[1].hp.h = (u16) reg_d4.h[0];
        if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
block_14:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0)) {
                if (((g_loop != 0) || ((s32) g_stage >= 3)) && ((s16) ENTITY(reg_a6)->y.h >= 0x1000)) {
                    reg_tmp.b[0] = MID_FLYER_E(reg_a5)->gun_countdown;
                    MID_FLYER_E(reg_a5)->gun_countdown -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        MID_FLYER_E(reg_a5)->gun_countdown = (u8) MID_FLYER_E(reg_a5)->gun_interval;
                        reg_d1.w = 0x20;
                        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d4.w = 0;
                        if (!(ENTITY(reg_a6)->flags.b[0] & 0x40)) {
                            reg_d0.w = 0x20007;
                            reg_d3.w = 0xF200F940;
                            bullet_fire_fixed();
                            reg_d3.w = 0xF2000700;
                            bullet_fire_fixed();
                        } else {
                            reg_d0.w = 0x20007;
                            reg_d3.w = 0xF400FE00;
                            bullet_fire_fixed();
                            reg_d3.w = 0xF4000240;
                            bullet_fire_fixed();
                        }
                        reg_tmp.b[0] = MID_FLYER_E(reg_a5)->gun_shots_left;
                        MID_FLYER_E(reg_a5)->gun_shots_left -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            MID_FLYER_E(reg_a5)->gun_shots_left = (u8) MID_FLYER_E(reg_a5)->gun_shots;
                            temp_v1 = ENTITY(reg_a6)->flags.b[0];
                            if (temp_v1 & 0x40) {
                                ENTITY(reg_a6)->flags.b[0] = temp_v1 & 0xBF;
                            } else {
                                ENTITY(reg_a6)->flags.b[0] = temp_v1 | 0x40;
                            }
                            reg_d0.h[0] = 0x20;
                            reg_d0.h[0] -= g_rank_2_16;
                            MID_FLYER_E(reg_a5)->gun_countdown = (u8) reg_d0.b[0];
                            MID_FLYER_E(reg_a5)->gun_pause = (u8) reg_d0.b[0];
                        }
                    }
                }
                if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0) && ((s16) ENTITY(reg_a6)->y.h >= 0x1000) && (MID_FLYER_E(reg_a5)->seen != 0)) {
                    reg_d0.h[0] = MID_FLYER_E(reg_a5)->hatch_state;
                    temp_a0_2 = reg_d0.h[0] & 0xFFFF;
                    if (reg_d0.h[0] == 0) {
                        reg_tmp.b[0] = MID_FLYER_E(reg_a5)->hatch_wait;
                        MID_FLYER_E(reg_a5)->hatch_wait -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            reg_d0.h[0] = 0x10;
                            reg_d0.h[0] -= g_rank_1_16;
                            MID_FLYER_E(reg_a5)->hatch_wait = (u8) reg_d0.b[0];
                            MID_FLYER_E(reg_a5)->hatch_state = 1U;
                        }
                    } else if (temp_a0_2 == 1) {
                        reg_tmp.b[0] = MID_FLYER_E(reg_a5)->frame_countdown;
                        MID_FLYER_E(reg_a5)->frame_countdown -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            MID_FLYER_E(reg_a5)->frame_countdown = (u8) MID_FLYER_E(reg_a5)->frame_interval;
                            MID_FLYER_E(reg_a5)->hatch_frame += 4;
                            if (MID_FLYER_E(reg_a5)->hatch_frame == 0x1C) {
                                MID_FLYER_E(reg_a5)->hatch_state = 2U;
                            }
                            goto block_58;
                        }
                    } else if (temp_a0_2 == 2) {
                        reg_tmp.b[0] = MID_FLYER_E(reg_a5)->hatch_wait;
                        MID_FLYER_E(reg_a5)->hatch_wait -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            MID_FLYER_E(reg_a5)->hatch_wait = (u8) MID_FLYER_E(reg_a5)->hatch_shot_interval;
                            reg_a0 = (u8 *)(((u16 *)g_player1));
                            reg_a1 = (u8 *)(((u16 *)g_player2));
                            if (ENEMY_STATE(reg_a5)->target_player != 0) {
                                reg_atmp = (u8 *)(reg_a0);
                                reg_a0 = (u8 *)(reg_a1);
                                reg_a1 = (u8 *)(reg_atmp);
                            }
                            temp_v1_2 = (s16 *)(reg_a0);
                            if ((*(s16 *)((u8 *)(temp_v1_2) + (0))) >= 0) {
                                if (*(s16 *)reg_a1 < 0) {
                                    reg_a0 = (u8 *)(reg_a1);
                                    reg_atmp = (u8 *)(temp_v1_2);
                                    reg_a1 = (u8 *)(temp_v1_2);
                                    goto block_45;
                                }
                            } else {
block_45:
                                reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                                reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                                reg_d4.w = 0;
                                reg_d4.b[0] = MID_FLYER_E(reg_a5)->hatch_shots_left;
                                reg_a0 = (u8 *)(&D_0028C9F8);
                                reg_d4.h[0] += reg_d4.h[0];
                                reg_d7.h[0] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
                                temp_a1 = reg_d7.h[0];
                                temp_s1 = reg_d1.w;
                                temp_s2 = reg_d2.w;
                                temp_s3 = reg_d3.w;
                                reg_d0.h[0] += temp_a1;
                                *(u16 *)&reg_tmp7.h[0] = temp_a1;
                                reg_d7.h[1] = *(u16 *)&reg_tmp7.h[0];
                                reg_d7.h[0] = 0x700;
                                reg_d1.h[0] += reg_d7.h[0];
                                temp_s0 = reg_d0.w;
                                direction256_between();
                                mid_flyer_e_hatch_fire();
                                reg_d1.w = temp_s1;
                                reg_d7.h[0] = 0xF900;
                                reg_d0.w = temp_s0;
                                reg_d2.w = temp_s2;
                                reg_d3.w = temp_s3;
                                reg_d1.h[0] += reg_d7.h[0];
                                direction256_between();
                                mid_flyer_e_hatch_fire();
                            }
                            reg_tmp.b[0] = MID_FLYER_E(reg_a5)->hatch_shots_left;
                            MID_FLYER_E(reg_a5)->hatch_shots_left -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                MID_FLYER_E(reg_a5)->hatch_shots_left = (u8) MID_FLYER_E(reg_a5)->hatch_shots;
                                reg_d0.h[0] = 0x10;
                                reg_d0.h[0] -= g_rank_1_16;
                                MID_FLYER_E(reg_a5)->hatch_wait = (u8) reg_d0.b[0];
                                MID_FLYER_E(reg_a5)->hatch_state = 3U;
                            }
                        }
                    } else {
                        temp_v0 = MID_FLYER_E(reg_a5)->hatch_wait;
                        if (temp_v0 != 0) {
                            MID_FLYER_E(reg_a5)->hatch_wait = (u8) (temp_v0 - 1);
                        } else {
                            reg_tmp.b[0] = MID_FLYER_E(reg_a5)->frame_countdown;
                            MID_FLYER_E(reg_a5)->frame_countdown -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                MID_FLYER_E(reg_a5)->frame_countdown = (u8) MID_FLYER_E(reg_a5)->frame_interval;
                                MID_FLYER_E(reg_a5)->hatch_frame -= 4;
                                if (MID_FLYER_E(reg_a5)->hatch_frame == 0) {
                                    reg_d0.h[0] = 0x30;
                                    if (g_stage == 4) {
                                        reg_d0.h[0] += 0x10;
                                    }
                                    reg_d0.h[0] -= g_rank_3_16;
                                    MID_FLYER_E(reg_a5)->hatch_wait = (u8) reg_d0.b[0];
                                    MID_FLYER_E(reg_a5)->hatch_state = 0U;
                                }
block_58:
                                reg_d0.h[0] = MID_FLYER_E(reg_a5)->hatch_frame;
                                reg_a0 = (u8 *)(D_0025AD30);
                                MID_FLYER_E(reg_a5)->hatch_sprite[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                                MID_FLYER_E(reg_a5)->hatch_sprite[1] = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            }
                        }
                    }
                }
            }
            entity_draw_layer5();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            temp_a0_3 = reg_d1.h[0];
            reg_d1.h[1] += 0x7FFF + 0x7D01;
            reg_d1.h[0] = (u32)temp_a0_3 + 0x7FFF + 0x7701;
            reg_d2.h[1] = MID_FLYER_E(reg_a5)->hatch_sprite[0];
            reg_d2.h[0] = MID_FLYER_E(reg_a5)->hatch_sprite[1];
            reg_d3.h[0] = 0x648;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer5();
            if ((g_loop == 0) && (g_frame_mod2 != 0) && ((g_stage != 1) || ((s32) g_scroll_line < 0x16C))) {
                reg_d1.h[1] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d1.h[1] += 0x7FFF + 0x5801;
                reg_d2.w = 0x1887;
                reg_d3.h[0] = 0x830;
                reg_d4.h[0] = 0x18;
                reg_d1.h[0] += 0x200;
                sprite_draw_layer4();
            }
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            reg_a0 = (u8 *)(reg_a6 + 0x20);
            enemy_hitbox_debug_draw();
            return;
        }
        reg_d0.w = 0x55;
        score_add();
        sfx_explosion_ground_large();
        reg_d0.w = 0xD;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        var_a2 = ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->x = var_a2;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->debris = 1;
        EXPLOSION(reg_a0)->debris_arg = 0;
        EXPLOSION(reg_a0)->start_y = 0xF600;
        EXPLOSION(reg_a0)->start_x = 0;
        if ((g_stage != 1) || ((s32) g_scroll_line < 0x150)) {
            reg_d0.h[0] = ENTITY(reg_a6)->move.h;
            reg_d0.b[0] *= 4;
            temp_a0_5 = reg_d0.h[0];
            EXPLOSION(reg_a0)->move.h = temp_a0_5;
            reg_d0.h[0] = 0x84;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            var_a2 = ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->x = var_a2;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->debris = 1;
            EXPLOSION(reg_a0)->debris_arg = 0x400;
            EXPLOSION(reg_a0)->start_y = 0x400;
            EXPLOSION(reg_a0)->start_x = 0;
            reg_d0.h[0] = ENTITY(reg_a6)->move.h;
            reg_d0.h[0] += 0x800;
            reg_d0.b[0] *= 4;
            EXPLOSION(reg_a0)->move.h = (u16) reg_d0.h[0];
        }
        enemy_remove();
    }
}

void mid_tank_horizontal_b_first(void) {
    enemy_set_entity_count(0);
}

extern u16 g_direction_sprites_a[];
extern s8 D_0025AD50[];
extern s8 D_0025AD60[];
extern s8 D_0025AD90[];

void mid_tank_horizontal_b_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    u16 temp_a0;
    (*(s8 **)&reg_a0) = (s8 *)D_0025AD90;
    enemy_init_entities();
    reg_tmp.w = (u32) ((s8 *)reg_a0);
    MID_TANK_HB(reg_a5)->after_entities[0] = (u16) reg_tmp.h[1];
    MID_TANK_HB(reg_a5)->after_entities[1] = (u16) reg_tmp.h[0];
    (*(s8 **)&reg_a0) = (s8 *)D_0025AD60;
    reg_d0.w = 0x10;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if (ENTITY(reg_a6)->misc.b.user != 0) {
            ENTITY(reg_a6)->attr.b.flip |= 0x40;
            MID_TANK_HB(reg_a5)->turret_x = 0x280U;
        }
        reg_a2 = (u8 *)(g_direction_sprites_a);
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        temp_a0 = (u32)reg_d0.h[0] + 0x440;
        reg_d0.h[0] = temp_a0;
        reg_d1.h[0] += MID_TANK_HB(reg_a5)->turret_x;
        aim_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        MID_TANK_HB(reg_a5)->turret_dir.b[0] = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        MID_TANK_HB(reg_a5)->turret_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        MID_TANK_HB(reg_a5)->turret_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d1.b[0] = 3;
        if ((s32) g_stage > 1) {
            reg_d1.b[0] = 3;
        }
        MID_TANK_HB(reg_a5)->shot_interval = (u8) reg_d1.b[0];
        reg_d0.h[0] = g_rank_8_16;
        MID_TANK_HB(reg_a5)->shot_countdown -= reg_d0.b[0];
        (*(s8 **)&reg_a0) = (s8 *)D_0025AD50;
        reg_d0.h[0] = g_stage_x2;
        (*(s8 **)&reg_a0) = &(*(s8 **)&reg_a0)[reg_d0.h[0]];
        ENTITY(reg_a6)->attr.sb.palette = (s8) *((s8 *)reg_a0);
        MID_TANK_HB(reg_a5)->palette = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
        MID_TANK_HB(reg_a5)->hit_palette = (s8) *((s8 *)reg_a0);
        (*(s8 **)&reg_a0) += 1;
        if (!(ENTITY(reg_a6)->flags.b[1] & 0x20)) {
            MID_TANK_HB(reg_a5)->armed = 1;
            reg_d0.w = 0;
            MID_TANK_HB(reg_a5)->variant.b[0] = (u8) ENTITY(reg_a6)->misc.b.user;
            if (MID_TANK_HB(reg_a5)->variant.b[0] == 0) {
                (*(s8 **)&reg_a0) = (s8 *)(reg_a6 + 0x16);
            } else {
                (*(s8 **)&reg_a0) = (s8 *)(reg_a6 + 0x14);
            }
            *(u16 *)(*(s8 **)&reg_a0) = 0xF800;
        }
        ENTITY(reg_a6)->misc.b.user = 0U;
    }
}

s32 sfx_explosion_air_large();
extern u16 g_direction_offsets_540[];
extern u16 D_0025ADE0[];
extern u16 D_0025ADF0[];

void mid_tank_horizontal_b(void) {
    s32 enemy_variant_offset_c_get();
    s16 *t1;
    s16 *t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;
    u16 v1;
    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        if ((MID_TANK_HB(reg_a5)->armed != 0) && (ENTITY(reg_a6)->flags.b[1] & 0x20)) {
            reg_a0 = (u8 *)(reg_a6 + 0x16);
            if (MID_TANK_HB(reg_a5)->variant.h != 0) {
                reg_a0 = (u8 *)(reg_a6 + 0x14);
                reg_d3.h[0] *= 0xFFFF;
            }
            t6 = *(u16 *)reg_a0;
            if ((s16)(t6) < 0x800) {
                *(s16 *)reg_a0 = t6 + reg_d3.h[0];
            }
        }
        v1 = g_side_scroll_x[0];
        reg_d0.h[1] = ENTITY(reg_a6)->y.h;
        reg_d0.h[0] = ENTITY(reg_a6)->x.h;
        reg_tmp.w = 0;
        reg_tmp.h[0] = 0xA800;
        reg_tmp1.w = 0;
        t5 = (u32)reg_d0.h[0] + 0x1000;
        reg_d0.h[0] = t5;
        reg_d0.h[0] += v1;
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x7FFF + 0x2801;
        if (reg_tmp.h[1] != 0) {
            goto next_20;
        }
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7800;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] = reg_d0.h[1];
        reg_d0.h[1] = reg_tmp.h[0];
        reg_d0.h[0] += 0xC00;
        reg_tmp.w = 0;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] += 0x7800;
        reg_tmp.w += reg_tmp1.sw;
        if (reg_tmp.h[1] != 0) {
next_20:
            if (MID_TANK_HB(reg_a5)->seen != 0) {
                enemy_remove();
                return;
            }
            goto next_1;
        }
        MID_TANK_HB(reg_a5)->seen = 1U;
next_1:
        t1 = (s16 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(t1) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = MID_TANK_HB(reg_a5)->palette;
            if (((s32) (*(u16 *)((u8 *)(t1) + (0x18))) < 0x2C0) && (g_damage_blink_counter == 0)) {
                reg_d0.w = 0x19;
            }
            goto next_2;
        }
        (*(u8 *)((u8 *)(t1) + (1))) &= 0xA3;
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = MID_TANK_HB(reg_a5)->palette;
        }
        reg_d2.b[0] = MID_TANK_HB(reg_a5)->hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
next_2:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            enemy_anims_spawn_listed();
            if ((g_enemies_stopped == 0) && ((s32) ENTITY(reg_a6)->move.b.dir < 0x40)) {
                reg_tmp.b[0] = MID_TANK_HB(reg_a5)->track_countdown;
                MID_TANK_HB(reg_a5)->track_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    MID_TANK_HB(reg_a5)->track_countdown = (u8) ENTITY(reg_a6)[1].hit_x_plus.b[0];
                    if (ENTITY(reg_a6)->move.b.dir == 0x10) {
                        MID_TANK_HB(reg_a5)->track_frame += 4;
                        if (MID_TANK_HB(reg_a5)->track_frame == 0x10) {
                            MID_TANK_HB(reg_a5)->track_frame = 0U;
                        }
                    } else {
                        reg_tmp.h[0] = MID_TANK_HB(reg_a5)->track_frame;
                        MID_TANK_HB(reg_a5)->track_frame -= 4;
                        if ((s32) reg_tmp.b[0] < 4) {
                            MID_TANK_HB(reg_a5)->track_frame = 0xCU;
                        }
                    }
                    reg_d0.h[0] = MID_TANK_HB(reg_a5)->track_frame;
                    reg_a0 = (u8 *)(D_0025ADE0);
                    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                }
            }
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0)) {
                reg_tmp.b[0] = MID_TANK_HB(reg_a5)->turn_countdown;
                MID_TANK_HB(reg_a5)->turn_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    MID_TANK_HB(reg_a5)->turn_countdown = (u8) MID_TANK_HB(reg_a5)->turn_interval;
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
                        reg_d0.h[0] += 0x440;
                        reg_d1.h[0] += MID_TANK_HB(reg_a5)->turret_x;
                        direction_between();
                        reg_d0.h[0] = MID_TANK_HB(reg_a5)->turret_dir.h;
                        direction_turn_toward();
                        MID_TANK_HB(reg_a5)->turret_dir.h = (u16) reg_d1.h[0];
                        reg_d1.h[0] &= 0x3E;
                        reg_d1.h[0] += reg_d1.h[0];
                        MID_TANK_HB(reg_a5)->turret_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                        MID_TANK_HB(reg_a5)->turret_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                    }
                }
            }
            enemy_variant_offset_a_get();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] += MID_TANK_HB(reg_a5)->turret_x;
            reg_d1.h[1] += 0x7FFF + 0x7E41;
            reg_d1.h[0] += 0x7FFF + 0x7C01;
            reg_d2.h[1] = MID_TANK_HB(reg_a5)->turret_sprite[0];
            reg_d2.h[0] = MID_TANK_HB(reg_a5)->turret_sprite[1];
            reg_d3.h[0] = 0x620;
            reg_d4.w = 0;
            reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
            enemy_variant_offset_c_get();
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            if (g_enemies_stopped != 0) {
                goto block_rts;
            }
            if (g_bullets_blocked != 0) {
                goto block_rts;
            }
            if ((s16) ENTITY(reg_a6)->y.h < 0x1000) {
                goto block_rts;
            }
            reg_tmp.b[0] = MID_TANK_HB(reg_a5)->shot_countdown;
            MID_TANK_HB(reg_a5)->shot_countdown -= 1;
            switch (reg_tmp.b[0]) {
            case 0:
                break;
            default:
                return;
            }
            reg_d0.h[0] = 3;
            reg_d1.h[0] = g_rank_1_16;
            reg_d1.h[0] >>= 3;
            reg_d0.h[0] -= reg_d1.h[0];
            MID_TANK_HB(reg_a5)->shot_countdown = (u8) reg_d0.b[0];
            reg_a4 = (u8 *)(g_direction_offsets_540);
            reg_d1.h[0] = MID_TANK_HB(reg_a5)->turret_dir.h;
            reg_d0.h[0] = reg_d1.h[0];
            reg_d0.h[0] &= 0x3E;
            reg_d0.h[0] += reg_d0.h[0];
            reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
            reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a4;
            reg_d3.h[0] += MID_TANK_HB(reg_a5)->turret_x;
            reg_d3.h[1] += 0x440;
            reg_d4.w = (u32) reg_a6;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            t4 = ENTITY(reg_a6)->x.h;
            reg_d2.h[0] = t4;
            reg_d0.w = 0x2000C;
            if (MID_TANK_HB(reg_a5)->shots_left & 1) {
                reg_d1.h[0] -= 2;
                bullet_fire_double();
                reg_d1.h[0] += 4;
                bullet_fire_double();
            } else {
                bullet_fire_double();
            }
            reg_tmp.b[0] = MID_TANK_HB(reg_a5)->shots_left;
            MID_TANK_HB(reg_a5)->shots_left -= 1;
            if ((s32) reg_tmp.b[0] > 0) {
                goto block_rts;
            }
            MID_TANK_HB(reg_a5)->shots_left = (u8) MID_TANK_HB(reg_a5)->shots;
            reg_d0.h[0] = 0xA;
            reg_d0.h[0] -= g_rank_1_16;
            reg_d0.h[0] += 8;
            MID_TANK_HB(reg_a5)->shot_countdown = (u8) reg_d0.b[0];
            reg_tmp.b[0] = MID_TANK_HB(reg_a5)->pause_countdown;
            MID_TANK_HB(reg_a5)->pause_countdown -= 1;
            if ((s32) reg_tmp.b[0] > 0) {
                goto block_rts;
            }
            MID_TANK_HB(reg_a5)->pause_countdown = (u8) MID_TANK_HB(reg_a5)->pause;
            reg_d0.h[0] = 0x70;
            reg_d0.h[0] -= g_rank_4_16;
            MID_TANK_HB(reg_a5)->shot_countdown = (u8) reg_d0.b[0];
block_rts:
            return;
        } else {
            sfx_explosion_air_large();
            reg_d0.w = 0x88;
            score_add();
            enemy_variant_word_get();
            reg_d2.w = 0xFE000000;
            reg_d0.w = 0xC;
            wreck_spawn_a();
            reg_d0.w = 8;
            reg_a4 = (u8 *)(D_0025ADF0);
            reg_d6.w = 4;
            do {
                reg_d1.h[1] = *(u16 *)reg_a4;
                reg_a4 += 2;
                reg_d1.h[0] = *(u16 *)reg_a4;
                reg_a4 += 2;
                pickup_spawn_plain();
            } while ((s16)(--reg_d6.h[0]) >= 0);
            reg_d0.w = 0xD;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            enemy_variant_timer_a_set();
            if (g_stage == 1) {
                EXPLOSION(reg_a0)->draw_layer = 8;
            }
            EXPLOSION(reg_a0)->debris = 1;
            EXPLOSION(reg_a0)->debris_arg = 0x400;
            EXPLOSION(reg_a0)->start_y = 0xFC00;
            EXPLOSION(reg_a0)->start_x = 0;
            EXPLOSION(reg_a0)->follows_scroll = 1;
            reg_d0.w = 8;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            enemy_variant_timer_a_set();
            if (g_stage == 1) {
                EXPLOSION(reg_a0)->draw_layer = 8;
            }
            EXPLOSION(reg_a0)->debris = 1;
            EXPLOSION(reg_a0)->debris_arg = 0;
            EXPLOSION(reg_a0)->start_y = 0xF600;
            EXPLOSION(reg_a0)->start_x = 0;
            EXPLOSION(reg_a0)->follows_scroll = 1;
            enemy_remove();
        }
    }
}
