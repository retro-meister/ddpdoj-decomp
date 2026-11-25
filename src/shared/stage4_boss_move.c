#include "common.h"
#include "entity.h"

void func_001BE5F0(void);
void func_001BE8F0(void);
void func_001BEA20();
void func_001BEA80(void);
void func_001BEC10(void);
void func_001BEDD0();
void func_001BEE10(void);
void func_001BEE50(void);
void func_001BF080(void);


void func_001BE1E0(void) {
    reg_d0.b[0] = reg_a4[3];
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_tmp.b[0] = reg_a4[5];
    reg_a4[5] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_1;
    reg_a4[5] = reg_a4[4];
    if (reg_d0.b[0] == reg_d1.b[0]) goto block_1;
    if ((s8) reg_d0.b[0] < (s8) reg_d1.b[0]) goto next_1;
    reg_d1.b[0] += 1;
    goto block_1;
next_1:
    reg_d1.b[0] -= 1;
block_1:
    ENTITY(reg_a6)->move.b.speed = reg_d1.b[0];
}


s32 entity_velocity();

void func_001BE270(void) {
    func_001BE1E0();
    entity_velocity();
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_d0.h[0];
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x194);
    *(u16 *)(reg_a6 + 0x22) += reg_d1.h[0];
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x196);
    *(u16 *)(reg_a6 + 0x24) += reg_d1.h[0];
    *(u16 *)(reg_a6 + 0x82) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x84) = (u16) reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x82);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x84);
    reg_tmp.w += 0xF2BFF500;
    *(u16 *)(reg_a6 + 0x82) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x84) = (u16) reg_tmp.h[0];
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x18C);
    *(u16 *)(reg_a6 + 0x82) += reg_d1.h[0];
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x18E);
    *(u16 *)(reg_a6 + 0x84) += reg_d1.h[0];
    *(u16 *)(reg_a6 + 0xA2) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0xA4) = (u16) reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA2);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xA4);
    reg_tmp.w += 0xF3000AC0;
    *(u16 *)(reg_a6 + 0xA2) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA4) = (u16) reg_tmp.h[0];
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x190);
    *(u16 *)(reg_a6 + 0xA2) += reg_d1.h[0];
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x192);
    *(u16 *)(reg_a6 + 0xA4) += reg_d1.h[0];
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x22);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    *(u16 *)(reg_a6 + 0x42) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x44) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x42) -= 0x2200;
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x42);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x44);
    *(u16 *)(reg_a6 + 0x62) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x64) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x62) += 0xA00;
    *(u16 *)(reg_a6 + 0xC2) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0xC4) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0xC2) += 0xA40;
    *(u16 *)(reg_a6 + 0xC4) += 0x7FFF + 0x75C1;
    *(u16 *)(reg_a6 + 0xE2) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0xE4) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0xE2) += 0xA40;
    *(u16 *)(reg_a6 + 0xE4) += 0xA40;
    *(u16 *)(reg_a6 + 0x102) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x104) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x102) += 0x7FFF + 0x7B41;
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.w += 0xEC000000;
    *(u16 *)(reg_a6 + 0x122) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x124) = (u16) reg_d0.h[0];
}

s32 func_001E8710(s32, s32, s32, s32); /* extern */

void func_001BE560(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0;
    ENTITY(reg_a6)->move.sh = 0x20;
    *(s8 *)(reg_a4 + 7) = 0;
    *(s16 *)(reg_a4 + 8) = 0x280;
    *(s8 *)(reg_a4 + 0xB) = 1;
    *(s8 *)(reg_a4 + 0xA) = 0;
    *(s16 *)(reg_a4 + 0xC) = 0x101;
    *(s16 *)(reg_a6 + 0x126) = 0x1C;
    *(s16 *)(reg_a6 + 0x128) = 0;
    func_001E8710(0x101, 1, 0x280, 0x20);
    func_001BE5F0();
}

s32 boss_phase_start();
s32 boss_movement_start();
s32 boss_part_show();
s32 boss_part_hide();
s32 func_0013B2E0();
s32 sprite_palette_load();
s32 velocity_from_dir256();
extern u8 D_0025FEF0[];
extern u8 D_0026F440[];
extern u8 D_0028E855;
extern u16 D_0029C068[];

void func_001BE5F0(void) {
    s32 boss_animation_start();
    if (*(u8 *)(reg_a4 + 7) == 0) {
        *(u8 *)(reg_a4 + 0xA) += 2;
        reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
        reg_d1.w = 0;
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0xA);
        velocity_from_dir256();
        reg_d3.h[0] = (s16) reg_d3.h[0] * 8;
        reg_d1.h[0] = reg_d3.h[0];
        reg_d1.h[0] = (u16) -(s16) reg_d1.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 6);
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 4);
        reg_d1.h[0] += 7;
        if ((s16) reg_d1.h[0] > 0xF) {
            reg_d1.h[0] = 0xF;
        }
        if (0 > (s16) reg_d1.h[0]) {
            reg_d1.h[0] = 0;
        }
        reg_d1.h[0] += reg_d1.h[0];
        reg_d1.h[0] += reg_d1.h[0];
        *(u16 *)(reg_a6 + 0x126) = (u16) reg_d1.h[0];
        reg_d0.h[0] = 0x1C00;
        reg_d0.h[0] += reg_d3.h[0];
        reg_d0.h[0] -= D_0029C068[0];
        ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
        reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
        ENTITY(reg_a6)->y.h += reg_d0.h[0];
        *(u16 *)(reg_a4 + 8) -= 5;
        if ((s16) *(u16 *)(reg_a4 + 8) <= 0) {
            *(u16 *)(reg_a4 + 8) = 0U;
            *(u8 *)(reg_a4 + 7) = 1U;
            reg_d0.w = 0xA;
            boss_part_hide();
            reg_d0.w = 0xB;
            boss_part_show();
        }
    }
    if (*(u8 *)(reg_a4 + 7) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xD);
        *(u8 *)(reg_a4 + 0xD) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
            *(u16 *)(reg_a6 + 0x128) += 4;
            if ((s16) *(u16 *)(reg_a6 + 0x128) > 0x1C) {
                *(u16 *)(reg_a6 + 0x128) = 0U;
                reg_d0.w = 0xB;
                boss_part_hide();
                reg_d0.h[0] = 0x15;
                reg_a0 = (u8 *)D_0025FEF0;
                sprite_palette_load();
                D_0028E855 |= 0x10;
                reg_d0.w = 1;
                D_0028E855 |= 2;
                boss_movement_start();
                reg_d0.w = 3;
                boss_phase_start();
                reg_d0.w = 9;
                boss_animation_start();
                reg_d0.w = 0xA;
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
                *(u16 *)(reg_a6 + 0x20) = 0xA001;
                *(u16 *)(reg_a6 + 0x40) = 0xA001;
                *(u16 *)(reg_a6 + 0x60) = 0xA001;
                reg_a0 = (u8 *)D_0026F440;
                func_0013B2E0();
            }
        }
    }
    func_001BE270();
}


void func_001BE8D0(void) {
    *(u8 *)(reg_a4 + 3) = 4;
    *(u16 *)(reg_a4 + 4) = 0;
    *(u16 *)(reg_a4 + 6) = 0;
    func_001BE8F0();
}

s32 direction_turn_toward();
extern u8 D_0026F480[];

void func_001BE8F0(void) {
    s32 direction_between(void *);
    s32 func_00202B70(u16, void *);
    u16 temp_a0;

    reg_a0 = D_0026F480;
    reg_a0 += *(u16 *)(reg_a4 + 6);
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between(reg_a6);
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_a0 = D_0026F480;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_a0 += *(u16 *)(reg_a4 + 6);
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    func_00202B70(temp_a0, reg_a6);
    if ((s16) reg_d0.h[0] < 0x201) {
        *(u16 *)(reg_a4 + 6) += 4;
        *(u16 *)(reg_a4 + 6) &= 0xF;
    }
    func_001BE270();
}


void func_001BE9F0(void) {
    ENTITY(reg_a6)->move.b.speed = 0;
    ENTITY(reg_a6)->move.b.dir = 0x20;
    reg_a4[0x3] = 0x20;
    *(u16 *)(reg_a4 + 0x4) = 0x303;
    func_001BEA20(0x20);
}


void func_001BEA20() {
    func_001BE270();
}


void func_001BEA30(void) {
    s32 boss_animation_start(s32);
    *(s8 *)(reg_a4 + 3) = 4;
    *(s16 *)(reg_a4 + 4) = 0x202;
    *(s8 *)(reg_a4 + 7) = 0;
    reg_d0.w = 0;
    boss_animation_start(4);
    func_001BEA80();
}

s32 boss_movement_stop();
extern u8 D_0028DC84[];

void func_001BEA80(void) {
    s32 direction_between();
    s32 func_00202B70();
    reg_a0 = D_0028DC84;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] -= D_0029C068[0];
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_a0 = D_0028DC84;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] -= D_0029C068[0];
    func_00202B70();
    if ((s16) reg_d0.h[0] < 0x1401) {
        if (*(u8 *)(reg_a4 + 7) == 0) {
            *(u8 *)(reg_a4 + 7) = 1U;
            *(s16 *)(reg_a4 + 4) = 0;
        }
        *(s8 *)(reg_a4 + 3) = 4;
        if ((s16) reg_d0.h[0] > 0x200) {
            func_001BE270();
            return;
        }
        ENTITY(reg_a6)->move.sb.speed = 0;
        reg_d0.w = 5;
        boss_phase_start();
        boss_movement_stop();
        func_001BE270();
        return;
    }
    *(s8 *)(reg_a4 + 3) = 0x20;
    func_001BE270();
}


void func_001BEBD0(void) {
    ENTITY(reg_a6)->move.sb.speed = 0;
    ENTITY(reg_a6)->move.sb.dir = 0x20;
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0;
    *(s16 *)(reg_a4 + 6) = 0;
    *(s8 *)(reg_a6 + 0x3B) = 6;
    func_001BEC10();
}

s32 func_00201D10();
extern u8 D_0026F490[];

void func_001BEC10(void) {
    s32 direction_between();
    s32 func_00202B70();
    reg_a0 = (u8 *)D_0026F490;
    reg_a0 += *(u16 *)(reg_a4 + 6);
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += *(u16 *)(reg_a6 + 0x194);
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x196);
    direction_between();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3A);
    direction_turn_toward();
    *(u8 *)(reg_a6 + 0x3A) = (u8) reg_d1.b[0];
    reg_a0 = (u8 *)D_0026F490;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += *(u16 *)(reg_a6 + 0x194);
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x196);
    reg_a0 += *(u16 *)(reg_a4 + 6);
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    func_00202B70();
    if ((s16) reg_d0.h[0] < 0x401) {
        *(u16 *)(reg_a4 + 6) += 4;
        *(u16 *)(reg_a4 + 6) &= 0xF;
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3B);
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x3A);
    func_00201D10();
    *(u16 *)(reg_a6 + 0x194) += reg_d2.h[0];
    *(u16 *)(reg_a6 + 0x196) += reg_d3.h[0];
    func_001BE270();
}


void func_001BEDA0(void) {
    ENTITY(reg_a6)->move.b.dir = 0x20;
    reg_a4[0x3] = 1;
    *(u16 *)&reg_a4[0x4] = 0;
    func_001BEDD0(0x20);
}

void func_001BEDD0() {
    func_001BE270();
}


void func_001BEDE0(void) {
    ENTITY(reg_a6)->move.b.speed = 0;
    ENTITY(reg_a6)->move.b.dir = 0x20;
    reg_a4[3] = 0;
    *(u16 *)&reg_a4[4] = 0;
    func_001BEE10();
}

void func_001BEE10(void) {
    func_001BE270();
}

typedef struct WorkRegA4 {
    u8 unk0[3];
    u8 unk3;
    u16 unk4;
    u16 unk6;
    u16 unk8;
} WorkRegA4;



void func_001BEE20(void) {
    ((WorkRegA4 *)reg_a4)->unk3 = 0;
    ((WorkRegA4 *)reg_a4)->unk4 = 0;
    ((WorkRegA4 *)reg_a4)->unk6 = 0;
    ((WorkRegA4 *)reg_a4)->unk8 = 0x808;
    func_001BEE50();
}

extern u8 D_0026F4A0[];

void func_001BEE50(void) {
    s32 direction_between();
    s32 func_00202B70();
    u8 temp_v0;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 9);
    *(u8 *)(reg_a4 + 9) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
        temp_v0 = *(u8 *)(reg_a6 + 0x3B);
        if (temp_v0 != 2) {
            *(u8 *)(reg_a6 + 0x3B) = (u8) (temp_v0 - 1);
            if ((s8) *(u8 *)(reg_a6 + 0x3B) < 3) {
                *(u8 *)(reg_a6 + 0x3B) = 2U;
            }
        }
    }
    reg_a0 = (u8 *)D_0026F4A0;
    reg_a0 += *(u16 *)(reg_a4 + 6);
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += *(u16 *)(reg_a6 + 0x194);
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x196);
    direction_between();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3A);
    direction_turn_toward();
    *(u8 *)(reg_a6 + 0x3A) = (u8) reg_d1.b[0];
    reg_a0 = (u8 *)D_0026F4A0;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += *(u16 *)(reg_a6 + 0x194);
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x196);
    reg_a0 += *(u16 *)(reg_a4 + 6);
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    func_00202B70();
    if ((s16) reg_d0.h[0] < 0x201) {
        *(u16 *)(reg_a4 + 6) += 4;
        *(u16 *)(reg_a4 + 6) &= 0xF;
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3B);
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x3A);
    func_00201D10();
    *(u16 *)(reg_a6 + 0x194) += reg_d2.h[0];
    *(u16 *)(reg_a6 + 0x196) += reg_d3.h[0];
    func_001BE270();
}


void func_001BF040(void) {
    ENTITY(reg_a6)->move.sb.speed = 0;
    ENTITY(reg_a6)->move.sb.dir = 0x20;
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0;
    *(s16 *)(reg_a4 + 6) = 4;
    *(s8 *)(reg_a6 + 0x3B) = 4;
    func_001BF080();
}

extern u8 D_0026F4B0[];

void func_001BF080(void) {
    s32 direction_between();
    s32 func_00202B70();
    reg_a0 = (u8 *)D_0026F4B0;
    reg_a0 += *(u16 *)(reg_a4 + 6);
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += *(u16 *)(reg_a6 + 0x194);
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x196);
    direction_between();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3A);
    direction_turn_toward();
    *(u8 *)(reg_a6 + 0x3A) = (u8) reg_d1.b[0];
    reg_a0 = (u8 *)D_0026F4B0;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += *(u16 *)(reg_a6 + 0x194);
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x196);
    reg_a0 += *(u16 *)(reg_a4 + 6);
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    func_00202B70();
    if ((s16) reg_d0.h[0] < 0x401) {
        *(u16 *)(reg_a4 + 6) += 4;
        if ((s16) *(u16 *)(reg_a4 + 6) > 0x1C) {
            *(u16 *)(reg_a4 + 6) = 0U;
        }
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3B);
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x3A);
    func_00201D10();
    *(u16 *)(reg_a6 + 0x194) += reg_d2.h[0];
    *(u16 *)(reg_a6 + 0x196) += reg_d3.h[0];
    func_001BE270();
}
