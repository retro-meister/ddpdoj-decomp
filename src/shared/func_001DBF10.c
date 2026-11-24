#include "common.h"

extern s8 D_0028E408;

s32 func_001292C0();
s32 func_00171400();
s32 func_002011A0();
s32 func_002026F0();
extern u8 D_0026EDC0[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001DBF10(void) {
    if ((*(u8 *)((u8 *)(reg_a4) + (9))) == 0) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            (*(u8 *)((u8 *)(reg_a4) + (8))) += 1;
            func_002011A0();
            reg_d0.h[0] &= 3;
            (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a4) + (0xE))) = 0U;
            reg_a0 = D_0026EDC0;
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += reg_d0.h[0];
            reg_a0 += reg_d0.h[0];
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
            reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a0) + (0)));
            reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a0) + (2)));
            func_002026F0();
            if (D_0028E408 == 0) {
                (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) reg_d1.b[0];
            }
            goto block_4;
        }
    } else {
block_4:
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
        (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
            reg_a0 = D_0026EDC0;
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += reg_d0.h[0];
            reg_a0 += reg_d0.h[0];
            reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
            reg_d1.w = 0;
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 0x13;
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xD)));
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
            reg_d4.w = 0;
            func_001292C0();
            (*(u16 *)((u8 *)(reg_a4) + (0xE))) += 2;
            (*(u8 *)((u8 *)(reg_a4) + (9))) -= 1;
            if ((s8) (*(u8 *)((u8 *)(reg_a4) + (9))) == 0) {
                func_00171400();
                (*(u16 *)((u8 *)(reg_a4) + (0x10))) -= 1;
                if ((s16) (*(u16 *)((u8 *)(reg_a4) + (0x10))) == 0) {
                    (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
                }
            }
        }
    }
}
