#include "common.h"

extern s8 D_0028E408;

s32 func_0016BD50();
s32 func_0019D230();
extern u32 D_0026ADF0[];
extern u16 D_0028E3EC;
extern Reg32 D_0028E474;
extern Reg32 D_0028E484;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_0016BAF0(void) {
    u32 t1;
    u32 t2;

    func_0016BD50();
    if (D_0028E408 == 0) {
        *(u8 *)(reg_a6 + 0xD) -= 1;
        if ((s8) *(u8 *)(reg_a6 + 0xD) < 0) {
            *(u8 *)(reg_a6 + 0xD) = (u8) *(u8 *)(reg_a6 + 0xC);
            *(u16 *)(reg_a6 + 0xE) += 4;
            *(u16 *)(reg_a6 + 0xE) &= 0x3F;
        }
        reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
        reg_d1.h[0] += reg_d5.h[0];
        D_0028E484.w = reg_d1.w;
        reg_d1.h[1] = reg_d1.h[0];
        reg_d1.h[0] = D_0028E484.h[1];
        D_0028E474.w = reg_d5.w;
        reg_d5.h[1] = reg_d5.h[0];
        reg_d5.h[0] = D_0028E474.h[1];
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        reg_d1.h[0] += reg_d5.h[0];
        reg_d3.h[0] = 0x638;
        func_0019D230();
        if (D_0028E3EC != 0) {
            reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
            reg_d1.h[0] += 0xFC00;
            D_0028E484.w = reg_d1.w;
            reg_d1.h[1] = reg_d1.h[0];
            reg_d1.h[0] = D_0028E484.h[1];
            reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d2.w = 0xB5C;
            reg_d1.h[0] += 0xFD00;
            reg_d3.h[0] = 0x418;
            func_0019D230();
        }
        reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
        reg_d1.h[0] += 0xFC00;
        D_0028E484.w = reg_d1.w;
        reg_d1.h[1] = reg_d1.h[0];
        reg_d1.h[0] = D_0028E484.h[1];
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        reg_a0 = (u8 *)(D_0026ADF0);
        reg_d1.h[0] += 0xFD00;
        t1 = *(u16 *)(reg_a6 + 0xE);
        reg_a0 += t1;
        t2 = *(u32 *)reg_a0;
        reg_d2.w = t2;
        reg_d3.h[0] = 0x418;
        func_0019D230();
    }
}
