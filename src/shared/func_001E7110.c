#include "common.h"

extern u16 *reg_a4_as_u16_p;

void func_001E7130(void);

void func_001E7110(void) {
    reg_a4_as_u16_p[1] = 0x2002;
    reg_a4_as_u16_p[2] = 0;
    func_001E7130();
}
