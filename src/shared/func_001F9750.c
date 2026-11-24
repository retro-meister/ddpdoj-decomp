#include "common.h"

extern s8 D_0028E408;

s32 func_001389D0();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0018D5C0();
s32 func_0019C470();
s32 func_001A3020();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_001D5040();
s32 func_001F9ED0();
s32 func_001F9F90();
s32 func_001FA0E0();
s32 func_001FA180();
s32 func_001FA320();
s32 func_00201B80();
s32 func_00202140();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u8 D_00261AF0[];
extern u8 D_00265B40[];
extern u8 D_00265B60[];
extern u16 D_0028E3A4;
extern u16 D_0028E3A8;
extern u16 D_0028E88C;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F9750(void) {
    u16 temp_a0;
    u16 temp_a0_4;
    u8 temp_a0_2;
    u8 temp_a0_3;

    reg_d0.h[0] = 0x10;
    reg_a0 = D_00261AF0;
    func_001A3020();
    if (D_0028E8A0 == 0) {
        if ((*(u8 *)((u8 *)(reg_a6) + (0x7F))) != 0) {
            D_0028E88C = 0;
            reg_d0.h[0] = 0x20;
            reg_d1.h[0] = 0x20;
            func_001389D0();
            func_0014E290();
            return;
        }
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
            (*(u16 *)((u8 *)(reg_a6) + (0x6E))) = (u16) reg_d1.h[0];
            func_001A9000();
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
            reg_d0.b[0] ^= 0xF;
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
            reg_d0.w = 0x7FFF;
            reg_d0.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x18)));
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x32)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x34)));
            reg_tmp.w -= reg_d0.w;
            (*(u16 *)((u8 *)(reg_a5) + (0x32))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a5) + (0x34))) = (u16) reg_tmp.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (0x18))) = 0x7FFFU;
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x32)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x34)));
            if ((s32) reg_tmp.w < 0) {
                reg_d0.w = 0x1000;
                func_001A91A0();
                vibration_start_pad1(0xB4, 0x50);
                vibration_start_pad2(0xB4, 0x50);
                reg_d0.h[0] = 0x20;
                reg_d1.h[0] = 0x20;
                func_001389D0();
                (*(u16 *)((u8 *)(reg_a6) + (0))) = 0x8000;
                (*(u8 *)((u8 *)(reg_a6) + (0x7E))) = 1U;
                D_0028E88C = 0;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_a1 = D_00265B60;
                func_001D5040();
                func_0018D5C0();
                goto block_6;
            }
        } else {
block_6:
            (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = 0x10U;
        }
        func_001FA320();
        reg_d0.w = 0;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_tmp.w = (u32) (s16) reg_d0.h[0];
        reg_d0.w = reg_tmp.w;
        reg_d0.w += 0x4000;
        if ((s32) reg_d0.w < 0x801) {
            if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
                D_0028E88C = 0;
                func_0014E290();
                return;
            }
            goto block_11;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_11:
        func_00201B80();
        if ((*(u8 *)((u8 *)(reg_a6) + (0x7E))) == 0) {
            if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 0) {
                (*(u16 *)((u8 *)(reg_a5) + (0x1C))) -= 1;
                if ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) == 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 1U;
                }
            }
            if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 1) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
                (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x18)));
                    (*(u16 *)((u8 *)(reg_a5) + (0x1A))) += 4;
                    if ((s32) (*(u16 *)((u8 *)(reg_a5) + (0x1A))) >= 0x1C) {
                        (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = 0x1CU;
                        D_0028E3A8 = 0;
                        D_0028E3A4 = 0;
                        (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 2U;
                        (*(s16 *)((u8 *)(reg_a5) + (0x1E))) = 0x1020;
                        (*(s16 *)((u8 *)(reg_a5) + (0x20))) = 0x606;
                        (*(s16 *)((u8 *)(reg_a5) + (0x22))) = 6;
                        (*(s16 *)((u8 *)(reg_a5) + (0x24))) = 0x2030;
                        (*(s16 *)((u8 *)(reg_a5) + (0x26))) = 0x404;
                        (*(s16 *)((u8 *)(reg_a5) + (0x28))) = 4;
                        (*(s8 *)((u8 *)(reg_a5) + (0x2B))) = 0;
                        (*(s8 *)((u8 *)(reg_a5) + (0x2A))) = 0;
                        (*(s16 *)((u8 *)(reg_a5) + (0x2C))) = 0x6040;
                        (*(u8 *)((u8 *)(reg_a5) + (0x2F))) = 1U;
                    }
                }
            }
            if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 2) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x2D)));
                (*(u8 *)((u8 *)(reg_a5) + (0x2D))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x2D))) = (*(u8 *)((u8 *)(reg_a5) + (0x2C)));
                    if (D_0028E89C == 0) {
                        temp_a0 = 0xFA80 & 0xFFFF;
                        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                        reg_d0.h[0] += temp_a0;
                        reg_d1.h[0] += 0x7FFF + 0x7801;
                        func_00202140();
                        if (D_0028E408 == 0) {
                            reg_d0.w = 0xD;
                            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_d2.w += 0xFA7FF800;
                            reg_d4.w = 0;
                            reg_d3.w = 0;
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_d0.h[0] += 0x7FFF + 0x7A81;
                            reg_d1.h[0] += 0x800;
                            func_00202140();
                            reg_d0.w = 0xD;
                            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_d2.w += 0xFA800800;
                            reg_d4.w = 0;
                            reg_d3.w = 0;
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_d0.h[0] += 0xF80;
                            reg_d1.h[0] += 0x7FFF + 0x7941;
                            func_00202140();
                            reg_d0.w = 0xD;
                            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_d2.w += 0x0F7FF940;
                            reg_d4.w = 0;
                            reg_d3.w = 0;
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_d0.h[0] += 0xF80;
                            reg_d1.h[0] += 0x6C0;
                            func_00202140();
                            reg_d0.w = 0xD;
                            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_d2.w += 0x0F8006C0;
                            reg_d4.w = 0;
                            reg_d3.w = 0;
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_d0.h[0] += 0x13C0;
                            reg_d1.h[0] += 0x7FFF + 0x7C01;
                            func_00202140();
                            reg_d0.w = 0xD;
                            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_d2.w += 0x13BFFC00;
                            reg_d4.w = 0;
                            reg_d3.w = 0;
                            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_d0.h[0] += 0x13C0;
                            reg_d1.h[0] += 0x400;
                            func_00202140();
                            reg_d0.w = 0xD;
                            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                            reg_d2.w += 0x13C00400;
                            reg_d4.w = 0;
                            reg_d3.w = 0;
                        }
                    }
                }
            }
            if ((*(u8 *)((u8 *)(reg_a5) + (0x2F))) == 1) {
                (*(u16 *)((u8 *)(reg_a6) + (0x2E))) -= 1;
                if ((*(u16 *)((u8 *)(reg_a6) + (0x2E))) == 0) {
                    func_001F9ED0();
                    (*(u8 *)((u8 *)(reg_a5) + (0x2F))) = 2U;
                }
            }
            temp_a0_2 = (*(u8 *)((u8 *)(reg_a5) + (0x2F)));
            if (temp_a0_2 == 2) {
                func_001F9F90();
                if (D_0028E408 == 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x2F))) = 3U;
                    func_001FA0E0();
                }
            }
            temp_a0_3 = (*(u8 *)((u8 *)(reg_a5) + (0x2F)));
            if (temp_a0_3 == 3) {
                func_001FA180();
                if (D_0028E408 == 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x2F))) = 2U;
                    func_001F9ED0();
                }
            }
        }
        goto block_33;
    }
block_33:
    if ((*(u8 *)((u8 *)(reg_a6) + (0x7E))) == 0) {
        reg_a0 = D_00265B40;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        temp_a0_4 = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.h[0] = temp_a0_4;
        reg_d1.w += 0xE400EA00;
        reg_d3.h[0] = 0x1CB0;
        reg_d4.w = 0;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
        func_0019C470();
        reg_a0 = reg_a6;
        func_0014D220();
    }
}
