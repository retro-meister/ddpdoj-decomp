#include "common.h"

typedef void (*Fn)();

extern u8 D_0026ED90[];
s32 func_00171400();
s32 func_002010A0();
s32 func_002026F0();
extern u16 D_0026ED98[];
extern u8 D_0026EDA0[];
extern u8 D_0026EDA8[];
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001DB480(void) {
    u16 *t1;
    u16 t2;
    u16 t3;
    u16 t4;
    u16 t5;
    u16 t6;
    u16 t7;
    u8 t8;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        if (*(u8 *)(reg_a4 + 9) == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
            *(u8 *)(reg_a4 + 5) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
                *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
                reg_a0 = (u8 *)D_0026ED90;
                reg_a0 += *(u16 *)(reg_a4 + 0xC);
                reg_d0.h[0] = *(u16 *)(reg_a6 + 0x22);
                reg_d1.h[0] = *(u16 *)(reg_a6 + 0x24);
                reg_d0.h[0] += *(u16 *)reg_a0;
                reg_a0 += 2;
                reg_d1.h[0] += *(u16 *)reg_a0;
                func_002026F0();
                *(u8 *)(reg_a4 + 0xA) = (u8) reg_d1.b[0];
                func_002010A0();
                *(u8 *)(reg_a4 + 0xA) += reg_d0.b[0];
                *(u8 *)(reg_a4 + 0xB) = 0U;
                goto next_1;
            }
        } else {
next_1:
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                reg_d0.w = 0;
                reg_d0.b[0] = *(u8 *)(reg_a4 + 0xB);
                reg_d1.w = 0;
                reg_d0.h[0] = (u16) (s8) reg_d0.b[0];
                t5 = reg_d0.h[0];
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = t5;
                reg_d0.h[0] = 0x13;
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xA);
                reg_a0 = (u8 *)D_0026ED90;
                reg_a0 += *(u16 *)(reg_a4 + 0xC);
                reg_d2.h[1] = *(u16 *)(reg_a6 + 0x22);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 0x24);
                reg_d3.h[1] = *(u16 *)reg_a0;
                reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
                reg_d4.w = 0;
                reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xC);
                reg_tmp.h[0] += *(u16 *)(reg_a6 + 0x19C);
                ((Fn)*(u32 *)((u8 *)D_0026EDA0 + (reg_tmp.h[0] & ~3)))();
                *(u8 *)(reg_a4 + 9) -= 1;
                if ((s8) *(u8 *)(reg_a4 + 9) == 0) {
                    *(u16 *)(reg_a4 + 0xC) += 4;
                    *(u16 *)(reg_a4 + 0xC) &= 0xF;
                    if ((s16) *(u16 *)(reg_a4 + 0xC) == 0) {
                        *(u16 *)(reg_a4 + 4) = 0x3002;
                        *(u16 *)(reg_a4 + 8) = 0xA;
                        *(u8 *)(reg_a4 + 0xB) = 8U;
                        *(u8 *)(reg_a4 + 3) = 1U;
                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x22);
                        reg_d1.h[0] = *(u16 *)(reg_a6 + 0x24);
                        func_002026F0();
                        *(u8 *)(reg_a4 + 0xA) = (u8) reg_d1.b[0];
                        func_002010A0();
                        *(u8 *)(reg_a4 + 0xA) += reg_d0.b[0];
                        func_00171400();
                    }
                }
            }
        }
    }
    t8 = *(u8 *)(reg_a4 + 3);
    if (t8 == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            if (*(u16 *)(reg_a4 + 0xE) == 0) {
                func_00171400();
                *(u16 *)(reg_a4 + 0xE) = 1U;
                reg_d0.h[0] = *(u16 *)(reg_a6 + 0x22);
                reg_d1.h[0] = *(u16 *)(reg_a6 + 0x24);
                func_002026F0();
                *(u8 *)(reg_a4 + 0xA) = (u8) reg_d1.b[0];
            }
            reg_a3 = (u8 *)(D_0026ED98);
            reg_a2 = (u8 *)D_0026EDA8;
            reg_a2 += *(u16 *)(reg_a6 + 0x19C);
            reg_d7.w = 1;
            do {
                reg_d0.w = 0;
                reg_d0.b[0] = *(u8 *)(reg_a4 + 0xB);
                reg_d1.w = 0;
                reg_d0.h[0] = (u16) (s8) reg_d0.b[0];
                t7 = reg_d0.h[0];
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = t7;
                reg_d0.h[0] = 0x13;
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xA);
                reg_d2.h[1] = *(u16 *)(reg_a6 + 0x22);
                t6 = *(u16 *)(reg_a6 + 0x24);
                reg_d2.h[0] = t6;
                t3 = *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_d3.h[1] = t3;
                t4 = *(u16 *)reg_a3;
                t1 = (u16 *)(reg_a3 + 2);
                reg_d3.h[0] = t4;
                reg_a3 = (u8 *)(t1);
                reg_d4.w = 0;
                reg_a0 = *(u8 **)reg_a2;
                reg_a2 += 4;
                jtbl_0028E3F4 = (Fn)(reg_a0);
                jtbl_0028E3F4();
            } while ((s16)(--reg_d7.h[0]) >= 0);
            *(u16 *)(reg_a4 + 8) -= 1;
            if (*(s16 *)(reg_a4 + 8) == 0) {
                *(s16 *)reg_a4 = 0;
                t2 = *(u16 *)(reg_a6 + 0x19C);
                if (t2 != 0x10) {
                    *(u16 *)(reg_a6 + 0x19C) = (u16) (t2 + 8);
                }
            }
        }
    }
}
