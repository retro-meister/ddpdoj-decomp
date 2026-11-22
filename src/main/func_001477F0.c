#include "common.h"

extern Reg32 work_reg_0;
extern Reg32 work_reg_1;
extern u16 D_0029F264[];
extern u16 D_0029F290[];
extern void func_00147830(void);

void func_001477F0(void) {
    work_reg_0.h[0] = D_0029F290[0];
    work_reg_1.h[0] = D_0029F264[0];
    func_00147830();
}
