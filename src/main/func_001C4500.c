#include "common.h"

void func_0019C670();
extern u8 D_0026C4F0[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001C4500(void) {
    reg_d0.w = 0;
    reg_a0 = D_0026C4F0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x11A)));
    reg_d0.b[0] += 1;
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d2.w = *(u32 *)(D_0026C4F0 + (reg_d0.h[0] & ~3));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x102)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x104)));
    reg_d1.w += 0xFC00FD00;
    reg_d3.h[0] = 0x418;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x12E)));
    func_0019C670();
}
