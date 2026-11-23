#include "common.h"

extern s8 D_0028E408;

s32 func_00123210();
s32 func_00123240();
s32 func_00123410();
s32 func_0012FAB0();
s32 func_0018D3D0();
extern u8 D_0024D628[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00123B00(void) {
    u16 temp_a0;
    u8 *temp_a2;

    func_0012FAB0();
    if ((*(u16 *)((u8 *)(reg_a6) + (6))) == 0) {
        (*(u16 *)((u8 *)(reg_a6) + (6))) = 1U;
        func_00123240();
        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = 0U;
        func_0018D3D0();
    }
    if ((*(u16 *)((u8 *)(reg_a6) + (6))) == 1) {
        reg_a0 = (u8 *)D_0024D628;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xE)));
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        reg_a0 = *(u8 **)reg_a0;
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
        reg_a0 += temp_a0;
        reg_d0.w = *(u32 *)reg_a0;
        temp_a2 = (u8 *)(reg_a6 + 0xE);
        if (reg_d0.w == -1U) {
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xE)));
            reg_d0.h[0] += 1;
            func_00123210();
            return;
        }
        reg_a0 = (u8 *) reg_d0.w;
        func_00123410();
        if (D_0028E408 == 0) {
            (*(u16 *)((u8 *)(reg_a6) + (0xC))) += 4;
            func_00123240();
        }
    }
}
