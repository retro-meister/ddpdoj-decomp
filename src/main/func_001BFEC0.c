#include "common.h"

s32 func_00128AC0();
s32 func_002010A0();
extern u8 D_0026C240[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001BFEC0(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        if (*(s16 *)(reg_a4 + 8) >= 0) {
            func_002010A0();
            reg_d1.w = 0;
            reg_d0.b[0] += 0x10;
            reg_d1.b[0] = reg_d0.b[0];
        } else {
            func_002010A0();
            reg_d1.w = 0;
            reg_d0.b[0] += 0x30;
            reg_d1.b[0] = reg_d0.b[0];
        }
        reg_a0 = (u8 *)D_0026C240;
        reg_a0 += *(u16 *)(reg_a4 + 4);
        reg_d3.h[1] = *(u16 *)reg_a0;
        reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
        *(u16 *)(reg_a4 + 4) += 4;
        *(u16 *)(reg_a4 + 4) &= 0xF;
        reg_d4.h[0] = 0x140;
        reg_d0.w = 0xFFEC0012;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x22);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x24);
        func_00128AC0();
        reg_d0.w += 0x20000;
        reg_d4.h[0] -= 0x60;
        func_00128AC0();
        reg_d0.w += 0x20000;
        reg_d4.h[0] -= 0x60;
        func_00128AC0();
        reg_d0.w += 0x20000;
        reg_d4.h[0] -= 0x60;
        func_00128AC0();
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
        *(u8 *)(reg_a4 + 7) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            func_002010A0();
            reg_d0.b[0] += reg_d0.b[0];
            *(u8 *)(reg_a4 + 7) += reg_d0.b[0];
            *(u8 *)(reg_a4 + 3) = 0x18U;
        }
    }
}
