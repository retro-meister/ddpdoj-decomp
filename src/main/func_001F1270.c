#include "common.h"

s32 func_0019C670();
s32 func_0019D920();
extern u8 D_00264A50[];
extern u16 D_0028E3E8;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001F1270(void) {
    u16 temp_a0;

    reg_a0 = D_00264A50;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x132)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF400F900;
    reg_d3.h[0] = 0xC38;
    reg_d4.w = 0;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xEC)));
    if (((*(u8 *)((u8 *)(reg_a6) + (0x15E))) == 0) && (D_0028E3E8 != 0)) {
        func_0019D920();
        return;
    }
    func_0019C670();
}
