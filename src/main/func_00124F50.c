#include "common.h"

extern u16 D_00295F44[];
extern u16 D_00296084[];
extern u8 *reg_a0;

void func_00124F50(void) {
    u32 t1;
    u32 t2;
    u32 s0;
    u32 saved;
    u32 s2;

    s0 = reg_d0.w;
    saved = reg_d1.w;
    s2 = reg_d2.w;
    reg_a0 = (u8 *)(D_00295F44);
    reg_d1.w = 9;
loop_1:
    reg_d2.h[0] = *(u16 *)reg_a0;
    if (reg_d2.h[0] == 0) {
        goto block_7;
    }
    reg_d2.h[0] &= 0xFF;
    if (reg_d0.h[0] == reg_d2.h[0]) {
        goto block_8;
    }
    reg_a0 += 0x20;
    t1 = reg_d1.h[0] - 1;
    reg_d1.h[0] = t1;
    if (((s64) ((s64) (t1 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
    reg_a0 = (u8 *)(D_00295F44);
    reg_d1.w = 9;
block_5:
    if ((s16) *(u16 *)reg_a0 != 0) {
        goto block_7;
    }
    reg_d0.h[0] |= 0x8000;
    *(u16 *)reg_a0 = reg_d0.h[0];
    reg_d0.w = s0;
    reg_d1.w = saved;
    reg_d2.w = s2;
    return;
block_7:
    reg_a0 += 0x20;
    t2 = reg_d1.h[0] - 1;
    reg_d1.h[0] = t2;
    if (((s64) ((s64) (t2 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto block_5;
    }
block_8:
    reg_d0.w = s0;
    reg_d1.w = saved;
    reg_d2.w = s2;
    reg_a0 = (u8 *)(D_00296084);
    return;
}
