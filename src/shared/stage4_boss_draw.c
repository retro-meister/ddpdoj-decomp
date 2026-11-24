#include "common.h"

void func_0019C730(void);

void func_001DC160(void) {
    func_0019C730();
}

void func_001DC170(void) {
    func_0019C730();
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
    func_001DC160();
}

extern u8 D_0026EE30[];

void func_001DC200(void) {
    reg_a0 = D_0026EE30;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x106)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    reg_d1.w += 0xFC000000;
    reg_d1.w += 0xE600EA00;
    reg_d3.h[0] = 0x1AB0;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x3C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x147)));
    func_001DC160();
}

extern u8 D_0026EE70[];

void func_001DC290(void) {
    u16 temp_a1;
    u16 temp_a1_2;

    reg_a0 = (u8 *)D_0026EE70;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x106)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFE000000;
    reg_d1.w += 0xEC00E300;
    reg_d3.h[0] = 0x14E8;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x3C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x147)));
    func_001DC170();
    reg_d2.w = 0x1D05;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
    temp_a1_2 = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    reg_d1.h[0] = temp_a1_2;
    reg_d1.w += 0x0D000000;
    reg_d1.w += 0xF600F600;
    reg_d3.h[0] = 0xA50;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x3C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x147)));
    func_001DC160();
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
    func_001DC160();
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
    func_001DC160();
}

extern u8 D_0026EEF0[];

void func_001DC490(void) {
    reg_a0 = D_0026EEF0;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0xC6);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    reg_d2.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = *(u16 *)(reg_a6 + 0xC2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0xC4);
    reg_d1.w += 0xF800FA00;
    reg_d3.h[0] = 0x830;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0xDC);
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x148);
    func_001DC160();
}

void func_001DC530(void) {
    reg_a0 = D_0026EEF0;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xE6)));
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xE2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xE4)));
    reg_d1.w += 0xF800FA00;
    reg_d3.h[0] = 0x830;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xFC)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x14B)));
    func_001DC160();
}

extern u16 D_0026EF50[];

void func_001DC5D0(void) {
    u16 temp_a1;
    reg_d0.w = 0;
    reg_a0 = (u8 *)(D_0026EF50);
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x11A)));
    reg_d0.b[0] += 1;
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x102)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0x104)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFA00FB00;
    reg_d3.h[0] = 0x628;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x11C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x14A)));
    func_001DC160();
}

s32 func_0019C4B0();
extern u8 D_0026EFD0[];
extern u8 D_0026EFF0[];

void func_001DC6D0(void) {
    u16 temp_a0;
    u16 temp_a1;

    reg_a0 = (u8 *)D_0026EFD0;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x86)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x82)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x84)));
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF000F800;
    reg_d3.h[0] = 0x1040;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x9C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x14D)));
    func_0019C4B0();
    reg_a0 = (u8 *)D_0026EFF0;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x88)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x82)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0x84)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFA00FC00;
    reg_d1.w += 0xF9400200;
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x9C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x14D)));
    func_0019C4B0();
}

extern u8 D_0026F020[];

void func_001DC7E0(void) {
    u16 temp_a0;
    u16 temp_a1;

    reg_a0 = (u8 *)D_0026F020;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0xA6)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF000F800;
    reg_d3.h[0] = 0x1040;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xBC)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x14C)));
    func_0019C4B0();
    reg_a0 = (u8 *)D_0026EFF0;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0xA8)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFA00FC00;
    reg_d1.w += 0xF93FFE40;
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xBC)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x14D)));
    func_0019C4B0();
}

extern void func_0019C570(void);
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
    func_0019C570();
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
    func_0019C570();
}
