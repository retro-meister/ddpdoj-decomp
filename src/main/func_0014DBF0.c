#include "common.h"


s32 func_00203400();
extern u8 D_002BC7C0[];
extern u8 *reg_a0;

void func_0014DBF0(u8 *arg1) {
    u8 *var_a1;
    u8 temp_a0;

    var_a1 = (u8 *)(arg1);
    reg_a0 = D_002BC7C0;
    reg_d3.w = 0x63;
    do {
        temp_a0 = (*(u8 *)((u8 *)(reg_a0) + (1)));
        if (temp_a0 & 0x20) {
            func_00203400();
            var_a1 = (u8 *)(reg_a0);
            (*(u8 *)((u8 *)(var_a1) + (1))) |= reg_d0.b[0];
            goto block_4;
        }
        if (temp_a0 & 0x40) {
block_4:
            (*(u16 *)((u8 *)(reg_a0) + (0x18))) = 0xFFFF;
        }
        reg_a0 += 0x20;
    } while ((s16)(--reg_d3.h[0]) >= 0);
}
