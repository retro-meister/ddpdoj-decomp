#include "common.h"

extern s8 D_0028E408;

s32 func_0013A780();
s32 func_0018D580();
s32 func_002010A0();
s32 func_002011A0();
extern u16 D_00258660[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001594D0(void) {
    u16 temp_a0;
    u16 *temp_a2;
    u16 temp_a1;
    u16 temp_v1;

    temp_v1 = (*(u16 *)((u8 *)(reg_a5) + (0x2E)));
    temp_a0 = temp_v1 & 0xFFFF;
    if (temp_v1 == 0) {
        D_0028E408 = 0;
        return;
    }
    if (temp_a0 == 1) {
        (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = 2U;
        (*(u16 *)((u8 *)(reg_a5) + (0x30))) = 0U;
        (*(s16 *)((u8 *)(reg_a5) + (0x32))) = 3;
        (*(u16 *)((u8 *)(reg_a5) + (0x34))) = 0U;
        func_0018D580();
    }
    (*(u16 *)((u8 *)(reg_a6) + (2))) -= 0x26;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x2E))) == 2) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x33)));
        (*(u8 *)((u8 *)(reg_a5) + (0x33))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x33))) = (*(u8 *)((u8 *)(reg_a5) + (0x32)));
            reg_a1 = (u8 *)(D_00258660);
            reg_a1 += (*(u16 *)((u8 *)(reg_a5) + (0x30)));
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
            temp_a2 = (u16 *)(reg_a1 + 2);
            reg_a1 = (u8 *)(temp_a2);
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a1;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0xC;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            if ((*(u16 *)((u8 *)(reg_a5) + (0x34))) != 0) {
                func_002010A0();
                reg_d0.b[0] += 0xC;
                (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) reg_d0.b[0];
                func_002011A0();
                (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
            }
            reg_a1 += 2;
            (*(u16 *)((u8 *)(reg_a5) + (0x30))) += 0xC;
            if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0x30))) >= 0x54) {
                (*(s16 *)((u8 *)(reg_a5) + (0x32))) = 0x601;
                (*(u16 *)((u8 *)(reg_a5) + (0x30))) = 0U;
                (*(s8 *)((u8 *)(reg_a6) + (0x1E))) = 1;
                (*(u16 *)((u8 *)(reg_a5) + (0x34))) += 1;
                if ((*(u16 *)((u8 *)(reg_a5) + (0x34))) == 1) {
                    (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = 0U;
                    reg_d0.w = 0;
                    D_0028E408 = 1;
                    reg_d0.h[0] -= 1;
                    return;
                }
            }
            goto block_11;
        }
    }
block_11:
    D_0028E408 = 0;
}
