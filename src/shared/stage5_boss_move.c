#include "common.h"
#include "entity.h"

void func_001F3CC0(void);
void func_001F3D30(void);
void func_001F3F10(void);
void func_001F4050();
void func_001F4090();
void func_001F4200(void);
void func_001F4370(void);
void func_001F44E0(void);
void func_001F4630();
void func_001F4770(void);
u8 func_001F48C0(u8 arg0);
void func_001F4A30(void);


void func_001F3A10(void) {
    reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
    reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x14C0;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x7FFF + 0x7181;
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_d1.h[0];
    reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
    reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x7FFF + 0x7B01;
    *(u16 *)(reg_a6 + 0x42) = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x7FFF + 0x6E41;
    *(u16 *)(reg_a6 + 0x44) = (u16) reg_d1.h[0];
    reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
    reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x7FFF + 0x6881;
    *(u16 *)(reg_a6 + 0x62) = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x7FFF + 0x6EC1;
    *(u16 *)(reg_a6 + 0x64) = (u16) reg_d1.h[0];
    reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
    reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x740;
    *(u16 *)(reg_a6 + 0x82) = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x1040;
    *(u16 *)(reg_a6 + 0x84) = (u16) reg_d1.h[0];
    reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
    reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x7FFF + 0x7781;
    *(u16 *)(reg_a6 + 0xA2) = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x14C0;
    *(u16 *)(reg_a6 + 0xA4) = (u16) reg_d1.h[0];
    reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
    reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x7FFF + 0x6541;
    *(u16 *)(reg_a6 + 0xC2) = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x1040;
    *(u16 *)(reg_a6 + 0xC4) = (u16) reg_d1.h[0];
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a6 + 0x1A2) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x1A4) = (u16) reg_d0.h[0];
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a6 + 0x142) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x144) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x162) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x164) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x182) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a6 + 0x184) = (u16) ENTITY(reg_a6)->x.h;
}

s32 rng_next_unsigned();
extern u16 D_0029C068[];

void func_001F3C30() {
    ENTITY(reg_a6)->y.h = 0xB000;
    ENTITY(reg_a6)->x.h = 0x1C00U;
    reg_d0.h[0] = D_0029C068[0];
    ENTITY(reg_a6)->x.h -= reg_d0.h[0];
    rng_next_unsigned();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d0.b[0];
    reg_d0.b[0] += 0x10;
    *(u8 *)(reg_a6 + 0x130) = (u8) reg_d0.b[0];
    reg_d0.b[0] += 0x30;
    *(u8 *)(reg_a6 + 0x13C) = (u8) reg_d0.b[0];
    func_001F3CC0();
}

s32 entity_follow_scroll();                            /* extern */

void func_001F3CC0(void) {
    entity_follow_scroll();
    func_001F3A10();
}


void func_001F3CF0(void) {
    *(s16 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 4) = 0x808;
    *(s16 *)(reg_a4 + 6) = 0x40;
    ENTITY(reg_a6)->move.sb.speed = 0;
    ENTITY(reg_a6)->move.sb.dir = 0;
    func_001F3D30();
}

s32 boss_movement_start();
s32 boss_part_show();
s32 boss_animation_start();
s32 func_0018D2D0();
s32 func_001F56F0();
s32 func_001F57C0();

void func_001F3D30(void) {
    s32 entity_velocity();
    u16 temp_v0;

    temp_v0 = *(u16 *)(reg_a4 + 6);
    if (temp_v0 != 0) {
        *(u16 *)(reg_a4 + 6) = (u16) (temp_v0 - 1);
        if (*(u16 *)(reg_a4 + 6) == 0) {
            func_0018D2D0();
            reg_d0.w = 3;
            boss_animation_start();
            reg_d0.w = 4;
            boss_animation_start();
            reg_d0.w = 0xA;
            boss_part_show();
            reg_d0.w = 0xE;
            boss_part_show();
            *(s16 *)(reg_a6 + 0x172) = 0x1000;
            func_001F56F0();
            func_001F57C0();
            goto block_3;
        }
    } else {
block_3:
        entity_velocity();
        if (*(u16 *)(reg_a4 + 2) == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
            *(u8 *)(reg_a4 + 5) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
                *(u8 *)(reg_a4 + 4) -= 1;
                ENTITY(reg_a6)->move.b.speed += 1;
                if (ENTITY(reg_a6)->move.b.speed == 8) {
                    *(u16 *)(reg_a4 + 4) = 0x303;
                    *(u16 *)(reg_a4 + 2) = 1U;
                }
            }
        } else {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
            *(u8 *)(reg_a4 + 5) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
                ENTITY(reg_a6)->move.b.speed -= 1;
                if (ENTITY(reg_a6)->move.b.speed == 4) {
                    reg_d0.w = 2;
                    boss_movement_start();
                    *(s16 *)reg_a4 = 0;
                }
            }
        }
    }
    func_001F3A10();
}

s32 rng_next_masked();

void func_001F3EC0() {
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
    *(u8 *)reg_a4 = (u8) reg_d0.b[0];
    ENTITY(reg_a6)->move.sb.speed = 4;
    rng_next_masked();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d0.b[0];
    func_001F3F10();
}

s32 rng_next();
s32 func_002024C0();

void func_001F3F10(void) {
    s32 entity_velocity();
    entity_velocity();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x3C00) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= 0x4C00) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x6000) {
        if ((s32) reg_d1.h[0] >= 0x6800) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
    func_001F3A10();
}


void func_001F4030(void) {
    ENTITY(reg_a6)->move.b.speed = 3;
    ENTITY(reg_a6)->move.b.dir = 0x20;
    func_001F4050(3);
}

void func_001F4050() {
    void entity_velocity(void);
    entity_velocity();
}


void func_001F4060(void) {
    u8 val;

    reg_d0.w = 0;
    val = reg_d0.b[0];
    *((u8 *)((void *)reg_a4) + 1) = reg_d0.b[0];
    val = reg_d0.b[0];
    *((u8 *)((void *)reg_a4) + 0) = reg_d0.b[0];
    *((u8 *)((void *)reg_a6) + 0x1B) = 6;
    func_001F4090(val);
}

void func_001F4090() {
    s32 entity_velocity();
    entity_velocity();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < MAIN_OR_DEATH_LABEL(0x3600, 0x4800)) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= MAIN_OR_DEATH_LABEL(0x5200, 0x5600)) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5E00) {
        if ((s32) reg_d1.h[0] >= 0x6200) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
    func_001F3A10();
}


void func_001F41B0() {
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
    *(u8 *)reg_a4 = (u8) reg_d0.b[0];
    ENTITY(reg_a6)->move.sb.speed = 8;
    rng_next_masked();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d0.b[0];
    func_001F4200();
}

void func_001F4200(void) {
    s32 entity_velocity();
    entity_velocity();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x3800) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= 0x5000) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x6400) {
        if ((s32) reg_d1.h[0] >= 0x6C00) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
    func_001F3A10();
}


void func_001F4320() {
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
    *(u8 *)reg_a4 = (u8) reg_d0.b[0];
    ENTITY(reg_a6)->move.sb.speed = 6;
    rng_next_masked();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d0.b[0];
    func_001F4370();
}

void func_001F4370(void) {
    s32 entity_velocity();
    entity_velocity();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x4000) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= 0x4800) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5400) {
        if ((s32) reg_d1.h[0] >= 0x5C00) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
    func_001F3A10();
}

s32 rng_next();                            /* extern */

void func_001F4490(void) {
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
    *(u8 *)reg_a4 = (u8) reg_d0.b[0];
    rng_next();
    reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d0.b[0];
    func_001F44E0();
}

void func_001F44E0(void) {
    s32 entity_velocity();
    entity_velocity();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x4200) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= 0x4600) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x7B80) {
        if ((s32) reg_d1.h[0] >= 0x7C80) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
    func_001F3A10();
}


void func_001F4600(void) {
    u8 value;

    reg_d0.w = 0;
    reg_a4[1] = reg_d0.b[0];
    value = reg_d0.b[0];
    reg_a4[0] = value;
    ENTITY(reg_a6)->move.b.speed = 2;
    func_001F4630(value);
}

void func_001F4630() {
    s32 entity_velocity();
    entity_velocity();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < MAIN_OR_DEATH_LABEL(0x4000, 0x4800)) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= MAIN_OR_DEATH_LABEL(0x4800, 0x5200)) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5200) {
        if ((s32) reg_d1.h[0] >= 0x5600) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
    func_001F3A10();
}


void func_001F4750(void) {
    reg_d0.w = 0;
    reg_a4[1] = reg_d0.b[0];
    reg_a4[0] = reg_d0.b[0];
    func_001F4770();
}

void func_001F4770(void) {
    s32 entity_velocity();
    entity_velocity();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < MAIN_OR_DEATH_LABEL(0x4000, 0x4800)) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= MAIN_OR_DEATH_LABEL(0x4800, 0x5200)) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x6200) {
        if ((s32) reg_d1.h[0] >= 0x6600) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
    func_001F3A10();
}


u8 func_001F4890(void) {
    u8 zero_byte;

    reg_d0.w = 0;
    zero_byte = reg_d0.b[0];
    reg_a4[1] = reg_d0.b[0];
    zero_byte = reg_d0.b[0];
    reg_a4[0] = reg_d0.b[0];
    ENTITY(reg_a6)->move.b.speed = 4;
    return func_001F48C0(zero_byte);
}

u8 func_001F48C0(u8 arg0) {
    s32 entity_velocity();
    entity_velocity();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < MAIN_OR_DEATH_LABEL(0x3600, 0x4800)) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= MAIN_OR_DEATH_LABEL(0x5200, 0x5600)) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5E00) {
        if ((s32) reg_d1.h[0] >= 0x6200) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
    func_001F3A10();
}


void func_001F49E0() {
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
    *(u8 *)reg_a4 = (u8) reg_d0.b[0];
    ENTITY(reg_a6)->move.sb.speed = 4;
    rng_next_masked();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d0.b[0];
    func_001F4A30();
}

void func_001F4A30(void) {
    s32 entity_velocity();
    entity_velocity();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < MAIN_OR_DEATH_LABEL(0x4000, 0x4800)) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= MAIN_OR_DEATH_LABEL(0x4800, 0x5200)) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x4800) {
        if ((s32) reg_d1.h[0] >= 0x5000) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
    func_001F3A10();
}
