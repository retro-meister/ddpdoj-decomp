#include "common.h"

extern u8 *reg_a6;

extern void func_001C9750(void);

void func_001C9AF0(void) {
    *(u16 *)(reg_a6 + 2) -= 0x10;
    func_001C9750();
}
