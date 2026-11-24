#include "common.h"

extern u8 D_0024F0F0[];
extern u8 D_00262570[];
extern u8 D_00262572[];

void func_0012DA30(void) {
    s32 off;

    reg_d3.h[0] = *(u16 *)(D_0024F0F0 + reg_d1.h[0] * 2);
    off = reg_d3.h[0] * 2;
    reg_d2.w = reg_d0.h[0] * *(u16 *)(D_00262570 + off);
    reg_d3.w = reg_d0.h[0] * *(u16 *)(D_00262572 + off);
    reg_d2.w = (s32)reg_d2.w >> 4;
    reg_d1.h[0] &= 0xC0;
    reg_d3.w = (s32)reg_d3.w >> 4;
    switch (reg_d1.h[0]) {
        case 0x0:
            break;
        case 0x40:
            reg_d2.h[0] *= 0xFFFF;
            break;
        case 0x80:
            reg_d2.h[0] *= 0xFFFF;
            reg_d3.h[0] *= 0xFFFF;
            break;
        case 0xC0:
            reg_d3.h[0] *= 0xFFFF;
            break;
    }
}
