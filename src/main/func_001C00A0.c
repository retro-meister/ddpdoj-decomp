#include "common.h"

extern u16 *work_reg_a4;
void func_001C00C0(void);

void func_001C00A0(void) {
    work_reg_a4[1] = 4;
    work_reg_a4[2] = 0;
    work_reg_a4[3] = 4;
    func_001C00C0();
}
