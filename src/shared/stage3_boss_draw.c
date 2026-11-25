#include "common.h"
#include "entity.h"

extern u8 D_0026D320[];

void func_001D13B0(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a1;
    u16 temp_a3;

    reg_a0 = (u8 *)D_0026D320;
    temp_a3 = *(u16 *)(reg_a6 + 0xA6);
    reg_a0 += temp_a3;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xA6);
    reg_d2.w = *(u32 *)(D_0026D320 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a1 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xE4400000;
    reg_d1.w += 0xEC00E800;
    reg_d3.h[0] = 0x14C0;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x69);
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
    reg_d4.b[0] = reg_a6[0x68];
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
    reg_d4.b[0] = reg_a6[0x68];
    sprite_draw_layer2_keep();
}

extern u8 D_0026D380[];

void func_001D15D0(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a0;
    u16 temp_a2;

    reg_a0 = D_0026D380;
    temp_a2 = *(u16 *)(reg_a6 + 0xBE);
    reg_a0 += temp_a2;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xBE);
    reg_d2.w = *(u32 *)(D_0026D380 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = *(u16 *)(reg_a6 + 0x22);
    temp_a0 = *(u16 *)(reg_a6 + 0x24);
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xE400F700;
    reg_d3.h[0] = 0x1C48;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x66);
    sprite_draw_layer2_keep();
}

extern u8 D_0026D3A0[];

void func_001D1650(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a0;
    u16 temp_a2;

    reg_a0 = D_0026D3A0;
    temp_a2 = *(u16 *)(reg_a6 + 0xBE);
    reg_a0 += temp_a2;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xBE);
    reg_d2.w = *(u32 *)(D_0026D3A0 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = *(u16 *)(reg_a6 + 0x42);
    temp_a0 = *(u16 *)(reg_a6 + 0x44);
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xE400F700;
    reg_d3.h[0] = 0x1C48;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x66);
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
    reg_d4.b[0] = reg_a6[0x66];
    sprite_draw_layer2_keep();
}

extern u16 D_002590F0[];

void func_001D1760(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a0;
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0xB0);
    reg_a0 = (u8 *)(D_002590F0);
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_tmp2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp2.h[0] = (((reg_d2.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d2.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = reg_tmp2.w;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x22);
    reg_d1.h[0] += 0xD00;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    temp_a0 = *(u16 *)(reg_a6 + 0x24);
    reg_d1.h[0] = temp_a0;
    reg_d3.h[0] = 0x418;
    reg_d4.w = 0;
    reg_d1.h[0] += 0x7FFF + 0x7D81;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x66);
    sprite_draw_layer2_keep();
}

void func_001D1870(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a0;
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0xB2);
    reg_a0 = (u8 *)(D_002590F0);
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_tmp2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp2.h[0] = (((reg_d2.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d2.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = reg_tmp2.w;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x42);
    reg_d1.h[0] += 0xD00;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    temp_a0 = *(u16 *)(reg_a6 + 0x44);
    reg_d1.h[0] = temp_a0;
    reg_d3.h[0] = 0x418;
    reg_d4.w = 0;
    reg_d1.h[0] += 0x7FFF + 0x7C81;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x66);
    sprite_draw_layer2_keep();
}

extern u16 D_0026D3E0[];

void func_001D1980(void) {
    s32 sprite_draw_layer2_keep();
    reg_a0 = (u8 *)D_0026D3E0;
    reg_a0 += *(u16 *)(reg_a6 + 0xBC);
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
