#include "common.h"
#include "entity.h"

void func_001D1C00(void);
void func_001D2550(void);
void func_001D27A0(void);

void func_001D1A50(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(1);
}

s32 enemy_set_task_work();
s32 enemy_init_entities();
s32 func_001713C0();
extern u8 D_0026D5C0[];
extern u8 D_0026D5E0[];
extern u8 D_0026D600[];
extern u32 D_0028DC10;
extern u16 g_loop;

void func_001D1A60(void) {
    s32 temp_a0_2;
    u16 temp_a0;

    reg_a0 = D_0026D600;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    ENTITY(reg_a6)->x.h = (u16) *(u16 *)(reg_a5 + 0x18);
    temp_a0 = *(u16 *)(reg_a5 + 0x1A);
    ENTITY(reg_a6)->attr.h = temp_a0;
    reg_a0 = D_0026D5E0;
    reg_d0.w = ((u32) D_0028DC10 >> 1) - 1;
    enemy_set_task_work();
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x37);
    *(u8 *)(reg_a5 + 0x1F) += reg_d0.b[0];
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a0_2 = reg_d0.h[0] & ~3;
    reg_a0 = *(u8 **)((u8 *)D_0026D5C0 + temp_a0_2);
    *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a0 + 1);
    *(u8 *)(reg_a5 + 0x1E) = (u8) *(u8 *)reg_a0;
    reg_a0 += 2;
    *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a0 + 1);
    *(u8 *)(reg_a5 + 0x24) = (u8) *(u8 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a5 + 0x30) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->hp.h = (u16) *(u16 *)reg_a0;
    ENTITY(reg_a6)[1].hp.h = (u16) *(u16 *)reg_a0;
    if (g_loop == 0) {
        func_001D1C00();
        return;
    }
    *(u8 *)(reg_a5 + 0x23) = 0xDU;
    *(u16 *)(reg_a5 + 0x30) = 1U;
    func_001D1C00();
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

void func_001D1C00(void) {
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
    if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_lim_end;
    enemy_remove();
    return;
next_lim:
    *(u8 *)(reg_a5 + 0x17) = 1;
next_lim_end:
    ENTITY(reg_a6)[1].y.h = ENTITY(reg_a6)->y.h;
    ENTITY(reg_a6)[1].x.h = ENTITY(reg_a6)->x.h;
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[1].flags.b[1];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) goto next_50;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
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
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
next_60:
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1C);
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
    if (*(u16 *)(reg_a5 + 0x18) == 0) goto next_200;
next_100:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x2D);
    *(u8 *)(reg_a5 + 0x2D) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_120;
    *(u8 *)(reg_a5 + 0x2D) = *(u8 *)(reg_a5 + 0x2C);
    reg_a0 = (u8 *)D_0026D640;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2E);
    reg_tmp.w = *(u32 *)(D_0026D640 + (reg_d0.h[0] & ~3));
    ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x2E);
    *(u16 *)(reg_a5 + 0x2E) -= 4;
    if ((s32)reg_tmp.h[0] >= 4) goto next_120;
    *(u16 *)(reg_a5 + 0x2E) = 0x1C;
next_120:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
    *(u8 *)(reg_a5 + 0x25) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto block_objset;
    *(u8 *)(reg_a5 + 0x25) = *(u8 *)(reg_a5 + 0x24);
    bits = ENTITY(reg_a6)->move.b.speed;
    if ((s8)bits >= 0x12) goto block_objset;
    ENTITY(reg_a6)->move.b.speed += 1;
    goto block_objset;
next_200:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x29);
    *(u8 *)(reg_a5 + 0x29) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto block_objset;
    *(u8 *)(reg_a5 + 0x29) = *(u8 *)(reg_a5 + 0x28);
    reg_a0 = (u8 *)D_0026D360;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2A);
    reg_tmp.w = *(u32 *)(D_0026D360 + (reg_d0.h[0] & ~3));
    ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
    *(u16 *)(reg_a5 + 0x2A) += 4;
    if (*(u16 *)(reg_a5 + 0x2A) != 0x20) goto block_objset;
    reg_tmp.w = 0xEE00FC00;
    ENTITY(reg_a6)->offset_y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = reg_tmp.h[0];
    ENTITY(reg_a6)->look.h = 0x1220;
    ENTITY(reg_a6)->move.h = *(u16 *)(reg_a5 + 0x34);
    *(u16 *)(reg_a5 + 0x18) = 1;
    goto next_100;
block_objset:
    entity_draw_layer5();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x20;
    enemy_hitbox_debug_draw();
    if (*(u16 *)(reg_a5 + 0x18) == 0) return;
    if (g_enemies_stopped != 0) return;
    if (g_bullets_blocked != 0) return;
    if (ENTITY(reg_a6)->y.sh < 0x1200) return;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    switch (reg_tmp.b[0]) { case 0: goto next_600; }
    return;
next_600:
    *(u8 *)(reg_a5 + 0x1F) = *(u8 *)(reg_a5 + 0x23);
    reg_a4 = (u8 *)D_0026D660;
    reg_a4 += *(u16 *)(reg_a5 + 0x26);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] += *(u16 *)(reg_a4 + 4);
    aim256_at_player();
    if (cond_flag != 0) goto next_660;
    reg_d0.h[1] = *(u16 *)(reg_a5 + 0x30);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x32);
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
    reg_d0.h[1] = *(u16 *)(reg_a5 + 0x30);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x32);
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
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x26);
    *(u16 *)(reg_a5 + 0x26) -= 0xC;
    if ((s32)reg_tmp.h[0] >= 0xC) goto next_670;
    *(u16 *)(reg_a5 + 0x26) = 0x60;
next_670:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
    *(u8 *)(reg_a5 + 0x21) -= 1;
    if ((s32)reg_tmp.b[0] > 0) return;
    *(u8 *)(reg_a5 + 0x21) = *(u8 *)(reg_a5 + 0x20);
    *(u8 *)(reg_a5 + 0x1F) = *(u8 *)(reg_a5 + 0x1E);
    bits = ENTITY(reg_a6)->flags.b[0];
    if (bits & 0x40) goto next_680;
    ENTITY(reg_a6)->flags.b[0] = bits | 0x40;
    goto next_690;
next_680:
    ENTITY(reg_a6)->flags.b[0] = bits & 0xBF;
    *(u8 *)(reg_a5 + 0x1F) = *(u8 *)(reg_a5 + 0x23);
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

void func_001D24B0(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

void func_001D24C0(void) {
    void enemy_remove(void);
    enemy_remove();
}


void func_001D24D0(void) {
    s32 enemy_remove();
    reg_tmp.h[1] = ENTITY(reg_a6)->draw.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->sprite.h;
    reg_tmp.w += 1;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->hit_y_plus.h -= 1;
    if (ENTITY(reg_a6)->hit_y_plus.h != 0) {
        func_001D2550();
        return;
    }
    enemy_remove();
}

void func_001D2550(void) {
    void entity_draw_with_bullets(void);
    entity_draw_with_bullets();
}

extern u8 D_0026D7B0[];

void func_001D2560(void) {
    s32 enemy_remove();
    s32 entity_draw_with_bullets();
    u32 var_a0;

    if (ENTITY(reg_a6)->flags.sb[0] < 0) {
        func_001D24D0();
        return;
    }
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    func_001D27A0();
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
            func_001D2550();
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
        if (*(u8 *)(reg_a5 + 0x17) != 0) {
            enemy_remove();
            return;
        }
        goto block_10;
    }
    *(u8 *)(reg_a5 + 0x17) = 1U;
block_10:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x19);
    *(u8 *)(reg_a5 + 0x19) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a5 + 0x19) = (u8) *(u8 *)(reg_a5 + 0x18);
        reg_a0 = (u8 *)D_0026D7B0;
        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1A);
        var_a0 = (u32) reg_d0.h[0];
        reg_tmp.w = *(u32 *)(D_0026D7B0 + (var_a0 & ~3));
        ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1A);
        *(u16 *)(reg_a5 + 0x1A) -= 4;
        if ((s32) reg_tmp.h[0] < 4) {
            *(u16 *)(reg_a5 + 0x1A) = 0xCU;
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
extern u16 D_0029CEA0[];

void func_001D27A0(void) {
    u32 temp_v1;

    reg_d0.h[0] = D_0029CEA0[0];
    reg_d0.h[0] |= g_boss_present_as_u16;
    if ((s16) reg_d0.h[0] < 0) {
        reg_d0.h[0] = D_0029CEA0[0];
        if ((D_0029CEA0[0] & 0xFFFF) && (reg_d0.w & 1)) {
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
