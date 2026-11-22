#include "common.h"

extern u8 *work_reg_a4;
extern void func_001BE8F0(void);

void func_001BE8D0(void) {
    *(u8 *)(work_reg_a4 + 3) = 4;
    *(u16 *)(work_reg_a4 + 4) = 0;
    *(u16 *)(work_reg_a4 + 6) = 0;
    func_001BE8F0();
}
