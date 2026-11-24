#include "common.h"

s32 func_001AE9A0(Reg32 *, Reg32 *);
extern u8 D_0026C020[];
extern u8 *reg_a2;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_001AAC00(void) {
    u8 *a5 = reg_a5;

    reg_d0.h[0] = *(u16 *) reg_a4;
    reg_a5 = (u8 *)D_0026C020;
    reg_d1.w = *(u32 *) (reg_a5 + reg_d0.h[0]);
    if (reg_d1.w != -1U) goto next_1;
    *(u32 *) reg_a2 = -1U;
    goto block_end;
next_1:
    if (!(reg_d1.w & 0x80000000)) goto next_2;
    reg_d1.w &= 0x7FFFFFFF;
    goto next_3;
next_2:
    *(u16 *) reg_a4 = 0xC;
next_3:
    reg_d2.w = *(u32 *) reg_a2;
    reg_d0.h[0] = 0;
    func_001AE9A0(&reg_d1, &reg_d2);
    *(u32 *) reg_a2 = reg_d2.w;
block_end:
    reg_a5 = a5;
}
