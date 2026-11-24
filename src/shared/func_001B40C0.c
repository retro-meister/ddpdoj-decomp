#include "common.h"

s32 func_00125310();
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B40C0(void) {
    u16 temp_v1;

    if ((*(u8 *)((u8 *)(reg_a4) + (7))) == 0) {
        (*(u16 *)((u8 *)(reg_a4) + (8))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a4) + (8))) == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (7))) = 1U;
            (*(s16 *)((u8 *)(reg_a6) + (0x114))) = 1;
            goto block_3;
        }
    } else {
block_3:
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (2)));
        (*(u8 *)((u8 *)(reg_a6) + (0x4A))) += reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x8A))) += reg_d0.b[0];
        if ((*(u8 *)((u8 *)(reg_a4) + (7))) == 1) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
            (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
                (*(u8 *)((u8 *)(reg_a4) + (2))) += reg_d0.b[0];
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (2)));
                if ((s8)(reg_d0.b[0]) < 0) {
                    reg_d0.b[0] *= -1;
                }
                if (reg_d0.b[0] == 2) {
                    (*(u8 *)((u8 *)(reg_a4) + (7))) = 2U;
                    (*(u16 *)((u8 *)(reg_a4) + (4))) = 0x6020;
                    (*(u16 *)((u8 *)(reg_a4) + (0x12))) = 0x100U;
                }
            }
        }
        if ((*(u8 *)((u8 *)(reg_a4) + (7))) == 2) {
            temp_v1 = (*(u16 *)((u8 *)(reg_a4) + (0x12)));
            if (temp_v1 != 0) {
                (*(u16 *)((u8 *)(reg_a4) + (0x12))) = (u16) (temp_v1 - 1);
            } else {
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
                reg_d0.b[0] += reg_d0.b[0];
                reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (2)));
                if (reg_d0.b[0] != reg_d1.b[0]) {
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
                    (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
                        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
                        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
                        reg_a0 = (u8 *)reg_tmp.w;
                        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
                        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x10)));
                        reg_a0 = (u8 *)reg_tmp.w;
                        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
                        (*(u8 *)((u8 *)(reg_a4) + (2))) -= reg_d0.b[0];
                    }
                } else {
                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x4A)));
                    reg_d0.b[0] &= 0xFE;
                    if (reg_d0.b[0] == 0x40) {
                        (*(u8 *)((u8 *)(reg_a6) + (0x4A))) = 0x40U;
                        (*(u8 *)((u8 *)(reg_a6) + (0x8A))) = 0xC0U;
                        (*(u8 *)((u8 *)(reg_a4) + (7))) = 3U;
                        reg_d0.w = 5;
                        func_00125310();
                        reg_d0.w = 6;
                        func_00125310();
                        reg_d0.w = 0xE;
                        func_00125310();
                    }
                }
            }
        }
        if ((*(u8 *)((u8 *)(reg_a4) + (7))) == 3) {
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
            (*(s16 *)((u8 *)(reg_a6) + (0x114))) = 0;
        }
    }
}
