#include "common.h"

s32 func_001C3800(void *);
extern u16 D_0028E4AA;
extern u8 *reg_a4;

void func_001C3730(void) {
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x11)));
    (*(u8 *)((u8 *)(reg_a4) + (0x11))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0x11))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0x10)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
        reg_tmp.w = reg_d0.w;
        D_0028E4AA = reg_d0.h[0];
        reg_d0.h[0] = reg_tmp.h[1];
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x16)));
        func_001C3800(reg_a4);
        (*(u16 *)((u8 *)(reg_a4) + (8))) += 0xA;
        (*(u8 *)((u8 *)(reg_a4) + (7))) += 2;
        (*(u16 *)((u8 *)(reg_a4) + (0x16))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0x18)));
        (*(u16 *)((u8 *)(reg_a4) + (0x14))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a4) + (0x14))) == 0) {
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
        }
    }
}
