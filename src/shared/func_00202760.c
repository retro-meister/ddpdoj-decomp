#include "common.h"

extern u16 *reg_a0_as_u16_p;

void func_00202780(void);

void func_00202760(void) {
    reg_d2.h[0] = reg_a0_as_u16_p[1];
    reg_d3.h[0] = reg_a0_as_u16_p[2];
    func_00202780();
}
