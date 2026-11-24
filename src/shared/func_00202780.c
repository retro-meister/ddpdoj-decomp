#include "common.h"

extern u16 *reg_a6_as_u16_p;

void func_002027A0(void);

void func_00202780(void) {
    reg_d0.h[0] = reg_a6_as_u16_p[1];
    reg_d1.h[0] = reg_a6_as_u16_p[2];
    func_002027A0();
}
