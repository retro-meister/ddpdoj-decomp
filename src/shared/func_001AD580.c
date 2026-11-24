#include "common.h"

extern u16 D_002BB342[];
extern u32 D_002BB404[];
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a5;

void func_001AD580(void) {
    u32 tmp;

    reg_a1 = (u8 *)D_002BB404;
    reg_a3 = (u8 *)D_002BB342;
    reg_d0.w = 4;
    reg_a2 = reg_a1;
    reg_a5 = reg_a3;
loop_1:
    reg_a1 -= 4;
    reg_d1.w = *(u32 *)reg_a1;
    reg_a3 -= 2;
    reg_d2.h[0] = *(u16 *)reg_a3;
    if ((s32) reg_d5.h[0] < (s32) reg_d2.h[0]) {
        goto next_1;
    }
    if ((s32) reg_d5.h[0] > (s32) reg_d2.h[0]) {
        goto next_2;
    }
    if ((u32) reg_d1.w >= (u32) reg_d7.w) {
        goto next_1;
    }
next_2:
    tmp = reg_d0.h[0] - 1;
    reg_d0.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
next_1:
    reg_d0.h[0] += 1;
    reg_d1.w = 4;
    reg_d2.h[0] = reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] -= reg_d2.h[0];
    reg_d0.h[0] += reg_d0.h[0];
}
