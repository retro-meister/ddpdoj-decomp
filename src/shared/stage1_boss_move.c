#include "common.h"
#include "entity.h"

void func_001BB300(void);

s32 velocity_from_dir256();
extern u16 D_002BDA90[];
extern u16 D_002BDA92[];
extern u8 D_002BDA94[];

void func_001BA820(void) {
    u32 t;
    u32 t1;
    u16 *p;

    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w = reg_d0.w;
    t1 = reg_d1.w;
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA6);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xA8);
    reg_d1.w = t1 + reg_tmp.w;
    reg_d1.w += 0xE0000000;
    *(u16 *)(reg_a6 + 0xA2) = reg_d1.h[1];
    *(u16 *)(reg_a6 + 0xA4) = reg_d1.h[0];
    reg_a0 = (u8 *)D_002BDA94;
    p = D_002BDA90;
    reg_a1 = (u8 *)p;
    reg_d1.w = 3;
loop_1:
    reg_a0 -= 4;
    reg_a1 -= 4;
    *(u16 *)(reg_a0 + 0) = *(u16 *)(reg_a1 + 0);
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a1 + 2);
    t = reg_d1.h[0] - 1;
    reg_d1.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    *(u16 *)(reg_a1 + 0) = reg_d0.h[1];
    *(u16 *)(reg_a1 + 2) = reg_d0.h[0];
    if (*(u8 *)(reg_a6 + 0x3E) != 0) goto next_2;
    reg_d0.h[1] = *p;
    reg_d0.h[0] = D_002BDA92[0];
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x26);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x28);
    reg_d0.w += reg_tmp.w;
    *(u16 *)(reg_a6 + 0x22) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x24) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x24) += 0x80;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x4B);
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x4A);
    velocity_from_dir256();
    reg_d2.h[0] = (s16) reg_d2.h[0] * 2;
    reg_d2.h[0] += 0xFD80;
    *(u16 *)(reg_a6 + 0x22) += reg_d2.h[0];
    reg_d3.h[0] = (s16) reg_d3.h[0] * 4;
    *(u16 *)(reg_a6 + 0x24) += reg_d3.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x4C);
    *(u16 *)(reg_a6 + 0x22) -= reg_d0.h[0];
next_2:
    if (*(u8 *)(reg_a6 + 0x7E) != 0) goto next_3;
    reg_d0.h[1] = *p;
    reg_d0.h[0] = D_002BDA92[0];
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x66);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x68);
    reg_d0.w += reg_tmp.w;
    *(u16 *)(reg_a6 + 0x62) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x64) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x64) += 0xFF80;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x8B);
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x8A);
    velocity_from_dir256();
    reg_d2.h[0] = (s16) reg_d2.h[0] * 2;
    reg_d2.h[0] += 0xFD80;
    *(u16 *)(reg_a6 + 0x62) += reg_d2.h[0];
    reg_d3.h[0] = (s16) reg_d3.h[0] * 4;
    *(u16 *)(reg_a6 + 0x64) += reg_d3.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x8C);
    *(u16 *)(reg_a6 + 0x62) -= reg_d0.h[0];
next_3:
    return;
}


void func_001BAB10(void) {
    ENTITY(reg_a6)->move.sh = 0x1E20;
    *(s16 *)(reg_a4 + 0x2) = 0x101;
    reg_a4[0x5] = 0;
    *(s16 *)(reg_a4 + 0x6) = 0x101;
}

s32 boss_phase_start();
s32 boss_movement_start();
s32 boss_part_show();
s32 boss_animation_start();
s32 func_0013B2E0();
s32 func_001BC3A0();
s32 func_001BC3B0();
s32 entity_velocity();
s32 direction_turn_toward();
s32 func_00202B50();
extern u16 D_0026E930[];
extern u8 D_0028E855;
extern u16 D_0029C068[];
extern u16 D_002BDA80_as_u16_a[];

void func_001BAB40(void) {
    s32 direction_between();
    u8 temp_v0_2;

    reg_d2.h[0] = 0x5400;
    reg_d3.h[0] = 0x1C00;
    reg_d3.h[0] -= D_0029C068[0];
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    entity_velocity();
    reg_a0 = (u8 *)(D_002BDA80_as_u16_a);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.w = 4;
    do {
        *(u16 *)reg_a0 = reg_d1.h[1];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[0];
        reg_a0 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d2.h[0] = 0x5400;
    reg_d3.h[0] = 0x1C00;
    reg_d3.h[0] -= D_0029C068[0];
    func_00202B50();
    if ((s16) reg_d0.h[0] < 0x1801) {
        *(u8 *)(reg_a4 + 5) = 1U;
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            temp_v0_2 = ENTITY(reg_a6)->move.b.speed;
            if (temp_v0_2 != 0) {
                ENTITY(reg_a6)->move.b.speed = (u8) (temp_v0_2 - 1);
            }
        }
    }
    if (*(u8 *)(reg_a4 + 5) == 0) {
        *(u16 *)(reg_a6 + 0x11A) += 0x10;
        *(u16 *)(reg_a6 + 0x11A) &= 0x3F;
    }
    if (*(u8 *)(reg_a4 + 5) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
        *(u8 *)(reg_a4 + 7) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            *(u16 *)(reg_a6 + 0x11A) += 0x10;
            if (*(u16 *)(reg_a6 + 0x11A) == 0x180) {
                D_0028E855 |= 0x10;
                D_0028E855 |= 2;
                reg_d0.w = 2;
                boss_movement_start();
                reg_d0.w = 1;
                boss_phase_start();
                func_001BC3A0();
                func_001BC3B0();
                reg_d0.w = 0;
                boss_animation_start();
                reg_d0.w = 1;
                boss_animation_start();
                reg_d0.w = 2;
                boss_animation_start();
                reg_d0.w = 3;
                boss_animation_start();
                reg_d0.w = 7;
                boss_animation_start();
                reg_d0.w = 0;
                boss_part_show();
                reg_d0.w = 1;
                boss_part_show();
                reg_d0.w = 2;
                boss_part_show();
                reg_d0.w = 3;
                boss_part_show();
                reg_d0.w = 4;
                boss_part_show();
                reg_d0.w = 5;
                boss_part_show();
                reg_d0.w = 6;
                reg_a0 = (u8 *)(D_0026E930);
                func_0013B2E0();
            }
        }
    }
    func_001BA820();
}

void func_001BAE30(void) {
}

void func_001BAE40(void) {
    ENTITY(reg_a6)->y.h -= 0x10;
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w = reg_d0.w;
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA6);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xA8);
    reg_d1.w += reg_tmp.w;
    reg_d1.w += 0xDE000000;
    *(u16 *)(reg_a6 + 0xA2) = (u16) reg_d1.h[1];
    *(u16 *)(reg_a6 + 0xA4) = (u16) reg_d1.h[0];
}

s32 rng_next_masked();

void func_001BAEC0(void) {
    rng_next_masked();
    reg_d0.h[0] &= 7;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    *(u16 *)reg_a4 = (u16) reg_d0.h[0];
    rng_next_masked();
    reg_d0.b[0] &= 3;
    reg_d0.b[0] += 2;
    *(u8 *)(reg_a4 + 3) = (u8) reg_d0.b[0];
}

void func_001BAF40(void)
{
    u8 *currentByte;

    reg_d0.b[0] = reg_a4[3];
    currentByte = &ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = *currentByte;

    if (reg_d0.b[0] != reg_d1.b[0]) {
        if ((s8)reg_d0.b[0] >= (s8)reg_d1.b[0]) {
            reg_d1.b[0]++;
        } else {
            reg_d1.b[0]--;
        }
    }

    *currentByte = reg_d1.b[0];
}


void func_001BAFA0(void) {
    *(u16 *)reg_a4 = 0;
    ENTITY(reg_a6)->move.h = 0x20;
    reg_a4[3] = ENTITY(reg_a6)->move.b.speed;
    func_001BAEC0();
}

extern u8 D_0026E980[];
extern u16 *reg_a4_as_u16_p;

void func_001BAFD0(void) {
    s32 direction_between(void *);
    reg_a0 = D_0026E980;
    reg_a0 += *reg_a4_as_u16_p;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between(reg_a6);
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    func_001BAF40();
    entity_velocity();
    reg_a0 = D_0026E980;
    reg_a0 += *reg_a4_as_u16_p;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    func_00202B50();
    if ((s16) reg_d0.h[0] < 0x101) {
        func_001BAEC0();
    }
    func_001BA820();
}

extern void *reg_a6_as_void_p;
extern void *reg_a4_as_void_p;

void func_001BB0B0(void) {
    *(u16 *)reg_a4_as_void_p = 0;
    ((u8 *)reg_a4_as_void_p)[3] = ((u8 *)reg_a6_as_void_p)[0x1B];
}

void func_001BB0D0() {
    s32 direction_between();
    reg_d2.h[0] = 0x6A00;
    reg_d3.h[0] = 0x1C00;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_d2.h[0] = 0x6A00;
    reg_d3.h[0] = 0x1C00;
    func_00202B50();
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] = (u16) ((s32) reg_d1.h[0] >> 7);
    *(u8 *)(reg_a4 + 3) = (u8) reg_d1.b[0];
    if ((s16) reg_d0.h[0] < 0x101) {
        reg_d0.w = 4;
        boss_movement_start();
    }
    func_001BAF40();
    entity_velocity();
    func_001BA820();
}


void func_001BB180(void) {
    *(u16 *)reg_a4 = 0;
    reg_a4[3] = ENTITY(reg_a6)->move.b.speed;
    func_001BAEC0();
}

extern u8 D_0026E9A0[];

void func_001BB1A0(void) {
    s32 direction_between(void *);
    reg_a0 = D_0026E9A0;
    reg_a0 += *reg_a4_as_u16_p;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between(reg_a6);
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    func_001BAF40();
    entity_velocity();
    reg_a0 = D_0026E9A0;
    reg_a0 += *reg_a4_as_u16_p;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    func_00202B50();
    if ((s16) reg_d0.h[0] < 0x101) {
        func_001BAEC0();
    }
    func_001BA820();
}


void func_001BB280(void) {
    *(s16 *)(reg_a4 + 0) = 0;
    ENTITY(reg_a6)->move.b.speed = 4U;
    *(u8 *)(reg_a4 + 3) = ENTITY(reg_a6)->move.b.speed;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3E);
    reg_d0.b[0] += *(u8 *)(reg_a6 + 0x7E);
    if (reg_d0.b[0] != 2) {
        func_001BB300();
        return;
    }
    ENTITY(reg_a6)->move.b.speed = 8U;
}

void func_001BB300() {
    s32 direction_between();
    reg_d2.h[0] = 0x5C00;
    reg_d3.h[0] = 0x1C00;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_d2.h[0] = 0x5C00;
    reg_d3.h[0] = 0x1C00;
    func_00202B50();
    if ((s16) reg_d0.h[0] < 0x101) {
        reg_d0.w = 2;
        boss_movement_start();
    }
    entity_velocity();
    func_001BA820();
}

void func_001BB390(void) {
    *(u16 *)reg_a4 = 0;
    reg_a4[3] = ENTITY(reg_a6)->move.b.speed;
}

void func_001BB3B0() {
    s32 direction_between();
    reg_d2.h[0] = 0x7400;
    reg_d3.h[0] = 0x1C00;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_d2.h[0] = 0x7400;
    reg_d3.h[0] = 0x1C00;
    func_00202B50();
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] = (u16) ((s32) reg_d1.h[0] >> 7);
    *(u8 *)(reg_a4 + 3) = (u8) reg_d1.b[0];
    if ((s16) reg_d0.h[0] < 0x101) {
        reg_d0.w = 7;
        boss_movement_start();
    }
    func_001BAF40();
    entity_velocity();
    func_001BA820();
}

extern s16 *reg_a4_as_s16_p;

void func_001BB460(void) {
    u8 value;

    *reg_a4_as_s16_p = 0;
    value = ENTITY(reg_a6)->move.b.speed;
    ((u8 *)reg_a4_as_s16_p)[3] = value;
    func_001BAEC0();
}

extern u8 D_0026E9C0[];

void func_001BB480(void) {
    s32 direction_between(void *);
    reg_a0 = D_0026E9C0;
    reg_a0 += *reg_a4_as_u16_p;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between(reg_a6);
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    func_001BAF40();
    entity_velocity();
    reg_a0 = D_0026E9C0;
    reg_a0 += *reg_a4_as_u16_p;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    func_00202B50();
    if ((s16) reg_d0.h[0] < 0x101) {
        func_001BAEC0();
    }
    func_001BA820();
}

void func_001BB560(void) {
    *(u16 *)reg_a4 = 0;
    reg_a4[3] = ENTITY(reg_a6)->move.b.speed;
}

void func_001BB580() {
    s32 direction_between();
    reg_d2.h[0] = 0x7400;
    reg_d3.h[0] = 0x1C00;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_d2.h[0] = 0x7400;
    reg_d3.h[0] = 0x1C00;
    func_00202B50();
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] = (u16) ((s32) reg_d1.h[0] >> 7);
    *(u8 *)(reg_a4 + 3) = (u8) reg_d1.b[0];
    if ((s16) reg_d0.h[0] < 0x101) {
        reg_d0.w = 4;
        boss_movement_start();
    }
    func_001BAF40();
    entity_velocity();
    func_001BA820();
}
