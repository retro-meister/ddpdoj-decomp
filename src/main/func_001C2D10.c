#include "common.h"

s32 func_00171400();
s32 func_001C2650();
s32 func_00202140();
s32 func_00202500();
extern u16 D_00259570[];
extern Reg32 D_0028E474;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001C2D10(void) {
    u16 t1;
    u16 t2;
    if (*(s16 *)(reg_a4 + 0xE) < 0) {
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x42);
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0x44);
        func_00202140();
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x5A);
        func_00202500();
        *(u8 *)(reg_a6 + 0x5A) = (u8) reg_d1.b[0];
    } else {
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x62);
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0x64);
        func_00202140();
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x7A);
        func_00202500();
        *(u8 *)(reg_a6 + 0x7A) = (u8) reg_d1.b[0];
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
    *(u8 *)(reg_a4 + 7) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
        func_00171400();
        if (*(s16 *)(reg_a4 + 0xE) >= 0) {
            reg_d1.w = 0;
            reg_a0 = (u8 *)(D_00259570);
            reg_d1.b[0] = *(u8 *)(reg_a6 + 0x5A);
            t1 = reg_d1.h[0];
            reg_d1.b[0] += 1;
            reg_d1.h[0] &= 0x3E;
            reg_d5.h[0] = reg_d1.h[0];
            reg_d5.h[0] += reg_d5.h[0];
            reg_d6.h[0] = t1;
            D_0028E474.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
            D_0028E474.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d5.w = D_0028E474.w;
            reg_d1.h[0] = reg_d6.h[0];
            reg_d1.h[0] += reg_d1.h[0];
            reg_d1.h[0] += reg_d1.h[0];
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0x42);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x44);
            func_001C2650();
        } else {
            reg_d1.w = 0;
            reg_a0 = (u8 *)(D_00259570);
            reg_d1.b[0] = *(u8 *)(reg_a6 + 0x7A);
            t2 = reg_d1.h[0];
            reg_d1.b[0] += 1;
            reg_d1.h[0] &= 0x3E;
            reg_d5.h[0] = reg_d1.h[0];
            reg_d5.h[0] += reg_d5.h[0];
            reg_d6.h[0] = t2;
            D_0028E474.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
            D_0028E474.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d5.w = D_0028E474.w;
            reg_d1.h[0] = reg_d6.h[0];
            reg_d1.h[0] += reg_d1.h[0];
            reg_d1.h[0] += reg_d1.h[0];
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0x62);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x64);
            func_001C2650();
        }
        *(u8 *)(reg_a4 + 0x15) += 0xA;
        *(u8 *)(reg_a4 + 0x11) -= 1;
        if (*(u8 *)(reg_a4 + 0x11) == 0) {
            *(u8 *)(reg_a4 + 0x11) = (u8) *(u8 *)(reg_a4 + 0x10);
            *(u8 *)(reg_a4 + 0x15) = (u8) *(u8 *)(reg_a4 + 0x14);
            *(u16 *)(reg_a4 + 0xE) *= -1;
            *(u16 *)(reg_a4 + 4) -= 1;
            if (*(u16 *)(reg_a4 + 4) == 0) {
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}
