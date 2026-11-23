#include "common.h"

extern s8 D_0028E408;

s32 func_00129280();
s32 func_00129370();
s32 func_0014D220();
s32 func_0014E290();
s32 func_00153650();
s32 func_001563B0();
s32 func_0018D560();
s32 func_0019C6D0();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_00201B80();
s32 func_00202140();
s32 func_00202500();
s32 func_00202F50();
s32 func_002115E0();
extern u8 D_00257FB0[];
extern u8 D_00258030[];
extern u16 D_0028E8C8;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00155F30(void) {
    u32 temp_a0;
    u32 temp_a0_3;
    u32 temp_a1;
    u32 temp_a0_2;
    u32 temp_a0_4;
    u32 temp_a0_5;

    if ((*(s16 *)((u8 *)(reg_a6) + (2))) < -0x1800) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            func_0014E290();
            return;
        }
        goto block_4;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_4:
    func_00201B80();
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
        func_001A9000();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1C)));
        reg_d0.b[0] ^= reg_d2.b[0];
        (*(u8 *)((u8 *)(reg_a5) + (0x1A))) = (u8) reg_d0.b[0];
        if ((*(s16 *)((u8 *)(reg_a6) + (0x18))) < 0) {
            reg_d0.w = 0x47;
            func_001A91A0();
            (*(u16 *)((u8 *)(reg_a6) + (0))) = 0x8000;
            (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = 1U;
            reg_a1 = (u8 *)D_00258030;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (6)));
            temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (8)));
            reg_tmp.h[0] = temp_a0;
            reg_d3.h[0] = 0xC;
            reg_d2.w += reg_tmp.w;
            func_00153650();
            reg_d0.w = 4;
            reg_d1.h[0] = 0xC;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            temp_a0_2 = reg_d2.w;
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (6)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (8)));
            reg_d2.w = temp_a0_2 + reg_tmp.w;
            reg_d2.w += 0xFC000000;
            func_002115E0();
            func_0018D560();
            goto block_7;
        }
    } else {
block_7:
        (*(u8 *)((u8 *)(reg_a5) + (0x1A))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
    }
    if ((*(u8 *)((u8 *)(reg_a5) + (0x1F))) == 0) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        temp_a0_3 = reg_d0.h[0];
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] = temp_a0_3 + (*(u32 *)((u8 *)(reg_a6) + (6)));
        reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (8)));
        func_00202140();
        if (D_0028E408 == 0) {
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
            func_00202500();
            (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) reg_d1.b[0];
            if ((*(u8 *)((u8 *)(reg_a5) + (0x25))) == 0) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x21)));
                (*(u8 *)((u8 *)(reg_a5) + (0x21))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    reg_d0.h[0] = 0x18;
                    reg_d0.h[0] -= D_0028E8C8;
                    (*(u8 *)((u8 *)(reg_a5) + (0x21))) = (u8) reg_d0.b[0];
                    reg_d0.h[0] = 4;
                    reg_d1.h[0] = D_0028E8C8;
                    reg_d1.h[0] >>= 3;
                    reg_d0.h[0] -= reg_d1.h[0];
                    (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (u8) reg_d0.b[0];
                    (*(u8 *)((u8 *)(reg_a5) + (0x1E))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
                    goto block_13;
                }
            } else {
block_13:
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
                (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x22)));
                    func_00202F50();
                    if (D_0028E408 == 0) {
                        reg_d3.w = 0;
                        reg_a4 = (u8 *)D_00257FB0;
                        reg_d3.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
                        reg_d3.b[0] += 1;
                        reg_d3.h[0] &= 0x3E;
                        reg_d3.h[0] += reg_d3.h[0];
                        reg_a4 += reg_d3.h[0];
                        reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0)));
                        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a4) + (2)));
                        temp_a0_4 = reg_d3.w;
                        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (6)));
                        temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (8)));
                        reg_tmp.h[0] = temp_a1;
                        reg_d0.w = 0xA0016;
                        reg_d1.w = 0;
                        reg_d3.w = temp_a0_4 + reg_tmp.w;
                        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
                        reg_d1.b[0] += 1;
                        reg_d1.h[0] &= 0x3E;
                        reg_d1.h[0] *= 4;
                        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                        reg_d4.w = 0;
                        func_00129280();
                        reg_d1.b[0] += 2;
                        func_00129370();
                        reg_d1.b[0] -= 4;
                        func_00129370();
                        (*(u8 *)((u8 *)(reg_a5) + (0x25))) -= 1;
                    }
                }
            }
        }
    }
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    temp_a0_5 = reg_d1.w;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x2C)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x2E)));
    reg_d1.w = temp_a0_5 + reg_tmp.w;
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x2A)));
    reg_d4.w = 0;
    reg_d4.h[0] = 0x15;
    func_0019C6D0();
    func_001563B0();
    reg_a0 = reg_a6;
    func_0014D220();
}
