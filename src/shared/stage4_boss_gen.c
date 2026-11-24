#include "common.h"
#include "entity.h"

void func_001E0B30(void);
void func_001E0C20(void);
void func_001E1F30(void);
void func_001E3D60(void);
void func_001E4410(void);
void func_001E4460(void);
void func_001E4490(void);
void func_001E44F0(void);
void func_001E4520(void);


void func_001DE1F0(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(1);
}

s32 enemy_set_task_work();
s32 enemy_init_entities();
s32 enemy_path_start();
s32 sprite_palette_load();
extern u8 D_00261870[];
extern u8 D_002637B0[];
extern u8 D_0028D9AC;
extern u16 g_scroll_line;
extern u16 D_0029C068[];
extern s8 enemy_move_end_requested;

void func_001DE200(void) {

    reg_a0 = D_002637B0;
    enemy_init_entities();
    reg_a0 = &D_0028D9AC;
    reg_d0.w = 1;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        *(u16 *)(reg_a6 + 0x22) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a6 + 0x24) = (u16) ENTITY(reg_a6)->x.h;
        ENTITY(reg_a6)->x.h += 0x1600;
        *(u16 *)(reg_a6 + 0x24) += 0x7FFF + 0x7801;
        reg_d0.h[0] = D_0029C068[0];
        *(u16 *)(reg_a6 + 0x24) -= reg_d0.h[0];
        reg_a0 = D_00261870;
        reg_d0.h[0] = 0x16;
        if (g_scroll_line == 0x19) {
            reg_d0.h[0] = 0x14;
        }
        sprite_palette_load();
    }
}

s32 enemy_hitbox_debug_draw();
s32 enemy_remove();
s32 func_0014EA50();
s32 func_0019BF00();
s32 func_001A9000();
extern u16 g_enemies_stopped;
extern u16 D_0029C06C[];

void func_001DE2E0(void) {
    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x5000;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x2000;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x5000;
        if (reg_tmp.h[1] != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                enemy_remove();
                return;
            }
            goto block_5;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
block_5:
        *(u16 *)(reg_a6 + 0x22) = (u16) ENTITY(reg_a6)->y.h;
        reg_d0.h[0] = D_0029C06C[0];
        *(u16 *)(reg_a6 + 0x24) -= reg_d0.h[0];
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        reg_d1.b[0] |= *(u8 *)(reg_a6 + 0x21);
        reg_d1.h[0] &= 0x5C;
        if (reg_d1.h[0] != 0) {
            reg_d0.h[0] = 0xA3;
            ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
            *(u8 *)(reg_a6 + 0x21) &= reg_d0.b[0];
            func_001A9000();
            reg_d0.h[0] = 0x7FFF;
            ENTITY(reg_a6)->hp.h = (u16) reg_d0.h[0];
            *(u16 *)(reg_a6 + 0x38) = (u16) reg_d0.h[0];
        }
        if (g_enemies_stopped == 0) {
            reg_a0 = reg_a6;
            enemy_hitbox_debug_draw();
            reg_a0 = reg_a6 + 0x20;
            enemy_hitbox_debug_draw();
            if (*(u8 *)(reg_a6 + 0x1F) != 0) {
                reg_d0.h[0] = 0x40;
                ENTITY(reg_a6)->x.h += reg_d0.h[0];
                *(u16 *)(reg_a6 + 0x24) -= reg_d0.h[0];
                *(u16 *)(reg_a5 + 0x18) += reg_d0.h[0];
                if ((s32) *(u16 *)(reg_a5 + 0x18) >= 0x2A80) {
                    enemy_remove();
                    return;
                }
            }
        }
        func_0019BF00();
        if ((s32) *(u16 *)(reg_a5 + 0x18) < 0x2680) {
            reg_a6 += 0x20;
            func_0019BF00();
        }
    }
}

void func_001DE500(void) {
    void enemy_set_entity_count(s32 id);
    enemy_set_entity_count(10);
}

typedef void (*Fn)();

extern u8 D_00261730[];
extern u8 D_00263840[];
extern u8 D_00263860[];
s32 func_00119B10();
s32 func_0011AD50();
s32 enemy_init_entities_n();
s32 rng_next_unsigned();
extern u8 D_002637F0[];
extern u8 D_00263810[];
extern void (*jtbl_0028E3F4)();

void func_001DE510(void) {
    reg_a0 = (u8 *)D_00263860;
    reg_d7.w = 0;
    enemy_init_entities_n();
    reg_a0 = (u8 *)D_00263840;
    reg_d0.w = 0xB;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested != 0) {
        return;
    }
    ENTITY(reg_a6)->y.h -= 0x1440;
    ENTITY(reg_a6)->x.h -= 0x1D40;
    reg_a0 = (u8 *)D_00261730;
    reg_d0.h[0] = 0x17;
    sprite_palette_load();
    rng_next_unsigned();
    if ((s8) reg_d0.b[0] < 0) {
        ENTITY(reg_a6)->flags.b[0] |= 0x40;
    }
    reg_d7.w = 4;
    reg_a0 = (u8 *)func_0011AD50;
    reg_a3 = (u8 *)D_002637F0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1E);
    if ((s8) reg_d0.b[0] < 0) {
        *(u8 *)(reg_a6 + 0x1E) = (u8) ~(s8) *(u8 *)(reg_a6 + 0x1E);
        *(s8 *)(reg_a6 + 0x1D) = 0x40;
        *(u16 *)(reg_a5 + 0x1A) *= (0xFFFF & 0xFFFF);
        *(u16 *)(reg_a5 + 0x2C) *= 0xFFFF;
        *(u8 *)(reg_a5 + 0x2A) *= -1;
        ENTITY(reg_a6)->x.h += 0x3A80;
        *(u16 *)(reg_a5 + 4) -= 6;
        *(s16 *)(reg_a6 + 0xA0) = 0;
        *(s16 *)(reg_a6 + 0xC0) = 0;
        *(s16 *)(reg_a6 + 0xE0) = 0;
        *(s16 *)(reg_a6 + 0x100) = 0;
        *(s16 *)(reg_a6 + 0x120) = 0;
        *(s16 *)(reg_a6 + 0x140) = 0;
        reg_d7.w = 1;
        reg_a0 = (u8 *)func_00119B10;
        reg_a3 = (u8 *)D_00263810;
    }
    reg_a6 += 0x20;
    do {
        jtbl_0028E3F4 = (Fn)(reg_a0);
        jtbl_0028E3F4();
        reg_a6 += 0x40;
        reg_a3 += 6;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern u8 D_00259870_as_u8_a[];
extern u8 D_00263880[];
s32 func_00119FE0();
s32 func_0011B220();
s32 bullet_fire256_2way();
s32 explosion_spawn();
s32 func_0018D580();
s32 func_0019BF40();
s32 func_001A91A0();
extern u16 D_0028E8B8;

void func_001DE720(void) {
    u32 saved;
    u8 bits;

    func_0014EA50();
    if (enemy_move_end_requested != 0) goto block_rts;
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp1.w = 0;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x1C00;
    reg_d0.h[0] += D_0029C068[0];
    reg_tmp1.h[0] = 0x9000;
    reg_tmp.h[0] = reg_d0.h[0];
    saved = reg_tmp.w;
    reg_tmp.w = saved + reg_tmp1.w;
    reg_d0.h[0] += 0x7FFF + 0x1001;
    if (reg_tmp.h[1] != 0) goto next_20;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x5C00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    saved = reg_tmp.h[0];
    reg_d0.h[0] += 0x1A00;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x5C00;
    reg_d0.h[1] = saved;
    switch (reg_tmp.h[1]) { case 0: goto next_30; }
next_20:
    if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_40;
    enemy_remove();
    return;
next_30:
    *(u8 *)(reg_a5 + 0x17) = 1;
next_40:
    if (ENTITY(reg_a6)->flags.sb[0] < 0) goto block_explos;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) goto next_50;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x23);
    if ((s32)ENTITY(reg_a6)->hp.h >= 0x480) goto next_90;
    if (D_0028E8B8 != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    if (reg_d0.b[0] != 0x19) goto next_60;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x23);
next_60:
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x22);
    reg_d0.b[0] ^= reg_d2.b[0];
    if (ENTITY(reg_a6)->hp.sh < 0) goto block_dead;
next_90:
    *(u8 *)(reg_a6 + 0x1C) = reg_d0.b[0];
    if (g_enemies_stopped != 0) goto block_objset;
    if (ENTITY(reg_a6)->y.sh < 0x800) goto next_200;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x27);
    *(u8 *)(reg_a5 + 0x27) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_200;
    *(u8 *)(reg_a5 + 0x27) = *(u8 *)(reg_a5 + 0x2B);
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d5.h[0] = 0x600;
    reg_tmp5.h[0] = reg_d5.h[0];
    reg_d5.h[0] = reg_d5.h[1];
    reg_d5.h[1] = reg_tmp5.h[0];
    reg_d5.h[0] = *(u16 *)(reg_a5 + 0x2C);
    reg_d0.w = 0x13;
    reg_a0 = (u8 *)D_00259870_as_u8_a;
    reg_d4.w = (u32) reg_a6;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x29);
    reg_d3.b[0] = reg_d1.b[0];
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.b[0] += reg_d3.b[0];
    if (*(u8 *)(reg_a6 + 0x1D) != 0x40) goto next_185;
    reg_d1.b[0] *= -1;
next_185:
    reg_d1.b[0] += *(u8 *)(reg_a5 + 0x2A);
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d5.w;
    bullet_fire256_2way();
    *(u8 *)(reg_a5 + 0x29) += 1;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x29);
    if (*(u8 *)(reg_a5 + 0x28) != reg_d0.b[0]) goto next_200;
    *(u8 *)(reg_a5 + 0x29) = 0;
    bits = ENTITY(reg_a6)->flags.b[0];
    if (!(bits & 0x40)) goto next_192;
    ENTITY(reg_a6)->flags.b[0] = bits & 0xBF;
    goto next_194;
next_192:
    ENTITY(reg_a6)->flags.b[0] = bits | 0x40;
next_194:
    *(u8 *)(reg_a5 + 0x27) = *(u8 *)(reg_a5 + 0x26);
next_200:
    if (*(u8 *)(reg_a6 + 0x1F) == 0) goto block_objset;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_240;
    *(u8 *)(reg_a5 + 0x1F) = *(u8 *)(reg_a5 + 0x1E);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
    reg_a0 = (u8 *)D_00263880;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0x20) -= 4;
    if (*(s16 *)(reg_a5 + 0x20) >= 0) goto next_240;
    *(u16 *)(reg_a5 + 0x20) = 0xC;
next_240:
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x1A);
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    ENTITY(reg_a6)->x.h += reg_d1.h[0];
    *(u16 *)(reg_a5 + 0x1C) -= reg_d0.h[0];
block_objset:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    func_0019BF40();
    reg_d7.w = 4;
    reg_d6.w = 0;
    reg_a0 = (u8 *)func_0011B220;
    if (*(u8 *)(reg_a6 + 0x1D) != 0x40) goto next_sen;
    reg_d7.w = 1;
    reg_a0 = (u8 *)func_00119FE0;
next_sen:
    reg_a6 += 0x20;
loop_1:
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
    if (ENTITY(reg_a6)->flags.sb[0] < 0) goto next_sen60;
    reg_d6.w = 1;
next_sen60:
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) goto loop_1;
    if (reg_d6.h[0] != 0) goto next_sen80;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
    reg_a6 = (u8 *) reg_tmp.w;
    ENTITY(reg_a6)->flags.b[1] |= 0x20;
next_sen80:
    return;
block_explos:
    *(u16 *)(reg_a5 + 0x24) -= 1;
    if (*(s16 *)(reg_a5 + 0x24) >= 0) goto next_exp10;
    enemy_remove();
    goto block_rts;
next_exp10:
    func_0019BF40();
    goto block_rts;
block_dead:
    reg_d0.w = 0x133;
    func_001A91A0();
    func_0018D580();
    ENTITY(reg_a6)->flags.h = 0x8080;
    *(u8 *)(reg_a6 + 0x1C) = *(u8 *)(reg_a5 + 0x23);
    ENTITY(reg_a6)->hit_y_plus.sh = 0x18;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 8;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(s16 *)(reg_a0 + 0x26) = 0;
    *(s16 *)(reg_a0 + 0x28) = 0;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x1A) = 0x700;
    *(s16 *)(reg_a0 + 0x18) = 0;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 8;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x26) = 0xFC00;
    *(s16 *)(reg_a0 + 0x28) = 0x800;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x1A) = 0x740;
    *(s16 *)(reg_a0 + 0x18) = 2;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 8;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x26) = 0xF200;
    *(s16 *)(reg_a0 + 0x28) = 0;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x1A) = 0x880;
    *(s16 *)(reg_a0 + 0x18) = 4;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 8;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x26) = 0xFC00;
    *(u16 *)(reg_a0 + 0x28) = 0xF800;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x1A) = 0x7C0;
    *(s16 *)(reg_a0 + 0x18) = 6;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 8;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(s16 *)(reg_a0 + 0x26) = 0x600;
    *(u16 *)(reg_a0 + 0x28) = 0xF600;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x1A) = 0x4D0;
    *(s8 *)(reg_a0 + 0x1D) = 0x40;
    *(s16 *)(reg_a0 + 0x18) = 8;
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 8;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(s16 *)(reg_a0 + 0x26) = 0x200;
    *(s16 *)(reg_a0 + 0x28) = 0x600;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x1A) = 0x430;
    *(s16 *)(reg_a0 + 0x18) = 0xA;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 8;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x26) = 0xF000;
    *(s16 *)(reg_a0 + 0x28) = 0xA00;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x1A) = 0x450;
    *(s16 *)(reg_a0 + 0x18) = 0xC;
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 8;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x26) = 0xF000;
    *(u16 *)(reg_a0 + 0x28) = 0xFA00;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x1A) = 0x4B0;
    *(s16 *)(reg_a0 + 0x18) = 0xE;
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 8;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x26) = 0xF400;
    *(s16 *)(reg_a0 + 0x28) = 0;
    *(s16 *)(reg_a0 + 0x10) = 1;
    *(s16 *)(reg_a0 + 0x18) = 0x10;
    enemy_remove();
block_rts:
    return;
}

void func_001DF2B0(void) {
    u16 temp_v1;

    temp_v1 = *(u16 *)(reg_a6 + 0x3E);
    if (temp_v1 != 0) {
        *(u16 *)(reg_a6 + 0x3E) = (u16) (temp_v1 - 1);
        if (*(u16 *)(reg_a6 + 0x3E) == 0) {
            reg_tmp.w = 0x1D9A;
            *(u16 *)(reg_a6 + 0x2A) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a6 + 0x2C) = (u16) reg_tmp.h[0];
        }
    }
}

void func_001DF300(void) {
    u16 temp_v1;

    temp_v1 = *(u16 *)(reg_a6 + 0x5E);
    if (temp_v1 != 0) {
        *(u16 *)(reg_a6 + 0x5E) = (u16) (temp_v1 - 1);
        if (*(u16 *)(reg_a6 + 0x5E) == 0) {
            reg_tmp.w = 0x1D9C;
            *(u16 *)(reg_a6 + 0x4A) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a6 + 0x4C) = (u16) reg_tmp.h[0];
        }
    }
}

s32 func_0018D560();

void func_001DF350() {
    u16 temp_a3;

    func_0018D560();
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    temp_a3 = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 4) = temp_a3;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0x1400;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0x400;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0x1400;
    *(u16 *)(reg_a0 + 0x28) = 0x600;
    *(u16 *)(reg_a0 + 0x1A) = 0x658;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x18) = 2;
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xC00;
    *(u16 *)(reg_a0 + 0x28) = 0xFE00;
    *(u16 *)(reg_a0 + 0x1A) = 0x6A8;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x18) = 2;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0x400;
    *(u16 *)(reg_a0 + 0x28) = 0xFC00;
    *(u16 *)(reg_a0 + 0x1A) = 0xA88;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x18) = 6;
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0x600;
    *(u16 *)(reg_a0 + 0x28) = 0x400;
    *(u16 *)(reg_a0 + 0x1A) = 0xA78;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x18) = 4;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xF600;
    *(u16 *)(reg_a0 + 0x28) = 0xA00;
    *(u16 *)(reg_a0 + 0x1A) = 0xA70;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x18) = 0xA;
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xF000;
    *(u16 *)(reg_a0 + 0x28) = 0xFE00;
    *(u16 *)(reg_a0 + 0x1A) = 0x588;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x18) = 8;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xE000;
    *(u16 *)(reg_a0 + 0x28) = 0xFC00;
    *(u16 *)(reg_a0 + 0x1A) = 0x4A0;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x18) = 8;
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xD800;
    *(u16 *)(reg_a0 + 0x28) = 0x400;
    *(u16 *)(reg_a0 + 0x1A) = 0x460;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x18) = 8;
}

s32 func_001DF790(void) {
    s32 enemy_set_entity_count(s32 id);
    return enemy_set_entity_count(2);
}

extern u8 D_002616F0[];
extern u8 D_002617B0[];
extern u8 D_002617F0[];
extern u8 D_00263890[];
extern u8 D_002638B0[];
extern s16 g_enemy_signal_2_as_s16;
extern s16 g_enemy_signal_0_as_s16;
extern u16 g_rank_6_16;
extern s16 D_00299768[];

void func_001DF7A0(void) {

    reg_a0 = D_002638B0;
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a5 + 0x44) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = (u16) reg_tmp.h[0];
    reg_a0 = D_00263890;
    reg_d0.w = 0xF;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = g_rank_6_16;
        *(u8 *)(reg_a5 + 0x1C) -= reg_d0.b[0];
        g_enemy_signal_0_as_s16 = 1;
        reg_a0 = D_002616F0;
        reg_d0.h[0] = 0xF;
        g_enemy_signal_2_as_s16 = 1;
        D_00299768[0] = 1;
        sprite_palette_load();
        reg_a0 = D_002617B0;
        reg_d0.h[0] = 0x10;
        sprite_palette_load();
        reg_a0 = D_002617F0;
        reg_d0.h[0] = 0x11;
        sprite_palette_load();
    }
}

extern u8 D_00259970_as_u8_a[];
extern u8 D_00263940[];
extern u8 D_00263960[];
extern u8 D_002639A0[];
extern u8 D_002639B0[];
extern u8 D_0029F1F0_as_u8_a[];
extern u8 D_0029F260_as_u8_a[];
s32 bullet_fire256_fixed();
s32 bullet_fire256_double();
s32 bullet_fire256_3way();
s32 func_001368E0();
s32 func_0013B2E0();
s32 func_0014E030();
s32 func_0016A9B0();
s32 enemy_switch_target_player();
s32 func_0018D500();
s32 func_0018D520();
s32 func_0018D5C0();
s32 func_0019BF80();
s32 func_0019C530();
s32 func_00201270();
s32 func_002012F0();
s32 func_00201800();
s32 direction256_between();
s32 func_00202C50();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u16 g_enemy_signal_2;
extern u16 g_enemy_signal_0;
extern u16 D_0029CEA0[];

void func_001DF890(void) {
    s16 saved_x;
    s32 saved_d0;
    u32 temp;

    func_0014EA50();
    if (enemy_move_end_requested != 0) {
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x2800;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x3400;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x2800;
    if (reg_tmp.h[1] == 0) goto next_30;
    if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_40;
    g_enemy_signal_0 = 0;
    enemy_remove();
    return;
next_30:
    *(u8 *)(reg_a5 + 0x17) = 1;
next_40:
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.h[0] = reg_d1.h[0];
    reg_d0.h[0] += 0xEC00;
    reg_d1.h[0] += 0xEC00;
    reg_d2.h[0] += 0x1400;
    *(u16 *)(reg_a6 + 0x22) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x24) = reg_d1.h[0];
    *(u16 *)(reg_a6 + 0x42) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x44) = reg_d2.h[0];
    if (ENTITY(reg_a6)->flags.sb[0] < 0) goto block_b;
    if (*(u16 *)(reg_a5 + 0x2A) == 0) goto next_45;
    *(u16 *)(reg_a5 + 0x2A) -= 1;
    ENTITY(reg_a6)->hp.h = 0x7000;
    *(u16 *)(reg_a6 + 0x38) = 0x2200;
    *(u16 *)(reg_a6 + 0x58) = 0x2200;
next_45:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) goto next_50;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
    if (!((s32) ENTITY(reg_a6)->hp.h < 0x1C00)) goto next_90;
    if (D_0028E8B8 != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    if (reg_d0.b[0] != 0x19) goto next_60;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
next_60:
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1A);
    reg_d0.b[0] ^= reg_d2.b[0];
    if (ENTITY(reg_a6)->hp.sh < 0) goto block_c;
next_90:
    *(u8 *)(reg_a6 + 0x1C) = reg_d0.b[0];
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x2D);
    *(u8 *)(reg_a5 + 0x2D) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_100;
    *(u8 *)(reg_a5 + 0x2D) = 4;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x35);
    *(u8 *)(reg_a5 + 0x35) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_100;
    *(u8 *)(reg_a5 + 0x35) = *(u8 *)(reg_a5 + 0x34);
    *(u8 *)(reg_a5 + 0x2D) = *(u8 *)(reg_a5 + 0x2C);
    func_001E0B30();
    func_001E0C20();
next_100:
    if (*(s8 *)(reg_a6 + 0x20) >= 0) goto next_130;
    func_001DF2B0();
    goto next_200;
next_130:
    if (*(u8 *)(reg_a5 + 0x2D) != 0) goto next_140;
    saved_x = ENTITY(reg_a6)->x.h;
    ENTITY(reg_a6)->x.h += 0xE880;
    func_00202C50();
    ENTITY(reg_a6)->x.sh = saved_x;
    if (!((s32) reg_d0.h[0] < 0xC00)) goto next_140;
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x3A);
    reg_d0.w = 0x6000B;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = 0xE100E880;
    reg_d4.w = 0;
    bullet_fire256_3way();
next_140:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 0x21);
    if (reg_d1.b[0] != 0) goto next_150;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
    if (!((s32) *(u16 *)(reg_a6 + 0x38) < 0x880)) goto next_190;
    if (D_0028E8B8 != 0) goto next_190;
    reg_d0.w = 0x19;
    goto next_190;
next_150:
    *(u8 *)(reg_a6 + 0x21) &= 0xA3;
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3C);
    if (reg_d0.b[0] != 0x19) goto next_160;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
next_160:
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1A);
    reg_d0.b[0] ^= reg_d2.b[0];
    if (*(s16 *)(reg_a6 + 0x38) >= 0) goto next_190;
    func_001E4460();
    goto next_200;
next_190:
    *(u8 *)(reg_a6 + 0x3C) = reg_d0.b[0];
next_200:
    if (*(s8 *)(reg_a6 + 0x40) >= 0) goto next_230;
    func_001DF300();
    goto next_300;
next_230:
    if (*(u8 *)(reg_a5 + 0x2D) != 0) goto next_240;
    saved_x = ENTITY(reg_a6)->x.h;
    ENTITY(reg_a6)->x.h += 0x1780;
    func_00202C50();
    ENTITY(reg_a6)->x.sh = saved_x;
    if (!((s32) reg_d0.h[0] < 0xC00)) goto next_240;
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x5A);
    reg_d0.w = 0x6000B;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = 0xE1001780;
    reg_d4.w = 0;
    bullet_fire256_3way();
next_240:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 0x41);
    if (reg_d1.b[0] != 0) goto next_250;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
    if (!((s32) *(u16 *)(reg_a6 + 0x58) < 0x880)) goto next_290;
    if (D_0028E8B8 != 0) goto next_290;
    reg_d0.w = 0x19;
    goto next_290;
next_250:
    *(u8 *)(reg_a6 + 0x41) &= 0xA3;
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x5C);
    if (reg_d0.b[0] != 0x19) goto next_260;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
next_260:
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1A);
    reg_d0.b[0] ^= reg_d2.b[0];
    if (*(s16 *)(reg_a6 + 0x58) >= 0) goto next_290;
    func_001E44F0();
    goto next_300;
next_290:
    *(u8 *)(reg_a6 + 0x5C) = reg_d0.b[0];
next_300:
    func_001368E0();
    if (g_enemies_stopped != 0) goto block_e;
    if ((s32) g_scroll_line < 0x228) goto next_350;
    g_enemy_signal_2 = 0;
next_350:
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (reg_d0.h[0] != 0) goto next_400;
    if (!((s32) g_scroll_line < 0x21C)) goto block_e;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
    *(u8 *)(reg_a5 + 0x1D) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_e;
    *(u16 *)(reg_a5 + 0x18) = 1;
    goto block_e;
next_400:
    if ((reg_d0.h[0] & 0xFFFF) != 1) goto next_500;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x29);
    *(u8 *)(reg_a5 + 0x29) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_d;
    *(u8 *)(reg_a5 + 0x29) = *(u8 *)(reg_a5 + 0x28);
    *(u16 *)(reg_a5 + 0x20) += 4;
    if (*(u16 *)(reg_a5 + 0x20) != 0x24) goto block_d;
    reg_a0 = (u8 *)D_0029F260_as_u8_a;
    reg_a1 = (u8 *)D_0029F1F0_as_u8_a;
    if (*(u8 *)(reg_a5 + 2) == 0) goto next_440;
    reg_atmp = reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *)reg_atmp;
next_440:
    if ((*(s16 *)reg_a0) < 0) goto next_460;
    if ((*(s16 *)reg_a1) >= 0) goto next_490;
    reg_atmp = reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *)reg_atmp;
next_460:
    reg_a4 = reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0xD600;
    direction256_between();
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.w = 0;
    reg_a0 = (u8 *)D_00259970_as_u8_a;
    if (*(u8 *)(reg_a5 + 0x1F) == 0) goto next_475;
    reg_d5.h[0] = reg_d1.h[0];
    reg_d5.h[0] -= 0xC;
    reg_d6.h[0] = 0x74;
    reg_d7.w = 6;
loop_470:
    reg_d0.w = 0xFFF60004;
    reg_d1.h[0] = reg_d5.h[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += 0xD6000000;
    bullet_fire256_double();
    if (reg_d7.h[0] == 0) goto next_474;
    reg_d0.w += 0x40000;
    reg_d1.b[0] += 2;
    bullet_fire256_fixed();
    reg_d0.w += 0x40000;
    reg_d1.b[0] -= 2;
    bullet_fire256_double();
    reg_d0.w += 0x40000;
    reg_d1.b[0] += 2;
    bullet_fire256_fixed();
    goto next_476;
next_474:
    reg_d0.w += 0x80000;
    bullet_fire256_double();
next_476:
    reg_d5.h[0] += 4;
    temp = reg_d7.h[0] - 1;
    reg_d7.h[0] = temp;
    if (((s64) ((s64) (temp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_470;
    goto next_490;
next_475:
    reg_d5.h[0] = reg_d1.h[0];
    reg_d7.w = 0x1C;
    reg_d5.h[0] -= 0x38;
    reg_d6.h[0] = 0x48;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] += 0xD600;
    if (*(s16 *)(reg_a4 + 2) <= (s16) reg_d0.h[0]) goto loop_480;
    reg_d6.h[0] = 0xFFC8;
loop_480:
    reg_d0.w = 0xFFF80004;
    reg_d1.h[0] = reg_d5.h[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += 0xD6000000;
    reg_d0.h[0] = 3;
    reg_d0.h[1] += 4;
    reg_d1.h[0] = reg_d6.h[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += 0xD6000000;
    if ((reg_d7.h[0] & 1) == 0) goto next_484;
    reg_d0.w += 0x20000;
    bullet_fire256_fixed();
    reg_d0.w += 0xFFFE0000;
    goto next_485;
next_484:
    bullet_fire256_double();
next_485:
    reg_d5.h[0] += 4;
    reg_d6.h[0] += 4;
    temp = reg_d7.h[0] - 1;
    reg_d7.h[0] = temp;
    if (((s64) ((s64) (temp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_480;
next_490:
    enemy_switch_target_player();
    *(u16 *)(reg_a5 + 0x18) = 2;
    goto block_d;
next_500:
    if ((reg_d0.h[0] & 0xFFFF) != 2) goto block_d;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x29);
    *(u8 *)(reg_a5 + 0x29) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_d;
    *(u8 *)(reg_a5 + 0x29) = *(u8 *)(reg_a5 + 0x28);
    *(u16 *)(reg_a5 + 0x22) -= 4;
    *(u16 *)(reg_a5 + 0x20) += 4;
    if (*(u16 *)(reg_a5 + 0x20) != 0x28) goto next_520;
    reg_d0.h[0] = 0x9E;
    func_0014E030();
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[1] += 0x1E00;
    *(u16 *)(reg_a0 + 0x16) = reg_d0.h[1];
    *(u16 *)(reg_a0 + 0x18) = reg_d0.h[0];
next_520:
    if (*(u16 *)(reg_a5 + 0x20) != 0x40) goto block_d;
    *(u16 *)(reg_a5 + 0x20) = 0;
    *(u16 *)(reg_a5 + 0x22) = 0xC;
    *(u16 *)(reg_a5 + 0x18) = 1;
    *(u16 *)(reg_a5 + 0x28) = 0;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_d;
    *(u8 *)(reg_a5 + 0x1F) = *(u8 *)(reg_a5 + 0x1E);
    reg_d0.h[0] = 0xA0;
    reg_d0.h[0] -= g_rank_6_16;
    *(u8 *)(reg_a5 + 0x1D) = reg_d0.b[0];
    reg_d0.b[0] = 1;
    *(u8 *)(reg_a5 + 0x29) = reg_d0.b[0];
    *(u8 *)(reg_a5 + 0x28) = reg_d0.b[0];
    *(u16 *)(reg_a5 + 0x18) = 0;
block_d:
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
    reg_a0 = (u8 *)D_00263960;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
block_e:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
    reg_a6 = (u8 *) reg_tmp.w;
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x20;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x40;
    enemy_hitbox_debug_draw();
    func_001E4410();
    func_0019BF80();
    if (ENTITY(reg_a6)->flags.sb[0] < 0) goto block_rts;
    if (*(u16 *)(reg_a5 + 0x18) != 2) goto block_rts;
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x22);
    if ((s16) reg_d2.h[0] < 0) goto block_rts;
    reg_a0 = (u8 *)D_002639A0;
    reg_d2.h[1] = (reg_d2.h[0]) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[1] += 0xB800;
    reg_d1.h[0] += 0xF200;
    reg_d3.h[0] = 0x2470;
    reg_d4.h[0] = 0x11;
    func_0019C530();
block_rts:
    return;
block_c:
    *(u16 *)(reg_a5 + 0x32) = reg_d1.h[0];
    reg_d0.w = 0x683;
    func_001A91A0();
    func_0018D580();
    g_enemy_signal_0 = 0;
    ENTITY(reg_a6)->flags.h = 0x8080;
    *(u8 *)(reg_a6 + 0x1C) = *(u8 *)(reg_a5 + 0x1B);
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x32);
    func_00201800();
    if (*(s8 *)(reg_a6 + 0x20) < 0) goto next_720;
    func_001E4490();
    *(u16 *)(reg_a5 + 0x2E) = 0;
next_720:
    if (*(s8 *)(reg_a6 + 0x40) < 0) goto next_740;
    func_001E4520();
    *(u16 *)(reg_a5 + 0x2E) = 0;
next_740:
    if (*(s16 *)D_0029CEA0 == 0) goto block_e;
    *(u16 *)(reg_a5 + 0x2E) = 0;
    goto block_e;
block_b:
    if (*(s8 *)(reg_a6 + 0x20) >= 0) goto next_620;
    func_001DF2B0();
next_620:
    if (*(s8 *)(reg_a6 + 0x40) >= 0) goto next_640;
    func_001DF300();
next_640:
    if (*(u16 *)(reg_a5 + 0x24) != 0) goto next_6200;
    if (*(u16 *)(reg_a6 + 0x1E) != 0) goto next_680;
    if (*(u16 *)(reg_a5 + 0x30) == 0) goto next_650;
    *(u16 *)(reg_a5 + 0x30) -= 1;
    if (*(u16 *)(reg_a5 + 0x30) != 0) goto next_650;
    g_enemy_signal_2 = 0;
next_650:
    if (*(u16 *)(reg_a5 + 0x2E) == 0) {
        func_001E4410();
        return;
    }
    *(u16 *)(reg_a5 + 0x2E) -= 1;
    if (*(u16 *)(reg_a5 + 0x2E) != 0) {
        func_001E4410();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    saved_d0 = reg_d0.w;
    if ((s16) reg_d0.h[0] >= 0x1000) goto next_660;
    ENTITY(reg_a6)->y.h = 0x1000;
next_660:
    reg_d0.h[0] = 0x10;
    func_0016A9B0();
    reg_tmp.w = saved_d0;
    ENTITY(reg_a6)->y.h = reg_tmp.h[0];
    func_001E4410();
    return;
next_680:
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x32);
    func_00201800();
    *(u16 *)(reg_a6 + 0x1E) -= 1;
    goto block_e;
next_6200:
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x32);
    func_00201800();
    *(u16 *)(reg_a5 + 0x24) -= 1;
    if (*(u16 *)(reg_a5 + 0x24) != 0) goto next_6240;
    func_001DF350();
    reg_a0 = (u8 *)D_002639B0;
    func_0013B2E0();
    vibration_start_pad1(0xB4, 0x64);
    vibration_start_pad2(0xB4, 0x64);
    func_0018D5C0();
    goto block_e;
next_6240:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x27);
    *(u8 *)(reg_a5 + 0x27) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_e;
    *(u8 *)(reg_a5 + 0x27) = *(u8 *)(reg_a5 + 0x26);
    reg_a0 = (u8 *) func_0018D500;
    rng_next_unsigned();
    if ((s8) reg_d0.b[0] >= 0) goto next_6260;
    reg_a0 = (u8 *) func_0018D520;
next_6260:
    jtbl_0028E3F4 = (Fn) reg_a0;
    jtbl_0028E3F4();
    rng_next_unsigned();
    reg_d0.h[0] &= 7;
    reg_a1 = (u8 *)D_00263940;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : (u16) *(u16 *)reg_a1;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x800;
    func_00201270();
    reg_d0.b[0] += 3;
    *(u8 *)(reg_a0 + 0x1B) = reg_d0.b[0];
    rng_next_unsigned();
    *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
    func_002012F0();
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d0.h[0] += reg_d1.h[0];
    reg_d0.h[0] += 0xF800;
    *(u16 *)(reg_a0 + 0x26) = reg_d0.h[0];
    func_002012F0();
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    *(u16 *)(reg_a0 + 0x28) = reg_d0.h[0];
    goto block_e;
}

extern s16 D_0029F1F0[];
extern s16 D_0029F260[];

void func_001E0B30(void) {
    s16 *temp_a0;
    s16 *var_a1;

    reg_a0 = (u8 *)(D_0029F260);
    reg_a1 = (u8 *)(D_0029F1F0);
    if (*(u8 *)(reg_a5 + 2) != 0) {
        reg_atmp = (u8 *)(reg_a0);
        reg_a0 = (u8 *)(reg_a1);
        reg_a1 = (u8 *)(reg_atmp);
    }
    temp_a0 = (s16 *)(reg_a0);
    if ((*(s16 *)((u8 *)(temp_a0) + (0))) >= 0) {
        var_a1 = (s16 *)(reg_a1);
        if (*var_a1 >= 0) goto block_st;
        reg_a0 = (u8 *)(var_a1);
        reg_atmp = (u8 *)(temp_a0);
        reg_a1 = (u8 *)(temp_a0);
    }
    enemy_switch_target_player();
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x7FFF + 0x6101;
    reg_d1.h[0] += 0x7FFF + 0x6881;
    direction256_between();
    *(u8 *)(reg_a6 + 0x3A) = (u8) reg_d1.b[0];
    return;
block_st:
    *(s8 *)(reg_a5 + 0x2D) = 4;
}

void func_001E0C20(void) {
    s16 *temp_a0;
    s16 *var_a1;

    reg_a0 = (u8 *)(D_0029F260);
    reg_a1 = (u8 *)(D_0029F1F0);
    if (*(u8 *)(reg_a5 + 2) != 0) {
        reg_atmp = (u8 *)(reg_a0);
        reg_a0 = (u8 *)(reg_a1);
        reg_a1 = (u8 *)(reg_atmp);
    }
    temp_a0 = (s16 *)(reg_a0);
    if ((*(s16 *)((u8 *)(temp_a0) + (0))) >= 0) {
        var_a1 = (s16 *)(reg_a1);
        if (*var_a1 >= 0) goto block_st;
        reg_a0 = (u8 *)(var_a1);
        reg_atmp = (u8 *)(temp_a0);
        reg_a1 = (u8 *)(temp_a0);
    }
    enemy_switch_target_player();
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x7FFF + 0x6101;
    reg_d1.h[0] += 0x1780;
    direction256_between();
    *(u8 *)(reg_a6 + 0x5A) = (u8) reg_d1.b[0];
    return;
block_st:
    *(s8 *)(reg_a5 + 0x2D) = 4;
}

void func_001E0D10(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 rng_next();
extern u8 D_00263A30[];
extern u8 D_00263EF0[];

void func_001E0D20(void) {
    u16 temp_a1;

    reg_a0 = D_00263A30;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    temp_a1 = *(u16 *)(reg_a5 + 0x18);
    ENTITY(reg_a6)->x.h = temp_a1;
    reg_a0 = D_00263EF0;
    reg_d0.w = 7;
    enemy_set_task_work();
    rng_next();
    reg_tmp.h[0] = (u16) (s8) reg_d0.b[0];
    reg_d0.h[0] = reg_tmp.h[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] * 8;
    *(u16 *)(reg_a5 + 0x1C) += reg_d0.h[0];
    rng_next_unsigned();
    if ((s8) reg_d0.b[0] < 0) {
        *(s8 *)(reg_a6 + 0x1D) = 0x40;
        *(u16 *)(reg_a5 + 0x1C) *= 0xFFFF;
    }
}

s32 func_0019D620();
extern u8 D_00263A50[];
extern u8 D_0028E2E4;

void func_001E0DF0(void) {
    if (D_0028E2E4 != 0) {
        goto block_7a;
    }
    if (g_enemy_signal_0 == 0) {
        goto block_11;
    }
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) {
        goto block_1;
    }
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
    if (ENTITY(reg_a6)->hp.h >= 0x100) {
        goto block_3;
    }
    if (D_0028E8B8 != 0) {
        goto block_3;
    }
    reg_d0.w = 0x19;
    goto block_3;
block_1:
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    if (reg_d0.b[0] != 0x19) {
        goto block_2;
    }
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
block_2:
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
    reg_d0.b[0] ^= reg_d2.b[0];
    if (ENTITY(reg_a6)->hp.sh < 0) {
        goto block_10;
    }
block_3:
    *(u8 *)(reg_a6 + 0x1C) = reg_d0.b[0];
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
    ENTITY(reg_a6)->flags.b[0] |= 0x20;
    if (!(reg_tmp.b[0] & 0x20)) {
        goto block_8;
    }
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1A);
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    if (*(u16 *)(reg_a5 + 0x24) != 0) {
        goto block_4;
    }
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1A);
    *(u16 *)(reg_a5 + 0x1E) += reg_d0.h[0];
    if (*(u16 *)(reg_a5 + 0x1E) < 0x1600) {
        goto block_6;
    }
    *(u16 *)(reg_a5 + 0x24) = 1;
block_4:
    if ((s16)*(u16 *)(reg_a5 + 0x1A) <= -0x200) {
        goto block_4b;
    }
    *(u16 *)(reg_a5 + 0x1A) -= 0x80;
block_4b:
    reg_a0 = (u8 *)D_00263A50;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x22);
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x22);
    *(u16 *)(reg_a5 + 0x22) -= 4;
    if ((s32)reg_tmp.h[0] >= 4) {
        goto block_5;
    }
    *(u16 *)(reg_a5 + 0x22) = 0x7C;
block_5:
    if (*(u16 *)(reg_a5 + 0x24) != 1) {
        goto block_5b;
    }
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1A);
    *(u16 *)(reg_a5 + 0x1E) += reg_d0.h[0];
    if (*(u16 *)(reg_a5 + 0x1E) < 0x3000) {
        goto block_6;
    }
    *(u16 *)(reg_a5 + 0x24) = 2;
block_5b:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
    *(u8 *)(reg_a5 + 0x21) -= 1;
    if ((s32)reg_tmp.b[0] > 0) {
        goto block_6;
    }
    *(u8 *)(reg_a5 + 0x21) = *(u8 *)(reg_a5 + 0x20);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1C);
    ENTITY(reg_a6)->x.h -= reg_d0.h[0];
block_6:
    if (*(s16 *)(reg_a5 + 0x1A) > -0x200) {
        goto block_8;
    }
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xB400;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0xA00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0xB400;
    if (reg_tmp.h[1] != 0) {
        goto block_7;
    }
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] += 0xE00;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x7400;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.sw;
    reg_d0.h[0] += 0x7400;
    if (reg_tmp.h[1] == 0) {
        goto block_7b;
    }
block_7:
    if (*(u8 *)(reg_a5 + 0x17) == 0) {
        goto block_8;
    }
block_7a:
    enemy_remove();
    return;
block_7b:
    *(u8 *)(reg_a5 + 0x17) = 1;
block_8:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    ENTITY(reg_a6)->flags.b[0] |= 1;
    if (ENTITY(reg_a6)->y.sh >= 0) {
        goto block_9;
    }
    ENTITY(reg_a6)->flags.b[0] &= 0xFE;
    return;
block_9:
    if (*(s16 *)(reg_a5 + 0x1A) < 0) {
        goto block_9b;
    }
    func_0019BF40();
    return;
block_9b:
    func_0019D620();
    return;
block_10:
    reg_d0.w = 0;
    func_001A91A0();
block_11:
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0xC;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(s16 *)(reg_a0 + 0x26) = 0;
    *(s16 *)(reg_a0 + 0x28) = 0;
    func_0018D500();
    enemy_remove();
}

void func_001E12C0(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(2);
}

extern u8 D_00261830[];
extern u8 D_002618B0[];
extern u8 D_002618F0[];
extern u8 D_00263B50[];
extern u8 D_00263B80[];

void func_001E12D0(void) {
    reg_a0 = D_00263B80;
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a5 + 0x44) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = (u16) reg_tmp.h[0];
    reg_a0 = D_00263B50;
    reg_d0.w = 0x12;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_a0 = D_002618B0;
        reg_d0.h[0] = 0x13;
        sprite_palette_load();
        reg_a0 = D_002618F0;
        reg_d0.h[0] = 0x14;
        sprite_palette_load();
        reg_a0 = D_00261830;
        reg_d0.h[0] = 0x15;
        sprite_palette_load();
    }
}

extern u8 D_00261770[];
extern u8 D_00263C10[];
extern u8 D_00263C30[];
extern u8 D_00263C70[];
extern u8 D_00263C80[];
extern u8 D_00263C90[];
extern u8 D_00263CF0[];
s32 func_00139EB0();
s32 func_0013B920();
s32 func_0013C300();
s32 func_0018DB30();
s32 func_0018DB50();
s32 func_0018DB70();
s32 func_0018DBC0();
s32 func_0018DDA0();
s32 func_0018DDB0();
s32 func_0019BEC0();
s32 func_0019C470();
s32 func_00201710();

void func_001E1390(void) {
    s16 x_save;

    func_0014EA50();
    if (enemy_move_end_requested != 0) goto block_rts;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x2000;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x3800;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x2000;
    if (reg_tmp.h[1] == 0) goto next_1;
    if (*(s8 *)(reg_a5 + 0x17) == 0) goto next_2;
    enemy_remove();
    return;
next_1:
    *(s8 *)(reg_a5 + 0x17) = 1;
next_2:
    if (ENTITY(reg_a6)->flags.sb[0] < 0) goto block_c;
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a6 + 0x42) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x44) = (u16) reg_d0.h[0];
    reg_d0.h[1] += 0xDC00;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_d0.h[0];
    *(s16 *)(reg_a6 + 0x38) = 0x7FFF;
    *(u8 *)(reg_a6 + 0x21) &= 0xA3;
    switch (*(u16 *)(reg_a5 + 0x32)) { case 0: goto next_3; }
    *(u16 *)(reg_a5 + 0x32) -= 1;
    ENTITY(reg_a6)->hp.h = 0x7800;
    *(u16 *)(reg_a6 + 0x58) = 0x7800;
next_3:
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    reg_d1.b[0] |= *(u8 *)(reg_a6 + 0x41);
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) goto next_4;
    reg_d0.b[0] = 0x13;
    if (!((s32) ENTITY(reg_a6)->hp.h < 0x1E00)) goto next_7;
    if (D_0028E8B8 != 0) goto next_7;
    reg_d0.w = 0x19;
    goto next_7;
next_4:
    reg_d0.h[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x41) &= reg_d0.b[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    if (reg_d0.b[0] != 0x19) goto next_5;
    reg_d0.b[0] = 0x13;
next_5:
    reg_d0.b[0] ^= 0xC;
    reg_d4.h[0] = ENTITY(reg_a6)->hp.h;
    if (!((s16) *(u16 *)(reg_a6 + 0x58) < (s16) reg_d4.h[0])) goto next_6;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x58);
next_6:
    ENTITY(reg_a6)->hp.h = (u16) reg_d4.h[0];
    *(u16 *)(reg_a6 + 0x58) = (u16) reg_d4.h[0];
    if ((s16) ENTITY(reg_a6)->hp.h < 0) goto block_b;
next_7:
    *(u8 *)(reg_a6 + 0x1C) = (u8) reg_d0.b[0];
    func_001368E0();
    if (g_enemies_stopped != 0) goto next_15;
    if (*(u16 *)(reg_a5 + 0x18) != 0) goto next_8;
    if (!((s32) ENTITY(reg_a6)->y.h < 0x7001)) goto next_15;
    *(u16 *)(reg_a5 + 0x1E) -= 0x40;
    *(u16 *)(reg_a5 + 0x18) = 1;
    goto next_15;
next_8:
    if (!((s16) *(u16 *)(reg_a5 + 0x1E) < 0x2400)) goto next_9;
    *(u16 *)(reg_a5 + 0x1E) += 0x40;
next_9:
    if (*(u16 *)(reg_a5 + 0x18) != 1) goto next_10;
    if (!((s16) ENTITY(reg_a6)->y.h < 0x5001)) goto next_15;
    reg_a0 = (u8 *)D_00263C70;
    func_0013B920();
    func_0018DB30();
    *(u16 *)(reg_a5 + 0x38) = 0x20;
    *(u16 *)(reg_a5 + 0x18) = 2;
    goto next_15;
next_10:
    if (ENTITY(reg_a6)->flags.b[1] & 0x20) goto next_11;
    reg_d0.h[0] = 0x40;
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    *(u16 *)(reg_a5 + 0x2A) += reg_d0.h[0];
    if (*(u16 *)(reg_a5 + 0x2A) != 0x1040) goto next_11;
    ENTITY(reg_a6)->y.h -= reg_d0.h[0];
    *(u16 *)(reg_a5 + 0x2A) -= reg_d0.h[0];
    ENTITY(reg_a6)->flags.h = 0xA000;
    *(u16 *)(reg_a6 + 0x40) = 0xA000;
next_11:
    if (*(u16 *)(reg_a5 + 0x18) != 2) goto next_13;
    if (*(u16 *)(reg_a5 + 0x38) == 0) goto next_12;
    *(u16 *)(reg_a5 + 0x38) -= 1;
    if (*(u16 *)(reg_a5 + 0x38) != 0) goto next_12;
    func_0018DB50();
next_12:
    reg_d0.h[0] = 0xA4;
    func_0014E030();
    reg_a1 = reg_a6 + 0x20;
    reg_tmp.w = (u32) reg_a1;
    *(u16 *)(reg_a0 + 0x24) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[0];
    *(u16 *)(reg_a0 + 0x28) = 0x800;
    if (!((s32) ENTITY(reg_a6)->y.h < 0x4601)) goto next_15;
    *(u16 *)(reg_a5 + 0x26) = 0x20;
    *(u16 *)(reg_a5 + 0x28) = 0x18;
    *(u16 *)(reg_a5 + 0x18) = 3;
    goto next_15;
next_13:
    if (*(u16 *)(reg_a5 + 0x18) != 3) goto next_14;
    if (!((s32) ENTITY(reg_a6)->y.h < 0x4001)) goto next_15;
    *(u16 *)(reg_a5 + 0x26) = 0x3C;
    *(u16 *)(reg_a5 + 0x28) = 0x34;
    reg_a0 = (u8 *)D_00263CF0;
    func_0013B2E0();
    func_0018DDB0();
    *(u16 *)(reg_a5 + 0x18) = 4;
    goto next_15;
next_14:
    if (*(u16 *)(reg_a5 + 0x18) != 4) goto next_15;
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x2A);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2C);
    if (reg_tmp.w != 0x1DE6) goto next_15;
    *(u16 *)(reg_a6 + 0x20) = 0xA001;
    func_0018DB70();
    *(u16 *)(reg_a5 + 0x38) = 0x40;
    *(u16 *)(reg_a5 + 0x18) = 5;
next_15:
    if (D_0028E2E4 != 0) goto next_17;
    if (*(u16 *)(reg_a5 + 0x18) != 5) goto next_16;
    if ((s16) *(u16 *)(reg_a5 + 0x38) == -1) goto next_16;
    *(u16 *)(reg_a5 + 0x38) -= 1;
    if ((s16) *(u16 *)(reg_a5 + 0x38) != -1) goto next_16;
    func_0018DBC0();
next_16:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
    *(u8 *)(reg_a5 + 0x23) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_17;
    *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x24);
    reg_a0 = (u8 *)D_00263C30;
    *(u16 *)(reg_a6 + 0x2A) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x2C) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0x24) += 4;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x26);
    if (*(u16 *)(reg_a5 + 0x24) != reg_d0.h[0]) goto next_17;
    *(u16 *)(reg_a5 + 0x24) = (u16) *(u16 *)(reg_a5 + 0x28);
next_17:
    func_0019BEC0();
    if (!((s16) *(u16 *)(reg_a6 + 0x22) > -0x800)) goto next_18;
    reg_a6 += 0x20;
    func_0019BEC0();
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
    reg_a6 = (u8 *) reg_tmp.w;
    goto next_19;
next_18:
    if ((s16) *(u16 *)(reg_a5 + 0x38) != -1) goto next_19;
    func_0018DDA0();
    *(u16 *)(reg_a5 + 0x38) = 0xFFFE;
next_19:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x20;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x40;
    enemy_hitbox_debug_draw();
    if (!((s16) *(u16 *)(reg_a5 + 0x1E) < 0x2400)) goto block_rts;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0xF400;
    reg_d1.h[1] -= *(u16 *)(reg_a5 + 0x1E);
    reg_d2.w = 0x1DD4;
    reg_d3.h[0] = 0x1860;
    reg_d4.h[0] = 0x14;
    reg_d1.h[1] += 0xB800;
    func_0019C470();
    goto block_rts;
block_b:
    *(u16 *)(reg_a5 + 0x3A) = (u16) reg_d1.h[0];
    reg_d0.w = 0x788;
    func_001A91A0();
    func_0018DDB0();
    func_0018DDA0();
    func_0018D5C0();
    ENTITY(reg_a6)->flags.h = 0x8080;
    *(u16 *)(reg_a6 + 0x20) = 0x8000;
    *(u16 *)(reg_a6 + 0x40) = 0x8000;
    *(u8 *)(reg_a6 + 0x1C) = 0x13;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x3A);
    func_00201710();
    reg_a0 = (u8 *)D_00263C80;
    func_0013B920();
    *(u16 *)(reg_a5 + 0x34) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a5 + 0x36) = (u16) reg_d0.h[0];
    func_0019BEC0();
    goto block_rts;
block_c:
    if (*(u16 *)(reg_a5 + 0x2C) != 0) goto next_22;
    if (*(u16 *)(reg_a5 + 0x30) == 0) goto next_26;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x3A);
    func_00201710();
    *(u16 *)(reg_a5 + 0x30) -= 1;
    if (*(u16 *)(reg_a5 + 0x30) != 0) goto next_26;
    reg_tmp.w = 0x1DD3;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)D_00261770;
    reg_d0.h[0] = 0x13;
    sprite_palette_load();
    goto next_26;
next_22:
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x3A);
    func_00201710();
    *(u16 *)(reg_a5 + 0x2C) -= 1;
    if (*(u16 *)(reg_a5 + 0x2C) == 0) goto next_23;
    if (*(u16 *)(reg_a5 + 0x2C) != 1) goto next_24;
    reg_d0.h[1] = *(u16 *)(reg_a5 + 0x34);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x36);
    func_0013C300();
    reg_a0 = (u8 *)D_00263C90;
    func_0013B2E0();
    goto next_24;
next_23:
    func_00139EB0();
    x_save = ENTITY(reg_a6)->x.h;
    ENTITY(reg_a6)->x.h += 0xF280;
    func_001E1F30();
    ENTITY(reg_a6)->x.h += 0x1B00;
    func_001E1F30();
    ENTITY(reg_a6)->x.h = x_save;
    func_0018D5C0();
    vibration_start_pad1(0xB4, 0x64);
    vibration_start_pad2(0xB4, 0x64);
    goto next_26;
next_24:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x2F);
    *(u8 *)(reg_a5 + 0x2F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_26;
    *(u8 *)(reg_a5 + 0x2F) = (u8) *(u8 *)(reg_a5 + 0x2E);
    reg_a0 = (u8 *)func_0018D500;
    rng_next_unsigned();
    if (reg_d0.sb[0] >= 0) goto next_25;
    reg_a0 = (u8 *)func_0018D520;
next_25:
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
    rng_next_unsigned();
    reg_d0.h[0] &= 7;
    reg_a0 = (u8 *)D_00263C10;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x800;
    func_00201270();
    reg_d0.b[0] += 3;
    *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
    rng_next_unsigned();
    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
    func_002012F0();
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d0.h[0] += reg_d1.h[0];
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d0.h[0] += reg_d1.h[0];
    reg_d0.h[0] += 0xF800;
    *(u16 *)(reg_a0 + 0x26) = (u16) reg_d0.h[0];
    func_002012F0();
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d0.h[0] += reg_d1.h[0];
    *(u16 *)(reg_a0 + 0x28) = (u16) reg_d0.h[0];
next_26:
    func_0019BEC0();
block_rts:
    return;
}

void func_001E1F30() {
    u16 temp_a3;

    func_0018D560();
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    temp_a3 = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 4) = temp_a3;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0x2800;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0x400;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0x2800;
    *(u16 *)(reg_a0 + 0x28) = 0x600;
    *(u16 *)(reg_a0 + 0x1A) = 0x658;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x18) = 2;
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0x2000;
    *(u16 *)(reg_a0 + 0x28) = 0xFE00;
    *(u16 *)(reg_a0 + 0x1A) = 0x6A8;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x18) = 2;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0x1800;
    *(u16 *)(reg_a0 + 0x28) = 0xFC00;
    *(u16 *)(reg_a0 + 0x1A) = 0xA88;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x18) = 6;
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0x1A00;
    *(u16 *)(reg_a0 + 0x28) = 0x400;
    *(u16 *)(reg_a0 + 0x1A) = 0xA78;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x18) = 4;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xA00;
    *(u16 *)(reg_a0 + 0x28) = 0xA00;
    *(u16 *)(reg_a0 + 0x1A) = 0xA70;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x18) = 0xA;
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0x400;
    *(u16 *)(reg_a0 + 0x28) = 0xFE00;
    *(u16 *)(reg_a0 + 0x1A) = 0x588;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x18) = 8;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xF400;
    *(u16 *)(reg_a0 + 0x28) = 0xFC00;
    *(u16 *)(reg_a0 + 0x1A) = 0x4A0;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x18) = 8;
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xEC00;
    *(u16 *)(reg_a0 + 0x28) = 0x400;
    *(u16 *)(reg_a0 + 0x1A) = 0x460;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x18) = 8;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xDC00;
    *(u16 *)(reg_a0 + 0x28) = 0xFC00;
    *(u16 *)(reg_a0 + 0x1A) = 0x4A0;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x18) = 0xA;
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xD400;
    *(u16 *)(reg_a0 + 0x28) = 0x400;
    *(u16 *)(reg_a0 + 0x1A) = 0x460;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x18) = 0xA;
}

void func_001E2460(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

extern u8 D_00263D00[];
extern u8 D_0028D9B0;

void func_001E2470(void) {
    reg_a0 = D_00263D00;
    enemy_init_entities();
    reg_tmp.w = (u32)reg_a0;
    *(u16 *)(reg_a5 + 0x44) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = reg_tmp.h[0];
    reg_a0 = &D_0028D9B0;
    reg_d0.w = 2;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_a0 = D_002618B0;
        reg_d0.h[0] = 0x12;
        sprite_palette_load();
    }
}

extern u16 D_00263D20[];

void func_001E24F0(void) {
    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x2000;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x3800;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x2000;
        if (reg_tmp.h[1] != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                enemy_remove();
                return;
            }
            goto block_5;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
block_5:
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x19);
        *(u8 *)(reg_a5 + 0x19) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x19) = (u8) *(u8 *)(reg_a5 + 0x18);
            reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1A);
            reg_a0 = (u8 *)(D_00263D20);
            ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
            ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            *(u16 *)(reg_a5 + 0x1A) -= 4;
            if ((s16) *(u16 *)(reg_a5 + 0x1A) < 0) {
                *(u16 *)(reg_a5 + 0x1A) = 0x3CU;
            }
        }
        func_0019BF00();
    }
}

void func_001E2690(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

extern s8 D_00263D60[];
extern s8 D_00263D70[];
extern s8 D_00263D90[];
extern u16 g_rank_3_16;
extern u16 g_rank_4_16;
extern u16 g_stage_x2;
extern s8 *reg_a0_as_s8_p;

void func_001E26A0(void) {
    reg_a0_as_s8_p = D_00263D90;
    enemy_init_entities();
    reg_a0_as_s8_p = D_00263D70;
    reg_d0.w = 0xE;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = g_rank_3_16;
        *(u8 *)(reg_a5 + 0x1D) -= reg_d0.b[0];
        reg_d0.h[0] = g_rank_4_16;
        *(u8 *)(reg_a5 + 0x1C) -= reg_d0.b[0];
        if (*(u8 *)(reg_a6 + 0x1F) != 0) {
            *(u8 *)(reg_a6 + 0x1F) = 0U;
            *(u8 *)(reg_a6 + 0x1D) |= 0x40;
            *(u16 *)(reg_a5 + 0x28) *= (0xFFFF & 0xFFFF);
            *(u16 *)(reg_a5 + 0x2A) *= 0xFFFF;
            *(u16 *)(reg_a5 + 0x2C) *= 0xFFFF;
        }
        reg_d0.w = (u32) reg_a6;
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x24);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x26);
        reg_tmp.w += reg_d0.w;
        *(u16 *)(reg_a5 + 0x24) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a5 + 0x26) = (u16) reg_tmp.h[0];
        reg_a0_as_s8_p = D_00263D60;
        reg_d0.h[0] = g_stage_x2;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        *(s8 *)(reg_a6 + 0x1C) = (s8) *reg_a0_as_s8_p;
        *(s8 *)(reg_a5 + 0x1B) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        *(s8 *)(reg_a5 + 0x1A) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
    }
}

extern u8 D_00263DB0[];

void func_001E2840(void) {
    u8 *var_a0;
    u32 temp_a3;
    u32 temp_a3_2;
    u32 temp_a3_3;
    u32 temp_a3_4;
    u8 temp_a0_2;
    u8 temp_a0_4;
    u8 temp_v0;
    u8 temp_v0_2;

    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x5800;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1C00;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x5800;
        if (reg_tmp.h[1] != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                enemy_remove();
                return;
            }
            goto block_5;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
block_5:
        var_a0 = (u8 *)(reg_a6);
        if ((*(s8 *)((u8 *)(var_a0) + (0))) >= 0) {
            reg_d1.w = 0x5C;
            reg_d1.b[0] &= (*(u8 *)((u8 *)(var_a0) + (1)));
            if (reg_d1.b[0] == 0) {
                reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
                if (((s32) (*(u16 *)((u8 *)(var_a0) + (0x18))) < 0x580) && (D_0028E8B8 == 0)) {
                    reg_d0.w = 0x19;
                }
                goto block_13;
            }
            (*(u8 *)((u8 *)(var_a0) + (1))) &= 0xA3;
            func_001A9000();
            reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
            if (reg_d0.b[0] == 0x19) {
                reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
            }
            reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1A);
            reg_d0.b[0] ^= reg_d2.b[0];
            if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
block_13:
                *(u8 *)(reg_a6 + 0x1C) = (u8) reg_d0.b[0];
                if ((g_enemies_stopped == 0) && ((s16) ENTITY(reg_a6)->y.h >= 0x1000)) {
                    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
                    if (reg_d0.h[0] == 0) {
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
                        *(u8 *)(reg_a5 + 0x1D) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x1D) = 0x10U;
                            *(u16 *)(reg_a5 + 0x18) = 1U;
                        }
                    } else if ((reg_d0.h[0] & 0xFFFF) == 1) {
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                        *(u8 *)(reg_a5 + 0x23) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
                            *(u16 *)(reg_a5 + 0x20) += 4;
                            if (*(u16 *)(reg_a5 + 0x20) == 0x58) {
                                *(u16 *)(reg_a5 + 0x18) = 2U;
                            }
                            goto block_45;
                        }
                    } else if ((reg_d0.h[0] & 0xFFFF) == 2) {
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
                        *(u8 *)(reg_a5 + 0x1D) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x16);
                            reg_d7.h[0] = 0xF300;
                            reg_tmp7.h[0] = reg_d7.h[0];
                            reg_d7.h[0] = reg_d7.h[1];
                            reg_d7.h[1] = reg_tmp7.h[0];
                            reg_d7.h[0] = *(u16 *)(reg_a5 + 0x28);
                            if (!((u8) ENTITY(reg_a6)->flags.sb[0] & 0x40)) {
                                reg_d7.h[0] = 0xF100;
                                reg_tmp7.h[0] = reg_d7.h[0];
                                reg_d7.h[0] = reg_d7.h[1];
                                reg_d7.h[1] = reg_tmp7.h[0];
                                reg_d7.h[0] = *(u16 *)(reg_a5 + 0x2A);
                            }
                            temp_a3 = reg_d7.h[0];
                            temp_a3_2 = reg_d1.h[0] + temp_a3;
                            reg_d1.h[0] = temp_a3_2;
                            reg_tmp7.h[0] = temp_a3;
                            reg_d7.h[0] = reg_d7.h[1];
                            reg_d7.h[1] = reg_tmp7.h[0];
                            reg_tmp7.h[0] = reg_d7.h[0];
                            reg_d0.h[0] += reg_d7.h[0];
                            reg_d7.h[0] = reg_d7.h[1];
                            reg_d7.h[1] = reg_tmp7.h[0];
                            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x31);
                            reg_d0.b[0] = (s8) reg_d0.b[0] * 8;
                            if ((u8) ENTITY(reg_a6)->flags.sb[0] & 0x20) {
                                reg_d0.b[0] = *(u8 *)(reg_a5 + 0x33);
                                reg_d0.b[0] += reg_d0.b[0];
                                reg_d0.b[0] += 0x10;
                            }
                            reg_d1.h[0] = 0x40;
                            if (*(u8 *)(reg_a6 + 0x1D) == 0x40) {
                                reg_d1.h[0] = 0xC0;
                                reg_d0.b[0] *= -1;
                            }
                            temp_a0_2 = (u8) ENTITY(reg_a6)->flags.sb[0];
                            if (temp_a0_2 & 0x40) {
                                ENTITY(reg_a6)->flags.sb[0] = (s8) (temp_a0_2 & 0xBF);
                            } else {
                                ENTITY(reg_a6)->flags.sb[0] = (s8) (temp_a0_2 | 0x40);
                                reg_d0.b[0] *= -1;
                            }
                            reg_d1.b[0] += reg_d0.b[0];
                            reg_d0.w = 0x40005;
                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d3.w = reg_d7.w;
                            reg_d4.w = 0;
                            bullet_fire256_2way();
                            if ((u8) ENTITY(reg_a6)->flags.sb[0] & 0x20) {
                                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x33);
                                *(u8 *)(reg_a5 + 0x33) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    *(u8 *)(reg_a5 + 0x33) = (u8) *(u8 *)(reg_a5 + 0x32);
                                    ENTITY(reg_a6)->flags.b[0] &= 0xDF;
                                    *(u8 *)(reg_a5 + 0x31) = 0U;
                                    *(u8 *)(reg_a5 + 0x1D) = 0x10U;
                                    *(u16 *)(reg_a5 + 0x18) = 3U;
                                }
                            } else {
                                temp_v0 = *(u8 *)(reg_a5 + 0x1F);
                                if (temp_v0 != 0) {
                                    *(u8 *)(reg_a5 + 0x1F) = (u8) (temp_v0 - 1);
                                } else {
                                    *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
                                    *(u8 *)(reg_a5 + 0x1D) = 4U;
                                    *(u8 *)(reg_a5 + 0x31) += 1;
                                    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x31);
                                    if (*(u8 *)(reg_a5 + 0x30) == reg_d0.b[0]) {
                                        *(u8 *)(reg_a5 + 0x1D) = 0x10U;
                                        ENTITY(reg_a6)->flags.b[0] |= 0x20;
                                    }
                                }
                            }
                        }
                    } else {
                        temp_v0_2 = *(u8 *)(reg_a5 + 0x1D);
                        if (temp_v0_2 != 0) {
                            *(u8 *)(reg_a5 + 0x1D) = (u8) (temp_v0_2 - 1);
                        } else {
                            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                            *(u8 *)(reg_a5 + 0x23) -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
                                *(u16 *)(reg_a5 + 0x20) -= 4;
                                if (*(u16 *)(reg_a5 + 0x20) == 0x38) {
                                    reg_d0.h[0] = 0x40;
                                    reg_d0.h[0] -= g_rank_4_16;
                                    *(u8 *)(reg_a5 + 0x1D) = (u8) reg_d0.b[0];
                                    *(u16 *)(reg_a5 + 0x18) = 0U;
                                }
block_45:
                                reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
                                reg_a0 = (u8 *)D_00263DB0;
                                reg_a0 += reg_d0.h[0];
                                ENTITY(reg_a6)->draw.h = (u16) *(u16 *)reg_a0;
                                reg_a0 += 2;
                                ENTITY(reg_a6)->sprite.h = (u16) *(u16 *)reg_a0;
                                reg_a0 += 2;
                            }
                        }
                    }
                }
block_objset:
                func_0019BF40();
                reg_a0 = reg_a6;
                enemy_hitbox_debug_draw();
                return;
            }
            func_0018D580();
            reg_d0.w = 0x46;
            func_001A91A0();
            ENTITY(reg_a6)->flags.h = 0x8080;
            temp_a0_4 = *(u8 *)(reg_a5 + 0x1B);
            *(u8 *)(reg_a6 + 0x1C) = temp_a0_4;
            reg_d0.h[0] = 0xD;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            temp_a3_3 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a3_3;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(u16 *)(reg_a0 + 0x26) = 0xEC00;
            *(s16 *)(reg_a0 + 0x28) = 0;
            *(s16 *)(reg_a0 + 0x10) = 1;
            reg_d0.h[0] = 0xD;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            temp_a3_4 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a3_4;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(u16 *)(reg_a0 + 0x26) = 0xFC00;
            *(s16 *)(reg_a0 + 0x28) = 0;
            *(s16 *)(reg_a0 + 0x10) = 1;
            reg_d0.h[0] = 0x85;
            explosion_spawn();
            var_a0 = (u8 *)1;
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(s16 *)(reg_a0 + 0x26) = 0xC00;
            *(s16 *)(reg_a0 + 0x28) = 0;
            *(s16 *)(reg_a0 + 0x10) = 1;
            goto block_48;
        }
block_48:
        *(u16 *)(reg_a5 + 0x2E) -= 1;
        if ((s16) *(u16 *)(reg_a5 + 0x2E) >= 0) {
            goto block_objset;
        }
        enemy_remove();
    }
}

void func_001E2FD0(void) {
    func_0018D500();
    reg_d0.h[0] = 0xC;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 8;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    *(u16 *)(reg_a0 + 0x10) = 2;
}

void func_001E3050(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(1);
}

extern u8 D_00263E10[];
extern u8 D_00263E40[];

void func_001E3060(void) {
    u16 temp_a0;

    reg_a0 = D_00263E40;
    enemy_init_entities();
    reg_a0 = D_00263E10;
    reg_d0.w = 0x13;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        temp_a0 = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] = 0x1C00;
        reg_d7.h[0] = temp_a0;
        reg_d0.h[0] -= D_0029C068[0];
        ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
        func_002012F0();
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
        *(u16 *)(reg_a5 + 0x2C) = (u16) reg_d0.h[0];
        reg_d0.h[0] += 0x1C00;
        *(u16 *)(reg_a6 + 0x24) = (u16) reg_d0.h[0];
        rng_next_unsigned();
        if ((s8) reg_d0.b[0] < 0) {
            *(u16 *)(reg_a5 + 0x2A) *= 0xFFFF;
        }
        rng_next();
        reg_d0.h[0] += 7;
        reg_d0.h[0] += reg_d0.h[0];
        *(u8 *)(reg_a5 + 0x1D) -= reg_d0.b[0];
        reg_d0.h[0] = g_rank_4_16;
        *(u8 *)(reg_a5 + 0x1C) -= reg_d0.b[0];
    }
}

s32 func_00125EC0();
s32 bullet_fire256_fast();
s32 entity_follow_scroll();
extern u16 D_00263E80[];
extern u16 D_0028D9B8;
extern u16 D_0028D9C0;
extern u16 g_rank_2_16;
extern u16 g_loop;
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];
void func_001E3190(void) {
    u8 *temp;

    if (ENTITY(reg_a6)->flags.sb[0] < 0) goto block_explos;
    func_0014EA50();
    if (enemy_move_end_requested != 0) goto block_rts;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x7400;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0xE00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x7400;
    if (reg_tmp.h[1] == 0) goto next_30;
    if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_40;
    enemy_remove();
    return;
next_30:
    *(u8 *)(reg_a5 + 0x17) = 1;
next_40:
    *(u16 *)(reg_a6 + 0x22) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a6 + 0x24) = (u16) ENTITY(reg_a6)->x.h;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 0x21);
    if (reg_d1.b[0] != 0) goto next_50;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
    reg_d3.b[0] = *(u8 *)(reg_a5 + 0x27);
    if (!((s32) *(u16 *)(reg_a6 + 0x38) < 0x780)) goto next_90;
    if (D_0028E8B8 != 0) goto next_90;
    reg_d0.w = 0x19;
    reg_d3.w = 0x19;
    goto next_90;
next_50:
    *(u8 *)(reg_a6 + 0x21) &= 0xA3;
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    reg_d3.b[0] = *(u8 *)(reg_a6 + 0x3C);
    if (reg_d0.b[0] != 0x19) goto next_60;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
    reg_d3.b[0] = *(u8 *)(reg_a5 + 0x27);
next_60:
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1A);
    reg_d0.b[0] ^= reg_d2.b[0];
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x26);
    reg_d3.b[0] ^= reg_d2.b[0];
    if ((s16) *(u16 *)(reg_a6 + 0x38) < 0) goto block_dead;
next_90:
    *(u8 *)(reg_a6 + 0x1C) = (u8) reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x3C) = (u8) reg_d3.b[0];
    if (g_enemies_stopped != 0) goto block_objset;
    if ((s16) ENTITY(reg_a6)->y.h < 0x1000) goto block_move;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (reg_d0.h[0] != 0) goto next_200;
    func_001E3D60();
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
    *(u8 *)(reg_a5 + 0x1D) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_move;
    *(u8 *)(reg_a5 + 0x1D) = 0x10;
    *(u16 *)(reg_a5 + 0x18) = 1;
    goto block_move;
next_200:
    if ((reg_d0.h[0] & 0xFFFF) != 1) goto next_220;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
    *(u8 *)(reg_a5 + 0x23) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_move;
    *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
    *(u16 *)(reg_a5 + 0x20) += 4;
    if (*(u16 *)(reg_a5 + 0x20) != 0x1C) goto block_data_set;
    *(u16 *)(reg_a5 + 0x18) = 2;
    goto block_data_set;
next_220:
    if ((reg_d0.h[0] & 0xFFFF) != 2) goto next_360;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
    *(u8 *)(reg_a5 + 0x1D) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_objset;
    *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x16);
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1F);
    if (*(u8 *)(reg_a5 + 0x1E) != reg_d0.b[0]) goto next_280;
    reg_a0 = (u8 *)(D_0029F260_as_u16_a);
    reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
    if (*(u8 *)(reg_a5 + 2) == 0) goto next_240;
    reg_atmp = (u8 *)(reg_a0);
    reg_a0 = (u8 *)(reg_a1);
    reg_a1 = (u8 *)(reg_atmp);
next_240:
    if (*(s16 *)reg_a1 < 0) goto next_250;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x34);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x36);
    if (reg_tmp.w != 0) goto next_250;
    reg_a1 = (u8 *)(&D_0028D9B8);
    reg_tmp.w = (u32) reg_a1;
    *(u16 *)(reg_a5 + 0x34) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x36) = (u16) reg_tmp.h[0];
next_250:
    if (*(s16 *)reg_a0 < 0) goto next_260;
    if (*(s16 *)reg_a1 >= 0) goto next_300;
    temp = reg_a0;
    reg_a0 = (u8 *)(reg_a1);
    reg_atmp = (u8 *)(temp);
    reg_a1 = (u8 *)(temp);
next_260:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x800;
    reg_a1 = (u8 *)(&D_0028D9B8);
    if ((s32) reg_d0.h[0] > (s32) reg_d2.h[0]) goto next_270;
    reg_a1 = (u8 *)(&D_0028D9C0);
next_270:
    reg_tmp.w = (u32) reg_a1;
    *(u16 *)(reg_a5 + 0x34) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x36) = (u16) reg_tmp.h[0];
    reg_d1.h[0] += 0xFF00;
    reg_d1.h[0] += *(u16 *)(reg_a5 + 0x2C);
    direction256_between();
    *(u8 *)(reg_a5 + 0x29) = (u8) reg_d1.b[0];
next_280:
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x29);
    reg_d0.w = 0x80016;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.w = 0;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x34);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x36);
    reg_d3.w = 0x0800FB80;
    reg_a3 = (u8 *)(reg_tmp.w);
    reg_d3.h[0] += *(u16 *)(reg_a5 + 0x2C);
    reg_d1.h[0] += *(u16 *)reg_a3;
    reg_a3 += 2;
    bullet_fire256_fast();
    reg_d3.w = 0x08000280;
    reg_d3.h[0] += *(u16 *)(reg_a5 + 0x2C);
    reg_d1.h[0] += *(u16 *)reg_a3;
    reg_a3 += 2;
    bullet_fire256_fast();
    reg_d3.w = 0x06000280;
    reg_d3.h[0] += *(u16 *)(reg_a5 + 0x2C);
    reg_d1.h[0] += *(u16 *)reg_a3;
    reg_a3 += 2;
    bullet_fire256_fast();
    reg_d3.w = 0x0600FB80;
    reg_d3.h[0] += *(u16 *)(reg_a5 + 0x2C);
    reg_d1.h[0] += *(u16 *)reg_a3;
    reg_a3 += 2;
    bullet_fire256_fast();
next_300:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_objset;
    *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
    *(u8 *)(reg_a5 + 0x1D) = 1;
    *(u16 *)(reg_a5 + 0x18) = 3;
    goto block_objset;
next_360:
    if (*(u8 *)(reg_a5 + 0x1D) == 0) goto next_380;
    *(u8 *)(reg_a5 + 0x1D) -= 1;
    goto block_move;
next_380:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
    *(u8 *)(reg_a5 + 0x23) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_move;
    *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
    *(u16 *)(reg_a5 + 0x20) -= 4;
    if (*(u16 *)(reg_a5 + 0x20) != 0) goto block_data_set;
    reg_d0.h[0] = 0x80;
    reg_d0.h[0] -= g_rank_2_16;
    *(u8 *)(reg_a5 + 0x1D) = (u8) reg_d0.b[0];
    *(u16 *)(reg_a5 + 0x18) = 0;
    *(s8 *)(reg_a5 + 0x39) = 0x10;
    *(u8 *)(reg_a5 + 0x3B) = (u8) *(u8 *)(reg_a5 + 0x3A);
block_data_set:
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
    reg_a0 = (u8 *)(D_00263E80);
    reg_a0 += reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x2A) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x2C) = *(u16 *)reg_a0;
    reg_a0 += 2;
block_move:
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2A);
    if ((s16) reg_d0.h[0] >= 0) goto next_m100;
    *(u16 *)(reg_a5 + 0x2C) += reg_d0.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2C);
    if (!((s16) reg_d0.h[0] < -0x1400)) goto block_objset;
    *(u16 *)(reg_a5 + 0x2A) = 0x80;
    goto block_objset;
next_m100:
    *(u16 *)(reg_a5 + 0x2C) += reg_d0.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2C);
    if ((s16) reg_d0.h[0] <= 0x1400) goto block_objset;
    *(u16 *)(reg_a5 + 0x2A) = 0xFF80;
block_objset:
    func_0019BF40();
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2C);
    *(u16 *)(reg_a6 + 0x24) += reg_d0.h[0];
    reg_a6 += 0x20;
    func_0019BF40();
    reg_a0 = (u8 *)(reg_a6);
    enemy_hitbox_debug_draw();
    goto block_rts;
block_dead:
    func_0018D580();
    reg_d0.w = 0x88;
    func_001A91A0();
    ENTITY(reg_a6)->flags.h = 0x8080;
    *(u16 *)(reg_a6 + 0x20) = 0x8000;
    *(u8 *)(reg_a6 + 0x1C) = (u8) *(u8 *)(reg_a5 + 0x1B);
    *(u8 *)(reg_a6 + 0x3C) = (u8) *(u8 *)(reg_a5 + 0x27);
    if (g_loop != 0) goto next_d20;
    if (*(u16 *)(reg_a5 + 0x18) == 0) goto next_d20;
    reg_d1.w = 0;
    reg_d0.w = 0x4C;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x2C);
    reg_d2.h[0] = 4;
    func_00125EC0();
next_d20:
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0xC;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x26) = 0xFA00;
    *(u16 *)(reg_a0 + 0x28) = *(u16 *)(reg_a5 + 0x2C);
    *(s16 *)(reg_a0 + 0x10) = 2;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2C);
    reg_d1.h[0] = reg_d0.h[0];
    reg_d0.h[0] -= 0x800;
    *(u16 *)(reg_a5 + 0x30) = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x800;
    *(u16 *)(reg_a5 + 0x32) = (u16) reg_d1.h[0];
block_explos:
    entity_follow_scroll();
    *(u16 *)(reg_a6 + 0x22) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a6 + 0x24) = (u16) ENTITY(reg_a6)->x.h;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x2F);
    *(u8 *)(reg_a5 + 0x2F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_e90;
    *(u8 *)(reg_a5 + 0x2F) = (u8) *(u8 *)(reg_a5 + 0x2E);
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += *(u16 *)(reg_a5 + 0x30);
    if ((s16) reg_d0.h[0] < -0x800) goto next_e50;
    if (g_loop == 0) goto next_e3a;
    reg_d1.h[0] = 0x80;
    reg_d0.w = 0xFFF80013;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = 0;
    reg_d3.h[0] = *(u16 *)(reg_a5 + 0x30);
    reg_d4.w = 0;
    reg_d3.h[0] += 0x200;
    bullet_fire256_fixed();
    reg_d4.w = 0;
    reg_d3.h[0] -= 0x400;
    bullet_fire256_fixed();
next_e3a:
    func_001E2FD0();
    *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)(reg_a5 + 0x30);
    if (g_loop != 0) goto next_e3b;
    if (*(u16 *)(reg_a5 + 0x18) == 0) goto next_e3b;
    reg_d1.w = 0;
    reg_d0.w = 0x48;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x30);
    reg_d2.h[0] = 4;
    reg_d1.h[0] += 0x200;
    func_00125EC0();
    reg_d0.w = 0x48;
    reg_d1.w = 0;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x30);
    reg_d2.h[0] = 4;
    reg_d1.h[0] -= 0x200;
    func_00125EC0();
next_e3b:
    *(u16 *)(reg_a5 + 0x30) -= 0x800;
next_e50:
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += *(u16 *)(reg_a5 + 0x32);
    if (!((s32) reg_d0.h[0] < 0x4001)) goto next_e90;
    if (g_loop == 0) goto next_e4a;
    reg_d1.h[0] = 0x80;
    reg_d0.w = 0xFFF80013;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = 0;
    reg_d3.h[0] = *(u16 *)(reg_a5 + 0x32);
    reg_d4.w = 0;
    reg_d3.h[0] += 0x200;
    bullet_fire256_fixed();
    reg_d4.w = 0;
    reg_d3.h[0] -= 0x400;
    bullet_fire256_fixed();
next_e4a:
    func_001E2FD0();
    *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)(reg_a5 + 0x32);
    if (g_loop != 0) goto next_e4b;
    if (*(u16 *)(reg_a5 + 0x18) == 0) goto next_e4b;
    reg_d1.w = 0;
    reg_d0.w = 0x48;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x32);
    reg_d2.h[0] = 4;
    reg_d1.h[0] += 0x200;
    func_00125EC0();
    reg_d0.w = 0x48;
    reg_d1.w = 0;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x32);
    reg_d2.h[0] = 4;
    reg_d1.h[0] -= 0x200;
    func_00125EC0();
next_e4b:
    *(u16 *)(reg_a5 + 0x32) += 0x800;
next_e90:
    *(u16 *)(reg_a5 + 0x24) -= 1;
    if (*(u16 *)(reg_a5 + 0x24) != 0) goto block_objset;
    enemy_remove();
block_rts:
    return;
}


void func_001E3D60(void) {
    u32 tmp;
    s32 tmp2;

    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x39);
    *(u8 *)(reg_a5 + 0x39) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    reg_d0.h[0] = 0x12;
    if (g_loop == 0) goto next_1;
    reg_d0.h[0] += 4;
next_1:
    *(u8 *)(reg_a5 + 0x39) = reg_d0.b[0];
    reg_a0 = (u8 *)D_0029F260_as_u16_a;
    reg_a1 = (u8 *)D_0029F1F0_as_u16_a;
    if (*(u8 *)(reg_a5 + 2) == 0) goto next_2;
    reg_atmp = reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *)reg_atmp;
next_2:
    if (*(s16 *)reg_a0 < 0) goto next_3;
    if (*(s16 *)reg_a1 >= 0) goto block_rts;
    reg_atmp = reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *)reg_atmp;
next_3:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d5.h[0] = 0;
    reg_d0.h[0] += reg_d5.h[0];
    reg_tmp5.h[0] = reg_d5.h[0];
    reg_d5.h[0] = 0xFF00;
    reg_d5.h[1] = reg_tmp5.h[0];
    reg_d5.h[0] += *(u16 *)(reg_a5 + 0x2C);
    reg_d1.h[0] += reg_d5.h[0];
    direction256_between();
    reg_d0.w = 0xFFFD0013;
    reg_d7.w = 1;
    reg_d1.h[0] = 0x75;
    if (g_loop == 0) goto loop_4;
    reg_d1.h[0] = 0x70;
loop_4:
    reg_d6.w = 3;
loop_5:
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = reg_d5.w;
    reg_d4.w = 0;
    bullet_fire256_2way();
    reg_d1.h[0] += 2;
    tmp2 = reg_d6.h[0] - 1;
    reg_d6.h[0] = tmp2;
    if (((s64) ((s64) (u16) tmp2 << 0x30) >> 0x30) >= 0) goto loop_5;
    reg_d1.h[0] += 0xA;
    if (g_loop == 0) goto next_6;
    reg_d1.h[0] += 0xA;
next_6:
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_4;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x3B);
    *(u8 *)(reg_a5 + 0x3B) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    *(u8 *)(reg_a5 + 0x3B) = *(u8 *)(reg_a5 + 0x3A);
    *(u8 *)(reg_a5 + 0x39) = *(u8 *)(reg_a5 + 0x38);
block_rts:
    return;
}

void func_001E3FB0(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 func_00201230();
s32 func_002013F0();
extern u16 D_00263EA0[];
extern u16 D_00263EB8[];
extern u16 D_00263ED0[];

void func_001E3FC0(void) {
    reg_a0 = (u8 *)(D_00263ED0);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_00263EB8);
    reg_d0.w = 6;
    enemy_set_task_work();
    reg_tmp.w = 0x1C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
    func_002013F0();
    *(u16 *)(reg_a5 + 0x20) = (u16) reg_d0.h[0];
    rng_next();
    reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
    reg_d0.b[0] += 0x70;
    ENTITY(reg_a6)->move.b.speed = (u8) reg_d0.b[0];
    rng_next_unsigned();
    reg_d0.h[0] &= 0x7F;
    reg_d0.b[0] += 0x40;
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d0.b[0];
    func_00201230();
    reg_a0 = (u8 *)(D_00263EA0);
    reg_d0.h[0] *= 8;
    reg_a0 += reg_d0.h[0];
    ENTITY(reg_a6)->draw.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->sprite.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a5 + 0x16) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a5 + 0x18) = (u16) *(u16 *)reg_a0;
    reg_d0.w = 0;
    reg_a0 += 2;
    func_00201270();
    reg_tmp.h[1] = ENTITY(reg_a6)->draw.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->sprite.h;
    reg_tmp.w += reg_d0.w;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
}

s32 func_00201FC0();
s32 func_00202040();

void func_001E4160(u8 *arg0, u8 *arg1) {
    u8 *t1;
    u8 *t2;

    t1 = (u8 *)(arg0);
    t2 = (u8 *)(arg1);
    if (g_enemies_stopped == 0) {
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x24);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x26);
        reg_a0 = (u8 *)reg_tmp.w;
        reg_d0.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[0] = *(u16 *)(reg_a0 + 4);
        reg_d0.h[0] += *(u16 *)(reg_a5 + 0x28);
        reg_d1.h[0] += *(u16 *)(reg_a5 + 0x20);
        ENTITY(reg_a6)->y.h = (u16) reg_d0.h[0];
        ENTITY(reg_a6)->x.h = (u16) reg_d1.h[0];
        reg_d4.w = 1;
        func_00201FC0();
        ENTITY(reg_a6)->y.h += reg_d2.h[0];
        reg_d1.w = 0;
        reg_d0.w = 0;
        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        reg_d4.w = 3;
        func_00202040();
        t2 = (u8 *)(reg_a5);
        reg_tmp.h[1] = (*(u16 *)((u8 *)(t2) + (0x24)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(t2) + (0x26)));
        reg_a0 = (u8 *)reg_tmp.w;
        reg_d0.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[0] = *(u16 *)(reg_a0 + 4);
        reg_d0.h[0] += (*(u16 *)((u8 *)(t2) + (0x28)));
        reg_d1.h[0] += (*(u16 *)((u8 *)(t2) + (0x20)));
        (*(u16 *)((u8 *)(t2) + (0x1C))) = (u16) reg_d0.h[0];
        *(u16 *)(reg_a5 + 0x1E) = (u16) reg_d1.h[0];
        *(u16 *)(reg_a5 + 0x1C) += reg_d2.h[0];
        t1 = (u8 *)(reg_a5);
        (*(u16 *)((u8 *)(t1) + (0x1E))) += reg_d3.h[0];
        reg_tmp.b[0] = ENTITY(reg_a6)->move.b.speed;
        ENTITY(reg_a6)->move.b.speed -= 4;
        if ((s32) reg_tmp.b[0] < 4) {
            enemy_remove();
            return;
        }
    }
    *(u8 *)(reg_a6 + 0x1D) ^= 0x60;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
    *(u8 *)(reg_a5 + 0x1B) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_100;
    *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
    reg_tmp.h[1] = ENTITY(reg_a6)->draw.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->sprite.h;
    reg_tmp.w += 1;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_d0.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (reg_tmp.w != reg_d0.w) goto next_200;
    enemy_remove();
    return;
next_100:
    func_0019BF80();
    return;
next_200:
    func_0019BF80();
    reg_d1.h[1] = *(u16 *)(reg_a5 + 0x1C);
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x1E);
    reg_tmp.h[1] = ENTITY(reg_a6)->offset_y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->offset_x.h;
    reg_d1.w += reg_tmp.w;
    reg_d2.h[1] = ENTITY(reg_a6)->draw.h;
    reg_d2.h[0] = ENTITY(reg_a6)->sprite.h;
    reg_d3.h[0] = ENTITY(reg_a6)->look.h;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
    func_0019C530();
}

s32 func_0019BF80();                            /* extern */
extern u32 reg_a6_as_u32;

void func_001E4410(void) {
    reg_a6_as_u32 += 0x20;
    func_0019BF80();
    reg_a6_as_u32 += 0x20;
    func_0019BF80();
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
    reg_a6_as_u32 = reg_tmp.w;
}

s32 func_0018D580();                            /* extern */
s32 func_001A91A0();                            /* extern */

void func_001E4460(void) {
    reg_d0.w = 0x385;
    func_001A91A0();
    func_0018D580();
    func_001E4490();
}


void func_001E4490(void) {
    *(u16 *)(reg_a6 + 0x20) = 0x8080;
    reg_a6 += 0x20;
    func_001DF350();
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
    reg_a6 = (void *) reg_tmp.w;
    *(u8 *)(reg_a6 + 0x3C) = (u8) *(u8 *)(reg_a5 + 0x1B);
}


void func_001E44F0(void) {
    reg_d0.w = 0x385;
    func_001A91A0();
    func_0018D580();
    func_001E4520();
}

void func_001E4520(void) {
    *(u16 *)(reg_a6 + 0x40) = 0x8080;
    reg_a6 += 0x40;
    func_001DF350();
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
    reg_a6 = (void *) reg_tmp.w;
    *(u8 *)(reg_a6 + 0x5C) = (u8) *(u8 *)(reg_a5 + 0x1B);
}
