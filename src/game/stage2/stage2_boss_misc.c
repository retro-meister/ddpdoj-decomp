#include "common.h"
#ifdef DDPDOJ_PC
#include "pc_gameplay_abi.h"
#endif
#include "entity.h"
#include "explosion.h"
#include "stage2_boss.h"

void stage2_boss_shoulder_bullet_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

#ifndef DDPDOJ_PC
s32 enemy_init_entities();                            /* extern */
#endif
extern s32 stage2_boss_shoulder_bullet_start_table[];

void stage2_boss_shoulder_bullet_start(void) {
    reg_a0 = (u8 *)stage2_boss_shoulder_bullet_start_table;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) STAGE2_SHOT(reg_a5)->at_start.y;
    ENTITY(reg_a6)->x.h = (u16) STAGE2_SHOT(reg_a5)->at_start.x;
    ENTITY(reg_a6)->move.h = (u16) STAGE2_SHOT(reg_a5)->at_start.move;
    STAGE2_SHOT(reg_a5)->now.seen = 0;
    STAGE2_SHOT(reg_a5)->now.frame_timer.both = 2;
    STAGE2_SHOT(reg_a5)->frame = 0;
    STAGE2_SHOT(reg_a5)->unread_23 = 0;
    STAGE2_SHOT(reg_a5)->unread_22 = 0;
    STAGE2_SHOT(reg_a5)->unread_24 = 2;
    STAGE2_SHOT(reg_a5)->unread_26 = 0x505;
    STAGE2_SHOT(reg_a5)->unread_2B = 0;
}


#ifndef DDPDOJ_PC
s32 enemy_remove();
s32 sprite_draw_layer5();
s32 entity_velocity();
#endif
s32 entity_check_bounds();
extern u16 stage2_boss_shoulder_bullet_buffer[];

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
        if (STAGE2_SHOT(reg_a5)->now.seen != 0) {
            enemy_remove();
            return;
        }
        goto block_7;
    }
    STAGE2_SHOT(reg_a5)->now.seen = 1U;
block_7:
    entity_velocity();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a2 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a2;
    reg_d1.w += 0xF800FC00;
    reg_d3.h[0] = 0x820;
    reg_d4.h[0] = 0x1A;
    reg_a0 = (u8 *)(stage2_boss_shoulder_bullet_buffer);
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

#ifndef DDPDOJ_PC
s32 enemy_init_entities();
#endif
extern u16 D_0024EBC0[];
extern u16 D_0024EC80[];
extern u16 D_0024EEF0[];
extern u16 stage2_boss_spread_bullet_start_table[];

void stage2_boss_spread_bullet_start(void) {
    reg_a0 = (u8 *)(stage2_boss_spread_bullet_start_table);
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) STAGE2_SHOT(reg_a5)->at_start.y;
    ENTITY(reg_a6)->x.h = (u16) STAGE2_SHOT(reg_a5)->at_start.x;
    ENTITY(reg_a6)->move.h = (u16) STAGE2_SHOT(reg_a5)->at_start.move;
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
    reg_a0 = (u8 *)(((u16 *)D_0024EBC0));
    STAGE2_SHOT(reg_a5)->now.frame_list[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    STAGE2_SHOT(reg_a5)->now.frame_list[1] = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    STAGE2_SHOT(reg_a5)->now.frame_timer.both = 2;
    STAGE2_SHOT(reg_a5)->frame = 0;
    STAGE2_SHOT(reg_a5)->now.seen = 0;
}

#ifndef DDPDOJ_PC
s32 entity_draw_with_bullets();
#endif
s32 entity_advance256();

void stage2_boss_spread_bullet(void) {
    reg_d1.w = 0x5C;
    if ((reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1]) != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        ENTITY(reg_a6)->hp.sh = 0x7FFF;
    }
    entity_advance256();
    if (0 > ENTITY(reg_a6)->y.sh) goto block_e1;
    if (ENTITY(reg_a6)->y.sh > 0x7000) goto block_e1;
    if (0 > ENTITY(reg_a6)->x.sh) goto block_e1;
    if (ENTITY(reg_a6)->x.sh > 0x3800) goto block_e1;
    goto block_l1;
block_e1:
    enemy_remove();
block_l1:
    reg_tmp.b[0] = STAGE2_SHOT(reg_a5)->now.frame_timer.b.countdown;
    STAGE2_SHOT(reg_a5)->now.frame_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STAGE2_SHOT(reg_a5)->now.frame_timer.b.countdown = (u8) STAGE2_SHOT(reg_a5)->now.frame_timer.b.interval;
        reg_tmp.h[1] = STAGE2_SHOT(reg_a5)->now.frame_list[0];
        reg_tmp.h[0] = STAGE2_SHOT(reg_a5)->now.frame_list[1];
        reg_a0 = (u8 *)(reg_tmp.w);
        reg_d0.h[0] = STAGE2_SHOT(reg_a5)->frame;
        ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        STAGE2_SHOT(reg_a5)->frame += 4;
        STAGE2_SHOT(reg_a5)->frame &= 0xF;
    }
    entity_draw_with_bullets();
}

void stage2_boss_cannon_shell_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

extern u8 stage2_boss_cannon_shell_start_table[];

void stage2_boss_cannon_shell_start(void) {
    reg_a0 = stage2_boss_cannon_shell_start_table;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) STAGE2_SHOT(reg_a5)->at_start.y;
    ENTITY(reg_a6)->x.h = (u16) STAGE2_SHOT(reg_a5)->at_start.x;
    ENTITY(reg_a6)->move.h = (u16) STAGE2_SHOT(reg_a5)->at_start.move;
    STAGE2_SHOT(reg_a5)->shot_timer.both = (u16) STAGE2_SHOT(reg_a5)->at_start.shot_timer;
    STAGE2_SHOT(reg_a5)->now.seen = 0;
    STAGE2_SHOT(reg_a5)->now.frame_timer.both = 2U;
    STAGE2_SHOT(reg_a5)->frame = 0;
    STAGE2_SHOT(reg_a5)->unread_24 = 0;
    STAGE2_SHOT(reg_a5)->unread_26 = 0x20;
    STAGE2_SHOT(reg_a5)->smoke_timer.both = 4;
    STAGE2_SHOT(reg_a5)->unread_2C = 0x10;
    ENTITY(reg_a6)->move.b.dir &= 0x3F;
    STAGE2_SHOT(reg_a5)->unread_31 = (u8) ENTITY(reg_a6)->move.h;
}

s32 explosion_spawn();
s32 entity_draw_layer5();
extern u8 stage2_boss_cannon_shell_table[];

void stage2_boss_cannon_shell(void) {
    entity_check_bounds();
    if (cond_flag != 0) {
        if (STAGE2_SHOT(reg_a5)->now.seen != 0) {
            enemy_remove();
            return;
        }
        goto block_4;
    }
    STAGE2_SHOT(reg_a5)->now.seen = 1U;
block_4:
    entity_velocity();
    reg_tmp.b[0] = STAGE2_SHOT(reg_a5)->smoke_timer.b.countdown;
    STAGE2_SHOT(reg_a5)->smoke_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STAGE2_SHOT(reg_a5)->smoke_timer.b.countdown = (u8) STAGE2_SHOT(reg_a5)->smoke_timer.b.interval;
        reg_d0.h[0] = 6;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
    }
    reg_tmp.b[0] = STAGE2_SHOT(reg_a5)->shot_timer.b.countdown;
    STAGE2_SHOT(reg_a5)->shot_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STAGE2_SHOT(reg_a5)->shot_timer.b.countdown = (u8) STAGE2_SHOT(reg_a5)->shot_timer.b.interval;
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
    reg_tmp.b[0] = STAGE2_SHOT(reg_a5)->now.frame_timer.b.countdown;
    STAGE2_SHOT(reg_a5)->now.frame_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STAGE2_SHOT(reg_a5)->now.frame_timer.b.countdown = (u8) STAGE2_SHOT(reg_a5)->now.frame_timer.b.interval;
        reg_a0 = stage2_boss_cannon_shell_table;
        reg_d0.h[0] = STAGE2_SHOT(reg_a5)->frame;
        ENTITY(reg_a6)->draw.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        STAGE2_SHOT(reg_a5)->frame += 4;
        STAGE2_SHOT(reg_a5)->frame &= 7;
    }
    entity_draw_layer5();
}

void stage2_boss_dropped_bomb_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 direction_to_target_player();
extern u8 stage2_boss_dropped_bomb_start_table[];

void stage2_boss_dropped_bomb_start(void) {
    reg_a0 = stage2_boss_dropped_bomb_start_table;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = STAGE2_SHOT(reg_a5)->at_start.y;
    ENTITY(reg_a6)->x.h = STAGE2_SHOT(reg_a5)->at_start.x;
    ENTITY(reg_a6)->move.h = STAGE2_SHOT(reg_a5)->at_start.move;
    direction_to_target_player();
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    STAGE2_SHOT(reg_a5)->now.seen = 0;
    STAGE2_SHOT(reg_a5)->now.frame_timer.both = 2;
    STAGE2_SHOT(reg_a5)->frame = 0;
}

s32 explosion_spawn();                            /* extern */

void stage2_boss_dropped_bomb(void) {
#ifndef DDPDOJ_PC
    extern s32 enemy_remove(u16);
#endif
    u16 temp_a0;

    reg_d0.h[0] = 3;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->x = temp_a0;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    ARCADE_REGISTER_CALL(enemy_remove, temp_a0);
}

void stage2_boss_ripple_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

#ifndef DDPDOJ_PC
s32 enemy_init_entities();                            /* extern */
#endif
extern s32 stage2_boss_ripple_start_table[];

void stage2_boss_ripple_start(void) {
    reg_a0 = (u8 *)stage2_boss_ripple_start_table;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) STAGE2_SHOT(reg_a5)->at_start.y;
    ENTITY(reg_a6)->x.h = (u16) STAGE2_SHOT(reg_a5)->at_start.x;
    STAGE2_SHOT(reg_a5)->now.seen = 0;
    STAGE2_SHOT(reg_a5)->now.frame_timer.both = 0x202;
    STAGE2_SHOT(reg_a5)->frame = 0;
}

#ifndef DDPDOJ_PC
s32 sprite_draw_layer1();
#endif
s32 entity_follow_scroll();
extern u32 stage2_boss_ripple_table[];

void stage2_boss_ripple(void) {
    u16 temp_a1;
    u16 temp_a2;

    entity_check_bounds();
    if (cond_flag != 0) {
        if (STAGE2_SHOT(reg_a5)->now.seen != 0) {
            enemy_remove();
            return;
        }
        goto block_4;
    }
    STAGE2_SHOT(reg_a5)->now.seen = 1U;
block_4:
    entity_velocity();
    entity_follow_scroll();
    reg_tmp.b[0] = STAGE2_SHOT(reg_a5)->now.frame_timer.b.countdown;
    STAGE2_SHOT(reg_a5)->now.frame_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STAGE2_SHOT(reg_a5)->now.frame_timer.b.countdown = (u8) STAGE2_SHOT(reg_a5)->now.frame_timer.b.interval;
        STAGE2_SHOT(reg_a5)->frame += 4;
        if (STAGE2_SHOT(reg_a5)->frame == 0x20) {
            enemy_remove();
            return;
        }
    }
    reg_a0 = (u8 *)(stage2_boss_ripple_table);
    temp_a2 = STAGE2_SHOT(reg_a5)->frame;
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

s32 stage2_boss_shoulder_bullet_start_table[8] = {
    0xFC008001, 0x0000FE00, 0x041001B8, 0x04000400, 0x02000200, 0x00007FFF, 0x0000001A, 0x00000000,
};

u16 stage2_boss_spread_bullet_start_table[16] = {
    0x8001, 0xFE00, 0xFE00, 0x0000, 0x0000, 0x0210, 0x0200, 0x0200,
    0x0100, 0x0100, 0x7FFF, 0x0000, 0x001A, 0x0000, 0x0000, 0x0000,
};

u8 stage2_boss_cannon_shell_start_table[32] = {
    0x00, 0x80, 0x00, 0xFC, 0x00, 0xFE, 0x00, 0x00, 0xB8, 0x01, 0x10, 0x04, 0x00, 0x04, 0x00, 0x04,
    0x00, 0x02, 0x00, 0x02, 0xFF, 0x7F, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage2_boss_dropped_bomb_start_table[32] = {
    0x01, 0xA0, 0x00, 0xFC, 0x00, 0xFE, 0x00, 0x00, 0xB8, 0x01, 0x10, 0x04, 0x00, 0x04, 0x00, 0x04,
    0x00, 0x02, 0x00, 0x02, 0xFF, 0x7F, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

s32 stage2_boss_ripple_start_table[8] = {
    0xFC008000, 0x0000FE00, 0x041001B8, 0x04000400, 0x02000200, 0x00007FFF, 0x0000001A, 0x00000000,
};

u32 stage2_boss_ripple_table[8] = {
    0x00001B76, 0x00001B77, 0x00001B78, 0x00001B79, 0x00001B7A, 0x00001B7B, 0x00001B7C, 0x00001B7D,
};

u8 stage2_boss_cannon_shell_table[8] = {
    0xB8, 0x01, 0x00, 0x00, 0xB7, 0x01, 0x00, 0x00,
};

/* .sbss (the compiler lays these out in reverse) */
u16 stage2_boss_shoulder_bullet_buffer[2];
