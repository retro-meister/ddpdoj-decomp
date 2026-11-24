#include "common.h"

s32 func_00125060();
s32 func_001251C0();
s32 func_00125250();
s32 func_002011A0();
extern s8 D_0028E408;
extern s16 D_0028E860_as_s16;
extern u16 D_0028E910;
extern u8 *reg_a0;
extern u8 *reg_a4;

void func_001E56D0() {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 var_a0;

    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        reg_d0.w = 3;
        func_00125060();
        if (D_0028E408 == 0) {
            reg_d0.w = 0xB;
            func_001251C0();
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
        }
    }
    var_a0 = 1;
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 1) {
        D_0028E860_as_s16 = 0;
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (4))) == 0) {
            D_0028E860_as_s16 = 1;
            func_002011A0();
            reg_d0.h[0] &= 0x7F;
            reg_d0.h[0] += 0x1C0;
            var_a0 = reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a4) + (4))) = var_a0;
        }
    }
    if ((*(u16 *)((u8 *)(reg_a4) + (6))) == 0) {
        reg_d0.w = 0xD;
        func_00125250();
        if (D_0028E408 == 0) {
            (*(u16 *)((u8 *)(reg_a4) + (8))) -= 1;
            if ((s16) (*(u16 *)((u8 *)(reg_a4) + (8))) == 0) {
                reg_d0.w = 0xE;
                func_001251C0();
                (*(u16 *)((u8 *)(reg_a0) + (0x10))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0xC)));
                (*(u16 *)((u8 *)(reg_a4) + (6))) = 1U;
                (*(u16 *)((u8 *)(reg_a4) + (8))) = 0x30U;
            }
        }
    }
    temp_a0 = (*(u16 *)((u8 *)(reg_a4) + (6)));
    if (temp_a0 == 1) {
        reg_d0.w = 0xE;
        func_00125250();
        if (D_0028E408 == 0) {
            (*(u16 *)((u8 *)(reg_a4) + (8))) -= 1;
            if ((s16) (*(u16 *)((u8 *)(reg_a4) + (8))) == 0) {
                (*(u16 *)((u8 *)(reg_a4) + (6))) = 0U;
                reg_d0.w = 0xD;
                func_001251C0();
                (*(u16 *)((u8 *)(reg_a0) + (0x10))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0xA)));
                (*(u16 *)((u8 *)(reg_a0) + (0x12))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (0xE)));
                (*(u16 *)((u8 *)(reg_a4) + (8))) = 0x40U;
                reg_d0.h[0] = 5;
                if (D_0028E910 == 0) {
                    reg_d0.h[0] = 3;
                }
                temp_a0_2 = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
                if (temp_a0_2 != reg_d0.h[0]) {
                    (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) (temp_a0_2 + 1);
                }
                temp_a0_3 = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
                if (temp_a0_3 != 0x10) {
                    (*(u16 *)((u8 *)(reg_a4) + (0xE))) = (u16) (temp_a0_3 + 1);
                }
            }
        }
    }
}
