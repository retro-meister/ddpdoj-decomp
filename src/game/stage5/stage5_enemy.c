#include "common.h"
#include "arcade_gameplay.h"
#include "entity.h"
#include "explosion.h"
#include "enemy.h"

/*
 * What the enemies of stage 5 keep in the enemy state block (reg_a5), after what every enemy has (EnemyState).
 * A pair named interval/countdown or shots/shots_left is a value and the counter loaded from it; where the two
 * are set with one store they are a union with `both`.
 */
#define STAGE5_ENEMY_HEAD(first) \
    /* 0x00 */ u8 common[0x16]; \
    /* 0x16 */ u8 first; \
    /* 0x17 */ u8 seen;               /* it has been on the screen; when it is off it again it is removed */ \
    /* 0x18 */ u8 hit_palette;        /* mixed into the palette on the frame of a hit */ \
    /* 0x19 */ u8 palette;

/* The small turret: it opens, fires bursts in the direction it took when it opened, and shuts. */
typedef struct {
    STAGE5_ENEMY_HEAD(phase)          /* 0: waiting, 1: opening, 2: firing, 3: shutting, 4: shut for good */
    /* 0x1A */ u8 wait;
    /* 0x1B */ u8 wait_countdown;
    /* 0x1C */ u8 frame_interval;
    /* 0x1D */ u8 frame_countdown;
    /* 0x1E */ u16 frame;             /* byte offset into its pictures, 0 to 0x1C */
    /* 0x20 */ union { s16 both; struct { u8 interval; u8 countdown; } b; } pause;
    /* 0x22 */ union { s16 both; struct { u8 interval; u8 countdown; } b; } shot;
    /* 0x24 */ union { s16 both; struct { u8 shots; u8 shots_left; } b; } burst;
    /* 0x26 */ u8 other_26;
    /* 0x27 */ u8 fire_dir;
} SmallTurretState;

#define SMALL_TURRET(pointer) ((SmallTurretState *)(pointer))

/* The bee hatch: it opens and lets a number of bee drones out. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 phase;
    /* 0x17 */ u8 seen;
    /* 0x18 */ u8 other_18;
    /* 0x19 */ u8 wait_countdown;     /* set from the scroll line it started at */
    /* 0x1A */ u8 frame_interval;
    /* 0x1B */ u8 frame_countdown;
    /* 0x1C */ u16 frame;
    /* 0x1E */ union { s16 both; struct { u8 interval; u8 countdown; } b; } release;
    /* 0x20 */ u16 bees_left;
    /* 0x22 */ u16 start_line;
} BeeHatchState;

#define BEE_HATCH(pointer) ((BeeHatchState *)(pointer))

/* The turret of the small and of the large spider: bursts whose direction steps on with every shot. */
typedef struct {
    STAGE5_ENEMY_HEAD(mirrored)
    /* 0x1A */ u8 frame_interval;
    /* 0x1B */ u8 frame_countdown;
    /* 0x1C */ u16 frame;
    /* 0x1E */ u8 pause;
    /* 0x1F */ u8 pause_countdown;
    /* 0x20 */ u8 start_dir;
    /* 0x21 */ u8 fire_dir;
    /* 0x22 */ u8 other_22;
    /* 0x23 */ u8 dir_step;
    /* 0x24 */ u8 shots;
    /* 0x25 */ u8 shots_left;
    /* 0x26 */ u8 shot_interval;
    /* 0x27 */ u8 shot_countdown;
} SpiderTurretState;

#define SPIDER_TURRET(pointer) ((SpiderTurretState *)(pointer))

/* The heads of the two spiders fire along a table of directions. `owner_flag` is the address of a word that
   the head sets at its start; what reads it is not identified. */
typedef struct {
    STAGE5_ENEMY_HEAD(mirrored)
    /* 0x1A */ u8 shot_interval;
    /* 0x1B */ u8 shot_countdown;
    /* 0x1C */ u16 step;              /* byte offset into its table of directions */
    /* 0x1E */ u8 other_1E[2];
    /* 0x20 */ u16 owner_flag[2];
} SmallSpiderHeadState;

#define SMALL_SPIDER_HEAD(pointer) ((SmallSpiderHeadState *)(pointer))

typedef struct {
    STAGE5_ENEMY_HEAD(mirrored)
    /* 0x1A */ union { s16 both; struct { u8 interval; u8 countdown; } b; } shot;
    /* 0x1C */ u16 step;
    /* 0x1E */ u8 other_1E[5];
    /* 0x23 */ u8 shots_left;
    /* 0x24 */ u8 side;               /* 0 or 1, changes with every shot */
    /* 0x25 */ u8 other_25;
    /* 0x26 */ u16 owner_flag[2];
} LargeSpiderHeadState;

#define LARGE_SPIDER_HEAD(pointer) ((LargeSpiderHeadState *)(pointer))

/*
 * The spiderling and the bee drone are started by another enemy, which leaves their position and more in the
 * first words; the start routine takes them and then loads the block from its table.
 */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct { u16 y; u16 x; u16 move; u16 misc; } at_start;
        struct {
            u8 phase;                 /* 0: slowing down, 1: waiting, 2: chasing the player */
            u8 seen;
            u8 hit_palette;
            u8 palette;
            u8 pause;
            u8 pause_countdown;
            u8 frame_interval;
            u8 frame_countdown;
        } now;
    };
    /* 0x1E */ u16 frame;             /* 0 or 4 */
    /* 0x20 */ u8 slow_interval;
    /* 0x21 */ u8 slow_countdown;
    /* 0x22 */ u16 unread_22;         /* set, not read here */
    /* 0x24 */ u16 wait_frames;
    /* 0x26 */ u16 legs;              /* byte offset into the pictures of its legs unfolding */
    /* 0x28 */ u8 shot_interval;
    /* 0x29 */ u8 shot_countdown;
    /* 0x2A */ u8 shots;
    /* 0x2B */ u8 shots_left;
    /* 0x2C */ u8 other_2C;
    /* 0x2D */ u8 fire_dir;
} SpiderlingState;

#define SPIDERLING(pointer) ((SpiderlingState *)(pointer))

typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct { u16 y; u16 x; u16 word_1A; u16 word_1C; } at_start;
        struct {
            u8 phase;                 /* 0: coming out, 1: out, 2: unfolding, 3: firing */
            u8 seen;
            u8 hit_palette;
            u8 palette;
            u8 other_1A[2];
            u8 frame_interval;
            u8 frame_countdown;
        } now;
    };
    /* 0x1E */ u16 frame;
    /* 0x20 */ u16 unread_20;         /* the four `unread` fields are set and not read here */
    /* 0x22 */ u16 unread_22;
    /* 0x24 */ u16 unread_24;
    /* 0x26 */ union { s16 both; struct { u8 pause; u8 countdown; } b; } shot;
    /* 0x28 */ u8 unread_28;
    /* 0x29 */ u8 fire_dir;
    /* 0x2A */ u16 sway;              /* what its swaying adds to y this frame */
    /* 0x2C */ u8 other_2C;
    /* 0x2D */ u8 sway_angle;
    /* 0x2E */ u8 shots;
    /* 0x2F */ u8 shots_left;
    /* 0x30 */ u16 shield_frames;     /* from at_start.word_1A: frames it cannot be hurt for once it is out */
    /* 0x32 */ u16 rise;              /* from at_start.word_1C: grows to 0x600 */
} BeeDroneState;

#define BEE_DRONE(pointer) ((BeeDroneState *)(pointer))

/* Two test objects that the second pad moves about. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 other_16[6];
    /* 0x1C */ u8 frame_interval;
    /* 0x1D */ u8 frame_countdown;
    /* 0x1E */ u16 frame;
} AnimTestState;

#define ANIM_TEST(pointer) ((AnimTestState *)(pointer))

void stage5_small_spider_turret_draw(void);
void spider_turret_unused(void);

extern u16 g_enemies_stopped;
s32 explosion_spawn();

void stage5_explosions_from_table(arg2)
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
        EXPLOSION(reg_a0)->draw_layer = 4;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0;
        EXPLOSION(reg_a0)->move.h = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        goto loop_1;
    }
}


void stage5_small_turret_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern u8 stage5_small_turret_start_table[];
extern u8 stage5_small_turret_start_table_2[];
extern s16 g_bullet_limit_raised_1[];
extern s8 enemy_move_end_requested;

void stage5_small_turret_start(void)
{
    reg_a0 = stage5_small_turret_start_table_2;
    enemy_init_entities();

    reg_a0 = stage5_small_turret_start_table;
    reg_d0.w = 8;
    enemy_set_task_state();
    enemy_path_start();

    if (enemy_move_end_requested == 0) {
        ENTITY(reg_a6)->attr.b.palette = SMALL_TURRET(reg_a5)->palette;
        g_bullet_limit_raised_1[0] = 1;
    }
}


s32 pickup_spawn_variant();
s32 bullet_fire_fast();
s32 sfx_explosion_air_small();
s32 score_add_no_chain();
s32 score_add();
s32 entity_follow_scroll();
s32 direction_to_target_player();
extern u8 stage5_small_turret_table[];

void stage5_small_turret(void) {
    u16 temp_a0;
    u16 temp_a1;

    if (ENTITY(reg_a6)->y.sh < -0x7FF) {
        enemy_remove();
        return;
    }
    entity_follow_scroll();
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        reg_d2.b[0] = SMALL_TURRET(reg_a5)->hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
        if (ENTITY(reg_a6)->hp.sh < 0) {
            reg_d0.w = 0x34;
            score_add();
            reg_d0.h[0] = 0x88;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = ENTITY(reg_a6)->y.h;
            temp_a1 = ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->x = temp_a1;
            EXPLOSION(reg_a0)->draw_layer = 4;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0;
            EXPLOSION(reg_a0)->follows_scroll = 2;
            sfx_explosion_air_small();
            reg_d1.w = 0;
            reg_d0.w = 8;
            reg_d2.w = 1;
            pickup_spawn_variant();
            enemy_remove();
            return;
        }
        goto block_6;
    }
    ENTITY(reg_a6)->attr.b.palette = (u8) SMALL_TURRET(reg_a5)->palette;
block_6:
    if (SMALL_TURRET(reg_a5)->phase == 0) {
        reg_tmp.b[0] = SMALL_TURRET(reg_a5)->wait_countdown;
        SMALL_TURRET(reg_a5)->wait_countdown -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            SMALL_TURRET(reg_a5)->wait_countdown = (u8) SMALL_TURRET(reg_a5)->wait;
            SMALL_TURRET(reg_a5)->phase = 1U;
        }
    }
    if (SMALL_TURRET(reg_a5)->phase == 1) {
        reg_tmp.b[0] = SMALL_TURRET(reg_a5)->frame_countdown;
        SMALL_TURRET(reg_a5)->frame_countdown -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            SMALL_TURRET(reg_a5)->frame_countdown = (u8) SMALL_TURRET(reg_a5)->frame_interval;
            SMALL_TURRET(reg_a5)->frame += 4;
            if ((s16) SMALL_TURRET(reg_a5)->frame >= 0x1C) {
                SMALL_TURRET(reg_a5)->frame = 0x1CU;
                direction_to_target_player();
                if (cond_flag == 0) {
                    reg_d1.b[0] += 2;
                    reg_d1.h[0] &= 0x3C;
                    SMALL_TURRET(reg_a5)->fire_dir = (u8) reg_d1.b[0];
                    SMALL_TURRET(reg_a5)->phase = 2U;
                    SMALL_TURRET(reg_a5)->pause.both = 0x808;
                    SMALL_TURRET(reg_a5)->shot.both = 3;
                    SMALL_TURRET(reg_a5)->burst.both = 3;
                }
            }
        }
    }
    if (SMALL_TURRET(reg_a5)->phase == 2) {
        if (ENTITY(reg_a6)->y.sh < 0x1400) {
            SMALL_TURRET(reg_a5)->phase = 3U;
        }
        if (SMALL_TURRET(reg_a5)->burst.b.shots_left == 0) {
            reg_tmp.b[0] = SMALL_TURRET(reg_a5)->pause.b.countdown;
            SMALL_TURRET(reg_a5)->pause.b.countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                SMALL_TURRET(reg_a5)->pause.b.countdown = SMALL_TURRET(reg_a5)->pause.b.interval;
                SMALL_TURRET(reg_a5)->burst.b.shots_left = SMALL_TURRET(reg_a5)->burst.b.shots;
                goto block_20;
            }
        } else {
block_20:
            reg_tmp.b[0] = SMALL_TURRET(reg_a5)->shot.b.countdown;
            SMALL_TURRET(reg_a5)->shot.b.countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                SMALL_TURRET(reg_a5)->shot.b.countdown = SMALL_TURRET(reg_a5)->shot.b.interval;
                reg_d0.w = 0xFFFE0006;
                reg_d1.w = 0;
                reg_d1.b[0] = SMALL_TURRET(reg_a5)->fire_dir;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d4.w = 0;
                reg_d3.w = 0;
                bullet_fire_fast();
                SMALL_TURRET(reg_a5)->burst.b.shots_left -= 1;
                if (SMALL_TURRET(reg_a5)->burst.b.shots_left == 0) {
                    reg_d1.b[0] = SMALL_TURRET(reg_a5)->fire_dir;
                    direction_to_target_player();
                    SMALL_TURRET(reg_a5)->fire_dir = (u8) reg_d1.b[0];
                }
            }
        }
    }
    if (SMALL_TURRET(reg_a5)->phase == 3) {
        reg_tmp.b[0] = SMALL_TURRET(reg_a5)->frame_countdown;
        SMALL_TURRET(reg_a5)->frame_countdown -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            SMALL_TURRET(reg_a5)->frame_countdown = (u8) SMALL_TURRET(reg_a5)->frame_interval;
            SMALL_TURRET(reg_a5)->frame -= 4;
            if (0 >= (s16) SMALL_TURRET(reg_a5)->frame) {
                SMALL_TURRET(reg_a5)->frame = 0U;
                SMALL_TURRET(reg_a5)->phase = 4U;
            }
        }
    }
    reg_a0 = (u8 *)stage5_small_turret_table;
    reg_a0 += SMALL_TURRET(reg_a5)->frame;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xFC00FC00;
    reg_d3.h[0] = 0x420;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer1();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

void stage5_bee_hatch_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

extern u8 stage5_bee_hatch_start_table[];
extern u8 stage5_bee_hatch_start_table_2[];
extern u16 g_scroll_line;

void stage5_bee_hatch_start(void) {
    reg_a0 = stage5_bee_hatch_start_table_2;
    enemy_init_entities();
    reg_a0 = stage5_bee_hatch_start_table;
    reg_d0.w = 6;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        BEE_HATCH(reg_a5)->start_line = (u16) g_scroll_line;
        if (g_scroll_line == 0xE6) {
            BEE_HATCH(reg_a5)->wait_countdown = 0x60;
        }
        if (g_scroll_line == 0xE4) {
            BEE_HATCH(reg_a5)->wait_countdown = 0xF0;
        }
        if (g_scroll_line == 0x108) {
            BEE_HATCH(reg_a5)->wait_countdown = 0x40;
        }
        if (g_scroll_line == 0x106) {
            BEE_HATCH(reg_a5)->wait_countdown = 0xF0;
        }
        if (g_scroll_line == 0x116) {
            BEE_HATCH(reg_a5)->wait_countdown = 0x80;
        }
    }
}

s32 spawn_request_add();
s32 rng_next_unsigned();
extern u8 stage5_bee_hatch_table[];

void stage5_bee_hatch(void) {
    s16 temp_v0;
    s16 temp_v0_2;
    u16 temp_a0;

    reg_d0.w = 0;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp.w = (u32) (s16) reg_d0.h[0];
    reg_d0.w = reg_tmp.w;
    reg_d0.w += 0x4000;
    if ((s32) reg_d0.w < 0x2001) {
        if (BEE_HATCH(reg_a5)->seen != 0) {
            enemy_remove();
            return;
        }
        goto block_4;
    }
    BEE_HATCH(reg_a5)->seen = 1U;
block_4:
    entity_follow_scroll();
    if (g_enemies_stopped == 0) {
        if ((BEE_HATCH(reg_a5)->phase == 0) && (BEE_HATCH(reg_a5)->seen != 0)) {
            temp_v0 = (s16) ENTITY(reg_a6)->y.h;
            if ((temp_v0 < 0x7000) && (temp_v0 > 0x5000)) {
                temp_v0_2 = ENTITY(reg_a6)->x.sh;
                if ((0 < temp_v0_2) && (temp_v0_2 < 0x3800)) {
                    reg_tmp.b[0] = BEE_HATCH(reg_a5)->wait_countdown;
                    BEE_HATCH(reg_a5)->wait_countdown -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        rng_next_unsigned();
                        reg_d0.h[0] &= 0x3F;
                        reg_d0.h[0] += 0x20;
                        BEE_HATCH(reg_a5)->wait_countdown = (u8) reg_d0.b[0];
                        BEE_HATCH(reg_a5)->phase = 1U;
                    }
                }
            }
        }
        if ((BEE_HATCH(reg_a5)->phase == 1) && ((BEE_HATCH(reg_a5)->frame != 0) || ((s16) ENTITY(reg_a6)->y.h > 0x3C00))) {
            reg_tmp.b[0] = BEE_HATCH(reg_a5)->frame_countdown;
            BEE_HATCH(reg_a5)->frame_countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                BEE_HATCH(reg_a5)->frame_countdown = (u8) BEE_HATCH(reg_a5)->frame_interval;
                BEE_HATCH(reg_a5)->frame += 4;
                if ((s16) BEE_HATCH(reg_a5)->frame >= 0x1C) {
                    BEE_HATCH(reg_a5)->frame = 0x1CU;
                    BEE_HATCH(reg_a5)->phase = 2U;
                    BEE_HATCH(reg_a5)->release.both = 0x28;
                    rng_next_unsigned();
                    reg_d0.h[0] &= 3;
                    reg_d0.h[0] += 2;
                    BEE_HATCH(reg_a5)->bees_left = (u16) reg_d0.h[0];
                }
            }
        }
        if (BEE_HATCH(reg_a5)->phase == 2) {
            reg_tmp.b[0] = BEE_HATCH(reg_a5)->release.b.countdown;
            BEE_HATCH(reg_a5)->release.b.countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                BEE_HATCH(reg_a5)->release.b.countdown = BEE_HATCH(reg_a5)->release.b.interval;
                reg_d0.w = 0x55;
                spawn_request_add();
                *(u16 *)(reg_a0 + 0x16) = (u16) ENTITY(reg_a6)->y.h;
                *(u16 *)(reg_a0 + 0x18) = ENTITY(reg_a6)->x.h;
                reg_tmp.w = (u32) reg_a5;
                *(u16 *)(reg_a0 + 0x1A) = (u16) reg_tmp.h[1];
                *(u16 *)(reg_a0 + 0x1C) = (u16) reg_tmp.h[0];
                BEE_HATCH(reg_a5)->phase = 4U;
                BEE_HATCH(reg_a5)->frame_countdown = 0x40U;
            }
        }
        if (BEE_HATCH(reg_a5)->phase == 3) {
            reg_tmp.b[0] = BEE_HATCH(reg_a5)->frame_countdown;
            BEE_HATCH(reg_a5)->frame_countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                BEE_HATCH(reg_a5)->frame_countdown = (u8) BEE_HATCH(reg_a5)->frame_interval;
                BEE_HATCH(reg_a5)->frame -= 4;
                if (0 >= (s16) BEE_HATCH(reg_a5)->frame) {
                    BEE_HATCH(reg_a5)->frame = 0U;
                    BEE_HATCH(reg_a5)->phase = 4U;
                }
            }
        }
    }
    reg_a0 = (u8 *)stage5_bee_hatch_table;
    reg_a0 += BEE_HATCH(reg_a5)->frame;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF000F000;
    reg_d3.h[0] = 0x1080;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer1();
}

void stage5_small_spider_turret_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(1);
}

extern u8 stage5_small_spider_turret_start_table[];
extern u8 stage5_small_spider_turret_start_table_2[];
extern s16 g_bullet_limit_raised_2[];

void stage5_small_spider_turret_start(void) {
    reg_a0 = stage5_small_spider_turret_start_table_2;
    enemy_init_entities();
    reg_a0 = stage5_small_spider_turret_start_table;
    reg_d0.w = 8;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if (g_scroll_line == 0x201) {
            ENTITY(reg_a6)->attr.sb.flip = 0x40;
            SPIDER_TURRET(reg_a5)->mirrored = 1;
        }
        g_bullet_limit_raised_1[0] = 1;
        g_bullet_limit_raised_2[0] = 1;
        ENTITY(reg_a6)->attr.b.palette = (u8) SPIDER_TURRET(reg_a5)->palette;
        rng_next_unsigned();
        SPIDER_TURRET(reg_a5)->fire_dir = (u8) reg_d0.b[0];
        rng_next_unsigned();
        SPIDER_TURRET(reg_a5)->start_dir = (u8) reg_d0.b[0];
    }
}

s32 bullet_fire256_double();
s32 sfx_explosion_ground_large();
extern u8 stage5_small_spider_turret_table[];
extern u8 stage5_small_spider_turret_table_2[4];
extern u8 stage5_small_spider_turret_table_3[4];

void stage5_small_spider_turret(void) {
    if (ENTITY(reg_a6)[1].misc.b.draw_layer == 0) {
        if (ENTITY(reg_a6)->y.sh > 0x2800) {
            reg_d1.w = 0x5C;
            reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
            if (reg_d1.b[0] != 0) {
                reg_d0.b[0] = 0xA3;
                ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
                score_add_no_chain();
                reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
                reg_d2.b[0] = SPIDER_TURRET(reg_a5)->hit_palette;
                reg_d0.b[0] ^= reg_d2.b[0];
                ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
                if (ENTITY(reg_a6)->hp.sh < 0) {
                    reg_d0.w = 0x230;
                    score_add();
                    goto block_5;
                }
            } else {
                goto block_6;
            }
        } else {
block_5:
            ENTITY(reg_a6)->flags.h = 0x8000;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a1 = (u8 *)stage5_small_spider_turret_table;
            stage5_explosions_from_table();
            sfx_explosion_ground_large();
            ENTITY(reg_a6)[1].misc.b.draw_layer = 1U;
            goto block_6;
        }
    } else {
block_6:
        ENTITY(reg_a6)->attr.b.palette = (u8) SPIDER_TURRET(reg_a5)->palette;
    }
    reg_d0.w = 0;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp.w = (u32) (s16) reg_d0.h[0];
    reg_d0.w = reg_tmp.w;
    reg_d0.w += 0x4000;
    if ((s32) reg_d0.w < 0x2C01) {
        if (SPIDER_TURRET(reg_a5)->seen != 0) {
            enemy_remove();
            return;
        }
        goto block_11;
    }
    SPIDER_TURRET(reg_a5)->seen = 1U;
block_11:
    entity_follow_scroll();
    spider_turret_unused();
    if (ENTITY(reg_a6)[1].misc.b.draw_layer == 0) {
        if (SPIDER_TURRET(reg_a5)->shots_left == 0) {
            reg_tmp.b[0] = SPIDER_TURRET(reg_a5)->pause_countdown;
            SPIDER_TURRET(reg_a5)->pause_countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                SPIDER_TURRET(reg_a5)->pause_countdown = (u8) SPIDER_TURRET(reg_a5)->pause;
                SPIDER_TURRET(reg_a5)->shots_left = (u8) SPIDER_TURRET(reg_a5)->shots;
                goto block_15;
            }
        } else {
block_15:
            reg_a1 = stage5_small_spider_turret_table_2;
            if (SPIDER_TURRET(reg_a5)->mirrored == 0) {
                reg_a1 = stage5_small_spider_turret_table_3;
            }
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.h[0] += *(u16 *)reg_a1;
            reg_d1.h[0] += *(u16 *)(reg_a1 + 2);
            aim256_at_player();
            if (cond_flag == 0) {
                SPIDER_TURRET(reg_a5)->fire_dir = (u8) reg_d1.b[0];
                reg_tmp.b[0] = SPIDER_TURRET(reg_a5)->shot_countdown;
                SPIDER_TURRET(reg_a5)->shot_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    SPIDER_TURRET(reg_a5)->shot_countdown = (u8) SPIDER_TURRET(reg_a5)->shot_interval;
                    reg_d1.w = 0;
                    reg_d1.b[0] = SPIDER_TURRET(reg_a5)->fire_dir;
                    reg_d0.w = 0xFFFE000B;
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    reg_a1 = stage5_small_spider_turret_table_2;
                    if (SPIDER_TURRET(reg_a5)->mirrored == 0) {
                        reg_a1 = stage5_small_spider_turret_table_3;
                    }
                    reg_tmp.h[1] = *(u16 *)reg_a1;
                    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                    reg_d2.w += reg_tmp.w;
                    reg_d1.h[0] -= 0xA;
                    reg_d7.h[0] = 4;
                    reg_d4.w = 0;
                    reg_d3.w = 0;
                    do {
                        bullet_fire256_double();
                        reg_d1.b[0] += 5;
                    } while ((s16)(--reg_d7.h[0]) >= 0);
                    reg_d0.b[0] = SPIDER_TURRET(reg_a5)->dir_step;
                    SPIDER_TURRET(reg_a5)->fire_dir += reg_d0.b[0];
                    SPIDER_TURRET(reg_a5)->shots_left -= 1;
                }
            }
        }
    }
    reg_tmp.b[0] = SPIDER_TURRET(reg_a5)->frame_countdown;
    SPIDER_TURRET(reg_a5)->frame_countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        SPIDER_TURRET(reg_a5)->frame_countdown = (u8) SPIDER_TURRET(reg_a5)->frame_interval;
        SPIDER_TURRET(reg_a5)->frame += 4;
        SPIDER_TURRET(reg_a5)->frame &= 0x1F;
    }
    if (ENTITY(reg_a6)[1].misc.b.draw_layer == 0) {
        stage5_small_spider_turret_draw();
    }
}

extern u8 stage5_small_spider_turret_draw_table[];

void stage5_small_spider_turret_draw(void) {
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = stage5_small_spider_turret_draw_table;
    reg_a0 += SPIDER_TURRET(reg_a5)->frame;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xF600F600;
    reg_d4.w = 0;
    reg_d3.h[0] = 0xA50;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    sprite_draw_layer1();
}

void spider_turret_unused(void) {
}

void stage5_small_spider_head_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern s16 stage5_small_spider_head_start_table[];
extern s16 stage5_small_spider_head_start_table_2[];
extern u16 g_enemy_signal_6;
extern u16 g_enemy_signal_4;

void stage5_small_spider_head_start(void) {
    reg_a0 = (u8 *)(stage5_small_spider_head_start_table_2);
    enemy_init_entities();
    reg_a0 = (u8 *)(stage5_small_spider_head_start_table);
    reg_d0.w = 6;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested != 0) return;
    if (g_scroll_line != 0x1F3) goto next_1;
    ENTITY(reg_a6)->attr.sb.flip = 0x40;
    SMALL_SPIDER_HEAD(reg_a5)->mirrored = 1;
next_1:
    ENTITY(reg_a6)->attr.b.palette = SMALL_SPIDER_HEAD(reg_a5)->palette;
    g_bullet_limit_raised_1[0] = 1;
    g_bullet_limit_raised_2[0] = 1;
    reg_a0 = (u8 *)(&(*(s16 *)&g_enemy_signal_4));
    if ((s32) g_scroll_line < 0x260) goto next_2;
    reg_a0 = (u8 *)(&(*(s16 *)&g_enemy_signal_6));
next_2:
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a0);
    SMALL_SPIDER_HEAD(reg_a5)->owner_flag[0] = reg_tmp.h[1];
    SMALL_SPIDER_HEAD(reg_a5)->owner_flag[1] = reg_tmp.h[0];
    *(s16 *)reg_a0 = 1;
}

s32 bullet_fire256_2way();
extern u8 stage5_small_spider_head_table[];
extern u8 stage5_small_spider_head_table_2[];
extern u8 stage5_small_spider_head_table_3[];
extern u8 stage5_small_spider_head_table_4[];
extern u8 stage5_small_spider_head_table_5[];
extern u16 g_bullets_blocked;

void stage5_small_spider_head(void) {
    u16 temp_a0;
    u16 temp_v1;
    u32 temp_v0;
    u8 *var_a0;

    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    var_a0 = (u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        var_a0 = (u8 *)(reg_a6);
        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x1C)));
        reg_d2.b[0] = SMALL_SPIDER_HEAD(reg_a5)->hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        (*(u8 *)((u8 *)(var_a0) + (0x1C))) = (u8) reg_d0.b[0];
        if (ENTITY(reg_a6)->hp.sh < 0) {
            reg_d0.w = 0x350;
            score_add();
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a1 = (u8 *)stage5_small_spider_head_table_5;
            stage5_explosions_from_table();
            sfx_explosion_ground_large();
            reg_tmp.h[1] = SMALL_SPIDER_HEAD(reg_a5)->owner_flag[0];
            reg_tmp.h[0] = SMALL_SPIDER_HEAD(reg_a5)->owner_flag[1];
            reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
            *(u16 *)reg_a0 = 0U;
            enemy_remove();
            return;
        }
        goto block_4;
    }
    ENTITY(reg_a6)->attr.b.palette = (u8) SMALL_SPIDER_HEAD(reg_a5)->palette;
block_4:
    reg_d0.w = 0;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp.w = (u32) (s16) reg_d0.h[0];
    reg_d0.w = reg_tmp.w;
    reg_d0.w += 0x4000;
    if ((s32) reg_d0.w < 0x2001) {
        if (SMALL_SPIDER_HEAD(reg_a5)->seen != 0) {
            reg_tmp.h[1] = SMALL_SPIDER_HEAD(reg_a5)->owner_flag[0];
            reg_tmp.h[0] = SMALL_SPIDER_HEAD(reg_a5)->owner_flag[1];
            reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
            *(u16 *)reg_a0 = 0U;
            enemy_remove();
            return;
        }
        goto block_8;
    }
    SMALL_SPIDER_HEAD(reg_a5)->seen = 1U;
block_8:
    entity_follow_scroll();
    reg_tmp.b[0] = SMALL_SPIDER_HEAD(reg_a5)->shot_countdown;
    SMALL_SPIDER_HEAD(reg_a5)->shot_countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        SMALL_SPIDER_HEAD(reg_a5)->shot_countdown = (u8) SMALL_SPIDER_HEAD(reg_a5)->shot_interval;
        if (g_bullets_blocked == 0) {
            reg_a1 = (u8 *)stage5_small_spider_head_table_4;
            if (SMALL_SPIDER_HEAD(reg_a5)->mirrored != 0) {
                reg_a1 = (u8 *)stage5_small_spider_head_table_3;
            }
            reg_d0.h[0] = SMALL_SPIDER_HEAD(reg_a5)->step;
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
            reg_a1 += reg_d0.h[0];
            temp_v1 = *(u16 *)reg_a1;
            reg_a1 = (u8 *)stage5_small_spider_head_table_2;
            reg_d1.h[0] = temp_v1;
            reg_a1 += SMALL_SPIDER_HEAD(reg_a5)->step;
            reg_d3.h[1] = *(u16 *)reg_a1;
            reg_d3.h[0] = *(u16 *)(reg_a1 + 2);
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            if (SMALL_SPIDER_HEAD(reg_a5)->mirrored != 0) {
                reg_d3.h[0] *= 0xFFFF;
            }
            reg_d0.w = 4;
            reg_d4.w = 0;
            temp_v0 = reg_d2.w + reg_d3.w;
            reg_d3.w = 0;
            reg_d2.w = temp_v0;
            bullet_fire256_fixed();
            reg_d0.w = 0xFFFC0005;
            bullet_fire256_2way();
            if ((s32) g_scroll_line >= 0x268) {
                reg_d0.w = 0x40003;
                bullet_fire256_double();
            }
        }
        SMALL_SPIDER_HEAD(reg_a5)->step += 4;
        if ((s16) SMALL_SPIDER_HEAD(reg_a5)->step >= 0x78) {
            SMALL_SPIDER_HEAD(reg_a5)->step = 0U;
        }
    }
    reg_a0 = (unsigned char *)reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = (unsigned char *)stage5_small_spider_head_table;
    reg_a0 += SMALL_SPIDER_HEAD(reg_a5)->step;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_d4.w = 0;
    reg_d1.w += 0xF000F600;
    reg_d3.h[0] = 0x1050;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    sprite_draw_layer1();
}

void stage5_large_spider_turret_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(1);
}

extern u8 stage5_large_spider_turret_start_table[];
extern u8 stage5_large_spider_turret_start_table_2[];

void stage5_large_spider_turret_start(void) {
    reg_a0 = stage5_large_spider_turret_start_table_2;
    enemy_init_entities();
    reg_a0 = stage5_large_spider_turret_start_table;
    reg_d0.w = 8;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if (g_scroll_line == 0x2B6) {
            ENTITY(reg_a6)->attr.sb.flip = 0x40;
            SPIDER_TURRET(reg_a5)->mirrored = 1;
        }
        g_bullet_limit_raised_1[0] = 1;
        g_bullet_limit_raised_2[0] = 1;
        ENTITY(reg_a6)->attr.b.palette = (u8) SPIDER_TURRET(reg_a5)->palette;
        rng_next_unsigned();
        SPIDER_TURRET(reg_a5)->fire_dir = (u8) reg_d0.b[0];
        rng_next_unsigned();
        SPIDER_TURRET(reg_a5)->start_dir = (u8) reg_d0.b[0];
    }
}

extern u8 stage5_large_spider_turret_table[];
extern u8 stage5_large_spider_turret_table_2[];
extern u8 stage5_large_spider_turret_table_3[4];
extern u8 stage5_large_spider_turret_table_4[4];

void stage5_large_spider_turret(void) {
    u32 temp_a0_3;
    u8 var_a0;

    if (ENTITY(reg_a6)[1].misc.b.draw_layer == 0) {
        if (ENTITY(reg_a6)->y.sh < 0x2801) {
            if (SPIDER_TURRET(reg_a5)->seen == 0) {
                goto block_4;
            }
            goto block_7;
        }
block_4:
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
            score_add_no_chain();
            reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
            reg_d2.b[0] = SPIDER_TURRET(reg_a5)->hit_palette;
            reg_d0.b[0] ^= reg_d2.b[0];
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            if (ENTITY(reg_a6)->hp.sh < 0) {
                reg_d0.w = 0x280;
                score_add();
block_7:
                ENTITY(reg_a6)->flags.h = 0x8000;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_a1 = (u8 *)stage5_large_spider_turret_table_2;
                stage5_explosions_from_table();
                sfx_explosion_ground_large();
                ENTITY(reg_a6)[1].misc.b.draw_layer = 1U;
                goto block_8;
            }
        } else {
            goto block_8;
        }
    } else {
block_8:
        var_a0 = SPIDER_TURRET(reg_a5)->palette;
        ENTITY(reg_a6)->attr.b.palette = var_a0;
    }
    reg_d0.w = 0;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp.w = (u32) (s16) reg_d0.h[0];
    reg_d0.w = reg_tmp.w;
    reg_d0.w += 0x4000;
    if ((s32) reg_d0.w < 0x1C01) {
        if (SPIDER_TURRET(reg_a5)->seen != 0) {
            enemy_remove();
            return;
        }
        goto block_13;
    }
    var_a0 = 1;
    SPIDER_TURRET(reg_a5)->seen = 1U;
block_13:
    if (g_enemies_stopped == 0) {
        entity_follow_scroll();
        spider_turret_unused();
        if (ENTITY(reg_a6)[1].misc.b.draw_layer == 0) {
            if (SPIDER_TURRET(reg_a5)->shots_left == 0) {
                reg_tmp.b[0] = SPIDER_TURRET(reg_a5)->pause_countdown;
                SPIDER_TURRET(reg_a5)->pause_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    SPIDER_TURRET(reg_a5)->pause_countdown = (u8) SPIDER_TURRET(reg_a5)->pause;
                    SPIDER_TURRET(reg_a5)->shots_left = (u8) SPIDER_TURRET(reg_a5)->shots;
                    goto block_18;
                }
            } else {
block_18:
                reg_a1 = stage5_large_spider_turret_table_3;
                if (SPIDER_TURRET(reg_a5)->mirrored == 0) {
                    reg_a1 = stage5_large_spider_turret_table_4;
                }
                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d0.h[0] += *(u16 *)reg_a1;
                reg_d1.h[0] += *(u16 *)(reg_a1 + 2);
                aim256_at_player();
                SPIDER_TURRET(reg_a5)->fire_dir = (u8) reg_d1.b[0];
                reg_tmp.b[0] = SPIDER_TURRET(reg_a5)->shot_countdown;
                SPIDER_TURRET(reg_a5)->shot_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    SPIDER_TURRET(reg_a5)->shot_countdown = (u8) SPIDER_TURRET(reg_a5)->shot_interval;
                    reg_d1.w = 0;
                    reg_d1.b[0] = SPIDER_TURRET(reg_a5)->fire_dir;
                    reg_d0.w = 0xFFFF000B;
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    reg_a1 = stage5_large_spider_turret_table_3;
                    if (SPIDER_TURRET(reg_a5)->mirrored == 0) {
                        reg_a1 = stage5_large_spider_turret_table_4;
                    }
                    reg_tmp.h[1] = *(u16 *)reg_a1;
                    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                    reg_d2.w += reg_tmp.w;
                    reg_d1.h[0] -= 9;
                    reg_d7.h[0] = 6;
                    reg_d4.w = 0;
                    reg_d3.w = 0;
                    do {
                        bullet_fire256_2way();
                        reg_d1.b[0] += 3;
                    } while ((s16)(--reg_d7.h[0]) >= 0);
                    reg_d0.b[0] = SPIDER_TURRET(reg_a5)->dir_step;
                    SPIDER_TURRET(reg_a5)->fire_dir += reg_d0.b[0];
                    SPIDER_TURRET(reg_a5)->shots_left -= 1;
                }
            }
        }
        reg_tmp.b[0] = SPIDER_TURRET(reg_a5)->frame_countdown;
        SPIDER_TURRET(reg_a5)->frame_countdown -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            SPIDER_TURRET(reg_a5)->frame_countdown = (u8) SPIDER_TURRET(reg_a5)->frame_interval;
            SPIDER_TURRET(reg_a5)->frame += 4;
            SPIDER_TURRET(reg_a5)->frame &= 0x1F;
        }
    }
    if (ENTITY(reg_a6)[1].misc.b.draw_layer == 0) {
        reg_a0 = (u8 *)stage5_large_spider_turret_table;
        reg_a0 += SPIDER_TURRET(reg_a5)->frame;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a0_3 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a0_3;
        reg_d1.w += 0xEE00EC00;
        reg_d3.h[0] = 0x12A0;
        reg_d4.w = 0;
        reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
        sprite_draw_layer1();
        reg_a0 = reg_a6;
        enemy_hitbox_debug_draw();
    }
}

void stage5_large_spider_head_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

extern s16 stage5_large_spider_head_start_table[];
extern s16 stage5_large_spider_head_start_table_2[];
extern u16 g_enemy_signal_7;
extern u16 g_enemy_signal_5;

void stage5_large_spider_head_start(void) {
    reg_a0 = (u8 *)(stage5_large_spider_head_start_table_2);
    enemy_init_entities();
    reg_a0 = (u8 *)(stage5_large_spider_head_start_table);
    reg_d0.w = 9;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested != 0) return;
    if (g_scroll_line != 0x299) goto next_1;
    ENTITY(reg_a6)->attr.sb.flip = 0x40;
    LARGE_SPIDER_HEAD(reg_a5)->mirrored = 1;
next_1:
    ENTITY(reg_a6)->attr.b.palette = LARGE_SPIDER_HEAD(reg_a5)->palette;
    g_bullet_limit_raised_1[0] = 1;
    g_bullet_limit_raised_2[0] = 1;
    g_enemy_signal_5 = 1;
    reg_a0 = (u8 *)(&(*(s16 *)&g_enemy_signal_5));
    if ((s32) g_scroll_line < 0x280) goto next_2;
    reg_a0 = (u8 *)(&(*(s16 *)&g_enemy_signal_7));
    LARGE_SPIDER_HEAD(reg_a5)->shot.both = 0x202;
next_2:
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a0);
    LARGE_SPIDER_HEAD(reg_a5)->owner_flag[0] = reg_tmp.h[1];
    LARGE_SPIDER_HEAD(reg_a5)->owner_flag[1] = reg_tmp.h[0];
    *(s16 *)reg_a0 = 1;
}

extern u8 stage5_large_spider_head_table[];
extern u8 stage5_large_spider_head_table_2[];
extern u8 stage5_large_spider_head_table_3[];
extern u8 stage5_large_spider_head_table_4[];
extern u8 stage5_large_spider_head_table_5[];

void stage5_large_spider_head(void) {
    u8 *temp_a1;
    s16 temp_a2;
    u16 temp_a0;
    u8 *var_a0;

    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    var_a0 = (u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        var_a0 = (u8 *)(reg_a6);
        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x1C)));
        reg_d2.b[0] = LARGE_SPIDER_HEAD(reg_a5)->hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        (*(u8 *)((u8 *)(var_a0) + (0x1C))) = (u8) reg_d0.b[0];
        if (ENTITY(reg_a6)->hp.sh < 0) {
            reg_d0.w = 0x390;
            score_add();
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a1 = (u8 *)stage5_large_spider_head_table_2;
            stage5_explosions_from_table();
            sfx_explosion_ground_large();
            reg_tmp.h[1] = LARGE_SPIDER_HEAD(reg_a5)->owner_flag[0];
            reg_tmp.h[0] = LARGE_SPIDER_HEAD(reg_a5)->owner_flag[1];
            reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
            *(u16 *)reg_a0 = 0U;
            enemy_remove();
            return;
        }
        goto block_4;
    }
    ENTITY(reg_a6)->attr.b.palette = (u8) LARGE_SPIDER_HEAD(reg_a5)->palette;
block_4:
    reg_d0.w = 0;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp.w = (u32) (s16) reg_d0.h[0];
    reg_d0.w = reg_tmp.w;
    reg_d0.w += 0x4000;
    if ((s32) reg_d0.w < 0x401) {
        if (LARGE_SPIDER_HEAD(reg_a5)->seen != 0) {
            reg_tmp.h[1] = LARGE_SPIDER_HEAD(reg_a5)->owner_flag[0];
            reg_tmp.h[0] = LARGE_SPIDER_HEAD(reg_a5)->owner_flag[1];
            reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
            *(u16 *)reg_a0 = 0U;
            enemy_remove();
            return;
        }
        goto block_8;
    }
    LARGE_SPIDER_HEAD(reg_a5)->seen = 1U;
block_8:
    if (g_enemies_stopped == 0) {
        entity_follow_scroll();
        reg_tmp.b[0] = LARGE_SPIDER_HEAD(reg_a5)->shot.b.countdown;
        LARGE_SPIDER_HEAD(reg_a5)->shot.b.countdown -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            LARGE_SPIDER_HEAD(reg_a5)->shot.b.countdown = (u8) LARGE_SPIDER_HEAD(reg_a5)->shot.b.interval;
            LARGE_SPIDER_HEAD(reg_a5)->step += 4;
            if ((s16) LARGE_SPIDER_HEAD(reg_a5)->step >= 0x78) {
                LARGE_SPIDER_HEAD(reg_a5)->step = 0U;
            }
            reg_a1 = (u8 *)stage5_large_spider_head_table_3;
            reg_a1 += LARGE_SPIDER_HEAD(reg_a5)->step;
            reg_d3.h[1] = *(u16 *)reg_a1;
            reg_d3.h[0] = *(u16 *)(reg_a1 + 2);
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a1 = (u8 *)stage5_large_spider_head_table_4;
            if (LARGE_SPIDER_HEAD(reg_a5)->mirrored != 0) {
                reg_a1 = (u8 *)stage5_large_spider_head_table_5;
                reg_d3.h[0] *= 0xFFFF;
            }
            temp_a1 = (u8 *)(reg_a1);
            reg_d0.h[0] = LARGE_SPIDER_HEAD(reg_a5)->step;
            temp_a2 = (s16) reg_d0.h[0];
            reg_d0.h[0] = (u16) (temp_a2 >> 1);
            reg_a1 = temp_a1 + reg_d0.h[0];
            temp_a0 = *(u16 *)reg_a1;
            reg_d1.h[0] = temp_a0;
            reg_d2.w += reg_d3.w;
            reg_d0.w = 0x10003;
            reg_d4.w = 0;
            reg_d3.w = 0;
            bullet_fire256_double();
            reg_d0.w = 0xFFFD0004;
            reg_d1.h[0] += 2;
            bullet_fire256_fixed();
            reg_d1.h[0] -= 4;
            bullet_fire256_fixed();
            reg_d1.h[0] += 3;
            reg_d0.w = 0xFFF90005;
            bullet_fire256_fixed();
            LARGE_SPIDER_HEAD(reg_a5)->side += 1;
            LARGE_SPIDER_HEAD(reg_a5)->side &= 1;
            LARGE_SPIDER_HEAD(reg_a5)->shots_left -= 1;
        }
    }
    reg_a0 = (unsigned char *)stage5_large_spider_head_table;
    reg_a0 += LARGE_SPIDER_HEAD(reg_a5)->step;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.w = 0;
    reg_d1.w += 0xE200EA00;
    reg_d3.h[0] = 0x1EB0;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    sprite_draw_layer1();
    reg_a0 = (unsigned char *)reg_a6;
    enemy_hitbox_debug_draw();
}

void stage5_spiderling_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 sprite_palette_load();
extern u8 stage5_spiderling_start_table[];
extern u8 stage5_spiderling_start_table_2[];
extern u8 stage5_spiderling_start_table_3[];

void stage5_spiderling_start(void) {
    reg_a0 = stage5_spiderling_start_table_3;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) SPIDERLING(reg_a5)->at_start.y;
    ENTITY(reg_a6)->x.h = (u16) SPIDERLING(reg_a5)->at_start.x;
    ENTITY(reg_a6)->move.h = (u16) SPIDERLING(reg_a5)->at_start.move;
    ENTITY(reg_a6)->misc.h = (u16) SPIDERLING(reg_a5)->at_start.misc;
    ENTITY(reg_a6)->misc.h -= 1;
    reg_a0 = stage5_spiderling_start_table_2;
    reg_d0.w = 0xB;
    enemy_set_task_state();
    reg_d0.h[0] = 0x15;
    reg_a0 = stage5_spiderling_start_table;
    sprite_palette_load();
    ENTITY(reg_a6)->attr.b.palette = (u8) SPIDERLING(reg_a5)->now.palette;
}

s32 sprite_draw_layer5_zoom_keep();
s32 rng_next();
s32 rng_next_d5();
s32 entity_turn_to_target_player();
s32 entity_check_bounds();
extern u8 stage5_spiderling_table[];
extern u8 stage5_spiderling_table_2[8];
extern u16 g_frame_mod2;
extern u16 g_game_frame;

void stage5_spiderling(void) {
    u8 *var_a0;
    u16 temp_a0_2;
    u16 temp_a2;

    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    var_a0 = (u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        var_a0 = (u8 *)(reg_a6);
        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x1C)));
        reg_d2.b[0] = SPIDERLING(reg_a5)->now.hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        (*(u8 *)((u8 *)(var_a0) + (0x1C))) = (u8) reg_d0.b[0];
        if (ENTITY(reg_a6)->hp.sh < 0) {
            reg_d0.w = 0x10;
            score_add();
            direction256_to_target_player();
            if (cond_flag == 0) {
                reg_d0.w = 0xFFFC0006;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d4.w = 0;
                reg_d3.w = 0;
                bullet_fire256();
                rng_next_d5();
                reg_d1.b[0] += reg_d5.b[0];
                reg_d0.w += 0x30000;
                bullet_fire256();
            }
            reg_d0.h[0] = 1;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            temp_a0_2 = ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->x = temp_a0_2;
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->move.b.speed = (u8) ENTITY(reg_a6)->move.b.speed;
            reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d0.b[0] *= 4;
            EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
            sfx_explosion_air_small();
            enemy_remove();
            return;
        }
        goto block_6;
    }
    ENTITY(reg_a6)->attr.b.palette = (u8) SPIDERLING(reg_a5)->now.palette;
block_6:
    entity_check_bounds();
    if (cond_flag != 0) {
        if (SPIDERLING(reg_a5)->now.seen != 0) {
            enemy_remove();
            return;
        }
        goto block_10;
    }
    SPIDERLING(reg_a5)->now.seen = 1U;
block_10:
    if (g_enemies_stopped == 0) {
        entity_velocity();
        if (SPIDERLING(reg_a5)->now.phase == 0) {
            reg_tmp.b[0] = SPIDERLING(reg_a5)->slow_countdown;
            SPIDERLING(reg_a5)->slow_countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                SPIDERLING(reg_a5)->slow_countdown = (u8) SPIDERLING(reg_a5)->slow_interval;
                ENTITY(reg_a6)->move.b.speed -= 1;
                if ((s8) ENTITY(reg_a6)->move.b.speed < 3) {
                    SPIDERLING(reg_a5)->unread_22 = 0;
                    SPIDERLING(reg_a5)->now.phase = 1U;
                    SPIDERLING(reg_a5)->wait_frames = 0x40U;
                }
            }
        }
        if (SPIDERLING(reg_a5)->now.phase == 1) {
            SPIDERLING(reg_a5)->wait_frames -= 1;
            if (SPIDERLING(reg_a5)->wait_frames == 0) {
                SPIDERLING(reg_a5)->legs = 0x3CU;
                SPIDERLING(reg_a5)->now.phase = 2U;
                ENTITY(reg_a6)->move.b.speed = 0x18U;
                direction_to_target_player();
                if (cond_flag == 0) {
                    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                }
            }
        }
        if (SPIDERLING(reg_a5)->now.phase == 2) {
            entity_turn_to_target_player();
            ENTITY(reg_a6)->move.b.speed -= 1;
            if ((s8) ENTITY(reg_a6)->move.b.speed < 3) {
                ENTITY(reg_a6)->move.b.dir += 0x20;
                ENTITY(reg_a6)->move.b.dir &= 0x3F;
                SPIDERLING(reg_a5)->wait_frames = 0x40U;
                SPIDERLING(reg_a5)->now.phase = 1U;
            }
        }
        if (SPIDERLING(reg_a5)->shots_left == 0) {
            reg_tmp.b[0] = SPIDERLING(reg_a5)->now.pause_countdown;
            SPIDERLING(reg_a5)->now.pause_countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                SPIDERLING(reg_a5)->now.pause_countdown = (u8) SPIDERLING(reg_a5)->now.pause;
                SPIDERLING(reg_a5)->shots_left = (u8) SPIDERLING(reg_a5)->shots;
                SPIDERLING(reg_a5)->fire_dir = 0x20U;
                direction_to_target_player();
                if (cond_flag == 0) {
                    SPIDERLING(reg_a5)->fire_dir = (u8) reg_d1.b[0];
                    rng_next();
                    SPIDERLING(reg_a5)->fire_dir += reg_d0.b[0];
                    goto block_26;
                }
            }
        } else {
block_26:
            if (SPIDERLING(reg_a5)->now.phase != 2) {
                reg_tmp.b[0] = SPIDERLING(reg_a5)->shot_countdown;
                SPIDERLING(reg_a5)->shot_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    SPIDERLING(reg_a5)->shot_countdown = (u8) SPIDERLING(reg_a5)->shot_interval;
                    if (g_bullets_blocked == 0) {
                        reg_d1.w = 0;
                        reg_d1.b[0] = SPIDERLING(reg_a5)->fire_dir;
                        reg_d0.w = 0xFFFC0006;
                        reg_d1.b[0] &= 0x3F;
                        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d4.w = 0;
                        reg_d3.w = 0;
                        SPIDERLING(reg_a5)->shots_left -= 1;
                    }
                }
            }
        }
        reg_tmp.b[0] = SPIDERLING(reg_a5)->now.frame_countdown;
        SPIDERLING(reg_a5)->now.frame_countdown -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            SPIDERLING(reg_a5)->now.frame_countdown = (u8) SPIDERLING(reg_a5)->now.frame_interval;
            SPIDERLING(reg_a5)->frame += 4;
            SPIDERLING(reg_a5)->frame &= 7;
        }
        if (SPIDERLING(reg_a5)->legs != 0) {
            reg_d0.w = 1;
            reg_d0.h[0] &= g_game_frame;
            if (reg_d0.h[0] == 0) {
                SPIDERLING(reg_a5)->legs -= 4;
                if (0 >= (s16) SPIDERLING(reg_a5)->legs) {
                    SPIDERLING(reg_a5)->legs = 0U;
                }
            }
        }
    }
    reg_a0 = stage5_spiderling_table_2;
    reg_a0 += SPIDERLING(reg_a5)->frame;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a2 = ENTITY(reg_a6)->x.h;
    reg_d4.w = 0;
    reg_d1.h[0] = temp_a2;
    reg_d1.w += 0xFE00FE00;
    reg_d3.h[0] = 0x210;
    reg_d4.b[0] = 0x19;
    if (g_frame_mod2 != 0) {
        reg_a1 = (u8 *)stage5_spiderling_table;
        reg_a1 += SPIDERLING(reg_a5)->legs;
        reg_d6.h[1] = *(u16 *)reg_a1;
        reg_d6.h[0] = *(u16 *)(reg_a1 + 2);
        sprite_draw_layer5_zoom_keep();
    }
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer5();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

void stage5_bee_drone_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern u8 stage5_bee_drone_start_table[];
extern u8 stage5_bee_drone_start_table_2[];
extern u8 stage5_bee_drone_start_table_3[];

void stage5_bee_drone_start(void) {
    u16 temp_a0;
    u32 temp_a2;

    reg_a0 = stage5_bee_drone_start_table_3;
    enemy_init_entities();
    reg_d0.h[1] = BEE_DRONE(reg_a5)->at_start.y;
    reg_d0.h[0] = BEE_DRONE(reg_a5)->at_start.x;
    temp_a2 = reg_d0.w;
    reg_d0.w = temp_a2 + 0x02000000;
    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
    BEE_DRONE(reg_a5)->shield_frames = (u16) BEE_DRONE(reg_a5)->at_start.word_1A;
    temp_a0 = BEE_DRONE(reg_a5)->at_start.word_1C;
    BEE_DRONE(reg_a5)->rise = temp_a0;
    reg_a0 = stage5_bee_drone_start_table_2;
    reg_d0.w = 0xE;
    enemy_set_task_state();
    if ((s16) ENTITY(reg_a6)->y.h < 0x2801) {
        enemy_remove();
        return;
    }
    reg_d0.h[0] = 0x15;
    reg_a0 = stage5_bee_drone_start_table;
    sprite_palette_load();
}

s32 velocity_from_dir256();
extern u8 g_direction64_offsets_2CC[];
extern u8 stage5_bee_drone_table[];
extern u8 stage5_bee_drone_table_2[];

void stage5_bee_drone(void) {
    s64 temp_v0_10;
    s64 temp_v0_11;
    s64 temp_v0_3;
    s64 temp_v0_4;
    s64 temp_v0_5;
    s64 temp_v0_7;
    s64 temp_v0_8;
    s64 temp_v0_9;
    u16 temp_v0;
    if ((BEE_DRONE(reg_a5)->now.phase != 0) && (BEE_DRONE(reg_a5)->shield_frames != 0)) {
        ENTITY(reg_a6)->hp.sh = 0x7FFF;
        BEE_DRONE(reg_a5)->shield_frames -= 1;
        if (BEE_DRONE(reg_a5)->shield_frames == 0) {
            ENTITY(reg_a6)->hp.sh = 0x1100;
        }
    }
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        reg_d2.b[0] = BEE_DRONE(reg_a5)->now.hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
        if (ENTITY(reg_a6)->hp.sh < 0) {
            reg_d0.w = 0x213;
            score_add();
            sfx_explosion_ground_large();
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a1 = stage5_bee_drone_table_2;
            stage5_explosions_from_table();
            enemy_remove();
            return;
        }
        goto block_8;
    }
    ENTITY(reg_a6)->attr.b.palette = (u8) BEE_DRONE(reg_a5)->now.palette;
block_8:
    if (g_enemies_stopped == 0) {
        reg_d1.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] -= BEE_DRONE(reg_a5)->sway;
        ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
        entity_follow_scroll();
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7400;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1400;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] += 0x7400;
        reg_tmp.w += reg_tmp1.w;
        if (reg_tmp.h[1] != 0) {
            if (BEE_DRONE(reg_a5)->now.seen != 0) {
                enemy_remove();
                return;
            }
            goto block_13;
        }
        BEE_DRONE(reg_a5)->now.seen = 1U;
block_13:
        if (BEE_DRONE(reg_a5)->now.phase == 0) {
            reg_tmp.b[0] = BEE_DRONE(reg_a5)->now.frame_countdown;
            BEE_DRONE(reg_a5)->now.frame_countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                BEE_DRONE(reg_a5)->now.frame_countdown = (u8) BEE_DRONE(reg_a5)->now.frame_interval;
                BEE_DRONE(reg_a5)->frame += 0x10;
                if (BEE_DRONE(reg_a5)->frame == 0x80) {
                    ENTITY(reg_a6)->flags.h = 0xA001;
                    BEE_DRONE(reg_a5)->now.phase = 1U;
                    BEE_DRONE(reg_a5)->now.phase = 2U;
                    BEE_DRONE(reg_a5)->unread_20 = 4;
                    BEE_DRONE(reg_a5)->unread_22 = 0xFFFD;
                    BEE_DRONE(reg_a5)->shot.both = 0x1060;
                    BEE_DRONE(reg_a5)->unread_28 = 0x10;
                    BEE_DRONE(reg_a5)->unread_24 = 0x606;
                }
            }
        }
        if ((s8) BEE_DRONE(reg_a5)->now.phase >= 2) {
            reg_d1.w = 0;
            reg_d0.w = 0;
            reg_d0.b[0] = 0x28;
            reg_d1.b[0] = BEE_DRONE(reg_a5)->sway_angle;
            BEE_DRONE(reg_a5)->sway_angle += 2;
            velocity_from_dir256();
            BEE_DRONE(reg_a5)->sway = (u16) reg_d2.h[0];
            reg_d1.h[0] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] += BEE_DRONE(reg_a5)->sway;
            ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
            temp_v0 = BEE_DRONE(reg_a5)->rise;
            if ((s32) temp_v0 < 0x600) {
                BEE_DRONE(reg_a5)->rise = (u16) (temp_v0 + 0x40);
                ENTITY(reg_a6)->hit_y_plus.h += 0x40;
                ENTITY(reg_a6)->hit_y_minus.h -= 0x40;
            }
        }
        if (BEE_DRONE(reg_a5)->now.phase == 2) {
            reg_tmp.b[0] = BEE_DRONE(reg_a5)->now.frame_countdown;
            BEE_DRONE(reg_a5)->now.frame_countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                BEE_DRONE(reg_a5)->now.frame_countdown = (u8) BEE_DRONE(reg_a5)->now.frame_interval;
                BEE_DRONE(reg_a5)->frame += 0x10;
                if ((s16) BEE_DRONE(reg_a5)->frame >= 0xF0) {
                    BEE_DRONE(reg_a5)->frame = 0xF0U;
                    BEE_DRONE(reg_a5)->now.phase = 3U;
                }
            }
        }
        if (BEE_DRONE(reg_a5)->now.phase == 3) {
            reg_tmp.b[0] = BEE_DRONE(reg_a5)->shot.b.countdown;
            BEE_DRONE(reg_a5)->shot.b.countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                BEE_DRONE(reg_a5)->shot.b.countdown = 0x10U;
                if ((g_bullets_blocked == 0) && ((s16) ENTITY(reg_a6)->y.h > 0x2000)) {
                    reg_d0.b[0] = BEE_DRONE(reg_a5)->shots_left;
                    if (BEE_DRONE(reg_a5)->shots == reg_d0.b[0]) {
                        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d0.h[0] += 0x7FFF + 0x7A01;
                        aim256_at_player();
                        if (cond_flag != 0) {
                            reg_d1.h[0] = 0x80;
                        }
                        BEE_DRONE(reg_a5)->fire_dir = (u8) reg_d1.b[0];
                    }
                    reg_d1.w = 0;
                    reg_d1.b[0] = BEE_DRONE(reg_a5)->fire_dir;
                    reg_d0.w = 0xFFFF0005;
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d5.w = 0x02000000;
                    reg_d4.w = 0;
                    reg_d3.w = 0;
                    if (BEE_DRONE(reg_a5)->shots_left != 0) {
                        reg_d1.h[0] -= 0x34;
                        reg_d7.h[0] = 4;
                        reg_a0 = g_direction64_offsets_2CC;
                        do {
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            bullet_fire256_fixed();
                            reg_d1.b[0] += 4;
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            bullet_fire256_fixed();
                            reg_d1.b[0] += 4;
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            bullet_fire256_fixed();
                            reg_d1.b[0] += 0x10;
                        } while ((s16)(--reg_d7.h[0]) >= 0);
                    } else {
                        reg_d0.w = 0xFFFF0004;
                        reg_d1.h[0] -= 0x22;
                        reg_d7.h[0] = 3;
                        reg_a0 = g_direction64_offsets_2CC;
                        do {
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            bullet_fire256_double();
                            reg_d1.b[0] += 2;
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            bullet_fire256_double();
                            reg_d1.b[0] += 2;
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            bullet_fire256_double();
                            reg_d1.b[0] += 2;
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            bullet_fire256_double();
                            reg_d1.b[0] += 2;
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            bullet_fire256_double();
                            reg_d1.b[0] += 0xC;
                        } while ((s16)(--reg_d7.h[0]) >= 0);
                    }
                    reg_tmp.b[0] = BEE_DRONE(reg_a5)->shots_left;
                    BEE_DRONE(reg_a5)->shots_left -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        BEE_DRONE(reg_a5)->shots_left = (u8) BEE_DRONE(reg_a5)->shots;
                        BEE_DRONE(reg_a5)->shot.b.countdown = BEE_DRONE(reg_a5)->shot.b.pause;
                    }
                }
            }
        }
        goto block_88;
    }
block_88:
    reg_a0 = stage5_bee_drone_table;
    reg_a0 += BEE_DRONE(reg_a5)->frame;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp.h[1] = *(u16 *)(reg_a0 + 4);
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 6);
    reg_d1.w += reg_tmp.w;
    reg_d1.h[1] += BEE_DRONE(reg_a5)->rise;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 8);
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer5();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

void stage5_anim_test_a_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern u8 D_0025FF30[];
extern u8 stage5_anim_test_a_start_table[];
extern u8 stage5_anim_test_a_start_table_2[];

void stage5_anim_test_a_start(void) {
    reg_a0 = stage5_anim_test_a_start_table_2;
    enemy_init_entities();
    reg_a0 = stage5_anim_test_a_start_table;
    reg_d0.w = 4;
    enemy_set_task_state();
    reg_tmp.w = 0x38001C00;
    ENTITY(reg_a6)->y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = reg_tmp.h[0];
    reg_d0.h[0] = 0x15;
    reg_a0 = D_0025FF30;
    sprite_palette_load();
}

s32 entity_move_by_p2_stick();
extern u8 stage5_anim_test_a_table[];

void stage5_anim_test_a(void) {
    u16 temp_a0;

    entity_move_by_p2_stick();
    reg_tmp.b[0] = ANIM_TEST(reg_a5)->frame_countdown;
    ANIM_TEST(reg_a5)->frame_countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ANIM_TEST(reg_a5)->frame_countdown = (u8) ANIM_TEST(reg_a5)->frame_interval;
        ANIM_TEST(reg_a5)->frame += 4;
        ANIM_TEST(reg_a5)->frame &= 0x3F;
    }
    reg_a0 = stage5_anim_test_a_table;
    reg_a0 += ANIM_TEST(reg_a5)->frame;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xD800E800;
    reg_d3.h[0] = 0x28C0;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer5();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

void stage5_anim_test_b_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern u8 stage5_anim_test_b_start_table[];
extern u8 stage5_anim_test_b_start_table_2[];

void stage5_anim_test_b_start(void) {
    reg_a0 = stage5_anim_test_b_start_table_2;
    enemy_init_entities();
    reg_a0 = stage5_anim_test_b_start_table;
    reg_d0.w = 4;
    enemy_set_task_state();
    reg_tmp.w = 0x38001C00;
    ENTITY(reg_a6)->y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = reg_tmp.h[0];
    reg_d0.h[0] = 0x15;
    reg_a0 = D_0025FF30;
    sprite_palette_load();
}

extern u8 stage5_anim_test_b_table[];

void stage5_anim_test_b(void) {
    u16 temp_a0;

    entity_move_by_p2_stick();
    reg_tmp.b[0] = ANIM_TEST(reg_a5)->frame_countdown;
    ANIM_TEST(reg_a5)->frame_countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ANIM_TEST(reg_a5)->frame_countdown = (u8) ANIM_TEST(reg_a5)->frame_interval;
        ANIM_TEST(reg_a5)->frame += 4;
        ANIM_TEST(reg_a5)->frame &= 0x1F;
    }
    reg_a0 = stage5_anim_test_b_table;
    reg_a0 += ANIM_TEST(reg_a5)->frame;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xDC00EE00;
    reg_d3.h[0] = 0x2490;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer5();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

u8 stage5_small_turret_start_table[32] = {
    0x00, 0x00, 0x09, 0x16, 0x10, 0x20, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_small_turret_start_table_2[32] = {
    0x00, 0xA0, 0x00, 0xFC, 0x00, 0xFD, 0x00, 0x00, 0xD3, 0x02, 0x18, 0x04, 0x00, 0x04, 0x00, 0x04,
    0x00, 0x04, 0x00, 0x04, 0x00, 0x06, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_small_turret_table[32] = {
    0x00, 0x00, 0x22, 0x1F, 0x00, 0x00, 0x23, 0x1F, 0x00, 0x00, 0x24, 0x1F, 0x00, 0x00, 0x25, 0x1F,
    0x00, 0x00, 0x26, 0x1F, 0x00, 0x00, 0x27, 0x1F, 0x00, 0x00, 0x28, 0x1F, 0x00, 0x00, 0x29, 0x1F,
};

u8 stage5_bee_hatch_start_table[16] = {
    0x00, 0x00, 0x10, 0x20, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_bee_hatch_start_table_2[32] = {
    0x00, 0x80, 0x00, 0xFC, 0x00, 0xFD, 0x00, 0x00, 0xD3, 0x02, 0x18, 0x04, 0x00, 0x04, 0x00, 0x04,
    0x00, 0x04, 0x00, 0x04, 0xFF, 0x7F, 0x00, 0x10, 0x16, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_bee_hatch_table[32] = {
    0x00, 0x00, 0x2A, 0x1F, 0x00, 0x00, 0x2B, 0x1F, 0x00, 0x00, 0x2C, 0x1F, 0x00, 0x00, 0x2D, 0x1F,
    0x00, 0x00, 0x2E, 0x1F, 0x00, 0x00, 0x2F, 0x1F, 0x00, 0x00, 0x30, 0x1F, 0x00, 0x00, 0x31, 0x1F,
};

u8 stage5_small_spider_turret_start_table[32] = {
    0x00, 0x00, 0x09, 0x16, 0x02, 0x02, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x04, 0x04, 0x03, 0x00,
    0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_small_spider_turret_start_table_2[64] = {
    0x00, 0xA0, 0x00, 0xFC, 0x00, 0xFD, 0x00, 0x00, 0xD3, 0x02, 0x18, 0x04, 0x00, 0x0C, 0x00, 0x0C,
    0x00, 0x0C, 0x00, 0x0C, 0x00, 0x18, 0x00, 0x10, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x10, 0x00, 0x04, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_small_spider_turret_draw_table[32] = {
    0x00, 0x00, 0x59, 0x1F, 0x00, 0x00, 0x5A, 0x1F, 0x00, 0x00, 0x5B, 0x1F, 0x00, 0x00, 0x5C, 0x1F,
    0x00, 0x00, 0x5D, 0x1F, 0x00, 0x00, 0x5C, 0x1F, 0x00, 0x00, 0x5B, 0x1F, 0x00, 0x00, 0x5A, 0x1F,
};

u8 stage5_small_spider_turret_table[64] = {
    0x00, 0x00, 0x8D, 0x00, 0x00, 0xFE, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x00,
    0x00, 0xFE, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x04, 0x00, 0x40, 0x00, 0x00, 0x02,
    0x00, 0xFA, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0xF2, 0x00, 0x04, 0x00, 0x00,
    0x02, 0x00, 0x05, 0x00, 0x40, 0x00, 0x00, 0xF6, 0x00, 0xFC, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00,
};

s16 stage5_small_spider_head_start_table[8] = {
    0x0000, 0x1609, 0x0303, 0x0000, 0x0006, 0x0000, 0x0000, 0x0000,
};

s16 stage5_small_spider_head_start_table_2[16] = {
    0xA000, 0xFC00, 0xFD00, 0x0000, 0x02D3, 0x0418, 0x0C00, 0x0800,
    0x0800, 0x0A00, 0x2200, 0x1000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u8 stage5_small_spider_head_table[128] = {
    0x00, 0x00, 0x48, 0x1F, 0x00, 0x00, 0x49, 0x1F, 0x00, 0x00, 0x4A, 0x1F, 0x00, 0x00, 0x4B, 0x1F,
    0x00, 0x00, 0x4C, 0x1F, 0x00, 0x00, 0x4D, 0x1F, 0x00, 0x00, 0x4E, 0x1F, 0x00, 0x00, 0x4F, 0x1F,
    0x00, 0x00, 0x50, 0x1F, 0x00, 0x00, 0x51, 0x1F, 0x00, 0x00, 0x52, 0x1F, 0x00, 0x00, 0x53, 0x1F,
    0x00, 0x00, 0x54, 0x1F, 0x00, 0x00, 0x55, 0x1F, 0x00, 0x00, 0x56, 0x1F, 0x00, 0x00, 0x57, 0x1F,
    0x00, 0x00, 0x56, 0x1F, 0x00, 0x00, 0x55, 0x1F, 0x00, 0x00, 0x54, 0x1F, 0x00, 0x00, 0x53, 0x1F,
    0x00, 0x00, 0x52, 0x1F, 0x00, 0x00, 0x51, 0x1F, 0x00, 0x00, 0x50, 0x1F, 0x00, 0x00, 0x4F, 0x1F,
    0x00, 0x00, 0x4E, 0x1F, 0x00, 0x00, 0x4D, 0x1F, 0x00, 0x00, 0x4C, 0x1F, 0x00, 0x00, 0x4B, 0x1F,
    0x00, 0x00, 0x4A, 0x1F, 0x00, 0x00, 0x49, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_small_spider_head_table_2[128] = {
    0x80, 0x00, 0x00, 0xFD, 0x80, 0x00, 0x00, 0xFE, 0x80, 0x00, 0xC0, 0xFE, 0xC0, 0x00, 0x80, 0xFF,
    0x40, 0x01, 0x00, 0x00, 0x80, 0x01, 0xC0, 0x00, 0xC0, 0x01, 0xC0, 0x01, 0x80, 0x02, 0x40, 0x02,
    0x00, 0x03, 0x00, 0x03, 0xC0, 0x03, 0x80, 0x03, 0x80, 0x04, 0xC0, 0x03, 0x40, 0x05, 0x00, 0x04,
    0x40, 0x06, 0x80, 0x04, 0x00, 0x07, 0x80, 0x04, 0xC0, 0x08, 0xC0, 0x04, 0x00, 0x09, 0xC0, 0x04,
    0xC0, 0x08, 0xC0, 0x04, 0x00, 0x07, 0x80, 0x04, 0x40, 0x06, 0x80, 0x04, 0x40, 0x05, 0x00, 0x04,
    0x80, 0x04, 0xC0, 0x03, 0xC0, 0x03, 0x80, 0x03, 0x00, 0x03, 0x00, 0x03, 0x80, 0x02, 0x40, 0x02,
    0xC0, 0x01, 0xC0, 0x01, 0x80, 0x01, 0xC0, 0x00, 0x40, 0x01, 0x00, 0x00, 0xC0, 0x00, 0x80, 0xFF,
    0x80, 0x00, 0xC0, 0xFE, 0x80, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_small_spider_head_table_3[128] = {
    0x66, 0x00, 0x6C, 0x00, 0x72, 0x00, 0x78, 0x00, 0x7E, 0x00, 0x84, 0x00, 0x8A, 0x00, 0x90, 0x00,
    0x96, 0x00, 0x9C, 0x00, 0xA2, 0x00, 0xA8, 0x00, 0xAE, 0x00, 0xB4, 0x00, 0xBA, 0x00, 0xC0, 0x00,
    0xBA, 0x00, 0xB4, 0x00, 0xAE, 0x00, 0xA8, 0x00, 0xA2, 0x00, 0x9C, 0x00, 0x96, 0x00, 0x90, 0x00,
    0x8A, 0x00, 0x84, 0x00, 0x7E, 0x00, 0x78, 0x00, 0x72, 0x00, 0x6C, 0x00, 0x20, 0x00, 0x21, 0x00,
    0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00,
    0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2E, 0x00, 0x2F, 0x00, 0x2E, 0x00, 0x2D, 0x00,
    0x2C, 0x00, 0x2B, 0x00, 0x2A, 0x00, 0x29, 0x00, 0x28, 0x00, 0x27, 0x00, 0x26, 0x00, 0x25, 0x00,
    0x24, 0x00, 0x23, 0x00, 0x22, 0x00, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_small_spider_head_table_4[128] = {
    0x9A, 0x00, 0x94, 0x00, 0x8E, 0x00, 0x88, 0x00, 0x82, 0x00, 0x7C, 0x00, 0x76, 0x00, 0x70, 0x00,
    0x6A, 0x00, 0x64, 0x00, 0x5E, 0x00, 0x58, 0x00, 0x52, 0x00, 0x4C, 0x00, 0x46, 0x00, 0x40, 0x00,
    0x46, 0x00, 0x4C, 0x00, 0x52, 0x00, 0x58, 0x00, 0x5E, 0x00, 0x64, 0x00, 0x6A, 0x00, 0x70, 0x00,
    0x76, 0x00, 0x7C, 0x00, 0x82, 0x00, 0x88, 0x00, 0x8E, 0x00, 0x94, 0x00, 0x20, 0x00, 0x1F, 0x00,
    0x1E, 0x00, 0x1D, 0x00, 0x1C, 0x00, 0x1B, 0x00, 0x1A, 0x00, 0x19, 0x00, 0x18, 0x00, 0x17, 0x00,
    0x16, 0x00, 0x15, 0x00, 0x14, 0x00, 0x13, 0x00, 0x12, 0x00, 0x11, 0x00, 0x12, 0x00, 0x13, 0x00,
    0x14, 0x00, 0x15, 0x00, 0x16, 0x00, 0x17, 0x00, 0x18, 0x00, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0x00,
    0x1C, 0x00, 0x1D, 0x00, 0x1E, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_small_spider_head_table_5[64] = {
    0x00, 0x00, 0x8D, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x00,
    0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0xF4,
    0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x40, 0x00, 0x00, 0xF8, 0x00, 0xFC, 0x00, 0x00,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_large_spider_turret_start_table[32] = {
    0x00, 0x00, 0x09, 0x16, 0x02, 0x02, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x04, 0x04, 0x06, 0x00,
    0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_large_spider_turret_start_table_2[64] = {
    0x00, 0xA0, 0x00, 0xFC, 0x00, 0xFD, 0x00, 0x00, 0xD3, 0x02, 0x18, 0x04, 0x00, 0x0C, 0x00, 0x10,
    0x00, 0x10, 0x00, 0x10, 0x00, 0x24, 0x00, 0x10, 0x00, 0x00, 0x00, 0x14, 0x00, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x10, 0x00, 0x04, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_large_spider_turret_table[32] = {
    0x00, 0x00, 0x43, 0x1F, 0x00, 0x00, 0x44, 0x1F, 0x00, 0x00, 0x45, 0x1F, 0x00, 0x00, 0x46, 0x1F,
    0x00, 0x00, 0x47, 0x1F, 0x00, 0x00, 0x46, 0x1F, 0x00, 0x00, 0x45, 0x1F, 0x00, 0x00, 0x44, 0x1F,
};

u8 stage5_large_spider_turret_table_2[112] = {
    0x00, 0x00, 0x8D, 0x00, 0x00, 0x08, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x8D, 0x00,
    0x00, 0xEC, 0x00, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x00, 0x00, 0xFE, 0x00, 0xFE,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x05, 0x00, 0x40, 0x00, 0x00, 0x06, 0x00, 0xF8, 0x00, 0x00,
    0x00, 0x00, 0x07, 0x00, 0x40, 0x00, 0x00, 0xEE, 0x00, 0xF4, 0x00, 0x00, 0x02, 0x00, 0x07, 0x00,
    0x40, 0x00, 0x00, 0xF4, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x40, 0x00, 0x00, 0xF6,
    0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0xE8, 0x00, 0x0A, 0x00, 0x00,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

s16 stage5_large_spider_head_start_table[16] = {
    0x0000, 0x1609, 0x0303, 0x0000, 0x000A, 0x000A, 0x0002, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

s16 stage5_large_spider_head_start_table_2[16] = {
    0xA000, 0xFC00, 0xFD00, 0x0000, 0x02D3, 0x0418, 0x1200, 0x0C00,
    0x0E00, 0x0E00, 0x3E00, 0x1000, 0x0016, 0x0000, 0x0000, 0x0000,
};

u8 stage5_large_spider_head_table[128] = {
    0x00, 0x00, 0x32, 0x1F, 0x00, 0x00, 0x33, 0x1F, 0x00, 0x00, 0x34, 0x1F, 0x00, 0x00, 0x35, 0x1F,
    0x00, 0x00, 0x36, 0x1F, 0x00, 0x00, 0x37, 0x1F, 0x00, 0x00, 0x38, 0x1F, 0x00, 0x00, 0x39, 0x1F,
    0x00, 0x00, 0x3A, 0x1F, 0x00, 0x00, 0x3B, 0x1F, 0x00, 0x00, 0x3C, 0x1F, 0x00, 0x00, 0x3D, 0x1F,
    0x00, 0x00, 0x3E, 0x1F, 0x00, 0x00, 0x3F, 0x1F, 0x00, 0x00, 0x40, 0x1F, 0x00, 0x00, 0x41, 0x1F,
    0x00, 0x00, 0x40, 0x1F, 0x00, 0x00, 0x3F, 0x1F, 0x00, 0x00, 0x3E, 0x1F, 0x00, 0x00, 0x3D, 0x1F,
    0x00, 0x00, 0x3C, 0x1F, 0x00, 0x00, 0x3B, 0x1F, 0x00, 0x00, 0x3A, 0x1F, 0x00, 0x00, 0x39, 0x1F,
    0x00, 0x00, 0x38, 0x1F, 0x00, 0x00, 0x37, 0x1F, 0x00, 0x00, 0x36, 0x1F, 0x00, 0x00, 0x35, 0x1F,
    0x00, 0x00, 0x34, 0x1F, 0x00, 0x00, 0x33, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_large_spider_head_table_2[80] = {
    0x00, 0x00, 0x8D, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x00,
    0x00, 0x00, 0x00, 0xFC, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x85, 0x00, 0x00, 0x00, 0x00, 0xF4,
    0x00, 0xFA, 0x00, 0x00, 0x04, 0x00, 0x85, 0x00, 0x00, 0x00, 0x00, 0xEE, 0x00, 0x06, 0x00, 0x00,
    0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x04, 0x00, 0x00, 0x02, 0x00, 0x07, 0x00,
    0x40, 0x00, 0x00, 0xF4, 0x00, 0xF8, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_large_spider_head_table_3[128] = {
    0x80, 0x03, 0xC0, 0xF8, 0x80, 0x03, 0x40, 0xFA, 0x00, 0x04, 0x00, 0xFC, 0xC0, 0x04, 0x40, 0xFD,
    0x40, 0x05, 0xC0, 0xFE, 0x00, 0x06, 0x40, 0x00, 0x80, 0x06, 0x80, 0x01, 0x00, 0x08, 0x00, 0x03,
    0x00, 0x09, 0x40, 0x04, 0x80, 0x0A, 0x40, 0x05, 0x00, 0x0C, 0x00, 0x06, 0xC0, 0x0D, 0x80, 0x06,
    0x40, 0x0F, 0x40, 0x07, 0x00, 0x11, 0x80, 0x07, 0x00, 0x13, 0xC0, 0x07, 0xC0, 0x14, 0x00, 0x08,
    0x00, 0x13, 0xC0, 0x07, 0x00, 0x11, 0x80, 0x07, 0x40, 0x0F, 0x40, 0x07, 0xC0, 0x0D, 0x80, 0x06,
    0x00, 0x0C, 0x00, 0x06, 0x80, 0x0A, 0x40, 0x05, 0x00, 0x09, 0x40, 0x04, 0x00, 0x08, 0x00, 0x03,
    0x80, 0x06, 0x80, 0x01, 0x00, 0x06, 0x40, 0x00, 0x40, 0x05, 0xC0, 0xFE, 0xC0, 0x04, 0x40, 0xFD,
    0x00, 0x04, 0x00, 0xFC, 0x80, 0x03, 0x40, 0xFA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_large_spider_head_table_4[64] = {
    0xB0, 0x00, 0xA8, 0x00, 0xA0, 0x00, 0x98, 0x00, 0x90, 0x00, 0x88, 0x00, 0x80, 0x00, 0x78, 0x00,
    0x70, 0x00, 0x68, 0x00, 0x60, 0x00, 0x58, 0x00, 0x50, 0x00, 0x48, 0x00, 0x40, 0x00, 0x38, 0x00,
    0x40, 0x00, 0x48, 0x00, 0x50, 0x00, 0x58, 0x00, 0x60, 0x00, 0x68, 0x00, 0x70, 0x00, 0x78, 0x00,
    0x80, 0x00, 0x88, 0x00, 0x90, 0x00, 0x98, 0x00, 0xA0, 0x00, 0xA8, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_large_spider_head_table_5[64] = {
    0x50, 0x00, 0x58, 0x00, 0x60, 0x00, 0x68, 0x00, 0x70, 0x00, 0x78, 0x00, 0x80, 0x00, 0x88, 0x00,
    0x90, 0x00, 0x98, 0x00, 0xA0, 0x00, 0xA8, 0x00, 0xB0, 0x00, 0xB8, 0x00, 0xC0, 0x00, 0xC8, 0x00,
    0xC0, 0x00, 0xB8, 0x00, 0xB0, 0x00, 0xA8, 0x00, 0xA0, 0x00, 0x98, 0x00, 0x90, 0x00, 0x88, 0x00,
    0x80, 0x00, 0x78, 0x00, 0x70, 0x00, 0x68, 0x00, 0x60, 0x00, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_spiderling_start_table_2[32] = {
    0x00, 0x00, 0x0A, 0x15, 0x20, 0x20, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
    0x3C, 0x00, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_spiderling_start_table_3[32] = {
    0x01, 0xA0, 0x00, 0xFC, 0x00, 0xFD, 0x00, 0x00, 0xD3, 0x02, 0x18, 0x04, 0x00, 0x02, 0x00, 0x02,
    0x00, 0x02, 0x00, 0x02, 0x00, 0x01, 0x00, 0x10, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_spiderling_table[64] = {
    0x00, 0x80, 0x00, 0x80, 0x00, 0x88, 0x00, 0x88, 0x00, 0x90, 0x00, 0x90, 0x00, 0x98, 0x00, 0x98,
    0x00, 0xA0, 0x00, 0xA0, 0x00, 0xA8, 0x00, 0xA8, 0x00, 0xB0, 0x00, 0xB0, 0x00, 0xB8, 0x00, 0xB8,
    0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC8, 0x00, 0xC8, 0x00, 0xD0, 0x00, 0xD0, 0x00, 0xD8, 0x00, 0xD8,
    0x00, 0xE0, 0x00, 0xE0, 0x00, 0xE8, 0x00, 0xE8, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0xF8, 0x00, 0xF8,
};

u8 stage5_bee_drone_start_table_2[32] = {
    0x00, 0x00, 0x0A, 0x15, 0x18, 0x00, 0x03, 0x03, 0x00, 0x00, 0x0E, 0x40, 0xFC, 0xFF, 0x05, 0x00,
    0x08, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_bee_drone_start_table_3[32] = {
    0x00, 0x80, 0x00, 0xFC, 0x00, 0xFD, 0x00, 0x00, 0xD3, 0x02, 0x18, 0x04, 0x00, 0x0C, 0x00, 0x06,
    0x00, 0x06, 0x00, 0x06, 0xFF, 0x7F, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_bee_drone_table[256] = {
    0x00, 0x00, 0xD2, 0x18, 0x00, 0xF0, 0x00, 0xF4, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xD3, 0x18, 0x00, 0xF0, 0x00, 0xF4, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xD4, 0x18, 0x00, 0xF0, 0x00, 0xF4, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xD5, 0x18, 0x00, 0xF0, 0x00, 0xF4, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xD6, 0x18, 0x00, 0xF0, 0x00, 0xF4, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xD7, 0x18, 0x00, 0xF0, 0x00, 0xF4, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xD8, 0x18, 0x00, 0xF0, 0x00, 0xF4, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xD9, 0x18, 0x00, 0xF0, 0x00, 0xF4, 0x60, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xCA, 0x18, 0x00, 0xEC, 0x00, 0xF4, 0x60, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xCB, 0x18, 0x00, 0xEC, 0x00, 0xF4, 0x60, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xCC, 0x18, 0x00, 0xEC, 0x00, 0xF4, 0x60, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xCD, 0x18, 0x00, 0xEC, 0x00, 0xF4, 0x60, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xCE, 0x18, 0x00, 0xEC, 0x00, 0xF4, 0x60, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xCF, 0x18, 0x00, 0xEC, 0x00, 0xF4, 0x60, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xD0, 0x18, 0x00, 0xEC, 0x00, 0xF4, 0x60, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xD1, 0x18, 0x00, 0xEC, 0x00, 0xF4, 0x60, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_bee_drone_table_2[64] = {
    0x00, 0x00, 0x8D, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x84, 0x00,
    0x00, 0x00, 0x00, 0xFC, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x85, 0x00, 0x00, 0x00, 0x00, 0xF2,
    0x00, 0x06, 0x00, 0x00, 0x06, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0xF4, 0x00, 0x04, 0x00, 0x00,
    0x08, 0x00, 0x07, 0x00, 0x40, 0x00, 0x00, 0xF8, 0x00, 0xF8, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00,
};

u8 stage5_anim_test_a_start_table[16] = {
    0x00, 0x00, 0x0A, 0x15, 0x10, 0x40, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_anim_test_a_start_table_2[32] = {
    0x01, 0xA0, 0x00, 0xFC, 0x00, 0xFD, 0x00, 0x00, 0xD3, 0x02, 0x18, 0x04, 0x00, 0x04, 0x00, 0x04,
    0x00, 0x04, 0x00, 0x04, 0x00, 0x06, 0x00, 0x10, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_anim_test_a_table[64] = {
    0x00, 0x00, 0x6A, 0x1D, 0x00, 0x00, 0x6B, 0x1D, 0x00, 0x00, 0x6C, 0x1D, 0x00, 0x00, 0x6D, 0x1D,
    0x00, 0x00, 0x6E, 0x1D, 0x00, 0x00, 0x6F, 0x1D, 0x00, 0x00, 0x70, 0x1D, 0x00, 0x00, 0x71, 0x1D,
    0x00, 0x00, 0x72, 0x1D, 0x00, 0x00, 0x73, 0x1D, 0x00, 0x00, 0x74, 0x1D, 0x00, 0x00, 0x75, 0x1D,
    0x00, 0x00, 0x76, 0x1D, 0x00, 0x00, 0x77, 0x1D, 0x00, 0x00, 0x78, 0x1D, 0x00, 0x00, 0x79, 0x1D,
};

u8 stage5_anim_test_b_start_table[16] = {
    0x00, 0x00, 0x0A, 0x15, 0x10, 0x40, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_anim_test_b_start_table_2[32] = {
    0x01, 0xA0, 0x00, 0xFC, 0x00, 0xFD, 0x00, 0x00, 0xD3, 0x02, 0x18, 0x04, 0x00, 0x04, 0x00, 0x04,
    0x00, 0x04, 0x00, 0x04, 0x00, 0x06, 0x00, 0x10, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_anim_test_b_table[32] = {
    0x00, 0x00, 0x7A, 0x1D, 0x00, 0x00, 0x7B, 0x1D, 0x00, 0x00, 0x7C, 0x1D, 0x00, 0x00, 0x7D, 0x1D,
    0x00, 0x00, 0x7E, 0x1D, 0x00, 0x00, 0x7F, 0x1D, 0x00, 0x00, 0x80, 0x1D, 0x00, 0x00, 0x81, 0x1D,
};

u8 stage5_small_spider_turret_table_2[4] = { 0xFF, 0x02, 0x00, 0xFF };

u8 stage5_small_spider_turret_table_3[4] = { 0x00, 0x03, 0x00, 0x01 };

u8 stage5_large_spider_turret_table_3[4] = { 0xFF, 0x05, 0x00, 0xFD };

u8 stage5_large_spider_turret_table_4[4] = { 0x00, 0x06, 0x00, 0x03 };

u8 stage5_spiderling_table_2[8] = { 0x00, 0x00, 0x67, 0x1F, 0x00, 0x00, 0x68, 0x1F };
