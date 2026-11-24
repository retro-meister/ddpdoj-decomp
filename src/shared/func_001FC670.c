#include "common.h"

void func_0019C570(void);
extern u8 D_00265FA0[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001FC670(void) {
    if ((*(u8 *)(reg_a5 + 0x1D)) & 1) {
        reg_a0 = D_00265FA0;
        reg_a0 += *(u16 *)(reg_a5 + 0x1E);
        reg_d2.h[1] = *(u16 *)(reg_a0 + 0);
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        reg_d1.w += 0xFE00FC00;
        reg_d3.h[0] = 0x220;
        reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
        func_0019C570();
    }
}
