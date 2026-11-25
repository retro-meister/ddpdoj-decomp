#include "common.h"
#include "entity.h"

void func_001D13B0(void);
void func_001D1440(void);
void func_001D1490(void);
void func_001D1530(void);
void func_001D15D0(void);
void func_001D1650(void);
void func_001D1760(void);
void func_001D1870(void);
void func_001D16D0(void);
void func_001D1980(void);

/* The draw routine of every part of the boss, by part number. */
void (*stage3_boss_draw_routines[])(void) = {
    func_001D13B0,
    func_001D1440,
    func_001D1490,
    func_001D1530,
    func_001D15D0,
    func_001D1650,
    func_001D1760,
    func_001D1870,
    func_001D16D0,
    func_001D1980,
    (void (*)(void))-1,
};

extern u8 D_0026D320[];

void func_001D13B0(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a1;
    u16 temp_a3;

    reg_a0 = (u8 *)D_0026D320;
    temp_a3 = ENTITY(reg_a6)[5].offset_y.h;
    reg_a0 += temp_a3;
    reg_tmp.h[0] = ENTITY(reg_a6)[5].offset_y.h;
    reg_d2.w = *(u32 *)(D_0026D320 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a1 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xE4400000;
    reg_d1.w += 0xEC00E800;
    reg_d3.h[0] = 0x14C0;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[3].offset_x.b[1];
    sprite_draw_layer2_keep();
}


void func_001D1440(void)
{
    extern void sprite_draw_layer2_keep(void);
    u8 *object = reg_a6;

    reg_d2.w = 0x1BFA;
    reg_d1.h[1] = *(u16 *)(object + 0x02);
    reg_d1.h[0] = *(u16 *)(object + 0x04);
    reg_d1.w = reg_d1.w + 0xDE00EC00U;
    reg_d3.h[0] = 0x22A0;
    reg_d4.h[0] = *(u16 *)(object + 0x1C);
    *(u8 *)&reg_d4 = object[0x67];
    sprite_draw_layer2_keep();
}

extern u8 D_0026D360[];

void func_001D1490(void) {
    s32 sprite_draw_layer2_keep();
    reg_a0 = (u8 *)D_0026D360;
    reg_a0 += *(u16 *) (reg_a6 + 0xAA);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0xAA);
    reg_d2.w = *(u32 *) (D_0026D360 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = *(u16 *) (reg_a6 + 2);
    reg_d1.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.h[1] += 0x4C0;
    reg_d1.h[0] += 0xF600;
    reg_d1.w += 0xF000FC00;
    reg_d3.h[0] = 0x1020;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)[3].offset_x.b[0];
    sprite_draw_layer2_keep();
}

void func_001D1530(void) {
    s32 sprite_draw_layer2_keep();
    reg_a0 = (u8 *)D_0026D360;
    reg_a0 += *(u16 *) (reg_a6 + 0xAC);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0xAC);
    reg_d2.w = *(u32 *) (D_0026D360 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = *(u16 *) (reg_a6 + 2);
    reg_d1.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.h[1] += 0x4C0;
    reg_d1.h[0] += 0xA00;
    reg_d1.w += 0xF000FC00;
    reg_d3.h[0] = 0x1020;
    reg_d4.h[0] = 0x4000;
    reg_d4.b[0] = ENTITY(reg_a6)[3].offset_x.b[0];
    sprite_draw_layer2_keep();
}

extern u8 D_0026D380[];

void func_001D15D0(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a0;
    u16 temp_a2;

    reg_a0 = D_0026D380;
    temp_a2 = ENTITY(reg_a6)[5].misc.h;
    reg_a0 += temp_a2;
    reg_tmp.h[0] = ENTITY(reg_a6)[5].misc.h;
    reg_d2.w = *(u32 *)(D_0026D380 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = ENTITY(reg_a6)[1].y.h;
    temp_a0 = ENTITY(reg_a6)[1].x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xE400F700;
    reg_d3.h[0] = 0x1C48;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)[3].offset_y.b[0];
    sprite_draw_layer2_keep();
}

extern u8 D_0026D3A0[];

void func_001D1650(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a0;
    u16 temp_a2;

    reg_a0 = D_0026D3A0;
    temp_a2 = ENTITY(reg_a6)[5].misc.h;
    reg_a0 += temp_a2;
    reg_tmp.h[0] = ENTITY(reg_a6)[5].misc.h;
    reg_d2.w = *(u32 *)(D_0026D3A0 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = ENTITY(reg_a6)[2].y.h;
    temp_a0 = ENTITY(reg_a6)[2].x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xE400F700;
    reg_d3.h[0] = 0x1C48;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)[3].offset_y.b[0];
    sprite_draw_layer2_keep();
}

extern u8 D_0026D3C0[];

void func_001D16D0(void) {
    s32 sprite_draw_layer2_keep();
    reg_a0 = (u8 *)D_0026D3C0;
    reg_a0 += *(u16 *) (reg_a6 + 0xA8);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0xA8);
    reg_d2.w = *(u32 *) (D_0026D3C0 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = *(u16 *) (reg_a6 + 2);
    reg_d1.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.w += 0xF6400000;
    reg_d1.w += 0xF600F400;
    reg_d3.h[0] = 0xA60;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)[3].offset_y.b[0];
    sprite_draw_layer2_keep();
}

extern u16 D_002590F0[];

void func_001D1760(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a0;
    reg_d2.h[0] = ENTITY(reg_a6)[5].hit_y_plus.h;
    reg_a0 = (u8 *)(D_002590F0);
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_tmp2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp2.h[0] = (((reg_d2.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d2.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = reg_tmp2.w;
    reg_d1.h[0] = ENTITY(reg_a6)[1].y.h;
    reg_d1.h[0] += 0xD00;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    temp_a0 = ENTITY(reg_a6)[1].x.h;
    reg_d1.h[0] = temp_a0;
    reg_d3.h[0] = 0x418;
    reg_d4.w = 0;
    reg_d1.h[0] += 0x7FFF + 0x7D81;
    reg_d4.b[0] = ENTITY(reg_a6)[3].offset_y.b[0];
    sprite_draw_layer2_keep();
}

void func_001D1870(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a0;
    reg_d2.h[0] = ENTITY(reg_a6)[5].hit_y_minus.h;
    reg_a0 = (u8 *)(D_002590F0);
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_tmp2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp2.h[0] = (((reg_d2.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d2.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = reg_tmp2.w;
    reg_d1.h[0] = ENTITY(reg_a6)[2].y.h;
    reg_d1.h[0] += 0xD00;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    temp_a0 = ENTITY(reg_a6)[2].x.h;
    reg_d1.h[0] = temp_a0;
    reg_d3.h[0] = 0x418;
    reg_d4.w = 0;
    reg_d1.h[0] += 0x7FFF + 0x7C81;
    reg_d4.b[0] = ENTITY(reg_a6)[3].offset_y.b[0];
    sprite_draw_layer2_keep();
}

extern u16 D_0026D3E0[];

void func_001D1980(void) {
    s32 sprite_draw_layer2_keep();
    reg_a0 = (u8 *)D_0026D3E0;
    reg_a0 += ENTITY(reg_a6)[5].attr.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xF7000000;
    reg_tmp1.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.w += reg_tmp1.w;
    reg_d3.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d4.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    sprite_draw_layer2_keep();
}
