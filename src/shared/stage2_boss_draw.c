#include "common.h"
#include "entity.h"

extern u8 D_0026C2A0[];

void func_001C3EC0(void) {
    s32 sprite_draw_layer2_keep();
    reg_a0 = (u8 *)D_0026C2A0;
    reg_a0 += *(u16 *) (reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0x28);
    reg_d2.w = *(u32 *) (D_0026C2A0 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = *(u16 *) (reg_a6 + 0x22);
    reg_d1.h[0] = *(u16 *) (reg_a6 + 0x24);
    reg_d1.h[0] += 0xFD00;
    reg_d1.w += 0xEC00F000;
    reg_d3.h[0] = 0x1480;
    reg_d4.h[0] = *(u16 *) (reg_a6 + 0x1C);
    reg_d4.b[0] = reg_a6[0x127];
    sprite_draw_layer2_keep();
}

extern u8 D_0026C2C0[];

void func_001C3F50(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a0;
    u16 temp_a2;

    reg_a0 = D_0026C2C0;
    temp_a2 = ENTITY(reg_a6)->offset_y.h;
    reg_a0 += temp_a2;
    reg_tmp.h[0] = ENTITY(reg_a6)->offset_y.h;
    reg_d2.w = *(u32 *)(D_0026C2C0 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xEE00FA00;
    reg_d3.h[0] = 0x1230;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x126);
    sprite_draw_layer2_keep();
}

extern u8 D_0026C2F0[];

void func_001C3FD0(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a2;
    u32 temp_a3;

    reg_a0 = (u8 *)D_0026C2F0;
    reg_a0 += *(u16 *)(reg_a6 + 0x166);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x166);
    reg_d2.w = *(u32 *)(D_0026C2F0 + (reg_tmp.h[0] & ~3));
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x168);
    temp_a3 = reg_d1.w;
    reg_tmp1.w = temp_a3;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    temp_a2 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a2;
    reg_d1.w += 0x04000000;
    reg_d1.w += 0xEE00ED00;
    reg_d3.h[0] = 0x1298;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x129);
    sprite_draw_layer2_keep();
}

extern u8 D_0026C330[];

void func_001C4090(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a1;
    u16 temp_a3;

    reg_a2 = (u8 *)D_0026C330;
    temp_a3 = *(u16 *)(reg_a6 + 0x16A);
    reg_a2 += temp_a3;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x16A);
    reg_d2.w = *(u32 *)(D_0026C330 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a1 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xF6000000;
    reg_d1.w += 0xF400ED00;
    reg_d3.h[0] = 0xC98;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x131);
    sprite_draw_layer2_keep();
}

extern u8 D_0026C3B0[];

void func_001C4120(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a1;
    u16 temp_a3;
    u32 temp_a2;

    reg_a2 = D_0026C3B0;
    temp_a3 = *(u16 *)(reg_a6 + 0xC6);
    reg_a2 += temp_a3;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xC6);
    reg_d2.w = *(u32 *)(D_0026C3B0 + (reg_tmp.h[0] & ~3));
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0xC2);
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x168);
    temp_a2 = reg_d1.w;
    reg_tmp1.w = temp_a2;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    temp_a1 = *(u16 *)(reg_a6 + 0xC4);
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xF600FC00;
    reg_d3.h[0] = 0xA20;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x12C);
    sprite_draw_layer2_keep();
}

extern u8 D_0026C370[];

void func_001C41D0(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a1;
    u16 temp_a3;
    u32 temp_a2;

    reg_a2 = D_0026C370;
    temp_a3 = *(u16 *)(reg_a6 + 0xE6);
    reg_a2 += temp_a3;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xE6);
    reg_d2.w = *(u32 *)(D_0026C370 + (reg_tmp.h[0] & ~3));
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0xE2);
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x168);
    temp_a2 = reg_d1.w;
    reg_tmp1.w = temp_a2;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    temp_a1 = *(u16 *)(reg_a6 + 0xE4);
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xF600FC00;
    reg_d3.h[0] = 0xA20;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x12F);
    sprite_draw_layer2_keep();
}

extern u8 D_0026C3F0[];

void func_001C4280(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a0;

    reg_d2.w = 0;
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x5A);
    reg_a0 = D_0026C3F0;
    reg_d2.b[0] += 1;
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(D_0026C3F0 + (reg_d2.h[0] & ~3));
    reg_d1.h[1] = *(u16 *)(reg_a6 + 0x42);
    temp_a0 = *(u16 *)(reg_a6 + 0x44);
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xFA00FC00;
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x128);
    sprite_draw_layer2_keep();
}

void func_001C4320(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a0;

    reg_d2.w = 0;
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x7A);
    reg_a0 = D_0026C3F0;
    reg_d2.b[0] += 1;
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(D_0026C3F0 + (reg_d2.h[0] & ~3));
    reg_d1.h[1] = *(u16 *)(reg_a6 + 0x62);
    temp_a0 = *(u16 *)(reg_a6 + 0x64);
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xFA00FC00;
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x12B);
    sprite_draw_layer2_keep();
}

extern u8 D_0026C470[];

void func_001C43C0(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a0;

    reg_d2.w = 0;
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x9A);
    reg_a0 = D_0026C470;
    reg_d2.b[0] += 1;
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(D_0026C470 + (reg_d2.h[0] & ~3));
    reg_d1.h[1] = *(u16 *)(reg_a6 + 0x82);
    temp_a0 = *(u16 *)(reg_a6 + 0x84);
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF600FA00;
    reg_d3.h[0] = 0xA30;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x12A);
    sprite_draw_layer2_keep();
}

void func_001C4460(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a0;

    reg_d2.w = 0;
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0xBA);
    reg_a0 = D_0026C470;
    reg_d2.b[0] += 1;
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(D_0026C470 + (reg_d2.h[0] & ~3));
    reg_d1.h[1] = *(u16 *)(reg_a6 + 0xA2);
    temp_a0 = *(u16 *)(reg_a6 + 0xA4);
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF600FA00;
    reg_d3.h[0] = 0xA30;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x12D);
    sprite_draw_layer2_keep();
}

extern u8 D_0026C4F0[];

void func_001C4500(void) {
    void sprite_draw_layer2_keep();
    reg_d0.w = 0;
    reg_a0 = D_0026C4F0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x11A);
    reg_d0.b[0] += 1;
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d2.w = *(u32 *)(D_0026C4F0 + (reg_d0.h[0] & ~3));
    reg_d1.h[1] = *(u16 *)(reg_a6 + 0x102);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x104);
    reg_d1.w += 0xFC00FD00;
    reg_d3.h[0] = 0x418;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x12E);
    sprite_draw_layer2_keep();
}
