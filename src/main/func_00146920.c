#include "common.h"

extern u16 D_0029F1F4[];
extern u16 D_0029F220[];
extern void func_00146940(void);

void func_00146920(void) {
    reg_d0.h[0] = D_0029F220[0];
    reg_d1.h[0] = D_0029F1F4[0];
    func_00146940();
}
