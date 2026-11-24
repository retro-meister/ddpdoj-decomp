#include "common.h"

extern u16 *reg_a4_as_u16_p;
extern void func_001F3240(void);

void func_001F3230(void) {
    reg_a4_as_u16_p[1] = 1;
    func_001F3240();
}
