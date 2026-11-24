#include "common.h"

extern u16 D_0028E4AA;
extern u16 D_0029F262[];
extern u16 D_0029F264[];

void func_00147250(void);

void func_001471E0(void) {
    D_0028E4AA = D_0029F262[0];
    *(u16 *)&reg_d0 = D_0029F264[0];
    func_00147250();
}
