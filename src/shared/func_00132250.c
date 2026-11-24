#include "common.h"

extern u16 D_00269AB0[];
extern u8 D_00269ADE[];
extern u16 D_00269AE0[];
extern u16 D_00269B10[];
extern u16 D_00269B40[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_00132250(void) {
    if ((*(s16 *)((u8 *)(reg_a6) + (0x3E))) >= 0) {
        reg_d1.w = 0;
        reg_a0 = (u8 *)(D_00269AB0);
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x3E)));
        reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0x4C))) += reg_d0.h[0];
        reg_a1 = (u8 *)(D_00269AE0);
        reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a1;
        (*(u16 *)((u8 *)(reg_a6) + (0x4E))) += reg_d0.h[0];
        reg_a1 = (u8 *)(D_00269B10);
        reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a1;
        (*(u16 *)((u8 *)(reg_a6) + (0x50))) += reg_d0.h[0];
        reg_a1 = (u8 *)(D_00269B40);
        reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a1;
        (*(u16 *)((u8 *)(reg_a6) + (0x52))) += reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x3E))) += 2;
        reg_a0 += reg_d1.w;
        if (D_00269ADE == reg_a0) {
            (*(u16 *)((u8 *)(reg_a6) + (0x3E))) = 0xFFFF;
        }
    }
}
