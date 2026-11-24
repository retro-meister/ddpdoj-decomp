#include "common.h"

s32 func_0014E030();
s32 func_002011A0();
extern u8 D_0026ED10[];
extern u16 D_0028E85C;
extern u8 *reg_a0;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001DB060(void) {
    s8 var_a0;
    u8 temp_v1;

    temp_v1 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_v1 != 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (temp_v1 - 1);
        if ((s8) (*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
            func_002011A0();
            reg_a3 = (u8 *)D_0026ED10;
            reg_d0.h[0] &= 7;
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += reg_d0.h[0];
            reg_a3 += reg_d0.h[0];
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a3) + (0)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a3) + (2)));
            reg_a3 = (u8 *) reg_tmp.w;
            reg_d6.b[0] = (u8) (s8) (*(s8 *)((u8 *)(reg_a3) + (0)));
            reg_a3 += 1;
            reg_d7.w = 0;
            var_a0 = (s8) (*(s8 *)((u8 *)(reg_a3) + (0)));
            reg_d7.b[0] = (u8) var_a0;
            reg_a3 += 1;
            (*(u16 *)((u8 *)(reg_a4) + (4))) = (u16) reg_d7.h[0];
            reg_d7.h[0] -= 1;
            do {
                reg_d0.w = 0x42;
                func_0014E030();
                var_a0 = 0xFF;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
                (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_d2.h[1];
                (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d2.h[0];
                (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) reg_d6.b[0];
                (*(s8 *)((u8 *)(reg_a0) + (0x1A))) = (s8) (*(s8 *)((u8 *)(reg_a3) + (0)));
                reg_a3 += 1;
                reg_tmp.w = (u32) reg_a6;
                (*(u16 *)((u8 *)(reg_a0) + (0x1C))) = (u16) reg_tmp.h[1];
                (*(u16 *)((u8 *)(reg_a0) + (0x1E))) = (u16) reg_tmp.h[0];
                (*(u8 *)((u8 *)(reg_a0) + (0x21))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
                (*(u8 *)((u8 *)(reg_a0) + (0x20))) = 0xFFU;
            } while ((s16)(--reg_d7.h[0]) >= 0);
        }
    }
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x19E)));
    if (((*(u16 *)((u8 *)(reg_a4) + (4))) == reg_d0.h[0]) && (D_0028E85C == 0)) {
        (*(u16 *)((u8 *)(reg_a4) + (0x10))) -= 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (0x10))) == 0) {
            D_0028E85C = 1;
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
        }
    }
}
