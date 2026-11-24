#include "common.h"

extern s8 D_0028E408;

s32 func_00122CE0();
s32 func_00123210();
s32 func_00123870();
s32 func_0012FD00();
s32 func_0018DE90();
s32 func_0018DEA0();
s32 func_0018DEE0();
s32 memset();
extern u8 D_0028DE80;
extern u8 D_00295E00[];
extern s16 D_00295E3E_as_s16_a[];
extern s16 D_00295E40_as_s16_a[];
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00123780(void) {
    (*(s8 *)((u8 *)(reg_a5) + (3))) = 1;
    (*(s16 *)((u8 *)(&D_0028DE80) + (8))) = 1;
    reg_a0 = (u8 *)D_00295E00;
    memset(D_00295E00, 0, 0x44);
    reg_a6 = (u8 *)D_00295E00;
    reg_d0.w = 0;
    if (0 > D_0029F260[0]) {
        reg_d0.h[0] += 1;
    }
    if (0 > D_0029F1F0[0]) {
        reg_d0.h[0] += 1;
    }
    (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_d0.h[0];
    D_00295E3E_as_s16_a[0] = 0x101;
    D_00295E40_as_s16_a[0] = 0;
    func_0012FD00();
    func_0018DEE0();
    func_0018DE90();
    func_0018DEA0();
    func_00123870();
    func_00122CE0();
    if (D_0028E408 != 0) {
        reg_d0.w = 4;
        func_00123210();
    }
}
