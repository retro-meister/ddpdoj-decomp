#include "common.h"

extern u8 *reg_a4;
void func_001D76F0(void);

void func_001D76E0(void) {
    *(u16 *)(reg_a4 + 2) = 1;
    func_001D76F0();
}
