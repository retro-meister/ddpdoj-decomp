#include "common.h"
#include "entity.h"

void stage1_boss_draw_right_side(void);
void stage1_boss_draw_left_side(void);
void stage1_boss_draw_body(void);
void stage1_boss_draw_gatling(void);
void stage1_boss_draw_core(void);
void stage1_boss_draw_turrets(void);
void stage1_boss_draw_entrance_part(void);
s32 sprite_draw_layer3_keep();
s32 sprite_draw_layer5_keep();
s32 sprite_draw_layer2_zoom_keep();
s32 sprite_draw_layer3_zoom_keep();
s32 sprite_draw_layer4_zoom_keep();

/* The draw routine of every part of the boss, by part number. */
void (*stage1_boss_draw_routines[])(void) = {
    stage1_boss_draw_right_side,
    stage1_boss_draw_left_side,
    stage1_boss_draw_body,
    stage1_boss_draw_gatling,
    stage1_boss_draw_core,
    stage1_boss_draw_turrets,
    stage1_boss_draw_entrance_part,
    (void (*)(void))-1,
};

/* The draw routine of a side part by the angle of its rotor, in steps of 32. */
s32 (*stage1_boss_rotor_draw_routines[])() = {
    sprite_draw_layer4_zoom_keep,
    sprite_draw_layer4_zoom_keep,
    sprite_draw_layer3_zoom_keep,
    sprite_draw_layer2_zoom_keep,
    sprite_draw_layer2_zoom_keep,
    sprite_draw_layer2_zoom_keep,
    sprite_draw_layer4_zoom_keep,
    sprite_draw_layer4_zoom_keep,
};

u16 stage1_boss_rotor_offsets[] = {
    0xC000, 0xC000, 0xB800, 0xB800, 0xB000, 0xB000, 0xA800, 0xA800,
    0xA000, 0xA000, 0x9800, 0x9800, 0x9000, 0x9000, 0x8800, 0x8800,
    0x8000, 0x8000, 0x7800, 0x7800, 0x7000, 0x7000, 0x6800, 0x6800,
    0x6000, 0x6000, 0x5800, 0x5800, 0x5000, 0x5000, 0x4800, 0x4800,
    0x4000, 0x4000, 0x4800, 0x4800, 0x5000, 0x5000, 0x5800, 0x5800,
    0x6000, 0x6000, 0x6800, 0x6800, 0x7000, 0x7000, 0x7800, 0x7800,
    0x8000, 0x8000, 0x8800, 0x8800, 0x9000, 0x9000, 0x9800, 0x9800,
    0xA000, 0xA000, 0xA800, 0xA800, 0xB000, 0xB000, 0xB800, 0xB800,
};

u16 stage1_boss_right_side_sprites[] = {
    0x0000, 0x197F, 0x0000, 0x1980, 0x0000, 0x1981, 0x0000, 0x1982,
    0x0000, 0x1983, 0x0000, 0x1984, 0x0000, 0x1985, 0x0000, 0x1986,
    0x0000, 0x1987, 0x0000, 0x1988, 0x0000, 0x1989, 0x0000, 0x198A,
    0x0000, 0x198B, 0x0000, 0x198C, 0x0000, 0x198D, 0x0000, 0x198E,
    0x0000, 0x198F, 0x0000, 0x1990, 0x0000, 0x1991, 0x0000, 0x1992,
    0x0000, 0x1993, 0x0000, 0x1994, 0x0000, 0x1995, 0x0000, 0x1996,
    0x0000, 0x1997, 0x0000, 0x1998, 0x0000, 0x1999, 0x0000, 0x199A,
    0x0000, 0x199B, 0x0000, 0x199C, 0x0000, 0x199D, 0x0000, 0x199E,
};

u16 stage1_boss_left_side_sprites[] = {
    0x0000, 0x195F, 0x0000, 0x1960, 0x0000, 0x1961, 0x0000, 0x1962,
    0x0000, 0x1963, 0x0000, 0x1964, 0x0000, 0x1965, 0x0000, 0x1966,
    0x0000, 0x1967, 0x0000, 0x1968, 0x0000, 0x1969, 0x0000, 0x196A,
    0x0000, 0x196B, 0x0000, 0x196C, 0x0000, 0x196D, 0x0000, 0x196E,
    0x0000, 0x196F, 0x0000, 0x1970, 0x0000, 0x1971, 0x0000, 0x1972,
    0x0000, 0x1973, 0x0000, 0x1974, 0x0000, 0x1975, 0x0000, 0x1976,
    0x0000, 0x1977, 0x0000, 0x1978, 0x0000, 0x1979, 0x0000, 0x197A,
    0x0000, 0x197B, 0x0000, 0x197C, 0x0000, 0x197D, 0x0000, 0x197E,
};

u16 stage1_boss_gatling_sprites[] = {
    0x0000, 0x1A0F, 0x0000, 0x1A10, 0x0000, 0x1A11, 0x0000, 0x1A12,
    0x0000, 0x1A13, 0x0000, 0x1A14, 0x0000, 0x1A15, 0x0000, 0x1A16,
    0x0000, 0x1A07, 0x0000, 0x1A08, 0x0000, 0x1A09, 0x0000, 0x1A0A,
    0x0000, 0x1A0B, 0x0000, 0x1A0C, 0x0000, 0x1A0D, 0x0000, 0x1A0E,
    0x0000, 0x19FF, 0x0000, 0x1A00, 0x0000, 0x1A01, 0x0000, 0x1A02,
    0x0000, 0x1A03, 0x0000, 0x1A04, 0x0000, 0x1A05, 0x0000, 0x1A06,
    0x0000, 0x19F7, 0x0000, 0x19F8, 0x0000, 0x19F9, 0x0000, 0x19FA,
    0x0000, 0x19FB, 0x0000, 0x19FC, 0x0000, 0x19FD, 0x0000, 0x19FE,
    0x0000, 0x19EF, 0x0000, 0x19F0, 0x0000, 0x19F1, 0x0000, 0x19F2,
    0x0000, 0x19F3, 0x0000, 0x19F4, 0x0000, 0x19F5, 0x0000, 0x19F6,
    0x0000, 0x19E7, 0x0000, 0x19E8, 0x0000, 0x19E9, 0x0000, 0x19EA,
    0x0000, 0x19EB, 0x0000, 0x19EC, 0x0000, 0x19ED, 0x0000, 0x19EE,
    0x0000, 0x19DF, 0x0000, 0x19E0, 0x0000, 0x19E1, 0x0000, 0x19E2,
    0x0000, 0x19E3, 0x0000, 0x19E4, 0x0000, 0x19E5, 0x0000, 0x19E6,
    0x0000, 0x19D7, 0x0000, 0x19D8, 0x0000, 0x19D9, 0x0000, 0x19DA,
    0x0000, 0x19DB, 0x0000, 0x19DC, 0x0000, 0x19DD, 0x0000, 0x19DE,
    0x0000, 0x19CF, 0x0000, 0x19D0, 0x0000, 0x19D1, 0x0000, 0x19D2,
    0x0000, 0x19D3, 0x0000, 0x19D4, 0x0000, 0x19D5, 0x0000, 0x19D6,
    0x0000, 0x19C7, 0x0000, 0x19C8, 0x0000, 0x19C9, 0x0000, 0x19CA,
    0x0000, 0x19CB, 0x0000, 0x19CC, 0x0000, 0x19CD, 0x0000, 0x19CE,
    0x0000, 0x19BF, 0x0000, 0x19C0, 0x0000, 0x19C1, 0x0000, 0x19C2,
    0x0000, 0x19C3, 0x0000, 0x19C4, 0x0000, 0x19C5, 0x0000, 0x19C6,
    0x0000, 0x19B7, 0x0000, 0x19B8, 0x0000, 0x19B9, 0x0000, 0x19BA,
    0x0000, 0x19BB, 0x0000, 0x19BC, 0x0000, 0x19BD, 0x0000, 0x19BE,
    0x0000, 0x19AF, 0x0000, 0x19B0, 0x0000, 0x19B1, 0x0000, 0x19B2,
    0x0000, 0x19B3, 0x0000, 0x19B4, 0x0000, 0x19B5, 0x0000, 0x19B6,
    0x0000, 0x19A7, 0x0000, 0x19A8, 0x0000, 0x19A9, 0x0000, 0x19AA,
    0x0000, 0x19AB, 0x0000, 0x19AC, 0x0000, 0x19AD, 0x0000, 0x19AE,
    0x0000, 0x199F, 0x0000, 0x19A0, 0x0000, 0x19A1, 0x0000, 0x19A2,
    0x0000, 0x19A3, 0x0000, 0x19A4, 0x0000, 0x19A5, 0x0000, 0x19A6,
};

u16 stage1_boss_core_sprite[] = {
    0x0000, 0x1A17, 0x0000, 0x1A18, 0x0000, 0x1A19,
};

u16 stage1_boss_turret_sprites[] = {
    0x0000, 0x1A1A, 0x0000, 0x1A1B, 0x0000, 0x1A1C, 0x0000, 0x1A1D,
    0x0000, 0x1A1E, 0x0000, 0x1A1F, 0x0000, 0x1A20, 0x0000, 0x1A21,
    0x0000, 0x1A22, 0x0000, 0x1A23, 0x0000, 0x1A24, 0x0000, 0x1A25,
    0x0000, 0x1A26, 0x0000, 0x1A27, 0x0000, 0x1A28, 0x0000, 0x1A29,
    0x0000, 0x1A2A, 0x0000, 0x1A2B, 0x0000, 0x1A2C, 0x0000, 0x1A2D,
    0x0000, 0x1A2E, 0x0000, 0x1A2F, 0x0000, 0x1A30, 0x0000, 0x1A31,
    0x0000, 0x1A32, 0x0000, 0x1A33, 0x0000, 0x1A34, 0x0000, 0x1A35,
    0x0000, 0x1A36, 0x0000, 0x1A37, 0x0000, 0x1A38, 0x0000, 0x1A39,
};

u16 stage1_boss_entrance_part_frames[] = {
    0x0000, 0x1A5B, 0xE600, 0xEE00, 0x1A90, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A5C, 0xE600, 0xEE00, 0x1A90, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A5D, 0xE600, 0xEE00, 0x1A90, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A5E, 0xE600, 0xEE00, 0x1A90, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A5F, 0xE600, 0xEE00, 0x1A90, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A60, 0xE600, 0xEE00, 0x1A90, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A61, 0xE600, 0xEE00, 0x1A90, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A62, 0xE600, 0xEE00, 0x1A90, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A63, 0xE600, 0xEE00, 0x1A90, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A64, 0xE600, 0xEE00, 0x1A90, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A65, 0xE600, 0xEE00, 0x1A90, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A66, 0xE600, 0xEE00, 0x1A90, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A67, 0xE000, 0xE500, 0x20D8, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A68, 0xE000, 0xE500, 0x20D8, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A69, 0xE000, 0xE500, 0x20D8, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A6A, 0xE000, 0xE500, 0x20D8, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A6B, 0xE000, 0xE500, 0x20D8, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A6C, 0xE000, 0xE500, 0x20D8, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A6D, 0xE000, 0xE500, 0x20D8, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A6E, 0xE000, 0xE500, 0x20D8, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A6F, 0xE000, 0xE500, 0x20D8, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A70, 0xE000, 0xE500, 0x20D8, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A71, 0xE000, 0xE500, 0x20D8, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1A72, 0xE000, 0xE500, 0x20D8,
};


void stage1_boss_draw_body(void)
{
    reg_d2.w = 0x195E;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xE600F400U;
    reg_d3.h[0] = 0x1A60;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    sprite_draw_layer3_keep();
}

typedef void (*Fn)();


void stage1_boss_draw_right_side(void) {
    u16 temp_a1;
    reg_a2 = (u8 *)(stage1_boss_right_side_sprites);
    reg_d2.h[0] = ENTITY(reg_a6)[1].draw.h;
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_d1.h[1] = ENTITY(reg_a6)[1].y.h;
    temp_a1 = ENTITY(reg_a6)[1].x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xEC00F400;
    reg_d3.h[0] = 0x1460;
    reg_d4.h[0] = ENTITY(reg_a6)[1].attr.h;
    if (ENTITY(reg_a6)[1].misc.b.draw_layer == 0) {
        reg_d0.w = 0;
        reg_d0.b[0] = ENTITY(reg_a6)[2].draw.b.flip;
        reg_a0 = (u8 *)(stage1_boss_rotor_offsets);
        reg_d0.b[0] = (u8) ((s32) reg_d0.b[0] >> 3);
        reg_d0.h[0] = (u16) reg_d0.b[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        ENTITY(reg_a6)[2].offset_y.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)[2].offset_x.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    }
    reg_d6.h[1] = ENTITY(reg_a6)[2].offset_y.h;
    reg_d6.h[0] = ENTITY(reg_a6)[2].offset_x.h;
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)[2].draw.b.flip;
    if (reg_d0.b[0] != 0xC0) {
        reg_d0.b[0] = (u8) ((s32) (reg_d0.b[0] & 0xFF) >> 5);
        reg_d0.h[0] = (u16) reg_d0.b[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        ((Fn)*(u32 *)((u8 *)stage1_boss_rotor_draw_routines + (reg_d0.h[0] & ~3)))();
        return;
    }
    sprite_draw_layer3_zoom_keep();
}


void stage1_boss_draw_left_side(void) {
    u16 temp_a1;
    reg_a2 = (u8 *)(stage1_boss_left_side_sprites);
    reg_d2.h[0] = ENTITY(reg_a6)[3].draw.h;
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_d1.h[1] = ENTITY(reg_a6)[3].y.h;
    temp_a1 = ENTITY(reg_a6)[3].x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xEC00F400;
    reg_d3.h[0] = 0x1460;
    reg_d4.h[0] = ENTITY(reg_a6)[3].attr.h;
    if (ENTITY(reg_a6)[3].misc.b.draw_layer == 0) {
        reg_d0.w = 0;
        reg_d0.b[0] = ENTITY(reg_a6)[4].draw.b.flip;
        reg_a0 = (u8 *)(stage1_boss_rotor_offsets);
        reg_d0.b[0] = (u8) ((s32) reg_d0.b[0] >> 3);
        reg_d0.h[0] = (u16) reg_d0.b[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        ENTITY(reg_a6)[4].offset_y.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)[4].offset_x.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    }
    reg_d6.h[1] = ENTITY(reg_a6)[4].offset_y.h;
    reg_d6.h[0] = ENTITY(reg_a6)[4].offset_x.h;
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)[4].draw.b.flip;
    if (reg_d0.b[0] != 0xC0) {
        reg_d0.b[0] = (u8) ((s32) (reg_d0.b[0] & 0xFF) >> 5);
        reg_a0 = (u8 *)stage1_boss_rotor_draw_routines;
        reg_d0.h[0] = (u16) reg_d0.b[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        ((Fn)*(u32 *)((u8 *)stage1_boss_rotor_draw_routines + (reg_d0.h[0] & ~3)))();
    }
    sprite_draw_layer3_zoom_keep();
}

void stage1_boss_draw_gatling(void) {
    u16 temp_a0;

    reg_a2 = ((u8 *)stage1_boss_gatling_sprites);
    reg_d2.h[0] = ENTITY(reg_a6)[5].sprite.h;
    reg_d2.h[0] += 7;
    reg_d2.h[0] = reg_d2.b[0] << 5;
    reg_a2 += reg_d2.h[0];
    reg_a2 += ENTITY(reg_a6)[5].draw.h;
    reg_d2.h[1] = *(u16 *)reg_a2;
    reg_d2.h[0] = *(u16 *)(reg_a2 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)[5].y.h;
    temp_a0 = ENTITY(reg_a6)[5].x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF600F800;
    reg_d3.h[0] = 0xA40;
    reg_d4.h[0] = ENTITY(reg_a6)[5].attr.h;
    sprite_draw_layer3_keep();
}

void stage1_boss_draw_core(void) {
    reg_a2 = (u8 *)((u16 *)stage1_boss_core_sprite);
    reg_d2.h[1] = *(u16 *)reg_a2;
    reg_d2.h[0] = *(u16 *)(reg_a2 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFC00FC00U;
    reg_d1.w += 0xF2000000U;
    reg_d3.h[0] = 0x420;
    reg_d4.h[0] = 0x15;
    sprite_draw_layer3_keep();
}

void stage1_boss_draw_turrets(void) {
    reg_d2.w = 0;
    reg_d2.b[0] = ENTITY(reg_a6)[6].offset_y.b[1];
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)stage1_boss_turret_sprites + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)stage1_boss_turret_sprites;
    reg_d2.h[0] = ((((u16)reg_d2.h[0]) + 2) != 0) ? *(u16 *)((u8 *)stage1_boss_turret_sprites + ((s16)(((u16)reg_d2.h[0]) + 2) & ~1)) : *(u16 *)stage1_boss_turret_sprites;
    reg_d3.h[0] = 0x418;
    reg_d4.h[0] = 0x17;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFC00FD00;
    reg_d0.w = reg_d1.w;
    reg_d1.w += 0x09C00400;
    sprite_draw_layer3_keep();
    reg_d2.w = 0;
    reg_d2.b[0] = ENTITY(reg_a6)[6].offset_y.b[0];
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)stage1_boss_turret_sprites + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)stage1_boss_turret_sprites;
    reg_d2.h[0] = ((((u16)reg_d2.h[0]) + 2) != 0) ? *(u16 *)((u8 *)stage1_boss_turret_sprites + ((s16)(((u16)reg_d2.h[0]) + 2) & ~1)) : *(u16 *)stage1_boss_turret_sprites;
    reg_d1.w = reg_d0.w;
    reg_d1.w += 0x09BFFC40;
    sprite_draw_layer3_keep();
    reg_d2.w = 0;
    reg_d2.b[0] = ENTITY(reg_a6)[6].offset_x.b[1];
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)stage1_boss_turret_sprites + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)stage1_boss_turret_sprites;
    reg_d2.h[0] = ((((u16)reg_d2.h[0]) + 2) != 0) ? *(u16 *)((u8 *)stage1_boss_turret_sprites + ((s16)(((u16)reg_d2.h[0]) + 2) & ~1)) : *(u16 *)stage1_boss_turret_sprites;
    reg_d1.w = reg_d0.w;
    reg_d1.w += 0x0F400600;
    sprite_draw_layer3_keep();
    reg_d2.w = 0;
    reg_d2.b[0] = ENTITY(reg_a6)[6].offset_x.b[0];
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)stage1_boss_turret_sprites + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)stage1_boss_turret_sprites;
    reg_d2.h[0] = ((((u16)reg_d2.h[0]) + 2) != 0) ? *(u16 *)((u8 *)stage1_boss_turret_sprites + ((s16)(((u16)reg_d2.h[0]) + 2) & ~1)) : *(u16 *)stage1_boss_turret_sprites;
    reg_d1.w = reg_d0.w;
    reg_d1.w += 0x0F3FF9C0;
    sprite_draw_layer3_keep();
}


void stage1_boss_draw_entrance_part(void) {
    u32 temp_a0;

    reg_a2 = ((u8 *)stage1_boss_entrance_part_frames);
    reg_a2 += ENTITY(reg_a6)[8].move.h;
    reg_d2.h[1] = *(u16 *)reg_a2;
    reg_d2.h[0] = *(u16 *)(reg_a2 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xF8000080;
    if ((s16) ENTITY(reg_a6)[8].move.h < 0xB1) {
        reg_d1.w += 0xFE000100;
    }
    temp_a0 = reg_d1.w;
    reg_tmp.h[1] = *(u16 *)(reg_a2 + 4);
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 6);
    reg_d1.w = temp_a0 + reg_tmp.w;
    reg_d3.h[0] = *(u16 *)(reg_a2 + 8);
    reg_d4.h[0] = 0x13;
    sprite_draw_layer5_keep();
}
