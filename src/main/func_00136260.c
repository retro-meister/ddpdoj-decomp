#include "common.h"

s32 func_00207490();
extern u8 D_002BF390[];
extern u8 D_002BF3B4[];
extern u8 *reg_a0;
extern u8 *reg_a2;
extern u8 *reg_a3;

void func_00136260(void) {
    reg_a2 = D_002BF390;
    reg_a3 = D_002BF3B4;
    reg_a0 = reg_a2 + 0x18;
    func_00207490();
    reg_a0 = reg_a3 + 0x18;
    func_00207490();
    reg_a0 = reg_a2 + 0x1C;
    func_00207490();
    reg_a0 = reg_a3 + 0x1C;
    func_00207490();
    reg_a0 = reg_a2 + 0x20;
    func_00207490();
    reg_a0 = reg_a3 + 0x20;
    func_00207490();
}
