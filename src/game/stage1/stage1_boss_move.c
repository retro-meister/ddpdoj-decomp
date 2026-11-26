#include "common.h"
#ifdef DDPDOJ_PC
void boss_movement_start(void);
#endif
#include "enemy.h"
#include "entity.h"
#include "stage1_boss.h"

void stage1_boss_move_enter_start(void);
void stage1_boss_move_enter(void);
void stage1_boss_move_dying_start(void);
void stage1_boss_move_dying(void);
void stage1_boss_move_wander_start(void);
void stage1_boss_move_wander(void);
void stage1_boss_move_up_start(void);
void stage1_boss_move_up(void);
void stage1_boss_move_sway_start(void);
void stage1_boss_move_sway(void);
void stage1_boss_move_down_start(void);
void stage1_boss_move_down(void);
void stage1_boss_move_up_b_start(void);
void stage1_boss_move_up_b(void);
void stage1_boss_move_sway_b_start(void);
void stage1_boss_move_sway_b(void);
void stage1_boss_move_up_c_start(void);
void stage1_boss_move_up_c(void);

/* The set-up routine and the per-frame routine of every movement, by movement number. */
void (*stage1_boss_move_routines[])(void) = {
    stage1_boss_move_enter_start,
    stage1_boss_move_enter,
    stage1_boss_move_dying_start,
    stage1_boss_move_dying,
    stage1_boss_move_wander_start,
    stage1_boss_move_wander,
    stage1_boss_move_up_start,
    stage1_boss_move_up,
    stage1_boss_move_sway_start,
    stage1_boss_move_sway,
    stage1_boss_move_down_start,
    stage1_boss_move_down,
    stage1_boss_move_up_b_start,
    stage1_boss_move_up_b,
    stage1_boss_move_sway_b_start,
    stage1_boss_move_sway_b,
    stage1_boss_move_up_c_start,
    stage1_boss_move_up_c,
};

u16 stage1_boss_enter_flash[] = {
    0x0005, 0x7FFF, 0x0000, 0x04C0, 0x0004, 0x0005, 0x001F, 0x0003,
    0x7FFF, 0x0000, 0x0540, 0x000B, 0x000C, 0x001F, 0x0003, 0x7FFF,
    0x0000, 0x0580, 0x0012, 0x0013, 0x001F, 0x0003, 0x7FFF, 0x0000,
    0x05C0, 0x0019, 0x001A, 0x001F, 0x0003, 0x7FFF, 0x0000, 0x07C0,
    0x0020, 0x0021, 0x001F, 0x0003,
};

u16 stage1_boss_wander_waypoints[] = {
    0x5C00, 0x2200, 0x6000, 0x2400, 0x5E00, 0x1800, 0x5800, 0x2200,
    0x5A00, 0x1400, 0x6000, 0x2000, 0x5E00, 0x1400, 0x5800, 0x2000,
};

u16 stage1_boss_sway_waypoints[] = {
    0x6A00, 0x2200, 0x6800, 0x2400, 0x6C00, 0x1800, 0x6800, 0x2200,
    0x6A00, 0x1400, 0x6C00, 0x2000, 0x6C00, 0x1400, 0x6800, 0x2000,
};

u16 stage1_boss_sway_b_waypoints[] = {
    0x7400, 0x2200, 0x7200, 0x2400, 0x7600, 0x1800, 0x7200, 0x2200,
    0x7400, 0x1400, 0x7600, 0x2000, 0x7600, 0x1400, 0x7200, 0x2000,
};

/*
 * The movement part of the boss slot (reg_a4) as the stage 1 boss uses it. Waypoints are (y, x) pairs.
 */
typedef struct {
    /* 0x00 */ u16 waypoint;      /* offset of the current waypoint in the table */
    /* 0x02 */ union {
        s16 sh;
        struct { u8 reload; u8 count; } brake;  /* entering: frames between two steps of slowing down */
        struct { u8 unused; u8 target; } speed; /* afterwards: the speed to ease toward */
    } pace;
    /* 0x04 */ u8 unused_04;
    /* 0x05 */ u8 arrived;        /* entering: within reach of the first position */
    /* 0x06 */ union {
        s16 sh;
        struct { u8 reload; u8 count; } b;      /* entering: frames between two steps of the gatling frame */
    } step;
} Stage1BossMove;

#define MOVE(pointer) ((Stage1BossMove *)(pointer))


s32 velocity_from_dir256();
s32 direction_between();

/* The last five positions of the body, oldest last; the side parts follow the body with this delay. */
#define POSITION_HISTORY ((u16 *)g_spare_entities)

void stage1_boss_parts_follow(void) {
    u32 t;
    u32 t1;
    u16 *p;

    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w = reg_d0.w;
    t1 = reg_d1.w;
    reg_tmp.h[1] = ENTITY(reg_a6)[5].offset_y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)[5].offset_x.h;
    reg_d1.w = t1 + reg_tmp.w;
    reg_d1.w += 0xE0000000;
    ENTITY(reg_a6)[5].y.h = reg_d1.h[1];
    ENTITY(reg_a6)[5].x.h = reg_d1.h[0];
    reg_a0 = (u8 *)&POSITION_HISTORY[10];
    p = &POSITION_HISTORY[8];
    reg_a1 = (u8 *)p;
    reg_d1.w = 3;
shift_history:
    reg_a0 -= 4;
    reg_a1 -= 4;
    *(u16 *)(reg_a0 + 0) = *(u16 *)(reg_a1 + 0);
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a1 + 2);
    t = reg_d1.h[0] - 1;
    reg_d1.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto shift_history;
    *(u16 *)(reg_a1 + 0) = reg_d0.h[1];
    *(u16 *)(reg_a1 + 2) = reg_d0.h[0];
    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) goto right_side_done;
    reg_d0.h[1] = *p;
    reg_d0.h[0] = POSITION_HISTORY[9];
    reg_tmp.h[1] = ENTITY(reg_a6)[1].offset_y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)[1].offset_x.h;
    reg_d0.w += reg_tmp.w;
    ENTITY(reg_a6)[1].y.h = reg_d0.h[1];
    ENTITY(reg_a6)[1].x.h = reg_d0.h[0];
    ENTITY(reg_a6)[1].x.h += 0x80;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)[2].draw.b.priority;
    reg_d1.b[0] = ENTITY(reg_a6)[2].draw.b.flip;
    velocity_from_dir256();
    reg_d2.h[0] = (s16) reg_d2.h[0] * 2;
    reg_d2.h[0] += 0xFD80;
    ENTITY(reg_a6)[1].y.h += reg_d2.h[0];
    reg_d3.h[0] = (s16) reg_d3.h[0] * 4;
    ENTITY(reg_a6)[1].x.h += reg_d3.h[0];
    reg_d0.h[0] = ENTITY(reg_a6)[2].sprite.h;
    ENTITY(reg_a6)[1].y.h -= reg_d0.h[0];
right_side_done:
    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) goto left_side_done;
    reg_d0.h[1] = *p;
    reg_d0.h[0] = POSITION_HISTORY[9];
    reg_tmp.h[1] = ENTITY(reg_a6)[3].offset_y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)[3].offset_x.h;
    reg_d0.w += reg_tmp.w;
    ENTITY(reg_a6)[3].y.h = reg_d0.h[1];
    ENTITY(reg_a6)[3].x.h = reg_d0.h[0];
    ENTITY(reg_a6)[3].x.h += 0xFF80;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)[4].draw.b.priority;
    reg_d1.b[0] = ENTITY(reg_a6)[4].draw.b.flip;
    velocity_from_dir256();
    reg_d2.h[0] = (s16) reg_d2.h[0] * 2;
    reg_d2.h[0] += 0xFD80;
    ENTITY(reg_a6)[3].y.h += reg_d2.h[0];
    reg_d3.h[0] = (s16) reg_d3.h[0] * 4;
    ENTITY(reg_a6)[3].x.h += reg_d3.h[0];
    reg_d0.h[0] = ENTITY(reg_a6)[4].sprite.h;
    ENTITY(reg_a6)[3].y.h -= reg_d0.h[0];
left_side_done:
    return;
}


void stage1_boss_move_enter_start(void) {
    ENTITY(reg_a6)->move.sh = 0x1E20;
    MOVE(reg_a4)->pace.sh = 0x101;
    MOVE(reg_a4)->arrived = 0;
    MOVE(reg_a4)->step.sh = 0x101;
}

s32 boss_phase_start();
#ifndef DDPDOJ_PC
s32 boss_movement_start();
#endif
s32 boss_part_show();
s32 boss_animation_start();
s32 fade_in_and_release();
s32 stage1_boss_shield_off();
s32 stage1_boss_parts_enable();
s32 entity_velocity();
s32 direction_turn_toward();
s32 entity_distance_to();
extern u8 g_boss_present_b1;
extern u16 g_side_scroll_x[];

void stage1_boss_move_enter(void) {
    u8 temp_v0_2;

    reg_d2.h[0] = 0x5400;
    reg_d3.h[0] = 0x1C00;
    reg_d3.h[0] -= g_side_scroll_x[0];
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    entity_velocity();
    reg_a0 = (u8 *)POSITION_HISTORY;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.w = 4;
    do {
        *(u16 *)reg_a0 = reg_d1.h[1];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[0];
        reg_a0 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d2.h[0] = 0x5400;
    reg_d3.h[0] = 0x1C00;
    reg_d3.h[0] -= g_side_scroll_x[0];
    entity_distance_to();
    if ((s16) reg_d0.h[0] < 0x1801) {
        MOVE(reg_a4)->arrived = 1U;
        reg_tmp.b[0] = MOVE(reg_a4)->pace.brake.count;
        MOVE(reg_a4)->pace.brake.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            MOVE(reg_a4)->pace.brake.count = (u8) MOVE(reg_a4)->pace.brake.reload;
            temp_v0_2 = ENTITY(reg_a6)->move.b.speed;
            if (temp_v0_2 != 0) {
                ENTITY(reg_a6)->move.b.speed = (u8) (temp_v0_2 - 1);
            }
        }
    }
    if (MOVE(reg_a4)->arrived == 0) {
        STAGE1_EXTRA(reg_a6)->enter_anim += 0x10;
        STAGE1_EXTRA(reg_a6)->enter_anim &= 0x3F;
    }
    if (MOVE(reg_a4)->arrived == 1) {
        reg_tmp.b[0] = MOVE(reg_a4)->step.b.count;
        MOVE(reg_a4)->step.b.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            MOVE(reg_a4)->step.b.count = (u8) MOVE(reg_a4)->step.b.reload;
            STAGE1_EXTRA(reg_a6)->enter_anim += 0x10;
            if (STAGE1_EXTRA(reg_a6)->enter_anim == 0x180) {
                g_boss_present_b1 |= 0x10;
                g_boss_present_b1 |= 2;
                reg_d0.w = 2;
                boss_movement_start();
                reg_d0.w = 1;
                boss_phase_start();
                stage1_boss_shield_off();
                stage1_boss_parts_enable();
                reg_d0.w = 0;
                boss_animation_start();
                reg_d0.w = 1;
                boss_animation_start();
                reg_d0.w = 2;
                boss_animation_start();
                reg_d0.w = 3;
                boss_animation_start();
                reg_d0.w = 7;
                boss_animation_start();
                reg_d0.w = 0;
                boss_part_show();
                reg_d0.w = 1;
                boss_part_show();
                reg_d0.w = 2;
                boss_part_show();
                reg_d0.w = 3;
                boss_part_show();
                reg_d0.w = 4;
                boss_part_show();
                reg_d0.w = 5;
                boss_part_show();
                reg_d0.w = 6;
                reg_a0 = (u8 *)(stage1_boss_enter_flash);
                fade_in_and_release();
            }
        }
    }
    stage1_boss_parts_follow();
}

void stage1_boss_move_dying_start(void) {
}

void stage1_boss_move_dying(void) {
    ENTITY(reg_a6)->y.h -= 0x10;
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w = reg_d0.w;
    reg_tmp.h[1] = ENTITY(reg_a6)[5].offset_y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)[5].offset_x.h;
    reg_d1.w += reg_tmp.w;
    reg_d1.w += 0xDE000000;
    ENTITY(reg_a6)[5].y.h = (u16) reg_d1.h[1];
    ENTITY(reg_a6)[5].x.h = (u16) reg_d1.h[0];
}

s32 rng_next_masked();

void stage1_boss_waypoint_pick(void) {
    rng_next_masked();
    reg_d0.h[0] &= 7;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    MOVE(reg_a4)->waypoint = (u16) reg_d0.h[0];
    rng_next_masked();
    reg_d0.b[0] &= 3;
    reg_d0.b[0] += 2;
    MOVE(reg_a4)->pace.speed.target = (u8) reg_d0.b[0];
}

void stage1_boss_speed_approach(void)
{
    u8 *currentByte;

    reg_d0.b[0] = MOVE(reg_a4)->pace.speed.target;
    currentByte = &ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = *currentByte;

    if (reg_d0.b[0] != reg_d1.b[0]) {
        if ((s8)reg_d0.b[0] >= (s8)reg_d1.b[0]) {
            reg_d1.b[0]++;
        } else {
            reg_d1.b[0]--;
        }
    }

    *currentByte = reg_d1.b[0];
}


void stage1_boss_move_wander_start(void) {
    MOVE(reg_a4)->waypoint = 0;
    ENTITY(reg_a6)->move.h = 0x20;
    MOVE(reg_a4)->pace.speed.target = ENTITY(reg_a6)->move.b.speed;
    stage1_boss_waypoint_pick();
}

void stage1_boss_move_wander(void) {
    reg_a0 = (u8 *)stage1_boss_wander_waypoints;
    reg_a0 += MOVE(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between(reg_a6);
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    stage1_boss_speed_approach();
    entity_velocity();
    reg_a0 = (u8 *)stage1_boss_wander_waypoints;
    reg_a0 += MOVE(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    entity_distance_to();
    if ((s16) reg_d0.h[0] < 0x101) {
        stage1_boss_waypoint_pick();
    }
    stage1_boss_parts_follow();
}

void stage1_boss_move_up_start(void) {
    MOVE(reg_a4)->waypoint = 0;
    MOVE(reg_a4)->pace.speed.target = ENTITY(reg_a6)->move.b.speed;
}

void stage1_boss_move_up() {
    reg_d2.h[0] = 0x6A00;
    reg_d3.h[0] = 0x1C00;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_d2.h[0] = 0x6A00;
    reg_d3.h[0] = 0x1C00;
    entity_distance_to();
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] = (u16) ((s32) reg_d1.h[0] >> 7);
    MOVE(reg_a4)->pace.speed.target = (u8) reg_d1.b[0];
    if ((s16) reg_d0.h[0] < 0x101) {
        reg_d0.w = 4;
        boss_movement_start();
    }
    stage1_boss_speed_approach();
    entity_velocity();
    stage1_boss_parts_follow();
}


void stage1_boss_move_sway_start(void) {
    MOVE(reg_a4)->waypoint = 0;
    MOVE(reg_a4)->pace.speed.target = ENTITY(reg_a6)->move.b.speed;
    stage1_boss_waypoint_pick();
}

void stage1_boss_move_sway(void) {
    reg_a0 = (u8 *)stage1_boss_sway_waypoints;
    reg_a0 += MOVE(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between(reg_a6);
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    stage1_boss_speed_approach();
    entity_velocity();
    reg_a0 = (u8 *)stage1_boss_sway_waypoints;
    reg_a0 += MOVE(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    entity_distance_to();
    if ((s16) reg_d0.h[0] < 0x101) {
        stage1_boss_waypoint_pick();
    }
    stage1_boss_parts_follow();
}


void stage1_boss_move_down_start(void) {
    MOVE(reg_a4)->waypoint = 0;
    ENTITY(reg_a6)->move.b.speed = 4U;
    MOVE(reg_a4)->pace.speed.target = ENTITY(reg_a6)->move.b.speed;
    reg_d0.b[0] = ENTITY(reg_a6)[1].misc.b.draw_layer;
    reg_d0.b[0] += ENTITY(reg_a6)[3].misc.b.draw_layer;
    if (reg_d0.b[0] != 2) {
        stage1_boss_move_down();
        return;
    }
    ENTITY(reg_a6)->move.b.speed = 8U;
}

void stage1_boss_move_down() {
    reg_d2.h[0] = 0x5C00;
    reg_d3.h[0] = 0x1C00;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_d2.h[0] = 0x5C00;
    reg_d3.h[0] = 0x1C00;
    entity_distance_to();
    if ((s16) reg_d0.h[0] < 0x101) {
        reg_d0.w = 2;
        boss_movement_start();
    }
    entity_velocity();
    stage1_boss_parts_follow();
}

void stage1_boss_move_up_b_start(void) {
    MOVE(reg_a4)->waypoint = 0;
    MOVE(reg_a4)->pace.speed.target = ENTITY(reg_a6)->move.b.speed;
}

void stage1_boss_move_up_b() {
    reg_d2.h[0] = 0x7400;
    reg_d3.h[0] = 0x1C00;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_d2.h[0] = 0x7400;
    reg_d3.h[0] = 0x1C00;
    entity_distance_to();
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] = (u16) ((s32) reg_d1.h[0] >> 7);
    MOVE(reg_a4)->pace.speed.target = (u8) reg_d1.b[0];
    if ((s16) reg_d0.h[0] < 0x101) {
        reg_d0.w = 7;
        boss_movement_start();
    }
    stage1_boss_speed_approach();
    entity_velocity();
    stage1_boss_parts_follow();
}

void stage1_boss_move_sway_b_start(void) {
    u8 value;

    MOVE(reg_a4)->waypoint = 0;
    value = ENTITY(reg_a6)->move.b.speed;
    MOVE(reg_a4)->pace.speed.target = value;
    stage1_boss_waypoint_pick();
}

void stage1_boss_move_sway_b(void) {
    reg_a0 = (u8 *)stage1_boss_sway_b_waypoints;
    reg_a0 += MOVE(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between(reg_a6);
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    stage1_boss_speed_approach();
    entity_velocity();
    reg_a0 = (u8 *)stage1_boss_sway_b_waypoints;
    reg_a0 += MOVE(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    entity_distance_to();
    if ((s16) reg_d0.h[0] < 0x101) {
        stage1_boss_waypoint_pick();
    }
    stage1_boss_parts_follow();
}

void stage1_boss_move_up_c_start(void) {
    MOVE(reg_a4)->waypoint = 0;
    MOVE(reg_a4)->pace.speed.target = ENTITY(reg_a6)->move.b.speed;
}

void stage1_boss_move_up_c() {
    reg_d2.h[0] = 0x7400;
    reg_d3.h[0] = 0x1C00;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_d2.h[0] = 0x7400;
    reg_d3.h[0] = 0x1C00;
    entity_distance_to();
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] = (u16) ((s32) reg_d1.h[0] >> 7);
    MOVE(reg_a4)->pace.speed.target = (u8) reg_d1.b[0];
    if ((s16) reg_d0.h[0] < 0x101) {
        reg_d0.w = 4;
        boss_movement_start();
    }
    stage1_boss_speed_approach();
    entity_velocity();
    stage1_boss_parts_follow();
}
