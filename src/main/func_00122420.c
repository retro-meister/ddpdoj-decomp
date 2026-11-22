#include "common.h"

extern s32 D_0028DFF4;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00122420(void) {
    reg_a0 = reg_a6;
    reg_a6 += 0x7E0;
    if ((*(u16 *)((u8 *)(reg_a6) + (0x28))) == 0) {
        if ((D_0028DFF4 == 0) && (((*(u16 *)((u8 *)(reg_a0) + (0x868))) == 0) || ((*(u8 *)((u8 *)(reg_a0) + (1))) & 0x40))) {
            (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xFD;
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d0.h[0] += 0x400;
            reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a5) + (0x30)));
            (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d0.h[0];
            if ((s32) reg_d0.h[0] >= 0x7E00) {
                (*(u16 *)((u8 *)(reg_a6) + (0x28))) = 1U;
                goto block_6;
            }
        } else {
block_6:
            (*(u8 *)((u8 *)(reg_a6) + (1))) |= 2;
        }
    }
    reg_a6 -= 0x7E0;
}
