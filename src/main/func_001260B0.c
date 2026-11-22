#include "common.h"

s32 func_00125810();
s32 func_00127CA0();
s32 func_0018D930();
s32 func_001A9130();
extern u8 *reg_a6;

void func_001260B0() {
    reg_d0.w = 1;
    func_00125810();
    reg_tmp.w = 0x50000;
    (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
    reg_d0.w = 0x50;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
    func_001A9130();
    func_0018D930();
    (*(u8 *)((u8 *)(reg_a6) + (0))) = 0x84;
    func_00127CA0();
}
