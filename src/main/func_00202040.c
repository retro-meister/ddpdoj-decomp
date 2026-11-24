#include "common.h"

extern u8 D_00262570[];
extern u8 D_00262572[];
extern u8 D_00267660[];

void func_00202040(void) {
    s32 t;

    reg_d3.h[0] = *(s16 *)(D_00267660 + reg_d1.h[0] * 2);
    t = reg_d3.h[0] * 2;
    reg_d2.w = reg_d0.h[0] * *(u16 *)(D_00262570 + t);
    reg_d3.w = reg_d0.h[0] * *(u16 *)(D_00262572 + t);
    reg_d2.w = (s32) reg_d2.w >> reg_d4.w;
    reg_d3.w = (s32) reg_d3.w >> reg_d4.w;
    reg_d1.h[0] &= 0xC0;
    switch (reg_d1.h[0]) {
    case 0x0:
        break;
    case 0x40:
        reg_d2.h[0] *= 0xFFFF;
        break;
    case 0x80:
        reg_d2.h[0] *= -1;
        reg_d3.h[0] *= 0xFFFF;
        break;
    case 0xC0:
        reg_d3.h[0] *= 0xFFFF;
        break;
    }
}
