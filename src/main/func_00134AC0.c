#include "common.h"

s32 func_00134A70();
s32 func_001A3560();
s32 func_001ACA00();
s32 func_001ACA80();
extern u8 D_00269CD0[];
extern u8 D_00269CF0[];
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_00134AC0() {
    (*(s8 *)((u8 *)(reg_a5) + (3))) = 1;
    reg_a4 = D_00269CD0;
    if ((*(u8 *)((u8 *)(reg_a5) + (6))) != 0) {
        reg_a4 = D_00269CF0;
    }
    reg_tmp.w = (u32) reg_a4;
    (*(u16 *)((u8 *)(reg_a5) + (8))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0xA))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a5) + (0x14))) = 1;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (6)));
    func_001A3560();
    if ((*(u8 *)((u8 *)(reg_a5) + (6))) == 0) {
        func_001ACA00();
    } else {
        func_001ACA80();
    }
    func_00134A70();
}
