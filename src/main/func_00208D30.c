#include "common.h"

extern s32 D_002680E0[];
extern void *D_0028E468;
extern void func_00209200(void);

void func_00208D30(void) {
    work_reg_0.h[0] = 0;
    D_0028E468 = D_002680E0;
    func_00209200();
}
