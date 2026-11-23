#include "common.h"

s32 func_001A3020();
extern u32 D_0025F620[];
extern u16 D_0028E914;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;

void func_001A3300(void) {
    s64 temp_a0;
    u16 temp_a1;

    reg_a2 = (u8 *)(D_0025F620);
    reg_d0.h[0] = D_0028E914;
    reg_tmp.w = *(u32 *)(reg_a2 + reg_d0.h[0]);
    reg_a2 = (u8 *) reg_tmp.w;
loop_1:
    reg_d0.w = *(u32 *)reg_a2;
    reg_a2 += 4;
    if (reg_d0.w != -1U) {
        reg_a1 = (u8 *)reg_d0.w;
loop_3:
        temp_a1 = (*(u16 *)((u8 *)(reg_a1) + (0)));
        temp_a0 = (s64) ((s64) temp_a1 << 0x30) >> 0x30;
        if (temp_a0 != -1) {
            reg_d0.h[0] = temp_a1;
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (4)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (6)));
            reg_a0 = (u8 *)reg_tmp.w;
            func_001A3020();
            reg_a1 += 8;
            goto loop_3;
        }
        goto loop_1;
    }
}
