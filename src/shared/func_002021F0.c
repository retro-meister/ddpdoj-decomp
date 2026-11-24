#include "common.h"

#pragma divbyzerocheck on

typedef void (*Fn)();

extern u8 D_00267120[];
extern u8 D_00267140[];
extern u8 D_00267150[];
extern u16 D_0028E484;

void func_002021F0(void) {
    reg_d4.h[0] = 0x1800;
    reg_d0.h[0] += reg_d4.h[0];
    reg_d1.h[0] += reg_d4.h[0];
    reg_d2.h[0] += reg_d4.h[0];
    reg_d3.h[0] += reg_d4.h[0];
    reg_d4.w = 8;
    D_0028E484 = reg_d1.h[0];
    reg_d1.h[0] -= reg_d3.h[0];
    if ((s32) D_0028E484 < (s32) reg_d3.h[0]) {
        reg_d4.w = 0;
        reg_d1.h[0] *= 0xFFFF;
    }
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] -= reg_d2.h[0];
    if ((s32) reg_tmp.h[0] < (s32) reg_d2.h[0]) {
        reg_d0.h[0] *= 0xFFFF;
        reg_d4.h[0] += 4;
    }
    reg_d2.h[0] = reg_d1.h[0];
    reg_d2.h[0] = (u16) ((s16) reg_d2.h[0] >> 1);
    reg_d1.h[0] += reg_d2.h[0];
    if (!((s32) reg_d0.h[0] > (s32) reg_d1.h[0])) goto next_1;
    reg_d4.h[0] += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.w = reg_d1.w;
    reg_d1.w = reg_tmp.w;
next_1:
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = 0;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    if (reg_d1.h[0] == 0) goto block_rts;
    reg_d0.w <<= 6;
    reg_d2.h[0] = reg_d0.w % reg_d1.h[0];
    reg_d0.w = reg_d0.w / (u32) (u16) reg_d1.h[0];
    reg_d2.h[0] *= 2;
    reg_d0.h[0] *= 2;
    if (!((s32) reg_d1.h[0] < (s32) reg_d2.h[0])) goto next_2;
    reg_d0.h[0] += 1;
next_2:
    reg_d0.b[0] = *(s8 *)(D_00267150 + reg_d0.h[0]);
    reg_d1.h[0] = *(s16 *)(D_00267140 + (reg_d4.h[0] & ~1));
    ((Fn)*(u32 *)((u8 *)D_00267120 + (((s32) reg_d4.h[0] >> 1) * 4)))();
block_rts:
    return;
}
