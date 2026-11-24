#include "common.h"

void death_func_00224F20(u8 index);
extern u16 D_002BD440[];
extern u8 *reg_a6;

void death_func_00225680(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *) D_002BD440;
    death_func_00224F20(0);
    reg_a6 = save_a6;
}
