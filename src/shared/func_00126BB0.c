#include "common.h"

s32 func_001255F0();
s32 func_001257E0();
s32 func_001258B0();
s32 func_00125BE0();
s32 func_00125C80();
s32 func_0018D930();
s32 func_001A9130();
extern u8 *reg_a6;

void func_00126BB0() {
    if (reg_d1.w & 0x1000) {
        reg_d0.w = 8;
        func_001258B0();
        reg_tmp.w = 0x10008;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x1000;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        func_001257E0();
        return;
    }
    func_00125C80();
    func_00125BE0();
    func_001255F0();
}
