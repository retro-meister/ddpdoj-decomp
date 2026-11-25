#include "common.h"
#include "entity.h"

void stage3_boss_move_enter_start(void);
void stage3_boss_move_enter(void);
void stage3_boss_move_wander_low_start(void);
void stage3_boss_move_wander_low(void);
void stage3_boss_move_wander_high_start(void);
void stage3_boss_move_wander_high(void);
void stage3_boss_move_wander_mid_start(void);
void stage3_boss_move_wander_mid(void);

/* Two bytes of a boss slot that are set together as one word: a reload value and its countdown. */
typedef union {
    u16 h;
    s16 sh;
    struct { u8 reload; u8 count; } t;
} SlotTimer;

/* The movement part of the boss slot (reg_a4). */
typedef struct {
    /* 0x00 */ SlotTimer brake;   /* entering: frames between two steps of slowing down */
} MoveEnter;

typedef struct {
    /* 0x00 */ u8 turning;        /* still turning toward target_dir */
    /* 0x01 */ u8 target_dir;
} MoveWander;

#define ENTER(pointer) ((MoveEnter *)(pointer))
#define WANDER(pointer) ((MoveWander *)(pointer))

/* The set-up routine and the per-frame routine of every movement, by movement number. */
void (*stage3_boss_move_routines[])(void) = {
    stage3_boss_move_enter_start,
    stage3_boss_move_enter,
    stage3_boss_move_wander_low_start,
    stage3_boss_move_wander_low,
    stage3_boss_move_wander_high_start,
    stage3_boss_move_wander_high,
    stage3_boss_move_wander_mid_start,
    stage3_boss_move_wander_mid,
};

void stage3_boss_move_enter(void);
void stage3_boss_move_wander_low(void);
void stage3_boss_move_wander_high(void);
void stage3_boss_move_wander_mid(void);


void stage3_boss_parts_follow(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0xF800 & 0xFFFF;
    reg_d0.h[0] += ENTITY(reg_a6)[1].offset_y.h;
    ENTITY(reg_a6)[1].y.h = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x7FFF + 0x7401;
    reg_d1.h[0] += ENTITY(reg_a6)[1].offset_x.h;
    ENTITY(reg_a6)[1].x.h = (u16) reg_d1.h[0];
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x7FFF + 0x7801;
    reg_d0.h[0] += ENTITY(reg_a6)[2].offset_y.h;
    ENTITY(reg_a6)[2].y.h = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0xC00;
    reg_d1.h[0] += ENTITY(reg_a6)[2].offset_x.sh;
    ENTITY(reg_a6)[2].x.h = (u16) reg_d1.h[0];
    ENTITY(reg_a6)[6].y.h = (u16) ENTITY(reg_a6)[1].y.h;
    ENTITY(reg_a6)[6].x.h = (u16) ENTITY(reg_a6)[1].x.h;
    ENTITY(reg_a6)[7].y.h = (u16) ENTITY(reg_a6)[2].y.h;
    ENTITY(reg_a6)[7].x.h = (u16) ENTITY(reg_a6)[2].x.h;
}

extern void *reg_a6_as_void_p;

void stage3_boss_move_enter_start(void)
{
    ENTER(reg_a4)->brake.sh = 0x1818;
    ((u8 *)reg_a6_as_void_p)[0x1B] = 0xC;
    ((u8 *)reg_a6_as_void_p)[0x1A] = 0xE;
    ((u16 *)reg_a6_as_void_p)[1] = 0x4400;
    ((u16 *)reg_a6_as_void_p)[2] = 0xEC00;
    stage3_boss_move_enter();
}

s32 boss_phase_start();
s32 boss_phase_stop();
s32 boss_animation_running(void *);
s32 entity_velocity();

void stage3_boss_move_enter(void) {
    u8 temp_v1;

    reg_tmp.b[0] = ENTER(reg_a4)->brake.t.count;
    ENTER(reg_a4)->brake.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ENTER(reg_a4)->brake.t.count = (u8) ENTER(reg_a4)->brake.t.reload;
        temp_v1 = ENTITY(reg_a6)->move.b.speed;
        if (temp_v1 != 4) {
            ENTITY(reg_a6)->move.b.speed = (u8) (temp_v1 - 1);
            goto block_5;
        }
        reg_d0.w = 7;
        boss_animation_running(reg_a6 + 0x1B);
        if (cond_flag == 0) {
            reg_d0.w = 0;
            boss_phase_stop();
            reg_d0.w = 2;
            boss_phase_start();
            stage3_boss_parts_follow();
            return;
        }
        goto block_5;
    }
block_5:
    entity_velocity();
    stage3_boss_parts_follow();
}



void stage3_boss_move_wander_low_start(void) {
    reg_d0.w = 0;
    WANDER(reg_a4)->target_dir = reg_d0.b[0];
    WANDER(reg_a4)->turning = reg_d0.b[0];
    stage3_boss_move_wander_low();
}

s32 rng_next();
s32 func_002024C0();

void stage3_boss_move_wander_low(void) {
    entity_velocity();
    if (WANDER(reg_a4)->turning != 0) {
        reg_d1.b[0] = WANDER(reg_a4)->target_dir;
        func_002024C0();
        if (WANDER(reg_a4)->target_dir == reg_d1.b[0]) {
            WANDER(reg_a4)->turning = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x3A00) {
        reg_d0.b[0] += 0x10;
        goto block_12;
    }
    if ((s32) reg_d1.h[0] >= 0x4E00) {
        reg_d0.b[0] += 0x30;
        goto block_12;
    }
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    if ((s32) reg_d1.h[0] >= 0x5C00) {
        if ((s32) reg_d1.h[0] < 0x6400) {
            stage3_boss_parts_follow();
            return;
        }
        reg_d0.b[0] += 0x20;
    goto block_12;
    }
block_12:
    reg_d0.b[0] &= 0x3F;
    WANDER(reg_a4)->target_dir = (u8) reg_d0.b[0];
    WANDER(reg_a4)->turning = 1U;
    stage3_boss_parts_follow();
}


void stage3_boss_move_wander_high_start(void) {
    reg_d0.w = 0;
    WANDER(reg_a4)->target_dir = reg_d0.b[0];
    WANDER(reg_a4)->turning = reg_d0.b[0];
    stage3_boss_move_wander_high();
}

void stage3_boss_move_wander_high(void) {
    entity_velocity();
    if (WANDER(reg_a4)->turning != 0) {
        reg_d1.b[0] = WANDER(reg_a4)->target_dir;
        func_002024C0();
        if (WANDER(reg_a4)->target_dir == reg_d1.b[0]) {
            WANDER(reg_a4)->turning = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x3600) {
        reg_d0.b[0] += 0x10;
        goto block_12;
    }
    if ((s32) reg_d1.b[0] >= 0x5200) {
        reg_d0.b[0] += 0x30;
        goto block_12;
    }
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    if ((s32) reg_d1.h[0] >= 0x6600) {
        if ((s32) reg_d1.h[0] < 0x6A00) {
            stage3_boss_parts_follow();
            return;
        }
        reg_d0.b[0] += 0x20;
    goto block_12;
    }
block_12:
    reg_d0.b[0] &= 0x3F;
    WANDER(reg_a4)->target_dir = (u8) reg_d0.b[0];
    WANDER(reg_a4)->turning = 1U;
    stage3_boss_parts_follow();
}


void stage3_boss_move_wander_mid_start(void) {
    reg_d0.w = 0;
    WANDER(reg_a4)->target_dir = reg_d0.b[0];
    WANDER(reg_a4)->turning = reg_d0.b[0];
    stage3_boss_move_wander_mid();
}

void stage3_boss_move_wander_mid(void) {
    entity_velocity();
    if (WANDER(reg_a4)->turning != 0) {
        reg_d1.b[0] = WANDER(reg_a4)->target_dir;
        func_002024C0();
        if (WANDER(reg_a4)->target_dir == reg_d1.b[0]) {
            WANDER(reg_a4)->turning = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x3C00) {
        reg_d0.b[0] += 0x10;
        goto block_12;
    }
    if ((s32) reg_d1.h[0] >= 0x4C00) {
        reg_d0.b[0] += 0x30;
        goto block_12;
    }
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    if ((s32) reg_d1.h[0] >= 0x5E00) {
        if ((s32) reg_d1.h[0] < 0x6600) {
            stage3_boss_parts_follow();
            return;
        }
        reg_d0.b[0] += 0x20;
    goto block_12;
    }
block_12:
    reg_d0.b[0] &= 0x3F;
    WANDER(reg_a4)->target_dir = (u8) reg_d0.b[0];
    WANDER(reg_a4)->turning = 1U;
    stage3_boss_parts_follow();
}
