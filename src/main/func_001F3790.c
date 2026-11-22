#include "common.h"

extern u16 *reg_a4;

void func_001F37A0(void);

void func_001F3790(void) {
    reg_a4[1] = 0x60;
    func_001F37A0();
}
