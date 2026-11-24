#include "common.h"

void death_func_00224EF0(u8 index);
extern u16 D_0029C06C[];
extern u8 death_D_006901B0[];
extern u8 *reg_a4;
extern u8 *reg_a6;

void death_func_002256C0(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = death_D_006901B0;
    reg_a4 += 0x10;
    *(u16 *)(reg_a6 + 4) -= D_0029C06C[0];
    death_func_00224EF0(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}
