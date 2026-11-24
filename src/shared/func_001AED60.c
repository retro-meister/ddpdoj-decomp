#include "common.h"

extern void func_001AED90(void);
extern u8 *reg_a0;
extern u16 D_0028E748;
extern u32 D_0028E764;
extern u8 D_002BAFAA[];

void func_001AED60(void) {
    reg_a0 = D_002BAFAA;
    reg_d0.w = D_0028E764;
    reg_d6.h[0] = D_0028E748;
    reg_d4.w = reg_d0.w;
    func_001AED90();
}
