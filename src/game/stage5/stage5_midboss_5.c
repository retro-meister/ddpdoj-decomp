#include "common.h"
#include "player.h"
#include "entity.h"

void func_001FDAB0(void);
void func_001FDBD0(void);
void func_001FDC10(void);
void func_001FDC80(void);
void func_001FDCF0(void);
void func_001FDD60(void);
void func_001FDDD0(void);
void func_001FDE00(void);
void func_001FDED0(void);
void func_001FDFC0(void);
void func_001FE0F0(void);
void func_001FE100(void);
void func_001FE120(void);
void func_001FE2E0(void);
void func_001FE2F0(void);
void func_001FE330(void);
void func_001FE6D0(void);
void func_001FEA90(void);
void func_001FEF40(void);
void func_001FEF70(void);
void func_001FF000(void);
void func_001FF0B0(void);
void func_001FFA50(void);
void func_00200420(void);
void func_002004E0(void);

s32 bullet_fire_fixed();
extern u16 g_direction64_offsets_432[];
extern u16 g_loop;

void func_001FC8E0(void) {
    u16 temp_a0;
    u16 var_v0_11;
    u16 var_v0_13;
    u16 var_v0_15;
    u16 var_v0_17;
    u16 var_v0_19;
    u16 var_v0_21;
    u16 var_v0_23;
    u16 var_v0_3;
    u16 var_v0_5;
    u16 var_v0_7;
    u16 var_v0_9;
    u32 temp_s0;
    u32 temp_s0_10;
    u32 temp_s0_11;
    u32 temp_s0_2;
    u32 temp_s0_3;
    u32 temp_s0_4;
    u32 temp_s0_5;
    u32 temp_s0_6;
    u32 temp_s0_7;
    u32 temp_s0_8;
    u32 temp_s0_9;

    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    reg_a4 = (u8 *)reg_tmp.w;
    if (*(u16 *)(reg_a5 + 0x1A) != 0) {
        reg_d6.b[0] = 0xFD;
        reg_d1.b[0] = 0x1B;
        reg_d7.w = 0;
        if (g_loop != 0) {
            reg_d7.b[0] = 1;
            reg_d1.b[0] = 0x1E;
        }
    } else {
        reg_d6.b[0] = 3;
        reg_d1.b[0] = 0x25;
        reg_d7.w = 0;
        if (g_loop != 0) {
            reg_d7.b[0] = 0xFF;
            reg_d1.b[0] = 0x22;
        }
    }
    reg_d2.h[1] = (*(u16 *)((u8 *)((u32)reg_a4) + (2)));
    temp_a0 = (*(u16 *)((u8 *)((u32)reg_a4) + (4)));
    reg_d2.h[0] = temp_a0;
    reg_a0 = (u8 *)(g_direction64_offsets_432);
    reg_d4.w = 0;
    reg_d3.w = 0;
    if (g_loop != 0) {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] *= 4;
        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        var_v0_3 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        temp_s0 = reg_d1.w;
        reg_d3.h[0] = var_v0_3;
        reg_d0.w = 0x4000B;
        bullet_fire_fixed();
        reg_d0.w -= 0x40000;
        reg_d1.b[0] += reg_d7.b[0];
        bullet_fire_fixed();
        reg_d1.w = temp_s0;
        reg_d1.b[0] += reg_d6.b[0];
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_5 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_2 = reg_d1.w;
    reg_d3.h[0] = var_v0_5;
    reg_d0.w = 0x8000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_2;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_7 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_3 = reg_d1.w;
    reg_d3.h[0] = var_v0_7;
    reg_d0.w = 0xC000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_3;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_9 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_4 = reg_d1.w;
    reg_d3.h[0] = var_v0_9;
    reg_d0.w = 0x10000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_4;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_11 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_5 = reg_d1.w;
    reg_d3.h[0] = var_v0_11;
    reg_d0.w = 0x14000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_5;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_13 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_6 = reg_d1.w;
    reg_d3.h[0] = var_v0_13;
    reg_d0.w = 0x14000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_6;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_15 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_7 = reg_d1.w;
    reg_d3.h[0] = var_v0_15;
    reg_d0.w = 0x14000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_7;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_17 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_8 = reg_d1.w;
    reg_d3.h[0] = var_v0_17;
    reg_d0.w = 0x14000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_8;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_19 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_9 = reg_d1.w;
    reg_d3.h[0] = var_v0_19;
    reg_d0.w = 0x14000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_9;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_21 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_10 = reg_d1.w;
    reg_d3.h[0] = var_v0_21;
    reg_d0.w = 0x14000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_10;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    var_v0_23 = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    temp_s0_11 = reg_d1.w;
    reg_d3.h[0] = var_v0_23;
    reg_d0.w = 0x14000B;
    bullet_fire_fixed();
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire_fixed();
    reg_d1.w = temp_s0_11;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d0.w = 0x14000B;
    bullet_fire_fixed();
}

void func_001FE990();
void func_001FEE40();

void stage5_midboss5_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(4);
}

s32 enemy_set_task_state();
s32 enemy_init_entities();
s32 sprite_palette_load();
extern u8 D_00260470[];
extern u8 D_002604B0[];
extern u8 D_002604F0[];
extern u8 D_002661C8[];
extern u8 D_002661E0[];
extern s16 g_enemy_signal_4_as_s16;
extern s16 g_enemy_signal_3_as_s16;
extern s16 D_00299768[];
extern u16 g_side_scroll_x[];

void stage5_midboss5_start(void) {
    reg_a0 = (u8 *)D_002661E0;
    enemy_init_entities();
    reg_a0 = (u8 *)D_002661C8;
    reg_d0.h[0] = 5;
    enemy_set_task_state();
    reg_tmp.w = 0xF4001C00;
    ENTITY(reg_a6)->y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = reg_tmp.h[0];
    reg_d0.h[0] = g_side_scroll_x[0];
    ENTITY(reg_a6)->x.h -= reg_d0.h[0];
    D_00299768[0] = 1;
    g_enemy_signal_3_as_s16 = 1;
    g_enemy_signal_4_as_s16 = 1;
    reg_d0.h[0] = 0x12;
    reg_a0 = (u8 *)D_00260470;
    sprite_palette_load();
    reg_d0.h[0] = 0x13;
    reg_a0 = (u8 *)D_002604B0;
    sprite_palette_load();
    reg_d0.h[0] = 0x14;
    reg_a0 = (u8 *)D_002604F0;
    sprite_palette_load();
}

s32 ground_speeds_request();
s32 func_0013B8B0();
s32 enemy_hitbox_debug_draw();
s32 score_add_no_chain();
s32 score_add();
extern u8 D_00266330[];
extern u16 g_enemy_signal_4;
extern u16 g_enemy_signal_3;
extern u16 g_enemies_stopped;
extern u16 g_scroll_line;

void stage5_midboss5_main() {
    s32 enemy_remove();
    if (g_enemies_stopped == 0) {
        if (ENTITY(reg_a6)[4].misc.b.user != 0) {
            g_enemy_signal_3 = 0;
            reg_d0.h[0] = 0x20;
            reg_d1.h[0] = 0x20;
            ground_speeds_request();
            enemy_remove();
            return;
        }
        if ((*(u8 *)(reg_a5 + 0x17) == 0) && (ENTITY(reg_a6)[4].misc.b.draw_layer == 0) && (g_scroll_line == 0x1F0)) {
            *(u8 *)(reg_a5 + 0x17) = 1U;
            *(u16 *)(reg_a5 + 0x20) = 1U;
            reg_d0.w = 7;
            func_001FDDD0();
        }
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
            ENTITY(reg_a6)[4].look.h = (u16) reg_d1.h[0];
            score_add_no_chain();
            reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
            reg_d0.b[0] ^= 0xD;
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            reg_d0.w = 0x7FFF;
            reg_d0.h[0] -= ENTITY(reg_a6)->hp.h;
            if (*(u8 *)(reg_a5 + 0x17) == 0) {
                reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1A);
                reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1C);
                reg_tmp.w -= reg_d0.w;
                *(u16 *)(reg_a5 + 0x1A) = (u16) reg_tmp.h[1];
                *(u16 *)(reg_a5 + 0x1C) = (u16) reg_tmp.h[0];
            }
            ENTITY(reg_a6)->hp.h = 0x7FFFU;
            reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1A);
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1C);
            if ((s32) reg_tmp.w < 0) {
                reg_d0.w = 0x1000;
                score_add();
                ENTITY(reg_a6)->flags.h = 0x8000;
                ENTITY(reg_a6)[4].misc.b.draw_layer = 1U;
                reg_d0.h[0] = 0x20;
                reg_d1.h[0] = 0x20;
                g_enemy_signal_3 = 0;
                g_enemy_signal_4 = 0;
                ground_speeds_request();
                reg_d0.w = 6;
                func_001FDDD0();
                reg_a0 = D_00266330;
                func_0013B8B0();
                goto block_12;
            }
        } else {
block_12:
            ENTITY(reg_a6)->attr.b.palette = 0x12U;
        }
        func_001FF0B0();
        if (ENTITY(reg_a6)[4].misc.b.draw_layer == 0) {
            func_001FDE00();
            if (*(u16 *)(reg_a5 + 0x20) == 0) {
                func_001FE120();
                func_001FE330();
            }
        }
        goto block_16;
    }
block_16:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    func_001FDCF0();
    func_001FDD60();
    func_001FDC10();
    func_001FDC80();
    func_001FDAB0();
}


void func_001FDAB0(void) {
    reg_d2.w = 0x1E92;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xF7000000;
    reg_d1.w += 0xF600F900;
    reg_d3.h[0] = 0xA38;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    func_001FDBD0();
    reg_d2.w = 0x1E91;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[1] += *(u16 *)(reg_a5 + 0x1E);
    reg_d1.w += 0x0C800000;
    reg_d1.w += 0xF200EF00;
    reg_d3.h[0] = 0xE88;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    func_001FDBD0();
    reg_d2.w = 0x1E90;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xF200E600;
    reg_d3.h[0] = 0xED0;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    func_001FDBD0();
}

s32 sprite_draw_layer1();                            /* extern */
s32 sprite_draw_layer4();                            /* extern */

void func_001FDBD0(void) {
    if (*(u8 *)(reg_a5 + 0x16) == 0) {
        sprite_draw_layer1();
        return;
    }
    sprite_draw_layer4();
}


void func_001FDC10(void) {
    u8 *object = reg_a6;

    reg_d2.w = 0x1E94;
    reg_d1.h[1] = *(u16 *)(object + 0x02);
    reg_d1.h[0] = *(u16 *)(object + 0x04);
    reg_d1.w += 0xFC3FEC80U;
    reg_d1.h[0] += *(u16 *)(object + 0x48);
    reg_d1.w += 0xFA00FF00U;
    reg_d3.h[0] = 0x608;
    reg_d4.w = 0;
    *(u8 *)&reg_d4 = object[0x5C];
    func_001FDBD0();
}

void func_001FDC80(void) {
    u8 *object = reg_a6;

    reg_d2.w = 0x1E94;
    reg_d1.h[1] = *(u16 *)(object + 0x02);
    reg_d1.h[0] = *(u16 *)(object + 0x04);
    reg_d1.w += 0xFC401380U;
    reg_d1.h[0] -= *(u16 *)(object + 0x4A);
    reg_d1.w += 0xFA00FF00U;
    reg_d3.h[0] = 0x0608;
    reg_d4.w = 0;
    *(u8 *)&reg_d4 = object[0x5C];
    func_001FDBD0();
}


void func_001FDCF0(void)
{
    u8 *object;

    reg_d2.w = 0x1E93;
    object = (void *)reg_a6;
    reg_d1.h[1] = *(u16 *)(object + 0x02);
    reg_d1.h[0] = *(u16 *)(object + 0x04);
    reg_d1.h[1] += *(u16 *)(object + 0x68);
    reg_d1.w += 0xF47FFC00u;
    reg_d4.w = 0;
    reg_d1.w += 0xF600FE00u;
    reg_d3.h[0] = 0xA10;
    *(u8 *)&reg_d4 = object[0x7C];
    func_001FDBD0();
}

void func_001FDD60(void) {
    u8 *object = reg_a6;

    reg_d2.w = 0x1E93;
    reg_d1.h[1] = *(u16 *)(object + 0x02);
    reg_d1.h[0] = *(u16 *)(object + 0x04);
    reg_d1.h[1] += *(u16 *)(object + 0x6A);
    reg_d1.w += 0xF4800400U;
    reg_d1.w += 0xF600FE00U;
    reg_d3.h[0] = 0x0A10;
    reg_d4.w = 0;
    *(u8 *)&reg_d4 = object[0x7C];
    func_001FDBD0();
}

void func_001FDDD0(void) {
    if (((u16 *)((void *)reg_a6))[0x26 / 2] != reg_d0.h[0]) {
        ((u16 *)((void *)reg_a6))[0x26 / 2] = (u16) reg_d0.h[0];
        ((u16 *)((void *)reg_a6))[0x28 / 2] = 0;
    }
}

s32 entity_velocity();

void func_001FDE00(void) {
    reg_d0.h[0] = ENTITY(reg_a6)[1].offset_y.h;
    switch (reg_d0.h[0]) {
    case 0:
        func_001FDED0();
        break;
    case 1:
        func_001FDFC0();
        break;
    case 2:
        func_001FE6D0();
        break;
    case 3:
        func_001FE990();
        break;
    case 4:
        func_001FEA90();
        break;
    case 5:
        func_001FEE40();
        break;
    case 6:
        func_001FEF40();
        break;
    case 7:
        func_001FEF70();
        break;
    }
    entity_velocity();
}

void func_001FDED0(void) {
    if (ENTITY(reg_a6)[1].offset_x.h == 0) {
        ENTITY(reg_a6)->move.sh = 0x1600;
        ENTITY(reg_a6)[1].hit_x_plus.sh = 0x202;
        ENTITY(reg_a6)[1].offset_x.h = 1U;
    }
    if ((ENTITY(reg_a6)[1].offset_x.h == 1) && (ENTITY(reg_a6)->y.sh >= 0x2000)) {
        ENTITY(reg_a6)[1].offset_x.h = 2U;
    }
    if (ENTITY(reg_a6)[1].offset_x.h == 2) {
        reg_tmp.b[0] = ENTITY(reg_a6)[1].hit_x_plus.b[1];
        ENTITY(reg_a6)[1].hit_x_plus.b[1] -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            ENTITY(reg_a6)[1].hit_x_plus.b[1] = ENTITY(reg_a6)[1].hit_x_plus.b[0];
            ENTITY(reg_a6)->move.b.speed -= 1;
            if (ENTITY(reg_a6)->move.b.speed == 0) {
                *(s8 *)(reg_a5 + 0x16) = 1;
                ENTITY(reg_a6)->flags.h = 0xA001;
                reg_d0.w = 1;
                func_001FDDD0();
            }
        }
    }
}

extern u8 D_0028DA58;

void func_001FDFC0() {
    if (ENTITY(reg_a6)[1].offset_x.h == 0) {
        ENTITY(reg_a6)[1].offset_x.h = 1U;
        ENTITY(reg_a6)->move.sb.speed = 4;
        ENTITY(reg_a6)[1].draw.h = 0U;
        ENTITY(reg_a6)[1].hit_y_plus.h = 0x12CU;
        func_001FE100();
        func_001FE2F0();
    }
    reg_a0 = &D_0028DA58;
    reg_a0 += ENTITY(reg_a6)[1].draw.h;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    func_001FF000();
    if (cond_flag == 0) {
        ENTITY(reg_a6)[1].draw.h += 4;
        ENTITY(reg_a6)[1].draw.h &= 7;
    }
    ENTITY(reg_a6)[1].hit_y_plus.h -= 1;
    if (ENTITY(reg_a6)[1].hit_y_plus.h == 0) {
        reg_d0.w = 2;
        if (*(u16 *)(reg_a5 + 0x18) != 0) {
            reg_d0.w = 4;
        }
        func_001FDDD0();
        *(u16 *)(reg_a5 + 0x18) += 1;
        *(u16 *)(reg_a5 + 0x18) &= 1;
        func_001FE0F0();
        func_001FE2E0();
    }
}

void func_001FE0F0(void) {
    ENTITY(reg_a6)[2].offset_y.sh = 0;
}

typedef struct FuncFe100Obj {
    u8 pad_00[0x46];
    s16 unk46;
    u8 pad_48[0x4];
    s16 unk4C;
} FuncFe100Obj;


void func_001FE100(void) {
    ((FuncFe100Obj *)reg_a6)->unk46 = 1;
    ((FuncFe100Obj *)reg_a6)->unk4C = 0;
}

s32 spawn_request_add();
extern u16 g_game_frame;

void func_001FE120(void) {
    u16 temp_v1;
    u16 temp_v1_2;

    if (ENTITY(reg_a6)[2].offset_y.h != 0) {
        if (ENTITY(reg_a6)[2].sprite.h == 1) {
            ENTITY(reg_a6)[2].offset_x.h = 0xA00U;
            ENTITY(reg_a6)[2].draw.h = 0xA00U;
            ENTITY(reg_a6)[2].sprite.h = 0U;
        }
        if (ENTITY(reg_a6)[2].sprite.h == 0) {
            reg_d0.h[0] = ENTITY(reg_a6)[2].offset_x.h;
            reg_d0.h[0] += ENTITY(reg_a6)[2].draw.h;
            if (reg_d0.h[0] == 0) {
                reg_d0.w = 0;
                reg_d0.h[0] &= g_game_frame;
                if (reg_d0.h[0] == 0) {
                    ENTITY(reg_a6)[2].sprite.h = 1U;
                    reg_d0.w = 0x4E;
                    spawn_request_add();
                    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d0.w += 0xFC3FEC80;
                    *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
                    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
                    *(u16 *)(reg_a0 + 0x1A) = 0xFA00;
                    reg_d0.w = 0x4E;
                    spawn_request_add();
                    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d0.w += 0xFC401380;
                    *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
                    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
                    *(s16 *)(reg_a0 + 0x1A) = 0x600;
                }
            }
        }
    }
    temp_v1 = ENTITY(reg_a6)[2].offset_x.h;
    if (temp_v1 != 0) {
        ENTITY(reg_a6)[2].offset_x.h = (u16) (temp_v1 - 0x100);
        if ((s16) ENTITY(reg_a6)[2].offset_x.h <= 0) {
            ENTITY(reg_a6)[2].offset_x.h = 0U;
        }
    }
    temp_v1_2 = ENTITY(reg_a6)[2].draw.h;
    if (temp_v1_2 != 0) {
        ENTITY(reg_a6)[2].draw.h = (u16) (temp_v1_2 - 0x100);
        if ((s16) ENTITY(reg_a6)[2].draw.h <= 0) {
            ENTITY(reg_a6)[2].draw.h = 0U;
        }
    }
}

void func_001FE2E0(void) {
    ENTITY(reg_a6)[3].offset_y.h = 0;
}


void func_001FE2F0(void) {
    ENTITY(reg_a6)[3].offset_y.sh = 1;
    ENTITY(reg_a6)[3].sprite.sh = 0;
    ENTITY(reg_a6)[3].look.sh = 0x1818;
    if (g_loop != 0) {
        ENTITY(reg_a6)[3].look.sh = 0x404;
    }
}

s32 bullet_fire_fast();
s32 rng_next_unsigned();
extern u8 g_direction64_offsets_2CC[];
extern u16 g_frame_mod16;
extern s16 g_player2[];
extern s16 g_player1[];

void func_001FE330(void) {
    u16 t1;
    u16 t2;
    if (ENTITY(reg_a6)[3].offset_y.h != 0) {
        if (ENTITY(reg_a6)[3].sprite.h == 1) {
            ENTITY(reg_a6)[3].offset_x.h = 0x800U;
            ENTITY(reg_a6)[3].sprite.h = 0U;
        }
        if (ENTITY(reg_a6)[3].sprite.h == 2) {
            ENTITY(reg_a6)[3].draw.h = 0x800U;
            ENTITY(reg_a6)[3].sprite.h = 0U;
        }
        if (ENTITY(reg_a6)[3].sprite.h == 0) {
            if (g_frame_mod16 == 0) {
                reg_d0.w = 0;
                if (g_player1[0] < 0) {
                    reg_d0.h[0] = PLAYER(g_player1)->y.h;
                }
                reg_d1.w = 0;
                if (g_player2[0] < 0) {
                    reg_d1.h[0] = PLAYER(g_player2)->y.h;
                }
                if ((s32) reg_d0.h[0] <= (s32) reg_d1.h[0]) {
                    reg_d0.h[0] = reg_d1.h[0];
                }
                reg_d1.h[0] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] -= 0x400;
                if ((s32) reg_d1.h[0] <= (s32) reg_d0.h[0]) {
                    reg_d7.h[0] = 0x24;
                    reg_d0.w = 0x10007;
                    reg_d1.h[0] = 0x2E;
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    reg_a0 = (u8 *)g_direction64_offsets_2CC;
                    reg_d5.w = 0;
                    do {
                        reg_d3.h[0] = reg_d1.h[0];
                        reg_d3.h[0] &= 0x3F;
                        reg_d3.h[0] *= 4;
                        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                        reg_d3.w += reg_d5.w;
                        bullet_fire_fast();
                        reg_d1.b[0] += 1;
                        reg_d1.h[0] &= 0x3F;
                    } while ((s16)(--reg_d7.h[0]) >= 0);
                }
            }
            reg_tmp.b[0] = ENTITY(reg_a6)[3].look.b.size;
            ENTITY(reg_a6)[3].look.b.size -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ENTITY(reg_a6)[3].look.b.size = (u8) ENTITY(reg_a6)[3].look.b.palette;
                reg_d0.h[0] = ENTITY(reg_a6)[3].offset_x.h;
                reg_d0.h[0] += ENTITY(reg_a6)[3].draw.h;
                if (reg_d0.h[0] == 0) {
                    rng_next_unsigned();
                    reg_d0.h[0] &= 1;
                    if (reg_d0.h[0] == 0) {
                        reg_d0.w = 0x50;
                        spawn_request_add();
                        reg_d0.h[1] = ENTITY(reg_a6)->y.h;
                        reg_d0.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d0.w += 0xF47FFC00;
                        *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
                        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
                        ENTITY(reg_a6)[3].sprite.h = 1;
                    } else {
                        reg_d0.w = 0x50;
                        spawn_request_add();
                        reg_d0.h[1] = ENTITY(reg_a6)->y.h;
                        reg_d0.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d0.w += 0xF4800400;
                        *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
                        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
                        ENTITY(reg_a6)[3].sprite.h = 2;
                    }
                }
            }
        }
    }
    t1 = ENTITY(reg_a6)[3].offset_x.h;
    if (t1 != 0) {
        ENTITY(reg_a6)[3].offset_x.h = (u16) (t1 - 0x80);
        if ((s16) ENTITY(reg_a6)[3].offset_x.h <= 0) {
            ENTITY(reg_a6)[3].offset_x.h = 0U;
        }
    }
    t2 = ENTITY(reg_a6)[3].draw.h;
    if (t2 != 0) {
        ENTITY(reg_a6)[3].draw.h = (u16) (t2 - 0x80);
        if ((s16) ENTITY(reg_a6)[3].draw.h <= 0) {
            ENTITY(reg_a6)[3].draw.h = 0U;
        }
    }
}

extern u8 D_00266270[];

void func_001FE6D0(void) {
    u16 temp_a0;
    u32 temp_a1;
    u32 temp_a1_2;

    if (ENTITY(reg_a6)[1].offset_x.h == 0) {
        ENTITY(reg_a6)[1].offset_x.h = 1U;
        ENTITY(reg_a6)->move.sb.speed = 0x10;
        ENTITY(reg_a6)[1].draw.b.priority = 0U;
        ENTITY(reg_a6)[1].draw.b.flip = 0U;
        ENTITY(reg_a6)[1].hit_x_plus.b[1] = 0x10U;
    }
    temp_a0 = ENTITY(reg_a6)[1].offset_x.h;
    if (temp_a0 == 1) {
        reg_d2.h[0] = 0x2800;
        reg_d3.h[0] = 0x1C00;
        func_001FF000();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->move.sb.speed = 0;
            ENTITY(reg_a6)[1].offset_x.h = 2U;
        }
    }
    if (ENTITY(reg_a6)[1].offset_x.h == 2) {
        *(u16 *)(reg_a5 + 0x1E) += 0x40;
        if ((s16) *(u16 *)(reg_a5 + 0x1E) >= 0x600) {
            *(u16 *)(reg_a5 + 0x1E) = 0x600U;
            ENTITY(reg_a6)[1].offset_x.h = 3U;
        }
    }
    if (ENTITY(reg_a6)[1].offset_x.h == 3) {
        reg_d1.w = 1;
        reg_d1.h[0] &= g_game_frame;
        if (reg_d1.h[0] == 0) {
            reg_d0.b[0] = ENTITY(reg_a6)[1].hit_x_plus.b[1];
            reg_a4 = (u8 *)D_00266270;
            reg_d0.h[0] &= 7;
            reg_d0.h[0] *= 4;
            reg_a4 += reg_d0.h[0];
            reg_d0.w = 0x52;
            spawn_request_add();
            reg_d0.h[1] = ENTITY(reg_a6)->y.h;
            reg_d0.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.w += 0x0C7FF600;
            temp_a1 = reg_d0.w;
            reg_tmp.h[1] = *(u16 *)reg_a4;
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
            reg_d0.w = temp_a1 + reg_tmp.w;
            *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
            *(u8 *)(reg_a0 + 0x1B) = (u8) ENTITY(reg_a6)[1].draw.b.priority;
            ENTITY(reg_a6)[1].draw.b.priority += 4;
            ENTITY(reg_a6)[1].draw.b.priority &= 0x3F;
            reg_d0.w = 0x52;
            spawn_request_add();
            reg_d0.h[1] = ENTITY(reg_a6)->y.h;
            reg_d0.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.w += 0x0C800A00;
            temp_a1_2 = reg_d0.w;
            reg_tmp.h[1] = *(u16 *)reg_a4;
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
            reg_d0.w = temp_a1_2 + reg_tmp.w;
            *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
            *(u8 *)(reg_a0 + 0x1B) = (u8) ENTITY(reg_a6)[1].draw.b.flip;
            ENTITY(reg_a6)[1].draw.b.flip -= 4;
            ENTITY(reg_a6)[1].draw.b.flip &= 0x3F;
            ENTITY(reg_a6)[1].hit_x_plus.b[1] -= 1;
            if (ENTITY(reg_a6)[1].hit_x_plus.b[1] == 0) {
                reg_d0.w = 3;
                func_001FDDD0();
            }
        }
    }
}

void func_001FE990(arg1)
    s32 arg1;
{
    s32 var_a1;
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    var_a1 = arg1;
    if (ENTITY(reg_a6)[1].offset_x.h == 0) {
        var_a1 = 0xF0;
        ENTITY(reg_a6)[1].offset_x.h = 1U;
        ENTITY(reg_a6)[1].hit_y_plus.h = 0xF0U;
        ENTITY(reg_a6)->move.sb.speed = 0x10;
    }
    temp_v1 = *(u16 *)(reg_a5 + 0x1E);
    if (temp_v1 != 0) {
        *(u16 *)(reg_a5 + 0x1E) = (u16) (temp_v1 - 0x40);
        if ((s16) *(u16 *)(reg_a5 + 0x1E) <= 0) {
            *(u16 *)(reg_a5 + 0x1E) = 0U;
        }
    }
    temp_a0 = ENTITY(reg_a6)[1].offset_x.h;
    if (temp_a0 == 1) {
        reg_d2.h[0] = 0x5C00;
        reg_d3.h[0] = 0x1C00;
        func_001FF000();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->move.sb.speed = 0;
            ENTITY(reg_a6)[1].offset_x.h = 2U;
        }
    }
    temp_a0_2 = ENTITY(reg_a6)[1].offset_x.h;
    if (temp_a0_2 == 2) {
        ENTITY(reg_a6)[1].hit_y_plus.h -= 1;
        if (ENTITY(reg_a6)[1].hit_y_plus.h == 0) {
            reg_d0.w = 1;
            func_001FDDD0();
        }
    }
}

void func_001FEA90(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u32 temp_a2;
    u8 temp_a1;

    if (ENTITY(reg_a6)[1].offset_x.h == 0) {
        ENTITY(reg_a6)[1].offset_x.h = 1U;
        ENTITY(reg_a6)->move.sb.speed = 8;
        ENTITY(reg_a6)[1].draw.b.priority = 0U;
    }
    temp_a0 = ENTITY(reg_a6)[1].offset_x.h;
    if (temp_a0 == 1) {
        reg_d2.h[0] = 0x3200;
        reg_d3.h[0] = 0x1C00;
        func_001FF000();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->move.sb.speed = 4;
            ENTITY(reg_a6)[1].offset_x.h = 2U;
            ENTITY(reg_a6)[1].draw.b.priority = 1U;
        }
    }
    temp_a0_2 = ENTITY(reg_a6)[1].offset_x.h;
    if (temp_a0_2 == 2) {
        reg_d2.h[0] = 0x3600;
        reg_d3.h[0] = 0x2A00;
        func_001FF000();
        if (cond_flag == 0) {
            ENTITY(reg_a6)[1].offset_x.h = 3U;
            ENTITY(reg_a6)[1].draw.b.priority = 1U;
        }
    }
    temp_a0_3 = ENTITY(reg_a6)[1].offset_x.h;
    if (temp_a0_3 == 3) {
        reg_d2.h[0] = 0x3600;
        reg_d3.h[0] = 0xE00;
        func_001FF000();
        if (cond_flag == 0) {
            reg_d0.w = 5;
            func_001FDDD0();
        }
    }
    if ((ENTITY(reg_a6)[1].draw.b.priority == 1) && ((temp_a0_4 = *(u16 *)(reg_a5 + 0x1E), (temp_a0_4 == 0x600)) || (*(u16 *)(reg_a5 + 0x1E) = (u16) (temp_a0_4 + 0x40), (((s16) *(u16 *)(reg_a5 + 0x1E) < 0x600) == 0)))) {
        *(u16 *)(reg_a5 + 0x1E) = 0x600U;
        ENTITY(reg_a6)[1].draw.b.priority = 2U;
        ENTITY(reg_a6)[1].draw.b.flip = 8U;
        ENTITY(reg_a6)[1].hit_x_plus.b[1] = 0U;
    }
    if (ENTITY(reg_a6)[1].draw.b.priority == 2) {
        reg_d1.h[0] = g_game_frame;
        reg_d1.b[0] &= 7;
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = ENTITY(reg_a6)[1].draw.b.flip;
            reg_a4 = (u8 *)D_00266270;
            reg_d0.h[0] &= 7;
            reg_d0.h[0] *= 4;
            reg_a4 += reg_d0.h[0];
            reg_d0.w = 0x58;
            spawn_request_add();
            reg_d0.h[1] = ENTITY(reg_a6)->y.h;
            reg_d0.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.w += 0x0C7FF600;
            temp_a2 = reg_d0.w;
            reg_tmp.h[1] = *(u16 *)reg_a4;
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
            reg_d0.w = temp_a2 + reg_tmp.w;
            *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
            reg_d1.w = 4;
            temp_a1 = ENTITY(reg_a6)[1].hit_x_plus.b[1];
            reg_d1.b[0] -= temp_a1;
            reg_d1.b[0] &= 0x3F;
            *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d1.b[0];
            ENTITY(reg_a6)[1].hit_x_plus.b[1] += 1;
            ENTITY(reg_a6)[1].hit_x_plus.b[1] &= 7;
            reg_d0.w = 0x58;
            spawn_request_add();
            reg_d0.h[1] = ENTITY(reg_a6)->y.h;
            reg_d0.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.w += 0x0C800A00;
            reg_tmp.h[1] = *(u16 *)reg_a4;
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
            reg_d0.w += reg_tmp.w;
            *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
            reg_d1.w = 4;
            reg_d1.b[0] -= ENTITY(reg_a6)[1].hit_x_plus.b[1];
            reg_d1.b[0] &= 0x3F;
            *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d1.b[0];
            ENTITY(reg_a6)[1].hit_x_plus.b[1] += 1;
            ENTITY(reg_a6)[1].hit_x_plus.b[1] &= 7;
            ENTITY(reg_a6)[1].draw.b.flip -= 1;
            if (ENTITY(reg_a6)[1].draw.b.flip == 0) {
                ENTITY(reg_a6)[1].draw.b.priority = 0U;
            }
        }
    }
}

void func_001FEE40(arg1)
    s32 arg1;
{
    s32 var_a1;
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    var_a1 = arg1;
    if (ENTITY(reg_a6)[1].offset_x.h == 0) {
        var_a1 = 0x40;
        ENTITY(reg_a6)[1].offset_x.h = 1U;
        ENTITY(reg_a6)[1].hit_y_plus.h = 0x40U;
        ENTITY(reg_a6)->move.sb.speed = 0x10;
    }
    temp_v1 = *(u16 *)(reg_a5 + 0x1E);
    if (temp_v1 != 0) {
        *(u16 *)(reg_a5 + 0x1E) = (u16) (temp_v1 - 0x40);
        if ((s16) *(u16 *)(reg_a5 + 0x1E) <= 0) {
            *(u16 *)(reg_a5 + 0x1E) = 0U;
        }
    }
    temp_a0 = ENTITY(reg_a6)[1].offset_x.h;
    if (temp_a0 == 1) {
        reg_d2.h[0] = 0x5C00;
        reg_d3.h[0] = 0x1C00;
        func_001FF000();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->move.sb.speed = 0;
            ENTITY(reg_a6)[1].offset_x.h = 2U;
        }
    }
    temp_a0_2 = ENTITY(reg_a6)[1].offset_x.h;
    if (temp_a0_2 == 2) {
        ENTITY(reg_a6)[1].hit_y_plus.h -= 1;
        if (ENTITY(reg_a6)[1].hit_y_plus.h == 0) {
            reg_d0.w = 1;
            func_001FDDD0();
        }
    }
}

void func_001FEF40(void) {
    if (ENTITY(reg_a6)[1].offset_x.h == 0) {
        ENTITY(reg_a6)[1].offset_x.h = 1;
        ENTITY(reg_a6)->move.h = 0x420;
    }
}

void func_001FEF70(void) {
    u8 temp_v1;

    if (ENTITY(reg_a6)[1].offset_x.h == 0) {
        ENTITY(reg_a6)[1].offset_x.h = 1U;
        ENTITY(reg_a6)->move.sb.dir = 0;
    }
    temp_v1 = ENTITY(reg_a6)->move.b.speed;
    if (temp_v1 != 8) {
        ENTITY(reg_a6)->move.b.speed = (u8) (temp_v1 + 1);
        if ((s8) ENTITY(reg_a6)->move.b.speed >= 8) {
            ENTITY(reg_a6)->move.b.speed = 8U;
        }
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x67FF) {
        ENTITY(reg_a6)[4].misc.sb.user = 1;
    }
}

s32 func_002021D0();                            /* extern */
s32 func_002024F0();                            /* extern */
s32 entity_distance_to();                            /* extern */

void func_001FF000(void) {
    reg_d0.h[0] = g_side_scroll_x[0];
    reg_d3.h[0] -= reg_d0.h[0];
    entity_distance_to();
    if (((s16) reg_d0.h[0] >= 0x200) || (ENTITY(reg_a6)->move.sb.speed = 8, (((s16) reg_d0.h[0] < 0x100) == 0)) || (ENTITY(reg_a6)->move.sb.speed = 6, (((s16) reg_d0.h[0] < 0x40) == 0))) {
        func_002021D0();
        func_002024F0();
        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

s32 explosion_spawn();
s32 explosion_burst_small();
s32 sfx_explosion_air_medium();
s32 sfx_explosion_extra_1();
s32 func_001D5040();
s32 rng_next();
s32 func_00201710();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u16 D_00266290[];
extern u16 D_002662E0[];

void func_001FF0B0(void) {
    u16 temp_a0_2;
    u16 temp_a0_3;
    u8 temp_a0;

    if (ENTITY(reg_a6)[4].misc.b.draw_layer != 0) {
        ENTITY(reg_a6)->y.h -= 0x40;
        reg_d1.h[0] = ENTITY(reg_a6)[4].look.h;
        func_00201710();
        temp_a0 = ENTITY(reg_a6)[4].offset_y.b[1];
        if (temp_a0 == 2) {
            ENTITY(reg_a6)[4].misc.sb.user = 1;
            goto block_set;
        }
        if (temp_a0 == 1) {
            ENTITY(reg_a6)[4].offset_x.b[1] -= 1;
            if (ENTITY(reg_a6)[4].offset_x.b[1] == 0) {
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_a1 = (u8 *)(D_002662E0);
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
                ENTITY(reg_a6)[4].offset_x.b[1] = 0x10U;
                ENTITY(reg_a6)[4].offset_y.b[1] = 2U;
                vibration_start_pad1(0xB4, 0x3C, 0x10);
                vibration_start_pad2(0xB4, 0x3C);
            }
        }
        if (ENTITY(reg_a6)[4].offset_y.b[1] == 0) {
            reg_tmp.b[0] = ENTITY(reg_a6)[4].offset_x.b[1];
            ENTITY(reg_a6)[4].offset_x.b[1] -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ENTITY(reg_a6)[4].offset_x.b[1] = (u8) ENTITY(reg_a6)[4].offset_x.b[0];
                sfx_explosion_air_medium();
                reg_a1 = (u8 *)(D_00266290);
                reg_a1 += ENTITY(reg_a6)[4].draw.h;
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
                ENTITY(reg_a6)[4].draw.h += 0xC;
                if (ENTITY(reg_a6)[4].draw.h == 0x48) {
                    ENTITY(reg_a6)[4].draw.h = 0U;
                    ENTITY(reg_a6)[4].sprite.h -= 1;
                    if (ENTITY(reg_a6)[4].sprite.h == 0) {
                        ENTITY(reg_a6)[4].offset_x.h = 0x1006;
                        ENTITY(reg_a6)[4].offset_y.b[1] = 1U;
                    }
                }
            }
        }
        goto block_11;
    }
block_11:
    cond_flag = 0;
    return;
block_set:
    cond_flag = 1;
}

void stage5_midboss5_small_missile_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern u8 D_00266340[];
extern u8 D_0028DA38;

void stage5_midboss5_small_missile_start() {
    u16 temp_a1;

    reg_a0 = D_00266340;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    temp_a1 = *(u16 *)(reg_a5 + 0x18);
    ENTITY(reg_a6)->x.h = temp_a1;
    reg_a0 = &D_0028DA38;
    reg_d0.h[0] = 1;
    enemy_set_task_state();
}

s32 sprite_draw_layer3();
s32 velocity_from_direction();
extern u8 D_0028E2E4;

void stage5_midboss5_small_missile(void) {
    s32 enemy_remove();
    if (D_0028E2E4 != 0) goto block_end;
    reg_d1.w = 0;
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    velocity_from_direction();
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
    *(u16 *)(reg_a5 + 0x18) -= 1;
    if (*(u16 *)(reg_a5 + 0x18) != 0) goto block_disp;
    reg_d0.w = 0x4F;
    spawn_request_add();
    *(u16 *)(reg_a0 + 0x16) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 0x18) = ENTITY(reg_a6)->x.h;
    reg_d0.w = 0x4F;
    spawn_request_add();
    *(u16 *)(reg_a0 + 0x16) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 0x18) = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x16) += 0xA00;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1A);
    *(u16 *)(reg_a0 + 0x18) += reg_d0.h[0];
block_end:
    enemy_remove();
    return;
block_disp:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_d2.w = 0x1E94;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFA00FF00;
    reg_d3.h[0] = 0x608;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer3();
}

void stage5_midboss5_small_blast_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

extern u8 D_00266360[];
extern u8 D_0028DA40;

void stage5_midboss5_small_blast_start() {
    u16 temp_a1;

    reg_a0 = D_00266360;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    temp_a1 = *(u16 *)(reg_a5 + 0x18);
    ENTITY(reg_a6)->x.h = temp_a1;
    reg_a0 = &D_0028DA40;
    reg_d0.h[0] = 2;
    enemy_set_task_state();
}

s32 sprite_draw_layer5_zoom();
s32 sprite_draw_with_bullets_zoom();
s32 entity_check_bounds();
extern u8 D_00266380[];
extern u16 g_frame_mod4;

void stage5_midboss5_small_blast(void) {
    s32 enemy_remove();
    u8 *t1;
    u16 t2;
    u8 t3;

    if (D_0028E2E4 != 0) goto block_end1;
    {
        if (g_enemy_signal_4 == 0) {
            func_001FFA50();
            return;
        }
        entity_check_bounds();
        if (cond_flag != 0) {
            if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_1;
block_end1:
            enemy_remove();
            return;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
next_1:
        reg_d1.w = 0;
        reg_d0.w = 0;
        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        velocity_from_direction();
        ENTITY(reg_a6)->y.h += reg_d2.h[0];
        t1 = (u8 *)(reg_a6);
        (*(u16 *)((u8 *)(t1) + (4))) += reg_d3.h[0];
        if (*(u8 *)(reg_a5 + 0x16) == 0) {
            ENTITY(reg_a6)->move.b.speed -= 1;
            if (ENTITY(reg_a6)->move.b.speed == 0) {
                t1 = (u8 *)1;
                *(u8 *)(reg_a5 + 0x16) = 1U;
                ENTITY(reg_a6)->move.b.dir = 0x20U;
            }
        } else {
            ENTITY(reg_a6)->move.b.speed += 1;
            if (g_loop != 0) {
                ENTITY(reg_a6)->move.b.speed += 1;
            }
        }
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
        *(u8 *)(reg_a5 + 0x1B) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
            *(u16 *)(reg_a5 + 0x18) += 4;
            if ((s16) *(u16 *)(reg_a5 + 0x18) >= 0x2C) {
                *(u16 *)(reg_a5 + 0x18) = 0x14U;
            }
        }
        reg_a0 = reg_a6;
        enemy_hitbox_debug_draw();
        reg_a0 = (u8 *)D_00266380;
        reg_a0 += *(u16 *)(reg_a5 + 0x18);
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        t2 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = t2;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        t3 = ENTITY(reg_a6)->attr.b.palette;
        reg_d4.b[0] = t3;
        reg_d6.w = 0xF800F800;
        if (g_frame_mod4 != 0) {
            sprite_draw_with_bullets_zoom();
        } else {
            sprite_draw_layer5_zoom();
        }
    }
}

void stage5_midboss5_large_missile_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

extern u8 D_002663C0[];
extern u8 D_0028DA48;

void stage5_midboss5_large_missile_start() {
    u16 temp_a1;

    reg_a0 = D_002663C0;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    temp_a1 = *(u16 *)(reg_a5 + 0x18);
    ENTITY(reg_a6)->x.h = temp_a1;
    reg_a0 = &D_0028DA48;
    reg_d0.h[0] = 1;
    enemy_set_task_state();
}

void stage5_midboss5_large_missile(void) {
    s32 enemy_remove();
    if (D_0028E2E4 != 0) goto block_1;
    if (g_enemy_signal_4 == 0) {
        func_001FFA50();
        return;
    }
    reg_d1.w = 0;
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    velocity_from_direction();
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
    *(u16 *)(reg_a5 + 0x18) -= 1;
    if (*(u16 *)(reg_a5 + 0x18) != 0) goto next_1;
    reg_d0.w = 0x51;
    spawn_request_add();
    *(u16 *)(reg_a0 + 0x16) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 0x18) = ENTITY(reg_a6)->x.h;
block_1:
    enemy_remove();
    return;
next_1:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_d2.w = 0x1E93;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xF600FE00;
    reg_d3.h[0] = 0xA10;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer3();
}

s32 explosion_spawn();                            /* extern */

void func_001FFA50(void) {
    s32 enemy_remove(u16);
    u16 temp_a0;

    reg_d0.h[0] = 4;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 4) = temp_a0;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    enemy_remove(temp_a0);
}

void stage5_midboss5_large_blast_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern u8 D_002663E0[];
extern u8 D_0028DA50;

void stage5_midboss5_large_blast_start() {
    u16 temp_a1;

    reg_a0 = D_002663E0;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    temp_a1 = *(u16 *)(reg_a5 + 0x18);
    ENTITY(reg_a6)->x.h = temp_a1;
    reg_a0 = &D_0028DA50;
    reg_d0.h[0] = 2;
    enemy_set_task_state();
}

extern u8 D_00266400[];

void stage5_midboss5_large_blast(void) {
    s32 enemy_remove();
    u8 *t1;
    u16 t2;
    u8 t3;
    u8 t4;
    u8 t5;

    if (D_0028E2E4 != 0) goto block_end1;
    {
        entity_check_bounds();
        if (cond_flag != 0) {
            if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_1;
block_end1:
            enemy_remove();
            return;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
next_1:
        reg_d1.w = 0;
        reg_d0.w = 0;
        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        velocity_from_direction();
        ENTITY(reg_a6)->y.h += reg_d2.h[0];
        t1 = (u8 *)(reg_a6);
        (*(u16 *)((u8 *)(t1) + (4))) += reg_d3.h[0];
        if (*(u8 *)(reg_a5 + 0x16) == 0) {
            ENTITY(reg_a6)->move.b.speed -= 1;
            if (ENTITY(reg_a6)->move.b.speed == 0) {
                t1 = (u8 *)0x20;
                *(u8 *)(reg_a5 + 0x16) = 1U;
                ENTITY(reg_a6)->move.b.dir = 0x20U;
                ENTITY(reg_a6)->flags.h = 0x8001;
            }
        } else if (g_loop == 0) {
            t1 = (u8 *)(reg_a6 + 0x1B);
            t5 = ENTITY(reg_a6)->move.b.speed;
            if (t5 != 0x1C) {
                ENTITY(reg_a6)->move.b.speed = (u8) (t5 + 1);
            }
        } else {
            t4 = ENTITY(reg_a6)->move.b.speed;
            if ((s32) t4 < 0x3C) {
                ENTITY(reg_a6)->move.b.speed = (u8) (t4 + 4);
            }
        }
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
        *(u8 *)(reg_a5 + 0x1B) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
            *(u16 *)(reg_a5 + 0x18) += 4;
            if ((s32) *(u16 *)(reg_a5 + 0x18) >= 0x38) {
                *(u16 *)(reg_a5 + 0x18) = 0x28U;
            }
        }
        reg_a0 = reg_a6;
        enemy_hitbox_debug_draw();
        reg_a0 = (u8 *)D_00266400;
        reg_a0 += *(u16 *)(reg_a5 + 0x18);
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        t2 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = t2;
        reg_d1.w += 0xF600FA00;
        reg_d3.h[0] = 0xA30;
        reg_d4.w = 0;
        t3 = ENTITY(reg_a6)->attr.b.palette;
        reg_d4.b[0] = t3;
        reg_d6.w = 0xF800F800;
        if (g_frame_mod4 != 0) {
            sprite_draw_with_bullets_zoom();
        } else {
            sprite_draw_layer5_zoom();
        }
    }
}

void stage5_midboss5_drone_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern u8 D_00266440[];
extern u8 D_00266460[];

void stage5_midboss5_drone_start() {
    u8 temp_a1;

    reg_a0 = D_00266460;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    ENTITY(reg_a6)->x.h = (u16) *(u16 *)(reg_a5 + 0x18);
    temp_a1 = *(u8 *)(reg_a5 + 0x1B);
    ENTITY(reg_a6)->move.b.dir = temp_a1;
    reg_a0 = D_00266440;
    reg_d0.h[0] = 8;
    enemy_set_task_state();
}

s32 sfx_explosion_ground_medium();
s32 func_00202490();
s32 direction_turn_toward();

void stage5_midboss5_drone(void) {
    s32 enemy_remove();
    u8 t;
    u8 c;

    entity_velocity();
    *(u16 *)(reg_a5 + 0x1C) -= 1;
    if (*(u16 *)(reg_a5 + 0x1C) == 0) goto block_1;
    if (g_enemy_signal_3 == 0) goto block_1;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto next_1;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    reg_d0.b[0] ^= 0xC;
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    if (ENTITY(reg_a6)->hp.sh >= 0) goto next_2;
block_1:
    reg_d0.h[0] = 0x14;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    sfx_explosion_ground_medium();
    enemy_remove();
    return;
next_1:
    ENTITY(reg_a6)->attr.b.palette = 0x13;
next_2:
    t = *(u8 *)(reg_a5 + 0x18);
    if (!(t & 8)) goto next_7;
    if (t & 0x80) goto next_6;
    if (!(0 > ENTITY(reg_a6)->x.sh)) goto next_3;
    ENTITY(reg_a6)->move.b.dir += 0x20;
    ENTITY(reg_a6)->move.b.dir &= 0x3F;
    *(u8 *)(reg_a5 + 0x18) |= 0x80;
next_3:
    if (ENTITY(reg_a6)->x.sh <= 0x3800) goto next_4;
    ENTITY(reg_a6)->move.b.dir += 0x20;
    ENTITY(reg_a6)->move.b.dir &= 0x3F;
    *(u8 *)(reg_a5 + 0x18) |= 0x80;
next_4:
    if (!(ENTITY(reg_a6)->y.sh < 0x3200)) goto next_6;
    ENTITY(reg_a6)->move.b.dir += 0x20;
    ENTITY(reg_a6)->move.b.dir &= 0x3F;
    *(u8 *)(reg_a5 + 0x18) |= 0x80;
next_6:
    ENTITY(reg_a6)->move.b.speed -= 1;
    if (ENTITY(reg_a6)->move.b.speed != 8) goto next_7;
    *(u8 *)(reg_a5 + 0x18) = 4;
    *(s8 *)(reg_a5 + 0x16) = 0;
next_7:
    if (!(*(u8 *)(reg_a5 + 0x18) & 1)) goto next_8;
    *(s8 *)(reg_a5 + 0x16) = 1;
    reg_d0.h[0] = g_game_frame;
    reg_d0.h[0] &= 1;
    if (reg_d0.h[0] != 0) goto next_8;
    *(u16 *)(reg_a5 + 0x1A) += 4;
    if ((s16) *(u16 *)(reg_a5 + 0x1A) < 0xC) goto next_8;
    *(u8 *)(reg_a5 + 0x18) &= 0xFE;
    *(u8 *)(reg_a5 + 0x18) |= 2;
    *(u16 *)(reg_a5 + 0x1A) = 0;
    *(u16 *)(reg_a5 + 0x1E) = 8;
next_8:
    if (!(*(u8 *)(reg_a5 + 0x18) & 2)) goto next_11;
    *(s8 *)(reg_a5 + 0x16) = 1;
    if (*(u16 *)(reg_a5 + 0x1E) == 0) goto next_10;
    reg_d0.h[0] = g_game_frame;
    reg_d0.h[0] &= 1;
    if (reg_d0.h[0] != 0) goto next_11;
    *(u16 *)(reg_a5 + 0x1E) -= 1;
    if (*(u16 *)(reg_a5 + 0x1A) != 8) goto next_9;
    *(u16 *)(reg_a5 + 0x1A) = 0;
next_9:
    *(u16 *)(reg_a5 + 0x1A) += 4;
    goto next_11;
next_10:
    *(u8 *)(reg_a5 + 0x18) &= 0xFD;
    *(u16 *)(reg_a5 + 0x1A) = 0;
    *(s8 *)(reg_a5 + 0x16) = 0;
next_11:
    if (!(*(u8 *)(reg_a5 + 0x18) & 4)) goto next_14;
    reg_d6.w = 0;
    reg_d7.b[0] = ENTITY(reg_a6)->move.b.dir;
    func_00202490();
    if (cond_flag != 0) goto next_12;
    reg_d6.w = 1;
    reg_d7.b[0] -= reg_d1.b[0];
    if (reg_d7.b[0] == 0) goto next_12;
    goto next_14;
next_12:
    if (reg_d6.b[0] != 0) goto next_13;
    *(u8 *)(reg_a5 + 0x21) = 1;
next_13:
    *(u8 *)(reg_a5 + 0x18) = 0x10;
    *(u16 *)(reg_a5 + 0x22) = 4;
    *(u8 *)(reg_a5 + 0x25) = 0x10;
next_14:
    if (!(*(u8 *)(reg_a5 + 0x18) & 0x10)) goto next_17;
    c = *(u8 *)(reg_a5 + 0x25);
    if (c == 0) goto next_15;
    *(u8 *)(reg_a5 + 0x25) = c - 1;
    goto next_17;
next_15:
    if (*(u16 *)(reg_a5 + 0x22) == 0) goto next_16;
    if (*(u8 *)(reg_a5 + 0x21) != 0) goto block_2;
    reg_d0.h[0] = g_game_frame;
    reg_d0.b[0] &= 7;
    if (reg_d0.b[0] != 0) goto next_17;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d0.w = 0x80007;
    reg_d3.w = 0;
    reg_d1.b[0] += 1;
    bullet_fire_fast();
    reg_d1.b[0] -= 2;
    bullet_fire_fast();
    reg_d1.b[0] += 0x20;
    reg_d1.b[0] &= 0x3F;
    reg_d0.w = 0x30;
    velocity_from_direction();
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
block_2:
    *(u16 *)(reg_a5 + 0x22) -= 1;
    goto next_17;
next_16:
    *(u8 *)(reg_a5 + 0x18) = 0x20;
    rng_next();
    *(u8 *)(reg_a5 + 0x27) = ENTITY(reg_a6)->move.b.dir;
    *(u8 *)(reg_a5 + 0x27) += reg_d0.b[0];
    *(u8 *)(reg_a5 + 0x27) &= 0x3F;
    *(u8 *)(reg_a5 + 0x25) = 0x10;
    *(u8 *)(reg_a5 + 0x21) = 0;
next_17:
    if (!(*(u8 *)(reg_a5 + 0x18) & 0x20)) goto next_19;
    c = *(u8 *)(reg_a5 + 0x25);
    if (c == 0) goto next_18;
    *(u8 *)(reg_a5 + 0x25) = c - 1;
    goto next_19;
next_18:
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x27);
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    reg_d1.b[0] -= *(u8 *)(reg_a5 + 0x27);
    if (reg_d1.b[0] != 0) goto next_19;
    *(u8 *)(reg_a5 + 0x18) = 0x40;
    *(u8 *)(reg_a5 + 0x25) = 0x10;
next_19:
    if (!(*(u8 *)(reg_a5 + 0x18) & 0x40)) goto next_20;
    *(u8 *)(reg_a5 + 0x25) -= 1;
    if (*(u8 *)(reg_a5 + 0x25) != 0) goto next_20;
    *(u8 *)(reg_a5 + 0x18) = 9;
    ENTITY(reg_a6)->move.b.speed = 0x20;
    rng_next_unsigned();
    reg_d0.b[0] &= 7;
    ENTITY(reg_a6)->move.b.speed += reg_d0.b[0];
next_20:
    func_00200420();
    func_002004E0();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

s32 sprite_draw_layer5();
extern u8 D_00266480[];

void func_00200420(void) {
    u16 temp_a0;

    if (*(u8 *)(reg_a5 + 0x16) == 0) {
        reg_a0 = (u8 *)D_00266480;
        reg_d0.w = 0xE;
        reg_d0.b[0] &= ENTITY(reg_a6)->move.b.dir;
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a0 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a0;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
        sprite_draw_layer5();
    }
}

extern u8 D_002664A0[];

void func_002004E0(void) {
    u16 temp_a0;

    if (*(u8 *)(reg_a5 + 0x16) != 0) {
        reg_d1.w = 0;
        reg_a0 = (u8 *)D_002664A0;
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] *= 8;
        reg_a0 += reg_d1.h[0];
        reg_a1 = reg_a0;
        reg_a0 += *(u16 *)(reg_a5 + 0x1A);
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a0 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a0;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
        reg_tmp.h[1] = *(u16 *)(reg_a1 + 0xC);
        reg_tmp.h[0] = *(u16 *)(reg_a1 + 0xE);
        reg_d4.w += reg_tmp.w;
        sprite_draw_layer5();
    }
}

void stage5_midboss5_spin_drone_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 func_00202180();
extern u8 D_002666A0[];
extern u8 D_002666B0[];

void stage5_midboss5_spin_drone_start() {
    u8 temp_a1;

    reg_a0 = D_002666B0;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    ENTITY(reg_a6)->x.h = (u16) *(u16 *)(reg_a5 + 0x18);
    temp_a1 = *(u8 *)(reg_a5 + 0x1B);
    ENTITY(reg_a6)->move.b.dir = temp_a1;
    reg_a0 = D_002666A0;
    reg_d0.h[0] = 7;
    enemy_set_task_state();
    reg_d1.w = 0;
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    velocity_from_direction();
    *(u16 *)(reg_a5 + 0x1E) = (u16) reg_d2.h[0];
    *(u16 *)(reg_a5 + 0x20) = (u16) reg_d3.h[0];
    *(u8 *)(reg_a5 + 0x1D) = 0x20U;
    func_00202180();
    if (cond_flag == 0) {
        *(u8 *)(reg_a5 + 0x1D) = (u8) reg_d1.b[0];
    }
}

void bullet_fire_fast_in_arc(void);

void stage5_midboss5_spin_drone(void) {
    s32 enemy_remove();
    if (ENTITY(reg_a6)->y.sh > -0x400) goto next_1;
    enemy_remove();
    return;
next_1:
    reg_d0.h[1] = *(u16 *)(reg_a5 + 0x1E);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp.w += reg_d0.w;
    ENTITY(reg_a6)->y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = reg_tmp.h[0];
    *(u16 *)(reg_a5 + 0x1E) -= 2;
    if (g_enemy_signal_3 == 0) goto block_1;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto next_2;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    reg_d0.b[0] ^= 0xC;
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    if (ENTITY(reg_a6)->hp.sh >= 0) goto next_3;
block_1:
    reg_d0.h[0] = 0x14;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    sfx_explosion_ground_medium();
    enemy_remove();
    return;
next_2:
    ENTITY(reg_a6)->attr.b.palette = 0x13;
next_3:
    reg_d0.w = 3;
    reg_d0.h[0] &= g_game_frame;
    if (reg_d0.h[0] != 0) goto next_4;
    *(u16 *)(reg_a5 + 0x1A) += 4;
    *(u16 *)(reg_a5 + 0x1A) &= 0x1F;
next_4:
    if (*(u16 *)(reg_a5 + 0x24) == 0) goto next_5;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
    *(u8 *)(reg_a5 + 0x23) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_5;
    *(u8 *)(reg_a5 + 0x23) = *(u8 *)(reg_a5 + 0x22);
    *(u8 *)(reg_a5 + 0x1D) += 3;
    *(u8 *)(reg_a5 + 0x1D) &= 0x3F;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x1D);
    reg_d0.w = 0xFFFC0007;
    reg_d4.w = 0;
    reg_d3.w = 0;
    bullet_fire_fast_in_arc();
    reg_d1.b[0] += 0x15;
    reg_d1.b[0] &= 0x3F;
    bullet_fire_fast_in_arc();
    reg_d1.b[0] += 0x15;
    reg_d1.b[0] &= 0x3F;
    bullet_fire_fast_in_arc();
    *(u16 *)(reg_a5 + 0x24) -= 1;
next_5:
    reg_a0 = (u8 *)D_00266480;
    reg_a0 += *(u16 *)(reg_a5 + 0x1A);
    reg_d2.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFA00FC00;
    reg_d3.h[0] = 0x620;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer5();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

/* Fires only in directions 0x0D to 0x33 of the 0x40 that make a full turn. */
void bullet_fire_fast_in_arc(void)
{
    u32 savedD0;
    s8 direction;

    savedD0 = reg_d0.w;
    direction = (s8)reg_d1.b[0];
    if (direction < 0x34 && direction > 0xC) {
        bullet_fire_fast();
    }
    reg_d0.w = savedD0;
}
