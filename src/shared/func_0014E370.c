#include "common.h"

extern u16 *reg_a5_as_u16_p;

void func_0014E380(void);

void func_0014E370(void) {
    reg_d7.h[0] = reg_a5_as_u16_p[2];
    func_0014E380();
}
