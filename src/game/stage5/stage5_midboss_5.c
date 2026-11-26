#include "common.h"
#include "player.h"
#include "entity.h"
#include "explosion.h"
#include "enemy.h"
#include "enemy_kinds.h"
#include "stage5_midboss.h"

typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 arrived;
    /* 0x17 */ u8 leaving;
    /* 0x18 */ u16 next_drones;        /* 0: the drones, 1: the spin drones; in turn */
    /* 0x1A */ u16 hp[2];              /* high word first */
    /* 0x1E */ u16 slide;              /* how far its second part is out, up to 0x600 */
    /* 0x20 */ u16 launchers_off;
} Stage5Midboss5State;

/* Entities 1 to 3 of mid-boss 5 are not drawn. They hold the values of its movement and of its missile launchers. */
typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u16 mode;               /* 0: arriving, 1: between two points, 2: the drones, 3: after them,
                                          4: the spin drones, 5: after them, 6: dying, 7: away */
    /* 0x08 */ u16 step;
    /* 0x0A */ union {
        u16 point;                                         /* mode 1: offset of the point in the table */
        struct { u8 direction_b; u8 direction_a; } drones; /* mode 2 */
        struct { u8 rounds_left; u8 step; } spin;          /* mode 4 */
    };
    /* 0x0C */ u8 unused_0C[4];
    /* 0x10 */ u16 frames_left;
    /* 0x12 */ u16 unused_12;
    /* 0x14 */ union {
        EnemyTimer slow_timer;                             /* mode 0 */
        struct { u8 unused_14; u8 count; } launch;         /* modes 2 and 4 */
    };
    /* 0x16 */ u8 unused_16[0xA];
} Stage5Midboss5Move;

typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u16 on;
    /* 0x08 */ u16 left_recoil;
    /* 0x0A */ u16 right_recoil;
    /* 0x0C */ u16 fired;
    /* 0x0E */ u8 unused_0E[0x12];
} Stage5Midboss5SmallLaunchers;

typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u16 on;
    /* 0x08 */ u16 left_recoil;
    /* 0x0A */ u16 right_recoil;
    /* 0x0C */ u16 fired;              /* 1: the left one, 2: the right one */
    /* 0x0E */ EnemyTimer shot_timer;
    /* 0x10 */ u8 unused_10[0x10];
} Stage5Midboss5LargeLaunchers;

/* A missile of either size: it flies for a number of frames and then asks for its blasts. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct { u16 y; u16 x; } at_start;
        struct { u16 unused_16; u16 frames_left; } now;
    };
    /* 0x1A */ u16 blast_shift_x;      /* small missile: where its second blast starts */
} Stage5Midboss5MissileState;

typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct { u16 y; u16 x; } at_start;
        struct { u8 speeding_up; u8 seen; u16 frame; } now;
    };
    /* 0x1A */ EnemyTimer frame_timer;
} Stage5Midboss5BlastState;

typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct { u16 y; u16 x; u8 unused_1A; u8 direction; } at_start;
        struct {
            u8 animated;
            u8 unused_17;
            u8 mode;                   /* 8: flying, 1 and 2: its two animations, 4: turning to the player,
                                          0x10: stepping, 0x20: turning to a new direction, 0x40: waiting */
            u8 unused_19;
            u16 frame;
        } now;
    };
    /* 0x1C */ u16 life;
    /* 0x1E */ u16 rounds_left;
    /* 0x20 */ u8 unused_20;
    /* 0x21 */ u8 other_21;
    /* 0x22 */ u16 steps_left;
    /* 0x24 */ u8 unused_24;
    /* 0x25 */ u8 wait;
    /* 0x26 */ u8 unused_26;
    /* 0x27 */ u8 new_direction;
} Stage5Midboss5DroneState;

typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct { u16 y; u16 x; u8 unused_1A; u8 direction; } at_start;
        struct { u16 unused_16; u16 unused_18; u16 frame; } now;
    };
    /* 0x1C */ u8 unused_1C;
    /* 0x1D */ u8 shot_direction;
    /* 0x1E */ u16 speed_y;
    /* 0x20 */ u16 speed_x;
    /* 0x22 */ EnemyTimer shot_timer;
    /* 0x24 */ u16 shots_left;
} Stage5Midboss5SpinDroneState;

#define STAGE5_MIDBOSS5(pointer) ((Stage5Midboss5State *)(pointer))
#define STAGE5_MIDBOSS5_MOVE(pointer) (&((Stage5Midboss5Move *)(pointer))[1])
#define STAGE5_MIDBOSS5_SMALL_LAUNCHERS(pointer) (&((Stage5Midboss5SmallLaunchers *)(pointer))[2])
#define STAGE5_MIDBOSS5_LARGE_LAUNCHERS(pointer) (&((Stage5Midboss5LargeLaunchers *)(pointer))[3])
#define STAGE5_MIDBOSS5_MISSILE(pointer) ((Stage5Midboss5MissileState *)(pointer))
#define STAGE5_MIDBOSS5_BLAST(pointer) ((Stage5Midboss5BlastState *)(pointer))
#define STAGE5_MIDBOSS5_DRONE(pointer) ((Stage5Midboss5DroneState *)(pointer))
#define STAGE5_MIDBOSS5_SPIN_DRONE(pointer) ((Stage5Midboss5SpinDroneState *)(pointer))

void stage5_midboss5_draw_body(void);
void stage5_midboss5_draw_part(void);
void stage5_midboss5_draw_left_small_launcher(void);
void stage5_midboss5_draw_right_small_launcher(void);
void stage5_midboss5_draw_left_large_launcher(void);
void stage5_midboss5_draw_right_large_launcher(void);
void stage5_midboss5_set_move(void);
void stage5_midboss5_move(void);
void stage5_midboss5_move_arrive(void);
void stage5_midboss5_move_between_points(void);
void stage5_midboss5_small_launchers_stop(void);
void stage5_midboss5_small_launchers_start(void);
void stage5_midboss5_small_launchers(void);
void stage5_midboss5_large_launchers_stop(void);
void stage5_midboss5_large_launchers_start(void);
void stage5_midboss5_large_launchers(void);
void stage5_midboss5_move_launch_drones(void);
void stage5_midboss5_move_launch_spin_drones(void);
void stage5_midboss5_move_dying(void);
void stage5_midboss5_move_away(void);
void stage5_midboss5_move_toward(void);
void stage5_midboss5_dying(void);
void stage5_midboss5_missile_explode(void);
void stage5_midboss5_drone_draw_flying(void);
void stage5_midboss5_drone_draw_animated(void);

s32 bullet_fire_fixed();
extern u16 g_direction64_offsets_432[];
extern u16 g_loop;

void stage5_midboss4_wave_beam_fire(void) {
    u16 temp_a0;
    u16 var_v0_11;
    u16 var_v0_13;
    u16 var_v0_15;
    u16 var_v0_17;
    u16 var_v0_19;
    u16 var_v0_21;
    u16 var_v0_23;
    u16 var_v0_3;
    u16 var_v0_5;
    u16 var_v0_7;
    u16 var_v0_9;
    u32 temp_s0;
    u32 temp_s0_10;
    u32 temp_s0_11;
    u32 temp_s0_2;
    u32 temp_s0_3;
    u32 temp_s0_4;
    u32 temp_s0_5;
    u32 temp_s0_6;
    u32 temp_s0_7;
    u32 temp_s0_8;
    u32 temp_s0_9;

    reg_tmp.h[1] = STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->owner[0];
    reg_tmp.h[0] = STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->owner[1];
    reg_a4 = (u8 *)reg_tmp.w;
    if (STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->left != 0) {
        reg_d6.b[0] = 0xFD;
        reg_d1.b[0] = 0x1B;
        reg_d7.w = 0;
        if (g_loop != 0) {
            reg_d7.b[0] = 1;
            reg_d1.b[0] = 0x1E;
        }
    } else {
        reg_d6.b[0] = 3;
        reg_d1.b[0] = 0x25;
        reg_d7.w = 0;
        if (g_loop != 0) {
            reg_d7.b[0] = 0xFF;
            reg_d1.b[0] = 0x22;
        }
    }
    reg_d2.h[1] = (*(u16 *)((u8 *)((u32)reg_a4) + (2)));
    temp_a0 = (*(u16 *)((u8 *)((u32)reg_a4) + (4)));
    reg_d2.h[0] = temp_a0;
    reg_a0 = (u8 *)(g_direction64_offsets_432);
    reg_d4.w = 0;
    reg_d3.w = 0;
    if (g_loop != 0) {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] *= 4;
        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        var_v0_3 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        temp_s0 = reg_d1.w;
        reg_d3.h[0] = var_v0_3;
        reg_d0.w = 0x4000B;
        bullet_fire_fixed();
        reg_d0.w -= 0x40000;
        reg_d1.b[0] += reg_d7.b[0];
        bullet_fire_fixed();
        reg_d1.w = temp_s0;
        reg_d1.b[0] += reg_d6.b[0];
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_5 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_2 = reg_d1.w;
    reg_d3.h[0] = var_v0_5;
    reg_d0.w = 0x8000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_2;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_7 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_3 = reg_d1.w;
    reg_d3.h[0] = var_v0_7;
    reg_d0.w = 0xC000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_3;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_9 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_4 = reg_d1.w;
    reg_d3.h[0] = var_v0_9;
    reg_d0.w = 0x10000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_4;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_11 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_5 = reg_d1.w;
    reg_d3.h[0] = var_v0_11;
    reg_d0.w = 0x14000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_5;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_13 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_6 = reg_d1.w;
    reg_d3.h[0] = var_v0_13;
    reg_d0.w = 0x14000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_6;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_15 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_7 = reg_d1.w;
    reg_d3.h[0] = var_v0_15;
    reg_d0.w = 0x14000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_7;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_17 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_8 = reg_d1.w;
    reg_d3.h[0] = var_v0_17;
    reg_d0.w = 0x14000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_8;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_19 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_9 = reg_d1.w;
    reg_d3.h[0] = var_v0_19;
    reg_d0.w = 0x14000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_9;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_21 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_10 = reg_d1.w;
    reg_d3.h[0] = var_v0_21;
    reg_d0.w = 0x14000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_10;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_23 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_11 = reg_d1.w;
    reg_d3.h[0] = var_v0_23;
    reg_d0.w = 0x14000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_11;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d0.w = 0x14000B;
    bullet_fire_fixed();
}

void stage5_midboss5_move_after_drones();
void stage5_midboss5_move_after_spin_drones();

void stage5_midboss5_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(4);
}

s32 enemy_set_task_state();
s32 enemy_init_entities();
s32 sprite_palette_load();
extern u8 D_00260470[];
extern u8 D_002604B0[];
extern u8 D_002604F0[];
extern u8 D_002661C8[];
extern u8 D_002661E0[];
extern s16 g_enemy_signal_4_as_s16;
extern s16 g_enemy_signal_3_as_s16;
extern s16 D_00299768[];
extern u16 g_side_scroll_x[];

void stage5_midboss5_start(void) {
    reg_a0 = (u8 *)D_002661E0;
    enemy_init_entities();
    reg_a0 = (u8 *)D_002661C8;
    reg_d0.h[0] = 5;
    enemy_set_task_state();
    reg_tmp.w = 0xF4001C00;
    ENTITY(reg_a6)->y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = reg_tmp.h[0];
    reg_d0.h[0] = g_side_scroll_x[0];
    ENTITY(reg_a6)->x.h -= reg_d0.h[0];
    D_00299768[0] = 1;
    g_enemy_signal_3_as_s16 = 1;
    g_enemy_signal_4_as_s16 = 1;
    reg_d0.h[0] = 0x12;
    reg_a0 = (u8 *)D_00260470;
    sprite_palette_load();
    reg_d0.h[0] = 0x13;
    reg_a0 = (u8 *)D_002604B0;
    sprite_palette_load();
    reg_d0.h[0] = 0x14;
    reg_a0 = (u8 *)D_002604F0;
    sprite_palette_load();
}

s32 ground_speeds_request();
s32 fade_out_and_release();
s32 enemy_hitbox_debug_draw();
s32 score_add_no_chain();
s32 score_add();
extern u8 D_00266330[];
extern u16 g_enemy_signal_4;
extern u16 g_enemy_signal_3;
extern u16 g_enemies_stopped;
extern u16 g_scroll_line;

void stage5_midboss5_main() {
    s32 enemy_remove();
    if (g_enemies_stopped == 0) {
        if (STAGE5_MIDBOSS5_DAMAGE(reg_a6)->gone != 0) {
            g_enemy_signal_3 = 0;
            reg_d0.h[0] = 0x20;
            reg_d1.h[0] = 0x20;
            ground_speeds_request();
            enemy_remove();
            return;
        }
        if ((STAGE5_MIDBOSS5(reg_a5)->leaving == 0) && (STAGE5_MIDBOSS5_DAMAGE(reg_a6)->dying == 0) && (g_scroll_line == 0x1F0)) {
            STAGE5_MIDBOSS5(reg_a5)->leaving = 1U;
            STAGE5_MIDBOSS5(reg_a5)->launchers_off = 1U;
            reg_d0.w = 7;
            stage5_midboss5_set_move();
        }
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
            STAGE5_MIDBOSS5_DAMAGE(reg_a6)->hit_by = (u16) reg_d1.h[0];
            score_add_no_chain();
            reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
            reg_d0.b[0] ^= 0xD;
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            reg_d0.w = 0x7FFF;
            reg_d0.h[0] -= ENTITY(reg_a6)->hp.h;
            if (STAGE5_MIDBOSS5(reg_a5)->leaving == 0) {
                reg_tmp.h[1] = STAGE5_MIDBOSS5(reg_a5)->hp[0];
                reg_tmp.h[0] = STAGE5_MIDBOSS5(reg_a5)->hp[1];
                reg_tmp.w -= reg_d0.w;
                STAGE5_MIDBOSS5(reg_a5)->hp[0] = (u16) reg_tmp.h[1];
                STAGE5_MIDBOSS5(reg_a5)->hp[1] = (u16) reg_tmp.h[0];
            }
            ENTITY(reg_a6)->hp.h = 0x7FFFU;
            reg_tmp.h[1] = STAGE5_MIDBOSS5(reg_a5)->hp[0];
            reg_tmp.h[0] = STAGE5_MIDBOSS5(reg_a5)->hp[1];
            if ((s32) reg_tmp.w < 0) {
                reg_d0.w = 0x1000;
                score_add();
                ENTITY(reg_a6)->flags.h = 0x8000;
                STAGE5_MIDBOSS5_DAMAGE(reg_a6)->dying = 1U;
                reg_d0.h[0] = 0x20;
                reg_d1.h[0] = 0x20;
                g_enemy_signal_3 = 0;
                g_enemy_signal_4 = 0;
                ground_speeds_request();
                reg_d0.w = 6;
                stage5_midboss5_set_move();
                reg_a0 = D_00266330;
                fade_out_and_release();
                goto normal_palette;
            }
        } else {
normal_palette:
            ENTITY(reg_a6)->attr.b.palette = 0x12U;
        }
        stage5_midboss5_dying();
        if (STAGE5_MIDBOSS5_DAMAGE(reg_a6)->dying == 0) {
            stage5_midboss5_move();
            if (STAGE5_MIDBOSS5(reg_a5)->launchers_off == 0) {
                stage5_midboss5_small_launchers();
                stage5_midboss5_large_launchers();
            }
        }
        goto draw;
    }
draw:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    stage5_midboss5_draw_left_large_launcher();
    stage5_midboss5_draw_right_large_launcher();
    stage5_midboss5_draw_left_small_launcher();
    stage5_midboss5_draw_right_small_launcher();
    stage5_midboss5_draw_body();
}


void stage5_midboss5_draw_body(void) {
    reg_d2.w = 0x1E92;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xF7000000;
    reg_d1.w += 0xF600F900;
    reg_d3.h[0] = 0xA38;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    stage5_midboss5_draw_part();
    reg_d2.w = 0x1E91;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[1] += STAGE5_MIDBOSS5(reg_a5)->slide;
    reg_d1.w += 0x0C800000;
    reg_d1.w += 0xF200EF00;
    reg_d3.h[0] = 0xE88;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    stage5_midboss5_draw_part();
    reg_d2.w = 0x1E90;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xF200E600;
    reg_d3.h[0] = 0xED0;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    stage5_midboss5_draw_part();
}

s32 sprite_draw_layer1();                            /* extern */
s32 sprite_draw_layer4();                            /* extern */

void stage5_midboss5_draw_part(void) {
    if (STAGE5_MIDBOSS5(reg_a5)->arrived == 0) {
        sprite_draw_layer1();
        return;
    }
    sprite_draw_layer4();
}


void stage5_midboss5_draw_left_small_launcher(void) {
    u8 *object = reg_a6;

    reg_d2.w = 0x1E94;
    reg_d1.h[1] = ENTITY(object)->y.h;
    reg_d1.h[0] = ENTITY(object)->x.h;
    reg_d1.w += 0xFC3FEC80U;
    reg_d1.h[0] += STAGE5_MIDBOSS5_SMALL_LAUNCHERS(object)->left_recoil;
    reg_d1.w += 0xFA00FF00U;
    reg_d3.h[0] = 0x608;
    reg_d4.w = 0;
    *(u8 *)&reg_d4 = ENTITY(object)[2].attr.b.palette;
    stage5_midboss5_draw_part();
}

void stage5_midboss5_draw_right_small_launcher(void) {
    u8 *object = reg_a6;

    reg_d2.w = 0x1E94;
    reg_d1.h[1] = ENTITY(object)->y.h;
    reg_d1.h[0] = ENTITY(object)->x.h;
    reg_d1.w += 0xFC401380U;
    reg_d1.h[0] -= STAGE5_MIDBOSS5_SMALL_LAUNCHERS(object)->right_recoil;
    reg_d1.w += 0xFA00FF00U;
    reg_d3.h[0] = 0x0608;
    reg_d4.w = 0;
    *(u8 *)&reg_d4 = ENTITY(object)[2].attr.b.palette;
    stage5_midboss5_draw_part();
}


void stage5_midboss5_draw_left_large_launcher(void)
{
    u8 *object;

    reg_d2.w = 0x1E93;
    object = (void *)reg_a6;
    reg_d1.h[1] = ENTITY(object)->y.h;
    reg_d1.h[0] = ENTITY(object)->x.h;
    reg_d1.h[1] += STAGE5_MIDBOSS5_LARGE_LAUNCHERS(object)->left_recoil;
    reg_d1.w += 0xF47FFC00u;
    reg_d4.w = 0;
    reg_d1.w += 0xF600FE00u;
    reg_d3.h[0] = 0xA10;
    *(u8 *)&reg_d4 = ENTITY(object)[3].attr.b.palette;
    stage5_midboss5_draw_part();
}

void stage5_midboss5_draw_right_large_launcher(void) {
    u8 *object = reg_a6;

    reg_d2.w = 0x1E93;
    reg_d1.h[1] = ENTITY(object)->y.h;
    reg_d1.h[0] = ENTITY(object)->x.h;
    reg_d1.h[1] += STAGE5_MIDBOSS5_LARGE_LAUNCHERS(object)->right_recoil;
    reg_d1.w += 0xF4800400U;
    reg_d1.w += 0xF600FE00U;
    reg_d3.h[0] = 0x0A10;
    reg_d4.w = 0;
    *(u8 *)&reg_d4 = ENTITY(object)[3].attr.b.palette;
    stage5_midboss5_draw_part();
}

void stage5_midboss5_set_move(void) {
    if (STAGE5_MIDBOSS5_MOVE(reg_a6)->mode != reg_d0.h[0]) {
        STAGE5_MIDBOSS5_MOVE(reg_a6)->mode = (u16) reg_d0.h[0];
        STAGE5_MIDBOSS5_MOVE(reg_a6)->step = 0;
    }
}

s32 entity_velocity();

void stage5_midboss5_move(void) {
    reg_d0.h[0] = STAGE5_MIDBOSS5_MOVE(reg_a6)->mode;
    switch (reg_d0.h[0]) {
    case 0:
        stage5_midboss5_move_arrive();
        break;
    case 1:
        stage5_midboss5_move_between_points();
        break;
    case 2:
        stage5_midboss5_move_launch_drones();
        break;
    case 3:
        stage5_midboss5_move_after_drones();
        break;
    case 4:
        stage5_midboss5_move_launch_spin_drones();
        break;
    case 5:
        stage5_midboss5_move_after_spin_drones();
        break;
    case 6:
        stage5_midboss5_move_dying();
        break;
    case 7:
        stage5_midboss5_move_away();
        break;
    }
    entity_velocity();
}

void stage5_midboss5_move_arrive(void) {
    if (STAGE5_MIDBOSS5_MOVE(reg_a6)->step == 0) {
        ENTITY(reg_a6)->move.sh = 0x1600;
        STAGE5_MIDBOSS5_MOVE(reg_a6)->slow_timer.both = 0x202;
        STAGE5_MIDBOSS5_MOVE(reg_a6)->step = 1U;
    }
    if ((STAGE5_MIDBOSS5_MOVE(reg_a6)->step == 1) && (ENTITY(reg_a6)->y.sh >= 0x2000)) {
        STAGE5_MIDBOSS5_MOVE(reg_a6)->step = 2U;
    }
    if (STAGE5_MIDBOSS5_MOVE(reg_a6)->step == 2) {
        reg_tmp.b[0] = STAGE5_MIDBOSS5_MOVE(reg_a6)->slow_timer.b.countdown;
        STAGE5_MIDBOSS5_MOVE(reg_a6)->slow_timer.b.countdown -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            STAGE5_MIDBOSS5_MOVE(reg_a6)->slow_timer.b.countdown = STAGE5_MIDBOSS5_MOVE(reg_a6)->slow_timer.b.interval;
            ENTITY(reg_a6)->move.b.speed -= 1;
            if (ENTITY(reg_a6)->move.b.speed == 0) {
                STAGE5_MIDBOSS5(reg_a5)->arrived = 1;
                ENTITY(reg_a6)->flags.h = 0xA001;
                reg_d0.w = 1;
                stage5_midboss5_set_move();
            }
        }
    }
}

extern u8 D_0028DA58[8];

void stage5_midboss5_move_between_points() {
    if (STAGE5_MIDBOSS5_MOVE(reg_a6)->step == 0) {
        STAGE5_MIDBOSS5_MOVE(reg_a6)->step = 1U;
        ENTITY(reg_a6)->move.sb.speed = 4;
        STAGE5_MIDBOSS5_MOVE(reg_a6)->point = 0U;
        STAGE5_MIDBOSS5_MOVE(reg_a6)->frames_left = 0x12CU;
        stage5_midboss5_small_launchers_start();
        stage5_midboss5_large_launchers_start();
    }
    reg_a0 = D_0028DA58;
    reg_a0 += STAGE5_MIDBOSS5_MOVE(reg_a6)->point;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    stage5_midboss5_move_toward();
    if (cond_flag == 0) {
        STAGE5_MIDBOSS5_MOVE(reg_a6)->point += 4;
        STAGE5_MIDBOSS5_MOVE(reg_a6)->point &= 7;
    }
    STAGE5_MIDBOSS5_MOVE(reg_a6)->frames_left -= 1;
    if (STAGE5_MIDBOSS5_MOVE(reg_a6)->frames_left == 0) {
        reg_d0.w = 2;
        if (STAGE5_MIDBOSS5(reg_a5)->next_drones != 0) {
            reg_d0.w = 4;
        }
        stage5_midboss5_set_move();
        STAGE5_MIDBOSS5(reg_a5)->next_drones += 1;
        STAGE5_MIDBOSS5(reg_a5)->next_drones &= 1;
        stage5_midboss5_small_launchers_stop();
        stage5_midboss5_large_launchers_stop();
    }
}

void stage5_midboss5_small_launchers_stop(void) {
    STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->on = 0;
}

void stage5_midboss5_small_launchers_start(void) {
    STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->on = 1;
    STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->fired = 0;
}

s32 spawn_request_add();
extern u16 g_game_frame;

void stage5_midboss5_small_launchers(void) {
    u16 temp_v1;
    u16 temp_v1_2;

    if (STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->on != 0) {
        if (STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->fired == 1) {
            STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->left_recoil = 0xA00U;
            STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->right_recoil = 0xA00U;
            STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->fired = 0U;
        }
        if (STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->fired == 0) {
            reg_d0.h[0] = STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->left_recoil;
            reg_d0.h[0] += STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->right_recoil;
            if (reg_d0.h[0] == 0) {
                reg_d0.w = 0;
                reg_d0.h[0] &= g_game_frame;
                if (reg_d0.h[0] == 0) {
                    STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->fired = 1U;
                    reg_d0.w = ENEMY_STAGE5_MIDBOSS5_SMALL_MISSILE;
                    spawn_request_add();
                    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d0.w += 0xFC3FEC80;
                    STAGE5_MIDBOSS5_MISSILE(reg_a0)->at_start.y = (u16) reg_d0.h[1];
                    STAGE5_MIDBOSS5_MISSILE(reg_a0)->at_start.x = (u16) reg_d0.h[0];
                    STAGE5_MIDBOSS5_MISSILE(reg_a0)->blast_shift_x = 0xFA00;
                    reg_d0.w = ENEMY_STAGE5_MIDBOSS5_SMALL_MISSILE;
                    spawn_request_add();
                    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d0.w += 0xFC401380;
                    STAGE5_MIDBOSS5_MISSILE(reg_a0)->at_start.y = (u16) reg_d0.h[1];
                    STAGE5_MIDBOSS5_MISSILE(reg_a0)->at_start.x = (u16) reg_d0.h[0];
                    STAGE5_MIDBOSS5_MISSILE(reg_a0)->blast_shift_x = 0x600;
                }
            }
        }
    }
    temp_v1 = STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->left_recoil;
    if (temp_v1 != 0) {
        STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->left_recoil = (u16) (temp_v1 - 0x100);
        if ((s16) STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->left_recoil <= 0) {
            STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->left_recoil = 0U;
        }
    }
    temp_v1_2 = STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->right_recoil;
    if (temp_v1_2 != 0) {
        STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->right_recoil = (u16) (temp_v1_2 - 0x100);
        if ((s16) STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->right_recoil <= 0) {
            STAGE5_MIDBOSS5_SMALL_LAUNCHERS(reg_a6)->right_recoil = 0U;
        }
    }
}

void stage5_midboss5_large_launchers_stop(void) {
    STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->on = 0;
}


void stage5_midboss5_large_launchers_start(void) {
    STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->on = 1;
    STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->fired = 0;
    STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->shot_timer.both = 0x1818;
    if (g_loop != 0) {
        STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->shot_timer.both = 0x404;
    }
}

s32 bullet_fire_fast();
s32 rng_next_unsigned();
extern u8 g_direction64_offsets_2CC[];
extern u16 g_frame_mod16;
extern s16 g_player2[];
extern s16 g_player1[];

void stage5_midboss5_large_launchers(void) {
    u16 t1;
    u16 t2;
    if (STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->on != 0) {
        if (STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->fired == 1) {
            STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->left_recoil = 0x800U;
            STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->fired = 0U;
        }
        if (STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->fired == 2) {
            STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->right_recoil = 0x800U;
            STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->fired = 0U;
        }
        if (STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->fired == 0) {
            if (g_frame_mod16 == 0) {
                reg_d0.w = 0;
                if (g_player1[0] < 0) {
                    reg_d0.h[0] = PLAYER(g_player1)->y.h;
                }
                reg_d1.w = 0;
                if (g_player2[0] < 0) {
                    reg_d1.h[0] = PLAYER(g_player2)->y.h;
                }
                if ((s32) reg_d0.h[0] <= (s32) reg_d1.h[0]) {
                    reg_d0.h[0] = reg_d1.h[0];
                }
                reg_d1.h[0] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] -= 0x400;
                if ((s32) reg_d1.h[0] <= (s32) reg_d0.h[0]) {
                    reg_d7.h[0] = 0x24;
                    reg_d0.w = 0x10007;
                    reg_d1.h[0] = 0x2E;
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    reg_a0 = (u8 *)g_direction64_offsets_2CC;
                    reg_d5.w = 0;
                    do {
                        reg_d3.h[0] = reg_d1.h[0];
                        reg_d3.h[0] &= 0x3F;
                        reg_d3.h[0] *= 4;
                        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                        reg_d3.w += reg_d5.w;
                        bullet_fire_fast();
                        reg_d1.b[0] += 1;
                        reg_d1.h[0] &= 0x3F;
                    } while ((s16)(--reg_d7.h[0]) >= 0);
                }
            }
            reg_tmp.b[0] = STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->shot_timer.b.countdown;
            STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->shot_timer.b.countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->shot_timer.b.countdown = (u8) STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->shot_timer.b.interval;
                reg_d0.h[0] = STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->left_recoil;
                reg_d0.h[0] += STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->right_recoil;
                if (reg_d0.h[0] == 0) {
                    rng_next_unsigned();
                    reg_d0.h[0] &= 1;
                    if (reg_d0.h[0] == 0) {
                        reg_d0.w = ENEMY_STAGE5_MIDBOSS5_LARGE_MISSILE;
                        spawn_request_add();
                        reg_d0.h[1] = ENTITY(reg_a6)->y.h;
                        reg_d0.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d0.w += 0xF47FFC00;
                        STAGE5_MIDBOSS5_MISSILE(reg_a0)->at_start.y = (u16) reg_d0.h[1];
                        STAGE5_MIDBOSS5_MISSILE(reg_a0)->at_start.x = (u16) reg_d0.h[0];
                        STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->fired = 1;
                    } else {
                        reg_d0.w = ENEMY_STAGE5_MIDBOSS5_LARGE_MISSILE;
                        spawn_request_add();
                        reg_d0.h[1] = ENTITY(reg_a6)->y.h;
                        reg_d0.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d0.w += 0xF4800400;
                        STAGE5_MIDBOSS5_MISSILE(reg_a0)->at_start.y = (u16) reg_d0.h[1];
                        STAGE5_MIDBOSS5_MISSILE(reg_a0)->at_start.x = (u16) reg_d0.h[0];
                        STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->fired = 2;
                    }
                }
            }
        }
    }
    t1 = STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->left_recoil;
    if (t1 != 0) {
        STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->left_recoil = (u16) (t1 - 0x80);
        if ((s16) STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->left_recoil <= 0) {
            STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->left_recoil = 0U;
        }
    }
    t2 = STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->right_recoil;
    if (t2 != 0) {
        STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->right_recoil = (u16) (t2 - 0x80);
        if ((s16) STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->right_recoil <= 0) {
            STAGE5_MIDBOSS5_LARGE_LAUNCHERS(reg_a6)->right_recoil = 0U;
        }
    }
}

extern u8 D_00266270[];

void stage5_midboss5_move_launch_drones(void) {
    u16 temp_a0;
    u32 temp_a1;
    u32 temp_a1_2;

    if (STAGE5_MIDBOSS5_MOVE(reg_a6)->step == 0) {
        STAGE5_MIDBOSS5_MOVE(reg_a6)->step = 1U;
        ENTITY(reg_a6)->move.sb.speed = 0x10;
        STAGE5_MIDBOSS5_MOVE(reg_a6)->drones.direction_a = 0U;
        STAGE5_MIDBOSS5_MOVE(reg_a6)->drones.direction_b = 0U;
        STAGE5_MIDBOSS5_MOVE(reg_a6)->launch.count = 0x10U;
    }
    temp_a0 = STAGE5_MIDBOSS5_MOVE(reg_a6)->step;
    if (temp_a0 == 1) {
        reg_d2.h[0] = 0x2800;
        reg_d3.h[0] = 0x1C00;
        stage5_midboss5_move_toward();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->move.sb.speed = 0;
            STAGE5_MIDBOSS5_MOVE(reg_a6)->step = 2U;
        }
    }
    if (STAGE5_MIDBOSS5_MOVE(reg_a6)->step == 2) {
        STAGE5_MIDBOSS5(reg_a5)->slide += 0x40;
        if ((s16) STAGE5_MIDBOSS5(reg_a5)->slide >= 0x600) {
            STAGE5_MIDBOSS5(reg_a5)->slide = 0x600U;
            STAGE5_MIDBOSS5_MOVE(reg_a6)->step = 3U;
        }
    }
    if (STAGE5_MIDBOSS5_MOVE(reg_a6)->step == 3) {
        reg_d1.w = 1;
        reg_d1.h[0] &= g_game_frame;
        if (reg_d1.h[0] == 0) {
            reg_d0.b[0] = STAGE5_MIDBOSS5_MOVE(reg_a6)->launch.count;
            reg_a4 = (u8 *)D_00266270;
            reg_d0.h[0] &= 7;
            reg_d0.h[0] *= 4;
            reg_a4 += reg_d0.h[0];
            reg_d0.w = ENEMY_STAGE5_MIDBOSS5_DRONE;
            spawn_request_add();
            reg_d0.h[1] = ENTITY(reg_a6)->y.h;
            reg_d0.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.w += 0x0C7FF600;
            temp_a1 = reg_d0.w;
            reg_tmp.h[1] = *(u16 *)reg_a4;
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
            reg_d0.w = temp_a1 + reg_tmp.w;
            STAGE5_MIDBOSS5_DRONE(reg_a0)->at_start.y = (u16) reg_d0.h[1];
            STAGE5_MIDBOSS5_DRONE(reg_a0)->at_start.x = (u16) reg_d0.h[0];
            STAGE5_MIDBOSS5_DRONE(reg_a0)->at_start.direction = (u8) STAGE5_MIDBOSS5_MOVE(reg_a6)->drones.direction_a;
            STAGE5_MIDBOSS5_MOVE(reg_a6)->drones.direction_a += 4;
            STAGE5_MIDBOSS5_MOVE(reg_a6)->drones.direction_a &= 0x3F;
            reg_d0.w = ENEMY_STAGE5_MIDBOSS5_DRONE;
            spawn_request_add();
            reg_d0.h[1] = ENTITY(reg_a6)->y.h;
            reg_d0.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.w += 0x0C800A00;
            temp_a1_2 = reg_d0.w;
            reg_tmp.h[1] = *(u16 *)reg_a4;
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
            reg_d0.w = temp_a1_2 + reg_tmp.w;
            STAGE5_MIDBOSS5_DRONE(reg_a0)->at_start.y = (u16) reg_d0.h[1];
            STAGE5_MIDBOSS5_DRONE(reg_a0)->at_start.x = (u16) reg_d0.h[0];
            STAGE5_MIDBOSS5_DRONE(reg_a0)->at_start.direction = (u8) STAGE5_MIDBOSS5_MOVE(reg_a6)->drones.direction_b;
            STAGE5_MIDBOSS5_MOVE(reg_a6)->drones.direction_b -= 4;
            STAGE5_MIDBOSS5_MOVE(reg_a6)->drones.direction_b &= 0x3F;
            STAGE5_MIDBOSS5_MOVE(reg_a6)->launch.count -= 1;
            if (STAGE5_MIDBOSS5_MOVE(reg_a6)->launch.count == 0) {
                reg_d0.w = 3;
                stage5_midboss5_set_move();
            }
        }
    }
}

void stage5_midboss5_move_after_drones(arg1)
    s32 arg1;
{
    s32 var_a1;
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    var_a1 = arg1;
    if (STAGE5_MIDBOSS5_MOVE(reg_a6)->step == 0) {
        var_a1 = 0xF0;
        STAGE5_MIDBOSS5_MOVE(reg_a6)->step = 1U;
        STAGE5_MIDBOSS5_MOVE(reg_a6)->frames_left = 0xF0U;
        ENTITY(reg_a6)->move.sb.speed = 0x10;
    }
    temp_v1 = STAGE5_MIDBOSS5(reg_a5)->slide;
    if (temp_v1 != 0) {
        STAGE5_MIDBOSS5(reg_a5)->slide = (u16) (temp_v1 - 0x40);
        if ((s16) STAGE5_MIDBOSS5(reg_a5)->slide <= 0) {
            STAGE5_MIDBOSS5(reg_a5)->slide = 0U;
        }
    }
    temp_a0 = STAGE5_MIDBOSS5_MOVE(reg_a6)->step;
    if (temp_a0 == 1) {
        reg_d2.h[0] = 0x5C00;
        reg_d3.h[0] = 0x1C00;
        stage5_midboss5_move_toward();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->move.sb.speed = 0;
            STAGE5_MIDBOSS5_MOVE(reg_a6)->step = 2U;
        }
    }
    temp_a0_2 = STAGE5_MIDBOSS5_MOVE(reg_a6)->step;
    if (temp_a0_2 == 2) {
        STAGE5_MIDBOSS5_MOVE(reg_a6)->frames_left -= 1;
        if (STAGE5_MIDBOSS5_MOVE(reg_a6)->frames_left == 0) {
            reg_d0.w = 1;
            stage5_midboss5_set_move();
        }
    }
}

void stage5_midboss5_move_launch_spin_drones(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u32 temp_a2;
    u8 temp_a1;

    if (STAGE5_MIDBOSS5_MOVE(reg_a6)->step == 0) {
        STAGE5_MIDBOSS5_MOVE(reg_a6)->step = 1U;
        ENTITY(reg_a6)->move.sb.speed = 8;
        STAGE5_MIDBOSS5_MOVE(reg_a6)->spin.step = 0U;
    }
    temp_a0 = STAGE5_MIDBOSS5_MOVE(reg_a6)->step;
    if (temp_a0 == 1) {
        reg_d2.h[0] = 0x3200;
        reg_d3.h[0] = 0x1C00;
        stage5_midboss5_move_toward();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->move.sb.speed = 4;
            STAGE5_MIDBOSS5_MOVE(reg_a6)->step = 2U;
            STAGE5_MIDBOSS5_MOVE(reg_a6)->spin.step = 1U;
        }
    }
    temp_a0_2 = STAGE5_MIDBOSS5_MOVE(reg_a6)->step;
    if (temp_a0_2 == 2) {
        reg_d2.h[0] = 0x3600;
        reg_d3.h[0] = 0x2A00;
        stage5_midboss5_move_toward();
        if (cond_flag == 0) {
            STAGE5_MIDBOSS5_MOVE(reg_a6)->step = 3U;
            STAGE5_MIDBOSS5_MOVE(reg_a6)->spin.step = 1U;
        }
    }
    temp_a0_3 = STAGE5_MIDBOSS5_MOVE(reg_a6)->step;
    if (temp_a0_3 == 3) {
        reg_d2.h[0] = 0x3600;
        reg_d3.h[0] = 0xE00;
        stage5_midboss5_move_toward();
        if (cond_flag == 0) {
            reg_d0.w = 5;
            stage5_midboss5_set_move();
        }
    }
    if ((STAGE5_MIDBOSS5_MOVE(reg_a6)->spin.step == 1) && ((temp_a0_4 = STAGE5_MIDBOSS5(reg_a5)->slide, (temp_a0_4 == 0x600)) || (STAGE5_MIDBOSS5(reg_a5)->slide = (u16) (temp_a0_4 + 0x40), (((s16) STAGE5_MIDBOSS5(reg_a5)->slide < 0x600) == 0)))) {
        STAGE5_MIDBOSS5(reg_a5)->slide = 0x600U;
        STAGE5_MIDBOSS5_MOVE(reg_a6)->spin.step = 2U;
        STAGE5_MIDBOSS5_MOVE(reg_a6)->spin.rounds_left = 8U;
        STAGE5_MIDBOSS5_MOVE(reg_a6)->launch.count = 0U;
    }
    if (STAGE5_MIDBOSS5_MOVE(reg_a6)->spin.step == 2) {
        reg_d1.h[0] = g_game_frame;
        reg_d1.b[0] &= 7;
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = STAGE5_MIDBOSS5_MOVE(reg_a6)->spin.rounds_left;
            reg_a4 = (u8 *)D_00266270;
            reg_d0.h[0] &= 7;
            reg_d0.h[0] *= 4;
            reg_a4 += reg_d0.h[0];
            reg_d0.w = ENEMY_STAGE5_MIDBOSS5_SPIN_DRONE;
            spawn_request_add();
            reg_d0.h[1] = ENTITY(reg_a6)->y.h;
            reg_d0.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.w += 0x0C7FF600;
            temp_a2 = reg_d0.w;
            reg_tmp.h[1] = *(u16 *)reg_a4;
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
            reg_d0.w = temp_a2 + reg_tmp.w;
            STAGE5_MIDBOSS5_SPIN_DRONE(reg_a0)->at_start.y = (u16) reg_d0.h[1];
            STAGE5_MIDBOSS5_SPIN_DRONE(reg_a0)->at_start.x = (u16) reg_d0.h[0];
            reg_d1.w = 4;
            temp_a1 = STAGE5_MIDBOSS5_MOVE(reg_a6)->launch.count;
            reg_d1.b[0] -= temp_a1;
            reg_d1.b[0] &= 0x3F;
            STAGE5_MIDBOSS5_SPIN_DRONE(reg_a0)->at_start.direction = (u8) reg_d1.b[0];
            STAGE5_MIDBOSS5_MOVE(reg_a6)->launch.count += 1;
            STAGE5_MIDBOSS5_MOVE(reg_a6)->launch.count &= 7;
            reg_d0.w = ENEMY_STAGE5_MIDBOSS5_SPIN_DRONE;
            spawn_request_add();
            reg_d0.h[1] = ENTITY(reg_a6)->y.h;
            reg_d0.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.w += 0x0C800A00;
            reg_tmp.h[1] = *(u16 *)reg_a4;
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
            reg_d0.w += reg_tmp.w;
            STAGE5_MIDBOSS5_SPIN_DRONE(reg_a0)->at_start.y = (u16) reg_d0.h[1];
            STAGE5_MIDBOSS5_SPIN_DRONE(reg_a0)->at_start.x = (u16) reg_d0.h[0];
            reg_d1.w = 4;
            reg_d1.b[0] -= STAGE5_MIDBOSS5_MOVE(reg_a6)->launch.count;
            reg_d1.b[0] &= 0x3F;
            STAGE5_MIDBOSS5_SPIN_DRONE(reg_a0)->at_start.direction = (u8) reg_d1.b[0];
            STAGE5_MIDBOSS5_MOVE(reg_a6)->launch.count += 1;
            STAGE5_MIDBOSS5_MOVE(reg_a6)->launch.count &= 7;
            STAGE5_MIDBOSS5_MOVE(reg_a6)->spin.rounds_left -= 1;
            if (STAGE5_MIDBOSS5_MOVE(reg_a6)->spin.rounds_left == 0) {
                STAGE5_MIDBOSS5_MOVE(reg_a6)->spin.step = 0U;
            }
        }
    }
}

void stage5_midboss5_move_after_spin_drones(arg1)
    s32 arg1;
{
    s32 var_a1;
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    var_a1 = arg1;
    if (STAGE5_MIDBOSS5_MOVE(reg_a6)->step == 0) {
        var_a1 = 0x40;
        STAGE5_MIDBOSS5_MOVE(reg_a6)->step = 1U;
        STAGE5_MIDBOSS5_MOVE(reg_a6)->frames_left = 0x40U;
        ENTITY(reg_a6)->move.sb.speed = 0x10;
    }
    temp_v1 = STAGE5_MIDBOSS5(reg_a5)->slide;
    if (temp_v1 != 0) {
        STAGE5_MIDBOSS5(reg_a5)->slide = (u16) (temp_v1 - 0x40);
        if ((s16) STAGE5_MIDBOSS5(reg_a5)->slide <= 0) {
            STAGE5_MIDBOSS5(reg_a5)->slide = 0U;
        }
    }
    temp_a0 = STAGE5_MIDBOSS5_MOVE(reg_a6)->step;
    if (temp_a0 == 1) {
        reg_d2.h[0] = 0x5C00;
        reg_d3.h[0] = 0x1C00;
        stage5_midboss5_move_toward();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->move.sb.speed = 0;
            STAGE5_MIDBOSS5_MOVE(reg_a6)->step = 2U;
        }
    }
    temp_a0_2 = STAGE5_MIDBOSS5_MOVE(reg_a6)->step;
    if (temp_a0_2 == 2) {
        STAGE5_MIDBOSS5_MOVE(reg_a6)->frames_left -= 1;
        if (STAGE5_MIDBOSS5_MOVE(reg_a6)->frames_left == 0) {
            reg_d0.w = 1;
            stage5_midboss5_set_move();
        }
    }
}

void stage5_midboss5_move_dying(void) {
    if (STAGE5_MIDBOSS5_MOVE(reg_a6)->step == 0) {
        STAGE5_MIDBOSS5_MOVE(reg_a6)->step = 1;
        ENTITY(reg_a6)->move.h = 0x420;
    }
}

void stage5_midboss5_move_away(void) {
    u8 temp_v1;

    if (STAGE5_MIDBOSS5_MOVE(reg_a6)->step == 0) {
        STAGE5_MIDBOSS5_MOVE(reg_a6)->step = 1U;
        ENTITY(reg_a6)->move.sb.dir = 0;
    }
    temp_v1 = ENTITY(reg_a6)->move.b.speed;
    if (temp_v1 != 8) {
        ENTITY(reg_a6)->move.b.speed = (u8) (temp_v1 + 1);
        if ((s8) ENTITY(reg_a6)->move.b.speed >= 8) {
            ENTITY(reg_a6)->move.b.speed = 8U;
        }
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x67FF) {
        STAGE5_MIDBOSS5_DAMAGE(reg_a6)->gone = 1;
    }
}

s32 func_002021D0();                            /* extern */
s32 func_002024F0();                            /* extern */
s32 entity_distance_to();                            /* extern */

void stage5_midboss5_move_toward(void) {
    reg_d0.h[0] = g_side_scroll_x[0];
    reg_d3.h[0] -= reg_d0.h[0];
    entity_distance_to();
    if (((s16) reg_d0.h[0] >= 0x200) || (ENTITY(reg_a6)->move.sb.speed = 8, (((s16) reg_d0.h[0] < 0x100) == 0)) || (ENTITY(reg_a6)->move.sb.speed = 6, (((s16) reg_d0.h[0] < 0x40) == 0))) {
        func_002021D0();
        func_002024F0();
        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

s32 explosion_spawn();
s32 explosion_burst_small();
s32 sfx_explosion_air_medium();
s32 sfx_explosion_extra_1();
s32 func_001D5040();
s32 rng_next();
s32 func_00201710();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u16 D_00266290[];
extern u16 D_002662E0[];

void stage5_midboss5_dying(void) {
    u16 temp_a0_2;
    u16 temp_a0_3;
    u8 temp_a0;

    if (STAGE5_MIDBOSS5_DAMAGE(reg_a6)->dying != 0) {
        ENTITY(reg_a6)->y.h -= 0x40;
        reg_d1.h[0] = STAGE5_MIDBOSS5_DAMAGE(reg_a6)->hit_by;
        func_00201710();
        temp_a0 = STAGE5_MIDBOSS5_DAMAGE(reg_a6)->dying_step;
        if (temp_a0 == 2) {
            STAGE5_MIDBOSS5_DAMAGE(reg_a6)->gone = 1;
            goto over;
        }
        if (temp_a0 == 1) {
            STAGE5_MIDBOSS5_DAMAGE(reg_a6)->blast_timer.b.countdown -= 1;
            if (STAGE5_MIDBOSS5_DAMAGE(reg_a6)->blast_timer.b.countdown == 0) {
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_a1 = (u8 *)(D_002662E0);
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
                STAGE5_MIDBOSS5_DAMAGE(reg_a6)->blast_timer.b.countdown = 0x10U;
                STAGE5_MIDBOSS5_DAMAGE(reg_a6)->dying_step = 2U;
                vibration_start_pad1(0xB4, 0x3C, 0x10);
                vibration_start_pad2(0xB4, 0x3C);
            }
        }
        if (STAGE5_MIDBOSS5_DAMAGE(reg_a6)->dying_step == 0) {
            reg_tmp.b[0] = STAGE5_MIDBOSS5_DAMAGE(reg_a6)->blast_timer.b.countdown;
            STAGE5_MIDBOSS5_DAMAGE(reg_a6)->blast_timer.b.countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                STAGE5_MIDBOSS5_DAMAGE(reg_a6)->blast_timer.b.countdown = (u8) STAGE5_MIDBOSS5_DAMAGE(reg_a6)->blast_timer.b.interval;
                sfx_explosion_air_medium();
                reg_a1 = (u8 *)(D_00266290);
                reg_a1 += STAGE5_MIDBOSS5_DAMAGE(reg_a6)->blast;
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
                STAGE5_MIDBOSS5_DAMAGE(reg_a6)->blast += 0xC;
                if (STAGE5_MIDBOSS5_DAMAGE(reg_a6)->blast == 0x48) {
                    STAGE5_MIDBOSS5_DAMAGE(reg_a6)->blast = 0U;
                    STAGE5_MIDBOSS5_DAMAGE(reg_a6)->blast_rounds -= 1;
                    if (STAGE5_MIDBOSS5_DAMAGE(reg_a6)->blast_rounds == 0) {
                        STAGE5_MIDBOSS5_DAMAGE(reg_a6)->blast_timer.both = 0x1006;
                        STAGE5_MIDBOSS5_DAMAGE(reg_a6)->dying_step = 1U;
                    }
                }
            }
        }
        goto not_over;
    }
not_over:
    cond_flag = 0;
    return;
over:
    cond_flag = 1;
}

void stage5_midboss5_small_missile_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern u8 D_00266340[];
extern u8 D_0028DA38[8];

void stage5_midboss5_small_missile_start() {
    u16 temp_a1;

    reg_a0 = D_00266340;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) STAGE5_MIDBOSS5_MISSILE(reg_a5)->at_start.y;
    temp_a1 = STAGE5_MIDBOSS5_MISSILE(reg_a5)->at_start.x;
    ENTITY(reg_a6)->x.h = temp_a1;
    reg_a0 = D_0028DA38;
    reg_d0.h[0] = 1;
    enemy_set_task_state();
}

s32 sprite_draw_layer3();
s32 velocity_from_direction();
extern u8 D_0028E2E4;

void stage5_midboss5_small_missile(void) {
    s32 enemy_remove();
    if (D_0028E2E4 != 0) goto remove;
    reg_d1.w = 0;
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    velocity_from_direction();
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
    STAGE5_MIDBOSS5_MISSILE(reg_a5)->now.frames_left -= 1;
    if (STAGE5_MIDBOSS5_MISSILE(reg_a5)->now.frames_left != 0) goto draw;
    reg_d0.w = ENEMY_STAGE5_MIDBOSS5_SMALL_BLAST;
    spawn_request_add();
    STAGE5_MIDBOSS5_BLAST(reg_a0)->at_start.y = ENTITY(reg_a6)->y.h;
    STAGE5_MIDBOSS5_BLAST(reg_a0)->at_start.x = ENTITY(reg_a6)->x.h;
    reg_d0.w = ENEMY_STAGE5_MIDBOSS5_SMALL_BLAST;
    spawn_request_add();
    STAGE5_MIDBOSS5_BLAST(reg_a0)->at_start.y = ENTITY(reg_a6)->y.h;
    STAGE5_MIDBOSS5_BLAST(reg_a0)->at_start.x = ENTITY(reg_a6)->x.h;
    STAGE5_MIDBOSS5_BLAST(reg_a0)->at_start.y += 0xA00;
    reg_d0.h[0] = STAGE5_MIDBOSS5_MISSILE(reg_a5)->blast_shift_x;
    STAGE5_MIDBOSS5_BLAST(reg_a0)->at_start.x += reg_d0.h[0];
remove:
    enemy_remove();
    return;
draw:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_d2.w = 0x1E94;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFA00FF00;
    reg_d3.h[0] = 0x608;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer3();
}

void stage5_midboss5_small_blast_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

extern u8 D_00266360[];
extern u8 D_0028DA40[8];

void stage5_midboss5_small_blast_start() {
    u16 temp_a1;

    reg_a0 = D_00266360;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) STAGE5_MIDBOSS5_BLAST(reg_a5)->at_start.y;
    temp_a1 = STAGE5_MIDBOSS5_BLAST(reg_a5)->at_start.x;
    ENTITY(reg_a6)->x.h = temp_a1;
    reg_a0 = D_0028DA40;
    reg_d0.h[0] = 2;
    enemy_set_task_state();
}

s32 sprite_draw_layer5_zoom();
s32 sprite_draw_with_bullets_zoom();
s32 entity_check_bounds();
extern u8 D_00266380[];
extern u16 g_frame_mod4;

void stage5_midboss5_small_blast(void) {
    s32 enemy_remove();
    u8 *t1;
    u16 t2;
    u8 t3;

    if (D_0028E2E4 != 0) goto remove;
    {
        if (g_enemy_signal_4 == 0) {
            stage5_midboss5_missile_explode();
            return;
        }
        entity_check_bounds();
        if (cond_flag != 0) {
            if (STAGE5_MIDBOSS5_BLAST(reg_a5)->now.seen == 0) goto move;
remove:
            enemy_remove();
            return;
        }
        STAGE5_MIDBOSS5_BLAST(reg_a5)->now.seen = 1U;
move:
        reg_d1.w = 0;
        reg_d0.w = 0;
        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        velocity_from_direction();
        ENTITY(reg_a6)->y.h += reg_d2.h[0];
        t1 = (u8 *)(reg_a6);
        (*(u16 *)((u8 *)(t1) + (4))) += reg_d3.h[0];
        if (STAGE5_MIDBOSS5_BLAST(reg_a5)->now.speeding_up == 0) {
            ENTITY(reg_a6)->move.b.speed -= 1;
            if (ENTITY(reg_a6)->move.b.speed == 0) {
                t1 = (u8 *)1;
                STAGE5_MIDBOSS5_BLAST(reg_a5)->now.speeding_up = 1U;
                ENTITY(reg_a6)->move.b.dir = 0x20U;
            }
        } else {
            ENTITY(reg_a6)->move.b.speed += 1;
            if (g_loop != 0) {
                ENTITY(reg_a6)->move.b.speed += 1;
            }
        }
        reg_tmp.b[0] = STAGE5_MIDBOSS5_BLAST(reg_a5)->frame_timer.b.countdown;
        STAGE5_MIDBOSS5_BLAST(reg_a5)->frame_timer.b.countdown -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            STAGE5_MIDBOSS5_BLAST(reg_a5)->frame_timer.b.countdown = (u8) STAGE5_MIDBOSS5_BLAST(reg_a5)->frame_timer.b.interval;
            STAGE5_MIDBOSS5_BLAST(reg_a5)->now.frame += 4;
            if ((s16) STAGE5_MIDBOSS5_BLAST(reg_a5)->now.frame >= 0x2C) {
                STAGE5_MIDBOSS5_BLAST(reg_a5)->now.frame = 0x14U;
            }
        }
        reg_a0 = reg_a6;
        enemy_hitbox_debug_draw();
        reg_a0 = (u8 *)D_00266380;
        reg_a0 += STAGE5_MIDBOSS5_BLAST(reg_a5)->now.frame;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        t2 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = t2;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        t3 = ENTITY(reg_a6)->attr.b.palette;
        reg_d4.b[0] = t3;
        reg_d6.w = 0xF800F800;
        if (g_frame_mod4 != 0) {
            sprite_draw_with_bullets_zoom();
        } else {
            sprite_draw_layer5_zoom();
        }
    }
}

void stage5_midboss5_large_missile_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

extern u8 D_002663C0[];
extern u8 D_0028DA48[8];

void stage5_midboss5_large_missile_start() {
    u16 temp_a1;

    reg_a0 = D_002663C0;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) STAGE5_MIDBOSS5_MISSILE(reg_a5)->at_start.y;
    temp_a1 = STAGE5_MIDBOSS5_MISSILE(reg_a5)->at_start.x;
    ENTITY(reg_a6)->x.h = temp_a1;
    reg_a0 = D_0028DA48;
    reg_d0.h[0] = 1;
    enemy_set_task_state();
}

void stage5_midboss5_large_missile(void) {
    s32 enemy_remove();
    if (D_0028E2E4 != 0) goto remove;
    if (g_enemy_signal_4 == 0) {
        stage5_midboss5_missile_explode();
        return;
    }
    reg_d1.w = 0;
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    velocity_from_direction();
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
    STAGE5_MIDBOSS5_MISSILE(reg_a5)->now.frames_left -= 1;
    if (STAGE5_MIDBOSS5_MISSILE(reg_a5)->now.frames_left != 0) goto draw;
    reg_d0.w = ENEMY_STAGE5_MIDBOSS5_LARGE_BLAST;
    spawn_request_add();
    STAGE5_MIDBOSS5_BLAST(reg_a0)->at_start.y = ENTITY(reg_a6)->y.h;
    STAGE5_MIDBOSS5_BLAST(reg_a0)->at_start.x = ENTITY(reg_a6)->x.h;
remove:
    enemy_remove();
    return;
draw:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_d2.w = 0x1E93;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xF600FE00;
    reg_d3.h[0] = 0xA10;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer3();
}

s32 explosion_spawn();                            /* extern */

void stage5_midboss5_missile_explode(void) {
    s32 enemy_remove(u16);
    u16 temp_a0;

    reg_d0.h[0] = 4;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->x = temp_a0;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    enemy_remove(temp_a0);
}

void stage5_midboss5_large_blast_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern u8 D_002663E0[];
extern u8 D_0028DA50[8];

void stage5_midboss5_large_blast_start() {
    u16 temp_a1;

    reg_a0 = D_002663E0;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) STAGE5_MIDBOSS5_BLAST(reg_a5)->at_start.y;
    temp_a1 = STAGE5_MIDBOSS5_BLAST(reg_a5)->at_start.x;
    ENTITY(reg_a6)->x.h = temp_a1;
    reg_a0 = D_0028DA50;
    reg_d0.h[0] = 2;
    enemy_set_task_state();
}

extern u8 D_00266400[];

void stage5_midboss5_large_blast(void) {
    s32 enemy_remove();
    u8 *t1;
    u16 t2;
    u8 t3;
    u8 t4;
    u8 t5;

    if (D_0028E2E4 != 0) goto remove;
    {
        entity_check_bounds();
        if (cond_flag != 0) {
            if (STAGE5_MIDBOSS5_BLAST(reg_a5)->now.seen == 0) goto move;
remove:
            enemy_remove();
            return;
        }
        STAGE5_MIDBOSS5_BLAST(reg_a5)->now.seen = 1U;
move:
        reg_d1.w = 0;
        reg_d0.w = 0;
        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        velocity_from_direction();
        ENTITY(reg_a6)->y.h += reg_d2.h[0];
        t1 = (u8 *)(reg_a6);
        (*(u16 *)((u8 *)(t1) + (4))) += reg_d3.h[0];
        if (STAGE5_MIDBOSS5_BLAST(reg_a5)->now.speeding_up == 0) {
            ENTITY(reg_a6)->move.b.speed -= 1;
            if (ENTITY(reg_a6)->move.b.speed == 0) {
                t1 = (u8 *)0x20;
                STAGE5_MIDBOSS5_BLAST(reg_a5)->now.speeding_up = 1U;
                ENTITY(reg_a6)->move.b.dir = 0x20U;
                ENTITY(reg_a6)->flags.h = 0x8001;
            }
        } else if (g_loop == 0) {
            t1 = (u8 *)(reg_a6 + 0x1B);
            t5 = ENTITY(reg_a6)->move.b.speed;
            if (t5 != 0x1C) {
                ENTITY(reg_a6)->move.b.speed = (u8) (t5 + 1);
            }
        } else {
            t4 = ENTITY(reg_a6)->move.b.speed;
            if ((s32) t4 < 0x3C) {
                ENTITY(reg_a6)->move.b.speed = (u8) (t4 + 4);
            }
        }
        reg_tmp.b[0] = STAGE5_MIDBOSS5_BLAST(reg_a5)->frame_timer.b.countdown;
        STAGE5_MIDBOSS5_BLAST(reg_a5)->frame_timer.b.countdown -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            STAGE5_MIDBOSS5_BLAST(reg_a5)->frame_timer.b.countdown = (u8) STAGE5_MIDBOSS5_BLAST(reg_a5)->frame_timer.b.interval;
            STAGE5_MIDBOSS5_BLAST(reg_a5)->now.frame += 4;
            if ((s32) STAGE5_MIDBOSS5_BLAST(reg_a5)->now.frame >= 0x38) {
                STAGE5_MIDBOSS5_BLAST(reg_a5)->now.frame = 0x28U;
            }
        }
        reg_a0 = reg_a6;
        enemy_hitbox_debug_draw();
        reg_a0 = (u8 *)D_00266400;
        reg_a0 += STAGE5_MIDBOSS5_BLAST(reg_a5)->now.frame;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        t2 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = t2;
        reg_d1.w += 0xF600FA00;
        reg_d3.h[0] = 0xA30;
        reg_d4.w = 0;
        t3 = ENTITY(reg_a6)->attr.b.palette;
        reg_d4.b[0] = t3;
        reg_d6.w = 0xF800F800;
        if (g_frame_mod4 != 0) {
            sprite_draw_with_bullets_zoom();
        } else {
            sprite_draw_layer5_zoom();
        }
    }
}

void stage5_midboss5_drone_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern u8 D_00266440[];
extern u8 D_00266460[];

void stage5_midboss5_drone_start() {
    u8 temp_a1;

    reg_a0 = D_00266460;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) STAGE5_MIDBOSS5_DRONE(reg_a5)->at_start.y;
    ENTITY(reg_a6)->x.h = (u16) STAGE5_MIDBOSS5_DRONE(reg_a5)->at_start.x;
    temp_a1 = STAGE5_MIDBOSS5_DRONE(reg_a5)->at_start.direction;
    ENTITY(reg_a6)->move.b.dir = temp_a1;
    reg_a0 = D_00266440;
    reg_d0.h[0] = 8;
    enemy_set_task_state();
}

s32 sfx_explosion_ground_medium();
s32 func_00202490();
s32 direction_turn_toward();

void stage5_midboss5_drone(void) {
    s32 enemy_remove();
    u8 t;
    u8 c;

    entity_velocity();
    STAGE5_MIDBOSS5_DRONE(reg_a5)->life -= 1;
    if (STAGE5_MIDBOSS5_DRONE(reg_a5)->life == 0) goto explode;
    if (g_enemy_signal_3 == 0) goto explode;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto not_hit;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    reg_d0.b[0] ^= 0xC;
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    if (ENTITY(reg_a6)->hp.sh >= 0) goto check_flying;
explode:
    reg_d0.h[0] = 0x14;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    sfx_explosion_ground_medium();
    enemy_remove();
    return;
not_hit:
    ENTITY(reg_a6)->attr.b.palette = 0x13;
check_flying:
    t = STAGE5_MIDBOSS5_DRONE(reg_a5)->now.mode;
    if (!(t & 8)) goto check_first_animation;
    if (t & 0x80) goto slow_down;
    if (!(0 > ENTITY(reg_a6)->x.sh)) goto check_right_edge;
    ENTITY(reg_a6)->move.b.dir += 0x20;
    ENTITY(reg_a6)->move.b.dir &= 0x3F;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.mode |= 0x80;
check_right_edge:
    if (ENTITY(reg_a6)->x.sh <= 0x3800) goto check_y;
    ENTITY(reg_a6)->move.b.dir += 0x20;
    ENTITY(reg_a6)->move.b.dir &= 0x3F;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.mode |= 0x80;
check_y:
    if (!(ENTITY(reg_a6)->y.sh < 0x3200)) goto slow_down;
    ENTITY(reg_a6)->move.b.dir += 0x20;
    ENTITY(reg_a6)->move.b.dir &= 0x3F;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.mode |= 0x80;
slow_down:
    ENTITY(reg_a6)->move.b.speed -= 1;
    if (ENTITY(reg_a6)->move.b.speed != 8) goto check_first_animation;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.mode = 4;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.animated = 0;
check_first_animation:
    if (!(STAGE5_MIDBOSS5_DRONE(reg_a5)->now.mode & 1)) goto check_second_animation;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.animated = 1;
    reg_d0.h[0] = g_game_frame;
    reg_d0.h[0] &= 1;
    if (reg_d0.h[0] != 0) goto check_second_animation;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.frame += 4;
    if ((s16) STAGE5_MIDBOSS5_DRONE(reg_a5)->now.frame < 0xC) goto check_second_animation;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.mode &= 0xFE;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.mode |= 2;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.frame = 0;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->rounds_left = 8;
check_second_animation:
    if (!(STAGE5_MIDBOSS5_DRONE(reg_a5)->now.mode & 2)) goto check_aiming;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.animated = 1;
    if (STAGE5_MIDBOSS5_DRONE(reg_a5)->rounds_left == 0) goto second_animation_over;
    reg_d0.h[0] = g_game_frame;
    reg_d0.h[0] &= 1;
    if (reg_d0.h[0] != 0) goto check_aiming;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->rounds_left -= 1;
    if (STAGE5_MIDBOSS5_DRONE(reg_a5)->now.frame != 8) goto next_frame;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.frame = 0;
next_frame:
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.frame += 4;
    goto check_aiming;
second_animation_over:
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.mode &= 0xFD;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.frame = 0;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.animated = 0;
check_aiming:
    if (!(STAGE5_MIDBOSS5_DRONE(reg_a5)->now.mode & 4)) goto check_stepping;
    reg_d6.w = 0;
    reg_d7.b[0] = ENTITY(reg_a6)->move.b.dir;
    func_00202490();
    if (cond_flag != 0) goto stop_aiming;
    reg_d6.w = 1;
    reg_d7.b[0] -= reg_d1.b[0];
    if (reg_d7.b[0] == 0) goto stop_aiming;
    goto check_stepping;
stop_aiming:
    if (reg_d6.b[0] != 0) goto start_steps;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->other_21 = 1;
start_steps:
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.mode = 0x10;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->steps_left = 4;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->wait = 0x10;
check_stepping:
    if (!(STAGE5_MIDBOSS5_DRONE(reg_a5)->now.mode & 0x10)) goto check_turning;
    c = STAGE5_MIDBOSS5_DRONE(reg_a5)->wait;
    if (c == 0) goto step;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->wait = c - 1;
    goto check_turning;
step:
    if (STAGE5_MIDBOSS5_DRONE(reg_a5)->steps_left == 0) goto steps_over;
    if (STAGE5_MIDBOSS5_DRONE(reg_a5)->other_21 != 0) goto count_step;
    reg_d0.h[0] = g_game_frame;
    reg_d0.b[0] &= 7;
    if (reg_d0.b[0] != 0) goto check_turning;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d0.w = 0x80007;
    reg_d3.w = 0;
    reg_d1.b[0] += 1;
    bullet_fire_fast();
    reg_d1.b[0] -= 2;
    bullet_fire_fast();
    reg_d1.b[0] += 0x20;
    reg_d1.b[0] &= 0x3F;
    reg_d0.w = 0x30;
    velocity_from_direction();
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
count_step:
    STAGE5_MIDBOSS5_DRONE(reg_a5)->steps_left -= 1;
    goto check_turning;
steps_over:
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.mode = 0x20;
    rng_next();
    STAGE5_MIDBOSS5_DRONE(reg_a5)->new_direction = ENTITY(reg_a6)->move.b.dir;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->new_direction += reg_d0.b[0];
    STAGE5_MIDBOSS5_DRONE(reg_a5)->new_direction &= 0x3F;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->wait = 0x10;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->other_21 = 0;
check_turning:
    if (!(STAGE5_MIDBOSS5_DRONE(reg_a5)->now.mode & 0x20)) goto check_leaving;
    c = STAGE5_MIDBOSS5_DRONE(reg_a5)->wait;
    if (c == 0) goto turn;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->wait = c - 1;
    goto check_leaving;
turn:
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d1.b[0] = STAGE5_MIDBOSS5_DRONE(reg_a5)->new_direction;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    reg_d1.b[0] -= STAGE5_MIDBOSS5_DRONE(reg_a5)->new_direction;
    if (reg_d1.b[0] != 0) goto check_leaving;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.mode = 0x40;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->wait = 0x10;
check_leaving:
    if (!(STAGE5_MIDBOSS5_DRONE(reg_a5)->now.mode & 0x40)) goto draw;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->wait -= 1;
    if (STAGE5_MIDBOSS5_DRONE(reg_a5)->wait != 0) goto draw;
    STAGE5_MIDBOSS5_DRONE(reg_a5)->now.mode = 9;
    ENTITY(reg_a6)->move.b.speed = 0x20;
    rng_next_unsigned();
    reg_d0.b[0] &= 7;
    ENTITY(reg_a6)->move.b.speed += reg_d0.b[0];
draw:
    stage5_midboss5_drone_draw_flying();
    stage5_midboss5_drone_draw_animated();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

s32 sprite_draw_layer5();
extern u8 D_00266480[];

void stage5_midboss5_drone_draw_flying(void) {
    u16 temp_a0;

    if (STAGE5_MIDBOSS5_DRONE(reg_a5)->now.animated == 0) {
        reg_a0 = (u8 *)D_00266480;
        reg_d0.w = 0xE;
        reg_d0.b[0] &= ENTITY(reg_a6)->move.b.dir;
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a0 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a0;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
        sprite_draw_layer5();
    }
}

extern u8 D_002664A0[];

void stage5_midboss5_drone_draw_animated(void) {
    u16 temp_a0;

    if (STAGE5_MIDBOSS5_DRONE(reg_a5)->now.animated != 0) {
        reg_d1.w = 0;
        reg_a0 = (u8 *)D_002664A0;
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] *= 8;
        reg_a0 += reg_d1.h[0];
        reg_a1 = reg_a0;
        reg_a0 += STAGE5_MIDBOSS5_DRONE(reg_a5)->now.frame;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a0 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a0;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
        reg_tmp.h[1] = *(u16 *)(reg_a1 + 0xC);
        reg_tmp.h[0] = *(u16 *)(reg_a1 + 0xE);
        reg_d4.w += reg_tmp.w;
        sprite_draw_layer5();
    }
}

void stage5_midboss5_spin_drone_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 func_00202180();
extern u8 D_002666A0[];
extern u8 D_002666B0[];

void stage5_midboss5_spin_drone_start() {
    u8 temp_a1;

    reg_a0 = D_002666B0;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->at_start.y;
    ENTITY(reg_a6)->x.h = (u16) STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->at_start.x;
    temp_a1 = STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->at_start.direction;
    ENTITY(reg_a6)->move.b.dir = temp_a1;
    reg_a0 = D_002666A0;
    reg_d0.h[0] = 7;
    enemy_set_task_state();
    reg_d1.w = 0;
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    velocity_from_direction();
    STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->speed_y = (u16) reg_d2.h[0];
    STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->speed_x = (u16) reg_d3.h[0];
    STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->shot_direction = 0x20U;
    func_00202180();
    if (cond_flag == 0) {
        STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->shot_direction = (u8) reg_d1.b[0];
    }
}

void bullet_fire_fast_in_arc(void);

void stage5_midboss5_spin_drone(void) {
    s32 enemy_remove();
    if (ENTITY(reg_a6)->y.sh > -0x400) goto move;
    enemy_remove();
    return;
move:
    reg_d0.h[1] = STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->speed_y;
    reg_d0.h[0] = STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->speed_x;
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp.w += reg_d0.w;
    ENTITY(reg_a6)->y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = reg_tmp.h[0];
    STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->speed_y -= 2;
    if (g_enemy_signal_3 == 0) goto explode;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto not_hit;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    reg_d0.b[0] ^= 0xC;
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    if (ENTITY(reg_a6)->hp.sh >= 0) goto animate;
explode:
    reg_d0.h[0] = 0x14;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    sfx_explosion_ground_medium();
    enemy_remove();
    return;
not_hit:
    ENTITY(reg_a6)->attr.b.palette = 0x13;
animate:
    reg_d0.w = 3;
    reg_d0.h[0] &= g_game_frame;
    if (reg_d0.h[0] != 0) goto shoot;
    STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->now.frame += 4;
    STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->now.frame &= 0x1F;
shoot:
    if (STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->shots_left == 0) goto draw;
    reg_tmp.b[0] = STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->shot_timer.b.countdown;
    STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->shot_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto draw;
    STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->shot_timer.b.countdown = STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->shot_timer.b.interval;
    STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->shot_direction += 3;
    STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->shot_direction &= 0x3F;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.b[0] = STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->shot_direction;
    reg_d0.w = 0xFFFC0007;
    reg_d4.w = 0;
    reg_d3.w = 0;
    bullet_fire_fast_in_arc();
    reg_d1.b[0] += 0x15;
    reg_d1.b[0] &= 0x3F;
    bullet_fire_fast_in_arc();
    reg_d1.b[0] += 0x15;
    reg_d1.b[0] &= 0x3F;
    bullet_fire_fast_in_arc();
    STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->shots_left -= 1;
draw:
    reg_a0 = (u8 *)D_00266480;
    reg_a0 += STAGE5_MIDBOSS5_SPIN_DRONE(reg_a5)->now.frame;
    reg_d2.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFA00FC00;
    reg_d3.h[0] = 0x620;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer5();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

/* Fires only in directions 0x0D to 0x33 of the 0x40 that make a full turn. */
void bullet_fire_fast_in_arc(void)
{
    u32 savedD0;
    s8 direction;

    savedD0 = reg_d0.w;
    direction = (s8)reg_d1.b[0];
    if (direction < 0x34 && direction > 0xC) {
        bullet_fire_fast();
    }
    reg_d0.w = savedD0;
}

u8 D_002661C8[14] = {
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 D_002661E0[144] = {
    0x00, 0x80, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x0B,
    0x00, 0x0E, 0x00, 0x0E, 0xFF, 0x7F, 0x00, 0x08, 0x12, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x12, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x00, 0x00, 0x08, 0x08, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 D_00266270[32] = {
    0x40, 0x03, 0xE0, 0x01, 0xC0, 0x03, 0xC0, 0x00, 0x60, 0x04, 0xA0, 0xFF, 0x20, 0x05, 0x80, 0xFE,
    0xA0, 0x02, 0xE0, 0x00, 0x60, 0x03, 0xA0, 0xFF, 0x00, 0x04, 0x80, 0xFE, 0x60, 0x04, 0x60, 0xFD,
};

u16 D_00266290[40] = {
    0x0000, 0x0008, 0x0000, 0x0800, 0x0400, 0x0000, 0x0000, 0x0085,
    0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x008D, 0x0000, 0xF800,
    0x0000, 0x0000, 0x0000, 0x0008, 0x0040, 0xF000, 0xFC00, 0x0000,
    0x0000, 0x0085, 0x0000, 0xE800, 0xFC00, 0x0000, 0x0000, 0x008D,
    0x0000, 0xE800, 0x0800, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000,
};

u16 D_002662E0[40] = {
    0x0002, 0x0008, 0x0000, 0x0800, 0x0400, 0x0000, 0x0004, 0x0085,
    0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x008D, 0x0000, 0xF800,
    0x0000, 0x0000, 0x0006, 0x0008, 0x0040, 0xF000, 0xFC00, 0x0000,
    0x0008, 0x0085, 0x0000, 0xE800, 0xFC00, 0x0000, 0x000A, 0x008D,
    0x0000, 0xE800, 0x0800, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000,
};

u8 D_00266330[16] = {
    0x01, 0x00, 0x00, 0x00, 0x80, 0x04, 0x03, 0x00, 0x04, 0x00, 0x1F, 0x00, 0x09, 0x00, 0x00, 0x00,
};

u8 D_00266340[32] = {
    0x01, 0x80, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x06,
    0x80, 0x01, 0x80, 0x01, 0xFF, 0x7F, 0x20, 0x0A, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 D_00266360[32] = {
    0x01, 0x80, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x04,
    0x80, 0x02, 0x80, 0x02, 0xFF, 0x7F, 0x00, 0x10, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 D_00266380[64] = {
    0x00, 0x00, 0xDF, 0x1E, 0x00, 0x00, 0xE0, 0x1E, 0x00, 0x00, 0xE1, 0x1E, 0x00, 0x00, 0xE2, 0x1E,
    0x00, 0x00, 0xE3, 0x1E, 0x00, 0x00, 0xE4, 0x1E, 0x00, 0x00, 0xE5, 0x1E, 0x00, 0x00, 0xE6, 0x1E,
    0x00, 0x00, 0xE7, 0x1E, 0x00, 0x00, 0xE8, 0x1E, 0x00, 0x00, 0xE9, 0x1E, 0x00, 0x00, 0xEA, 0x1E,
    0x00, 0x00, 0xEB, 0x1E, 0x00, 0x00, 0xEC, 0x1E, 0x00, 0x00, 0xED, 0x1E, 0x00, 0x00, 0xEE, 0x1E,
};

u8 D_002663C0[32] = {
    0x01, 0x80, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x08,
    0x00, 0x02, 0x00, 0x02, 0xFF, 0x7F, 0x20, 0x08, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 D_002663E0[32] = {
    0x00, 0x80, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x04,
    0x00, 0x04, 0x00, 0x04, 0xFF, 0x7F, 0x00, 0x18, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 D_00266400[64] = {
    0x00, 0x00, 0xD1, 0x1E, 0x00, 0x00, 0xD2, 0x1E, 0x00, 0x00, 0xD3, 0x1E, 0x00, 0x00, 0xD4, 0x1E,
    0x00, 0x00, 0xD5, 0x1E, 0x00, 0x00, 0xD6, 0x1E, 0x00, 0x00, 0xD7, 0x1E, 0x00, 0x00, 0xD8, 0x1E,
    0x00, 0x00, 0xD9, 0x1E, 0x00, 0x00, 0xDA, 0x1E, 0x00, 0x00, 0xDB, 0x1E, 0x00, 0x00, 0xDC, 0x1E,
    0x00, 0x00, 0xDD, 0x1E, 0x00, 0x00, 0xDE, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 D_00266440[32] = {
    0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 D_00266460[32] = {
    0x01, 0xA0, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02,
    0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x20, 0x20, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 D_00266480[32] = {
    0x00, 0x00, 0x95, 0x1E, 0x00, 0x00, 0x96, 0x1E, 0x00, 0x00, 0x97, 0x1E, 0x00, 0x00, 0x98, 0x1E,
    0x00, 0x00, 0x99, 0x1E, 0x00, 0x00, 0x9A, 0x1E, 0x00, 0x00, 0x9B, 0x1E, 0x00, 0x00, 0x9C, 0x1E,
};

u8 D_002664A0[512] = {
    0x00, 0x00, 0x9D, 0x1E, 0x00, 0x00, 0xAE, 0x1E, 0x00, 0x00, 0xBF, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x9E, 0x1E, 0x00, 0x00, 0xAF, 0x1E, 0x00, 0x00, 0xC0, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x9F, 0x1E, 0x00, 0x00, 0xB0, 0x1E, 0x00, 0x00, 0xC1, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xA0, 0x1E, 0x00, 0x00, 0xB1, 0x1E, 0x00, 0x00, 0xC2, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xA1, 0x1E, 0x00, 0x00, 0xB2, 0x1E, 0x00, 0x00, 0xC3, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xA2, 0x1E, 0x00, 0x00, 0xB3, 0x1E, 0x00, 0x00, 0xC4, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xA3, 0x1E, 0x00, 0x00, 0xB4, 0x1E, 0x00, 0x00, 0xC5, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xA4, 0x1E, 0x00, 0x00, 0xB5, 0x1E, 0x00, 0x00, 0xC6, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xA5, 0x1E, 0x00, 0x00, 0xB6, 0x1E, 0x00, 0x00, 0xC7, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xA6, 0x1E, 0x00, 0x00, 0xB7, 0x1E, 0x00, 0x00, 0xC8, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xA7, 0x1E, 0x00, 0x00, 0xB8, 0x1E, 0x00, 0x00, 0xC9, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xA8, 0x1E, 0x00, 0x00, 0xB9, 0x1E, 0x00, 0x00, 0xCA, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xA9, 0x1E, 0x00, 0x00, 0xBA, 0x1E, 0x00, 0x00, 0xCB, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xAA, 0x1E, 0x00, 0x00, 0xBB, 0x1E, 0x00, 0x00, 0xCC, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xAB, 0x1E, 0x00, 0x00, 0xBC, 0x1E, 0x00, 0x00, 0xCD, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xAC, 0x1E, 0x00, 0x00, 0xBD, 0x1E, 0x00, 0x00, 0xCE, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xAD, 0x1E, 0x00, 0x00, 0xBE, 0x1E, 0x00, 0x00, 0xCF, 0x1E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xAC, 0x1E, 0x00, 0x00, 0xBD, 0x1E, 0x00, 0x00, 0xCE, 0x1E, 0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0xAB, 0x1E, 0x00, 0x00, 0xBC, 0x1E, 0x00, 0x00, 0xCD, 0x1E, 0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0xAA, 0x1E, 0x00, 0x00, 0xBB, 0x1E, 0x00, 0x00, 0xCC, 0x1E, 0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0xA9, 0x1E, 0x00, 0x00, 0xBA, 0x1E, 0x00, 0x00, 0xCB, 0x1E, 0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0xA8, 0x1E, 0x00, 0x00, 0xB9, 0x1E, 0x00, 0x00, 0xCA, 0x1E, 0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0xA7, 0x1E, 0x00, 0x00, 0xB8, 0x1E, 0x00, 0x00, 0xC9, 0x1E, 0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0xA6, 0x1E, 0x00, 0x00, 0xB7, 0x1E, 0x00, 0x00, 0xC8, 0x1E, 0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0xA5, 0x1E, 0x00, 0x00, 0xB6, 0x1E, 0x00, 0x00, 0xC7, 0x1E, 0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0xA4, 0x1E, 0x00, 0x00, 0xB5, 0x1E, 0x00, 0x00, 0xC6, 0x1E, 0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0xA3, 0x1E, 0x00, 0x00, 0xB4, 0x1E, 0x00, 0x00, 0xC5, 0x1E, 0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0xA2, 0x1E, 0x00, 0x00, 0xB3, 0x1E, 0x00, 0x00, 0xC4, 0x1E, 0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0xA1, 0x1E, 0x00, 0x00, 0xB2, 0x1E, 0x00, 0x00, 0xC3, 0x1E, 0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0xA0, 0x1E, 0x00, 0x00, 0xB1, 0x1E, 0x00, 0x00, 0xC2, 0x1E, 0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0x9F, 0x1E, 0x00, 0x00, 0xB0, 0x1E, 0x00, 0x00, 0xC1, 0x1E, 0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0x9E, 0x1E, 0x00, 0x00, 0xAF, 0x1E, 0x00, 0x00, 0xC0, 0x1E, 0x00, 0x00, 0x40, 0x00,
};

u8 D_002666A0[16] = {
    0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x10, 0x08, 0x00,
};

u8 D_002666B0[32] = {
    0x01, 0xA0, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02,
    0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x0C, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 D_0028DA38[8] = { 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00 };

u8 D_0028DA40[8] = { 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00 };

u8 D_0028DA48[8] = { 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00 };

u8 D_0028DA50[8] = { 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00 };

u8 D_0028DA58[8] = { 0x00, 0x50, 0x00, 0x2A, 0x00, 0x50, 0x00, 0x0E };
