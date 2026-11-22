#include "common.h"

extern u16 *work_reg_a4;

void func_001E7130(void);

void func_001E7110(void) {
    work_reg_a4[1] = 0x2002;
    work_reg_a4[2] = 0;
    func_001E7130();
}
