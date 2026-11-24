#include "common.h"

s32 func_0014E030();
s32 func_0014E290();
s32 func_0019C470();
s32 func_002011A0();
s32 func_00201B80();
extern u8 D_002651A0[];
extern u16 D_0028E8A0;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F68C0(void) {
    s16 temp_v0;
    s16 temp_v0_2;
    u16 temp_a0;

    reg_d0.w = 0;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_tmp.w = (u32) (s16) reg_d0.h[0];
    reg_d0.w = reg_tmp.w;
    reg_d0.w += 0x4000;
    if ((s32) reg_d0.w < 0x2001) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            func_0014E290();
            return;
        }
        goto block_4;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_4:
    func_00201B80();
    if (D_0028E8A0 == 0) {
        if (((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 0) && ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0)) {
            temp_v0 = (s16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            if ((temp_v0 < 0x7000) && (temp_v0 > 0x5000)) {
                temp_v0_2 = (*(s16 *)((u8 *)(reg_a6) + (4)));
                if ((0 < temp_v0_2) && (temp_v0_2 < 0x3800)) {
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        func_002011A0();
                        reg_d0.h[0] &= 0x3F;
                        reg_d0.h[0] += 0x20;
                        (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) reg_d0.b[0];
                        (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 1U;
                    }
                }
            }
        }
        if (((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 1) && (((*(u16 *)((u8 *)(reg_a5) + (0x1C))) != 0) || ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) > 0x3C00))) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
            (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
                (*(u16 *)((u8 *)(reg_a5) + (0x1C))) += 4;
                if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0x1C))) >= 0x1C) {
                    (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = 0x1CU;
                    (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 2U;
                    (*(s16 *)((u8 *)(reg_a5) + (0x1E))) = 0x28;
                    func_002011A0();
                    reg_d0.h[0] &= 3;
                    reg_d0.h[0] += 2;
                    (*(u16 *)((u8 *)(reg_a5) + (0x20))) = (u16) reg_d0.h[0];
                }
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 2) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
            (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (*(u8 *)((u8 *)(reg_a5) + (0x1E)));
                reg_d0.w = 0x55;
                func_0014E030();
                (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
                (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_tmp.w = (u32) reg_a5;
                (*(u16 *)((u8 *)(reg_a0) + (0x1A))) = (u16) reg_tmp.h[1];
                (*(u16 *)((u8 *)(reg_a0) + (0x1C))) = (u16) reg_tmp.h[0];
                (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 4U;
                (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 0x40U;
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 3) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
            (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
                (*(u16 *)((u8 *)(reg_a5) + (0x1C))) -= 4;
                if (0 >= (s16) (*(u16 *)((u8 *)(reg_a5) + (0x1C)))) {
                    (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = 0U;
                    (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 4U;
                }
            }
        }
    }
    reg_a0 = (u8 *)D_002651A0;
    reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF000F000;
    reg_d3.h[0] = 0x1080;
    reg_d4.w = 0;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
    func_0019C470();
}
