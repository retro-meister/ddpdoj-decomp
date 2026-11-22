#include "common.h"

s32 func_00201330();
extern u8 *reg_a6;

void func_00148860() {
    func_00201330();
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 2);
    (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d1.h[0];
    func_00201330();
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 2);
    (*(u16 *)((u8 *)(reg_a6) + (4))) += reg_d1.h[0];
}
