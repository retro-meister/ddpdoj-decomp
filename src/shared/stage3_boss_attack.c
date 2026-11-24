#include "common.h"
#include "entity.h"

void func_001CE800(void);
void func_001CF800(void);
void func_001CFF10(void);
void func_001D03B0(void);
void func_001D08C0(void);
void func_001D0E60(void);

extern s16 *reg_a4_as_s16_p;

void func_001CE7F0(void) {
    reg_a4_as_s16_p[1] = 0;
    func_001CE800();
}

s32 boss_part_hide();
s32 func_0014E030();
s32 rng_next();

void func_001CE800(void) {
    u32 temp_s0;

    if (*(u16 *)(reg_a4 + 2) != 0) {
        reg_d0.w = 2;
        boss_part_hide();
        reg_d0.w = 3;
        boss_part_hide();
        *(s16 *)reg_a4 = 0;
        return;
    }
    reg_d0.h[0] = 0x99;
    func_0014E030();
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[1] += 0x4C0;
    reg_d0.h[0] += 0x7FFF + 0x7601;
    *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x68);
    *(u16 *)(reg_a0 + 0x1A) = (u16) reg_d0.h[0];
    *(s16 *)(reg_a0 + 0x34) = 0x184;
    rng_next();
    temp_s0 = reg_d0.w;
    *(u8 *)(reg_a0 + 0x37) = (u8) reg_d0.b[0];
    reg_d0.h[0] = 0x99;
    func_0014E030();
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[1] += 0x4C0;
    reg_d0.h[0] += 0xA00;
    *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x4000;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x68);
    *(u16 *)(reg_a0 + 0x1A) = (u16) reg_d0.h[0];
    *(s16 *)(reg_a0 + 0x34) = 0x17C;
    reg_d0.w = temp_s0;
    *(u8 *)(reg_a0 + 0x37) = (u8) reg_d0.b[0];
    *(u16 *)(reg_a4 + 2) = 1U;
}

void func_001CE980(void) {
    void bullet_fire256_fast(void);
    s32 status = reg_d1.b[0];

    if (status < 0x20 || status > 0xE0) {
        reg_d0.w += 0x80000;
    }
    bullet_fire256_fast();
}

s32 func_001713C0();
s32 rng_next_unsigned();
extern u8 D_0026CC40[];
extern u32 D_0028DB20;
extern u16 g_loop;

void func_001CE9B0(void) {
    s32 temp_a1;
    u16 *temp_a0;
    u16 temp_a2;
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a2 = reg_d0.h[0];
    temp_a1 = temp_a2 & ~3;
    reg_a0 = *(u8 **)(D_0026CC40 + temp_a1);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DB20 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.b[0] = 8;
    if (g_loop != 0) {
        reg_d0.b[0] = 4;
    }
    *(u8 *)(reg_a4 + 6) = (u8) reg_d0.b[0];
    rng_next_unsigned();
    *(u8 *)(reg_a4 + 0x17) = (u8) reg_d0.b[0];
    reg_d1.h[0] = 3;
    rng_next_unsigned();
    if ((s8) reg_d0.b[0] < 0) {
        reg_d1.h[0] = 0xFFFD;
    }
    *(u8 *)(reg_a4 + 0x16) = (u8) reg_d1.b[0];
    *(s16 *)(reg_a4 + 0x18) = 0x606;
}

s32 enemy_switch_target_player();

void func_001CEAD0(void) {
    u16 var_a0;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 6);
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0x17);
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        var_a0 = ENTITY(reg_a6)->x.h;
        reg_d2.h[0] = var_a0;
        reg_d3.w = 0xE2000000;
        reg_d7.w = 3;
        reg_d4.w = 0;
        do {
            reg_d0.h[1] = *(u16 *)(reg_a4 + 8);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xA);
            func_001CE980();
            var_a0 = (u32)reg_d1.h[0] + 0x40;
            reg_d1.h[0] = var_a0;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        reg_d0.b[0] = *(u8 *)(reg_a4 + 0x16);
        *(u8 *)(reg_a4 + 0x17) += reg_d0.b[0];
        *(u8 *)(reg_a4 + 0x19) -= 1;
        if (*(u8 *)(reg_a4 + 0x19) == 0) {
            *(u8 *)(reg_a4 + 0x19) = (u8) *(u8 *)(reg_a4 + 0x18);
            *(u8 *)(reg_a4 + 3) = 0x12U;
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if (reg_tmp.b[0] == 0) {
            *(u8 *)(reg_a4 + 0x16) *= -1;
            enemy_switch_target_player();
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        }
    }
}

s32 bullet_fire256_fixed();

void func_001CEC30(void) {
    s32 bullet_fire256_fast();
    u32 tmp;

    if (g_loop != 0) goto next_4;
    reg_d5.w = 0xFFFE0004;
    reg_d7.h[0] = 2;
    reg_d6.h[0] = 0x55;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (!(reg_tmp.w < 0x8C00U)) goto loop_1;
    reg_d5.w = 0xFFFE0004;
    reg_d7.h[0] = 3;
    reg_d6.h[0] = 0x40;
loop_1:
    reg_d0.w = reg_d5.w;
    if (reg_d1.b[0] < 0x40) goto next_2;
    if (reg_d1.b[0] <= 0xC0) goto next_3;
next_2:
    reg_d0.w += 0x80000;
next_3:
    bullet_fire256_fixed();
    reg_d1.b[0] += reg_d6.b[0];
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    goto block_rts;
next_4:
    reg_d5.w = 0xFFFE0004;
    reg_d7.h[0] = 4;
    reg_d6.h[0] = 0x33;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (!(reg_tmp.w < 0x8C00U)) goto loop_5;
    reg_d5.w = 0xFFFE0004;
    reg_d7.h[0] = 5;
    reg_d6.h[0] = 0x2A;
loop_5:
    reg_d0.w = reg_d5.w;
    if (reg_d1.b[0] < 0x40) goto next_6;
    if (reg_d1.b[0] <= 0xC0) goto next_7;
next_6:
    reg_d0.w += 0x100000;
next_7:
    bullet_fire256_fast();
    reg_d1.b[0] += reg_d6.b[0];
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_5;
block_rts:
    return;
}

s32 rng_next_bit();
extern u8 D_0026CD60[];
extern u32 D_0028DB24;

void func_001CEDD0(void) {
    s32 temp_a1;
    u16 *temp_a0;
    u16 temp_a2;
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a2 = reg_d0.h[0];
    temp_a1 = temp_a2 & ~3;
    reg_a0 = *(u8 **)(D_0026CD60 + temp_a1);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DB24 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    rng_next_bit();
    *(u8 *)(reg_a4 + 0x11) = (u8) reg_d0.b[0];
    rng_next_unsigned();
    *(u8 *)(reg_a4 + 0x17) = (u8) reg_d0.b[0];
    *(s8 *)(reg_a4 + 0x16) = 5;
    reg_d0.b[0] *= -1;
    *(u8 *)(reg_a4 + 0x19) = (u8) reg_d0.b[0];
    *(u8 *)(reg_a4 + 0x18) = 0xFB;
    if (g_loop != 0) {
        *(s8 *)(reg_a4 + 2) = 3;
    }
}

extern u16 D_002594F0[];

void func_001CEF00(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
        if ((u32) reg_tmp.w < 0x8C00U) {
            *(u8 *)(reg_a4 + 0x16) = 5U;
            *(u8 *)(reg_a4 + 0x18) = 0xFBU;
            *(u8 *)(reg_a4 + 2) = 3U;
            if (g_loop != 0) {
                *(u8 *)(reg_a4 + 2) = 3U;
            }
        }
        reg_a3 = (u8 *)(D_002594F0);
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0xB0);
        reg_d0.h[0] = reg_d1.h[0];
        reg_d0.h[0] &= 0x3E;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
        reg_d3.h[0] = ((((u16)reg_d0.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(((u16)reg_d0.h[0]) + 2) & ~1)) : *(u16 *)reg_a3;
        reg_d3.w += 0x11000080;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x22);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x24);
        reg_d4.w = 0;
        reg_d0.b[0] = *(u8 *)(reg_a4 + 0x16);
        *(u8 *)(reg_a4 + 0x17) += reg_d0.b[0];
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0x17);
        func_001CEC30();
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0xB2);
        reg_d5.h[0] = reg_d1.h[0];
        reg_d5.h[0] &= 0x3E;
        reg_d5.h[0] += reg_d5.h[0];
        reg_d3.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a3;
        reg_d3.h[0] = ((((u16)reg_d5.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(((u16)reg_d5.h[0]) + 2) & ~1)) : *(u16 *)reg_a3;
        reg_d3.w += 0x1100FF80;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x42);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x44);
        reg_d4.w = 0;
        reg_d0.b[0] = *(u8 *)(reg_a4 + 0x18);
        *(u8 *)(reg_a4 + 0x19) += reg_d0.b[0];
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0x19);
        func_001CEC30();
        enemy_switch_target_player();
    }
}

extern u8 D_0026CE00[];
extern u32 D_0028DB28;
extern u16 D_0028DB70[];
extern u32 D_0028DB78;

void func_001CF1A0(void) {
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = *(u8 **)(D_0026CE00 + (reg_d0.h[0] & ~3));
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DB28 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *)(D_0028DB70);
    reg_d0.w = ((u32) D_0028DB78 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x10B);
    *(u8 *)(reg_a4 + 2) -= reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12A);
    reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
    *(u8 *)(reg_a4 + 3) += reg_d0.b[0];
    *(u8 *)(reg_a4 + 7) += reg_d0.b[0];
}

void func_001CF320(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 0xB);
        reg_d0.h[0] = 0x9A;
        func_0014E030();
        reg_d0.h[1] = ENTITY(reg_a6)->y.h;
        reg_d0.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[1] += 0x7FFF + 0x5C81;
        reg_d0.h[0] += 0x7FFF + 0x7801;
        *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
        reg_d0.b[0] = 0xD;
        reg_d0.b[0] += *(u8 *)(reg_a6 + 0x10A);
        *(u8 *)(reg_a0 + 0x1B) = reg_d0.b[0];
        *(u8 *)(reg_a0 + 0x1A) = 0x80;
        *(u16 *)(reg_a0 + 0x1C) = (u16) *(u16 *)(reg_a4 + 0xC);
        reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xC);
        *(u16 *)(reg_a4 + 0xC) -= 4;
        if ((s32) reg_tmp.h[0] < 4) {
            *(u16 *)(reg_a4 + 0xC) = 8U;
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if (reg_tmp.b[0] == 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        }
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
    *(u8 *)(reg_a4 + 7) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 0xB);
        reg_d0.h[0] = 0x9A;
        func_0014E030();
        reg_d0.h[1] = ENTITY(reg_a6)->y.h;
        reg_d0.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[1] += 0x7FFF + 0x5C81;
        reg_d0.h[0] += 0x800;
        *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
        reg_d0.b[0] = 0xD;
        reg_d0.b[0] += *(u8 *)(reg_a6 + 0x10A);
        *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
        *(u8 *)(reg_a0 + 0x1A) = 0x80;
        *(u16 *)(reg_a0 + 0x1C) = (u16) *(u16 *)(reg_a4 + 0xC);
        reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xC);
        *(u16 *)(reg_a4 + 0xC) -= 4;
        if ((s32) reg_tmp.h[0] < 4) {
            *(u16 *)(reg_a4 + 0xC) = 8U;
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 9);
        *(u8 *)(reg_a4 + 9) -= 1;
        if (reg_tmp.b[0] == 0) {
            *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
        }
    }
}

extern u8 D_0026CE20[];
extern u32 D_0028DB7C;
extern u16 D_0028DB80[];
extern u32 D_0028DB84;
extern u16 D_0028DB88[];
extern u32 D_0028DB90;

void func_001CF5B0(void) {
    u16 *temp_a0;
    u16 *temp_s0;
    u16 temp_a1;
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_a0 = (u8 *)(D_0028DB80);
    reg_d0.w = ((u32) D_0028DB84 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    temp_s0 = (u16 *)(reg_a1);
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a1 = reg_d0.h[0];
    reg_a0 = *(u8 **)(D_0026CE20 + (temp_a1 & ~3));
    reg_a1 = (u8 *)(temp_s0);
    reg_d0.w = ((u32) D_0028DB7C >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *)(D_0028DB88);
    reg_d0.w = ((u32) D_0028DB90 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x107);
    *(u8 *)(reg_a4 + 5) += reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x106);
    *(u8 *)(reg_a4 + 7) -= reg_d0.b[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x108);
    *(u16 *)(reg_a4 + 8) += reg_d0.h[0];
    *(u16 *)(reg_a4 + 0xC) += reg_d0.h[0];
    *(u16 *)(reg_a4 + 0x10) += reg_d0.h[0];
    *(u16 *)(reg_a4 + 0x14) += reg_d0.h[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12A);
    reg_d0.b[0] = (s8) reg_d0.b[0] * 8;
    *(u8 *)(reg_a4 + 3) += reg_d0.b[0];
    func_001CF800();
}

s32 boss_attack_stop();
s32 bullet_fire256_2way();
s32 bullet_fire256_3way();
s32 direction256_between();
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];

void func_001CF800(void) {
    s32 bullet_fire256_fast();
    s16 *t1;
    s16 *t2;
    s16 *v1;
    u16 t3;
    u16 t4;
    u16 t5;
    u16 t6;
    u16 t7;
    u32 t8;
    u32 t9;
    u8 t10;
    u8 t11;
    u8 t12;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 7);
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
        if (*(u8 *)(reg_a5 + 2) != 0) {
            t1 = (s16 *)(reg_a1);
            reg_a1 = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(t1);
        }
        v1 = (s16 *)(reg_a0);
        if ((*(s16 *)((u8 *)(v1) + (0))) >= 0) {
            t2 = (s16 *)(reg_a1);
            if (*t2 < 0) {
                reg_a1 = (u8 *)(v1);
                reg_a0 = (u8 *)(t2);
                goto next_1;
            }
        } else {
next_1:
            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
            t8 = reg_d2.w;
            reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
            t9 = reg_d3.w;
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.h[0] += 0x400;
            reg_d1.h[0] += 0x7FFF + 0x7D01;
            direction256_between();
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d4.w = 0;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 8);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xA);
            reg_d3.w = 0x0400FD00;
            bullet_fire256_fast();
            reg_d2.w = t8;
            reg_d3.w = t9;
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.h[0] += 0x400;
            reg_d1.h[0] += 0x300;
            direction256_between();
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d4.w = 0;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 8);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xA);
            reg_d3.w = 0x04000300;
            bullet_fire256_fast();
            enemy_switch_target_player();
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x19);
            reg_d6.h[0] = reg_d1.h[0];
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d3.w = 0xFE00FD00;
            reg_d4.w = 0;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xC);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xE);
            bullet_fire256_2way();
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x10);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x12);
            reg_d1.h[0] += 4;
            bullet_fire256_2way();
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xC);
            t3 = *(u16 *)(reg_a4 + 0xE);
            reg_d0.h[0] = t3;
            reg_d0.w -= 0x80000;
            reg_d1.h[0] += 4;
            bullet_fire256_2way();
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x10);
            t4 = *(u16 *)(reg_a4 + 0x12);
            reg_d0.h[0] = t4;
            reg_d0.w -= 0x80000;
            reg_d1.h[0] += 4;
            bullet_fire256_2way();
            reg_d1.h[0] = reg_d6.h[0];
            reg_d1.b[0] *= -1;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xC);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xE);
            reg_d3.h[0] = 0x300;
            bullet_fire256_2way();
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x10);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x12);
            reg_d1.h[0] -= 4;
            bullet_fire256_2way();
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xC);
            t5 = *(u16 *)(reg_a4 + 0xE);
            reg_d0.h[0] = t5;
            reg_d0.w -= 0x80000;
            reg_d1.h[0] -= 4;
            bullet_fire256_2way();
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x10);
            t6 = *(u16 *)(reg_a4 + 0x12);
            reg_d0.h[0] = t6;
            reg_d0.w -= 0x80000;
            reg_d1.h[0] -= 4;
            bullet_fire256_2way();
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x14);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x16);
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x18);
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d3.w = 0xF800FD00;
            bullet_fire256_3way();
            reg_d1.h[0] -= 0x10;
            bullet_fire256_3way();
            reg_d1.h[0] -= 0x10;
            bullet_fire256_3way();
            reg_d3.h[0] = 0x300;
            reg_d1.b[0] *= -1;
            bullet_fire256_3way();
            reg_d1.h[0] -= 0x10;
            bullet_fire256_3way();
            reg_d1.h[0] -= 0x10;
            bullet_fire256_3way();
            reg_d0.b[0] = reg_a4[0x1D];
            reg_a4[0x19] -= reg_d0.b[0];
            if (reg_a4[0x19] > 0xC0) {
                reg_a4[0x19] = 0xC0;
                goto next_11;
            }
            if (reg_a4[0x19] >= 0x40) {
                goto skip_1;
            }
            reg_a4[0x19] = 0x40;
next_11:
            reg_a4[0x1D] *= -1;
skip_1:
            reg_d0.b[0] = reg_a4[0x1C];
            reg_a4[0x18] -= reg_d0.b[0];
            if (reg_a4[0x18] > 0xC0) {
                reg_a4[0x18] = 0xC0;
                goto next_12;
            }
            if (reg_a4[0x18] >= 0x40) {
                goto skip_2;
            }
            reg_a4[0x18] = 0x40;
next_12:
            reg_a4[0x1C] *= -1;
skip_2:;
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if (reg_tmp.b[0] == 0) {
            t10 = *(u8 *)(reg_a6 + 0x107);
            if ((s32) t10 < 0x60) {
                *(u8 *)(reg_a6 + 0x107) = (u8) (t10 + 0x10);
            }
            t11 = *(u8 *)(reg_a6 + 0x106);
            if ((s32) t11 < 4) {
                *(u8 *)(reg_a6 + 0x106) = (u8) (t11 - 2);
            }
            t7 = *(u16 *)(reg_a6 + 0x108);
            if ((s32) t7 < 5) {
                *(u16 *)(reg_a6 + 0x108) = (u16) (t7 + 1);
            }
            t12 = *(u8 *)(reg_a6 + 0x10B);
            if ((s32) t12 < 0xA) {
                *(u8 *)(reg_a6 + 0x10B) = (u8) (t12 + 2);
            }
            reg_d0.w = 4;
            boss_attack_stop();
            reg_d0.w = 3;
            boss_attack_stop();
        }
    }
}

extern u8 D_0026CF40[];
extern u32 D_0028DB94;
extern u16 D_0028DB98[];
extern u32 D_0028DB9C;

void func_001CFD70(void) {
    u16 *temp_a0;
    u16 *temp_s0;
    u16 temp_a1;
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_a0 = (u8 *)(D_0028DB98);
    reg_d0.w = ((u32) D_0028DB9C >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    temp_s0 = (u16 *)(reg_a1);
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a1 = reg_d0.h[0];
    reg_a0 = *(u8 **)(D_0026CF40 + (temp_a1 & ~3));
    reg_a1 = (u8 *)(temp_s0);
    reg_d0.w = ((u32) D_0028DB94 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12B);
    *(u8 *)(reg_a4 + 0xB) += reg_d0.b[0];
    *(u8 *)(reg_a4 + 0xA) += reg_d0.b[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x126);
    *(u16 *)(reg_a4 + 0xC) += reg_d0.h[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12A);
    *(u8 *)(reg_a4 + 3) -= reg_d0.b[0];
    func_001CFF10();
}

extern s16 *reg_save_atmp;

void func_001CFF10(void) {
    s16 *temp_a0;
    u16 temp_v0;
    u16 temp_v0_3;
    u16 temp_v0_4;
    u8 temp_v0_2;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 9);
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
        switch (*(u8 *)(reg_a5 + 2)) { case 0: break; default:
            reg_save_atmp = (s16 *)(reg_a1);
            reg_a1 = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(reg_save_atmp);
        }
        if (*(s16 *)reg_a0 >= 0) {
            temp_a0 = (s16 *)(reg_a1);
            if (*temp_a0 < 0) {
                reg_a1 = (u8 *)(reg_a0);
                reg_save_atmp = (s16 *)(temp_a0);
                reg_a0 = (u8 *)(temp_a0);
                goto block_6;
            }
        } else {
block_6:
            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
            reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.h[0] += 0x7FFF + 0x6201;
            direction256_between();
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d3.w = 0xE2000000;
            reg_d4.w = (u32) reg_a6;
            reg_d0.h[0] = *(u16 *)(reg_a4 + 6);
            reg_d0.h[0] -= *(u16 *)(reg_a4 + 4);
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += *(u16 *)(reg_a4 + 0xC);
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 0xB;
            bullet_fire256_fixed();
        }
        reg_tmp.h[0] = *(u16 *)(reg_a4 + 4);
        *(u16 *)(reg_a4 + 4) -= 1;
        switch (reg_tmp.h[0]) {
        case 0:
            enemy_switch_target_player();
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 8);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xE);
            *(u16 *)(reg_a4 + 6) += reg_d0.h[0];
            if ((s32) *(u16 *)(reg_a4 + 6) > 0xC) {
                *(u16 *)(reg_a4 + 6) = 0xCU;
            }
            *(u16 *)(reg_a4 + 4) = (u16) *(u16 *)(reg_a4 + 6);
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xB);
            *(u8 *)(reg_a4 + 0xB) -= 1;
            if (reg_tmp.b[0] == 0) {
                temp_v0 = *(u16 *)(reg_a6 + 0x126);
                if ((s32) temp_v0 < 6) {
                    *(u16 *)(reg_a6 + 0x126) = (u16) (temp_v0 + 3);
                }
                temp_v0_2 = *(u8 *)(reg_a6 + 0x12A);
                if ((s32) temp_v0_2 < 0x20) {
                    *(u8 *)(reg_a6 + 0x12A) = (u8) (temp_v0_2 + 8);
                }
                temp_v0_3 = *(u16 *)(reg_a6 + 0x10C);
                if ((s32) temp_v0_3 < 0xF) {
                    *(u16 *)(reg_a6 + 0x10C) = (u16) (temp_v0_3 + 3);
                }
                temp_v0_4 = *(u16 *)(reg_a6 + 0x10E);
                if ((s32) temp_v0_4 < 6) {
                    *(u16 *)(reg_a6 + 0x10E) = (u16) (temp_v0_4 + 2);
                    *(u16 *)(reg_a6 + 0x110) += 4;
                }
                reg_d0.w = 6;
                boss_attack_stop();
                reg_d0.w = 7;
                boss_attack_stop();
            }
            break;
        }
    }
}

void bullet_fire256(void);

void func_001D01D0(void) {
    bullet_fire256();
}

extern u8 D_0026CFE0[];
extern u32 D_0028DBA0;
extern u16 D_0028DBA4[];
extern u32 D_0028DBA8;

void func_001D01E0(void) {
    u16 *temp_a0;
    u16 *temp_s0;
    u16 temp_a1;
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_a0 = (u8 *)(D_0028DBA4);
    reg_d0.w = ((u32) D_0028DBA8 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    temp_s0 = (u16 *)(reg_a1);
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a1 = reg_d0.h[0];
    reg_a0 = *(u8 **)(D_0026CFE0 + (temp_a1 & ~3));
    reg_a1 = (u8 *)(temp_s0);
    reg_d0.w = ((u32) D_0028DBA0 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x10C);
    *(u16 *)(reg_a4 + 6) += reg_d0.h[0];
    *(u16 *)(reg_a4 + 0xA) += reg_d0.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x10E);
    *(u16 *)(reg_a4 + 0xE) += reg_d0.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x110);
    *(u16 *)(reg_a4 + 0x10) += reg_d0.h[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x12A);
    *(u8 *)(reg_a4 + 3) -= reg_d0.b[0];
    *(u8 *)(reg_a4 + 5) -= reg_d0.b[0];
    func_001D03B0();
}


void func_001D03B0(void) {
    u16 var_a0_3;
    u8 *var_a0_4;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 4);
        reg_a3 = (u8 *)(D_002594F0);
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0xB0);
        reg_d0.h[0] = reg_d1.h[0];
        reg_d0.h[0] &= 0x3E;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
        reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a3;
        reg_d3.w += 0x11000080;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x22);
        var_a0_3 = *(u16 *)(reg_a6 + 0x24);
        reg_d4.w = (u32) reg_a6;
        reg_d1.h[0] += reg_d1.h[0];
        reg_d2.h[0] = var_a0_3;
        reg_d4.w += 0x20;
        reg_d1.h[0] += reg_d1.h[0];
        reg_d1.h[0] -= *(u16 *)(reg_a4 + 0x10);
        reg_d7.h[0] = *(u16 *)(reg_a4 + 0xE);
        do {
            if (!(reg_d7.w & 1)) {
                reg_d0.h[1] = *(u16 *)(reg_a4 + 6);
                reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
                func_001D01D0();
                reg_d0.w += 0x30000;
                func_001D01D0();
                reg_d0.w += 0xFFFD0000;
            } else {
                reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
                reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
                func_001D01D0();
            }
            reg_d1.b[0] += 4;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
        var_a0_4 = (u8 *)(reg_a6);
        reg_a3 = (u8 *)(D_002594F0);
        reg_d1.h[0] = (*(u16 *)((u8 *)(var_a0_4) + (0xB2)));
        reg_d3.w = 0x1100FF80;
        reg_d5.h[0] = reg_d1.h[0];
        reg_d5.h[0] &= 0x3E;
        reg_d5.h[0] += reg_d5.h[0];
        reg_d2.h[1] = (*(u16 *)((u8 *)(var_a0_4) + (0x42)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(var_a0_4) + (0x44)));
        reg_d1.h[0] += reg_d1.h[0];
        reg_d4.w = (u32) var_a0_4;
        reg_d4.w += 0x40;
        reg_d1.h[0] += reg_d1.h[0];
        reg_d1.h[0] += *(u16 *)(reg_a4 + 0x10);
        reg_d7.h[0] = *(u16 *)(reg_a4 + 0xE);
        do {
            if (!(reg_d7.w & 1)) {
                reg_d0.h[1] = *(u16 *)(reg_a4 + 6);
                reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
                func_001D01D0();
                reg_d0.w += 0x30000;
                func_001D01D0();
                reg_d0.w += 0xFFFD0000;
            } else {
                reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
                reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
                func_001D01D0();
            }
            var_a0_4 = (u8 *)(reg_d1.b[0] - 4);
            reg_d1.b[0] = (u8) var_a0_4;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
}

extern u8 D_0026D080[];
extern u32 D_0028DBAC;
extern u16 D_0028DBB0[];
extern u32 D_0028DBB4;
extern u16 D_0028DBB8[];
extern u32 D_0028DBBC;

void func_001D0700(void) {
    u16 *temp_a0;
    u16 *temp_s0;
    u16 temp_a1;
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_a0 = (u8 *)(D_0028DBB0);
    reg_d0.w = ((u32) D_0028DBB4 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    temp_s0 = (u16 *)(reg_a1);
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a1 = reg_d0.h[0];
    reg_a0 = *(u8 **)(D_0026D080 + (temp_a1 & ~3));
    reg_a1 = (u8 *)(temp_s0);
    reg_d0.w = ((u32) D_0028DBAC >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *)(D_0028DBB8);
    reg_d0.w = ((u32) D_0028DBBC >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x112);
    *(u16 *)(reg_a4 + 0xE) += reg_d0.h[0];
    *(u16 *)(reg_a4 + 0x12) += reg_d0.h[0];
    func_001D08C0();
}

s32 boss_animation_start();
extern u16 D_0026D1A0[];

void func_001D08C0(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_5;
    u16 temp_a1;
    u16 temp_a1_2;
    u16 temp_a1_3;
    u16 temp_a1_4;
    u16 temp_a1_5;
    u16 temp_v1_2;
    u8 temp_v1;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 7);
        temp_v1 = *(u8 *)(reg_a4 + 0x1E);
        if (!(temp_v1 & 1)) {
            *(u8 *)(reg_a4 + 0x1E) = (u8) (temp_v1 | 1);
            rng_next_unsigned();
            if ((s8)(reg_d0.b[0]) >= 0) {
                reg_d0.b[0] *= -1;
            }
            *(u8 *)(reg_a4 + 0x1F) = (u8) reg_d0.b[0];
        }
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0x1F);
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d4.w = 0;
        reg_d6.b[0] = *(u8 *)(reg_a4 + 9);
        reg_a3 = (u8 *)(D_0026D1A0);
        temp_a1 = *(u16 *)reg_a3;
        reg_d3.h[1] = temp_a1;
        reg_a3 += 2;
        temp_a0 = *(u16 *)reg_a3;
        reg_d3.h[0] = temp_a0;
        reg_a3 += 2;
        reg_d0.h[1] = *(u16 *)(reg_a4 + 0xE);
        reg_d0.h[0] = *(u16 *)(reg_a4 + 0x10);
        reg_d1.b[0] += reg_d6.b[0];
        bullet_fire256_fixed();
        temp_a1_2 = *(u16 *)reg_a3;
        reg_d3.h[1] = temp_a1_2;
        reg_a3 += 2;
        temp_a0_2 = *(u16 *)reg_a3;
        reg_d3.h[0] = temp_a0_2;
        reg_a3 += 2;
        reg_d0.h[1] = *(u16 *)(reg_a4 + 0x12);
        reg_d0.h[0] = *(u16 *)(reg_a4 + 0x14);
        reg_d1.b[0] -= reg_d6.b[0];
        bullet_fire256_3way();
        temp_a1_3 = *(u16 *)reg_a3;
        reg_d3.h[1] = temp_a1_3;
        reg_a3 += 2;
        temp_a0_3 = *(u16 *)reg_a3;
        reg_d3.h[0] = temp_a0_3;
        reg_a3 += 2;
        reg_d0.h[1] = *(u16 *)(reg_a4 + 0xE);
        reg_d0.h[0] = *(u16 *)(reg_a4 + 0x10);
        reg_d1.b[0] -= reg_d6.b[0];
        bullet_fire256_2way();
        reg_d1.b[0] += 0x80;
        temp_v1_2 = *(u16 *)reg_a3;
        reg_a3 += 2;
        reg_d3.h[1] = temp_v1_2;
        reg_d3.h[0] = *(u16 *)reg_a3;
        reg_a3 += 2;
        bullet_fire256_fixed();
        temp_a1_4 = *(u16 *)reg_a3;
        reg_d3.h[1] = temp_a1_4;
        reg_a3 += 2;
        temp_a0_4 = *(u16 *)reg_a3;
        reg_d3.h[0] = temp_a0_4;
        reg_a3 += 2;
        reg_d0.h[1] = *(u16 *)(reg_a4 + 0x12);
        reg_d0.h[0] = *(u16 *)(reg_a4 + 0x14);
        reg_d1.b[0] += reg_d6.b[0];
        bullet_fire256_3way();
        temp_a1_5 = *(u16 *)reg_a3;
        reg_d3.h[1] = temp_a1_5;
        reg_a3 += 2;
        temp_a0_5 = *(u16 *)reg_a3;
        reg_d3.h[0] = temp_a0_5;
        reg_a3 += 2;
        reg_d0.h[1] = *(u16 *)(reg_a4 + 0xE);
        reg_d0.h[0] = *(u16 *)(reg_a4 + 0x10);
        reg_d1.b[0] += reg_d6.b[0];
        bullet_fire256_2way();
        reg_d0.b[0] = *(u8 *)(reg_a4 + 8);
        *(u8 *)(reg_a4 + 0x1F) += reg_d0.b[0];
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if (reg_tmp.b[0] == 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 0xD);
            *(u8 *)(reg_a4 + 8) *= -1;
            *(u8 *)(reg_a4 + 0x1E) &= 0xFE;
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x1A);
            *(u16 *)(reg_a4 + 0xE) += reg_d0.h[0];
            *(u16 *)(reg_a4 + 0x12) += reg_d0.h[0];
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xB);
            *(u8 *)(reg_a4 + 0xB) -= 1;
            if (reg_tmp.b[0] == 0) {
                reg_d0.h[0] = *(u16 *)(reg_a4 + 0x1C);
                *(u16 *)(reg_a6 + 0x112) += reg_d0.h[0];
                if ((s32) *(u16 *)(reg_a6 + 0x112) > 12) {
                    *(u16 *)(reg_a6 + 0x112) = 0xCU;
                }
                reg_d0.w = 5;
                boss_attack_stop();
                reg_d0.w = 5;
                boss_animation_start();
            }
        }
    }
}

extern u8 D_0026D1D0[];
extern u32 D_0028DBC0;
extern u16 D_0028DBC4[];
extern u32 D_0028DBC8;

void func_001D0C80(void) {
    s32 temp_a1;
    u16 temp_a2;
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a2 = reg_d0.h[0];
    temp_a1 = temp_a2 & ~3;
    reg_a0 = *(u8 **)(D_0026D1D0 + temp_a1);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DBC0 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *)(D_0028DBC4);
    reg_d0.w = ((u32) D_0028DBC8 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x118);
    *(u16 *)(reg_a4 + 0xE) += reg_d0.h[0];
    *(u16 *)(reg_a4 + 0x12) += reg_d0.h[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x117);
    *(u8 *)(reg_a4 + 5) += reg_d0.b[0];
    *(u8 *)(reg_a4 + 4) += reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x116);
    *(u8 *)(reg_a4 + 0xB) += reg_d0.b[0];
    if ((s32) *(u8 *)(reg_a4 + 5) > 0xE) {
        reg_d0.b[0] = 0xE;
        *(u8 *)(reg_a4 + 5) = (u8) reg_d0.b[0];
        *(u8 *)(reg_a4 + 4) = (u8) reg_d0.b[0];
    }
    func_001D0E60();
}

extern u16 D_0026D1B8[];
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];

void func_001D0E60(void) {
    s16 *temp_a0_2;
    s16 *var_a1;
    u32 temp_a0_10;
    u32 temp_a0_3;
    u32 temp_a0_6;
    u32 temp_a0_7;
    u32 temp_a0_8;
    u32 temp_a1;
    u8 temp_a0;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 7);
        temp_a0 = *(u8 *)(reg_a4 + 0x1B);
        if (!(temp_a0 & 1)) {
            *(u8 *)(reg_a4 + 0x1B) = (u8) (temp_a0 | 1);
            reg_a0 = (u8 *)(D_0029F260_as_u16_a);
            reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
            if (*(u8 *)(reg_a5 + 2) != 0) {
                reg_save_atmp = (s16 *)(reg_a1);
                reg_a1 = (u8 *)(reg_a0);
                reg_a0 = (u8 *)(reg_save_atmp);
            }
            var_a1 = (s16 *)(reg_a0);
            if ((*(s16 *)((u8 *)(var_a1) + (0))) >= 0) {
                temp_a0_2 = (s16 *)(reg_a1);
                if (*temp_a0_2 < 0) {
                    reg_a1 = (u8 *)(var_a1);
                    reg_save_atmp = (s16 *)(temp_a0_2);
                    reg_a0 = (u8 *)(temp_a0_2);
                    goto block_7;
                }
            } else {
block_7:
                reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d0.h[0] += 0x7FFF + 0x7541;
                direction256_between();
                *(u8 *)(reg_a4 + 0x1A) = (u8) reg_d1.b[0];
                goto block_8;
            }
        } else {
block_8:
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x1A);
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            temp_a1 = ENTITY(reg_a6)->x.h;
            reg_d2.h[0] = temp_a1;
            reg_d6.h[0] = 8;
            reg_d7.h[0] = 0xFFFE;
            reg_d4.w = 0;
            if (g_loop != 0) {
                reg_d6.h[0] = 0xA;
                reg_d7.h[0] = 0xFFFF;
            }
            reg_a3 = (u8 *)(D_0026D1A0);
            if (*(s8 *)(reg_a4 + 8) >= 0) {
                reg_a3 = (u8 *)(D_0026D1B8);
            }
            reg_d3.h[1] = *(u16 *)reg_a3;
            reg_a3 += 2;
            temp_a0_3 = *(u16 *)reg_a3;
            reg_d3.h[0] = temp_a0_3;
            reg_a3 += 2;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xE);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x10);
            reg_d1.h[0] += 0x14;
            bullet_fire256_fixed();
            if (g_loop != 0) {
                reg_d0.h[0] = 5;
                reg_d0.h[1] -= reg_d7.h[0];
                reg_d1.h[0] += reg_d6.h[0];
                bullet_fire256_fixed();
                reg_d1.h[0] -= reg_d6.h[0];
            }
            reg_d0.h[0] = 5;
            reg_d0.h[1] -= reg_d7.h[0];
            reg_d1.h[0] -= reg_d6.h[0];
            bullet_fire256_fixed();
            reg_d1.h[0] += reg_d6.h[0];
            temp_a0_6 = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d3.h[1] = temp_a0_6;
            temp_a0_7 = *(u16 *)reg_a3;
            reg_d3.h[0] = temp_a0_7;
            reg_a3 += 2;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x12);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x14);
            reg_d1.h[0] -= 0x14;
            bullet_fire256_3way();
            reg_d3.h[1] = *(u16 *)reg_a3;
            reg_a3 += 2;
            temp_a0_8 = *(u16 *)reg_a3;
            reg_d3.h[0] = temp_a0_8;
            reg_a3 += 2;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xE);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x10);
            reg_d1.h[0] -= 0x14;
            bullet_fire256_fixed();
            reg_d0.h[0] = 5;
            reg_d0.h[1] -= reg_d7.h[0];
            reg_d1.h[0] += reg_d6.h[0];
            bullet_fire256_fixed();
            reg_d1.h[0] -= reg_d6.h[0];
            switch (g_loop) { case 0: break; default:
                temp_a0_10 = reg_d0.h[1];
                reg_d0.h[0] = 5;
                reg_d0.h[1] = temp_a0_10 - reg_d7.h[0];
                reg_d1.h[0] -= reg_d6.h[0];
                bullet_fire256_fixed();
            }
            var_a1 = (s16 *)(reg_a4);
            reg_d0.b[0] = (u8) (*(u8 *)((u8 *)(var_a1) + (8)));
            (*(u8 *)((u8 *)(var_a1) + (0x1A))) += reg_d0.b[0];
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        switch (reg_tmp.b[0]) {
        case 0:
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 0xD);
            *(u8 *)(reg_a4 + 8) *= -1;
            *(u8 *)(reg_a4 + 0x1B) &= 0xFE;
            enemy_switch_target_player();
            reg_d0.b[0] = *(u8 *)(reg_a4 + 9);
            *(u8 *)(reg_a4 + 4) += reg_d0.b[0];
            if ((s32) *(u8 *)(reg_a4 + 4) > 0xE) {
                *(u8 *)(reg_a4 + 4) = 0xEU;
            }
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x16);
            *(u16 *)(reg_a4 + 0xE) += reg_d0.h[0];
            *(u16 *)(reg_a4 + 0x12) += reg_d0.h[0];
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xB);
            *(u8 *)(reg_a4 + 0xB) -= 1;
            if (reg_tmp.b[0] == 0) {
                reg_d0.b[0] = *(u8 *)(reg_a4 + 9);
                *(u8 *)(reg_a6 + 0x117) += reg_d0.b[0];
                if ((s32) *(u8 *)(reg_a6 + 0x117) > 0xE) {
                    *(u8 *)(reg_a6 + 0x117) = 0xEU;
                }
                *(u8 *)(reg_a6 + 0x116) += 1;
                if ((s32) *(u8 *)(reg_a6 + 0x116) > 4) {
                    *(u8 *)(reg_a6 + 0x116) = 4U;
                }
                reg_d0.h[0] = *(u16 *)(reg_a4 + 0x18);
                *(u16 *)(reg_a6 + 0x118) += reg_d0.b[0];
                if ((s32) *(u16 *)(reg_a6 + 0x118) > 0xC) {
                    *(u16 *)(reg_a6 + 0x118) = 0xCU;
                }
                reg_d0.w = 8;
                boss_attack_stop();
                reg_d0.w = 5;
                boss_animation_start();
            }
            break;
        }
    }
}
