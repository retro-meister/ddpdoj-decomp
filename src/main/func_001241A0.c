#include "common.h"


extern s8 D_0028E408;

s32 func_00123240();
s32 func_00123410();
extern u32 D_0024DE00[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001241A0(void) {
    u16 temp_a1;

    if ((*(u16 *)((u8 *)(reg_a6) + (6))) == 0) {
        (*(u16 *)((u8 *)(reg_a6) + (6))) = 1U;
        func_00123240();
        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = 0U;
    }
    if ((*(u16 *)((u8 *)(reg_a6) + (6))) == 1) {
        reg_a0 = (u8 *)(D_0024DE00);
        temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
        reg_a0 += temp_a1;
        reg_d0.w = *(u32 *)reg_a0;
        if (reg_d0.w == -1U) {
            (*(s8 *)((u8 *)(reg_a5) + (3))) = 2;
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
