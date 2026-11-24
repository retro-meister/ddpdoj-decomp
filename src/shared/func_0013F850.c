#include "common.h"

s32 func_0013F8A0();
extern u32 D_0028E428;
extern u8 *D_0028E43C;
extern u8 *D_0028E440;
extern u8 *D_0028E444;
extern u8 D_0029CDA0[];
extern u8 D_0029CE20[];
extern u8 D_0029F1F0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;

void func_0013F850(void) {
    u8 *temp_a1;
    u8 *temp_a2;
    u8 *temp_a3;

    temp_a3 = reg_a0;
    temp_a2 = reg_a1;
    temp_a1 = reg_a2;
    D_0028E428 = reg_d0.w;
    D_0028E444 = temp_a3;
    D_0028E440 = temp_a2;
    D_0028E43C = temp_a1;
    reg_a0 = D_0029CE20;
    reg_a1 = D_0029CDA0;
    reg_a2 = D_0029F1F0;
    func_0013F8A0();
}
