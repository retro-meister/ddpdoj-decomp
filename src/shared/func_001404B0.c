#include "common.h"

s32 func_001406F0();
s32 func_001420E0();
extern u16 D_0028E03C;
extern u16 D_0028E044;
extern s16 D_0028E054;
extern u16 D_0028E05C;
extern u16 D_0028E05E;
extern s16 D_0028E068;
extern s16 D_0028E06C;
extern s16 D_0028E074;
extern u8 D_0028E080[];
extern s16 D_0028E584;
extern u16 D_0028E920;
extern u16 D_0028E930;
extern u16 D_0028E938;
extern s8 D_0028ED6C;
extern u8 D_0028ED7C;
extern u8 D_0029CD90[];
extern u8 D_0029F180[];
extern u8 D_0029F260[];
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001404B0() {
    reg_a6 = D_0029F260;
    reg_a2 = D_0029F180;
    D_0028E920 |= 1;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (2)));
    (*(u8 *)((u8 *)(reg_a5) + (2))) |= 1;
    if (reg_tmp.b[0] & 1) {
        func_001420E0();
        return;
    }
    D_0028E584 = 0;
    if (D_0028ED7C == 1) {
        D_0028ED6C = 1;
    }
    reg_a3 = D_0029CD90;
    reg_a4 = D_0028E080;
    reg_d3.w = 0x25000E00;
    reg_d4.h[0] = D_0028E03C;
    reg_d6.h[0] = D_0028E044;
    (*(u16 *)((u8 *)(reg_a6) + (0x58))) = (u16) D_0028E938;
    (*(u16 *)((u8 *)(reg_a6) + (0x5A))) = (u16) D_0028E930;
    if ((*(u8 *)((u8 *)(reg_a5) + (7))) != 0) {
        func_001406F0();
        return;
    }
    D_0028E06C = 2;
    D_0028E068 = 2;
    reg_tmp.w = 0xC30;
    D_0028E054 = 0x101;
    D_0028E074 = 0;
    D_0028E05C = reg_tmp.h[1];
    D_0028E05E = reg_tmp.h[0];
    func_001406F0();
}
