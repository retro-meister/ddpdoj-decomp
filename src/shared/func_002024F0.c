#include "common.h"

extern u8 *reg_a6;
void func_00202500(void);

void func_002024F0(void) {
    *(u8 *)&reg_d0 = reg_a6[0x1A];
    func_00202500();
}
