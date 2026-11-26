#include "common.h"
#include "entity.h"
#include "enemy.h"

typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 step;                /* 0: waiting, 1: the frame runs up, 2: firing */
    /* 0x17 */ u8 seen;
    /* 0x18 */ EnemyTimer frame_timer;
    /* 0x1A */ u16 frame;              /* up to 0x1C in steps of 4 */
    /* 0x1C */ u16 wait;
    /* 0x1E */ u16 unread_1E;
    /* 0x20 */ u16 unread_20;
    /* 0x22 */ u16 unread_22;
    /* 0x24 */ u16 unread_24;
    /* 0x26 */ u16 unread_26;
    /* 0x28 */ u16 unread_28;
    /* 0x2A */ u8 unread_2A;
    /* 0x2B */ u8 unread_2B;
    /* 0x2C */ EnemyTimer shot_timer;
    /* 0x2E */ u8 unused_2E;
    /* 0x2F */ u8 attack_step;         /* 1: waiting, 2: the spiral, 3: the sweep */
    /* 0x30 */ u16 unused_30;
    /* 0x32 */ u16 hp[2];              /* high word first */
} Stage5Midboss3State;

/* Entities 1 to 3 of the mid-boss are not drawn. They hold the values of its two attacks and its damage flags. */
typedef struct {
    /* 0x00 */ u8 unused_00[8];
    /* 0x08 */ EnemyTimer shot_timer;
    /* 0x0A */ u16 frames_left;
    /* 0x0C */ u8 turn;
    /* 0x0D */ u8 direction;
    /* 0x0E */ u16 wait;               /* frames before the first attack */
    /* 0x10 */ u8 unused_10[0x10];
} Stage5Midboss3Spiral;

typedef struct {
    /* 0x00 */ u8 unused_00[8];
    /* 0x08 */ EnemyTimer shot_timer;
    /* 0x0A */ u16 frames_left;
    /* 0x0C */ u8 unused_0C;
    /* 0x0D */ u8 direction;
    /* 0x0E */ u16 second_kind;        /* 0 and 1 in turn, in the second loop only */
    /* 0x10 */ u8 unused_10[0x10];
} Stage5Midboss3Sweep;

typedef struct {
    /* 0x00 */ u8 unused_00[7];
    /* 0x07 */ u8 other_07;
    /* 0x08 */ u8 unused_08[6];
    /* 0x0E */ u16 hit_by;
    /* 0x10 */ u16 dying_frames;
    /* 0x12 */ u8 unused_12[0xC];
    /* 0x1E */ u8 dying;
    /* 0x1F */ u8 gone;
} Stage5Midboss3Damage;

#define STAGE5_MIDBOSS3(pointer) ((Stage5Midboss3State *)(pointer))
#define STAGE5_MIDBOSS3_SPIRAL(pointer) (&((Stage5Midboss3Spiral *)(pointer))[1])
#define STAGE5_MIDBOSS3_SWEEP(pointer) (&((Stage5Midboss3Sweep *)(pointer))[2])
#define STAGE5_MIDBOSS3_DAMAGE(pointer) (&((Stage5Midboss3Damage *)(pointer))[3])

void stage5_midboss3_spiral_start(void);
void stage5_midboss3_spiral(void);
void stage5_midboss3_sweep_start(void);
void stage5_midboss3_sweep(void);
void stage5_midboss3_dying(void);

s32 enemy_set_entity_count(s32);

s32 stage5_midboss3_first(void) {
    return enemy_set_entity_count(3);
}

s32 enemy_set_task_state();
s32 enemy_init_entities();
s32 enemy_path_start();
s32 sprite_palette_load();
s32 slowdown_allow_with_boss();
extern u8 D_00261AF0[];
extern u8 D_00265AB0[];
extern u8 D_00265AD0[];
extern u16 g_enemy_signal_2;
extern s16 g_bullet_limit_raised_1[];
extern s8 enemy_move_end_requested;

void stage5_midboss3_start(void) {
    reg_a0 = D_00265AD0;
    enemy_init_entities();
    reg_a0 = D_00265AB0;
    reg_d0.h[0] = 0xF;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = 0x10;
        g_bullet_limit_raised_1[0] = 1;
        g_enemy_signal_2 = 1;
        reg_a0 = D_00261AF0;
        sprite_palette_load();
        slowdown_allow_with_boss();
    }
}


s32 ground_speeds_request();
s32 enemy_hitbox_debug_draw();
s32 enemy_remove();
s32 sfx_explosion_extra_1();
s32 sprite_draw_layer1();
s32 score_add_no_chain();
s32 score_add();
s32 midboss_explode_by_table();
s32 entity_follow_scroll();
s32 aim_at_player();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u8 D_00265B40[];
extern u8 D_00265B60[];
extern s16 g_slowdown_off;
extern s16 g_slowdown_boss_allowed;
extern u16 g_enemy_signal_2;
extern u16 g_bullets_blocked;
extern u16 g_enemies_stopped;

void stage5_midboss3_main(void) {
    u16 temp_a0;
    u16 temp_a0_4;
    u8 temp_a0_2;
    u8 temp_a0_3;

    reg_d0.h[0] = 0x10;
    reg_a0 = D_00261AF0;
    sprite_palette_load();
    if (g_enemies_stopped == 0) {
        if (STAGE5_MIDBOSS3_DAMAGE(reg_a6)->gone != 0) {
            g_enemy_signal_2 = 0;
            reg_d0.h[0] = 0x20;
            reg_d1.h[0] = 0x20;
            ground_speeds_request();
            enemy_remove();
            return;
        }
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
            STAGE5_MIDBOSS3_DAMAGE(reg_a6)->hit_by = (u16) reg_d1.h[0];
            score_add_no_chain();
            reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
            reg_d0.b[0] ^= 0xF;
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            reg_d0.w = 0x7FFF;
            reg_d0.h[0] -= ENTITY(reg_a6)->hp.h;
            reg_tmp.h[1] = STAGE5_MIDBOSS3(reg_a5)->hp[0];
            reg_tmp.h[0] = STAGE5_MIDBOSS3(reg_a5)->hp[1];
            reg_tmp.w -= reg_d0.w;
            STAGE5_MIDBOSS3(reg_a5)->hp[0] = (u16) reg_tmp.h[1];
            STAGE5_MIDBOSS3(reg_a5)->hp[1] = (u16) reg_tmp.h[0];
            ENTITY(reg_a6)->hp.h = 0x7FFFU;
            reg_tmp.h[1] = STAGE5_MIDBOSS3(reg_a5)->hp[0];
            reg_tmp.h[0] = STAGE5_MIDBOSS3(reg_a5)->hp[1];
            if ((s32) reg_tmp.w < 0) {
                reg_d0.w = 0x1000;
                score_add();
                vibration_start_pad1(0xB4, 0x50);
                vibration_start_pad2(0xB4, 0x50);
                reg_d0.h[0] = 0x20;
                reg_d1.h[0] = 0x20;
                ground_speeds_request();
                ENTITY(reg_a6)->flags.h = 0x8000;
                STAGE5_MIDBOSS3_DAMAGE(reg_a6)->dying = 1U;
                g_enemy_signal_2 = 0;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_a1 = D_00265B60;
                midboss_explode_by_table();
                sfx_explosion_extra_1();
                goto normal_palette;
            }
        } else {
normal_palette:
            ENTITY(reg_a6)->attr.b.palette = 0x10U;
        }
        stage5_midboss3_dying();
        reg_d0.w = 0;
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp.w = (u32) (s16) reg_d0.h[0];
        reg_d0.w = reg_tmp.w;
        reg_d0.w += 0x4000;
        if ((s32) reg_d0.w < 0x801) {
            if (STAGE5_MIDBOSS3(reg_a5)->seen != 0) {
                g_enemy_signal_2 = 0;
                enemy_remove();
                return;
            }
            goto follow_scroll;
        }
        STAGE5_MIDBOSS3(reg_a5)->seen = 1U;
follow_scroll:
        entity_follow_scroll();
        if (STAGE5_MIDBOSS3_DAMAGE(reg_a6)->dying == 0) {
            if (STAGE5_MIDBOSS3(reg_a5)->step == 0) {
                STAGE5_MIDBOSS3(reg_a5)->wait -= 1;
                if (STAGE5_MIDBOSS3(reg_a5)->wait == 0) {
                    STAGE5_MIDBOSS3(reg_a5)->step = 1U;
                }
            }
            if (STAGE5_MIDBOSS3(reg_a5)->step == 1) {
                reg_tmp.b[0] = STAGE5_MIDBOSS3(reg_a5)->frame_timer.b.countdown;
                STAGE5_MIDBOSS3(reg_a5)->frame_timer.b.countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    STAGE5_MIDBOSS3(reg_a5)->frame_timer.b.countdown = (u8) STAGE5_MIDBOSS3(reg_a5)->frame_timer.b.interval;
                    STAGE5_MIDBOSS3(reg_a5)->frame += 4;
                    if ((s32) STAGE5_MIDBOSS3(reg_a5)->frame >= 0x1C) {
                        STAGE5_MIDBOSS3(reg_a5)->frame = 0x1CU;
                        g_slowdown_boss_allowed = 0;
                        g_slowdown_off = 0;
                        STAGE5_MIDBOSS3(reg_a5)->step = 2U;
                        STAGE5_MIDBOSS3(reg_a5)->unread_1E = 0x1020;
                        STAGE5_MIDBOSS3(reg_a5)->unread_20 = 0x606;
                        STAGE5_MIDBOSS3(reg_a5)->unread_22 = 6;
                        STAGE5_MIDBOSS3(reg_a5)->unread_24 = 0x2030;
                        STAGE5_MIDBOSS3(reg_a5)->unread_26 = 0x404;
                        STAGE5_MIDBOSS3(reg_a5)->unread_28 = 4;
                        STAGE5_MIDBOSS3(reg_a5)->unread_2B = 0;
                        STAGE5_MIDBOSS3(reg_a5)->unread_2A = 0;
                        STAGE5_MIDBOSS3(reg_a5)->shot_timer.both = 0x6040;
                        STAGE5_MIDBOSS3(reg_a5)->attack_step = 1U;
                    }
                }
            }
            if (STAGE5_MIDBOSS3(reg_a5)->step == 2) {
                reg_tmp.b[0] = STAGE5_MIDBOSS3(reg_a5)->shot_timer.b.countdown;
                STAGE5_MIDBOSS3(reg_a5)->shot_timer.b.countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    STAGE5_MIDBOSS3(reg_a5)->shot_timer.b.countdown = STAGE5_MIDBOSS3(reg_a5)->shot_timer.b.interval;
                    if (g_bullets_blocked == 0) {
                        temp_a0 = 0xFA80 & 0xFFFF;
                        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d0.h[0] += temp_a0;
                        reg_d1.h[0] += 0x7FFF + 0x7801;
                        aim_at_player();
                        if (cond_flag == 0) {
                            reg_d0.w = 0xD;
                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d2.w += 0xFA7FF800;
                            reg_d4.w = 0;
                            reg_d3.w = 0;
                            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d0.h[0] += 0x7FFF + 0x7A81;
                            reg_d1.h[0] += 0x800;
                            aim_at_player();
                            reg_d0.w = 0xD;
                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d2.w += 0xFA800800;
                            reg_d4.w = 0;
                            reg_d3.w = 0;
                            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d0.h[0] += 0xF80;
                            reg_d1.h[0] += 0x7FFF + 0x7941;
                            aim_at_player();
                            reg_d0.w = 0xD;
                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d2.w += 0x0F7FF940;
                            reg_d4.w = 0;
                            reg_d3.w = 0;
                            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d0.h[0] += 0xF80;
                            reg_d1.h[0] += 0x6C0;
                            aim_at_player();
                            reg_d0.w = 0xD;
                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d2.w += 0x0F8006C0;
                            reg_d4.w = 0;
                            reg_d3.w = 0;
                            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d0.h[0] += 0x13C0;
                            reg_d1.h[0] += 0x7FFF + 0x7C01;
                            aim_at_player();
                            reg_d0.w = 0xD;
                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d2.w += 0x13BFFC00;
                            reg_d4.w = 0;
                            reg_d3.w = 0;
                            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d0.h[0] += 0x13C0;
                            reg_d1.h[0] += 0x400;
                            aim_at_player();
                            reg_d0.w = 0xD;
                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d2.w += 0x13C00400;
                            reg_d4.w = 0;
                            reg_d3.w = 0;
                        }
                    }
                }
            }
            if (STAGE5_MIDBOSS3(reg_a5)->attack_step == 1) {
                STAGE5_MIDBOSS3_SPIRAL(reg_a6)->wait -= 1;
                if (STAGE5_MIDBOSS3_SPIRAL(reg_a6)->wait == 0) {
                    stage5_midboss3_spiral_start();
                    STAGE5_MIDBOSS3(reg_a5)->attack_step = 2U;
                }
            }
            temp_a0_2 = STAGE5_MIDBOSS3(reg_a5)->attack_step;
            if (temp_a0_2 == 2) {
                stage5_midboss3_spiral();
                if (cond_flag == 0) {
                    STAGE5_MIDBOSS3(reg_a5)->attack_step = 3U;
                    stage5_midboss3_sweep_start();
                }
            }
            temp_a0_3 = STAGE5_MIDBOSS3(reg_a5)->attack_step;
            if (temp_a0_3 == 3) {
                stage5_midboss3_sweep();
                if (cond_flag == 0) {
                    STAGE5_MIDBOSS3(reg_a5)->attack_step = 2U;
                    stage5_midboss3_spiral_start();
                }
            }
        }
        goto draw;
    }
draw:
    if (STAGE5_MIDBOSS3_DAMAGE(reg_a6)->dying == 0) {
        reg_a0 = D_00265B40;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a0_4 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a0_4;
        reg_d1.w += 0xE400EA00;
        reg_d3.h[0] = 0x1CB0;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
        sprite_draw_layer1();
        reg_a0 = reg_a6;
        enemy_hitbox_debug_draw();
    }
}

s32 rng_next_unsigned();

void stage5_midboss3_spiral_start(void) {
    STAGE5_MIDBOSS3_SPIRAL(reg_a6)->frames_left = 0x258;
    STAGE5_MIDBOSS3_SPIRAL(reg_a6)->shot_timer.both = 0x104;
    rng_next_unsigned();
    reg_d0.h[0] &= 0x1F;
    STAGE5_MIDBOSS3_SPIRAL(reg_a6)->direction = 0x40U;
    STAGE5_MIDBOSS3_SPIRAL(reg_a6)->direction -= reg_d0.b[0];
    STAGE5_MIDBOSS3_SPIRAL(reg_a6)->turn = 0U;
    reg_d7.h[0] = 0x3B;
    do {
        STAGE5_MIDBOSS3_SPIRAL(reg_a6)->turn += 1;
        reg_d0.b[0] = STAGE5_MIDBOSS3_SPIRAL(reg_a6)->turn;
        STAGE5_MIDBOSS3_SPIRAL(reg_a6)->direction += reg_d0.b[0];
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

s32 bullet_fire256_2way();

void stage5_midboss3_spiral(void) {
    u8 var_a0;

    cond_flag = 0;
    reg_tmp.b[0] = STAGE5_MIDBOSS3_SPIRAL(reg_a6)->shot_timer.b.countdown;
    STAGE5_MIDBOSS3_SPIRAL(reg_a6)->shot_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        var_a0 = 0x10000000;
        STAGE5_MIDBOSS3_SPIRAL(reg_a6)->shot_timer.b.countdown = (u8) STAGE5_MIDBOSS3_SPIRAL(reg_a6)->shot_timer.b.interval;
        STAGE5_MIDBOSS3_SPIRAL(reg_a6)->turn += 1;
        reg_d0.b[0] = STAGE5_MIDBOSS3_SPIRAL(reg_a6)->turn;
        STAGE5_MIDBOSS3_SPIRAL(reg_a6)->direction += reg_d0.b[0];
        reg_d1.b[0] = STAGE5_MIDBOSS3_SPIRAL(reg_a6)->direction;
        reg_d0.w = 0x50003;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d2.w += 0x10000000;
        reg_d1.b[0] -= 0x18;
        reg_d7.w = 3;
        reg_d4.w = 0;
        reg_d3.w = 0;
        do {
            reg_d6.h[0] = reg_d1.h[0];
            bullet_fire256_2way();
            reg_d1.h[0] = reg_d6.h[0];
            reg_d1.b[0] += 0x80;
            reg_d6.h[0] = reg_d1.h[0];
            bullet_fire256_2way();
            reg_d1.h[0] = reg_d6.h[0];
            reg_d1.b[0] += 0x8C;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    STAGE5_MIDBOSS3_SPIRAL(reg_a6)->frames_left -= 1;
    if (STAGE5_MIDBOSS3_SPIRAL(reg_a6)->frames_left != 0) {
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

extern u16 g_game_frame;
extern u16 g_loop;

void stage5_midboss3_sweep_start(void) {
    STAGE5_MIDBOSS3_SWEEP(reg_a6)->second_kind = 0;
    STAGE5_MIDBOSS3_SWEEP(reg_a6)->frames_left = 0x258;
    STAGE5_MIDBOSS3_SWEEP(reg_a6)->shot_timer.both = 0x202;
    reg_d0.w = 3;
    if (g_loop != 0) {
        reg_d0.w = 2;
    }
    if (!(g_game_frame & 2)) {
        STAGE5_MIDBOSS3_SWEEP(reg_a6)->shot_timer.b.countdown += reg_d0.b[0];
    }
    STAGE5_MIDBOSS3_SWEEP(reg_a6)->shot_timer.b.interval += reg_d0.b[0];
    rng_next_unsigned();
    reg_d0.b[0] -= 0x20;
    STAGE5_MIDBOSS3_SWEEP(reg_a6)->direction = (u8) reg_d0.b[0];
}

s32 bullet_fire256_fixed();
s32 bullet_fire256_double();

void stage5_midboss3_sweep(void) {
    u32 temp_a0;
    u8 temp_a1;

    STAGE5_MIDBOSS3_SWEEP(reg_a6)->direction += 2;
    STAGE5_MIDBOSS3_SWEEP(reg_a6)->shot_timer.b.countdown -= 1;
    if ((s8) STAGE5_MIDBOSS3_SWEEP(reg_a6)->shot_timer.b.countdown < 0) {
        reg_d0.b[0] = STAGE5_MIDBOSS3_SWEEP(reg_a6)->direction;
        reg_d0.b[0] += 0x10;
        if ((s32) reg_d0.b[0] < 0x21) {
            if ((s8) STAGE5_MIDBOSS3_SWEEP(reg_a6)->shot_timer.b.countdown > -2) {
                goto no_reload;
            }
        } else if ((s8) STAGE5_MIDBOSS3_SWEEP(reg_a6)->shot_timer.b.countdown >= -2) {
            goto no_reload;
        }
        STAGE5_MIDBOSS3_SWEEP(reg_a6)->shot_timer.b.countdown = (u8) STAGE5_MIDBOSS3_SWEEP(reg_a6)->shot_timer.b.interval;
no_reload:;
    } else {
        temp_a1 = STAGE5_MIDBOSS3_SWEEP(reg_a6)->direction;
        reg_d1.b[0] = temp_a1;
        reg_d0.w = 0xFFFD0004;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        temp_a0 = reg_d2.w;
        reg_d4.w = 0;
        reg_d3.w = 0;
        reg_d2.w = temp_a0 + 0x10000000;
        if (g_loop == 0) {
            bullet_fire256_double();
            reg_d1.b[0] *= -1;
            bullet_fire256_double();
        } else {
            if (STAGE5_MIDBOSS3_SWEEP(reg_a6)->second_kind == 0) {
                bullet_fire256_double();
                reg_d1.b[0] *= -1;
                bullet_fire256_double();
            } else {
                bullet_fire256_fixed();
                reg_d1.b[0] *= -1;
                bullet_fire256_fixed();
            }
            STAGE5_MIDBOSS3_SWEEP(reg_a6)->second_kind += 1;
            STAGE5_MIDBOSS3_SWEEP(reg_a6)->second_kind &= 1;
        }
    }
    STAGE5_MIDBOSS3_SWEEP(reg_a6)->frames_left -= 1;
    if (STAGE5_MIDBOSS3_SWEEP(reg_a6)->frames_left != 0) {
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

s32 bullet_cancel_with_flags(void *);

void stage5_midboss3_dying(void) {
    if ((STAGE5_MIDBOSS3_DAMAGE(reg_a6)->dying != 0) && (STAGE5_MIDBOSS3_DAMAGE(reg_a6)->other_07 == 0)) {
        reg_d1.h[0] = STAGE5_MIDBOSS3_DAMAGE(reg_a6)->hit_by;
        bullet_cancel_with_flags(reg_a6);
        STAGE5_MIDBOSS3_DAMAGE(reg_a6)->dying_frames -= 1;
        if (STAGE5_MIDBOSS3_DAMAGE(reg_a6)->dying_frames == 0) {
            STAGE5_MIDBOSS3_DAMAGE(reg_a6)->gone = 1;
        }
    }
    cond_flag = 0;
}

u8 D_00265AB0[368] = {
    0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xC0,
    0x00, 0xA0, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x14,
    0x00, 0x14, 0x00, 0x14, 0xFF, 0x7F, 0x00, 0x08, 0x10, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x08, 0x08, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x5F, 0x1F, 0x00, 0x00, 0x60, 0x1F, 0x00, 0x00, 0x61, 0x1F, 0x00, 0x00, 0x62, 0x1F,
    0x00, 0x00, 0x63, 0x1F, 0x00, 0x00, 0x64, 0x1F, 0x00, 0x00, 0x65, 0x1F, 0x00, 0x00, 0x66, 0x1F,
    0x02, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x04, 0x00, 0x00, 0x04, 0x00, 0x85, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x8D, 0x00, 0x00, 0x00, 0x00, 0xF8,
    0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x08, 0x00, 0x40, 0x00, 0x00, 0xF0, 0x00, 0xFC, 0x00, 0x00,
    0x08, 0x00, 0x85, 0x00, 0x00, 0x00, 0x00, 0xE8, 0x00, 0xFC, 0x00, 0x00, 0x0A, 0x00, 0x8D, 0x00,
    0x00, 0x00, 0x00, 0xE8, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x85, 0x00, 0x00, 0x00, 0x00, 0xE8, 0x00, 0xF6, 0x00, 0x00,
    0x04, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x06, 0x00, 0x00, 0x06, 0x00, 0x85, 0x00,
    0x00, 0x00, 0x00, 0xDC, 0x00, 0x02, 0x00, 0x00, 0x08, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0xFC,
    0x00, 0xF8, 0x00, 0x00, 0x0A, 0x00, 0x8C, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x0A, 0x00, 0x00,
    0x0C, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x0C, 0x00, 0x00, 0x0E, 0x00, 0x85, 0x00,
    0x00, 0x00, 0x00, 0xE4, 0x00, 0xF4, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x04, 0x03, 0x00, 0x04, 0x00, 0x1F, 0x00, 0x09, 0x00, 0x00, 0x00,
};
