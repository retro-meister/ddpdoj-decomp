#include "common.h"

s32 func_00201E20();
extern u8 *reg_a6;

void func_00201F70(void) {
    func_00201E20();
    (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (4))) += reg_d3.h[0];
}
