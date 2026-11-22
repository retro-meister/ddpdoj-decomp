#include "common.h"

extern u8 *work_reg_a4;
void func_001D3A20(void);

void func_001D3A00(void) {
    work_reg_0.w = 0;
    work_reg_a4[1] = work_reg_0.b[0];
    work_reg_a4[0] = work_reg_0.b[0];
    func_001D3A20();
}
