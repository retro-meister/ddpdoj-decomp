#include "common.h"

extern u16 D_00255510[];
extern u16 D_0028DFFC;
extern u16 D_0028E5E8;
extern u16 D_0028E5EC;
extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern u8 D_0028E855;
extern u16 D_0028E908;
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern u8 *reg_a0;

void func_0013D660(void) {
    reg_d0.h[0] = D_0028E5EC;
    if ((s32) D_0028E5E8 > (s32) reg_d0.h[0]) {
        reg_d0.h[0] = D_0028E5E8;
    }
    if (reg_d0.h[0] == 0) goto next_1;
    reg_d2.h[0] = D_0028E5FC;
    reg_d2.h[0] |= D_0028E5F8;
    if (reg_d2.h[0] != 0) goto next_2;
    reg_d0.h[0] >>= 2;
    if (reg_d0.h[0] == 0) goto next_1;
next_2:
    reg_d2.h[0] = reg_d0.h[0];
    reg_a0 = (u8 *) D_00255510;
    reg_d2.h[0] -= 1;
    reg_d2.h[0] *= 2;
    reg_d0.h[0] = (reg_d2.h[0] != 0) ? *(u16 *) ((u8 *) reg_a0 + ((s16) reg_d2.h[0] & ~1)) : *(u16 *) reg_a0;
    if (D_0028E855 & 4) {
        reg_d0.h[0] += 2;
    }
next_1:
    if (D_0028E910 != 0) {
        reg_d0.h[0] += 1;
        if ((D_0028E91C == 4) && (D_0028E908 != 0)) {
            reg_d0.h[0] += 4;
        }
    }
    if ((s32) reg_d0.h[0] > 0xA) {
        reg_d0.h[0] = 0xA;
    }
    D_0028DFFC = MAIN_OR_DEATH_LABEL(reg_d0.h[0], 0xA);
}
