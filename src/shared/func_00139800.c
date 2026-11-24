#include "common.h"

extern u16 D_0029C060[];
extern u8 *reg_a1;
extern void *reg_a5_as_void_p;

void func_00139800(void) {
    if (0 <= (s64) *(s16 *) reg_a1) {
        goto block_rts;
    }
    reg_d5.h[0] = *(u16 *) (reg_a1 + 0x5C);
    *(u16 *) (reg_a1 + 0x5C) = 0;
    reg_d5.h[0] = (s16) reg_d5.h[0] >> 2;
    if (reg_d5.h[0] == 0) {
        goto block_rts;
    }
    reg_d4.w = 6;
    reg_d0.h[0] = reg_d5.h[0];
    reg_d5.h[0] = (s16) reg_d5.h[0] >> 1;
    reg_d0.h[0] += reg_d5.h[0];
    if (0 > (s64) (s16) reg_d0.h[0]) {
        goto next_1;
    }
    reg_d4.w = 7;
next_1:
    if ((1U << reg_d4.b[0]) & ((u8 *) reg_a5_as_void_p)[0x31]) {
        goto block_rts;
    }
    reg_d1.h[0] = D_0029C060[0];
    if (reg_d1.h[0] == 0) {
        goto next_4;
    }
    if (0 > (s64) (s16) reg_d1.h[0]) {
        goto next_2;
    }
    if (!((s32) reg_d1.h[0] < (reg_d0.h[0] & 0xFFFF))) {
        goto block_rts;
    }
    if (0 > (s64) (s16) reg_d0.h[0]) {
        goto next_4;
    }
    goto next_3;
next_2:
    if (!((reg_d0.h[0] & 0xFFFF) < (s32) reg_d1.h[0])) {
        goto block_rts;
    }
    if (!(0 > (s64) (s16) reg_d0.h[0])) {
        goto next_4;
    }
next_3:
    reg_d1.w = 0;
next_4:
    reg_d1.h[0] += reg_d0.h[0];
    D_0029C060[0] = reg_d1.h[0];
block_rts:;
}
