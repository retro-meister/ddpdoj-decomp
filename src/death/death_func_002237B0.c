#include "common.h"

void death_func_002237F0(u8 phase);
void death_func_00223870(void);
s32 func_00124D90();
extern u8 death_D_0029085C;
extern u8 *reg_a4;

void death_func_002237B0(void) {
    death_D_0029085C = 2;
    death_func_002237F0(0);
    *(u16 *)(reg_a4 + 2) = 0x60;
    death_func_00223870();
}
