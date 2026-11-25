#include "common.h"
#include "entity.h"

void func_001F9ED0(void);
void func_001F9F90(void);
void func_001FA0E0(void);
void func_001FA180(void);
void func_001FA320(void);

s32 enemy_set_entity_count(s32);

s32 func_001F96C0(void) {
    return enemy_set_entity_count(3);
}

s32 enemy_set_task_work();
s32 enemy_init_entities();
s32 enemy_path_start();
s32 sprite_palette_load();
s32 func_0020ED00();
extern u8 D_00261AF0[];
extern u8 D_00265AB0[];
extern u8 D_00265AD0[];
extern s16 g_enemy_signal_2_as_s16;
extern s16 D_00299768[];
extern s8 enemy_move_end_requested;

void func_001F96D0(void) {
    reg_a0 = D_00265AD0;
    enemy_init_entities();
    reg_a0 = D_00265AB0;
    reg_d0.h[0] = 0xF;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = 0x10;
        D_00299768[0] = 1;
        g_enemy_signal_2_as_s16 = 1;
        reg_a0 = D_00261AF0;
        sprite_palette_load();
        func_0020ED00();
    }
}


s32 func_001389D0();
s32 enemy_hitbox_debug_draw();
s32 enemy_remove();
s32 sfx_explosion_extra_1();
s32 sprite_draw_layer1();
s32 score_add_no_chain();
s32 score_add();
s32 func_001D5040();
s32 entity_follow_scroll();
s32 aim_at_player();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u8 D_00265B40[];
extern u8 D_00265B60[];
extern u16 D_0028E3A4_as_u16;
extern u16 D_0028E3A8_as_u16;
extern u16 g_enemy_signal_2;
extern u16 g_bullets_blocked;
extern u16 g_enemies_stopped;

void func_001F9750(void) {
    u16 temp_a0;
    u16 temp_a0_4;
    u8 temp_a0_2;
    u8 temp_a0_3;

    reg_d0.h[0] = 0x10;
    reg_a0 = D_00261AF0;
    sprite_palette_load();
    if (g_enemies_stopped == 0) {
        if (ENTITY(reg_a6)[3].misc.b.user != 0) {
            g_enemy_signal_2 = 0;
            reg_d0.h[0] = 0x20;
            reg_d1.h[0] = 0x20;
            func_001389D0();
            enemy_remove();
            return;
        }
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
            ENTITY(reg_a6)[3].look.h = (u16) reg_d1.h[0];
            score_add_no_chain();
            reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
            reg_d0.b[0] ^= 0xF;
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            reg_d0.w = 0x7FFF;
            reg_d0.h[0] -= ENTITY(reg_a6)->hp.h;
            reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x32);
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x34);
            reg_tmp.w -= reg_d0.w;
            *(u16 *)(reg_a5 + 0x32) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a5 + 0x34) = (u16) reg_tmp.h[0];
            ENTITY(reg_a6)->hp.h = 0x7FFFU;
            reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x32);
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x34);
            if ((s32) reg_tmp.w < 0) {
                reg_d0.w = 0x1000;
                score_add();
                vibration_start_pad1(0xB4, 0x50);
                vibration_start_pad2(0xB4, 0x50);
                reg_d0.h[0] = 0x20;
                reg_d1.h[0] = 0x20;
                func_001389D0();
                ENTITY(reg_a6)->flags.h = 0x8000;
                ENTITY(reg_a6)[3].misc.b.draw_layer = 1U;
                g_enemy_signal_2 = 0;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_a1 = D_00265B60;
                func_001D5040();
                sfx_explosion_extra_1();
                goto block_6;
            }
        } else {
block_6:
            ENTITY(reg_a6)->attr.b.palette = 0x10U;
        }
        func_001FA320();
        reg_d0.w = 0;
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp.w = (u32) (s16) reg_d0.h[0];
        reg_d0.w = reg_tmp.w;
        reg_d0.w += 0x4000;
        if ((s32) reg_d0.w < 0x801) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                g_enemy_signal_2 = 0;
                enemy_remove();
                return;
            }
            goto block_11;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
block_11:
        entity_follow_scroll();
        if (ENTITY(reg_a6)[3].misc.b.draw_layer == 0) {
            if (*(u8 *)(reg_a5 + 0x16) == 0) {
                *(u16 *)(reg_a5 + 0x1C) -= 1;
                if (*(u16 *)(reg_a5 + 0x1C) == 0) {
                    *(u8 *)(reg_a5 + 0x16) = 1U;
                }
            }
            if (*(u8 *)(reg_a5 + 0x16) == 1) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x19);
                *(u8 *)(reg_a5 + 0x19) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x19) = (u8) *(u8 *)(reg_a5 + 0x18);
                    *(u16 *)(reg_a5 + 0x1A) += 4;
                    if ((s32) *(u16 *)(reg_a5 + 0x1A) >= 0x1C) {
                        *(u16 *)(reg_a5 + 0x1A) = 0x1CU;
                        D_0028E3A8_as_u16 = 0;
                        D_0028E3A4_as_u16 = 0;
                        *(u8 *)(reg_a5 + 0x16) = 2U;
                        *(s16 *)(reg_a5 + 0x1E) = 0x1020;
                        *(s16 *)(reg_a5 + 0x20) = 0x606;
                        *(s16 *)(reg_a5 + 0x22) = 6;
                        *(s16 *)(reg_a5 + 0x24) = 0x2030;
                        *(s16 *)(reg_a5 + 0x26) = 0x404;
                        *(s16 *)(reg_a5 + 0x28) = 4;
                        *(s8 *)(reg_a5 + 0x2B) = 0;
                        *(s8 *)(reg_a5 + 0x2A) = 0;
                        *(s16 *)(reg_a5 + 0x2C) = 0x6040;
                        *(u8 *)(reg_a5 + 0x2F) = 1U;
                    }
                }
            }
            if (*(u8 *)(reg_a5 + 0x16) == 2) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x2D);
                *(u8 *)(reg_a5 + 0x2D) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x2D) = *(u8 *)(reg_a5 + 0x2C);
                    if (g_bullets_blocked == 0) {
                        temp_a0 = 0xFA80 & 0xFFFF;
                        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d0.h[0] += temp_a0;
                        reg_d1.h[0] += 0x7FFF + 0x7801;
                        aim_at_player();
                        if (cond_flag == 0) {
                            reg_d0.w = 0xD;
                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d2.w += 0xFA7FF800;
                            reg_d4.w = 0;
                            reg_d3.w = 0;
                            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d0.h[0] += 0x7FFF + 0x7A81;
                            reg_d1.h[0] += 0x800;
                            aim_at_player();
                            reg_d0.w = 0xD;
                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d2.w += 0xFA800800;
                            reg_d4.w = 0;
                            reg_d3.w = 0;
                            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d0.h[0] += 0xF80;
                            reg_d1.h[0] += 0x7FFF + 0x7941;
                            aim_at_player();
                            reg_d0.w = 0xD;
                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d2.w += 0x0F7FF940;
                            reg_d4.w = 0;
                            reg_d3.w = 0;
                            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d0.h[0] += 0xF80;
                            reg_d1.h[0] += 0x6C0;
                            aim_at_player();
                            reg_d0.w = 0xD;
                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d2.w += 0x0F8006C0;
                            reg_d4.w = 0;
                            reg_d3.w = 0;
                            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d0.h[0] += 0x13C0;
                            reg_d1.h[0] += 0x7FFF + 0x7C01;
                            aim_at_player();
                            reg_d0.w = 0xD;
                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d2.w += 0x13BFFC00;
                            reg_d4.w = 0;
                            reg_d3.w = 0;
                            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d0.h[0] += 0x13C0;
                            reg_d1.h[0] += 0x400;
                            aim_at_player();
                            reg_d0.w = 0xD;
                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d2.w += 0x13C00400;
                            reg_d4.w = 0;
                            reg_d3.w = 0;
                        }
                    }
                }
            }
            if (*(u8 *)(reg_a5 + 0x2F) == 1) {
                ENTITY(reg_a6)[1].look.h -= 1;
                if (ENTITY(reg_a6)[1].look.h == 0) {
                    func_001F9ED0();
                    *(u8 *)(reg_a5 + 0x2F) = 2U;
                }
            }
            temp_a0_2 = *(u8 *)(reg_a5 + 0x2F);
            if (temp_a0_2 == 2) {
                func_001F9F90();
                if (cond_flag == 0) {
                    *(u8 *)(reg_a5 + 0x2F) = 3U;
                    func_001FA0E0();
                }
            }
            temp_a0_3 = *(u8 *)(reg_a5 + 0x2F);
            if (temp_a0_3 == 3) {
                func_001FA180();
                if (cond_flag == 0) {
                    *(u8 *)(reg_a5 + 0x2F) = 2U;
                    func_001F9ED0();
                }
            }
        }
        goto block_33;
    }
block_33:
    if (ENTITY(reg_a6)[3].misc.b.draw_layer == 0) {
        reg_a0 = D_00265B40;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a0_4 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a0_4;
        reg_d1.w += 0xE400EA00;
        reg_d3.h[0] = 0x1CB0;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
        sprite_draw_layer1();
        reg_a0 = reg_a6;
        enemy_hitbox_debug_draw();
    }
}

s32 rng_next_unsigned();

void func_001F9ED0(void) {
    ENTITY(reg_a6)[1].draw.sh = 0x258;
    ENTITY(reg_a6)[1].offset_x.sh = 0x104;
    rng_next_unsigned();
    reg_d0.h[0] &= 0x1F;
    ENTITY(reg_a6)[1].sprite.b[1] = 0x40U;
    ENTITY(reg_a6)[1].sprite.b[1] -= reg_d0.b[0];
    ENTITY(reg_a6)[1].sprite.b[0] = 0U;
    reg_d7.h[0] = 0x3B;
    do {
        ENTITY(reg_a6)[1].sprite.b[0] += 1;
        reg_d0.b[0] = ENTITY(reg_a6)[1].sprite.b[0];
        ENTITY(reg_a6)[1].sprite.b[1] += reg_d0.b[0];
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

s32 bullet_fire256_2way();

void func_001F9F90(void) {
    u8 var_a0;

    cond_flag = 0;
    reg_tmp.b[0] = ENTITY(reg_a6)[1].offset_x.b[1];
    ENTITY(reg_a6)[1].offset_x.b[1] -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        var_a0 = 0x10000000;
        ENTITY(reg_a6)[1].offset_x.b[1] = (u8) ENTITY(reg_a6)[1].offset_x.b[0];
        ENTITY(reg_a6)[1].sprite.b[0] += 1;
        reg_d0.b[0] = ENTITY(reg_a6)[1].sprite.b[0];
        ENTITY(reg_a6)[1].sprite.b[1] += reg_d0.b[0];
        reg_d1.b[0] = ENTITY(reg_a6)[1].sprite.b[1];
        reg_d0.w = 0x50003;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d2.w += 0x10000000;
        reg_d1.b[0] -= 0x18;
        reg_d7.w = 3;
        reg_d4.w = 0;
        reg_d3.w = 0;
        do {
            reg_d6.h[0] = reg_d1.h[0];
            bullet_fire256_2way();
            reg_d1.h[0] = reg_d6.h[0];
            reg_d1.b[0] += 0x80;
            reg_d6.h[0] = reg_d1.h[0];
            bullet_fire256_2way();
            reg_d1.h[0] = reg_d6.h[0];
            reg_d1.b[0] += 0x8C;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    ENTITY(reg_a6)[1].draw.h -= 1;
    if (ENTITY(reg_a6)[1].draw.h != 0) {
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

extern u16 g_game_frame;
extern u16 g_loop;

void func_001FA0E0(void) {
    ENTITY(reg_a6)[2].look.sh = 0;
    ENTITY(reg_a6)[2].draw.sh = 0x258;
    ENTITY(reg_a6)[2].offset_x.sh = 0x202;
    reg_d0.w = 3;
    if (g_loop != 0) {
        reg_d0.w = 2;
    }
    if (!(g_game_frame & 2)) {
        ENTITY(reg_a6)[2].offset_x.b[1] += reg_d0.b[0];
    }
    ENTITY(reg_a6)[2].offset_x.b[0] += reg_d0.b[0];
    rng_next_unsigned();
    reg_d0.b[0] -= 0x20;
    ENTITY(reg_a6)[2].sprite.b[1] = (u8) reg_d0.b[0];
}

s32 bullet_fire256_fixed();
s32 bullet_fire256_double();

void func_001FA180(void) {
    u32 temp_a0;
    u8 temp_a1;

    ENTITY(reg_a6)[2].sprite.b[1] += 2;
    ENTITY(reg_a6)[2].offset_x.b[1] -= 1;
    if ((s8) ENTITY(reg_a6)[2].offset_x.b[1] < 0) {
        reg_d0.b[0] = ENTITY(reg_a6)[2].sprite.b[1];
        reg_d0.b[0] += 0x10;
        if ((s32) reg_d0.b[0] < 0x21) {
            if ((s8) ENTITY(reg_a6)[2].offset_x.b[1] > -2) {
                goto block_end;
            }
        } else if ((s8) ENTITY(reg_a6)[2].offset_x.b[1] >= -2) {
            goto block_end;
        }
        ENTITY(reg_a6)[2].offset_x.b[1] = (u8) ENTITY(reg_a6)[2].offset_x.b[0];
block_end:;
    } else {
        temp_a1 = ENTITY(reg_a6)[2].sprite.b[1];
        reg_d1.b[0] = temp_a1;
        reg_d0.w = 0xFFFD0004;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        temp_a0 = reg_d2.w;
        reg_d4.w = 0;
        reg_d3.w = 0;
        reg_d2.w = temp_a0 + 0x10000000;
        if (g_loop == 0) {
            bullet_fire256_double();
            reg_d1.b[0] *= -1;
            bullet_fire256_double();
        } else {
            if (ENTITY(reg_a6)[2].look.h == 0) {
                bullet_fire256_double();
                reg_d1.b[0] *= -1;
                bullet_fire256_double();
            } else {
                bullet_fire256_fixed();
                reg_d1.b[0] *= -1;
                bullet_fire256_fixed();
            }
            ENTITY(reg_a6)[2].look.h += 1;
            ENTITY(reg_a6)[2].look.h &= 1;
        }
    }
    ENTITY(reg_a6)[2].draw.h -= 1;
    if (ENTITY(reg_a6)[2].draw.h != 0) {
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

s32 func_00201710(void *);

void func_001FA320(void) {
    if ((ENTITY(reg_a6)[3].misc.b.draw_layer != 0) && (ENTITY(reg_a6)[3].offset_y.b[1] == 0)) {
        reg_d1.h[0] = ENTITY(reg_a6)[3].look.h;
        func_00201710(reg_a6);
        ENTITY(reg_a6)[3].hit_y_plus.h -= 1;
        if (ENTITY(reg_a6)[3].hit_y_plus.h == 0) {
            ENTITY(reg_a6)[3].misc.sb.user = 1;
        }
    }
    cond_flag = 0;
}
