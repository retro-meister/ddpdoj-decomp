#include "common.h"

extern void func_002032F0(void);

extern s8 D_0028E408;
extern u32 D_0028E448;
extern u8 D_0029F1F0[];
extern u8 D_0029F260[];
extern u32 reg_a0;
extern u32 reg_a1;
extern u32 reg_a5;

void func_002032A0(void)
{
    reg_a0 = (u32)D_0029F260;
    D_0028E408 = 0;
    reg_a1 = (u32)D_0029F1F0;

    if (((u8 *)reg_a5)[2] != 0) {
        D_0028E448 = reg_a1;
        reg_a1 = reg_a0;
        reg_a0 = D_0028E448;
    }

    func_002032F0();
}
