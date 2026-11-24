#include "common.h"

extern void func_00129320(void);

void func_001D6160(void)
{
    reg_d1.b[0] *= 4;
    reg_d0.w = 0x80003;
    reg_d4.w = 0;
    reg_d1.b[0] -= 2;
    func_00129320();
    reg_d1.b[0] += 4;
    func_00129320();
}
