#include "common.h"

extern void func_001F4770(void);
extern u8 *reg_a4;

void func_001F4750(void) {
    reg_d0.w = 0;
    reg_a4[1] = reg_d0.b[0];
    reg_a4[0] = reg_d0.b[0];
    func_001F4770();
}
