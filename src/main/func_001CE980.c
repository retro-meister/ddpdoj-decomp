#include "common.h"

void func_001292C0(void);

void func_001CE980(void) {
    s32 status = reg_d1.b[0];

    if (status < 0x20 || status > 0xE0) {
        reg_d0.w += 0x80000;
    }
    func_001292C0();
}
