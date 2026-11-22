#include "common.h"

extern void func_001F4770(void);
extern u8 *work_reg_a4;

void func_001F4750(void) {
    work_reg_0.w = 0;
    work_reg_a4[1] = work_reg_0.b[0];
    work_reg_a4[0] = work_reg_0.b[0];
    func_001F4770();
}
