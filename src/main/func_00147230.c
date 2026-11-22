#include "common.h"

extern u16 D_0028E4AA;
extern u16 D_0029F1F2[];
extern u16 D_0029F1F4[];

void func_00147250(void);

void func_00147230(void) {
    D_0028E4AA = D_0029F1F2[0];
    *(u16 *)&work_reg_0 = D_0029F1F4[0];
    func_00147250();
}
