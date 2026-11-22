#include "common.h"

s32 func_00136BB0();
extern u16 D_0028E49E;
extern u16 D_0028E4A2;
extern u16 D_0028E4A6;
extern u8 *reg_a0;
extern u32 reg_a1;
extern u32 reg_a2;
extern u8 *reg_a6;

void func_00137820(void) {
    u32 temp_s0;

    D_0028E4A6 = (*(u16 *)((u8 *)(reg_a6) + (0x10)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x12)));
    D_0028E4A2 = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x16)));
    D_0028E49E = (*(u16 *)((u8 *)(reg_a6) + (0x18)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1A)));
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x1E)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x20)));
    reg_a2 = reg_tmp.w;
    if ((*(u8 *)((u8 *)(reg_a6) + (1))) & 2) {
        temp_s0 = reg_d1.w;
        reg_a0 = reg_a6;
        func_00136BB0();
        reg_a1 = temp_s0;
        (*(u8 *)((u8 *)(reg_a0) + (1))) |= 2;
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a1) + (2)));
        (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a1) + (4)));
        reg_tmp.w = reg_a1;
        (*(u16 *)((u8 *)(reg_a0) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a0) + (0x12))) = (u16) reg_tmp.h[0];
        return;
    }
    reg_a0 = reg_a6;
    func_00136BB0();
}
