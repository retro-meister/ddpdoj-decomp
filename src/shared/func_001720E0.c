#include "common.h"

extern s8 D_0028E408;

s32 func_00172090();
s32 func_001A3020();
extern u8 D_0026B250[];
extern s16 D_0028E784;
extern u16 D_0028E788;
extern u16 D_0028E78C;
extern u8 D_0028E790;
extern u8 D_0028E791;
extern u16 D_0028E794;
extern u8 *reg_a0;

void func_001720E0(void) {
    s32 temp_a0;
    s32 temp_a0_3;

    if (D_0028E794 == 0) {
        D_0028E794 = 1;
        func_00172090();
        reg_d0.h[0] *= 2;
        reg_d0.h[0] += 1;
        temp_a0 = reg_d0.h[0] * 4;
        reg_a0 = *(u8 **)((u8 *)D_0026B250 + temp_a0);
        reg_d0.h[0] = 0x17;
        func_001A3020();
    }
    if (D_0028E794 == 1) {
        D_0028E78C -= 1;
        D_0028E791 -= 1;
        if ((s8) D_0028E791 < 0) {
            D_0028E78C = 7;
            D_0028E791 = D_0028E790;
            D_0028E788 -= 1;
            func_00172090();
            reg_d0.h[0] *= 2;
            reg_d0.h[0] += 1;
            temp_a0_3 = reg_d0.h[0] * 4;
            reg_a0 = *(u8 **)((u8 *)D_0026B250 + temp_a0_3);
            reg_d0.h[0] = 0x17;
            func_001A3020();
            if (D_0028E788 == 0) {
                D_0028E791 = 0x20;
                D_0028E794 = 2;
            }
        }
    }
    if (D_0028E794 == 2) {
        if (D_0028E78C != 0) {
            D_0028E78C -= 1;
        }
        D_0028E791 -= 1;
        if ((s8) D_0028E791 < 0) {
            D_0028E784 = 1;
            goto block_z;
        }
    }
    D_0028E408 = 1;
    return;
block_z:
    D_0028E408 = 0;
}
