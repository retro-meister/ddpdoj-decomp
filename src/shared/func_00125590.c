#include "common.h"

extern u16 D_0028E3EC;
extern u16 D_0028E988;
extern void func_0019D290(u16);

void func_00125590(u16 arg0) {
    if (D_0028E988 >= 0x34) {
        reg_d0.w = 1;
        reg_d0.h[0] &= reg_d7.h[0];
        arg0 = D_0028E3EC;
        if (arg0 == reg_d0.h[0]) {
            return;
        }
    }
    func_0019D290(arg0);
}
