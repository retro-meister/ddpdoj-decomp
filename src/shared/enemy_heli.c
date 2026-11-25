#include "common.h"
#include "entity.h"

void func_00150F40(void);


s32 explosion_spawn();
s32 func_0018D540();
s32 score_add_no_chain();
s32 score_add();

void func_00150510(u32 arg0) {
    s32 enemy_remove();
    u8 temp_a0;
    u8 temp_a1;

    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = *(u8 *)(reg_a5 + 0x2B);
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x2A);
        reg_d0.b[0] ^= reg_d2.b[0];
        *(u8 *)(reg_a6 + 0x1C) = (u8) reg_d0.b[0];
        if (ENTITY(reg_a6)->hp.sh < 0) {
            reg_d0.w = arg0;
            score_add();
            reg_d0.w = 2;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
            reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
            reg_d0.b[0] += 8;
            *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d1.b[0] *= 4;
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d1.b[0];
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            func_0018D540();
            enemy_remove();
            cond_flag = 1;
            return;
        }
        goto block_4;
    }
    *(u8 *)(reg_a6 + 0x1C) = (u8) *(u8 *)(reg_a5 + 0x2B);
block_4:
    cond_flag = 0;
}

extern u16 D_002579D0[];

void func_00150670(u8 arg0) {
    reg_d2.w = 0;
    reg_d2.b[0] = arg0;
    reg_a0 = (u8 *)(D_002579D0);
    reg_d2.h[0] += 1;
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
}

void func_00150730(void) {
}

extern u16 g_enemy_signal_0;
extern u16 g_stage;

void func_00150740(void) {
    s32 enemy_remove(u16);
    if ((g_stage == 1) && (g_enemy_signal_0 != 0)) {
        enemy_remove(g_stage);
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

extern u16 g_enemy_signal_f;

void func_00150790(void) {
    s32 enemy_remove(u16);
    if ((g_stage == 2) && (g_enemy_signal_f != 0)) {
        enemy_remove(g_stage);
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

s32 enemy_hitbox_debug_draw(void);
s32 sprite_draw_layer4(void);
s32 sprite_draw_layer5(void);
extern u8 D_00257880[];
extern u16 D_0028E3EC;
extern u16 g_loop;

void func_001507E0(void) {
    u32 offset;

    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    if (D_0028E3EC != 0) {
        reg_d1.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] += 0x7FFF + 0x7901;
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d3.h[0] = 0x828;
        reg_d1.h[0] += 0x7FFF + 0x7B01;
        reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
        reg_d2.h[0] = *(u16 *)(reg_a5 + 0x20);
        reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)(D_00257880 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)D_00257880;
        offset = reg_d2.h[0] + 2;
        reg_d2.h[0] = (offset != 0) ? *(u16 *)(D_00257880 + ((s16)offset & ~1)) : *(u16 *)D_00257880;
        sprite_draw_layer5();
        *(u16 *)(reg_a5 + 0x20) += 4;
        *(u16 *)(reg_a5 + 0x20) &= 0xF;
    block_rts:
        return;
    }
    if (g_loop != 0) {
        goto block_rts;
    }
    switch (g_stage) {
    case 2:
        return;
    }
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] += 0x7FFF + 0x6C01;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x400;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0x2C);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x2E);
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
    reg_d4.b[0] = 0x18;
    sprite_draw_layer4();
}


extern void enemy_set_entity_count(s32);

void func_001509C0(void) {
    enemy_set_entity_count(0);
}


s32 enemy_set_task_work();
s32 enemy_init_entities();
s32 enemy_path_start();
s32 func_002036F0();
extern u16 D_00257890[];
extern u16 D_002578B0[];
extern u16 D_002578D0[];
extern u16 D_00257950[];
extern u16 g_enemy_signal_5;
extern u16 g_enemy_signal_4;
extern u16 g_enemy_signal_3;
extern u16 g_enemy_signal_2;
extern u16 g_enemy_signal_1;
extern u16 g_rank_2_16;
extern s8 enemy_move_end_requested;

void func_001509D0(void) {
    s32 enemy_remove();
    func_00150740();
    if ((cond_flag == 0) && (reg_a0 = (u8 *)D_002578B0, enemy_init_entities(), reg_a0 = (u8 *)D_00257890, reg_d0.h[0] = 0xC, enemy_set_task_work(), *(u8 *)(reg_a6 + 0x1C) = (u8) *(u8 *)(reg_a5 + 0x2B), enemy_path_start(), (enemy_move_end_requested == 0))) {
        reg_a0 = (u8 *)(D_002578D0);
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_00257950);
        *(u16 *)(reg_a5 + 0x2C) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a5 + 0x2E) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        if (*(u8 *)(reg_a5 + 0xD) & 0x20) {
            func_002036F0();
        }
        reg_d0.h[0] = g_rank_2_16;
        reg_d0.b[0] -= 8;
        *(u8 *)(reg_a5 + 0x19) -= reg_d0.b[0];
        if (g_stage == 4) {
            if (g_enemy_signal_1 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_2 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_3 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_4 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_5 != 0) {
                enemy_remove();
            }
        }
    }
}

s32 bullet_fire();
s32 func_00171430();
s32 entity_velocity();
s32 func_00202180();
s32 func_00202490();
s32 func_00202D50();
extern u16 g_enemies_stopped;
extern u16 g_rank_5_16;

void func_00150C50(void) {
    u16 temp_a0_2;
    func_00150510(8);
    if ((cond_flag == 0) && (func_00171430(), (cond_flag == 0))) {
        if (g_enemies_stopped != 0) {
#ifndef DEATH_LABEL
            func_00150F40();
#endif
            return;
        }
        entity_velocity();
        if (*(u16 *)(reg_a5 + 0x28) != 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
            *(u8 *)(reg_a5 + 0x1B) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
                *(u16 *)(reg_a5 + 0x28) -= 1;
                func_00202490();
                if (cond_flag != 0) {
                    func_00150F40();
                    return;
                }
                reg_a0 = (u8 *)(D_002578D0);
                reg_d1.h[0] &= 0x3E;
                reg_d1.h[0] += reg_d1.h[0];
                ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_a0 = (u8 *)(D_00257950);
                *(u16 *)(reg_a5 + 0x2C) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                *(u16 *)(reg_a5 + 0x2E) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                goto block_21;
            }
        }
block_21:
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x19);
        *(u8 *)(reg_a5 + 0x19) -= 1;
        if ((s32) reg_tmp.b[0] > 0) {
            func_00150F40();
            return;
        }
        reg_d0.w = 0x58;
        reg_d0.h[0] -= g_rank_5_16;
        reg_d0.h[0] += 2;
        *(u8 *)(reg_a5 + 0x19) = (u8) reg_d0.b[0];
        func_00202D50();
        if (cond_flag != 0) {
            func_00150F40();
            return;
        }
        func_00202180();
        if (cond_flag != 0) {
            func_00150F40();
            return;
        }
        func_00150670(ENTITY(reg_a6)->move.b.dir);
        reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
        temp_a0_2 = ENTITY(reg_a6)->x.h;
        reg_tmp.h[0] = temp_a0_2;
        reg_d0.w = 0x3000D;
        reg_d2.w += reg_tmp.w;
        func_00150730();
        reg_d3.w = 0;
        bullet_fire();
        func_00150F40();
    }
}

s32 entity_draw_layer5();                            /* extern */

void func_00150F40(void) {
    entity_draw_layer5();
    func_001507E0();
}

s32 entity_draw_layer5();

void func_00150F70(void) {
    reg_a0 = (u8 *)(D_002578D0);
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(D_00257950);
    *(u16 *)(reg_a5 + 0x2C) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0x2E) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    entity_draw_layer5();
    func_001507E0();
}

void func_001510C0(void) {
    enemy_set_entity_count(0);
}

extern u16 D_00257A50[];
extern u16 D_00257A70[];

void func_001510D0(void) {
    func_00150740();
    if (cond_flag == 0) {
        func_00150790();
        if (cond_flag == 0) {
            reg_a0 = (u8 *)(D_00257A70);
            enemy_init_entities();
            reg_a0 = (u8 *)(D_00257A50);
            reg_d0.h[0] = 0xA;
            enemy_set_task_work();
            *(u8 *)(reg_a6 + 0x1C) = (u8) *(u8 *)(reg_a5 + 0x2B);
            enemy_path_start();
            if (enemy_move_end_requested == 0) {
                reg_a0 = (u8 *)(D_002578D0);
                reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                reg_d1.h[0] &= 0x3E;
                reg_d1.h[0] += reg_d1.h[0];
                ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_a0 = (u8 *)(D_00257950);
                *(u16 *)(reg_a5 + 0x2C) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                *(u16 *)(reg_a5 + 0x2E) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                if (*(u8 *)(reg_a5 + 0xD) & 0x20) {
                    func_002036F0();
                }
                reg_d0.h[0] = g_rank_2_16;
                reg_d0.b[0] -= 8;
                *(u8 *)(reg_a5 + 0x19) -= reg_d0.b[0];
            }
        }
    }
}

s32 enemy_path_step();

void func_001512D0(void) {
    u16 temp_a0_2;
    func_00150510(8);
    if ((cond_flag == 0) && (func_00171430(), (cond_flag == 0))) {
        if (g_enemies_stopped != 0) {
            func_00150F40();
            return;
        }
        if (*(u16 *)(reg_a5 + 0x1C) != 0) {
            entity_velocity();
            goto block_7;
        }
        enemy_path_step();
        if (enemy_move_end_requested == 0) {
block_7:
            if ((s32) ENTITY(reg_a6)->move.b.dir >= 0x40) {
                *(u16 *)(reg_a5 + 0x1C) = 1U;
            }
            if ((*(u16 *)(reg_a5 + 0x28) != 0) && (*(u16 *)(reg_a5 + 0x1C) != 0)) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
                *(u8 *)(reg_a5 + 0x1B) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
                    *(u8 *)(reg_a5 + 0x29) -= 1;
                    func_00202490();
                    goto block_13;
                }
            } else {
block_13:
                reg_a0 = (u8 *)(D_002578D0);
                reg_d1.h[0] &= 0x3E;
                reg_d1.h[0] += reg_d1.h[0];
                ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_a0 = (u8 *)(D_00257950);
                *(u16 *)(reg_a5 + 0x2C) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                *(u16 *)(reg_a5 + 0x2E) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            }
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x19);
            *(u8 *)(reg_a5 + 0x19) -= 1;
            if ((s32) reg_tmp.b[0] > 0) {
                func_00150F40();
                return;
            }
            reg_d0.w = 0x58;
            reg_d0.h[0] -= g_rank_5_16;
            reg_d0.h[0] += 2;
            *(u8 *)(reg_a5 + 0x19) = (u8) reg_d0.b[0];
            func_00202D50();
            if (cond_flag != 0) {
                func_00150F40();
                return;
            }
            func_00202180();
            if (cond_flag != 0) {
                func_00150F40();
                return;
            }
            func_00150670(ENTITY(reg_a6)->move.b.dir);
            reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
            temp_a0_2 = ENTITY(reg_a6)->x.h;
            reg_tmp.h[0] = temp_a0_2;
            reg_d0.w = 0x3000D;
            reg_d2.w += reg_tmp.w;
            func_00150730();
            reg_d3.w = 0;
            bullet_fire();
            func_00150F40();
        }
    }
}

void func_00151600(void) {
    enemy_set_entity_count(0);
}

extern u16 D_00257A90[];
extern u16 D_00257AB0[];

void func_00151610(void) {
    func_00150740();
    if (cond_flag == 0) {
        func_00150790();
        if (cond_flag == 0) {
            reg_a0 = (u8 *)(D_00257AB0);
            enemy_init_entities();
            reg_a0 = (u8 *)(D_00257A90);
            reg_d0.h[0] = 0xA;
            enemy_set_task_work();
            *(u8 *)(reg_a6 + 0x1C) = (u8) *(u8 *)(reg_a5 + 0x2B);
            enemy_path_start();
            if (enemy_move_end_requested == 0) {
                reg_a0 = (u8 *)(D_002578D0);
                reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                reg_d1.h[0] &= 0x3E;
                reg_d1.h[0] += reg_d1.h[0];
                ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_a0 = (u8 *)(D_00257950);
                *(u16 *)(reg_a5 + 0x2C) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                *(u16 *)(reg_a5 + 0x2E) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                if (*(u8 *)(reg_a5 + 0xD) & 0x20) {
                    func_002036F0();
                }
                reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
                reg_d0.b[0] += 0x20;
                reg_d0.b[0] &= 0x3C;
                *(u8 *)(reg_a5 + 0x23) = (u8) reg_d0.b[0];
                func_00202180();
                if (cond_flag != 0) {
                    reg_d1.w = 0x20;
                }
                *(u8 *)(reg_a5 + 0x22) = (u8) reg_d1.b[0];
                reg_d0.h[0] = g_rank_2_16;
                reg_d0.b[0] -= 8;
                *(u8 *)(reg_a5 + 0x19) -= reg_d0.b[0];
                if (g_stage == 2) {
                    *(u8 *)(reg_a5 + 0x19) = 0xAU;
                }
            }
        }
    }
}

s32 direction_turn_toward();
extern u16 D_0028E3E4;

void func_00151880(void) {
    func_00150510(8);
    if (cond_flag != 0) return;
    func_00171430();
    if (cond_flag != 0) return;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x22);
    if (g_enemies_stopped != 0) {
        func_00150F70();
        return;
    }
    entity_velocity();
    if (*(u16 *)(reg_a5 + 0x26) != 0) goto next_4;
    if (ENTITY(reg_a6)->move.b.speed == 0) goto next_1;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
    *(u8 *)(reg_a5 + 0x25) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_1;
    *(u8 *)(reg_a5 + 0x25) = *(u8 *)(reg_a5 + 0x24);
    ENTITY(reg_a6)->move.b.speed -= 1;
    if (ENTITY(reg_a6)->move.b.speed != 0) goto next_1;
    *(u16 *)(reg_a5 + 0x24) = 3;
    *(u8 *)(reg_a5 + 0x19) = 0x10;
    reg_d1.h[0] = 0x3000;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x22);
    reg_d1.b[0] &= 0x3C;
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    *(u8 *)(reg_a5 + 0x1B) = 0x30;
    if (*(u8 *)(reg_a5 + 0x23) == reg_d1.b[0]) goto next_1;
    if ((s32)*(u8 *)(reg_a5 + 0x23) < (s32)reg_d1.b[0]) goto next_0;
    *(u8 *)(reg_a5 + 0x1E) = 0xFC;
    goto next_1;
next_0:
    *(u8 *)(reg_a5 + 0x1E) = 4;
next_1:
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x22);
    if (D_0028E3E4 != 0) goto next_2;
    func_00202180();
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x22);
    direction_turn_toward();
    *(u8 *)(reg_a5 + 0x22) = reg_d1.b[0];
next_2:
    if (ENTITY(reg_a6)->move.b.speed != 0) goto next_7;
    *(u16 *)(reg_a5 + 0x26) = 1;
    goto next_7;
next_4:
    if (ENTITY(reg_a6)->move.b.speed == 0x1C) goto next_5;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
    *(u8 *)(reg_a5 + 0x25) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_5;
    *(u8 *)(reg_a5 + 0x25) = *(u8 *)(reg_a5 + 0x24);
    ENTITY(reg_a6)->move.b.speed += 1;
next_5:
    if (*(u16 *)(reg_a5 + 0x1C) != 0) goto next_6;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
    *(u8 *)(reg_a5 + 0x1B) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_6;
    *(u8 *)(reg_a5 + 0x1B) = *(u8 *)(reg_a5 + 0x1A);
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d1.b[0] += *(u8 *)(reg_a5 + 0x1E);
    reg_d1.b[0] &= 0x3C;
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    if (*(u8 *)(reg_a5 + 0x23) != reg_d1.b[0]) {
        func_00150F70();
        return;
    }
    *(u16 *)(reg_a5 + 0x1C) = 1;
next_6:
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    func_00150F70();
    return;
next_7:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x19);
    *(u8 *)(reg_a5 + 0x19) -= 1;
    if ((s32)reg_tmp.b[0] > 0) {
        func_00150F70();
        return;
    }
    reg_d0.w = 0x58;
    reg_d0.h[0] -= g_rank_5_16;
    reg_d0.h[0] += 2;
    *(u8 *)(reg_a5 + 0x19) = reg_d0.b[0];
    func_00202D50();
    if (cond_flag != 0) {
        func_00150F70();
        return;
    }
    func_00202180();
    if (cond_flag != 0) {
        func_00150F70();
        return;
    }
    func_00150670(reg_d1.b[0]);
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.w = 0x3000D;
    reg_d2.w += reg_tmp.w;
    func_00150730();
    reg_d3.w = 0;
    bullet_fire();
    func_00150F70();
}

void func_00151C20(void) {
    enemy_set_entity_count(0);
}

extern u16 D_00257AD0[];
extern u16 D_00257AF0[];
extern u16 g_enemy_signal_7;
extern u16 g_enemy_signal_6;

void func_00151C30(void) {
    s32 enemy_remove();
    func_00150740();
    if ((cond_flag == 0) && (func_00150790(), (cond_flag == 0)) && (reg_a0 = (u8 *)D_00257AF0, enemy_init_entities(), reg_a0 = (u8 *)D_00257AD0, reg_d0.h[0] = 0xA, enemy_set_task_work(), *(u8 *)(reg_a6 + 0x1C) = (u8) *(u8 *)(reg_a5 + 0x2B), enemy_path_start(), (enemy_move_end_requested == 0))) {
        reg_a0 = (u8 *)(D_002578D0);
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_00257950);
        *(u16 *)(reg_a5 + 0x2C) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a5 + 0x2E) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        if (*(u8 *)(reg_a5 + 0xD) & 0x20) {
            func_002036F0();
        }
        reg_d1.w = 0x20;
        func_00202180();
        *(u8 *)(reg_a5 + 0x22) = (u8) reg_d1.b[0];
        reg_d0.h[0] = g_rank_2_16;
        reg_d0.b[0] -= 8;
        *(u8 *)(reg_a5 + 0x19) -= reg_d0.b[0];
        if (g_stage == 4) {
            if (g_enemy_signal_4 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_5 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_6 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_7 != 0) {
                enemy_remove();
            }
        }
    }
}

#ifdef DEATH_LABEL
s32 func_00202490();
#endif

void func_00151EC0(void) {
    func_00150510(8);
    if (cond_flag != 0) return;
    func_00171430();
    if (cond_flag != 0) return;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x22);
    if (g_enemies_stopped != 0) {
        func_00150F70();
        return;
    }
    entity_velocity();
    if (*(u16 *)(reg_a5 + 0x26) != 0) goto next_4;
    if (ENTITY(reg_a6)->move.b.speed == 0) goto next_1;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
    *(u8 *)(reg_a5 + 0x25) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_1;
    *(u8 *)(reg_a5 + 0x25) = *(u8 *)(reg_a5 + 0x24);
    ENTITY(reg_a6)->move.b.speed -= 1;
    if (ENTITY(reg_a6)->move.b.speed != 0) goto next_1;
    *(u16 *)(reg_a5 + 0x24) = 2;
    *(u8 *)(reg_a5 + 0x19) = 0x10;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x22);
    reg_d1.b[0] &= 0x3C;
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    *(u8 *)(reg_a5 + 0x1B) = 0x30;
next_1:
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x22);
    if (D_0028E3E4 != 0) goto next_2;
    func_00202180();
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x22);
    direction_turn_toward();
    *(u8 *)(reg_a5 + 0x22) = reg_d1.b[0];
next_2:
    if (ENTITY(reg_a6)->move.b.speed != 0) goto next_7;
    *(u16 *)(reg_a5 + 0x26) = 1;
    goto next_7;
next_4:
    if (ENTITY(reg_a6)->move.b.speed == MAIN_OR_DEATH_LABEL(0x1C, 0x20)) goto next_5;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
    *(u8 *)(reg_a5 + 0x25) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_5;
    *(u8 *)(reg_a5 + 0x25) = *(u8 *)(reg_a5 + 0x24);
    ENTITY(reg_a6)->move.b.speed += MAIN_OR_DEATH_LABEL(1, 2);
next_5:
#ifdef DEATH_LABEL
    if (*(u16 *)(reg_a5 + 0x1C) == 0) goto next_6;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
    *(u8 *)(reg_a5 + 0x1B) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_6;
    *(u8 *)(reg_a5 + 0x1B) = *(u8 *)(reg_a5 + 0x1A);
    *(u16 *)(reg_a5 + 0x28) -= 1;
    func_00202490();
    func_00150F70();
    return;
#else
    if (*(u16 *)(reg_a5 + 0x1C) != 0) goto next_6;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
    *(u8 *)(reg_a5 + 0x1B) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_6;
    *(u8 *)(reg_a5 + 0x1B) = *(u8 *)(reg_a5 + 0x1A);
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d1.b[0] += *(u8 *)(reg_a5 + 0x1E);
    reg_d1.b[0] &= 0x3C;
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    if (*(u8 *)(reg_a5 + 0x23) != reg_d1.b[0]) {
        func_00150F70();
        return;
    }
    *(u16 *)(reg_a5 + 0x1C) = 1;
#endif
next_6:
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    func_00150F70();
    return;
next_7:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x19);
    *(u8 *)(reg_a5 + 0x19) -= 1;
    if ((s32)reg_tmp.b[0] > 0) {
        func_00150F70();
        return;
    }
    reg_d0.w = 0x58;
    reg_d0.h[0] -= g_rank_5_16;
    reg_d0.h[0] += 2;
    *(u8 *)(reg_a5 + 0x19) = reg_d0.b[0];
    func_00202D50();
    if (cond_flag != 0) {
        func_00150F70();
        return;
    }
    func_00202180();
    if (cond_flag != 0) {
        func_00150F70();
        return;
    }
    func_00150670(reg_d1.b[0]);
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.w = 0x3000D;
    reg_d2.w += reg_tmp.w;
    func_00150730();
    reg_d3.w = 0;
    bullet_fire();
    func_00150F70();
}

void func_00152230(void) {
    enemy_set_entity_count(0);
}

extern u16 D_00257B10[];
extern u16 D_00257B30[];

void func_00152240(void) {
    func_00150740();
    if (cond_flag == 0) {
        reg_a0 = (u8 *)(D_00257B30);
        enemy_init_entities();
        reg_a0 = (u8 *)(D_00257B10);
        reg_d0.h[0] = 0xA;
        enemy_set_task_work();
        *(u8 *)(reg_a6 + 0x1C) = (u8) *(u8 *)(reg_a5 + 0x2B);
        enemy_path_start();
        if (enemy_move_end_requested == 0) {
            reg_a0 = (u8 *)(D_002578D0);
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d1.h[0] &= 0x3E;
            reg_d1.h[0] += reg_d1.h[0];
            ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_a0 = (u8 *)(D_00257950);
            *(u16 *)(reg_a5 + 0x2C) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            *(u16 *)(reg_a5 + 0x2E) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            if (*(u8 *)(reg_a5 + 0xD) & 0x20) {
                func_002036F0();
            }
            reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d0.b[0] += 0x20;
            reg_d0.b[0] &= 0x3C;
            *(u8 *)(reg_a5 + 0x23) = (u8) reg_d0.b[0];
            func_00202180();
            if (cond_flag != 0) {
                reg_d1.w = 0x20;
            }
            *(u8 *)(reg_a5 + 0x22) = (u8) reg_d1.b[0];
            reg_d0.h[0] = g_rank_2_16;
            reg_d0.b[0] -= 8;
            *(u8 *)(reg_a5 + 0x19) -= reg_d0.b[0];
        }
    }
}

void func_00152480(void) {
    u16 temp_a0;
    u8 temp_v0;
    u8 *var_a0;

    func_00150510(8);
    if ((cond_flag == 0) && (func_00171430(), (cond_flag == 0))) {
        reg_d1.b[0] = *(u8 *)(reg_a5 + 0x22);
        if (g_enemies_stopped != 0) {
            func_00150F70();
            return;
        }
        entity_velocity();
        *(u8 *)(reg_a5 + 0x19) -= 1;
        if (*(u8 *)(reg_a5 + 0x19) == 0) {
            reg_d0.w = 0x58;
            reg_d0.h[0] -= g_rank_5_16;
            reg_d0.h[0] += 2;
            *(u8 *)(reg_a5 + 0x19) = (u8) reg_d0.b[0];
            func_00202D50();
            if (cond_flag == 0) {
                func_00202180();
                if (cond_flag == 0) {
                    func_00150670(reg_d1.b[0]);
                    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
                    temp_a0 = ENTITY(reg_a6)->x.h;
                    reg_tmp.h[0] = temp_a0;
                    reg_d0.w = 0xD;
                    reg_d2.w += reg_tmp.w;
                    func_00150730();
                    reg_d3.w = 0;
                    bullet_fire();
                }
            }
        }
        var_a0 = (u8 *)(reg_a5);
        if ((*(u16 *)((u8 *)(var_a0) + (0x26))) == 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x25)));
            (*(u8 *)((u8 *)(var_a0) + (0x25))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x25) = (u8) *(u8 *)(reg_a5 + 0x24);
                ENTITY(reg_a6)->move.b.speed -= 1;
                if (ENTITY(reg_a6)->move.b.speed == 0) {
                    *(u16 *)(reg_a5 + 0x26) = 1U;
                    *(u16 *)(reg_a5 + 0x24) = 2;
                    *(s16 *)(reg_a5 + 0x18) = 0x3008;
                    var_a0 = (u8 *)((void *) *(u8 *)(reg_a5 + 0x23));
                    ENTITY(reg_a6)->move.sb.dir = (s8) var_a0;
                    *(u8 *)(reg_a5 + 0x1B) = 0x30U;
                }
            }
        } else {
            temp_v0 = (*(u8 *)((u8 *)(var_a0) + (0x1B)));
            if (temp_v0 != 0) {
                (*(u8 *)((u8 *)(var_a0) + (0x1B))) = (u8) (temp_v0 - 1);
            } else if (ENTITY(reg_a6)->move.b.speed != 0x20) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x25)));
                (*(u8 *)((u8 *)(var_a0) + (0x25))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x25) = (u8) *(u8 *)(reg_a5 + 0x24);
                    ENTITY(reg_a6)->move.b.speed += 2;
                }
            }
        }
        reg_d1.b[0] = *(u8 *)(reg_a5 + 0x22);
        if (D_0028E3E4 != 0) {
            func_00150F70();
            return;
        }
        func_00202180();
        reg_d0.b[0] = *(u8 *)(reg_a5 + 0x22);
        direction_turn_toward();
        *(u8 *)(reg_a5 + 0x22) = (u8) reg_d1.b[0];
        func_00150F70();
    }
}

void func_001526F0(void) {
    enemy_set_entity_count(0);
}

extern u16 D_00257B50[];
extern u16 D_00257B70[];

void func_00152700(void) {
    func_00150740();
    if (cond_flag == 0) {
        reg_a0 = (u8 *)(D_00257B70);
        enemy_init_entities();
        reg_a0 = (u8 *)(D_00257B50);
        reg_d0.h[0] = 0xA;
        enemy_set_task_work();
        *(u8 *)(reg_a6 + 0x1C) = (u8) *(u8 *)(reg_a5 + 0x2B);
        enemy_path_start();
        if (enemy_move_end_requested == 0) {
            reg_a0 = (u8 *)(D_002578D0);
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d1.h[0] &= 0x3E;
            reg_d1.h[0] += reg_d1.h[0];
            ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_a0 = (u8 *)(D_00257950);
            *(u16 *)(reg_a5 + 0x2C) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            *(u16 *)(reg_a5 + 0x2E) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            func_00202180();
            if (cond_flag != 0) {
                reg_d1.w = 0x20;
            }
            *(u8 *)(reg_a5 + 0x22) = (u8) reg_d1.b[0];
            if (*(u8 *)(reg_a5 + 0xD) & 0x20) {
                func_002036F0();
            }
            reg_d0.h[0] = g_rank_2_16;
            reg_d0.b[0] -= 8;
            *(u8 *)(reg_a5 + 0x19) -= reg_d0.b[0];
        }
    }
}

void func_00152910(void) {
    u16 temp_a0;

    func_00150510(8);
    if ((cond_flag == 0) && (func_00171430(), (cond_flag == 0))) {
        reg_d1.b[0] = *(u8 *)(reg_a5 + 0x22);
        if (g_enemies_stopped != 0) {
            func_00150F70();
            return;
        }
        entity_velocity();
        *(u8 *)(reg_a5 + 0x19) -= 1;
        if (*(u8 *)(reg_a5 + 0x19) == 0) {
            reg_d0.w = 0x58;
            reg_d0.h[0] -= g_rank_5_16;
            reg_d0.h[0] += 2;
            *(u8 *)(reg_a5 + 0x19) = (u8) reg_d0.b[0];
            func_00202D50();
            if (cond_flag == 0) {
                func_00202180();
                if (cond_flag == 0) {
                    func_00150670(*(u8 *)(reg_a5 + 0x22));
                    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
                    temp_a0 = ENTITY(reg_a6)->x.h;
                    reg_tmp.h[0] = temp_a0;
                    reg_d0.w = 0xD;
                    reg_d2.w += reg_tmp.w;
                    func_00150730();
                    reg_d3.w = 0;
                    bullet_fire();
                }
            }
        }
        reg_d1.b[0] = *(u8 *)(reg_a5 + 0x22);
        if (D_0028E3E4 != 0) {
            func_00150F70();
            return;
        }
        func_00202180();
        reg_d0.b[0] = *(u8 *)(reg_a5 + 0x22);
        direction_turn_toward();
        *(u8 *)(reg_a5 + 0x22) = (u8) reg_d1.b[0];
        func_00150F70();
    }
}

void enemy_set_entity_count(s32);

void func_00152A80(void) {
    enemy_set_entity_count(0);
}

extern u16 D_00257B90[];
extern u16 D_00257BB0[];
extern s16 g_scroll_line_as_s16;

void func_00152A90(void) {
    s32 enemy_remove();
    func_00150740();
    if ((cond_flag == 0) && (func_00150790(), (cond_flag == 0)) && (reg_a0 = (u8 *)D_00257BB0, enemy_init_entities(), reg_a0 = (u8 *)D_00257B90, reg_d0.h[0] = 0xA, enemy_set_task_work(), *(u8 *)(reg_a6 + 0x1C) = (u8) *(u8 *)(reg_a5 + 0x2B), enemy_path_start(), (enemy_move_end_requested == 0))) {
        reg_a0 = (u8 *)(D_002578D0);
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_00257950);
        *(u16 *)(reg_a5 + 0x2C) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a5 + 0x2E) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        if (*(u8 *)(reg_a5 + 0xD) & 0x20) {
            func_002036F0();
        }
        reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
        reg_d0.b[0] += 0x20;
        reg_d0.b[0] &= 0x3C;
        *(u8 *)(reg_a5 + 0x23) = (u8) reg_d0.b[0];
        func_00202180();
        if (cond_flag != 0) {
            reg_d1.w = 0x20;
        }
        *(u8 *)(reg_a5 + 0x22) = (u8) reg_d1.b[0];
        reg_d0.h[0] = g_rank_2_16;
        reg_d0.b[0] -= 8;
        *(u8 *)(reg_a5 + 0x19) -= reg_d0.b[0];
        if (g_stage == 4) {
            if (g_scroll_line_as_s16 >= 0x290) {
                if (g_enemy_signal_7 != 0) {
                    enemy_remove();
                }
            } else if (g_scroll_line_as_s16 > 0x1FC) {
                if (((g_scroll_line_as_s16 < 0x240) || (g_scroll_line_as_s16 > 0x274)) && (g_enemy_signal_4 != 0)) {
                    enemy_remove();
                    return;
                }
                if ((g_enemy_signal_5 != 0) && (g_scroll_line_as_s16 > 0x228)) {
                    enemy_remove();
                    return;
                }
                if (g_enemy_signal_6 != 0) {
                    enemy_remove();
                    return;
                }
                if (g_enemy_signal_7 != 0) {
                    enemy_remove();
                }
            }
        }
    }
}

void func_00152DA0(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u8 temp_v1;

    func_00150510(8);
    if ((cond_flag == 0) && (func_00171430(), (cond_flag == 0))) {
        reg_d1.b[0] = *(u8 *)(reg_a5 + 0x22);
        if (g_enemies_stopped != 0) {
            func_00150F70();
            return;
        }
        entity_velocity();
        if (*(u8 *)(reg_a5 + 0x27) == 0) {
            *(u8 *)(reg_a5 + 0x29) -= 1;
            if (*(u8 *)(reg_a5 + 0x29) == 0) {
                *(u8 *)(reg_a5 + 0x29) = (u8) *(u8 *)(reg_a5 + 0x28);
                func_00202D50();
                if (cond_flag == 0) {
                    func_00202180();
                    if (cond_flag == 0) {
                        func_00150670(*(u8 *)(reg_a5 + 0x22));
                        reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
                        temp_a0 = ENTITY(reg_a6)->x.h;
                        reg_tmp.h[0] = temp_a0;
                        reg_d0.w = 0xD;
                        reg_d2.w += reg_tmp.w;
                        func_00150730();
                        reg_d3.w = 0;
                        bullet_fire();
                    }
                }
            }
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
            *(u8 *)(reg_a5 + 0x25) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x25) = (u8) *(u8 *)(reg_a5 + 0x24);
                ENTITY(reg_a6)->move.b.speed -= 1;
                if (ENTITY(reg_a6)->move.b.speed == 0) {
                    *(u8 *)(reg_a5 + 0x27) = 1U;
                    *(u16 *)(reg_a5 + 0x24) = 2;
                    *(u8 *)(reg_a5 + 0x19) = 1U;
                    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x22);
                    reg_d1.b[0] &= 0x3C;
                    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                    *(u8 *)(reg_a5 + 0x1B) = 0x30U;
                    temp_v1 = *(u8 *)(reg_a5 + 0x23);
                    if (temp_v1 != reg_d1.b[0]) {
                        if ((s32) temp_v1 >= (s32) reg_d1.b[0]) {
                            *(u8 *)(reg_a5 + 0x1E) = 0xFC;
                        } else {
                            *(u8 *)(reg_a5 + 0x1E) = 4;
                        }
                    }
                }
            }
            reg_d1.b[0] = *(u8 *)(reg_a5 + 0x22);
            if (D_0028E3E4 != 0) {
                func_00150F70();
                return;
            }
            func_00202180();
            if (cond_flag != 0) {
                func_00150F70();
                return;
            }
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x22);
            direction_turn_toward();
            *(u8 *)(reg_a5 + 0x22) = (u8) reg_d1.b[0];
            func_00150F70();
            return;
        }
        if (*(u8 *)(reg_a5 + 0x26) != 0) {
            *(u8 *)(reg_a5 + 0x19) -= 1;
            if (*(u8 *)(reg_a5 + 0x19) == 0) {
                *(u8 *)(reg_a5 + 0x19) = (u8) *(u8 *)(reg_a5 + 0x18);
                *(u8 *)(reg_a5 + 0x26) -= 1;
                func_00202D50();
                if (cond_flag == 0) {
                    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x22);
                    reg_d1.b[0] = reg_d2.b[0];
                    func_00150670(reg_d1.b[0]);
                    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
                    temp_a0_2 = ENTITY(reg_a6)->x.h;
                    reg_tmp.h[0] = temp_a0_2;
                    reg_d0.w = 0xD;
                    reg_d2.w += reg_tmp.w;
                    func_00150730();
                    reg_d3.w = 0;
                    bullet_fire();
                }
            }
            goto block_33;
        }
        if (ENTITY(reg_a6)->move.b.speed != 0x1C) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
            *(u8 *)(reg_a5 + 0x25) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x25) = (u8) *(u8 *)(reg_a5 + 0x24);
                ENTITY(reg_a6)->move.b.speed += 1;
            }
        }
        if (*(u16 *)(reg_a5 + 0x1C) == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
            *(u8 *)(reg_a5 + 0x1B) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
                reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                reg_d1.b[0] += *(u8 *)(reg_a5 + 0x1E);
                reg_d1.b[0] &= 0x3C;
                ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                if (*(u8 *)(reg_a5 + 0x23) != reg_d1.b[0]) {
                    func_00150F70();
                    return;
                }
                *(u16 *)(reg_a5 + 0x1C) = 1U;
                goto block_33;
            }
        }
block_33:
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        func_00150F70();
    }
}

void func_00153190(void) {
    enemy_set_entity_count(0);
}

extern u16 D_00257BD0[];
extern u16 D_00257BF0[];
extern u16 g_rank_4_16;

void func_001531A0(void) {
    s32 enemy_remove();
    func_00150740();
    if ((cond_flag == 0) && (func_00150790(), (cond_flag == 0)) && (reg_a0 = (u8 *)D_00257BF0, enemy_init_entities(), reg_a0 = (u8 *)D_00257BD0, reg_d0.h[0] = 0xA, enemy_set_task_work(), *(u8 *)(reg_a6 + 0x1C) = (u8) *(u8 *)(reg_a5 + 0x2B), enemy_path_start(), (enemy_move_end_requested == 0))) {
        reg_a0 = (u8 *)(D_002578D0);
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_00257950);
        *(u16 *)(reg_a5 + 0x2C) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a5 + 0x2E) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        func_00202180();
        if (cond_flag != 0) {
            reg_d1.w = 0x20;
        }
        *(u8 *)(reg_a5 + 0x22) = (u8) reg_d1.b[0];
        if (*(u8 *)(reg_a5 + 0xD) & 0x20) {
            func_002036F0();
        }
        reg_d0.h[0] = g_rank_4_16;
        reg_d0.b[0] -= 8;
        *(u8 *)(reg_a5 + 0x19) -= reg_d0.b[0];
        if (g_stage == 4) {
            if (g_enemy_signal_4 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_5 != 0) {
                enemy_remove();
            }
        }
    }
}

void func_00153400(void) {
    u16 temp_a0_2;

    func_00150510(8);
    if ((cond_flag == 0) && (func_00171430(), (cond_flag == 0))) {
        reg_d1.b[0] = *(u8 *)(reg_a5 + 0x22);
        if (g_enemies_stopped != 0) {
            func_00150F70();
            return;
        }
        if (*(u16 *)(reg_a5 + 0x1C) != 0) {
            entity_velocity();
            goto block_7;
        }
        enemy_path_step();
        if (enemy_move_end_requested == 0) {
block_7:
            if ((s32) ENTITY(reg_a6)->move.b.dir >= 0x40) {
                *(u16 *)(reg_a5 + 0x1C) = 1U;
                ENTITY(reg_a6)->move.b.dir -= 0x40;
            }
            if ((*(u16 *)(reg_a5 + 0x28) != 0) && (*(u16 *)(reg_a5 + 0x1C) != 0)) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
                *(u8 *)(reg_a5 + 0x1B) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
                    *(u16 *)(reg_a5 + 0x28) -= 1;
                    func_00202490();
                    if (cond_flag != 0) {
                        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                    }
                }
            }
            func_00202180();
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x22);
            direction_turn_toward();
            *(u8 *)(reg_a5 + 0x22) = (u8) reg_d1.b[0];
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x19);
            *(u8 *)(reg_a5 + 0x19) -= 1;
            if ((s32) reg_tmp.b[0] > 0) {
                func_00150F70();
                return;
            }
            reg_d0.w = 0x58;
            reg_d0.h[0] -= g_rank_5_16;
            reg_d0.h[0] += 2;
            *(u8 *)(reg_a5 + 0x19) = (u8) reg_d0.b[0];
            func_00202D50();
            if (cond_flag != 0) {
                func_00150F70();
                return;
            }
            func_00202180();
            if (cond_flag != 0) {
                func_00150F70();
                return;
            }
            func_00150670(reg_d1.b[0]);
            reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
            temp_a0_2 = ENTITY(reg_a6)->x.h;
            reg_tmp.h[0] = temp_a0_2;
            reg_d0.w = 0x3000D;
            reg_d2.w += reg_tmp.w;
            func_00150730();
            reg_d3.w = 0;
            bullet_fire();
            func_00150F70();
        }
    }
}
