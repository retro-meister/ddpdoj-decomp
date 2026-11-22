#include "common.h"

extern u8 *work_reg_a4;

void func_001E71D0(void);

void func_001E71B0(void) {
    *(u16 *)(work_reg_a4 + 2) = 0;
    *(u16 *)(work_reg_a4 + 4) = 4;
    *(u8 *)(work_reg_a4 + 7) = 0;
    func_001E71D0();
}
