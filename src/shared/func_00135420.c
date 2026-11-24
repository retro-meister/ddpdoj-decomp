#include "common.h"


typedef void (*Fn)();

extern u8 D_00269D30[];
extern u16 D_002BF390_as_u16_a[];
extern u8 *reg_a6;

void func_00135420(u16 *arg0) {
    u16 *var_a0;
    u32 temp_s0;

    var_a0 = (u16 *)(arg0);
    reg_a6 = (u8 *)(D_002BF390_as_u16_a);
    reg_d7.w = 1;
    do {
        reg_d0.h[0] = *(u16 *)reg_a6;
        if (reg_d0.h[0] != 0) {
            temp_s0 = reg_d7.w;
            ((Fn)*(u32 *)((u8 *)D_00269D30 + ((reg_d0.h[0] & 0xFFFF) * 4)))();
            reg_d7.w = temp_s0;
        }
        var_a0 = (u16 *)(reg_a6 + 0x24);
        reg_a6 = (u8 *)(var_a0);
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
