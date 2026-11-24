#include "common.h"

void death_func_0021D4B0(void);
void death_func_0021BFC0(void);
extern u8 death_D_006901D0[];
extern u8 *reg_a6;

void death_func_0021D6C0(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901D0;
    death_func_0021D4B0();
    death_func_0021BFC0();
    reg_a6 = save_a6;
}
