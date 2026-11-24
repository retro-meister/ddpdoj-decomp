#include "common.h"

s32 func_0014D220();
s32 func_0014E030();
s32 func_0014E290();
s32 func_0019C4F0();
s32 func_001FFA50();
s32 func_00201D10();
extern u8 D_0028E2E4;
extern u16 D_0028E884;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001FF920(void) {
    if (D_0028E2E4 != 0) goto block_1;
    if (D_0028E884 == 0) {
        func_001FFA50();
        return;
    }
    reg_d1.w = 0;
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1B);
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x1A);
    func_00201D10();
    *(u16 *)(reg_a6 + 2) += reg_d2.h[0];
    *(u16 *)(reg_a6 + 4) += reg_d3.h[0];
    *(u16 *)(reg_a5 + 0x18) -= 1;
    if (*(u16 *)(reg_a5 + 0x18) != 0) goto next_1;
    reg_d0.w = 0x51;
    func_0014E030();
    *(u16 *)(reg_a0 + 0x16) = *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 0x18) = *(u16 *)(reg_a6 + 4);
block_1:
    func_0014E290();
    return;
next_1:
    reg_a0 = reg_a6;
    func_0014D220();
    reg_d2.w = 0x1E93;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.w += 0xF600FE00;
    reg_d3.h[0] = 0xA10;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x1C);
    func_0019C4F0();
}
