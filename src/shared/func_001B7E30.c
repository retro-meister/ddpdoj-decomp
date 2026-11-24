#include "common.h"

extern u32 D_0026E530[];
extern u16 *reg_a2;
extern u16 *reg_a6;
extern void func_0019C6D0(void);

void func_001B7E30(void) {
    reg_a2 = (u16 *)D_0026E530;
    reg_d2.h[1] = reg_a2[0];
    reg_d2.h[0] = reg_a2[1];
    reg_d1.h[1] = reg_a6[1];
    reg_d1.h[0] = reg_a6[2];
    reg_d1.w += 0xFC00FC00U;
    reg_d1.w += 0xF2000000U;
    reg_d3.h[0] = 0x420;
    reg_d4.h[0] = 0x15;
    func_0019C6D0();
}
