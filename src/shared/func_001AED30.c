#include "common.h"

extern Reg32 reg_d0;
extern u16 D_0028E750;
extern u32 D_0028E768;
extern u32 *reg_a0_as_u32_p;
extern u8 D_002BAF50_as_u8_a[];

void func_001AED90(void);

void func_001AED30(void) {
    reg_a0_as_u32_p = (u32 *)D_002BAF50_as_u8_a;
    reg_d0.w = D_0028E768;
    reg_d6.h[0] = D_0028E750;
    reg_d4.w = reg_d0.w;
    func_001AED90();
}
