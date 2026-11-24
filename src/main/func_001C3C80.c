#include "common.h"

extern s8 D_0028E408;

s32 func_00129320();
s32 func_00129370();
s32 func_002010A0();
s32 func_002012F0();
s32 func_00202730();
extern u16 D_0028E3EC;
extern u32 D_0028E47C;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001C3C80(void) {
    u8 t;
    u32 c;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    *(u8 *)(reg_a4 + 5) = *(u8 *)(reg_a4 + 4);
    reg_d6.w = 0;
    reg_d7.w = 0;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (!((s32) reg_tmp.w < 0x2F99)) goto loop_1;
    reg_d6.w = 3;
    if (D_0028E3EC != 0) goto loop_1;
    reg_d7.w = 1;
loop_1:
    func_00202730();
    if (D_0028E408 != 0) goto block_rts;
    func_002012F0();
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 3;
    reg_d3.h[0] = reg_d0.h[0];
    func_002012F0();
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 3;
    D_0028E47C = reg_d3.w;
    reg_d3.h[1] = reg_d3.h[0];
    reg_d3.h[0] = reg_d0.h[0];
    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d2.w += 0x06000000;
    func_002010A0();
    reg_d5.h[0] = reg_d0.h[0];
    reg_d4.h[0] = reg_d0.h[0];
    reg_d0.b[0] = (s8) reg_d0.b[0] * 4;
    reg_d0.b[0] += reg_d4.b[0];
    reg_d1.b[0] += reg_d0.b[0];
    func_002010A0();
    reg_d0.h[0] = (s8) reg_d0.b[0];
    reg_d5.h[0] = (s8) reg_d5.b[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 1;
    reg_d0.h[0] -= 6;
    if ((s16) reg_d5.h[0] >= 0) goto next_1;
    reg_d5.h[0] *= 0xFFFF;
next_1:
    if (reg_d5.h[0] <= 1) goto next_2;
    reg_d0.h[0] += reg_d5.h[0];
next_2:
    reg_d0.h[0] += reg_d6.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 0x16;
    reg_d4.w = 0;
    t = *(u8 *)(reg_a4 + 7);
    if (!(t & 1)) goto next_3;
    *(u8 *)(reg_a4 + 7) = t ^ 1;
    goto next_4;
next_3:
    *(u8 *)(reg_a4 + 7) = t ^ 1;
    func_00129320();
    goto next_5;
next_4:
    func_00129370();
next_5:
    c = reg_d7.h[0] - 1;
    reg_d7.h[0] = c;
    if (((s64) ((s64) (c & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
block_rts:
    return;
}
