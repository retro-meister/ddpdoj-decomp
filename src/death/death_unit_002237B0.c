#include "common.h"
#include "entity.h"

void death_func_002237F0(u8 phase);
void death_func_00223870(void);
void death_func_00223980(void);
void death_func_00223A70(void);
void death_func_00223B70(void);
void death_func_00223C90(void);
void death_func_00223D40(void);

s32 func_00124D90();
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

extern Pair death_D_0028E450[][3][5];
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

s32 func_00124B20();
s32 func_001251C0();
s32 func_00125250();
extern u16 D_0028E89C;

void death_func_00223870(void) {
    s8 first_busy;
    s8 second_busy;

    if (*(u16 *)(reg_a4 + 2) != 0) {
        if (D_0028E89C != 0) {
            return;
        }
        *(u16 *)(reg_a4 + 2) -= 1;
        if (*(u16 *)(reg_a4 + 2) != 0) {
            return;
        }
        reg_d0.w = 0x18;
        func_001251C0();
        reg_d0.w = 0x19;
        func_001251C0();
    }
    reg_d0.w = 0x18;
    func_00125250();
    first_busy = cond_flag;
    reg_d0.w = 0x19;
    func_00125250();
    second_busy = cond_flag;
    if ((first_busy == 0) && (second_busy == 0)) {
        reg_d0.w = 0x17;
        func_00124B20();
        reg_d0.w = 0xe;
        func_00124D90();
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
        if (D_0028E89C != 0) {
            return;
        }
        *(u16 *)(reg_a4 + 2) -= 1;
        if (*(u16 *)(reg_a4 + 2) != 0) {
            return;
        }
        reg_d0.w = 0x10;
        func_001251C0();
        reg_d0.w = 0x11;
        func_001251C0();
    }
    reg_d0.w = 0x10;
    func_00125250();
    first_busy = cond_flag;
    reg_d0.w = 0x11;
    func_00125250();
    second_busy = cond_flag;
    if ((first_busy == 0) && (second_busy == 0)) {
        reg_d0.w = 0x15;
        func_00124B20();
        reg_d0.w = 0x10;
        func_00124D90();
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
        if (D_0028E89C != 0) {
            return;
        }
        *(u16 *)(reg_a4 + 2) -= 1;
        if (*(u16 *)(reg_a4 + 2) != 0) {
            return;
        }
        reg_d0.w = 0x12;
        func_001251C0();
        reg_d0.w = 0x13;
        func_001251C0();
        ENTITY(reg_a6)->move.b.speed = 4;
        *(u8 *)(reg_a6 + 0x21B) = 4;
    }
    reg_d0.w = 0x12;
    func_00125250();
    first_busy = cond_flag;
    reg_d0.w = 0x12;
    func_00125250();
    second_busy = cond_flag;
    if ((first_busy == 0) && (second_busy == 0)) {
        reg_d0.w = 0x16;
        func_00124B20();
        reg_d0.w = 0xd;
        func_00124D90();
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
        if (D_0028E89C != 0) {
            return;
        }
        *(u16 *)(reg_a4 + 2) -= 1;
        if (*(u16 *)(reg_a4 + 2) != 0) {
            return;
        }
        reg_d0.w = 0x14;
        func_001251C0();
        reg_d0.w = 0x15;
        func_001251C0();
    }
    reg_d0.w = 0x14;
    func_00125250();
    first_busy = cond_flag;
    reg_d0.w = 0x15;
    func_00125250();
    second_busy = cond_flag;
    if ((first_busy == 0) && (second_busy == 0)) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            reg_d0.w = 0x15;
            func_00124B20();
            reg_d0.w = 0x10;
            func_00124D90();
            *(u16 *)reg_a4 = 0;
        }
    }
}


void death_func_00223C50(void) {
    *(u16 *)(reg_a4 + 2) = 0x60;
    death_func_002237F0(4);
    reg_d0.w = 0x10;
    func_00124D90();
    death_func_00223C90();
}

s32 func_001F5630();

void death_func_00223C90(void) {
    if ((*(u16 *)(reg_a4 + 2) != 0) && (D_0028E89C == 0)) {
        *(u16 *)(reg_a4 + 2) -= 1;
        if (*(u16 *)(reg_a4 + 2) == 0) {
            reg_d0.w = 0x16;
            func_001251C0();
            reg_d0.w = 0x17;
            func_001251C0();
            func_001F5630();
        }
    }
}


void death_func_00223D00(void) {
    death_func_002237F0(3);
    *(u16 *)(reg_a4 + 2) = 0x60;
    reg_d0.w = 0xC;
    func_00124D90();
    death_func_00223D40();
}

void death_func_00223D40(void) {
    if ((*(u16 *)(reg_a4 + 2) != 0) && (D_0028E89C == 0)) {
        *(u16 *)(reg_a4 + 2) -= 1;
        if (*(u16 *)(reg_a4 + 2) == 0) {
            reg_d0.w = 0x1c;
            func_001251C0();
            reg_d0.w = 0x1d;
            func_001251C0();
            func_001F5630();
        }
    }
}
