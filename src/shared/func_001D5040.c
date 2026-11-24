#include "common.h"


s32 func_0013A780();
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_001D5040(u16 *arg2) {
    u16 *var_a2;
    u16 temp_a1;

    var_a2 = (u16 *)(arg2);
loop_1:
    temp_a1 = *(u16 *)reg_a1;
    reg_d1.h[0] = temp_a1;
    reg_a1 += 2;
    if ((s16) reg_d1.h[0] != -1) {
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
        var_a2 = (u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)(var_a2);
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) reg_d2.h[1];
        (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) reg_d2.h[0];
        (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
        (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
        (*(u16 *)((u8 *)(reg_a0) + (0x1A))) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        goto loop_1;
    }
}
