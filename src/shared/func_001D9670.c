#include "common.h"

typedef void (*Fn)();

s32 func_00129410();
s32 func_001D7940();
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001D9670(s32 arg0, s32 arg1, void *arg2) {
    if ((*(u8 *)((u8 *)(reg_a4) + (0x17))) != 0) goto next_0;
    if ((*(s16 *)((u8 *)(reg_a4) + (0xA))) <= 0x10) goto next_1;
    jtbl_0028E3F4 = (Fn)(arg2);
    jtbl_0028E3F4();
next_1:
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) -= 1;
    if ((*(s16 *)((u8 *)(reg_a4) + (0xA))) != 0) goto next_0;
    (*(u8 *)((u8 *)(reg_a4) + (0x17))) = 1;
next_0:
    if ((*(u8 *)((u8 *)(reg_a4) + (0x17))) != 1) return;
    (*(u8 *)((u8 *)(reg_a4) + (0x19))) += 1;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
    if ((s32)reg_tmp.b[0] > 0) return;
    (*(u8 *)((u8 *)(reg_a4) + (5))) = (*(u8 *)((u8 *)(reg_a4) + (4)));
    reg_d0.h[0] = ((arg0) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg0) & ~1)) : *(u16 *)reg_a6;
    func_001D7940();
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : *(u16 *)reg_a6;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : *(u16 *)reg_a6;
    reg_d4.w = 0;
    reg_d7.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x19)));
    reg_d1.b[0] -= reg_d7.b[0];
    func_00129410();
    reg_d0.h[0] = 9;
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    reg_d1.b[0] += reg_d7.b[0];
    func_00129410();
    reg_d0.h[0] = ((arg0) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg0) & ~1)) : *(u16 *)reg_a6;
    reg_d0.h[0] += 8;
    func_001D7940();
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : *(u16 *)reg_a6;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : *(u16 *)reg_a6;
    reg_d4.w = 0;
    reg_d7.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x19)));
    reg_d1.b[0] -= reg_d7.b[0];
    func_00129410();
    reg_d0.h[0] = 9;
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    reg_d1.b[0] += reg_d7.b[0];
    func_00129410();
    reg_d0.h[0] = ((arg0) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg0) & ~1)) : *(u16 *)reg_a6;
    reg_d0.h[0] += 0x10;
    func_001D7940();
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : *(u16 *)reg_a6;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : *(u16 *)reg_a6;
    reg_d4.w = 0;
    reg_d7.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x19)));
    reg_d1.b[0] -= reg_d7.b[0];
    func_00129410();
    reg_d0.h[0] = 9;
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    reg_d1.b[0] += reg_d7.b[0];
    func_00129410();
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1B)));
    (*(u8 *)((u8 *)(reg_a4) + (0x1B))) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_2;
    (*(u8 *)((u8 *)(reg_a4) + (0x1B))) = (*(u8 *)((u8 *)(reg_a4) + (0x1A)));
    (*(u16 *)((u8 *)(reg_a4) + (8))) += 1;
next_2:
    (*(u16 *)((u8 *)(reg_a4) + (6))) -= 1;
    if ((*(s16 *)((u8 *)(reg_a4) + (6))) != 0) return;
    (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
}
