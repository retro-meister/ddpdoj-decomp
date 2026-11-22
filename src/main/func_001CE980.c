#include "common.h"

void func_001292C0(void);

void func_001CE980(void) {
    s32 status = work_reg_1.b[0];

    if (status < 0x20 || status > 0xE0) {
        work_reg_0.w += 0x80000;
    }
    func_001292C0();
}
