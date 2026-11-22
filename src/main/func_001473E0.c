#include "common.h"
extern u16 D_0028E4AA;
extern u16 D_0029F182[];
extern u16 D_0029F184[];
extern u16 D_0029F282[];
void func_00147470(void);
void func_001473E0(void) {
    D_0028E4AA = D_0029F182[0];
    work_reg_0.h[0] = D_0029F184[0];
    work_reg_1.h[0] = D_0029F282[0];
    func_00147470();
}
