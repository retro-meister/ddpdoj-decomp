#include "common.h"

extern u8 *D_0028E450;
void func_00202500(void);

void func_002024F0(void) {
    *(u8 *)&work_reg_0 = D_0028E450[0x1A];
    func_00202500();
}
