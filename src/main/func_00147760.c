#include "common.h"

extern u16 D_0029F220[];
extern u16 D_0029F1F4[];
void func_00147780(void);

void func_00147760(void) {
    work_reg_0.h[0] = D_0029F220[0];
    work_reg_1.h[0] = D_0029F1F4[0];
    func_00147780();
}
