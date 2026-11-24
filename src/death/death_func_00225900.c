#include "common.h"

void death_func_002251D0(u8 index);
extern u16 D_002BD440[];
extern u8 *reg_a6;

void death_func_00225900(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *) D_002BD440;
    death_func_002251D0(0);
    reg_a6 = save_a6;
}
