#include "common.h"

typedef void (*Fn)();

s32 func_00127FA0();
extern u8 D_002693E0[];
extern u8 *reg_a6;

void func_00125FF0(void) {
    u32 t1;

loop_1:
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0)));
    if (reg_d1.h[0] == 0) {
        reg_a6 += 0x2C;
        goto loop_1;
    }
    (*(u16 *)((u8 *)(reg_a6) + (4))) -= reg_d6.h[0];
    reg_d0.w = 0x7C;
    reg_d0.h[0] &= reg_d1.h[0];
    if ((s8) reg_d1.b[0] < 0) {
        func_00127FA0();
        return;
    }
    ((Fn)*(u32 *)((u8 *)D_002693E0 + (reg_d0.h[0] & ~3)))();
    reg_a6 += 0x2C;
    t1 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t1;
    if (((s64) ((s64) (t1 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
}
