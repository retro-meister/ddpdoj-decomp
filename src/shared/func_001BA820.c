#include "common.h"

s32 func_00201E20();
extern u16 D_002BDA90[];
extern u16 D_002BDA92[];
extern u8 D_002BDA94[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_001BA820(void) {
    u32 t;
    u32 t1;
    u16 *p;

    reg_d0.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.w = reg_d0.w;
    t1 = reg_d1.w;
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA6);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xA8);
    reg_d1.w = t1 + reg_tmp.w;
    reg_d1.w += 0xE0000000;
    *(u16 *)(reg_a6 + 0xA2) = reg_d1.h[1];
    *(u16 *)(reg_a6 + 0xA4) = reg_d1.h[0];
    reg_a0 = (u8 *)D_002BDA94;
    p = D_002BDA90;
    reg_a1 = (u8 *)p;
    reg_d1.w = 3;
loop_1:
    reg_a0 -= 4;
    reg_a1 -= 4;
    *(u16 *)(reg_a0 + 0) = *(u16 *)(reg_a1 + 0);
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a1 + 2);
    t = reg_d1.h[0] - 1;
    reg_d1.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    *(u16 *)(reg_a1 + 0) = reg_d0.h[1];
    *(u16 *)(reg_a1 + 2) = reg_d0.h[0];
    if (*(u8 *)(reg_a6 + 0x3E) != 0) goto next_2;
    reg_d0.h[1] = *p;
    reg_d0.h[0] = D_002BDA92[0];
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x26);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x28);
    reg_d0.w += reg_tmp.w;
    *(u16 *)(reg_a6 + 0x22) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x24) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x24) += 0x80;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x4B);
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x4A);
    func_00201E20();
    reg_d2.h[0] = (s16) reg_d2.h[0] * 2;
    reg_d2.h[0] += 0xFD80;
    *(u16 *)(reg_a6 + 0x22) += reg_d2.h[0];
    reg_d3.h[0] = (s16) reg_d3.h[0] * 4;
    *(u16 *)(reg_a6 + 0x24) += reg_d3.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x4C);
    *(u16 *)(reg_a6 + 0x22) -= reg_d0.h[0];
next_2:
    if (*(u8 *)(reg_a6 + 0x7E) != 0) goto next_3;
    reg_d0.h[1] = *p;
    reg_d0.h[0] = D_002BDA92[0];
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x66);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x68);
    reg_d0.w += reg_tmp.w;
    *(u16 *)(reg_a6 + 0x62) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x64) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x64) += 0xFF80;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x8B);
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x8A);
    func_00201E20();
    reg_d2.h[0] = (s16) reg_d2.h[0] * 2;
    reg_d2.h[0] += 0xFD80;
    *(u16 *)(reg_a6 + 0x62) += reg_d2.h[0];
    reg_d3.h[0] = (s16) reg_d3.h[0] * 4;
    *(u16 *)(reg_a6 + 0x64) += reg_d3.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x8C);
    *(u16 *)(reg_a6 + 0x62) -= reg_d0.h[0];
next_3:
    return;
}
