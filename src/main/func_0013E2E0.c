#include "common.h"

extern u16 D_0029CD80[];
extern u32 D_0029CD84[];
extern u32 D_0029CD88[];
extern u16 D_0029CD8C[];
extern u16 D_0029CD8E[];

extern void func_00200EE0(void);

void func_0013E2E0(void) {
    reg_d0.h[0] = D_0029CD80[0];
    reg_d5.h[0] = reg_d0.h[0];
    func_00200EE0();

    D_0029CD84[0] = reg_d2.w;
    reg_d5.h[0] >>= 1;
    reg_d0.h[0] = reg_d5.h[0];
    func_00200EE0();

    D_0029CD88[0] = reg_d2.w;
    reg_d0.h[0] = D_0029CD8C[0];
    func_00200EE0();

    D_0029CD8E[0] = reg_d2.h[0];
}
