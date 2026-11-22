#include "common.h"

extern u16 *D_0028E450;
void func_00202B70(void);

void func_00202B50(void) {
    work_reg_0.h[0] = D_0028E450[1];
    work_reg_1.h[0] = D_0028E450[2];
    func_00202B70();
}
