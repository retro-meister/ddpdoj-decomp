#include "common.h"

s32 func_0014E030();
extern u16 D_0028E3F0;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001FE120(void) {
    u16 temp_v1;
    u16 temp_v1_2;

    if ((*(u16 *)((u8 *)(reg_a6) + (0x46))) != 0) {
        if ((*(u16 *)((u8 *)(reg_a6) + (0x4C))) == 1) {
            (*(u16 *)((u8 *)(reg_a6) + (0x48))) = 0xA00U;
            (*(u16 *)((u8 *)(reg_a6) + (0x4A))) = 0xA00U;
            (*(u16 *)((u8 *)(reg_a6) + (0x4C))) = 0U;
        }
        if ((*(u16 *)((u8 *)(reg_a6) + (0x4C))) == 0) {
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x48)));
            reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x4A)));
            if (reg_d0.h[0] == 0) {
                reg_d0.w = 0;
                reg_d0.h[0] &= D_0028E3F0;
                if (reg_d0.h[0] == 0) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x4C))) = 1U;
                    reg_d0.w = 0x4E;
                    func_0014E030();
                    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    reg_d0.w += 0xFC3FEC80;
                    (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_d0.h[1];
                    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d0.h[0];
                    (*(u16 *)((u8 *)(reg_a0) + (0x1A))) = 0xFA00;
                    reg_d0.w = 0x4E;
                    func_0014E030();
                    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    reg_d0.w += 0xFC401380;
                    (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_d0.h[1];
                    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d0.h[0];
                    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x600;
                }
            }
        }
    }
    temp_v1 = (*(u16 *)((u8 *)(reg_a6) + (0x48)));
    if (temp_v1 != 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0x48))) = (u16) (temp_v1 - 0x100);
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x48))) <= 0) {
            (*(u16 *)((u8 *)(reg_a6) + (0x48))) = 0U;
        }
    }
    temp_v1_2 = (*(u16 *)((u8 *)(reg_a6) + (0x4A)));
    if (temp_v1_2 != 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0x4A))) = (u16) (temp_v1_2 - 0x100);
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x4A))) <= 0) {
            (*(u16 *)((u8 *)(reg_a6) + (0x4A))) = 0U;
        }
    }
}
