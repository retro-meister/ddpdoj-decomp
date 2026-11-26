#include "common.h"
#include "entity.h"

void func_001FABA0(void);
void func_001FAC60(void);
void func_001FACB0(void);
void func_001FAD00(void);
void func_001FAD30(void);
void func_001FADE0(void);
void func_001FB010();
void func_001FB1F0(void);
void func_001FB630(void);
void func_001FB650(void);
void func_001FB6C0(void);
void func_001FB6E0(void);
void func_001FB700(void);
void func_001FB770();
void func_001FBD90();
void func_001FBE90(void);
void func_001FC670(void);
void func_001FC710(void);
void func_001FC7F0(void);

void stage5_midboss4_arrival_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 enemy_set_task_state();
s32 enemy_init_entities();
s32 sprite_palette_load();
extern u8 D_002603F0[];
extern u8 D_00260430[];
extern u8 D_00260530[];
extern u8 D_00265C20[];
extern u8 D_00265C30[];
extern u16 g_side_scroll_x[];

void stage5_midboss4_arrival_start(void) {

    reg_a0 = D_00265C30;
    enemy_init_entities();
    reg_a0 = D_00265C20;
    reg_d0.h[0] = 4;
    enemy_set_task_state();
    reg_tmp.w = 0x30001C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
    reg_d0.h[0] = g_side_scroll_x[0];
    ENTITY(reg_a6)->x.h -= reg_d0.h[0];
    reg_d0.h[0] = 0x12;
    reg_a0 = D_002603F0;
    sprite_palette_load();
    reg_d0.h[0] = 0x13;
    reg_a0 = D_00260430;
    sprite_palette_load();
    reg_d0.h[0] = 0x14;
    reg_a0 = D_00260530;
    sprite_palette_load();
}

s32 enemy_request_start();
s32 enemy_remove();
s32 sprite_draw_layer1();
s32 entity_follow_scroll();
s32 entity_velocity();
extern u8 D_00265C50[];
extern u16 g_enemies_stopped;

void stage5_midboss4_arrival(void) {
    u16 temp_a1;
    u16 temp_v1;

    if (g_enemies_stopped == 0) {
        if (*(u8 *)(reg_a5 + 0x16) == 0) {
            entity_follow_scroll();
            *(u16 *)(reg_a5 + 0x1E) -= 1;
            if (*(u16 *)(reg_a5 + 0x1E) == 0) {
                *(u8 *)(reg_a5 + 0x16) = 1U;
            }
        }
        if (*(u8 *)(reg_a5 + 0x16) == 1) {
            entity_velocity();
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
            *(u8 *)(reg_a5 + 0x1D) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x1C);
                ENTITY(reg_a6)->move.b.speed -= 1;
                if (ENTITY(reg_a6)->move.b.speed == 2) {
                    *(u8 *)(reg_a5 + 0x16) = 2U;
                }
            }
        }
        if (*(u8 *)(reg_a5 + 0x16) == 2) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x19);
            *(u8 *)(reg_a5 + 0x19) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x19) = (u8) *(u8 *)(reg_a5 + 0x18);
                *(u16 *)(reg_a5 + 0x1A) += 4;
                temp_v1 = *(u16 *)(reg_a5 + 0x1A);
                if (temp_v1 == 0x40) {
                    enemy_remove();
                    return;
                }
                if (temp_v1 == 0x3C) {
                    reg_d0.w = 0x44;
                    enemy_request_start();
                    *(u16 *)(reg_a0 + 0x16) = (u16) ENTITY(reg_a6)->y.h;
                    *(u16 *)(reg_a0 + 0x18) = (u16) ENTITY(reg_a6)->x.h;
                }
                goto block_14;
            }
        }
        goto block_14;
    }
block_14:
    reg_a0 = (u8 *)D_00265C50;
    reg_a0 += *(u16 *)(reg_a5 + 0x1A);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a1 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFC000000;
    reg_d4.w = 0;
    reg_d1.w += 0xE600E600;
    reg_d3.h[0] = 0x1AD0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer1();
}

void stage5_midboss4_first(void) {
    void enemy_set_entity_count(s32 id);
    enemy_set_entity_count(5);
}

extern u8 D_00265C90[];
extern u8 D_0028DA30;
extern s16 g_enemy_signal_1_as_s16;
extern s16 D_00299768[];

void stage5_midboss4_start() {
    u16 temp_a1;

    reg_a0 = D_00265C90;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    temp_a1 = *(u16 *)(reg_a5 + 0x18);
    ENTITY(reg_a6)->x.h = temp_a1;
    reg_a0 = &D_0028DA30;
    reg_d0.h[0] = 2;
    enemy_set_task_state();
    g_enemy_signal_1_as_s16 = 1;
    D_00299768[0] = 1;
}

s32 ground_speeds_request();
s32 func_0013B8B0();
s32 enemy_hitbox_debug_draw();
s32 score_add_no_chain();
extern u8 D_00265F60[];
extern u16 g_enemy_signal_1;
extern u16 g_scroll_line;

void stage5_midboss4_main(void) {
    u16 temp_v0;
    u16 temp_v0_2;

    if (g_enemies_stopped == 0) {
        if (ENTITY(reg_a6)[5].misc.b.user != 0) {
            g_enemy_signal_1 = 0;
            reg_d0.h[0] = 0x20;
            reg_d1.h[0] = 0x20;
            ground_speeds_request();
            enemy_remove();
            return;
        }
        if ((*(u8 *)(reg_a5 + 0x16) == 0) && (ENTITY(reg_a6)[5].misc.b.draw_layer == 0) && (g_scroll_line == 0xE0)) {
            *(u8 *)(reg_a5 + 0x16) = 1U;
            func_001FB6C0();
            reg_d0.w = 4;
            func_001FAD00();
        }
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        reg_d1.b[0] |= ENTITY(reg_a6)[1].flags.b[1];
        reg_d1.b[0] |= ENTITY(reg_a6)[2].flags.b[1];
        reg_d1.h[0] &= 0x5C;
        if (reg_d1.h[0] != 0) {
            ENTITY(reg_a6)[5].look.h = (u16) reg_d1.h[0];
            reg_d0.b[0] = 0xA3;
            ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
            ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
            ENTITY(reg_a6)[2].flags.b[1] &= reg_d0.b[0];
            score_add_no_chain();
            reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
            reg_d0.b[0] ^= 0xD;
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            reg_d0.b[0] = ENTITY(reg_a6)[1].attr.b.palette;
            reg_d0.b[0] ^= 0xD;
            ENTITY(reg_a6)[1].attr.b.palette = (u8) reg_d0.b[0];
            reg_d0.b[0] = ENTITY(reg_a6)[2].attr.b.palette;
            reg_d0.b[0] ^= 0xD;
            ENTITY(reg_a6)[2].attr.b.palette = (u8) reg_d0.b[0];
            reg_d2.w = 0x7FFF;
            reg_d2.h[0] -= ENTITY(reg_a6)->hp.h;
            reg_d3.w = 0x7FFF;
            reg_d3.h[0] -= ENTITY(reg_a6)[1].hp.h;
            if ((s32) reg_d2.w < (s32) reg_d3.w) {
                reg_d2.w = reg_d3.w;
            }
            reg_d3.w = 0x7FFF;
            reg_d3.h[0] -= ENTITY(reg_a6)[2].hp.h;
            if ((s32) reg_d2.w < (s32) reg_d3.w) {
                reg_d2.w = reg_d3.w;
            }
            reg_d0.h[0] = 0x7FFF;
            ENTITY(reg_a6)->hp.h = (u16) reg_d0.h[0];
            ENTITY(reg_a6)[1].hp.h = (u16) reg_d0.h[0];
            ENTITY(reg_a6)[2].hp.h = (u16) reg_d0.h[0];
            if (*(u8 *)(reg_a5 + 0x16) == 0) {
                reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x18);
                reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1A);
                reg_tmp.w -= reg_d2.w;
                *(u16 *)(reg_a5 + 0x18) = (u16) reg_tmp.h[1];
                *(u16 *)(reg_a5 + 0x1A) = (u16) reg_tmp.h[0];
                if ((s32) reg_tmp.w < 0) {
                    ENTITY(reg_a6)->flags.h = 0x8000;
                    ENTITY(reg_a6)[1].flags.h = 0x8000;
                    ENTITY(reg_a6)[2].flags.h = 0x8000;
                    func_001FB6C0();
                    reg_d0.w = 3;
                    func_001FAD00();
                    ENTITY(reg_a6)[5].misc.b.draw_layer = 1U;
                    reg_d0.h[0] = 0x20;
                    reg_d1.h[0] = 0x20;
                    g_enemy_signal_1 = 0;
                    ground_speeds_request();
                    reg_a0 = (u8 *)D_00265F60;
                    func_0013B8B0();
                    goto block_15;
                }
            }
        } else {
block_15:
            reg_d0.w = 0x12;
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            ENTITY(reg_a6)[1].attr.b.palette = (u8) reg_d0.b[0];
            ENTITY(reg_a6)[2].attr.b.palette = (u8) reg_d0.b[0];
        }
        func_001FBE90();
        func_001FAD30();
        reg_d0.h[1] = ENTITY(reg_a6)->y.h;
        reg_d0.h[0] = ENTITY(reg_a6)->x.h;
        ENTITY(reg_a6)[1].y.h = (u16) reg_d0.h[1];
        ENTITY(reg_a6)[1].x.h = (u16) reg_d0.h[0];
        reg_tmp.h[1] = ENTITY(reg_a6)[1].y.h;
        reg_tmp.h[0] = ENTITY(reg_a6)[1].x.h;
        reg_tmp.w += 0xF6FFF800;
        ENTITY(reg_a6)[1].y.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)[1].x.h = (u16) reg_tmp.h[0];
        reg_d1.h[0] = ENTITY(reg_a6)[1].offset_y.h;
        ENTITY(reg_a6)[1].y.h += reg_d1.h[0];
        ENTITY(reg_a6)[2].y.h = (u16) reg_d0.h[1];
        ENTITY(reg_a6)[2].x.h = (u16) reg_d0.h[0];
        reg_tmp.h[1] = ENTITY(reg_a6)[2].y.h;
        reg_tmp.h[0] = ENTITY(reg_a6)[2].x.h;
        reg_tmp.w += 0xF7000800;
        ENTITY(reg_a6)[2].y.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)[2].x.h = (u16) reg_tmp.h[0];
        reg_d1.h[0] = ENTITY(reg_a6)[2].offset_y.h;
        ENTITY(reg_a6)[2].y.h += reg_d1.h[0];
        func_001FB700();
        temp_v0 = ENTITY(reg_a6)[1].offset_y.h;
        if (temp_v0 != 0) {
            ENTITY(reg_a6)[1].offset_y.h = (u16) (temp_v0 - 0x40);
            if (0 >= (s16) ENTITY(reg_a6)[1].offset_y.h) {
                ENTITY(reg_a6)[1].offset_y.h = 0U;
            }
        }
        temp_v0_2 = ENTITY(reg_a6)[2].offset_y.h;
        if (temp_v0_2 != 0) {
            ENTITY(reg_a6)[2].offset_y.h = (u16) (temp_v0_2 - 0x40);
            if (0 >= (s16) ENTITY(reg_a6)[2].offset_y.h) {
                ENTITY(reg_a6)[2].offset_y.h = 0U;
            }
        }
        goto block_22;
    }
block_22:
    func_001FABA0();
    func_001FAC60();
    func_001FACB0();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x20;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x40;
    enemy_hitbox_debug_draw();
}

void func_001FABA0(void) {
    s32 sprite_draw_layer4();
    u16 temp_a0;
    u16 temp_a1;

    reg_d2.w = 0x1E7F;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a1 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xF2000000;
    reg_d4.w = 0;
    reg_d1.w += 0xF000E600;
    reg_d3.h[0] = 0x10D0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer4();
    reg_d2.w = 0x1E7C;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xEA00E600;
    reg_d3.h[0] = 0x16D0;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer4();
}

void func_001FAC60(void)
{
    extern void sprite_draw_layer4(void);
    u8 *object = reg_a6;

    reg_d2.w = 0x1E7D;
    reg_d1.h[1] = *(u16 *)(object + 0x22);
    reg_d1.h[0] = *(u16 *)(object + 0x24);
    reg_d1.w += 0xF600F800U;
    reg_d3.h[0] = 0xA40;
    reg_d4.w = 0;
    *(u8 *)&reg_d4 = object[0x3C];
    sprite_draw_layer4();
}

void func_001FACB0(void)
{
    extern void sprite_draw_layer4(void);
    u8 *object = reg_a6;

    reg_d2.w = 0x1E7E;
    reg_d1.h[1] = *(u16 *)(object + 0x42);
    reg_d1.h[0] = *(u16 *)(object + 0x44);
    reg_d4.w = 0;
    reg_d1.w += 0xF600F800U;
    reg_d3.h[0] = 0xA40;
    *(u8 *)&reg_d4 = object[0x5C];
    sprite_draw_layer4();
}

struct Unk0028E450 {
    u8 pad_00[0x66];
    u16 unk66;
    u16 unk68;
};

extern struct Unk0028E450 *reg_a6_as_Unk0028E450_p;

void func_001FAD00(void) {
    if (reg_a6_as_Unk0028E450_p->unk66 != reg_d0.h[0]) {
        reg_a6_as_Unk0028E450_p->unk66 = (u16) reg_d0.h[0];
        reg_a6_as_Unk0028E450_p->unk68 = 0;
    }
}

s32 func_00201F20();                            /* extern */

void func_001FAD30(void) {
    reg_d0.h[0] = ENTITY(reg_a6)[3].offset_y.h;
    switch (reg_d0.h[0]) {                          /* irregular */
    case 0:
        func_001FADE0();
        break;
    case 1:
        func_001FB010();
        break;
    case 2:
        func_001FB1F0();
        break;
    case 3:
        func_001FB630();
        break;
    case 4:
        func_001FB650();
        break;
    }
    func_00201F20();
}

s32 rng_next_unsigned();
s32 direction256_between();
s32 distance_between();
extern u8 D_00265D40[];
extern u16 D_00265D70[];

void func_001FADE0(void) {
    if (ENTITY(reg_a6)[3].offset_x.h == 0) {
        rng_next_unsigned();
        reg_d0.h[0] &= 7;
        reg_d0.h[0] *= 4;
        ENTITY(reg_a6)[3].draw.h = (u16) reg_d0.h[0];
        ENTITY(reg_a6)[3].offset_x.h = 1U;
    }
    reg_a0 = (u8 *)D_00265D40;
    reg_a0 += ENTITY(reg_a6)[3].draw.h;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] -= g_side_scroll_x[0];
    direction256_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_a0 = (u8 *)D_00265D40;
    reg_a0 += ENTITY(reg_a6)[3].draw.h;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] -= g_side_scroll_x[0];
    distance_between();
    if ((s16) reg_d0.h[0] < 0x81) {
        ENTITY(reg_a6)[3].draw.h += 4;
        if ((s16) ENTITY(reg_a6)[3].draw.h >= 0x24) {
            ENTITY(reg_a6)[3].draw.h = 0U;
        }
    }
    ENTITY(reg_a6)[3].hit_y_minus.b[1] = 5U;
    reg_a4 = (u8 *)(D_00265D70);
loop_6:
    reg_d1.h[0] = *(u16 *)reg_a4;
    reg_a4 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d2.h[0] = *(u16 *)reg_a4;
        reg_a4 += 2;
        if ((s16) reg_d1.h[0] >= (s16) reg_d0.h[0]) {
            ENTITY(reg_a6)[3].hit_y_minus.b[1] = (u8) reg_d2.b[0];
        } else {
            goto loop_6;
        }
    }
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d2.b[0] = ENTITY(reg_a6)[3].hit_y_minus.b[1];
    if (reg_d1.b[0] != reg_d2.b[0]) {
        if ((s8)(reg_d1.b[0]) >= (s8)(reg_d2.b[0])) {
            ENTITY(reg_a6)->move.b.speed -= 1;
        } else {
            ENTITY(reg_a6)->move.b.speed += 1;
        }
    }
}

s32 target_player_get();
extern u16 D_00265DE0[];
extern u16 *reg_a4_as_u16_p;

void func_001FB010(arg0)
    u16 arg0;
{
    u16 var_a0;
    u32 temp_s0;
    u32 temp_s1;

    var_a0 = arg0;
    if (ENTITY(reg_a6)[3].offset_x.h == 0) {
        ENTITY(reg_a6)[3].offset_x.h = 1U;
    }
    if (ENTITY(reg_a6)[3].offset_x.h == 1) {
        target_player_get();
        if (cond_flag == 0) {
            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
            var_a0 = *(u16 *)(reg_a0 + 4);
            reg_d2.h[0] += 0x1E00;
            reg_d3.h[0] = var_a0;
            ENTITY(reg_a6)[3].sprite.h = (u16) reg_d2.h[0];
            ENTITY(reg_a6)[3].look.h = (u16) reg_d3.h[0];
            goto block_5;
        }
        goto block_9;
    }
block_5:
    reg_d2.h[0] = ENTITY(reg_a6)[3].sprite.h;
    temp_s0 = reg_d2.w;
    reg_d3.h[0] = ENTITY(reg_a6)[3].look.h;
    temp_s1 = reg_d3.w;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction256_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_d2.w = temp_s0;
    reg_d3.w = temp_s1;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    distance_between();
    if ((s16) reg_d0.h[0] < 0x601) {
        ENTITY(reg_a6)[3].offset_x.h = 2U;
    }
    if ((s16) reg_d0.h[0] < 0x101) {
block_9:
        reg_d0.w = 1;
        func_001FB6E0();
        ENTITY(reg_a6)[3].sprite.h = (u16) ENTITY(reg_a6)->y.h;
        ENTITY(reg_a6)[3].hit_y_plus.sh = 0x50;
        ENTITY(reg_a6)->move.b.speed = 0U;
        ENTITY(reg_a6)[3].look.h = 0U;
        if ((s16) ENTITY(reg_a6)->x.h < 0x1C01) {
            ENTITY(reg_a6)[3].look.h = 0x3800U;
        }
    }
    ENTITY(reg_a6)->move.b.speed = 0x32U;
    reg_a4_as_u16_p = D_00265DE0;
loop_12:
    reg_d1.h[0] = *reg_a4_as_u16_p;
    reg_a4_as_u16_p += 1;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d2.h[0] = *reg_a4_as_u16_p;
        reg_a4_as_u16_p += 1;
        if ((s16) reg_d1.h[0] >= (s16) reg_d0.h[0]) {
            ENTITY(reg_a6)->move.b.speed = (u8) reg_d2.b[0];
        } else {
            goto loop_12;
        }
    }
}

s32 func_00202590();
extern u16 D_00265E50[];
extern u16 g_game_frame;

void func_001FB1F0(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_5;
    u16 temp_a0_6;

    if (ENTITY(reg_a6)[3].offset_x.h == 0) {
        ENTITY(reg_a6)->move.b.speed = 0U;
        ENTITY(reg_a6)[3].hit_y_plus.h -= 1;
        if (ENTITY(reg_a6)[3].hit_y_plus.h == 0) {
            ENTITY(reg_a6)[3].draw.h = 2U;
            ENTITY(reg_a6)[3].offset_x.h = 1U;
        }
    }
    temp_a0 = ENTITY(reg_a6)[3].offset_x.h;
    if (temp_a0 == 1) {
        reg_d2.h[0] = ENTITY(reg_a6)[3].sprite.h;
        reg_d3.h[0] = ENTITY(reg_a6)[3].look.h;
        reg_d3.h[0] -= g_side_scroll_x[0];
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        direction256_between();
        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
        reg_d2.h[0] = ENTITY(reg_a6)[3].sprite.h;
        reg_d3.h[0] = ENTITY(reg_a6)[3].look.h;
        temp_a0_2 = ENTITY(reg_a6)->y.h;
        reg_d0.h[0] = temp_a0_2;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d3.h[0] -= g_side_scroll_x[0];
        distance_between();
        if ((s16) reg_d0.h[0] < 0x81) {
            ENTITY(reg_a6)[3].offset_x.h = 2U;
            ENTITY(reg_a6)[3].sprite.h += 0x100;
            if ((s16) ENTITY(reg_a6)[3].sprite.h >= 0x5A00) {
                ENTITY(reg_a6)[3].sprite.h = 0x5A00U;
            }
        }
        ENTITY(reg_a6)[3].hit_y_minus.b[1] = 0x12U;
        reg_a4 = (u8 *)(D_00265E50);
loop_8:
        reg_d1.h[0] = *(u16 *)reg_a4;
        reg_a4 += 2;
        if ((s16) reg_d1.h[0] != -1) {
            reg_d2.h[0] = *(u16 *)reg_a4;
            reg_a4 += 2;
            if ((s16) reg_d1.h[0] >= (s16) reg_d0.h[0]) {
                ENTITY(reg_a6)[3].hit_y_minus.b[1] = (u8) reg_d2.b[0];
            } else {
                goto loop_8;
            }
        }
    }
    temp_a0_3 = ENTITY(reg_a6)[3].offset_x.h;
    if (temp_a0_3 == 2) {
        reg_d2.h[0] = ENTITY(reg_a6)[3].sprite.h;
        reg_d3.h[0] = ENTITY(reg_a6)[3].look.h;
        reg_d3.h[0] -= g_side_scroll_x[0];
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        direction256_between();
        reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
        func_00202590();
        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
        reg_d2.h[0] = ENTITY(reg_a6)[3].sprite.h;
        reg_d3.h[0] = ENTITY(reg_a6)[3].look.h;
        temp_a0_4 = ENTITY(reg_a6)->y.h;
        reg_d0.h[0] = temp_a0_4;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d3.h[0] -= g_side_scroll_x[0];
        distance_between();
        ENTITY(reg_a6)[3].hit_y_minus.b[1] = 4U;
        if ((ENTITY(reg_a6)->move.b.speed == 4) && ((s16) reg_d0.h[0] < 0x1001)) {
            ENTITY(reg_a6)[3].sprite.h += 0x1C00;
            ENTITY(reg_a6)[3].offset_x.h = 1U;
            ENTITY(reg_a6)[3].draw.h -= 1;
            if (ENTITY(reg_a6)[3].draw.h == 0) {
                ENTITY(reg_a6)[3].look.h = 0x1C00U;
                ENTITY(reg_a6)[3].offset_x.h = 3U;
            } else {
                ENTITY(reg_a6)[3].look.h = 0U;
                if ((s16) ENTITY(reg_a6)->x.h < 0x1C01) {
                    ENTITY(reg_a6)[3].look.h = 0x3800U;
                }
            }
        }
    }
    temp_a0_5 = ENTITY(reg_a6)[3].offset_x.h;
    if (temp_a0_5 == 3) {
        reg_d2.h[0] = ENTITY(reg_a6)[3].sprite.h;
        reg_d3.h[0] = ENTITY(reg_a6)[3].look.h;
        reg_d3.h[0] -= g_side_scroll_x[0];
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        direction256_between();
        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
        reg_d2.h[0] = ENTITY(reg_a6)[3].sprite.h;
        reg_d3.h[0] = ENTITY(reg_a6)[3].look.h;
        temp_a0_6 = ENTITY(reg_a6)->y.h;
        reg_d0.h[0] = temp_a0_6;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d3.h[0] -= g_side_scroll_x[0];
        distance_between();
        ENTITY(reg_a6)[3].hit_y_minus.b[1] = 0xAU;
        if ((s16) reg_d0.h[0] < 0x1001) {
            func_001FB6C0();
            ENTITY(reg_a6)[3].hit_y_minus.b[1] = 2U;
            if (ENTITY(reg_a6)->move.b.speed == 2) {
                ENTITY(reg_a6)[4].misc.sb.draw_layer = 1;
                reg_d0.w = 0;
                func_001FB6E0();
            }
        }
    }
    reg_d0.h[0] = g_game_frame;
    reg_d0.h[0] &= 3;
    if (reg_d0.h[0] == 0) {
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.speed;
        reg_d2.b[0] = ENTITY(reg_a6)[3].hit_y_minus.b[1];
        if (reg_d1.b[0] != reg_d2.b[0]) {
            if ((s8)(reg_d1.b[0]) >= (s8)(reg_d2.b[0])) {
                ENTITY(reg_a6)->move.b.speed -= 1;
            } else {
                ENTITY(reg_a6)->move.b.speed += 1;
            }
        }
    }
}

void func_001FB630(void) {
    u8 *object = reg_a6;

    if (*(u16 *)(object + 0x68) == 0) {
        *(u16 *)(object + 0x1A) = 0x480;
    }
}

void func_001FB650(void) {
    if (ENTITY(reg_a6)[3].offset_x.h == 0) {
        ENTITY(reg_a6)->move.sh = 0xC40;
        if (ENTITY(reg_a6)->x.sh < 0x1C01) {
            ENTITY(reg_a6)->move.sh = 0xCC0;
        }
    }
    if (ENTITY(reg_a6)->x.sh >= 0x5400) {
        ENTITY(reg_a6)[5].misc.sb.user = 1;
    }
    if (ENTITY(reg_a6)->x.sh < -0x1BFF) {
        ENTITY(reg_a6)[5].misc.sb.user = 1;
    }
}

void func_001FB6C0(void) {
    ENTITY(reg_a6)[4].offset_y.h = 0xFFFF;
    ENTITY(reg_a6)[4].offset_x.h = 0;
}

void func_001FB6E0(void) {
    ENTITY(reg_a6)[4].offset_y.h = (u16)reg_d0.h[0];
    ENTITY(reg_a6)[4].offset_x.h = 0;
}


void func_001FB700(void) {
    extern void func_001FB770(s64, u16);
    extern void func_001FBD90(s64, u16);
    s64 temp_a0;

    reg_a4 = reg_a6 + 0x8A;
    reg_d0.h[0] = ENTITY(reg_a6)[4].offset_y.h;
    temp_a0 = (s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30;
    if (temp_a0 != -1) {
        if (!(reg_d0.h[0] & 0xFFFF)) {
            func_001FB770(temp_a0, reg_d0.h[0]);
            return;
        }
        func_001FBD90(temp_a0, reg_d0.h[0]);
    }
}

s32 bullet_fire256_2way();
s32 bullet_fire256();
s32 func_00202730();
extern u16 D_00259870[];
extern u16 D_00259970[];
extern u16 g_bullets_blocked;

void func_001FB770() {
    u16 temp_a1;

    if (ENTITY(reg_a6)[4].offset_x.h == 0) {
        reg_d0.w = 0;
        func_001FAD00();
        ENTITY(reg_a6)[4].offset_x.h = 1U;
        *(s16 *)reg_a4 = 0x124;
        *(s16 *)(reg_a4 + 2) = 0x120;
        *(u16 *)(reg_a4 + 4) = 0x80U;
        *(u16 *)(reg_a4 + 6) = 0x100U;
        if (ENTITY(reg_a6)[4].misc.b.draw_layer != 0) {
            *(u16 *)(reg_a4 + 6) = 0x140U;
            *(s16 *)reg_a4 = 0x112;
        }
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 1);
    *(u8 *)(reg_a4 + 1) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 1) = *(u8 *)reg_a4;
        if (g_bullets_blocked == 0) {
            reg_d1.h[0] = *(u16 *)(reg_a4 + 4);
            reg_tmp1.w = 0;
            reg_tmp.w = 0;
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 4);
            reg_tmp1.h[0] = 0xE;
            reg_tmp.w += reg_tmp1.w;
            *(u16 *)(reg_a4 + 4) += 0xE;
            if (reg_tmp.h[1] == 0) {
                reg_d0.w = 0xFFFF000B;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d1.b[0] -= 0x79;
                reg_d7.h[0] = 0x16;
                reg_a0 = (u8 *)(D_00259970);
                reg_d4.w = 0;
                reg_d3.w = 0;
                do {
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d3.h[0] += 2;
                    reg_d3.h[0] &= 0xFC;
                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    bullet_fire256_2way();
                    reg_d1.b[0] += 0xB;
                } while ((s16)(--reg_d7.h[0]) >= 0);
            }
        }
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = *(u8 *)(reg_a4 + 2);
        if (g_bullets_blocked == 0) {
            func_00202730();
            if (cond_flag == 0) {
                reg_d0.w = 0x30004;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                temp_a1 = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0;
                reg_d2.h[0] = temp_a1;
                reg_a0 = (u8 *)(D_00259870);
                reg_d7.b[0] = reg_d1.b[0];
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d4.w = 0;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                bullet_fire256();
                reg_d1.b[0] += 6;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                bullet_fire256();
                reg_d1.b[0] += 6;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                bullet_fire256();
                reg_d1.b[0] = reg_d7.b[0];
                reg_d1.b[0] -= 6;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                bullet_fire256();
                reg_d1.b[0] -= 6;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                bullet_fire256();
            }
        }
    }
    *(u16 *)(reg_a4 + 6) -= 1;
    if (*(u16 *)(reg_a4 + 6) == 0) {
        func_001FB6C0();
        reg_d0.w = 1;
        func_001FAD00();
    }
}

s32 spawn_request_add();

void func_001FBD90(arg1)
    u16 arg1;
{
    u16 var_a1;

    var_a1 = arg1;
    if (ENTITY(reg_a6)[4].offset_x.h == 0) {
        reg_d0.w = 2;
        func_001FAD00();
        *(s16 *)reg_a4 = 0x2828;
        rng_next_unsigned();
        reg_d0.h[0] &= 1;
        var_a1 = reg_d0.h[0];
        *(u16 *)(reg_a4 + 2) = var_a1;
        ENTITY(reg_a6)[4].offset_x.h = 1U;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 1);
    *(u8 *)(reg_a4 + 1) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 1) = *(u8 *)reg_a4;
        if (g_bullets_blocked == 0) {
            reg_d0.w = 0x53;
            spawn_request_add();
            reg_tmp.w = (u32) reg_a6;
            *(u16 *)(reg_a0 + 0x16) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_tmp.h[0];
            *(u16 *)(reg_a0 + 0x1A) = (u16) *(u16 *)(reg_a4 + 2);
            *(u16 *)(reg_a4 + 2) += 1;
            *(u16 *)(reg_a4 + 2) &= 1;
        }
    }
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
extern u16 D_00265EC0[];
extern u16 D_00265F10[];

void func_001FBE90(void) {
    u16 temp_a0_2;
    u16 temp_a0_3;
    u8 temp_a0;

    if (ENTITY(reg_a6)[5].misc.b.draw_layer != 0) {
        reg_d1.h[0] = ENTITY(reg_a6)[5].look.h;
        func_00201710();
        temp_a0 = ENTITY(reg_a6)[5].offset_y.b[1];
        if (temp_a0 == 2) {
            ENTITY(reg_a6)[5].misc.sb.user = 1;
            goto block_set;
        }
        if (temp_a0 == 1) {
            ENTITY(reg_a6)[5].offset_x.b[1] -= 1;
            if (ENTITY(reg_a6)[5].offset_x.b[1] == 0) {
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_a1 = (u8 *)(D_00265F10);
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
                ENTITY(reg_a6)[5].offset_x.b[1] = 0x10U;
                ENTITY(reg_a6)[5].offset_y.b[1] = 2U;
                vibration_start_pad1(0xB4, 0x3C, 0x10);
                vibration_start_pad2(0xB4, 0x3C);
            }
        }
        if (ENTITY(reg_a6)[5].offset_y.b[1] == 0) {
            reg_tmp.b[0] = ENTITY(reg_a6)[5].offset_x.b[1];
            ENTITY(reg_a6)[5].offset_x.b[1] -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ENTITY(reg_a6)[5].offset_x.b[1] = (u8) ENTITY(reg_a6)[5].offset_x.b[0];
                sfx_explosion_air_medium();
                reg_a1 = (u8 *)(D_00265EC0);
                reg_a1 += ENTITY(reg_a6)[5].draw.h;
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
                ENTITY(reg_a6)[5].draw.h += 0xC;
                if (ENTITY(reg_a6)[5].draw.h == 0x48) {
                    ENTITY(reg_a6)[5].draw.h = 0U;
                    ENTITY(reg_a6)[5].sprite.h -= 1;
                    if (ENTITY(reg_a6)[5].sprite.h == 0) {
                        ENTITY(reg_a6)[5].offset_x.h = 0x1006;
                        ENTITY(reg_a6)[5].offset_y.b[1] = 1U;
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

void stage5_midboss4_wave_beam_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern u16 D_00265F70[];
extern u16 D_00265F80[];

void stage5_midboss4_wave_beam_start(void) {
    reg_a0 = (u8 *)(D_00265F80);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_00265F70);
    reg_d0.h[0] = 7;
    reg_a1 = (u8 *)(reg_a5 + 0x1C);
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    if (*(u16 *)(reg_a5 + 0x1A) != 0) {
        ENTITY(reg_a6)->attr.h |= 0x40;
    }
}

s32 sfx_shockwave();
s32 func_001FC8E0();
extern u8 D_00266160[];
extern u8 D_0028E2E4;

void stage5_midboss4_wave_beam(void) {
    if (D_0028E2E4 != 0) return;
    ENTITY(reg_a6)->hp.sh = 0x7FFF;
    if (g_enemy_signal_1 == 0) goto block_end1;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[1] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a0 + 4);
    if (*(u16 *)(reg_a5 + 0x1A) != 0) {
        reg_d0.w += 0xF1FFF880;
    } else {
        reg_d0.w += 0xF2000780;
    }
    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
    if (!(*(u8 *)(reg_a5 + 0x1D) & 1)) goto skip_1;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
    *(u8 *)(reg_a5 + 0x21) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto skip_1;
    *(u8 *)(reg_a5 + 0x21) = *(u8 *)(reg_a5 + 0x20);
    *(u16 *)(reg_a5 + 0x1E) += 4;
    if ((s16) *(u16 *)(reg_a5 + 0x1E) < 0x60) goto skip_1;
    *(u16 *)(reg_a5 + 0x1E) = 0;
    *(u8 *)(reg_a5 + 0x1D) &= 0xFE;
    *(u8 *)(reg_a5 + 0x1D) |= 0xE;
    func_001FC8E0();
    sfx_shockwave();
    ENTITY(reg_a6)->flags.h = 0x8001;
skip_1:
    if (!(*(u8 *)(reg_a5 + 0x1D) & 2)) goto skip_2;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
    *(u8 *)(reg_a5 + 0x25) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto skip_2;
    *(u8 *)(reg_a5 + 0x25) = *(u8 *)(reg_a5 + 0x24);
    *(u16 *)(reg_a5 + 0x22) += 0x10;
    if ((s16) *(u16 *)(reg_a5 + 0x22) < 0x90) goto skip_2;
    *(u16 *)(reg_a5 + 0x22) = 0;
    *(u8 *)(reg_a5 + 0x1D) &= 0xFD;
skip_2:
    if (!(*(u8 *)(reg_a5 + 0x1D) & 4)) goto skip_4;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x29);
    *(u8 *)(reg_a5 + 0x29) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto skip_3;
    *(u8 *)(reg_a5 + 0x29) = *(u8 *)(reg_a5 + 0x28);
    *(u16 *)(reg_a5 + 0x26) += 0x10;
    if ((s16) *(u16 *)(reg_a5 + 0x26) < 0xD0) goto skip_3;
    *(u16 *)(reg_a5 + 0x26) = 0;
block_end1:
    enemy_remove();
    return;
skip_3:
    reg_a0 = (u8 *)D_00266160;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x26);
    reg_d0.h[0] >>= 1;
    reg_a0 += reg_d0.h[0];
    ENTITY(reg_a6)->hit_y_plus.h = *(u16 *)reg_a0;
    ENTITY(reg_a6)->hit_y_minus.h = *(u16 *)(reg_a0 + 2);
    ENTITY(reg_a6)->hit_x_plus.h = *(u16 *)(reg_a0 + 4);
    ENTITY(reg_a6)->hit_x_minus.h = *(u16 *)(reg_a0 + 6);
    if (*(u16 *)(reg_a5 + 0x1A) != 0) {
        ENTITY(reg_a6)->hit_x_plus.h = *(u16 *)(reg_a0 + 6);
        ENTITY(reg_a6)->hit_x_minus.h = *(u16 *)(reg_a0 + 4);
    }
skip_4:
    if (!(*(u8 *)(reg_a5 + 0x1D) & 8)) goto skip_5;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    reg_a0 = (u8 *)reg_tmp.w;
    if (*(u16 *)(reg_a5 + 0x1A) != 0) {
        reg_a0 = reg_a0 + 0x26;
    } else {
        reg_a0 = reg_a0 + 0x46;
    }
    if (*(u16 *)reg_a0 == 0x280) goto skip_5;
    *(u16 *)reg_a0 += 0x100;
    if ((s16) *(u16 *)reg_a0 < 0x280) goto skip_5;
    *(u16 *)reg_a0 = 0x280;
    *(u8 *)(reg_a5 + 0x1D) &= 0xF7;
skip_5:
    func_001FC670();
    func_001FC710();
    func_001FC7F0();
    reg_a0 = (u8 *)reg_a6;
    enemy_hitbox_debug_draw();
}

extern u8 D_00265FA0[];

void func_001FC670(void) {
    void sprite_draw_layer5(void);
    if ((*(u8 *)(reg_a5 + 0x1D)) & 1) {
        reg_a0 = D_00265FA0;
        reg_a0 += *(u16 *)(reg_a5 + 0x1E);
        reg_d2.h[1] = *(u16 *)(reg_a0 + 0);
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.w += 0xFE00FC00;
        reg_d3.h[0] = 0x220;
        reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
        sprite_draw_layer5();
    }
}

extern u8 D_00266000[];

void func_001FC710(void) {
    s32 sprite_draw_layer5();
    u32 temp_a0;

    if (*(u8 *)(reg_a5 + 0x1D) & 2) {
        reg_a0 = (u8 *)D_00266000;
        reg_a0 += *(u16 *)(reg_a5 + 0x22);
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] += 0x180;
        if (*(u16 *)(reg_a5 + 0x1A) != 0) {
            reg_d1.h[0] += 0x7FFF + 0x7E01;
        } else {
            reg_d1.h[0] += 0x100;
        }
        temp_a0 = reg_d1.w;
        reg_tmp.h[1] = *(u16 *)(reg_a0 + 4);
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 6);
        reg_d1.w = temp_a0 + reg_tmp.w;
        reg_d3.h[0] = *(u16 *)(reg_a0 + 8);
        reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
        sprite_draw_layer5();
    }
}

extern u8 D_00266090[];

void func_001FC7F0(void) {
    s32 sprite_draw_layer5();
    u32 temp_a0;

    if (*(u8 *)(reg_a5 + 0x1D) & 4) {
        reg_a0 = (u8 *)D_00266090;
        reg_a0 += *(u16 *)(reg_a5 + 0x26);
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_tmp.h[1] = *(u16 *)(reg_a0 + 4);
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 6);
        reg_d1.w += reg_tmp.w;
        if (*(u16 *)(reg_a5 + 0x1A) != 0) {
            reg_d1.h[0] += 0x7FFF + 0x7D81;
        } else {
            reg_d1.h[0] += 0x280;
        }
        temp_a0 = reg_d1.w;
        reg_tmp.h[1] = *(u16 *)(reg_a0 + 0xC);
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 0xE);
        reg_d1.w = temp_a0 + reg_tmp.w;
        reg_d3.h[0] = *(u16 *)(reg_a0 + 8);
        reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
        sprite_draw_layer5();
    }
}
