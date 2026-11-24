#include "common.h"

extern u32 reg_a0_as_u32;

void func_0013C300(void)
{
    u32 saved_data_register = reg_d0.w;
    u32 saved_address_register = reg_a0_as_u32;
    u16 *entry;

    do {
        reg_a0_as_u32 = reg_d0.w;
        ((u16 *)reg_a0_as_u32)[0] = 0;
        ((u16 *)reg_a0_as_u32)[2] = 0;
        entry = (u16 *)reg_a0_as_u32;
        reg_d0.h[1] = entry[0x16];
        reg_d0.h[0] = entry[0x17];
    } while (reg_d0.w != 0);

    reg_a0_as_u32 = saved_address_register;
    reg_d0.w = saved_data_register;
}
