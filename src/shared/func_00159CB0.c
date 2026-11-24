#include "common.h"

typedef void (*Fn)();

s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_00153650();
s32 func_0018D500();
s32 func_0019C790();
s32 func_001A9000();
s32 func_001A91A0();
extern u16 D_00258760[];
extern u16 D_00258770[];
extern u8 D_00258790[];
extern u16 D_0028E484_as_u16;
extern u16 D_0028E8A0;
extern u16 D_0028E8A8;
extern s8 enemy_move_end_requested;
extern u32 jtbl_0028E3F4_as_u32;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00159CB0(void) {
    u16 temp_a1;
    u32 temp_a0;

    if ((*(s16 *)((u8 *)(reg_a6) + (2))) < -0x1000) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            func_0014E290();
            return;
        }
        goto block_4;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_4:
    func_0014EA50();
    if (enemy_move_end_requested == 0) {
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
            if ((*(u8 *)((u8 *)(reg_a5) + (0x27))) == 0) {
                (*(s16 *)((u8 *)(reg_a6) + (0x18))) = 0xC00;
            }
            if ((*(s16 *)((u8 *)(reg_a6) + (0x18))) < 0) {
                reg_d0.w = 0x72;
                func_001A91A0();
                func_0018D500();
                reg_a1 = (u8 *)D_00258790;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d3.h[0] = 0x10;
                func_00153650();
                func_0014E290();
                return;
            }
            goto block_11;
        }
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x19)));
block_11:
        if (D_0028E8A0 == 0) {
            if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 3) {
                (*(u16 *)((u8 *)(reg_a5) + (0x1A))) -= 0x40;
                (*(u16 *)((u8 *)(reg_a6) + (0x14))) -= 0x40;
                (*(u16 *)((u8 *)(reg_a6) + (0x16))) -= 0x40;
                if (0 >= (s16) (*(u16 *)((u8 *)(reg_a5) + (0x1A)))) {
                    (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = 0U;
                    (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 0U;
                }
            }
            if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 2) {
                (*(u8 *)((u8 *)(reg_a5) + (0x27))) = 1U;
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
                (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1E)));
                    reg_a0 = (u8 *)(D_00258760);
                    if ((s32) D_0028E8A8 >= 0x100) {
                        reg_a0 = (u8 *)(D_00258770);
                    }
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x24)));
                    reg_d0.h[0] *= 4;
                    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    jtbl_0028E3F4_as_u32 = reg_tmp.w;
                    ((Fn)jtbl_0028E3F4_as_u32)();
                    (*(u16 *)((u8 *)(reg_a5) + (0x24))) += 1;
                    reg_d0.w = 4;
                    reg_d1.w = 3;
                    if ((s32) D_0028E8A8 >= 0x100) {
                        reg_d0.w = 8;
                        reg_d1.w = 2;
                    }
                    (*(u16 *)((u8 *)(reg_a5) + (0x22))) += reg_d1.h[0];
                    if ((*(u16 *)((u8 *)(reg_a5) + (0x24))) == reg_d0.h[0]) {
                        (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 3U;
                    }
                }
            }
            if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 1) {
                (*(u16 *)((u8 *)(reg_a5) + (0x1A))) += 0x40;
                (*(u16 *)((u8 *)(reg_a6) + (0x14))) += 0x40;
                (*(u16 *)((u8 *)(reg_a6) + (0x16))) += 0x40;
                if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0x1A))) >= 0x380) {
                    (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = 0x380U;
                    (*(u8 *)((u8 *)(reg_a5) + (0x21))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x20)));
                    (*(u16 *)((u8 *)(reg_a5) + (0x22))) = 1U;
                    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = 0U;
                    (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 2U;
                }
            }
            if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 0) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
                (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1C)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 1U;
                }
            }
        }
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xF200F900;
        reg_d3.h[0] = 0xE38;
        reg_d2.w = 0x187A;
        reg_d4.w = 0;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
        func_0019C790();
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.w += 0xFEBFFB40;
        reg_d7.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
        D_0028E484_as_u16 = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = D_0028E484_as_u16;
        reg_d1.h[0] -= reg_d7.h[0];
        D_0028E484_as_u16 = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = D_0028E484_as_u16;
        reg_d1.h[0] -= (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
        temp_a0 = reg_d1.w;
        reg_d3.h[0] = 0xE28;
        reg_d2.w = 0x187B;
        reg_d4.w = 0;
        reg_d1.w = temp_a0 + 0xF200FB00;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
        func_0019C790();
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.w += 0xFEC00480;
        reg_d7.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
        D_0028E484_as_u16 = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = D_0028E484_as_u16;
        reg_d1.h[0] -= reg_d7.h[0];
        D_0028E484_as_u16 = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = D_0028E484_as_u16;
        reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
        reg_d1.w += 0xF200FB00;
        reg_d3.h[0] = 0xE28;
        reg_d2.w = 0x187C;
        reg_d4.w = 0;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
        func_0019C790();
        reg_a0 = (u8 *)(reg_a6);
        func_0014D220();
    }
}
