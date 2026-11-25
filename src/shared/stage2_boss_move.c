#include "common.h"
#include "entity.h"

void func_001C9950(void);
void func_001C9C50(void);
void func_001C9DB0(void);
void func_001C9EE0(void);
void func_001CA090(void);
void func_001CA1F0(void);
void func_001CA370(void);


void func_001C9750(void) {
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    ENTITY(reg_a6)[1].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[1].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[1].y.h -= 0x1800;
    ENTITY(reg_a6)[1].x.h += 0x300;
    ENTITY(reg_a6)[2].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[2].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[2].y.h -= 0x11C0;
    ENTITY(reg_a6)[2].x.h += 0x6C0;
    ENTITY(reg_a6)[3].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[3].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[3].y.h -= 0x11C0;
    ENTITY(reg_a6)[3].x.h -= 0x6C0;
    ENTITY(reg_a6)[4].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[4].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[4].y.h -= 0x40;
    ENTITY(reg_a6)[4].x.h += 0xCC0;
    ENTITY(reg_a6)[5].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[5].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[5].y.h -= 0x40;
    ENTITY(reg_a6)[5].x.h -= 0xCC0;
    ENTITY(reg_a6)[6].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[6].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[6].y.h += 0x540;
    ENTITY(reg_a6)[6].x.h += 0x1480;
    ENTITY(reg_a6)[7].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[7].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[7].y.h += 0x540;
    ENTITY(reg_a6)[7].x.h -= 0x1480;
    ENTITY(reg_a6)[8].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[8].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[8].y.h -= 0x300;
}


void func_001C9920(void) {
    reg_a4[3] = 0;
    *(u16 *)(reg_a4 + 4) = 0x1C0;
    *(u16 *)(reg_a4 + 6) = 0;
    *(u16 *)(reg_a4 + 8) = 0;
    func_001C9950();
}

s32 boss_phase_start();
s32 boss_movement_stop();
s32 func_0013B2E0();
s32 sprite_palette_load();
s32 func_001CBBF0();
s32 entity_follow_scroll();
extern u8 D_0025FCB0[];
extern u8 D_0026C8C0[];
extern u8 D_0028E854;
extern u8 D_0028E855;

void func_001C9950(void) {
    entity_follow_scroll();
    if (*(u8 *)(reg_a4 + 3) == 0) {
        if (*(u16 *)(reg_a4 + 4) == 0x10) {
            reg_d0.h[0] = 0xD;
            reg_a0 = (u8 *)D_0025FCB0;
            sprite_palette_load();
        }
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) != 0) {
            func_001C9750();
            return;
        }
        *(u8 *)(reg_a4 + 3) = 1U;
        D_0028E854 |= 1;
        func_001C9750();
        return;
    }
    if (*(u16 *)(reg_a4 + 6) != 0x100) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 9);
        *(u8 *)(reg_a4 + 9) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
            *(u16 *)(reg_a4 + 6) += 3;
            if ((s16) *(u16 *)(reg_a4 + 6) >= 0x100) {
                *(u16 *)(reg_a4 + 6) = 0x100U;
            }
        }
    }
    reg_d0.h[0] = *(u16 *)(reg_a4 + 6);
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    if ((s16) ENTITY(reg_a6)->y.h < 0x6200) {
        func_001C9750();
        return;
    }
    D_0028E855 |= 0x10;
    D_0028E855 |= 2;
    reg_d0.w = 3;
    boss_phase_start();
    func_001CBBF0();
    boss_movement_stop();
    reg_a0 = (u8 *)D_0026C8C0;
    func_0013B2E0();
    func_001C9750();
}


void func_001C9AF0(void) {
    ENTITY(reg_a6)->y.h -= 0x10;
    func_001C9750();
}

s32 rng_next_masked();
extern u16 *reg_a4_as_u16_p;

void func_001C9B10(void) {
    rng_next_masked();
    reg_d0.h[0] &= 7;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    *reg_a4_as_u16_p = reg_d0.h[0];
}

void func_001C9B60(void)
{
    reg_d0.b[0] = reg_a4[3];
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.speed;

    if (reg_d0.b[0] != reg_d1.b[0]) {
        if ((s8)reg_d0.b[0] >= (s8)reg_d1.b[0]) {
            reg_d1.b[0]++;
        } else {
            reg_d1.b[0]--;
        }
    }

    ENTITY(reg_a6)->move.b.speed = reg_d1.b[0];
}

extern u8 D_0026C860[];

void func_001C9BC0(void) {
    s32 direction_between(void *);
    *reg_a4_as_u16_p = 0;
    ENTITY(reg_a6)->move.sb.speed = 4;
    reg_a0 = D_0026C860;
    reg_a0 += *reg_a4_as_u16_p;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between(reg_a6);
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    func_001C9C50();
}

s32 rng_next_bit();
s32 entity_velocity();
s32 direction_turn_toward();
s32 func_00202B50();

void func_001C9C50() {
    s32 direction_between();
    reg_a0 = D_0026C860;
    reg_a0 += *reg_a4_as_u16_p;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    entity_velocity();
    reg_a0 = D_0026C860;
    reg_a0 += *reg_a4_as_u16_p;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    func_00202B50();
    if ((s16) reg_d0.h[0] < 0x101) {
        *reg_a4_as_u16_p += 4;
        *reg_a4_as_u16_p &= 0x3F;
        ENTITY(reg_a6)->move.b.speed = 4U;
        rng_next_bit();
        ENTITY(reg_a6)->move.b.speed -= reg_d0.b[0];
    }
    func_001C9750();
}


void func_001C9D70(void) {
    *(s8 *)(reg_a4 + 3) = 2;
    *(s16 *)(reg_a4 + 4) = 0x404;
    reg_tmp.w = 0x5C001C00;
    *(u16 *)(reg_a4 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0xA) = (u16) reg_tmp.h[0];
    func_001C9DB0();
}

s32 boss_movement_start();
s32 func_001CBBE0();

void func_001C9DB0(void) {
    s32 direction_between();
    reg_d2.h[0] = *(u16 *)(reg_a4 + 8);
    reg_d3.h[0] = *(u16 *)(reg_a4 + 0xA);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_d2.h[0] = *(u16 *)(reg_a4 + 8);
    reg_d3.h[0] = *(u16 *)(reg_a4 + 0xA);
    func_00202B50();
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] >>= 8;
    *(u8 *)(reg_a4 + 3) = (u8) reg_d1.b[0];
    if ((s16) reg_d0.h[0] < 0x101) {
        reg_d0.w = 5;
        boss_movement_start();
        func_001CBBE0();
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
        func_001C9B60();
    }
    entity_velocity();
    func_001C9750();
}


void func_001C9EA0(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0x101;
    reg_tmp.w = 0x5C001C00;
    *(u16 *)(reg_a4 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0xA) = (u16) reg_tmp.h[0];
    func_001C9EE0();
}

void func_001C9EE0(void) {
    s32 direction_between();
    reg_d2.h[0] = *(u16 *)(reg_a4 + 8);
    reg_d3.h[0] = *(u16 *)(reg_a4 + 0xA);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_d2.h[0] = *(u16 *)(reg_a4 + 8);
    reg_d3.h[0] = *(u16 *)(reg_a4 + 0xA);
    func_00202B50();
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] >>= 7;
    *(u8 *)(reg_a4 + 3) = (u8) reg_d1.b[0];
    if ((s16) reg_d0.h[0] < 0x101) {
        reg_d0.w = 5;
        boss_movement_start();
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
        func_001C9B60();
    }
    entity_velocity();
    func_001C9750();
}

s32 boss_attack_stop();
s32 rng_next_word();

void func_001C9FC0(void) {
    u16 temp_a0;

    reg_d0.w = 2;
    boss_attack_stop();
    *(s8 *)(reg_a4 + 3) = 2;
    *(s16 *)(reg_a4 + 0xC) = 0;
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] = temp_a0;
    *(u16 *)(reg_a4 + 4) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a4 + 6) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a4 + 8) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a4 + 0xA) = (u16) reg_d0.h[0];
    rng_next_word();
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
    *(u16 *)(reg_a4 + 8) += reg_d0.h[0];
    rng_next_word();
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
    *(u16 *)(reg_a4 + 0xA) += reg_d0.h[0];
    func_001CA090();
}

void func_001CA090() {
    s32 direction_between();
    reg_d2.h[0] = *(u16 *)(reg_a4 + 8);
    reg_d3.h[0] = *(u16 *)(reg_a4 + 0xA);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xD);
    *(u8 *)(reg_a4 + 0xD) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
        func_001C9B60();
    }
    entity_velocity();
    reg_d2.h[0] = *(u16 *)(reg_a4 + 8);
    reg_d3.h[0] = *(u16 *)(reg_a4 + 0xA);
    func_00202B50();
    if ((s16) reg_d0.h[0] < 0x101) {
        reg_d0.h[1] = *(u16 *)(reg_a4 + 4);
        reg_d0.h[0] = *(u16 *)(reg_a4 + 6);
        *(u16 *)(reg_a4 + 8) = (u16) reg_d0.h[1];
        *(u16 *)(reg_a4 + 0xA) = (u16) reg_d0.h[0];
        rng_next_word();
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
        *(u16 *)(reg_a4 + 8) += reg_d0.h[0];
        rng_next_word();
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
        *(u16 *)(reg_a4 + 0xA) += reg_d0.h[0];
    }
    func_001C9750();
}


void func_001CA1D0(void) {
    reg_a4[3] = 0;
    reg_a4[2] = 0;
    *(s16 *)(reg_a4 + 4) = 0x404;
    func_001CA1F0();
}

void func_001CA1F0(void) {
    s32 direction_between();
    if (*(u8 *)(reg_a4 + 2) == 0) {
        reg_d2.h[0] = *(u16 *)(reg_a4 + 8);
        reg_d3.h[0] = *(u16 *)(reg_a4 + 0xA);
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        direction_between();
        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
        reg_d2.h[0] = *(u16 *)(reg_a4 + 8);
        reg_d3.h[0] = *(u16 *)(reg_a4 + 0xA);
        func_00202B50();
        reg_d1.h[0] = reg_d0.h[0];
        reg_d1.h[0] >>= 7;
        if ((s16)(reg_d1.b[0]) < 3) {
            reg_d1.w = 2;
        }
        *(u8 *)(reg_a4 + 3) = (u8) reg_d1.b[0];
        if ((s16) reg_d0.h[0] < 0x201) {
            *(u8 *)(reg_a4 + 2) = 1U;
            *(u8 *)(reg_a4 + 3) = 2U;
            *(s16 *)(reg_a4 + 4) = 0x101;
        }
    }
    if ((*(u8 *)(reg_a4 + 2) == 1) && (ENTITY(reg_a6)->move.sb.speed < 3)) {
        ENTITY(reg_a6)->move.sb.speed = 2;
        reg_d0.w = 5;
        boss_movement_start();
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
        func_001C9B60();
    }
    entity_velocity();
    func_001C9750();
}

extern s16 *reg_a4_as_s16_p;


void func_001CA350(void) {
    *reg_a4_as_s16_p = 0;
    ENTITY(reg_a6)->move.b.speed = 8;
    func_001CA370();
}

extern u8 D_0026C8A0[];

void func_001CA370(void) {
    s32 direction_between(void *);
    reg_a0 = D_0026C8A0;
    reg_a0 += *(u16 *)reg_a4;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between(reg_a6);
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    entity_velocity();
    reg_a0 = D_0026C8A0;
    reg_a0 += *(u16 *)reg_a4;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    func_00202B50();
    if ((s16) reg_d0.h[0] < 0x201) {
        func_001C9B10();
    }
    func_001C9750();
}
