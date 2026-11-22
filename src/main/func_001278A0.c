#include "common.h"
extern u16 *reg_a0;
extern u8 D_0029F260[];
void func_001278D0(void);
void func_001278A0(void) {
    reg_tmp.w = (u32)D_0029F260;
    reg_a0[18] = reg_tmp.h[1];
    reg_a0[19] = reg_tmp.h[0];
    func_001278D0();
}
