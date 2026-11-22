#include "common.h"

extern void *reg_a4;

extern void func_001D38E0(void);

void func_001D38C0(void) {
    reg_d0.w = 0;
    ((u8 *)reg_a4)[1] = reg_d0.b[0];
    ((u8 *)reg_a4)[0] = reg_d0.b[0];
    func_001D38E0();
}
