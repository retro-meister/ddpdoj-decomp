#include "common.h"

extern u16 D_0029F290[];
extern u16 D_0029F264[];

void func_00146940(void);

void func_001468F0(void) {
    work_reg_0.h[0] = D_0029F290[0];
    work_reg_1.h[0] = D_0029F264[0];
    func_00146940();
}
