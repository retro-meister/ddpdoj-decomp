#include "common.h"

s32 func_0014E030();
s32 func_001D55B0();
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D5780(void) {
    if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 0) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x66)));
        (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d0.h[0];
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) > 0x3C00) {
            (*(u16 *)((u8 *)(reg_a6) + (0x66))) -= 9;
            if (0 >= (s16) (*(u16 *)((u8 *)(reg_a6) + (0x66)))) {
                (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 1U;
                reg_d0.w = 0x14;
                func_0014E030();
                func_001D55B0();
                (*(u16 *)((u8 *)(reg_a6) + (0))) = 0xA001;
                (*(u16 *)((u8 *)(reg_a6) + (0x20))) = 0xA001;
                (*(u16 *)((u8 *)(reg_a6) + (0x40))) = 0xA001;
            }
        }
    }
}
