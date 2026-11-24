#include "common.h"

typedef void (*Fn)();

extern s8 D_0028E408;

s32 func_00123240();
s32 func_00123410();
s32 func_0013BE50();
s32 func_0013C300();
s32 func_0013C350();
s32 func_0018DA30();
s32 func_0018DA50();
s32 func_0019C790();
s32 func_001A3020();
extern u32 D_0024D640[];
extern u32 D_0024D660[];
extern u32 D_0025F770_as_u32_a[];
extern u32 D_0028C090;
extern u32 D_0028C098;
extern u16 D_00295E38[];
extern u16 D_00295E3A[];
extern s16 D_00295E3C_as_s16_a[];
extern s16 D_0029F260[];
void func_0016A8D0();
void func_0016A8E0();
extern u32 jtbl_0028E3F4_as_u32;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

#define W(o) (*(u16 *)(reg_a6 + (o)))

void func_00123C20(void) {
    if (W(6) != 0) goto next_10;
    W(6) = 1;
    func_00123240();
    W(0xC) = 0;
    D_00295E3C_as_s16_a[0] = 1;
    D_00295E38[0] = 1;
    D_00295E3A[0] = 0x258;
    reg_a0 = (u8 *) D_0025F770_as_u32_a;
    reg_d0.h[0] = 3;
    func_001A3020();
next_10:
    if (W(6) != 1) goto next_20;
    reg_a0 = (u8 *) &D_0028C098;
    reg_a0 += W(0xC);
    reg_d0.w = *(u32 *)reg_a0;
    if (reg_d0.w != -1U) goto next_15;
    W(6) = 2;
    reg_tmp.w = (u32) (void *) func_0016A8D0;
    W(0x18) = reg_tmp.h[1];
    W(0x1A) = reg_tmp.h[0];
    if (0 > D_0029F260[0]) goto next_20;
    reg_tmp.w = (u32) (void *) func_0016A8E0;
    W(0x18) = reg_tmp.h[1];
    W(0x1A) = reg_tmp.h[0];
    goto next_20;
next_15:
    reg_a0 = (u8 *) reg_d0.w;
    func_00123410();
    if (D_0028E408 != 0) goto next_20;
    W(0xC) += 4;
next_20:
    if (W(6) != 2) goto next_40;
    reg_tmp.h[1] = W(0x18);
    reg_tmp.h[0] = W(0x1A);
    jtbl_0028E3F4_as_u32 = reg_tmp.w;
    ((Fn) jtbl_0028E3F4_as_u32)();
    if (!(reg_d0.h[0] & 4)) goto next_25;
    D_00295E38[0] += 1;
    func_0018DA50();
next_25:
    reg_tmp.h[1] = W(0x18);
    reg_tmp.h[0] = W(0x1A);
    jtbl_0028E3F4_as_u32 = reg_tmp.w;
    ((Fn) jtbl_0028E3F4_as_u32)();
    if (!(reg_d0.h[0] & 8)) goto next_28;
    D_00295E38[0] += 1;
    func_0018DA50();
next_28:
    D_00295E38[0] &= 1;
    reg_tmp.h[1] = W(0x18);
    reg_tmp.h[0] = W(0x1A);
    jtbl_0028E3F4_as_u32 = reg_tmp.w;
    ((Fn) jtbl_0028E3F4_as_u32)();
    reg_d0.h[0] &= 0x70;
    if (reg_d0.h[0] == 0) goto next_35;
next_32:
    func_0018DA30();
    reg_a0 = (u8 *) D_0024D640;
    func_0013BE50();
    W(0x14) = reg_d0.h[1];
    W(0x16) = reg_d0.h[0];
    W(6) = 3;
    goto next_40;
next_35:
    D_00295E3A[0] -= 1;
    if (D_00295E3A[0] == 0) goto next_32;
next_40:
    if (W(6) != 3) goto next_50;
    reg_d0.h[1] = W(0x14);
    reg_d0.h[0] = W(0x16);
    func_0013C350();
    if (D_0028E408 != 0) goto next_50;
    func_0013C300();
    *(s8 *)(reg_a5 + 3) = 2;
next_50:
    if ((s16) W(6) < 2) goto block_rts;
    reg_a0 = (u8 *) &D_0028C090;
    reg_d0.h[0] = D_00295E38[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 0xE8;
    reg_d3.h[0] = 0x210;
    reg_d4.h[0] = 3;
    func_0019C790();
    reg_d1.h[0] += 0x1000;
    reg_d4.h[0] |= 0x40;
    func_0019C790();
    reg_d0.w = 0;
    reg_d0.h[0] = D_00295E3A[0];
    reg_d0.w /= 0x3C;
    reg_a0 = (u8 *) D_0024D660;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.w = 0x5E001C00;
    reg_d3.h[0] = 0x210;
    reg_d4.h[0] = 3;
    func_0019C790();
block_rts:
    return;
}
