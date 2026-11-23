#include "common.h"

s32 func_0015BFD0();
s32 func_0015C090();
s32 func_0015C1F0();
s32 func_001A31D0();
extern u8 D_002687B0[];
extern u8 *D_0028DF48;
extern u8 *D_0028DF4C;
extern u8 *D_0028DF50;
extern u8 *D_0028DF54;
extern u8 *D_0028DF58;
extern u8 *D_0028DF5C;
extern u8 *D_0028DF60;
extern u32 D_0028DF64;
extern u32 D_0028DF68;
extern u32 D_0028DF6C;
extern u32 D_0028DF70;
extern u32 D_0028DF74;
extern u32 D_0028DF78;
extern u32 D_0028DF7C;
extern u32 D_0028DF80;
extern s16 D_0028E7C4;
extern u16 D_0028E7C8;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0015BEF0(void) {
    D_0028DF80 = reg_d0.w;
    D_0028DF7C = reg_d1.w;
    D_0028DF78 = reg_d2.w;
    D_0028DF74 = reg_d3.w;
    D_0028DF70 = reg_d4.w;
    D_0028DF6C = reg_d5.w;
    D_0028DF68 = reg_d6.w;
    D_0028DF64 = reg_d7.w;
    D_0028DF60 = (u8 *)(reg_a0);
    D_0028DF5C = reg_a1;
    D_0028DF58 = reg_a2;
    D_0028DF54 = reg_a3;
    D_0028DF50 = reg_a4;
    D_0028DF4C = reg_a5;
    D_0028DF48 = reg_a6;
    if (D_0028E7C8 != 0) {
        func_0015BFD0();
        return;
    }
    reg_d0.h[0] = 0;
    D_0028E7C8 = 1;
    D_0028E7C4 = 0x258;
    reg_a0 = (u8 *)D_002687B0;
    func_001A31D0();
    func_0015C1F0();
    func_0015C090();
}
