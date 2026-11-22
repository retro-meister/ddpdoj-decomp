#include "common.h"

extern void *work_reg_a4;

extern void func_001D38E0(void);

void func_001D38C0(void) {
    work_reg_0.w = 0;
    ((u8 *)work_reg_a4)[1] = work_reg_0.b[0];
    ((u8 *)work_reg_a4)[0] = work_reg_0.b[0];
    func_001D38E0();
}
