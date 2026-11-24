#include "common.h"
extern u16 *reg_a0_as_u16_p;
extern u8 D_0029F260_as_u8_a[];
void func_001278D0(void);
void func_001278A0(void) {
    reg_tmp.w = (u32)D_0029F260_as_u8_a;
    reg_a0_as_u16_p[18] = reg_tmp.h[1];
    reg_a0_as_u16_p[19] = reg_tmp.h[0];
    func_001278D0();
}
