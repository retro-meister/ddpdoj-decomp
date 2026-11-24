#include "common.h"

extern u32 D_0028E0D8[];
extern u32 D_0028E0DC[];
extern u16 D_0028E0E0[];
extern u16 D_0028E0E2[];
extern u16 D_0028E0E4[];
extern u16 D_0028E0E6[];
extern s32 D_0028E0E8[];
extern s32 D_0028E0EC[];

void func_0011C0B0(void) {
    u32 sv_d0;
    u32 sv_d1;

    sv_d0 = reg_d0.w;
    sv_d1 = reg_d1.w;
    D_0028E0D8[0] += reg_d0.w;
    reg_d2.w = D_0028E0D8[0];
    reg_d2.w &= ~0x3F;
    D_0028E0E8[0] += reg_d2.w;
    D_0028E0D8[0] &= 0x3F;
    D_0028E0DC[0] += (s16) reg_d1.h[0];
    reg_d2.w = D_0028E0DC[0];
    reg_d2.w &= ~0x3F;
    D_0028E0EC[0] += reg_d2.w;
    D_0028E0DC[0] &= 0x3F;
    D_0028E0E0[0] += reg_d0.h[0];
    reg_d0.h[0] = D_0028E0E0[0];
    reg_d0.h[0] &= 0xFFC0 & 0xFFFF;
    reg_d0.h[0] *= 0xFFFF & 0xFFFF;
    D_0028E0E4[0] = reg_d0.h[0];
    D_0028E0E0[0] &= 0x3F;
    D_0028E0E2[0] += reg_d1.h[0];
    reg_d1.h[0] = D_0028E0E2[0];
    reg_d1.h[0] &= 0xFFC0;
    reg_d1.h[0] *= 0xFFFF;
    D_0028E0E6[0] = reg_d1.h[0];
    D_0028E0E2[0] &= 0x3F;
    reg_d1.w = sv_d1;
    reg_d0.w = sv_d0;
}
