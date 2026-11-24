#include "common.h"

s32 func_00147050(u16);
extern u16 D_0028E4AA;
extern u8 D_0029F110[];
extern u16 D_0029F112[];
extern u16 D_0029F114[];
extern u16 D_0029F248[];
extern void func_0018D7D0();
extern void func_0018D7F0();
extern u8 *reg_a3;
extern u8 *reg_a4;

void func_00146FC0(void) {
    reg_a4 = D_0029F110;
    reg_a3 = (void *)func_0018D7D0;
    D_0028E4AA = D_0029F112[0];
    reg_d0.h[0] = D_0029F114[0];
    if (D_0029F248[0] != 0) {
        reg_a3 = (void *)func_0018D7F0;
    }
    func_00147050(D_0029F112[0]);
}
