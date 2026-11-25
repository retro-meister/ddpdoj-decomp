#include "common.h"
#include "entity.h"

void func_001D5150(void);
void func_001D51C0(void);
void func_001D5230(void);
void func_001D55B0(void);
void func_001D6690(void);
void func_001D66A0(void);
void func_001D66B0(void);
void func_001D66E0(void);
void func_001D6710(void);
void func_001D6790(void);
void func_001D6990(void);
void func_001D6A40(void);
void func_001D6B60(void);


void func_001D4620(void) {
    *(s16 *)((u8 *)((void *)reg_a6) + 0x86) = 1;
}

s32 func_001D4400();
void active_players_mask(void);
extern u16 g_enemies_stopped;

void func_001D4630(void) {
#ifdef DEATH_LABEL
    if ((g_enemies_stopped == 0) && (*(u16 *)(reg_a5 + 0x1A) == 0)) {
#else
    if ((g_enemies_stopped == 0) && (*(u16 *)(reg_a5 + 0x1A) -= 1, *(u16 *)(reg_a5 + 0x1A) == 0)) {
#endif
        active_players_mask();
        if (reg_d0.h[0] == 0) {
            *(u16 *)(reg_a5 + 0x1A) = 0x78U;
            return;
        }
        ENTITY(reg_a6)[4].draw.sh = 0;
        func_001D4400();
    }
}

s32 bullet_fire();
extern u16 D_00259870[];

void func_001D46A0(void) {
    reg_d0.w = 0xFFFC0004;
    reg_d1.h[0] -= 0xC;
    reg_d7.w = 6;
    reg_a0 = (u8 *)(D_00259870);
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] *= 4;
        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w += reg_d5.w;
        bullet_fire();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

void func_001D61B0();

void enemy_set_entity_count(s32);

void stage3_midboss_first(void) {
    enemy_set_entity_count(6);
}

s32 enemy_set_task_work();
s32 enemy_init_entities();
s32 sprite_palette_load();
extern u16 D_00260330[];
extern u16 D_00260370[];
extern u16 D_002603B0[];
extern u16 D_00263370[];
extern u16 stage3_midboss_table[];
extern s16 g_enemy_signal_e_as_s16;
extern s16 g_enemy_signal_4_as_s16;
extern u16 g_spare_entities_as_u16_a[];
extern u16 *reg_a0_as_u16_p;

void stage3_midboss_start(void) {
    reg_a0_as_u16_p = stage3_midboss_table;
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0_as_u16_p;
    *(u16 *)(reg_a5 + 0x44) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = (u16) reg_tmp.h[0];
    reg_a0_as_u16_p = D_00263370;
    reg_d0.h[0] = 0xE;
    enemy_set_task_work();
    reg_tmp.w = 0xF0001C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
    reg_a0_as_u16_p = g_spare_entities_as_u16_a;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.w = 9;
    do {
        *reg_a0_as_u16_p = reg_d1.h[1];
        reg_a0_as_u16_p += 1;
        *reg_a0_as_u16_p = reg_d1.h[0];
        reg_a0_as_u16_p += 1;
        *reg_a0_as_u16_p = 0;
        reg_a0_as_u16_p += 1;
        *reg_a0_as_u16_p = 0;
        reg_a0_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = 0x12;
    g_enemy_signal_e_as_s16 = 1;
    g_enemy_signal_4_as_s16 = 1;
    reg_a0_as_u16_p = D_00260330;
    sprite_palette_load();
    reg_d0.h[0] = 0x13;
    reg_a0_as_u16_p = D_00260370;
    sprite_palette_load();
    reg_d0.h[0] = 0xA;
    reg_a0_as_u16_p = D_002603B0;
    sprite_palette_load();
}

typedef void (*Fn)();

extern u8 stage3_midboss_mode_routines[];
extern u8 D_002BDAA8[];
s32 enemy_hitbox_debug_draw();
s32 enemy_remove();
s32 score_add_no_chain();
s32 score_add();
s32 func_00201800();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u16 g_enemy_signal_4;
extern u16 g_side_scroll_step[];
extern u16 D_002BDAA4[];
extern u16 D_002BDAA6[];

void stage3_midboss_main(void) {
    u32 saved;
    u32 saved_d1;
    u8 *p;

    if (g_enemies_stopped != 0) goto next_1;
    reg_d7.h[1] = ENTITY(reg_a6)->y.h;
    reg_d7.h[0] = ENTITY(reg_a6)->x.h;
    saved = reg_d7.w;
    reg_a0 = (u8 *)stage3_midboss_mode_routines;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
    reg_d0.h[0] *= 4;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)(reg_a0 + 0);
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_call_target = (Fn)(reg_a0);
    reg_call_target();
    reg_d7.w = saved;
    if (*(u8 *)(reg_a5 + 0x25) != 0) goto next_3;
    if (*(u16 *)(reg_a5 + 0x2E) == 0) goto next_3;
    if (*(u8 *)(reg_a5 + 0x1E) != 0) goto next_2;
    if ((s16) *(u16 *)(reg_a5 + 0x2E) <= 0x258) goto block_1;
next_2:
    *(u16 *)(reg_a5 + 0x2E) -= 1;
    if (*(u16 *)(reg_a5 + 0x2E) != 0) goto next_3;
    func_001D55B0();
next_3:
    func_001D61B0();
    func_001D66E0();
    func_001D5230();
    if (*(u16 *)(reg_a5 + 0x30) == 0) goto next_1;
    enemy_remove();
    return;
next_1:
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_a0 = (u8 *)D_002BDAA8;
    p = (u8 *) D_002BDAA4;
    reg_a1 = p;
    reg_d1.w = 8;
loop_1:
    reg_a1 -= 4;
    reg_d2.h[1] = *(u16 *)(reg_a1 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a1 + 2);
    reg_d2.h[0] -= g_side_scroll_step[0];
    reg_a0 -= 4;
    *(u16 *)(reg_a0 + 0) = reg_d2.h[1];
    *(u16 *)(reg_a0 + 2) = reg_d2.h[0];
    if ((s16) --reg_d1.h[0] >= 0) goto loop_1;
    reg_d0.h[0] -= g_side_scroll_step[0];
    *(u16 *)(reg_a1 + 0) = reg_d0.h[1];
    *(u16 *)(reg_a1 + 2) = reg_d0.h[0];
    reg_d0.h[1] = *(u16 *)p;
    reg_d0.h[0] = D_002BDAA6[0];
    ENTITY(reg_a6)[1].y.h = reg_d0.h[1];
    ENTITY(reg_a6)[1].x.h = reg_d0.h[0];
    ENTITY(reg_a6)[1].x.h -= 0x1000;
    ENTITY(reg_a6)[2].y.h = reg_d0.h[1];
    ENTITY(reg_a6)[2].x.h = reg_d0.h[0];
    ENTITY(reg_a6)[2].x.h += 0x1000;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto next_6;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    reg_d2.b[0] = ENTITY(reg_a6)->misc.b.draw_layer;
    reg_d0.b[0] ^= reg_d2.b[0];
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    reg_d0.w = 0x7FFF;
    reg_d0.h[0] -= ENTITY(reg_a6)->hp.h;
    if (*(u16 *)(reg_a5 + 0x2E) == 0) goto next_4;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x20);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x22);
    reg_tmp.w -= reg_d0.w;
    *(u16 *)(reg_a5 + 0x20) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x22) = reg_tmp.h[0];
next_4:
    ENTITY(reg_a6)->hp.h = 0x7FFF;
    if (*(u8 *)(reg_a5 + 0x1E) != 0) goto next_5;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x20);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x22);
    if ((s32) reg_tmp.w > 0x2800) goto next_5;
block_1:
    func_001D5150();
    func_001D51C0();
    *(u8 *)(reg_a5 + 0x1E) = 1;
    goto next_7;
next_5:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x20);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x22);
    if ((s32) reg_tmp.w >= 0) goto next_7;
    saved_d1 = reg_d1.w;
    reg_d0.w = 0x712;
    score_add();
    vibration_start_pad1(0xB4, 0x78);
    vibration_start_pad2(0xB4, 0x78);
    reg_d1.w = saved_d1;
    func_00201800();
    ENTITY(reg_a6)->flags.h = 0x8000;
    *(u8 *)(reg_a5 + 0x25) = 1;
    g_enemy_signal_4 = 0;
next_6:
    ENTITY(reg_a6)->attr.b.palette = ENTITY(reg_a6)->misc.b.user;
next_7:
    if (*(u8 *)(reg_a5 + 0x1F) != 0) goto next_8;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x20);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x22);
    if ((s32) reg_tmp.w > 0x1000) goto next_8;
    *(u8 *)(reg_a5 + 0x1F) = 1;
next_8:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)[1].flags.b[1];
    if (reg_d1.b[0] == 0) goto next_10;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)[1].move.b.speed;
    reg_d2.b[0] = ENTITY(reg_a6)[1].attr.b.palette;
    reg_d0.b[0] ^= reg_d2.b[0];
    ENTITY(reg_a6)[1].move.b.speed = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[1].move.b.dir;
    reg_d2.b[0] = ENTITY(reg_a6)[1].misc.b.draw_layer;
    reg_d0.b[0] ^= reg_d2.b[0];
    ENTITY(reg_a6)[1].move.b.dir = reg_d0.b[0];
    if (*(u16 *)(reg_a5 + 0x2E) != 0) goto next_9;
    ENTITY(reg_a6)[1].hp.h = 0x4000;
next_9:
    if (ENTITY(reg_a6)[1].hp.sh >= 0) goto next_11;
    reg_d0.w = 0x173;
    score_add();
    func_001D5150();
next_10:
    ENTITY(reg_a6)[1].move.b.speed = ENTITY(reg_a6)[1].attr.b.flip;
    ENTITY(reg_a6)[1].move.b.dir = ENTITY(reg_a6)[1].misc.b.user;
next_11:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)[2].flags.b[1];
    if (reg_d1.b[0] == 0) goto next_13;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[2].flags.b[1] &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)[2].move.b.speed;
    reg_d2.b[0] = ENTITY(reg_a6)[2].attr.b.palette;
    reg_d0.b[0] ^= reg_d2.b[0];
    ENTITY(reg_a6)[2].move.b.speed = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[2].move.b.dir;
    reg_d2.b[0] = ENTITY(reg_a6)[2].misc.b.draw_layer;
    reg_d0.b[0] ^= reg_d2.b[0];
    ENTITY(reg_a6)[2].move.b.dir = reg_d0.b[0];
    if (*(u16 *)(reg_a5 + 0x2E) != 0) goto next_12;
    ENTITY(reg_a6)[2].hp.h = 0x4000;
next_12:
    if (ENTITY(reg_a6)[2].hp.sh >= 0) goto next_14;
    reg_d0.w = 0x173;
    score_add();
    func_001D51C0();
next_13:
    ENTITY(reg_a6)[2].move.b.speed = ENTITY(reg_a6)[2].attr.b.flip;
    ENTITY(reg_a6)[2].move.b.dir = ENTITY(reg_a6)[2].misc.b.user;
next_14:
    *(u16 *)(reg_a5 + 0x32) += 4;
    *(u16 *)(reg_a5 + 0x32) &= 0x1F;
    if (*(u16 *)(reg_a5 + 0x2C) == 0) return;
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x20;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x40;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x60;
    enemy_hitbox_debug_draw();
    func_001D6990();
    func_001D6A40();
    func_001D6B60();
}

s32 explosion_spawn();

void func_001D5040(arg2)
    u16 *arg2;
{
    u16 *var_a2;
    u16 temp_a1;

    var_a2 = (u16 *)(arg2);
loop_1:
    temp_a1 = *(u16 *)reg_a1;
    reg_d1.h[0] = temp_a1;
    reg_a1 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        explosion_spawn();
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d1.h[0];
        *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
        var_a2 = (u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)(var_a2);
        *(u16 *)(reg_a0 + 2) = (u16) reg_d2.h[1];
        *(u16 *)(reg_a0 + 4) = (u16) reg_d2.h[0];
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(u16 *)(reg_a0 + 0x1A) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        goto loop_1;
    }
}

s32 sfx_explosion_ground_large();
extern u8 D_00263470[];

void func_001D5150() {
    if (ENTITY(reg_a6)[1].look.b.size == 0) {
        ENTITY(reg_a6)[1].look.b.size = 1U;
        ENTITY(reg_a6)[1].flags.h = 0x8000;
        reg_a1 = D_00263470;
        reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
        func_001D5040();
        sfx_explosion_ground_large();
    }
}

void func_001D51C0() {
    if (ENTITY(reg_a6)[2].look.b.size == 0) {
        ENTITY(reg_a6)[2].look.b.size = 1U;
        ENTITY(reg_a6)[2].flags.h = 0x8000;
        reg_a1 = D_00263470;
        reg_d2.h[1] = ENTITY(reg_a6)[2].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[2].x.h;
        func_001D5040();
        sfx_explosion_ground_large();
    }
}


s32 func_00138A40();
s32 explosion_burst_small();
s32 func_0013B2E0();
s32 sfx_explosion_air_medium();
s32 sfx_explosion_extra_1();
s32 rng_next();
extern u16 D_002634F0[];
extern u16 D_00263540[];
extern u8 stage3_midboss_flash_palettes[];

void func_001D5230(void) {
    u16 temp_a0_2;
    u16 temp_a0_3;
    u8 temp_a0;
    u8 *var_a1;

    if (*(u8 *)(reg_a5 + 0x25) != 0) {
        temp_a0 = *(u8 *)(reg_a5 + 0x24);
        if (temp_a0 == 2) {
            *(u8 *)(reg_a5 + 0x27) -= 1;
            if (*(u8 *)(reg_a5 + 0x27) == 0) {
                func_00138A40();
                g_enemy_signal_e_as_s16 = 0;
                *(s16 *)(reg_a5 + 0x30) = 1;
                goto block_set;
            }
        }
        var_a1 = (u8 *)(reg_a5);
        if ((*(u8 *)((u8 *)(var_a1) + (0x24))) == 1) {
            (*(u8 *)((u8 *)(var_a1) + (0x27))) -= 1;
            if (*(u8 *)(reg_a5 + 0x27) == 0) {
                *(s16 *)(reg_a5 + 0x2C) = 0;
                reg_a0 = (u8 *)stage3_midboss_flash_palettes;
                func_0013B2E0();
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_a1 = (u8 *)(D_00263540);
                func_001D5040();
                rng_next();
                reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
                reg_d1.b[0] = reg_d0.b[0];
                reg_d1.b[0] += 0x40;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                temp_a0_2 = ENTITY(reg_a6)->x.h;
                reg_d2.h[0] = temp_a0_2;
                reg_d2.w += 0xF8000800;
                reg_d3.h[0] = 0xC;
                reg_d0.h[0] = 0;
                explosion_burst_small();
                rng_next();
                reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
                reg_d1.b[0] = reg_d0.b[0];
                reg_d1.b[0] += 0xC0;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                temp_a0_3 = ENTITY(reg_a6)->x.h;
                reg_d2.h[0] = temp_a0_3;
                reg_d2.w += 0x01FFF800;
                reg_d3.h[0] = 0xC;
                reg_d0.h[0] = 0;
                explosion_burst_small();
                sfx_explosion_extra_1();
                var_a1 = (u8 *)((void *)0x10);
                *(u8 *)(reg_a5 + 0x27) = 0x10U;
                *(u8 *)(reg_a5 + 0x24) = 2U;
            }
        }
        if (*(u8 *)(reg_a5 + 0x24) == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x27);
            *(u8 *)(reg_a5 + 0x27) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x27) = (u8) *(u8 *)(reg_a5 + 0x26);
                sfx_explosion_air_medium();
                reg_a1 = (u8 *)(D_002634F0);
                reg_a1 += *(u16 *)(reg_a5 + 0x2A);
                reg_d1.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                explosion_spawn();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a0 + 0x18) = (u16) reg_d1.h[0];
                *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
                *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
                *(s16 *)(reg_a0 + 0x1E) = 0x10;
                *(s16 *)(reg_a0 + 0x12) = 0;
                *(s16 *)(reg_a0 + 0x14) = 0;
                *(u8 *)(reg_a0 + 0x1B) = (u8) ENTITY(reg_a6)->move.b.speed;
                reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
                reg_d0.b[0] *= 4;
                *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a5 + 0x2A) += 0xC;
                if (*(u16 *)(reg_a5 + 0x2A) == 0x48) {
                    *(u16 *)(reg_a5 + 0x2A) = 0U;
                    *(u16 *)(reg_a5 + 0x28) -= 1;
                    if (*(u16 *)(reg_a5 + 0x28) == 0) {
                        *(u16 *)(reg_a5 + 0x26) = 0x1006;
                        *(u8 *)(reg_a5 + 0x24) = 1U;
                    }
                }
            }
        }
        goto block_12;
    }
block_12:
    cond_flag = 0;
    return;
block_set:
    cond_flag = 1;
}

void func_001D55B0(void) {
    *(s8 *)(reg_a5 + 0x1B) = 0;
    if (*(u16 *)(reg_a5 + 0x2E) != 0) {
        reg_d0.b[0] = ENTITY(reg_a6)[1].look.b.size;
        reg_d0.b[0] += ENTITY(reg_a6)[2].look.b.size;
        if (reg_d0.b[0] != 2) {
            reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1C);
            reg_d0.h[0] += 1;
            *(u16 *)(reg_a5 + 0x18) = (u16) reg_d0.h[0];
            *(u16 *)(reg_a5 + 0x1C) += 1;
            *(u16 *)(reg_a5 + 0x1C) &= 3;
            return;
        }
        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
        if (reg_d0.h[0] == 5) {
            *(u16 *)(reg_a5 + 0x18) = 2U;
            return;
        }
        *(u16 *)(reg_a5 + 0x18) = 5U;
        return;
    }
    g_enemy_signal_4_as_s16 = 0;
    *(u16 *)(reg_a5 + 0x18) = 6U;
}

s32 entity_velocity();
s32 direction_between();
s32 direction_turn_toward();
s32 func_00202B50();
extern u8 stage3_midboss2_state_routines_0[];

void func_001D5670(void) {
    if (*(u8 *)(reg_a5 + 0x25) != 0) {
        ENTITY(reg_a6)->move.sh = 0x420;
        entity_velocity();
        return;
    }
    reg_a0 = stage3_midboss2_state_routines_0;
    reg_a0 += ENTITY(reg_a6)[4].offset_y.h;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    entity_velocity();
    reg_a0 = stage3_midboss2_state_routines_0;
    reg_a0 += ENTITY(reg_a6)[4].offset_y.h;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    func_00202B50();
    if ((s16) reg_d0.h[0] < 0x101) {
        ENTITY(reg_a6)[4].offset_y.h += 4;
        ENTITY(reg_a6)[4].offset_y.h &= 0xF;
    }
}

s32 spawn_request_add();

void stage3_midboss_mode_00(void) {
    if (*(u8 *)(reg_a5 + 0x1B) == 0) {
        reg_d0.h[0] = ENTITY(reg_a6)[3].offset_y.h;
        ENTITY(reg_a6)->y.h += reg_d0.h[0];
        if ((s16) ENTITY(reg_a6)->y.h > 0x3C00) {
            ENTITY(reg_a6)[3].offset_y.h -= 9;
            if (0 >= (s16) ENTITY(reg_a6)[3].offset_y.h) {
                *(u8 *)(reg_a5 + 0x1B) = 1U;
                reg_d0.w = 0x14;
                spawn_request_add();
                func_001D55B0();
                ENTITY(reg_a6)->flags.h = 0xA001;
                ENTITY(reg_a6)[1].flags.h = 0xA001;
                ENTITY(reg_a6)[2].flags.h = 0xA001;
            }
        }
    }
}

s32 aim_at_player();

void func_001D5830(void) {
    reg_d0.h[0] = ENTITY(reg_a6)[1].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[1].x.h;
    reg_d0.h[0] += ENTITY(reg_a6)[1].offset_y.h;
    reg_d1.h[0] += ENTITY(reg_a6)[1].offset_x.h;
    aim_at_player();
    if (cond_flag != 0) {
        reg_d1.h[0] = 0x20;
    }
    ENTITY(reg_a6)[4].hit_y_plus.b[1] = (u8) reg_d1.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)[2].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[2].x.h;
    reg_d0.h[0] += ENTITY(reg_a6)[2].offset_y.h;
    reg_d1.h[0] += ENTITY(reg_a6)[2].offset_x.h;
    aim_at_player();
    if (cond_flag != 0) {
        reg_d1.h[0] = 0x20;
    }
    ENTITY(reg_a6)[4].hit_y_plus.b[0] = (u8) reg_d1.b[0];
}

extern u16 g_rank_1_16;

void func_001D58F0(void) {
    s32 var_a1;
    u16 temp_v1;
    u8 temp_a0;
    u8 *var_a0;
    if (*(u8 *)(reg_a5 + 0x1B) == 0) {
        var_a1 = 0x404;
        *(u8 *)(reg_a5 + 0x1B) = 1U;
        ENTITY(reg_a6)[4].offset_x.sh = 0x404;
        ENTITY(reg_a6)[4].draw.sh = 0x1020;
        ENTITY(reg_a6)[4].sprite.h = 6U;
        reg_d0.b[0] = ENTITY(reg_a6)[1].look.b.size;
        reg_d0.b[0] += ENTITY(reg_a6)[2].look.b.size;
        if (reg_d0.b[0] != 0) {
            ENTITY(reg_a6)[4].draw.sh = 0x1008;
            ENTITY(reg_a6)[4].sprite.h = 0x20U;
        }
        ENTITY(reg_a6)[1].sprite.sh = 0;
        *(u8 *)(reg_a5 + 0x1B) = 1U;
    }
    reg_d0.b[0] = ENTITY(reg_a6)[1].look.b.size;
    reg_d0.b[0] += ENTITY(reg_a6)[2].look.b.size;
    if (reg_d0.b[0] != 2) {
        func_001D5670();
        if (*(u8 *)(reg_a5 + 0x1B) == 1) {
            temp_v1 = ENTITY(reg_a6)[4].look.h;
            if (temp_v1 != 0) {
                ENTITY(reg_a6)[4].look.h = (u16) (temp_v1 - 1);
            } else {
                reg_tmp.b[0] = ENTITY(reg_a6)[1].sprite.b[1];
                ENTITY(reg_a6)[1].sprite.b[1] -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    ENTITY(reg_a6)[1].sprite.b[1] = (u8) ENTITY(reg_a6)[1].sprite.b[0];
                    ENTITY(reg_a6)[2].draw.h += 4;
                    ENTITY(reg_a6)[1].draw.h += 4;
                    if ((s16) ENTITY(reg_a6)[1].draw.h >= 0x1C) {
                        ENTITY(reg_a6)[1].draw.h = 0x1CU;
                        ENTITY(reg_a6)[2].draw.h = 0x1CU;
                        *(u8 *)(reg_a5 + 0x1B) = 2U;
                        func_001D5830();
                    }
                }
            }
        }
        if (*(u8 *)(reg_a5 + 0x1B) == 2) {
            reg_tmp.b[0] = ENTITY(reg_a6)[4].offset_x.b[1];
            ENTITY(reg_a6)[4].offset_x.b[1] -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ENTITY(reg_a6)[4].offset_x.b[1] = (u8) ENTITY(reg_a6)[4].offset_x.b[0];
                temp_a0 = ENTITY(reg_a6)->move.b.speed;
                if (temp_a0 != 8) {
                    ENTITY(reg_a6)->move.b.speed = (u8) (temp_a0 + 1);
                }
            }
            reg_tmp.b[0] = ENTITY(reg_a6)[4].draw.b.priority;
            ENTITY(reg_a6)[4].draw.b.priority -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                reg_d0.h[0] = 0x20;
                reg_d0.h[0] -= g_rank_1_16;
                ENTITY(reg_a6)[4].draw.b.priority = (u8) reg_d0.b[0];
                reg_d0.b[0] = ENTITY(reg_a6)[1].look.b.size;
                reg_d0.b[0] += ENTITY(reg_a6)[2].look.b.size;
                if (reg_d0.b[0] != 0) {
                    ENTITY(reg_a6)[4].draw.b.flip = 8;
                }
                if (ENTITY(reg_a6)[1].look.b.size == 0) {
                    reg_d1.w = 0;
                    reg_d1.b[0] = ENTITY(reg_a6)[4].hit_y_plus.b[1];
                    reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
                    reg_d5.h[1] = ENTITY(reg_a6)[1].offset_y.h;
                    reg_d5.h[0] = ENTITY(reg_a6)[1].offset_x.h;
                    reg_d4.w = 0;
                    func_001D46A0();
                }
                if (ENTITY(reg_a6)[2].look.b.size == 0) {
                    reg_d1.w = 0;
                    reg_d1.b[0] = ENTITY(reg_a6)[4].hit_y_plus.b[0];
                    reg_d2.h[1] = ENTITY(reg_a6)[2].y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)[2].x.h;
                    reg_d5.h[1] = ENTITY(reg_a6)[2].offset_y.h;
                    reg_d5.h[0] = ENTITY(reg_a6)[2].offset_x.h;
                    reg_d4.w = 0;
                    func_001D46A0();
                }
                ENTITY(reg_a6)[4].sprite.h -= 1;
                if (ENTITY(reg_a6)[4].sprite.h == 0) {
                    *(u8 *)(reg_a5 + 0x1B) = 3U;
                    ENTITY(reg_a6)[1].sprite.sh = 0x2000;
                }
            }
        }
        if (*(u8 *)(reg_a5 + 0x1B) == 3) {
            reg_tmp.b[0] = ENTITY(reg_a6)[1].sprite.b[1];
            ENTITY(reg_a6)[1].sprite.b[1] -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ENTITY(reg_a6)[1].sprite.b[1] = (u8) ENTITY(reg_a6)[1].sprite.b[0];
                ENTITY(reg_a6)[2].draw.h -= 4;
                ENTITY(reg_a6)[1].draw.h -= 4;
                var_a0 = (unsigned char *)((reg_a6 + 0x2A));
                if (0 >= (s16) ENTITY(reg_a6)[1].draw.h) {
                    *(u16 *)var_a0 = 0;
                    ENTITY(reg_a6)[2].draw.h = 0U;
                    goto block_28;
                }
            }
        }
    } else {
block_28:
        func_001D55B0();
    }
}

extern u8 stage3_midboss2_state_routines_1[];


void func_001D5CA0(void) {
    u32 temp_a0_2;
    u32 temp_a0_4;
    u8 *var_a0;
    u8 *var_a1;
    if (*(u8 *)(reg_a5 + 0x1B) == 0) {
        ENTITY(reg_a6)[5].draw.h = (u16) ENTITY(reg_a6)[5].hit_y_plus.h;
        ENTITY(reg_a6)[5].hit_y_plus.b[0] -= 4;
        if ((s8) ENTITY(reg_a6)[5].hit_y_plus.h < 0x11) {
            ENTITY(reg_a6)[5].hit_y_plus.b[0] = 0x10;
        }
        ENTITY(reg_a6)[5].sprite.h = 8U;
        var_a1 = (u8 *)(reg_a6);
        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a1) + (0x2F)));
        reg_d0.b[0] += (*(u8 *)((u8 *)(var_a1) + (0x4F)));
        if (reg_d0.b[0] != 0) {
            (*(s16 *)((u8 *)(var_a1) + (0x8A))) = 0x1008;
            ENTITY(reg_a6)[5].sprite.h = 0x10U;
            ENTITY(reg_a6)[5].hit_y_plus.b[0] = 8;
            ENTITY(reg_a6)[5].draw.h = (u16) ENTITY(reg_a6)[5].hit_y_plus.h;
        }
        ENTITY(reg_a6)[5].look.h = 0U;
        ENTITY(reg_a6)[1].sprite.sh = 0;
        *(u8 *)(reg_a5 + 0x1B) = 1U;
    }
    reg_d0.b[0] = ENTITY(reg_a6)[1].look.b.size;
    reg_d0.b[0] += ENTITY(reg_a6)[2].look.b.size;
    if (reg_d0.b[0] != 2) {
        func_001D5670();
        if (*(u8 *)(reg_a5 + 0x1B) == 1) {
            reg_tmp.b[0] = ENTITY(reg_a6)[1].sprite.b[1];
            ENTITY(reg_a6)[1].sprite.b[1] -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ENTITY(reg_a6)[1].sprite.b[1] = ENTITY(reg_a6)[1].sprite.b[0];
                ENTITY(reg_a6)[2].draw.h += 4;
                ENTITY(reg_a6)[1].draw.h += 4;
                if ((s16) ENTITY(reg_a6)[1].draw.h >= 0x1C) {
                    ENTITY(reg_a6)[1].draw.h = 0x1CU;
                    ENTITY(reg_a6)[2].draw.h = 0x1CU;
                    *(u8 *)(reg_a5 + 0x1B) = 2U;
                }
            }
        }
        if (*(u8 *)(reg_a5 + 0x1B) == 2) {
            reg_tmp.b[0] = ENTITY(reg_a6)[5].draw.b.priority;
            ENTITY(reg_a6)[5].draw.b.priority -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ENTITY(reg_a6)[5].draw.b.priority = ENTITY(reg_a6)[5].draw.b.flip;
                reg_d0.b[0] = ENTITY(reg_a6)[1].look.b.size;
                reg_d0.b[0] += ENTITY(reg_a6)[2].look.b.size;
                if (reg_d0.b[0] != 0) {
                    ENTITY(reg_a6)[5].draw.b.flip = 8;
                }
                reg_a4 = (u8 *)stage3_midboss2_state_routines_1;
                reg_a4 += ENTITY(reg_a6)[5].look.h;
                reg_tmp.h[1] = *(u16 *)reg_a4;
                reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
                reg_a4 = (u8 *) reg_tmp.w;
                ENTITY(reg_a6)[5].look.h += 4;
                ENTITY(reg_a6)[5].look.h &= 0x1F;
                if (ENTITY(reg_a6)[1].look.b.size == 0) {
                    reg_d0.h[0] = ENTITY(reg_a6)[1].y.h;
                    reg_d1.h[0] = ENTITY(reg_a6)[1].x.h;
                    reg_d0.h[0] += ENTITY(reg_a6)[1].offset_y.h;
                    reg_d1.h[0] += ENTITY(reg_a6)[1].offset_x.h;
                    aim_at_player();
                    if (cond_flag != 0) {
                        reg_d1.h[0] = 0x20;
                    }
                    reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
                    reg_d3.h[1] = ENTITY(reg_a6)[1].offset_y.h;
                    temp_a0_2 = ENTITY(reg_a6)[1].offset_x.h;
                    reg_d3.h[0] = temp_a0_2;
                    reg_a0 = reg_a6 + 0x20;
                    reg_call_target = (Fn)(reg_a4);
                    reg_call_target();
                }
                if (ENTITY(reg_a6)[2].look.b.size == 0) {
                    reg_d0.h[0] = ENTITY(reg_a6)[2].y.h;
                    reg_d1.h[0] = ENTITY(reg_a6)[2].x.h;
                    reg_d0.h[0] += ENTITY(reg_a6)[2].offset_y.h;
                    reg_d1.h[0] += ENTITY(reg_a6)[2].offset_x.h;
                    aim_at_player();
                    if (cond_flag != 0) {
                        reg_d1.h[0] = 0x20;
                    }
                    reg_d2.h[1] = ENTITY(reg_a6)[2].y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)[2].x.h;
                    reg_d3.h[1] = ENTITY(reg_a6)[2].offset_y.h;
                    temp_a0_4 = ENTITY(reg_a6)[2].offset_x.h;
                    reg_d3.h[0] = temp_a0_4;
                    reg_a0 = reg_a6 + 0x40;
                    reg_call_target = (Fn)(reg_a4);
                    reg_call_target();
                }
                ENTITY(reg_a6)[5].sprite.h -= 1;
                if (ENTITY(reg_a6)[5].sprite.h == 0) {
                    *(u8 *)(reg_a5 + 0x1B) = 3U;
                    ENTITY(reg_a6)[1].sprite.sh = 0x2000;
                }
            }
        }
        if (*(u8 *)(reg_a5 + 0x1B) == 3) {
            reg_tmp.b[0] = ENTITY(reg_a6)[1].sprite.b[1];
            ENTITY(reg_a6)[1].sprite.b[1] -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ENTITY(reg_a6)[1].sprite.b[1] = ENTITY(reg_a6)[1].sprite.b[0];
                ENTITY(reg_a6)[2].draw.h -= 4;
                ENTITY(reg_a6)[1].draw.h -= 4;
                var_a0 = (unsigned char *)((reg_a6 + 0x2A));
                if (0 >= (s16) ENTITY(reg_a6)[1].draw.h) {
                    *(u16 *)var_a0 = 0;
                    ENTITY(reg_a6)[2].draw.h = 0U;
                    goto block_29;
                }
            }
        }
    } else {
block_29:
        func_001D55B0();
    }
}

extern void bullet_fire256_fixed(void);
extern u32 D_00259970_as_u32_a[];

void stage3_midboss2_state_0_04(void)
{
    reg_d0.w = 0x80004;
    reg_d4.w = 0;
    reg_d7.w = 0xF;
    reg_a0 = (u8 *)D_00259970_as_u32_a;

    do {
        bullet_fire256_fixed();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern void bullet_fire256_double(void);

void func_001D6160(void)
{
    reg_d1.b[0] *= 4;
    reg_d0.w = 0x80003;
    reg_d4.w = 0;
    reg_d1.b[0] -= 2;
    bullet_fire256_double();
    reg_d1.b[0] += 4;
    bullet_fire256_double();
}

s32 func_00202730();

void func_001D61B0(arg1, arg2)
    s32 arg1;
    s32 arg2;
{
    s32 var_a1;
    s32 var_a2;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;

    var_a1 = arg1;
    var_a2 = arg2;
    if (ENTITY(reg_a6)[6].offset_y.b[1] == 0) {
        var_a2 = 0x1010;
        ENTITY(reg_a6)[6].offset_y.b[1] = 1U;
        var_a1 = 0x505;
        ENTITY(reg_a6)[6].draw.sh = 0x1010;
        ENTITY(reg_a6)[6].sprite.sh = 0x505;
        ENTITY(reg_a6)[6].move.h = 0x60U;
    }
    if (*(u16 *)(reg_a5 + 0x2E) != 0) {
        temp_a0 = ENTITY(reg_a6)[6].offset_y.b[1];
        if (temp_a0 == 1) {
            func_001D66B0();
            if (cond_flag == 0) {
                ENTITY(reg_a6)[6].move.h -= 1;
                if (ENTITY(reg_a6)[6].move.h == 0) {
                    func_001D6690();
                    ENTITY(reg_a6)[6].offset_y.b[1] = 2U;
                }
            }
        }
        temp_a0_2 = ENTITY(reg_a6)[6].offset_y.b[1];
        if (temp_a0_2 == 2) {
            func_001D66B0();
            if ((cond_flag == 0) && (*(u8 *)(reg_a5 + 0x25) == 0)) {
                reg_tmp.b[0] = ENTITY(reg_a6)[6].draw.b.priority;
                ENTITY(reg_a6)[6].draw.b.priority -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    ENTITY(reg_a6)[6].draw.b.priority = ENTITY(reg_a6)[6].draw.b.flip;
                    reg_d1.h[0] = 0x80;
                    func_00202730();
                    reg_d7.b[0] = reg_d1.b[0];
                    reg_d0.w = 0x13;
                    spawn_request_add();
                    *(u16 *)(reg_a0 + 0x16) = (u16) ENTITY(reg_a6)->y.h;
                    *(u16 *)(reg_a0 + 0x18) = (u16) ENTITY(reg_a6)->x.h;
                    *(u16 *)(reg_a0 + 0x16) -= 0x800;
                    *(s8 *)(reg_a0 + 0x1B) = 0;
                    rng_next();
                    reg_d0.b[0] += reg_d7.b[0];
                    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
                    ENTITY(reg_a6)[6].sprite.b[1] -= 1;
                    if (ENTITY(reg_a6)[6].sprite.b[1] == 0) {
                        ENTITY(reg_a6)[6].offset_y.b[1] = 3U;
                        ENTITY(reg_a6)[6].move.h = 0x40U;
                    }
                }
            }
        }
    }
    temp_a0_3 = ENTITY(reg_a6)[6].offset_y.b[1];
    if (temp_a0_3 == 3) {
        ENTITY(reg_a6)[6].move.h -= 1;
        if (ENTITY(reg_a6)[6].move.h == 0) {
            func_001D66A0();
            ENTITY(reg_a6)[6].move.h = 0x60U;
            ENTITY(reg_a6)[6].offset_y.b[1] = 1U;
            ENTITY(reg_a6)[6].sprite.b[1] = ENTITY(reg_a6)[6].sprite.b[0];
            reg_d0.b[0] = ENTITY(reg_a6)[1].look.b.size;
            reg_d0.b[0] += ENTITY(reg_a6)[2].look.b.size;
            if (reg_d0.b[0] != 0) {
                ENTITY(reg_a6)[6].sprite.b[1] = 0xAU;
            }
        }
    }
}

s32 bullet_fire256();
extern u16 D_00259970[];

void func_001D6410(void) {
    u8 t1;

    if (*(u8 *)(reg_a5 + 0x1B) == 0) {
        *(u8 *)(reg_a5 + 0x1B) = 1U;
        ENTITY(reg_a6)[6].look.sh = 0x810;
        ENTITY(reg_a6)[6].hit_y_plus.sh = 0x20;
        ENTITY(reg_a6)[6].hit_x_minus.b[1] = 1U;
        ENTITY(reg_a6)[6].hp.b[1] = 0U;
        ENTITY(reg_a6)[6].hit_x_plus.sb[1] = 0;
        ENTITY(reg_a6)->sprite.sh = 0x3001;
        func_001D6690();
    }
    func_001D5670();
    if (*(u8 *)(reg_a5 + 0x25) == 0) {
        reg_tmp.b[0] = ENTITY(reg_a6)[6].look.b.size;
        ENTITY(reg_a6)[6].look.b.size -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            reg_d0.h[0] = 0x10;
            reg_d1.h[0] = g_rank_1_16;
            reg_d1.h[0] >>= 2;
            reg_d0.b[0] -= reg_d1.b[0];
            ENTITY(reg_a6)[6].look.b.size = (u8) reg_d0.b[0];
            func_00202730();
            if (cond_flag == 0) {
                reg_d0.w = 0x70004;
                t1 = 0xF6000000;
                reg_d1.h[0] -= 0x20;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d5.w = 0xF6000000;
                reg_d7.w = 8;
                reg_a0 = (u8 *)(D_00259970);
                reg_d4.w = 0;
                do {
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d3.h[0] += 2;
                    reg_d3.h[0] &= 0xFC;
                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d3.w += reg_d5.w;
                    bullet_fire256();
                    reg_d1.b[0] += 8;
                } while ((s16)(--reg_d7.h[0]) >= 0);
                reg_d0.b[0] = ENTITY(reg_a6)[6].hit_x_minus.b[1];
                ENTITY(reg_a6)[6].hp.b[1] += reg_d0.b[0];
                if ((s8) reg_d0.b[0] < 0) {
                    if (ENTITY(reg_a6)[6].hp.sb[1] < -4) {
                        ENTITY(reg_a6)[6].hit_x_minus.b[1] *= -1;
                    }
                } else if (ENTITY(reg_a6)[6].hp.sb[1] > 4) {
                    ENTITY(reg_a6)[6].hit_x_minus.b[1] *= -1;
                }
            }
        }
    }
}

void func_001D6690(void) {
    ENTITY(reg_a6)[3].offset_x.b[1] = 1;
}

void func_001D66A0(void) {
    ENTITY(reg_a6)[3].offset_x.b[1] = 2;
}

void func_001D66B0(void) {
    if (ENTITY(reg_a6)[3].offset_x.b[1] == 0) {
        cond_flag = 0;
        return;
    }
    cond_flag = 1;
}


void func_001D66E0(void) {
    func_001D6710();
    func_001D6790();
}

void func_001D6710(void) {
    if (ENTITY(reg_a6)[3].offset_x.b[1] == 1) {
        reg_tmp.b[0] = ENTITY(reg_a6)[3].draw.b.priority;
        ENTITY(reg_a6)[3].draw.b.priority -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            ENTITY(reg_a6)[3].draw.b.priority = (u8) ENTITY(reg_a6)[3].draw.b.flip;
            ENTITY(reg_a6)->draw.h += 4;
            if ((s16) ENTITY(reg_a6)->draw.h >= 0x1C) {
                ENTITY(reg_a6)->draw.h = 0x1CU;
                ENTITY(reg_a6)[3].offset_x.b[1] = 0U;
            }
        }
    }
}

void func_001D6790(void) {
    if (ENTITY(reg_a6)[3].offset_x.b[1] == 2) {
        reg_d0.b[0] = ENTITY(reg_a6)[1].look.b.size;
        reg_d0.b[0] += ENTITY(reg_a6)[2].look.b.size;
        if (reg_d0.b[0] != 2) {
            reg_tmp.b[0] = ENTITY(reg_a6)[3].draw.b.priority;
            ENTITY(reg_a6)[3].draw.b.priority -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ENTITY(reg_a6)[3].draw.b.priority = (u8) ENTITY(reg_a6)[3].draw.b.flip;
                ENTITY(reg_a6)->draw.h -= 4;
                if (0 >= (s16) ENTITY(reg_a6)->draw.h) {
                    ENTITY(reg_a6)->draw.h = 0U;
                    goto block_5;
                }
            }
        } else {
block_5:
            ENTITY(reg_a6)[3].offset_x.b[1] = 0U;
        }
    }
}

void func_001D6830(s32 arg0) {
    s16 temp_v0;
    s32 var_a0;

    var_a0 = arg0;
    if (*(u8 *)(reg_a5 + 0x1B) == 0) {
        func_001D66A0();
        var_a0 = 0x600;
        ENTITY(reg_a6)->move.sh = 0x600;
        *(u8 *)(reg_a5 + 0x1B) = 1U;
    }
    if (*(u8 *)(reg_a5 + 0x1B) == 1) {
        reg_tmp.b[0] = ENTITY(reg_a6)[1].sprite.b[1];
        ENTITY(reg_a6)[1].sprite.b[1] -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            ENTITY(reg_a6)[1].sprite.b[1] = (u8) ENTITY(reg_a6)[1].sprite.b[0];
            ENTITY(reg_a6)[2].draw.h -= 4;
            ENTITY(reg_a6)[1].draw.h -= 4;
            if (0 >= (s16) ENTITY(reg_a6)[1].draw.h) {
                ENTITY(reg_a6)[1].draw.h = 0U;
                ENTITY(reg_a6)[2].draw.h = 0U;
                *(u8 *)(reg_a5 + 0x1B) = 2U;
            }
        }
    }
    if ((*(u8 *)(reg_a5 + 0x1B) == 2) && (ENTITY(reg_a6)->y.sh >= 0x6A00)) {
        func_00138A40();
        g_enemy_signal_e_as_s16 = 0;
        *(u8 *)(reg_a5 + 0x1B) = 3U;
    }
    if (*(u8 *)(reg_a5 + 0x1B) == 3) {
        temp_v0 = ENTITY(reg_a6)->y.sh;
        if ((temp_v0 < -0x63FF) && (temp_v0 > -0x6800)) {
            *(s16 *)(reg_a5 + 0x30) = 1;
        }
    }
    entity_velocity();
}

s32 sprite_draw_layer4();
extern u8 D_00263630[];
extern u8 D_00263650[];

void func_001D6990(void) {
    u16 temp_a0;

    reg_a0 = D_00263650;
    reg_a0 += ENTITY(reg_a6)->draw.h;
    ENTITY(reg_a6)->hit_x_plus.h = (u16) *(u16 *)reg_a0;
    ENTITY(reg_a6)->hit_x_minus.h = (u16) *(u16 *)(reg_a0 + 2);
    reg_a0 = D_00263630;
    reg_a0 += ENTITY(reg_a6)->draw.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF200F100;
    reg_d3.h[0] = 0xE78;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    sprite_draw_layer4();
}

extern u8 D_00263670[];
extern u8 D_00263690[];

void func_001D6A40(void) {
    u16 temp_a0;
    u16 temp_a1;

    if (ENTITY(reg_a6)[1].look.b.size == 0) {
        reg_a0 = (u8 *)D_00263670;
        reg_a0 += *(u16 *)(reg_a5 + 0x32);
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)[1].y.h;
        temp_a0 = ENTITY(reg_a6)[1].x.h;
        reg_d1.h[0] = temp_a0;
        reg_d1.w += 0xF000F900;
        reg_d3.h[0] = 0x1038;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)[1].move.b.speed;
        sprite_draw_layer4();
        reg_a0 = (u8 *)D_00263690;
        reg_a0 += ENTITY(reg_a6)[1].draw.h;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)[1].y.h;
        temp_a1 = ENTITY(reg_a6)[1].x.h;
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xEC000200;
        reg_d4.w = 0;
        reg_d1.w += 0xF200F900;
        reg_d3.h[0] = 0xE38;
        reg_d4.b[0] = ENTITY(reg_a6)[1].move.b.dir;
        sprite_draw_layer4();
    }
}

extern u8 D_002636B0[];
extern u8 D_002636D0[];

void func_001D6B60(void) {
    u16 temp_a0;
    u16 temp_a1;

    if (ENTITY(reg_a6)[2].look.b.size == 0) {
        reg_a0 = (u8 *)D_002636B0;
        reg_a0 += *(u16 *)(reg_a5 + 0x32);
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)[2].y.h;
        temp_a0 = ENTITY(reg_a6)[2].x.h;
        reg_d1.h[0] = temp_a0;
        reg_d1.w += 0xF000F900;
        reg_d3.h[0] = 0x1038;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)[2].move.b.speed;
        sprite_draw_layer4();
        reg_a0 = (u8 *)D_002636D0;
        reg_a0 += ENTITY(reg_a6)[2].draw.h;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)[2].y.h;
        temp_a1 = ENTITY(reg_a6)[2].x.h;
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xF200F900;
        reg_d4.w = 0;
        reg_d1.w += 0xEBFFFE00;
        reg_d3.h[0] = 0xE38;
        reg_d4.b[0] = ENTITY(reg_a6)[2].move.b.dir;
        sprite_draw_layer4();
    }
}

void func_001D6C80(void) {
    enemy_set_entity_count(0);
}

extern u8 D_002636F0[];

void func_001D6C90(void) {
    reg_a0 = D_002636F0;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    ENTITY(reg_a6)->x.h = (u16) *(u16 *)(reg_a5 + 0x18);
    ENTITY(reg_a6)->move.h = (u16) *(u16 *)(reg_a5 + 0x1A);
    rng_next();
    reg_d0.b[0] *= 2;
    ENTITY(reg_a6)->move.b.dir += reg_d0.b[0];
    *(u16 *)(reg_a5 + 0x18) = 0x408U;
    *(u16 *)(reg_a5 + 0x1A) = 2U;
    *(s16 *)(reg_a5 + 0x1E) = 0;
    *(s16 *)(reg_a5 + 0x20) = 0;
    *(s16 *)(reg_a5 + 0x22) = 0x101;
    *(s16 *)(reg_a5 + 0x24) = 0;
    *(s8 *)(reg_a5 + 0x27) = 6;
    *(s8 *)(reg_a5 + 0x17) = 0;
}

s32 sfx_explosion_air_small();
s32 entity_draw_layer5_zoom();
s32 func_00201F20();
s32 entity_check_bounds();
extern u8 D_00263710[];
extern u8 D_00263750[];
extern u8 D_0028E2E4;
extern u16 g_enemy_signal_e;

void func_001D6D60(void) {
    if (D_0028E2E4 != 0) {
        goto next_1;
    }
    if (g_enemy_signal_4 == 0) {
        goto next_2;
    }
    if (g_enemy_signal_e == 0) {
        goto next_2;
    }
    if (g_enemy_signal_e == 2) {
        goto next_2;
    }
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *) (reg_a6 + 1);
    if (reg_d1.b[0] == 0) {
        goto next_3;
    }
    reg_d0.b[0] = 0xA3;
    *(u8 *) (reg_a6 + 1) &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = *(u8 *) (reg_a6 + 0x1C);
    reg_d2.b[0] = 0x15;
    reg_d0.b[0] ^= reg_d2.b[0];
    *(u8 *) (reg_a6 + 0x1C) = reg_d0.b[0];
    if (*(s16 *) (reg_a6 + 0x18) >= 0) {
        goto next_4;
    }
next_2:
    reg_d0.w = 2;
    explosion_spawn();
    *(u16 *) (reg_a0 + 2) = *(u16 *) (reg_a6 + 2);
    *(u16 *) (reg_a0 + 4) = *(u16 *) (reg_a6 + 4);
    *(u16 *) (reg_a0 + 0x1A) = *(u16 *) (reg_a6 + 0x1A);
    *(u16 *) (reg_a0 + 0x1E) = 0x10;
    sfx_explosion_air_small();
next_1:
    enemy_remove();
    return;
next_3:
    *(u8 *) (reg_a6 + 0x1C) = 0xA;
next_4:
    entity_check_bounds();
    if (cond_flag == 0) {
        goto next_5;
    }
    if (*(u8 *) (reg_a5 + 0x17) == 0) {
        goto next_6;
    }
    enemy_remove();
    return;
next_5:
    *(u8 *) (reg_a5 + 0x17) = 1;
next_6:
    if (g_enemies_stopped != 0) {
        goto next_15;
    }
    func_00201F20();
    reg_tmp.b[0] = *(u8 *) (reg_a5 + 0x1B);
    *(u8 *) (reg_a5 + 0x1B) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_8;
    }
    *(u8 *) (reg_a5 + 0x1B) = *(u8 *) (reg_a5 + 0x1A);
    if (*(u8 *) (reg_a5 + 0x27) == 0) {
        goto next_7;
    }
    if (*(u8 *) (reg_a6 + 0x1B) == 4) {
        goto next_8;
    }
next_7:
    *(u8 *) (reg_a6 + 0x1B) += 1;
next_8:
    if (*(s16 *) (reg_a6 + 2) <= 0x600) {
        goto next_9;
    }
    if (*(u8 *) (reg_a5 + 0x27) == 0) {
        goto next_10;
    }
    if (*(s8 *) (reg_a6 + 0x1B) < 4) {
        goto next_10;
    }
    reg_tmp.b[0] = *(u8 *) (reg_a5 + 0x19);
    *(u8 *) (reg_a5 + 0x19) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_10;
    }
    *(u8 *) (reg_a5 + 0x19) = *(u8 *) (reg_a5 + 0x18);
    func_00202730();
    if (cond_flag != 0) {
        goto next_10;
    }
    rng_next();
    reg_d0.b[0] = (s8) reg_d0.b[0] >> 1;
    reg_d1.b[0] += reg_d0.b[0];
    reg_d0.w = 0x16;
    reg_d2.h[1] = *(u16 *) (reg_a6 + 2);
    reg_d2.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d4.w = 0;
    reg_d3.w = 0;
    bullet_fire256();
next_9:
    *(u8 *) (reg_a5 + 0x27) -= 1;
next_10:
    reg_tmp.b[0] = *(u8 *) (reg_a5 + 0x1F);
    *(u8 *) (reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_11;
    }
    *(u8 *) (reg_a5 + 0x1F) = *(u8 *) (reg_a5 + 0x1E);
    reg_a0 = (u8 *)D_00263710;
    reg_d0.h[0] = *(u16 *) (reg_a5 + 0x20);
    *(u16 *) (reg_a6 + 0xA) = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a0;
    *(u16 *) (reg_a6 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    *(u16 *) (reg_a5 + 0x20) += 4;
    *(u16 *) (reg_a5 + 0x20) &= 0x3F;
next_11:
    reg_tmp.b[0] = *(u8 *) (reg_a5 + 0x23);
    *(u8 *) (reg_a5 + 0x23) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_15;
    }
    *(u8 *) (reg_a5 + 0x23) = *(u8 *) (reg_a5 + 0x22);
    if (*(u16 *) (reg_a5 + 0x24) == 0x5C) {
        goto next_15;
    }
    *(u16 *) (reg_a5 + 0x24) += 4;
    *(u16 *) (reg_a6 + 0x10) += 0x40;
    *(u16 *) (reg_a6 + 0x12) += 0x40;
    *(u16 *) (reg_a6 + 0x14) += 0x20;
    *(u16 *) (reg_a6 + 0x16) += 0x20;
next_15:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = (u8 *)D_00263750;
    reg_a0 += *(u16 *) (reg_a5 + 0x24);
    reg_d6.h[1] = *(u16 *) reg_a0;
    reg_d6.h[0] = *(u16 *) (reg_a0 + 2);
    entity_draw_layer5_zoom();
}
