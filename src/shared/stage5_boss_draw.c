#include "common.h"

void func_001F0E70(void);

s32 func_00201E20();
extern u8 D_00264870[];
extern u16 D_0028E4A2;
extern u16 D_0028E4A6;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001F0330(void) {
    s32 func_0019C670();
    u32 temp_a1;
    u32 temp_a2;

    reg_d1.w = 0;
    reg_d0.h[0] = 0x1A;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x13C)));
    func_00201E20();
    (*(u8 *)((u8 *)(reg_a6) + (0x13C))) += 2;
    (*(u16 *)((u8 *)(reg_a6) + (0x10))) = 0x1400U;
    (*(u16 *)((u8 *)(reg_a6) + (0x10))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x12))) = 0x2200U;
    (*(u16 *)((u8 *)(reg_a6) + (0x12))) -= reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x1B0))) = 0xDE00U;
    (*(u16 *)((u8 *)(reg_a6) + (0x1B0))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x1B2))) = 0x2600U;
    (*(u16 *)((u8 *)(reg_a6) + (0x1B2))) -= reg_d2.h[0];
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] += reg_d2.h[0];
    reg_tmp.w = reg_d1.w;
    D_0028E4A6 = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    temp_a2 = reg_d1.w;
    reg_a0 = D_00264870;
    reg_d1.w = temp_a2 + 0xE6000000;
    temp_a1 = reg_d1.w;
    reg_d1.w = temp_a1 + 0xEA00F200;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x128)));
    D_0028E4A2 = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d3.h[0] = 0x1670;
    reg_d4.w = 0;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xE9)));
    func_0019C670(reg_a0, temp_a1, temp_a2, reg_tmp.h[0]);
}

void func_001F04A0(void) {
    s32 func_0019C670();
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1B);
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x1A);
    func_00201E20();
    *(u16 *)(reg_a6 + 0x1FA) = reg_d2.h[0];
    *(u8 *)(reg_a6 + 0x1A) += 2;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] += reg_d2.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.w += 0xFC000000;
    reg_d1.w += 0xE000DC00;
    reg_d2.w = 0x1E50;
    reg_d3.h[0] = 0x2120;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0xE6);
    func_0019C670();
}

void func_001F0570(void) {
    s32 func_0019C670();
    reg_d0.h[0] = 0x1A;
    reg_d1.w = 0;
    reg_d1.b[0] = reg_a6[0x13C];
    func_00201E20();
    reg_d1.h[0] = *(u16 *) (reg_a6 + 2);
    reg_d1.h[0] += reg_d2.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.w += 0xD0000000;
    reg_d1.w += 0xF400F900;
    reg_d2.w = 0x1DF4;
    reg_d3.h[0] = 0xC38;
    reg_d4.w = 0;
    reg_d4.b[0] = reg_a6[0xE9];
    func_0019C670();
}

extern u16 D_00264890[];

void func_001F0620(void) {
    s32 func_0019C670();
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    (*(u16 *)((u8 *)(reg_a6) + (0x70))) = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    (*(u16 *)((u8 *)(reg_a6) + (0x72))) = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x7A)));
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x62)));
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x64)));
    temp_a0 = reg_d1.w;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x66)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x68)));
    reg_d1.w = temp_a0 + reg_tmp.w;
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x6E)));
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x7C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xE8)));
    func_0019C670();
}

void func_001F0780(void) {
    s32 func_0019C670();
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    (*(u16 *)((u8 *)(reg_a6) + (0x50))) = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    (*(u16 *)((u8 *)(reg_a6) + (0x52))) = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x5A)));
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
    temp_a0 = reg_d1.w;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x46)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x48)));
    reg_d1.w = temp_a0 + reg_tmp.w;
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x4E)));
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x5C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xE8)));
    func_0019C670();
}

void func_001F08E0(void) {
    s32 func_0019C670();
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    (*(u16 *)((u8 *)(reg_a6) + (0x30))) = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    (*(u16 *)((u8 *)(reg_a6) + (0x32))) = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x3A)));
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    temp_a0 = reg_d1.w;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x26)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
    reg_d1.w = temp_a0 + reg_tmp.w;
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2E)));
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x3C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xE8)));
    func_0019C670();
}

void func_001F0A40(void) {
    s32 func_0019C670();
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    (*(u16 *)((u8 *)(reg_a6) + (0xD0))) = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    (*(u16 *)((u8 *)(reg_a6) + (0xD2))) = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xDA)));
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC2)));
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC4)));
    temp_a0 = reg_d1.w;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xC6)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC8)));
    reg_d1.w = temp_a0 + reg_tmp.w;
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xCE)));
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xDC)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xE8)));
    func_0019C670();
}

void func_001F0BA0(void) {
    s32 func_0019C670();
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    (*(u16 *)((u8 *)(reg_a6) + (0xB0))) = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    (*(u16 *)((u8 *)(reg_a6) + (0xB2))) = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xBA)));
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
    temp_a0 = reg_d1.w;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA6)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA8)));
    reg_d1.w = temp_a0 + reg_tmp.w;
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xAE)));
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xBC)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xE8)));
    func_0019C670();
}

void func_001F0D00(void) {
    s32 func_0019C670();
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    (*(u16 *)((u8 *)(reg_a6) + (0x90))) = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    (*(u16 *)((u8 *)(reg_a6) + (0x92))) = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x9A)));
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x82)));
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x84)));
    temp_a0 = reg_d1.w;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x86)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x88)));
    reg_d1.w = temp_a0 + reg_tmp.w;
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x8E)));
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x9C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xE8)));
    func_0019C670();
}


void func_001F0E60(void) {
    func_001F0E70();
}

extern u8 D_00264990[];

void func_001F0E70(void) {
    s32 func_0019C670();
    u32 temp_a1;

    reg_d1.w = 0;
    reg_d0.h[0] = 0x10;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x130)));
    func_00201E20();
    (*(u8 *)((u8 *)(reg_a6) + (0x130))) += 2;
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] += reg_d2.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    temp_a1 = reg_d1.w;
    reg_d1.w = temp_a1 + 0xEE00EC00;
    reg_a0 = D_00264990;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x126)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d3.h[0] = 0x12A0;
    reg_d4.w = 0;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xE7)));
    func_0019C670();
}

void func_001F0F50(void) {
    s32 func_0019C670();
    u32 temp_a1;
    u32 temp_a2;

    reg_d1.w = 0;
    reg_d0.h[0] = 0x1C;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x13C)));
    func_00201E20();
    (*(u8 *)((u8 *)(reg_a6) + (0x13C))) += 3;
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] += reg_d2.h[0];
    reg_tmp.w = reg_d1.w;
    D_0028E4A6 = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    temp_a2 = reg_d1.w;
    reg_a0 = D_00264870;
    reg_d1.w = temp_a2 + 0xEE000000;
    temp_a1 = reg_d1.w;
    reg_d1.w = temp_a1 + 0xEA00F200;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x128)));
    D_0028E4A2 = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d3.h[0] = 0x1670;
    reg_d4.w = 0;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xE9)));
    func_0019C670(reg_a0, temp_a1, temp_a2, reg_tmp.h[0]);
}

extern void *reg_a6_as_void_p;

void func_001F1040(void)
{
    extern void func_0019C670(void);
    u8 *source;

    reg_d2.w = 0x1E51;
    source = (u8 *)reg_a6_as_void_p;
    D_0028E4A6 = *(u16 *)(source + 2);
    reg_d1.h[0] = *(u16 *)(source + 4);
    reg_d1.w = reg_d1.w + 0x0200FFC0U;
    reg_d4.w = 0;
    reg_d1.w = reg_d1.w + 0xF200F400U;
    reg_d3.h[0] = 0xE60;
    *(u8 *)&reg_d4 = source[0xE6];
    func_0019C670();
}

void func_001F10A0(void) {
    s32 func_0019C670();
    reg_d0.h[0] = 0x1A;
    reg_d1.w = 0;
    reg_d1.b[0] = reg_a6[0x13C];
    func_00201E20();
    reg_d1.h[0] = *(u16 *) (reg_a6 + 2);
    reg_d1.h[0] += reg_d2.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.w += 0xD8000000;
    reg_d1.w += 0xF400F900;
    reg_d2.w = 0x1DF4;
    reg_d3.h[0] = 0xC38;
    reg_d4.w = 0;
    reg_d4.b[0] = reg_a6[0xE9];
    func_0019C670();
}

extern u8 D_002649A8[];

void func_001F1150(void) {
    s32 func_0019C670();
    u16 temp_a1;

    reg_a0 = D_002649A8;
    reg_a0 += *(u16 *)(reg_a6 + 0x12A);
    reg_d2.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    temp_a1 = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xF4000000;
    reg_d1.w += 0xF000DE00;
    reg_d3.h[0] = 0x1110;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0xEB);
    func_0019C670();
}

extern u16 D_002649C0[];

void func_001F11D0(void) {
    s32 func_0019C670();
    u16 temp_a3;
    u32 temp_a0;

    reg_a0 = (u8 *)(D_002649C0);
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x12C)));
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a3 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a3;
    reg_d1.w += 0x0C000000;
    temp_a0 = reg_d1.w + 0xF200E000;
    reg_d1.w = temp_a0;
    reg_d3.h[0] = 0xF00;
    reg_d4.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    func_0019C670();
}

s32 func_0019D920();
extern u8 D_00264A50[];
extern u16 D_0028E3E8;

void func_001F1270(void) {
    s32 func_0019C670();
#ifdef DEATH_LABEL
    s32 i;
    u16 x;
    u16 y;

    x = (*(u16 *)((u8 *)(reg_a6) + (2)));
    y = (*(u16 *)((u8 *)(reg_a6) + (4)));
    for (i = 0; i < 2; i++) {
        reg_a0 = D_00264A50;
        reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x132)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d1.h[1] = x;
        reg_d1.h[0] = y;
        x = (*(u16 *)((u8 *)(reg_a6) + (0x202)));
        y = (*(u16 *)((u8 *)(reg_a6) + (0x204)));
        reg_d1.w += 0xF400F900;
        reg_d3.h[0] = 0xC38;
        reg_d4.w = 0;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xEC)));
        if (((*(u8 *)((u8 *)(reg_a6) + (0x15E))) == 0) && (D_0028E3E8 != 0)) {
            func_0019D920();
        } else {
            func_0019C670();
        }
    }
#else
    u16 temp_a0;

    reg_a0 = D_00264A50;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x132)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF400F900;
    reg_d3.h[0] = 0xC38;
    reg_d4.w = 0;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xEC)));
    if (((*(u8 *)((u8 *)(reg_a6) + (0x15E))) == 0) && (D_0028E3E8 != 0)) {
        func_0019D920();
        return;
    }
    func_0019C670();
#endif
}

extern u16 MAIN_OR_DEATH_LABEL(D_00264A70, death_D_0026A2E0)[];

#ifdef DEATH_LABEL
#define BOSS_X x
#define BOSS_Y y
#else
#define BOSS_X (*(u16 *)(reg_a6 + 2))
#define BOSS_Y (*(u16 *)(reg_a6 + 4))
#endif

void func_001F1320(void) {
    s32 func_0019C670();
#ifdef DEATH_LABEL
    s32 i;
    u16 x;
    u16 y;

    x = *(u16 *)(reg_a6 + 2);
    y = *(u16 *)(reg_a6 + 4);
    for (i = 0; i < 2; i++) {
#endif
    reg_a0 = (u8 *) MAIN_OR_DEATH_LABEL(D_00264A70, death_D_0026A2E0);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x12E);
    reg_d2.h[0] -= 0x18;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[1] = BOSS_X;
    reg_d1.h[0] = BOSS_Y;
    reg_d1.w += 0xFE00FF00;
    reg_d4.w = 0;
    reg_d1.w += 0xF7C00000;
    reg_d3.h[0] = 0x208;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0xEC);
    func_0019C670();
#ifdef DEATH_LABEL
        x = *(u16 *)(reg_a6 + 0x202);
        y = *(u16 *)(reg_a6 + 0x204);
    }
#endif
}

extern u8 D_00264AC0[];
extern u16 D_0028E3EC;

void func_001F1420(void) {
    s32 func_0019C670();
#ifdef DEATH_LABEL
    s32 i;
    u16 x;
    u16 y;

    if (D_0028E3EC == 0) {
        return;
    }
    x = (*(u16 *)((u8 *)(reg_a6) + (2)));
    y = (*(u16 *)((u8 *)(reg_a6) + (4)));
    for (i = 0; i < 2; i++) {
        reg_a0 = (u8 *)D_00264AC0;
        reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x138)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d1.h[1] = x;
        reg_d1.h[0] = y;
        reg_d1.w += 0xFF800000;
        reg_d4.w = 0;
        reg_d1.w += 0xF000F800;
        reg_d3.h[0] = 0x1040;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xEF)));
        func_0019C670();
        x = (*(u16 *)((u8 *)(reg_a6) + (0x202)));
        y = (*(u16 *)((u8 *)(reg_a6) + (0x204)));
    }
#else
    u16 temp_a1;

    if (D_0028E3EC != 0) {
        reg_a0 = (u8 *)D_00264AC0;
        reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x138)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xFF800000;
        reg_d4.w = 0;
        reg_d1.w += 0xF000F800;
        reg_d3.h[0] = 0x1040;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xEF)));
        func_0019C670();
    }
#endif
}
