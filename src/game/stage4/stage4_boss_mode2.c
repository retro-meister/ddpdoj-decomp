#include "common.h"
#ifdef DDPDOJ_PC
void boss_movement_start(void);
#endif
#include "entity.h"
#include "stage4_boss.h"

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;               /* 0 to 5 */
    /* 0x04 */ SlotTimer volley;
    /* 0x06 */ u16 side;              /* 0, 2 */
    /* 0x08 */ u16 right_frame;
    /* 0x0A */ u16 left_frame;
    /* 0x0C */ SlotTimer faster;
    /* 0x0E */ u16 volleys_left;
    /* 0x10 */ SlotTimer pause;
    /* 0x12 */ u8 rounds_b;
    /* 0x13 */ u8 rounds_a;
    /* 0x14 */ u8 wait;
    /* 0x15 */ u8 swaps_left;
} AttackAMode;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;               /* 0 to 4 */
    /* 0x04 */ u16 wait;
    /* 0x06 */ u16 entry;
} AttackBMode;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 pod_steps;          /* bits */
    /* 0x03 */ u8 steps;              /* bits */
    /* 0x04 */ u16 pod_wait;
    /* 0x06 */ u16 pod_accel;
    /* 0x08 */ u16 unused_08;
    /* 0x0A */ u16 unread_0A;
    /* 0x0C */ u16 wait;
    /* 0x0E */ u16 unused_0E;
    /* 0x10 */ SlotTimer cutter_rounds;
    /* 0x12 */ u16 cutter_side;       /* 0, 1 */
    /* 0x14 */ SlotTimer cutter_timer;
} AttackCMode;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;               /* 0, 1 */
    /* 0x04 */ u16 wait;
    /* 0x06 */ u16 turn;              /* 0, 1 */
    /* 0x08 */ u16 attack_wait;
    /* 0x0A */ u16 side_shots;
    /* 0x0C */ u16 wing_rounds;
    /* 0x0E */ u16 other_0E;
} RageMode;

#define ATTACK_A(pointer) ((AttackAMode *)(pointer))
#define ATTACK_B(pointer) ((AttackBMode *)(pointer))
#define ATTACK_C(pointer) ((AttackCMode *)(pointer))
#define RAGE(pointer) ((RageMode *)(pointer))


void stage4_boss_mode_attack_a();
void stage4_boss_mode_attack_b(void);
void stage4_boss_mode_attack_c(void);
void stage4_boss_mode_rage(void);

s32 rng_next_unsigned();                            /* extern */

void stage4_boss_mode_attack_a_start(void) {
    ATTACK_A(reg_a4)->step = 0;
    ATTACK_A(reg_a4)->volley.sh = 0x200C;
    ATTACK_A(reg_a4)->side = 0;
    rng_next_unsigned();
    reg_d0.h[0] &= 0xF;
    ATTACK_A(reg_a4)->right_frame = (u16) reg_d0.h[0];
    rng_next_unsigned();
    reg_d0.h[0] &= 0xF;
    ATTACK_A(reg_a4)->left_frame = (u16) reg_d0.h[0];
    ATTACK_A(reg_a4)->faster.sh = 0x101;
    ATTACK_A(reg_a4)->volleys_left = 0x20;
    ATTACK_A(reg_a4)->pause.sh = 0x808;
    ATTACK_A(reg_a4)->rounds_a = 2;
    ATTACK_A(reg_a4)->rounds_b = 2;
    ATTACK_A(reg_a4)->swaps_left = 2;
    ATTACK_A(reg_a4)->wait = 0x10;
    stage4_boss_mode_attack_a(2, 0x808, 0x20, 0x101);
}


s32 boss_phase_start();
s32 boss_attack_start();
s32 boss_attack_running();
s32 stage4_boss_right_spinner_turn();
s32 stage4_boss_left_spinner_turn_back();

void stage4_boss_mode_attack_a() {
    u16 temp_a0;
    u16 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_v1;
    u8 temp_v1_2;
    u8 temp_v1_3;
    u8 *var_a0;

    if (ATTACK_A(reg_a4)->step == 0) {
        reg_d7.w = 0;
        reg_d0.h[0] = ENTITY(reg_a6)[6].offset_y.h;
        temp_a0 = ATTACK_A(reg_a4)->right_frame;
        if (temp_a0 != reg_d0.h[0]) {
            stage4_boss_right_spinner_turn();
            reg_d7.w = 1;
        }
        reg_d0.h[0] = ENTITY(reg_a6)[7].offset_y.h;
        temp_a0_2 = ATTACK_A(reg_a4)->left_frame;
        if (temp_a0_2 != reg_d0.h[0]) {
            stage4_boss_left_spinner_turn_back();
            reg_d7.w = 1;
        }
        if (reg_d7.h[0] == 0) {
            ATTACK_A(reg_a4)->step = 1U;
        }
    }
    if (ATTACK_A(reg_a4)->step == 1) {
        reg_tmp.b[0] = ATTACK_A(reg_a4)->volley.t.count;
        ATTACK_A(reg_a4)->volley.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            ATTACK_A(reg_a4)->volley.t.count = (u8) ATTACK_A(reg_a4)->volley.t.reload;
            reg_tmp.b[0] = ATTACK_A(reg_a4)->faster.t.count;
            ATTACK_A(reg_a4)->faster.t.count -= 1;
            if (((s32) reg_tmp.b[0] <= 0) && (ATTACK_A(reg_a4)->faster.t.count = (u8) ATTACK_A(reg_a4)->faster.t.reload, var_a0 = reg_a4 + 4, temp_v1 = ATTACK_A(reg_a4)->volley.t.reload, (temp_v1 != 6))) {
                ATTACK_A(reg_a4)->volley.t.reload = (u8) (temp_v1 - 1);
            } else {
                ATTACK_A(reg_a4)->volleys_left -= 1;
                var_a0 = (u8 *)(reg_a4);
                if ((s16) (*(u16 *)((u8 *)(var_a0) + (0xE))) == 0) {
                    (*(u8 *)((u8 *)(var_a0) + (3))) = 2U;
                    ATTACK_A(reg_a4)->wait = 0x60U;
                }
            }
            reg_a0 = (u8 *)stage4_form2_volley;
            reg_a0 += ATTACK_A(reg_a4)->side;
            reg_d7.h[0] = *(u16 *)(reg_a0 + 2);
            reg_d0.h[0] = *(u16 *)reg_a0;
            boss_attack_start();
            SPINNER(reg_a0)->pattern = 0U;
            ATTACK_A(reg_a4)->side += 2;
            ATTACK_A(reg_a4)->side &= 3;
        }
    }
    if (ATTACK_A(reg_a4)->step == 2) {
        temp_v1_2 = ATTACK_A(reg_a4)->wait;
        if (temp_v1_2 != 0) {
            ATTACK_A(reg_a4)->wait = (u8) (temp_v1_2 - 1);
        } else {
            reg_d0.w = 1;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_tmp.b[0] = ATTACK_A(reg_a4)->volley.t.count;
                ATTACK_A(reg_a4)->volley.t.count -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    ATTACK_A(reg_a4)->volley.t.count = (u8) ATTACK_A(reg_a4)->volley.t.reload;
                    reg_d0.h[0] = 1;
                    boss_attack_start();
                    SPINNER(reg_a0)->pattern = 1U;
                }
                reg_d0.w = 2;
                boss_attack_running();
                if (cond_flag == 0) {
                    reg_tmp.b[0] = ATTACK_A(reg_a4)->pause.t.count;
                    ATTACK_A(reg_a4)->pause.t.count -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        ATTACK_A(reg_a4)->pause.t.count = (u8) ATTACK_A(reg_a4)->pause.t.reload;
                        ATTACK_A(reg_a4)->rounds_a -= 1;
                        if ((s8) ATTACK_A(reg_a4)->rounds_a == 0) {
                            ATTACK_A(reg_a4)->rounds_a = 2U;
                            ATTACK_A(reg_a4)->step = 3U;
                            ATTACK_A(reg_a4)->swaps_left -= 1;
                            if ((s8) ATTACK_A(reg_a4)->swaps_left == 0) {
                                ATTACK_A(reg_a4)->step = 4U;
                                ATTACK_A(reg_a4)->wait = 0x10U;
                            }
                        } else {
                            reg_d0.h[0] = 2;
                            boss_attack_start();
                            SPINNER(reg_a0)->pattern = 2U;
                        }
                    }
                }
            }
        }
    }
    if (ATTACK_A(reg_a4)->step == 3) {
        temp_v1_3 = ATTACK_A(reg_a4)->wait;
        if (temp_v1_3 != 0) {
            ATTACK_A(reg_a4)->wait = (u8) (temp_v1_3 - 1);
        } else {
            reg_tmp.b[0] = ATTACK_A(reg_a4)->volley.t.count;
            ATTACK_A(reg_a4)->volley.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ATTACK_A(reg_a4)->volley.t.count = (u8) ATTACK_A(reg_a4)->volley.t.reload;
                reg_d0.h[0] = 2;
                boss_attack_start();
                SPINNER(reg_a0)->pattern = 1U;
            }
            reg_d0.w = 1;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_tmp.b[0] = ATTACK_A(reg_a4)->pause.t.count;
                ATTACK_A(reg_a4)->pause.t.count -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    ATTACK_A(reg_a4)->pause.t.count = (u8) ATTACK_A(reg_a4)->pause.t.reload;
                    ATTACK_A(reg_a4)->rounds_b -= 1;
                    if ((s8) ATTACK_A(reg_a4)->rounds_b == 0) {
                        ATTACK_A(reg_a4)->rounds_b = 2U;
                        ATTACK_A(reg_a4)->step = 2U;
                        ATTACK_A(reg_a4)->swaps_left -= 1;
                        if ((s8) ATTACK_A(reg_a4)->swaps_left == 0) {
                            ATTACK_A(reg_a4)->step = 4U;
                            ATTACK_A(reg_a4)->wait = 0x10U;
                        }
                    } else {
                        reg_d0.h[0] = 1;
                        boss_attack_start();
                        SPINNER(reg_a0)->pattern = 2U;
                    }
                }
            }
        }
    }
    if (ATTACK_A(reg_a4)->step == 4) {
        ATTACK_A(reg_a4)->wait -= 1;
        if ((s8) ATTACK_A(reg_a4)->wait == 0) {
            ATTACK_A(reg_a4)->step = 5U;
            reg_d0.h[0] = 1;
            boss_attack_start();
            SPINNER(reg_a0)->pattern = 3U;
            reg_d0.h[0] = 2;
            boss_attack_start();
            SPINNER(reg_a0)->pattern = 3U;
        }
    }
    temp_a0_3 = ATTACK_A(reg_a4)->step;
    if (temp_a0_3 == 5) {
        reg_d0.h[0] = 1;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.h[0] = 2;
            boss_attack_running();
            if (cond_flag == 0) {
                ATTACK_A(reg_a4)->running = 0;
                reg_d0.w = 4;
                boss_phase_start();
            }
        }
    }
}

void stage4_boss_mode_attack_b_start(void) {
    ATTACK_B(reg_a4)->step = 0;
    ATTACK_B(reg_a4)->wait = 0x20;
    ATTACK_B(reg_a4)->entry = 0;
    stage4_boss_mode_attack_b();
}

s32 boss_animation_start();
s32 boss_attack_stop();
extern u8 stage4_boss_mode_attack_b_table[];

void stage4_boss_mode_attack_b(void) {
    u16 temp_v1;
    u8 temp_a0;

    if (ATTACK_B(reg_a4)->step == 0) {
        ATTACK_B(reg_a4)->wait -= 1;
        if ((s16) ATTACK_B(reg_a4)->wait == 0) {
            ATTACK_B(reg_a4)->step = 1U;
            ATTACK_B(reg_a4)->wait = 0x20U;
            reg_d0.w = 3;
            boss_attack_start();
        }
    }
    if (ATTACK_B(reg_a4)->step == 1) {
        ATTACK_B(reg_a4)->wait -= 1;
        if ((s16) ATTACK_B(reg_a4)->wait == 0) {
            reg_d0.w = 1;
            boss_animation_start();
            ATTACK_B(reg_a4)->step = 2U;
            ATTACK_B(reg_a4)->wait = 0x10U;
        }
    }
    if ((ATTACK_B(reg_a4)->step == 2) && ((temp_v1 = ATTACK_B(reg_a4)->wait, (temp_v1 == 0)) || (ATTACK_B(reg_a4)->wait = (u16) (temp_v1 - 1), ((s16) ATTACK_B(reg_a4)->wait == 0)))) {
        reg_d0.w = 5;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 5;
            boss_attack_start();
            reg_a1 = stage4_boss_mode_attack_b_table;
            reg_a1 += ATTACK_B(reg_a4)->entry;
            CENTER_HATCH(reg_a0)->sides.h = (u16) *(u16 *)reg_a1;
            CENTER_HATCH(reg_a0)->volleys_left = (u16) *(u16 *)(reg_a1 + 2);
            CENTER_HATCH(reg_a0)->shot.h = (u16) *(u16 *)(reg_a1 + 4);
            ATTACK_B(reg_a4)->entry += 6;
            if (ATTACK_B(reg_a4)->entry == 0x1E) {
                ATTACK_B(reg_a4)->step = 3U;
            }
        }
    }
    temp_a0 = ATTACK_B(reg_a4)->step;
    if (temp_a0 == 3) {
        reg_d0.w = 5;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 3;
            boss_attack_stop();
            ATTACK_B(reg_a4)->step = 4U;
            ATTACK_B(reg_a4)->wait = 0x80U;
            reg_d0.w = 2;
            boss_animation_start();
        }
    }
    if (ATTACK_B(reg_a4)->step == 4) {
        ATTACK_B(reg_a4)->wait -= 1;
        if ((s16) ATTACK_B(reg_a4)->wait == 0) {
            ATTACK_B(reg_a4)->running = 0;
            reg_d0.w = 3;
            boss_phase_start();
        }
    }
}

s32 rng_next();
s32 velocity_from_dir256();

void stage4_boss_pod_drift(s32 arg0, s32 arg1) {
    u16 *p0;
    u8 *p1;

    p0 = (u16 *)(reg_a6 + arg0);
    reg_d0.h[0] = *p0;
    p1 = reg_a6;
    p1 += arg1;
    if (reg_d0.h[0] == 0) goto next_3;
    if ((s16)reg_d0.h[0] >= 0) goto next_1;
    if (*(s16 *)p1 > 0x5A00) goto block_rts;
    reg_d1.b[0] = 0;
    rng_next();
    reg_d0.b[0] = (s8)reg_d0.b[0] >> 1;
    reg_d0.b[0] += 4;
    goto next_5;
next_1:
    if (*(s16 *)p1 < 0x6400) goto block_rts;
    reg_d1.b[0] = 0x80;
    rng_next();
    reg_d0.b[0] = (s8)reg_d0.b[0] >> 1;
    reg_d0.b[0] += 4;
    goto next_5;
next_3:
    rng_next();
    reg_d1.w = 0;
    if ((s8)reg_d0.b[0] >= 0) goto next_4;
    reg_d1.b[0] = 0x80;
next_4:
    rng_next();
    reg_d0.b[0] = (s8)reg_d0.b[0] >> 1;
    reg_d0.b[0] += 4;
next_5:
    reg_d0.h[0] = reg_d0.b[0];
    reg_d1.h[0] = reg_d1.b[0];
    velocity_from_dir256();
    *p0 = reg_d2.h[0];
block_rts:
    return;
}

#ifndef DDPDOJ_PC
s32 boss_movement_start();                            /* extern */
#endif

void stage4_boss_mode_attack_c_start(void) {
    reg_d0.w = 4;
    boss_movement_start();
    ATTACK_C(reg_a4)->steps = 1;
    ATTACK_C(reg_a4)->pod_steps = 0;
    ATTACK_C(reg_a4)->pod_wait = 0;
    ATTACK_C(reg_a4)->pod_accel = 0;
    stage4_boss_mode_attack_c();
}

#ifndef DDPDOJ_PC
s32 boss_movement_start();
#endif
s32 boss_animation_running();

void stage4_boss_mode_attack_c(void) {
    u32 t;

    if (!(ATTACK_C(reg_a4)->steps & 1)) {
        goto next_1;
    }
    if (STAGE4_EXTRA(reg_a6)->right_pod_x_offset == -0x1000) {
        goto next_1;
    }
    ATTACK_C(reg_a4)->pod_accel += 4;
    reg_d0.h[0] = ATTACK_C(reg_a4)->pod_accel;
    STAGE4_EXTRA(reg_a6)->right_pod_x_offset -= reg_d0.h[0];
    STAGE4_EXTRA(reg_a6)->left_pod_x_offset += reg_d0.h[0];
    if ((s16) STAGE4_EXTRA(reg_a6)->left_pod_x_offset < 0xE00) {
        goto next_1;
    }
    STAGE4_EXTRA(reg_a6)->left_pod_x_offset = 0xE00;
    STAGE4_EXTRA(reg_a6)->right_pod_x_offset = 0xF200;
    t = ATTACK_C(reg_a4)->steps;
    if (t & 1) {
        ATTACK_C(reg_a4)->steps = t & 0xFE;
    }
    ATTACK_C(reg_a4)->steps |= 2;
    ATTACK_C(reg_a4)->steps |= 4;
    STAGE4_EXTRA(reg_a6)->right_pod_y_speed = 0;
    STAGE4_EXTRA(reg_a6)->left_pod_y_speed = 0;
    ATTACK_C(reg_a4)->unread_0A = 0;
    stage4_boss_pod_drift(0x198, 0x82);
    stage4_boss_pod_drift(0x19A, 0xA2);
    ATTACK_C(reg_a4)->pod_wait = 0x10;
    ATTACK_C(reg_a4)->wait = 0x10;
    ATTACK_C(reg_a4)->cutter_rounds.h = 0x808;
    ATTACK_C(reg_a4)->cutter_side = 0;
    ATTACK_C(reg_a4)->cutter_timer.h = 4;
next_1:
    if (!(ATTACK_C(reg_a4)->pod_steps & 1)) {
        goto next_2;
    }
    reg_d0.w = 6;
    boss_animation_running();
    if (cond_flag != 0) {
        goto next_2;
    }
    reg_d0.w = 8;
    boss_animation_running();
    if (cond_flag != 0) {
        goto next_2;
    }
    reg_d0.w = 5;
    boss_animation_start();
    reg_d0.w = 7;
    boss_animation_start();
    t = ATTACK_C(reg_a4)->pod_steps;
    if (t & 1) {
        ATTACK_C(reg_a4)->pod_steps = t & 0xFE;
    }
    ATTACK_C(reg_a4)->pod_steps |= 2;
next_2:
    if (!(ATTACK_C(reg_a4)->pod_steps & 2)) {
        goto next_3;
    }
    reg_d0.w = 5;
    boss_animation_running();
    if (cond_flag != 0) {
        goto next_3;
    }
    reg_d0.w = 7;
    boss_animation_running();
    if (cond_flag != 0) {
        goto next_3;
    }
    reg_d0.w = 8;
    boss_attack_start();
    t = ATTACK_C(reg_a4)->pod_steps;
    if (t & 2) {
        ATTACK_C(reg_a4)->pod_steps = t & 0xFD;
    }
next_3:
    if (!(ATTACK_C(reg_a4)->pod_steps & 4)) {
        goto next_4;
    }
    reg_d0.w = 6;
    boss_animation_running();
    if (cond_flag != 0) {
        goto next_4;
    }
    reg_d0.w = 8;
    boss_animation_running();
    if (cond_flag != 0) {
        goto next_4;
    }
    reg_d0.w = 5;
    boss_animation_start();
    reg_d0.w = 7;
    boss_animation_start();
    t = ATTACK_C(reg_a4)->pod_steps;
    if (t & 4) {
        ATTACK_C(reg_a4)->pod_steps = t & 0xFB;
    }
    ATTACK_C(reg_a4)->pod_steps |= 8;
next_4:
    if (!(ATTACK_C(reg_a4)->pod_steps & 8)) {
        goto next_5;
    }
    reg_d0.w = 5;
    boss_animation_running();
    if (cond_flag != 0) {
        goto next_5;
    }
    reg_d0.w = 7;
    boss_animation_running();
    if (cond_flag != 0) {
        goto next_5;
    }
    t = ATTACK_C(reg_a4)->pod_steps;
    if (t & 8) {
        ATTACK_C(reg_a4)->pod_steps = t & 0xF7;
    }
next_5:
    if (!(ATTACK_C(reg_a4)->steps & 2)) {
        goto next_6;
    }
    t = ATTACK_C(reg_a4)->pod_wait;
    if (t != 0) {
        ATTACK_C(reg_a4)->pod_wait = t - 1;
    }
    stage4_boss_pod_drift(0x198, 0x82);
    stage4_boss_pod_drift(0x19A, 0xA2);
    reg_d0.h[0] = STAGE4_EXTRA(reg_a6)->right_pod_y_speed;
    STAGE4_EXTRA(reg_a6)->right_pod_y_offset += reg_d0.h[0];
    reg_d0.h[0] = STAGE4_EXTRA(reg_a6)->left_pod_y_speed;
    STAGE4_EXTRA(reg_a6)->left_pod_y_offset += reg_d0.h[0];
next_6:
    if (!(ATTACK_C(reg_a4)->steps & 4)) {
        goto next_8;
    }
    reg_d0.w = 4;
    boss_animation_running();
    if (cond_flag != 0) {
        goto next_8;
    }
    t = ATTACK_C(reg_a4)->wait;
    if (t == 0) {
        goto next_7;
    }
    ATTACK_C(reg_a4)->wait = t - 1;
    if ((s16) ATTACK_C(reg_a4)->wait != 0) {
        goto next_8;
    }
    reg_d0.w = 8;
    boss_attack_stop();
    reg_d0.w = 6;
    boss_attack_start();
    reg_d0.w = 0xA;
    boss_attack_start();
    ATTACK_C(reg_a4)->pod_steps |= 4;
next_7:
    reg_d0.w = 0xA;
    boss_attack_running();
    if (cond_flag != 0) {
        goto next_8;
    }
    reg_d0.w = 6;
    boss_attack_stop();
    reg_d0.w = 7;
    boss_attack_stop();
    reg_d0.w = 6;
    boss_animation_start();
    reg_d0.w = 8;
    boss_animation_start();
    t = ATTACK_C(reg_a4)->steps;
    if (t & 4) {
        ATTACK_C(reg_a4)->steps = t & 0xFB;
    }
    ATTACK_C(reg_a4)->steps |= 8;
    ATTACK_C(reg_a4)->wait = 0x40;
next_8:
    if (!(ATTACK_C(reg_a4)->steps & 8)) {
        goto next_9;
    }
    ATTACK_C(reg_a4)->wait -= 1;
    if ((s16) ATTACK_C(reg_a4)->wait != 0) {
        goto next_9;
    }
    ATTACK_C(reg_a4)->pod_steps |= 1;
    reg_d0.w = 3;
    boss_animation_start();
    reg_d0.w = 7;
    boss_movement_start();
    t = ATTACK_C(reg_a4)->steps;
    if (t & 8) {
        ATTACK_C(reg_a4)->steps = t & 0xF7;
    }
    ATTACK_C(reg_a4)->steps |= 0x10;
    ATTACK_C(reg_a4)->cutter_rounds.t.count = ATTACK_C(reg_a4)->cutter_rounds.t.reload;
    t = ATTACK_C(reg_a4)->cutter_rounds.t.reload;
    if (t == 8) {
        goto next_9;
    }
    ATTACK_C(reg_a4)->cutter_rounds.t.reload = t + 1;
next_9:
    if (!(ATTACK_C(reg_a4)->steps & 0x10)) {
        goto next_10;
    }
    reg_d0.w = 3;
    boss_animation_running();
    if (cond_flag != 0) {
        goto next_10;
    }
    reg_d0.w = 9;
    boss_attack_running();
    if (cond_flag != 0) {
        goto next_10;
    }
    reg_tmp.b[0] = ATTACK_C(reg_a4)->cutter_timer.t.count;
    ATTACK_C(reg_a4)->cutter_timer.t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_10;
    }
    ATTACK_C(reg_a4)->cutter_timer.t.count = ATTACK_C(reg_a4)->cutter_timer.t.reload;
    reg_d0.w = 9;
    boss_attack_start();
    CUTTERS(reg_a0)->unread_06 = ATTACK_C(reg_a4)->cutter_side;
    ATTACK_C(reg_a4)->cutter_side += 1;
    ATTACK_C(reg_a4)->cutter_side &= 1;
    t = ATTACK_C(reg_a4)->steps;
    if (t & 0x10) {
        ATTACK_C(reg_a4)->steps = t & 0xEF;
    }
    ATTACK_C(reg_a4)->steps |= 0x20;
    ATTACK_C(reg_a4)->wait = 0xE0;
next_10:
    if (!(ATTACK_C(reg_a4)->steps & 0x20)) {
        return;
    }
    reg_d0.w = 9;
    boss_attack_running();
    if (cond_flag != 0) {
        return;
    }
    ATTACK_C(reg_a4)->wait -= 1;
    if ((s16) ATTACK_C(reg_a4)->wait != 0) {
        return;
    }
    reg_d0.w = 4;
    boss_movement_start();
    reg_d0.w = 4;
    boss_animation_start();
    t = ATTACK_C(reg_a4)->steps;
    if (t & 0x20) {
        ATTACK_C(reg_a4)->steps = t & 0xDF;
    }
    ATTACK_C(reg_a4)->steps |= 4;
    ATTACK_C(reg_a4)->wait = 0x40;
}

s32 boss_animation_stop();
extern u16 g_enemy_signal_e;
extern u16 g_enemy_signal_d;
extern u16 g_enemy_signal_c;
extern u16 g_enemy_signal_b;
extern u16 g_enemy_signal_a;
extern u16 g_loop;

void stage4_boss_mode_rage_start() {
    g_enemy_signal_e = 2;
    g_enemy_signal_a = 0xFFFF;
    reg_d0.w = 8;
    g_enemy_signal_b = 0xFFFF;
    g_enemy_signal_c = 0;
    boss_movement_start();
    RAGE(reg_a4)->step = 0;
    reg_d0.w = 4;
    boss_animation_stop();
    reg_d0.w = 3;
    boss_animation_start();
    reg_d0.w = 6;
    boss_attack_stop();
    reg_d0.w = 7;
    boss_attack_stop();
    reg_d0.w = 8;
    boss_attack_stop();
    reg_d0.w = 9;
    boss_attack_stop();
    reg_d0.w = 0xA;
    boss_attack_stop();
    RAGE(reg_a4)->wait = 0x180;
    RAGE(reg_a4)->turn = 0;
    RAGE(reg_a4)->attack_wait = 0x100;
    RAGE(reg_a4)->side_shots = 1;
    if (g_loop != 0) {
        RAGE(reg_a4)->side_shots = 3;
    }
    RAGE(reg_a4)->wing_rounds = 8;
    RAGE(reg_a4)->other_0E = 8;
    g_enemy_signal_d = 0;
    stage4_boss_mode_rage();
}

s32 rng_next_unsigned();

void stage4_boss_mode_rage() {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 var_a0;

    if (RAGE(reg_a4)->step == 0) {
        reg_d0.w = 3;
        boss_animation_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xB;
            boss_attack_start();
            RAGE(reg_a4)->step = 1U;
        }
    }
    var_a0 = 1;
    if (RAGE(reg_a4)->step == 1) {
        g_enemy_signal_d = 0;
        RAGE(reg_a4)->wait -= 1;
        if ((s16) RAGE(reg_a4)->wait == 0) {
            g_enemy_signal_d = 1;
            rng_next_unsigned();
            reg_d0.h[0] &= 0x7F;
            reg_d0.h[0] += 0x1C0;
            var_a0 = reg_d0.h[0];
            RAGE(reg_a4)->wait = var_a0;
        }
    }
    if (RAGE(reg_a4)->turn == 0) {
        reg_d0.w = 0xD;
        boss_attack_running();
        if (cond_flag == 0) {
            RAGE(reg_a4)->attack_wait -= 1;
            if ((s16) RAGE(reg_a4)->attack_wait == 0) {
                reg_d0.w = 0xE;
                boss_attack_start();
                RAGE_WINGS(reg_a0)->rounds_left = (u16) RAGE(reg_a4)->wing_rounds;
                RAGE(reg_a4)->turn = 1U;
                RAGE(reg_a4)->attack_wait = 0x30U;
            }
        }
    }
    temp_a0 = RAGE(reg_a4)->turn;
    if (temp_a0 == 1) {
        reg_d0.w = 0xE;
        boss_attack_running();
        if (cond_flag == 0) {
            RAGE(reg_a4)->attack_wait -= 1;
            if ((s16) RAGE(reg_a4)->attack_wait == 0) {
                RAGE(reg_a4)->turn = 0U;
                reg_d0.w = 0xD;
                boss_attack_start();
                BOTH_SIDES(reg_a0)->burst_shots.h = (u16) RAGE(reg_a4)->side_shots;
                BOTH_SIDES(reg_a0)->unread_12 = (u16) RAGE(reg_a4)->other_0E;
                RAGE(reg_a4)->attack_wait = 0x40U;
                reg_d0.h[0] = 5;
                if (g_loop == 0) {
                    reg_d0.h[0] = 3;
                }
                temp_a0_2 = RAGE(reg_a4)->side_shots;
                if (temp_a0_2 != reg_d0.h[0]) {
                    RAGE(reg_a4)->side_shots = (u16) (temp_a0_2 + 1);
                }
                temp_a0_3 = RAGE(reg_a4)->other_0E;
                if (temp_a0_3 != 0x10) {
                    RAGE(reg_a4)->other_0E = (u16) (temp_a0_3 + 1);
                }
            }
        }
    }
}

u8 stage4_boss_mode_attack_b_table[32] = {
    0x00, 0x01, 0x04, 0x00, 0x02, 0x10, 0x00, 0x02, 0x08, 0x00, 0x02, 0x0C, 0x00, 0x01, 0x0C, 0x00,
    0x02, 0x08, 0x00, 0x02, 0x10, 0x00, 0x02, 0x04, 0x00, 0x03, 0x20, 0x00, 0x02, 0x40, 0x00, 0x00,
};

/* Each volley takes two adjacent words. The second uses target_y for d7. */
Stage4VolleyData stage4_form2_volley[1] = { { { 1, 2 }, 0x6000, 0x1C00 } };

#ifdef DDPDOJ_PC
#include <stddef.h>
_Static_assert(offsetof(Stage4VolleyData, target_y) == 4, "second volley parameter offset");
_Static_assert(sizeof(Stage4VolleyData) == 8, "volley and target size");
#endif
