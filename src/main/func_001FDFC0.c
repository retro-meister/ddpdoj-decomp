#include "common.h"

s32 func_001FDDD0();
s32 func_001FE0F0();
s32 func_001FE100();
s32 func_001FE2E0();
s32 func_001FE2F0();
s32 func_001FF000();
extern u8 D_0028DA58;
extern s8 D_0028E408;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001FDFC0() {
    if ((*(u16 *)((u8 *)(reg_a6) + (0x28))) == 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0x28))) = 1U;
        (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 4;
        (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = 0U;
        (*(u16 *)((u8 *)(reg_a6) + (0x30))) = 0x12CU;
        func_001FE100();
        func_001FE2F0();
    }
    reg_a0 = &D_0028DA58;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    func_001FF000();
    if (D_0028E408 == 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0x2A))) += 4;
        (*(u16 *)((u8 *)(reg_a6) + (0x2A))) &= 7;
    }
    (*(u16 *)((u8 *)(reg_a6) + (0x30))) -= 1;
    if ((*(u16 *)((u8 *)(reg_a6) + (0x30))) == 0) {
        reg_d0.w = 2;
        if ((*(u16 *)((u8 *)(reg_a5) + (0x18))) != 0) {
            reg_d0.w = 4;
        }
        func_001FDDD0();
        (*(u16 *)((u8 *)(reg_a5) + (0x18))) += 1;
        (*(u16 *)((u8 *)(reg_a5) + (0x18))) &= 1;
        func_001FE0F0();
        func_001FE2E0();
    }
}
