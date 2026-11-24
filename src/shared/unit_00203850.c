#include "common.h"
#include "entity.h"

void func_00205320(void);
void func_00205DA0(void);
void func_00205EE0(void);
void func_00205F30(void);
void func_00206510(void);
void func_00206520(void);
void func_00206690(void);

s32 func_0019C5B0();

void func_00203850(void) {
    if (*(u16 *)(reg_a6 + 0x64) == 0) goto block_rts;
    if (*(u8 *)(reg_a6 + 0x34) != 0) goto block_rts;
    reg_d1.w = 0x34010D00;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x46);
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d2.w = 0xACE;
    reg_d3.h[0] = 0xC78;
    reg_d4.h[0] = 0x13;
    func_0019C5B0();
    reg_d1.w = 0x21410D00;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 0x46);
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d2.w = 0xACF;
    func_0019C5B0();
    reg_d1.w = 0x21810E00;
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 0x48);
    reg_d2.w = 0xADB;
    reg_d3.h[0] = 0x1650;
    reg_d4.h[0] = 0x14;
    func_0019C5B0();
    reg_d1.h[0] = 0x1640;
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x48);
    reg_d2.w = 0xADC;
    func_0019C5B0();
block_rts:
    return;
}

s32 func_0019C840();
extern u8 D_00251EF0[];

void func_002039B0(void) {
    reg_d1.w = 0x48010000;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += (*(u16 *)(reg_a6 + 0x62));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d2.w = 0xAD0;
    reg_d3.h[0] = 0x14E0;
    reg_d4.h[0] = 0x10;
    reg_d1.w = 0xFE810000;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] -= (*(u16 *)(reg_a6 + 0x62));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d2.w = 0xAD1;
    reg_d1.w = 0x10000;
    reg_d1.h[0] -= (*(u16 *)(reg_a6 + 0x62));
    reg_d2.w = 0xAD2;
    reg_d3.h[0] = 0x3840;
    reg_d1.w = 0x12800;
    reg_d1.h[0] += (*(u16 *)(reg_a6 + 0x62));
    reg_d2.w = 0xAD3;
    reg_a4 = (u8 *)D_00251EF0;
    reg_a4 += *(u16 *)(reg_a6 + 0x60);
    reg_d6.h[1] = *(u16 *)(reg_a4 + 0);
    reg_d6.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d1.w = 0x48010000;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += (*(u16 *)(reg_a6 + 0x4E));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = (*(u16 *)(reg_a6 + 0x50));
    reg_d1.h[0] -= reg_d0.h[0];
    reg_d1.h[0] -= reg_d0.h[0];
    reg_d2.w = 0xAD0;
    reg_d3.h[0] = 0x14E0;
    reg_d4.h[0] = 0x10;
    func_0019C840();
    reg_d1.w = 0xFE810000;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] -= (*(u16 *)(reg_a6 + 0x4E));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = (*(u16 *)(reg_a6 + 0x50));
    reg_d1.h[0] += reg_d0.h[0];
    reg_d1.h[0] += reg_d0.h[0];
    reg_d2.w = 0xAD1;
    func_0019C840();
    reg_d1.w = 0x10000;
    reg_d1.h[0] -= (*(u16 *)(reg_a6 + 0x50));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = (*(u16 *)(reg_a6 + 0x4E));
    reg_d1.h[0] -= reg_d0.h[0];
    reg_d1.h[0] -= reg_d0.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d2.w = 0xAD2;
    reg_d3.h[0] = 0x3840;
    func_0019C840();
    reg_d1.w = 0x12800;
    reg_d1.h[0] += (*(u16 *)(reg_a6 + 0x50));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = (*(u16 *)(reg_a6 + 0x4E));
    reg_d1.h[0] += reg_d0.h[0];
    reg_d1.h[0] += reg_d0.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d2.w = 0xAD3;
    func_0019C840();
    reg_d1.w = 0x48010000;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += (*(u16 *)(reg_a6 + 0x4E));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = (*(u16 *)(reg_a6 + 0x50));
    reg_d0.h[0] <<= 2;
    reg_d1.h[0] -= reg_d0.h[0];
    reg_d2.w = 0xAD0;
    reg_d3.h[0] = 0x14E0;
    reg_d4.h[0] = 0x10;
    reg_d1.w = 0xFE810000;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] -= (*(u16 *)(reg_a6 + 0x4E));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = (*(u16 *)(reg_a6 + 0x50));
    reg_d0.h[0] <<= 2;
    reg_d1.h[0] += reg_d0.h[0];
    reg_d2.w = 0xAD1;
    reg_d1.w = 0x10000;
    reg_d1.h[0] -= (*(u16 *)(reg_a6 + 0x50));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = (*(u16 *)(reg_a6 + 0x4E));
    reg_d0.h[0] <<= 2;
    reg_d1.h[0] -= reg_d0.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d2.w = 0xAD2;
    reg_d3.h[0] = 0x3840;
    reg_d1.w = 0x12800;
    reg_d1.h[0] += (*(u16 *)(reg_a6 + 0x50));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = (*(u16 *)(reg_a6 + 0x4E));
    reg_d0.h[0] <<= 2;
    reg_d1.h[0] += reg_d0.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d2.w = 0xAD3;
    reg_d1.w = 0x48010000;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += (*(u16 *)(reg_a6 + 0x4E));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = (*(u16 *)(reg_a6 + 0x50));
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 1;
    reg_d1.h[0] -= reg_d0.h[0];
    reg_d2.w = 0xAD0;
    reg_d3.h[0] = 0x14E0;
    reg_d4.h[0] = 0x10;
    reg_d1.w = 0xFE810000;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] -= (*(u16 *)(reg_a6 + 0x4E));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] -= (*(u16 *)(reg_a6 + 0x50));
    reg_d2.w = 0xAD1;
    reg_d1.w = 0x10000;
    reg_d1.h[0] -= (*(u16 *)(reg_a6 + 0x50));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += (*(u16 *)(reg_a6 + 0x4E));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d2.w = 0xAD2;
    reg_d3.h[0] = 0x3840;
    reg_d1.w = 0x12800;
    reg_d1.h[0] += (*(u16 *)(reg_a6 + 0x50));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] -= (*(u16 *)(reg_a6 + 0x4E));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d2.w = 0xAD3;
}

extern u8 D_0028C148[];
extern u8 D_0028C868_as_u8_a[];
extern u16 D_0028E3E4;
extern u16 D_0028E3EC;

void func_00203F50(void) {
    u32 i;

    if (*(u16 *)(reg_a6 + 0x54) == 0) goto block_rts;
    if (D_0028E3EC == 0) goto block_rts;
    reg_a0 = (u8 *)D_0028C148;
    reg_a1 = (u8 *)D_0028C868_as_u8_a;
    i = reg_d5.h[0];
    reg_tmp.h[1] = (i != 0) ? *(u16 *)(reg_a0 + ((s16) i & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) i + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) ((u16) i + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = D_0028E3E4;
    reg_d0.h[0] *= 2;
    reg_d0.h[0] &= 4;
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[1] = (i != 0) ? *(u16 *)(reg_a1 + ((s16) i & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = (((u16) i + 2) != 0) ? *(u16 *)(reg_a1 + ((s16) ((u16) i + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *) reg_tmp.w;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] -= 0xFA00;
    reg_d1.h[0] += *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] -= 0xFC00;
    reg_d1.h[0] += *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d3.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d4.h[0] = 0x1A;
    func_0019C5B0();
block_rts:
    return;
}

extern u8 D_00251F30[];
extern u8 D_0028C140[];

void func_002041C0(void) {
    if (reg_d7.h[0] == 0) goto block_2p;
    reg_d1.w = 0x37800D40;
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 0x40);
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 0x44);
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xFE80;
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 0x4A);
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0x780;
    *(u16 *)(reg_a6 + 0x56) = reg_d1.h[1];
    *(u16 *)(reg_a6 + 0x58) = reg_d1.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xFA00;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xFC00;
    reg_d5.h[0] = ENTITY(reg_a6)->y.h;
    reg_d5.h[0] += reg_d5.h[0];
    reg_d5.h[0] += reg_d5.h[0];
    reg_a0 = (u8 *)D_0028C140;
    reg_d2.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((u16) reg_d5.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = 0;
    reg_a0 = (u8 *)D_00251F30;
    reg_a0 += *(u16 *)(reg_a6 + 0x60);
    reg_d6.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d6.h[0] = *(u16 *)(reg_a0 + 2);
    func_0019C840();
    func_00203F50();
    reg_d1.w = 0x21810040;
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 0x40);
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 0x44);
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 0x50);
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 0x50);
    reg_d2.w = 0xACD;
    reg_d3.h[0] = 0x1668;
    reg_d4.h[0] = 0x11;
    reg_a0 = (u8 *)D_00251EF0;
    reg_a0 += *(u16 *)(reg_a6 + 0x60);
    reg_d6.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d6.h[0] = *(u16 *)(reg_a0 + 2);
    func_0019C840();
    return;
block_2p:
    reg_d1.w = 0x37802A80;
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x40);
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x44);
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xFE80;
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 0x4A);
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xF880;
    *(u16 *)(reg_a6 + 0x56) = reg_d1.h[1];
    *(u16 *)(reg_a6 + 0x58) = reg_d1.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xFA00;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xFC00;
    reg_d5.h[0] = ENTITY(reg_a6)->y.h;
    reg_d5.h[0] += reg_d5.h[0];
    reg_d5.h[0] += reg_d5.h[0];
    reg_a0 = (u8 *)D_0028C140;
    reg_d2.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((u16) reg_d5.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = 1;
    reg_a0 = (u8 *)D_00251F30;
    reg_a0 += *(u16 *)(reg_a6 + 0x60);
    reg_d6.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d6.h[0] = *(u16 *)(reg_a0 + 2);
    func_0019C840();
    func_00203F50();
    reg_d1.w = 0x21811D80;
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x40);
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x44);
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x50);
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x50);
    reg_d2.w = 0xACD;
    reg_d3.h[0] = 0x1668;
    reg_d4.h[0] = 0x11;
    reg_d4.h[0] |= 0x40;
    reg_a0 = (u8 *)D_00251EF0;
    reg_a0 += *(u16 *)(reg_a6 + 0x60);
    reg_d6.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d6.h[0] = *(u16 *)(reg_a0 + 2);
    func_0019C840();
}

void func_002046F0(void) {
    reg_d1.w = 0x38001C00;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xC800;
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x3E);
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xE400;
    reg_d2.w = 0xACC;
    reg_d3.h[0] = 0x38E0;
    reg_d4.h[0] = 0x15;
    func_0019C5B0();
    reg_d2.w = 0xACC;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 0x3E);
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 0x3E);
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d4.h[0] |= 0x6000;
    func_0019C5B0();
}


s32 func_0019C790();
s32 func_001A3520();
extern u8 D_00251F70[];
extern u8 D_00251F80[];
extern u8 D_0028DF0C;
extern u8 D_0028E304;

void func_00204800(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u32 save_d0;
    u32 save_d7;
    u16 temp_a0;
    u8 *temp_s5;

    reg_a0 = (u8 *)D_00251F70;
    if (reg_d7.h[0] != 0) {
        reg_a0 = (u8 *)D_00251F80;
    }
    if ((D_0028E304 != 0) || (D_0028DF0C != 0) || (reg_d0.h[0] = reg_d7.h[0], reg_d0.h[0] += 1, reg_d0.h[0] &= 1, func_001A3520(), (reg_d0.h[0] == 4)) || (temp_s5 = reg_a6, ((*(u8 *)((u8 *)(temp_s5) + (1))) != 0))) {
        reg_d0.h[0] = reg_d7.h[0];
        reg_d0.h[0] += 1;
        reg_d0.h[0] &= 1;
        func_00206520();
        return;
    }
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    reg_d0.w = 0;
    func_00206510();
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = temp_s5;
    if (cond_flag == 0) {
        save_d0 = reg_d0.w;
        reg_d0.h[0] = reg_d7.h[0];
        reg_d0.h[0] += 1;
        reg_d0.h[0] &= 1;
        func_00206520();
        reg_d0.w = save_d0;
        reg_d1.h[1] = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_d1.h[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_tmp.w = reg_d1.w;
        reg_a0 += reg_d0.h[0];
        reg_d1.h[1] = reg_tmp.h[0];
        reg_d1.h[0] = reg_tmp.h[1];
        reg_d1.h[0] += 0x7FFF + 0x7A01;
        reg_tmp.w = reg_d1.w;
        reg_d1.h[1] = reg_tmp.h[0];
        reg_d1.h[0] = reg_tmp.h[1];
        reg_d1.h[0] += 0x7FFF + 0x6C01;
        reg_d2.h[1] = *(u16 *)reg_a0;
        temp_a0 = *(u16 *)(reg_a0 + 2);
        reg_d2.h[0] = temp_a0;
        reg_d3.h[0] = 0x6A0;
        reg_d4.h[0] = 0xB;
        func_0019C790();
    }
}

extern u8 D_00251F90[];
extern u8 D_00251FB0[];
extern u8 D_00251FD0[];
extern u8 D_00251FF0[];
extern u16 D_0028E3F0;
extern u16 D_0028E910;

void func_00204A20(void) {
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_5;
    u16 temp_a0_6;
    u16 temp_a0_7;
    u8 temp_a0;

    reg_a0 = D_00251FB0;
    reg_a1 = D_00251FF0;
    reg_d6.h[0] = *(u16 *)(reg_a6 + 0x36);
    reg_d6.h[0] *= 0xFFFF;
    if (reg_d7.h[0] != 0) {
        reg_a0 = D_00251F90;
        reg_a1 = D_00251FD0;
        reg_d6.h[0] = *(u16 *)(reg_a6 + 0x36);
    }
    *(s16 *)(reg_a6 + 0x2C) = 0;
    if (ENTITY(reg_a6)->flags.b[0] == 1) {
        if (ENTITY(reg_a6)->y.h != 0) {
            reg_d0.h[0] = ENTITY(reg_a6)->hit_x_plus.h;
            if (*(u16 *)reg_a1 == reg_d0.h[0]) {
                *(s16 *)(reg_a6 + 0x2C) = 1;
            } else {
                reg_a2 = reg_a6 + 0x10;
                reg_d1.h[0] = *(u16 *)(reg_a1 + 2);
                reg_d5.h[0] = *(u16 *)reg_a1;
                func_00205320();
            }
            goto block_11;
        }
        ENTITY(reg_a6)->hit_y_plus.sh = 0x60;
        ENTITY(reg_a6)->hit_y_minus.sh = 0xC00;
        reg_d0.h[0] = ENTITY(reg_a6)->hit_x_plus.h;
        reg_d1.h[0] = *(u16 *)(reg_a1 + 4);
        if (reg_d7.h[0] == 0) {
            reg_tmp.w = reg_d0.w;
            reg_d0.w = reg_d1.w;
            reg_d1.w = reg_tmp.w;
        }
        if ((s16) reg_d1.h[0] < (s16) reg_d0.h[0]) {
            reg_d1.h[0] = *(u16 *)(reg_a1 + 6);
            ENTITY(reg_a6)->hit_x_plus.h += reg_d1.h[0];
block_11:
            reg_d1.h[0] = *(u16 *)(reg_a1 + 8);
            reg_d1.h[0] += 0xE600 & 0xFFFF;
            reg_tmp.w = reg_d1.w;
            reg_d1.h[1] = reg_tmp.h[0];
            reg_d1.h[0] = reg_tmp.h[1];
            reg_d1.h[0] = ENTITY(reg_a6)->hit_x_plus.h;
            reg_d1.h[0] += 0x7FFF + 0x6601;
            reg_d2.h[1] = *(u16 *)reg_a0;
            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
            reg_d3.h[0] = 0x1AD0;
            reg_d4.h[0] = *(u16 *)(reg_a1 + 0xA);
            func_0019C5B0();
            reg_d1.h[0] = *(u16 *)(reg_a1 + 8);
            reg_d1.h[0] += 0x7FFF + 0x7A01;
            reg_d1.h[0] += *(u16 *)(reg_a1 + 0x12);
            reg_tmp.w = reg_d1.w;
            reg_d1.h[1] = reg_tmp.h[0];
            reg_d1.h[0] = reg_tmp.h[1];
            reg_d1.h[0] = ENTITY(reg_a6)->hit_x_plus.h;
            reg_d1.h[0] += 0x7FFF + 0x7001;
            reg_d1.h[0] += *(u16 *)(reg_a1 + 0x14);
            reg_d2.w = 3;
            reg_d2.h[0] &= D_0028E3F0;
            reg_tmp.h[1] = *(u16 *)(reg_a0 + 0x14);
            reg_tmp.h[0] = *(u16 *)(reg_a0 + 0x16);
            reg_d2.w += reg_tmp.w;
            reg_d3.h[0] = 0x680;
            reg_d4.h[0] = *(u16 *)(reg_a1 + 0xE);
            func_0019C5B0();
        }
        if (ENTITY(reg_a6)->y.h == 0) {
            reg_d0.h[0] = ENTITY(reg_a6)->look.h;
            if (*(u16 *)reg_a1 == reg_d0.h[0]) {
                *(s16 *)(reg_a6 + 0x2C) = 1;
            } else {
                reg_a2 = reg_a6 + 0xA;
                reg_d1.h[0] = *(u16 *)(reg_a1 + 2);
                reg_d5.h[0] = *(u16 *)reg_a1;
                func_00205320();
            }
            goto block_20;
        }
        ENTITY(reg_a6)->draw.sh = 0x60;
        ENTITY(reg_a6)->sprite.sh = 0xC00;
        reg_d0.h[0] = ENTITY(reg_a6)->look.h;
        reg_d1.h[0] = *(u16 *)(reg_a1 + 4);
        if (reg_d7.h[0] == 0) {
            reg_tmp.w = reg_d0.w;
            reg_d0.w = reg_d1.w;
            reg_d1.w = reg_tmp.w;
        }
        if ((s16) reg_d1.h[0] < (s16) reg_d0.h[0]) {
            reg_d1.h[0] = *(u16 *)(reg_a1 + 6);
            ENTITY(reg_a6)->look.h += reg_d1.h[0];
block_20:
            reg_d1.h[0] = *(u16 *)(reg_a1 + 8);
            reg_d1.h[0] += 0xE600 & 0xFFFF;
            reg_tmp.w = reg_d1.w;
            reg_d1.h[1] = reg_tmp.h[0];
            reg_d1.h[0] = reg_tmp.h[1];
            reg_d1.h[0] = ENTITY(reg_a6)->look.h;
            reg_d1.h[0] += 0x7FFF + 0x6601;
            reg_d2.h[1] = *(u16 *)(reg_a0 + 4);
            reg_d2.h[0] = *(u16 *)(reg_a0 + 6);
            reg_d3.h[0] = 0x1AD0;
            reg_d4.h[0] = *(u16 *)(reg_a1 + 0xC);
            func_0019C5B0();
            reg_d1.h[0] = *(u16 *)(reg_a1 + 8);
            reg_d1.h[0] += 0x7FFF + 0x7C01;
            reg_d1.h[0] += *(u16 *)(reg_a1 + 0x16);
            reg_tmp.w = reg_d1.w;
            reg_d1.h[1] = reg_tmp.h[0];
            reg_d1.h[0] = reg_tmp.h[1];
            reg_d1.h[0] = ENTITY(reg_a6)->look.h;
            reg_d1.h[0] += 0x7FFF + 0x7001;
            reg_d1.h[0] += *(u16 *)(reg_a1 + 0x18);
            reg_d2.w = 3;
            reg_d2.h[0] &= D_0028E3F0;
            reg_tmp.h[1] = *(u16 *)(reg_a0 + 0x18);
            reg_tmp.h[0] = *(u16 *)(reg_a0 + 0x1A);
            reg_d2.w += reg_tmp.w;
            reg_d3.h[0] = 0x480;
            reg_d4.h[0] = *(u16 *)(reg_a1 + 0x10);
            func_0019C5B0();
        }
    }
    temp_a0 = ENTITY(reg_a6)->flags.b[0];
    if ((temp_a0 == 4) || (temp_a0 == 7)) {
        if (ENTITY(reg_a6)->x.h == 2) {
            reg_d0.h[0] = *(u16 *)(reg_a6 + 0x26);
            temp_a0_2 = *(u16 *)reg_a1;
            if (temp_a0_2 == reg_d0.h[0]) {
                *(s16 *)(reg_a6 + 0x2C) = 1;
            } else {
                reg_a2 = reg_a6 + 0x22;
                reg_d1.h[0] = *(u16 *)(reg_a1 + 2);
                reg_d5.h[0] = *(u16 *)reg_a1;
                func_00205320();
            }
            goto block_31;
        }
        *(s16 *)(reg_a6 + 0x22) = 0x60;
        *(s16 *)(reg_a6 + 0x24) = 0xC00;
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x26);
        reg_d1.h[0] = *(u16 *)(reg_a1 + 4);
        if (reg_d7.h[0] == 0) {
            reg_tmp.w = reg_d0.w;
            reg_d0.w = reg_d1.w;
            reg_d1.w = reg_tmp.w;
        }
        if ((s16) reg_d1.h[0] < (s16) reg_d0.h[0]) {
            reg_d1.h[0] = *(u16 *)(reg_a1 + 6);
            *(u16 *)(reg_a6 + 0x26) += reg_d1.h[0];
block_31:
            if (D_0028E910 == 0) {
                reg_d1.h[0] = *(u16 *)(reg_a1 + 8);
                reg_d1.h[0] += 0xE600 & 0xFFFF;
                reg_d1.h[0] += reg_d6.h[0];
                reg_tmp.w = reg_d1.w;
                reg_d1.h[1] = reg_tmp.h[0];
                reg_d1.h[0] = reg_tmp.h[1];
                reg_d1.h[0] = *(u16 *)(reg_a6 + 0x26);
                reg_d1.h[0] += 0x7FFF + 0x6601;
                reg_d2.h[1] = *(u16 *)(reg_a0 + 8);
                temp_a0_3 = *(u16 *)(reg_a0 + 0xA);
                reg_d2.h[0] = temp_a0_3;
                reg_d3.h[0] = 0x1AD0;
                reg_d4.h[0] = 0x1B;
                func_0019C5B0();
            }
        }
        if (ENTITY(reg_a6)->x.h == 1) {
            reg_d0.h[0] = *(u16 *)(reg_a6 + 0x20);
            temp_a0_4 = *(u16 *)reg_a1;
            if (temp_a0_4 == reg_d0.h[0]) {
                *(s16 *)(reg_a6 + 0x2C) = 1;
            } else {
                reg_a2 = reg_a6 + 0x1C;
                reg_d1.h[0] = *(u16 *)(reg_a1 + 2);
                reg_d5.h[0] = *(u16 *)reg_a1;
                func_00205320();
            }
            goto block_41;
        }
        *(s16 *)(reg_a6 + 0x1C) = 0x60;
        *(s16 *)(reg_a6 + 0x1E) = 0xC00;
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x20);
        reg_d1.h[0] = *(u16 *)(reg_a1 + 4);
        if (reg_d7.h[0] == 0) {
            reg_tmp.w = reg_d0.w;
            reg_d0.w = reg_d1.w;
            reg_d1.w = reg_tmp.w;
        }
        if ((s16) reg_d1.h[0] < (s16) reg_d0.h[0]) {
            reg_d1.h[0] = *(u16 *)(reg_a1 + 6);
            *(u16 *)(reg_a6 + 0x20) += reg_d1.h[0];
block_41:
            if (D_0028E910 == 0) {
                reg_d1.h[0] = *(u16 *)(reg_a1 + 8);
                reg_d1.h[0] += 0xE600 & 0xFFFF;
                reg_d1.h[0] += reg_d6.h[0];
                reg_tmp.w = reg_d1.w;
                reg_d1.h[1] = reg_tmp.h[0];
                reg_d1.h[0] = reg_tmp.h[1];
                reg_d1.h[0] = *(u16 *)(reg_a6 + 0x20);
                reg_d1.h[0] += 0x7FFF + 0x6601;
                reg_d2.h[1] = *(u16 *)(reg_a0 + 0xC);
                temp_a0_5 = *(u16 *)(reg_a0 + 0xE);
                reg_d2.h[0] = temp_a0_5;
                reg_d3.h[0] = 0x1AD0;
                reg_d4.h[0] = 0x19;
                func_0019C5B0();
            }
        }
        if (ENTITY(reg_a6)->x.h == 0) {
            reg_d0.h[0] = ENTITY(reg_a6)->move.h;
            temp_a0_6 = *(u16 *)reg_a1;
            if (temp_a0_6 == reg_d0.h[0]) {
                *(s16 *)(reg_a6 + 0x2C) = 1;
            } else {
                reg_a2 = reg_a6 + 0x16;
                reg_d1.h[0] = *(u16 *)(reg_a1 + 2);
                reg_d5.h[0] = *(u16 *)reg_a1;
                func_00205320();
            }
            goto block_51;
        }
        ENTITY(reg_a6)->hit_x_minus.sh = 0x60;
        ENTITY(reg_a6)->hp.sh = 0xC00;
        reg_d0.h[0] = ENTITY(reg_a6)->move.h;
        reg_d1.h[0] = *(u16 *)(reg_a1 + 4);
        if (reg_d7.h[0] == 0) {
            reg_tmp.w = reg_d0.w;
            reg_d0.w = reg_d1.w;
            reg_d1.w = reg_tmp.w;
        }
        if ((s16) reg_d1.h[0] < (s16) reg_d0.h[0]) {
            reg_d1.h[0] = *(u16 *)(reg_a1 + 6);
            ENTITY(reg_a6)->move.h += reg_d1.h[0];
block_51:
            if (D_0028E910 == 0) {
                reg_d1.h[0] = *(u16 *)(reg_a1 + 8);
                reg_d1.h[0] += 0xE600 & 0xFFFF;
                reg_d1.h[0] += reg_d6.h[0];
                reg_tmp.w = reg_d1.w;
                reg_d1.h[1] = reg_tmp.h[0];
                reg_d1.h[0] = reg_tmp.h[1];
                reg_d1.h[0] = ENTITY(reg_a6)->move.h;
                reg_d1.h[0] += 0x7FFF + 0x6601;
                reg_d2.h[1] = *(u16 *)(reg_a0 + 0x10);
                temp_a0_7 = *(u16 *)(reg_a0 + 0x12);
                reg_d2.h[0] = temp_a0_7;
                reg_d3.h[0] = 0x1AD0;
                reg_d4.h[0] = 0x18;
                func_0019C5B0();
            }
        }
    }
}

s32 func_00201D10();

void func_00205320(void) {
    reg_d0.h[0] = *(u16 *)reg_a2;
    func_00201D10();
    *(u16 *)(reg_a2 + 4) += reg_d3.h[0];
    reg_d2.h[0] = reg_d5.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a2 + 4);
    reg_d0.h[0] -= reg_d2.h[0];
    if (0 > (s16)(reg_d0.h[0])) {
        reg_d0.h[0] *= 0xFFFF;
    }
    if ((s32) *(u16 *)(reg_a2 + 2) > (s32) reg_d0.h[0]) {
        *(u16 *)reg_a2 >>= 1;
        *(u16 *)(reg_a2 + 2) >>= 1;
        if ((s16) *(u16 *)(reg_a2 + 2) < 0x21) {
            *(u16 *)(reg_a2 + 4) = (u16) reg_d5.h[0];
            *(u16 *)(reg_a2 + 2) = 0U;
        }
    }
}

extern u16 D_00252010[];
extern u16 D_00252050[];
extern u16 D_00252210[];
extern u16 D_00252220[];
extern u16 D_00252330[];
extern u16 D_00252340[];
extern u16 D_0028C150[];
extern u16 D_0028C154[];

void func_002053F0(void) {
    u8 *save_a0;

    reg_a0 = (u8 *)(D_0028C154);
    reg_a1 = (u8 *)(D_00252340);
    reg_a2 = (u8 *)(D_00252220);
    reg_a3 = (u8 *)(D_00252050);
    if (reg_d7.h[0] == 0) goto next_1;
    reg_a0 = (u8 *)(D_0028C150);
    reg_a1 = (u8 *)(D_00252330);
    reg_a2 = (u8 *)(D_00252210);
    reg_a3 = (u8 *)(D_00252010);
next_1:
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_a2 = (u8 *) reg_tmp.w;
    if (ENTITY(reg_a6)->flags.b[0] != 4) goto block_rts;
    if (*(u16 *)(reg_a6 + 0x28) == 0) goto next_2;
    *(u16 *)(reg_a6 + 0x28) = 0;
    *(u16 *)(reg_a6 + 0x2A) = 0xB4;
    *(u16 *)(reg_a6 + 0x5C) = 4;
next_2:
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = 0;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    if (*(u16 *)(reg_a6 + 0x2C) == 0) goto block_a;
    *(u16 *)(reg_a6 + 0x2A) -= 1;
    if (!(0 > (s16) *(u16 *)(reg_a6 + 0x2A))) goto next_3;
    *(u16 *)(reg_a6 + 0x2A) = 0xB4;
    *(u16 *)(reg_a6 + 0x5C) += 4;
    if (*(u16 *)(reg_a6 + 0x5C) != 0xC) goto next_3;
    *(u16 *)(reg_a6 + 0x5C) = 0;
next_3:
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x5C);
    if (reg_d1.h[0] == 0) goto block_a;
    if (reg_d1.h[0] == 4) goto block_b;
    if (reg_d1.h[0] == 8) goto block_c;
    return;
block_a:
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_tmp.h[0] = (((u16) reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)((u16) reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
    reg_a3 = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
    reg_a3 = (u8 *) reg_tmp.w;
    reg_d1.h[1] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d1.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d3.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d2.h[1] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d2.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    goto block_d;
block_b:
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_tmp.h[0] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
    reg_a3 = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
    reg_a3 = (u8 *) reg_tmp.w;
    save_a0 = reg_a0;
    reg_d1.h[1] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d1.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d3.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d2.w = 0xE;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d2.h[0] &= D_0028E3F0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = save_a0;
    goto block_d;
block_c:
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_tmp.h[0] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
    reg_a3 = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
    reg_a3 = (u8 *) reg_tmp.w;
    reg_d1.h[1] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d1.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d3.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d2.h[1] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d2.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
block_d:
    reg_d4.h[0] = 0x12;
    func_0019C5B0();
    if (D_0028E3EC == 0) goto next_4;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] += 0xE600 & 0xFFFF;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_d1.h[0] += 0xE600;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d2.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = 0x1AD0;
    reg_d4.h[0] = 0x12;
    func_0019C5B0();
next_4:
    reg_d1.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_d1.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
loop_1:
    reg_d3.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d2.w = 0xE;
    reg_d2.h[0] &= D_0028E3F0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d4.h[0] = 0x12;
    func_0019C5B0();
    reg_d1.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_d1.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    if (reg_d1.w != 0) goto loop_1;
block_rts:
    return;
}


void func_00205D20(void) {
    reg_a1 = reg_a6 - 0x70;
    if (reg_d7.h[0] != 0) {
        reg_a1 = reg_a6 + 0x70;
    }
    if (reg_d7.h[0] == 0) {
        func_00205EE0();
        return;
    }
    if (reg_a1[1] != 0) {
        func_00205DA0();
    } else {
        func_00205F30();
        func_00205DA0();
    }
}

void func_00205DA0(void) {
    if (D_0028E910 != 0) goto block_rts;
    reg_d1.w = 0x5B001C00;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xEA00;
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x36);
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xE400;
    reg_d2.w = 0xAD8;
    reg_d3.h[0] = 0x16E0;
    reg_d4.h[0] = 0x16;
    func_0019C5B0();
    reg_d1.w = 0x3FC03000;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xF600;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xF800;
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x38);
    reg_d2.w = 0xAD9;
    reg_d3.h[0] = 0xA40;
    reg_d4.h[0] = 0x16;
    func_0019C5B0();
block_rts:
    return;
}


void func_00205EE0(void) {
    if (*(u8 *)(reg_a1 + 1) != 0) {
        func_00205F30();
        return;
    }
    func_00205DA0();
    func_00205F30();
}

void func_00205F30(void) {
    if (D_0028E910 != 0) goto block_rts;
    reg_d1.w = 0x15401C00;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 0x36);
    reg_d1.h[0] += 0xEA00;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xE400;
    reg_d2.w = 0xAD8;
    reg_d3.h[0] = 0x16E0;
    reg_d4.h[0] = 0x16;
    reg_d4.h[0] |= 0x60;
    func_0019C5B0();
    reg_d1.w = 0x30000800;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xF600;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xF800;
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 0x38);
    reg_d2.w = 0xADA;
    reg_d3.h[0] = 0xA40;
    reg_d4.h[0] = 0x16;
    func_0019C5B0();
block_rts:
    return;
}

extern u8 D_00252350[];
extern u8 D_00252380[];
extern u8 D_002523B0[];

void func_00206080(void) {
    reg_a0 = (u8 *)D_00252350;
    reg_d5.h[0] = *(u16 *)(reg_a6 + 0x38);
    if (reg_d7.h[0] != 0) goto next_0;
    reg_a0 = (u8 *)D_00252380;
    reg_d5.h[0] *= 0xFFFF;
next_0:
    if (ENTITY(reg_a6)->flags.b[0] < 7) goto next_1;
    reg_a0 += 0x18;
    goto next_2;
next_1:
    reg_d1.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    if (D_0028E3EC == 0) goto next_3;
    reg_d2.w = 0xA9D;
    if (ENTITY(reg_a6)->flags.b[0] != 4) goto next_4;
    reg_d2.w = 0xA9E;
next_4:
    reg_d3.h[0] = 0x458;
    reg_d4.h[0] = 0x12;
    func_0019C5B0();
next_3:
    reg_d1.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    if (*(u16 *)(reg_a6 + 0x2C) == 0) goto next_5;
    reg_a1 = (u8 *)D_002523B0;
    reg_a1 += *(u16 *)(reg_a6 + 0x66);
    reg_d2.h[1] = *(u16 *)reg_a1;
    reg_d2.h[0] = *(u16 *)(reg_a1 + 2);
    reg_d3.h[0] = 0xE20;
    reg_d4.h[0] = 0x17;
    *(u16 *)(reg_a6 + 0x66) += 4;
    if (*(u16 *)(reg_a6 + 0x66) != 0x30) goto next_6;
    *(u16 *)(reg_a6 + 0x66) = 0;
next_6:
    if (reg_d7.h[0] != 0) goto next_7;
    reg_d4.h[0] |= 0x60;
next_7:
    func_0019C5B0();
next_5:
    reg_d1.h[1] = *(u16 *)reg_a0;
    reg_d1.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d2.h[1] = *(u16 *)(reg_a0 + 4);
    reg_d2.h[0] = *(u16 *)(reg_a0 + 6);
    reg_d3.h[0] = 0x630;
    reg_d4.h[0] = 0x12;
    if (ENTITY(reg_a6)->flags.b[0] != 1) goto next_8;
    if (ENTITY(reg_a6)->y.h == 0) goto next_9;
next_8:
    func_0019C5B0();
next_9:
    reg_d1.h[1] = *(u16 *)(reg_a0 + 8);
    reg_d1.h[0] = *(u16 *)(reg_a0 + 0xA);
    reg_d2.h[1] = *(u16 *)(reg_a0 + 0xC);
    reg_d2.h[0] = *(u16 *)(reg_a0 + 0xE);
    if (ENTITY(reg_a6)->flags.b[0] != 1) goto next_10;
    if (ENTITY(reg_a6)->y.h == 1) goto next_11;
next_10:
    func_0019C5B0();
next_11:
    reg_a0 += 0x10;
next_2:
    if (D_0028E910 != 0) return;
    reg_d1.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] += reg_d5.h[0];
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = 0x218;
    reg_d4.h[0] = 0x12;
    func_0019C5B0();
    reg_d1.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] += reg_d5.h[0];
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.w = 0;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2E);
    reg_d0.h[0] &= 0xF0;
    reg_d0.h[0] >>= 4;
    reg_d2.w += reg_d0.w;
    reg_d3.h[0] = 0x818;
    reg_d4.h[0] = 0x12;
    reg_d6.w = 0x80005000;
    func_0019C840();
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (-4)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (-2)));
    reg_d1.h[0] -= 0x3C0;
    reg_d0.w = 0;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2E);
    reg_d0.h[0] &= 0xF00;
    reg_d0.h[0] >>= 8;
    reg_d2.w += reg_d0.w;
    reg_d6.w = 0x80005000;
    func_0019C840();
    reg_d1.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] += reg_d5.h[0];
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.w = 0xF;
    reg_d0.h[0] &= *(u16 *)(reg_a6 + 0x2E);
    reg_d2.w += reg_d0.w;
    reg_d3.h[0] = 0x610;
    reg_d4.h[0] = 0x12;
    reg_d6.w = 0x80005000;
    func_0019C840();
}


void func_00206510(void) {
    func_00206690();
}

s32 func_00137AD0();
extern u8 D_00251B40[];
extern u8 D_0028C158[];
extern u8 D_0028C15C[];

void func_00206520(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u16 temp_a0;

    temp_a0 = reg_d0.h[0];
    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a6 = reg_a6;
    reg_a4 = (u8 *)D_0028C158;
    save_a5 = reg_a5;
    if (temp_a0 != 0) {
        reg_a4 = (u8 *)D_0028C15C;
    }
    reg_d4.h[0] = temp_a0;
    reg_a0 = (u8 *)D_00251B40;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] = *(u16 *)reg_a4;
    reg_d2.h[0] = 0;
    func_00137AD0();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    func_00137AD0();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

s32 func_0012FFE0();
s32 func_00130050();
s32 func_001301B0();
s32 func_00130CC0();
extern u8 D_00251BC0[];
extern u8 D_00251BE0[];
extern u8 D_00251C00[];
extern u8 D_0028E390;
extern u8 D_0028E39C;

void func_00206690(void) {
    cond_flag = 0;
    reg_a4 = (u8 *)D_0028C158;
    if (reg_d7.h[0] != 0) goto next_1;
    reg_a4 = (u8 *)D_0028C15C;
next_1:
    func_001301B0();
    if (reg_d7.h[0] != 0) goto next_2;
    if (D_0028E390 != 1) goto next_2;
    reg_d0.h[0] = reg_d1.h[0];
next_2:
    if (reg_d0.h[0] != 0) goto block_4;
    reg_d0.b[0] = D_0028E39C;
    if (reg_d0.b[0] == 0x12) goto block_5;
    if (reg_d0.b[0] == 0x11) goto block_7;
    if ((s8) reg_d0.b[0] > 8) goto block_7;
    goto block_6;
block_4:
    reg_d0.h[0] = 4;
    return;
block_5:
    reg_d0.h[0] = 4;
    return;
block_6:
    reg_d0.h[0] = 0;
    return;
block_7:
    if (reg_d7.h[0] != 0) goto next_8;
    func_00130050();
    goto next_9;
next_8:
    func_0012FFE0();
next_9:
    if (reg_d0.h[0] != 1) goto next_10;
    if (reg_d1.h[0] != 0) goto block_4;
    goto block_6;
next_10:
    if (reg_d1.h[0] != 0) goto next_11;
    reg_d4.h[0] = reg_d0.h[0];
    reg_a0 = (u8 *)D_00251BC0;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0);
    reg_d2.h[0] = 0;
    func_00137AD0();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    func_00137AD0();
    reg_d0.h[0] = 1;
    reg_d0.h[0] += *(u16 *)(reg_a4 + 2);
    func_00130CC0();
    cond_flag = 1;
    return;
next_11:
    reg_d0.h[0] -= reg_d1.h[0];
    if (0 >= (s16) reg_d0.h[0]) goto block_4;
    if ((reg_d0.h[0] & 0xFFFF) == 1) goto next_12;
    reg_d4.h[0] = reg_d0.h[0];
    reg_a0 = (u8 *)D_00251BE0;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0);
    reg_d2.h[0] = 0;
    func_00137AD0();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    func_00137AD0();
    reg_d0.h[0] = 1;
    reg_d0.h[0] += *(u16 *)(reg_a4 + 2);
    func_00130CC0();
    cond_flag = 1;
    return;
next_12:
    reg_a0 = (u8 *)D_00251C00;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0);
    reg_d2.h[0] = 0;
    func_00137AD0();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    func_00137AD0();
    cond_flag = 1;
}
