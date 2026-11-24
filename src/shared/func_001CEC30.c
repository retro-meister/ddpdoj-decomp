#include "common.h"

s32 func_00129280();
s32 func_001292C0();
extern u16 D_0028E910;
extern u8 *reg_a5;

void func_001CEC30(void) {
    u32 tmp;

    if (D_0028E910 != 0) goto next_4;
    reg_d5.w = 0xFFFE0004;
    reg_d7.h[0] = 2;
    reg_d6.h[0] = 0x55;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (!(reg_tmp.w < 0x8C00U)) goto loop_1;
    reg_d5.w = 0xFFFE0004;
    reg_d7.h[0] = 3;
    reg_d6.h[0] = 0x40;
loop_1:
    reg_d0.w = reg_d5.w;
    if (reg_d1.b[0] < 0x40) goto next_2;
    if (reg_d1.b[0] <= 0xC0) goto next_3;
next_2:
    reg_d0.w += 0x80000;
next_3:
    func_00129280();
    reg_d1.b[0] += reg_d6.b[0];
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    goto block_rts;
next_4:
    reg_d5.w = 0xFFFE0004;
    reg_d7.h[0] = 4;
    reg_d6.h[0] = 0x33;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (!(reg_tmp.w < 0x8C00U)) goto loop_5;
    reg_d5.w = 0xFFFE0004;
    reg_d7.h[0] = 5;
    reg_d6.h[0] = 0x2A;
loop_5:
    reg_d0.w = reg_d5.w;
    if (reg_d1.b[0] < 0x40) goto next_6;
    if (reg_d1.b[0] <= 0xC0) goto next_7;
next_6:
    reg_d0.w += 0x100000;
next_7:
    func_001292C0();
    reg_d1.b[0] += reg_d6.b[0];
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_5;
block_rts:
    return;
}
