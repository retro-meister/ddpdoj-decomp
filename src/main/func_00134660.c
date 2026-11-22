#include "common.h"

s32 func_00134740();
s32 func_00137AD0();
extern u8 D_00269BA0[];
extern u8 *reg_a0;
extern u8 *reg_a4;

void func_00134660() {
    reg_d0.h[0] = 1;
    reg_d1.h[0] = 0x33;
    if ((*(u16 *)((u8 *)(reg_a4) + (4))) != 0) {
        reg_d1.h[0] = 0x33;
        reg_d0.h[0] = 0xF;
    }
    (*(u16 *)((u8 *)(reg_a4) + (6))) = (u16) reg_d1.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (8))) = (u16) reg_d0.h[0];
    reg_a0 = D_00269BA0;
    reg_d2.h[0] = 2;
    func_00137AD0();
    func_00134740();
    if ((*(u16 *)((u8 *)(reg_a4) + (4))) == 0) {
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x32;
        reg_a0 = D_00269BA0;
        reg_d2.h[0] = 2;
        func_00137AD0();
        return;
    }
    reg_d0.h[0] = 0xF;
    reg_d1.h[0] = 0x32;
    reg_a0 = D_00269BA0;
    reg_d2.h[0] = 2;
    func_00137AD0();
}
