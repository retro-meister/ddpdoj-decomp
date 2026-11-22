#include "common.h"

extern s32 D_002680E0[];
extern void *reg_a0;
extern void func_00209200(void);

void func_00208D30(void) {
    reg_d0.h[0] = 0;
    reg_a0 = D_002680E0;
    func_00209200();
}
