#include "common.h"

s32 func_0013EEE0();
s32 func_0013F000();
s32 func_001A3560();
extern u8 D_00251AE0[];
extern u8 D_00251B00[];
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_001AF3A0() {
    (*(s8 *)((u8 *)(reg_a5) + (3))) = 1;
    reg_a4 = D_00251AE0;
    if ((*(u8 *)((u8 *)(reg_a5) + (6))) != 0) {
        reg_a4 = D_00251B00;
    }
    reg_tmp.w = (u32) reg_a4;
    (*(u16 *)((u8 *)(reg_a5) + (8))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0xA))) = (u16) reg_tmp.h[0];
    if ((*(u8 *)((u8 *)(reg_a5) + (6))) == 0) {
        func_0013EEE0();
    } else {
        func_0013F000();
    }
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (6)));
    func_001A3560();
    (*(s8 *)((u8 *)(reg_a5) + (0xD))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x12))) = 0x4B0;
    (*(s16 *)((u8 *)(reg_a5) + (0x14))) = 4;
}
