#include "common.h"

extern void func_00130DE0(void);

void func_00130DC0(void) {
    reg_d0.h[0] = 0x11;
    reg_d1.h[0] = 0x3;
    func_00130DE0();
}
