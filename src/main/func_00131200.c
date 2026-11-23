#include "common.h"

s32 func_00130D80();
s32 func_00130DB0();
s32 func_00130DC0();
s32 func_00130E00();
s32 func_00130E70();
s32 func_00130EC0();
s32 func_00130F10();
s32 func_00130FB0();
s32 func_00131050();
s32 func_001310F0();
s32 func_00131150();
s32 func_001311A0();
extern u8 D_0028E390;
extern u8 D_0028E39C;

void func_00131200(void) {
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = D_0028E39C;
    reg_d1.b[0] = D_0028E390;
    if (reg_d0.h[0] == 0x12) {
        if (reg_d1.b[0] != 1) {
            func_00130D80();
            return;
        }
        func_00130DB0();
        func_00130DC0();
        return;
    }
    if (reg_d0.h[0] == 0x11) {
        if (reg_d1.b[0] != 1) {
            func_00130E00();
            return;
        }
        func_00130E70();
        func_00130EC0();
        return;
    }
    if (((s16) reg_d0.h[0] < 0x11) && ((s16) reg_d0.h[0] >= 9)) {
        if (reg_d1.b[0] != 1) {
            func_00130F10();
            return;
        }
        func_00130FB0();
        func_00131050();
        return;
    }
    if (reg_d1.b[0] != 1) {
        func_001310F0();
        return;
    }
    func_00131150();
    func_001311A0();
}
