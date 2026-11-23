#include "common.h"

typedef void (*Fn)();

s32 func_00146690();
s32 func_00147CA0();
extern u16 D_0028E000;
extern u16 D_0028E004;
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a3;
extern u8 *reg_a6;

void func_00147050(void) {
    s64 temp_v1;
    u16 temp_a0;

    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_d0.h[0];
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x1E)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x20)));
    reg_a0 = (u8 *)(reg_tmp.w);
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    temp_v1 = (s64) ((s64) (*(u16 *)((u8 *)(reg_a6) + (0x22))) << 0x30) >> 0x30;
    if (temp_v1 < 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) ~temp_v1;
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        if (temp_a0 == 0x7F) {
            (*(s16 *)((u8 *)(reg_a6) + (0))) = 0;
            return;
        }
        if ((*(u16 *)((u8 *)(reg_a6) + (0x1A))) != 0) {
            if (D_0028E004 == 0) {
                goto block_7;
            }
            goto block_8;
        } else if (D_0028E000 == 0) {
block_7:
            jtbl_0028E3F4 = (Fn)(reg_a3);
            jtbl_0028E3F4();
        }
block_8:
        func_00147CA0();
        goto block_9;
    }
block_9:
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.w = (u32)reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0x1E))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x20))) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x26)));
    (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d0.h[0];
    func_00146690();
}
