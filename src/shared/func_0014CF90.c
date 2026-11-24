#include "common.h"

typedef void (*Fn)();

extern u8 D_002526F0[];
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a6;

void func_0014CF90(void) {
    u32 temp_a1;
    reg_d2.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (8)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
    reg_a2 = (u8 *)(reg_tmp.w);
loop_1:
    reg_d0.h[0] = *(u16 *)reg_a2;
    temp_a1 = reg_d0.h[0];
    reg_a2 += 2;
    if ((s16)(temp_a1) != -1) {
        reg_a3 = (u8 *)D_002526F0;
        reg_d0.h[0] = temp_a1 + temp_a1;
        reg_d0.h[0] += reg_d0.h[0];
        reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
        reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a3;
        reg_a3 = (u8 *) reg_tmp.w;
        jtbl_0028E3F4 = (Fn)(reg_a3);
        jtbl_0028E3F4();
        reg_d2.h[0] -= 1;
        if (reg_d2.h[0] == 0) {
            reg_tmp.w = (u32)reg_a2;
            (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[0];
        } else {
            goto loop_1;
        }
    }
}
