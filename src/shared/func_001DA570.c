#include "common.h"

extern u8 *reg_a4;

void func_001DA580(void);

void func_001DA570(void) {
    *(u16 *)(reg_a4 + 6) = 0;
    func_001DA580();
}
