#include "common.h"

s32 func_0014E000();
s32 func_0014E290();
s32 func_0019C470();
s32 func_00201B80();
s32 func_00201C60();
extern u8 D_00265C50[];
extern u16 D_0028E8A0;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001FA470(void) {
    u16 temp_a1;
    u16 temp_v1;

    if (D_0028E8A0 == 0) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 0) {
            func_00201B80();
            (*(u16 *)((u8 *)(reg_a5) + (0x1E))) -= 1;
            if ((*(u16 *)((u8 *)(reg_a5) + (0x1E))) == 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 1U;
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 1) {
            func_00201C60();
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
            (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1C)));
                (*(u8 *)((u8 *)(reg_a6) + (0x1B))) -= 1;
                if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) == 2) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 2U;
                }
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 2) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x18)));
                (*(u16 *)((u8 *)(reg_a5) + (0x1A))) += 4;
                temp_v1 = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
                if (temp_v1 == 0x40) {
                    func_0014E290();
                    return;
                }
                if (temp_v1 == 0x3C) {
                    reg_d0.w = 0x44;
                    func_0014E000();
                    (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
                    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
                }
                goto block_14;
            }
        }
        goto block_14;
    }
block_14:
    reg_a0 = (u8 *)D_00265C50;
    reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFC000000;
    reg_d4.w = 0;
    reg_d1.w += 0xE600E600;
    reg_d3.h[0] = 0x1AD0;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
    func_0019C470();
}
