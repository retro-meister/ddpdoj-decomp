#include "common.h"

void func_001DC160(void);
extern u8 D_0026EEF0[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001DC490(void) {
    reg_a0 = D_0026EEF0;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0xC6);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    reg_d2.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = *(u16 *)(reg_a6 + 0xC2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0xC4);
    reg_d1.w += 0xF800FA00;
    reg_d3.h[0] = 0x830;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0xDC);
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x148);
    func_001DC160();
}
