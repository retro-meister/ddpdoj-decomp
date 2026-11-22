#include "common.h"

extern u8 *reg_a4;
void func_001E75C0(void);

void func_001E75A0(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    *(u16 *)(reg_a4 + 4) = 0;
    func_001E75C0();
}
