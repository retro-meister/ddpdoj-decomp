#include "common.h"

extern s8 D_0028E408;

s32 func_0013A780();
s32 func_0013AB50();
s32 func_0018D500();
s32 func_0018D5C0();
s32 func_001D5040();
s32 func_002010A0();
s32 func_00201710();
s32 func_00217BB0();
s32 func_00217C20();
extern u16 D_00266290[];
extern u16 D_002662E0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_001FF0B0(void) {
    u16 temp_a0_2;
    u16 temp_a0_3;
    u8 temp_a0;

    if ((*(u8 *)((u8 *)(reg_a6) + (0x9E))) != 0) {
        (*(u16 *)((u8 *)(reg_a6) + (2))) -= 0x40;
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x8E)));
        func_00201710();
        temp_a0 = (*(u8 *)((u8 *)(reg_a6) + (0x87)));
        if (temp_a0 == 2) {
            (*(s8 *)((u8 *)(reg_a6) + (0x9F))) = 1;
            goto block_set;
        }
        if (temp_a0 == 1) {
            (*(u8 *)((u8 *)(reg_a6) + (0x89))) -= 1;
            if ((*(u8 *)((u8 *)(reg_a6) + (0x89))) == 0) {
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_a1 = (u8 *)(D_002662E0);
                func_001D5040();
                func_002010A0();
                reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
                reg_d1.b[0] = reg_d0.b[0];
                reg_d1.b[0] += 0x40;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d2.h[0] = temp_a0_2;
                reg_d2.w += 0xF8000800;
                reg_d3.h[0] = 0xC;
                reg_d0.h[0] = 0;
                func_0013AB50();
                func_002010A0();
                reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
                reg_d1.b[0] = reg_d0.b[0];
                reg_d1.b[0] += 0xC0;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                temp_a0_3 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d2.h[0] = temp_a0_3;
                reg_d2.w += 0x01FFF800;
                reg_d3.h[0] = 0xC;
                reg_d0.h[0] = 0;
                func_0013AB50();
                func_0018D5C0();
                (*(u8 *)((u8 *)(reg_a6) + (0x89))) = 0x10U;
                (*(u8 *)((u8 *)(reg_a6) + (0x87))) = 2U;
                func_00217BB0(0xB4, 0x3C, 0x10);
                func_00217C20(0xB4, 0x3C);
            }
        }
        if ((*(u8 *)((u8 *)(reg_a6) + (0x87))) == 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x89)));
            (*(u8 *)((u8 *)(reg_a6) + (0x89))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a6) + (0x89))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x88)));
                func_0018D500();
                reg_a1 = (u8 *)(D_00266290);
                reg_a1 += (*(u16 *)((u8 *)(reg_a6) + (0x8A)));
                reg_d1.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                func_0013A780();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                (*(u8 *)((u8 *)(reg_a0) + (0x1D))) = (u8) reg_d0.b[0];
                (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d1.h[0];
                (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
                (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
                (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
                (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
                (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
                (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                reg_d0.b[0] *= 4;
                (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
                (*(u16 *)((u8 *)(reg_a6) + (0x8A))) += 0xC;
                if ((*(u16 *)((u8 *)(reg_a6) + (0x8A))) == 0x48) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x8A))) = 0U;
                    (*(u16 *)((u8 *)(reg_a6) + (0x8C))) -= 1;
                    if ((*(u16 *)((u8 *)(reg_a6) + (0x8C))) == 0) {
                        (*(u16 *)((u8 *)(reg_a6) + (0x88))) = 0x1006;
                        (*(u8 *)((u8 *)(reg_a6) + (0x87))) = 1U;
                    }
                }
            }
        }
        goto block_11;
    }
block_11:
    D_0028E408 = 0;
    return;
block_set:
    D_0028E408 = 1;
}
