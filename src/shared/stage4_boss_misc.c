#include "common.h"
#include "entity.h"

void func_001DC9D0(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 enemy_init_entities();
extern u8 D_0026F0A0[];

void func_001DC9E0(void) {
    reg_a0 = D_0026F0A0;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    ENTITY(reg_a6)->x.h = (u16) *(u16 *)(reg_a5 + 0x18);
    ENTITY(reg_a6)->move.h = (u16) *(u16 *)(reg_a5 + 0x1A);
    *(s8 *)(reg_a5 + 0x17) = 0;
    *(u8 *)(reg_a5 + 0x16) = 0;
    *(u16 *)(reg_a5 + 0x18) = 0U;
    *(u8 *)(reg_a5 + 0x1B) = (u8) ENTITY(reg_a6)->move.h;
    *(s16 *)(reg_a5 + 0x1C) = 0x804;
    *(s16 *)(reg_a5 + 0x1E) = 2;
    *(s16 *)(reg_a5 + 0x20) = 0;
}


s32 enemy_remove();
s32 func_0019D710();
s32 func_001D27A0();
s32 entity_velocity();
s32 func_00202180();
s32 func_00203060();
extern u8 D_0024EBC0[];
extern u8 D_0024EC80_as_u8_a[];
extern u8 D_0024EEF0_as_u8_a[];
extern u8 D_0028E2E4;

void func_001DCA80(void) {
    u16 temp_a0;
    u16 temp_a1;
    u8 temp_v1;
    if (D_0028E2E4 == 0) {
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
            ENTITY(reg_a6)->hp.sh = 0x7FFF;
        }
        func_001D27A0();
        if (cond_flag == 0) {
            func_00203060();
            if (cond_flag != 0) {
                if (*(u8 *)(reg_a5 + 0x17) != 0) {
block_6:
                    enemy_remove();
                    return;
                }
                goto block_8;
            }
            *(u8 *)(reg_a5 + 0x17) = 1U;
block_8:
            entity_velocity();
            if (*(u8 *)(reg_a5 + 0x16) == 0) {
                *(u8 *)(reg_a5 + 0x1B) += 4;
                *(u8 *)(reg_a5 + 0x1B) &= 0x3F;
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x19);
                *(u8 *)(reg_a5 + 0x19) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x19) = (u8) *(u8 *)(reg_a5 + 0x18);
                    ENTITY(reg_a6)->move.b.speed -= 1;
                    if (ENTITY(reg_a6)->move.b.speed == 0) {
                        *(u8 *)(reg_a5 + 0x16) = 1U;
                        *(u16 *)(reg_a5 + 0x18) = 0;
                        func_00202180();
                        *(u8 *)(reg_a5 + 0x1B) = (u8) reg_d1.b[0];
                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                    }
                }
            }
            if (*(u8 *)(reg_a5 + 0x16) == 1) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x19);
                *(u8 *)(reg_a5 + 0x19) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x19) = (u8) *(u8 *)(reg_a5 + 0x18);
                    temp_v1 = ENTITY(reg_a6)->move.b.speed;
                    if (temp_v1 != 0x24) {
                        ENTITY(reg_a6)->move.b.speed = (u8) (temp_v1 + 1);
                    }
                }
            }
            reg_d1.w = 0;
            reg_d1.b[0] = *(u8 *)(reg_a5 + 0x1B);
            reg_a0 = (u8 *)D_0024EEF0_as_u8_a;
            reg_d1.b[0] += 1;
            reg_d1.h[0] &= 0x3E;
            reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            *(u8 *)(reg_a6 + 0x1D) = (u8) reg_d0.b[0];
            reg_a0 = (u8 *)D_0024EC80_as_u8_a;
            reg_d1.h[0] += reg_d1.h[0];
            reg_d1.h[0] += reg_d1.h[0];
            reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_a0 = (u8 *)D_0024EBC0;
            reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_a0 = (u8 *) reg_tmp.w;
            reg_d2.h[1] = *(u16 *)reg_a0;
            temp_a1 = *(u16 *)(reg_a0 + 2);
            reg_d2.h[0] = temp_a1;
            reg_d3.h[0] = 0x210;
            reg_d4.w = 0;
            reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            temp_a0 = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] = temp_a0;
            reg_d1.w += 0xFE00FE00;
            reg_d6.w = 0xF800F800;
            func_0019D710();
            return;
        }
        goto block_6;
    }
    goto block_6;
}

void func_001DCE10(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(4);
}

s32 velocity_from_dir256();
extern u8 D_0026F0C0[];

void func_001DCE20(void) {
    u8 temp_a0;

    reg_a0 = (u8 *)D_0026F0C0;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    ENTITY(reg_a6)->x.h = (u16) *(u16 *)(reg_a5 + 0x18);
    ENTITY(reg_a6)->move.sb.speed = 0;
    *(s8 *)(reg_a5 + 0x17) = 0;
    *(u8 *)(reg_a5 + 0x16) = 0;
    *(u8 *)(reg_a6 + 0x3D) = (u8) *(u8 *)(reg_a5 + 0x20);
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
    reg_d0.h[0] = (u16) (s8) reg_d0.b[0];
    *(u16 *)(reg_a6 + 0x26) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x38) = (u16) *(u16 *)(reg_a6 + 0x26);
    *(u16 *)(reg_a6 + 0x48) = (u16) *(u16 *)(reg_a6 + 0x26);
    *(s16 *)(reg_a6 + 0x6C) = 0;
    if ((s16) *(u16 *)(reg_a6 + 0x26) < 0) {
        *(s16 *)(reg_a6 + 0x6C) = 1;
    }
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1A);
    reg_d0.h[0] = (u16) reg_d0.b[0];
    if ((reg_d0.b[0] == 0x10) || (reg_d0.b[0] == 0x65) || (reg_d0.b[0] == 0xBB) || (reg_d0.b[0] == -0x10U) || (reg_d0.b[0] == 0x45) || (reg_d0.b[0] == 0x9B)) {
        *(s8 *)(reg_a6 + 0x8C) = 1;
    }
    reg_d0.h[0] = (s16) reg_d0.h[0] * 0x10;
    *(u16 *)(reg_a6 + 0x28) = (u16) reg_d0.h[0];
    *(u8 *)(reg_a5 + 0x18) = 0;
    *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x21);
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x28);
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 4);
    velocity_from_dir256();
    reg_d2.h[0] = (s16) reg_d2.h[0] * 8;
    reg_d0.h[0] = 0x2000;
    reg_d3.h[0] = (s16) reg_d3.h[0] * 8;
    *(u16 *)(reg_a5 + 0x20) = (u16) reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1C);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1E);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d2.h[0] += *(u16 *)(reg_a0 + 0x22);
    reg_d2.h[0] -= (u16) *(u16 *)(reg_a5 + 0x20);
    reg_d3.h[0] += *(u16 *)(reg_a0 + 0x24);
    ENTITY(reg_a6)->y.h = (u16) reg_d2.h[0];
    ENTITY(reg_a6)->x.h = (u16) reg_d3.h[0];
    *(s16 *)(reg_a5 + 0x22) = 0x404;
    *(s8 *)(reg_a5 + 0x3B) = 0;
    *(s8 *)(reg_a5 + 0x3A) = 0x18;
    *(s16 *)(reg_a5 + 0x3C) = 0;
    *(s16 *)(reg_a5 + 0x3E) = 0;
    temp_a0 = *(u8 *)(reg_a6 + 0x3D);
    if ((temp_a0 != 0x70) && (temp_a0 != 0x71)) {
        ENTITY(reg_a6)->flags.h = 0x8000;
    }
}

s32 bullet_fire256_fixed();
s32 bullet_fire256_fast();
s32 bullet_fire256_2way();
s32 explosion_spawn();
s32 enemy_hitbox_debug_draw();
s32 func_0018D4E0();
s32 sprite_draw_layer3();
s32 func_0019D6A0();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_00201F20();
s32 direction256_between();
s32 func_00202B70();
extern u8 D_0026F150[];
extern u16 D_0026F170[];
extern u16 D_0028E3F0;
extern u16 g_enemy_signal_e;
extern u16 g_enemy_signal_d;
extern u16 g_enemy_signal_c;
extern u16 g_enemy_signal_9;
extern u16 g_enemy_signal_8;
extern u8 g_enemy_signal_6_as_u8;
extern u8 D_0028E87D;
extern u16 g_enemies_stopped;
extern u16 D_0029C06C[];
extern u16 *reg_a4_as_u16_p;

void func_001DD090(void) {
    switch (g_enemy_signal_c) { case 0: goto next_10; }
    g_enemy_signal_8 = 0;
    g_enemy_signal_9 = 0;
    if (*(u8 *)(reg_a6 + 0x1E) == 0) goto next_5;
    reg_d0.w = 2;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1A) = ENTITY(reg_a6)->move.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
next_5:
    enemy_remove();
    return;
next_10:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto next_100;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    func_001A9000();
    reg_d0.h[0] = 0x7FFF;
    reg_d0.h[0] -= ENTITY(reg_a6)->hp.h;
    if (!((s16) g_enemy_signal_8 < (s16) reg_d0.h[0])) goto next_20;
    g_enemy_signal_8 = reg_d0.h[0];
    g_enemy_signal_9 = reg_d1.h[0];
next_20:
    ENTITY(reg_a6)->hp.h = 0x7FFF;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x3E);
    reg_d0.b[0] ^= reg_d2.b[0];
    *(u8 *)(reg_a6 + 0x1C) = reg_d0.b[0];
    if (ENTITY(reg_a6)->hp.sh >= 0) goto next_110;
    reg_d0.w = 0x20;
    func_001A91A0();
    reg_d0.w = 2;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1A) = ENTITY(reg_a6)->move.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    func_0018D4E0();
    if (g_enemy_signal_e == 2) goto next_30;
    enemy_remove();
    return;
next_30:
    ENTITY(reg_a6)->flags.h = 0x8000;
    ENTITY(reg_a6)->hp.h = 0xFFFF;
    *(u8 *)(reg_a6 + 0x1E) = 0;
next_100:
    *(u8 *)(reg_a6 + 0x1C) = *(u8 *)(reg_a6 + 0x3F);
next_110:
    if (*(u8 *)(reg_a5 + 0x3B) != 1) goto next_130;
    if (ENTITY(reg_a6)->x.sh <= -0x400) goto block_b;
    if (!(ENTITY(reg_a6)->x.sh < 0x3C00)) goto block_b;
    func_00203060();
    if ((s8) (*(u8 *)&cond_flag) == 0) goto next_120;
    if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_130;
block_b:
    enemy_remove();
    return;
next_120:
    *(u8 *)(reg_a5 + 0x17) = 1;
next_130:
    if (g_enemies_stopped != 0) goto block_c;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1C);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1E);
    reg_a0 = (u8 *) reg_tmp.w;
    *(u16 *)(reg_a5 + 0x30) = *(u16 *)(reg_a0 + 0x22);
    *(u16 *)(reg_a5 + 0x32) = *(u16 *)(reg_a0 + 0x24);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
    *(u16 *)(reg_a5 + 0x30) -= reg_d0.h[0];
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x28);
    reg_d1.h[0] = (s16) reg_d1.h[0] >> 4;
    velocity_from_dir256();
    reg_d2.h[0] = (s16) reg_d2.h[0] * 8;
    reg_d3.h[0] = (s16) reg_d3.h[0] * 8;
    if (*(u8 *)(reg_a5 + 0x3B) != 1) goto next_140;
    reg_d0.h[0] = D_0029C06C[0];
    *(u16 *)(reg_a6 + 0x32) -= reg_d0.h[0];
    reg_d2.h[0] += *(u16 *)(reg_a6 + 0x30);
    reg_d3.h[0] += *(u16 *)(reg_a6 + 0x32);
    goto next_150;
next_140:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1C);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1E);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d2.h[0] += *(u16 *)(reg_a0 + 0x22);
    reg_d3.h[0] += *(u16 *)(reg_a0 + 0x24);
next_150:
    reg_d2.h[0] -= *(u16 *)(reg_a5 + 0x20);
    ENTITY(reg_a6)->offset_y.h = reg_d2.h[0];
    ENTITY(reg_a6)->offset_x.h = reg_d3.h[0];
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.h[0] = ENTITY(reg_a6)->offset_y.h;
    reg_d3.h[0] = ENTITY(reg_a6)->offset_x.h;
    direction256_between();
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.h[0] = ENTITY(reg_a6)->offset_y.h;
    reg_d3.h[0] = ENTITY(reg_a6)->offset_x.h;
    func_00202B70();
    ENTITY(reg_a6)->move.b.speed = 0x40;
    reg_a4_as_u16_p = (u16 *)D_0026F170;
loop_160:
    reg_d1.h[0] = *reg_a4_as_u16_p++;
    if ((s16) reg_d1.h[0] == -1) goto next_170;
    reg_d2.h[0] = *reg_a4_as_u16_p++;
    if ((s16) reg_d1.h[0] < (s16) reg_d0.h[0]) goto loop_160;
    ENTITY(reg_a6)->move.b.speed = reg_d2.b[0];
next_170:
    func_00201F20();
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x26);
    *(u16 *)(reg_a6 + 0x28) += reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x28) &= 0xFFF;
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x3B);
    *(u8 *)(reg_a6 + 0x3B) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_190;
    *(u8 *)(reg_a6 + 0x3B) = *(u8 *)(reg_a6 + 0x3A);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x38);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x26);
    if (reg_d0.h[0] == reg_d1.h[0]) goto next_190;
    if ((s16) reg_d0.h[0] < (s16) reg_d1.h[0]) goto next_180;
    *(u16 *)(reg_a6 + 0x26) += 1;
    goto next_190;
next_180:
    *(u16 *)(reg_a6 + 0x26) -= 1;
next_190:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x28);
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 4;
    reg_d0.h[0] = reg_d0.b[0];
    if (!((s16) reg_d0.h[0] < 0xFF)) goto next_200;
    if (!((s16) reg_d0.h[0] < 2)) goto next_210;
next_200:
    if (*(u8 *)(reg_a6 + 0x1E) != 0) goto next_210;
    *(u8 *)(reg_a6 + 0x1E) = 1;
    ENTITY(reg_a6)->hp.h = 0x7FFF;
    ENTITY(reg_a6)->flags.h = 0xA001;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1C);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1E);
    reg_a0 = (u8 *) reg_tmp.w;
    *(u16 *)(reg_a0 + 0x19E) += 1;
next_210:
    if (*(u8 *)(reg_a5 + 0x3B) != 1) goto next_250;
    if (*(u16 *)(reg_a6 + 0x56) == 0) goto next_220;
    *(u16 *)(reg_a6 + 0x56) -= 1;
    if (*(u16 *)(reg_a6 + 0x56) != 0) goto next_250;
    *(u16 *)(reg_a6 + 0x26) = *(u16 *)(reg_a6 + 0x48);
    *(u16 *)(reg_a6 + 0x38) = *(u16 *)(reg_a6 + 0x48);
    *(u8 *)(reg_a6 + 0x70) = 0;
    goto next_250;
next_220:
    if (*(u8 *)(reg_a6 + 0x70) != 0) goto next_230;
    *(u8 *)(reg_a5 + 0x1B) -= 1;
    if (!(*(s8 *)(reg_a5 + 0x1B) < 9)) goto next_230;
    *(u8 *)(reg_a5 + 0x1B) = 8;
    *(u8 *)(reg_a6 + 0x70) = 1;
    *(u8 *)(reg_a6 + 0x7F) = 0x40;
    *(u8 *)(reg_a6 + 0x7E) = 0;
next_230:
    if (*(u8 *)(reg_a6 + 0x70) != 1) goto next_250;
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
    reg_d0.h[0] += 2;
    if (!((s16) reg_d0.h[0] < 0x100)) goto block_b;
    *(u8 *)(reg_a5 + 0x1B) = reg_d0.b[0];
next_250:
    if (*(u8 *)(reg_a5 + 0x3B) == 1) goto next_260;
    if (g_enemy_signal_e != 1) goto next_260;
    *(u8 *)(reg_a5 + 0x3B) = 1;
    *(u16 *)(reg_a6 + 0x48) = *(u16 *)(reg_a6 + 0x26);
    *(u16 *)(reg_a6 + 0x26) = 0;
    *(u16 *)(reg_a6 + 0x38) = 0;
    *(u16 *)(reg_a6 + 0x56) = 0x60;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1C);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1E);
    reg_a0 = (u8 *) reg_tmp.w;
    *(u16 *)(reg_a6 + 0x30) = *(u16 *)(reg_a0 + 0x22);
    *(u16 *)(reg_a6 + 0x32) = *(u16 *)(reg_a0 + 0x24);
next_260:
    if (g_enemy_signal_e != 2) goto next_300;
    if (*(u16 *)(reg_a6 + 0x6C) == 0) goto next_300;
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x75);
    *(u8 *)(reg_a6 + 0x75) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_270;
    *(u8 *)(reg_a6 + 0x75) = *(u8 *)(reg_a6 + 0x74);
    if (*(u8 *)(reg_a6 + 0x1E) == 0) goto next_270;
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x28);
    reg_d1.h[0] = (s16) reg_d1.h[0] >> 4;
    reg_d1.h[0] += 0x80;
    reg_d1.h[0] = reg_d1.b[0];
    reg_d0.w = 0x20003;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = 0;
    reg_d4.w = 0;
next_270:
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x5F);
    *(u8 *)(reg_a6 + 0x5F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_300;
    *(u8 *)(reg_a6 + 0x5F) = *(u8 *)(reg_a6 + 0x5E);
    if (*(u8 *)(reg_a6 + 0x1E) == 0) goto next_300;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x28);
    reg_d1.h[0] = (s16) reg_d1.h[0] >> 4;
    reg_d1.h[0] = reg_d1.b[0];
    reg_d1.b[0] += 0x80;
    reg_d0.w = 0xFFFA0023;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = 0;
    reg_d4.w = 0;
next_300:
    if (g_enemy_signal_e != 2) goto next_600;
    if (*(u16 *)(reg_a6 + 0x6C) != 0) goto next_600;
    if (*(u16 *)(reg_a6 + 0x86) != 0) goto next_310;
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x8B);
    *(u8 *)(reg_a6 + 0x8B) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_310;
    *(u8 *)(reg_a6 + 0x8B) = *(u8 *)(reg_a6 + 0x8A);
    *(u16 *)(reg_a6 + 0x86) = 1;
next_310:
    if (*(u16 *)(reg_a6 + 0x86) != 1) goto next_330;
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x89);
    *(u8 *)(reg_a6 + 0x89) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_330;
    *(u8 *)(reg_a6 + 0x89) = *(u8 *)(reg_a6 + 0x88);
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x8D);
    *(u8 *)(reg_a5 + 0x1B) += reg_d0.b[0];
    if (*(s8 *)(reg_a6 + 0x8D) >= 0) goto next_320;
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
    if (!((s16) reg_d0.h[0] < 0x21)) goto next_330;
    *(u8 *)(reg_a6 + 0x8D) *= -1;
    *(u16 *)(reg_a6 + 0x86) = 0;
    goto next_330;
next_320:
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
    if ((s16) reg_d0.h[0] < 0x60) goto next_330;
    *(u8 *)(reg_a6 + 0x8D) *= -1;
    *(u16 *)(reg_a6 + 0x86) = 0;
next_330:
    if (*(u16 *)(reg_a6 + 0x66) != 0) goto next_340;
    if (g_enemy_signal_d == 0) goto next_340;
    *(u16 *)(reg_a6 + 0x66) = 1;
    *(u16 *)(reg_a6 + 0x7C) = 1;
next_340:
    if (*(u16 *)(reg_a6 + 0x66) != 1) goto next_350;
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x6F);
    *(u8 *)(reg_a6 + 0x6F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_350;
    *(u8 *)(reg_a6 + 0x6F) = *(u8 *)(reg_a6 + 0x6E);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x6A);
    *(u16 *)(reg_a6 + 0x38) -= reg_d0.h[0];
    if (!(*(s16 *)(reg_a6 + 0x38) < 5)) goto next_350;
    *(u16 *)(reg_a6 + 0x66) = 2;
    *(u8 *)(reg_a6 + 0x6F) = 0x60;
next_350:
    if (*(u16 *)(reg_a6 + 0x66) != 2) goto next_370;
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x6F);
    *(u8 *)(reg_a6 + 0x6F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_370;
    *(u8 *)(reg_a6 + 0x6F) = *(u8 *)(reg_a6 + 0x6E);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x6A);
    *(u16 *)(reg_a6 + 0x38) -= reg_d0.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x38);
    if ((s16) reg_d0.h[0] >= 0) goto next_360;
    reg_d0.h[0] *= 0xFFFF;
next_360:
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x78);
    if ((s16) reg_d1.h[0] > (s16) reg_d0.h[0]) goto next_370;
    *(u16 *)(reg_a6 + 0x66) = 0;
    *(u16 *)(reg_a6 + 0x6A) *= 0xFFFF;
    if (*(u16 *)(reg_a6 + 0x78) == 0x10) goto next_370;
    *(u16 *)(reg_a6 + 0x78) += 2;
next_370:
    reg_d7.b[0] = *(u8 *)(reg_a6 + 0x3D);
    if (reg_d7.b[0] == 0x70) goto next_380;
    if (reg_d7.b[0] != 0x71) goto next_400;
next_380:
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x28);
    reg_d1.h[0] = (s16) reg_d1.h[0] >> 4;
    reg_d1.h[0] = reg_d1.b[0];
    reg_d1.b[0] += *(u8 *)(reg_a6 + 0x5B);
    if (reg_d7.b[0] == 0x70) goto next_390;
    g_enemy_signal_6_as_u8 = reg_d1.b[0];
    goto next_400;
next_390:
    D_0028E87D = reg_d1.b[0];
next_400:
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x8F);
    *(u8 *)(reg_a6 + 0x8F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_500;
    *(u8 *)(reg_a6 + 0x8F) = *(u8 *)(reg_a6 + 0x8E);
    reg_d7.b[0] = *(u8 *)(reg_a6 + 0x3D);
    if (reg_d7.b[0] == 0x70) goto next_500;
    if (reg_d7.b[0] == 0x71) goto next_500;
    if (*(u8 *)(reg_a6 + 0x1E) == 0) goto next_500;
    reg_d1.w = 0;
    reg_d1.b[0] = D_0028E87D;
    if (*(s8 *)(reg_a6 + 0x3D) <= 3) goto next_410;
    reg_d1.b[0] = g_enemy_signal_6_as_u8;
next_410:
    reg_d1.b[0] += 0x80;
    reg_d0.w = 0xFFFD0007;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = 0;
    reg_d4.w = 0;
    reg_d6.w = 0;
    if (*(u8 *)(reg_a6 + 0x3D) != 0) goto next_420;
    reg_d1.b[0] -= 0x10;
    reg_d6.w = 1;
next_420:
    if (*(u8 *)(reg_a6 + 0x3D) != 1) goto next_430;
    reg_d1.b[0] -= 4;
next_430:
    if (*(u8 *)(reg_a6 + 0x3D) != 2) goto next_440;
    reg_d1.b[0] += 4;
next_440:
    if (*(u8 *)(reg_a6 + 0x3D) != 3) goto next_450;
    reg_d1.b[0] += 0x10;
    reg_d6.w = 1;
next_450:
    if (*(u8 *)(reg_a6 + 0x3D) != 4) goto next_460;
    reg_d1.b[0] -= 0x10;
    reg_d6.w = 1;
next_460:
    if (*(u8 *)(reg_a6 + 0x3D) != 5) goto next_470;
    reg_d1.b[0] -= 4;
next_470:
    if (*(u8 *)(reg_a6 + 0x3D) != 6) goto next_480;
    reg_d1.b[0] += 4;
next_480:
    if (*(u8 *)(reg_a6 + 0x3D) != 7) goto next_490;
    reg_d1.b[0] += 0x10;
    reg_d6.w = 1;
next_490:
    if (reg_d6.h[0] != 0) goto next_495;
    bullet_fire256_fixed();
    goto next_500;
next_495:
    bullet_fire256_2way();
next_500:
    if (*(u8 *)(reg_a6 + 0x1E) == 0) goto next_600;
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x59);
    *(u8 *)(reg_a6 + 0x59) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_600;
    *(u8 *)(reg_a6 + 0x59) = *(u8 *)(reg_a6 + 0x58);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x28);
    reg_d1.h[0] = (s16) reg_d1.h[0] >> 4;
    reg_d1.h[0] = reg_d1.b[0];
    reg_d0.w = 0xFFFE000B;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = 0;
    reg_d4.w = 0;
next_600:
    if (g_enemy_signal_e == 2) goto block_c;
    if (*(u8 *)(reg_a6 + 0x1E) == 0) goto block_c;
    if (*(u8 *)(reg_a5 + 0x3B) == 1) goto next_620;
    if (*(u8 *)(reg_a6 + 0x4F) != 0) goto next_650;
    reg_d0.h[0] = D_0028E3F0;
    reg_d0.h[0] &= 0x1F;
    if (reg_d0.h[0] != 0) goto block_c;
    goto next_640;
next_620:
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x28);
    reg_d1.h[0] = (s16) reg_d1.h[0] >> 4;
    reg_d1.h[0] = reg_d1.b[0];
    *(u8 *)(reg_a6 + 0x51) = reg_d1.b[0];
    reg_d0.h[0] = D_0028E3F0;
    reg_d0.h[0] &= 3;
    if (reg_d0.h[0] != 0) goto block_c;
    reg_d0.w = 7;
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x51);
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = 0;
    reg_d4.w = 0;
    if (*(u8 *)(reg_a6 + 0x70) != 1) goto next_630;
    reg_d1.b[0] += 0x80;
    reg_d0.w += 0xFFFA0000;
    if (ENTITY(reg_a6)->y.sh <= 0x600) goto block_c;
    if (*(u8 *)(reg_a6 + 0x8C) != 0) goto block_c;
next_630:
    bullet_fire256_2way();
    goto block_c;
next_640:
    *(u8 *)(reg_a6 + 0x4F) = *(u8 *)(reg_a6 + 0x4E);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x28);
    reg_d1.h[0] = (s16) reg_d1.h[0] >> 4;
    reg_d1.h[0] = reg_d1.b[0];
    *(u8 *)(reg_a6 + 0x51) = reg_d1.b[0];
next_650:
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x4D);
    *(u8 *)(reg_a6 + 0x4D) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_c;
    *(u8 *)(reg_a6 + 0x4D) = *(u8 *)(reg_a6 + 0x4C);
    reg_d0.w = 7;
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x51);
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = 0;
    reg_d4.w = 0;
    bullet_fire256_fast();
    *(u8 *)(reg_a6 + 0x4F) -= 1;
block_c:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x3F);
    *(u8 *)(reg_a5 + 0x3F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_700;
    *(u8 *)(reg_a5 + 0x3F) = *(u8 *)(reg_a5 + 0x3E);
    *(u16 *)(reg_a5 + 0x3C) += 4;
    *(u16 *)(reg_a5 + 0x3C) &= 0x1F;
next_700:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    if (*(u8 *)(reg_a6 + 0x1E) == 0) goto block_rts;
    if (*(u8 *)(reg_a6 + 0x3D) == 0x70) goto block_rts;
    if (*(u8 *)(reg_a6 + 0x3D) == 0x71) goto block_rts;
    reg_a0 = (u8 *)D_0026F150;
    reg_a0 += *(u16 *)(reg_a5 + 0x3C);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = 0x620;
    reg_d4.w = 0;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFA00FC00;
    if (*(u8 *)(reg_a6 + 0x70) == 1) goto next_710;
    sprite_draw_layer3();
    return;
next_710:
    func_0019D6A0();
block_rts:
    return;
}
