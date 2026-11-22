#include "common.h"

extern u8 *work_reg_a4;
void func_001CE4C0(void);

void func_001CE4B0(void) {
    *(u16 *)(work_reg_a4 + 2) = 1;
    func_001CE4C0();
}
