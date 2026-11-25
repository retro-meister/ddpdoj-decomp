#include "common.h"
#include "entity.h"

void stage1_boss_fire_body_ports_rage_start(void);
void stage1_boss_fire_body_ports_rage(void);
void stage1_boss_fire_turrets_scatter_start(void);
void stage1_boss_fire_turrets_scatter(void);
void stage1_boss_fire_gatling_a_start(void);
void stage1_boss_fire_gatling_a(void);
void stage1_boss_fire_right_beam_start(void);
void stage1_boss_fire_left_beam_start(void);
void stage1_boss_fire_right_main_gun_start(void);
void stage1_boss_fire_left_main_gun_start(void);
void stage1_boss_fire_gatling_b_start(void);
void stage1_boss_fire_gatling_b(void);
void stage1_boss_fire_main_guns_burst_start(void);
void stage1_boss_fire_body_ports_rapid_start(void);
void stage1_boss_fire_body_ports_aimed_start(void);
void stage1_boss_fire_front_guns_rage_start(void);
void stage1_boss_fire_front_guns_rage_spread_start(void);
void stage1_boss_fire_gatling_c_start(void);
void stage1_boss_fire_gatling_c(void);
void stage1_boss_fire_side_spread_start(void);

void stage1_boss_fire_right_beam(void);
void stage1_boss_fire_left_beam(void);
void stage1_boss_fire_right_main_gun(void);
void stage1_boss_fire_left_main_gun(void);
void stage1_boss_fire_main_guns_burst(void);
void stage1_boss_fire_body_ports_rapid(void);
void stage1_boss_fire_body_ports_aimed(void);
void stage1_boss_fire_front_guns_rage(void);
void stage1_boss_fire_front_guns_rage_spread(void);
void stage1_boss_fire_side_spread(void);
/* Two bytes of a boss slot that are set together as one word: a reload value and its countdown. */
typedef union {
    u16 h;
    s16 sh;
    struct { u8 reload; u8 count; } t;
} SlotTimer;

/*
 * The attack part of the boss slot (reg_a4), one record per attack. `running` is cleared when the attack is over.
 * The mode that starts an attack fills in some of its fields. Directions are in 1/256 of a turn where the
 * bullets are fired with the 256-step routines, otherwise in 1/64.
 */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ u16 speed;
    /* 0x06 */ u16 shots_left;
    /* 0x08 */ u16 spread;        /* angle between the pairs; grows by spread_step with every shot */
    /* 0x0A */ u8 unused_0A;
    /* 0x0B */ u8 direction;
    /* 0x0C */ u16 spread_step;
} BodyPortsRage;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ u8 swing;          /* one bit per turret: swinging back */
    /* 0x05 */ u8 volleys_left;
    /* 0x06 */ u8 unused_06;
    /* 0x07 */ u8 aimed;          /* every turret has reached its start angle */
    /* 0x08 */ u8 start_angle[4];
    /* 0x0C */ u16 speed;
} TurretsScatter;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer aim_wait;
    /* 0x04 */ u8 target_angle;
    /* 0x05 */ u8 step;
    /* 0x06 */ SlotTimer turn;
    /* 0x08 */ SlotTimer shot;
    /* 0x0A */ u16 shots_left;
    /* 0x0C */ u16 speed;
} GatlingA;

/* The beams of the right and the left side. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 kind;           /* 0: one aimed line, otherwise a fan */
    /* 0x03 */ u8 shots_left;
    /* 0x04 */ SlotTimer shot;
    /* 0x06 */ Field16 spare;
    /* 0x08 */ u16 y;             /* where the bullets start */
    /* 0x0A */ u16 x;
    /* 0x0C */ u8 unused_0C;
    /* 0x0D */ u8 direction;
    /* 0x0E */ u16 unused_0E;
    /* 0x10 */ u16 speed;
} SideBeam;

/* The main guns of the right and the left side. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 interval;       /* frames between two shots; gets shorter */
    /* 0x03 */ u8 wait;
    /* 0x04 */ s16 unused_04;
    /* 0x06 */ s16 unused_06;
    /* 0x08 */ u8 unused_08[3];
    /* 0x0B */ u8 direction;      /* turns with every shot */
    /* 0x0C */ u8 unused_0C[2];
    /* 0x0E */ SlotTimer speedup; /* shots between two steps of the interval */
    /* 0x10 */ SlotTimer spare;
    /* 0x12 */ u8 unused_12;
    /* 0x13 */ u8 unused_13;
    /* 0x14 */ u16 speed;
} SideMainGun;

#define RAGE(pointer) ((BodyPortsRage *)(pointer))
#define TURRETS(pointer) ((TurretsScatter *)(pointer))
#define GATLING_A(pointer) ((GatlingA *)(pointer))
#define BEAM(pointer) ((SideBeam *)(pointer))
#define MAIN_GUN(pointer) ((SideMainGun *)(pointer))

/* The set-up routine and the per-frame routine of every attack, by attack number. */
void (*stage1_boss_fire_routines[])(void) = {
    stage1_boss_fire_body_ports_rage_start,
    stage1_boss_fire_body_ports_rage,
    stage1_boss_fire_turrets_scatter_start,
    stage1_boss_fire_turrets_scatter,
    stage1_boss_fire_gatling_a_start,
    stage1_boss_fire_gatling_a,
    stage1_boss_fire_right_beam_start,
    stage1_boss_fire_right_beam,
    stage1_boss_fire_left_beam_start,
    stage1_boss_fire_left_beam,
    stage1_boss_fire_right_main_gun_start,
    stage1_boss_fire_right_main_gun,
    stage1_boss_fire_left_main_gun_start,
    stage1_boss_fire_left_main_gun,
    stage1_boss_fire_gatling_b_start,
    stage1_boss_fire_gatling_b,
    stage1_boss_fire_main_guns_burst_start,
    stage1_boss_fire_main_guns_burst,
    stage1_boss_fire_body_ports_rapid_start,
    stage1_boss_fire_body_ports_rapid,
    stage1_boss_fire_body_ports_aimed_start,
    stage1_boss_fire_body_ports_aimed,
    stage1_boss_fire_front_guns_rage_start,
    stage1_boss_fire_front_guns_rage,
    stage1_boss_fire_front_guns_rage_spread_start,
    stage1_boss_fire_front_guns_rage_spread,
    stage1_boss_fire_gatling_c_start,
    stage1_boss_fire_gatling_c,
    stage1_boss_fire_side_spread_start,
    stage1_boss_fire_side_spread,
    0,
    0,
};

void stage1_boss_fire_turrets_sweep(void);
void stage1_boss_fire_right_beam(void);
void stage1_boss_fire_left_beam(void);
void stage1_boss_fire_right_main_gun(void);
void stage1_boss_fire_left_main_gun(void);
void stage1_boss_fire_main_guns_burst(void);
void stage1_boss_fire_body_ports_rapid(void);
void stage1_boss_fire_body_ports_aimed(void);
void stage1_boss_fire_front_guns_rage(void);
void stage1_boss_fire_front_guns_rage_spread(void);
void stage1_boss_fire_side_spread();

extern u16 *reg_a4_as_u16_p;

void stage1_boss_fire_clear(void) {
    *reg_a4_as_u16_p = 0;
}


s32 func_001713B0();
s32 enemy_switch_target_player();
s32 rng_next();
s32 func_00202730();
extern u16 D_0026E070[];
extern u16 D_0026E080[];

void stage1_boss_fire_body_ports_rage_start(void) {
    enemy_switch_target_player();
    RAGE(reg_a4)->shot.sh = 0x1001;
    RAGE(reg_a4)->speed = 0;
    RAGE(reg_a4)->spread = 8;
    RAGE(reg_a4)->direction = 0x80U;
    func_00202730();
    if (cond_flag == 0) {
        rng_next();
        reg_d1.b[0] += reg_d0.b[0];
        RAGE(reg_a4)->direction = (u8) reg_d1.b[0];
    }
    func_001713B0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)(D_0026E070);
    RAGE(reg_a4)->spread_step = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(D_0026E080);
    RAGE(reg_a4)->shots_left = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
}

s32 bullet_fire256_2way();
extern u16 D_0026E090[];
extern u16 D_0026E092[];
extern u16 D_0026E094[];
extern u16 D_0026E096[];
extern u16 D_0026E098[];
extern u16 D_0026E09A[];
extern u16 D_0026E09C[];
extern u16 D_0026E09E[];

void stage1_boss_fire_body_ports_rage(void) {
    u16 temp_a1;
    u16 temp_a2;

    reg_tmp.b[0] = RAGE(reg_a4)->shot.t.count;
    RAGE(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        RAGE(reg_a4)->shot.t.count = (u8) RAGE(reg_a4)->shot.t.reload;
        reg_d1.w = 0;
        reg_d1.b[0] = RAGE(reg_a4)->direction;
        reg_d0.h[0] = RAGE(reg_a4)->speed;
        temp_a2 = reg_d0.h[0];
        reg_tmp.w = reg_d0.w;
        reg_d0.h[1] = temp_a2;
        reg_d0.h[0] = 3;
        temp_a1 = RAGE(reg_a4)->spread;
        reg_d6.h[0] = temp_a1;
        reg_d3.h[1] = D_0026E098[0];
        reg_d3.h[0] = D_0026E09A[0];
        reg_d4.w = 0;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] += 2;
        bullet_fire256_2way();
        reg_d3.h[1] = D_0026E09C[0];
        reg_d3.h[0] = D_0026E09E[0];
        reg_d1.h[0] -= 4;
        bullet_fire256_2way();
        reg_d1.h[0] += 2;
        reg_d1.b[0] += reg_d6.b[0];
        reg_d3.h[1] = D_0026E090[0];
        reg_d3.h[0] = D_0026E092[0];
        bullet_fire256_2way();
        reg_d1.b[0] -= reg_d6.b[0];
        reg_d3.h[1] = D_0026E094[0];
        reg_d3.h[0] = D_0026E096[0];
        reg_d1.b[0] -= reg_d6.b[0];
        bullet_fire256_2way();
        RAGE(reg_a4)->speed += 4;
        reg_d0.h[0] = RAGE(reg_a4)->spread_step;
        RAGE(reg_a4)->spread += reg_d0.h[0];
        RAGE(reg_a4)->shots_left -= 1;
        if ((s16) RAGE(reg_a4)->shots_left == 0) {
            RAGE(reg_a4)->running = 0;
        }
    }
}

void bullet_fire_3way(void);

void bullet_fire_3way_entry(void) {
    bullet_fire_3way();
}

extern u16 D_0026E0B0[];

void stage1_boss_fire_turrets_scatter_start(void) {
    u32 temp_a0;
    TURRETS(reg_a4)->swing = 0;
    TURRETS(reg_a4)->aimed = 0;
    func_001713B0();
    reg_a0 = (u8 *)(D_0026E0B0);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    temp_a0 = TURRETS(reg_a4)->speed;
    TURRETS(reg_a4)->speed = (u16) (temp_a0 + reg_d0.h[0]);
    TURRETS(reg_a4)->start_angle[1] = 0x20U;
    TURRETS(reg_a4)->start_angle[0] = 0x20U;
    TURRETS(reg_a4)->start_angle[3] = 0x20U;
    TURRETS(reg_a4)->start_angle[2] = 0x20U;
    rng_next();
    TURRETS(reg_a4)->start_angle[1] += reg_d0.b[0];
    rng_next();
    TURRETS(reg_a4)->start_angle[0] += reg_d0.b[0];
    rng_next();
    TURRETS(reg_a4)->start_angle[3] += reg_d0.b[0];
    rng_next();
    TURRETS(reg_a4)->start_angle[2] += reg_d0.b[0];
}

s32 direction_turn_toward();                            /* extern */

void stage1_boss_fire_turrets_scatter(void) {
    if (TURRETS(reg_a4)->aimed != 0) {
        stage1_boss_fire_turrets_sweep();
        return;
    }
    reg_d1.b[0] = TURRETS(reg_a4)->start_angle[1];
    reg_d0.b[0] = ENTITY(reg_a6)[6].offset_y.b[1];
    direction_turn_toward();
    ENTITY(reg_a6)[6].offset_y.b[1] = (u8) reg_d1.b[0];
    reg_d1.b[0] = TURRETS(reg_a4)->start_angle[0];
    reg_d0.b[0] = ENTITY(reg_a6)[6].offset_y.b[0];
    direction_turn_toward();
    ENTITY(reg_a6)[6].offset_y.b[0] = (u8) reg_d1.b[0];
    reg_d1.b[0] = TURRETS(reg_a4)->start_angle[3];
    reg_d0.b[0] = ENTITY(reg_a6)[6].offset_x.b[1];
    direction_turn_toward();
    ENTITY(reg_a6)[6].offset_x.b[1] = (u8) reg_d1.b[0];
    reg_d1.b[0] = TURRETS(reg_a4)->start_angle[2];
    reg_d0.b[0] = ENTITY(reg_a6)[6].offset_x.b[0];
    direction_turn_toward();
    ENTITY(reg_a6)[6].offset_x.b[0] = (u8) reg_d1.b[0];
    reg_d0.b[0] = TURRETS(reg_a4)->start_angle[1];
    if (ENTITY(reg_a6)[6].offset_y.b[1] == reg_d0.b[0]) {
        reg_d0.b[0] = TURRETS(reg_a4)->start_angle[0];
        if (ENTITY(reg_a6)[6].offset_y.b[0] == reg_d0.b[0]) {
            reg_d0.b[0] = TURRETS(reg_a4)->start_angle[3];
            if (ENTITY(reg_a6)[6].offset_x.b[1] == reg_d0.b[0]) {
                reg_d0.b[0] = TURRETS(reg_a4)->start_angle[2];
                if (ENTITY(reg_a6)[6].offset_x.b[0] == reg_d0.b[0]) {
                    TURRETS(reg_a4)->aimed = 1U;
                }
            }
        }
    }
}

extern u16 D_0026E0A0[];
extern u16 D_0026E0A2[];
extern u16 D_0026E0A4[];
extern u16 D_0026E0A6[];
extern u16 D_0026E0A8[];
extern u16 D_0026E0AA[];
extern u16 D_0026E0AC[];
extern u16 D_0026E0AE[];
extern u16 g_bullets_blocked;

void stage1_boss_fire_turrets_sweep(void) {
    u16 temp_a0;
    u16 temp_a1;

    if (g_bullets_blocked == 0) {
        if (!(TURRETS(reg_a4)->swing & 1)) {
            ENTITY(reg_a6)[6].offset_y.b[1] += 1;
            if ((s8) ENTITY(reg_a6)[6].offset_y.b[1] >= 0x30) {
                TURRETS(reg_a4)->swing |= 1;
            }
        } else {
            ENTITY(reg_a6)[6].offset_y.b[1] -= 1;
            if ((s8) ENTITY(reg_a6)[6].offset_y.b[1] < 0x11) {
                TURRETS(reg_a4)->swing &= 0xE;
            }
        }
        if (!(TURRETS(reg_a4)->swing & 2)) {
            ENTITY(reg_a6)[6].offset_y.b[0] += 1;
            if ((s8) ENTITY(reg_a6)[6].offset_y.b[0] >= 0x30) {
                TURRETS(reg_a4)->swing |= 2;
            }
        } else {
            ENTITY(reg_a6)[6].offset_y.b[0] -= 1;
            if ((s8) ENTITY(reg_a6)[6].offset_y.b[0] < 0x11) {
                TURRETS(reg_a4)->swing &= 0xD;
            }
        }
        if (!(TURRETS(reg_a4)->swing & 4)) {
            ENTITY(reg_a6)[6].offset_x.b[1] += 1;
            if ((s8) ENTITY(reg_a6)[6].offset_x.b[1] >= 0x30) {
                TURRETS(reg_a4)->swing |= 4;
            }
        } else {
            ENTITY(reg_a6)[6].offset_x.b[1] -= 1;
            if ((s8) ENTITY(reg_a6)[6].offset_x.b[1] < 0x11) {
                TURRETS(reg_a4)->swing &= 0xB;
            }
        }
        if (!(TURRETS(reg_a4)->swing & 8)) {
            ENTITY(reg_a6)[6].offset_x.b[0] += 1;
            if ((s8) ENTITY(reg_a6)[6].offset_x.b[0] >= 0x30) {
                TURRETS(reg_a4)->swing |= 8;
            }
        } else {
            ENTITY(reg_a6)[6].offset_x.b[0] -= 1;
            if ((s8) ENTITY(reg_a6)[6].offset_x.b[0] < 0x11) {
                TURRETS(reg_a4)->swing &= 7;
            }
        }
        reg_tmp.b[0] = TURRETS(reg_a4)->shot.t.count;
        TURRETS(reg_a4)->shot.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            TURRETS(reg_a4)->shot.t.count = (u8) TURRETS(reg_a4)->shot.t.reload;
            reg_d0.h[0] = TURRETS(reg_a4)->speed;
            temp_a1 = reg_d0.h[0];
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = temp_a1;
            reg_d0.h[0] = 0xC;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            temp_a0 = ENTITY(reg_a6)->x.h;
            reg_d2.h[0] = temp_a0;
            reg_d3.h[1] = D_0026E0A0[0];
            reg_d3.h[0] = D_0026E0A2[0];
            reg_d1.w = 0;
            reg_d1.b[0] = ENTITY(reg_a6)[6].offset_y.b[1];
            bullet_fire_3way_entry();
            reg_d3.h[1] = D_0026E0A4[0];
            reg_d3.h[0] = D_0026E0A6[0];
            reg_d1.b[0] = ENTITY(reg_a6)[6].offset_y.b[0];
            bullet_fire_3way_entry();
            reg_d3.h[1] = D_0026E0A8[0];
            reg_d3.h[0] = D_0026E0AA[0];
            reg_d1.b[0] = ENTITY(reg_a6)[6].offset_x.b[1];
            bullet_fire_3way_entry();
            reg_d3.h[1] = D_0026E0AC[0];
            reg_d3.h[0] = D_0026E0AE[0];
            reg_d1.b[0] = ENTITY(reg_a6)[6].offset_x.b[0];
            bullet_fire_3way_entry();
            TURRETS(reg_a4)->volleys_left -= 1;
            if ((s8) TURRETS(reg_a4)->volleys_left == 0) {
                TURRETS(reg_a4)->running = 0;
            }
        }
    }
}

void stage1_boss_fire_gatling_a_start(void) {
    GATLING_A(reg_a4)->aim_wait.h = 0;
    GATLING_A(reg_a4)->step = 0;
    GATLING_A(reg_a4)->target_angle = 0x20;
    GATLING_A(reg_a4)->turn.h = 0x101;
    GATLING_A(reg_a4)->shot.h = 4;
    GATLING_A(reg_a4)->shots_left = 0x10;
    GATLING_A(reg_a4)->speed = 0xFFFC;
}

s32 bullet_fire256_fixed();
s32 func_00201200();
s32 aim_at_player();
s32 direction_turn_toward();
extern u16 D_0026E0C0[];

void stage1_boss_fire_gatling_a(void) {
    u16 temp_a0_2;
    u8 temp_a0;

    if (GATLING_A(reg_a4)->step == 0) {
        reg_tmp.b[0] = GATLING_A(reg_a4)->aim_wait.t.count;
        GATLING_A(reg_a4)->aim_wait.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            GATLING_A(reg_a4)->aim_wait.t.count = (u8) GATLING_A(reg_a4)->aim_wait.t.reload;
            GATLING_A(reg_a4)->step = 1U;
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
                GATLING_A(reg_a4)->target_angle = (u8) reg_d1.b[0];
            }
        }
    }
    temp_a0 = GATLING_A(reg_a4)->step;
    if (temp_a0 == 1) {
        reg_tmp.b[0] = GATLING_A(reg_a4)->turn.t.count;
        GATLING_A(reg_a4)->turn.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            GATLING_A(reg_a4)->turn.t.count = (u8) GATLING_A(reg_a4)->turn.t.reload;
            reg_d0.w = 0;
            reg_d1.w = 0;
            reg_d1.b[0] = GATLING_A(reg_a4)->target_angle;
            reg_d0.h[0] = ENTITY(reg_a6)[5].sprite.h;
            reg_d0.h[0] += 0x20;
            direction_turn_toward();
            reg_d0.h[0] = reg_d1.h[0];
            reg_d0.h[0] = (u16) reg_d0.b[0];
            reg_d0.h[0] -= 0x20;
            ENTITY(reg_a6)[5].sprite.h = (u16) reg_d0.h[0];
            if (GATLING_A(reg_a4)->target_angle == reg_d1.b[0]) {
                GATLING_A(reg_a4)->step = 2U;
            }
        }
    }
    if (GATLING_A(reg_a4)->step == 2) {
        reg_tmp.b[0] = GATLING_A(reg_a4)->shot.t.count;
        GATLING_A(reg_a4)->shot.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            GATLING_A(reg_a4)->shot.t.count = (u8) GATLING_A(reg_a4)->shot.t.reload;
            reg_d0.h[0] = GATLING_A(reg_a4)->speed;
            reg_d0.h[0] += 0x14;
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 7;
            func_00201200();
            reg_d5.b[0] -= 1;
            reg_d5.b[0] += GATLING_A(reg_a4)->target_angle;
            reg_a0 = (u8 *)(D_0026E0C0);
            reg_d5.h[0] &= 0x3F;
            reg_d1.h[0] = reg_d5.h[0];
            reg_d2.h[0] = ENTITY(reg_a6)[5].sprite.h;
            reg_d2.h[0] += 7;
            reg_d2.h[0] += reg_d2.h[0];
            reg_d2.h[0] += reg_d2.h[0];
            reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            temp_a0_2 = ENTITY(reg_a6)[5].y.h;
            reg_tmp.h[1] = temp_a0_2;
            reg_tmp.h[0] = ENTITY(reg_a6)[5].x.h;
            reg_d3.w = 0;
            reg_d4.w = 0;
            reg_d2.w += reg_tmp.w;
            bullet_fire256_fixed();
            GATLING_A(reg_a4)->speed += 2;
            GATLING_A(reg_a4)->shots_left -= 1;
            if (GATLING_A(reg_a4)->shots_left == 0) {
                GATLING_A(reg_a4)->running = 0;
            }
        }
    }
}

s32 bullet_fire256_fast();
extern u16 g_loop;

void stage1_boss_fire_beam_fan() {
    u32 tmp;

    reg_d0.h[0] = BEAM(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d1.b[0] = BEAM(reg_a4)->direction;
    if (g_loop != 0) goto next_1;
    reg_d1.b[0] -= 0x14;
    reg_d5.h[0] = 0x14;
    reg_d7.h[0] = 2;
    goto loop_1;
next_1:
    reg_d1.b[0] -= 0x1E;
    reg_d5.h[0] = 0xA;
    reg_d7.h[0] = 6;
loop_1:
    bullet_fire256_fast();
    reg_d1.b[0] += reg_d5.b[0];
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
}

s32 rng_next_bit();
s32 aim256_at_player();

void stage1_boss_fire_right_beam_start(void) {
    u16 temp_a0;
    u8 temp_a0_2;

    enemy_switch_target_player();
    BEAM(reg_a4)->shot.sh = 4;
    BEAM(reg_a4)->spare.sh = 0x820;
    rng_next_bit();
    reg_d0.b[0] -= 1;
    BEAM(reg_a4)->spare.b[0] += reg_d0.b[0];
    reg_d0.h[1] = ENTITY(reg_a6)[1].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[1].x.h;
    reg_d0.w += 0xF6C00140;
    BEAM(reg_a4)->y = (u16) reg_d0.h[1];
    temp_a0 = reg_d0.h[0];
    BEAM(reg_a4)->x = temp_a0;
    BEAM(reg_a4)->direction = 0x80U;
    reg_d0.h[0] = BEAM(reg_a4)->y;
    reg_d1.h[0] = BEAM(reg_a4)->x;
    aim256_at_player();
    if (cond_flag != 0) {
        stage1_boss_fire_right_beam();
        return;
    }
    BEAM(reg_a4)->direction = (u8) reg_d1.b[0];
    temp_a0_2 = BEAM(reg_a4)->kind;
    if (temp_a0_2 != 2) {
        stage1_boss_fire_right_beam();
    }
}


void stage1_boss_fire_right_beam(void) {
    u8 temp_v1;

    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        stage1_boss_fire_clear();
        return;
    }
    reg_tmp.b[0] = BEAM(reg_a4)->shot.t.count;
    BEAM(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        BEAM(reg_a4)->shot.t.count = (u8) BEAM(reg_a4)->shot.t.reload;
        if (g_bullets_blocked == 0) {
            reg_d0.w = 0x100007;
            reg_d2.h[1] = BEAM(reg_a4)->y;
            reg_d2.h[0] = BEAM(reg_a4)->x;
            reg_d3.w = 0;
            reg_d1.w = 0;
            temp_v1 = BEAM(reg_a4)->kind;
            if (temp_v1 == 0) {
                reg_d0.w = 0x10007;
                reg_d6.w = reg_d0.w;
                reg_d1.b[0] = BEAM(reg_a4)->direction;
            } else if (temp_v1 == 1) {
                stage1_boss_fire_beam_fan(reg_a4);
            } else {
                stage1_boss_fire_beam_fan(reg_a4);
            }
        }
        BEAM(reg_a4)->speed += 4;
        BEAM(reg_a4)->shots_left -= 1;
        if (BEAM(reg_a4)->shots_left == 0) {
            BEAM(reg_a4)->running = 0;
        }
    }
}


void stage1_boss_fire_left_beam_start(void) {
    u16 temp_a0;
    u8 temp_a0_2;

    enemy_switch_target_player();
    BEAM(reg_a4)->shot.sh = 4;
    BEAM(reg_a4)->spare.sh = 0x820;
    rng_next_bit();
    reg_d0.b[0] -= 1;
    BEAM(reg_a4)->spare.b[0] += reg_d0.b[0];
    reg_d0.h[1] = ENTITY(reg_a6)[3].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[3].x.h;
    reg_d0.w += 0xF6BFFEC0;
    BEAM(reg_a4)->y = (u16) reg_d0.h[1];
    temp_a0 = reg_d0.h[0];
    BEAM(reg_a4)->x = temp_a0;
    BEAM(reg_a4)->direction = 0x80U;
    reg_d0.h[0] = BEAM(reg_a4)->y;
    reg_d1.h[0] = BEAM(reg_a4)->x;
    aim256_at_player();
    if (cond_flag != 0) {
        stage1_boss_fire_right_beam();
        return;
    }
    BEAM(reg_a4)->direction = (u8) reg_d1.b[0];
    temp_a0_2 = BEAM(reg_a4)->kind;
    if (temp_a0_2 != 2) {
        stage1_boss_fire_left_beam();
    }
}

void stage1_boss_fire_left_beam(void) {
    u8 temp_v1;

    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        stage1_boss_fire_clear();
        return;
    }
    reg_tmp.b[0] = BEAM(reg_a4)->shot.t.count;
    BEAM(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        BEAM(reg_a4)->shot.t.count = (u8) BEAM(reg_a4)->shot.t.reload;
        if (g_bullets_blocked == 0) {
            reg_d0.w = 0x100007;
            reg_d2.h[1] = BEAM(reg_a4)->y;
            reg_d2.h[0] = BEAM(reg_a4)->x;
            reg_d3.w = 0;
            reg_d1.w = 0;
            temp_v1 = BEAM(reg_a4)->kind;
            if (temp_v1 == 0) {
                reg_d0.w = 0x10007;
                reg_d6.w = reg_d0.w;
                reg_d1.b[0] = BEAM(reg_a4)->direction;
            } else if (temp_v1 == 1) {
                stage1_boss_fire_beam_fan(reg_a4);
            } else {
                stage1_boss_fire_beam_fan(reg_a4);
            }
        }
        BEAM(reg_a4)->speed += 4;
        BEAM(reg_a4)->shots_left -= 1;
        if (BEAM(reg_a4)->shots_left == 0) {
            BEAM(reg_a4)->running = 0;
        }
    }
}

void stage1_boss_main_gun_pace_set(void) {
    MAIN_GUN(reg_a4)->interval = 6;
    MAIN_GUN(reg_a4)->speed = 0xFFFA;
    if (g_loop != 0) {
        MAIN_GUN(reg_a4)->interval = 3;
        MAIN_GUN(reg_a4)->speed = 0xFFFB;
    }
}


void stage1_boss_main_gun_shoot() {
    reg_d1.w = 0;
    reg_d1.b[0] = MAIN_GUN(reg_a4)->direction;
    reg_d0.h[0] = MAIN_GUN(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 0x13;
    bullet_fire256_2way();
    reg_d1.b[0] += 0x80;
    bullet_fire256_2way();
    if (g_loop != 0) {
        reg_d1.b[0] += 0x40;
        bullet_fire256_fixed();
        reg_d1.b[0] += 0x80;
        bullet_fire256_fixed();
    }
}

extern u8 D_0028DC38[];

void stage1_boss_fire_right_main_gun_start(void) {
    MAIN_GUN(reg_a4)->wait = 0x38;
    MAIN_GUN(reg_a4)->unused_04 = 0;
    MAIN_GUN(reg_a4)->unused_06 = 8;
    MAIN_GUN(reg_a4)->direction = 0x40U;
    rng_next();
    reg_d0.b[0] = reg_d0.sb[0] * 4;
    MAIN_GUN(reg_a4)->direction += reg_d0.b[0];
    MAIN_GUN(reg_a4)->speedup.sh = 0x404;
    MAIN_GUN(reg_a4)->spare.sh = 0x505;
    MAIN_GUN(reg_a4)->unused_13 = 1;
    MAIN_GUN(reg_a4)->unused_12 = 0;
    stage1_boss_main_gun_pace_set();
    func_001713B0();
    MAIN_GUN(reg_a4)->spare.t.reload = *(D_0028DC38 + reg_d0.b[0]);
    stage1_boss_fire_right_main_gun();
}


void stage1_boss_fire_right_main_gun() {
    u32 temp_a1;
    u8 temp_v1;
    u8 *var_a0;

    if (ENTITY(reg_a6)[1].misc.b.draw_layer == 0) {
        var_a0 = reg_a4;
        reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
        temp_a1 = reg_d2.w;
        reg_d3.w = 0;
        reg_d4.w = 0;
        reg_d2.w = temp_a1 + 0xF6C00140;
        reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0) + (3)));
        (*(u8 *)((u8 *)(var_a0) + (3))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            reg_tmp.b[0] = MAIN_GUN(reg_a4)->speedup.t.count;
            MAIN_GUN(reg_a4)->speedup.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                MAIN_GUN(reg_a4)->speedup.t.count = (u8) MAIN_GUN(reg_a4)->speedup.t.reload;
                var_a0 = reg_a4 + 2;
                temp_v1 = MAIN_GUN(reg_a4)->interval;
                if (temp_v1 != 3) {
                    MAIN_GUN(reg_a4)->interval = (u8) (temp_v1 - 1);
                }
            }
            MAIN_GUN(reg_a4)->wait = (u8) MAIN_GUN(reg_a4)->interval;
            reg_tmp.b[0] = MAIN_GUN(reg_a4)->spare.t.count;
            MAIN_GUN(reg_a4)->spare.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                MAIN_GUN(reg_a4)->spare.t.count = (u8) MAIN_GUN(reg_a4)->spare.t.reload;
            }
            stage1_boss_main_gun_shoot();
            MAIN_GUN(reg_a4)->direction += 0xB;
        }
    }
}


void stage1_boss_fire_left_main_gun_start(void) {
    MAIN_GUN(reg_a4)->wait = 0x20;
    MAIN_GUN(reg_a4)->unused_04 = 0;
    MAIN_GUN(reg_a4)->unused_06 = 8;
    MAIN_GUN(reg_a4)->speedup.sh = 0x404;
    MAIN_GUN(reg_a4)->direction = 0xC0U;
    rng_next();
    reg_d0.b[0] = reg_d0.sb[0] * 4;
    MAIN_GUN(reg_a4)->direction += reg_d0.b[0];
    MAIN_GUN(reg_a4)->speedup.sh = 0x404;
    MAIN_GUN(reg_a4)->spare.sh = 0x505;
    MAIN_GUN(reg_a4)->unused_13 = 1;
    MAIN_GUN(reg_a4)->unused_12 = 0;
    stage1_boss_main_gun_pace_set();
    func_001713B0();
    MAIN_GUN(reg_a4)->spare.t.reload = *(D_0028DC38 + reg_d0.b[0]);
    stage1_boss_fire_left_main_gun();
}

void stage1_boss_fire_left_main_gun() {
    u32 temp_a1;
    u8 temp_v1;
    u8 *var_a0;

    if (ENTITY(reg_a6)[3].misc.b.draw_layer == 0) {
        var_a0 = reg_a4;
        reg_d2.h[1] = ENTITY(reg_a6)[3].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[3].x.h;
        temp_a1 = reg_d2.w;
        reg_d3.w = 0;
        reg_d4.w = 0;
        reg_d2.w = temp_a1 + 0xF6BFFEC0;
        reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0) + (3)));
        (*(u8 *)((u8 *)(var_a0) + (3))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            reg_tmp.b[0] = MAIN_GUN(reg_a4)->speedup.t.count;
            MAIN_GUN(reg_a4)->speedup.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                MAIN_GUN(reg_a4)->speedup.t.count = (u8) MAIN_GUN(reg_a4)->speedup.t.reload;
                var_a0 = reg_a4 + 2;
                temp_v1 = MAIN_GUN(reg_a4)->interval;
                if (temp_v1 != 3) {
                    MAIN_GUN(reg_a4)->interval = (u8) (temp_v1 - 1);
                }
            }
            MAIN_GUN(reg_a4)->wait = (u8) MAIN_GUN(reg_a4)->interval;
            reg_tmp.b[0] = MAIN_GUN(reg_a4)->spare.t.count;
            MAIN_GUN(reg_a4)->spare.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                MAIN_GUN(reg_a4)->spare.t.count = (u8) MAIN_GUN(reg_a4)->spare.t.reload;
            }
            stage1_boss_main_gun_shoot();
            MAIN_GUN(reg_a4)->direction -= 0xB;
        }
    }
}

void stage1_boss_fire_gatling_b_start(void) {
    *(s8 *)(reg_a4 + 5) = 0;
    *(s8 *)(reg_a4 + 4) = 0x20;
    *(u16 *)(reg_a4 + 6) = 0x202;
    *(u16 *)(reg_a4 + 8) = 8;
    *(u16 *)(reg_a4 + 0xA) = 6;
    *(u16 *)(reg_a4 + 0xC) = 0xFFF8;
}

void stage1_boss_fire_gatling_b(void) {
    u16 temp_a0;

    if (*(u8 *)(reg_a4 + 5) == 0) {
        *(u8 *)(reg_a4 + 5) = 1U;
    }
    if (*(u8 *)(reg_a4 + 5) == 1) {
        *(u8 *)(reg_a4 + 5) = 2U;
    }
    if (*(u8 *)(reg_a4 + 5) == 2) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 9);
        *(u8 *)(reg_a4 + 9) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
            reg_d0.h[0] += 0x14;
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 7;
            func_00201200();
            reg_d5.b[0] -= 1;
            reg_d5.b[0] += *(u8 *)(reg_a4 + 4);
            reg_a0 = (u8 *)(D_0026E0C0);
            reg_d5.h[0] &= 0x3F;
            reg_d1.h[0] = reg_d5.h[0];
            reg_d2.h[0] = ENTITY(reg_a6)[5].sprite.h;
            reg_d2.h[0] += 7;
            reg_d2.h[0] += reg_d2.h[0];
            reg_d2.h[0] += reg_d2.h[0];
            reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            temp_a0 = ENTITY(reg_a6)[5].y.h;
            reg_tmp.h[1] = temp_a0;
            reg_tmp.h[0] = ENTITY(reg_a6)[5].x.h;
            reg_d3.w = 0;
            reg_d4.w = 0;
            reg_d2.w += reg_tmp.w;
            bullet_fire256_fixed();
            *(u16 *)(reg_a4 + 0xC) += 1;
            *(u16 *)(reg_a4 + 0xA) -= 1;
            if (*(u16 *)(reg_a4 + 0xA) == 0) {
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

s32 rng_next_unsigned();
extern u16 D_0026E100[];
extern u16 D_0026E110[];

void stage1_boss_fire_main_guns_burst_start(void) {
    func_001713B0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)(D_0026E110);
    *(u16 *)(reg_a4 + 2) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(D_0026E100);
    *(u16 *)(reg_a4 + 4) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(s16 *)(reg_a4 + 6) = 0x18;
    *(u16 *)(reg_a4 + 8) = 0U;
    *(s16 *)(reg_a4 + 0xA) = 2;
    rng_next_unsigned();
    reg_d0.h[0] &= 1;
    *(u16 *)(reg_a4 + 8) = (u16) reg_d0.h[0];
    stage1_boss_fire_main_guns_burst();
}

s32 spawn_request_add();

void stage1_boss_fire_main_guns_burst(void) {
    reg_tmp.b[0] = reg_a4[7];
    reg_a4[7] -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        return;
    }
    reg_a4[7] = reg_a4[6];
    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        goto skip_1;
    }
    if (*(u16 *)(reg_a4 + 8) != 0) {
        goto skip_1;
    }
    reg_d0.w = 0x1E;
    spawn_request_add();
    reg_d0.h[1] = ENTITY(reg_a6)[1].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[1].x.h;
    reg_d0.w += 0xF6C00140;
    *(u16 *)(reg_a0 + 0x16) = reg_d0.h[1];
    *(u16 *)(reg_a0 + 0x18) = reg_d0.h[0];
    *(u16 *)(reg_a0 + 0x1A) = 0x2020;
    *(u16 *)(reg_a0 + 0x1C) = *(u16 *)(reg_a4 + 4);
    *(u16 *)(reg_a0 + 0x1E) = *(u16 *)(reg_a4 + 2);
    if (g_loop == 0) {
        goto skip_1;
    }
    reg_d0.w = 0x1E;
    spawn_request_add();
    reg_d0.h[1] = ENTITY(reg_a6)[1].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[1].x.h;
    reg_d0.w += 0xF6C00140;
    *(u16 *)(reg_a0 + 0x16) = reg_d0.h[1];
    *(u16 *)(reg_a0 + 0x18) = reg_d0.h[0];
    *(u16 *)(reg_a0 + 0x1A) = 0x1A28;
    *(u16 *)(reg_a0 + 0x1C) = *(u16 *)(reg_a4 + 4);
    *(u16 *)(reg_a0 + 0x1E) = *(u16 *)(reg_a4 + 2);
skip_1:
    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        goto skip_2;
    }
    if (*(u16 *)(reg_a4 + 8) == 0) {
        goto skip_2;
    }
    reg_d0.w = 0x1E;
    spawn_request_add();
    reg_d0.h[1] = ENTITY(reg_a6)[3].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[3].x.h;
    reg_d0.w += 0xF6BFFEC0;
    *(u16 *)(reg_a0 + 0x16) = reg_d0.h[1];
    *(u16 *)(reg_a0 + 0x18) = reg_d0.h[0];
    *(u16 *)(reg_a0 + 0x1A) = 0x2020;
    *(u16 *)(reg_a0 + 0x1C) = *(u16 *)(reg_a4 + 4);
    *(u16 *)(reg_a0 + 0x1E) = *(u16 *)(reg_a4 + 2);
    if (g_loop == 0) {
        goto skip_2;
    }
    reg_d0.w = 0x1E;
    spawn_request_add();
    reg_d0.h[1] = ENTITY(reg_a6)[3].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[3].x.h;
    reg_d0.w += 0xF6BFFEC0;
    *(u16 *)(reg_a0 + 0x16) = reg_d0.h[1];
    *(u16 *)(reg_a0 + 0x18) = reg_d0.h[0];
    *(u16 *)(reg_a0 + 0x1A) = 0x1A18;
    *(u16 *)(reg_a0 + 0x1C) = *(u16 *)(reg_a4 + 4);
    *(u16 *)(reg_a0 + 0x1E) = *(u16 *)(reg_a4 + 2);
skip_2:
    *(u16 *)(reg_a4 + 4) += 1;
    *(u16 *)(reg_a4 + 8) += 1;
    *(u16 *)(reg_a4 + 8) &= 1;
    *(u16 *)(reg_a4 + 0xA) -= 1;
    if (*(u16 *)(reg_a4 + 0xA) == 0) {
        *(u16 *)reg_a4 = 0;
    }
}

extern u8 D_0026E120[];

void stage1_boss_fire_body_ports_rapid_start(void) {
    func_001713B0();
    reg_a0 = D_0026E120;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    *(u16 *)(reg_a4 + 8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0xA) = *(u16 *)reg_a0;
    stage1_boss_fire_body_ports_rapid();
}

s32 bullet_fire256();

void stage1_boss_fire_body_ports_rapid() {
    u16 temp_a2;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 9);
    *(u8 *)(reg_a4 + 9) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
        reg_d1.w = 0;
        reg_d1.b[0] = 0x80;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        temp_a2 = ENTITY(reg_a6)->x.h;
        reg_d2.h[0] = temp_a2;
        reg_d0.w = 0x80009;
        reg_d1.b[0] = 0x60;
        reg_d3.h[1] = D_0026E094[0];
        reg_d3.h[0] = D_0026E096[0];
        reg_d4.w = 0;
        bullet_fire256();
        reg_d1.b[0] = 0x70;
        reg_d3.h[1] = D_0026E09C[0];
        reg_d3.h[0] = D_0026E09E[0];
        bullet_fire256();
        reg_d1.b[0] = 0xA0;
        reg_d3.h[1] = D_0026E090[0];
        reg_d3.h[0] = D_0026E092[0];
        bullet_fire256();
        reg_d1.b[0] = 0x90;
        reg_d3.h[1] = D_0026E098[0];
        reg_d3.h[0] = D_0026E09A[0];
        bullet_fire256();
        *(u16 *)(reg_a4 + 0xA) -= 1;
        if (*(u16 *)(reg_a4 + 0xA) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}

extern u16 D_0026E140[];

void stage1_boss_fire_body_ports_aimed_start(void) {
    u16 temp_a0;

    func_001713B0();
    reg_a0 = (u8 *)(D_0026E140);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    *(u16 *)(reg_a4 + 8) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    temp_a0 = *(u16 *)reg_a0;
    *(u16 *)(reg_a4 + 0xA) = temp_a0;
    *(s8 *)(reg_a4 + 0xD) = 0x20;
    stage1_boss_fire_body_ports_aimed();
}

void stage1_boss_fire_body_ports_aimed() {
    u16 temp_a2;
    u8 temp_a0;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 9);
    *(u8 *)(reg_a4 + 9) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        aim256_at_player();
        if (cond_flag == 0) {
            *(u8 *)(reg_a4 + 0xD) = (u8) reg_d1.b[0];
        }
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        temp_a2 = ENTITY(reg_a6)->x.h;
        reg_d2.h[0] = temp_a2;
        reg_d0.w = 0x20009;
        reg_d4.w = 0;
        reg_d1.w = 0;
        temp_a0 = *(u8 *)(reg_a4 + 0xD);
        reg_d1.b[0] = temp_a0;
        reg_d3.h[1] = D_0026E094[0];
        reg_d3.h[0] = D_0026E096[0];
        bullet_fire256();
        reg_d3.h[1] = D_0026E09C[0];
        reg_d3.h[0] = D_0026E09E[0];
        bullet_fire256();
        reg_d3.h[1] = D_0026E090[0];
        reg_d3.h[0] = D_0026E092[0];
        bullet_fire256();
        reg_d3.h[1] = D_0026E098[0];
        reg_d3.h[0] = D_0026E09A[0];
        bullet_fire256();
        *(u16 *)(reg_a4 + 0xA) -= 1;
        if (*(u16 *)(reg_a4 + 0xA) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}

extern u16 D_0026E160[];

void stage1_boss_fire_front_guns_rage_start(void) {
    *(s16 *)(reg_a4 + 2) = 8;
    func_001713B0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)D_0026E160;
    *(u16 *)(reg_a4 + 4) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)((u16 *)reg_a0) + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    stage1_boss_fire_front_guns_rage();
}

extern u16 D_0026E170[];
extern u16 D_0026E172[];
extern u16 D_0026E174[];
extern u16 D_0026E176[];
extern u16 D_0026E178[];
extern u16 D_0026E17A[];
extern u16 D_0026E17C[];
extern u16 D_0026E17E[];

void stage1_boss_fire_front_guns_rage(void) {
    u16 temp_a2;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        temp_a2 = ENTITY(reg_a6)->x.h;
        reg_d1.w = 0;
        reg_d2.h[0] = temp_a2;
        reg_d0.w = 0x80013;
        reg_d1.b[0] = 0x80;
        reg_d3.h[1] = D_0026E174[0];
        reg_d3.h[0] = D_0026E176[0];
        reg_d4.w = 0;
        bullet_fire256_fixed();
        reg_d3.h[1] = D_0026E17C[0];
        reg_d3.h[0] = D_0026E17E[0];
        bullet_fire256_fixed();
        reg_d3.h[1] = D_0026E170[0];
        reg_d3.h[0] = D_0026E172[0];
        bullet_fire256_fixed();
        reg_d3.h[1] = D_0026E178[0];
        reg_d3.h[0] = D_0026E17A[0];
        bullet_fire256_fixed();
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}

extern u16 D_0026E180[];

void stage1_boss_fire_front_guns_rage_spread_start(void) {
    func_001713B0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)D_0026E180;
    *(u16 *)(reg_a4 + 2) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)((u16 *)reg_a0) + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(s16 *)(reg_a4 + 4) = 2;
    stage1_boss_fire_front_guns_rage_spread();
}

void stage1_boss_fire_front_guns_rage_spread(void) {
    u16 temp_a2;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        temp_a2 = ENTITY(reg_a6)->x.h;
        reg_d1.w = 0;
        reg_d2.h[0] = temp_a2;
        reg_d0.w = 0x13;
        reg_d1.b[0] = 0x80;
        reg_d3.h[1] = D_0026E170[0];
        reg_d3.h[0] = D_0026E172[0];
        reg_d4.w = 0;
        bullet_fire256_2way();
        reg_d1.b[0] += 0xC;
        bullet_fire256_2way();
        reg_d1.b[0] += 0xC;
        bullet_fire256_2way();
        reg_d1.b[0] -= 0x24;
        bullet_fire256_2way();
        reg_d1.b[0] -= 0xC;
        bullet_fire256_2way();
        reg_d1.b[0] = 0x80;
        reg_d3.h[1] = D_0026E174[0];
        reg_d3.h[0] = D_0026E176[0];
        bullet_fire256_2way();
        reg_d1.b[0] += 0xC;
        bullet_fire256_2way();
        reg_d1.b[0] += 0xC;
        bullet_fire256_2way();
        reg_d1.b[0] -= 0x24;
        bullet_fire256_2way();
        reg_d1.b[0] -= 0xC;
        bullet_fire256_2way();
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}

void stage1_boss_fire_gatling_c_start(void) {
    *(s16 *)(reg_a4 + 8) = 8;
    *(s16 *)(reg_a4 + 0xA) = 0;
    *(s16 *)(reg_a4 + 0xC) = 0;
    reg_d0.h[0] = ENTITY(reg_a6)[5].sprite.h;
    reg_d0.h[0] += 0x20;
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += reg_d0.b[0];
    *(u8 *)(reg_a4 + 0x11) = (u8) reg_d0.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)[5].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[5].x.h;
    aim256_at_player();
    if (cond_flag == 0) {
        *(u8 *)(reg_a4 + 0x11) = (u8) reg_d1.b[0];
    }
    enemy_switch_target_player();
}

s32 rng_next_word();
extern u16 D_00259970[];

void stage1_boss_fire_gatling_c(void) {
    u16 temp_a0;
    u16 temp_a1;
    u16 temp_a1_2;
    u16 temp_a1_3;
    u16 temp_a2;
    u16 temp_a2_2;
    u16 temp_a2_3;
    u32 temp_a0_3;
    u32 temp_a0_5;
    u32 temp_a0_7;

    if (g_bullets_blocked == 0) {
        reg_a2 = (u8 *)(D_0026E0C0);
        reg_d2.h[0] = ENTITY(reg_a6)[5].sprite.h;
        reg_d2.h[0] += 7;
        reg_d2.h[0] += reg_d2.h[0];
        reg_d2.h[0] += reg_d2.h[0];
        reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a2;
        reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        temp_a0 = ENTITY(reg_a6)[5].y.h;
        reg_tmp.h[1] = temp_a0;
        reg_tmp.h[0] = ENTITY(reg_a6)[5].x.h;
        reg_d2.w += reg_tmp.w;
        rng_next_unsigned();
        reg_d4.w = 0;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d0.w = 0xFFF9000B;
        reg_d7.w = 0xF;
        reg_a0 = (u8 *)(D_00259970);
        do {
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] += 2;
            reg_d3.h[0] &= 0xFC;
            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d6.b[0] = reg_d1.b[0];
            bullet_fire256();
            reg_d1.b[0] += 4;
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] += 2;
            reg_d3.h[0] &= 0xFC;
            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            bullet_fire256();
            reg_d1.b[0] = reg_d6.b[0];
            reg_d1.b[0] += 0x10;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        do {
            rng_next_word();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            *(u16 *)(reg_a4 + 0x12) = (u16) reg_d0.h[0];
            reg_d0.w = 0;
            reg_d0.b[0] = *(u8 *)(reg_a4 + 5);
            reg_d0.h[0] -= 0x14;
            temp_a2 = reg_d0.h[0];
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = temp_a2;
            reg_d0.h[0] = 7;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x11);
            reg_a0 = (u8 *)(D_0026E0C0);
            reg_d2.h[0] = ENTITY(reg_a6)[5].sprite.h;
            reg_d2.h[0] += 7;
            reg_d2.h[0] += reg_d2.h[0];
            reg_d2.h[0] += reg_d2.h[0];
            reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            temp_a1 = ENTITY(reg_a6)[5].y.h;
            temp_a0_3 = reg_d2.w;
            reg_tmp.h[1] = temp_a1;
            reg_tmp.h[0] = ENTITY(reg_a6)[5].x.h;
            reg_d2.w = temp_a0_3 + reg_tmp.w;
            reg_d2.h[0] += *(u16 *)(reg_a4 + 0x12);
            reg_d3.w = 0;
            reg_d4.w = 0;
            bullet_fire256_fixed();
            *(u8 *)(reg_a4 + 5) += 2;
            *(u16 *)(reg_a4 + 0xA) += 2;
            *(u16 *)(reg_a4 + 0xC) += 2;
            rng_next_word();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            *(u16 *)(reg_a4 + 0x12) = (u16) reg_d0.h[0];
            reg_d0.w = 0;
            reg_d0.b[0] = *(u8 *)(reg_a4 + 5);
            reg_d0.h[0] -= 0x15;
            temp_a2_2 = reg_d0.h[0];
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = temp_a2_2;
            reg_d0.h[0] = 7;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x11);
            reg_a0 = (u8 *)(D_0026E0C0);
            reg_d1.b[0] += 3;
            reg_d2.h[0] = ENTITY(reg_a6)[5].sprite.h;
            reg_d2.h[0] += 7;
            reg_d2.h[0] += reg_d2.h[0];
            reg_d2.h[0] += reg_d2.h[0];
            reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            temp_a1_2 = ENTITY(reg_a6)[5].y.h;
            temp_a0_5 = reg_d2.w;
            reg_tmp.h[1] = temp_a1_2;
            reg_tmp.h[0] = ENTITY(reg_a6)[5].x.h;
            reg_d2.w = temp_a0_5 + reg_tmp.w;
            reg_d2.h[0] += *(u16 *)(reg_a4 + 0x12);
            reg_d3.w = 0;
            reg_d4.w = 0;
            bullet_fire256_fixed();
            rng_next_word();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            *(u16 *)(reg_a4 + 0x12) = (u16) reg_d0.h[0];
            reg_d0.w = 0;
            reg_d0.b[0] = *(u8 *)(reg_a4 + 5);
            reg_d0.h[0] -= 0x16;
            temp_a2_3 = reg_d0.h[0];
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = temp_a2_3;
            reg_d0.h[0] = 7;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x11);
            reg_a0 = (u8 *)(D_0026E0C0);
            reg_d1.b[0] -= 3;
            reg_d2.h[0] = ENTITY(reg_a6)[5].sprite.h;
            reg_d2.h[0] += 7;
            reg_d2.h[0] += reg_d2.h[0];
            reg_d2.h[0] += reg_d2.h[0];
            reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            temp_a1_3 = ENTITY(reg_a6)[5].y.h;
            temp_a0_7 = reg_d2.w;
            reg_tmp.h[1] = temp_a1_3;
            reg_tmp.h[0] = ENTITY(reg_a6)[5].x.h;
            reg_d2.w = temp_a0_7 + reg_tmp.w;
            reg_d2.h[0] += *(u16 *)(reg_a4 + 0x12);
            reg_d3.w = 0;
            reg_d4.w = 0;
            bullet_fire256_fixed();
            *(u16 *)(reg_a4 + 6) -= 1;
        } while (*(u16 *)(reg_a4 + 6) != 0);
    }
    *(s16 *)reg_a4 = 0;
}

void func_001B7620(void) {
    u32 tmp;

    reg_d3.w = 0;
    reg_d4.w = 0;
    if (g_loop != 0) goto next_1;
    reg_d0.w = 0xFFFE0004;
    reg_d1.b[0] -= 2;
    reg_d5.h[0] = 2;
    reg_d7.h[0] = 2;
    goto loop_1;
next_1:
    reg_d0.w = 3;
    reg_d1.b[0] -= 0xC;
    reg_d5.h[0] = 4;
    reg_d7.h[0] = 6;
loop_1:
    bullet_fire256_fixed();
    reg_d1.b[0] += reg_d5.b[0];
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
}

typedef struct WorkRegA4 {
    u8 pad0[4];
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
} WorkRegA4;



void stage1_boss_fire_side_spread_start(void) {
    ((WorkRegA4 *)reg_a4)->unk4 = 0x9050;
    ((WorkRegA4 *)reg_a4)->unk6 = 0;
    ((WorkRegA4 *)reg_a4)->unk8 = 1;
    ((WorkRegA4 *)reg_a4)->unkA = 0xC;
    stage1_boss_fire_side_spread(1, 0x9050);
}


void stage1_boss_fire_side_spread() {
    u8 temp_v1;

    if (*(u8 *)(reg_a4 + 9) == 0) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            temp_v1 = *(u8 *)(reg_a4 + 4);
            if ((s32) temp_v1 > 0x10) {
                *(u8 *)(reg_a4 + 4) = (u8) (temp_v1 - 4);
            }
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
            goto block_5;
        }
    } else {
block_5:
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xB);
        *(u8 *)(reg_a4 + 0xB) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xB) = (u8) *(u8 *)(reg_a4 + 0xA);
            enemy_switch_target_player();
            if (ENTITY(reg_a6)[1].misc.b.draw_layer == 0) {
                reg_d0.h[0] = ENTITY(reg_a6)[1].y.h;
                reg_d1.h[0] = ENTITY(reg_a6)[1].x.h;
                reg_d0.h[0] += 0x7FFF + 0x76C1;
                reg_d1.h[0] += 0x140;
                aim256_at_player();
                if (cond_flag == 0) {
                    reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
                    reg_d2.w += 0xF6C00140;
                    func_001B7620();
                }
            }
            if (ENTITY(reg_a6)[3].misc.b.draw_layer == 0) {
                reg_d0.h[0] = ENTITY(reg_a6)[3].y.h;
                reg_d1.h[0] = ENTITY(reg_a6)[3].x.h;
                reg_d0.h[0] += 0x7FFF + 0x76C1;
                reg_d1.h[0] += 0x7FFF + 0x7EC1;
                aim256_at_player();
                if (cond_flag == 0) {
                    reg_d2.h[1] = ENTITY(reg_a6)[3].y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)[3].x.h;
                    reg_d2.w += 0xF6BFFEC0;
                    func_001B7620();
                }
            }
            *(u8 *)(reg_a4 + 9) -= 1;
            if (*(u8 *)(reg_a4 + 9) == 0) {
                *(u16 *)(reg_a4 + 6) += 1;
                *(u16 *)(reg_a4 + 6) &= 1;
            }
        }
    }
}
