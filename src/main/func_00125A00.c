#include "common.h"

extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00125A00(void) {
    (*(u8 *)((u8 *)(reg_a6) + (0x19))) -= 1;
    if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0x19))) < 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0x19))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x18)));
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_tmp.w += 1;
        (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) reg_tmp.h[0];
        if (reg_tmp.w == 0xBCF) {
            reg_tmp.w = 0xBBF;
            (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) reg_tmp.h[0];
        }
    }
}
