#include "common.h"


s32 func_0019C530();
extern u8 D_00263630[];
extern u8 D_00263650[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001D6990(void) {
    u16 temp_a0;

    reg_a0 = D_00263650;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0xA)));
    (*(u16 *)((u8 *)(reg_a6) + (0x14))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (0)));
    (*(u16 *)((u8 *)(reg_a6) + (0x16))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_a0 = D_00263630;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0xA)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF200F100;
    reg_d3.h[0] = 0xE78;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    func_0019C530();
}
