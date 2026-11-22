#include "common.h"

extern u16 reg_d2;
void func_0012DA10(void);

void func_0012D9F0(void) {
    reg_d2 = (u16)((reg_d2 << 16) - reg_d2);
    func_0012DA10();
}
