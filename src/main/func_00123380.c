#include "common.h"

extern u8 D_002BDA80[];
extern u8 *reg_a3;

void func_00123380(void) {
    u32 tmp;

    reg_a3 = (u8 *)D_002BDA80;
    reg_d7.h[0] = 0xC7;
loop_1:
    reg_tmp.h[1] = *(u16 *) (reg_a3 + 0);
    reg_tmp.h[0] = *(u16 *) (reg_a3 + 2);
    if (reg_tmp.w != 0) goto next_1;
    *(u16 *) (reg_a3 + 0) = reg_d0.h[1];
    *(u16 *) (reg_a3 + 2) = reg_d0.h[0];
    *(u16 *) (reg_a3 + 4) = reg_d1.h[1];
    *(u16 *) (reg_a3 + 6) = reg_d1.h[0];
    goto block_rts;
next_1:
    reg_a3 += 8;
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
block_rts:
    return;
}
