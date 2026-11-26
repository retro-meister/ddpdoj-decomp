#include "common.h"
#include "entity.h"
#include "stage1_boss.h"

void stage1_boss_mode_enter_start(void);
void stage1_boss_mode_enter(void);
void stage1_boss_mode_normal_start(void);
void stage1_boss_mode_normal(void);
void stage1_boss_mode_vulcan_start(void);
void stage1_boss_mode_vulcan(void);
void stage1_boss_mode_side_attack_start(void);
void stage1_boss_mode_side_attack(void);
void stage1_boss_mode_one_side_lost_start(void);
void stage1_boss_mode_one_side_lost(void);
void stage1_boss_mode_both_sides_lost_start(void);
void stage1_boss_mode_both_sides_lost(void);
void stage1_boss_mode_gatling_start(void);
void stage1_boss_mode_gatling(void);

/* The set-up routine and the per-frame routine of every mode, by mode number. */
void (*stage1_boss_mode_routines[])(void) = {
    stage1_boss_mode_enter_start,
    stage1_boss_mode_enter,
    stage1_boss_mode_normal_start,
    stage1_boss_mode_normal,
    stage1_boss_mode_vulcan_start,
    stage1_boss_mode_vulcan,
    stage1_boss_mode_side_attack_start,
    stage1_boss_mode_side_attack,
    stage1_boss_mode_one_side_lost_start,
    stage1_boss_mode_one_side_lost,
    stage1_boss_mode_both_sides_lost_start,
    stage1_boss_mode_both_sides_lost,
    stage1_boss_mode_gatling_start,
    stage1_boss_mode_gatling,
    0,
    0,
};

u16 stage1_boss_beam_levels[] = {
    0xFFFC, 0xFFFD, 0xFFFE, 0xFFFF, 0x0000, 0x0001, 0x0002, 0x0003,
};

u16 stage1_boss_beam_speeds[] = {
    0xFFFC, 0xFFFC, 0xFFFC, 0xFFFC, 0xFFFE, 0x0000, 0x0002, 0x0004,
};

u16 stage1_boss_gatling_levels[] = {
    0x0003, 0x0001, 0x0003, 0x0001, 0x0004, 0x0002, 0x0005, 0x0003,
    0x0006, 0x0003, 0x0008, 0x0004, 0x0008, 0x0004, 0x0009, 0x0005,
};

/*
 * The mode part of the boss slot (reg_a4), one record per mode. `running` is cleared when the mode hands over.
 * The attack records it fills in are in stage1_boss.h.
 */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 delay;
} EnterMode;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;
    /* 0x04 */ SlotTimer turrets;      /* wait between two turret attacks */
    /* 0x06 */ union {
        u16 h;                         /* becomes the turret attack's shot timer */
        struct { u8 wait; u8 zero; } b;
    } turret_shot;
    /* 0x08 */ u8 unused_08;
    /* 0x09 */ u8 turret_volleys;
    /* 0x0A */ SlotTimer beams;        /* wait between two beam attacks */
    /* 0x0C */ u8 unused_0C;
    /* 0x0D */ union { u8 b; s8 sb; } side; /* 1: the right side fires next, -1: the left */
    /* 0x0E */ u16 beam_level;
    /* 0x10 */ u16 beam_speed;
    /* 0x12 */ s16 unused_12;
    /* 0x14 */ u8 unused_14;
    /* 0x15 */ u8 pause;
} NormalMode;

/* The vulcan and side attack modes: the sides open, fire and close again. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 guns_open;
    /* 0x03 */ u8 step;
    /* 0x04 */ u16 delay;
    /* 0x06 */ s16 unused_06;
} SidesMode;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;
    /* 0x04 */ u16 delay;
    /* 0x06 */ SlotTimer front;          /* wait between two front gun attacks */
    /* 0x08 */ SlotTimer front_volleys;  /* how many in a row */
    /* 0x0A */ SlotTimer spread;         /* the same for the spread attack */
    /* 0x0C */ SlotTimer spread_volleys;
} OneSideMode;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;
    /* 0x04 */ SlotTimer body;           /* wait between two body attacks */
    /* 0x06 */ u16 unused_06;
} BothSidesMode;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 sweep_start;
    /* 0x03 */ u8 step;
    /* 0x04 */ SlotTimer aim;            /* frames between two steps of turning the gun toward the player */
    /* 0x06 */ u16 sweep_side;           /* 1 or -1, changes with every volley */
    /* 0x08 */ u8 unused_08;
    /* 0x09 */ u8 volley_speed;
    /* 0x0A */ SlotTimer volley;         /* wait between two volleys; gets shorter */
    /* 0x0C */ u16 volleys_left;
    /* 0x0E */ u16 volley_shots;
    /* 0x10 */ u8 volley_number;
    /* 0x11 */ u8 aiming;
    /* 0x12 */ u16 end_delay;
    /* 0x14 */ s16 unused_14;
} GatlingMode;

#define ENTER_MODE(pointer) ((EnterMode *)(pointer))
#define NORMAL_MODE(pointer) ((NormalMode *)(pointer))
#define SIDES_MODE(pointer) ((SidesMode *)(pointer))
#define ONE_SIDE_MODE(pointer) ((OneSideMode *)(pointer))
#define BOTH_SIDES_MODE(pointer) ((BothSidesMode *)(pointer))
#define GATLING_MODE(pointer) ((GatlingMode *)(pointer))

s32 boss_movement_start();
s32 sprite_palette_load();
s32 func_001713B0();
s32 boss_phase_start();
s32 boss_attack_start();
s32 boss_attack_running();
s32 rng_next();
s32 rng_next_bit();
s32 boss_movement_current();
s32 boss_animation_start();
s32 boss_animation_running();
s32 boss_animation_stop();
s32 aim_at_player();
s32 direction_turn_toward();

extern u8 stage1_boss_palette[];
extern u8 stage1_boss_turret_shot_waits[];
extern u8 stage1_boss_turret_volleys[];
extern u8 stage1_boss_beam_waits[];
extern u8 stage1_boss_normal_rounds[];

void stage1_boss_mode_vulcan_end(void);
void stage1_boss_mode_side_attack_end(void);

void stage1_boss_mode_enter_start(void) {
    ENTER_MODE(reg_a4)->delay = 0xC0;
}

void stage1_boss_mode_enter() {
    ENTER_MODE(reg_a4)->delay -= 1;
    if ((s16) ENTER_MODE(reg_a4)->delay == 0) {
        reg_d0.w = 0;
        boss_movement_start();
        reg_d0.h[0] = 0x13;
        reg_a0 = stage1_boss_palette;
        sprite_palette_load();
        ENTER_MODE(reg_a4)->running = 0;
    }
}

void stage1_boss_mode_normal_start(void) {
    reg_d0.w = 5;
    boss_movement_start();
    NORMAL_MODE(reg_a4)->step = 0;
    NORMAL_MODE(reg_a4)->turrets.sh = 0x1000;
    func_001713B0();
    reg_d1.b[0] = *(stage1_boss_turret_volleys + reg_d0.b[0]);
    reg_d1.b[0] += STAGE1_EXTRA(reg_a6)->turrets_burst;
    if ((s32) reg_d1.b[0] >= 0x80) {
        reg_d1.b[0] = 0x80;
    }
    NORMAL_MODE(reg_a4)->turret_volleys = (u8) reg_d1.b[0];
    reg_d1.b[0] = *(stage1_boss_turret_shot_waits + reg_d0.b[0]);
    reg_d1.b[0] -= STAGE1_EXTRA(reg_a6)->turrets_interval;
    if ((s8) reg_d1.b[0] < 3) {
        reg_d1.b[0] = 3;
    }
    NORMAL_MODE(reg_a4)->turret_shot.b.zero = 0;
    NORMAL_MODE(reg_a4)->turret_shot.b.wait = (u8) reg_d1.b[0];
    STAGE1_EXTRA(reg_a6)->turrets_burst += 2;
    if ((s32) STAGE1_EXTRA(reg_a6)->turrets_burst >= 0x80) {
        STAGE1_EXTRA(reg_a6)->turrets_burst = 0x80U;
    }
    STAGE1_EXTRA(reg_a6)->turrets_interval -= 1;
    if ((s8) STAGE1_EXTRA(reg_a6)->turrets_interval < 3) {
        STAGE1_EXTRA(reg_a6)->turrets_interval = 3U;
    }
    NORMAL_MODE(reg_a4)->beams.sh = 0x6000;
    NORMAL_MODE(reg_a4)->side.sb = 1;
    NORMAL_MODE(reg_a4)->unused_0C = 4;
    func_001713B0();
    reg_d1.b[0] = *(stage1_boss_beam_waits + reg_d0.b[0]);
    NORMAL_MODE(reg_a4)->beams.t.reload = reg_d1.b[0];
    reg_a0 = (u8 *)(stage1_boss_beam_levels);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] += STAGE1_EXTRA(reg_a6)->beam_ways;
    if ((s16) reg_d1.h[0] > 4) {
        reg_d1.h[0] = 4;
    }
    NORMAL_MODE(reg_a4)->beam_level = (u16) reg_d1.h[0];
    STAGE1_EXTRA(reg_a6)->beam_ways += 1;
    if ((s16) STAGE1_EXTRA(reg_a6)->beam_ways > 4) {
        STAGE1_EXTRA(reg_a6)->beam_ways = 4U;
    }
    reg_a0 = (u8 *)(stage1_boss_beam_speeds);
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] += STAGE1_EXTRA(reg_a6)->beam_speed;
    if ((s16) reg_d1.h[0] > 0x20) {
        reg_d1.h[0] = 0x20;
    }
    NORMAL_MODE(reg_a4)->beam_speed = (u16) reg_d1.h[0];
    STAGE1_EXTRA(reg_a6)->beam_speed += 2;
    if ((s16) STAGE1_EXTRA(reg_a6)->beam_speed > 0x20) {
        STAGE1_EXTRA(reg_a6)->beam_speed = 0x20U;
    }
    NORMAL_MODE(reg_a4)->unused_12 = 0x2020;
}

void stage1_boss_mode_normal(void) {
    u16 temp_a0_3;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_4;

    if (NORMAL_MODE(reg_a4)->step == 0) {
        reg_d0.w = 1;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_tmp.b[0] = NORMAL_MODE(reg_a4)->turrets.t.count;
            NORMAL_MODE(reg_a4)->turrets.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                NORMAL_MODE(reg_a4)->turrets.t.count = (u8) NORMAL_MODE(reg_a4)->turrets.t.reload;
                NORMAL_MODE(reg_a4)->step = 1U;
                reg_d0.w = 1;
                boss_attack_start();
                TURRETS(reg_a0)->shot.h = (u16) NORMAL_MODE(reg_a4)->turret_shot.h;
                TURRETS(reg_a0)->volleys_left = (u8) NORMAL_MODE(reg_a4)->turret_volleys;
                TURRETS(reg_a0)->speed = (u16) STAGE1_EXTRA(reg_a6)->turrets_speed;
                STAGE1_EXTRA(reg_a6)->turrets_speed += 2;
                if ((s16) STAGE1_EXTRA(reg_a6)->turrets_speed > 0xC) {
                    STAGE1_EXTRA(reg_a6)->turrets_speed = 0xCU;
                }
            }
        }
    }
    temp_a0 = NORMAL_MODE(reg_a4)->step;
    if (temp_a0 == 1) {
        reg_d0.w = 3;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 4;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_d0.w = 1;
                boss_attack_running();
                if (cond_flag == 0) {
                    NORMAL_MODE(reg_a4)->step = 2U;
                    rng_next();
                    reg_d0.b[0] += 0x20;
                    NORMAL_MODE(reg_a4)->pause = (u8) reg_d0.b[0];
                } else {
                    reg_tmp.b[0] = NORMAL_MODE(reg_a4)->beams.t.count;
                    NORMAL_MODE(reg_a4)->beams.t.count -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        NORMAL_MODE(reg_a4)->beams.t.count = (u8) NORMAL_MODE(reg_a4)->beams.t.reload;
                        reg_d0.w = 3;
                        if (NORMAL_MODE(reg_a4)->side.sb < 0) {
                            reg_d0.w = 4;
                        }
                        boss_attack_start();
                        BEAM(reg_a0)->shots_left = 4;
                        BEAM(reg_a0)->kind = 0;
                        NORMAL_MODE(reg_a4)->side.b *= -1;
                        if (NORMAL_MODE(reg_a4)->side.sb >= 0) {
                            NORMAL_MODE(reg_a4)->beam_level += 1;
                            if ((s16) NORMAL_MODE(reg_a4)->beam_level > 4) {
                                NORMAL_MODE(reg_a4)->beam_level = 4U;
                            }
                        }
                    }
                }
            }
        }
    }
    temp_a0_2 = NORMAL_MODE(reg_a4)->step;
    if (temp_a0_2 == 2) {
        NORMAL_MODE(reg_a4)->pause -= 1;
        if ((s8) NORMAL_MODE(reg_a4)->pause == 0) {
            reg_d0.w = 3;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_d0.w = 4;
                boss_attack_running();
                if (cond_flag == 0) {
                    rng_next_bit();
                    reg_d7.h[0] = reg_d0.h[0];
                    reg_d0.w = 3;
                    reg_d7.h[0] += 1;
                    boss_attack_start();
                    BEAM(reg_a0)->shots_left = 8;
                    BEAM(reg_a0)->kind = (u8) reg_d7.b[0];
                    temp_a0_3 = NORMAL_MODE(reg_a4)->beam_speed;
                    BEAM(reg_a0)->speed = temp_a0_3;
                    reg_d0.w = 4;
                    boss_attack_start();
                    BEAM(reg_a0)->shots_left = 8;
                    BEAM(reg_a0)->kind = (u8) reg_d7.b[0];
                    BEAM(reg_a0)->speed = (u16) NORMAL_MODE(reg_a4)->beam_speed;
                    NORMAL_MODE(reg_a4)->step = 3U;
                }
            }
        }
    }
    temp_a0_4 = NORMAL_MODE(reg_a4)->step;
    if (temp_a0_4 == 3) {
        reg_d0.w = 1;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 3;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_d0.w = 4;
                boss_attack_running();
                if (cond_flag == 0) {
                    reg_a0 = (u8 *)stage1_boss_normal_rounds;
                    reg_a0 += STAGE1_EXTRA(reg_a6)->next_mode;
                    reg_d0.h[0] = *(u16 *)reg_a0;
                    if ((s16) reg_d0.h[0] < 0) {
                        reg_d7.w = 3;
                        rng_next_bit();
                        if (reg_d0.b[0] == 0) {
                            reg_d7.w = 2;
                        }
                    } else {
                        STAGE1_EXTRA(reg_a6)->next_mode += 2;
                    }
                    reg_d0.w = 3;
                    boss_phase_start();
                    NORMAL_MODE(reg_a4)->running = 0;
                }
            }
        }
    }
}

void stage1_boss_mode_vulcan_start(void) {
    reg_d0.b[0] = ENTITY(reg_a6)[1].misc.b.draw_layer;
    reg_d0.b[0] += ENTITY(reg_a6)[3].misc.b.draw_layer;
    if (reg_d0.b[0] == 2) {
        stage1_boss_mode_vulcan_end();
        return;
    }
    SIDES_MODE(reg_a4)->step = 0;
    SIDES_MODE(reg_a4)->guns_open = 0;
    SIDES_MODE(reg_a4)->unused_06 = 0x2020;
    SIDES_MODE(reg_a4)->delay = 0x10;
    reg_d0.w = 8;
    boss_movement_start();
}

void stage1_boss_mode_vulcan(void) {
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_a0_4;

    reg_d0.b[0] = ENTITY(reg_a6)[1].misc.b.draw_layer;
    reg_d0.b[0] += ENTITY(reg_a6)[3].misc.b.draw_layer;
    if (reg_d0.b[0] == 2) {
        stage1_boss_mode_vulcan_end();
        return;
    }
    if (SIDES_MODE(reg_a4)->step == 0) {
        boss_movement_current();
        if (reg_d0.h[0] == 4) {
            reg_d0.w = 8;
            boss_animation_start();
            reg_d0.w = 9;
            boss_animation_start();
            SIDES_MODE(reg_a4)->step = 1U;
        }
    }
    temp_a0 = SIDES_MODE(reg_a4)->step;
    if (temp_a0 == 1) {
        reg_d0.w = 9;
        boss_animation_running();
        if (cond_flag == 0) {
            reg_d0.w = 8;
            boss_animation_running();
            if (cond_flag == 0) {
                SIDES_MODE(reg_a4)->guns_open = 1;
                SIDES_MODE(reg_a4)->step = 2U;
            }
        }
    }
    temp_a0_2 = SIDES_MODE(reg_a4)->step;
    if (temp_a0_2 == 2) {
        SIDES_MODE(reg_a4)->delay -= 1;
        if ((s16) SIDES_MODE(reg_a4)->delay == 0) {
            reg_d0.w = 0xE;
            boss_animation_start();
            SIDES_MODE(reg_a4)->step = 3U;
        }
    }
    temp_a0_3 = SIDES_MODE(reg_a4)->step;
    if (temp_a0_3 == 3) {
        reg_d0.w = 0xE;
        boss_animation_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xC;
            boss_animation_start();
            reg_d0.w = 0xD;
            boss_animation_start();
            SIDES_MODE(reg_a4)->guns_open = 0;
            reg_d0.w = 5;
            boss_movement_start();
            SIDES_MODE(reg_a4)->step = 4U;
        }
    }
    temp_a0_4 = SIDES_MODE(reg_a4)->step;
    if (temp_a0_4 == 4) {
        reg_d0.w = 2;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xC;
            boss_animation_running();
            if (cond_flag == 0) {
                reg_d0.w = 0xD;
                boss_animation_running();
                if (cond_flag == 0) {
                    reg_d0.w = 0xF;
                    boss_animation_start();
                    stage1_boss_mode_vulcan_end();
                }
            }
        }
    }
}

void stage1_boss_mode_vulcan_end(void) {
    reg_d0.w = 1;
    boss_phase_start();
    SIDES_MODE(reg_a4)->running = 0;
}

void stage1_boss_mode_side_attack_start(void) {
    reg_d0.b[0] = ENTITY(reg_a6)[1].misc.b.draw_layer;
    reg_d0.b[0] += ENTITY(reg_a6)[3].misc.b.draw_layer;
    if (reg_d0.b[0] == 2) {
        stage1_boss_mode_side_attack_end();
        return;
    }
    SIDES_MODE(reg_a4)->step = 0;
    SIDES_MODE(reg_a4)->guns_open = 0;
    SIDES_MODE(reg_a4)->unused_06 = 0x2020;
    reg_d0.w = 3;
    boss_movement_start();
}

void stage1_boss_mode_side_attack(void) {
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_a0_4;

    reg_d0.b[0] = ENTITY(reg_a6)[1].misc.b.draw_layer;
    reg_d0.b[0] += ENTITY(reg_a6)[3].misc.b.draw_layer;
    if (reg_d0.b[0] == 2) {
        stage1_boss_mode_side_attack_end();
        return;
    }
    if (SIDES_MODE(reg_a4)->step == 0) {
        boss_movement_current();
        if (reg_d0.h[0] == 4) {
            reg_d0.w = 0x10;
            boss_animation_start();
            reg_d0.w = 0x11;
            boss_animation_start();
            SIDES_MODE(reg_a4)->step = 1U;
        }
    }
    temp_a0 = SIDES_MODE(reg_a4)->step;
    if (temp_a0 == 1) {
        reg_d0.w = 9;
        boss_animation_running();
        if (cond_flag == 0) {
            reg_d0.w = 8;
            boss_animation_running();
            if (cond_flag == 0) {
                SIDES_MODE(reg_a4)->guns_open = 1;
                SIDES_MODE(reg_a4)->step = 2U;
                SIDES_MODE(reg_a4)->delay = 0x40U;
            }
        }
    }
    temp_a0_2 = SIDES_MODE(reg_a4)->step;
    if (temp_a0_2 == 2) {
        SIDES_MODE(reg_a4)->delay -= 1;
        if ((s16) SIDES_MODE(reg_a4)->delay == 0) {
            reg_d0.w = 8;
            boss_attack_start();
            SIDES_MODE(reg_a4)->step = 3U;
            SIDES_MODE(reg_a4)->delay = 0x40U;
            reg_d0.w = 0x12;
            boss_animation_start();
            reg_d0.w = 0x13;
            boss_animation_start();
        }
    }
    temp_a0_3 = SIDES_MODE(reg_a4)->step;
    if (temp_a0_3 == 3) {
        SIDES_MODE(reg_a4)->delay -= 1;
        if ((s16) SIDES_MODE(reg_a4)->delay == 0) {
            reg_d7.w = 9;
            rng_next_bit();
            if (reg_d0.b[0] == 0) {
                reg_d7.w = 0xA;
            }
            reg_d0.h[0] = reg_d7.h[0];
            SIDES_MODE(reg_a4)->step = 4U;
            SIDES_MODE(reg_a4)->guns_open = 0;
            reg_d0.w = 5;
            boss_movement_start();
        }
    }
    temp_a0_4 = SIDES_MODE(reg_a4)->step;
    if (temp_a0_4 == 4) {
        reg_d0.w = 7;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 9;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_d0.w = 0xA;
                boss_attack_running();
                if (cond_flag == 0) {
                    stage1_boss_mode_side_attack_end();
                }
            }
        }
    }
}

void stage1_boss_mode_side_attack_end(void) {
    reg_d0.w = 6;
    boss_phase_start();
    SIDES_MODE(reg_a4)->running = 0;
}

void stage1_boss_mode_one_side_lost_start(void) {
    ONE_SIDE_MODE(reg_a4)->step = 0;
    ONE_SIDE_MODE(reg_a4)->delay = 0x80;
    ONE_SIDE_MODE(reg_a4)->front.sh = 0x40;
    ONE_SIDE_MODE(reg_a4)->front_volleys.sh = 0x404;
    ONE_SIDE_MODE(reg_a4)->spread.sh = 0x6060;
    ONE_SIDE_MODE(reg_a4)->spread_volleys.sh = 0x404;
}

void stage1_boss_mode_one_side_lost() {
    u8 temp_a0;
    u8 temp_a0_2;

    if (ONE_SIDE_MODE(reg_a4)->step == 0) {
        ONE_SIDE_MODE(reg_a4)->delay -= 1;
        if ((s16) ONE_SIDE_MODE(reg_a4)->delay == 0) {
            ONE_SIDE_MODE(reg_a4)->step = 1U;
        }
    }
    temp_a0 = ONE_SIDE_MODE(reg_a4)->step;
    if (temp_a0 == 1) {
        reg_d0.w = 0xB;
        boss_attack_running();
        if (cond_flag == 0) {
            if (ONE_SIDE_MODE(reg_a4)->front_volleys.t.count == 0) {
                ONE_SIDE_MODE(reg_a4)->front_volleys.t.count = (u8) ONE_SIDE_MODE(reg_a4)->front_volleys.t.reload;
                ONE_SIDE_MODE(reg_a4)->step = 2U;
            } else {
                reg_tmp.b[0] = ONE_SIDE_MODE(reg_a4)->front.t.count;
                ONE_SIDE_MODE(reg_a4)->front.t.count -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    ONE_SIDE_MODE(reg_a4)->front.t.count = (u8) ONE_SIDE_MODE(reg_a4)->front.t.reload;
                    reg_d0.w = 0xB;
                    boss_attack_start();
                    ONE_SIDE_MODE(reg_a4)->front_volleys.t.count -= 1;
                }
            }
        }
    }
    temp_a0_2 = ONE_SIDE_MODE(reg_a4)->step;
    if ((temp_a0_2 == 2) && (reg_d0.w = 0xC, boss_attack_running(), (cond_flag == 0))) {
        if (ONE_SIDE_MODE(reg_a4)->spread_volleys.t.count == 0) {
            ONE_SIDE_MODE(reg_a4)->spread_volleys.t.count = (u8) ONE_SIDE_MODE(reg_a4)->spread_volleys.t.reload;
            ONE_SIDE_MODE(reg_a4)->step = 1U;
            return;
        }
        reg_tmp.b[0] = ONE_SIDE_MODE(reg_a4)->spread.t.count;
        ONE_SIDE_MODE(reg_a4)->spread.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            ONE_SIDE_MODE(reg_a4)->spread.t.count = (u8) ONE_SIDE_MODE(reg_a4)->spread.t.reload;
            reg_d0.w = 0xC;
            boss_attack_start();
            ONE_SIDE_MODE(reg_a4)->spread_volleys.t.count -= 1;
        }
    }
}

void stage1_boss_mode_both_sides_lost_start(void) {
    BOTH_SIDES_MODE(reg_a4)->step = 0;
    BOTH_SIDES_MODE(reg_a4)->body.h = 0x40;
    BOTH_SIDES_MODE(reg_a4)->unused_06 = 0x404;
}

void stage1_boss_mode_both_sides_lost() {
    u8 temp_a0;

    if (BOTH_SIDES_MODE(reg_a4)->step == 0) {
        BOTH_SIDES_MODE(reg_a4)->step = 1U;
    }
    temp_a0 = BOTH_SIDES_MODE(reg_a4)->step;
    if (temp_a0 == 1) {
        reg_d0.w = 0;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_tmp.b[0] = BOTH_SIDES_MODE(reg_a4)->body.t.count;
            BOTH_SIDES_MODE(reg_a4)->body.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                BOTH_SIDES_MODE(reg_a4)->body.t.count = (u8) BOTH_SIDES_MODE(reg_a4)->body.t.reload;
                reg_d0.w = 0;
                boss_attack_start();
            }
        }
    }
}

void stage1_boss_mode_gatling_start(void) {
    GATLING_MODE(reg_a4)->step = 0;
    GATLING_MODE(reg_a4)->aim.sh = 0x202;
    GATLING_MODE(reg_a4)->volley_speed = 0xD;
    GATLING_MODE(reg_a4)->volley.sh = 0x7050;
    GATLING_MODE(reg_a4)->unused_14 = 0x2040;
    GATLING_MODE(reg_a4)->aiming = 1;
    GATLING_MODE(reg_a4)->volley_number = 1;
    func_001713B0();
    reg_a0 = (u8 *)(stage1_boss_gatling_levels);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    GATLING_MODE(reg_a4)->volley_shots = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_d1.h[0] += STAGE1_EXTRA(reg_a6)->gatling_count;
    if ((s16) reg_d1.h[0] > 0x5) {
        reg_d1.h[0] = 5;
    }
    GATLING_MODE(reg_a4)->volleys_left = (u16) reg_d1.h[0];
    STAGE1_EXTRA(reg_a6)->gatling_count += 1;
    if ((s16) STAGE1_EXTRA(reg_a6)->gatling_count > 0x5) {
        STAGE1_EXTRA(reg_a6)->gatling_count = 5U;
    }
    reg_d0.w = 6;
    boss_movement_start();
}

void stage1_boss_mode_gatling(void) {
    u8 temp_a0;
    u8 temp_a0_2;

    if (GATLING_MODE(reg_a4)->step == 0) {
        boss_movement_current();
        if (reg_d0.h[0] == 7) {
            reg_d0.w = 7;
            boss_animation_stop();
            reg_d0.w = 0x14;
            boss_animation_start();
            GATLING_MODE(reg_a4)->sweep_side = 1U;
            reg_d1.w = 0x25;
            rng_next_bit();
            if (reg_d0.b[0] != 0) {
                reg_d1.w = 0x1C;
                GATLING_MODE(reg_a4)->sweep_side *= 0xFFFF;
            }
            rng_next();
            reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
            reg_d1.b[0] += reg_d0.b[0];
            GATLING_MODE(reg_a4)->sweep_start = (u8) reg_d1.b[0];
            GATLING_MODE(reg_a4)->step = 2U;
        }
    }
    temp_a0 = GATLING_MODE(reg_a4)->step;
    if (temp_a0 == 2) {
        if (GATLING_MODE(reg_a4)->aiming != 0) {
            reg_tmp.b[0] = GATLING_MODE(reg_a4)->aim.t.count;
            GATLING_MODE(reg_a4)->aim.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                GATLING_MODE(reg_a4)->aim.t.count = (u8) GATLING_MODE(reg_a4)->aim.t.reload;
                reg_d0.h[0] = ENTITY(reg_a6)[5].y.h;
                reg_d1.h[0] = ENTITY(reg_a6)[5].x.h;
                aim_at_player();
                if (cond_flag == 0) {
                    if ((s8) reg_d1.b[0] > 0x27) {
                        reg_d1.w = 0x27;
                    }
                    if ((s8) reg_d1.b[0] < 0x19) {
                        reg_d1.w = 0x19;
                    }
                    reg_d0.w = 0;
                    reg_d1.h[0] = (u16) reg_d1.b[0];
                    reg_d0.h[0] = ENTITY(reg_a6)[5].sprite.h;
                    reg_d0.h[0] += 0x20;
                    direction_turn_toward();
                    reg_d0.h[0] = reg_d1.h[0];
                    reg_d0.h[0] = (u16) reg_d0.b[0];
                    reg_d0.h[0] -= 0x20;
                    ENTITY(reg_a6)[5].sprite.h = (u16) reg_d0.h[0];
                }
            }
        }
        reg_d0.w = 0xD;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_tmp.b[0] = GATLING_MODE(reg_a4)->volley.t.count;
            GATLING_MODE(reg_a4)->volley.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                GATLING_MODE(reg_a4)->volley.t.reload -= 8;
                GATLING_MODE(reg_a4)->volley.t.count = (u8) GATLING_MODE(reg_a4)->volley.t.reload;
                reg_d0.w = 0xD;
                boss_attack_start();
                GATLING_C(reg_a0)->speed = (u8) GATLING_MODE(reg_a4)->volley_speed;
                GATLING_C(reg_a0)->volley_number = (u8) GATLING_MODE(reg_a4)->volley_number;
                GATLING_C(reg_a0)->shots_left = (u16) GATLING_MODE(reg_a4)->volley_shots;
                GATLING_MODE(reg_a4)->volley_speed += 4;
                GATLING_MODE(reg_a4)->volley_number += 1;
                GATLING_MODE(reg_a4)->volley_shots += 2;
                GATLING_MODE(reg_a4)->aiming = 1U;
                GATLING_MODE(reg_a4)->sweep_side *= 0xFFFF;
                GATLING_MODE(reg_a4)->volleys_left -= 1;
                if ((s16) GATLING_MODE(reg_a4)->volleys_left == 0) {
                    GATLING_MODE(reg_a4)->end_delay = 0x50U;
                    GATLING_MODE(reg_a4)->step = 3U;
                }
            }
        }
    }
    temp_a0_2 = GATLING_MODE(reg_a4)->step;
    if (temp_a0_2 == 3) {
        reg_d0.w = 0xD;
        boss_attack_running();
        if (cond_flag == 0) {
            GATLING_MODE(reg_a4)->end_delay -= 1;
            if ((s16) GATLING_MODE(reg_a4)->end_delay == 0) {
                reg_d0.w = 0xF;
                boss_animation_start();
                reg_d0.w = 0x14;
                boss_animation_stop();
                reg_d0.w = 7;
                boss_animation_start();
                reg_d0.w = 2;
                boss_phase_start();
                GATLING_MODE(reg_a4)->running = 0;
            }
        }
    }
}

u8 stage1_boss_turret_shot_waits[8] = {
    0x0A, 0x08, 0x06, 0x04, 0x04, 0x03, 0x03, 0x03,
};

u8 stage1_boss_turret_volleys[8] = {
    0x20, 0x20, 0x20, 0x28, 0x30, 0x38, 0x3C, 0x40,
};

u8 stage1_boss_beam_waits[8] = {
    0x48, 0x40, 0x38, 0x30, 0x2C, 0x28, 0x24, 0x20,
};

u8 stage1_boss_normal_rounds[8] = {
    0x03, 0x00, 0x02, 0x00, 0xFF, 0xFF, 0x00, 0x00,
};
