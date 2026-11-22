#include "common.h"

extern u8 *reg_a0;
extern u8 D_00295EA0[];

void func_00124F00(void)
{
    u8 *savedAddress = *(u8 *volatile *)&reg_a0;
    u8 *tableBase = D_00295EA0;
    u16 index = *(volatile u16 *)&reg_d0.h[0];
    u32 savedData = reg_d0.w;

    *(u8 *volatile *)&reg_a0 = tableBase;
    reg_d0.h[0] = (u32)index << 3;
    reg_a0 += reg_d0.h[0];
    *(s16 *)reg_a0 = *(s16 *)reg_a0 & ~1;
    reg_a0 = savedAddress;
    reg_d0.w = savedData;
}
