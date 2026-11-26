#include "common.h"
#include "entity.h"
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
void func_001F71A0(void);

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
        *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d1.h[0];
        *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
        var_a2 = (u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)(var_a2);
        *(u16 *)(reg_a0 + 2) = (u16) reg_d2.h[1];
        *(u16 *)(reg_a0 + 4) = (u16) reg_d2.h[0];
        *(s16 *)(reg_a0 + 0x1E) = 4;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(u16 *)(reg_a0 + 0x1A) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        goto loop_1;
    }
}


void stage5_small_turret_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern u8 D_00265110[];
extern u8 D_00265130[];
extern s16 D_00299768[];
extern s8 enemy_move_end_requested;

void stage5_small_turret_start(void)
{
    extern void enemy_set_task_state(void);
    extern void enemy_init_entities(void);
    extern void enemy_path_start(void);
    reg_a0 = D_00265130;
    enemy_init_entities();

    reg_a0 = D_00265110;
    reg_d0.w = 8;
    enemy_set_task_state();
    enemy_path_start();

    if (enemy_move_end_requested == 0) {
        ENTITY(reg_a6)->attr.b.palette = SMALL_TURRET(reg_a5)->palette;
        D_00299768[0] = 1;
    }
}


s32 func_00125EC0();
s32 bullet_fire_fast();
s32 enemy_remove();
s32 sfx_explosion_air_small();
s32 score_add_no_chain();
s32 score_add();
s32 entity_follow_scroll();
s32 func_00202180();
extern u8 D_00265150[];

void stage5_small_turret(void) {
    s32 enemy_hitbox_debug_draw();
    s32 sprite_draw_layer1();
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
            *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
            temp_a1 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a1;
            *(s16 *)(reg_a0 + 0x1E) = 4;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(s16 *)(reg_a0 + 0x10) = 2;
            sfx_explosion_air_small();
            reg_d1.w = 0;
            reg_d0.w = 8;
            reg_d2.w = 1;
            func_00125EC0();
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
                func_00202180();
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
                    func_00202180();
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
    reg_a0 = (u8 *)D_00265150;
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

extern u8 D_00265170[];
extern u8 D_00265180[];
extern u16 g_scroll_line;

void stage5_bee_hatch_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = D_00265180;
    enemy_init_entities();
    reg_a0 = D_00265170;
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
extern u8 D_002651A0[];

void stage5_bee_hatch(void) {
    s32 sprite_draw_layer1();
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
    reg_a0 = (u8 *)D_002651A0;
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

extern u8 D_002651C0[];
extern u8 D_002651E0[];
extern s16 D_0029976A[];

void stage5_small_spider_turret_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = D_002651E0;
    enemy_init_entities();
    reg_a0 = D_002651C0;
    reg_d0.w = 8;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if (g_scroll_line == 0x201) {
            ENTITY(reg_a6)->attr.sb.flip = 0x40;
            SPIDER_TURRET(reg_a5)->mirrored = 1;
        }
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        ENTITY(reg_a6)->attr.b.palette = (u8) SPIDER_TURRET(reg_a5)->palette;
        rng_next_unsigned();
        SPIDER_TURRET(reg_a5)->fire_dir = (u8) reg_d0.b[0];
        rng_next_unsigned();
        SPIDER_TURRET(reg_a5)->start_dir = (u8) reg_d0.b[0];
    }
}

s32 bullet_fire256_double();
s32 sfx_explosion_ground_large();
s32 aim256_at_player();
extern u8 D_00265240[];
extern u8 D_0028DA18;
extern u8 D_0028DA1C;

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
            reg_a1 = (u8 *)D_00265240;
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
    func_001F71A0();
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
            reg_a1 = &D_0028DA18;
            if (SPIDER_TURRET(reg_a5)->mirrored == 0) {
                reg_a1 = &D_0028DA1C;
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
                    reg_a1 = &D_0028DA18;
                    if (SPIDER_TURRET(reg_a5)->mirrored == 0) {
                        reg_a1 = &D_0028DA1C;
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

extern u8 D_00265220[];

void stage5_small_spider_turret_draw(void) {
    void enemy_hitbox_debug_draw();
    void sprite_draw_layer1();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = D_00265220;
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

void func_001F71A0(void) {
}

void stage5_small_spider_head_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern s16 D_00265280[];
extern s16 D_00265290[];
extern s16 g_enemy_signal_6_as_s16;
extern s16 g_enemy_signal_4_as_s16;

void stage5_small_spider_head_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)(D_00265290);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_00265280);
    reg_d0.w = 6;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested != 0) return;
    if (g_scroll_line != 0x1F3) goto next_1;
    ENTITY(reg_a6)->attr.sb.flip = 0x40;
    SMALL_SPIDER_HEAD(reg_a5)->mirrored = 1;
next_1:
    ENTITY(reg_a6)->attr.b.palette = SMALL_SPIDER_HEAD(reg_a5)->palette;
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    reg_a0 = (u8 *)(&g_enemy_signal_4_as_s16);
    if ((s32) g_scroll_line < 0x260) goto next_2;
    reg_a0 = (u8 *)(&g_enemy_signal_6_as_s16);
next_2:
    reg_tmp.w = (u32) reg_a0;
    SMALL_SPIDER_HEAD(reg_a5)->owner_flag[0] = reg_tmp.h[1];
    SMALL_SPIDER_HEAD(reg_a5)->owner_flag[1] = reg_tmp.h[0];
    *(s16 *)reg_a0 = 1;
}

s32 bullet_fire256_fixed();
s32 bullet_fire256_2way();
extern u8 D_002652B0[];
extern u8 D_00265330[];
extern u8 D_002653B0[];
extern u8 D_00265430[];
extern u8 D_002654B0[];
extern u16 g_bullets_blocked;

void stage5_small_spider_head(void) {
    s32 enemy_hitbox_debug_draw();
    s32 sprite_draw_layer1();
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
            reg_a1 = (u8 *)D_002654B0;
            stage5_explosions_from_table();
            sfx_explosion_ground_large();
            reg_tmp.h[1] = SMALL_SPIDER_HEAD(reg_a5)->owner_flag[0];
            reg_tmp.h[0] = SMALL_SPIDER_HEAD(reg_a5)->owner_flag[1];
            reg_a0 = (u8 *)reg_tmp.w;
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
            reg_a0 = (u8 *)reg_tmp.w;
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
            reg_a1 = (u8 *)D_00265430;
            if (SMALL_SPIDER_HEAD(reg_a5)->mirrored != 0) {
                reg_a1 = (u8 *)D_002653B0;
            }
            reg_d0.h[0] = SMALL_SPIDER_HEAD(reg_a5)->step;
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
            reg_a1 += reg_d0.h[0];
            temp_v1 = *(u16 *)reg_a1;
            reg_a1 = (u8 *)D_00265330;
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
    reg_a0 = (unsigned char *)D_002652B0;
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

extern u8 D_002654F0[];
extern u8 D_00265510[];

void stage5_large_spider_turret_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = D_00265510;
    enemy_init_entities();
    reg_a0 = D_002654F0;
    reg_d0.w = 8;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if (g_scroll_line == 0x2B6) {
            ENTITY(reg_a6)->attr.sb.flip = 0x40;
            SPIDER_TURRET(reg_a5)->mirrored = 1;
        }
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        ENTITY(reg_a6)->attr.b.palette = (u8) SPIDER_TURRET(reg_a5)->palette;
        rng_next_unsigned();
        SPIDER_TURRET(reg_a5)->fire_dir = (u8) reg_d0.b[0];
        rng_next_unsigned();
        SPIDER_TURRET(reg_a5)->start_dir = (u8) reg_d0.b[0];
    }
}

extern u8 D_00265550[];
extern u8 D_00265570[];
extern u8 D_0028DA20;
extern u8 D_0028DA24;

void stage5_large_spider_turret(void) {
    s32 enemy_hitbox_debug_draw();
    s32 sprite_draw_layer1();
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
                reg_a1 = (u8 *)D_00265570;
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
        func_001F71A0();
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
                reg_a1 = &D_0028DA20;
                if (SPIDER_TURRET(reg_a5)->mirrored == 0) {
                    reg_a1 = &D_0028DA24;
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
                    reg_a1 = &D_0028DA20;
                    if (SPIDER_TURRET(reg_a5)->mirrored == 0) {
                        reg_a1 = &D_0028DA24;
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
        reg_a0 = (u8 *)D_00265550;
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

extern s16 D_002655E0[];
extern s16 D_00265600[];
extern s16 g_enemy_signal_7_as_s16;
extern s16 g_enemy_signal_5_as_s16;

void stage5_large_spider_head_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)(D_00265600);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_002655E0);
    reg_d0.w = 9;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested != 0) return;
    if (g_scroll_line != 0x299) goto next_1;
    ENTITY(reg_a6)->attr.sb.flip = 0x40;
    LARGE_SPIDER_HEAD(reg_a5)->mirrored = 1;
next_1:
    ENTITY(reg_a6)->attr.b.palette = LARGE_SPIDER_HEAD(reg_a5)->palette;
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    g_enemy_signal_5_as_s16 = 1;
    reg_a0 = (u8 *)(&g_enemy_signal_5_as_s16);
    if ((s32) g_scroll_line < 0x280) goto next_2;
    reg_a0 = (u8 *)(&g_enemy_signal_7_as_s16);
    LARGE_SPIDER_HEAD(reg_a5)->shot.both = 0x202;
next_2:
    reg_tmp.w = (u32) reg_a0;
    LARGE_SPIDER_HEAD(reg_a5)->owner_flag[0] = reg_tmp.h[1];
    LARGE_SPIDER_HEAD(reg_a5)->owner_flag[1] = reg_tmp.h[0];
    *(s16 *)reg_a0 = 1;
}

extern u8 D_00265620[];
extern u8 D_002656A0[];
extern u8 D_002656F0[];
extern u8 D_00265770[];
extern u8 D_002657B0[];

void stage5_large_spider_head(void) {
    s32 enemy_hitbox_debug_draw();
    s32 sprite_draw_layer1();
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
            reg_a1 = (u8 *)D_002656A0;
            stage5_explosions_from_table();
            sfx_explosion_ground_large();
            reg_tmp.h[1] = LARGE_SPIDER_HEAD(reg_a5)->owner_flag[0];
            reg_tmp.h[0] = LARGE_SPIDER_HEAD(reg_a5)->owner_flag[1];
            reg_a0 = (u8 *)reg_tmp.w;
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
            reg_a0 = (u8 *)reg_tmp.w;
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
            reg_a1 = (u8 *)D_002656F0;
            reg_a1 += LARGE_SPIDER_HEAD(reg_a5)->step;
            reg_d3.h[1] = *(u16 *)reg_a1;
            reg_d3.h[0] = *(u16 *)(reg_a1 + 2);
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a1 = (u8 *)D_00265770;
            if (LARGE_SPIDER_HEAD(reg_a5)->mirrored != 0) {
                reg_a1 = (u8 *)D_002657B0;
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
    reg_a0 = (unsigned char *)D_00265620;
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
extern u8 D_00261BB0[];
extern u8 D_002657F0[];
extern u8 D_00265810[];

void stage5_spiderling_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    reg_a0 = D_00265810;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) SPIDERLING(reg_a5)->at_start.y;
    ENTITY(reg_a6)->x.h = (u16) SPIDERLING(reg_a5)->at_start.x;
    ENTITY(reg_a6)->move.h = (u16) SPIDERLING(reg_a5)->at_start.move;
    ENTITY(reg_a6)->misc.h = (u16) SPIDERLING(reg_a5)->at_start.misc;
    ENTITY(reg_a6)->misc.h -= 1;
    reg_a0 = D_002657F0;
    reg_d0.w = 0xB;
    enemy_set_task_state();
    reg_d0.h[0] = 0x15;
    reg_a0 = D_00261BB0;
    sprite_palette_load();
    ENTITY(reg_a6)->attr.b.palette = (u8) SPIDERLING(reg_a5)->now.palette;
}

s32 bullet_fire256();
s32 sprite_draw_layer5();
s32 sprite_draw_layer5_zoom_keep();
s32 rng_next();
s32 func_00201100();
s32 entity_velocity();
s32 func_00202490();
s32 func_00202730();
s32 entity_check_bounds();
extern u8 D_00265830[];
extern u8 D_0028DA28;
extern u16 g_frame_mod2;
extern u16 g_game_frame;

void stage5_spiderling(void) {
    s32 enemy_hitbox_debug_draw();
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
            func_00202730();
            if (cond_flag == 0) {
                reg_d0.w = 0xFFFC0006;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d4.w = 0;
                reg_d3.w = 0;
                bullet_fire256();
                func_00201100();
                reg_d1.b[0] += reg_d5.b[0];
                reg_d0.w += 0x30000;
                bullet_fire256();
            }
            reg_d0.h[0] = 1;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            temp_a0_2 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a0_2;
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(u8 *)(reg_a0 + 0x1B) = (u8) ENTITY(reg_a6)->move.b.speed;
            reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d0.b[0] *= 4;
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
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
                func_00202180();
                if (cond_flag == 0) {
                    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                }
            }
        }
        if (SPIDERLING(reg_a5)->now.phase == 2) {
            func_00202490();
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
                func_00202180();
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
    reg_a0 = &D_0028DA28;
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
        reg_a1 = (u8 *)D_00265830;
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

extern u8 D_00260870[];
extern u8 D_00265870[];
extern u8 D_00265890[];

void stage5_bee_drone_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    u16 temp_a0;
    u32 temp_a2;

    reg_a0 = D_00265890;
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
    reg_a0 = D_00265870;
    reg_d0.w = 0xE;
    enemy_set_task_state();
    if ((s16) ENTITY(reg_a6)->y.h < 0x2801) {
        enemy_remove();
        return;
    }
    reg_d0.h[0] = 0x15;
    reg_a0 = D_00260870;
    sprite_palette_load();
}

s32 velocity_from_dir256();
extern u8 g_direction64_offsets_2CC[];
extern u8 D_002658B0[];
extern u8 D_002659B0[];

void stage5_bee_drone(void) {
    s32 enemy_hitbox_debug_draw();
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
            reg_a1 = D_002659B0;
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
    reg_a0 = D_002658B0;
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
extern u8 D_002659F0[];
extern u8 D_00265A00[];

void stage5_anim_test_a_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    reg_a0 = D_00265A00;
    enemy_init_entities();
    reg_a0 = D_002659F0;
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
extern u8 D_00265A20[];

void stage5_anim_test_a(void) {
    s32 enemy_hitbox_debug_draw();
    u16 temp_a0;

    entity_move_by_p2_stick();
    reg_tmp.b[0] = ANIM_TEST(reg_a5)->frame_countdown;
    ANIM_TEST(reg_a5)->frame_countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ANIM_TEST(reg_a5)->frame_countdown = (u8) ANIM_TEST(reg_a5)->frame_interval;
        ANIM_TEST(reg_a5)->frame += 4;
        ANIM_TEST(reg_a5)->frame &= 0x3F;
    }
    reg_a0 = D_00265A20;
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

extern u8 D_00265A60[];
extern u8 D_00265A70[];

void stage5_anim_test_b_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    reg_a0 = D_00265A70;
    enemy_init_entities();
    reg_a0 = D_00265A60;
    reg_d0.w = 4;
    enemy_set_task_state();
    reg_tmp.w = 0x38001C00;
    ENTITY(reg_a6)->y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = reg_tmp.h[0];
    reg_d0.h[0] = 0x15;
    reg_a0 = D_0025FF30;
    sprite_palette_load();
}

extern u8 D_00265A90[];

void stage5_anim_test_b(void) {
    s32 enemy_hitbox_debug_draw();
    u16 temp_a0;

    entity_move_by_p2_stick();
    reg_tmp.b[0] = ANIM_TEST(reg_a5)->frame_countdown;
    ANIM_TEST(reg_a5)->frame_countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ANIM_TEST(reg_a5)->frame_countdown = (u8) ANIM_TEST(reg_a5)->frame_interval;
        ANIM_TEST(reg_a5)->frame += 4;
        ANIM_TEST(reg_a5)->frame &= 0x1F;
    }
    reg_a0 = D_00265A90;
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
