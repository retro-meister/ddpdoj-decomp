#include "common.h"

extern s8 D_0028E408;

s32 func_00125EC0();
s32 func_00128970();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0018D4E0();
s32 func_0019C470();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_00201B80();
s32 func_00202180();
extern u8 D_00265150[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F6340(void) {
    u16 temp_a0;
    u16 temp_a1;

    if ((*(s16 *)((u8 *)(reg_a6) + (2))) < -0x7FF) {
        func_0014E290();
        return;
    }
    func_00201B80();
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
        func_001A9000();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x18)));
        reg_d0.b[0] ^= reg_d2.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
        if ((*(s16 *)((u8 *)(reg_a6) + (0x18))) < 0) {
            reg_d0.w = 0x34;
            func_001A91A0();
            reg_d0.h[0] = 0x88;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a1;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 4;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 2;
            func_0018D4E0();
            reg_d1.w = 0;
            reg_d0.w = 8;
            reg_d2.w = 1;
            func_00125EC0();
            func_0014E290();
            return;
        }
        goto block_6;
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x19)));
block_6:
    if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 0) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
            (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 1U;
        }
    }
    if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 1) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
        (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1C)));
            (*(u16 *)((u8 *)(reg_a5) + (0x1E))) += 4;
            if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0x1E))) >= 0x1C) {
                (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = 0x1CU;
                func_00202180();
                if (D_0028E408 == 0) {
                    reg_d1.b[0] += 2;
                    reg_d1.h[0] &= 0x3C;
                    (*(u8 *)((u8 *)(reg_a5) + (0x27))) = (u8) reg_d1.b[0];
                    (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 2U;
                    (*(s16 *)((u8 *)(reg_a5) + (0x20))) = 0x808;
                    (*(s16 *)((u8 *)(reg_a5) + (0x22))) = 3;
                    (*(s16 *)((u8 *)(reg_a5) + (0x24))) = 3;
                }
            }
        }
    }
    if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 2) {
        if ((*(s16 *)((u8 *)(reg_a6) + (2))) < 0x1400) {
            (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 3U;
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x25))) == 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x21)));
            (*(u8 *)((u8 *)(reg_a5) + (0x21))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x21))) = (*(u8 *)((u8 *)(reg_a5) + (0x20)));
                (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (*(u8 *)((u8 *)(reg_a5) + (0x24)));
                goto block_20;
            }
        } else {
block_20:
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
            (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
                reg_d0.w = 0xFFFE0006;
                reg_d1.w = 0;
                reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x27)));
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d4.w = 0;
                reg_d3.w = 0;
                func_00128970();
                (*(u8 *)((u8 *)(reg_a5) + (0x25))) -= 1;
                if ((*(u8 *)((u8 *)(reg_a5) + (0x25))) == 0) {
                    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x27)));
                    func_00202180();
                    (*(u8 *)((u8 *)(reg_a5) + (0x27))) = (u8) reg_d1.b[0];
                }
            }
        }
    }
    if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 3) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
        (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1C)));
            (*(u16 *)((u8 *)(reg_a5) + (0x1E))) -= 4;
            if (0 >= (s16) (*(u16 *)((u8 *)(reg_a5) + (0x1E)))) {
                (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = 0U;
                (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 4U;
            }
        }
    }
    reg_a0 = (u8 *)D_00265150;
    reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x1E)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xFC00FC00;
    reg_d3.h[0] = 0x420;
    reg_d4.w = 0;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
    func_0019C470();
    reg_a0 = reg_a6;
    func_0014D220();
}
