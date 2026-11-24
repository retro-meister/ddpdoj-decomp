#include "common.h"

extern u16 *reg_a4_as_u16_p;

void func_001F37A0(void);

void func_001F3790(void) {
    reg_a4_as_u16_p[1] = 0x60;
    func_001F37A0();
}
