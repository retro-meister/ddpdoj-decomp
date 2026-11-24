#include "common.h"

s32 func_001396B0();
s32 func_00139790();
s32 func_00139800();
extern u16 D_0029C060[];
extern u16 D_0029C062[];
extern u16 D_0029C064[];
extern u16 D_0029C066[];
extern u16 D_0029C068[];
extern u16 D_0029C06A[];
extern u16 D_0029C06C[];
extern u16 D_0029C06E[];
extern u16 D_0029F1F0[];
extern u16 D_0029F260[];
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00139930(void) {
    if (D_0029C062[0] != 0) {
        goto next_1;
    }
    reg_d0.h[0] = D_0029F260[0];
    reg_d1.h[0] = D_0029F1F0[0];
    reg_d1.h[0] ^= reg_d0.h[0];
    if (0 > (s64) (s16) reg_d1.h[0]) {
        goto next_2;
    }
next_1:
    reg_a5[0x31] &= 0x3F;
    reg_a1 = (u8 *) D_0029F260;
    func_00139790();
    reg_a1 = (u8 *) D_0029F1F0;
    func_00139790();
    reg_a1 = (u8 *) D_0029F260;
    func_00139800();
    reg_a1 = (u8 *) D_0029F1F0;
    func_00139800();
    goto next_4;
next_2:
    reg_a6 = (u8 *) D_0029F260;
    if (0 > (s64) (s16) D_0029F260[0]) {
        goto next_3;
    }
    reg_a6 = (u8 *) D_0029F1F0;
next_3:
    reg_d0.w = 0;
    reg_d0.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d0.w -= 0x1C00;
    reg_d0.w = (s32) reg_d0.w / 200;
    reg_d0.h[0] <<= 6;
    reg_d0.h[0] -= *(u16 *) (reg_a5 + 0x28);
    D_0029C060[0] = reg_d0.h[0];
next_4:
    func_001396B0();
    D_0029C064[0] = reg_d0.h[0];
    reg_d1.h[0] = *(u16 *) (reg_a5 + 0x28);
    reg_d1.h[0] >>= 6;
    reg_d2.h[0] = reg_d1.h[0];
    reg_d1.h[0] <<= 6;
    D_0029C066[0] = D_0029C068[0];
    D_0029C068[0] = reg_d1.h[0];
    reg_d0.h[0] = D_0029C06A[0];
    D_0029C06A[0] = reg_d2.h[0];
    reg_d2.h[0] -= reg_d0.h[0];
    reg_d2.h[0] <<= 6;
    D_0029C06C[0] = reg_d2.h[0];
    D_0029C06E[0] -= reg_d2.h[0];
}
