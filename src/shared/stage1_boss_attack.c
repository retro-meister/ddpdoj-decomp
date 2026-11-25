#include "common.h"
#include "entity.h"

void func_001B5110(void);
void func_001B5990(void);
void func_001B5BB0(void);
void func_001B5E70(void);
void func_001B6060(void);
void func_001B64D0(void);
void func_001B6820(void);
void func_001B69E0(void);
void func_001B6BA0(void);
void func_001B6D30(void);
void func_001B7700();

extern u16 *reg_a4_as_u16_p;

void func_001B4BD0(void) {
    *reg_a4_as_u16_p = 0;
}


s32 func_001713B0();
s32 enemy_switch_target_player();
s32 rng_next();
s32 func_00202730();
extern u16 D_0026E070[];
extern u16 D_0026E080[];

void func_001B4BE0(void) {
    enemy_switch_target_player();
    *(s16 *)(reg_a4 + 2) = 0x1001;
    *(s16 *)(reg_a4 + 4) = 0;
    *(s16 *)(reg_a4 + 8) = 8;
    *(u8 *)(reg_a4 + 0xB) = 0x80U;
    func_00202730();
    if (cond_flag == 0) {
        rng_next();
        reg_d1.b[0] += reg_d0.b[0];
        *(u8 *)(reg_a4 + 0xB) = (u8) reg_d1.b[0];
    }
    func_001713B0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)(D_0026E070);
    *(u16 *)(reg_a4 + 0xC) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(D_0026E080);
    *(u16 *)(reg_a4 + 6) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
}

s32 bullet_fire256_2way();
extern u16 D_0026E090[];
extern u16 D_0026E092[];
extern u16 D_0026E094[];
extern u16 D_0026E096[];
extern u16 D_0026E098[];
extern u16 D_0026E09A[];
extern u16 D_0026E09C[];
extern u16 D_0026E09E[];

void func_001B4D00(void) {
    u16 temp_a1;
    u16 temp_a2;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_d1.w = 0;
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0xB);
        reg_d0.h[0] = *(u16 *)(reg_a4 + 4);
        temp_a2 = reg_d0.h[0];
        reg_tmp.w = reg_d0.w;
        reg_d0.h[1] = temp_a2;
        reg_d0.h[0] = 3;
        temp_a1 = *(u16 *)(reg_a4 + 8);
        reg_d6.h[0] = temp_a1;
        reg_d3.h[1] = D_0026E098[0];
        reg_d3.h[0] = D_0026E09A[0];
        reg_d4.w = 0;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] += 2;
        bullet_fire256_2way();
        reg_d3.h[1] = D_0026E09C[0];
        reg_d3.h[0] = D_0026E09E[0];
        reg_d1.h[0] -= 4;
        bullet_fire256_2way();
        reg_d1.h[0] += 2;
        reg_d1.b[0] += reg_d6.b[0];
        reg_d3.h[1] = D_0026E090[0];
        reg_d3.h[0] = D_0026E092[0];
        bullet_fire256_2way();
        reg_d1.b[0] -= reg_d6.b[0];
        reg_d3.h[1] = D_0026E094[0];
        reg_d3.h[0] = D_0026E096[0];
        reg_d1.b[0] -= reg_d6.b[0];
        bullet_fire256_2way();
        *(u16 *)(reg_a4 + 4) += 4;
        reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
        *(u16 *)(reg_a4 + 8) += reg_d0.h[0];
        *(u16 *)(reg_a4 + 6) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 6) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}

void bullet_fire_3way(void);

void func_001B4EB0(void) {
    bullet_fire_3way();
}

extern u16 D_0026E0B0[];

void func_001B4EC0(void) {
    u32 temp_a0;
    *(s8 *)(reg_a4 + 4) = 0;
    *(s8 *)(reg_a4 + 7) = 0;
    func_001713B0();
    reg_a0 = (u8 *)(D_0026E0B0);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    temp_a0 = *(u16 *)(reg_a4 + 0xC);
    *(u16 *)(reg_a4 + 0xC) = (u16) (temp_a0 + reg_d0.h[0]);
    *(u8 *)(reg_a4 + 9) = 0x20U;
    *(u8 *)(reg_a4 + 8) = 0x20U;
    *(u8 *)(reg_a4 + 0xB) = 0x20U;
    *(u8 *)(reg_a4 + 0xA) = 0x20U;
    rng_next();
    *(u8 *)(reg_a4 + 9) += reg_d0.b[0];
    rng_next();
    *(u8 *)(reg_a4 + 8) += reg_d0.b[0];
    rng_next();
    *(u8 *)(reg_a4 + 0xB) += reg_d0.b[0];
    rng_next();
    *(u8 *)(reg_a4 + 0xA) += reg_d0.b[0];
}

s32 direction_turn_toward();                            /* extern */

void func_001B4FD0(void) {
    if (*(u8 *)(reg_a4 + 7) != 0) {
        func_001B5110();
        return;
    }
    reg_d1.b[0] = *(u8 *)(reg_a4 + 9);
    reg_d0.b[0] = ENTITY(reg_a6)[6].offset_y.b[1];
    direction_turn_toward();
    ENTITY(reg_a6)[6].offset_y.b[1] = (u8) reg_d1.b[0];
    reg_d1.b[0] = *(u8 *)(reg_a4 + 8);
    reg_d0.b[0] = ENTITY(reg_a6)[6].offset_y.b[0];
    direction_turn_toward();
    ENTITY(reg_a6)[6].offset_y.b[0] = (u8) reg_d1.b[0];
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0xB);
    reg_d0.b[0] = ENTITY(reg_a6)[6].offset_x.b[1];
    direction_turn_toward();
    ENTITY(reg_a6)[6].offset_x.b[1] = (u8) reg_d1.b[0];
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0xA);
    reg_d0.b[0] = ENTITY(reg_a6)[6].offset_x.b[0];
    direction_turn_toward();
    ENTITY(reg_a6)[6].offset_x.b[0] = (u8) reg_d1.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a4 + 9);
    if (ENTITY(reg_a6)[6].offset_y.b[1] == reg_d0.b[0]) {
        reg_d0.b[0] = *(u8 *)(reg_a4 + 8);
        if (ENTITY(reg_a6)[6].offset_y.b[0] == reg_d0.b[0]) {
            reg_d0.b[0] = *(u8 *)(reg_a4 + 0xB);
            if (ENTITY(reg_a6)[6].offset_x.b[1] == reg_d0.b[0]) {
                reg_d0.b[0] = *(u8 *)(reg_a4 + 0xA);
                if (ENTITY(reg_a6)[6].offset_x.b[0] == reg_d0.b[0]) {
                    *(u8 *)(reg_a4 + 7) = 1U;
                }
            }
        }
    }
}

extern u16 D_0026E0A0[];
extern u16 D_0026E0A2[];
extern u16 D_0026E0A4[];
extern u16 D_0026E0A6[];
extern u16 D_0026E0A8[];
extern u16 D_0026E0AA[];
extern u16 D_0026E0AC[];
extern u16 D_0026E0AE[];
extern u16 g_bullets_blocked;

void func_001B5110(void) {
    u16 temp_a0;
    u16 temp_a1;

    if (g_bullets_blocked == 0) {
        if (!(*(u8 *)(reg_a4 + 4) & 1)) {
            ENTITY(reg_a6)[6].offset_y.b[1] += 1;
            if ((s8) ENTITY(reg_a6)[6].offset_y.b[1] >= 0x30) {
                *(u8 *)(reg_a4 + 4) |= 1;
            }
        } else {
            ENTITY(reg_a6)[6].offset_y.b[1] -= 1;
            if ((s8) ENTITY(reg_a6)[6].offset_y.b[1] < 0x11) {
                *(u8 *)(reg_a4 + 4) &= 0xE;
            }
        }
        if (!(*(u8 *)(reg_a4 + 4) & 2)) {
            ENTITY(reg_a6)[6].offset_y.b[0] += 1;
            if ((s8) ENTITY(reg_a6)[6].offset_y.b[0] >= 0x30) {
                *(u8 *)(reg_a4 + 4) |= 2;
            }
        } else {
            ENTITY(reg_a6)[6].offset_y.b[0] -= 1;
            if ((s8) ENTITY(reg_a6)[6].offset_y.b[0] < 0x11) {
                *(u8 *)(reg_a4 + 4) &= 0xD;
            }
        }
        if (!(*(u8 *)(reg_a4 + 4) & 4)) {
            ENTITY(reg_a6)[6].offset_x.b[1] += 1;
            if ((s8) ENTITY(reg_a6)[6].offset_x.b[1] >= 0x30) {
                *(u8 *)(reg_a4 + 4) |= 4;
            }
        } else {
            ENTITY(reg_a6)[6].offset_x.b[1] -= 1;
            if ((s8) ENTITY(reg_a6)[6].offset_x.b[1] < 0x11) {
                *(u8 *)(reg_a4 + 4) &= 0xB;
            }
        }
        if (!(*(u8 *)(reg_a4 + 4) & 8)) {
            ENTITY(reg_a6)[6].offset_x.b[0] += 1;
            if ((s8) ENTITY(reg_a6)[6].offset_x.b[0] >= 0x30) {
                *(u8 *)(reg_a4 + 4) |= 8;
            }
        } else {
            ENTITY(reg_a6)[6].offset_x.b[0] -= 1;
            if ((s8) ENTITY(reg_a6)[6].offset_x.b[0] < 0x11) {
                *(u8 *)(reg_a4 + 4) &= 7;
            }
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
            temp_a1 = reg_d0.h[0];
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = temp_a1;
            reg_d0.h[0] = 0xC;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            temp_a0 = ENTITY(reg_a6)->x.h;
            reg_d2.h[0] = temp_a0;
            reg_d3.h[1] = D_0026E0A0[0];
            reg_d3.h[0] = D_0026E0A2[0];
            reg_d1.w = 0;
            reg_d1.b[0] = ENTITY(reg_a6)[6].offset_y.b[1];
            func_001B4EB0();
            reg_d3.h[1] = D_0026E0A4[0];
            reg_d3.h[0] = D_0026E0A6[0];
            reg_d1.b[0] = ENTITY(reg_a6)[6].offset_y.b[0];
            func_001B4EB0();
            reg_d3.h[1] = D_0026E0A8[0];
            reg_d3.h[0] = D_0026E0AA[0];
            reg_d1.b[0] = ENTITY(reg_a6)[6].offset_x.b[1];
            func_001B4EB0();
            reg_d3.h[1] = D_0026E0AC[0];
            reg_d3.h[0] = D_0026E0AE[0];
            reg_d1.b[0] = ENTITY(reg_a6)[6].offset_x.b[0];
            func_001B4EB0();
            *(u8 *)(reg_a4 + 5) -= 1;
            if ((s8) *(u8 *)(reg_a4 + 5) == 0) {
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

void func_001B5460(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    *(s8 *)(reg_a4 + 5) = 0;
    *(s8 *)(reg_a4 + 4) = 0x20;
    *(u16 *)(reg_a4 + 6) = 0x101;
    *(u16 *)(reg_a4 + 8) = 4;
    *(u16 *)(reg_a4 + 0xA) = 0x10;
    *(u16 *)(reg_a4 + 0xC) = 0xFFFC;
}

s32 bullet_fire256_fixed();
s32 func_00201200();
s32 aim_at_player();
s32 direction_turn_toward();
extern u16 D_0026E0C0[];

void func_001B54B0(void) {
    u16 temp_a0_2;
    u8 temp_a0;

    if (*(u8 *)(reg_a4 + 5) == 0) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            *(u8 *)(reg_a4 + 5) = 1U;
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
                *(u8 *)(reg_a4 + 4) = (u8) reg_d1.b[0];
            }
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 5);
    if (temp_a0 == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
        *(u8 *)(reg_a4 + 7) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            reg_d0.w = 0;
            reg_d1.w = 0;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 4);
            reg_d0.h[0] = ENTITY(reg_a6)[5].sprite.h;
            reg_d0.h[0] += 0x20;
            direction_turn_toward();
            reg_d0.h[0] = reg_d1.h[0];
            reg_d0.h[0] = (u16) reg_d0.b[0];
            reg_d0.h[0] -= 0x20;
            ENTITY(reg_a6)[5].sprite.h = (u16) reg_d0.h[0];
            if (*(u8 *)(reg_a4 + 4) == reg_d1.b[0]) {
                *(u8 *)(reg_a4 + 5) = 2U;
            }
        }
    }
    if (*(u8 *)(reg_a4 + 5) == 2) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 9);
        *(u8 *)(reg_a4 + 9) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
            reg_d0.h[0] += 0x14;
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 7;
            func_00201200();
            reg_d5.b[0] -= 1;
            reg_d5.b[0] += *(u8 *)(reg_a4 + 4);
            reg_a0 = (u8 *)(D_0026E0C0);
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
            *(u16 *)(reg_a4 + 0xC) += 2;
            *(u16 *)(reg_a4 + 0xA) -= 1;
            if (*(u16 *)(reg_a4 + 0xA) == 0) {
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

s32 bullet_fire256_fast();
extern u16 g_loop;

void func_001B57D0() {
    u32 tmp;

    reg_d0.h[0] = *(u16 *) (reg_a4 + 0x10);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d1.b[0] = reg_a4[0xD];
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

void func_001B5890(void) {
    u16 temp_a0;
    u8 temp_a0_2;

    enemy_switch_target_player();
    *(s16 *)(reg_a4 + 4) = 4;
    *(s16 *)(reg_a4 + 6) = 0x820;
    rng_next_bit();
    reg_d0.b[0] -= 1;
    *(u8 *)(reg_a4 + 6) += reg_d0.b[0];
    reg_d0.h[1] = ENTITY(reg_a6)[1].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[1].x.h;
    reg_d0.w += 0xF6C00140;
    *(u16 *)(reg_a4 + 8) = (u16) reg_d0.h[1];
    temp_a0 = reg_d0.h[0];
    *(u16 *)(reg_a4 + 0xA) = temp_a0;
    *(u8 *)(reg_a4 + 0xD) = 0x80U;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0xA);
    aim256_at_player();
    if (cond_flag != 0) {
        func_001B5990();
        return;
    }
    *(u8 *)(reg_a4 + 0xD) = (u8) reg_d1.b[0];
    temp_a0_2 = *(u8 *)(reg_a4 + 2);
    if (temp_a0_2 != 2) {
        func_001B5990();
    }
}


void func_001B5990(void) {
    u8 temp_v1;

    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        func_001B4BD0();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
        if (g_bullets_blocked == 0) {
            reg_d0.w = 0x100007;
            reg_d2.h[1] = *(u16 *)(reg_a4 + 8);
            reg_d2.h[0] = *(u16 *)(reg_a4 + 0xA);
            reg_d3.w = 0;
            reg_d1.w = 0;
            temp_v1 = *(u8 *)(reg_a4 + 2);
            if (temp_v1 == 0) {
                reg_d0.w = 0x10007;
                reg_d6.w = reg_d0.w;
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xD);
            } else if (temp_v1 == 1) {
                func_001B57D0(reg_a4);
            } else {
                func_001B57D0(reg_a4);
            }
        }
        *(u16 *)(reg_a4 + 0x10) += 4;
        *(u8 *)(reg_a4 + 3) -= 1;
        if (*(u8 *)(reg_a4 + 3) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}


void func_001B5AB0(void) {
    u16 temp_a0;
    u8 temp_a0_2;

    enemy_switch_target_player();
    *(s16 *)(reg_a4 + 4) = 4;
    *(s16 *)(reg_a4 + 6) = 0x820;
    rng_next_bit();
    reg_d0.b[0] -= 1;
    *(u8 *)(reg_a4 + 6) += reg_d0.b[0];
    reg_d0.h[1] = ENTITY(reg_a6)[3].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[3].x.h;
    reg_d0.w += 0xF6BFFEC0;
    *(u16 *)(reg_a4 + 8) = (u16) reg_d0.h[1];
    temp_a0 = reg_d0.h[0];
    *(u16 *)(reg_a4 + 0xA) = temp_a0;
    *(u8 *)(reg_a4 + 0xD) = 0x80U;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0xA);
    aim256_at_player();
    if (cond_flag != 0) {
        func_001B5990();
        return;
    }
    *(u8 *)(reg_a4 + 0xD) = (u8) reg_d1.b[0];
    temp_a0_2 = *(u8 *)(reg_a4 + 2);
    if (temp_a0_2 != 2) {
        func_001B5BB0();
    }
}

void func_001B5BB0(void) {
    u8 temp_v1;

    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        func_001B4BD0();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
        if (g_bullets_blocked == 0) {
            reg_d0.w = 0x100007;
            reg_d2.h[1] = *(u16 *)(reg_a4 + 8);
            reg_d2.h[0] = *(u16 *)(reg_a4 + 0xA);
            reg_d3.w = 0;
            reg_d1.w = 0;
            temp_v1 = *(u8 *)(reg_a4 + 2);
            if (temp_v1 == 0) {
                reg_d0.w = 0x10007;
                reg_d6.w = reg_d0.w;
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xD);
            } else if (temp_v1 == 1) {
                func_001B57D0(reg_a4);
            } else {
                func_001B57D0(reg_a4);
            }
        }
        *(u16 *)(reg_a4 + 0x10) += 4;
        *(u8 *)(reg_a4 + 3) -= 1;
        if (*(u8 *)(reg_a4 + 3) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}

void func_001B5CD0(void) {
    *(s8 *)(reg_a4 + 2) = 6;
    *(u16 *)(reg_a4 + 0x14) = 0xFFFA;
    if (g_loop != 0) {
        *(s8 *)(reg_a4 + 2) = 3;
        *(u16 *)(reg_a4 + 0x14) = 0xFFFB;
    }
}


void func_001B5D20() {
    reg_d1.w = 0;
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0xB);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x14);
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

void func_001B5DB0(void) {
    *(s8 *)(reg_a4 + 3) = 0x38;
    *(s16 *)(reg_a4 + 4) = 0;
    *(s16 *)(reg_a4 + 6) = 8;
    *(u8 *)(reg_a4 + 0xB) = 0x40U;
    rng_next();
    reg_d0.b[0] = reg_d0.sb[0] * 4;
    *(u8 *)(reg_a4 + 0xB) += reg_d0.b[0];
    *(s16 *)(reg_a4 + 0xE) = 0x404;
    *(s16 *)(reg_a4 + 0x10) = 0x505;
    *(s8 *)(reg_a4 + 0x13) = 1;
    *(s8 *)(reg_a4 + 0x12) = 0;
    func_001B5CD0();
    func_001713B0();
    *(u8 *)(reg_a4 + 0x10) = *(D_0028DC38 + reg_d0.b[0]);
    func_001B5E70();
}


void func_001B5E70() {
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
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xF);
            *(u8 *)(reg_a4 + 0xF) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0xF) = (u8) *(u8 *)(reg_a4 + 0xE);
                var_a0 = reg_a4 + 2;
                temp_v1 = *(u8 *)(reg_a4 + 2);
                if (temp_v1 != 3) {
                    *(u8 *)(reg_a4 + 2) = (u8) (temp_v1 - 1);
                }
            }
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x11);
            *(u8 *)(reg_a4 + 0x11) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0x11) = (u8) *(u8 *)(reg_a4 + 0x10);
            }
            func_001B5D20();
            *(u8 *)(reg_a4 + 0xB) += 0xB;
        }
    }
}


void func_001B5F90(void) {
    *(s8 *)(reg_a4 + 3) = 0x20;
    *(s16 *)(reg_a4 + 4) = 0;
    *(s16 *)(reg_a4 + 6) = 8;
    *(s16 *)(reg_a4 + 0xE) = 0x404;
    *(u8 *)(reg_a4 + 0xB) = 0xC0U;
    rng_next();
    reg_d0.b[0] = reg_d0.sb[0] * 4;
    *(u8 *)(reg_a4 + 0xB) += reg_d0.b[0];
    *(s16 *)(reg_a4 + 0xE) = 0x404;
    *(s16 *)(reg_a4 + 0x10) = 0x505;
    *(s8 *)(reg_a4 + 0x13) = 1;
    *(s8 *)(reg_a4 + 0x12) = 0;
    func_001B5CD0();
    func_001713B0();
    *(u8 *)(reg_a4 + 0x10) = *(D_0028DC38 + reg_d0.b[0]);
    func_001B6060();
}

void func_001B6060() {
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
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xF);
            *(u8 *)(reg_a4 + 0xF) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0xF) = (u8) *(u8 *)(reg_a4 + 0xE);
                var_a0 = reg_a4 + 2;
                temp_v1 = *(u8 *)(reg_a4 + 2);
                if (temp_v1 != 3) {
                    *(u8 *)(reg_a4 + 2) = (u8) (temp_v1 - 1);
                }
            }
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x11);
            *(u8 *)(reg_a4 + 0x11) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0x11) = (u8) *(u8 *)(reg_a4 + 0x10);
            }
            func_001B5D20();
            *(u8 *)(reg_a4 + 0xB) -= 0xB;
        }
    }
}

void func_001B6180(void) {
    *(s8 *)(reg_a4 + 5) = 0;
    *(s8 *)(reg_a4 + 4) = 0x20;
    *(u16 *)(reg_a4 + 6) = 0x202;
    *(u16 *)(reg_a4 + 8) = 8;
    *(u16 *)(reg_a4 + 0xA) = 6;
    *(u16 *)(reg_a4 + 0xC) = 0xFFF8;
}

void func_001B61D0(void) {
    u16 temp_a0;

    if (*(u8 *)(reg_a4 + 5) == 0) {
        *(u8 *)(reg_a4 + 5) = 1U;
    }
    if (*(u8 *)(reg_a4 + 5) == 1) {
        *(u8 *)(reg_a4 + 5) = 2U;
    }
    if (*(u8 *)(reg_a4 + 5) == 2) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 9);
        *(u8 *)(reg_a4 + 9) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
            reg_d0.h[0] += 0x14;
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 7;
            func_00201200();
            reg_d5.b[0] -= 1;
            reg_d5.b[0] += *(u8 *)(reg_a4 + 4);
            reg_a0 = (u8 *)(D_0026E0C0);
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
            *(u16 *)(reg_a4 + 0xC) += 1;
            *(u16 *)(reg_a4 + 0xA) -= 1;
            if (*(u16 *)(reg_a4 + 0xA) == 0) {
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

s32 rng_next_unsigned();
extern u16 D_0026E100[];
extern u16 D_0026E110[];

void func_001B63D0(void) {
    func_001713B0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)(D_0026E110);
    *(u16 *)(reg_a4 + 2) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(D_0026E100);
    *(u16 *)(reg_a4 + 4) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(s16 *)(reg_a4 + 6) = 0x18;
    *(u16 *)(reg_a4 + 8) = 0U;
    *(s16 *)(reg_a4 + 0xA) = 2;
    rng_next_unsigned();
    reg_d0.h[0] &= 1;
    *(u16 *)(reg_a4 + 8) = (u16) reg_d0.h[0];
    func_001B64D0();
}

s32 func_0014E030();

void func_001B64D0(void) {
    reg_tmp.b[0] = reg_a4[7];
    reg_a4[7] -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        return;
    }
    reg_a4[7] = reg_a4[6];
    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        goto skip_1;
    }
    if (*(u16 *)(reg_a4 + 8) != 0) {
        goto skip_1;
    }
    reg_d0.w = 0x1E;
    func_0014E030();
    reg_d0.h[1] = ENTITY(reg_a6)[1].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[1].x.h;
    reg_d0.w += 0xF6C00140;
    *(u16 *)(reg_a0 + 0x16) = reg_d0.h[1];
    *(u16 *)(reg_a0 + 0x18) = reg_d0.h[0];
    *(u16 *)(reg_a0 + 0x1A) = 0x2020;
    *(u16 *)(reg_a0 + 0x1C) = *(u16 *)(reg_a4 + 4);
    *(u16 *)(reg_a0 + 0x1E) = *(u16 *)(reg_a4 + 2);
    if (g_loop == 0) {
        goto skip_1;
    }
    reg_d0.w = 0x1E;
    func_0014E030();
    reg_d0.h[1] = ENTITY(reg_a6)[1].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[1].x.h;
    reg_d0.w += 0xF6C00140;
    *(u16 *)(reg_a0 + 0x16) = reg_d0.h[1];
    *(u16 *)(reg_a0 + 0x18) = reg_d0.h[0];
    *(u16 *)(reg_a0 + 0x1A) = 0x1A28;
    *(u16 *)(reg_a0 + 0x1C) = *(u16 *)(reg_a4 + 4);
    *(u16 *)(reg_a0 + 0x1E) = *(u16 *)(reg_a4 + 2);
skip_1:
    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        goto skip_2;
    }
    if (*(u16 *)(reg_a4 + 8) == 0) {
        goto skip_2;
    }
    reg_d0.w = 0x1E;
    func_0014E030();
    reg_d0.h[1] = ENTITY(reg_a6)[3].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[3].x.h;
    reg_d0.w += 0xF6BFFEC0;
    *(u16 *)(reg_a0 + 0x16) = reg_d0.h[1];
    *(u16 *)(reg_a0 + 0x18) = reg_d0.h[0];
    *(u16 *)(reg_a0 + 0x1A) = 0x2020;
    *(u16 *)(reg_a0 + 0x1C) = *(u16 *)(reg_a4 + 4);
    *(u16 *)(reg_a0 + 0x1E) = *(u16 *)(reg_a4 + 2);
    if (g_loop == 0) {
        goto skip_2;
    }
    reg_d0.w = 0x1E;
    func_0014E030();
    reg_d0.h[1] = ENTITY(reg_a6)[3].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[3].x.h;
    reg_d0.w += 0xF6BFFEC0;
    *(u16 *)(reg_a0 + 0x16) = reg_d0.h[1];
    *(u16 *)(reg_a0 + 0x18) = reg_d0.h[0];
    *(u16 *)(reg_a0 + 0x1A) = 0x1A18;
    *(u16 *)(reg_a0 + 0x1C) = *(u16 *)(reg_a4 + 4);
    *(u16 *)(reg_a0 + 0x1E) = *(u16 *)(reg_a4 + 2);
skip_2:
    *(u16 *)(reg_a4 + 4) += 1;
    *(u16 *)(reg_a4 + 8) += 1;
    *(u16 *)(reg_a4 + 8) &= 1;
    *(u16 *)(reg_a4 + 0xA) -= 1;
    if (*(u16 *)(reg_a4 + 0xA) == 0) {
        *(u16 *)reg_a4 = 0;
    }
}

extern u8 D_0026E120[];

void func_001B67A0(void) {
    func_001713B0();
    reg_a0 = D_0026E120;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    *(u16 *)(reg_a4 + 8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0xA) = *(u16 *)reg_a0;
    func_001B6820();
}

s32 bullet_fire256();

void func_001B6820() {
    u16 temp_a2;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 9);
    *(u8 *)(reg_a4 + 9) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
        reg_d1.w = 0;
        reg_d1.b[0] = 0x80;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        temp_a2 = ENTITY(reg_a6)->x.h;
        reg_d2.h[0] = temp_a2;
        reg_d0.w = 0x80009;
        reg_d1.b[0] = 0x60;
        reg_d3.h[1] = D_0026E094[0];
        reg_d3.h[0] = D_0026E096[0];
        reg_d4.w = 0;
        bullet_fire256();
        reg_d1.b[0] = 0x70;
        reg_d3.h[1] = D_0026E09C[0];
        reg_d3.h[0] = D_0026E09E[0];
        bullet_fire256();
        reg_d1.b[0] = 0xA0;
        reg_d3.h[1] = D_0026E090[0];
        reg_d3.h[0] = D_0026E092[0];
        bullet_fire256();
        reg_d1.b[0] = 0x90;
        reg_d3.h[1] = D_0026E098[0];
        reg_d3.h[0] = D_0026E09A[0];
        bullet_fire256();
        *(u16 *)(reg_a4 + 0xA) -= 1;
        if (*(u16 *)(reg_a4 + 0xA) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}

extern u16 D_0026E140[];

void func_001B6950(void) {
    u16 temp_a0;

    func_001713B0();
    reg_a0 = (u8 *)(D_0026E140);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    *(u16 *)(reg_a4 + 8) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    temp_a0 = *(u16 *)reg_a0;
    *(u16 *)(reg_a4 + 0xA) = temp_a0;
    *(s8 *)(reg_a4 + 0xD) = 0x20;
    func_001B69E0();
}

void func_001B69E0() {
    u16 temp_a2;
    u8 temp_a0;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 9);
    *(u8 *)(reg_a4 + 9) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        aim256_at_player();
        if (cond_flag == 0) {
            *(u8 *)(reg_a4 + 0xD) = (u8) reg_d1.b[0];
        }
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        temp_a2 = ENTITY(reg_a6)->x.h;
        reg_d2.h[0] = temp_a2;
        reg_d0.w = 0x20009;
        reg_d4.w = 0;
        reg_d1.w = 0;
        temp_a0 = *(u8 *)(reg_a4 + 0xD);
        reg_d1.b[0] = temp_a0;
        reg_d3.h[1] = D_0026E094[0];
        reg_d3.h[0] = D_0026E096[0];
        bullet_fire256();
        reg_d3.h[1] = D_0026E09C[0];
        reg_d3.h[0] = D_0026E09E[0];
        bullet_fire256();
        reg_d3.h[1] = D_0026E090[0];
        reg_d3.h[0] = D_0026E092[0];
        bullet_fire256();
        reg_d3.h[1] = D_0026E098[0];
        reg_d3.h[0] = D_0026E09A[0];
        bullet_fire256();
        *(u16 *)(reg_a4 + 0xA) -= 1;
        if (*(u16 *)(reg_a4 + 0xA) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}

extern u16 D_0026E160[];

void func_001B6B20(void) {
    *(s16 *)(reg_a4 + 2) = 8;
    func_001713B0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)D_0026E160;
    *(u16 *)(reg_a4 + 4) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)((u16 *)reg_a0) + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    func_001B6BA0();
}

extern u16 D_0026E170[];
extern u16 D_0026E172[];
extern u16 D_0026E174[];
extern u16 D_0026E176[];
extern u16 D_0026E178[];
extern u16 D_0026E17A[];
extern u16 D_0026E17C[];
extern u16 D_0026E17E[];

void func_001B6BA0(void) {
    u16 temp_a2;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        temp_a2 = ENTITY(reg_a6)->x.h;
        reg_d1.w = 0;
        reg_d2.h[0] = temp_a2;
        reg_d0.w = 0x80013;
        reg_d1.b[0] = 0x80;
        reg_d3.h[1] = D_0026E174[0];
        reg_d3.h[0] = D_0026E176[0];
        reg_d4.w = 0;
        bullet_fire256_fixed();
        reg_d3.h[1] = D_0026E17C[0];
        reg_d3.h[0] = D_0026E17E[0];
        bullet_fire256_fixed();
        reg_d3.h[1] = D_0026E170[0];
        reg_d3.h[0] = D_0026E172[0];
        bullet_fire256_fixed();
        reg_d3.h[1] = D_0026E178[0];
        reg_d3.h[0] = D_0026E17A[0];
        bullet_fire256_fixed();
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}

extern u16 D_0026E180[];

void func_001B6CB0(void) {
    func_001713B0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)D_0026E180;
    *(u16 *)(reg_a4 + 2) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)((u16 *)reg_a0) + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(s16 *)(reg_a4 + 4) = 2;
    func_001B6D30();
}

void func_001B6D30(void) {
    u16 temp_a2;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        temp_a2 = ENTITY(reg_a6)->x.h;
        reg_d1.w = 0;
        reg_d2.h[0] = temp_a2;
        reg_d0.w = 0x13;
        reg_d1.b[0] = 0x80;
        reg_d3.h[1] = D_0026E170[0];
        reg_d3.h[0] = D_0026E172[0];
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
        reg_d3.h[1] = D_0026E174[0];
        reg_d3.h[0] = D_0026E176[0];
        bullet_fire256_2way();
        reg_d1.b[0] += 0xC;
        bullet_fire256_2way();
        reg_d1.b[0] += 0xC;
        bullet_fire256_2way();
        reg_d1.b[0] -= 0x24;
        bullet_fire256_2way();
        reg_d1.b[0] -= 0xC;
        bullet_fire256_2way();
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}

void func_001B6E90(void) {
    *(s16 *)(reg_a4 + 8) = 8;
    *(s16 *)(reg_a4 + 0xA) = 0;
    *(s16 *)(reg_a4 + 0xC) = 0;
    reg_d0.h[0] = ENTITY(reg_a6)[5].sprite.h;
    reg_d0.h[0] += 0x20;
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += reg_d0.b[0];
    *(u8 *)(reg_a4 + 0x11) = (u8) reg_d0.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)[5].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[5].x.h;
    aim256_at_player();
    if (cond_flag == 0) {
        *(u8 *)(reg_a4 + 0x11) = (u8) reg_d1.b[0];
    }
    enemy_switch_target_player();
}

s32 rng_next_word();
extern u16 D_00259970[];

void func_001B6F40(void) {
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
        reg_a2 = (u8 *)(D_0026E0C0);
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
        reg_a0 = (u8 *)(D_00259970);
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
            *(u16 *)(reg_a4 + 0x12) = (u16) reg_d0.h[0];
            reg_d0.w = 0;
            reg_d0.b[0] = *(u8 *)(reg_a4 + 5);
            reg_d0.h[0] -= 0x14;
            temp_a2 = reg_d0.h[0];
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = temp_a2;
            reg_d0.h[0] = 7;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x11);
            reg_a0 = (u8 *)(D_0026E0C0);
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
            reg_d2.h[0] += *(u16 *)(reg_a4 + 0x12);
            reg_d3.w = 0;
            reg_d4.w = 0;
            bullet_fire256_fixed();
            *(u8 *)(reg_a4 + 5) += 2;
            *(u16 *)(reg_a4 + 0xA) += 2;
            *(u16 *)(reg_a4 + 0xC) += 2;
            rng_next_word();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            *(u16 *)(reg_a4 + 0x12) = (u16) reg_d0.h[0];
            reg_d0.w = 0;
            reg_d0.b[0] = *(u8 *)(reg_a4 + 5);
            reg_d0.h[0] -= 0x15;
            temp_a2_2 = reg_d0.h[0];
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = temp_a2_2;
            reg_d0.h[0] = 7;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x11);
            reg_a0 = (u8 *)(D_0026E0C0);
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
            reg_d2.h[0] += *(u16 *)(reg_a4 + 0x12);
            reg_d3.w = 0;
            reg_d4.w = 0;
            bullet_fire256_fixed();
            rng_next_word();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            *(u16 *)(reg_a4 + 0x12) = (u16) reg_d0.h[0];
            reg_d0.w = 0;
            reg_d0.b[0] = *(u8 *)(reg_a4 + 5);
            reg_d0.h[0] -= 0x16;
            temp_a2_3 = reg_d0.h[0];
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = temp_a2_3;
            reg_d0.h[0] = 7;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x11);
            reg_a0 = (u8 *)(D_0026E0C0);
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
            reg_d2.h[0] += *(u16 *)(reg_a4 + 0x12);
            reg_d3.w = 0;
            reg_d4.w = 0;
            bullet_fire256_fixed();
            *(u16 *)(reg_a4 + 6) -= 1;
        } while (*(u16 *)(reg_a4 + 6) != 0);
    }
    *(s16 *)reg_a4 = 0;
}

void func_001B7620(void) {
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

typedef struct WorkRegA4 {
    u8 pad0[4];
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
} WorkRegA4;



void func_001B76D0(void) {
    ((WorkRegA4 *)reg_a4)->unk4 = 0x9050;
    ((WorkRegA4 *)reg_a4)->unk6 = 0;
    ((WorkRegA4 *)reg_a4)->unk8 = 1;
    ((WorkRegA4 *)reg_a4)->unkA = 0xC;
    func_001B7700(1, 0x9050);
}


void func_001B7700() {
    u8 temp_v1;

    if (*(u8 *)(reg_a4 + 9) == 0) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            temp_v1 = *(u8 *)(reg_a4 + 4);
            if ((s32) temp_v1 > 0x10) {
                *(u8 *)(reg_a4 + 4) = (u8) (temp_v1 - 4);
            }
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
            goto block_5;
        }
    } else {
block_5:
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xB);
        *(u8 *)(reg_a4 + 0xB) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xB) = (u8) *(u8 *)(reg_a4 + 0xA);
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
                    func_001B7620();
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
                    func_001B7620();
                }
            }
            *(u8 *)(reg_a4 + 9) -= 1;
            if (*(u8 *)(reg_a4 + 9) == 0) {
                *(u16 *)(reg_a4 + 6) += 1;
                *(u16 *)(reg_a4 + 6) &= 1;
            }
        }
    }
}
