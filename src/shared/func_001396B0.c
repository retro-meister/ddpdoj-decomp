#include "common.h"


extern u16 D_0029C060[];
extern u16 D_0029C070[];
extern u8 *reg_a5;

void func_001396B0(void) {
    D_0029C070[0] = 0;
    reg_d2.h[0] = 0x800;
    reg_d0.h[0] = D_0029C060[0];
    D_0029C060[0] = 0;
    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a5) + (0x2A)));
    reg_d1.h[0] = reg_d0.h[0];
    if ((s16)(reg_d1.h[0]) < 0) {
        reg_d1.h[0] *= 0xFFFF & 0xFFFF;
        reg_d2.h[0] *= 0xFFFF;
    }
    if ((s32) reg_d1.h[0] > 0x800) {
        reg_d0.h[0] = reg_d2.h[0];
        D_0029C070[0] = 1;
    }
    (*(u16 *)((u8 *)(reg_a5) + (0x2A))) = (u16) reg_d0.h[0];
    reg_d0.h[0] &= 0xFFC0;
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
    (*(u16 *)((u8 *)(reg_a5) + (0x28))) = (u16) reg_d0.h[0];
    reg_d2.h[0] = reg_d0.h[0];
    reg_d0.h[0] -= reg_d1.h[0];
}
