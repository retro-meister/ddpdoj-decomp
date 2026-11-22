#include "common.h"

void func_0014D220();
void func_0019C470();
extern u8 D_00265220[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F7100(void) {
    reg_a0 = reg_a6;
    func_0014D220();
    reg_a0 = D_00265220;
    reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.w += 0xF600F600;
    reg_d4.w = 0;
    reg_d3.h[0] = 0xA50;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    func_0019C470();
}
