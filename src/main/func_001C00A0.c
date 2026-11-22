#include "common.h"

extern u16 *reg_a4;
void func_001C00C0(void);

void func_001C00A0(void) {
    reg_a4[1] = 4;
    reg_a4[2] = 0;
    reg_a4[3] = 4;
    func_001C00C0();
}
