#include "common.h"

extern void func_00130DE0(void);

void func_00130DB0(void) {
    reg_d0.h[0] = 3;
    reg_d1.h[0] = 3;
    func_00130DE0();
}
