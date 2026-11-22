#include "common.h"

extern u16 *D_0028E450;
extern void func_002021F0(void);

void func_002021D0(void) {
    work_reg_0.h[0] = D_0028E450[1];
    work_reg_1.h[0] = D_0028E450[2];
    func_002021F0();
}
