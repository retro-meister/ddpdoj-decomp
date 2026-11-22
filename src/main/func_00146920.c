#include "common.h"

extern u16 D_0029F1F4[];
extern u16 D_0029F220[];
extern void func_00146940(void);

void func_00146920(void) {
    work_reg_0.h[0] = D_0029F220[0];
    work_reg_1.h[0] = D_0029F1F4[0];
    func_00146940();
}
