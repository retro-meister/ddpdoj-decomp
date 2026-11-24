#include "common.h"


s32 func_00129450();
extern u8 *reg_a4;

void death_func_0021D0F0(void) {
    u32 temp_a0;

    reg_d7.h[0] = reg_d1.h[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    reg_d1.b[0] -= 1;
    func_00129450();
    reg_d1.b[0] += 2;
    func_00129450();
    reg_d1.h[0] = reg_d7.h[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
    reg_d0.w += 0x40000;
    func_00129450();
    reg_d1.b[0] -= 2;
    func_00129450();
    reg_d1.b[0] += 4;
    func_00129450();
    reg_d1.h[0] = reg_d7.h[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    temp_a0 = reg_d0.w;
    reg_d0.w = temp_a0 + 0x40000;
    reg_d1.b[0] -= 1;
    func_00129450();
    reg_d1.b[0] += 2;
    func_00129450();
    reg_d1.h[0] = reg_d7.h[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
    reg_d0.w += 0x40000;
    func_00129450();
    reg_d1.b[0] -= 2;
    func_00129450();
    reg_d1.b[0] += 4;
    func_00129450();
}
