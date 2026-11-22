#include "common.h"

extern u8 *reg_a6;

void func_001BAE40(void) {
    (*(u16 *)((u8 *)(reg_a6) + (2))) -= 0x10;
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.w = reg_d0.w;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA6)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA8)));
    reg_d1.w += reg_tmp.w;
    reg_d1.w += 0xDE000000;
    (*(u16 *)((u8 *)(reg_a6) + (0xA2))) = (u16) reg_d1.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xA4))) = (u16) reg_d1.h[0];
}
