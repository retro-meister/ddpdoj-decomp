#include "common.h"

extern u8 *work_reg_a4;
void func_001D7540(void);

void func_001D7530(void) {
    *(s16 *)(work_reg_a4 + 2) = 1;
    func_001D7540();
}
