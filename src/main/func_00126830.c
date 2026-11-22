#include "common.h"


s32 func_00125590();
s32 func_001257E0();
s32 func_00125810();
s32 func_00125930();
s32 func_00125B40();
s32 func_00127CA0();
s32 func_0018D930();
s32 func_001A9130();
extern u8 *reg_a6;

void func_00126830(void) {
    u32 temp_v0;

    temp_v0 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = temp_v0;
    if (temp_v0 & 0xFFFF) {
        reg_d0.w = 4;
        func_00125810();
        reg_tmp.w = 0x50004;
        (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0x500;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
        func_001A9130();
        func_0018D930();
        (*(u8 *)((u8 *)(reg_a6) + (0))) = 0x84;
        func_00127CA0();
        return;
    }
    func_00125B40();
    func_00125930();
    if ((*(s16 *)((u8 *)(reg_a6) + (2))) >= -0x400) {
        func_00125590();
        return;
    }
    func_001257E0();
}
