#include "common.h"

extern u16 *D_0028E450;

void func_002027A0(void);

void func_00202780(void) {
    work_reg_0.h[0] = D_0028E450[1];
    work_reg_1.h[0] = D_0028E450[2];
    func_002027A0();
}
