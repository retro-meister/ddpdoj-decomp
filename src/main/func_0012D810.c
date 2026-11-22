#include "common.h"


extern u16 D_0024EEB0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_0012D810(void) {
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    reg_a1 = (u8 *)(D_0024EEB0);
    reg_d1.h[0] = (u16) reg_d1.b[0];
    reg_d1.h[0] += 4;
    reg_d1.h[0] >>= 2;
    reg_d1.h[0] &= 0x3E;
    reg_a1 += reg_d1.h[0];
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a0 += reg_d1.h[0];
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_d0.h[0];
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x16)));
    reg_d0.w += reg_tmp.w;
    (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_d0.h[0];
}
