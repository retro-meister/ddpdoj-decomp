#include "common.h"

s32 func_001406F0();
s32 func_001420E0();
extern u16 D_0028E038;
extern u16 D_0028E040;
extern s16 D_0028E050;
extern u16 D_0028E058;
extern u16 D_0028E05A;
extern s16 D_0028E060;
extern s16 D_0028E064;
extern s16 D_0028E070;
extern u8 D_0028E078[];
extern s16 D_0028E580;
extern u16 D_0028E920;
extern u16 D_0028E92C;
extern u16 D_0028E934;
extern s8 D_0028ED6C;
extern u8 D_0028ED7C;
extern u8 D_0029CD80[];
extern u8 D_0029F110[];
extern u8 D_0029F1F0[];
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001405D0() {
    reg_a6 = D_0029F1F0;
    reg_a2 = D_0029F110;
    D_0028E920 |= 2;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (2)));
    (*(u8 *)((u8 *)(reg_a5) + (2))) |= 1;
    if (reg_tmp.b[0] & 1) {
        func_001420E0();
        return;
    }
    D_0028E580 = 0;
    if (D_0028ED7C == 1) {
        D_0028ED6C = 1;
    }
    reg_a3 = D_0029CD80;
    reg_a4 = D_0028E078;
    reg_d3.w = 0x25002E00;
    reg_d4.h[0] = D_0028E038;
    reg_d6.h[0] = D_0028E040;
    (*(u16 *)((u8 *)(reg_a6) + (0x58))) = (u16) D_0028E934;
    (*(u16 *)((u8 *)(reg_a6) + (0x5A))) = (u16) D_0028E92C;
    if ((*(u8 *)((u8 *)(reg_a5) + (7))) != 0) {
        func_001406F0();
        return;
    }
    D_0028E064 = 2;
    D_0028E060 = 2;
    reg_tmp.w = 0xC30;
    D_0028E050 = 0x101;
    D_0028E070 = 0;
    D_0028E058 = reg_tmp.h[1];
    D_0028E05A = reg_tmp.h[0];
    func_001406F0();
}
