#include "common.h"
#include "entity.h"

void stage2_boss_shoulder_bullet_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 enemy_init_entities();                            /* extern */
extern s32 D_0026C570[];

void stage2_boss_shoulder_bullet_start(void) {
    reg_a0 = (u8 *)D_0026C570;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    ENTITY(reg_a6)->x.h = (u16) *(u16 *)(reg_a5 + 0x18);
    ENTITY(reg_a6)->move.h = (u16) *(u16 *)(reg_a5 + 0x1A);
    *(s8 *)(reg_a5 + 0x17) = 0;
    *(s16 *)(reg_a5 + 0x1E) = 2;
    *(s16 *)(reg_a5 + 0x20) = 0;
    *(s8 *)(reg_a5 + 0x23) = 0;
    *(s8 *)(reg_a5 + 0x22) = 0;
    *(s16 *)(reg_a5 + 0x24) = 2;
    *(s16 *)(reg_a5 + 0x26) = 0x505;
    *(s8 *)(reg_a5 + 0x2B) = 0;
}


s32 enemy_remove();
s32 sprite_draw_layer5();
s32 entity_velocity();
s32 entity_check_bounds();
extern u16 D_0028E574[];

void stage2_boss_shoulder_bullet(void) {
    u16 temp_a2;

    reg_d1.w = 0x5C;
    if ((reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1]) != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        ENTITY(reg_a6)->hp.sh = 0x7FFF;
        if (ENTITY(reg_a6)->hp.sh < 0) {
            enemy_remove();
        }
    }
    entity_check_bounds();
    if (cond_flag != 0) {
        if (*(u8 *)(reg_a5 + 0x17) != 0) {
            enemy_remove();
            return;
        }
        goto block_7;
    }
    *(u8 *)(reg_a5 + 0x17) = 1U;
block_7:
    entity_velocity();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a2 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a2;
    reg_d1.w += 0xF800FC00;
    reg_d3.h[0] = 0x820;
    reg_d4.h[0] = 0x1A;
    reg_a0 = (u8 *)(D_0028E574);
    reg_d2.w = 0;
    reg_d2.b[0] = ENTITY(reg_a6)->move.b.dir;
    if ((s16)(reg_d2.h[0]) > 0x20) {
        reg_d4.h[0] |= 0x40;
    }
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    sprite_draw_layer5();
}

void stage2_boss_spread_bullet_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 enemy_init_entities();
extern u16 D_0024EBC0_as_u16_a[];
extern u16 D_0024EC80[];
extern u16 D_0024EEF0[];
extern u16 D_0026C590[];

void stage2_boss_spread_bullet_start(void) {
    reg_a0 = (u8 *)(D_0026C590);
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    ENTITY(reg_a6)->x.h = (u16) *(u16 *)(reg_a5 + 0x18);
    ENTITY(reg_a6)->move.h = (u16) *(u16 *)(reg_a5 + 0x1A);
    reg_d1.w = 0;
    reg_d1.b[0] = (u8) ENTITY(reg_a6)->move.h;
    reg_a0 = (u8 *)(D_0024EEF0);
    reg_d1.b[0] += 2;
    reg_d1.b[0] = (u8) ((s8) reg_d1.b[0] >> 2);
    reg_d1.h[0] &= 0x3E;
    reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->attr.b.flip = (u8) reg_d0.b[0];
    reg_a0 = (u8 *)(D_0024EC80);
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(D_0024EBC0_as_u16_a);
    *(u16 *)(reg_a5 + 0x1A) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0x1C) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(s16 *)(reg_a5 + 0x1E) = 2;
    *(s16 *)(reg_a5 + 0x20) = 0;
    *(s8 *)(reg_a5 + 0x17) = 0;
}

s32 entity_draw_with_bullets();
s32 func_00201F20();

void stage2_boss_spread_bullet(void) {
    reg_d1.w = 0x5C;
    if ((reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1]) != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        ENTITY(reg_a6)->hp.sh = 0x7FFF;
    }
    func_00201F20();
    if (0 > ENTITY(reg_a6)->y.sh) goto block_e1;
    if (ENTITY(reg_a6)->y.sh > 0x7000) goto block_e1;
    if (0 > ENTITY(reg_a6)->x.sh) goto block_e1;
    if (ENTITY(reg_a6)->x.sh > 0x3800) goto block_e1;
    goto block_l1;
block_e1:
    enemy_remove();
block_l1:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1A);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1C);
        reg_a0 = (u8 *)(reg_tmp.w);
        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
        ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a5 + 0x20) += 4;
        *(u16 *)(reg_a5 + 0x20) &= 0xF;
    }
    entity_draw_with_bullets();
}

void stage2_boss_cannon_shell_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

extern u8 D_0026C5B0[];

void stage2_boss_cannon_shell_start(void) {
    reg_a0 = D_0026C5B0;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    ENTITY(reg_a6)->x.h = (u16) *(u16 *)(reg_a5 + 0x18);
    ENTITY(reg_a6)->move.h = (u16) *(u16 *)(reg_a5 + 0x1A);
    *(u16 *)(reg_a5 + 0x2E) = (u16) *(u16 *)(reg_a5 + 0x1E);
    *(s8 *)(reg_a5 + 0x17) = 0;
    *(u16 *)(reg_a5 + 0x1E) = 2U;
    *(s16 *)(reg_a5 + 0x20) = 0;
    *(s16 *)(reg_a5 + 0x24) = 0;
    *(s16 *)(reg_a5 + 0x26) = 0x20;
    *(s16 *)(reg_a5 + 0x28) = 4;
    *(s16 *)(reg_a5 + 0x2C) = 0x10;
    ENTITY(reg_a6)->move.b.dir &= 0x3F;
    *(u8 *)(reg_a5 + 0x31) = (u8) ENTITY(reg_a6)->move.h;
}

s32 explosion_spawn();
s32 entity_draw_layer5();
extern u8 D_0028DB10[];

void stage2_boss_cannon_shell(void) {
    entity_check_bounds();
    if (cond_flag != 0) {
        if (*(u8 *)(reg_a5 + 0x17) != 0) {
            enemy_remove();
            return;
        }
        goto block_4;
    }
    *(u8 *)(reg_a5 + 0x17) = 1U;
block_4:
    entity_velocity();
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x29);
    *(u8 *)(reg_a5 + 0x29) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a5 + 0x29) = (u8) *(u8 *)(reg_a5 + 0x28);
        reg_d0.h[0] = 6;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x2F);
    *(u8 *)(reg_a5 + 0x2F) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a5 + 0x2F) = (u8) *(u8 *)(reg_a5 + 0x2E);
        reg_d0.w = 0xFFFA0007;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.w = 1;
        reg_d3.w = 0;
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        reg_d1.b[0] += 0x10;
        reg_d1.b[0] &= 0x3F;
        reg_d1.b[0] += 0x20;
        reg_d1.b[0] &= 0x3F;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
        reg_a0 = D_0028DB10;
        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
        ENTITY(reg_a6)->draw.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a5 + 0x20) += 4;
        *(u16 *)(reg_a5 + 0x20) &= 7;
    }
    entity_draw_layer5();
}

void stage2_boss_dropped_bomb_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 func_00202180();
extern u8 D_0026C5D0[];

void stage2_boss_dropped_bomb_start(void) {
    reg_a0 = D_0026C5D0;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = *(u16 *)(reg_a5 + 0x16);
    ENTITY(reg_a6)->x.h = *(u16 *)(reg_a5 + 0x18);
    ENTITY(reg_a6)->move.h = *(u16 *)(reg_a5 + 0x1A);
    func_00202180();
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    *(s8 *)(reg_a5 + 0x17) = 0;
    *(s16 *)(reg_a5 + 0x1E) = 2;
    *(s16 *)(reg_a5 + 0x20) = 0;
}

s32 explosion_spawn();                            /* extern */

void stage2_boss_dropped_bomb(void) {
    extern s32 enemy_remove(u16);
    u16 temp_a0;

    reg_d0.h[0] = 3;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 4) = temp_a0;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    enemy_remove(temp_a0);
}

void stage2_boss_ripple_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

s32 enemy_init_entities();                            /* extern */
extern s32 D_0026C5F0[];

void stage2_boss_ripple_start(void) {
    reg_a0 = (u8 *)D_0026C5F0;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    ENTITY(reg_a6)->x.h = (u16) *(u16 *)(reg_a5 + 0x18);
    *(s8 *)(reg_a5 + 0x17) = 0;
    *(s16 *)(reg_a5 + 0x1E) = 0x202;
    *(s16 *)(reg_a5 + 0x20) = 0;
}

s32 sprite_draw_layer1();
s32 entity_follow_scroll();
extern u32 D_0026C610[];

void stage2_boss_ripple(void) {
    u16 temp_a1;
    u16 temp_a2;

    entity_check_bounds();
    if (cond_flag != 0) {
        if (*(u8 *)(reg_a5 + 0x17) != 0) {
            enemy_remove();
            return;
        }
        goto block_4;
    }
    *(u8 *)(reg_a5 + 0x17) = 1U;
block_4:
    entity_velocity();
    entity_follow_scroll();
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
        *(u16 *)(reg_a5 + 0x20) += 4;
        if (*(u16 *)(reg_a5 + 0x20) == 0x20) {
            enemy_remove();
            return;
        }
    }
    reg_a0 = (u8 *)(D_0026C610);
    temp_a2 = *(u16 *)(reg_a5 + 0x20);
    reg_a0 += temp_a2;
    reg_d2.w = *(u32 *)reg_a0;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a1 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFA00FC00;
    reg_d3.h[0] = 0x620;
    reg_d4.w = 0x17;
    sprite_draw_layer1();
}

s32 D_0026C570[48] = {
    -67076095, 65024, 68157880, 67109888, 33554944, 32767, 26, 0,
    -33521663, 65024, 34603008, 33554944, 16777472, 32767, 26, 0,
    -67076096, 65024, 68157880, 67109888, 33554944, 32767, 26, 0,
    -67067903, 65024, 68157880, 67109888, 33554944, 32767, 26, 0,
    -67076096, 65024, 68157880, 67109888, 33554944, 32767, 26, 0,
    7030, 7031, 7032, 7033, 7034, 7035, 7036, 7037,
};

u8 D_0028DB10[8] = {
    0xB8, 0x01, 0x00, 0x00, 0xB7, 0x01, 0x00, 0x00,
};
