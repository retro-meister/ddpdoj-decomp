#include "common.h"

extern u16 *reg_a4;
extern void func_001F3240(void);

void func_001F3230(void) {
    reg_a4[1] = 1;
    func_001F3240();
}
