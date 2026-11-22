#include "common.h"

extern u8 *work_reg_a4;
void func_001D7A20(void);

void func_001D7A10(void) {
    *(u16 *)(work_reg_a4 + 2) = 0;
    func_001D7A20();
}
