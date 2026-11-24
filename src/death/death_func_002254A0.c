#include "common.h"

s32 func_00201160();
void death_func_00225500(u8 index);
extern u8 *reg_a4;
extern u8 *reg_a6;

void death_func_002254A0(u8 index) {
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 1) = reg_d0.b[0];
    *(u8 *)(reg_a4 + 0) = reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x1B) = 4;
    func_00201160();
    *(u8 *)(reg_a6 + 0x1A) = reg_d0.b[0];
    death_func_00225500(index);
}
