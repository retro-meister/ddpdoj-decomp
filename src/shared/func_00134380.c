#include "common.h"


typedef void (*Fn)();

extern u8 D_00269B70[];
extern u16 D_002BF3E0[];
extern u8 *reg_a4;

void func_00134380(u16 *arg0) {
    u16 *var_a0;
    u16 temp_v1_2;

    var_a0 = (u16 *)(arg0);
    reg_a4 = (u8 *)(D_002BF3E0);
    reg_d7.w = 1;
    do {
        temp_v1_2 = *(u16 *)reg_a4;
        reg_d0.h[0] = temp_v1_2;
        if (temp_v1_2 != 0) {
            ((Fn)*(u32 *)((u8 *)D_00269B70 + (reg_d0.h[0] * 4)))();
        }
        var_a0 = (u16 *)(reg_a4 + 0x16);
        reg_a4 = (u8 *)(var_a0);
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
