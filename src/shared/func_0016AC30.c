#include "common.h"

typedef void (*Fn)();

s32 func_0016C4B0();
extern u8 D_0026ADA0[];
extern u16 D_0028E7B0;
extern u16 D_0029C06C[];
extern u8 D_002BB4B0[];
extern u8 *reg_a6;

void func_0016AC30(void) {
    u32 cnt;
    u8 flags;

    reg_d7.h[0] = D_0028E7B0;
    if (D_0028E7B0 == 0) {
        return;
    }
    reg_d7.h[0] -= 1;
    reg_a6 = (u8 *)D_002BB4B0;
    goto loop_1;
next_1:
    reg_a6 += 0x40;
loop_1:
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0);
    if (reg_d1.h[0] == 0) {
        goto next_1;
    }
    reg_d0.h[0] = D_0029C06C[0];
    *(u16 *)(reg_a6 + 4) -= reg_d0.h[0];
    flags = *(u8 *)(reg_a6 + 0);
    if ((flags & 0x80) || (flags & 1)) {
        func_0016C4B0();
        goto next_2;
    }
    reg_d0.w = 0x3C;
    reg_d0.h[0] &= reg_d1.h[0];
    ((Fn) *(u32 *)(D_0026ADA0 + (reg_d0.h[0] & ~3)))();
next_2:
    reg_a6 += 0x40;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
}
