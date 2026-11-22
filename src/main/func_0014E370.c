#include "common.h"

extern u16 *reg_a5;
extern u16 reg_d7;

void func_0014E380(void);

void func_0014E370(void) {
    reg_d7 = reg_a5[2];
    func_0014E380();
}
