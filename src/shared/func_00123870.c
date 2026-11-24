#include "common.h"

s32 func_00122FD0();
s32 func_00123210();
s32 func_00123240();
extern u16 D_0028E92C;
extern u16 D_0028E930;
extern u8 D_00295E00[];
extern s16 D_00295E2C_as_s16_a[];
extern s8 D_0029F261_as_s8_a[];
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00123870(void) {
    *(s8 *)(reg_a5 + 3) = 1;
    func_00123240();
    func_00122FD0();
    reg_d0.w = 0;
    func_00123210();
    D_00295E2C_as_s16_a[0] = 0;
    reg_a6 = (u8 *)D_00295E00;
    if (*(u16 *)(reg_a6 + 0x10) != 1) goto next_0;
    reg_d0.h[0] = D_0028E930;
    if (0 > D_0029F261_as_s8_a[0]) goto next_1;
    reg_d0.h[0] = D_0028E92C;
    goto next_1;
next_0:
    reg_d0.h[0] = D_0028E930;
    if (*(u16 *)(reg_a6 + 0x12) == 0) goto next_1;
    reg_d0.h[0] = D_0028E92C;
next_1:
    if (reg_d0.h[0] == 2) {
        *(u16 *)(reg_a6 + 0xE) = 0U;
    }
    if (reg_d0.h[0] == 4) {
        *(u16 *)(reg_a6 + 0xE) = 1U;
    }
    if (reg_d0.h[0] == 6) {
        *(u16 *)(reg_a6 + 0xE) = 2U;
    }
    if (*(u16 *)(reg_a6 + 0x12) != 0) {
        reg_d0.w = 0;
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0xE);
        reg_d0.h[0] += 1;
        func_00123210();
    }
}
