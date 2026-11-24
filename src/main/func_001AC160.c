#include "common.h"

s32 func_0016AA30();
s32 func_001AC150();
extern u16 D_00255740[];
extern u16 D_0028E5B0;
extern u16 D_0028E5B4;
extern u16 D_0028E5BC;
extern u16 D_0028E5E0;
extern u16 D_0028E5F8;
extern u16 D_00299764[];
extern u16 D_00299766[];
extern s16 D_0029F1F0[];
extern u8 D_0029F215[];
extern u8 *reg_a0;
extern u8 *reg_a2;

void func_001AC160(void) {
    u32 save_d0;
    u32 save_d2;
    u32 save_d6;
    u8 *save_a0;
    u8 *save_a2;

    if (!((s32) D_0028E5E0 > 0x95F)) goto block_end;
    if (D_0028E5BC == 5) {
        func_001AC150();
        return;
    }
    if (D_0028E5B4 == 4) {
        func_001AC150();
        goto block_end;
    }
    D_0028E5E0 = 0;
    switch (D_0028E5B0) { case 0: goto next_1; }
    if (D_0029F1F0[0] >= 0) goto next_2;
    if (D_0029F215[0] != 0) goto next_2;
next_1:
    if (D_0028E5F8 == 0) goto next_3;
next_2:
    D_0028E5B4 += 1;
    if (D_0029F1F0[0] < 0) {
        reg_a0 = (u8 *)(D_00255740);
        reg_d0.h[0] = D_0028E5B4;
        reg_d0.h[0] -= 1;
        reg_d0.h[0] += reg_d0.h[0];
        D_00299764[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d0.w = 0x30;
        if ((D_0028E5B4 & 0xFFFF) == 5) {
            reg_d0.w = 0x3C;
        }
        D_00299766[0] = reg_d0.h[0];
    }
    return;
next_3:
    reg_d0.w = 0x14;
    save_d6 = reg_d6.w;
    save_d2 = reg_d2.w;
    save_d0 = reg_d0.w;
    save_a0 = reg_a0;
    save_a2 = reg_a2;
    reg_d6.h[0] = 0x7000;
    func_0016AA30();
    reg_d0.w = save_d0;
    reg_d2.w = save_d2;
    reg_d6.w = save_d6;
    reg_a0 = save_a0;
    reg_a2 = save_a2;
block_end:
    return;
}
