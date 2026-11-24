#include "common.h"

extern u16 *reg_a5_as_u16_p;
extern u16 *reg_a6_as_u16_p;
extern void func_00170BE0(void);

void func_00164C30(void) {
    reg_d1.h[1] = reg_a6_as_u16_p[1];
    reg_d1.h[0] = reg_a6_as_u16_p[2];
    reg_d1.h[0] += 0xFB00;
    reg_d1.h[1] += 0xFC00;
    reg_d1.h[1] += reg_a5_as_u16_p[0x16];
    reg_d2.h[1] = reg_a5_as_u16_p[0x10];
    reg_d2.h[0] = reg_a5_as_u16_p[0x11];
    reg_d3.h[0] = 0x428;
    reg_d4.h[0] = 0xD;
    func_00170BE0();
}
