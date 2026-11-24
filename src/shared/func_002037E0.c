#include "common.h"

extern s8 D_0028E408;
extern Reg32 D_0028E484;
extern void func_002037B0(void);

void func_002037E0(void) {
    Reg32 *temporaryRegister = &reg_tmp;
    Reg32 *dataRegister6 = &reg_d6;
    u32 originalD6;
    u32 adjustment;

    temporaryRegister->w = 0;
    temporaryRegister->h[0] = 0x2400;
    D_0028E484.w = 0;
    originalD6 = dataRegister6->h[0];
    adjustment = temporaryRegister->w;
    D_0028E484.h[0] = originalD6;
    D_0028E484.w -= adjustment;
    dataRegister6->h[0] = originalD6 - 0x2400;

    if (D_0028E484.h[1] != 0) {
        D_0028E408 = 1;
        return;
    }

    func_002037B0();
    reg_d0.w = -1;
    D_0028E408 = 1;
}
