#include "common.h"

extern s8 D_0028E408;

s32 func_0013D7A0();
s32 func_0013DA90();
s32 func_0016AF30();
s32 func_0016AF90();
s32 func_0016C2A0();
s32 func_0016C350();
s32 func_0018D910();
s32 func_0018DC60();
s32 func_0019D230();
extern u32 D_0026ADC0[];
extern u32 D_0026AFC0[];
extern Reg32 D_0028E484;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_0016AD60(void) {
    u32 t1;
    u32 t2;
    u32 t3;

    if (!(reg_d1.w & 0x2000)) {
        *(u8 *)(reg_a6 + 1) |= 0x20;
        func_0016AF30();
        *(s16 *)(reg_a6 + 0xC) = 0x202;
        *(u16 *)(reg_a6 + 0xE) = 0U;
    }
    t2 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = t2;
    if (t2 & 0xFFFF) {
        if (!(reg_d1.w & 0x1000)) goto next_2;
        func_0013D7A0();
        if (D_0028E408 == 0) goto next_1;
        func_0016C350();
        return;
next_1:
        func_0018D910();
        func_0018DC60();
        reg_a0 = (u8 *)(D_0026AFC0);
        func_0016C2A0();
        return;
next_2:
        func_0013DA90();
        if (D_0028E408 == 0) goto next_1;
        func_0016C350();
        return;
    }
    func_0016AF90();
    if (D_0028E408 == 0) {
        *(u8 *)(reg_a6 + 0xD) -= 1;
        if ((s8) *(u8 *)(reg_a6 + 0xD) < 0) {
            *(u8 *)(reg_a6 + 0xD) = (u8) *(u8 *)(reg_a6 + 0xC);
            *(u16 *)(reg_a6 + 0xE) += 4;
            *(u16 *)(reg_a6 + 0xE) &= 0xF;
        }
        reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
        reg_d1.h[0] += 0xFA00 & 0xFFFF;
        D_0028E484.w = reg_d1.w;
        reg_d1.h[1] = reg_d1.h[0];
        reg_d1.h[0] = D_0028E484.h[1];
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        reg_a0 = (u8 *)(D_0026ADC0);
        reg_d1.h[0] += 0x7FFF + 0x7D01;
        t1 = *(u16 *)(reg_a6 + 0xE);
        reg_a0 += t1;
        t3 = *(u32 *)reg_a0;
        reg_d2.w = t3;
        reg_d3.h[0] = 0x618;
        reg_d4.h[0] = 0x1B;
        func_0019D230();
    }
}
