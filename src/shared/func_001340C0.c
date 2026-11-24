#include "common.h"

extern u16 D_0025F9B0[];
extern u16 *reg_a0_as_u16_p;

void func_001340E0(void);

void func_001340C0(void) {
    reg_a0_as_u16_p = D_0025F9B0;
    func_001340E0();
}
