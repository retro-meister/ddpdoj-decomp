#include "common.h"
#include "entity.h"

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
};

u16 stage1_boss_side_gun_levels[] = {
    0xFFFC, 0xFFFD, 0xFFFE, 0xFFFF, 0x0000, 0x0001, 0x0002, 0x0003,
};

u16 stage1_boss_side_arg10_levels[] = {
    0xFFFC, 0xFFFC, 0xFFFC, 0xFFFC, 0xFFFE, 0x0000, 0x0002, 0x0004,
};

u16 stage1_boss_gatling_levels[] = {
    0x0003, 0x0001, 0x0003, 0x0001, 0x0004, 0x0002, 0x0005, 0x0003,
    0x0006, 0x0003, 0x0008, 0x0004, 0x0008, 0x0004, 0x0009, 0x0005,
};

/* Two bytes of a boss slot that are set together as one word: a reload value and its countdown. */
typedef union {
    u16 h;
    s16 sh;
    struct { u8 reload; u8 count; } t;
} SlotTimer;

/*
 * The mode part of the boss slot (reg_a4), one record per mode. `running` is cleared when the mode hands over.
 * Fields named *_argN are copied to offset N of the slot of the attack they start.
 */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 delay;
} EnterMode;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;
    /* 0x04 */ SlotTimer gatling;      /* wait between two gatling attacks */
    /* 0x06 */ union {
        u16 h;
        struct { u8 rate; u8 zero; } b;
    } gatling_arg2;
    /* 0x08 */ u8 unused_08;
    /* 0x09 */ u8 gatling_arg5;
    /* 0x0A */ SlotTimer side_guns;    /* wait between two side gun attacks */
    /* 0x0C */ u8 unused_0C;
    /* 0x0D */ union { u8 b; s8 sb; } side; /* 1: the right side fires next, -1: the left */
    /* 0x0E */ u16 side_gun_level;
    /* 0x10 */ u16 side_arg10;
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
    /* 0x09 */ u8 volley_arg5;
    /* 0x0A */ SlotTimer volley;         /* wait between two volleys; gets shorter */
    /* 0x0C */ u16 volleys_left;
    /* 0x0E */ u16 volley_arg6;
    /* 0x10 */ u8 volley_arg4;
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
extern u8 stage1_boss_gatling_rates[];
extern u8 stage1_boss_gatling_arg5_levels[];
extern u8 stage1_boss_side_gun_waits[];
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
    NORMAL_MODE(reg_a4)->gatling.sh = 0x1000;
    func_001713B0();
    reg_d1.b[0] = *(stage1_boss_gatling_arg5_levels + reg_d0.b[0]);
    reg_d1.b[0] += ENTITY(reg_a6)[8].sprite.b[1];
    if ((s32) reg_d1.b[0] >= 0x80) {
        reg_d1.b[0] = 0x80;
    }
    NORMAL_MODE(reg_a4)->gatling_arg5 = (u8) reg_d1.b[0];
    reg_d1.b[0] = *(stage1_boss_gatling_rates + reg_d0.b[0]);
    reg_d1.b[0] -= ENTITY(reg_a6)[8].draw.b.flip;
    if ((s8) reg_d1.b[0] < 3) {
        reg_d1.b[0] = 3;
    }
    NORMAL_MODE(reg_a4)->gatling_arg2.b.zero = 0;
    NORMAL_MODE(reg_a4)->gatling_arg2.b.rate = (u8) reg_d1.b[0];
    ENTITY(reg_a6)[8].sprite.b[1] += 2;
    if ((s32) ENTITY(reg_a6)[8].sprite.b[1] >= 0x80) {
        ENTITY(reg_a6)[8].sprite.b[1] = 0x80U;
    }
    ENTITY(reg_a6)[8].draw.b.flip -= 1;
    if ((s8) ENTITY(reg_a6)[8].draw.b.flip < 3) {
        ENTITY(reg_a6)[8].draw.b.flip = 3U;
    }
    NORMAL_MODE(reg_a4)->side_guns.sh = 0x6000;
    NORMAL_MODE(reg_a4)->side.sb = 1;
    NORMAL_MODE(reg_a4)->unused_0C = 4;
    func_001713B0();
    reg_d1.b[0] = *(stage1_boss_side_gun_waits + reg_d0.b[0]);
    NORMAL_MODE(reg_a4)->side_guns.t.reload = reg_d1.b[0];
    reg_a0 = (u8 *)(stage1_boss_side_gun_levels);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] += ENTITY(reg_a6)[8].look.h;
    if ((s16) reg_d1.h[0] > 4) {
        reg_d1.h[0] = 4;
    }
    NORMAL_MODE(reg_a4)->side_gun_level = (u16) reg_d1.h[0];
    ENTITY(reg_a6)[8].look.h += 1;
    if ((s16) ENTITY(reg_a6)[8].look.h > 4) {
        ENTITY(reg_a6)[8].look.h = 4U;
    }
    reg_a0 = (u8 *)(stage1_boss_side_arg10_levels);
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] += ENTITY(reg_a6)[8].hit_y_plus.h;
    if ((s16) reg_d1.h[0] > 0x20) {
        reg_d1.h[0] = 0x20;
    }
    NORMAL_MODE(reg_a4)->side_arg10 = (u16) reg_d1.h[0];
    ENTITY(reg_a6)[8].hit_y_plus.h += 2;
    if ((s16) ENTITY(reg_a6)[8].hit_y_plus.h > 0x20) {
        ENTITY(reg_a6)[8].hit_y_plus.h = 0x20U;
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
            reg_tmp.b[0] = NORMAL_MODE(reg_a4)->gatling.t.count;
            NORMAL_MODE(reg_a4)->gatling.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                NORMAL_MODE(reg_a4)->gatling.t.count = (u8) NORMAL_MODE(reg_a4)->gatling.t.reload;
                NORMAL_MODE(reg_a4)->step = 1U;
                reg_d0.w = 1;
                boss_attack_start();
                *(u16 *)(reg_a0 + 2) = (u16) NORMAL_MODE(reg_a4)->gatling_arg2.h;
                *(u8 *)(reg_a0 + 5) = (u8) NORMAL_MODE(reg_a4)->gatling_arg5;
                *(u16 *)(reg_a0 + 0xC) = (u16) ENTITY(reg_a6)[8].offset_x.h;
                ENTITY(reg_a6)[8].offset_x.h += 2;
                if ((s16) ENTITY(reg_a6)[8].offset_x.h > 0xC) {
                    ENTITY(reg_a6)[8].offset_x.h = 0xCU;
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
                    reg_tmp.b[0] = NORMAL_MODE(reg_a4)->side_guns.t.count;
                    NORMAL_MODE(reg_a4)->side_guns.t.count -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        NORMAL_MODE(reg_a4)->side_guns.t.count = (u8) NORMAL_MODE(reg_a4)->side_guns.t.reload;
                        reg_d0.w = 3;
                        if (NORMAL_MODE(reg_a4)->side.sb < 0) {
                            reg_d0.w = 4;
                        }
                        boss_attack_start();
                        *(s8 *)(reg_a0 + 3) = 4;
                        *(u8 *)(reg_a0 + 2) = 0;
                        NORMAL_MODE(reg_a4)->side.b *= -1;
                        if (NORMAL_MODE(reg_a4)->side.sb >= 0) {
                            NORMAL_MODE(reg_a4)->side_gun_level += 1;
                            if ((s16) NORMAL_MODE(reg_a4)->side_gun_level > 4) {
                                NORMAL_MODE(reg_a4)->side_gun_level = 4U;
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
                    *(s8 *)(reg_a0 + 3) = 8;
                    *(u8 *)(reg_a0 + 2) = (u8) reg_d7.b[0];
                    temp_a0_3 = NORMAL_MODE(reg_a4)->side_arg10;
                    *(u16 *)(reg_a0 + 0x10) = temp_a0_3;
                    reg_d0.w = 4;
                    boss_attack_start();
                    *(s8 *)(reg_a0 + 3) = 8;
                    *(u8 *)(reg_a0 + 2) = (u8) reg_d7.b[0];
                    *(u16 *)(reg_a0 + 0x10) = (u16) NORMAL_MODE(reg_a4)->side_arg10;
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
                    reg_a0 += ENTITY(reg_a6)[8].offset_y.h;
                    reg_d0.h[0] = *(u16 *)reg_a0;
                    if ((s16) reg_d0.h[0] < 0) {
                        reg_d7.w = 3;
                        rng_next_bit();
                        if (reg_d0.b[0] == 0) {
                            reg_d7.w = 2;
                        }
                    } else {
                        ENTITY(reg_a6)[8].offset_y.h += 2;
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
    GATLING_MODE(reg_a4)->volley_arg5 = 0xD;
    GATLING_MODE(reg_a4)->volley.sh = 0x7050;
    GATLING_MODE(reg_a4)->unused_14 = 0x2040;
    GATLING_MODE(reg_a4)->aiming = 1;
    GATLING_MODE(reg_a4)->volley_arg4 = 1;
    func_001713B0();
    reg_a0 = (u8 *)(stage1_boss_gatling_levels);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    GATLING_MODE(reg_a4)->volley_arg6 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_d1.h[0] += ENTITY(reg_a6)[8].hp.h;
    if ((s16) reg_d1.h[0] > 0x5) {
        reg_d1.h[0] = 5;
    }
    GATLING_MODE(reg_a4)->volleys_left = (u16) reg_d1.h[0];
    ENTITY(reg_a6)[8].hp.h += 1;
    if ((s16) ENTITY(reg_a6)[8].hp.h > 0x5) {
        ENTITY(reg_a6)[8].hp.h = 5U;
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
                *(u8 *)(reg_a0 + 5) = (u8) GATLING_MODE(reg_a4)->volley_arg5;
                *(u8 *)(reg_a0 + 4) = (u8) GATLING_MODE(reg_a4)->volley_arg4;
                *(u16 *)(reg_a0 + 6) = (u16) GATLING_MODE(reg_a4)->volley_arg6;
                GATLING_MODE(reg_a4)->volley_arg5 += 4;
                GATLING_MODE(reg_a4)->volley_arg4 += 1;
                GATLING_MODE(reg_a4)->volley_arg6 += 2;
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
