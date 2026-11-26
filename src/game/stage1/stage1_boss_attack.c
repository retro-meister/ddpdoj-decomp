#include "common.h"
#include "entity.h"
#include "stage1_boss.h"
#include "enemy_kinds.h"

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

u16 stage1_boss_rage_spread_steps[] = {
    0x000B, 0x000A, 0x0009, 0x0008, 0x0007, 0x0006, 0x0005, 0x0004,
};

u16 stage1_boss_rage_shots[] = {
    0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x000A,
};

u16 stage1_boss_port_offsets[] = {
    0xFB80, 0xFC80, 0xFB80, 0x0380, 0xF580, 0xFDC0, 0xF580, 0x0240,
};

u16 stage1_boss_turret_offsets[] = {
    0x09C0, 0x0400, 0x09C0, 0xFC40, 0x0F40, 0x0600, 0x0F40, 0xF9C0,
};

u16 stage1_boss_turret_speeds[] = {
    0xFFF9, 0xFFF9, 0xFFFA, 0xFFFB, 0xFFFC, 0xFFFD, 0x0003, 0x0007,
};

u16 stage1_boss_gatling_muzzles[] = {
    0xFC40, 0x0540, 0xFC00, 0x0480, 0xFB80, 0x0400, 0xFB00, 0x0300,
    0xFAC0, 0x0280, 0xFAC0, 0x0180, 0xFA80, 0x00C0, 0xFA80, 0x0000,
    0xFA80, 0xFF40, 0xFAC0, 0xFE80, 0xFAC0, 0xFD80, 0xFB00, 0xFD00,
    0xFB80, 0xFC00, 0xFC00, 0xFB80, 0xFC40, 0xFAC0,
};

u16 stage1_boss_shell_burst_speed_levels[] = {
    0xFFFC, 0xFFFC, 0xFFFC, 0xFFFD, 0xFFFF, 0x0001, 0x0003, 0x0005,
};

u16 stage1_boss_shell_spare_levels[] = {
    0x0003, 0x0005, 0x0007, 0x000A, 0x000A, 0x000A, 0x000A, 0x000A,
};

u16 stage1_boss_ports_rapid_levels[] = {
    0x000A, 0x0005, 0x0008, 0x0006, 0x0006, 0x0007, 0x0004, 0x0008,
    0x0004, 0x0008, 0x0004, 0x0007, 0x0004, 0x0007, 0x0004, 0x0009,
};

u16 stage1_boss_ports_aimed_levels[] = {
    0x3010, 0x0002, 0x300C, 0x0003, 0x300A, 0x0005, 0x3008, 0x0006,
    0x3008, 0x0006, 0x3008, 0x0007, 0x3007, 0x0008, 0x3006, 0x0009,
};

u16 stage1_boss_front_gun_shots[] = {
    0x0001, 0x0002, 0x0003, 0x0004, 0x0004, 0x0005, 0x0005, 0x0006,
};

u16 stage1_boss_front_gun_offsets[] = {
    0xEB40, 0xFC00, 0xEB40, 0x0400, 0xE8C0, 0xFC00, 0xE8C0, 0x0400,
};

u16 stage1_boss_front_spread_waits[] = {
    0x0030, 0x0020, 0x0018, 0x0010, 0x0010, 0x000E, 0x000E, 0x000C,
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


void stage1_boss_fire_clear(void) {
    RAGE(reg_a4)->running = 0;
}


s32 boss_level_get_from_58();
s32 enemy_switch_target_player();
s32 rng_next();
s32 direction256_to_target_player();

void stage1_boss_fire_body_ports_rage_start(void) {
    enemy_switch_target_player();
    RAGE(reg_a4)->shot.sh = 0x1001;
    RAGE(reg_a4)->speed = 0;
    RAGE(reg_a4)->spread = 8;
    RAGE(reg_a4)->direction = 0x80U;
    direction256_to_target_player();
    if (cond_flag == 0) {
        rng_next();
        reg_d1.b[0] += reg_d0.b[0];
        RAGE(reg_a4)->direction = (u8) reg_d1.b[0];
    }
    boss_level_get_from_58();
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)(stage1_boss_rage_spread_steps);
    RAGE(reg_a4)->spread_step = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(stage1_boss_rage_shots);
    RAGE(reg_a4)->shots_left = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
}

s32 bullet_fire256_2way();

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
        reg_d3.h[1] = stage1_boss_port_offsets[4];
        reg_d3.h[0] = stage1_boss_port_offsets[5];
        reg_d4.w = 0;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] += 2;
        bullet_fire256_2way();
        reg_d3.h[1] = stage1_boss_port_offsets[6];
        reg_d3.h[0] = stage1_boss_port_offsets[7];
        reg_d1.h[0] -= 4;
        bullet_fire256_2way();
        reg_d1.h[0] += 2;
        reg_d1.b[0] += reg_d6.b[0];
        reg_d3.h[1] = stage1_boss_port_offsets[0];
        reg_d3.h[0] = stage1_boss_port_offsets[1];
        bullet_fire256_2way();
        reg_d1.b[0] -= reg_d6.b[0];
        reg_d3.h[1] = stage1_boss_port_offsets[2];
        reg_d3.h[0] = stage1_boss_port_offsets[3];
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

void stage1_boss_fire_turrets_scatter_start(void) {
    u32 temp_a0;
    TURRETS(reg_a4)->swing = 0;
    TURRETS(reg_a4)->aimed = 0;
    boss_level_get_from_58();
    reg_a0 = (u8 *)(stage1_boss_turret_speeds);
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
    reg_d0.b[0] = STAGE1_GUNS(reg_a6)->gun0_direction;
    direction_turn_toward();
    STAGE1_GUNS(reg_a6)->gun0_direction = (u8) reg_d1.b[0];
    reg_d1.b[0] = TURRETS(reg_a4)->start_angle[0];
    reg_d0.b[0] = STAGE1_GUNS(reg_a6)->gun1_direction;
    direction_turn_toward();
    STAGE1_GUNS(reg_a6)->gun1_direction = (u8) reg_d1.b[0];
    reg_d1.b[0] = TURRETS(reg_a4)->start_angle[3];
    reg_d0.b[0] = STAGE1_GUNS(reg_a6)->gun2_direction;
    direction_turn_toward();
    STAGE1_GUNS(reg_a6)->gun2_direction = (u8) reg_d1.b[0];
    reg_d1.b[0] = TURRETS(reg_a4)->start_angle[2];
    reg_d0.b[0] = STAGE1_GUNS(reg_a6)->gun3_direction;
    direction_turn_toward();
    STAGE1_GUNS(reg_a6)->gun3_direction = (u8) reg_d1.b[0];
    reg_d0.b[0] = TURRETS(reg_a4)->start_angle[1];
    if (STAGE1_GUNS(reg_a6)->gun0_direction == reg_d0.b[0]) {
        reg_d0.b[0] = TURRETS(reg_a4)->start_angle[0];
        if (STAGE1_GUNS(reg_a6)->gun1_direction == reg_d0.b[0]) {
            reg_d0.b[0] = TURRETS(reg_a4)->start_angle[3];
            if (STAGE1_GUNS(reg_a6)->gun2_direction == reg_d0.b[0]) {
                reg_d0.b[0] = TURRETS(reg_a4)->start_angle[2];
                if (STAGE1_GUNS(reg_a6)->gun3_direction == reg_d0.b[0]) {
                    TURRETS(reg_a4)->aimed = 1U;
                }
            }
        }
    }
}
extern u16 g_bullets_blocked;

void stage1_boss_fire_turrets_sweep(void) {
    u16 temp_a0;
    u16 temp_a1;

    if (g_bullets_blocked == 0) {
        if (!(TURRETS(reg_a4)->swing & 1)) {
            STAGE1_GUNS(reg_a6)->gun0_direction += 1;
            if ((s8) STAGE1_GUNS(reg_a6)->gun0_direction >= 0x30) {
                TURRETS(reg_a4)->swing |= 1;
            }
        } else {
            STAGE1_GUNS(reg_a6)->gun0_direction -= 1;
            if ((s8) STAGE1_GUNS(reg_a6)->gun0_direction < 0x11) {
                TURRETS(reg_a4)->swing &= 0xE;
            }
        }
        if (!(TURRETS(reg_a4)->swing & 2)) {
            STAGE1_GUNS(reg_a6)->gun1_direction += 1;
            if ((s8) STAGE1_GUNS(reg_a6)->gun1_direction >= 0x30) {
                TURRETS(reg_a4)->swing |= 2;
            }
        } else {
            STAGE1_GUNS(reg_a6)->gun1_direction -= 1;
            if ((s8) STAGE1_GUNS(reg_a6)->gun1_direction < 0x11) {
                TURRETS(reg_a4)->swing &= 0xD;
            }
        }
        if (!(TURRETS(reg_a4)->swing & 4)) {
            STAGE1_GUNS(reg_a6)->gun2_direction += 1;
            if ((s8) STAGE1_GUNS(reg_a6)->gun2_direction >= 0x30) {
                TURRETS(reg_a4)->swing |= 4;
            }
        } else {
            STAGE1_GUNS(reg_a6)->gun2_direction -= 1;
            if ((s8) STAGE1_GUNS(reg_a6)->gun2_direction < 0x11) {
                TURRETS(reg_a4)->swing &= 0xB;
            }
        }
        if (!(TURRETS(reg_a4)->swing & 8)) {
            STAGE1_GUNS(reg_a6)->gun3_direction += 1;
            if ((s8) STAGE1_GUNS(reg_a6)->gun3_direction >= 0x30) {
                TURRETS(reg_a4)->swing |= 8;
            }
        } else {
            STAGE1_GUNS(reg_a6)->gun3_direction -= 1;
            if ((s8) STAGE1_GUNS(reg_a6)->gun3_direction < 0x11) {
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
            reg_d3.h[1] = stage1_boss_turret_offsets[0];
            reg_d3.h[0] = stage1_boss_turret_offsets[1];
            reg_d1.w = 0;
            reg_d1.b[0] = STAGE1_GUNS(reg_a6)->gun0_direction;
            bullet_fire_3way_entry();
            reg_d3.h[1] = stage1_boss_turret_offsets[2];
            reg_d3.h[0] = stage1_boss_turret_offsets[3];
            reg_d1.b[0] = STAGE1_GUNS(reg_a6)->gun1_direction;
            bullet_fire_3way_entry();
            reg_d3.h[1] = stage1_boss_turret_offsets[4];
            reg_d3.h[0] = stage1_boss_turret_offsets[5];
            reg_d1.b[0] = STAGE1_GUNS(reg_a6)->gun2_direction;
            bullet_fire_3way_entry();
            reg_d3.h[1] = stage1_boss_turret_offsets[6];
            reg_d3.h[0] = stage1_boss_turret_offsets[7];
            reg_d1.b[0] = STAGE1_GUNS(reg_a6)->gun3_direction;
            bullet_fire_3way_entry();
            TURRETS(reg_a4)->volleys_left -= 1;
            if ((s8) TURRETS(reg_a4)->volleys_left == 0) {
                TURRETS(reg_a4)->running = 0;
            }
        }
    }
}

void stage1_boss_fire_gatling_a_start(void) {
    GATLING(reg_a4)->aim_wait.h = 0;
    GATLING(reg_a4)->step = 0;
    GATLING(reg_a4)->target_angle = 0x20;
    GATLING(reg_a4)->turn.h = 0x101;
    GATLING(reg_a4)->shot.h = 4;
    GATLING(reg_a4)->shots_left = 0x10;
    GATLING(reg_a4)->speed = 0xFFFC;
}

s32 bullet_fire256_fixed();
s32 rng_next_bit_d5();
s32 aim_at_player();
s32 direction_turn_toward();

void stage1_boss_fire_gatling_a(void) {
    u16 temp_a0_2;
    u8 temp_a0;

    if (GATLING(reg_a4)->step == 0) {
        reg_tmp.b[0] = GATLING(reg_a4)->aim_wait.t.count;
        GATLING(reg_a4)->aim_wait.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            GATLING(reg_a4)->aim_wait.t.count = (u8) GATLING(reg_a4)->aim_wait.t.reload;
            GATLING(reg_a4)->step = 1U;
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
                GATLING(reg_a4)->target_angle = (u8) reg_d1.b[0];
            }
        }
    }
    temp_a0 = GATLING(reg_a4)->step;
    if (temp_a0 == 1) {
        reg_tmp.b[0] = GATLING(reg_a4)->turn.t.count;
        GATLING(reg_a4)->turn.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            GATLING(reg_a4)->turn.t.count = (u8) GATLING(reg_a4)->turn.t.reload;
            reg_d0.w = 0;
            reg_d1.w = 0;
            reg_d1.b[0] = GATLING(reg_a4)->target_angle;
            reg_d0.h[0] = ENTITY(reg_a6)[5].sprite.h;
            reg_d0.h[0] += 0x20;
            direction_turn_toward();
            reg_d0.h[0] = reg_d1.h[0];
            reg_d0.h[0] = (u16) reg_d0.b[0];
            reg_d0.h[0] -= 0x20;
            ENTITY(reg_a6)[5].sprite.h = (u16) reg_d0.h[0];
            if (GATLING(reg_a4)->target_angle == reg_d1.b[0]) {
                GATLING(reg_a4)->step = 2U;
            }
        }
    }
    if (GATLING(reg_a4)->step == 2) {
        reg_tmp.b[0] = GATLING(reg_a4)->shot.t.count;
        GATLING(reg_a4)->shot.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            GATLING(reg_a4)->shot.t.count = (u8) GATLING(reg_a4)->shot.t.reload;
            reg_d0.h[0] = GATLING(reg_a4)->speed;
            reg_d0.h[0] += 0x14;
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 7;
            rng_next_bit_d5();
            reg_d5.b[0] -= 1;
            reg_d5.b[0] += GATLING(reg_a4)->target_angle;
            reg_a0 = (u8 *)(stage1_boss_gatling_muzzles);
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
            GATLING(reg_a4)->speed += 2;
            GATLING(reg_a4)->shots_left -= 1;
            if (GATLING(reg_a4)->shots_left == 0) {
                GATLING(reg_a4)->running = 0;
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
    boss_level_get_from_58();
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
    boss_level_get_from_58();
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
    GATLING(reg_a4)->step = 0;
    GATLING(reg_a4)->target_angle = 0x20;
    GATLING(reg_a4)->turn.h = 0x202;
    GATLING(reg_a4)->shot.h = 8;
    GATLING(reg_a4)->shots_left = 6;
    GATLING(reg_a4)->speed = 0xFFF8;
}

void stage1_boss_fire_gatling_b(void) {
    u16 temp_a0;

    if (GATLING(reg_a4)->step == 0) {
        GATLING(reg_a4)->step = 1U;
    }
    if (GATLING(reg_a4)->step == 1) {
        GATLING(reg_a4)->step = 2U;
    }
    if (GATLING(reg_a4)->step == 2) {
        reg_tmp.b[0] = GATLING(reg_a4)->shot.t.count;
        GATLING(reg_a4)->shot.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            GATLING(reg_a4)->shot.t.count = (u8) GATLING(reg_a4)->shot.t.reload;
            reg_d0.h[0] = GATLING(reg_a4)->speed;
            reg_d0.h[0] += 0x14;
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 7;
            rng_next_bit_d5();
            reg_d5.b[0] -= 1;
            reg_d5.b[0] += GATLING(reg_a4)->target_angle;
            reg_a0 = (u8 *)(stage1_boss_gatling_muzzles);
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
            GATLING(reg_a4)->speed += 1;
            GATLING(reg_a4)->shots_left -= 1;
            if (GATLING(reg_a4)->shots_left == 0) {
                GATLING(reg_a4)->running = 0;
            }
        }
    }
}

s32 rng_next_unsigned();

void stage1_boss_fire_main_guns_burst_start(void) {
    boss_level_get_from_58();
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)(stage1_boss_shell_spare_levels);
    BURST(reg_a4)->shell_spare = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(stage1_boss_shell_burst_speed_levels);
    BURST(reg_a4)->shell_burst_speed = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    BURST(reg_a4)->shot.sh = 0x18;
    BURST(reg_a4)->side = 0U;
    BURST(reg_a4)->volleys_left = 2;
    rng_next_unsigned();
    reg_d0.h[0] &= 1;
    BURST(reg_a4)->side = (u16) reg_d0.h[0];
    stage1_boss_fire_main_guns_burst();
}

s32 spawn_request_add();

void stage1_boss_fire_main_guns_burst(void) {
    reg_tmp.b[0] = BURST(reg_a4)->shot.t.count;
    BURST(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        return;
    }
    BURST(reg_a4)->shot.t.count = BURST(reg_a4)->shot.t.reload;
    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        goto skip_1;
    }
    if (BURST(reg_a4)->side != 0) {
        goto skip_1;
    }
    reg_d0.w = ENEMY_STAGE1_BOSS_SHELL;
    spawn_request_add();
    reg_d0.h[1] = ENTITY(reg_a6)[1].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[1].x.h;
    reg_d0.w += 0xF6C00140;
    STAGE1_SHELL(reg_a0)->at_start.y = reg_d0.h[1];
    STAGE1_SHELL(reg_a0)->at_start.x = reg_d0.h[0];
    STAGE1_SHELL(reg_a0)->at_start.move = 0x2020;
    STAGE1_SHELL(reg_a0)->at_start.burst_speed = BURST(reg_a4)->shell_burst_speed;
    STAGE1_SHELL(reg_a0)->at_start.spare = BURST(reg_a4)->shell_spare;
    if (g_loop == 0) {
        goto skip_1;
    }
    reg_d0.w = ENEMY_STAGE1_BOSS_SHELL;
    spawn_request_add();
    reg_d0.h[1] = ENTITY(reg_a6)[1].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[1].x.h;
    reg_d0.w += 0xF6C00140;
    STAGE1_SHELL(reg_a0)->at_start.y = reg_d0.h[1];
    STAGE1_SHELL(reg_a0)->at_start.x = reg_d0.h[0];
    STAGE1_SHELL(reg_a0)->at_start.move = 0x1A28;
    STAGE1_SHELL(reg_a0)->at_start.burst_speed = BURST(reg_a4)->shell_burst_speed;
    STAGE1_SHELL(reg_a0)->at_start.spare = BURST(reg_a4)->shell_spare;
skip_1:
    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        goto skip_2;
    }
    if (BURST(reg_a4)->side == 0) {
        goto skip_2;
    }
    reg_d0.w = ENEMY_STAGE1_BOSS_SHELL;
    spawn_request_add();
    reg_d0.h[1] = ENTITY(reg_a6)[3].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[3].x.h;
    reg_d0.w += 0xF6BFFEC0;
    STAGE1_SHELL(reg_a0)->at_start.y = reg_d0.h[1];
    STAGE1_SHELL(reg_a0)->at_start.x = reg_d0.h[0];
    STAGE1_SHELL(reg_a0)->at_start.move = 0x2020;
    STAGE1_SHELL(reg_a0)->at_start.burst_speed = BURST(reg_a4)->shell_burst_speed;
    STAGE1_SHELL(reg_a0)->at_start.spare = BURST(reg_a4)->shell_spare;
    if (g_loop == 0) {
        goto skip_2;
    }
    reg_d0.w = ENEMY_STAGE1_BOSS_SHELL;
    spawn_request_add();
    reg_d0.h[1] = ENTITY(reg_a6)[3].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[3].x.h;
    reg_d0.w += 0xF6BFFEC0;
    STAGE1_SHELL(reg_a0)->at_start.y = reg_d0.h[1];
    STAGE1_SHELL(reg_a0)->at_start.x = reg_d0.h[0];
    STAGE1_SHELL(reg_a0)->at_start.move = 0x1A18;
    STAGE1_SHELL(reg_a0)->at_start.burst_speed = BURST(reg_a4)->shell_burst_speed;
    STAGE1_SHELL(reg_a0)->at_start.spare = BURST(reg_a4)->shell_spare;
skip_2:
    BURST(reg_a4)->shell_burst_speed += 1;
    BURST(reg_a4)->side += 1;
    BURST(reg_a4)->side &= 1;
    BURST(reg_a4)->volleys_left -= 1;
    if (BURST(reg_a4)->volleys_left == 0) {
        BURST(reg_a4)->running = 0;
    }
}

void stage1_boss_fire_body_ports_rapid_start(void) {
    boss_level_get_from_58();
    reg_a0 = ((u8 *)stage1_boss_ports_rapid_levels);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    PORTS(reg_a4)->shot.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    PORTS(reg_a4)->shots_left = *(u16 *)reg_a0;
    stage1_boss_fire_body_ports_rapid();
}

s32 bullet_fire256();

void stage1_boss_fire_body_ports_rapid() {
    u16 temp_a2;

    reg_tmp.b[0] = PORTS(reg_a4)->shot.t.count;
    PORTS(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        PORTS(reg_a4)->shot.t.count = (u8) PORTS(reg_a4)->shot.t.reload;
        reg_d1.w = 0;
        reg_d1.b[0] = 0x80;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        temp_a2 = ENTITY(reg_a6)->x.h;
        reg_d2.h[0] = temp_a2;
        reg_d0.w = 0x80009;
        reg_d1.b[0] = 0x60;
        reg_d3.h[1] = stage1_boss_port_offsets[2];
        reg_d3.h[0] = stage1_boss_port_offsets[3];
        reg_d4.w = 0;
        bullet_fire256();
        reg_d1.b[0] = 0x70;
        reg_d3.h[1] = stage1_boss_port_offsets[6];
        reg_d3.h[0] = stage1_boss_port_offsets[7];
        bullet_fire256();
        reg_d1.b[0] = 0xA0;
        reg_d3.h[1] = stage1_boss_port_offsets[0];
        reg_d3.h[0] = stage1_boss_port_offsets[1];
        bullet_fire256();
        reg_d1.b[0] = 0x90;
        reg_d3.h[1] = stage1_boss_port_offsets[4];
        reg_d3.h[0] = stage1_boss_port_offsets[5];
        bullet_fire256();
        PORTS(reg_a4)->shots_left -= 1;
        if (PORTS(reg_a4)->shots_left == 0) {
            PORTS(reg_a4)->running = 0;
        }
    }
}

void stage1_boss_fire_body_ports_aimed_start(void) {
    u16 temp_a0;

    boss_level_get_from_58();
    reg_a0 = (u8 *)(stage1_boss_ports_aimed_levels);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    PORTS(reg_a4)->shot.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    temp_a0 = *(u16 *)reg_a0;
    PORTS(reg_a4)->shots_left = temp_a0;
    PORTS(reg_a4)->direction = 0x20;
    stage1_boss_fire_body_ports_aimed();
}

void stage1_boss_fire_body_ports_aimed() {
    u16 temp_a2;
    u8 temp_a0;

    reg_tmp.b[0] = PORTS(reg_a4)->shot.t.count;
    PORTS(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        PORTS(reg_a4)->shot.t.count = (u8) PORTS(reg_a4)->shot.t.reload;
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        aim256_at_player();
        if (cond_flag == 0) {
            PORTS(reg_a4)->direction = (u8) reg_d1.b[0];
        }
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        temp_a2 = ENTITY(reg_a6)->x.h;
        reg_d2.h[0] = temp_a2;
        reg_d0.w = 0x20009;
        reg_d4.w = 0;
        reg_d1.w = 0;
        temp_a0 = PORTS(reg_a4)->direction;
        reg_d1.b[0] = temp_a0;
        reg_d3.h[1] = stage1_boss_port_offsets[2];
        reg_d3.h[0] = stage1_boss_port_offsets[3];
        bullet_fire256();
        reg_d3.h[1] = stage1_boss_port_offsets[6];
        reg_d3.h[0] = stage1_boss_port_offsets[7];
        bullet_fire256();
        reg_d3.h[1] = stage1_boss_port_offsets[0];
        reg_d3.h[0] = stage1_boss_port_offsets[1];
        bullet_fire256();
        reg_d3.h[1] = stage1_boss_port_offsets[4];
        reg_d3.h[0] = stage1_boss_port_offsets[5];
        bullet_fire256();
        PORTS(reg_a4)->shots_left -= 1;
        if (PORTS(reg_a4)->shots_left == 0) {
            PORTS(reg_a4)->running = 0;
        }
    }
}

void stage1_boss_fire_front_guns_rage_start(void) {
    FRONT_GUNS(reg_a4)->shot.sh = 8;
    boss_level_get_from_58();
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)stage1_boss_front_gun_shots;
    FRONT_GUNS(reg_a4)->shots_left = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)((u16 *)reg_a0) + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    stage1_boss_fire_front_guns_rage();
}

void stage1_boss_fire_front_guns_rage(void) {
    u16 temp_a2;

    reg_tmp.b[0] = FRONT_GUNS(reg_a4)->shot.t.count;
    FRONT_GUNS(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        FRONT_GUNS(reg_a4)->shot.t.count = (u8) FRONT_GUNS(reg_a4)->shot.t.reload;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        temp_a2 = ENTITY(reg_a6)->x.h;
        reg_d1.w = 0;
        reg_d2.h[0] = temp_a2;
        reg_d0.w = 0x80013;
        reg_d1.b[0] = 0x80;
        reg_d3.h[1] = stage1_boss_front_gun_offsets[2];
        reg_d3.h[0] = stage1_boss_front_gun_offsets[3];
        reg_d4.w = 0;
        bullet_fire256_fixed();
        reg_d3.h[1] = stage1_boss_front_gun_offsets[6];
        reg_d3.h[0] = stage1_boss_front_gun_offsets[7];
        bullet_fire256_fixed();
        reg_d3.h[1] = stage1_boss_front_gun_offsets[0];
        reg_d3.h[0] = stage1_boss_front_gun_offsets[1];
        bullet_fire256_fixed();
        reg_d3.h[1] = stage1_boss_front_gun_offsets[4];
        reg_d3.h[0] = stage1_boss_front_gun_offsets[5];
        bullet_fire256_fixed();
        FRONT_GUNS(reg_a4)->shots_left -= 1;
        if (FRONT_GUNS(reg_a4)->shots_left == 0) {
            FRONT_GUNS(reg_a4)->running = 0;
        }
    }
}

void stage1_boss_fire_front_guns_rage_spread_start(void) {
    boss_level_get_from_58();
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)stage1_boss_front_spread_waits;
    FRONT_GUNS(reg_a4)->shot.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)((u16 *)reg_a0) + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    FRONT_GUNS(reg_a4)->shots_left = 2;
    stage1_boss_fire_front_guns_rage_spread();
}

void stage1_boss_fire_front_guns_rage_spread(void) {
    u16 temp_a2;

    reg_tmp.b[0] = FRONT_GUNS(reg_a4)->shot.t.count;
    FRONT_GUNS(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        FRONT_GUNS(reg_a4)->shot.t.count = (u8) FRONT_GUNS(reg_a4)->shot.t.reload;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        temp_a2 = ENTITY(reg_a6)->x.h;
        reg_d1.w = 0;
        reg_d2.h[0] = temp_a2;
        reg_d0.w = 0x13;
        reg_d1.b[0] = 0x80;
        reg_d3.h[1] = stage1_boss_front_gun_offsets[0];
        reg_d3.h[0] = stage1_boss_front_gun_offsets[1];
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
        reg_d3.h[1] = stage1_boss_front_gun_offsets[2];
        reg_d3.h[0] = stage1_boss_front_gun_offsets[3];
        bullet_fire256_2way();
        reg_d1.b[0] += 0xC;
        bullet_fire256_2way();
        reg_d1.b[0] += 0xC;
        bullet_fire256_2way();
        reg_d1.b[0] -= 0x24;
        bullet_fire256_2way();
        reg_d1.b[0] -= 0xC;
        bullet_fire256_2way();
        FRONT_GUNS(reg_a4)->shots_left -= 1;
        if (FRONT_GUNS(reg_a4)->shots_left == 0) {
            FRONT_GUNS(reg_a4)->running = 0;
        }
    }
}

void stage1_boss_fire_gatling_c_start(void) {
    GATLING_C(reg_a4)->unused_08 = 8;
    GATLING_C(reg_a4)->spare_0A = 0;
    GATLING_C(reg_a4)->spare_0C = 0;
    reg_d0.h[0] = ENTITY(reg_a6)[5].sprite.h;
    reg_d0.h[0] += 0x20;
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += reg_d0.b[0];
    GATLING_C(reg_a4)->direction = (u8) reg_d0.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)[5].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[5].x.h;
    aim256_at_player();
    if (cond_flag == 0) {
        GATLING_C(reg_a4)->direction = (u8) reg_d1.b[0];
    }
    enemy_switch_target_player();
}

s32 rng_next_word();
extern u16 g_direction64_offsets_432[];

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
        reg_a2 = (u8 *)(stage1_boss_gatling_muzzles);
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
        reg_a0 = (u8 *)(g_direction64_offsets_432);
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
            GATLING_C(reg_a4)->jitter = (u16) reg_d0.h[0];
            reg_d0.w = 0;
            reg_d0.b[0] = GATLING_C(reg_a4)->speed;
            reg_d0.h[0] -= 0x14;
            temp_a2 = reg_d0.h[0];
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = temp_a2;
            reg_d0.h[0] = 7;
            reg_d1.b[0] = GATLING_C(reg_a4)->direction;
            reg_a0 = (u8 *)(stage1_boss_gatling_muzzles);
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
            reg_d2.h[0] += GATLING_C(reg_a4)->jitter;
            reg_d3.w = 0;
            reg_d4.w = 0;
            bullet_fire256_fixed();
            GATLING_C(reg_a4)->speed += 2;
            GATLING_C(reg_a4)->spare_0A += 2;
            GATLING_C(reg_a4)->spare_0C += 2;
            rng_next_word();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            GATLING_C(reg_a4)->jitter = (u16) reg_d0.h[0];
            reg_d0.w = 0;
            reg_d0.b[0] = GATLING_C(reg_a4)->speed;
            reg_d0.h[0] -= 0x15;
            temp_a2_2 = reg_d0.h[0];
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = temp_a2_2;
            reg_d0.h[0] = 7;
            reg_d1.b[0] = GATLING_C(reg_a4)->direction;
            reg_a0 = (u8 *)(stage1_boss_gatling_muzzles);
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
            reg_d2.h[0] += GATLING_C(reg_a4)->jitter;
            reg_d3.w = 0;
            reg_d4.w = 0;
            bullet_fire256_fixed();
            rng_next_word();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            GATLING_C(reg_a4)->jitter = (u16) reg_d0.h[0];
            reg_d0.w = 0;
            reg_d0.b[0] = GATLING_C(reg_a4)->speed;
            reg_d0.h[0] -= 0x16;
            temp_a2_3 = reg_d0.h[0];
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = temp_a2_3;
            reg_d0.h[0] = 7;
            reg_d1.b[0] = GATLING_C(reg_a4)->direction;
            reg_a0 = (u8 *)(stage1_boss_gatling_muzzles);
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
            reg_d2.h[0] += GATLING_C(reg_a4)->jitter;
            reg_d3.w = 0;
            reg_d4.w = 0;
            bullet_fire256_fixed();
            GATLING_C(reg_a4)->shots_left -= 1;
        } while (GATLING_C(reg_a4)->shots_left != 0);
    }
    GATLING_C(reg_a4)->running = 0;
}

void stage1_boss_fire_gatling_fan(void) {
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




void stage1_boss_fire_side_spread_start(void) {
    SIDE_SPREAD(reg_a4)->round.h = 0x9050;
    SIDE_SPREAD(reg_a4)->side = 0;
    SIDE_SPREAD(reg_a4)->volleys.h = 1;
    SIDE_SPREAD(reg_a4)->shot.h = 0xC;
    stage1_boss_fire_side_spread(1, 0x9050);
}


void stage1_boss_fire_side_spread() {
    u8 temp_v1;

    if (SIDE_SPREAD(reg_a4)->volleys.t.count == 0) {
        reg_tmp.b[0] = SIDE_SPREAD(reg_a4)->round.t.count;
        SIDE_SPREAD(reg_a4)->round.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            temp_v1 = SIDE_SPREAD(reg_a4)->round.t.reload;
            if ((s32) temp_v1 > 0x10) {
                SIDE_SPREAD(reg_a4)->round.t.reload = (u8) (temp_v1 - 4);
            }
            SIDE_SPREAD(reg_a4)->round.t.count = (u8) SIDE_SPREAD(reg_a4)->round.t.reload;
            SIDE_SPREAD(reg_a4)->volleys.t.count = (u8) SIDE_SPREAD(reg_a4)->volleys.t.reload;
            goto block_5;
        }
    } else {
block_5:
        reg_tmp.b[0] = SIDE_SPREAD(reg_a4)->shot.t.count;
        SIDE_SPREAD(reg_a4)->shot.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            SIDE_SPREAD(reg_a4)->shot.t.count = (u8) SIDE_SPREAD(reg_a4)->shot.t.reload;
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
                    stage1_boss_fire_gatling_fan();
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
                    stage1_boss_fire_gatling_fan();
                }
            }
            SIDE_SPREAD(reg_a4)->volleys.t.count -= 1;
            if (SIDE_SPREAD(reg_a4)->volleys.t.count == 0) {
                SIDE_SPREAD(reg_a4)->side += 1;
                SIDE_SPREAD(reg_a4)->side &= 1;
            }
        }
    }
}

u8 D_0028DC38[8] = {
    0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04,
};
