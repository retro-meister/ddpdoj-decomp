#include "common.h"
#include "entity.h"
#include "enemy.h"

/*
 * The drone the stage 3 boss launches, and what flies off its lid. The boss leaves the drone's position and its
 * drawing attributes in the first words of the request. The drone unfolds, then flies on and fires bursts toward
 * the player from its two muzzles in turn, getting faster.
 */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct { u16 y; u16 x; u16 attr; } at_start;
        struct { u8 unused_16; u8 seen; u16 unfolded; u16 unused_1A; } now;
    };
    /* 0x1C */ u8 hit_flash;
    /* 0x1D */ u8 palette;
    /* 0x1E */ u8 pause;              /* frames between two bursts */
    /* 0x1F */ u8 wait;
    /* 0x20 */ u8 burst_shots;
    /* 0x21 */ u8 burst_shots_left;
    /* 0x22 */ u8 unused_22;
    /* 0x23 */ u8 shot_interval;
    /* 0x24 */ EnemyTimer accel;      /* frames between two steps of its speed */
    /* 0x26 */ u16 muzzle;            /* offset of the next pair of muzzles in their table */
    /* 0x28 */ EnemyTimer unfold_timer;
    /* 0x2A */ u16 unfold_frame;
    /* 0x2C */ EnemyTimer spin_timer;
    /* 0x2E */ u16 spin_frame;
    /* 0x30 */ u16 bullet_speed;
    /* 0x32 */ u16 bullet;
    /* 0x34 */ u16 move;              /* direction and speed it takes once unfolded */
    /* 0x36 */ u8 unused_36;
    /* 0x37 */ u8 start_wait;         /* added to the first wait */
} Stage3BossDroneState;

typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 unused_16;
    /* 0x17 */ u8 seen;
    /* 0x18 */ EnemyTimer frame_timer;
    /* 0x1A */ u16 frame;
} LidBulletState;

#define BOSS_DRONE(pointer) ((Stage3BossDroneState *)(pointer))
#define LID_BULLET(pointer) ((LidBulletState *)(pointer))

void stage3_boss_drone(void);
void stage3_boss_lid_bullet_draw(void);
void breakable_bullet_check(void);

void stage3_boss_drone_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(1);
}

s32 enemy_set_task_state();
s32 enemy_init_entities();
s32 func_001713C0();
extern u8 D_0026D5C0[];
extern u8 D_0026D5E0[];
extern u8 D_0026D600[];
extern u32 D_0028DC10;
extern u16 g_loop;

void stage3_boss_drone_start(void) {
    s32 temp_a0_2;
    u16 temp_a0;

    reg_a0 = D_0026D600;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) BOSS_DRONE(reg_a5)->at_start.y;
    ENTITY(reg_a6)->x.h = (u16) BOSS_DRONE(reg_a5)->at_start.x;
    temp_a0 = BOSS_DRONE(reg_a5)->at_start.attr;
    ENTITY(reg_a6)->attr.h = temp_a0;
    reg_a0 = D_0026D5E0;
    reg_d0.w = ((u32) D_0028DC10 >> 1) - 1;
    enemy_set_task_state();
    reg_d0.b[0] = BOSS_DRONE(reg_a5)->start_wait;
    BOSS_DRONE(reg_a5)->wait += reg_d0.b[0];
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a0_2 = reg_d0.h[0] & ~3;
    reg_a0 = *(u8 **)((u8 *)D_0026D5C0 + temp_a0_2);
    BOSS_DRONE(reg_a5)->wait = (u8) *(u8 *)(reg_a0 + 1);
    BOSS_DRONE(reg_a5)->pause = (u8) *(u8 *)reg_a0;
    reg_a0 += 2;
    BOSS_DRONE(reg_a5)->shot_interval = (u8) *(u8 *)(reg_a0 + 1);
    BOSS_DRONE(reg_a5)->accel.b.interval = (u8) *(u8 *)reg_a0;
    reg_a0 += 2;
    BOSS_DRONE(reg_a5)->bullet_speed = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->hp.h = (u16) *(u16 *)reg_a0;
    ENTITY(reg_a6)[1].hp.h = (u16) *(u16 *)reg_a0;
    if (g_loop == 0) {
        stage3_boss_drone();
        return;
    }
    BOSS_DRONE(reg_a5)->shot_interval = 0xDU;
    BOSS_DRONE(reg_a5)->bullet_speed = 1U;
    stage3_boss_drone();
}


s32 bullet_fire256_fixed();
s32 explosion_spawn();
s32 enemy_hitbox_debug_draw();
s32 sfx_explosion_air_large();
s32 entity_draw_layer5();
s32 func_00201F20();
s32 aim256_at_player();
extern u8 D_0026D360[];
extern u8 D_0026D640[];
extern u8 D_0026D660[];
extern u8 g_boss_present_b1;
extern u16 g_bullets_blocked;
extern u16 g_enemies_stopped;
extern u16 g_damage_blink_counter;

void stage3_boss_drone(void) {
    s32 enemy_remove();
    u8 bits;
    u16 hp;

    bits = ENTITY(reg_a6)->misc.b.user;
    if (bits == 0) goto next_20;
    ENTITY(reg_a6)->misc.b.user = bits - 1;
next_20:
    if (g_boss_present_b1 & 0x40) goto block_dead;
    func_00201F20();
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x7000;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x1000;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x7000;
    if (reg_tmp.h[1] == 0) goto next_lim;
    if (BOSS_DRONE(reg_a5)->now.seen == 0) goto next_lim_end;
    enemy_remove();
    return;
next_lim:
    BOSS_DRONE(reg_a5)->now.seen = 1;
next_lim_end:
    ENTITY(reg_a6)[1].y.h = ENTITY(reg_a6)->y.h;
    ENTITY(reg_a6)[1].x.h = ENTITY(reg_a6)->x.h;
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[1].flags.b[1];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) goto next_50;
    reg_d0.b[0] = BOSS_DRONE(reg_a5)->palette;
    if ((s32)ENTITY(reg_a6)->hp.h >= 0x180) goto next_90;
    if (g_damage_blink_counter != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    reg_d0.h[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)->misc.b.user = 2;
    reg_d2.w = 1;
    if (!(reg_d1.w & 4)) goto next_53;
    reg_d2.w = 2;
next_53:
    ENTITY(reg_a6)->move.b.speed -= reg_d2.b[0];
    if (ENTITY(reg_a6)->move.sb.speed >= 3) goto next_55;
    ENTITY(reg_a6)->move.b.speed = 3;
next_55:
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    if (reg_d0.b[0] != 0x19) goto next_60;
    reg_d0.b[0] = BOSS_DRONE(reg_a5)->palette;
next_60:
    reg_d2.b[0] = BOSS_DRONE(reg_a5)->hit_flash;
    reg_d0.b[0] ^= reg_d2.b[0];
    reg_d4.h[0] = ENTITY(reg_a6)->hp.h;
    hp = ENTITY(reg_a6)[1].hp.h;
    if (!((s16)hp < (s16)reg_d4.h[0])) goto next_80;
    reg_d4.h[0] = hp;
next_80:
    ENTITY(reg_a6)->hp.h = reg_d4.h[0];
    ENTITY(reg_a6)[1].hp.h = reg_d4.h[0];
    if (ENTITY(reg_a6)->hp.sh < 0) goto block_dead;
next_90:
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    if (BOSS_DRONE(reg_a5)->now.unfolded == 0) goto next_200;
next_100:
    reg_tmp.b[0] = BOSS_DRONE(reg_a5)->spin_timer.b.countdown;
    BOSS_DRONE(reg_a5)->spin_timer.b.countdown -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_120;
    BOSS_DRONE(reg_a5)->spin_timer.b.countdown = BOSS_DRONE(reg_a5)->spin_timer.b.interval;
    reg_a0 = (u8 *)D_0026D640;
    reg_d0.h[0] = BOSS_DRONE(reg_a5)->spin_frame;
    reg_tmp.w = *(u32 *)(D_0026D640 + (reg_d0.h[0] & ~3));
    ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
    reg_tmp.h[0] = BOSS_DRONE(reg_a5)->spin_frame;
    BOSS_DRONE(reg_a5)->spin_frame -= 4;
    if ((s32)reg_tmp.h[0] >= 4) goto next_120;
    BOSS_DRONE(reg_a5)->spin_frame = 0x1C;
next_120:
    reg_tmp.b[0] = BOSS_DRONE(reg_a5)->accel.b.countdown;
    BOSS_DRONE(reg_a5)->accel.b.countdown -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto block_objset;
    BOSS_DRONE(reg_a5)->accel.b.countdown = BOSS_DRONE(reg_a5)->accel.b.interval;
    bits = ENTITY(reg_a6)->move.b.speed;
    if ((s8)bits >= 0x12) goto block_objset;
    ENTITY(reg_a6)->move.b.speed += 1;
    goto block_objset;
next_200:
    reg_tmp.b[0] = BOSS_DRONE(reg_a5)->unfold_timer.b.countdown;
    BOSS_DRONE(reg_a5)->unfold_timer.b.countdown -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto block_objset;
    BOSS_DRONE(reg_a5)->unfold_timer.b.countdown = BOSS_DRONE(reg_a5)->unfold_timer.b.interval;
    reg_a0 = (u8 *)D_0026D360;
    reg_d0.h[0] = BOSS_DRONE(reg_a5)->unfold_frame;
    reg_tmp.w = *(u32 *)(D_0026D360 + (reg_d0.h[0] & ~3));
    ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
    BOSS_DRONE(reg_a5)->unfold_frame += 4;
    if (BOSS_DRONE(reg_a5)->unfold_frame != 0x20) goto block_objset;
    reg_tmp.w = 0xEE00FC00;
    ENTITY(reg_a6)->offset_y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = reg_tmp.h[0];
    ENTITY(reg_a6)->look.h = 0x1220;
    ENTITY(reg_a6)->move.h = BOSS_DRONE(reg_a5)->move;
    BOSS_DRONE(reg_a5)->now.unfolded = 1;
    goto next_100;
block_objset:
    entity_draw_layer5();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x20;
    enemy_hitbox_debug_draw();
    if (BOSS_DRONE(reg_a5)->now.unfolded == 0) return;
    if (g_enemies_stopped != 0) return;
    if (g_bullets_blocked != 0) return;
    if (ENTITY(reg_a6)->y.sh < 0x1200) return;
    reg_tmp.b[0] = BOSS_DRONE(reg_a5)->wait;
    BOSS_DRONE(reg_a5)->wait -= 1;
    switch (reg_tmp.b[0]) { case 0: goto next_600; }
    return;
next_600:
    BOSS_DRONE(reg_a5)->wait = BOSS_DRONE(reg_a5)->shot_interval;
    reg_a4 = (u8 *)D_0026D660;
    reg_a4 += BOSS_DRONE(reg_a5)->muzzle;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] += *(u16 *)(reg_a4 + 4);
    aim256_at_player();
    if (cond_flag != 0) goto next_660;
    reg_d0.h[1] = BOSS_DRONE(reg_a5)->bullet_speed;
    reg_d0.h[0] = BOSS_DRONE(reg_a5)->bullet;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.w = 0;
    reg_d5.h[0] = *(u16 *)reg_a4;
    reg_a4 += 2;
    reg_d3.h[1] = *(u16 *)reg_a4;
    reg_a4 += 2;
    reg_d3.h[0] = *(u16 *)reg_a4;
    reg_a4 += 2;
    bullet_fire256_fixed();
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] += *(u16 *)(reg_a4 + 4);
    aim256_at_player();
    reg_d0.h[1] = BOSS_DRONE(reg_a5)->bullet_speed;
    reg_d0.h[0] = BOSS_DRONE(reg_a5)->bullet;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.w = 0;
    reg_d5.h[0] = *(u16 *)reg_a4;
    reg_a4 += 2;
    reg_d3.h[1] = *(u16 *)reg_a4;
    reg_a4 += 2;
    reg_d3.h[0] = *(u16 *)reg_a4;
    reg_a4 += 2;
    bullet_fire256_fixed();
next_660:
    reg_tmp.h[0] = BOSS_DRONE(reg_a5)->muzzle;
    BOSS_DRONE(reg_a5)->muzzle -= 0xC;
    if ((s32)reg_tmp.h[0] >= 0xC) goto next_670;
    BOSS_DRONE(reg_a5)->muzzle = 0x60;
next_670:
    reg_tmp.b[0] = BOSS_DRONE(reg_a5)->burst_shots_left;
    BOSS_DRONE(reg_a5)->burst_shots_left -= 1;
    if ((s32)reg_tmp.b[0] > 0) return;
    BOSS_DRONE(reg_a5)->burst_shots_left = BOSS_DRONE(reg_a5)->burst_shots;
    BOSS_DRONE(reg_a5)->wait = BOSS_DRONE(reg_a5)->pause;
    bits = ENTITY(reg_a6)->flags.b[0];
    if (bits & 0x40) goto next_680;
    ENTITY(reg_a6)->flags.b[0] = bits | 0x40;
    goto next_690;
next_680:
    ENTITY(reg_a6)->flags.b[0] = bits & 0xBF;
    BOSS_DRONE(reg_a5)->wait = BOSS_DRONE(reg_a5)->shot_interval;
next_690:
    return;
block_dead:
    reg_d0.h[0] = 0xA;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0xC;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x1A) = ENTITY(reg_a6)->move.h;
    *(s16 *)(reg_a0 + 0x26) = 0x600;
    *(s16 *)(reg_a0 + 0x28) = 0;
    *(s16 *)(reg_a0 + 0x18) = 4;
    reg_d0.h[0] = 0xA;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0xC;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x1A) = ENTITY(reg_a6)->move.h;
    *(s16 *)(reg_a0 + 0x26) = 0;
    *(s16 *)(reg_a0 + 0x28) = 0;
    *(s16 *)(reg_a0 + 0x18) = 2;
    reg_d0.h[0] = 0xA;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0xC;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x1A) = ENTITY(reg_a6)->move.h;
    *(u16 *)(reg_a0 + 0x26) = 0xFA00;
    *(s16 *)(reg_a0 + 0x28) = 0;
    *(s16 *)(reg_a0 + 0x18) = 0;
    sfx_explosion_air_large();
    enemy_remove();
}

void stage3_boss_lid_bullet_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

void stage3_boss_lid_bullet_start(void) {
    void enemy_remove(void);
    enemy_remove();
}


void stage3_boss_lid_bullet_fade(void) {
    s32 enemy_remove();
    reg_tmp.h[1] = ENTITY(reg_a6)->draw.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->sprite.h;
    reg_tmp.w += 1;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->hit_y_plus.h -= 1;
    if (ENTITY(reg_a6)->hit_y_plus.h != 0) {
        stage3_boss_lid_bullet_draw();
        return;
    }
    enemy_remove();
}

void stage3_boss_lid_bullet_draw(void) {
    void entity_draw_with_bullets(void);
    entity_draw_with_bullets();
}

extern u8 D_0026D7B0[];

void stage3_boss_lid_bullet(void) {
    s32 enemy_remove();
    s32 entity_draw_with_bullets();
    u32 var_a0;

    if (ENTITY(reg_a6)->flags.sb[0] < 0) {
        stage3_boss_lid_bullet_fade();
        return;
    }
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    breakable_bullet_check();
    if (cond_flag != 0) {
        if (ENTITY(reg_a6)->flags.sb[0] < 0) {
            ENTITY(reg_a6)->flags.b[1] = 0x80U;
            reg_tmp.w = 0x24F;
            ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
            ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
            ENTITY(reg_a6)->look.sh = 0x410;
            reg_tmp.w = 0xFC00FE00;
            ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
            ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
            ENTITY(reg_a6)->hit_y_plus.sh = 0x10;
            stage3_boss_lid_bullet_draw();
            return;
        }
        enemy_remove();
        return;
    }
    func_00201F20();
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xFFC6;
    reg_d0.h[0] += 0x400;
    reg_tmp.w = (u32) reg_d0.h[0];
    var_a0 = reg_tmp.w;
    reg_tmp.w = var_a0 + reg_tmp1.w;
    reg_d0.h[0] += 0x7FFF + 0x7FC7;
    if (reg_tmp.h[1] != 0) {
        if (LID_BULLET(reg_a5)->seen != 0) {
            enemy_remove();
            return;
        }
        goto block_10;
    }
    LID_BULLET(reg_a5)->seen = 1U;
block_10:
    reg_tmp.b[0] = LID_BULLET(reg_a5)->frame_timer.b.countdown;
    LID_BULLET(reg_a5)->frame_timer.b.countdown -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        LID_BULLET(reg_a5)->frame_timer.b.countdown = (u8) LID_BULLET(reg_a5)->frame_timer.b.interval;
        reg_a0 = (u8 *)D_0026D7B0;
        reg_d0.h[0] = LID_BULLET(reg_a5)->frame;
        var_a0 = (u32) reg_d0.h[0];
        reg_tmp.w = *(u32 *)(D_0026D7B0 + (var_a0 & ~3));
        ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
        reg_tmp.h[0] = LID_BULLET(reg_a5)->frame;
        LID_BULLET(reg_a5)->frame -= 4;
        if ((s32) reg_tmp.h[0] < 4) {
            LID_BULLET(reg_a5)->frame = 0xCU;
        }
    }
    entity_draw_with_bullets();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x20;
    enemy_hitbox_debug_draw();
}

s32 func_00125EE0();
extern u16 g_boss_present_as_u16;
extern u16 D_00299764[];
extern u16 D_00299766[];
extern u16 g_bomb_entities[];

void breakable_bullet_check(void) {
    u32 temp_v1;

    reg_d0.h[0] = g_bomb_entities[0];
    reg_d0.h[0] |= g_boss_present_as_u16;
    if ((s16) reg_d0.h[0] < 0) {
        reg_d0.h[0] = g_bomb_entities[0];
        if ((g_bomb_entities[0] & 0xFFFF) && (reg_d0.w & 1)) {
            temp_v1 = reg_d1.b[0] & 0x5C;
            reg_d1.b[0] = temp_v1;
            if (!(temp_v1 & 0xFF)) {
                if ((s16)(g_boss_present_as_u16) < 0) {
                    goto block_5;
                }
                goto block_6;
            }
            goto block_11;
        }
block_5:
        reg_d0.w = 0;
        goto block_9;
    }
block_6:
    if (D_00299764[0] != 0) {
        reg_d0.h[0] = D_00299766[0];
        if ((s16) reg_d0.h[0] < 0) {
            *reg_a6 = 0x80;
        } else {
block_9:
            func_00125EE0();
        }
block_11:
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}
