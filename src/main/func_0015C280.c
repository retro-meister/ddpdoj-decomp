#include "common.h"

extern Reg32 reg_d1;
void func_0019C430(void);

void func_0015C280(void) {
    reg_d1.w = 0x1A000800;
    reg_d2.sw = 0x155A;
    reg_d3.sh[0] = 0x20A0;
    reg_d4.sh[0] = 1;
    func_0019C430();
}
