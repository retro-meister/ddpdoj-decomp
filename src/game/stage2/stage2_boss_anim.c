#include "common.h"
#include "entity.h"

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
    *(s16 *)((u8 *)((void *)reg_a6) + 0x26) = 2;
    *(s16 *)((u8 *)((void *)reg_a6) + 0x28) = 0;
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

void func_001E6C70(void)
{
    extern void rng_next_bit(void);
    *(u16 *)((u8 *)((void *)reg_a4) + 4) = 0;
    rng_next_bit();
    ((u8 *)((void *)reg_a4))[4] = reg_d0.b[0];
    rng_next_masked();
    ((u8 *)((void *)reg_a4))[2] = reg_d0.b[0];
    rng_next_masked();
    *(u16 *)((u8 *)((void *)reg_a4) + 6) = reg_d0.h[0];
    ((u8 *)((void *)reg_a4))[3] = 0;
}


void stage2_boss_radome_idle_start(void) {
    func_001E6C70();
    stage2_boss_radome_idle();
}

s32 direction_turn_toward();

void stage2_boss_radome_idle() {
    u8 temp_a0;
    u8 temp_a0_2;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u16 *)(reg_a4 + 6) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 6) < 0) {
            *(u8 *)(reg_a4 + 3) = 1U;
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            reg_d0.w = 0;
            reg_d1.w = 0;
            reg_d0.b[0] = ENTITY(reg_a6)[8].move.b.dir;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 2);
            direction_turn_toward();
            ENTITY(reg_a6)[8].move.b.dir = (u8) reg_d1.b[0];
            temp_a0_2 = *(u8 *)(reg_a4 + 2);
            if (temp_a0_2 == reg_d1.b[0]) {
                func_001E6C70();
            }
        }
    }
}



void stage2_boss_torso_idle_start(void) {
    *(s16 *)(reg_a4 + 2) = 3;
    *(s16 *)(reg_a4 + 4) = 0;
    stage2_boss_torso_idle();
}


extern u8 D_0026C0A0[];

void stage2_boss_torso_idle(void) {
    reg_tmp.b[0] = (*(u8 *)(reg_a4 + 3));
    (*(u8 *)(reg_a4 + 3)) -= 1;
    if ((s32)reg_tmp.b[0] <= 0) {
        (*(u8 *)(reg_a4 + 3)) = (*(u8 *)(reg_a4 + 2));
        reg_a0 = D_0026C0A0;
        reg_a0 += (*(u16 *)(reg_a4 + 4));
        (ENTITY(reg_a6)->offset_y.h) = *(u16 *)reg_a0;
        (*(u16 *)(reg_a4 + 4)) += 2;
        if ((*(u16 *)(reg_a4 + 4)) == 0xC) {
            (*(u16 *)(reg_a4 + 4)) = 0;
        }
    }
}


void stage2_boss_radome_spin_start(void) {
    s32 rng_next_bit();
    *(s16 *)(reg_a4 + 4) = 0;
    *(u8 *)(reg_a4 + 7) = 1U;
    rng_next_bit();
    if (reg_d0.h[0] != 0) {
        stage2_boss_radome_spin();
        return;
    }
    *(u8 *)(reg_a4 + 7) *= -1;
    stage2_boss_radome_spin();
}

void stage2_boss_radome_spin(void) {
    reg_d0.b[0] = *(u8 *)(reg_a4 + 7);
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
    *(u16 *)((u8 *)((void *)reg_a4) + 2) = 2;
    *(u16 *)((u8 *)((void *)reg_a4) + 4) = 0;
    stage2_boss_torso_open();
}

void stage2_boss_torso_open(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)->offset_y.h += 4;
        if (ENTITY(reg_a6)->offset_y.h == 0x1C) {
            *(s16 *)reg_a4 = 0;
        }
    }
}



void stage2_boss_torso_close_start(void) {
    *(u16 *)(reg_a4 + 2) = 0x2002;
    *(u16 *)(reg_a4 + 4) = 0;
    stage2_boss_torso_close();
}

s32 boss_animation_start();

void stage2_boss_torso_close() {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)->offset_y.h -= 4;
        if (ENTITY(reg_a6)->offset_y.h == 0) {
            *(s16 *)reg_a4 = 0;
            reg_d0.w = 2;
            boss_animation_start();
        }
    }
}


void stage2_boss_recoil_start(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    *(u16 *)(reg_a4 + 4) = 4;
    *(u8 *)(reg_a4 + 7) = 0;
    stage2_boss_recoil();
}

void stage2_boss_recoil(void) {
    if (*(u8 *)(reg_a4 + 7) == 1) {
        ENTITY(reg_a6)[11].offset_x.h -= 0x20;
        if (0 > (s16) ENTITY(reg_a6)[11].offset_x.h) {
            ENTITY(reg_a6)[11].offset_x.h = 0U;
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            ENTITY(reg_a6)[11].offset_y.h += 4;
            if (ENTITY(reg_a6)[11].offset_y.h == 0x40) {
                ENTITY(reg_a6)[11].offset_y.h = 0U;
                ENTITY(reg_a6)[11].offset_x.h = 0U;
                *(s16 *)reg_a4 = 0;
            }
        }
    }
    if (*(u8 *)(reg_a4 + 7) == 0) {
        ENTITY(reg_a6)[11].offset_x.h += 0x100;
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            ENTITY(reg_a6)[11].offset_y.h += 0x10;
            if (ENTITY(reg_a6)[11].offset_y.h == 0x20) {
                *(u8 *)(reg_a4 + 7) = 1U;
                *(u16 *)(reg_a4 + 4) = 0;
            }
        }
    }
}


void stage2_boss_shoulder_cannon_open_start(void) {
    *(s16 *)(reg_a4 + 2) = 1;
    stage2_boss_shoulder_cannon_open();
}

void stage2_boss_shoulder_cannon_open(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[11].offset_y.h += 4;
        if ((s16) ENTITY(reg_a6)[11].offset_y.h >= 0x20) {
            ENTITY(reg_a6)[11].offset_y.h = 0x20U;
            *(s16 *)reg_a4 = 0;
        }
    }
}


void stage2_boss_shoulder_cannon_close_start(void) {
    *(u16 *)(reg_a4 + 2) = 1;
    stage2_boss_shoulder_cannon_close();
}

void stage2_boss_shoulder_cannon_close(void)
{
    s16 *remaining;

    reg_tmp.b[0] = reg_a4[3];
    reg_a4[3] -= 1;
    if ((s32)(u8)reg_tmp.b[0] <= 0) {
        reg_a4[3] = reg_a4[2];
        ENTITY(reg_a6)[11].offset_y.h -= 4;
        remaining = (s16 *)(reg_a6 + 0x166);
        if (0 < *remaining) {
            return;
        }
        *remaining = 0;
        *(u16 *)reg_a4 = 0;
    }
}


void stage2_boss_shoulder_turret_anim_start(void) {
    ((u16 *)reg_a4)[1] = 0x202;
    stage2_boss_shoulder_turret_anim();
}

void stage2_boss_shoulder_turret_anim(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[11].draw.h += 4;
        if ((s16) ENTITY(reg_a6)[11].draw.h >= 0x38) {
            ENTITY(reg_a6)[11].draw.h = 0U;
        }
    }
}

s32 rng_next_unsigned();

void stage2_boss_side_gun_anim_start(void) {
    *(s16 *)(reg_a4 + 2) = 0x101;
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
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[6].offset_y.h += 4;
        ENTITY(reg_a6)[6].offset_y.h &= 0x3F;
        ENTITY(reg_a6)[7].offset_y.h += 4;
        ENTITY(reg_a6)[7].offset_y.h &= 0x3F;
    }
}


void stage2_boss_ripple_request_start(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    *(u16 *)(reg_a4 + 4) = 0;
    stage2_boss_ripple_request();
}

s32 spawn_request_add();
extern u8 D_0026C0B0[];

void stage2_boss_ripple_request(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_d0.w = 0x4D;
        spawn_request_add();
        reg_d0.h[1] = ENTITY(reg_a6)[1].y.h;
        reg_d0.h[0] = ENTITY(reg_a6)[1].x.h;
        reg_a1 = D_0026C0B0;
        reg_a1 += *(u16 *)(reg_a4 + 4);
        reg_tmp.h[1] = *(u16 *)reg_a1;
        reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
        reg_d0.w += reg_tmp.w;
        *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
        *(u16 *)(reg_a4 + 4) += 4;
        *(u16 *)(reg_a4 + 4) &= 0xF;
    }
}

u8 D_0026C0A0[32] = {
    0x00, 0x00, 0x04, 0x00, 0x08, 0x00, 0x0C, 0x00, 0x08, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xF0, 0x00, 0xF5, 0x00, 0xF0, 0x00, 0x05, 0x80, 0xF4, 0x00, 0xF1, 0x80, 0xF4, 0x00, 0x09,
};
