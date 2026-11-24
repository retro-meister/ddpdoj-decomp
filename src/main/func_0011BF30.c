#include "common.h"

extern u32 D_0028E0F8[];
extern u32 D_0028E0FC[];
extern u16 D_0028E100[];
extern u16 D_0028E102[];
extern u16 D_0028E104[];
extern u16 D_0028E106[];
extern s32 D_0028E108[];
extern s32 D_0028E10C[];

void func_0011BF30(void) {
    u32 sv_d0;
    u32 sv_d1;

    sv_d0 = reg_d0.w;
    sv_d1 = reg_d1.w;
    D_0028E0F8[0] += reg_d0.w;
    reg_d2.w = D_0028E0F8[0];
    reg_d2.w &= ~0x3F;
    D_0028E108[0] += reg_d2.w;
    D_0028E0F8[0] &= 0x3F;
    D_0028E0FC[0] += (s16) reg_d1.h[0];
    reg_d2.w = D_0028E0FC[0];
    reg_d2.w &= ~0x3F;
    D_0028E10C[0] += reg_d2.w;
    D_0028E0FC[0] &= 0x3F;
    D_0028E100[0] += reg_d0.h[0];
    reg_d0.h[0] = D_0028E100[0];
    reg_d0.h[0] &= 0xFFC0 & 0xFFFF;
    reg_d0.h[0] *= 0xFFFF & 0xFFFF;
    D_0028E104[0] = reg_d0.h[0];
    D_0028E100[0] &= 0x3F;
    D_0028E102[0] += reg_d1.h[0];
    reg_d1.h[0] = D_0028E102[0];
    reg_d1.h[0] &= 0xFFC0;
    reg_d1.h[0] *= 0xFFFF;
    D_0028E106[0] = reg_d1.h[0];
    D_0028E102[0] &= 0x3F;
    reg_d1.w = sv_d1;
    reg_d0.w = sv_d0;
}
