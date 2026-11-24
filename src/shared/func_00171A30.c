#include "common.h"

s32 func_00171490();
s32 func_00171520();
s32 func_00171580();
s32 func_00171670();
s32 func_00171770();
s32 func_00171820();
s32 func_0019D6D0();
s32 func_001A3020();
extern u8 D_002554B0[];
extern u8 D_0026B170[];
extern u8 D_0026B180[];
extern u8 D_0028DAC0[];
extern s32 D_0028DC20;
extern u16 D_0028E798;
extern s16 D_0028E79C;
extern u16 D_0028E918;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_00171A30(void) {
    s32 temp_a1;
    s32 var_v0;
    u16 temp_a2;

    if ((*(s16 *)((u8 *)(reg_a6) + (0))) >= 0) {
        reg_a0 = (u8 *)D_0026B180;
        func_00171490();
        reg_a0 = (u8 *)D_0028DAC0;
        var_v0 = (s32) D_0028DC20 >> 1;
        if (D_0028DC20 < 0) {
            var_v0 = (s32) (D_0028DC20 + 1) >> 1;
        }
        reg_d0.w = var_v0 - 1;
        func_00171520();
        reg_d0.h[0] = D_0028E918;
        temp_a2 = reg_d0.h[0];
        temp_a1 = temp_a2 & ~1;
        reg_d0.h[0] = *(u16 *)(D_0026B170 + temp_a1);
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x3C))) = (u8) reg_d0.b[0];
        reg_a0 = (u8 *)D_002554B0;
        func_001A3020();
        return;
    }
    if ((*(u16 *)((u8 *)(reg_a4) + (0))) == 0) {
        if (D_0028E798 != 0) {
            (*(s16 *)((u8 *)(reg_a4) + (2))) = 1;
            D_0028E79C = 0;
            (*(s16 *)((u8 *)(reg_a6) + (0))) = 0;
            return;
        }
        reg_d1.w = 0;
        reg_d2.w = 0x10AA;
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xE)));
        reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
        func_0019D6D0();
        return;
    }
    if ((*(u16 *)((u8 *)(reg_a6) + (0x10))) != 0) {
        func_00171580();
    }
    func_00171770();
    reg_a6 += 0x20;
    if ((*(u16 *)((u8 *)(reg_a6) + (0x10))) != 0) {
        func_00171670();
    }
    func_00171820();
}
