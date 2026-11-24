#include "common.h"

extern s8 D_0028E408;

s32 func_00129280();
s32 func_00129320();
extern u16 D_0028E910;
extern u8 *reg_a6;

void func_001FA180(void) {
    u32 temp_a0;
    u8 temp_a1;

    (*(u8 *)((u8 *)(reg_a6) + (0x4D))) += 2;
    (*(u8 *)((u8 *)(reg_a6) + (0x49))) -= 1;
    if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0x49))) < 0) {
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x4D)));
        reg_d0.b[0] += 0x10;
        if ((s32) reg_d0.b[0] < 0x21) {
            if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0x49))) > -2) {
                goto block_end;
            }
        } else if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0x49))) >= -2) {
            goto block_end;
        }
        (*(u8 *)((u8 *)(reg_a6) + (0x49))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x48)));
block_end:;
    } else {
        temp_a1 = (*(u8 *)((u8 *)(reg_a6) + (0x4D)));
        reg_d1.b[0] = temp_a1;
        reg_d0.w = 0xFFFD0004;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        temp_a0 = reg_d2.w;
        reg_d4.w = 0;
        reg_d3.w = 0;
        reg_d2.w = temp_a0 + 0x10000000;
        if (D_0028E910 == 0) {
            func_00129320();
            reg_d1.b[0] *= -1;
            func_00129320();
        } else {
            if ((*(u16 *)((u8 *)(reg_a6) + (0x4E))) == 0) {
                func_00129320();
                reg_d1.b[0] *= -1;
                func_00129320();
            } else {
                func_00129280();
                reg_d1.b[0] *= -1;
                func_00129280();
            }
            (*(u16 *)((u8 *)(reg_a6) + (0x4E))) += 1;
            (*(u16 *)((u8 *)(reg_a6) + (0x4E))) &= 1;
        }
    }
    (*(u16 *)((u8 *)(reg_a6) + (0x4A))) -= 1;
    if ((*(u16 *)((u8 *)(reg_a6) + (0x4A))) != 0) {
        D_0028E408 = 1;
        return;
    }
    D_0028E408 = 0;
}
