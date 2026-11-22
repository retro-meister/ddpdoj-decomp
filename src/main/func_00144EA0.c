#include "common.h"

s32 func_00145A80(u16);                         /* extern */
extern u16 D_0029F1F0[];
extern u16 *reg_a6;

void func_00144EA0(void) {
    reg_a6 = D_0029F1F0;
    reg_d0.h[0] = *reg_a6;
    if ((((s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30) >= 0) && (reg_d0.h[0] & 0xFFFF & 0x100)) {
        func_00145A80(reg_d0.h[0]);
    }
}
