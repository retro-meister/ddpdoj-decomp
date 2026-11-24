#include "common.h"

s32 func_00147050(u16);
extern u16 D_0028E4AA;
extern u8 D_0029F180[];
extern u16 D_0029F182[];
extern u16 D_0029F184[];
extern u16 D_0029F2B8[];
extern void func_0018D750();
extern void func_0018D770();
extern u8 *reg_a3;
extern u8 *reg_a4;

void func_00146F10(void) {
    reg_a4 = D_0029F180;
    reg_a3 = (void *)func_0018D750;
    D_0028E4AA = D_0029F182[0];
    reg_d0.h[0] = D_0029F184[0];
    if (D_0029F2B8[0] == 0) {
        func_00147050(D_0029F182[0]);
        return;
    }
    reg_a3 = (void *)func_0018D770;
    func_00147050(D_0029F182[0]);
}
