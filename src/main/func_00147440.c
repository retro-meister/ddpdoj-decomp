#include "common.h"

void func_00147470(u16);

extern u16 D_0028E4AA;
extern u16 D_0029F112[];
extern u16 D_0029F114[];
extern u16 D_0029F212[];

void func_00147440(void) {
    u16 reg_value = D_0029F112[0];

    D_0028E4AA = reg_value;
    reg_d0.h[0] = D_0029F114[0];
    reg_d1.h[0] = D_0029F212[0];
    func_00147470(reg_value);
}
