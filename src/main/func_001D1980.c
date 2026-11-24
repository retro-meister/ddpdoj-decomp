#include "common.h"

s32 func_0019C670();
extern u16 D_0026D3E0[];
extern Reg32 D_0028E484;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001D1980(void) {
    reg_a0 = (u8 *)D_0026D3E0;
    reg_a0 += *(u16 *)(reg_a6 + 0xBC);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.w += 0xF7000000;
    D_0028E484.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    D_0028E484.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.w += D_0028E484.w;
    reg_d3.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d4.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    func_0019C670();
}
