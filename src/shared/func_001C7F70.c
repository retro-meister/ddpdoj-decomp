#include "common.h"

typedef void (*Fn)();

extern u8 D_0026C6C0[];
extern u8 D_0026C790[];
extern s8 D_0028E408;

s32 func_00124510();
s32 func_00124E80();
s32 func_00125410();
s32 func_00125440();
s32 func_0013A780();
s32 func_0013AAB0();
s32 func_0013B2E0();
s32 func_0018D560();
s32 func_0018D660();
s32 func_002010A0();
s32 func_002011A0();
s32 func_002012F0();
extern u16 D_0026C6E0[];
extern Reg32 D_0028E480;
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001C7F70(void) {
    u16 *t1;
    u16 *t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;
    u8 t7;
    u8 t8;
    u8 t9;
    u8 t10;
    u8 t11;
    u8 *v1;

    v1 = (u8 *)(reg_a4);
    t7 = (*(u8 *)((u8 *)(v1) + (3)));
    if (t7 == 4) {
        (*(u16 *)((u8 *)(v1) + (4))) -= 1;
        if (*(u16 *)(reg_a4 + 4) != 0) {
            goto block_rts;
        }
        func_00124510();
        *(s16 *)reg_a4 = 0;
block_rts:
        return;
    } else {
        if (t7 == 3) {
            reg_d6.w = 0;
            reg_a1 = (u8 *)(D_0026C6E0);
loop_6:
            t3 = *(u16 *)reg_a1;
            reg_d0.h[0] = t3;
            reg_a1 += 2;
            if (reg_d0.h[0] != 0xFFFF) {
                func_0013A780();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
                t1 = (u16 *)(reg_a1 + 2);
                reg_a1 = (u8 *)(t1);
                *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
                t4 = *(u16 *)(reg_a6 + 4);
                *(u16 *)(reg_a0 + 4) = t4;
                *(s16 *)(reg_a0 + 0x1E) = 8;
                *(s16 *)(reg_a0 + 0x12) = 0;
                *(s16 *)(reg_a0 + 0x14) = 0;
                func_002010A0();
                reg_d0.b[0] += 4;
                reg_d0.b[0] += *(u8 *)(reg_a4 + 0xD);
                *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
                func_002011A0();
                *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a0 + 0x18) = (u16) reg_d6.h[0];
                reg_d6.h[0] += 1;
                reg_a1 += 2;
                goto loop_6;
            }
            reg_d0.h[0] = 0x1E;
            func_0013A780();
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
            t6 = *(u16 *)(reg_a6 + 4);
            *(u16 *)(reg_a0 + 4) = t6;
            reg_tmp.w = 0xF4000000;
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_tmp.h[0];
            *(s16 *)(reg_a0 + 0x1E) = 4;
            func_0018D660();
            v1 = (u8 *)((void *)0x80);
            *(u16 *)(reg_a4 + 4) = 0x80U;
            *(u8 *)(reg_a4 + 3) = 4U;
        }
        t9 = *(u8 *)(reg_a4 + 3);
        if (t9 == 2) {
            func_00125440();
            if (D_0028E408 == 0) {
                reg_a0 = (u8 *)D_0026C790;
                func_0013B2E0();
                func_00124E80();
                *(u8 *)(reg_a4 + 3) = 3U;
                *(u16 *)(reg_a4 + 0xA) = 1U;
            }
        }
        t10 = *(u8 *)(reg_a4 + 3);
        if (t10 == 1) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x11);
            *(u8 *)(reg_a4 + 0x11) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0x11) = (u8) *(u8 *)(reg_a4 + 0x10);
                func_002011A0();
                reg_d1.b[0] = reg_d0.b[0];
                reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
                func_002012F0();
                reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
                reg_d2.h[0] += reg_d0.h[0];
                D_0028E480.w = reg_d2.w;
                reg_d2.h[1] = reg_d2.h[0];
                reg_d2.h[0] = D_0028E480.h[1];
                func_002012F0();
                reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
                reg_d2.h[0] += reg_d0.h[0];
                reg_d2.h[0] -= 0x1000;
                D_0028E480.w = reg_d2.w;
                reg_d2.h[1] = reg_d2.h[0];
                reg_d2.h[0] = D_0028E480.h[1];
                reg_d3.h[0] = 8;
                reg_d0.h[0] = 0;
                func_0013AAB0();
                func_0018D560();
            }
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xF);
            *(u8 *)(reg_a4 + 0xF) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0xF) = (u8) *(u8 *)(reg_a4 + 0xE);
                t11 = *(u8 *)(reg_a4 + 6);
                if (t11 != 2) {
                    *(u8 *)(reg_a4 + 6) = (u8) (t11 - 1);
                    *(u8 *)(reg_a4 + 0xD) += 1;
                }
            }
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x13);
                *(u8 *)(reg_a4 + 0x13) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a4 + 0x13) = (u8) *(u8 *)(reg_a4 + 0x12);
                    reg_a0 = (u8 *)D_0026C6C0;
                    reg_a0 += *(u16 *)(reg_a4 + 0x14);
                    reg_a0 = *(u8 **)reg_a0;
                    jtbl_0028E3F4 = (Fn)(reg_a0);
                    jtbl_0028E3F4();
                    *(u16 *)(reg_a4 + 0x14) += 4;
                    *(u16 *)(reg_a4 + 0x14) &= 0x1F;
                }
                reg_a1 = (u8 *)(D_0026C6E0);
                reg_a1 += *(u16 *)(reg_a4 + 8);
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                func_0013A780();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
                t2 = (u16 *)(reg_a1 + 2);
                reg_a1 = (u8 *)(t2);
                *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
                t5 = *(u16 *)(reg_a6 + 4);
                *(u16 *)(reg_a0 + 4) = t5;
                *(s16 *)(reg_a0 + 0x1E) = 8;
                func_002010A0();
                reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
                reg_d0.b[0] += 2;
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xD);
                reg_d1.b[0] = (u8) ((s8) reg_d1.b[0] >> 1);
                reg_d0.b[0] += reg_d1.b[0];
                *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
                func_002011A0();
                *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a4 + 8) += 0xA;
                if (*(u16 *)(reg_a4 + 8) == 0xA0) {
                    *(u16 *)(reg_a4 + 8) = 0U;
                    t8 = *(u8 *)(reg_a4 + 6);
                    if (t8 == 2) {
                        reg_d0.h[0] = 0x16;
                        func_00125410();
                        *(u8 *)(reg_a4 + 3) = 2U;
                    }
                }
            }
        }
        if (*(u8 *)(reg_a4 + 3) == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x13);
            *(u8 *)(reg_a4 + 0x13) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0x13) = (u8) *(u8 *)(reg_a4 + 0x12);
                reg_a0 = (u8 *)D_0026C6C0;
                reg_a0 += *(u16 *)(reg_a4 + 0x14);
                reg_a0 = *(u8 **)reg_a0;
                jtbl_0028E3F4 = (Fn)(reg_a0);
                jtbl_0028E3F4();
                *(u16 *)(reg_a4 + 0x14) += 4;
                *(u16 *)(reg_a4 + 0x14) &= 0x1F;
            }
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                reg_a1 = (u8 *)(D_0026C6E0);
                reg_a1 += *(u16 *)(reg_a4 + 8);
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                func_0013A780();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 2);
                *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 4);
                *(s16 *)(reg_a0 + 0x1E) = 8;
                *(s16 *)(reg_a0 + 0x12) = 0;
                *(s16 *)(reg_a0 + 0x14) = 0;
                *(u16 *)(reg_a4 + 8) += 0xA;
                if ((s16) *(u16 *)(reg_a4 + 8) >= 0xA0) {
                    *(u16 *)(reg_a4 + 8) = 0U;
                    *(u16 *)(reg_a4 + 0xA) -= 1;
                    if (*(u16 *)(reg_a4 + 0xA) == 0) {
                        *(u16 *)(reg_a4 + 6) = 0x2010;
                        *(u16 *)(reg_a4 + 0xE) = 0x1111;
                        *(u8 *)(reg_a4 + 3) = 1U;
                        *(u16 *)(reg_a4 + 0x12) = 0x101;
                        *(u16 *)(reg_a4 + 0x14) = 0U;
                    }
                }
            }
        }
    }
}
