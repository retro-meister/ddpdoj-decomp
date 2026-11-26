#include "common.h"
#include "entity.h"
#include "stage4_boss.h"

void stage4_boss_move_enter_start(void);
void stage4_boss_move_enter(void);
void stage4_boss_move_wander_high_start(void);
void stage4_boss_move_wander_high(void);
void stage4_boss_move_to_form2_start(void);
void stage4_boss_move_to_form2(void);
void stage4_boss_move_to_form2_b_start(void);
void stage4_boss_move_to_form2_b(void);
void stage4_boss_move_wander_high_b_start(void);
void stage4_boss_move_wander_high_b(void);
void stage4_boss_move_final_explosion_start(void);
void stage4_boss_move_final_explosion(void);
void stage4_boss_move_wait_start(void);
void stage4_boss_move_wait(void);
void stage4_boss_move_hover_high_start(void);
void stage4_boss_move_hover_high(void);
void stage4_boss_move_rage_start(void);
void stage4_boss_move_rage(void);

/*
 * The movement part of the boss slot (reg_a4). Every movement eases the speed toward target_speed, one step
 * every `pace` frames.
 */
typedef struct {
    /* 0x00 */ u16 unused_00;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 target_speed;
    /* 0x04 */ SlotTimer pace;
    /* 0x06 */ u16 waypoint;      /* offset of the current waypoint in the table */
    /* 0x08 */ SlotTimer hover;
} MovePath;

/* Entering in a shrinking circle, and the change to the second form. */
typedef struct {
    /* 0x00 */ u16 unused_00;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 target_speed;
    /* 0x04 */ SlotTimer pace;
    /* 0x06 */ u8 unused_06;
    /* 0x07 */ u8 step;
    /* 0x08 */ u16 radius;
    /* 0x0A */ u8 angle;
    /* 0x0B */ u8 unused_0B;
    /* 0x0C */ SlotTimer wait;
} MoveEnter;

#define PATH(pointer) ((MovePath *)(pointer))
#define ENTER(pointer) ((MoveEnter *)(pointer))

/* The set-up routine and the per-frame routine of every movement, by movement number. */
void (*stage4_boss_move_routines[])(void) = {
    stage4_boss_move_enter_start,
    stage4_boss_move_enter,
    stage4_boss_move_wander_high_start,
    stage4_boss_move_wander_high,
    stage4_boss_move_to_form2_start,
    stage4_boss_move_to_form2,
    stage4_boss_move_to_form2_b_start,
    stage4_boss_move_to_form2_b,
    stage4_boss_move_wander_high_b_start,
    stage4_boss_move_wander_high_b,
    stage4_boss_move_final_explosion_start,
    stage4_boss_move_final_explosion,
    stage4_boss_move_wait_start,
    stage4_boss_move_wait,
    stage4_boss_move_hover_high_start,
    stage4_boss_move_hover_high,
    stage4_boss_move_rage_start,
    stage4_boss_move_rage,
    0,
    0,
};

u16 stage4_boss_enter_flash[] = {
    0x0004, 0x7FFF, 0x0000, 0x04C0, 0x0004, 0x0005, 0x001F, 0x0003,
    0x7FFF, 0x0000, 0x0500, 0x000B, 0x000C, 0x001F, 0x0003, 0x7FFF,
    0x0000, 0x0540, 0x0012, 0x0013, 0x001F, 0x0003, 0x7FFF, 0x0000,
    0x07C0, 0x0019, 0x001A, 0x001F, 0x0003,
};

u16 stage4_boss_wander_waypoints[] = {
    0x7800, 0x1C00, 0x7600, 0x1E00, 0x7400, 0x1600, 0x7200, 0x1800,
};

u16 stage4_boss_wander_b_waypoints[] = {
    0x6000, 0x0C00, 0x5E00, 0x2E00, 0x5C00, 0x0A00, 0x5A00, 0x2C00,
};

u16 stage4_boss_hover_waypoints[] = {
    0x6800, 0x1A00, 0x6600, 0x1E00, 0x6400, 0x1800, 0x6200, 0x2000,
};

u16 stage4_boss_rage_waypoints[] = {
    0x6600, 0x1A00, 0x6400, 0x2000, 0x6200, 0x1800, 0x6000, 0x1E00,
    0x5E00, 0x1800, 0x6000, 0x2000, 0x6200, 0x1A00, 0x6400, 0x2000,
};

void stage4_boss_move_enter(void);
void stage4_boss_move_wander_high(void);
void stage4_boss_move_to_form2();
void stage4_boss_move_to_form2_b(void);
void stage4_boss_move_wander_high_b(void);
void stage4_boss_move_final_explosion();
void stage4_boss_move_wait(void);
void stage4_boss_move_hover_high(void);
void stage4_boss_move_rage(void);


void stage4_boss_speed_approach(void) {
    reg_d0.b[0] = PATH(reg_a4)->target_speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_tmp.b[0] = PATH(reg_a4)->pace.t.count;
    PATH(reg_a4)->pace.t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_1;
    PATH(reg_a4)->pace.t.count = PATH(reg_a4)->pace.t.reload;
    if (reg_d0.b[0] == reg_d1.b[0]) goto block_1;
    if ((s8) reg_d0.b[0] < (s8) reg_d1.b[0]) goto next_1;
    reg_d1.b[0] += 1;
    goto block_1;
next_1:
    reg_d1.b[0] -= 1;
block_1:
    ENTITY(reg_a6)->move.b.speed = reg_d1.b[0];
}


s32 entity_velocity();

void stage4_boss_parts_follow(void) {
    stage4_boss_speed_approach();
    entity_velocity();
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    ENTITY(reg_a6)[1].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[1].x.h = (u16) reg_d0.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)[12].hit_x_plus.h;
    ENTITY(reg_a6)[1].y.h += reg_d1.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)[12].hit_x_minus.h;
    ENTITY(reg_a6)[1].x.h += reg_d1.h[0];
    ENTITY(reg_a6)[4].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[4].x.h = (u16) reg_d0.h[0];
    reg_tmp.h[1] = ENTITY(reg_a6)[4].y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)[4].x.h;
    reg_tmp.w += 0xF2BFF500;
    ENTITY(reg_a6)[4].y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)[4].x.h = (u16) reg_tmp.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)[12].sprite.h;
    ENTITY(reg_a6)[4].y.h += reg_d1.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)[12].look.h;
    ENTITY(reg_a6)[4].x.h += reg_d1.h[0];
    ENTITY(reg_a6)[5].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[5].x.h = (u16) reg_d0.h[0];
    reg_tmp.h[1] = ENTITY(reg_a6)[5].y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)[5].x.h;
    reg_tmp.w += 0xF3000AC0;
    ENTITY(reg_a6)[5].y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)[5].x.h = (u16) reg_tmp.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)[12].hit_y_plus.h;
    ENTITY(reg_a6)[5].y.h += reg_d1.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)[12].hit_y_minus.h;
    ENTITY(reg_a6)[5].x.h += reg_d1.h[0];
    reg_d0.h[1] = ENTITY(reg_a6)[1].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[1].x.h;
    ENTITY(reg_a6)[2].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[2].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[2].y.h -= 0x2200;
    reg_d0.h[1] = ENTITY(reg_a6)[2].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[2].x.h;
    ENTITY(reg_a6)[3].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[3].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[3].y.h += 0xA00;
    ENTITY(reg_a6)[6].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[6].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[6].y.h += 0xA40;
    ENTITY(reg_a6)[6].x.h += 0x7FFF + 0x75C1;
    ENTITY(reg_a6)[7].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[7].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[7].y.h += 0xA40;
    ENTITY(reg_a6)[7].x.h += 0xA40;
    ENTITY(reg_a6)[8].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[8].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[8].y.h += 0x7FFF + 0x7B41;
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.w += 0xEC000000;
    ENTITY(reg_a6)[9].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[9].x.h = (u16) reg_d0.h[0];
}

s32 stage4_boss_shield_off(s32, s32, s32, s32); /* extern */

void stage4_boss_move_enter_start(void) {
    ENTER(reg_a4)->target_speed = 0;
    ENTER(reg_a4)->pace.sh = 0;
    ENTITY(reg_a6)->move.sh = 0x20;
    ENTER(reg_a4)->step = 0;
    ENTER(reg_a4)->radius = 0x280;
    ENTER(reg_a4)->unused_0B = 1;
    ENTER(reg_a4)->angle = 0;
    ENTER(reg_a4)->wait.sh = 0x101;
    ENTITY(reg_a6)[9].offset_y.sh = 0x1C;
    ENTITY(reg_a6)[9].offset_x.sh = 0;
    stage4_boss_shield_off(0x101, 1, 0x280, 0x20);
    stage4_boss_move_enter();
}

s32 boss_phase_start();
s32 boss_movement_start();
s32 boss_part_show();
s32 boss_part_hide();
s32 func_0013B2E0();
s32 sprite_palette_load();
s32 velocity_from_dir256();
extern u8 D_0025FEF0[];
extern u8 g_boss_present_b1;
extern u16 g_side_scroll_x[];

void stage4_boss_move_enter(void) {
    s32 boss_animation_start();
    if (ENTER(reg_a4)->step == 0) {
        ENTER(reg_a4)->angle += 2;
        reg_d0.h[0] = ENTER(reg_a4)->radius;
        reg_d1.w = 0;
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
        reg_d1.b[0] = ENTER(reg_a4)->angle;
        velocity_from_dir256();
        reg_d3.h[0] = (s16) reg_d3.h[0] * 8;
        reg_d1.h[0] = reg_d3.h[0];
        reg_d1.h[0] = (u16) -(s16) reg_d1.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 6);
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 4);
        reg_d1.h[0] += 7;
        if ((s16) reg_d1.h[0] > 0xF) {
            reg_d1.h[0] = 0xF;
        }
        if (0 > (s16) reg_d1.h[0]) {
            reg_d1.h[0] = 0;
        }
        reg_d1.h[0] += reg_d1.h[0];
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)[9].offset_y.h = (u16) reg_d1.h[0];
        reg_d0.h[0] = 0x1C00;
        reg_d0.h[0] += reg_d3.h[0];
        reg_d0.h[0] -= g_side_scroll_x[0];
        ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
        reg_d0.h[0] = ENTER(reg_a4)->radius;
        ENTITY(reg_a6)->y.h += reg_d0.h[0];
        ENTER(reg_a4)->radius -= 5;
        if ((s16) ENTER(reg_a4)->radius <= 0) {
            ENTER(reg_a4)->radius = 0U;
            ENTER(reg_a4)->step = 1U;
            reg_d0.w = 0xA;
            boss_part_hide();
            reg_d0.w = 0xB;
            boss_part_show();
        }
    }
    if (ENTER(reg_a4)->step == 1) {
        reg_tmp.b[0] = ENTER(reg_a4)->wait.t.count;
        ENTER(reg_a4)->wait.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            ENTER(reg_a4)->wait.t.count = (u8) ENTER(reg_a4)->wait.t.reload;
            ENTITY(reg_a6)[9].offset_x.h += 4;
            if ((s16) ENTITY(reg_a6)[9].offset_x.h > 0x1C) {
                ENTITY(reg_a6)[9].offset_x.h = 0U;
                reg_d0.w = 0xB;
                boss_part_hide();
                reg_d0.h[0] = 0x15;
                reg_a0 = (u8 *)D_0025FEF0;
                sprite_palette_load();
                g_boss_present_b1 |= 0x10;
                reg_d0.w = 1;
                g_boss_present_b1 |= 2;
                boss_movement_start();
                reg_d0.w = 3;
                boss_phase_start();
                reg_d0.w = 9;
                boss_animation_start();
                reg_d0.w = 0xA;
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
                ENTITY(reg_a6)[1].flags.h = 0xA001;
                ENTITY(reg_a6)[2].flags.h = 0xA001;
                ENTITY(reg_a6)[3].flags.h = 0xA001;
                reg_a0 = (u8 *)stage4_boss_enter_flash;
                func_0013B2E0();
            }
        }
    }
    stage4_boss_parts_follow();
}


void stage4_boss_move_wander_high_start(void) {
    PATH(reg_a4)->target_speed = 4;
    PATH(reg_a4)->pace.h = 0;
    PATH(reg_a4)->waypoint = 0;
    stage4_boss_move_wander_high();
}

s32 direction_turn_toward();

void stage4_boss_move_wander_high(void) {
    s32 direction_between(void *);
    s32 distance_between(u16, void *);
    u16 temp_a0;

    reg_a0 = ((u8 *)stage4_boss_wander_waypoints);
    reg_a0 += PATH(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between(reg_a6);
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_a0 = ((u8 *)stage4_boss_wander_waypoints);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_a0 += PATH(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    distance_between(temp_a0, reg_a6);
    if ((s16) reg_d0.h[0] < 0x201) {
        PATH(reg_a4)->waypoint += 4;
        PATH(reg_a4)->waypoint &= 0xF;
    }
    stage4_boss_parts_follow();
}


void stage4_boss_move_to_form2_start(void) {
    ENTITY(reg_a6)->move.b.speed = 0;
    ENTITY(reg_a6)->move.b.dir = 0x20;
    PATH(reg_a4)->target_speed = 0x20;
    PATH(reg_a4)->pace.h = 0x303;
    stage4_boss_move_to_form2(0x20);
}


void stage4_boss_move_to_form2() {
    stage4_boss_parts_follow();
}


void stage4_boss_move_to_form2_b_start(void) {
    s32 boss_animation_start(s32);
    ENTER(reg_a4)->target_speed = 4;
    ENTER(reg_a4)->pace.sh = 0x202;
    ENTER(reg_a4)->step = 0;
    reg_d0.w = 0;
    boss_animation_start(4);
    stage4_boss_move_to_form2_b();
}

s32 boss_movement_stop();
extern u8 D_0028DC84[];

void stage4_boss_move_to_form2_b(void) {
    s32 direction_between();
    s32 distance_between();
    reg_a0 = D_0028DC84;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] -= g_side_scroll_x[0];
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_a0 = D_0028DC84;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] -= g_side_scroll_x[0];
    distance_between();
    if ((s16) reg_d0.h[0] < 0x1401) {
        if (ENTER(reg_a4)->step == 0) {
            ENTER(reg_a4)->step = 1U;
            ENTER(reg_a4)->pace.sh = 0;
        }
        ENTER(reg_a4)->target_speed = 4;
        if ((s16) reg_d0.h[0] > 0x200) {
            stage4_boss_parts_follow();
            return;
        }
        ENTITY(reg_a6)->move.sb.speed = 0;
        reg_d0.w = 5;
        boss_phase_start();
        boss_movement_stop();
        stage4_boss_parts_follow();
        return;
    }
    ENTER(reg_a4)->target_speed = 0x20;
    stage4_boss_parts_follow();
}


void stage4_boss_move_wander_high_b_start(void) {
    ENTITY(reg_a6)->move.sb.speed = 0;
    ENTITY(reg_a6)->move.sb.dir = 0x20;
    PATH(reg_a4)->target_speed = 0;
    PATH(reg_a4)->pace.sh = 0;
    PATH(reg_a4)->waypoint = 0;
    ENTITY(reg_a6)[1].move.sb.speed = 6;
    stage4_boss_move_wander_high_b();
}

s32 velocity_from_direction();

void stage4_boss_move_wander_high_b(void) {
    s32 direction_between();
    s32 distance_between();
    reg_a0 = (u8 *)stage4_boss_wander_b_waypoints;
    reg_a0 += PATH(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += ENTITY(reg_a6)[12].hit_x_plus.h;
    reg_d1.h[0] += ENTITY(reg_a6)[12].hit_x_minus.h;
    direction_between();
    reg_d0.b[0] = ENTITY(reg_a6)[1].move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)[1].move.b.dir = (u8) reg_d1.b[0];
    reg_a0 = (u8 *)stage4_boss_wander_b_waypoints;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += ENTITY(reg_a6)[12].hit_x_plus.h;
    reg_d1.h[0] += ENTITY(reg_a6)[12].hit_x_minus.h;
    reg_a0 += PATH(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    distance_between();
    if ((s16) reg_d0.h[0] < 0x401) {
        PATH(reg_a4)->waypoint += 4;
        PATH(reg_a4)->waypoint &= 0xF;
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)[1].move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)[1].move.b.dir;
    velocity_from_direction();
    ENTITY(reg_a6)[12].hit_x_plus.h += reg_d2.h[0];
    ENTITY(reg_a6)[12].hit_x_minus.h += reg_d3.h[0];
    stage4_boss_parts_follow();
}


void stage4_boss_move_final_explosion_start(void) {
    ENTITY(reg_a6)->move.b.dir = 0x20;
    PATH(reg_a4)->target_speed = 1;
    PATH(reg_a4)->pace.h = 0;
    stage4_boss_move_final_explosion(0x20);
}

void stage4_boss_move_final_explosion() {
    stage4_boss_parts_follow();
}


void stage4_boss_move_wait_start(void) {
    ENTITY(reg_a6)->move.b.speed = 0;
    ENTITY(reg_a6)->move.b.dir = 0x20;
    PATH(reg_a4)->target_speed = 0;
    PATH(reg_a4)->pace.h = 0;
    stage4_boss_move_wait();
}

void stage4_boss_move_wait(void) {
    stage4_boss_parts_follow();
}




void stage4_boss_move_hover_high_start(void) {
    PATH(reg_a4)->target_speed = 0;
    PATH(reg_a4)->pace.h = 0;
    PATH(reg_a4)->waypoint = 0;
    PATH(reg_a4)->hover.h = 0x808;
    stage4_boss_move_hover_high();
}

void stage4_boss_move_hover_high(void) {
    s32 direction_between();
    s32 distance_between();
    u8 temp_v0;

    reg_tmp.b[0] = PATH(reg_a4)->hover.t.count;
    PATH(reg_a4)->hover.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        PATH(reg_a4)->hover.t.count = (u8) PATH(reg_a4)->hover.t.reload;
        temp_v0 = ENTITY(reg_a6)[1].move.b.speed;
        if (temp_v0 != 2) {
            ENTITY(reg_a6)[1].move.b.speed = (u8) (temp_v0 - 1);
            if ((s8) ENTITY(reg_a6)[1].move.b.speed < 3) {
                ENTITY(reg_a6)[1].move.b.speed = 2U;
            }
        }
    }
    reg_a0 = (u8 *)stage4_boss_hover_waypoints;
    reg_a0 += PATH(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += ENTITY(reg_a6)[12].hit_x_plus.h;
    reg_d1.h[0] += ENTITY(reg_a6)[12].hit_x_minus.h;
    direction_between();
    reg_d0.b[0] = ENTITY(reg_a6)[1].move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)[1].move.b.dir = (u8) reg_d1.b[0];
    reg_a0 = (u8 *)stage4_boss_hover_waypoints;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += ENTITY(reg_a6)[12].hit_x_plus.h;
    reg_d1.h[0] += ENTITY(reg_a6)[12].hit_x_minus.h;
    reg_a0 += PATH(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    distance_between();
    if ((s16) reg_d0.h[0] < 0x201) {
        PATH(reg_a4)->waypoint += 4;
        PATH(reg_a4)->waypoint &= 0xF;
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)[1].move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)[1].move.b.dir;
    velocity_from_direction();
    ENTITY(reg_a6)[12].hit_x_plus.h += reg_d2.h[0];
    ENTITY(reg_a6)[12].hit_x_minus.h += reg_d3.h[0];
    stage4_boss_parts_follow();
}


void stage4_boss_move_rage_start(void) {
    ENTITY(reg_a6)->move.sb.speed = 0;
    ENTITY(reg_a6)->move.sb.dir = 0x20;
    PATH(reg_a4)->target_speed = 0;
    PATH(reg_a4)->pace.sh = 0;
    PATH(reg_a4)->waypoint = 4;
    ENTITY(reg_a6)[1].move.sb.speed = 4;
    stage4_boss_move_rage();
}

void stage4_boss_move_rage(void) {
    s32 direction_between();
    s32 distance_between();
    reg_a0 = (u8 *)stage4_boss_rage_waypoints;
    reg_a0 += PATH(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += ENTITY(reg_a6)[12].hit_x_plus.h;
    reg_d1.h[0] += ENTITY(reg_a6)[12].hit_x_minus.h;
    direction_between();
    reg_d0.b[0] = ENTITY(reg_a6)[1].move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)[1].move.b.dir = (u8) reg_d1.b[0];
    reg_a0 = (u8 *)stage4_boss_rage_waypoints;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += ENTITY(reg_a6)[12].hit_x_plus.h;
    reg_d1.h[0] += ENTITY(reg_a6)[12].hit_x_minus.h;
    reg_a0 += PATH(reg_a4)->waypoint;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    distance_between();
    if ((s16) reg_d0.h[0] < 0x401) {
        PATH(reg_a4)->waypoint += 4;
        if ((s16) PATH(reg_a4)->waypoint > 0x1C) {
            PATH(reg_a4)->waypoint = 0U;
        }
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)[1].move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)[1].move.b.dir;
    velocity_from_direction();
    ENTITY(reg_a6)[12].hit_x_plus.h += reg_d2.h[0];
    ENTITY(reg_a6)[12].hit_x_minus.h += reg_d3.h[0];
    stage4_boss_parts_follow();
}

u8 D_0028DC84[4] = {
    0x00, 0x60, 0x00, 0x1C,
};
