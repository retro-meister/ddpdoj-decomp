#include "common.h"
#include "arcade_gameplay.h"
#include "entity.h"
#include "explosion.h"
#include "enemy.h"
#include "enemy_kinds.h"
#include "stage5_midboss.h"

/* What mid-boss 4 is first seen as. It asks for the mid-boss when its last frame comes. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 step;                /* 0: waiting, 1: slowing down, 2: the frames run */
    /* 0x17 */ u8 unused_17;
    /* 0x18 */ EnemyTimer frame_timer;
    /* 0x1A */ u16 frame;
    /* 0x1C */ EnemyTimer slow_timer;
    /* 0x1E */ u16 wait;
} Stage5Midboss4ArrivalState;

typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct { u16 y; u16 x; u16 unused_1A; } at_start;
        struct { u8 leaving; u8 unused_17; u16 hp[2]; } now;   /* hp: high word first */
    };
} Stage5Midboss4State;

/* Entities 3 and 4 of mid-boss 4 are not drawn. They hold the values of its movement and of its attacks. */
typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u16 mode;               /* 0: between its points, 1: to the player, 2: zigzag, 3: dying, 4: away */
    /* 0x08 */ u16 step;
    /* 0x0A */ union {
        u16 point;                     /* mode 0: offset of the point in the table */
        u16 passes_left;               /* mode 2 */
    };
    /* 0x0C */ u16 target_y;
    /* 0x0E */ u16 target_x;
    /* 0x10 */ u16 wait;
    /* 0x12 */ u8 unused_12;
    /* 0x13 */ u8 wanted_speed;
    /* 0x14 */ u8 unused_14[0xC];
} Stage5Midboss4Move;

typedef struct {
    /* 0x00 */ EnemyTimer fan_timer;
    /* 0x02 */ EnemyTimer aimed_timer;
    /* 0x04 */ u16 direction;
    /* 0x06 */ u16 frames_left;
} Stage5Midboss4Fan;

typedef struct {
    /* 0x00 */ EnemyTimer timer;
    /* 0x02 */ u16 left;               /* 0 and 1 in turn */
    /* 0x04 */ u16 unused_04[2];
} Stage5Midboss4Beams;

typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u16 attack;             /* 0xFFFF: none, 0: the fan, 1: the wave beams */
    /* 0x08 */ u16 started;
    /* 0x0A */ union {                 /* the attack routines get these in reg_a4 */
        Stage5Midboss4Fan fan;
        Stage5Midboss4Beams beams;
    } values;
    /* 0x12 */ u8 unused_12[0xC];
    /* 0x1E */ u8 fan_longer;
    /* 0x1F */ u8 unused_1F;
} Stage5Midboss4Attack;

#define STAGE5_MIDBOSS4_ARRIVAL(pointer) ((Stage5Midboss4ArrivalState *)(pointer))
#define STAGE5_MIDBOSS4(pointer) ((Stage5Midboss4State *)(pointer))
#define STAGE5_MIDBOSS4_MOVE(pointer) (&((Stage5Midboss4Move *)(pointer))[3])
#define STAGE5_MIDBOSS4_ATTACK(pointer) (&((Stage5Midboss4Attack *)(pointer))[4])
#define STAGE5_MIDBOSS4_FAN(pointer) ((Stage5Midboss4Fan *)(pointer))
#define STAGE5_MIDBOSS4_BEAMS(pointer) ((Stage5Midboss4Beams *)(pointer))

void stage5_midboss4_draw_body(void);
void stage5_midboss4_draw_left_cannon(void);
void stage5_midboss4_draw_right_cannon(void);
void stage5_midboss4_set_move(void);
void stage5_midboss4_move(void);
void stage5_midboss4_move_between_points(void);
void stage5_midboss4_move_to_player();
void stage5_midboss4_move_zigzag(void);
void stage5_midboss4_move_dying(void);
void stage5_midboss4_move_away(void);
void stage5_midboss4_attack_stop(void);
void stage5_midboss4_attack_set(void);
void stage5_midboss4_attack(void);
void stage5_midboss4_attack_fan();
void stage5_midboss4_attack_beams();
void stage5_midboss4_dying(void);
void stage5_midboss4_wave_beam_draw_charge(void);
void stage5_midboss4_wave_beam_draw_burst(void);
void stage5_midboss4_wave_beam_draw_wave(void);

void stage5_midboss4_arrival_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 sprite_palette_load();
extern u8 stage5_midboss4_arrival_start_table[];
extern u8 stage5_midboss4_arrival_start_table_2[];
extern u8 stage5_midboss4_arrival_start_table_3[];
extern u8 stage5_midboss4_arrival_start_table_4[];
extern u8 stage5_midboss4_arrival_start_table_5[];
extern u16 g_side_scroll_x[];

void stage5_midboss4_arrival_start(void) {

    reg_a0 = stage5_midboss4_arrival_start_table_5;
    enemy_init_entities();
    reg_a0 = stage5_midboss4_arrival_start_table_4;
    reg_d0.h[0] = 4;
    enemy_set_task_state();
    reg_tmp.w = 0x30001C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
    reg_d0.h[0] = g_side_scroll_x[0];
    ENTITY(reg_a6)->x.h -= reg_d0.h[0];
    reg_d0.h[0] = 0x12;
    reg_a0 = stage5_midboss4_arrival_start_table;
    sprite_palette_load();
    reg_d0.h[0] = 0x13;
    reg_a0 = stage5_midboss4_arrival_start_table_2;
    sprite_palette_load();
    reg_d0.h[0] = 0x14;
    reg_a0 = stage5_midboss4_arrival_start_table_3;
    sprite_palette_load();
}

s32 enemy_request_start();
s32 entity_follow_scroll();
extern u8 stage5_midboss4_arrival_table[];
extern u16 g_enemies_stopped;

void stage5_midboss4_arrival(void) {
    u16 temp_a1;
    u16 temp_v1;

    if (g_enemies_stopped == 0) {
        if (STAGE5_MIDBOSS4_ARRIVAL(reg_a5)->step == 0) {
            entity_follow_scroll();
            STAGE5_MIDBOSS4_ARRIVAL(reg_a5)->wait -= 1;
            if (STAGE5_MIDBOSS4_ARRIVAL(reg_a5)->wait == 0) {
                STAGE5_MIDBOSS4_ARRIVAL(reg_a5)->step = 1U;
            }
        }
        if (STAGE5_MIDBOSS4_ARRIVAL(reg_a5)->step == 1) {
            entity_velocity();
            reg_tmp.b[0] = STAGE5_MIDBOSS4_ARRIVAL(reg_a5)->slow_timer.b.countdown;
            STAGE5_MIDBOSS4_ARRIVAL(reg_a5)->slow_timer.b.countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                STAGE5_MIDBOSS4_ARRIVAL(reg_a5)->slow_timer.b.countdown = (u8) STAGE5_MIDBOSS4_ARRIVAL(reg_a5)->slow_timer.b.interval;
                ENTITY(reg_a6)->move.b.speed -= 1;
                if (ENTITY(reg_a6)->move.b.speed == 2) {
                    STAGE5_MIDBOSS4_ARRIVAL(reg_a5)->step = 2U;
                }
            }
        }
        if (STAGE5_MIDBOSS4_ARRIVAL(reg_a5)->step == 2) {
            reg_tmp.b[0] = STAGE5_MIDBOSS4_ARRIVAL(reg_a5)->frame_timer.b.countdown;
            STAGE5_MIDBOSS4_ARRIVAL(reg_a5)->frame_timer.b.countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                STAGE5_MIDBOSS4_ARRIVAL(reg_a5)->frame_timer.b.countdown = (u8) STAGE5_MIDBOSS4_ARRIVAL(reg_a5)->frame_timer.b.interval;
                STAGE5_MIDBOSS4_ARRIVAL(reg_a5)->frame += 4;
                temp_v1 = STAGE5_MIDBOSS4_ARRIVAL(reg_a5)->frame;
                if (temp_v1 == 0x40) {
                    enemy_remove();
                    return;
                }
                if (temp_v1 == 0x3C) {
                    reg_d0.w = ENEMY_STAGE5_MIDBOSS4;
                    enemy_request_start();
                    STAGE5_MIDBOSS4(reg_a0)->at_start.y = (u16) ENTITY(reg_a6)->y.h;
                    STAGE5_MIDBOSS4(reg_a0)->at_start.x = (u16) ENTITY(reg_a6)->x.h;
                }
                goto draw;
            }
        }
        goto draw;
    }
draw:
    reg_a0 = (u8 *)stage5_midboss4_arrival_table;
    reg_a0 += STAGE5_MIDBOSS4_ARRIVAL(reg_a5)->frame;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a1 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFC000000;
    reg_d4.w = 0;
    reg_d1.w += 0xE600E600;
    reg_d3.h[0] = 0x1AD0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer1();
}

void stage5_midboss4_first(void) {
    void enemy_set_entity_count(s32 id);
    enemy_set_entity_count(5);
}

extern u8 stage5_midboss4_start_table[];
extern u8 stage5_midboss4_start_table_2[8];
extern u16 g_enemy_signal_1;
extern s16 g_bullet_limit_raised_1[];

void stage5_midboss4_start() {
    u16 temp_a1;

    reg_a0 = stage5_midboss4_start_table;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) STAGE5_MIDBOSS4(reg_a5)->at_start.y;
    temp_a1 = STAGE5_MIDBOSS4(reg_a5)->at_start.x;
    ENTITY(reg_a6)->x.h = temp_a1;
    reg_a0 = stage5_midboss4_start_table_2;
    reg_d0.h[0] = 2;
    enemy_set_task_state();
    g_enemy_signal_1 = 1;
    g_bullet_limit_raised_1[0] = 1;
}

s32 ground_speeds_request();
s32 fade_out_and_release();
s32 score_add_no_chain();
extern u8 D_00265F60[];
extern u16 g_enemy_signal_1;
extern u16 g_scroll_line;

void stage5_midboss4_main(void) {
    u16 temp_v0;
    u16 temp_v0_2;

    if (g_enemies_stopped == 0) {
        if (STAGE5_MIDBOSS4_DAMAGE(reg_a6)->gone != 0) {
            g_enemy_signal_1 = 0;
            reg_d0.h[0] = 0x20;
            reg_d1.h[0] = 0x20;
            ground_speeds_request();
            enemy_remove();
            return;
        }
        if ((STAGE5_MIDBOSS4(reg_a5)->now.leaving == 0) && (STAGE5_MIDBOSS4_DAMAGE(reg_a6)->dying == 0) && (g_scroll_line == 0xE0)) {
            STAGE5_MIDBOSS4(reg_a5)->now.leaving = 1U;
            stage5_midboss4_attack_stop();
            reg_d0.w = 4;
            stage5_midboss4_set_move();
        }
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        reg_d1.b[0] |= ENTITY(reg_a6)[1].flags.b[1];
        reg_d1.b[0] |= ENTITY(reg_a6)[2].flags.b[1];
        reg_d1.h[0] &= 0x5C;
        if (reg_d1.h[0] != 0) {
            STAGE5_MIDBOSS4_DAMAGE(reg_a6)->hit_by = (u16) reg_d1.h[0];
            reg_d0.b[0] = 0xA3;
            ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
            ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
            ENTITY(reg_a6)[2].flags.b[1] &= reg_d0.b[0];
            score_add_no_chain();
            reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
            reg_d0.b[0] ^= 0xD;
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            reg_d0.b[0] = ENTITY(reg_a6)[1].attr.b.palette;
            reg_d0.b[0] ^= 0xD;
            ENTITY(reg_a6)[1].attr.b.palette = (u8) reg_d0.b[0];
            reg_d0.b[0] = ENTITY(reg_a6)[2].attr.b.palette;
            reg_d0.b[0] ^= 0xD;
            ENTITY(reg_a6)[2].attr.b.palette = (u8) reg_d0.b[0];
            reg_d2.w = 0x7FFF;
            reg_d2.h[0] -= ENTITY(reg_a6)->hp.h;
            reg_d3.w = 0x7FFF;
            reg_d3.h[0] -= ENTITY(reg_a6)[1].hp.h;
            if ((s32) reg_d2.w < (s32) reg_d3.w) {
                reg_d2.w = reg_d3.w;
            }
            reg_d3.w = 0x7FFF;
            reg_d3.h[0] -= ENTITY(reg_a6)[2].hp.h;
            if ((s32) reg_d2.w < (s32) reg_d3.w) {
                reg_d2.w = reg_d3.w;
            }
            reg_d0.h[0] = 0x7FFF;
            ENTITY(reg_a6)->hp.h = (u16) reg_d0.h[0];
            ENTITY(reg_a6)[1].hp.h = (u16) reg_d0.h[0];
            ENTITY(reg_a6)[2].hp.h = (u16) reg_d0.h[0];
            if (STAGE5_MIDBOSS4(reg_a5)->now.leaving == 0) {
                reg_tmp.h[1] = STAGE5_MIDBOSS4(reg_a5)->now.hp[0];
                reg_tmp.h[0] = STAGE5_MIDBOSS4(reg_a5)->now.hp[1];
                reg_tmp.w -= reg_d2.w;
                STAGE5_MIDBOSS4(reg_a5)->now.hp[0] = (u16) reg_tmp.h[1];
                STAGE5_MIDBOSS4(reg_a5)->now.hp[1] = (u16) reg_tmp.h[0];
                if ((s32) reg_tmp.w < 0) {
                    ENTITY(reg_a6)->flags.h = 0x8000;
                    ENTITY(reg_a6)[1].flags.h = 0x8000;
                    ENTITY(reg_a6)[2].flags.h = 0x8000;
                    stage5_midboss4_attack_stop();
                    reg_d0.w = 3;
                    stage5_midboss4_set_move();
                    STAGE5_MIDBOSS4_DAMAGE(reg_a6)->dying = 1U;
                    reg_d0.h[0] = 0x20;
                    reg_d1.h[0] = 0x20;
                    g_enemy_signal_1 = 0;
                    ground_speeds_request();
                    reg_a0 = (u8 *)D_00265F60;
                    fade_out_and_release();
                    goto normal_palette;
                }
            }
        } else {
normal_palette:
            reg_d0.w = 0x12;
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            ENTITY(reg_a6)[1].attr.b.palette = (u8) reg_d0.b[0];
            ENTITY(reg_a6)[2].attr.b.palette = (u8) reg_d0.b[0];
        }
        stage5_midboss4_dying();
        stage5_midboss4_move();
        reg_d0.h[1] = ENTITY(reg_a6)->y.h;
        reg_d0.h[0] = ENTITY(reg_a6)->x.h;
        ENTITY(reg_a6)[1].y.h = (u16) reg_d0.h[1];
        ENTITY(reg_a6)[1].x.h = (u16) reg_d0.h[0];
        reg_tmp.h[1] = ENTITY(reg_a6)[1].y.h;
        reg_tmp.h[0] = ENTITY(reg_a6)[1].x.h;
        reg_tmp.w += 0xF6FFF800;
        ENTITY(reg_a6)[1].y.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)[1].x.h = (u16) reg_tmp.h[0];
        reg_d1.h[0] = ENTITY(reg_a6)[1].offset_y.h;
        ENTITY(reg_a6)[1].y.h += reg_d1.h[0];
        ENTITY(reg_a6)[2].y.h = (u16) reg_d0.h[1];
        ENTITY(reg_a6)[2].x.h = (u16) reg_d0.h[0];
        reg_tmp.h[1] = ENTITY(reg_a6)[2].y.h;
        reg_tmp.h[0] = ENTITY(reg_a6)[2].x.h;
        reg_tmp.w += 0xF7000800;
        ENTITY(reg_a6)[2].y.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)[2].x.h = (u16) reg_tmp.h[0];
        reg_d1.h[0] = ENTITY(reg_a6)[2].offset_y.h;
        ENTITY(reg_a6)[2].y.h += reg_d1.h[0];
        stage5_midboss4_attack();
        temp_v0 = ENTITY(reg_a6)[1].offset_y.h;
        if (temp_v0 != 0) {
            ENTITY(reg_a6)[1].offset_y.h = (u16) (temp_v0 - 0x40);
            if (0 >= (s16) ENTITY(reg_a6)[1].offset_y.h) {
                ENTITY(reg_a6)[1].offset_y.h = 0U;
            }
        }
        temp_v0_2 = ENTITY(reg_a6)[2].offset_y.h;
        if (temp_v0_2 != 0) {
            ENTITY(reg_a6)[2].offset_y.h = (u16) (temp_v0_2 - 0x40);
            if (0 >= (s16) ENTITY(reg_a6)[2].offset_y.h) {
                ENTITY(reg_a6)[2].offset_y.h = 0U;
            }
        }
        goto draw;
    }
draw:
    stage5_midboss4_draw_body();
    stage5_midboss4_draw_left_cannon();
    stage5_midboss4_draw_right_cannon();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x20;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x40;
    enemy_hitbox_debug_draw();
}

void stage5_midboss4_draw_body(void) {
    u16 temp_a0;
    u16 temp_a1;

    reg_d2.w = 0x1E7F;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a1 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xF2000000;
    reg_d4.w = 0;
    reg_d1.w += 0xF000E600;
    reg_d3.h[0] = 0x10D0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer4();
    reg_d2.w = 0x1E7C;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xEA00E600;
    reg_d3.h[0] = 0x16D0;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer4();
}

void stage5_midboss4_draw_left_cannon(void)
{
    u8 *object = reg_a6;

    reg_d2.w = 0x1E7D;
    reg_d1.h[1] = ENTITY(object)[1].y.h;
    reg_d1.h[0] = ENTITY(object)[1].x.h;
    reg_d1.w += 0xF600F800U;
    reg_d3.h[0] = 0xA40;
    reg_d4.w = 0;
    *(u8 *)&reg_d4 = ENTITY(object)[1].attr.b.palette;
    sprite_draw_layer4();
}

void stage5_midboss4_draw_right_cannon(void)
{
    u8 *object = reg_a6;

    reg_d2.w = 0x1E7E;
    reg_d1.h[1] = ENTITY(object)[2].y.h;
    reg_d1.h[0] = ENTITY(object)[2].x.h;
    reg_d4.w = 0;
    reg_d1.w += 0xF600F800U;
    reg_d3.h[0] = 0xA40;
    *(u8 *)&reg_d4 = ENTITY(object)[2].attr.b.palette;
    sprite_draw_layer4();
}

void stage5_midboss4_set_move(void) {
    if (STAGE5_MIDBOSS4_MOVE(reg_a6)->mode != reg_d0.h[0]) {
        STAGE5_MIDBOSS4_MOVE(reg_a6)->mode = (u16) reg_d0.h[0];
        STAGE5_MIDBOSS4_MOVE(reg_a6)->step = 0;
    }
}

s32 entity_advance256();                            /* extern */

void stage5_midboss4_move(void) {
    reg_d0.h[0] = STAGE5_MIDBOSS4_MOVE(reg_a6)->mode;
    switch (reg_d0.h[0]) {                          /* irregular */
    case 0:
        stage5_midboss4_move_between_points();
        break;
    case 1:
        stage5_midboss4_move_to_player();
        break;
    case 2:
        stage5_midboss4_move_zigzag();
        break;
    case 3:
        stage5_midboss4_move_dying();
        break;
    case 4:
        stage5_midboss4_move_away();
        break;
    }
    entity_advance256();
}

s32 rng_next_unsigned();
s32 direction256_between();
extern u8 stage5_midboss4_move_between_points_table[];
extern u16 stage5_midboss4_move_between_points_table_2[];

void stage5_midboss4_move_between_points(void) {
    if (STAGE5_MIDBOSS4_MOVE(reg_a6)->step == 0) {
        rng_next_unsigned();
        reg_d0.h[0] &= 7;
        reg_d0.h[0] *= 4;
        STAGE5_MIDBOSS4_MOVE(reg_a6)->point = (u16) reg_d0.h[0];
        STAGE5_MIDBOSS4_MOVE(reg_a6)->step = 1U;
    }
    reg_a0 = (u8 *)stage5_midboss4_move_between_points_table;
    reg_a0 += STAGE5_MIDBOSS4_MOVE(reg_a6)->point;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] -= g_side_scroll_x[0];
    direction256_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_a0 = (u8 *)stage5_midboss4_move_between_points_table;
    reg_a0 += STAGE5_MIDBOSS4_MOVE(reg_a6)->point;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] -= g_side_scroll_x[0];
    distance_between();
    if ((s16) reg_d0.h[0] < 0x81) {
        STAGE5_MIDBOSS4_MOVE(reg_a6)->point += 4;
        if ((s16) STAGE5_MIDBOSS4_MOVE(reg_a6)->point >= 0x24) {
            STAGE5_MIDBOSS4_MOVE(reg_a6)->point = 0U;
        }
    }
    STAGE5_MIDBOSS4_MOVE(reg_a6)->wanted_speed = 5U;
    reg_a4 = (u8 *)(stage5_midboss4_move_between_points_table_2);
next_speed:
    reg_d1.h[0] = *(u16 *)reg_a4;
    reg_a4 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d2.h[0] = *(u16 *)reg_a4;
        reg_a4 += 2;
        if ((s16) reg_d1.h[0] >= (s16) reg_d0.h[0]) {
            STAGE5_MIDBOSS4_MOVE(reg_a6)->wanted_speed = (u8) reg_d2.b[0];
        } else {
            goto next_speed;
        }
    }
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d2.b[0] = STAGE5_MIDBOSS4_MOVE(reg_a6)->wanted_speed;
    if (reg_d1.b[0] != reg_d2.b[0]) {
        if ((s8)(reg_d1.b[0]) >= (s8)(reg_d2.b[0])) {
            ENTITY(reg_a6)->move.b.speed -= 1;
        } else {
            ENTITY(reg_a6)->move.b.speed += 1;
        }
    }
}

s32 target_player_get();
extern u16 stage5_midboss4_move_to_player_table[];
extern u16 *reg_a4_as_u16_p;

void stage5_midboss4_move_to_player(arg0)
    u16 arg0;
{
    u16 var_a0;
    u32 temp_s0;
    u32 temp_s1;

    var_a0 = arg0;
    if (STAGE5_MIDBOSS4_MOVE(reg_a6)->step == 0) {
        STAGE5_MIDBOSS4_MOVE(reg_a6)->step = 1U;
    }
    if (STAGE5_MIDBOSS4_MOVE(reg_a6)->step == 1) {
        target_player_get();
        if (cond_flag == 0) {
            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
            var_a0 = *(u16 *)(reg_a0 + 4);
            reg_d2.h[0] += 0x1E00;
            reg_d3.h[0] = var_a0;
            STAGE5_MIDBOSS4_MOVE(reg_a6)->target_y = (u16) reg_d2.h[0];
            STAGE5_MIDBOSS4_MOVE(reg_a6)->target_x = (u16) reg_d3.h[0];
            goto have_target;
        }
        goto start_beams;
    }
have_target:
    reg_d2.h[0] = STAGE5_MIDBOSS4_MOVE(reg_a6)->target_y;
    temp_s0 = reg_d2.w;
    reg_d3.h[0] = STAGE5_MIDBOSS4_MOVE(reg_a6)->target_x;
    temp_s1 = reg_d3.w;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction256_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_d2.w = temp_s0;
    reg_d3.w = temp_s1;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    distance_between();
    if ((s16) reg_d0.h[0] < 0x601) {
        STAGE5_MIDBOSS4_MOVE(reg_a6)->step = 2U;
    }
    if ((s16) reg_d0.h[0] < 0x101) {
start_beams:
        reg_d0.w = 1;
        stage5_midboss4_attack_set();
        STAGE5_MIDBOSS4_MOVE(reg_a6)->target_y = (u16) ENTITY(reg_a6)->y.h;
        STAGE5_MIDBOSS4_MOVE(reg_a6)->wait = 0x50;
        ENTITY(reg_a6)->move.b.speed = 0U;
        STAGE5_MIDBOSS4_MOVE(reg_a6)->target_x = 0U;
        if ((s16) ENTITY(reg_a6)->x.h < 0x1C01) {
            STAGE5_MIDBOSS4_MOVE(reg_a6)->target_x = 0x3800U;
        }
    }
    ENTITY(reg_a6)->move.b.speed = 0x32U;
    reg_a4_as_u16_p = stage5_midboss4_move_to_player_table;
next_speed:
    reg_d1.h[0] = *reg_a4_as_u16_p;
    reg_a4_as_u16_p += 1;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d2.h[0] = *reg_a4_as_u16_p;
        reg_a4_as_u16_p += 1;
        if ((s16) reg_d1.h[0] >= (s16) reg_d0.h[0]) {
            ENTITY(reg_a6)->move.b.speed = (u8) reg_d2.b[0];
        } else {
            goto next_speed;
        }
    }
}

s32 direction_step_toward();
extern u16 stage5_midboss4_move_zigzag_table[];
extern u16 g_game_frame;

void stage5_midboss4_move_zigzag(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_5;
    u16 temp_a0_6;

    if (STAGE5_MIDBOSS4_MOVE(reg_a6)->step == 0) {
        ENTITY(reg_a6)->move.b.speed = 0U;
        STAGE5_MIDBOSS4_MOVE(reg_a6)->wait -= 1;
        if (STAGE5_MIDBOSS4_MOVE(reg_a6)->wait == 0) {
            STAGE5_MIDBOSS4_MOVE(reg_a6)->passes_left = 2U;
            STAGE5_MIDBOSS4_MOVE(reg_a6)->step = 1U;
        }
    }
    temp_a0 = STAGE5_MIDBOSS4_MOVE(reg_a6)->step;
    if (temp_a0 == 1) {
        reg_d2.h[0] = STAGE5_MIDBOSS4_MOVE(reg_a6)->target_y;
        reg_d3.h[0] = STAGE5_MIDBOSS4_MOVE(reg_a6)->target_x;
        reg_d3.h[0] -= g_side_scroll_x[0];
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        direction256_between();
        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
        reg_d2.h[0] = STAGE5_MIDBOSS4_MOVE(reg_a6)->target_y;
        reg_d3.h[0] = STAGE5_MIDBOSS4_MOVE(reg_a6)->target_x;
        temp_a0_2 = ENTITY(reg_a6)->y.h;
        reg_d0.h[0] = temp_a0_2;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d3.h[0] -= g_side_scroll_x[0];
        distance_between();
        if ((s16) reg_d0.h[0] < 0x81) {
            STAGE5_MIDBOSS4_MOVE(reg_a6)->step = 2U;
            STAGE5_MIDBOSS4_MOVE(reg_a6)->target_y += 0x100;
            if ((s16) STAGE5_MIDBOSS4_MOVE(reg_a6)->target_y >= 0x5A00) {
                STAGE5_MIDBOSS4_MOVE(reg_a6)->target_y = 0x5A00U;
            }
        }
        STAGE5_MIDBOSS4_MOVE(reg_a6)->wanted_speed = 0x12U;
        reg_a4 = (u8 *)(stage5_midboss4_move_zigzag_table);
next_speed:
        reg_d1.h[0] = *(u16 *)reg_a4;
        reg_a4 += 2;
        if ((s16) reg_d1.h[0] != -1) {
            reg_d2.h[0] = *(u16 *)reg_a4;
            reg_a4 += 2;
            if ((s16) reg_d1.h[0] >= (s16) reg_d0.h[0]) {
                STAGE5_MIDBOSS4_MOVE(reg_a6)->wanted_speed = (u8) reg_d2.b[0];
            } else {
                goto next_speed;
            }
        }
    }
    temp_a0_3 = STAGE5_MIDBOSS4_MOVE(reg_a6)->step;
    if (temp_a0_3 == 2) {
        reg_d2.h[0] = STAGE5_MIDBOSS4_MOVE(reg_a6)->target_y;
        reg_d3.h[0] = STAGE5_MIDBOSS4_MOVE(reg_a6)->target_x;
        reg_d3.h[0] -= g_side_scroll_x[0];
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        direction256_between();
        reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
        direction_step_toward();
        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
        reg_d2.h[0] = STAGE5_MIDBOSS4_MOVE(reg_a6)->target_y;
        reg_d3.h[0] = STAGE5_MIDBOSS4_MOVE(reg_a6)->target_x;
        temp_a0_4 = ENTITY(reg_a6)->y.h;
        reg_d0.h[0] = temp_a0_4;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d3.h[0] -= g_side_scroll_x[0];
        distance_between();
        STAGE5_MIDBOSS4_MOVE(reg_a6)->wanted_speed = 4U;
        if ((ENTITY(reg_a6)->move.b.speed == 4) && ((s16) reg_d0.h[0] < 0x1001)) {
            STAGE5_MIDBOSS4_MOVE(reg_a6)->target_y += 0x1C00;
            STAGE5_MIDBOSS4_MOVE(reg_a6)->step = 1U;
            STAGE5_MIDBOSS4_MOVE(reg_a6)->passes_left -= 1;
            if (STAGE5_MIDBOSS4_MOVE(reg_a6)->passes_left == 0) {
                STAGE5_MIDBOSS4_MOVE(reg_a6)->target_x = 0x1C00U;
                STAGE5_MIDBOSS4_MOVE(reg_a6)->step = 3U;
            } else {
                STAGE5_MIDBOSS4_MOVE(reg_a6)->target_x = 0U;
                if ((s16) ENTITY(reg_a6)->x.h < 0x1C01) {
                    STAGE5_MIDBOSS4_MOVE(reg_a6)->target_x = 0x3800U;
                }
            }
        }
    }
    temp_a0_5 = STAGE5_MIDBOSS4_MOVE(reg_a6)->step;
    if (temp_a0_5 == 3) {
        reg_d2.h[0] = STAGE5_MIDBOSS4_MOVE(reg_a6)->target_y;
        reg_d3.h[0] = STAGE5_MIDBOSS4_MOVE(reg_a6)->target_x;
        reg_d3.h[0] -= g_side_scroll_x[0];
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        direction256_between();
        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
        reg_d2.h[0] = STAGE5_MIDBOSS4_MOVE(reg_a6)->target_y;
        reg_d3.h[0] = STAGE5_MIDBOSS4_MOVE(reg_a6)->target_x;
        temp_a0_6 = ENTITY(reg_a6)->y.h;
        reg_d0.h[0] = temp_a0_6;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d3.h[0] -= g_side_scroll_x[0];
        distance_between();
        STAGE5_MIDBOSS4_MOVE(reg_a6)->wanted_speed = 0xAU;
        if ((s16) reg_d0.h[0] < 0x1001) {
            stage5_midboss4_attack_stop();
            STAGE5_MIDBOSS4_MOVE(reg_a6)->wanted_speed = 2U;
            if (ENTITY(reg_a6)->move.b.speed == 2) {
                STAGE5_MIDBOSS4_ATTACK(reg_a6)->fan_longer = 1;
                reg_d0.w = 0;
                stage5_midboss4_attack_set();
            }
        }
    }
    reg_d0.h[0] = g_game_frame;
    reg_d0.h[0] &= 3;
    if (reg_d0.h[0] == 0) {
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.speed;
        reg_d2.b[0] = STAGE5_MIDBOSS4_MOVE(reg_a6)->wanted_speed;
        if (reg_d1.b[0] != reg_d2.b[0]) {
            if ((s8)(reg_d1.b[0]) >= (s8)(reg_d2.b[0])) {
                ENTITY(reg_a6)->move.b.speed -= 1;
            } else {
                ENTITY(reg_a6)->move.b.speed += 1;
            }
        }
    }
}

void stage5_midboss4_move_dying(void) {
    u8 *object = reg_a6;

    if (STAGE5_MIDBOSS4_MOVE(object)->step == 0) {
        ENTITY(object)->move.h = 0x480;
    }
}

void stage5_midboss4_move_away(void) {
    if (STAGE5_MIDBOSS4_MOVE(reg_a6)->step == 0) {
        ENTITY(reg_a6)->move.sh = 0xC40;
        if (ENTITY(reg_a6)->x.sh < 0x1C01) {
            ENTITY(reg_a6)->move.sh = 0xCC0;
        }
    }
    if (ENTITY(reg_a6)->x.sh >= 0x5400) {
        STAGE5_MIDBOSS4_DAMAGE(reg_a6)->gone = 1;
    }
    if (ENTITY(reg_a6)->x.sh < -0x1BFF) {
        STAGE5_MIDBOSS4_DAMAGE(reg_a6)->gone = 1;
    }
}

void stage5_midboss4_attack_stop(void) {
    STAGE5_MIDBOSS4_ATTACK(reg_a6)->attack = 0xFFFF;
    STAGE5_MIDBOSS4_ATTACK(reg_a6)->started = 0;
}

void stage5_midboss4_attack_set(void) {
    STAGE5_MIDBOSS4_ATTACK(reg_a6)->attack = (u16)reg_d0.h[0];
    STAGE5_MIDBOSS4_ATTACK(reg_a6)->started = 0;
}


void stage5_midboss4_attack(void) {
#ifndef DDPDOJ_PC
    extern void stage5_midboss4_attack_fan(s64, u16);
    extern void stage5_midboss4_attack_beams(s64, u16);
#endif
    s64 temp_a0;

    reg_a4 = (u8 *)&STAGE5_MIDBOSS4_ATTACK(reg_a6)->values;
    reg_d0.h[0] = STAGE5_MIDBOSS4_ATTACK(reg_a6)->attack;
    temp_a0 = (s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30;
    if (temp_a0 != -1) {
        if (!(reg_d0.h[0] & 0xFFFF)) {
            ARCADE_REGISTER_CALL(stage5_midboss4_attack_fan, temp_a0, reg_d0.h[0]);
            return;
        }
        ARCADE_REGISTER_CALL(stage5_midboss4_attack_beams, temp_a0, reg_d0.h[0]);
    }
}

s32 bullet_fire256_2way();
extern u16 g_direction64_offsets_2CC[];
extern u16 g_direction64_offsets_432[];
extern u16 g_bullets_blocked;

void stage5_midboss4_attack_fan() {
    u16 temp_a1;

    if (STAGE5_MIDBOSS4_ATTACK(reg_a6)->started == 0) {
        reg_d0.w = 0;
        stage5_midboss4_set_move();
        STAGE5_MIDBOSS4_ATTACK(reg_a6)->started = 1U;
        STAGE5_MIDBOSS4_FAN(reg_a4)->fan_timer.both = 0x124;
        STAGE5_MIDBOSS4_FAN(reg_a4)->aimed_timer.both = 0x120;
        STAGE5_MIDBOSS4_FAN(reg_a4)->direction = 0x80U;
        STAGE5_MIDBOSS4_FAN(reg_a4)->frames_left = 0x100U;
        if (STAGE5_MIDBOSS4_ATTACK(reg_a6)->fan_longer != 0) {
            STAGE5_MIDBOSS4_FAN(reg_a4)->frames_left = 0x140U;
            STAGE5_MIDBOSS4_FAN(reg_a4)->fan_timer.both = 0x112;
        }
    }
    reg_tmp.b[0] = STAGE5_MIDBOSS4_FAN(reg_a4)->fan_timer.b.countdown;
    STAGE5_MIDBOSS4_FAN(reg_a4)->fan_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STAGE5_MIDBOSS4_FAN(reg_a4)->fan_timer.b.countdown = STAGE5_MIDBOSS4_FAN(reg_a4)->fan_timer.b.interval;
        if (g_bullets_blocked == 0) {
            reg_d1.h[0] = STAGE5_MIDBOSS4_FAN(reg_a4)->direction;
            reg_tmp1.w = 0;
            reg_tmp.w = 0;
            reg_tmp.h[0] = STAGE5_MIDBOSS4_FAN(reg_a4)->direction;
            reg_tmp1.h[0] = 0xE;
            reg_tmp.w += reg_tmp1.w;
            STAGE5_MIDBOSS4_FAN(reg_a4)->direction += 0xE;
            if (reg_tmp.h[1] == 0) {
                reg_d0.w = 0xFFFF000B;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d1.b[0] -= 0x79;
                reg_d7.h[0] = 0x16;
                reg_a0 = (u8 *)(g_direction64_offsets_432);
                reg_d4.w = 0;
                reg_d3.w = 0;
                do {
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d3.h[0] += 2;
                    reg_d3.h[0] &= 0xFC;
                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    bullet_fire256_2way();
                    reg_d1.b[0] += 0xB;
                } while ((s16)(--reg_d7.h[0]) >= 0);
            }
        }
    }
    reg_tmp.b[0] = STAGE5_MIDBOSS4_FAN(reg_a4)->aimed_timer.b.countdown;
    STAGE5_MIDBOSS4_FAN(reg_a4)->aimed_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STAGE5_MIDBOSS4_FAN(reg_a4)->aimed_timer.b.countdown = STAGE5_MIDBOSS4_FAN(reg_a4)->aimed_timer.b.interval;
        if (g_bullets_blocked == 0) {
            direction256_to_target_player();
            if (cond_flag == 0) {
                reg_d0.w = 0x30004;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                temp_a1 = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0;
                reg_d2.h[0] = temp_a1;
                reg_a0 = (u8 *)(g_direction64_offsets_2CC);
                reg_d7.b[0] = reg_d1.b[0];
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d4.w = 0;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                bullet_fire256();
                reg_d1.b[0] += 6;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                bullet_fire256();
                reg_d1.b[0] += 6;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                bullet_fire256();
                reg_d1.b[0] = reg_d7.b[0];
                reg_d1.b[0] -= 6;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                bullet_fire256();
                reg_d1.b[0] -= 6;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                bullet_fire256();
            }
        }
    }
    STAGE5_MIDBOSS4_FAN(reg_a4)->frames_left -= 1;
    if (STAGE5_MIDBOSS4_FAN(reg_a4)->frames_left == 0) {
        stage5_midboss4_attack_stop();
        reg_d0.w = 1;
        stage5_midboss4_set_move();
    }
}

s32 spawn_request_add();

#ifdef DDPDOJ_PC
void stage5_midboss4_attack_beams(void)
#else
void stage5_midboss4_attack_beams(arg1)
    u16 arg1;
#endif
{
    u16 var_a1;

#ifndef DDPDOJ_PC
    var_a1 = arg1;
#endif
    if (STAGE5_MIDBOSS4_ATTACK(reg_a6)->started == 0) {
        reg_d0.w = 2;
        stage5_midboss4_set_move();
        STAGE5_MIDBOSS4_BEAMS(reg_a4)->timer.both = 0x2828;
        rng_next_unsigned();
        reg_d0.h[0] &= 1;
        var_a1 = reg_d0.h[0];
        STAGE5_MIDBOSS4_BEAMS(reg_a4)->left = var_a1;
        STAGE5_MIDBOSS4_ATTACK(reg_a6)->started = 1U;
    }
    reg_tmp.b[0] = STAGE5_MIDBOSS4_BEAMS(reg_a4)->timer.b.countdown;
    STAGE5_MIDBOSS4_BEAMS(reg_a4)->timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STAGE5_MIDBOSS4_BEAMS(reg_a4)->timer.b.countdown = STAGE5_MIDBOSS4_BEAMS(reg_a4)->timer.b.interval;
        if (g_bullets_blocked == 0) {
            reg_d0.w = ENEMY_STAGE5_MIDBOSS4_WAVE_BEAM;
            spawn_request_add();
            reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a6);
            STAGE5_MIDBOSS4_WAVE_BEAM(reg_a0)->owner[0] = (u16) reg_tmp.h[1];
            STAGE5_MIDBOSS4_WAVE_BEAM(reg_a0)->owner[1] = (u16) reg_tmp.h[0];
            STAGE5_MIDBOSS4_WAVE_BEAM(reg_a0)->left = (u16) STAGE5_MIDBOSS4_BEAMS(reg_a4)->left;
            STAGE5_MIDBOSS4_BEAMS(reg_a4)->left += 1;
            STAGE5_MIDBOSS4_BEAMS(reg_a4)->left &= 1;
        }
    }
}

s32 explosion_spawn();
s32 explosion_burst_small();
s32 sfx_explosion_air_medium();
s32 sfx_explosion_extra_1();
s32 midboss_explode_by_table();
s32 rng_next();
s32 bullet_cancel_with_flags();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u16 stage5_midboss4_dying_table[];
extern u16 stage5_midboss4_dying_table_2[];

void stage5_midboss4_dying(void) {
    u16 temp_a0_2;
    u16 temp_a0_3;
    u8 temp_a0;

    if (STAGE5_MIDBOSS4_DAMAGE(reg_a6)->dying != 0) {
        reg_d1.h[0] = STAGE5_MIDBOSS4_DAMAGE(reg_a6)->hit_by;
        bullet_cancel_with_flags();
        temp_a0 = STAGE5_MIDBOSS4_DAMAGE(reg_a6)->dying_step;
        if (temp_a0 == 2) {
            STAGE5_MIDBOSS4_DAMAGE(reg_a6)->gone = 1;
            goto over;
        }
        if (temp_a0 == 1) {
            STAGE5_MIDBOSS4_DAMAGE(reg_a6)->blast_timer.b.countdown -= 1;
            if (STAGE5_MIDBOSS4_DAMAGE(reg_a6)->blast_timer.b.countdown == 0) {
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_a1 = (u8 *)(stage5_midboss4_dying_table_2);
                midboss_explode_by_table();
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
                STAGE5_MIDBOSS4_DAMAGE(reg_a6)->blast_timer.b.countdown = 0x10U;
                STAGE5_MIDBOSS4_DAMAGE(reg_a6)->dying_step = 2U;
                vibration_start_pad1(0xB4, 0x3C, 0x10);
                vibration_start_pad2(0xB4, 0x3C);
            }
        }
        if (STAGE5_MIDBOSS4_DAMAGE(reg_a6)->dying_step == 0) {
            reg_tmp.b[0] = STAGE5_MIDBOSS4_DAMAGE(reg_a6)->blast_timer.b.countdown;
            STAGE5_MIDBOSS4_DAMAGE(reg_a6)->blast_timer.b.countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                STAGE5_MIDBOSS4_DAMAGE(reg_a6)->blast_timer.b.countdown = (u8) STAGE5_MIDBOSS4_DAMAGE(reg_a6)->blast_timer.b.interval;
                sfx_explosion_air_medium();
                reg_a1 = (u8 *)(stage5_midboss4_dying_table);
                reg_a1 += STAGE5_MIDBOSS4_DAMAGE(reg_a6)->blast;
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
                STAGE5_MIDBOSS4_DAMAGE(reg_a6)->blast += 0xC;
                if (STAGE5_MIDBOSS4_DAMAGE(reg_a6)->blast == 0x48) {
                    STAGE5_MIDBOSS4_DAMAGE(reg_a6)->blast = 0U;
                    STAGE5_MIDBOSS4_DAMAGE(reg_a6)->blast_rounds -= 1;
                    if (STAGE5_MIDBOSS4_DAMAGE(reg_a6)->blast_rounds == 0) {
                        STAGE5_MIDBOSS4_DAMAGE(reg_a6)->blast_timer.both = 0x1006;
                        STAGE5_MIDBOSS4_DAMAGE(reg_a6)->dying_step = 1U;
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

void stage5_midboss4_wave_beam_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern u16 stage5_midboss4_wave_beam_start_table[];
extern u16 stage5_midboss4_wave_beam_start_table_2[];

void stage5_midboss4_wave_beam_start(void) {
    reg_a0 = (u8 *)(stage5_midboss4_wave_beam_start_table_2);
    enemy_init_entities();
    reg_a0 = (u8 *)(stage5_midboss4_wave_beam_start_table);
    reg_d0.h[0] = 7;
    reg_a1 = (u8 *)(reg_a5 + 0x1C);
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    if (STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->left != 0) {
        ENTITY(reg_a6)->attr.h |= 0x40;
    }
}

s32 sfx_shockwave();
s32 stage5_midboss4_wave_beam_fire();
extern u8 stage5_midboss4_wave_beam_table[];
extern u8 g_no_enemy_bullets;

void stage5_midboss4_wave_beam(void) {
    if (g_no_enemy_bullets != 0) return;
    ENTITY(reg_a6)->hp.sh = 0x7FFF;
    if (g_enemy_signal_1 == 0) goto remove;
    reg_tmp.h[1] = STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->owner[0];
    reg_tmp.h[0] = STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->owner[1];
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[1] = ENTITY(reg_a0)->y.h;
    reg_d0.h[0] = ENTITY(reg_a0)->x.h;
    if (STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->left != 0) {
        reg_d0.w += 0xF1FFF880;
    } else {
        reg_d0.w += 0xF2000780;
    }
    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
    if (!(STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->parts & 1)) goto charge_done;
    reg_tmp.b[0] = STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->charge_timer.b.countdown;
    STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->charge_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto charge_done;
    STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->charge_timer.b.countdown = STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->charge_timer.b.interval;
    STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->charge_frame += 4;
    if ((s16) STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->charge_frame < 0x60) goto charge_done;
    STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->charge_frame = 0;
    STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->parts &= 0xFE;
    STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->parts |= 0xE;
    stage5_midboss4_wave_beam_fire();
    sfx_shockwave();
    ENTITY(reg_a6)->flags.h = 0x8001;
charge_done:
    if (!(STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->parts & 2)) goto burst_done;
    reg_tmp.b[0] = STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->burst_timer.b.countdown;
    STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->burst_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto burst_done;
    STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->burst_timer.b.countdown = STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->burst_timer.b.interval;
    STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->burst_frame += 0x10;
    if ((s16) STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->burst_frame < 0x90) goto burst_done;
    STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->burst_frame = 0;
    STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->parts &= 0xFD;
burst_done:
    if (!(STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->parts & 4)) goto wave_done;
    reg_tmp.b[0] = STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->wave_timer.b.countdown;
    STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->wave_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto wave_hitbox;
    STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->wave_timer.b.countdown = STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->wave_timer.b.interval;
    STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->wave_frame += 0x10;
    if ((s16) STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->wave_frame < 0xD0) goto wave_hitbox;
    STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->wave_frame = 0;
remove:
    enemy_remove();
    return;
wave_hitbox:
    reg_a0 = (u8 *)stage5_midboss4_wave_beam_table;
    reg_d0.h[0] = STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->wave_frame;
    reg_d0.h[0] >>= 1;
    reg_a0 += reg_d0.h[0];
    ENTITY(reg_a6)->hit_y_plus.h = *(u16 *)reg_a0;
    ENTITY(reg_a6)->hit_y_minus.h = *(u16 *)(reg_a0 + 2);
    ENTITY(reg_a6)->hit_x_plus.h = *(u16 *)(reg_a0 + 4);
    ENTITY(reg_a6)->hit_x_minus.h = *(u16 *)(reg_a0 + 6);
    if (STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->left != 0) {
        ENTITY(reg_a6)->hit_x_plus.h = *(u16 *)(reg_a0 + 6);
        ENTITY(reg_a6)->hit_x_minus.h = *(u16 *)(reg_a0 + 4);
    }
wave_done:
    if (!(STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->parts & 8)) goto draw;
    reg_tmp.h[1] = STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->owner[0];
    reg_tmp.h[0] = STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->owner[1];
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    if (STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->left != 0) {
        reg_a0 = reg_a0 + 0x26;
    } else {
        reg_a0 = reg_a0 + 0x46;
    }
    if (*(u16 *)reg_a0 == 0x280) goto draw;
    *(u16 *)reg_a0 += 0x100;
    if ((s16) *(u16 *)reg_a0 < 0x280) goto draw;
    *(u16 *)reg_a0 = 0x280;
    STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->parts &= 0xF7;
draw:
    stage5_midboss4_wave_beam_draw_charge();
    stage5_midboss4_wave_beam_draw_burst();
    stage5_midboss4_wave_beam_draw_wave();
    reg_a0 = (u8 *)reg_a6;
    enemy_hitbox_debug_draw();
}

extern u8 stage5_midboss4_wave_beam_draw_charge_table[];

void stage5_midboss4_wave_beam_draw_charge(void) {
    if ((STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->parts) & 1) {
        reg_a0 = stage5_midboss4_wave_beam_draw_charge_table;
        reg_a0 += STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->charge_frame;
        reg_d2.h[1] = *(u16 *)(reg_a0 + 0);
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.w += 0xFE00FC00;
        reg_d3.h[0] = 0x220;
        reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
        sprite_draw_layer5();
    }
}

extern u8 stage5_midboss4_wave_beam_draw_burst_table[];

void stage5_midboss4_wave_beam_draw_burst(void) {
    u32 temp_a0;

    if (STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->parts & 2) {
        reg_a0 = (u8 *)stage5_midboss4_wave_beam_draw_burst_table;
        reg_a0 += STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->burst_frame;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] += 0x180;
        if (STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->left != 0) {
            reg_d1.h[0] += 0x7FFF + 0x7E01;
        } else {
            reg_d1.h[0] += 0x100;
        }
        temp_a0 = reg_d1.w;
        reg_tmp.h[1] = *(u16 *)(reg_a0 + 4);
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 6);
        reg_d1.w = temp_a0 + reg_tmp.w;
        reg_d3.h[0] = *(u16 *)(reg_a0 + 8);
        reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
        sprite_draw_layer5();
    }
}

extern u8 stage5_midboss4_wave_beam_draw_wave_table[];

void stage5_midboss4_wave_beam_draw_wave(void) {
    u32 temp_a0;

    if (STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->parts & 4) {
        reg_a0 = (u8 *)stage5_midboss4_wave_beam_draw_wave_table;
        reg_a0 += STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->wave_frame;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_tmp.h[1] = *(u16 *)(reg_a0 + 4);
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 6);
        reg_d1.w += reg_tmp.w;
        if (STAGE5_MIDBOSS4_WAVE_BEAM(reg_a5)->left != 0) {
            reg_d1.h[0] += 0x7FFF + 0x7D81;
        } else {
            reg_d1.h[0] += 0x280;
        }
        temp_a0 = reg_d1.w;
        reg_tmp.h[1] = *(u16 *)(reg_a0 + 0xC);
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 0xE);
        reg_d1.w = temp_a0 + reg_tmp.w;
        reg_d3.h[0] = *(u16 *)(reg_a0 + 8);
        reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
        sprite_draw_layer5();
    }
}

u8 stage5_midboss4_arrival_start_table_4[16] = {
    0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_midboss4_arrival_start_table_5[32] = {
    0x00, 0x80, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x0B,
    0x00, 0x0A, 0x00, 0x0A, 0xFF, 0x7F, 0x00, 0x24, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_midboss4_arrival_table[64] = {
    0x00, 0x00, 0x80, 0x1E, 0x00, 0x00, 0x81, 0x1E, 0x00, 0x00, 0x82, 0x1E, 0x00, 0x00, 0x83, 0x1E,
    0x00, 0x00, 0x84, 0x1E, 0x00, 0x00, 0x85, 0x1E, 0x00, 0x00, 0x86, 0x1E, 0x00, 0x00, 0x87, 0x1E,
    0x00, 0x00, 0x88, 0x1E, 0x00, 0x00, 0x89, 0x1E, 0x00, 0x00, 0x8A, 0x1E, 0x00, 0x00, 0x8B, 0x1E,
    0x00, 0x00, 0x8C, 0x1E, 0x00, 0x00, 0x8D, 0x1E, 0x00, 0x00, 0x8E, 0x1E, 0x00, 0x00, 0x8F, 0x1E,
};

u8 stage5_midboss4_start_table[176] = {
    0x01, 0xA0, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x0B,
    0x80, 0x11, 0x80, 0x11, 0xFF, 0x7F, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x01, 0xA0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x00, 0x08, 0x00, 0x06, 0x00, 0x08,
    0xFF, 0x7F, 0x00, 0x08, 0x12, 0x00, 0x00, 0x00, 0x01, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x00, 0x08, 0x00, 0x08, 0x00, 0x06, 0xFF, 0x7F, 0x00, 0x08,
    0x12, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
    0x08, 0x08, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_midboss4_move_between_points_table[48] = {
    0x00, 0x5C, 0x00, 0x0C, 0x00, 0x48, 0x00, 0x2C, 0x00, 0x5C, 0x00, 0x2C, 0x00, 0x54, 0x00, 0x0E,
    0x00, 0x54, 0x00, 0x2E, 0x00, 0x60, 0x00, 0x1E, 0x00, 0x4C, 0x00, 0x1E, 0x00, 0x54, 0x00, 0x1E,
    0x00, 0x48, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u16 stage5_midboss4_move_between_points_table_2[56] = {
    0x0040, 0x0001, 0x0080, 0x0001, 0x00C0, 0x0001, 0x0100, 0x0001,
    0x0140, 0x0001, 0x0180, 0x0001, 0x01C0, 0x0001, 0x0200, 0x0002,
    0x0240, 0x0002, 0x0280, 0x0002, 0x02C0, 0x0002, 0x0300, 0x0002,
    0x0340, 0x0002, 0x0380, 0x0002, 0x03C0, 0x0002, 0x0400, 0x0003,
    0x0440, 0x0003, 0x0480, 0x0003, 0x04C0, 0x0003, 0x0500, 0x0003,
    0x0540, 0x0004, 0x0580, 0x0004, 0x05C0, 0x0004, 0x0600, 0x0004,
    0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 stage5_midboss4_move_to_player_table[56] = {
    0x0040, 0x0002, 0x0080, 0x0004, 0x0100, 0x0006, 0x0180, 0x0008,
    0x0200, 0x000A, 0x0280, 0x000C, 0x0300, 0x000E, 0x0380, 0x0010,
    0x0400, 0x0012, 0x0480, 0x0014, 0x0500, 0x0016, 0x0580, 0x0018,
    0x0600, 0x001A, 0x0680, 0x001C, 0x0700, 0x001E, 0x0780, 0x0020,
    0x0800, 0x0022, 0x0880, 0x0024, 0x0900, 0x0026, 0x0980, 0x0028,
    0x0A00, 0x002A, 0x0A80, 0x002C, 0x0B00, 0x002E, 0x0B80, 0x0030,
    0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 stage5_midboss4_move_zigzag_table[56] = {
    0x0040, 0x0001, 0x0080, 0x0002, 0x00C0, 0x0003, 0x0100, 0x0004,
    0x0140, 0x0005, 0x0180, 0x0006, 0x01C0, 0x0007, 0x0200, 0x0008,
    0x0240, 0x0009, 0x0280, 0x000A, 0x02C0, 0x000B, 0x0300, 0x000B,
    0x0340, 0x000C, 0x0380, 0x000C, 0x03C0, 0x000D, 0x0400, 0x000D,
    0x0440, 0x000E, 0x0480, 0x000E, 0x04C0, 0x000F, 0x0500, 0x000F,
    0x0540, 0x0010, 0x0580, 0x0010, 0x05C0, 0x0011, 0x0600, 0x0011,
    0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 stage5_midboss4_dying_table[40] = {
    0x0000, 0x0008, 0x0000, 0x0800, 0x0400, 0x0000, 0x0000, 0x0085,
    0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x008D, 0x0000, 0xF800,
    0x0000, 0x0000, 0x0000, 0x0008, 0x0040, 0xF000, 0xFC00, 0x0000,
    0x0000, 0x0085, 0x0000, 0xE800, 0xFC00, 0x0000, 0x0000, 0x008D,
    0x0000, 0xE800, 0x0800, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000,
};

u16 stage5_midboss4_dying_table_2[40] = {
    0x0002, 0x0008, 0x0000, 0x0800, 0x0400, 0x0000, 0x0004, 0x0085,
    0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x008D, 0x0000, 0xF800,
    0x0000, 0x0000, 0x0006, 0x0008, 0x0040, 0xF000, 0xFC00, 0x0000,
    0x0008, 0x0085, 0x0000, 0xE800, 0xFC00, 0x0000, 0x000A, 0x008D,
    0x0000, 0xE800, 0x0800, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000,
};

u8 D_00265F60[16] = {
    0x01, 0x00, 0x00, 0x00, 0x80, 0x04, 0x03, 0x00, 0x04, 0x00, 0x1F, 0x00, 0x09, 0x00, 0x00, 0x00,
};

u16 stage5_midboss4_wave_beam_start_table[8] = {
    0x0100, 0x0000, 0x0000, 0x0000, 0x0202, 0x0000, 0x0202, 0x0000,
};

u16 stage5_midboss4_wave_beam_start_table_2[16] = {
    0x8000, 0x1001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x7FFF, 0x0800, 0x0014, 0x0000, 0x0000, 0x0000,
};

u8 stage5_midboss4_wave_beam_draw_charge_table[96] = {
    0x00, 0x00, 0xEF, 0x1E, 0x00, 0x00, 0xF0, 0x1E, 0x00, 0x00, 0xF1, 0x1E, 0x00, 0x00, 0xF2, 0x1E,
    0x00, 0x00, 0xF3, 0x1E, 0x00, 0x00, 0xF4, 0x1E, 0x00, 0x00, 0xF5, 0x1E, 0x00, 0x00, 0xF6, 0x1E,
    0x00, 0x00, 0xF7, 0x1E, 0x00, 0x00, 0xF8, 0x1E, 0x00, 0x00, 0xF9, 0x1E, 0x00, 0x00, 0xFA, 0x1E,
    0x00, 0x00, 0xFB, 0x1E, 0x00, 0x00, 0xFC, 0x1E, 0x00, 0x00, 0xFD, 0x1E, 0x00, 0x00, 0xFE, 0x1E,
    0x00, 0x00, 0xFF, 0x1E, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x01, 0x1F, 0x00, 0x00, 0x02, 0x1F,
    0x00, 0x00, 0x03, 0x1F, 0x00, 0x00, 0x04, 0x1F, 0x00, 0x00, 0x05, 0x1F, 0x00, 0x00, 0x06, 0x1F,
};

u8 stage5_midboss4_wave_beam_draw_burst_table[144] = {
    0x00, 0x00, 0x07, 0x1F, 0x00, 0xFE, 0x00, 0xFE, 0x10, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x08, 0x1F, 0x00, 0xFE, 0x00, 0xFE, 0x10, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x09, 0x1F, 0x00, 0xFA, 0x00, 0xFA, 0x30, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0A, 0x1F, 0x00, 0xF6, 0x00, 0xF4, 0x60, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0B, 0x1F, 0x00, 0xF6, 0x00, 0xF4, 0x60, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0C, 0x1F, 0x00, 0xF6, 0x00, 0xF4, 0x60, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0D, 0x1F, 0x00, 0xF4, 0x00, 0xF4, 0x60, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x1F, 0x00, 0xF4, 0x00, 0xF4, 0x60, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0F, 0x1F, 0x00, 0xF4, 0x00, 0xF4, 0x60, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_midboss4_wave_beam_draw_wave_table[208] = {
    0x00, 0x00, 0x10, 0x1F, 0x00, 0xF8, 0x00, 0xF4, 0x60, 0x08, 0x00, 0x00, 0x00, 0xFE, 0x80, 0xFF,
    0x00, 0x00, 0x11, 0x1F, 0x00, 0xF0, 0x00, 0xF4, 0x60, 0x10, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00,
    0x00, 0x00, 0x12, 0x1F, 0x00, 0xE0, 0x00, 0xF4, 0x60, 0x20, 0x00, 0x00, 0x00, 0xE2, 0x00, 0x00,
    0x00, 0x00, 0x13, 0x1F, 0x00, 0xE0, 0x00, 0xF6, 0x50, 0x20, 0x00, 0x00, 0x00, 0xE2, 0x00, 0x00,
    0x00, 0x00, 0x14, 0x1F, 0x00, 0xE0, 0x00, 0xF6, 0x50, 0x20, 0x00, 0x00, 0x00, 0xE2, 0x00, 0x00,
    0x00, 0x00, 0x15, 0x1F, 0x00, 0xE0, 0x00, 0xF6, 0x50, 0x20, 0x00, 0x00, 0x00, 0xE2, 0x00, 0x00,
    0x00, 0x00, 0x16, 0x1F, 0x00, 0xE0, 0x00, 0xF6, 0x50, 0x20, 0x00, 0x00, 0x00, 0xE2, 0x00, 0x00,
    0x00, 0x00, 0x17, 0x1F, 0x00, 0xE0, 0x00, 0xFC, 0x20, 0x20, 0x00, 0x00, 0x00, 0xE2, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x1F, 0x00, 0xE0, 0x00, 0xFC, 0x20, 0x20, 0x00, 0x00, 0x00, 0xE2, 0x00, 0x00,
    0x00, 0x00, 0x19, 0x1F, 0x00, 0xE0, 0x00, 0xFC, 0x20, 0x20, 0x00, 0x00, 0x00, 0xE2, 0x00, 0x00,
    0x00, 0x00, 0x1A, 0x1F, 0x00, 0xE0, 0x00, 0xFC, 0x20, 0x20, 0x00, 0x00, 0x00, 0xE2, 0x00, 0x00,
    0x00, 0x00, 0x1B, 0x1F, 0x00, 0xE0, 0x00, 0xFE, 0x10, 0x20, 0x00, 0x00, 0x00, 0xE2, 0x00, 0x00,
    0x00, 0x00, 0x1C, 0x1F, 0x00, 0xE0, 0x00, 0xFE, 0x10, 0x20, 0x00, 0x00, 0x00, 0xE2, 0x00, 0x00,
};

u8 stage5_midboss4_wave_beam_table[104] = {
    0x00, 0x04, 0x00, 0x06, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x12, 0x00, 0x04, 0x00, 0x00,
    0x00, 0x00, 0x80, 0x34, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x80, 0x34, 0xC0, 0x03, 0xC0, 0xFF,
    0x00, 0x00, 0x80, 0x34, 0x80, 0x03, 0x80, 0xFF, 0x00, 0x00, 0x80, 0x34, 0x40, 0x03, 0x40, 0xFF,
    0x00, 0x00, 0x80, 0x34, 0x00, 0x03, 0x00, 0xFF, 0x00, 0x00, 0x80, 0x34, 0xC0, 0x02, 0xC0, 0xFE,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage5_midboss4_start_table_2[8] = { 0x00, 0x00, 0x01, 0x00, 0x00, 0x50, 0x00, 0x00 };
