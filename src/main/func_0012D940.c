#include "common.h"

extern void func_0012D960(void);

void func_0012D940(void) {
    u16 value = reg_d2.h[0];
    s32 diff = (value << 16) - value;
    reg_d2.h[0] = diff;
    func_0012D960();
}
