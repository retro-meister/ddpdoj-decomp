#include "common.h"

extern u16 *reg_a6_as_u16_p;
extern void func_002021F0(void);

void func_002021D0(void) {
    reg_d0.h[0] = reg_a6_as_u16_p[1];
    reg_d1.h[0] = reg_a6_as_u16_p[2];
    func_002021F0();
}
