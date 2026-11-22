#include "common.h"

s32 func_00124D90();
s32 func_00124F50();
s32 func_00125120();
s32 func_00125310();
s32 func_001E56D0();
extern u16 D_0028E85C;
extern u16 D_0028E860;
extern u16 D_0028E864;
extern u16 D_0028E868;
extern u16 D_0028E86C;
extern u16 D_0028E910;
extern u8 *reg_a4;

void func_001E55D0() {
    D_0028E85C = 2;
    D_0028E86C = 0xFFFF;
    reg_d0.w = 8;
    D_0028E868 = 0xFFFF;
    D_0028E864 = 0;
    func_00124D90();
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    reg_d0.w = 4;
    func_00125120();
    reg_d0.w = 3;
    func_00124F50();
    reg_d0.w = 6;
    func_00125310();
    reg_d0.w = 7;
    func_00125310();
    reg_d0.w = 8;
    func_00125310();
    reg_d0.w = 9;
    func_00125310();
    reg_d0.w = 0xA;
    func_00125310();
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x180;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (8))) = 0x100;
    (*(s16 *)((u8 *)(reg_a4) + (0xA))) = 1;
    if (D_0028E910 != 0) {
        (*(s16 *)((u8 *)(reg_a4) + (0xA))) = 3;
    }
    (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 8;
    (*(s16 *)((u8 *)(reg_a4) + (0xE))) = 8;
    D_0028E860 = 0;
    func_001E56D0();
}
