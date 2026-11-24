#include "common.h"

s32 func_0019EF20();
s32 func_0019F410();
s32 func_0019F750();
s32 func_001A2680();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001A1360(void) {
    func_0019F750();
    func_001A2680();
    reg_a6 += 0x20;
    func_001A2680();
    reg_a6 -= 0x20;
    func_0019F410();
    if ((*(u8 *)((u8 *)(reg_a6) + (0x40))) & 0x10) {
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x20)));
        if ((*(u8 *)((u8 *)(reg_a4) + (0))) & 1) {
            reg_d0.h[0] = 8;
        }
        reg_d0.b[0] >>= 1;
        reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x36)));
        (*(u8 *)((u8 *)(reg_a4) + (0x34))) = (u8) reg_d0.b[0];
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0)));
        (*(u8 *)((u8 *)(reg_a6) + (0))) &= 0xF7;
        if (reg_tmp.b[0] & 8) {
            (*(u8 *)((u8 *)(reg_a6) + (0))) |= 0x10;
            (*(u8 *)((u8 *)(reg_a4) + (0x34))) = 0U;
            goto block_10;
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0)));
        (*(u8 *)((u8 *)(reg_a6) + (0))) &= 0xEF;
        if (reg_tmp.b[0] & 0x10) {
            (*(u8 *)((u8 *)(reg_a4) + (0x35))) = 1U;
            return;
        }
        goto block_10;
    }
    (*(u8 *)((u8 *)(reg_a6) + (0))) &= 0xEF;
    if ((*(u8 *)((u8 *)(reg_a4) + (0x34))) != 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0x35))) -= 1;
        if ((*(u8 *)((u8 *)(reg_a4) + (0x35))) == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (0x34))) -= 1;
            (*(u8 *)((u8 *)(reg_a6) + (0))) |= 0x10;
block_10:
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x37)));
            if (!((*(u8 *)((u8 *)(reg_a4) + (0))) & 1)) {
                if ((u16) (*(u16 *)((u8 *)(reg_a4) + (0x20))) == 8) {
                    goto block_13;
                }
            } else {
block_13:
                reg_d0.w = 2;
            }
            (*(u8 *)((u8 *)(reg_a4) + (0x35))) = (u8) reg_d0.b[0];
            func_0019EF20();
        }
    }
}
