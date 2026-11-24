#include "common.h"

s32 func_0014D220();
s32 func_0019C570();
s32 func_00203670();
extern u8 D_00265A20[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F9450(void) {
    u16 temp_a0;

    func_00203670();
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1C)));
        (*(u16 *)((u8 *)(reg_a5) + (0x1E))) += 4;
        (*(u16 *)((u8 *)(reg_a5) + (0x1E))) &= 0x3F;
    }
    reg_a0 = D_00265A20;
    reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x1E)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xD800E800;
    reg_d3.h[0] = 0x28C0;
    reg_d4.w = 0;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
    func_0019C570();
    reg_a0 = reg_a6;
    func_0014D220();
}
