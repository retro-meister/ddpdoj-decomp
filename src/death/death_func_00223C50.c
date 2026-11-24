#include "common.h"

void death_func_002237F0(u8 phase);
void death_func_00223C90(void);
s32 func_00124D90();
extern u8 death_D_0029085C;
extern u8 *reg_a4;

void death_func_00223C50(void) {
    *(u16 *)(reg_a4 + 2) = 0x60;
    death_func_002237F0(4);
    reg_d0.w = 0x10;
    func_00124D90();
    death_func_00223C90();
}
