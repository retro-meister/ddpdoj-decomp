#include "common.h"

extern u8 D_0028E855;
extern u8 D_0029F29F[];

void func_0013EA00(void) {
    work_reg_0.b[0] = 0x50;
    if (D_0028E855 & 4) {
        work_reg_0.b[0] = 0x78;
    }
    D_0029F29F[0] = work_reg_0.b[0];
}
