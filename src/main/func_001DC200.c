#include "common.h"

void func_001DC160();
extern u8 D_0026EE30[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001DC200(void) {
    reg_a0 = D_0026EE30;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x106)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    reg_d1.w += 0xFC000000;
    reg_d1.w += 0xE600EA00;
    reg_d3.h[0] = 0x1AB0;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x3C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x147)));
    func_001DC160();
}
