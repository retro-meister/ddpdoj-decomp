#include "common.h"

s32 func_001DAF90();
s32 func_002026F0();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001DAD20(void) {
    if ((*(u8 *)((u8 *)(reg_a4) + (7))) == 0) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
        (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
            (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
            goto block_3;
        }
    } else {
block_3:
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x12)));
            (*(u8 *)((u8 *)(reg_a4) + (0x13))) += reg_d0.b[0];
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x13)));
            reg_d1.b[0] = 0x40;
            reg_d3.w = 0xF9400200;
            reg_d0.w = 0;
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x11)));
            reg_d0.h[0] = (u16) (s8) reg_d0.b[0];
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 5;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x82)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x84)));
            reg_d4.w = 0;
            reg_d7.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x17)));
            func_001DAF90();
            (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (0xD))) == 0) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (9)));
        (*(u8 *)((u8 *)(reg_a4) + (9))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xC)));
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x14)));
            (*(u8 *)((u8 *)(reg_a4) + (0x15))) += reg_d0.b[0];
            goto block_8;
        }
    } else {
block_8:
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xB)));
        (*(u8 *)((u8 *)(reg_a4) + (0xB))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (0xB))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xA)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
            reg_d0.h[0] += 0xF940;
            reg_d1.h[0] += 0xFE00;
            func_002026F0();
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x15)));
            reg_d1.b[0] = 0xC0;
            reg_d0.w = 0;
            reg_d3.w = 0xF93FFE00;
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x10)));
            reg_d0.h[0] = (u16) (s8) reg_d0.b[0];
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 5;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
            reg_d4.w = 0;
            reg_d7.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x16)));
            func_001DAF90();
            (*(u8 *)((u8 *)(reg_a4) + (0xD))) -= 1;
        }
    }
}
