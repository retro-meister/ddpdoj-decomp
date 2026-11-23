#include "common.h"

extern s8 D_0028E408;

s32 func_0011C7C0();
s32 func_00130CC0();
s32 func_00131610();
s32 func_00134660();
s32 func_00137AD0();
s32 func_0018D9F0();
extern u8 D_00269B90[];
extern u8 D_00269BA0[];
extern u8 *reg_a0;
extern u8 *reg_a4;

void func_00134410(void) {
    u16 temp_a0;

    func_00131610();
    if (D_0028E408 != 0) {
        func_00134660();
        return;
    }
    if ((*(u16 *)((u8 *)(reg_a4) + (2))) == 0) {
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x33;
        reg_a0 = (u8 *)D_00269BA0;
        reg_d2.h[0] = 2;
        func_00137AD0();
        reg_d0.h[0] = 0xF;
        reg_d1.h[0] = 0x33;
        reg_a0 = (u8 *)D_00269BA0;
        reg_d2.h[0] = 2;
        func_00137AD0();
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x32;
        reg_a0 = (u8 *)D_00269BA0;
        reg_d2.h[0] = 2;
        func_00137AD0();
        reg_d0.h[0] = 0xF;
        reg_d1.h[0] = 0x32;
        reg_a0 = (u8 *)D_00269BA0;
        reg_d2.h[0] = 2;
        func_00137AD0();
        (*(u16 *)((u8 *)(reg_a4) + (2))) = 1U;
        (*(u8 *)((u8 *)(reg_a4) + (0xD))) = 0U;
        reg_d0.h[0] = 0x8C;
        reg_d1.h[0] = 0x400;
        reg_d2.w = 3;
        reg_d3.w = 0x13;
        func_0011C7C0();
        reg_d0.h[0] = 0x74;
        reg_d1.h[0] = 0xC00;
        reg_d2.w = 7;
        reg_d3.w = 3;
        func_0011C7C0();
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x33;
        if ((*(u16 *)((u8 *)(reg_a4) + (4))) != 0) {
            reg_d1.h[0] = 0x33;
            reg_d0.h[0] = 0xF;
        }
        (*(u16 *)((u8 *)(reg_a4) + (6))) = (u16) reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a4) + (8))) = (u16) reg_d0.h[0];
    }
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a4) + (6)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_d0.h[0] = temp_a0;
    reg_a0 = (u8 *)D_00269B90;
    reg_d2.h[0] = 2;
    func_00137AD0();
    reg_d4.w = 0;
    reg_d4.b[0] = (u8) (*(s8 *)((u8 *)(reg_a4) + (0xA)));
    if ((*(u8 *)((u8 *)(reg_a4) + (0xD))) != reg_d4.b[0]) {
        (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) reg_d4.b[0];
        func_0018D9F0();
    }
    reg_d4.w = 0;
    reg_d4.b[0] = (u8) (*(s8 *)((u8 *)(reg_a4) + (0xA)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_d0.h[0] += 0xA;
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a4) + (6)));
    reg_d2.h[0] = 2;
    func_00130CC0();
}
