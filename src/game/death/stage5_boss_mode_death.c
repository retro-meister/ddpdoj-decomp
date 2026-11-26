#include "common.h"
#include "entity.h"

typedef struct {
    /* 0x00 */ u16 running;
    /* 0x02 */ u16 wait;
    /* 0x04 */ u16 second_wait;
} Mode;

#define MODE(pointer) ((Mode *)(pointer))

void twin_boss_set_bullet_limits(u8 attack);
void twin_boss_mode_stinger(void);
void twin_boss_mode_attack_b(void);
void twin_boss_mode_attack_c(void);
void twin_boss_mode_spiral(void);
void twin_boss_mode_rage(void);
void twin_boss_mode_jet(void);

s32 boss_movement_start();
extern u8 g_death_boss_form;

void twin_boss_mode_stinger_start(void) {
    g_death_boss_form = 2;
    twin_boss_set_bullet_limits(0);
    MODE(reg_a4)->wait = 0x60;
    twin_boss_mode_stinger();
}

typedef struct {
    u8 speed_limit;
    u8 halved;
} BulletLimits;

const BulletLimits g_twin_boss_bullet_limits[2][3][5] = {
    {
        { { 42, 1 }, { 24, 1 }, { 24, 1 }, { 10, 1 }, { 24, 1 } },
        { { 24, 1 }, { 42, 1 }, { 42, 1 }, { 24, 1 }, { 42, 1 } },
        { { 42, 1 }, { 42, 1 }, { 42, 1 }, { 24, 1 }, { 42, 1 } },
    },
    {
        { { 42, 0 }, { 42, 0 }, { 42, 0 }, { 24, 0 }, { 24, 1 } },
        { { 42, 0 }, { 42, 0 }, { 42, 0 }, { 24, 0 }, { 42, 1 } },
        { { 42, 0 }, { 42, 0 }, { 42, 0 }, { 24, 0 }, { 42, 1 } },
    },
};
extern u8 g_twin_boss_bullets_halved;
extern u8 g_twin_boss_bullet_speed_limit;
extern u8 death_D_00290DC0;
extern u16 D_00684C80[];

void twin_boss_set_bullet_limits(u8 attack) {
    u8 type;

    type = D_00684C80[9] / 2 - 1;
    g_twin_boss_bullet_speed_limit = g_twin_boss_bullet_limits[death_D_00290DC0][type][attack].speed_limit;
    g_twin_boss_bullets_halved = g_twin_boss_bullet_limits[death_D_00290DC0][type][attack].halved;
}

s32 boss_phase_start();
s32 boss_attack_start();
s32 boss_attack_running();
extern u16 g_bullets_blocked;

void twin_boss_mode_stinger(void) {
    s8 first_busy;
    s8 second_busy;

    if (MODE(reg_a4)->wait != 0) {
        if (g_bullets_blocked != 0) {
            return;
        }
        MODE(reg_a4)->wait -= 1;
        if (MODE(reg_a4)->wait != 0) {
            return;
        }
        reg_d0.w = 0x18;
        boss_attack_start();
        reg_d0.w = 0x19;
        boss_attack_start();
    }
    reg_d0.w = 0x18;
    boss_attack_running();
    first_busy = cond_flag;
    reg_d0.w = 0x19;
    boss_attack_running();
    second_busy = cond_flag;
    if ((first_busy == 0) && (second_busy == 0)) {
        reg_d0.w = 0x17;
        boss_phase_start();
        reg_d0.w = 0xe;
        boss_movement_start();
        ENTITY(reg_a6)->move.b.speed = 0xC;
        ENTITY(reg_a6)[16].move.b.speed = 0xC;
        MODE(reg_a4)->running = 0;
    }
}


void twin_boss_mode_attack_b_start(void) {
    twin_boss_set_bullet_limits(2);
    MODE(reg_a4)->wait = 0x60;
    twin_boss_mode_attack_b();
}

void twin_boss_mode_attack_b(void) {
    s8 first_busy;
    s8 second_busy;

    if (MODE(reg_a4)->wait != 0) {
        if (g_bullets_blocked != 0) {
            return;
        }
        MODE(reg_a4)->wait -= 1;
        if (MODE(reg_a4)->wait != 0) {
            return;
        }
        reg_d0.w = 0x10;
        boss_attack_start();
        reg_d0.w = 0x11;
        boss_attack_start();
    }
    reg_d0.w = 0x10;
    boss_attack_running();
    first_busy = cond_flag;
    reg_d0.w = 0x11;
    boss_attack_running();
    second_busy = cond_flag;
    if ((first_busy == 0) && (second_busy == 0)) {
        reg_d0.w = 0x15;
        boss_phase_start();
        reg_d0.w = 0x10;
        boss_movement_start();
        MODE(reg_a4)->running = 0;
    }
}


void twin_boss_mode_attack_c_start(void) {
    twin_boss_set_bullet_limits(1);
    MODE(reg_a4)->wait = 0x60;
    twin_boss_mode_attack_c();
}

void twin_boss_mode_attack_c(void) {
    s8 first_busy;
    s8 second_busy;

    if (MODE(reg_a4)->wait != 0) {
        if (g_bullets_blocked != 0) {
            return;
        }
        MODE(reg_a4)->wait -= 1;
        if (MODE(reg_a4)->wait != 0) {
            return;
        }
        reg_d0.w = 0x12;
        boss_attack_start();
        reg_d0.w = 0x13;
        boss_attack_start();
        ENTITY(reg_a6)->move.b.speed = 4;
        ENTITY(reg_a6)[16].move.b.speed = 4;
    }
    reg_d0.w = 0x12;
    boss_attack_running();
    first_busy = cond_flag;
    reg_d0.w = 0x12;
    boss_attack_running();
    second_busy = cond_flag;
    if ((first_busy == 0) && (second_busy == 0)) {
        reg_d0.w = 0x16;
        boss_phase_start();
        reg_d0.w = 0xd;
        boss_movement_start();
        MODE(reg_a4)->running = 0;
    }
}


void twin_boss_mode_spiral_start(void) {
    MODE(reg_a4)->wait = 0x60;
    MODE(reg_a4)->second_wait = 0x40;
    twin_boss_mode_spiral();
}

void twin_boss_mode_spiral(void) {
    s8 first_busy;
    s8 second_busy;

    if (MODE(reg_a4)->wait != 0) {
        if (g_bullets_blocked != 0) {
            return;
        }
        MODE(reg_a4)->wait -= 1;
        if (MODE(reg_a4)->wait != 0) {
            return;
        }
        reg_d0.w = 0x14;
        boss_attack_start();
        reg_d0.w = 0x15;
        boss_attack_start();
    }
    reg_d0.w = 0x14;
    boss_attack_running();
    first_busy = cond_flag;
    reg_d0.w = 0x15;
    boss_attack_running();
    second_busy = cond_flag;
    if ((first_busy == 0) && (second_busy == 0)) {
        MODE(reg_a4)->second_wait -= 1;
        if (MODE(reg_a4)->second_wait == 0) {
            reg_d0.w = 0x15;
            boss_phase_start();
            reg_d0.w = 0x10;
            boss_movement_start();
            MODE(reg_a4)->running = 0;
        }
    }
}


void twin_boss_mode_rage_start(void) {
    MODE(reg_a4)->wait = 0x60;
    twin_boss_set_bullet_limits(4);
    reg_d0.w = 0x10;
    boss_movement_start();
    twin_boss_mode_rage();
}

s32 stage5_boss_shield_off();

void twin_boss_mode_rage(void) {
    if ((MODE(reg_a4)->wait != 0) && (g_bullets_blocked == 0)) {
        MODE(reg_a4)->wait -= 1;
        if (MODE(reg_a4)->wait == 0) {
            reg_d0.w = 0x16;
            boss_attack_start();
            reg_d0.w = 0x17;
            boss_attack_start();
            stage5_boss_shield_off();
        }
    }
}


void twin_boss_mode_jet_start(void) {
    twin_boss_set_bullet_limits(3);
    MODE(reg_a4)->wait = 0x60;
    reg_d0.w = 0xC;
    boss_movement_start();
    twin_boss_mode_jet();
}

void twin_boss_mode_jet(void) {
    if ((MODE(reg_a4)->wait != 0) && (g_bullets_blocked == 0)) {
        MODE(reg_a4)->wait -= 1;
        if (MODE(reg_a4)->wait == 0) {
            reg_d0.w = 0x1c;
            boss_attack_start();
            reg_d0.w = 0x1d;
            boss_attack_start();
            stage5_boss_shield_off();
        }
    }
}
