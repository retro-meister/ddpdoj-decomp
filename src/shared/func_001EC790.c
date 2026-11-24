#include "common.h"

extern void func_00129450(void);
extern u8 *reg_a6;

void func_001EC790(void) {
    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d3.w = 0xFA000000;
    reg_d6.h[0] = 5;
    reg_d7.h[0] = 0xF;
    reg_d4.w = 0;
    do {
        func_00129450();
        reg_d1.b[0] += reg_d6.b[0];
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
