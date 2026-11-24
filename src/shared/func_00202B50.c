#include "common.h"

extern u16 *reg_a6;
void func_00202B70(void);

void func_00202B50(void) {
    reg_d0.h[0] = reg_a6[1];
    reg_d1.h[0] = reg_a6[2];
    func_00202B70();
}
