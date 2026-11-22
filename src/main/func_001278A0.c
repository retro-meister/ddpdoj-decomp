#include "common.h"
extern u16 *D_0028E468;
extern u8 D_0029F260[];
void func_001278D0(void);
void func_001278A0(void) {
    work_reg_tmp.w = (u32)D_0029F260;
    D_0028E468[18] = work_reg_tmp.h[1];
    D_0028E468[19] = work_reg_tmp.h[0];
    func_001278D0();
}
