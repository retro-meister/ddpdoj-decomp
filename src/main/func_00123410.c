#include "common.h"

extern s8 D_0028E408;

s32 func_00123380();
s32 func_00123540();
extern u32 D_0024CBE0[];
extern u16 D_00295E1C[];
extern u8 D_00295E1E[];
extern u8 D_00295E1F[];
extern u32 D_00295E28[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;

void func_00123410(void) {
    reg_a2 = reg_a0;
    reg_a2 += D_00295E1C[0];
    reg_d0.h[0] = *(u16 *) reg_a2;
    reg_a2 += 2;
    if (0 > (s16) reg_d0.h[0]) {
        func_00123540();
        return;
    }
    D_00295E1F[0] -= 1;
    if (0 > (s8) D_00295E1F[0]) goto next_1;
    D_0028E408 = 1;
    return;
next_1:
    D_00295E1F[0] = D_00295E1E[0];
    reg_a1 = (u8 *) D_0024CBE0;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 += reg_d0.h[0];
    reg_d0.w = *(u32 *) reg_a1;
    reg_d1.w = D_00295E28[0];
    func_00123380();
    D_0028E408 = 1;
    ((u16 *) D_00295E28)[0] += 0x400;
    D_00295E1C[0] += 2;
}
