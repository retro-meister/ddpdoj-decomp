#include "common.h"

extern u8 *reg_a0;
extern u8 *reg_a6;

void func_0019F750(void) {
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x43)));
    (*(u8 *)((u8 *)(reg_a6) + (0x43))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0x43))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x42)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x46)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x48)));
        reg_a0 = (u8 *)(reg_tmp.w);
        reg_d1.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d1.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_d1.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = (u16) reg_d1.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x2C))) = (u16) reg_d1.h[0];
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x58)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x5A)));
        reg_a0 = (u8 *)(reg_tmp.w);
        reg_d0.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0x5C))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x5E))) = (u16) reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x60))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x62))) = (u16) reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x44))) -= 4;
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x44))) < 0) {
            (*(u16 *)((u8 *)(reg_a6) + (0x44))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x4C)));
        }
    }
}
