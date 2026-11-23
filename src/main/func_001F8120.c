#include "common.h"

extern s8 D_0028E408;

s32 func_00129410();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0018D4E0();
s32 func_0019C570();
s32 func_0019CA40();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_002010A0();
s32 func_00201100();
s32 func_00201C60();
s32 func_00202180();
s32 func_00202490();
s32 func_00202730();
s32 func_00203060();
extern u8 D_00265830[];
extern u8 D_0028DA28;
extern u16 D_0028E3EC;
extern u16 D_0028E3F0;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F8120(void) {
    u8 *var_a0;
    u16 temp_a0_2;
    u16 temp_a2;

    reg_d1.w = 0x5C;
    reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
    var_a0 = (u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
        func_001A9000();
        var_a0 = (u8 *)(reg_a6);
        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x1C)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x18)));
        reg_d0.b[0] ^= reg_d2.b[0];
        (*(u8 *)((u8 *)(var_a0) + (0x1C))) = (u8) reg_d0.b[0];
        if ((*(s16 *)((u8 *)(reg_a6) + (0x18))) < 0) {
            reg_d0.w = 0x10;
            func_001A91A0();
            func_00202730();
            if (D_0028E408 == 0) {
                reg_d0.w = 0xFFFC0006;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d4.w = 0;
                reg_d3.w = 0;
                func_00129410();
                func_00201100();
                reg_d1.b[0] += reg_d5.b[0];
                reg_d0.w += 0x30000;
                func_00129410();
            }
            reg_d0.h[0] = 1;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a0_2;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0xC;
            (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
            reg_d0.b[0] *= 4;
            (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
            func_0018D4E0();
            func_0014E290();
            return;
        }
        goto block_6;
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x19)));
block_6:
    func_00203060();
    if (D_0028E408 != 0) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            func_0014E290();
            return;
        }
        goto block_10;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_10:
    if (D_0028E8A0 == 0) {
        func_00201C60();
        if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x21)));
            (*(u8 *)((u8 *)(reg_a5) + (0x21))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x21))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x20)));
                (*(u8 *)((u8 *)(reg_a6) + (0x1B))) -= 1;
                if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0x1B))) < 3) {
                    (*(s16 *)((u8 *)(reg_a5) + (0x22))) = 0;
                    (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 1U;
                    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = 0x40U;
                }
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 1) {
            (*(u16 *)((u8 *)(reg_a5) + (0x24))) -= 1;
            if ((*(u16 *)((u8 *)(reg_a5) + (0x24))) == 0) {
                (*(u16 *)((u8 *)(reg_a5) + (0x26))) = 0x3CU;
                (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 2U;
                (*(u8 *)((u8 *)(reg_a6) + (0x1B))) = 0x18U;
                func_00202180();
                if (D_0028E408 == 0) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
                }
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 2) {
            func_00202490();
            (*(u8 *)((u8 *)(reg_a6) + (0x1B))) -= 1;
            if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0x1B))) < 3) {
                (*(u8 *)((u8 *)(reg_a6) + (0x1A))) += 0x20;
                (*(u8 *)((u8 *)(reg_a6) + (0x1A))) &= 0x3F;
                (*(u16 *)((u8 *)(reg_a5) + (0x24))) = 0x40U;
                (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 1U;
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x2B))) == 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
            (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
                (*(u8 *)((u8 *)(reg_a5) + (0x2B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2A)));
                (*(u8 *)((u8 *)(reg_a5) + (0x2D))) = 0x20U;
                func_00202180();
                if (D_0028E408 == 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x2D))) = (u8) reg_d1.b[0];
                    func_002010A0();
                    (*(u8 *)((u8 *)(reg_a5) + (0x2D))) += reg_d0.b[0];
                    goto block_26;
                }
            }
        } else {
block_26:
            if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) != 2) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x29)));
                (*(u8 *)((u8 *)(reg_a5) + (0x29))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x29))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x28)));
                    if (D_0028E89C == 0) {
                        reg_d1.w = 0;
                        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x2D)));
                        reg_d0.w = 0xFFFC0006;
                        reg_d1.b[0] &= 0x3F;
                        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                        reg_d4.w = 0;
                        reg_d3.w = 0;
                        (*(u8 *)((u8 *)(reg_a5) + (0x2B))) -= 1;
                    }
                }
            }
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
        (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1C)));
            (*(u16 *)((u8 *)(reg_a5) + (0x1E))) += 4;
            (*(u16 *)((u8 *)(reg_a5) + (0x1E))) &= 7;
        }
        if ((*(u16 *)((u8 *)(reg_a5) + (0x26))) != 0) {
            reg_d0.w = 1;
            reg_d0.h[0] &= D_0028E3F0;
            if (reg_d0.h[0] == 0) {
                (*(u16 *)((u8 *)(reg_a5) + (0x26))) -= 4;
                if (0 >= (s16) (*(u16 *)((u8 *)(reg_a5) + (0x26)))) {
                    (*(u16 *)((u8 *)(reg_a5) + (0x26))) = 0U;
                }
            }
        }
    }
    reg_a0 = &D_0028DA28;
    reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x1E)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d4.w = 0;
    reg_d1.h[0] = temp_a2;
    reg_d1.w += 0xFE00FE00;
    reg_d3.h[0] = 0x210;
    reg_d4.b[0] = 0x19;
    if (D_0028E3EC != 0) {
        reg_a1 = (u8 *)D_00265830;
        reg_a1 += (*(u16 *)((u8 *)(reg_a5) + (0x26)));
        reg_d6.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
        reg_d6.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
        func_0019CA40();
    }
    reg_d4.w = 0;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
    func_0019C570();
    reg_a0 = reg_a6;
    func_0014D220();
}
