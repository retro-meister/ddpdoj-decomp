#include "common.h"
#include "entity.h"

void func_0011CA20(void);
void func_0011CB20(void);
void func_0011CC10(void);
void func_0011CD00(void);
void func_0011CDF0(void);
void func_0011CEE0(void);
void func_0011CFD0(void);
void func_0011D0C0(void);
void func_0011D1B0(void);
void func_0011D2A0(void);
void func_0011D390(void);
void func_0011D450(void);

extern u32 D_002A17C0[];
extern u8 D_002A3C80[];
extern u8 g_text_layer[];

void func_0011C7C0(void) {
    u8 *a0;
    u32 d0;
    u32 d1;
    u32 d2;
    u32 d3;
    u32 d4;
    u32 d5;
    u32 d6;
    u32 d7;
    u32 t;
    s32 t2;

    d0 = reg_d0.w;
    d1 = reg_d1.w;
    d2 = reg_d2.w;
    d3 = reg_d3.w;
    d4 = reg_d4.w;
    d5 = reg_d5.w;
    d6 = reg_d6.w;
    d7 = reg_d7.w;
    a0 = reg_a0;
    reg_a0 = (u8 *)D_002A17C0[0];
    reg_tmp.w = (u32)reg_a0;
    if (reg_tmp.w == (u32)D_002A3C80) goto block_rts;
    reg_d4.w = 0;
    reg_d5.w = 0;
loop_1:
    reg_d6.h[0] = reg_d1.h[0];
    reg_d7.h[0] = reg_d3.h[0];
loop_2:
    reg_tmp.w = (u32)g_text_layer;
    *(u32 *)reg_a0 = (u32)g_text_layer;
    reg_d5.h[0] = reg_d6.h[0];
    reg_d5.h[0] += reg_d0.h[0];
    reg_tmp.w += reg_d5.w;
    *(u32 *)reg_a0 = reg_tmp.w;
    reg_a0 += 4;
    *(u32 *)reg_a0 = reg_d4.w;
    reg_a0 += 4;
    reg_d6.h[0] += 0x100;
    t2 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t2;
    if (((s64) ((s64) (u16) t2 << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_d0.h[0] -= 4;
    t = reg_d2.h[0] - 1;
    reg_d2.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    *(u32 *)reg_a0 = -1;
    D_002A17C0[0] = (u32)reg_a0;
block_rts:
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_d3.w = d3;
    reg_d4.w = d4;
    reg_d5.w = d5;
    reg_d6.w = d6;
    reg_d7.w = d7;
    reg_a0 = a0;
}

extern s32 D_0028E0D4_as_s32;
extern s32 *D_002A17C0_as_s32_p_a[];
extern s32 D_002A2400_as_s32_a[];

void func_0011C920(void) {
    D_002A2400_as_s32_a[0] = -1;
    reg_d0.w = 0;
    D_0028E0D4_as_s32 = 0;
    D_002A17C0_as_s32_p_a[0] = D_002A2400_as_s32_a;
}

extern u32 D_002A2400[];
extern u32 *reg_a0_as_u32_p;
extern u32 *reg_a1_as_u32_p;

void func_0011C950(void) {
    reg_a0_as_u32_p = D_002A2400;
    reg_d0.h[0] = 0x30F;
loop_1:
    reg_tmp.w = *reg_a0_as_u32_p;
    reg_a0_as_u32_p += 1;
    if (reg_tmp.w != -1U) {
        reg_a1_as_u32_p = (u32 *)(reg_tmp.w);
        *reg_a1_as_u32_p = (u32) *reg_a0_as_u32_p;
        reg_a0_as_u32_p += 1;
        goto loop_1;
    }
    func_0011C920();
}


void func_0011C9C0(void) {
    reg_tmp.w = 0x1AC0;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x24D0;
    reg_tmp.w = (u32) (u32)func_0011CA20;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x14;
}

s32 func_00171330(s32 *);
s32 entity_release();
s32 entity_follow_scroll();
extern u8 D_0028E290;
extern u8 D_0028E2C8;
extern u16 g_enemy_signal_1;
extern u8 D_0028ED80;
extern void sprite_draw_layer3();

void func_0011CA20(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    if ((g_enemy_signal_1 != 0) || (reg_d0.h[0] = ENTITY(reg_a6)->y.h, (((s16) reg_d0.h[0] < -0x4800) != 0))) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)sprite_draw_layer3);
}


void func_0011CAC0(void) {
    reg_tmp.w = 0x1AC1;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x1470;
    reg_tmp.w = (u32) (u32)func_0011CB20;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x13;
}

void func_0011CB20(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x2800) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)sprite_draw_layer3);
}


void func_0011CBB0(void) {
    reg_tmp.w = 0x1AC2;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x1690;
    reg_tmp.w = (u32) (u32)func_0011CC10;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x13;
}

void func_0011CC10(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x2BFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)sprite_draw_layer3);
}


void func_0011CCA0(void) {
    reg_tmp.w = 0x1AC3;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x26A8;
    reg_tmp.w = (u32) (u32)func_0011CD00;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

void func_0011CD00(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x4BFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)sprite_draw_layer3);
}


void func_0011CD90(void) {
    reg_tmp.w = 0x1AC4;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x26B0;
    reg_tmp.w = (u32) (u32)func_0011CDF0;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x16;
}

void func_0011CDF0(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x4BFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)sprite_draw_layer3);
}


void func_0011CE80(void) {
    reg_tmp.w = 0x1AC5;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x2860;
    reg_tmp.w = (u32) (u32)func_0011CEE0;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x12;
}

void func_0011CEE0(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x4FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)sprite_draw_layer3);
}


void func_0011CF70(void) {
    reg_tmp.w = 0x1AC6;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x28C0;
    reg_tmp.w = (u32) (u32)func_0011CFD0;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x12;
}

void func_0011CFD0(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x4FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)sprite_draw_layer3);
}


void func_0011D060(void) {
    reg_tmp.w = 0x1AC7;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x2660;
    reg_tmp.w = (u32) (u32)func_0011D0C0;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x12;
}

void func_0011D0C0(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x4BFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)sprite_draw_layer3);
}


void func_0011D150(void) {
    reg_tmp.w = 0x1AC8;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x2A70;
    reg_tmp.w = (u32) (u32)func_0011D1B0;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x13;
}

void func_0011D1B0(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x53FF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)sprite_draw_layer3);
}


void func_0011D240(void) {
    reg_tmp.w = 0x1AC9;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x2A70;
    reg_tmp.w = (u32) (u32)func_0011D2A0;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x13;
}

void func_0011D2A0(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        entity_release();
        return;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x53FF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)sprite_draw_layer3);
}


void func_0011D330(void) {
    reg_tmp.w = 0x1ACA;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x1E80;
    reg_tmp.w = (u32) (u32)func_0011D390;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x14;
}

void func_0011D390(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x3BFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)sprite_draw_layer3);
}


void func_0011D3F0(void) {
    reg_tmp.w = 0x1ACB;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0x2090;
    reg_tmp.w = (u32) (u32)func_0011D450;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x14;
}

void func_0011D450(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x3FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    func_00171330((void *)sprite_draw_layer3);
}

extern void func_0011D510(void);

void func_0011D4B0(void) {
    reg_tmp.w = 0x1ACC;
    *(u16 *)(reg_a6 + 0x10) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x12) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x14) = 0xA50;
    reg_tmp.w = (u32) (u32)func_0011D510;
    *(u16 *)(reg_a6 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0xC) = 0x15;
}
