#include "common.h"

extern void func_002032F0(void);

extern s8 D_0028E408;
extern u32 D_0028E448_as_u32;
extern u8 D_0029F1F0_as_u8_a[];
extern u8 D_0029F260_as_u8_a[];
extern u32 reg_a0_as_u32;
extern u32 reg_a1_as_u32;
extern u32 reg_a5_as_u32;

void func_002032A0(void)
{
    reg_a0_as_u32 = (u32)D_0029F260_as_u8_a;
    D_0028E408 = 0;
    reg_a1_as_u32 = (u32)D_0029F1F0_as_u8_a;

    if (((u8 *)reg_a5_as_u32)[2] != 0) {
        D_0028E448_as_u32 = reg_a1_as_u32;
        reg_a1_as_u32 = reg_a0_as_u32;
        reg_a0_as_u32 = D_0028E448_as_u32;
    }

    func_002032F0();
}
