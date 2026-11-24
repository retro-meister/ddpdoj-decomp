#include "common.h"

extern s8 D_0028E408;

s32 func_00138A40();
s32 func_0013A780();
s32 func_0013AB50();
s32 func_0013B2E0();
s32 func_0018D500();
s32 func_0018D5C0();
s32 func_001D5040();
s32 func_002010A0();
extern u16 D_002634F0[];
extern u16 D_00263540[];
extern u8 D_00263590[];
extern s16 D_0028E85C;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D5230(void) {
    u16 temp_a0_2;
    u16 temp_a0_3;
    u8 temp_a0;
    u8 *var_a1;

    if ((*(u8 *)((u8 *)(reg_a5) + (0x25))) != 0) {
        temp_a0 = (*(u8 *)((u8 *)(reg_a5) + (0x24)));
        if (temp_a0 == 2) {
            (*(u8 *)((u8 *)(reg_a5) + (0x27))) -= 1;
            if ((*(u8 *)((u8 *)(reg_a5) + (0x27))) == 0) {
                func_00138A40();
                D_0028E85C = 0;
                (*(s16 *)((u8 *)(reg_a5) + (0x30))) = 1;
                goto block_set;
            }
        }
        var_a1 = (u8 *)(reg_a5);
        if ((*(u8 *)((u8 *)(var_a1) + (0x24))) == 1) {
            (*(u8 *)((u8 *)(var_a1) + (0x27))) -= 1;
            if ((*(u8 *)((u8 *)(reg_a5) + (0x27))) == 0) {
                (*(s16 *)((u8 *)(reg_a5) + (0x2C))) = 0;
                reg_a0 = (u8 *)D_00263590;
                func_0013B2E0();
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_a1 = (u8 *)(D_00263540);
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
                var_a1 = (u8 *)((void *)0x10);
                (*(u8 *)((u8 *)(reg_a5) + (0x27))) = 0x10U;
                (*(u8 *)((u8 *)(reg_a5) + (0x24))) = 2U;
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x24))) == 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x27)));
            (*(u8 *)((u8 *)(reg_a5) + (0x27))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x27))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x26)));
                func_0018D500();
                reg_a1 = (u8 *)(D_002634F0);
                reg_a1 += (*(u16 *)((u8 *)(reg_a5) + (0x2A)));
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
                (*(u16 *)((u8 *)(reg_a5) + (0x2A))) += 0xC;
                if ((*(u16 *)((u8 *)(reg_a5) + (0x2A))) == 0x48) {
                    (*(u16 *)((u8 *)(reg_a5) + (0x2A))) = 0U;
                    (*(u16 *)((u8 *)(reg_a5) + (0x28))) -= 1;
                    if ((*(u16 *)((u8 *)(reg_a5) + (0x28))) == 0) {
                        (*(u16 *)((u8 *)(reg_a5) + (0x26))) = 0x1006;
                        (*(u8 *)((u8 *)(reg_a5) + (0x24))) = 1U;
                    }
                }
            }
        }
        goto block_12;
    }
block_12:
    D_0028E408 = 0;
    return;
block_set:
    D_0028E408 = 1;
}
