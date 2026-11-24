#include "common.h"

s32 func_0014E290();
s32 func_0019BF80();
s32 func_0019C530();
s32 func_00201FC0();
s32 func_00202040();
extern u16 D_0028E8A0;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001E4160(u8 *arg0, u8 *arg1) {
    u8 *t1;
    u8 *t2;

    t1 = (u8 *)(arg0);
    t2 = (u8 *)(arg1);
    if (D_0028E8A0 == 0) {
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x24);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x26);
        reg_a0 = (u8 *)reg_tmp.w;
        reg_d0.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[0] = *(u16 *)(reg_a0 + 4);
        reg_d0.h[0] += *(u16 *)(reg_a5 + 0x28);
        reg_d1.h[0] += *(u16 *)(reg_a5 + 0x20);
        *(u16 *)(reg_a6 + 2) = (u16) reg_d0.h[0];
        *(u16 *)(reg_a6 + 4) = (u16) reg_d1.h[0];
        reg_d4.w = 1;
        func_00201FC0();
        *(u16 *)(reg_a6 + 2) += reg_d2.h[0];
        reg_d1.w = 0;
        reg_d0.w = 0;
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1B);
        reg_d1.b[0] = *(u8 *)(reg_a6 + 0x1A);
        reg_d4.w = 3;
        func_00202040();
        t2 = (u8 *)(reg_a5);
        reg_tmp.h[1] = (*(u16 *)((u8 *)(t2) + (0x24)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(t2) + (0x26)));
        reg_a0 = (u8 *)reg_tmp.w;
        reg_d0.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[0] = *(u16 *)(reg_a0 + 4);
        reg_d0.h[0] += (*(u16 *)((u8 *)(t2) + (0x28)));
        reg_d1.h[0] += (*(u16 *)((u8 *)(t2) + (0x20)));
        (*(u16 *)((u8 *)(t2) + (0x1C))) = (u16) reg_d0.h[0];
        *(u16 *)(reg_a5 + 0x1E) = (u16) reg_d1.h[0];
        *(u16 *)(reg_a5 + 0x1C) += reg_d2.h[0];
        t1 = (u8 *)(reg_a5);
        (*(u16 *)((u8 *)(t1) + (0x1E))) += reg_d3.h[0];
        reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x1B);
        *(u8 *)(reg_a6 + 0x1B) -= 4;
        if ((s32) reg_tmp.b[0] < 4) {
            func_0014E290();
            return;
        }
    }
    *(u8 *)(reg_a6 + 0x1D) ^= 0x60;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
    *(u8 *)(reg_a5 + 0x1B) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_100;
    *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_tmp.w += 1;
    *(u16 *)(reg_a6 + 0xA) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = (u16) reg_tmp.h[0];
    reg_d0.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (reg_tmp.w != reg_d0.w) goto next_200;
    func_0014E290();
    return;
next_100:
    func_0019BF80();
    return;
next_200:
    func_0019BF80();
    reg_d1.h[1] = *(u16 *)(reg_a5 + 0x1C);
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x1E);
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 8);
    reg_d1.w += reg_tmp.w;
    reg_d2.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_d3.h[0] = *(u16 *)(reg_a6 + 0xE);
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
    func_0019C530();
}
