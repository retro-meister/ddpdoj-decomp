#include "common.h"

extern s8 D_0028E408;

s32 func_0014E030();
s32 func_001FDDD0();
s32 func_001FF000();
extern u8 D_00266270[];
extern u16 D_0028E3F0;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001FE6D0(void) {
    u16 temp_a0;
    u32 temp_a1;
    u32 temp_a1_2;

    if ((*(u16 *)((u8 *)(reg_a6) + (0x28))) == 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0x28))) = 1U;
        (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 0x10;
        (*(u8 *)((u8 *)(reg_a6) + (0x2B))) = 0U;
        (*(u8 *)((u8 *)(reg_a6) + (0x2A))) = 0U;
        (*(u8 *)((u8 *)(reg_a6) + (0x35))) = 0x10U;
    }
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
    if (temp_a0 == 1) {
        reg_d2.h[0] = 0x2800;
        reg_d3.h[0] = 0x1C00;
        func_001FF000();
        if (D_0028E408 == 0) {
            (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 0;
            (*(u16 *)((u8 *)(reg_a6) + (0x28))) = 2U;
        }
    }
    if ((*(u16 *)((u8 *)(reg_a6) + (0x28))) == 2) {
        (*(u16 *)((u8 *)(reg_a5) + (0x1E))) += 0x40;
        if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0x1E))) >= 0x600) {
            (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = 0x600U;
            (*(u16 *)((u8 *)(reg_a6) + (0x28))) = 3U;
        }
    }
    if ((*(u16 *)((u8 *)(reg_a6) + (0x28))) == 3) {
        reg_d1.w = 1;
        reg_d1.h[0] &= D_0028E3F0;
        if (reg_d1.h[0] == 0) {
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x35)));
            reg_a4 = (u8 *)D_00266270;
            reg_d0.h[0] &= 7;
            reg_d0.h[0] *= 4;
            reg_a4 += reg_d0.h[0];
            reg_d0.w = 0x52;
            func_0014E030();
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d0.w += 0x0C7FF600;
            temp_a1 = reg_d0.w;
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (2)));
            reg_d0.w = temp_a1 + reg_tmp.w;
            (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_d0.h[1];
            (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d0.h[0];
            (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x2B)));
            (*(u8 *)((u8 *)(reg_a6) + (0x2B))) += 4;
            (*(u8 *)((u8 *)(reg_a6) + (0x2B))) &= 0x3F;
            reg_d0.w = 0x52;
            func_0014E030();
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d0.w += 0x0C800A00;
            temp_a1_2 = reg_d0.w;
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (2)));
            reg_d0.w = temp_a1_2 + reg_tmp.w;
            (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_d0.h[1];
            (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d0.h[0];
            (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x2A)));
            (*(u8 *)((u8 *)(reg_a6) + (0x2A))) -= 4;
            (*(u8 *)((u8 *)(reg_a6) + (0x2A))) &= 0x3F;
            (*(u8 *)((u8 *)(reg_a6) + (0x35))) -= 1;
            if ((*(u8 *)((u8 *)(reg_a6) + (0x35))) == 0) {
                reg_d0.w = 3;
                func_001FDDD0();
            }
        }
    }
}
