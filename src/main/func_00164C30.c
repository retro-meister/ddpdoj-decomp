#include "common.h"

extern u16 *reg_a5;
extern u16 *reg_a6;
extern void func_00170BE0(void);

void func_00164C30(void) {
    reg_d1.h[1] = reg_a6[1];
    reg_d1.h[0] = reg_a6[2];
    reg_d1.h[0] += 0xFB00;
    reg_d1.h[1] += 0xFC00;
    reg_d1.h[1] += reg_a5[0x16];
    reg_d2.h[1] = reg_a5[0x10];
    reg_d2.h[0] = reg_a5[0x11];
    reg_d3.h[0] = 0x428;
    reg_d4.h[0] = 0xD;
    func_00170BE0();
}
