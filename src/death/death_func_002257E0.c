#include "common.h"

void death_func_00225090(u8 index);
extern u16 D_002BD440[];
extern u8 *reg_a6;

void death_func_002257E0(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *) D_002BD440;
    death_func_00225090(0);
    reg_a6 = save_a6;
}
