#include "common.h"

extern u8 *reg_a4;

void func_001C3080(void);

void func_001C3070(void) {
    reg_a4[3] = 0;
    func_001C3080();
}
