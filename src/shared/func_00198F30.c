#include "common.h"

s32 func_0013BDE0();
s32 func_0018DA30();
s32 func_00199970();
s32 func_00199A50();
s32 func_00199D50();
s32 func_0019A050();
s32 func_0019A2B0();
s32 func_0019A410();
s32 func_0019A520();
s32 func_0019A5B0();
s32 func_0019A640();
s32 func_0019A870();
extern u8 D_0025BD60[];
extern u8 D_0025BFD0[];
extern u16 D_002BAE82_as_u16_a[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;

#define W(o) (*(u16 *)(reg_a4 + (o)))
#define L(p, o) (*(u32 *)((p) + (o)))

void func_00198F30(void) {
    u8 *ptr;

    if (W(0x2E) == 0) goto next_1;
    func_0019A410();
next_1:
    reg_d0.b[0] = reg_a5[4];
    if (reg_d0.b[0] != 3) {
        if (reg_d0.w & 1) {
            func_0019A5B0();
        } else if (reg_d0.w & 2) {
            func_0019A520();
        }
    }
    func_0019A050();
    func_0019A2B0();
    if (W(0x1E) == 0) goto block_count;
    func_00199A50();
    if (D_002BAE82_as_u16_a[0] != 0) return;
    if (W(0x2E) == 0) return;
    if (W(0x1E) != 0x30) goto next_4;
    W(0x1E) -= 1;
    reg_a0 = (u8 *)D_0025BFD0;
    func_0013BDE0();
    return;
next_4:
    W(0x1E) -= 1;
    if (W(0x1E) != 0) goto next_5;
    reg_a5[3] = 2;
    return;
next_5:
    if (W(0x1E) == 0x30) {
        reg_d2.w = 0x20;
    }
    return;
block_count:
    W(2) += 1;
    reg_d7.h[0] = W(2);
    if (reg_d7.h[0] >= 0x30) goto next_6;
    func_00199A50();
    return;
next_6:
    if (reg_d7.h[0] >= 0x738) goto block_fill;
    reg_d0.w = 0xF;
    reg_d0.h[0] &= W(0x36);
    if (reg_d0.h[0] != 0) goto next_7;
    if (reg_a4[0x21] == 0) goto next_8;
    reg_a4[0x20] -= 1;
    if (reg_a4[0x20] != 0) goto next_8;
    func_0019A870();
    goto next_8;
next_7:
    W(0x14) = 0;
    func_0019A640();
next_8:
    func_00199D50();
    func_00199A50();
    reg_d0.h[0] = W(0x36);
    if (!(reg_d0.w & 0x8000)) goto next_9;
    func_0018DA30();
    if (W(0x16) != 0) goto block_fill;
block_default:
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_a1 = reg_a0;
    ptr = reg_a1;
    L(ptr, 0) = 0xC;
    L(ptr, 4) = 0xC;
    L(ptr, 8) = 0x3C;
    reg_a1 = ptr + 0xC;
    W(0x16) = 3;
    goto block_copy;
next_9:
    reg_d0.h[0] = W(0x36);
    reg_d3.w = 0x20;
    reg_d3.h[0] &= reg_d0.h[0];
    if (reg_d3.h[0] != 0) goto next_12;
    reg_d0.h[0] &= 0x50;
    if (reg_d0.h[0] == 0) return;
    func_0018DA30();
    reg_d0.h[0] = W(0x18);
    if (reg_d0.h[0] < 27) goto next_13;
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
loop_10:
    reg_d0.w = 0x70;
loop_11:
    reg_d1.h[0] = W(0x16);
    L(reg_a0, reg_d1.h[0] * 4) = reg_d0.w;
    W(0x16) += 1;
    if (W(0x16) != 3) goto loop_11;
    goto block_check;
block_fill:
    reg_d0.h[0] = W(0x18);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d1.h[0] = W(0x16);
    if (W(0x18) < 27) goto next_14;
    reg_d0.w = 0;
    goto block_default;
next_14:
    L(reg_a0, reg_d1.h[0] * 4) = reg_d0.w;
    W(0x16) += 1;
    if (W(0x16) != 3) goto loop_10;
    goto block_check;
next_12:
    reg_d1.w = 0;
    reg_d1.h[0] = W(0x16);
    if (reg_d1.h[0] == 0) return;
    W(0x16) -= 1;
    reg_d1.h[0] = W(0x16);
    reg_d0.w = 0;
    goto block_store;
next_13:
    reg_d1.h[0] = W(0x16);
    W(0x16) += 1;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
block_store:
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
    L(reg_a0, reg_d1.h[0] * 4) = reg_d0.w;
    if (W(0x16) < 3) return;
block_check:
    reg_a1 = (u8 *)D_0025BD60;
loop_15:
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[1] = *(u16 *)(reg_a1 + 0);
    reg_d0.h[0] = *(u16 *)(reg_a1 + 2);
    if (reg_d0.w == 0xFFFFFFFF) goto block_copy;
    reg_tmp.w = L(reg_a0, 0);
    if (reg_tmp.w != reg_d0.w) goto next_16;
    reg_d0.h[1] = *(u16 *)(reg_a1 + 4);
    reg_d0.h[0] = *(u16 *)(reg_a1 + 6);
    reg_tmp.w = L(reg_a0, 4);
    if (reg_tmp.w != reg_d0.w) goto next_16;
    reg_d0.h[1] = *(u16 *)(reg_a1 + 8);
    reg_d0.h[0] = *(u16 *)(reg_a1 + 0xA);
    reg_tmp.w = L(reg_a0, 8);
    if (reg_tmp.w == reg_d0.w) goto block_default;
next_16:
    reg_a1 += 0xC;
    goto loop_15;
block_copy:
    func_00199970();
    reg_d1.h[0] = W(0x12);
    *(u8 *)D_002BAE82_as_u16_a &= ~(1 << reg_d1.sb[0]);
    W(0x1E) = 0x70;
    reg_d0.w = 0;
    W(0x1A) = reg_d0.h[1];
    W(0x1C) = reg_d0.h[0];
    func_00199A50();
}
