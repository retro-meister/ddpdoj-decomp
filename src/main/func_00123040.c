#include "common.h"

extern s8 D_0028E408;

s32 func_0013B350();
s32 func_0013BE50();
s32 func_0013C300();
s32 func_0013C350();
extern u8 D_0024D200[];
extern u8 D_0024D2D0[];
extern u16 D_00295E2C[];
extern u16 D_00295E2E[];
extern u16 D_00295E30[];
extern u16 D_00295E32[];
extern u32 D_00295E34[];
extern u8 *reg_a0;

void func_00123040(void) {
    if (D_00295E2E[0] == 0) goto block_rts;
    if (D_00295E2E[0] != 1) goto next_1;
    if (D_00295E2C[0] == 0) goto next_2;
    reg_a0 = (u8 *)D_0024D200;
    reg_d0.h[0] = D_00295E32[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    reg_a0 = *(u8 **)reg_a0;
    func_0013BE50();
    D_00295E34[0] = reg_d0.w;
    D_00295E2E[0] = 2;
next_1:
    if (D_00295E2E[0] != 2) goto next_3;
    reg_d0.w = D_00295E34[0];
    func_0013C350();
    if (D_0028E408 != 0) goto next_3;
    func_0013C300();
next_2:
    D_00295E2C[0] = D_00295E30[0];
    D_00295E2E[0] = 3;
    if (D_00295E2C[0] != 0) goto next_3;
    D_00295E2E[0] = 0;
next_3:
    if (D_00295E2E[0] != 3) goto next_4;
    reg_a0 = (u8 *)D_0024D2D0;
    reg_d0.h[0] = D_00295E32[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    reg_a0 = *(u8 **)reg_a0;
    func_0013B350();
    D_00295E34[0] = reg_d0.w;
    D_00295E2E[0] = 4;
next_4:
    if (D_00295E2E[0] != 4) goto block_rts;
    reg_d0.w = D_00295E34[0];
    func_0013C350();
    if (D_0028E408 != 0) goto block_rts;
    func_0013C300();
    D_00295E2E[0] = 0;
block_rts:
    return;
}
