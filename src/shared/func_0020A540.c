#include "common.h"

s32 func_00209E80();
s32 func_00209EA0();
s32 func_00209EC0();
s32 func_00209EE0();
extern u16 D_0028E3E0;
extern u16 D_0028E3EC;
extern u8 *D_0028E570;
extern u8 D_00299D30[];
extern u16 D_0029A528[];
extern u16 D_0029A52A[];
extern u8 D_002A5A30[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

#define W(o) (*(u16 *)(reg_a6 + (o)))
#define LOOKUP(d) (((d) != 0) ? *(u16 *)(reg_a0 + ((s16)(d) & ~1)) : *(u16 *)reg_a0)

void func_0020A540(void) {
    reg_d0.w = 0;
    D_0029A52A[0] = 0xD0;
    D_0029A52A[0] -= reg_d0.h[0];
    if (0 > (s16) D_0029A52A[0]) {
        D_0029A52A[0] = 0;
    }
    reg_d7.h[0] = D_0029A528[0];
    if (reg_d7.h[0] == 0) return;
    reg_d7.h[0] -= 1;
    reg_d6.h[0] = D_0028E3E0;
    reg_d6.h[0] = -reg_d6.sh[0];
    reg_tmp.w = reg_d6.w;
    reg_d6.h[1] = reg_tmp.h[0];
    reg_d6.h[0] = D_0028E3EC;
    reg_d5.h[0] = 0x7000;
    reg_tmp.w = reg_d5.w;
    reg_d5.h[1] = reg_tmp.h[0];
    reg_d5.h[0] = D_0029A52A[0];
    reg_d4.w = 6;
    reg_d3.w = 0x07FF03FF;
    reg_d2.w = 0x80008000;
    reg_d1.w = 0x1A;
    reg_a6 = (u8 *)D_00299D30;
    reg_a4 = (u8 *)D_002A5A30;
    D_0028E570 = reg_a4;
    goto loop_2;
loop_1:
    reg_a6 += 0x20;
loop_2:
    reg_d0.h[0] = W(0);
    reg_a6 += 2;
    if (reg_d0.h[0] == 0) goto loop_1;
    if (reg_d5.h[0] == 0) goto block_clr2;
    reg_d5.h[0] -= 1;
    reg_d0.h[0] = W(0);
    reg_a6 += 2;
    switch (reg_d0.h[0]) {
    default:
    block_clr2:
        func_00209E80();
        reg_a6 += 0x20;
        if ((s16)(--reg_d7.h[0]) >= 0) goto loop_2;
        func_00209EE0();
        return;
    case 0:
    block_a:
        reg_a6[0xF] -= 1;
        if (0 > (s8) reg_a6[0xF]) goto next_4;
        goto block_move;
    next_4:
        reg_a6[0xF] = reg_a6[0xE];
        goto block_anim;
    block_d:
        reg_a6[0x17] -= 1;
        if (0 > (s8) reg_a6[0x17]) goto next_5;
        goto block_a;
    next_5:
        reg_a6[0x17] = reg_a6[0x16];
    case 4:
        reg_a6[0x17] -= 1;
        if (0 > (s8) reg_a6[0x17]) goto next_6;
        goto block_a;
    next_6:
        reg_a6[0x17] = reg_a6[0x16];
    case 8:
    block_anim:
        reg_d0.h[0] = W(0x10);
        reg_tmp.h[0] = W(0x10);
        W(0x10) -= 4;
        if (reg_tmp.h[0] < 4) goto block_clr4;
        reg_tmp.h[1] = W(0x12);
        reg_tmp.h[0] = W(0x14);
        reg_a0 = (u8 *) reg_tmp.w;
        W(4) = LOOKUP(reg_d0.h[0]);
        W(6) = LOOKUP(reg_d0.h[0] + 2);
    block_move:
        reg_d0.h[1] = W(0x18);
        reg_d0.h[0] = W(0x1A);
        reg_tmp.h[1] = W(0);
        reg_tmp.h[0] = W(2);
        reg_d0.w += reg_tmp.w;
        W(0) = reg_d0.h[1];
        reg_a6 += 2;
        W(0) = reg_d0.h[0];
        reg_a6 += 2;
        if (0 > reg_d6.sh[0]) goto next_3;
        if (!(reg_d5.w > reg_d0.w)) goto block_clr8;
    next_3:
        reg_d0.w = reg_d0.sw >> reg_d4.w;
        reg_d0.w &= reg_d3.w;
        reg_d0.w |= reg_d2.w;
        *(u16 *)reg_a4 = reg_d0.h[1];
        reg_a4 += 2;
        *(u16 *)reg_a4 = reg_d0.h[0];
        reg_a4 += 2;
        *(u16 *)reg_a4 = W(0);
        reg_a6 += 2;
        reg_a4 += 2;
        *(u16 *)reg_a4 = W(0);
        reg_a6 += 2;
        reg_a4 += 2;
        *(u16 *)reg_a4 = W(0);
        reg_a6 += 2;
        reg_a4 += 2;
        *(u16 *)reg_a4 = W(0);
        reg_a4 += 2;
        reg_a6 += 0x14;
        if ((s16)(--reg_d7.h[0]) >= 0) goto loop_2;
        func_00209EE0();
        return;
    case 12:
        goto block_d;
    }
block_clr4:
    func_00209EA0();
    reg_a6 += 0x1E;
    if ((s16)(--reg_d7.h[0]) >= 0) goto loop_2;
    func_00209EE0();
    return;
block_clr8:
    func_00209EC0();
    reg_a6 += 0x1A;
    if ((s16)(--reg_d7.h[0]) >= 0) goto loop_2;
    func_00209EE0();
}
