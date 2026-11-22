#include "common.h"

extern u8 *reg_a4;
void func_001D3A20(void);

void func_001D3A00(void) {
    reg_d0.w = 0;
    reg_a4[1] = reg_d0.b[0];
    reg_a4[0] = reg_d0.b[0];
    func_001D3A20();
}
