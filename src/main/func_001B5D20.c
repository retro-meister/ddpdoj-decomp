#include "common.h"

s32 func_00129280();
s32 func_00129370();
extern u16 D_0028E4AA;
extern u16 D_0028E910;
extern u8 *reg_a4;

void func_001B5D20() {
    reg_d1.w = 0;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xB)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
    reg_tmp.w = reg_d0.w;
    D_0028E4AA = reg_d0.h[0];
    reg_d0.h[0] = 0x13;
    func_00129370();
    reg_d1.b[0] += 0x80;
    func_00129370();
    if (D_0028E910 != 0) {
        reg_d1.b[0] += 0x40;
        func_00129280();
        reg_d1.b[0] += 0x80;
        func_00129280();
    }
}
