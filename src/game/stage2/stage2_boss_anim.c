#include "common.h"
#include "entity.h"
#include "enemy_kinds.h"
#include "stage2_boss.h"

void stage2_boss_lower_splash_start(void);
void stage2_boss_lower_splash(void);
void stage2_boss_radome_idle_start(void);
void stage2_boss_radome_idle(void);
void stage2_boss_torso_idle_start(void);
void stage2_boss_torso_idle(void);
void stage2_boss_radome_spin_start(void);
void stage2_boss_radome_spin(void);
void stage2_boss_shoulder_turrets_aim(void);
void stage2_boss_shoulder_turrets_aim_wide(void);
void stage2_boss_torso_open_start(void);
void stage2_boss_torso_open(void);
void stage2_boss_torso_close_start(void);
void stage2_boss_torso_close(void);
void stage2_boss_recoil_start(void);
void stage2_boss_recoil(void);
void stage2_boss_shoulder_cannon_open_start(void);
void stage2_boss_shoulder_cannon_open(void);
void stage2_boss_shoulder_cannon_close_start(void);
void stage2_boss_shoulder_cannon_close(void);
void stage2_boss_shoulder_turret_anim_start(void);
void stage2_boss_shoulder_turret_anim(void);
void stage2_boss_side_gun_anim_start(void);
void stage2_boss_side_gun_anim(void);
void stage2_boss_ripple_request_start(void);
void stage2_boss_ripple_request(void);

/* The animation part of the boss slot (reg_a4). */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer frame;
    /* 0x04 */ u16 step;
} FrameStep;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 target;
    /* 0x03 */ u8 turning;        /* 0: waiting, 1: turning */
    /* 0x04 */ SlotTimer turn;
    /* 0x06 */ u16 wait;
} RadomeIdle;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 unused_02;
    /* 0x04 */ u16 unread_04;
    /* 0x06 */ u8 unused_06;
    /* 0x07 */ u8 step;           /* 1 or -1 */
} RadomeSpin;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer back;
    /* 0x04 */ SlotTimer forward;
    /* 0x06 */ u8 unused_06;
    /* 0x07 */ u8 returning;
} Recoil;

#define STEP(pointer) ((FrameStep *)(pointer))
#define RADOME_IDLE(pointer) ((RadomeIdle *)(pointer))
#define RADOME_SPIN(pointer) ((RadomeSpin *)(pointer))
#define RECOIL(pointer) ((Recoil *)(pointer))

/* The set-up routine and the per-frame routine of every animation, by animation number. */
void (*stage2_boss_anim_routines[])(void) = {
    stage2_boss_lower_splash_start,
    stage2_boss_lower_splash,
    stage2_boss_radome_idle_start,
    stage2_boss_radome_idle,
    stage2_boss_torso_idle_start,
    stage2_boss_torso_idle,
    stage2_boss_radome_spin_start,
    stage2_boss_radome_spin,
    stage2_boss_shoulder_turrets_aim,
    stage2_boss_shoulder_turrets_aim,
    stage2_boss_shoulder_turrets_aim_wide,
    stage2_boss_shoulder_turrets_aim_wide,
    stage2_boss_torso_open_start,
    stage2_boss_torso_open,
    stage2_boss_torso_close_start,
    stage2_boss_torso_close,
    stage2_boss_recoil_start,
    stage2_boss_recoil,
    stage2_boss_shoulder_cannon_open_start,
    stage2_boss_shoulder_cannon_open,
    stage2_boss_shoulder_cannon_close_start,
    stage2_boss_shoulder_cannon_close,
    stage2_boss_shoulder_turret_anim_start,
    stage2_boss_shoulder_turret_anim,
    stage2_boss_side_gun_anim_start,
    stage2_boss_side_gun_anim,
    stage2_boss_ripple_request_start,
    stage2_boss_ripple_request,
};

void stage2_boss_lower_splash(void);
void stage2_boss_radome_idle(void);
void stage2_boss_torso_idle(void);
void stage2_boss_radome_spin(void);
void stage2_boss_torso_open(void);
void stage2_boss_torso_close(void);
void stage2_boss_recoil(void);
void stage2_boss_shoulder_cannon_open(void);
void stage2_boss_shoulder_cannon_close(void);
void stage2_boss_shoulder_turret_anim(void);
void stage2_boss_side_gun_anim(void);
void stage2_boss_ripple_request(void);


void stage2_boss_lower_splash_start(void) {
    ENTITY(reg_a6)[1].offset_y.sh = 2;
    ENTITY(reg_a6)[1].offset_x.sh = 0;
    stage2_boss_lower_splash();
}


void stage2_boss_lower_splash(void) {
    reg_tmp.b[0] = ENTITY(reg_a6)[1].offset_y.b[1];
    ENTITY(reg_a6)[1].offset_y.b[1] -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ENTITY(reg_a6)[1].offset_y.b[1] = (u8) ENTITY(reg_a6)[1].offset_y.b[0];
        ENTITY(reg_a6)[1].offset_x.h += 4;
        if (ENTITY(reg_a6)[1].offset_x.h == 0x20) {
            ENTITY(reg_a6)[1].offset_x.h = 0U;
        }
    }
}

extern void rng_next_masked(void);

void stage2_boss_radome_idle_pick(void)
{
    extern void rng_next_bit(void);
    RADOME_IDLE(reg_a4)->turn.h = 0;
    rng_next_bit();
    RADOME_IDLE(reg_a4)->turn.t.reload = reg_d0.b[0];
    rng_next_masked();
    RADOME_IDLE(reg_a4)->target = reg_d0.b[0];
    rng_next_masked();
    RADOME_IDLE(reg_a4)->wait = reg_d0.h[0];
    RADOME_IDLE(reg_a4)->turning = 0;
}


void stage2_boss_radome_idle_start(void) {
    stage2_boss_radome_idle_pick();
    stage2_boss_radome_idle();
}

s32 direction_turn_toward();

void stage2_boss_radome_idle() {
    u8 temp_a0;
    u8 temp_a0_2;

    if (RADOME_IDLE(reg_a4)->turning == 0) {
        RADOME_IDLE(reg_a4)->wait -= 1;
        if ((s16) RADOME_IDLE(reg_a4)->wait < 0) {
            RADOME_IDLE(reg_a4)->turning = 1U;
        }
    }
    temp_a0 = RADOME_IDLE(reg_a4)->turning;
    if (temp_a0 == 1) {
        reg_tmp.b[0] = RADOME_IDLE(reg_a4)->turn.t.count;
        RADOME_IDLE(reg_a4)->turn.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            RADOME_IDLE(reg_a4)->turn.t.count = (u8) RADOME_IDLE(reg_a4)->turn.t.reload;
            reg_d0.w = 0;
            reg_d1.w = 0;
            reg_d0.b[0] = ENTITY(reg_a6)[8].move.b.dir;
            reg_d1.b[0] = RADOME_IDLE(reg_a4)->target;
            direction_turn_toward();
            ENTITY(reg_a6)[8].move.b.dir = (u8) reg_d1.b[0];
            temp_a0_2 = RADOME_IDLE(reg_a4)->target;
            if (temp_a0_2 == reg_d1.b[0]) {
                stage2_boss_radome_idle_pick();
            }
        }
    }
}



void stage2_boss_torso_idle_start(void) {
    STEP(reg_a4)->frame.h = 3;
    STEP(reg_a4)->step = 0;
    stage2_boss_torso_idle();
}


extern u8 D_0026C0A0[];

void stage2_boss_torso_idle(void) {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32)reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = STEP(reg_a4)->frame.t.reload;
        reg_a0 = D_0026C0A0;
        reg_a0 += STEP(reg_a4)->step;
        (ENTITY(reg_a6)->offset_y.h) = *(u16 *)reg_a0;
        STEP(reg_a4)->step += 2;
        if (STEP(reg_a4)->step == 0xC) {
            STEP(reg_a4)->step = 0;
        }
    }
}


void stage2_boss_radome_spin_start(void) {
    s32 rng_next_bit();
    RADOME_SPIN(reg_a4)->unread_04 = 0;
    RADOME_SPIN(reg_a4)->step = 1U;
    rng_next_bit();
    if (reg_d0.h[0] != 0) {
        stage2_boss_radome_spin();
        return;
    }
    RADOME_SPIN(reg_a4)->step *= -1;
    stage2_boss_radome_spin();
}

void stage2_boss_radome_spin(void) {
    reg_d0.b[0] = RADOME_SPIN(reg_a4)->step;
    ENTITY(reg_a6)[8].move.b.dir += reg_d0.b[0];
    ENTITY(reg_a6)[8].move.b.dir &= 0x3F;
}

s32 aim_at_player();                            /* extern */
s32 direction_turn_toward();                            /* extern */

void stage2_boss_shoulder_turrets_aim(void) {
    reg_d0.h[0] = ENTITY(reg_a6)[4].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[4].x.h;
    aim_at_player();
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)[4].move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)[4].move.b.dir = (u8) reg_d1.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)[5].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[5].x.h;
    aim_at_player();
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)[5].move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)[5].move.b.dir = (u8) reg_d1.b[0];
}

s32 aim_at_player();                            /* extern */
s32 direction_turn_toward();                            /* extern */

void stage2_boss_shoulder_turrets_aim_wide(void) {
    reg_d0.h[0] = ENTITY(reg_a6)[4].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[4].x.h;
    aim_at_player();
    reg_d0.w = 0;
    reg_d1.b[0] += 0x14;
    reg_d1.b[0] &= 0x3F;
    reg_d0.b[0] = ENTITY(reg_a6)[4].move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)[4].move.b.dir = (u8) reg_d1.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)[5].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[5].x.h;
    aim_at_player();
    reg_d0.w = 0;
    reg_d1.b[0] += 0x2C;
    reg_d1.b[0] &= 0x3F;
    reg_d0.b[0] = ENTITY(reg_a6)[5].move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)[5].move.b.dir = (u8) reg_d1.b[0];
}


void stage2_boss_torso_open_start(void) {
    STEP(reg_a4)->frame.h = 2;
    STEP(reg_a4)->step = 0;
    stage2_boss_torso_open();
}

void stage2_boss_torso_open(void) {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        ENTITY(reg_a6)->offset_y.h += 4;
        if (ENTITY(reg_a6)->offset_y.h == 0x1C) {
            STEP(reg_a4)->running = 0;
        }
    }
}



void stage2_boss_torso_close_start(void) {
    STEP(reg_a4)->frame.h = 0x2002;
    STEP(reg_a4)->step = 0;
    stage2_boss_torso_close();
}

s32 boss_animation_start();

void stage2_boss_torso_close() {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        ENTITY(reg_a6)->offset_y.h -= 4;
        if (ENTITY(reg_a6)->offset_y.h == 0) {
            STEP(reg_a4)->running = 0;
            reg_d0.w = 2;
            boss_animation_start();
        }
    }
}


void stage2_boss_recoil_start(void) {
    RECOIL(reg_a4)->back.h = 0;
    RECOIL(reg_a4)->forward.h = 4;
    RECOIL(reg_a4)->returning = 0;
    stage2_boss_recoil();
}

void stage2_boss_recoil(void) {
    if (RECOIL(reg_a4)->returning == 1) {
        STAGE2_EXTRA(reg_a6)->recoil_offset -= 0x20;
        if (0 > (s16) STAGE2_EXTRA(reg_a6)->recoil_offset) {
            STAGE2_EXTRA(reg_a6)->recoil_offset = 0U;
        }
        reg_tmp.b[0] = RECOIL(reg_a4)->forward.t.count;
        RECOIL(reg_a4)->forward.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            RECOIL(reg_a4)->forward.t.count = (u8) RECOIL(reg_a4)->forward.t.reload;
            STAGE2_EXTRA(reg_a6)->shoulder_cannon_anim += 4;
            if (STAGE2_EXTRA(reg_a6)->shoulder_cannon_anim == 0x40) {
                STAGE2_EXTRA(reg_a6)->shoulder_cannon_anim = 0U;
                STAGE2_EXTRA(reg_a6)->recoil_offset = 0U;
                RECOIL(reg_a4)->running = 0;
            }
        }
    }
    if (RECOIL(reg_a4)->returning == 0) {
        STAGE2_EXTRA(reg_a6)->recoil_offset += 0x100;
        reg_tmp.b[0] = RECOIL(reg_a4)->back.t.count;
        RECOIL(reg_a4)->back.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            RECOIL(reg_a4)->back.t.count = (u8) RECOIL(reg_a4)->back.t.reload;
            STAGE2_EXTRA(reg_a6)->shoulder_cannon_anim += 0x10;
            if (STAGE2_EXTRA(reg_a6)->shoulder_cannon_anim == 0x20) {
                RECOIL(reg_a4)->returning = 1U;
                RECOIL(reg_a4)->forward.h = 0;
            }
        }
    }
}


void stage2_boss_shoulder_cannon_open_start(void) {
    STEP(reg_a4)->frame.h = 1;
    stage2_boss_shoulder_cannon_open();
}

void stage2_boss_shoulder_cannon_open(void) {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        STAGE2_EXTRA(reg_a6)->shoulder_cannon_anim += 4;
        if ((s16) STAGE2_EXTRA(reg_a6)->shoulder_cannon_anim >= 0x20) {
            STAGE2_EXTRA(reg_a6)->shoulder_cannon_anim = 0x20U;
            STEP(reg_a4)->running = 0;
        }
    }
}


void stage2_boss_shoulder_cannon_close_start(void) {
    STEP(reg_a4)->frame.h = 1;
    stage2_boss_shoulder_cannon_close();
}

void stage2_boss_shoulder_cannon_close(void)
{
    s16 *remaining;

    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32)(u8)reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = STEP(reg_a4)->frame.t.reload;
        STAGE2_EXTRA(reg_a6)->shoulder_cannon_anim -= 4;
        remaining = (s16 *)&STAGE2_EXTRA(reg_a6)->shoulder_cannon_anim;
        if (0 < *remaining) {
            return;
        }
        *remaining = 0;
        STEP(reg_a4)->running = 0;
    }
}


void stage2_boss_shoulder_turret_anim_start(void) {
    STEP(reg_a4)->frame.h = 0x202;
    stage2_boss_shoulder_turret_anim();
}

void stage2_boss_shoulder_turret_anim(void) {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        STAGE2_EXTRA(reg_a6)->base_anim += 4;
        if ((s16) STAGE2_EXTRA(reg_a6)->base_anim >= 0x38) {
            STAGE2_EXTRA(reg_a6)->base_anim = 0U;
        }
    }
}

s32 rng_next_unsigned();

void stage2_boss_side_gun_anim_start(void) {
    STEP(reg_a4)->frame.h = 0x101;
    rng_next_unsigned();
    reg_d0.h[0] &= 0xF;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    ENTITY(reg_a6)[6].offset_y.h = (u16) reg_d0.h[0];
    rng_next_unsigned();
    reg_d0.h[0] &= 0xF;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    ENTITY(reg_a6)[7].offset_y.h = (u16) reg_d0.h[0];
    stage2_boss_side_gun_anim();
}

void stage2_boss_side_gun_anim(void) {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        ENTITY(reg_a6)[6].offset_y.h += 4;
        ENTITY(reg_a6)[6].offset_y.h &= 0x3F;
        ENTITY(reg_a6)[7].offset_y.h += 4;
        ENTITY(reg_a6)[7].offset_y.h &= 0x3F;
    }
}


void stage2_boss_ripple_request_start(void) {
    STEP(reg_a4)->frame.h = 0;
    STEP(reg_a4)->step = 0;
    stage2_boss_ripple_request();
}

s32 spawn_request_add();
extern u8 D_0026C0B0[];

void stage2_boss_ripple_request(void) {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        reg_d0.w = ENEMY_STAGE2_BOSS_RIPPLE;
        spawn_request_add();
        reg_d0.h[1] = ENTITY(reg_a6)[1].y.h;
        reg_d0.h[0] = ENTITY(reg_a6)[1].x.h;
        reg_a1 = D_0026C0B0;
        reg_a1 += STEP(reg_a4)->step;
        reg_tmp.h[1] = *(u16 *)reg_a1;
        reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
        reg_d0.w += reg_tmp.w;
        STAGE2_SHOT(reg_a0)->at_start.y = (u16) reg_d0.h[1];
        STAGE2_SHOT(reg_a0)->at_start.x = (u16) reg_d0.h[0];
        STEP(reg_a4)->step += 4;
        STEP(reg_a4)->step &= 0xF;
    }
}

u8 D_0026C0A0[32] = {
    0x00, 0x00, 0x04, 0x00, 0x08, 0x00, 0x0C, 0x00, 0x08, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xF0, 0x00, 0xF5, 0x00, 0xF0, 0x00, 0x05, 0x80, 0xF4, 0x00, 0xF1, 0x80, 0xF4, 0x00, 0x09,
};
