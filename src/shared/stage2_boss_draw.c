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
    reg_d4.b[0] = ENTITY(reg_a6)[9].offset_y.b[1];
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
    reg_d4.b[0] = ENTITY(reg_a6)[9].offset_y.b[0];
    sprite_draw_layer2_keep();
}

extern u8 D_0026C2F0[];

void func_001C3FD0(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a2;
    u32 temp_a3;

    reg_a0 = (u8 *)D_0026C2F0;
    reg_a0 += ENTITY(reg_a6)[11].offset_y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)[11].offset_y.h;
    reg_d2.w = *(u32 *)(D_0026C2F0 + (reg_tmp.h[0] & ~3));
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] += ENTITY(reg_a6)[11].offset_x.h;
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
    reg_d4.b[0] = ENTITY(reg_a6)[9].offset_x.b[1];
    sprite_draw_layer2_keep();
}

extern u8 D_0026C330[];

void func_001C4090(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a1;
    u16 temp_a3;

    reg_a2 = (u8 *)D_0026C330;
    temp_a3 = ENTITY(reg_a6)[11].draw.h;
    reg_a2 += temp_a3;
    reg_tmp.h[0] = ENTITY(reg_a6)[11].draw.h;
    reg_d2.w = *(u32 *)(D_0026C330 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a1 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xF6000000;
    reg_d1.w += 0xF400ED00;
    reg_d3.h[0] = 0xC98;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[9].hit_y_plus.b[1];
    sprite_draw_layer2_keep();
}

extern u8 D_0026C3B0[];

void func_001C4120(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a1;
    u16 temp_a3;
    u32 temp_a2;

    reg_a2 = D_0026C3B0;
    temp_a3 = ENTITY(reg_a6)[6].offset_y.h;
    reg_a2 += temp_a3;
    reg_tmp.h[0] = ENTITY(reg_a6)[6].offset_y.h;
    reg_d2.w = *(u32 *)(D_0026C3B0 + (reg_tmp.h[0] & ~3));
    reg_d1.h[0] = ENTITY(reg_a6)[6].y.h;
    reg_d1.h[0] += ENTITY(reg_a6)[11].offset_x.h;
    temp_a2 = reg_d1.w;
    reg_tmp1.w = temp_a2;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    temp_a1 = ENTITY(reg_a6)[6].x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xF600FC00;
    reg_d3.h[0] = 0xA20;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[9].sprite.b[0];
    sprite_draw_layer2_keep();
}

extern u8 D_0026C370[];

void func_001C41D0(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a1;
    u16 temp_a3;
    u32 temp_a2;

    reg_a2 = D_0026C370;
    temp_a3 = ENTITY(reg_a6)[7].offset_y.h;
    reg_a2 += temp_a3;
    reg_tmp.h[0] = ENTITY(reg_a6)[7].offset_y.h;
    reg_d2.w = *(u32 *)(D_0026C370 + (reg_tmp.h[0] & ~3));
    reg_d1.h[0] = ENTITY(reg_a6)[7].y.h;
    reg_d1.h[0] += ENTITY(reg_a6)[11].offset_x.h;
    temp_a2 = reg_d1.w;
    reg_tmp1.w = temp_a2;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    temp_a1 = ENTITY(reg_a6)[7].x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xF600FC00;
    reg_d3.h[0] = 0xA20;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[9].look.b.size;
    sprite_draw_layer2_keep();
}

extern u8 D_0026C3F0[];

void func_001C4280(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a0;

    reg_d2.w = 0;
    reg_d2.b[0] = ENTITY(reg_a6)[2].move.b.dir;
    reg_a0 = D_0026C3F0;
    reg_d2.b[0] += 1;
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(D_0026C3F0 + (reg_d2.h[0] & ~3));
    reg_d1.h[1] = ENTITY(reg_a6)[2].y.h;
    temp_a0 = ENTITY(reg_a6)[2].x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xFA00FC00;
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[9].offset_x.b[0];
    sprite_draw_layer2_keep();
}

void func_001C4320(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a0;

    reg_d2.w = 0;
    reg_d2.b[0] = ENTITY(reg_a6)[3].move.b.dir;
    reg_a0 = D_0026C3F0;
    reg_d2.b[0] += 1;
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(D_0026C3F0 + (reg_d2.h[0] & ~3));
    reg_d1.h[1] = ENTITY(reg_a6)[3].y.h;
    temp_a0 = ENTITY(reg_a6)[3].x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xFA00FC00;
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[9].draw.b.priority;
    sprite_draw_layer2_keep();
}

extern u8 D_0026C470[];

void func_001C43C0(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a0;

    reg_d2.w = 0;
    reg_d2.b[0] = ENTITY(reg_a6)[4].move.b.dir;
    reg_a0 = D_0026C470;
    reg_d2.b[0] += 1;
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(D_0026C470 + (reg_d2.h[0] & ~3));
    reg_d1.h[1] = ENTITY(reg_a6)[4].y.h;
    temp_a0 = ENTITY(reg_a6)[4].x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF600FA00;
    reg_d3.h[0] = 0xA30;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[9].draw.b.flip;
    sprite_draw_layer2_keep();
}

void func_001C4460(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a0;

    reg_d2.w = 0;
    reg_d2.b[0] = ENTITY(reg_a6)[5].move.b.dir;
    reg_a0 = D_0026C470;
    reg_d2.b[0] += 1;
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(D_0026C470 + (reg_d2.h[0] & ~3));
    reg_d1.h[1] = ENTITY(reg_a6)[5].y.h;
    temp_a0 = ENTITY(reg_a6)[5].x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF600FA00;
    reg_d3.h[0] = 0xA30;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[9].sprite.b[1];
    sprite_draw_layer2_keep();
}

extern u8 D_0026C4F0[];

void func_001C4500(void) {
    void sprite_draw_layer2_keep();
    reg_d0.w = 0;
    reg_a0 = D_0026C4F0;
    reg_d0.b[0] = ENTITY(reg_a6)[8].move.b.dir;
    reg_d0.b[0] += 1;
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d2.w = *(u32 *)(D_0026C4F0 + (reg_d0.h[0] & ~3));
    reg_d1.h[1] = ENTITY(reg_a6)[8].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[8].x.h;
    reg_d1.w += 0xFC00FD00;
    reg_d3.h[0] = 0x418;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[9].look.b.palette;
    sprite_draw_layer2_keep();
}
