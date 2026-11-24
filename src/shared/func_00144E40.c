#include "common.h"

s32 func_00145A80(u16);                         /* extern */
extern u16 D_0029F260_as_u16_a[];
extern u16 *reg_a6_as_u16_p;

void func_00144E40(void) {
    reg_a6_as_u16_p = D_0029F260_as_u16_a;
    reg_d0.h[0] = *reg_a6_as_u16_p;
    if ((((s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30) >= 0) && (reg_d0.h[0] & 0xFFFF & 0x100)) {
        func_00145A80(reg_d0.h[0]);
    }
}
