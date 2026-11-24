#include "common.h"

extern u8 D_002B4E28[];
extern u8 D_002B5728[];
extern u8 D_002B5F28[];
extern u8 D_002B6828[];
extern u16 D_002BAF30[];
extern u16 D_002BAF3A[];
extern u16 D_002BAF50[];
extern u16 D_002BAFAA[];
extern u8 *reg_a0;

void func_001AACC0(void) {
    u32 t;
    s32 t2;

    reg_d0.w = 0;
    reg_d2.w = 0;
    reg_d1.w = (u32) D_002B4E28;
    reg_d3.w = 0;
    reg_d6.w = 1;
    reg_a0 = (u8 *)D_002BAF50;
loop_1:
    reg_d7.w = 8;
loop_2:
    *(u16 *)reg_a0 = reg_d0.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d1.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    reg_d1.w += 0x100;
    t2 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t2;
    if (((s64) ((s64) (u16) t2 << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_d1.w = (u32) D_002B5F28;
    reg_a0 = (u8 *)D_002BAFAA;
    t = reg_d6.h[0] - 1;
    reg_d6.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_a0 = (u8 *)D_002BAF30;
    *(u16 *)reg_a0 = reg_d0.h[0];
    reg_tmp.w = (u32) D_002B5728;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = 0xC030;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 = (u8 *)D_002BAF3A;
    *(u16 *)reg_a0 = reg_d0.h[0];
    reg_tmp.w = (u32) D_002B6828;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = 0xC030;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
}
