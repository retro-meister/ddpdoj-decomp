#include "common.h"


s32 func_001B23C0();
s32 func_00201E20();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B2500(void) {
    u32 temp_a0;

    if ((*(u8 *)((u8 *)(reg_a6) + (0x7E))) != 0) {
        func_001B23C0();
        return;
    }
    reg_d1.w = 0;
    reg_d0.w = 2;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
    func_00201E20();
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x66)));
    (*(u16 *)((u8 *)(reg_a6) + (0x66))) = (u16) (temp_a0 + reg_d2.h[0]);
    reg_d0.w = 1;
    reg_d1.w = 0;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (4)));
    func_00201E20();
    (*(u16 *)((u8 *)(reg_a6) + (0x68))) += reg_d3.h[0];
    (*(u8 *)((u8 *)(reg_a4) + (5))) += 2;
    (*(u8 *)((u8 *)(reg_a4) + (4))) += 1;
}
