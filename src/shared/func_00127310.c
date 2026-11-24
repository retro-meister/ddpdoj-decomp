#include "common.h"

s32 func_001273D0();
s32 func_002011A0();
extern u16 D_002695D0[];
extern Reg32 D_0028E484;
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_00127310(void) {
    u8 *sa1;

    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d7.w = reg_d1.w;
    reg_d0.h[0] = reg_tmp.h[1];
    *(u16 *)(reg_a0 + 0x1A) = 0x420;
    func_002011A0();
    reg_d0.h[0] &= 0xE;
    sa1 = reg_a1;
    reg_d1.w = 0;
    reg_a1 = (u8 *)D_002695D0;
    reg_a1 += reg_d0.h[0];
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a1 = sa1;
    D_0028E484.h[1] = *(u16 *)(reg_a0 + 0xA);
    D_0028E484.h[0] = *(u16 *)(reg_a0 + 0xC);
    D_0028E484.w += reg_d1.w;
    *(u16 *)(reg_a0 + 0xA) = D_0028E484.h[1];
    *(u16 *)(reg_a0 + 0xC) = D_0028E484.h[0];
    func_001273D0();
}
