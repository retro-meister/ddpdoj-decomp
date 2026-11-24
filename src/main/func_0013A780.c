#include "common.h"

extern u8 D_0029AA40[];
extern u8 D_0029BBC0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0013A780(void) {
    u8 *sa1;
    u8 *sa2;
    u8 *sa3;
    u8 *sa4;
    u8 *sa5;
    u8 *sa6;
    u32 s0;
    u32 s1;
    u32 t1;

    s0 = reg_d0.w;
    s1 = reg_d1.w;
    sa1 = reg_a1;
    sa2 = reg_a2;
    sa3 = reg_a3;
    sa4 = reg_a4;
    sa5 = reg_a5;
    sa6 = reg_a6;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] &= 0x7F;
    if (0 > (s16) reg_d1.h[0]) goto block_2;
    if ((s16) reg_d1.h[0] > 0x21) goto block_2;
    reg_d1.h[0] = 0x4F;
    reg_a0 = (u8 *)D_0029AA40;
loop_1:
    if (*(u16 *) reg_a0 != 0) goto next_1;
    reg_d0.h[0] |= 0x8000;
    *(u16 *) reg_a0 = reg_d0.h[0];
    reg_d0.w = 0;
    *(u16 *) (reg_a0 + 0x10) = reg_d0.h[0];
    *(u16 *) (reg_a0 + 0x12) = 0xFFFF;
    *(u8 *) (reg_a0 + 0x17) = 0x1E;
    *(u16 *) (reg_a0 + 0x18) = reg_d0.h[0];
    *(u16 *) (reg_a0 + 0x1A) = reg_d0.h[0];
    *(u8 *) (reg_a0 + 0x1D) = reg_d0.b[0];
    *(u8 *) (reg_a0 + 0x1C) = 0x1E;
    *(u16 *) (reg_a0 + 0x1E) = 0;
    *(u16 *) (reg_a0 + 0x22) = reg_d0.h[1];
    *(u16 *) (reg_a0 + 0x24) = reg_d0.h[0];
    *(u16 *) (reg_a0 + 0x26) = reg_d0.h[1];
    *(u16 *) (reg_a0 + 0x28) = reg_d0.h[0];
    *(u16 *) (reg_a0 + 0x34) = reg_d0.h[1];
    *(u16 *) (reg_a0 + 0x36) = reg_d0.h[0];
    reg_d0.w = s0;
    reg_d1.w = s1;
    reg_a1 = sa1;
    reg_a2 = sa2;
    reg_a3 = sa3;
    reg_a4 = sa4;
    reg_a5 = sa5;
    reg_a6 = sa6;
    return;
next_1:
    reg_a0 += 0x38;
    t1 = reg_d1.h[0] - 1;
    reg_d1.h[0] = t1;
    if (((s64) ((s64) (u16) t1 << 0x30) >> 0x30) >= 0) goto loop_1;
block_2:
    reg_d0.w = s0;
    reg_d1.w = s1;
    reg_a1 = sa1;
    reg_a0 = (u8 *)D_0029BBC0;
    reg_a2 = sa2;
    reg_a3 = sa3;
    reg_a4 = sa4;
    reg_a5 = sa5;
    reg_a6 = sa6;
}
