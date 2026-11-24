#include "common.h"

s32 func_0014E030();
extern u16 D_0028E910;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B64D0(void) {
    reg_tmp.b[0] = reg_a4[7];
    reg_a4[7] -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        return;
    }
    reg_a4[7] = reg_a4[6];
    if (reg_a6[0x3E] != 0) {
        goto skip_1;
    }
    if (*(u16 *)(reg_a4 + 8) != 0) {
        goto skip_1;
    }
    reg_d0.w = 0x1E;
    func_0014E030();
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x22);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_d0.w += 0xF6C00140;
    *(u16 *)(reg_a0 + 0x16) = reg_d0.h[1];
    *(u16 *)(reg_a0 + 0x18) = reg_d0.h[0];
    *(u16 *)(reg_a0 + 0x1A) = 0x2020;
    *(u16 *)(reg_a0 + 0x1C) = *(u16 *)(reg_a4 + 4);
    *(u16 *)(reg_a0 + 0x1E) = *(u16 *)(reg_a4 + 2);
    if (D_0028E910 == 0) {
        goto skip_1;
    }
    reg_d0.w = 0x1E;
    func_0014E030();
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x22);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_d0.w += 0xF6C00140;
    *(u16 *)(reg_a0 + 0x16) = reg_d0.h[1];
    *(u16 *)(reg_a0 + 0x18) = reg_d0.h[0];
    *(u16 *)(reg_a0 + 0x1A) = 0x1A28;
    *(u16 *)(reg_a0 + 0x1C) = *(u16 *)(reg_a4 + 4);
    *(u16 *)(reg_a0 + 0x1E) = *(u16 *)(reg_a4 + 2);
skip_1:
    if (reg_a6[0x7E] != 0) {
        goto skip_2;
    }
    if (*(u16 *)(reg_a4 + 8) == 0) {
        goto skip_2;
    }
    reg_d0.w = 0x1E;
    func_0014E030();
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x62);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x64);
    reg_d0.w += 0xF6BFFEC0;
    *(u16 *)(reg_a0 + 0x16) = reg_d0.h[1];
    *(u16 *)(reg_a0 + 0x18) = reg_d0.h[0];
    *(u16 *)(reg_a0 + 0x1A) = 0x2020;
    *(u16 *)(reg_a0 + 0x1C) = *(u16 *)(reg_a4 + 4);
    *(u16 *)(reg_a0 + 0x1E) = *(u16 *)(reg_a4 + 2);
    if (D_0028E910 == 0) {
        goto skip_2;
    }
    reg_d0.w = 0x1E;
    func_0014E030();
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x62);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x64);
    reg_d0.w += 0xF6BFFEC0;
    *(u16 *)(reg_a0 + 0x16) = reg_d0.h[1];
    *(u16 *)(reg_a0 + 0x18) = reg_d0.h[0];
    *(u16 *)(reg_a0 + 0x1A) = 0x1A18;
    *(u16 *)(reg_a0 + 0x1C) = *(u16 *)(reg_a4 + 4);
    *(u16 *)(reg_a0 + 0x1E) = *(u16 *)(reg_a4 + 2);
skip_2:
    *(u16 *)(reg_a4 + 4) += 1;
    *(u16 *)(reg_a4 + 8) += 1;
    *(u16 *)(reg_a4 + 8) &= 1;
    *(u16 *)(reg_a4 + 0xA) -= 1;
    if (*(u16 *)(reg_a4 + 0xA) == 0) {
        *(u16 *)reg_a4 = 0;
    }
}
