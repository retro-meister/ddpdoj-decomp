#include "common.h"

s32 func_00147F30();
s32 func_00147F90();
extern u8 *reg_a6;

void func_00147780() {
    reg_d0.h[0] += 0x800;
    (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d0.h[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    if ((s32) reg_d0.h[0] >= 0x7800) {
        func_00147F30();
        return;
    }
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_d1.h[0];
    func_00147F90();
}
