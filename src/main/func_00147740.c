#include "common.h"

extern u16 D_0029F290[];
extern u16 D_0029F264[];

void func_00147780(void);

void func_00147740(void) {
    reg_d0.h[0] = D_0029F290[0];
    reg_d1.h[0] = D_0029F264[0];
    func_00147780();
}
