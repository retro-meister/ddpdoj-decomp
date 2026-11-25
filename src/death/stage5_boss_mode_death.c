#include "common.h"
#include "entity.h"

void death_func_002237F0(u8 phase);
void death_func_00223870(void);
void death_func_00223980(void);
void death_func_00223A70(void);
void death_func_00223B70(void);
void death_func_00223C90(void);
void death_func_00223D40(void);

s32 boss_movement_start();
extern u8 death_D_0029085C;

void death_func_002237B0(void) {
    death_D_0029085C = 2;
    death_func_002237F0(0);
    *(u16 *)(reg_a4 + 2) = 0x60;
    death_func_00223870();
}

typedef struct {
    u8 first;
    u8 second;
} Pair;

const Pair death_D_0028E450[2][3][5] = {
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
extern u8 death_D_00290854;
extern u8 death_D_00290858;
extern u8 death_D_00290DC0;
extern u16 D_00684C80[];

void death_func_002237F0(u8 phase) {
    u8 type;

    type = D_00684C80[9] / 2 - 1;
    death_D_00290858 = death_D_0028E450[death_D_00290DC0][type][phase].first;
    death_D_00290854 = death_D_0028E450[death_D_00290DC0][type][phase].second;
}

s32 boss_phase_start();
s32 boss_attack_start();
s32 boss_attack_running();
extern u16 g_bullets_blocked;

void death_func_00223870(void) {
    s8 first_busy;
    s8 second_busy;

    if (*(u16 *)(reg_a4 + 2) != 0) {
        if (g_bullets_blocked != 0) {
            return;
        }
        *(u16 *)(reg_a4 + 2) -= 1;
        if (*(u16 *)(reg_a4 + 2) != 0) {
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
        *(u8 *)(reg_a6 + 0x21B) = 0xC;
        *(u16 *)reg_a4 = 0;
    }
}


void death_func_00223950(void) {
    death_func_002237F0(2);
    *(u16 *)(reg_a4 + 2) = 0x60;
    death_func_00223980();
}

void death_func_00223980(void) {
    s8 first_busy;
    s8 second_busy;

    if (*(u16 *)(reg_a4 + 2) != 0) {
        if (g_bullets_blocked != 0) {
            return;
        }
        *(u16 *)(reg_a4 + 2) -= 1;
        if (*(u16 *)(reg_a4 + 2) != 0) {
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
        *(u16 *)reg_a4 = 0;
    }
}


void death_func_00223A40(void) {
    death_func_002237F0(1);
    *(u16 *)(reg_a4 + 2) = 0x60;
    death_func_00223A70();
}

void death_func_00223A70(void) {
    s8 first_busy;
    s8 second_busy;

    if (*(u16 *)(reg_a4 + 2) != 0) {
        if (g_bullets_blocked != 0) {
            return;
        }
        *(u16 *)(reg_a4 + 2) -= 1;
        if (*(u16 *)(reg_a4 + 2) != 0) {
            return;
        }
        reg_d0.w = 0x12;
        boss_attack_start();
        reg_d0.w = 0x13;
        boss_attack_start();
        ENTITY(reg_a6)->move.b.speed = 4;
        *(u8 *)(reg_a6 + 0x21B) = 4;
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
        *(u16 *)reg_a4 = 0;
    }
}


void death_func_00223B50(void) {
    *(u16 *)(reg_a4 + 2) = 0x60;
    *(u16 *)(reg_a4 + 4) = 0x40;
    death_func_00223B70();
}

void death_func_00223B70(void) {
    s8 first_busy;
    s8 second_busy;

    if (*(u16 *)(reg_a4 + 2) != 0) {
        if (g_bullets_blocked != 0) {
            return;
        }
        *(u16 *)(reg_a4 + 2) -= 1;
        if (*(u16 *)(reg_a4 + 2) != 0) {
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
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            reg_d0.w = 0x15;
            boss_phase_start();
            reg_d0.w = 0x10;
            boss_movement_start();
            *(u16 *)reg_a4 = 0;
        }
    }
}


void death_func_00223C50(void) {
    *(u16 *)(reg_a4 + 2) = 0x60;
    death_func_002237F0(4);
    reg_d0.w = 0x10;
    boss_movement_start();
    death_func_00223C90();
}

s32 func_001F5630();

void death_func_00223C90(void) {
    if ((*(u16 *)(reg_a4 + 2) != 0) && (g_bullets_blocked == 0)) {
        *(u16 *)(reg_a4 + 2) -= 1;
        if (*(u16 *)(reg_a4 + 2) == 0) {
            reg_d0.w = 0x16;
            boss_attack_start();
            reg_d0.w = 0x17;
            boss_attack_start();
            func_001F5630();
        }
    }
}


void death_func_00223D00(void) {
    death_func_002237F0(3);
    *(u16 *)(reg_a4 + 2) = 0x60;
    reg_d0.w = 0xC;
    boss_movement_start();
    death_func_00223D40();
}

void death_func_00223D40(void) {
    if ((*(u16 *)(reg_a4 + 2) != 0) && (g_bullets_blocked == 0)) {
        *(u16 *)(reg_a4 + 2) -= 1;
        if (*(u16 *)(reg_a4 + 2) == 0) {
            reg_d0.w = 0x1c;
            boss_attack_start();
            reg_d0.w = 0x1d;
            boss_attack_start();
            func_001F5630();
        }
    }
}
