#include "common.h"
#include "entity.h"

void sprite_draw_layer4_keep(void);

void sprite_draw_layer4_keep_entry(void) {
    sprite_draw_layer4_keep();
}

void sprite_draw_layer4_keep_entry_2(void) {
    sprite_draw_layer4_keep();
}

extern u32 D_0026EE10[];

void func_001DC180(void) {
    u8 *object = reg_a6;
    u16 *entry;

    reg_a0 = (u8 *)D_0026EE10;
    reg_a0 += *(u16 *)(object + 0x26);
    entry = (u16 *)reg_a0;
    reg_d2.h[1] = entry[0];
    reg_d2.h[0] = entry[1];
    reg_d1.h[1] = *(u16 *)(object + 0x22);
    reg_d1.h[0] = *(u16 *)(object + 0x24);
    reg_d1.w += 0xEE00EE00u;
    reg_d3.h[0] = 0x1290;
    reg_d4.h[0] = *(u16 *)(object + 0x3C);
    *(u8 *)&reg_d4 = object[0x147];
    sprite_draw_layer4_keep_entry();
}

extern u8 D_0026EE30[];

void func_001DC200(void) {
    reg_a0 = D_0026EE30;
    reg_a0 += ENTITY(reg_a6)[8].offset_y.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)[1].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[1].x.h;
    reg_d1.w += 0xFC000000;
    reg_d1.w += 0xE600EA00;
    reg_d3.h[0] = 0x1AB0;
    reg_d4.h[0] = ENTITY(reg_a6)[1].attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[10].offset_y.b[1];
    sprite_draw_layer4_keep_entry();
}

extern u8 D_0026EE70[];

void func_001DC290(void) {
    u16 temp_a1;
    u16 temp_a1_2;

    reg_a0 = (u8 *)D_0026EE70;
    reg_a0 += ENTITY(reg_a6)[8].offset_y.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)[1].y.h;
    temp_a1 = ENTITY(reg_a6)[1].x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFE000000;
    reg_d1.w += 0xEC00E300;
    reg_d3.h[0] = 0x14E8;
    reg_d4.h[0] = ENTITY(reg_a6)[1].attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[10].offset_y.b[1];
    sprite_draw_layer4_keep_entry_2();
    reg_d2.w = 0x1D05;
    reg_d1.h[1] = ENTITY(reg_a6)[1].y.h;
    temp_a1_2 = ENTITY(reg_a6)[1].x.h;
    reg_d1.h[0] = temp_a1_2;
    reg_d1.w += 0x0D000000;
    reg_d1.w += 0xF600F600;
    reg_d3.h[0] = 0xA50;
    reg_d4.h[0] = ENTITY(reg_a6)[1].attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[10].offset_y.b[1];
    sprite_draw_layer4_keep_entry();
}

extern u8 D_0026EEB0[];

void func_001DC390(void) {
    u8 *object = reg_a6;
    u16 *table_entry;

    reg_a0 = D_0026EEB0;
    reg_a0 += *(u16 *)(object + 0x46);
    table_entry = (u16 *)reg_a0;
    reg_d2.h[1] = table_entry[0];
    reg_d2.h[0] = table_entry[1];
    reg_d1.h[1] = *(u16 *)(object + 0x42);
    reg_d1.h[0] = *(u16 *)(object + 0x44);
    reg_d1.w += 0xE800EC00U;
    reg_d3.h[0] = 0x18A0;
    reg_d4.h[0] = *(u16 *)(object + 0x5C);
    *(u8 *)&reg_d4 = object[0x146];
    sprite_draw_layer4_keep_entry();
}

extern u16 D_0026EED0[];

void func_001DC410(void) {
    u8 *object = reg_a6;
    u16 *entry;

    reg_a0 = (u8 *)D_0026EED0;
    reg_a0 += *(u16 *)(object + 0x66);
    entry = (u16 *)reg_a0;
    reg_d2.h[1] = entry[0];
    reg_d2.h[0] = entry[1];
    reg_d1.h[1] = *(u16 *)(object + 0x62);
    reg_d1.h[0] = *(u16 *)(object + 0x64);
    reg_d1.w += 0xF600FA00u;
    reg_d3.h[0] = 0x0A30;
    reg_d4.h[0] = *(u16 *)(object + 0x7C);
    *(u8 *)&reg_d4 = object[0x149];
    sprite_draw_layer4_keep_entry();
}

extern u8 D_0026EEF0[];

void func_001DC490(void) {
    reg_a0 = D_0026EEF0;
    reg_d0.h[0] = ENTITY(reg_a6)[6].offset_y.h;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    reg_d2.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)[6].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[6].x.h;
    reg_d1.w += 0xF800FA00;
    reg_d3.h[0] = 0x830;
    reg_d4.h[0] = ENTITY(reg_a6)[6].attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[10].offset_x.b[0];
    sprite_draw_layer4_keep_entry();
}

void func_001DC530(void) {
    reg_a0 = D_0026EEF0;
    reg_d0.h[0] = ENTITY(reg_a6)[7].offset_y.h;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)[7].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[7].x.h;
    reg_d1.w += 0xF800FA00;
    reg_d3.h[0] = 0x830;
    reg_d4.h[0] = ENTITY(reg_a6)[7].attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[10].draw.b.priority;
    sprite_draw_layer4_keep_entry();
}

extern u16 D_0026EF50[];

void func_001DC5D0(void) {
    u16 temp_a1;
    reg_d0.w = 0;
    reg_a0 = (u8 *)(D_0026EF50);
    reg_d0.b[0] = ENTITY(reg_a6)[8].move.b.dir;
    reg_d0.b[0] += 1;
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[1] = ENTITY(reg_a6)[8].y.h;
    temp_a1 = ENTITY(reg_a6)[8].x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFA00FB00;
    reg_d3.h[0] = 0x628;
    reg_d4.h[0] = ENTITY(reg_a6)[8].attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[10].draw.b.flip;
    sprite_draw_layer4_keep_entry();
}

s32 sprite_draw_layer2();
extern u8 D_0026EFD0[];
extern u8 D_0026EFF0[];

void func_001DC6D0(void) {
    u16 temp_a0;
    u16 temp_a1;

    reg_a0 = (u8 *)D_0026EFD0;
    reg_a0 += ENTITY(reg_a6)[4].offset_y.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)[4].y.h;
    temp_a0 = ENTITY(reg_a6)[4].x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF000F800;
    reg_d3.h[0] = 0x1040;
    reg_d4.h[0] = ENTITY(reg_a6)[4].attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[10].sprite.b[1];
    sprite_draw_layer2();
    reg_a0 = (u8 *)D_0026EFF0;
    reg_a0 += ENTITY(reg_a6)[4].offset_x.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)[4].y.h;
    temp_a1 = ENTITY(reg_a6)[4].x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFA00FC00;
    reg_d1.w += 0xF9400200;
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = ENTITY(reg_a6)[4].attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[10].sprite.b[1];
    sprite_draw_layer2();
}

extern u8 D_0026F020[];

void func_001DC7E0(void) {
    u16 temp_a0;
    u16 temp_a1;

    reg_a0 = (u8 *)D_0026F020;
    reg_a0 += ENTITY(reg_a6)[5].offset_y.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)[5].y.h;
    temp_a0 = ENTITY(reg_a6)[5].x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF000F800;
    reg_d3.h[0] = 0x1040;
    reg_d4.h[0] = ENTITY(reg_a6)[5].attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[10].sprite.b[0];
    sprite_draw_layer2();
    reg_a0 = (u8 *)D_0026EFF0;
    reg_a0 += ENTITY(reg_a6)[5].offset_x.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)[5].y.h;
    temp_a1 = ENTITY(reg_a6)[5].x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFA00FC00;
    reg_d1.w += 0xF93FFE40;
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = ENTITY(reg_a6)[5].attr.h;
    reg_d4.b[0] = ENTITY(reg_a6)[10].sprite.b[1];
    sprite_draw_layer2();
}

extern void sprite_draw_layer5(void);
extern u32 D_0026F040[];

void func_001DC8F0(void) {
    u8 *work = reg_a6;
    u16 *tableEntry;

    reg_a0 = (u8 *)D_0026F040;
    reg_a0 += *(u16 *)(work + 0x126);
    tableEntry = (u16 *)reg_a0;
    reg_d2.h[1] = tableEntry[0];
    reg_d2.h[0] = tableEntry[1];
    reg_d1.h[1] = *(u16 *)(work + 0x122);
    reg_d1.h[0] = *(u16 *)(work + 0x124);
    reg_d1.w += 0xD800E800U;
    reg_d3.h[0] = 0x28C0;
    reg_d4.w = 0x15;
    sprite_draw_layer5();
}

extern u8 D_0026F080[];

void func_001DC960(void) {
    u8 *work = reg_a6;
    u16 *tableEntry;

    reg_a0 = D_0026F080;
    reg_a0 += *(u16 *)(work + 0x128);
    tableEntry = (u16 *)reg_a0;
    reg_d2.h[1] = tableEntry[0];
    reg_d2.h[0] = tableEntry[1];
    reg_d1.h[1] = *(u16 *)(work + 0x122);
    reg_d1.h[0] = *(u16 *)(work + 0x124);
    reg_d1.w += 0xDC00EE00U;
    reg_d3.h[0] = 0x2490;
    reg_d4.w = 0x15;
    sprite_draw_layer5();
}
