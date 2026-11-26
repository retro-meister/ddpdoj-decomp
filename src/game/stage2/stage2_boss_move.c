#include "common.h"
#include "entity.h"
#include "stage2_boss.h"

void stage2_boss_move_enter_start(void);
void stage2_boss_move_enter(void);
void stage2_boss_move_retreat(void);
void stage2_boss_move_hover_high_start(void);
void stage2_boss_move_hover_high(void);
void stage2_boss_move_dive_start(void);
void stage2_boss_move_dive(void);
void stage2_boss_move_rise_start(void);
void stage2_boss_move_rise(void);
void stage2_boss_move_wander_start(void);
void stage2_boss_move_wander(void);
void stage2_boss_move_rise_sway_start(void);
void stage2_boss_move_rise_sway(void);
void stage2_boss_move_dash_sideways_start(void);
void stage2_boss_move_dash_sideways(void);

/*
 * The movement part of the boss slot (reg_a4), one record per kind of movement. Positions are (y, x).
 */
typedef struct {
    /* 0x00 */ u16 unused_00;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;
    /* 0x04 */ u16 delay;
    /* 0x06 */ u16 speed;         /* rises to 0x100 */
    /* 0x08 */ SlotTimer accel;
} MoveEnter;

/* Along a table of waypoints. */
typedef struct {
    /* 0x00 */ u16 waypoint;      /* offset of the current waypoint in the table */
} MovePath;

/* To one position, easing the speed. */
typedef struct {
    /* 0x00 */ u16 unused_00;
    /* 0x02 */ u8 near;           /* rising with a sway: close to the goal */
    /* 0x03 */ u8 target_speed;
    /* 0x04 */ SlotTimer pace;    /* frames between two steps of the speed */
    /* 0x06 */ u16 unused_06;
    /* 0x08 */ u16 goal_y;
    /* 0x0A */ u16 goal_x;
} MoveGoal;

/* To random positions around where it started. */
typedef struct {
    /* 0x00 */ u16 unused_00;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 target_speed;
    /* 0x04 */ u16 home_y;
    /* 0x06 */ u16 home_x;
    /* 0x08 */ u16 goal_y;
    /* 0x0A */ u16 goal_x;
    /* 0x0C */ SlotTimer pace;
} MoveWander;

#define ENTER(pointer) ((MoveEnter *)(pointer))
#define PATH(pointer) ((MovePath *)(pointer))
#define GOAL(pointer) ((MoveGoal *)(pointer))
#define WANDER(pointer) ((MoveWander *)(pointer))

/* The set-up routine and the per-frame routine of every movement, by movement number. */
void (*stage2_boss_move_routines[])(void) = {
    stage2_boss_move_enter_start,
    stage2_boss_move_enter,
    stage2_boss_move_retreat,
    stage2_boss_move_retreat,
    stage2_boss_move_hover_high_start,
    stage2_boss_move_hover_high,
    stage2_boss_move_dive_start,
    stage2_boss_move_dive,
    stage2_boss_move_rise_start,
    stage2_boss_move_rise,
    stage2_boss_move_wander_start,
    stage2_boss_move_wander,
    stage2_boss_move_rise_sway_start,
    stage2_boss_move_rise_sway,
    stage2_boss_move_dash_sideways_start,
    stage2_boss_move_dash_sideways,
};

u16 stage2_boss_hover_waypoints[] = {
    0x5C00, 0x1C00, 0x5A00, 0x1E00, 0x5800, 0x2200, 0x5600, 0x2800,
    0x5400, 0x2C00, 0x5200, 0x2800, 0x5000, 0x2200, 0x4E00, 0x1E00,
    0x4C00, 0x1C00, 0x4E00, 0x1A00, 0x5000, 0x1600, 0x5200, 0x1000,
    0x5400, 0x0C00, 0x5600, 0x1000, 0x5800, 0x1600, 0x5A00, 0x1A00,
};

u16 stage2_boss_dash_waypoints[] = {
    0x5C00, 0x2200, 0x6000, 0x1C00, 0x5E00, 0x1000, 0x5800, 0x2200,
    0x5A00, 0x1600, 0x6000, 0x2800, 0x5E00, 0x1600, 0x5800, 0x2800,
};

u16 stage2_boss_enter_flash[] = {
    0x0006, 0x7FFF, 0x0000, 0x0400, 0x0004, 0x0005, 0x001F, 0x0003,
    0x7FFF, 0x0000, 0x0440, 0x000B, 0x000C, 0x001F, 0x0003, 0x7FFF,
    0x0000, 0x0480, 0x0012, 0x0013, 0x001F, 0x0003, 0x7FFF, 0x0000,
    0x05C0, 0x0019, 0x001A, 0x001F, 0x0003, 0x7FFF, 0x0000, 0x0340,
    0x0020, 0x0021, 0x001F, 0x0003, 0x7FFF, 0x0000, 0x04C0, 0x0027,
    0x0028, 0x001F, 0x0003,
};

void stage2_boss_move_enter(void);
void stage2_boss_move_hover_high(void);
void stage2_boss_move_dive(void);
void stage2_boss_move_rise(void);
void stage2_boss_move_wander(void);
void stage2_boss_move_rise_sway(void);
void stage2_boss_move_dash_sideways(void);


void stage2_boss_parts_follow(void) {
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    ENTITY(reg_a6)[1].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[1].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[1].y.h -= 0x1800;
    ENTITY(reg_a6)[1].x.h += 0x300;
    ENTITY(reg_a6)[2].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[2].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[2].y.h -= 0x11C0;
    ENTITY(reg_a6)[2].x.h += 0x6C0;
    ENTITY(reg_a6)[3].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[3].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[3].y.h -= 0x11C0;
    ENTITY(reg_a6)[3].x.h -= 0x6C0;
    ENTITY(reg_a6)[4].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[4].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[4].y.h -= 0x40;
    ENTITY(reg_a6)[4].x.h += 0xCC0;
    ENTITY(reg_a6)[5].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[5].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[5].y.h -= 0x40;
    ENTITY(reg_a6)[5].x.h -= 0xCC0;
    ENTITY(reg_a6)[6].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[6].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[6].y.h += 0x540;
    ENTITY(reg_a6)[6].x.h += 0x1480;
    ENTITY(reg_a6)[7].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[7].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[7].y.h += 0x540;
    ENTITY(reg_a6)[7].x.h -= 0x1480;
    ENTITY(reg_a6)[8].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[8].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[8].y.h -= 0x300;
}


void stage2_boss_move_enter_start(void) {
    ENTER(reg_a4)->step = 0;
    ENTER(reg_a4)->delay = 0x1C0;
    ENTER(reg_a4)->speed = 0;
    ENTER(reg_a4)->accel.h = 0;
    stage2_boss_move_enter();
}

s32 boss_phase_start();
s32 boss_movement_stop();
s32 func_0013B2E0();
s32 sprite_palette_load();
s32 func_001CBBF0();
s32 entity_follow_scroll();
extern u8 D_0025FCB0[];
extern u8 g_boss_present;
extern u8 g_boss_present_b1;

void stage2_boss_move_enter(void) {
    entity_follow_scroll();
    if (ENTER(reg_a4)->step == 0) {
        if (ENTER(reg_a4)->delay == 0x10) {
            reg_d0.h[0] = 0xD;
            reg_a0 = (u8 *)D_0025FCB0;
            sprite_palette_load();
        }
        ENTER(reg_a4)->delay -= 1;
        if (ENTER(reg_a4)->delay != 0) {
            stage2_boss_parts_follow();
            return;
        }
        ENTER(reg_a4)->step = 1U;
        g_boss_present |= 1;
        stage2_boss_parts_follow();
        return;
    }
    if (ENTER(reg_a4)->speed != 0x100) {
        reg_tmp.b[0] = ENTER(reg_a4)->accel.t.count;
        ENTER(reg_a4)->accel.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            ENTER(reg_a4)->accel.t.count = (u8) ENTER(reg_a4)->accel.t.reload;
            ENTER(reg_a4)->speed += 3;
            if ((s16) ENTER(reg_a4)->speed >= 0x100) {
                ENTER(reg_a4)->speed = 0x100U;
            }
        }
    }
    reg_d0.h[0] = ENTER(reg_a4)->speed;
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    if ((s16) ENTITY(reg_a6)->y.h < 0x6200) {
        stage2_boss_parts_follow();
        return;
    }
    g_boss_present_b1 |= 0x10;
    g_boss_present_b1 |= 2;
    reg_d0.w = 3;
    boss_phase_start();
    func_001CBBF0();
    boss_movement_stop();
    reg_a0 = (u8 *)stage2_boss_enter_flash;
    func_0013B2E0();
    stage2_boss_parts_follow();
}


void stage2_boss_move_retreat(void) {
    ENTITY(reg_a6)->y.h -= 0x10;
    stage2_boss_parts_follow();
}

s32 rng_next_masked();

void stage2_boss_waypoint_pick(void) {
    rng_next_masked();
    reg_d0.h[0] &= 7;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    PATH(reg_a4)->waypoint = reg_d0.h[0];
}

void stage2_boss_speed_approach(void)
{
    reg_d0.b[0] = GOAL(reg_a4)->target_speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.speed;

    if (reg_d0.b[0] != reg_d1.b[0]) {
        if ((s8)reg_d0.b[0] >= (s8)reg_d1.b[0]) {
            reg_d1.b[0]++;
        } else {
            reg_d1.b[0]--;
        }
    }

    ENTITY(reg_a6)->move.b.speed = reg_d1.b[0];
}

void stage2_boss_move_hover_high_start(void) {
    s32 direction_between(void *);
    PATH(reg_a4)->waypoint = 0;
    ENTITY(reg_a6)->move.sb.speed = 4;
    reg_a0 = ((u8 *)stage2_boss_hover_waypoints);
    reg_a0 += PATH(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between(reg_a6);
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    stage2_boss_move_hover_high();
}

s32 rng_next_bit();
s32 entity_velocity();
s32 direction_turn_toward();
s32 entity_distance_to();

void stage2_boss_move_hover_high() {
    s32 direction_between();
    reg_a0 = ((u8 *)stage2_boss_hover_waypoints);
    reg_a0 += PATH(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    entity_velocity();
    reg_a0 = ((u8 *)stage2_boss_hover_waypoints);
    reg_a0 += PATH(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    entity_distance_to();
    if ((s16) reg_d0.h[0] < 0x101) {
        PATH(reg_a4)->waypoint += 4;
        PATH(reg_a4)->waypoint &= 0x3F;
        ENTITY(reg_a6)->move.b.speed = 4U;
        rng_next_bit();
        ENTITY(reg_a6)->move.b.speed -= reg_d0.b[0];
    }
    stage2_boss_parts_follow();
}


void stage2_boss_move_dive_start(void) {
    GOAL(reg_a4)->target_speed = 2;
    GOAL(reg_a4)->pace.sh = 0x404;
    reg_tmp.w = 0x5C001C00;
    GOAL(reg_a4)->goal_y = (u16) reg_tmp.h[1];
    GOAL(reg_a4)->goal_x = (u16) reg_tmp.h[0];
    stage2_boss_move_dive();
}

s32 boss_movement_start();
s32 func_001CBBE0();

void stage2_boss_move_dive(void) {
    s32 direction_between();
    reg_d2.h[0] = GOAL(reg_a4)->goal_y;
    reg_d3.h[0] = GOAL(reg_a4)->goal_x;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_d2.h[0] = GOAL(reg_a4)->goal_y;
    reg_d3.h[0] = GOAL(reg_a4)->goal_x;
    entity_distance_to();
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] >>= 8;
    GOAL(reg_a4)->target_speed = (u8) reg_d1.b[0];
    if ((s16) reg_d0.h[0] < 0x101) {
        reg_d0.w = 5;
        boss_movement_start();
        func_001CBBE0();
    }
    reg_tmp.b[0] = GOAL(reg_a4)->pace.t.count;
    GOAL(reg_a4)->pace.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        GOAL(reg_a4)->pace.t.count = (u8) GOAL(reg_a4)->pace.t.reload;
        stage2_boss_speed_approach();
    }
    entity_velocity();
    stage2_boss_parts_follow();
}


void stage2_boss_move_rise_start(void) {
    GOAL(reg_a4)->target_speed = 0;
    GOAL(reg_a4)->pace.sh = 0x101;
    reg_tmp.w = 0x5C001C00;
    GOAL(reg_a4)->goal_y = (u16) reg_tmp.h[1];
    GOAL(reg_a4)->goal_x = (u16) reg_tmp.h[0];
    stage2_boss_move_rise();
}

void stage2_boss_move_rise(void) {
    s32 direction_between();
    reg_d2.h[0] = GOAL(reg_a4)->goal_y;
    reg_d3.h[0] = GOAL(reg_a4)->goal_x;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_d2.h[0] = GOAL(reg_a4)->goal_y;
    reg_d3.h[0] = GOAL(reg_a4)->goal_x;
    entity_distance_to();
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] >>= 7;
    GOAL(reg_a4)->target_speed = (u8) reg_d1.b[0];
    if ((s16) reg_d0.h[0] < 0x101) {
        reg_d0.w = 5;
        boss_movement_start();
    }
    reg_tmp.b[0] = GOAL(reg_a4)->pace.t.count;
    GOAL(reg_a4)->pace.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        GOAL(reg_a4)->pace.t.count = (u8) GOAL(reg_a4)->pace.t.reload;
        stage2_boss_speed_approach();
    }
    entity_velocity();
    stage2_boss_parts_follow();
}

s32 boss_attack_stop();
s32 rng_next_word();

void stage2_boss_move_wander_start(void) {
    u16 temp_a0;

    reg_d0.w = 2;
    boss_attack_stop();
    WANDER(reg_a4)->target_speed = 2;
    WANDER(reg_a4)->pace.sh = 0;
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] = temp_a0;
    WANDER(reg_a4)->home_y = (u16) reg_d0.h[1];
    WANDER(reg_a4)->home_x = (u16) reg_d0.h[0];
    WANDER(reg_a4)->goal_y = (u16) reg_d0.h[1];
    WANDER(reg_a4)->goal_x = (u16) reg_d0.h[0];
    rng_next_word();
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
    WANDER(reg_a4)->goal_y += reg_d0.h[0];
    rng_next_word();
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
    WANDER(reg_a4)->goal_x += reg_d0.h[0];
    stage2_boss_move_wander();
}

void stage2_boss_move_wander() {
    s32 direction_between();
    reg_d2.h[0] = WANDER(reg_a4)->goal_y;
    reg_d3.h[0] = WANDER(reg_a4)->goal_x;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_tmp.b[0] = WANDER(reg_a4)->pace.t.count;
    WANDER(reg_a4)->pace.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        WANDER(reg_a4)->pace.t.count = (u8) WANDER(reg_a4)->pace.t.reload;
        stage2_boss_speed_approach();
    }
    entity_velocity();
    reg_d2.h[0] = WANDER(reg_a4)->goal_y;
    reg_d3.h[0] = WANDER(reg_a4)->goal_x;
    entity_distance_to();
    if ((s16) reg_d0.h[0] < 0x101) {
        reg_d0.h[1] = WANDER(reg_a4)->home_y;
        reg_d0.h[0] = WANDER(reg_a4)->home_x;
        WANDER(reg_a4)->goal_y = (u16) reg_d0.h[1];
        WANDER(reg_a4)->goal_x = (u16) reg_d0.h[0];
        rng_next_word();
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
        WANDER(reg_a4)->goal_y += reg_d0.h[0];
        rng_next_word();
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
        WANDER(reg_a4)->goal_x += reg_d0.h[0];
    }
    stage2_boss_parts_follow();
}


void stage2_boss_move_rise_sway_start(void) {
    GOAL(reg_a4)->target_speed = 0;
    GOAL(reg_a4)->near = 0;
    GOAL(reg_a4)->pace.sh = 0x404;
    stage2_boss_move_rise_sway();
}

void stage2_boss_move_rise_sway(void) {
    s32 direction_between();
    if (GOAL(reg_a4)->near == 0) {
        reg_d2.h[0] = GOAL(reg_a4)->goal_y;
        reg_d3.h[0] = GOAL(reg_a4)->goal_x;
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        direction_between();
        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
        reg_d2.h[0] = GOAL(reg_a4)->goal_y;
        reg_d3.h[0] = GOAL(reg_a4)->goal_x;
        entity_distance_to();
        reg_d1.h[0] = reg_d0.h[0];
        reg_d1.h[0] >>= 7;
        if ((s16)(reg_d1.b[0]) < 3) {
            reg_d1.w = 2;
        }
        GOAL(reg_a4)->target_speed = (u8) reg_d1.b[0];
        if ((s16) reg_d0.h[0] < 0x201) {
            GOAL(reg_a4)->near = 1U;
            GOAL(reg_a4)->target_speed = 2U;
            GOAL(reg_a4)->pace.sh = 0x101;
        }
    }
    if ((GOAL(reg_a4)->near == 1) && (ENTITY(reg_a6)->move.sb.speed < 3)) {
        ENTITY(reg_a6)->move.sb.speed = 2;
        reg_d0.w = 5;
        boss_movement_start();
    }
    reg_tmp.b[0] = GOAL(reg_a4)->pace.t.count;
    GOAL(reg_a4)->pace.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        GOAL(reg_a4)->pace.t.count = (u8) GOAL(reg_a4)->pace.t.reload;
        stage2_boss_speed_approach();
    }
    entity_velocity();
    stage2_boss_parts_follow();
}



void stage2_boss_move_dash_sideways_start(void) {
    PATH(reg_a4)->waypoint = 0;
    ENTITY(reg_a6)->move.b.speed = 8;
    stage2_boss_move_dash_sideways();
}

void stage2_boss_move_dash_sideways(void) {
    s32 direction_between(void *);
    reg_a0 = ((u8 *)stage2_boss_dash_waypoints);
    reg_a0 += PATH(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between(reg_a6);
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    entity_velocity();
    reg_a0 = ((u8 *)stage2_boss_dash_waypoints);
    reg_a0 += PATH(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    entity_distance_to();
    if ((s16) reg_d0.h[0] < 0x201) {
        stage2_boss_waypoint_pick();
    }
    stage2_boss_parts_follow();
}
