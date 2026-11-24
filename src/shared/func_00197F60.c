#include "common.h"

extern s8 D_0028E408;

s32 func_0012FAB0();
s32 func_0018D450();
s32 func_001A3020();
s32 func_001ACBA0();
s32 func_001ACC60();
s32 func_00219570();
s32 memset();
extern u8 D_00261EF0[];
extern u8 D_00261F30[];
extern u8 D_00261F70[];
extern u8 D_00261FB0[];
extern u16 D_0028E4B0;
extern u8 D_0028E8B4;
extern u16 D_0028E920;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 D_002BAE00[];
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_00197F60(void) {
    func_00219570();
#ifndef DEATH_LABEL
    D_0028E4B0 = D_0028E920;
#endif
    func_0012FAB0();
    (*(s8 *)((u8 *)(reg_a5) + (3))) = 1;
    memset(D_002BAE00, 0, 0x84);
    reg_a0 = (u8 *)D_00261F30;
    reg_d0.h[0] = 2;
    func_001A3020();
    reg_a0 = (u8 *)D_00261F70;
    reg_d0.h[0] = 3;
    func_001A3020();
    reg_a0 = (u8 *)D_00261FB0;
    reg_d0.h[0] = 4;
    func_001A3020();
    reg_a0 = (u8 *)D_00261EF0;
    reg_d0.h[0] = 5;
    func_001A3020();
    if (0 > D_0029F260[0]) {
        func_001ACBA0();
        if (D_0028E408 == 0) {
            D_0028E8B4 |= 1;
        }
    }
    if (0 > D_0029F1F0[0]) {
        func_001ACC60();
        if (D_0028E408 == 0) {
            D_0028E8B4 |= 2;
        }
    }
    (*(u8 *)((u8 *)(reg_a5) + (4))) = (u8) D_0028E8B4;
    if ((*(u8 *)((u8 *)(reg_a5) + (4))) != 0) {
        func_0018D450();
    }
}
