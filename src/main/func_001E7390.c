#include "common.h"

extern u8 *work_reg_a4;
extern void func_001E73A0(void);

void func_001E7390(void) {
    *(u16 *)(work_reg_a4 + 2) = 1;
    func_001E73A0();
}
