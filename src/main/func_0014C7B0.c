#include "common.h"

extern u16 D_0028E8A8;
extern u8 D_0029C082[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a5;

void func_0014C7B0(void) {
    reg_a0 = (u8 *)D_0029C082;
    reg_a1 = reg_a5 + 0xA;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0xC)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0xE)));
    reg_a2 = (u8 *)reg_tmp.w;
    if (reg_a2 == 0) return;
    (*(u16 *)((u8 *)(reg_a0) + (0x16))) -= 1;
    if (0 >= (s16) (*(u16 *)((u8 *)(reg_a0) + (0x16)))) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0x10)));
        if ((s16) reg_d0.h[0] != -1) {
            (*(u16 *)((u8 *)(reg_a0) + (0x10))) -= 1;
            if (0 >= (s16) (*(u16 *)((u8 *)(reg_a0) + (0x10)))) {
                (*(u16 *)((u8 *)(reg_a0) + (0xC))) = 0U;
                (*(u16 *)((u8 *)(reg_a0) + (0xE))) = 0U;
                (*(s16 *)((u8 *)(reg_a5) + (8))) = 0;
                D_0028E8A8 = (*(u16 *)((u8 *)(reg_a0) + (0x18)));
                return;
            }
        }
        (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (0x14)));
        reg_tmp.w = (u32)reg_a2;
        (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
    }
}
