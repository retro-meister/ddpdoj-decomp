#include "common.h"

typedef void (*Fn)();

extern u8 D_002526D0[];
extern u8 D_0029C082[];
extern u8 D_0029C09E[];
extern u16 D_0029C0BA[];
extern u16 D_0029C0BC[];
extern u16 D_0029C0BE[];
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_0014CAE0(void) {
    u16 temp_a0;
    reg_a6 = (u8 *)D_0029C082;
    reg_d6.w = 1;
    do {
loop_1:
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_a1 = (u8 *)(reg_tmp.w);
        reg_d1.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        if (((s16)(reg_d1.h[0]) != -1) && ((reg_d1.h[0] & 0xFFFF) == reg_d7.h[0])) {
            reg_a1 += 2;
            temp_a0 = *(u16 *)reg_a1;
            reg_d2.h[0] = temp_a0;
            reg_a1 += 2;
            reg_a2 = (u8 *)D_002526D0;
            reg_a2 += reg_d2.h[0];
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a2) + (0)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a2) + (2)));
            reg_a2 = (u8 *) reg_tmp.w;
            jtbl_0028E3F4 = (Fn)(reg_a2);
            jtbl_0028E3F4();
            reg_tmp.w = (u32)reg_a1;
            (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
            goto loop_1;
        }
        reg_a6 = (u8 *)D_0029C09E;
    } while ((s16)(--reg_d6.h[0]) >= 0);
    reg_d0.h[1] = D_0029C0BC[0];
    reg_d0.h[0] = D_0029C0BE[0];
    if (reg_d0.w != 0) {
        D_0029C0BA[0] -= 1;
        if (0 > (s16) D_0029C0BA[0]) {
            reg_a0 = (u8 *)reg_d0.w;
            jtbl_0028E3F4 = (Fn)((u8 *) reg_a0);
            jtbl_0028E3F4();
            *(u32 *)D_0029C0BC = 0;
        }
    }
}
