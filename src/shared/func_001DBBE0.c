#include "common.h"

typedef void (*Fn)();

extern u8 D_0028DC78[];
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001DBBE0(void) {
    u16 temp_a3;

    if ((*(u8 *)((u8 *)(reg_a4) + (9))) == 0) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            goto block_3;
        }
    } else {
block_3:
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
        (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
            reg_d0.h[0] = 8;
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 0xB;
            reg_d1.w = 0x80;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
            temp_a3 = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
            reg_d2.h[0] = temp_a3;
            reg_d3.w = 0x08000000;
            reg_d7.h[0] = reg_d1.h[0];
            reg_d4.w = 0;
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
            ((Fn)*(u32 *)((u8 *)D_0028DC78 + (reg_tmp.h[0] & ~3)))();
            (*(u16 *)((u8 *)(reg_a4) + (0xA))) += 4;
            (*(u16 *)((u8 *)(reg_a4) + (0xA))) &= 7;
            (*(u8 *)((u8 *)(reg_a4) + (9))) -= 1;
            if ((s8) (*(u8 *)((u8 *)(reg_a4) + (9))) == 0) {
                (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
            }
        }
    }
}
